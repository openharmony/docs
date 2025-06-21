# picture_native.h

## 概述

提供获取picture数据和信息的API。

**库：** libpicture.so

**起始版本：** 13

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) | OH_PictureNative | Picture结构体类型，用于执行picture相关操作。 |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) | OH_AuxiliaryPictureNative | AuxiliaryPicture结构体类型，用于执行AuxiliaryPicture相关操作。 |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) | OH_AuxiliaryPictureInfo | AuxiliaryPictureInfo结构体类型，用于执行AuxiliaryPictureInfo相关操作。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) | Image_AuxiliaryPictureType | 辅助图类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Image_ErrorCode OH_PictureNative_CreatePicture(OH_PixelmapNative *mainPixelmap, OH_PictureNative **picture)](#oh_picturenative_createpicture) | 创建OH_PictureNative指针。 |
| [Image_ErrorCode OH_PictureNative_GetMainPixelmap(OH_PictureNative *picture, OH_PixelmapNative **mainPixelmap)](#oh_picturenative_getmainpixelmap) | 获取主图的OH_PixelmapNative指针。 |
| [Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmap(OH_PictureNative *picture, OH_PixelmapNative **hdrPixelmap)](#oh_picturenative_gethdrcomposedpixelmap) | 获取hdr图的OH_PixelmapNative指针。 |
| [Image_ErrorCode OH_PictureNative_GetGainmapPixelmap(OH_PictureNative *picture, OH_PixelmapNative **gainmapPixelmap)](#oh_picturenative_getgainmappixelmap) | 获取增益图的OH_PixelmapNative指针。 |
| [Image_ErrorCode OH_PictureNative_SetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type,OH_AuxiliaryPictureNative *auxiliaryPicture)](#oh_picturenative_setauxiliarypicture) | 设置辅助图。 |
| [Image_ErrorCode OH_PictureNative_GetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type,OH_AuxiliaryPictureNative **auxiliaryPicture)](#oh_picturenative_getauxiliarypicture) | 根据类型获取辅助图。 |
| [Image_ErrorCode OH_PictureNative_GetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType,OH_PictureMetadata **metadata)](#oh_picturenative_getmetadata) | 获取主图的元数据。 |
| [Image_ErrorCode OH_PictureNative_SetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType,OH_PictureMetadata *metadata)](#oh_picturenative_setmetadata) | 设置主图的元数据。 |
| [Image_ErrorCode OH_PictureNative_Release(OH_PictureNative *picture)](#oh_picturenative_release) | 释放OH_PictureNative指针。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_Create(uint8_t *data, size_t dataLength, Image_Size *size,Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)](#oh_auxiliarypicturenative_create) | 创建OH_AuxiliaryPictureNative指针。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_WritePixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *source,size_t bufferSize)](#oh_auxiliarypicturenative_writepixels) | 读取缓冲区的图像像素数据，并将结果写入辅助图中。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_ReadPixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *destination,size_t *bufferSize)](#oh_auxiliarypicturenative_readpixels) | 读取辅助图的像素数据，结果写入缓冲区。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetType(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_AuxiliaryPictureType *type)](#oh_auxiliarypicturenative_gettype) | 获取辅助图类型。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,OH_AuxiliaryPictureInfo **info)](#oh_auxiliarypicturenative_getinfo) | 获取辅助图信息。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,OH_AuxiliaryPictureInfo *info)](#oh_auxiliarypicturenative_setinfo) | 设置辅助图信息。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_GetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_MetadataType metadataType, OH_PictureMetadata **metadata)](#oh_auxiliarypicturenative_getmetadata) | 获取辅助图的元数据。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_SetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_MetadataType metadataType, OH_PictureMetadata *metadata)](#oh_auxiliarypicturenative_setmetadata) | 设置辅助图的元数据。 |
| [Image_ErrorCode OH_AuxiliaryPictureNative_Release(OH_AuxiliaryPictureNative *picture)](#oh_auxiliarypicturenative_release) | 释放OH_AuxiliaryPictureNative指针。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_Create(OH_AuxiliaryPictureInfo **info)](#oh_auxiliarypictureinfo_create) | 创建一个OH_AuxiliaryPictureInfo对象。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType *type)](#oh_auxiliarypictureinfo_gettype) | 获取辅助图的图片信息的辅助图类型。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType type)](#oh_auxiliarypictureinfo_settype) | 设置辅助图的图片信息的辅助图类型。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)](#oh_auxiliarypictureinfo_getsize) | 获取辅助图的图片尺寸。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)](#oh_auxiliarypictureinfo_setsize) | 设置辅助图的图片尺寸。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t *rowStride)](#oh_auxiliarypictureinfo_getrowstride) | 获取辅助图的图片信息的行跨距。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t rowStride)](#oh_auxiliarypictureinfo_setrowstride) | 设置辅助图的图片信息的行跨距。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_GetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT *pixelFormat)](#oh_auxiliarypictureinfo_getpixelformat) | 获取辅助图的图片信息的像素格式。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_SetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT pixelFormat)](#oh_auxiliarypictureinfo_setpixelformat) | 设置辅助图的图片信息的像素格式。 |
| [Image_ErrorCode OH_AuxiliaryPictureInfo_Release(OH_AuxiliaryPictureInfo *info)](#oh_auxiliarypictureinfo_release) | 释放OH_AuxiliaryPictureInfo指针。 |

## 枚举类型说明

### Image_AuxiliaryPictureType

```
enum Image_AuxiliaryPictureType
```

**描述**

辅助图类型

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| AUXILIARY_PICTURE_TYPE_GAINMAP = 1 | 增益图，代表了一种增强SDR图像以产生具有可变显示调整能力的HDR图像的机制。它是一组描述如何应用gainmap元数据的组合。 |
| AUXILIARY_PICTURE_TYPE_DEPTH_MAP = 2 | 深度图，储存图像的深度数据，通过捕捉每个像素与摄像机之间的距离，提供场景的三维结构信息，通常用于3D重建和场景理解。 |
| AUXILIARY_PICTURE_TYPE_UNREFOCUS_MAP = 3 | 人像未对焦的原图，提供了一种在人像拍摄中突出背景模糊效果的方式，能够帮助用户在后期处理中选择焦点区域，增加创作自由度。 |
| AUXILIARY_PICTURE_TYPE_LINEAR_MAP = 4 | 线性图，用于提供额外的数据视角或补充信息，通常用于视觉效果的增强，它可以包含场景中光照、颜色或其他视觉元素的线性表示。 |
| AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP = 5 | 水印裁剪图，表示在原图中被水印覆盖的区域，该图像用于修复或移除水印影响，恢复图像的完整性和可视性。 |


## 函数说明

### OH_PictureNative_CreatePicture()

```
Image_ErrorCode OH_PictureNative_CreatePicture(OH_PixelmapNative *mainPixelmap, OH_PictureNative **picture)
```

**描述**

创建OH_PictureNative指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *mainPixelmap | 主图的OH_PixelmapNative指针。 |
| [OH_PictureNative](capi-oh-picturenative.md) **picture | 被创建的OH_PictureNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PictureNative_GetMainPixelmap()

```
Image_ErrorCode OH_PictureNative_GetMainPixelmap(OH_PictureNative *picture, OH_PixelmapNative **mainPixelmap)
```

**描述**

获取主图的OH_PixelmapNative指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *picture | 被操作的OH_PictureNative指针。 |
| [OH_PictureNative](capi-oh-picturenative.md) **mainPixelmap | 获取的OH_PixelmapNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PictureNative_GetHdrComposedPixelmap()

```
Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmap(OH_PictureNative *picture, OH_PixelmapNative **hdrPixelmap)
```

**描述**

获取hdr图的OH_PixelmapNative指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *picture | 被操作的OH_PictureNative指针。 |
| [OH_PictureNative](capi-oh-picturenative.md) **hdrPixelmap | 获取的hdr图OH_PixelmapNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br> IMAGE_UNSUPPORTED_OPERATION：操作不支持，例如picture对象中不包含增益图。 |

### OH_PictureNative_GetGainmapPixelmap()

```
Image_ErrorCode OH_PictureNative_GetGainmapPixelmap(OH_PictureNative *picture, OH_PixelmapNative **gainmapPixelmap)
```

**描述**

获取增益图的OH_PixelmapNative指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *picture | 被操作的OH_PictureNative指针。 |
| [OH_PictureNative](capi-oh-picturenative.md) **gainmapPixelmap | 获取的增益图OH_PixelmapNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PictureNative_SetAuxiliaryPicture()

```
Image_ErrorCode OH_PictureNative_SetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type,OH_AuxiliaryPictureNative *auxiliaryPicture)
```

**描述**

设置辅助图。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *picture | 被操作的OH_PictureNative指针。 |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type | 辅助图的类型。 |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *auxiliaryPicture | 设置的OH_AuxiliaryPictureNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PictureNative_GetAuxiliaryPicture()

```
Image_ErrorCode OH_PictureNative_GetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type,OH_AuxiliaryPictureNative **auxiliaryPicture)
```

**描述**

根据类型获取辅助图。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *picture | 被操作的OH_PictureNative指针。 |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type | 辅助图类型。 |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) **auxiliaryPicture | 获取的OH_AuxiliaryPictureNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PictureNative_GetMetadata()

```
Image_ErrorCode OH_PictureNative_GetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType,OH_PictureMetadata **metadata)
```

**描述**

获取主图的元数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *picture | 被操作的OH_PictureNative指针。 |
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) metadataType | 元数据类型。 |
| [OH_PictureMetadata](capi-oh-picturemetadata.md) **metadata | 主图的元数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br> IMAGE_UNSUPPORTED_METADATA：不支持的元数据类型。 |

### OH_PictureNative_SetMetadata()

```
Image_ErrorCode OH_PictureNative_SetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType,OH_PictureMetadata *metadata)
```

**描述**

设置主图的元数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *picture | 被操作的OH_PictureNative指针。 |
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) metadataType | 元数据类型。 |
| [OH_PictureMetadata](capi-oh-picturemetadata.md) *metadata | 将设置的元数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br> IMAGE_UNSUPPORTED_METADATA：不支持的元数据类型。 |

### OH_PictureNative_Release()

```
Image_ErrorCode OH_PictureNative_Release(OH_PictureNative *picture)
```

**描述**

释放OH_PictureNative指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PictureNative](capi-oh-picturenative.md) *picture | 被操作的OH_PictureNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureNative_Create()

```
Image_ErrorCode OH_AuxiliaryPictureNative_Create(uint8_t *data, size_t dataLength, Image_Size *size,Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)
```

**描述**

创建OH_AuxiliaryPictureNative指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *data | 图像数据。 |
| size_t dataLength | 图像数据长度。 |
| [Image_Size](capi-image-size.md) *size | 辅助图尺寸。 |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type | 辅助图类型。 |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) **auxiliaryPicture | 被创建的OH_AuxiliaryPictureNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureNative_WritePixels()

```
Image_ErrorCode OH_AuxiliaryPictureNative_WritePixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *source,size_t bufferSize)
```

**描述**

读取缓冲区的图像像素数据，并将结果写入辅助图中。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *auxiliaryPicture | 被操作的OH_AuxiliaryPictureNative指针。 |
| uint8_t *source | 将被写入的图像像素数据。 |
| size_t bufferSize | 图像像素数据长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br> IMAGE_ALLOC_FAILED：内存分配失败。<br> IMAGE_COPY_FAILED：内存拷贝失败。 |

### OH_AuxiliaryPictureNative_ReadPixels()

```
Image_ErrorCode OH_AuxiliaryPictureNative_ReadPixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *destination,size_t *bufferSize)
```

**描述**

读取辅助图的像素数据，结果写入缓冲区。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *auxiliaryPicture | 被操作的OH_AuxiliaryPictureNative指针。 |
| uint8_t *destination | 缓冲区，获取的辅助图像素数据写入到该内存区域内。 |
| size_t *bufferSize | 缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br> IMAGE_ALLOC_FAILED：内存分配失败。<br> IMAGE_COPY_FAILED：内存拷贝失败。 |

### OH_AuxiliaryPictureNative_GetType()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetType(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_AuxiliaryPictureType *type)
```

**描述**

获取辅助图类型。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *auxiliaryPicture | 被操作的OH_AuxiliaryPictureNative指针。 |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) *type | 辅助图类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureNative_GetInfo()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,OH_AuxiliaryPictureInfo **info)
```

**描述**

获取辅助图信息。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *auxiliaryPicture | 被操作的OH_AuxiliaryPictureNative指针。 |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) **info | 辅助图信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureNative_SetInfo()

```
Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture,OH_AuxiliaryPictureInfo *info)
```

**描述**

设置辅助图信息。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *auxiliaryPicture | 将操作的OH_AuxiliaryPictureNative指针。 |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将要设置的辅助图信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureNative_GetMetadata()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_MetadataType metadataType, OH_PictureMetadata **metadata)
```

**描述**

获取辅助图的元数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *auxiliaryPicture | 将操作的OH_AuxiliaryPictureNative指针。 |
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) metadataType | 元数据类型。 |
| [OH_PictureMetadata](capi-oh-picturemetadata.md) **metadata | 获取的元数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br> IMAGE_UNSUPPORTED_METADATA：不支持的元数据类型，或者元数据类型与辅助图片类型不匹配。 |

### OH_AuxiliaryPictureNative_SetMetadata()

```
Image_ErrorCode OH_AuxiliaryPictureNative_SetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture,Image_MetadataType metadataType, OH_PictureMetadata *metadata)
```

**描述**

设置辅助图的元数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *auxiliaryPicture | 将操作的OH_AuxiliaryPictureNative指针。 |
| [Image_MetadataType](capi-image-common-h.md#image_metadatatype) metadataType | 元数据类型。 |
| [OH_PictureMetadata](capi-oh-picturemetadata.md) *metadata | 将要设置的元数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br> IMAGE_UNSUPPORTED_METADATA：不支持的元数据类型，或者元数据类型与辅助图片类型不匹配。 |

### OH_AuxiliaryPictureNative_Release()

```
Image_ErrorCode OH_AuxiliaryPictureNative_Release(OH_AuxiliaryPictureNative *picture)
```

**描述**

释放OH_AuxiliaryPictureNative指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureNative](capi-oh-auxiliarypicturenative.md) *picture | 将操作的OH_AuxiliaryPictureNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_Create()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_Create(OH_AuxiliaryPictureInfo **info)
```

