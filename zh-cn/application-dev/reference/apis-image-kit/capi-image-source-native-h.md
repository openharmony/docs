# image_source_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## 概述

图片解码API。

**引用文件：** <multimedia/image_framework/image/image_source_native.h>

**库：** libimage_source.so

**系统能力：** SystemCapability.Multimedia.Image.ImageSource

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) | OH_ImageSourceNative | OH_ImageSourceNative是native层封装的ImageSource结构体，用于创建图片数据。 |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) | OH_ImageSource_Info | OH_ImageSource_Info是native层封装的ImageSource信息结构体，OH_ImageSource_Info结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。 |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) | OH_DecodingOptionsForPicture | Picture解码参数结构体。通过[OH_DecodingOptionsForPicture_Create](#oh_decodingoptionsforpicture_create)获取。 |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) | OH_DecodingOptions | OH_DecodingOptions是native层封装的解码选项参数结构体，用于设置解码选项参数，在创建Pixelmap时作为入参传入，详细信息见[OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap)。 |

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
| [Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)](#oh_imagesourceinfo_getwidth) | 获取图片的宽。 |
| [Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)](#oh_imagesourceinfo_getheight) | 获取图片的高。 |
| [Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)](#oh_imagesourceinfo_getdynamicrange) | 获取图片是否为高动态范围的信息。 |
| [Image_ErrorCode OH_ImageSourceInfo_GetMimetype(OH_ImageSource_Info *info, Image_MimeType *mimetype)](#oh_imagesourceinfo_getmimetype) | 获取图片源的MIME类型。 |
| [Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)](#oh_imagesourceinfo_release) | 释放OH_ImageSource_Info指针。 |
| [Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)](#oh_decodingoptions_create) | 创建OH_DecodingOptions指针。 |
| [Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options,int32_t *pixelFormat)](#oh_decodingoptions_getpixelformat) | 获取pixel格式。 |
| [Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options,int32_t pixelFormat)](#oh_decodingoptions_setpixelformat) | 设置pixel格式。 |
| [Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)](#oh_decodingoptions_getindex) | 获取解码图片序号。 |
| [Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)](#oh_decodingoptions_setindex) | 设置解码图片序号。 |
| [Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)](#oh_decodingoptions_getrotate) | 获取旋转角度。 |
| [Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)](#oh_decodingoptions_setrotate) | 设置旋转角度。 |
| [Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options,Image_Size *desiredSize)](#oh_decodingoptions_getdesiredsize) | 获取期望输出大小。 |
| [Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options,Image_Size *desiredSize)](#oh_decodingoptions_setdesiredsize) | 设置期望输出大小。 |
| [Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options,Image_Region *desiredRegion)](#oh_decodingoptions_getdesiredregion) | 获取解码区域。<br> 由于对应SetDesiredRegion接口无法满足区域解码诉求，从API 19开始，推荐配套使用[OH_DecodingOptions_GetCropRegion](#oh_decodingoptions_getcropregion)接口替代。 |
| [Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options,Image_Region *desiredRegion)](#oh_decodingoptions_setdesiredregion) | 设置解码区域。<br> 实际解码结果会按照原图解码，无区域解码效果。从API 19开始，推荐使用接口[OH_DecodingOptions_SetCropRegion](#oh_decodingoptions_setcropregion)替代。 |
| [Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options,int32_t *desiredDynamicRange)](#oh_decodingoptions_getdesireddynamicrange) | 获取解码时设置的期望动态范围。 |
| [Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options,int32_t desiredDynamicRange)](#oh_decodingoptions_setdesireddynamicrange) | 设置解码时的期望动态范围。 |
| [Image_ErrorCode OH_DecodingOptions_GetDesiredColorSpace(OH_DecodingOptions *options, int32_t *colorSpace)](#oh_decodingoptions_getdesiredcolorspace) | 获取解码参数中设置的色彩空间。 |
| [Image_ErrorCode OH_DecodingOptions_SetDesiredColorSpace(OH_DecodingOptions *options, int32_t colorSpace)](#oh_decodingoptions_setdesiredcolorspace) | 设置解码期望得到的色彩空间。 |
| [Image_ErrorCode OH_DecodingOptions_SetCropAndScaleStrategy(OH_DecodingOptions *options,int32_t cropAndScaleStrategy)](#oh_decodingoptions_setcropandscalestrategy) | 设置解码选项的裁剪和缩放策略。 |
| [Image_ErrorCode OH_DecodingOptions_GetCropAndScaleStrategy(OH_DecodingOptions *options,int32_t *cropAndScaleStrategy)](#oh_decodingoptions_getcropandscalestrategy) | 获取解码选项的裁剪和缩放策略。 |
| [Image_ErrorCode OH_DecodingOptions_GetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)](#oh_decodingoptions_getcropregion) | 获取解码参数中的裁剪区域。 |
| [Image_ErrorCode OH_DecodingOptions_SetCropRegion(OH_DecodingOptions *options, Image_Region *cropRegion)](#oh_decodingoptions_setcropregion) | 设置解码参数中的裁剪区域。 |
| [Image_ErrorCode OH_DecodingOptions_Release(OH_DecodingOptions *options)](#oh_decodingoptions_release) | 释放OH_DecodingOptions指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromUri(char *uri, size_t uriSize, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromuri) | 通过uri创建OH_ImageSourceNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromfd) | 通过fd创建OH_ImageSourceNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromdata) | 通过缓冲区数据创建OH_ImageSourceNative指针。<br> data数据应该是未解码的数据，不要传入类似于RBGA，YUV的像素buffer数据，如果想通过像素buffer数据创建pixelMap，可以调用[OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap)这一类接口。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength,OH_ImageSourceNative **imageSource)](#oh_imagesourcenative_createfromdatawithuserbuffer) | 由数据缓存创建图片源。传入的数据缓存将在图片源对象中直接访问，在图片源对象的声明周期内，数据缓存需要保持可用。 |
| [Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)](#oh_imagesourcenative_createfromrawfile) | 通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options,OH_PixelmapNative **pixelmap)](#oh_imagesourcenative_createpixelmap) | 通过图片解码参数创建OH_PixelmapNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source,OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)](#oh_imagesourcenative_createpixelmapusingallocator) | 根据解码参数创建一个PixelMap，PixelMap使用的内存类型可以通过allocatorType来指定。<br> 默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理通过此接口返回的PixelMap时，请始终考虑步幅（stride）的影响。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options,OH_PixelmapNative *resVecPixMap[], size_t size)](#oh_imagesourcenative_createpixelmaplist) | 通过图片解码参数创建OH_PixelmapNative数组。<br> 注意，此接口会一次性解码全部帧，当帧数过多或单帧图像过大时，会占用较大内存，造成系统内存紧张，此种情况推荐使用Image组件显示动图，Image组件采用逐帧解码，占用内存比此接口少。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options,OH_PictureNative **picture)](#oh_imagesourcenative_createpicture) | 通过图片解码创建OH_PictureNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index,OH_PictureNative **picture)](#oh_imagesourcenative_createpictureatindex) | 通过指定序号的图片解码创建OH_PictureNative指针。 |
| [Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)](#oh_imagesourcenative_getdelaytimelist) | 获取图像延迟时间数组。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index,OH_ImageSource_Info *info)](#oh_imagesourcenative_getimageinfo) | 获取指定序号的图片信息。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key,Image_String *value)](#oh_imagesourcenative_getimageproperty) | 获取图片指定属性键的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key,Image_String *value)](#oh_imagesourcenative_getimagepropertywithnull) | 获取图像属性值。输出的value.data以字符串结束符结尾。 |
| [Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key,Image_String *value)](#oh_imagesourcenative_modifyimageproperty) | 通过指定的键修改图片属性的值。 |
| [Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)](#oh_imagesourcenative_getframecount) | 获取图像帧数。 |
| [Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)](#oh_imagesourcenative_getsupportedformats) | 获取支持解码的图片格式。 |
| [Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)](#oh_imagesourcenative_release) | 释放OH_ImageSourceNative指针。 |
| [Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)](#oh_decodingoptionsforpicture_create) | 创建OH_DecodingOptionsForPicture指针。 |
| [Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options,Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)](#oh_decodingoptionsforpicture_getdesiredauxiliarypictures) | 获取解码时设置的期望辅助图（期望解码出的picture包含的辅助图）。 |
| [Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options,Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)](#oh_decodingoptionsforpicture_setdesiredauxiliarypictures) | 设置解码选项中的期望辅助图。 |
| [Image_ErrorCode OH_DecodingOptionsForPicture_Release(OH_DecodingOptionsForPicture *options)](#oh_decodingoptionsforpicture_release) | 释放OH_DecodingOptionsForPicture指针。 |

## 枚举类型说明

### IMAGE_DYNAMIC_RANGE

```
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

```
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

```
enum Image_CropAndScaleStrategy
```

**描述**

在同时指定desiredSize和desiredRegion时执行裁剪和缩放的策略。<br> 如果在配置解码选项[OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md)时，未填入参数Image_CropAndScaleStrategy，并且同时设置了desiredRegion和desiredSize，由于系统对于不同图片格式采用的解码算法不同，最终解码效果将略有差异。<br> 例如原始图片大小200x200，传入desiredSize:{width: 150, height: 150}，desiredRegion:{x: 0, y: 0, width: 100, height: 100}，即预期解码原图左上角1/4区域，最终将pixelMap大小缩放至150x150返回。<br> 对于jpeg、webp图片（部分dng图片解码时会优先解码图片中的jpeg预览图，在此场景下也会被视为jpeg图片格式）会先进行下采样，例如按照7/8下采样，再基于175x175的图片大小进行区域裁剪，因此最终的区域内容稍大于原图的左上角1/4区域。<br> 对于svg图片，由于是矢量图，可以任意缩放不损失清晰度，在解码时会根据desiredSize与原图Size的比例选择缩放比例，在基于缩放后的图片大小进行区域裁剪，因此最终返回的解码区域会有所差异。<br> 针对该场景，建议在解码选项同时设置了desiredRegion与desiredSize时，参数Image_CropAndScaleStrategy应传入CROP_FIRST参数保证效果一致。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| IMAGE_CROP_AND_SCALE_STRATEGY_SCALE_FIRST = 1 | 先裁剪，后缩放。 |
| IMAGE_CROP_AND_SCALE_STRATEGY_CROP_FIRST = 2 | 先缩放，后裁剪。 |


## 函数说明

### OH_ImageSourceInfo_Create()

```
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

```
Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)
```

**描述**

获取图片的宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 被操作的OH_ImageSource_Info指针。 |
| uint32_t *width | 图片的宽，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceInfo_GetHeight()

```
Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)
```

**描述**

获取图片的高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 被操作的OH_ImageSource_Info指针。 |
| uint32_t *height | 图片的高，单位：像素高 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceInfo_GetDynamicRange()

```
Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)
```

**描述**

获取图片是否为高动态范围的信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 被操作的OH_ImageSource_Info指针。 |
| bool *isHdr | 是否为hdr的布尔值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数校验错误。 |

### OH_ImageSourceInfo_GetMimetype()

```
Image_ErrorCode OH_ImageSourceInfo_GetMimetype(OH_ImageSource_Info *info, Image_MimeType *mimetype)
```

**描述**

获取图片源的MIME类型。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | OH_ImageSource_Info指针。 |
| [Image_MimeType](capi-image-nativemodule-image-string.md) *mimetype | 图片源的MIME类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_SOURCE_INVALID_PARAMETER：参数错误，INFO或者MIME类型为空。 |

### OH_ImageSourceInfo_Release()

```
Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)
```

**描述**

释放OH_ImageSource_Info指针。

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

```
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

```
Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options,int32_t *pixelFormat)
```

**描述**

获取pixel格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t *pixelFormat | pixel格式[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetPixelFormat()

```
Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options,int32_t pixelFormat)
```

**描述**

设置pixel格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t pixelFormat | pixel格式[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetIndex()

```
Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)
```

**描述**

获取解码图片序号。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| uint32_t *index | 解码图片序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetIndex()

```
Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)
```

**描述**

设置解码图片序号。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| uint32_t index | 解码图片序号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetRotate()

```
Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)
```

**描述**

获取旋转角度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| float *rotate | 旋转角度，单位为deg。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetRotate()

```
Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)
```

**描述**

设置旋转角度。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| float rotate | 旋转角度，单位为deg。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options,Image_Size *desiredSize)
```

**描述**

获取期望输出大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSize | 期望输出大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options,Image_Size *desiredSize)
```

**描述**

设置期望输出大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| [Image_Size](capi-image-nativemodule-image-size.md) *desiredSize | 期望输出大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options,Image_Region *desiredRegion)
```

**描述**

获取解码区域。<br> 由于对应SetDesiredRegion接口无法满足区域解码诉求，从API 19开始，推荐配套使用[OH_DecodingOptions_GetCropRegion](#oh_decodingoptions_getcropregion)接口替代。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *desiredRegion | 解码区域。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_SetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options,Image_Region *desiredRegion)
```

**描述**

设置解码区域。<br> 实际解码结果会按照原图解码，无区域解码效果。从API 19开始，推荐使用接口[OH_DecodingOptions_SetCropRegion](#oh_decodingoptions_setcropregion)替代。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *desiredRegion | 解码区域。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options,int32_t *desiredDynamicRange)
```

**描述**

获取解码时设置的期望动态范围。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t *desiredDynamicRange | 期望的动态范围值[IMAGE_DYNAMIC_RANGE](#image_dynamic_range)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数校验错误。 |

### OH_DecodingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options,int32_t desiredDynamicRange)
```

**描述**

设置解码时的期望动态范围。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 被操作的OH_DecodingOptions指针。 |
| int32_t desiredDynamicRange | 期望的动态范围值[IMAGE_DYNAMIC_RANGE](#image_dynamic_range)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数校验错误。 |

### OH_DecodingOptions_GetDesiredColorSpace()

```
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

```
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

```
Image_ErrorCode OH_DecodingOptions_SetCropAndScaleStrategy(OH_DecodingOptions *options,int32_t cropAndScaleStrategy)
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

```
Image_ErrorCode OH_DecodingOptions_GetCropAndScaleStrategy(OH_DecodingOptions *options,int32_t *cropAndScaleStrategy)
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

```
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

```
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

```
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

```
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
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) **res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_BAD_SOURCE：解码数据源异常。 |

### OH_ImageSourceNative_CreateFromFd()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)
```

**描述**

通过fd创建OH_ImageSourceNative指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t fd | 文件描述符fd。 |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) **res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_CreateFromData()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)
```

**描述**

通过缓冲区数据创建OH_ImageSourceNative指针。<br> data数据应该是未解码的数据，不要传入类似于RBGA，YUV的像素buffer数据，如果想通过像素buffer数据创建pixelMap，可以调用[OH_PixelmapNative_CreatePixelmap](capi-pixelmap-native-h.md#oh_pixelmapnative_createpixelmap)这一类接口。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *data | 图像缓冲区数据。 |
| size_t dataSize | 图像缓冲区数据长度。 |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) **res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_BAD_SOURCE：解码数据源异常。 |

### OH_ImageSourceNative_CreateFromDataWithUserBuffer()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromDataWithUserBuffer(uint8_t *data, size_t datalength,OH_ImageSourceNative **imageSource)
```

**描述**

由数据缓存创建图片源。传入的数据缓存将在图片源对象中直接访问，在图片源对象的声明周期内，数据缓存需要保持可用。

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

```
Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)
```

**描述**

通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [RawFileDescriptor](../apis-localization-kit/capi-rawfile-rawfiledescriptor.md) *rawFile | 指示raw文件的文件描述符。 |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) **res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_CreatePixelmap()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options,OH_PixelmapNative **pixelmap)
```

**描述**

通过图片解码参数创建OH_PixelmapNative指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 解码参数。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 指向c++本地层创建的OH_PixelmapNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_CreatePixelmapUsingAllocator()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator(OH_ImageSourceNative *source,OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap)
```

**描述**

根据解码参数创建一个PixelMap，PixelMap使用的内存类型可以通过allocatorType来指定。<br> 默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理通过此接口返回的PixelMap时，请始终考虑步幅（stride）的影响。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 解码参数。 |
| [IMAGE_ALLOCATOR_TYPE](#image_allocator_type) allocator | 指示返回的PixelMap将使用哪种内存类型。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 指向c++本地层创建的OH_PixelmapNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_BAD_SOURCE：数据源异常。<br>         IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE：不支持的MIME类型。<br>         IMAGE_SOURCE_TOO_LARGE：图像过大。<br>         IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE：不支持的分配器类型。例如，使用共享内存解码HDR图像，因为只有DMA支持HDR元数据。<br>         IMAGE_SOURCE_UNSUPPORTED_OPTIONS：不支持的选项。例如，无法将图像转换为所需的像素格式。<br>         IMAGE_DECODE_FAILED：解码失败。<br>         IMAGE_SOURCE_ALLOC_FAILED：内存分配失败。 |

### OH_ImageSourceNative_CreatePixelmapList()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options,OH_PixelmapNative *resVecPixMap[], size_t size)
```

**描述**

通过图片解码参数创建OH_PixelmapNative数组。<br> 注意，此接口会一次性解码全部帧，当帧数过多或单帧图像过大时，会占用较大内存，造成系统内存紧张，此种情况推荐使用Image组件显示动图，Image组件采用逐帧解码，占用内存比此接口少。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [OH_DecodingOptions](capi-image-nativemodule-oh-decodingoptions.md) *options | 解码参数。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *resVecPixMap[] | 指向c++本地层创建的OH_PixelmapNative对象的指针数组。 |
| size_t size | 数组长度。 用户可以使用[OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。 |

### OH_ImageSourceNative_CreatePicture()

```
Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options,OH_PictureNative **picture)
```

**描述**

通过图片解码创建OH_PictureNative指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [OH_DecodingOptionsForPicture](capi-image-nativemodule-oh-decodingoptionsforpicture.md) *options | 解码参数。 |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) **picture | 指向c++本地层创建的OH_PictureNative对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_DECODE_FAILED：解码失败。 |

### OH_ImageSourceNative_CreatePictureAtIndex()

```
Image_ErrorCode OH_ImageSourceNative_CreatePictureAtIndex(OH_ImageSourceNative *source, uint32_t index,OH_PictureNative **picture)
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

```
Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)
```

**描述**

获取图像延迟时间数组。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| int32_t *delayTimeList | 指向获得的延迟时间列表的指针。它不能是空指针。 |
| size_t size | delayTimeList的大小。用户可以从[OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount)获得大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetImageInfo()

```
Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index,OH_ImageSource_Info *info)
```

**描述**

获取指定序号的图片信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| int32_t index | 图片序号。对GIF图片可传入[0,N-1],N表示GIF的帧数。对只有一帧数据的图片格式，可传入0。 |
| [OH_ImageSource_Info](capi-image-nativemodule-imagesource-info.md) *info | 指向获取的图像源信息的OH_ImageSource_Info指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetImageProperty()

```
Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key,Image_String *value)
```

**描述**

获取图片指定属性键的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 指示指向属性的指针，详情请参见[Image_String](capi-image-nativemodule-image-string.md)，key的取值范围参考[OHOS_IMAGE_PROPERTY_XXX](capi-image-common-h.md#变量)定义。使用ImageSource后释放，参见[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)。 |
| [Image_String](capi-image-nativemodule-image-string.md) *value | 指向获取的值的指针。用户可以传入一个空指针和零大小，我们将分配内存，但用户必须在使用后释放内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetImagePropertyWithNull()

```
Image_ErrorCode OH_ImageSourceNative_GetImagePropertyWithNull(OH_ImageSourceNative *source, Image_String *key,Image_String *value)
```

**描述**

获取图像属性值。输出的value.data以字符串结束符结尾。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 指向ImageSource的指针。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 指向属性键的指针。 |
| [Image_String](capi-image-nativemodule-image-string.md) *value | 指向属性值的指针（输出参数）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_SOURCE_INVALID_PARAMETER：source、key或value为空。 |

### OH_ImageSourceNative_ModifyImageProperty()

```
Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key,Image_String *value)
```

**描述**

通过指定的键修改图片属性的值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| [Image_String](capi-image-nativemodule-image-string.md) *key | 指向属性键的指针，详情请参见[Image_String](capi-image-nativemodule-image-string.md)，key是一个exif常数。使用ImageSource后释放，参见[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)。 |
| [Image_String](capi-image-nativemodule-image-string.md) *value | 需要修改的属性值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetFrameCount()

```
Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)
```

**描述**

获取图像帧数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 被操作的OH_ImageSourceNative指针。 |
| uint32_t *frameCount | 图像帧数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageSourceNative_GetSupportedFormats()

```
Image_ErrorCode OH_ImageSourceNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
```

**描述**

获取支持解码的图片格式。

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

```
Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)
```

**描述**

释放OH_ImageSourceNative指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageSourceNative](capi-image-imagesourcenative-.md) *source | 要释放的OH_ImageSourceNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。 <br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_DecodingOptionsForPicture_Create()

```
Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)
```

**描述**

创建OH_DecodingOptionsForPicture指针。

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

```
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options,Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)
```

**描述**

获取解码时设置的期望辅助图（期望解码出的picture包含的辅助图）。

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

```
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options,Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)
```

**描述**

设置解码选项中的期望辅助图。

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

### OH_DecodingOptionsForPicture_Release()

```
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


