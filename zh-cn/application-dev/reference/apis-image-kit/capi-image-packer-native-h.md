# image_packer_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## 概述

图片编码API。

**库：** libimage_packer.so

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) | OH_ImagePackerNative | ImagePacker结构体类型，用于执行ImagePacker相关操作。 |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) | OH_PackingOptions | OH_PackingOptions是native层封装的图像编码选项结构体，OH_PackingOptions结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。 |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) | OH_PackingOptionsForSequence | 图像序列编码选项。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range) | IMAGE_PACKER_DYNAMIC_RANGE | 编码指定动态范围。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)](#oh_packingoptions_create) | 创建PackingOptions结构体的指针。 |
| [Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions *options,Image_MimeType *format)](#oh_packingoptions_getmimetype) | 获取MIME类型。 |
| [Image_ErrorCode OH_PackingOptions_GetMimeTypeWithNull(OH_PackingOptions *options,Image_MimeType *format)](#oh_packingoptions_getmimetypewithnull) | 获取编解码参数中的MIME类型。输出的format.data以字符串结束符结尾。 |
| [Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options,Image_MimeType *format)](#oh_packingoptions_setmimetype) | 设置MIME类型。 |
| [Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options,uint32_t *quality)](#oh_packingoptions_getquality) | 获取编码质量。 |
| [Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options,uint32_t quality)](#oh_packingoptions_setquality) | 设置编码质量。 |
| [ Image_ErrorCode OH_PackingOptions_GetNeedsPackProperties(OH_PackingOptions *options,bool *needsPackProperties)](#oh_packingoptions_getneedspackproperties) | 获取OH_PackingOptions结构体的needsPackProperties参数。 |
| [Image_ErrorCode OH_PackingOptions_SetNeedsPackProperties(OH_PackingOptions *options,bool needsPackProperties)](#oh_packingoptions_setneedspackproperties) | 设置OH_PackingOptions结构体的needsPackProperties参数。 |
| [Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange(OH_PackingOptions *options, int32_t* desiredDynamicRange)](#oh_packingoptions_getdesireddynamicrange) | 获取编码时期望的图片动态范围。 |
| [Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange(OH_PackingOptions *options, int32_t desiredDynamicRange)](#oh_packingoptions_setdesireddynamicrange) | 设置编码时期望的图片动态范围。 |
| [Image_ErrorCode OH_PackingOptions_Release(OH_PackingOptions *options)](#oh_packingoptions_release) | 释放OH_PackingOptions指针。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_Create(OH_PackingOptionsForSequence **options)](#oh_packingoptionsforsequence_create) | 创建OH_PackingOptionsForSequence结构体的指针。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_SetFrameCount(OH_PackingOptionsForSequence *options,uint32_t frameCount)](#oh_packingoptionsforsequence_setframecount) | 设置编码时指定的帧数。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_GetFrameCount(OH_PackingOptionsForSequence *options,uint32_t *frameCount)](#oh_packingoptionsforsequence_getframecount) | 获取编码时指定的帧数。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_SetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)](#oh_packingoptionsforsequence_setdelaytimelist) | 设定编码时图片的延迟时间数组。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_GetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)](#oh_packingoptionsforsequence_getdelaytimelist) | 获取编码时图片的延迟时间数组。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_SetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)](#oh_packingoptionsforsequence_setdisposaltypes) | 设定编码时图片的过渡帧模式数组。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_GetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)](#oh_packingoptionsforsequence_getdisposaltypes) | 获取编码时图片的过渡帧模式数组。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_SetLoopCount(OH_PackingOptionsForSequence *options, uint32_t loopCount)](#oh_packingoptionsforsequence_setloopcount) | 设定编码时图片循环播放次数，取值范围为[0，65535]，0表示无限循环；若无此字段，则表示不循环播放。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_GetLoopCount(OH_PackingOptionsForSequence *options, uint32_t *loopCount)](#oh_packingoptionsforsequence_getloopcount) | 获取编码时图片循环播放次数。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_Release(OH_PackingOptionsForSequence *options)](#oh_packingoptionsforsequence_release) | 释放OH_PackingOptionsForSequence指针。 |
| [Image_ErrorCode OH_ImagePackerNative_Create(OH_ImagePackerNative **imagePacker)](#oh_imagepackernative_create) | 创建OH_ImagePackerNative指针。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafromimagesource) | 将ImageSource编码为指定格式的数据。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafrompixelmap) | 将Pixelmap编码为指定格式的数据。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafrompicture) | 将Picture编码为指定格式的数据。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence,size_t sequenceLength, uint8_t *outData, size_t *outDataSize)](#oh_imagepackernative_packtodatafrompixelmapsequence) | 将Pixelmap序列编码为数据。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, int32_t fd)](#oh_imagepackernative_packtofilefromimagesource) | 将一个ImageSource编码到文件中。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, int32_t fd)](#oh_imagepackernative_packtofilefrompixelmap) | 将一个Pixelmap编码到文件中。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, int32_t fd)](#oh_imagepackernative_packtofilefrompicture) | 将一个Picture编码到文件中。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, int32_t fd)](#oh_imagepackernative_packtofilefrompixelmapsequence) | 将一个Pixelmap序列编码到文件中。 |
| [Image_ErrorCode OH_ImagePackerNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)](#oh_imagepackernative_getsupportedformats) | 获取支持编码的图片格式。 |
| [Image_ErrorCode OH_ImagePackerNative_Release(OH_ImagePackerNative *imagePacker)](#oh_imagepackernative_release) | 释放OH_ImagePackerNative指针。 |

## 枚举类型说明

### IMAGE_PACKER_DYNAMIC_RANGE

```
enum IMAGE_PACKER_DYNAMIC_RANGE
```

**描述**

编码指定动态范围。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IMAGE_PACKER_DYNAMIC_RANGE_AUTO = 0 | 编码动态范围根据图像信息自适应。 |
| IMAGE_PACKER_DYNAMIC_RANGE_SDR = 1 | 编码图片为标准动态范围。 |


## 函数说明

### OH_PackingOptions_Create()

```
Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)
```

**描述**

创建PackingOptions结构体的指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) **options | 用于操作的PackingOptions指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_GetMimeType()

```
Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions *options,Image_MimeType *format)
```

**描述**

获取MIME类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | 图像格式。可传入一个空指针和零大小，系统将分配内存，但必须在使用后释放内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_GetMimeTypeWithNull()

```
Image_ErrorCode OH_PackingOptions_GetMimeTypeWithNull(OH_PackingOptions *options,Image_MimeType *format)
```

**描述**

获取编解码参数中的MIME类型。输出的format.data以字符串结束符结尾。

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 编码参数指针。 |
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | 编码参数中的 MIME 类型的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_PACKER_INVALID_PARAMETER：options或format为空。 |

### OH_PackingOptions_SetMimeType()

```
Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options,Image_MimeType *format)
```

**描述**

设置MIME类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | 图像格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_GetQuality()

```
Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options,uint32_t *quality)
```

**描述**

获取编码质量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| uint32_t *quality | 编码质量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_SetQuality()

```
Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options,uint32_t quality)
```

**描述**

设置编码质量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| uint32_t quality | 编码质量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_GetNeedsPackProperties()

```
 Image_ErrorCode OH_PackingOptions_GetNeedsPackProperties(OH_PackingOptions *options,bool *needsPackProperties)
```

**描述**

获取OH_PackingOptions结构体的needsPackProperties参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| bool *needsPackProperties | 是否需要编码图片属性信息，例如EXIF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_SetNeedsPackProperties()

```
Image_ErrorCode OH_PackingOptions_SetNeedsPackProperties(OH_PackingOptions *options,bool needsPackProperties)
```

**描述**

设置OH_PackingOptions结构体的needsPackProperties参数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| bool needsPackProperties | 是否需要编码图片属性信息，例如EXIF。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange(OH_PackingOptions *options, int32_t* desiredDynamicRange)
```

**描述**

获取编码时期望的图片动态范围。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| int32_t* desiredDynamicRange | 期望的动态范围[IMAGE_PACKER_DYNAMIC_RANGE]#image_packer_dynamic_range)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange(OH_PackingOptions *options, int32_t desiredDynamicRange)
```

**描述**

设置编码时期望的图片动态范围。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| int32_t desiredDynamicRange | 期望的动态范围[IMAGE_PACKER_DYNAMIC_RANGE]#image_packer_dynamic_range)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_Release()

```
Image_ErrorCode OH_PackingOptions_Release(OH_PackingOptions *options)
```

**描述**

释放OH_PackingOptions指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_Create()

```
Image_ErrorCode OH_PackingOptionsForSequence_Create(OH_PackingOptionsForSequence **options)
```

**描述**

创建OH_PackingOptionsForSequence结构体的指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) **options | 用于操作的OH_PackingOptionsForSequence指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_SetFrameCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetFrameCount(OH_PackingOptionsForSequence *options,uint32_t frameCount)
```

**描述**

设置编码时指定的帧数。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| uint32_t frameCount | 图片的帧数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_GetFrameCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetFrameCount(OH_PackingOptionsForSequence *options,uint32_t *frameCount)
```

**描述**

获取编码时指定的帧数。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| uint32_t *frameCount | 图片的帧数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_SetDelayTimeList()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)
```

**描述**

设定编码时图片的延迟时间数组。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| int32_t *delayTimeList | 图片延迟时间数组的指针。 |
| size_t delayTimeListLength | 图片延迟时间数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_GetDelayTimeList()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)
```

**描述**

获取编码时图片的延迟时间数组。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| int32_t *delayTimeList | 图片延迟时间数组的指针。 |
| size_t delayTimeListLength | 图片延迟时间数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_SetDisposalTypes()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)
```

**描述**

设定编码时图片的过渡帧模式数组。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| uint32_t *disposalTypes | 图片过渡帧模式数组的指针，图片帧过渡模式的参数，如果长度小于frameCount，不足的部分将使用disposalTypes中的最后一个值进行填充，可取值如下：<br>0：不需要任何操作。<br>1：保持图形不变。<br>2：恢复背景色。<br>3：恢复到之前的状态。 |
| size_t disposalTypesLength | 图片过渡帧模式数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_GetDisposalTypes()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)
```

**描述**

获取编码时图片的过渡帧模式数组。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| uint32_t *disposalTypes | 图片过渡帧模式数组的指针。 |
| size_t disposalTypesLength | 图片过渡帧模式数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_SetLoopCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetLoopCount(OH_PackingOptionsForSequence *options, uint32_t loopCount)
```

**描述**

设定编码时图片循环播放次数，取值范围为[0，65535]，0表示无限循环；若无此字段，则表示不循环播放。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| uint32_t loopCount | 图片循环播放次数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_GetLoopCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetLoopCount(OH_PackingOptionsForSequence *options, uint32_t *loopCount)
```

**描述**

获取编码时图片循环播放次数。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| uint32_t *loopCount | 图片循环播放次数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_Release()

```
Image_ErrorCode OH_PackingOptionsForSequence_Release(OH_PackingOptionsForSequence *options)
```

**描述**

释放OH_PackingOptionsForSequence指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImagePackerNative_Create()

```
Image_ErrorCode OH_ImagePackerNative_Create(OH_ImagePackerNative **imagePacker)
```

**描述**

创建OH_ImagePackerNative指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) **imagePacker | 被操作的OH_ImagePackerNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImagePackerNative_PackToDataFromImageSource()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, uint8_t *outData, size_t *size)
```

**描述**

将ImageSource编码为指定格式的数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 编码选项参数。 |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *imageSource | 用于编码的image source指针。 |
| uint8_t *outData | 用于存储打包图像输出数据的缓冲区。 |
| size_t *size | 用于存储打包图像输出数据的缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。<br>IMAGE_ALLOC_FAILED：申请内存失败。<br> IMAGE_TOO_LARGE：数据或图片过大。<br>IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_ImagePackerNative_PackToDataFromPixelmap()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, uint8_t *outData, size_t *size)
```

**描述**

将Pixelmap编码为指定格式的数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 编码选项参数。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 用于编码的Pixelmap指针。 |
| uint8_t *outData | 用于存储打包图像输出数据的缓冲区。 |
| size_t *size | 用于存储打包图像输出数据的缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。<br>IMAGE_ALLOC_FAILED：申请内存失败。<br> IMAGE_TOO_LARGE：数据或图片过大。<br>IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_ImagePackerNative_PackToDataFromPicture()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, uint8_t *outData, size_t *size)
```

**描述**

将Picture编码为指定格式的数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 编码选项参数。 |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | 用于编码的Picture指针。 |
| uint8_t *outData | 用于存储打包图像输出数据的缓冲区。 |
| size_t *size | 用于存储打包图像输出数据的缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。 |

### OH_ImagePackerNative_PackToDataFromPixelmapSequence()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence,size_t sequenceLength, uint8_t *outData, size_t *outDataSize)
```

**描述**

将Pixelmap序列编码为数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 编码选项参数 [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md)。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapSequence | 用于编码的Pixelmap序列指针。 |
| size_t sequenceLength | 用于编码的Pixelmap序列长度。 |
| uint8_t *outData | 用于存储编码后图像输出数据的缓冲区。 |
| size_t *outDataSize | 用于存储编码后图像输出数据的缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。 |

### OH_ImagePackerNative_PackToFileFromImageSource()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, int32_t fd)
```

**描述**

将一个ImageSource编码到文件中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 编码选项参数。 |
| [OH_ImageSourceNative](capi-image-nativemodule-oh-imagesourcenative.md) *imageSource | 用于编码的image source指针。 |
| int32_t fd | 可写的文件描述符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。<br>IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_ImagePackerNative_PackToFileFromPixelmap()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, int32_t fd)
```

**描述**

将一个Pixelmap编码到文件中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 编码选项参数。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 用于编码的pixelmap指针。 |
| int32_t fd | 可写的文件描述符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。<br>IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_ImagePackerNative_PackToFileFromPicture()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, int32_t fd)
```

**描述**

将一个Picture编码到文件中。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 编码选项参数。 |
| [OH_PictureNative](capi-image-nativemodule-oh-picturenative.md) *picture | 用于编码的picture指针。 |
| int32_t fd | 可写的文件描述符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。<br>IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_ImagePackerNative_PackToFileFromPixelmapSequence()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, int32_t fd)
```

**描述**

将一个Pixelmap序列编码到文件中。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 编码选项参数 [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md)。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapSequence | 用于编码的Pixelmap序列指针。 |
| size_t sequenceLength | 用于编码的Pixelmap序列长度。 |
| int32_t fd | 可写的文件描述符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。 |

### OH_ImagePackerNative_GetSupportedFormats()

```
Image_ErrorCode OH_ImagePackerNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
```

**描述**

获取支持编码的图片格式。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Image_MimeType](capi-image-nativemodule-image-string.md) **supportedFormats | 支持编码的图片格式。 |
| size_t *length | 数组长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_PACKER_INVALID_PARAMETER：参数异常，supportedFormats或length为空。 |

### OH_ImagePackerNative_Release()

```
Image_ErrorCode OH_ImagePackerNative_Release(OH_ImagePackerNative *imagePacker)
```

**描述**

释放OH_ImagePackerNative指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |


