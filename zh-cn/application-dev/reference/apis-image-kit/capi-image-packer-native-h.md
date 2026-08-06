# image_packer_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 概述

图片编码API。

**引用文件：** <multimedia/image_framework/image/image_packer_native.h>

**库：** libimage_packer.so

**系统能力：** SystemCapability.Multimedia.Image.ImagePacker

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) | OH_ImagePackerNative | ImagePacker结构体类型，用于执行ImagePacker相关操作。 |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) | OH_PackingOptions | OH_PackingOptions是native层封装的图像编码选项结构体，不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。 |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) | OH_PackingOptionsForSequence | OH_PackingOptionsForSequence是native层封装的图像序列编码选项结构体，不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range) | IMAGE_PACKER_DYNAMIC_RANGE | 编码指定动态范围。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)](#oh_packingoptions_create) | 创建PackingOptions结构体的指针。 |
| [Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_getmimetype) | 获取编码参数中的MIME类型。该接口获取的format.data缺少字符串结束符'\0'，请谨慎使用。|
| [Image_ErrorCode OH_PackingOptions_GetMimeTypeWithNull(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_getmimetypewithnull) | 获取编码参数中的MIME类型。该接口获取的format.data以字符串结束符'\0'结尾。 |
| [Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)](#oh_packingoptions_setmimetype) | 设置MIME类型。 |
| [Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options, uint32_t *quality)](#oh_packingoptions_getquality) | 获取编码质量。 |
| [Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options, uint32_t quality)](#oh_packingoptions_setquality) | 设置编码质量。 |
| [ Image_ErrorCode OH_PackingOptions_GetNeedsPackProperties(OH_PackingOptions *options, bool *needsPackProperties)](#oh_packingoptions_getneedspackproperties) | 获取OH_PackingOptions结构体的needsPackProperties参数。 |
| [Image_ErrorCode OH_PackingOptions_SetNeedsPackProperties(OH_PackingOptions *options, bool needsPackProperties)](#oh_packingoptions_setneedspackproperties) | 设置OH_PackingOptions结构体的needsPackProperties参数。 |
| <!--DelRow--> [Image_ErrorCode OH_PackingOptions_GetNeedsPackDfxData(OH_PackingOptions *options, bool *needsPackDfxData)](#oh_packingoptions_getneedspackdfxdata) | 获取OH_PackingOptions结构体中的needsPackDfxData参数。 |
| <!--DelRow--> [Image_ErrorCode OH_PackingOptions_SetNeedsPackDfxData(OH_PackingOptions *options, bool needsPackDfxData)](#oh_packingoptions_setneedspackdfxdata) | 设置OH_PackingOptions结构体中的needsPackDfxData参数。 |
| [Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange(OH_PackingOptions *options, int32_t* desiredDynamicRange)](#oh_packingoptions_getdesireddynamicrange) | 获取编码时期望的图片动态范围。 |
| [Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange(OH_PackingOptions *options, int32_t desiredDynamicRange)](#oh_packingoptions_setdesireddynamicrange) | 设置编码时期望的图片动态范围。 |
| [Image_ErrorCode OH_PackingOptions_Release(OH_PackingOptions *options)](#oh_packingoptions_release) | 释放OH_PackingOptions指针。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_Create(OH_PackingOptionsForSequence **options)](#oh_packingoptionsforsequence_create) | 创建OH_PackingOptionsForSequence结构体的指针。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_SetFrameCount(OH_PackingOptionsForSequence *options, uint32_t frameCount)](#oh_packingoptionsforsequence_setframecount) | 设置编码时指定的帧数。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_GetFrameCount(OH_PackingOptionsForSequence *options, uint32_t *frameCount)](#oh_packingoptionsforsequence_getframecount) | 获取编码时指定的帧数。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_SetDelayTimeList(OH_PackingOptionsForSequence *options, int32_t *delayTimeList, size_t delayTimeListLength)](#oh_packingoptionsforsequence_setdelaytimelist) | 设定编码时图片的延迟时间数组。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_GetDelayTimeList(OH_PackingOptionsForSequence *options, int32_t *delayTimeList, size_t delayTimeListLength)](#oh_packingoptionsforsequence_getdelaytimelist) | 获取编码时图片的延迟时间数组。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_SetDisposalTypes(OH_PackingOptionsForSequence *options, uint32_t *disposalTypes, size_t disposalTypesLength)](#oh_packingoptionsforsequence_setdisposaltypes) | 设定编码时图片的过渡帧模式数组。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_GetDisposalTypes(OH_PackingOptionsForSequence *options, uint32_t *disposalTypes, size_t disposalTypesLength)](#oh_packingoptionsforsequence_getdisposaltypes) | 获取编码时图片的过渡帧模式数组。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_SetLoopCount(OH_PackingOptionsForSequence *options, uint32_t loopCount)](#oh_packingoptionsforsequence_setloopcount) | 设定编码时图片循环播放次数，取值范围为[0, 65535]，0表示无限循环；若无此字段，则表示不循环播放。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_GetLoopCount(OH_PackingOptionsForSequence *options, uint32_t *loopCount)](#oh_packingoptionsforsequence_getloopcount) | 获取编码时图片循环播放次数。 |
| [Image_ErrorCode OH_PackingOptionsForSequence_Release(OH_PackingOptionsForSequence *options)](#oh_packingoptionsforsequence_release) | 释放OH_PackingOptionsForSequence指针。 |
| [Image_ErrorCode OH_ImagePackerNative_Create(OH_ImagePackerNative **imagePacker)](#oh_imagepackernative_create) | 创建OH_ImagePackerNative指针。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_ImageSourceNative *imageSource, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafromimagesource) | 将ImageSource编码为指定格式的数据。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PixelmapNative *pixelmap, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafrompixelmap) | 将Pixelmap编码为指定格式的数据。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPicture(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PictureNative *picture, uint8_t *outData, size_t *size)](#oh_imagepackernative_packtodatafrompicture) | 将Picture编码为指定格式的数据。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmapSequence(OH_ImagePackerNative *imagePacker, OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence,size_t sequenceLength, uint8_t *outData, size_t *outDataSize)](#oh_imagepackernative_packtodatafrompixelmapsequence) | 将Pixelmap序列编码为数据。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_ImageSourceNative *imageSource, int32_t fd)](#oh_imagepackernative_packtofilefromimagesource) | 将一个ImageSource编码到文件中。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PixelmapNative *pixelmap, int32_t fd)](#oh_imagepackernative_packtofilefrompixelmap) | 将一个Pixelmap编码到文件中。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPicture(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PictureNative *picture, int32_t fd)](#oh_imagepackernative_packtofilefrompicture) | 将一个Picture编码到文件中。 |
| [Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmapSequence(OH_ImagePackerNative *imagePacker, OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, int32_t fd)](#oh_imagepackernative_packtofilefrompixelmapsequence) | 将一个Pixelmap序列编码到文件中。 |
| [Image_ErrorCode OH_ImagePackerNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)](#oh_imagepackernative_getsupportedformats) | 获取支持编码的图片格式。 |
| [Image_ErrorCode OH_ImagePackerNative_Release(OH_ImagePackerNative *imagePacker)](#oh_imagepackernative_release) | 释放OH_ImagePackerNative指针。 |

## 枚举类型说明

### IMAGE_PACKER_DYNAMIC_RANGE

```c
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

```c
Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)
```

**描述**

创建PackingOptions结构体的指针。

使用约束：options不能为空指针；接口返回失败时，输出参数内容不应使用。

资源管理：接口成功返回的OH_PackingOptions对象由调用方管理，使用完成后应调用[OH_PackingOptions_Release](#oh_packingoptions_release)释放。

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

```c
Image_ErrorCode OH_PackingOptions_GetMimeType(OH_PackingOptions *options,Image_MimeType *format)
```

**描述**

获取编码参数中的MIME类型。该接口获取的format.data缺少字符串结束符'\0'，请谨慎使用。

使用约束：options和format均不能为空指针。调用前若format->size不为0，则format->size必须大于或等于当前MIME类型长度。接口返回失败时，不应读取format.data。

资源管理：接口执行成功后，format.data由接口分配，调用方使用完成后应使用free()释放。该接口返回的format.data不以字符串结束符'\0'结尾，如需按C字符串处理，建议使用[OH_PackingOptions_GetMimeTypeWithNull](#oh_packingoptions_getmimetypewithnull)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | 图像格式。format无需手动初始化，系统将分配内存，但必须在使用后释放内存。<br>该接口获取到的format.data缺少字符串结束符'\0'，需要检查实际数据长度是否超出了申请缓冲区的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_GetMimeTypeWithNull()

```c
Image_ErrorCode OH_PackingOptions_GetMimeTypeWithNull(OH_PackingOptions *options,Image_MimeType *format)
```

**描述**

获取编码参数中的MIME类型。该接口获取的format.data以字符串结束符'\0'结尾。

使用场景：适用于读取字符串形式的MIME类型。与[OH_PackingOptions_GetMimeType](#oh_packingoptions_getmimetype)相比，本接口返回的format.data以'\0'结尾，更适合直接按C字符串处理。

使用约束：options和format均不能为空指针。调用前若format->size不为0，则format->size必须大于或等于当前MIME类型长度。接口返回失败时，不应读取format.data。

资源管理：接口执行成功后，format.data由接口分配，调用方使用完成后应使用free()释放。

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

```c
Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options,Image_MimeType *format)
```

**描述**

设置MIME类型。

使用场景：用于设置OH_PackingOptions的目标编码格式。使用OH_PackingOptions进行ImageSource、PixelMap或Picture编码前，必须调用本接口设置MIME类型。未设置MIME类型时，编码接口会返回参数错误。

使用约束：options、format和format->data均不能为空指针，format->size必须大于0。format必须为支持编码的MIME类型，可通过[OH_ImagePackerNative_GetSupportedFormats](#oh_imagepackernative_getsupportedformats)查询支持编码的图片格式。

资源管理：接口会拷贝传入的MIME类型数据，不持有调用方传入的format->data指针。接口返回后，调用方仍需自行管理format的生命周期。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| [Image_MimeType](capi-image-nativemodule-image-string.md) *format | 目标编码格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_GetQuality()

```c
Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options,uint32_t *quality)
```

**描述**

获取编码质量。

使用约束：options和quality均不能为空指针。接口返回失败时，输出参数内容不应使用。

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

```c
Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options,uint32_t quality)
```

**描述**

设置编码质量。

使用约束：options不能为空指针，quality取值范围为[0, 100]。OH_PackingOptions创建后，quality默认值为0，建议设置quality不低于80。quality的实际效果取决于目标编码格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| uint32_t quality | 编码质量，取值范围为[0, 100]，默认值为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_GetNeedsPackProperties()

```c
 Image_ErrorCode OH_PackingOptions_GetNeedsPackProperties(OH_PackingOptions *options,bool *needsPackProperties)
```

**描述**

获取OH_PackingOptions结构体的needsPackProperties参数。

使用约束：options和needsPackProperties均不能为空指针。接口返回失败时，输出参数内容不应使用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| bool *needsPackProperties | 是否需要编码图片属性信息（例如Exif）。true表示需要，false表示不需要。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_SetNeedsPackProperties()

```c
Image_ErrorCode OH_PackingOptions_SetNeedsPackProperties(OH_PackingOptions *options,bool needsPackProperties)
```

**描述**

设置OH_PackingOptions结构体的needsPackProperties参数。

使用场景：当需要在编码输出中保留或写入图片属性信息（例如Exif）时，将needsPackProperties设置为true。如果只关心像素内容、希望减少输出数据体积或目标格式不需要保留属性信息，可设置为false。

使用约束：options不能为空指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| bool needsPackProperties | 是否需要编码图片属性信息（例如Exif）。true表示需要，false表示不需要。默认值为false。<br>如果原始图片本身没有Exif数据，那么即使设置needsPackProperties为true，输出文件也不会包含这些属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |
<!--Del-->
### OH_PackingOptions_GetNeedsPackDfxData()

```c
Image_ErrorCode OH_PackingOptions_GetNeedsPackDfxData(OH_PackingOptions *options, bool *needsPackDfxData)
```

**描述**

获取OH_PackingOptions结构体中的needsPackDfxData参数。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 指向OH_PackingOptions结构体的指针。 |
| bool *needsPackDfxData | 图像DFX数据是否需要编码。true表示图像DFX数据需要编码，false表示图像DFX数据不需要编码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_PACKER_INVALID_PARAMETER：options或needsPackDfxData为空指针。</li><br>         </ul> |

### OH_PackingOptions_SetNeedsPackDfxData()

```c
Image_ErrorCode OH_PackingOptions_SetNeedsPackDfxData(OH_PackingOptions *options, bool needsPackDfxData)
```

**描述**

设置OH_PackingOptions结构体中的needsPackDfxData参数。

**起始版本：** 26.0.0

**系统接口：** 该接口为系统接口。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 指向OH_PackingOptions结构体的指针。 |
| bool needsPackDfxData | 图像DFX数据是否需要编码。true表示图像DFX数据需要编码，false表示图像DFX数据不需要编码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | <ul><br>         <li>IMAGE_SUCCESS：执行成功。</li><br>         <li>202：非系统应用程序调用该接口则返回此错误码。</li><br>         <li>IMAGE_PACKER_INVALID_PARAMETER：options为空指针。</li><br>         </ul> |
<!--DelEnd-->
### OH_PackingOptions_GetDesiredDynamicRange()

```c
Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange(OH_PackingOptions *options, int32_t* desiredDynamicRange)
```

**描述**

获取编码时期望的图片动态范围。

使用约束：options和desiredDynamicRange均不能为空指针。接口返回失败时，输出参数内容不应使用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| int32_t* desiredDynamicRange | 期望的动态范围[IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_SetDesiredDynamicRange()

```c
Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange(OH_PackingOptions *options, int32_t desiredDynamicRange)
```

**描述**

设置编码时期望的图片动态范围。

使用约束：options不能为空指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptions](capi-image-nativemodule-oh-packingoptions.md) *options | 被操作的OH_PackingOptions指针。 |
| int32_t desiredDynamicRange | 期望的动态范围[IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range)。默认值为IMAGE_PACKER_DYNAMIC_RANGE_SDR。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptions_Release()

```c
Image_ErrorCode OH_PackingOptions_Release(OH_PackingOptions *options)
```

**描述**

释放OH_PackingOptions指针。

使用约束：options不能为空指针。

资源管理：由[OH_PackingOptions_Create](#oh_packingoptions_create)成功创建的对象，都应在编码完成后调用本接口释放。释放OH_PackingOptions不会影响已经完成的编码输出，也不会释放OH_ImagePackerNative对象；调用该接口后，options指向的OH_PackingOptions对象会被释放，不应继续使用。

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

```c
Image_ErrorCode OH_PackingOptionsForSequence_Create(OH_PackingOptionsForSequence **options)
```

**描述**

创建OH_PackingOptionsForSequence结构体的指针。

使用约束：options不能为空指针。接口返回失败时，输出参数内容不应使用。

资源管理：接口成功返回的OH_PackingOptionsForSequence对象由调用方管理，使用完成后应调用[OH_PackingOptionsForSequence_Release](#oh_packingoptionsforsequence_release)释放。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) **options | 用于操作的OH_PackingOptionsForSequence指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_SetFrameCount()

```c
Image_ErrorCode OH_PackingOptionsForSequence_SetFrameCount(OH_PackingOptionsForSequence *options,uint32_t frameCount)
```

**描述**

设置编码时指定的帧数。

使用约束：options不能为空指针。

**起始版本：** 18


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

```c
Image_ErrorCode OH_PackingOptionsForSequence_GetFrameCount(OH_PackingOptionsForSequence *options,uint32_t *frameCount)
```

**描述**

获取编码时指定的帧数。

使用约束：options和frameCount均不能为空指针。接口返回失败时，输出参数内容不应使用。

**起始版本：** 18


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

```c
Image_ErrorCode OH_PackingOptionsForSequence_SetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)
```

**描述**

设定编码时图片的延迟时间数组。

使用约束：options不能为空指针。

资源管理：接口会保存传入的delayTimeList指针，不拷贝数组内容。调用方需保证OH_PackingOptionsForSequence对象使用期间delayTimeList指向的数据有效。多次调用该接口时，新的delayTimeList指针会替换此前保存的指针。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |
| int32_t *delayTimeList | 图片延迟时间数组的指针。延迟时间的单位为10毫秒（ms）。 |
| size_t delayTimeListLength | 图片延迟时间数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PackingOptionsForSequence_GetDelayTimeList()

```c
Image_ErrorCode OH_PackingOptionsForSequence_GetDelayTimeList(OH_PackingOptionsForSequence *options,int32_t *delayTimeList, size_t delayTimeListLength)
```

**描述**

获取编码时图片的延迟时间数组。

使用约束：options和delayTimeList均不能为空指针，delayTimeListLength必须大于0。接口会将已设置的延迟时间数组拷贝到调用方传入的delayTimeList缓冲区。接口返回失败时，输出缓冲区内容不应使用。

**起始版本：** 18


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

```c
Image_ErrorCode OH_PackingOptionsForSequence_SetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)
```

**描述**

设定编码时图片的过渡帧模式数组。

使用约束：options不能为空指针。

资源管理：接口会保存传入的disposalTypes指针，不拷贝数组内容。调用方需保证OH_PackingOptionsForSequence对象使用期间disposalTypes指向的数据有效。多次调用该接口时，新的disposalTypes指针会替换此前保存的指针。

**起始版本：** 18


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

```c
Image_ErrorCode OH_PackingOptionsForSequence_GetDisposalTypes(OH_PackingOptionsForSequence *options,uint32_t *disposalTypes, size_t disposalTypesLength)
```

**描述**

获取编码时图片的过渡帧模式数组。

使用约束：options和disposalTypes均不能为空指针，disposalTypesLength必须大于0。接口会将已设置的过渡帧模式数组拷贝到调用方传入的disposalTypes缓冲区。接口返回失败时，输出缓冲区内容不应使用。

**起始版本：** 18


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

```c
Image_ErrorCode OH_PackingOptionsForSequence_SetLoopCount(OH_PackingOptionsForSequence *options, uint32_t loopCount)
```

**描述**

设定编码时图片循环播放次数，取值范围为[0, 65535]，0表示无限循环；若无此字段，则表示不循环播放。

使用约束：options不能为空指针。本接口仅保存传入的loopCount。当loopCount大于65535时，本接口仍会返回成功，但后续调用[OH_ImagePackerNative_PackToDataFromPixelmapSequence](#oh_imagepackernative_packtodatafrompixelmapsequence)或[OH_ImagePackerNative_PackToFileFromPixelmapSequence](#oh_imagepackernative_packtofilefrompixelmapsequence)编码时会返回参数错误。

**起始版本：** 18


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

```c
Image_ErrorCode OH_PackingOptionsForSequence_GetLoopCount(OH_PackingOptionsForSequence *options, uint32_t *loopCount)
```

**描述**

获取编码时图片循环播放次数。

使用约束：options和loopCount均不能为空指针。接口返回失败时，输出参数内容不应使用。

**起始版本：** 18


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

```c
Image_ErrorCode OH_PackingOptionsForSequence_Release(OH_PackingOptionsForSequence *options)
```

**描述**

释放OH_PackingOptionsForSequence指针。

使用约束：options不能为空指针。

资源管理：调用该接口后，options指向的OH_PackingOptionsForSequence对象会被释放，不应继续使用。释放OH_PackingOptionsForSequence对象不会释放通过[OH_PackingOptionsForSequence_SetDelayTimeList](#oh_packingoptionsforsequence_setdelaytimelist)或[OH_PackingOptionsForSequence_SetDisposalTypes](#oh_packingoptionsforsequence_setdisposaltypes)传入的数组。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 用于操作的OH_PackingOptionsForSequence指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImagePackerNative_Create()

```c
Image_ErrorCode OH_ImagePackerNative_Create(OH_ImagePackerNative **imagePacker)
```

**描述**

创建OH_ImagePackerNative指针。

使用场景：适用于将ImageSource、PixelMap、Picture或PixelMap序列编码为JPEG、PNG、WebP等格式的数据或文件。创建ImagePacker后，需要结合OH_PackingOptions或OH_PackingOptionsForSequence设置编码格式、质量、是否保留图片属性等参数。

使用约束：imagePacker不能为空指针。接口返回失败时，输出参数内容不应使用。

资源管理：成功创建的OH_ImagePackerNative对象由调用方持有，使用完成后必须调用[OH_ImagePackerNative_Release](#oh_imagepackernative_release)释放。Packer不会接管输入ImageSource、PixelMap、Picture或编码参数对象的生命周期。

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

```c
Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, uint8_t *outData, size_t *size)
```

**描述**

将ImageSource编码为指定格式的数据。

使用场景：适用于将已有ImageSource转码为另一种图片格式，或在修改图片属性后重新输出为内存数据。

使用约束：imagePacker、options、imageSource、outData和size均不能为空指针。调用前，*size应设置为outData的容量。接口返回失败时，不应使用outData中的内容或size输出值。

资源管理：outData由调用方申请和释放。调用前，*size应设置为outData可写缓冲区大小。调用成功后，*size会更新为实际写入的编码数据长度。imagePacker、options和imageSource的生命周期仍由调用方管理，本接口不会释放这些对象。

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

```c
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, uint8_t *outData, size_t *size)
```

**描述**

将Pixelmap编码为指定格式的数据。

使用场景：适用于将解码、编辑、绘制或算法处理后的PixelMap编码为JPEG、PNG、WebP等格式的内存数据，以便上传、缓存或继续写入文件。

使用约束：imagePacker、options、pixelmap、outData和size均不能为空指针。调用前，*size应设置为outData的容量；接口返回失败时，不应使用outData中的内容或size输出值。

资源管理：outData由调用方申请和释放。调用前，*size应设置为outData可写缓冲区大小。调用成功后，*size会更新为实际写入的编码数据长度。imagePacker、options和pixelmap的生命周期仍由调用方管理，本接口不会释放这些对象。

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

```c
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, uint8_t *outData, size_t *size)
```

**描述**

将Picture编码为指定格式的数据。

使用约束：imagePacker、options、picture、outData和size均不能为空指针。调用前，*size应设置为outData的容量。接口返回失败时，不应使用outData中的内容或size输出值。

资源管理：outData由调用方申请和释放。调用前，*size应设置为outData可写缓冲区大小。调用成功后，*size会更新为实际写入的编码数据长度。imagePacker、options和picture的生命周期仍由调用方管理，本接口不会释放这些对象。

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

```c
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence,size_t sequenceLength, uint8_t *outData, size_t *outDataSize)
```

**描述**

将Pixelmap序列编码为数据。

使用场景：适用于将多帧PixelMap编码为动图或其他支持序列帧的图片格式。编码前应通过OH_PackingOptionsForSequence设置帧数、延迟时间、循环次数等参数。

使用约束：接口返回失败时，不应使用outData中的内容或outDataSize输出值。

资源管理：outData由调用方申请和释放。imagePacker、options和pixelmapSequence中PixelMap对象的生命周期仍由调用方管理，本接口不会释放这些对象。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针，不允许为NULL。 |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 编码选项参数，不允许为NULL。frameCount必须大于0，需设置有效的delayTimeList，loopCount取值范围为[0, 65535]。delayTimeList中的每个延迟时间必须大于0且不超过65535，单位为10毫秒（ms）。disposalTypes中的每个取值必须小于等于3。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapSequence | 用于编码的Pixelmap序列指针，不允许为NULL。数组中用于编码的Pixelmap指针不允许为NULL。 |
| size_t sequenceLength | 用于编码的Pixelmap序列长度，必须大于0。 |
| uint8_t *outData | 用于存储编码后图像输出数据的缓冲区，不允许为NULL。 |
| size_t *outDataSize | 用于存储编码后图像输出数据缓冲区大小的指针，不允许为NULL。调用前，*outDataSize应设置为outData可写缓冲区大小；调用成功后，*outDataSize会更新为实际写入的编码数据长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。 |

### OH_ImagePackerNative_PackToFileFromImageSource()

```c
Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_ImageSourceNative *imageSource, int32_t fd)
```

**描述**

将一个ImageSource编码到文件中。

使用场景：适用于将ImageSource转码后直接写入文件描述符，避免调用方自行管理编码后的内存缓冲区。

使用约束：imagePacker、options和imageSource均不能为空指针，fd必须为可写文件描述符。

资源管理：fd必须是可写文件描述符，文件描述符的打开和关闭由调用方负责。接口不会释放imagePacker、options或imageSource。

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

```c
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PixelmapNative *pixelmap, int32_t fd)
```

**描述**

将一个Pixelmap编码到文件中。

使用场景：适用于将处理后的PixelMap直接保存为文件。与PackToDataFromPixelmap相比，该接口不需要调用方预先分配输出数据缓冲区。

使用约束：imagePacker、options和pixelmap均不能为空指针，fd必须为可写文件描述符。

资源管理：fd必须是可写文件描述符，文件描述符的打开和关闭由调用方负责。接口不会释放imagePacker、options或pixelmap。

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

```c
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPicture(OH_ImagePackerNative *imagePacker,OH_PackingOptions *options, OH_PictureNative *picture, int32_t fd)
```

**描述**

将一个Picture编码到文件中。

使用约束：imagePacker、options和picture均不能为空指针，fd必须为可写文件描述符。

资源管理：fd的打开和关闭由调用方负责。接口不会释放imagePacker、options或picture。

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

```c
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmapSequence(OH_ImagePackerNative *imagePacker,OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, int32_t fd)
```

**描述**

将一个Pixelmap序列编码到文件中。

使用约束：接口返回失败时，目标文件中的内容不应继续使用。

资源管理：fd的打开和关闭由调用方负责。接口不会释放imagePacker、options或pixelmapSequence中的PixelMap对象。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针，不允许为NULL。 |
| [OH_PackingOptionsForSequence](capi-image-nativemodule-oh-packingoptionsforsequence.md) *options | 编码选项参数，不允许为NULL。frameCount必须大于0，需设置有效的delayTimeList，loopCount取值范围为[0, 65535]。delayTimeList中的每个延迟时间必须大于0且不超过65535。disposalTypes中的每个取值必须小于等于3。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapSequence | 用于编码的Pixelmap序列指针，不允许为NULL。数组中用于编码的Pixelmap指针不允许为NULL。 |
| size_t sequenceLength | 用于编码的Pixelmap序列长度，必须大于0。 |
| int32_t fd | 文件描述符，必须为可写文件描述符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_DECODE_FAILED：解码失败。 |

### OH_ImagePackerNative_GetSupportedFormats()

```c
Image_ErrorCode OH_ImagePackerNative_GetSupportedFormats(Image_MimeType **supportedFormats, size_t *length)
```

**描述**

获取支持编码的图片格式。

使用场景：适用于在编码前动态查询当前系统支持的目标格式，并据此设置[OH_PackingOptions_SetMimeType](#oh_packingoptions_setmimetype)的MIME类型。

使用约束：supportedFormats和length均不能为空指针。接口返回失败时，输出参数内容不应使用。

资源管理：接口成功返回的supportedFormats数组由系统内部管理，调用方不需要也不应释放或修改。如需长期保存，应自行拷贝数组内容。

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

```c
Image_ErrorCode OH_ImagePackerNative_Release(OH_ImagePackerNative *imagePacker)
```

**描述**

释放OH_ImagePackerNative指针。

使用约束：imagePacker不能为空指针。

资源管理：由[OH_ImagePackerNative_Create](#oh_imagepackernative_create)成功创建的对象，在使用完毕后必须调用本接口释放。释放Packer不会释放OH_PackingOptions、OH_PackingOptionsForSequence、OH_ImageSourceNative、OH_PixelmapNative或OH_PictureNative对象。调用该接口后，imagePacker指向的OH_ImagePackerNative对象会被释放，不应继续使用。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImagePackerNative](capi-image-nativemodule-oh-imagepackernative.md) *imagePacker | 被操作的OH_ImagePackerNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |


