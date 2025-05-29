# image_native.h

## 概述

声明图像的剪辑矩形、大小和组件数据的接口函数。

**库：** libohimage.so

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ImageNative](capi-oh-imagenative.md) | OH_ImageNative | 为图像接口定义native层图像对象的别名。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Image_ErrorCode OH_ImageNative_GetImageSize(OH_ImageNative *image, Image_Size *size)](#oh_imagenative_getimagesize) | 获取native [OH_ImageNative](capi-oh-imagenative.md) 对象的 [Image_Size](capi-image-size.md) 信息。 |
| [Image_ErrorCode OH_ImageNative_GetComponentTypes(OH_ImageNative *image,uint32_t **types, size_t *typeSize)](#oh_imagenative_getcomponenttypes) | 获取native [OH_ImageNative](capi-oh-imagenative.md) 对象的组件列表信息。 |
| [Image_ErrorCode OH_ImageNative_GetByteBuffer(OH_ImageNative *image,uint32_t componentType, OH_NativeBuffer **nativeBuffer)](#oh_imagenative_getbytebuffer) | 获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中某个组件类型所对应的缓冲区。 |
| [Image_ErrorCode OH_ImageNative_GetBufferSize(OH_ImageNative *image,uint32_t componentType, size_t *size)](#oh_imagenative_getbuffersize) | 获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中某个组件类型所对应的缓冲区的大小。 |
| [Image_ErrorCode OH_ImageNative_GetRowStride(OH_ImageNative *image,uint32_t componentType, int32_t *rowStride)](#oh_imagenative_getrowstride) | 获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中某个组件类型所对应的像素行宽。 |
| [Image_ErrorCode OH_ImageNative_GetPixelStride(OH_ImageNative *image,uint32_t componentType, int32_t *pixelStride)
	](#oh_imagenative_getpixelstride) | 获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中某个组件类型所对应的像素大小。 |
| [Image_ErrorCode OH_ImageNative_GetTimestamp(OH_ImageNative *image, int64_t *timestamp)](#oh_imagenative_gettimestamp) | 获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中的时间戳信息 |
| [Image_ErrorCode OH_ImageNative_Release(OH_ImageNative *image)](#oh_imagenative_release) | 释放native [OH_ImageNative](capi-oh-imagenative.md) 对象。 |

## 函数说明

### OH_ImageNative_GetImageSize()

```
Image_ErrorCode OH_ImageNative_GetImageSize(OH_ImageNative *image, Image_Size *size)
```

**描述**

获取native [OH_ImageNative](capi-oh-imagenative.md) 对象的 [Image_Size](capi-image-size.md) 信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-oh-imagenative.md) *image | 表示 [OH_ImageNative](capi-oh-imagenative.md) native对象的指针。 |
| [Image_Size](capi-image-size.md) *size | 表示作为获取结果的 [Image_Size](capi-image-size.md) 对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 如果未知原因错误返回 IMAGE_UNKNOWN_ERROR；<br> 具体释义参考[Image_ErrorCode](capi-image-common-h.md#image_errorcode)。 |

### OH_ImageNative_GetComponentTypes()

```
Image_ErrorCode OH_ImageNative_GetComponentTypes(OH_ImageNative *image,uint32_t **types, size_t *typeSize)
```

**描述**

获取native [OH_ImageNative](capi-oh-imagenative.md) 对象的组件列表信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-oh-imagenative.md) *image | 表示 [OH_ImageNative](capi-oh-imagenative.md) native对象的指针。 |
| uint32_t **types | 表示作为获取结果的组件列表对象的指针。 |
| size_t *typeSize | 表示作为获取结果的组件列表中，元素个数的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考[Image_ErrorCode](capi-image-common-h.md#image_errorcode)。 |

### OH_ImageNative_GetByteBuffer()

```
Image_ErrorCode OH_ImageNative_GetByteBuffer(OH_ImageNative *image,uint32_t componentType, OH_NativeBuffer **nativeBuffer)
```

**描述**

获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中某个组件类型所对应的缓冲区。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-oh-imagenative.md) *image | 表示 [OH_ImageNative](capi-oh-imagenative.md) native对象的指针。 |
| uint32_t componentType | 表示组件的类型。 |
| [OH_NativeBuffer](../ArkGraphics2D/capi-oh-nativebuffer.md) **nativeBuffer | 表示作为获取结果的 [OH_NativeBuffer](../ArkGraphics2D/capi-oh-nativebuffer.md) 缓冲区对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考[Image_ErrorCode](capi-image-common-h.md#image_errorcode)。 |

### OH_ImageNative_GetBufferSize()

```
Image_ErrorCode OH_ImageNative_GetBufferSize(OH_ImageNative *image,uint32_t componentType, size_t *size)
```

**描述**

获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中某个组件类型所对应的缓冲区的大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-oh-imagenative.md) *image | 表示 [OH_ImageNative](capi-oh-imagenative.md) native对象的指针。 |
| uint32_t componentType | 表示组件的类型。 |
| size_t *size | 表示作为获取结果的缓冲区大小的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考[Image_ErrorCode](capi-image-common-h.md#image_errorcode)。 |

### OH_ImageNative_GetRowStride()

```
Image_ErrorCode OH_ImageNative_GetRowStride(OH_ImageNative *image,uint32_t componentType, int32_t *rowStride)
```

**描述**

获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中某个组件类型所对应的像素行宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-oh-imagenative.md) *image | 表示 [OH_ImageNative](capi-oh-imagenative.md) native对象的指针。 |
| uint32_t componentType | 表示组件的类型。 |
| int32_t *rowStride | 表示作为获取结果的像素行宽的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考[Image_ErrorCode](capi-image-common-h.md#image_errorcode)。 |

### OH_ImageNative_GetPixelStride()

```
Image_ErrorCode OH_ImageNative_GetPixelStride(OH_ImageNative *image,uint32_t componentType, int32_t *pixelStride)
	
```

**描述**

获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中某个组件类型所对应的像素大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-oh-imagenative.md) *image | 表示 [OH_ImageNative](capi-oh-imagenative.md) native对象的指针。 |
| uint32_t componentType | 表示组件的类型。 |
| pixelStride | 表示作为获取结果的像素大小的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考[Image_ErrorCode](capi-image-common-h.md#image_errorcode)。 |

### OH_ImageNative_GetTimestamp()

```
Image_ErrorCode OH_ImageNative_GetTimestamp(OH_ImageNative *image, int64_t *timestamp)
```

**描述**

获取native [OH_ImageNative](capi-oh-imagenative.md) 对象中的时间戳信息

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| 表示 | [OH_ImageNative](capi-oh-imagenative.md) native对象的指针。 |
| 表示作为获取结果的时间戳信息的指针。 |  |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考[Image_ErrorCode](capi-image-common-h.md#image_errorcode)。 |

### OH_ImageNative_Release()

```
Image_ErrorCode OH_ImageNative_Release(OH_ImageNative *image)
```

**描述**

释放native [OH_ImageNative](capi-oh-imagenative.md) 对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-oh-imagenative.md) *image | 表示 [OH_ImageNative](capi-oh-imagenative.md) native对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | 如果操作成功返回 IMAGE_SUCCESS；<br> 如果参数错误返回 IMAGE_BAD_PARAMETER；<br> 具体释义参考[Image_ErrorCode](capi-image-common-h.md#image_errorcode)。 |