**描述**

创建一个OH_AuxiliaryPictureInfo对象。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) **info | 将操作的OH_AuxiliaryPictureInfo指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_GetType()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType *type)
```

**描述**

获取辅助图的图片信息的辅助图类型。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) *type | 获取的辅助图类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_SetType()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType type)
```

**描述**

设置辅助图的图片信息的辅助图类型。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type | 将要设置的辅助图类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_GetSize()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)
```

**描述**

获取辅助图的图片尺寸。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |
| [Image_Size](capi-image-size.md) *size | 获取的图片尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_SetSize()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)
```

**描述**

设置辅助图的图片尺寸。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |
| [Image_Size](capi-image-size.md) *size | 将要设置的图片尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_GetRowStride()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t *rowStride)
```

**描述**

获取辅助图的图片信息的行跨距。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |
| uint32_t *rowStride | 跨距，内存中每行像素所占的空间。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_SetRowStride()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t rowStride)
```

**描述**

设置辅助图的图片信息的行跨距。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |
| uint32_t rowStride | 跨距，内存中每行像素所占的空间。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_GetPixelFormat()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT *pixelFormat)
```

**描述**

获取辅助图的图片信息的像素格式。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) *pixelFormat | 获取的像素格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_SetPixelFormat()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT pixelFormat)
```

**描述**

设置辅助图的图片信息的像素格式。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |
| [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format) pixelFormat | 将要设置的像素格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_AuxiliaryPictureInfo_Release()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_Release(OH_AuxiliaryPictureInfo *info)
```

**描述**

释放OH_AuxiliaryPictureInfo指针。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AuxiliaryPictureInfo](capi-oh-auxiliarypictureinfo.md) *info | 将操作的OH_AuxiliaryPictureInfo指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |


