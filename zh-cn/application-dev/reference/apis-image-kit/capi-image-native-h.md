# image_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

声明图像的剪辑矩形、大小和组件数据的接口函数。

**引用文件：** <multimedia/image_framework/image/image_native.h>

**库：** libohimage.so

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) | OH_ImageNative | 为图像接口定义native层图像对象的别名。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Image_ErrorCode OH_ImageNative_GetImageSize(OH_ImageNative *image, Image_Size *size)](#oh_imagenative_getimagesize) | 获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象的[Image_Size](capi-image-nativemodule-image-size.md)信息。 |
| [Image_ErrorCode OH_ImageNative_GetComponentTypes(OH_ImageNative *image, uint32_t **types, size_t *typeSize)](#oh_imagenative_getcomponenttypes) | 获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象的组件列表信息。 |
| [Image_ErrorCode OH_ImageNative_GetByteBuffer(OH_ImageNative *image, uint32_t componentType, OH_NativeBuffer **nativeBuffer)](#oh_imagenative_getbytebuffer) | 获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中某个组件类型所对应的缓冲区。 |
| [Image_ErrorCode OH_ImageNative_GetBufferSize(OH_ImageNative *image, uint32_t componentType, size_t *size)](#oh_imagenative_getbuffersize) | 获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中某个组件类型所对应的缓冲区的大小。 |
| [Image_ErrorCode OH_ImageNative_GetRowStride(OH_ImageNative *image, uint32_t componentType, int32_t *rowStride)](#oh_imagenative_getrowstride) | 获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中某个组件类型所对应的像素行宽。 |
| [Image_ErrorCode OH_ImageNative_GetPixelStride(OH_ImageNative *image, uint32_t componentType, int32_t *pixelStride)](#oh_imagenative_getpixelstride) | 获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中某个组件类型所对应的像素大小。 |
| [Image_ErrorCode OH_ImageNative_GetTimestamp(OH_ImageNative *image, int64_t *timestamp)](#oh_imagenative_gettimestamp) | 获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中的时间戳信息。 |
| [Image_ErrorCode OH_ImageNative_Release(OH_ImageNative *image)](#oh_imagenative_release) | 释放Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象。 |

## 函数说明

### OH_ImageNative_GetImageSize()

```
Image_ErrorCode OH_ImageNative_GetImageSize(OH_ImageNative *image, Image_Size *size)
```

**描述**

获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象的[Image_Size](capi-image-nativemodule-image-size.md)信息。

如果OH_ImageNative对象所存储的是相机预览流数据，即YUV图像数据，那么获取到的Image_Size中的宽高分别对应YUV图像的宽高；如果OH_ImageNative对象所存储的是相机拍照流数据，即JPEG图像，由于已经是编码后的数据，Image_Size中的宽等于JPEG数据大小，高等于1。

OH_ImageNative对象所存储的数据是预览流还是拍照流，取决于应用将receiver中的surfaceId传给相机的previewOutput还是captureOutput。相机预览与拍照最佳实践请参考[预览流二次处理(C/C++)](../../media/camera/native-camera-preview-imageReceiver.md)与[拍照(C/C++)](../../media/camera/native-camera-shooting.md)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | 表示OH_ImageNative native对象的指针。 |
| [Image_Size](capi-image-nativemodule-image-size.md) *size | 表示作为获取结果的Image_Size对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。<br>IMAGE_UNKNOWN_ERROR：未知原因错误。 |

### OH_ImageNative_GetComponentTypes()

```
Image_ErrorCode OH_ImageNative_GetComponentTypes(OH_ImageNative *image,uint32_t **types, size_t *typeSize)
```

**描述**

获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象的组件列表信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | 表示OH_ImageNative native对象的指针。 |
| uint32_t **types | 表示作为获取结果的组件列表对象的指针。 |
| size_t *typeSize | 表示作为获取结果的组件列表中，元素个数的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageNative_GetByteBuffer()

```
Image_ErrorCode OH_ImageNative_GetByteBuffer(OH_ImageNative *image,uint32_t componentType, OH_NativeBuffer **nativeBuffer)
```

**描述**

获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中某个组件类型所对应的缓冲区。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | 表示OH_ImageNative native对象的指针。 |
| uint32_t componentType | 表示组件的类型。 |
| [OH_NativeBuffer](../apis-arkgraphics2d/capi-oh-nativebuffer-oh-nativebuffer.md) **nativeBuffer | 表示作为获取结果的OH_NativeBuffer缓冲区对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageNative_GetBufferSize()

```
Image_ErrorCode OH_ImageNative_GetBufferSize(OH_ImageNative *image,uint32_t componentType, size_t *size)
```

**描述**

获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中某个组件类型所对应的缓冲区的大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | 表示OH_ImageNative native对象的指针。 |
| uint32_t componentType | 表示组件的类型。 |
| size_t *size | 表示作为获取结果的缓冲区大小的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageNative_GetRowStride()

```
Image_ErrorCode OH_ImageNative_GetRowStride(OH_ImageNative *image,uint32_t componentType, int32_t *rowStride)
```

**描述**

获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中某个组件类型所对应的像素行宽。

读取相机预览流数据时，需要考虑按stride进行读取，具体用法参考[预览流二次处理(C/C++)](../../media/camera/native-camera-preview-imageReceiver.md)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | 表示OH_ImageNative native对象的指针。 |
| uint32_t componentType | 表示组件的类型。 |
| int32_t *rowStride | 表示作为获取结果的像素行宽的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageNative_GetPixelStride()

```
Image_ErrorCode OH_ImageNative_GetPixelStride(OH_ImageNative *image,uint32_t componentType, int32_t *pixelStride)
```

**描述**

获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中某个组件类型所对应的像素大小。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | 表示OH_ImageNative native对象的指针。 |
| uint32_t componentType | 表示组件的类型。 |
| int32_t *pixelStride | 表示作为获取结果的像素大小的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageNative_GetTimestamp()

```
Image_ErrorCode OH_ImageNative_GetTimestamp(OH_ImageNative *image, int64_t *timestamp)
```

**描述**

获取Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象中的时间戳信息。时间戳以纳秒为单位，通常是单调递增的。

时间戳的具体含义和基准取决于图像的生产者，在相机预览/拍照场景，生产者就是相机。来自不同生产者的图像的时间戳可能有不同的含义和基准，因此可能无法进行比较。

如果要获取某张照片的生成时间，可以通过[OH_ImageSourceNative_GetImageProperty](capi-image-source-native-h.md#oh_imagesourcenative_getimageproperty)接口读取相关的EXIF信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | 表示OH_ImageNative native对象的指针。 |
| int64_t *timestamp | 表示作为获取结果的时间戳信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |

### OH_ImageNative_Release()

```
Image_ErrorCode OH_ImageNative_Release(OH_ImageNative *image)
```

**描述**

释放Native [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md)对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_ImageNative](capi-image-nativemodule-oh-imagenative.md) *image | 表示OH_ImageNative native对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>IMAGE_BAD_PARAMETER：参数错误。 |


