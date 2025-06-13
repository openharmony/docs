# image_effect_filter.h

## 概述

声明滤镜相关接口。

开发者可以通过滤镜的接口快速实现基本的效果处理，也可以将滤镜添加到效果器中，组合成滤镜链串联执行。系统提供了如“亮度”、“裁剪”等基本的效果处理滤镜。

**库：** libimage_effect.so

**引用文件：** <multimedia/image_effect/image_effect_filter.h>

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**相关模块：** [ImageEffect](capi-imageeffect.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ImageEffect_DataValue](capi-imageeffect-datavalue.md) | ImageEffect_DataValue | 数据值联合体。 |
| [OH_EffectFilter](capi-oh-effectfilter.md) | OH_EffectFilter | 定义滤镜结构类型。 |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) | OH_EffectFilterInfo | 定义滤镜信息结构体。 |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) | OH_EffectBufferInfo | 定义图像信息。 |
| [ImageEffect_Any](capi-imageeffect-any.md) | ImageEffect_Any | 参数结构体。 |
| [ImageEffect_FilterNames](capi-imageeffect-filternames.md) | ImageEffect_FilterNames | 滤镜名信息。 |
| [ImageEffect_FilterDelegate](capi-imageeffect-filterdelegate.md) | ImageEffect_FilterDelegate | 自定义滤镜回调函数结构体。 |
| [ImageEffect_Region](capi-imageeffect-region.md) | ImageEffect_Region | 图像区域结构体。 |
| [ImageEffect_Size](capi-imageeffect-size.md) | ImageEffect_Size | 图像尺寸结构体。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ImageEffect_DataType](#imageeffect_datatype) | ImageEffect_DataType | 数据类型枚举值。 |
| [ImageEffect_Format](#imageeffect_format) | ImageEffect_Format | 像素格式枚举值。 |
| [ImageEffect_BufferType](#imageeffect_buffertype) | ImageEffect_BufferType | 内存类型枚举值。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_EffectFilterInfo *OH_EffectFilterInfo_Create()](#oh_effectfilterinfo_create) | - | 创建OH_EffectFilterInfo实例，调用[OH_EffectFilterInfo_Release](capi-imageeffect-filternames.md#oh_effectfilterinfo_release)进行资源释放。 |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetFilterName(OH_EffectFilterInfo *info, const char *name)](#oh_effectfilterinfo_setfiltername) | - | 设置滤镜名。 |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetFilterName(OH_EffectFilterInfo *info, char **name)](#oh_effectfilterinfo_getfiltername) | - | 获取滤镜名。 |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_BufferType *bufferTypeArray)](#oh_effectfilterinfo_setsupportedbuffertypes) | - | 设置滤镜所支持的内存类型。 |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_BufferType **bufferTypeArray)](#oh_effectfilterinfo_getsupportedbuffertypes) | - | 获取滤镜所支持的内存类型。 |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedFormats(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_Format *formatArray)](#oh_effectfilterinfo_setsupportedformats) | - | 设置滤镜所支持的像素格式。 |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedFormats(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_Format **formatArray)](#oh_effectfilterinfo_getsupportedformats) | - | 获取滤镜所支持的像素格式。 |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_Release(OH_EffectFilterInfo *info)](#oh_effectfilterinfo_release) | - | 销毁OH_EffectFilterInfo实例。 |
| [OH_EffectBufferInfo *OH_EffectBufferInfo_Create()](#oh_effectbufferinfo_create) | - | 创建OH_EffectBufferInfo实例，调用[OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release)进行资源释放。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetAddr(OH_EffectBufferInfo *info, void *addr)](#oh_effectbufferinfo_setaddr) | - | 设置图像内存地址。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetAddr(OH_EffectBufferInfo *info, void **addr)](#oh_effectbufferinfo_getaddr) | - | 获取图像内存地址。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetWidth(OH_EffectBufferInfo *info, int32_t width)](#oh_effectbufferinfo_setwidth) | - | 设置图像宽度。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetWidth(OH_EffectBufferInfo *info, int32_t *width)](#oh_effectbufferinfo_getwidth) | - | 获取图像宽度。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetHeight(OH_EffectBufferInfo *info, int32_t height)](#oh_effectbufferinfo_setheight) | - | 设置图像高度。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetHeight(OH_EffectBufferInfo *info, int32_t *height)](#oh_effectbufferinfo_getheight) | - | 获取图像高度。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetRowSize(OH_EffectBufferInfo *info, int32_t rowSize)](#oh_effectbufferinfo_setrowsize) | - | 设置图像每一行的字节数。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetRowSize(OH_EffectBufferInfo *info, int32_t *rowSize)](#oh_effectbufferinfo_getrowsize) | - | 获取图像每一行的字节数。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format format)](#oh_effectbufferinfo_seteffectformat) | - | 设置图像的像素格式。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format *format)](#oh_effectbufferinfo_geteffectformat) | - | 获取图像的像素格式。 |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_Release(OH_EffectBufferInfo *info)](#oh_effectbufferinfo_release) | - | 销毁OH_EffectBufferInfo实例。 |
| [typedef bool (\*OH_EffectFilterDelegate_SetValue)(OH_EffectFilter *filter, const char *key,const ImageEffect_Any *value)](#oh_effectfilterdelegate_setvalue) | OH_EffectFilterDelegate_SetValue | 自定义滤镜设置参数的回调函数，用于开发者校验参数及参数值。 |
| [typedef void (\*OH_EffectFilterDelegate_PushData)(OH_EffectFilter *filter, OH_EffectBufferInfo *info)](#oh_effectfilterdelegate_pushdata) | OH_EffectFilterDelegate_PushData | 自定义滤镜传递图像信息到下一级滤镜的函数指针。需要在[OH_EffectFilterDelegate_Render](capi-image-effect-filter-h.md#oh_effectfilterdelegate_render)的回调中主动调用该函数指针。 |
| [typedef bool (\*OH_EffectFilterDelegate_Render)(OH_EffectFilter *filter, OH_EffectBufferInfo *info,OH_EffectFilterDelegate_PushData pushData)](#oh_effectfilterdelegate_render) | OH_EffectFilterDelegate_Render | 自定义滤镜渲染图像的回调函数。 |
| [typedef bool (\*OH_EffectFilterDelegate_Save)(OH_EffectFilter *filter, char **info)](#oh_effectfilterdelegate_save) | OH_EffectFilterDelegate_Save | 自定义滤镜序列化的回调函数，按照JSON格式进行滤镜序列化处理。 |
| [typedef OH_EffectFilter *(\*OH_EffectFilterDelegate_Restore)(const char *info)](#oh_effectfilterdelegate_restore) | OH_EffectFilterDelegate_Restore | 自定义滤镜反序列化的回调函数。 |
| [OH_EffectFilter *OH_EffectFilter_Create(const char *name)](#oh_effectfilter_create) | - | 创建OH_EffectFilter实例，调用[OH_EffectFilter_Release](#oh_effectfilter_release)进行资源释放。 |
| [ImageEffect_ErrorCode OH_EffectFilter_SetValue(OH_EffectFilter *filter, const char *key, const ImageEffect_Any *value)](#oh_effectfilter_setvalue) | - | 设置滤镜参数。 |
| [ImageEffect_ErrorCode OH_EffectFilter_GetValue(OH_EffectFilter *filter, const char *key, ImageEffect_Any *value)](#oh_effectfilter_getvalue) | - | 获取滤镜参数。 |
| [ImageEffect_ErrorCode OH_EffectFilter_Register(const OH_EffectFilterInfo *info,const ImageEffect_FilterDelegate *delegate)](#oh_effectfilter_register) | - | 注册自定义滤镜。 |
| [ImageEffect_FilterNames *OH_EffectFilter_LookupFilters(const char *key)](#oh_effectfilter_lookupfilters) | - | 查询满足条件的滤镜。 |
| [void OH_EffectFilter_ReleaseFilterNames()](#oh_effectfilter_releasefilternames) | - | 释放滤镜名内存资源。 |
| [ImageEffect_ErrorCode OH_EffectFilter_LookupFilterInfo(const char *name, OH_EffectFilterInfo *info)](#oh_effectfilter_lookupfilterinfo) | - | 查询滤镜信息。 |
| [ImageEffect_ErrorCode OH_EffectFilter_Render(OH_EffectFilter *filter, OH_PixelmapNative *inputPixelmap,OH_PixelmapNative *outputPixelmap)](#oh_effectfilter_render) | - | 执行图像渲染。 |
| [ImageEffect_ErrorCode OH_EffectFilter_Release(OH_EffectFilter *filter)](#oh_effectfilter_release) | - | 销毁OH_EffectFilter实例。 |

## 枚举类型说明

### ImageEffect_DataType

```
enum ImageEffect_DataType
```

**描述**

数据类型枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| EFFECT_DATA_TYPE_UNKNOWN = 0 | 未定义类型。 |
| EFFECT_DATA_TYPE_INT32 = 1 | 整形。 |
| EFFECT_DATA_TYPE_FLOAT = 2 | 单精度浮点型。 |
| EFFECT_DATA_TYPE_DOUBLE = 3 | 双精度浮点型。 |
| EFFECT_DATA_TYPE_CHAR = 4 | 字节类型。 |
| EFFECT_DATA_TYPE_LONG = 5 | 长整型。 |
| EFFECT_DATA_TYPE_BOOL = 6 | 布尔类型。 |
| EFFECT_DATA_TYPE_PTR = 7 | 指针类型。 |

### ImageEffect_Format

```
enum ImageEffect_Format
```

**描述**

像素格式枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| EFFECT_PIXEL_FORMAT_UNKNOWN = 0 | 未定义类型。 |
| EFFECT_PIXEL_FORMAT_RGBA8888 = 1 | RGBA8888类型。 |
| EFFECT_PIXEL_FORMAT_NV21 = 2 | NV21类型。 |
| EFFECT_PIXEL_FORMAT_NV12 = 3 | NV12类型。 |
| EFFECT_PIXEL_FORMAT_RGBA1010102 = 4 | 10bit RGBA类型。 |
| EFFECT_PIXEL_FORMAT_YCBCR_P010 = 5 | 10bit YCBCR420类型。 |
| EFFECT_PIXEL_FORMAT_YCRCB_P010 = 6 | 10bit YCRCB420类型。 |

### ImageEffect_BufferType

```
enum ImageEffect_BufferType
```

**描述**

内存类型枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| EFFECT_BUFFER_TYPE_UNKNOWN = 0 | 未定义类型。 |
| EFFECT_BUFFER_TYPE_PIXEL = 1 | 像素图类型。 |
| EFFECT_BUFFER_TYPE_TEXTURE = 2 | 纹理类型。 |


## 函数说明

### OH_EffectFilterInfo_Create()

```
OH_EffectFilterInfo *OH_EffectFilterInfo_Create()
```

**描述**

创建OH_EffectFilterInfo实例，调用[OH_EffectFilterInfo_Release](capi-imageeffect-filternames.md#oh_effectfilterinfo_release)进行资源释放。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) | 返回一个指向OH_EffectFilterInfo实例的指针，创建失败时返回空指针。 |

### OH_EffectFilterInfo_SetFilterName()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetFilterName(OH_EffectFilterInfo *info, const char *name)
```

**描述**

设置滤镜名。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针。 |
| const char *name | 滤镜名，例如：OH_EFFECT_BRIGHTNESS_FILTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilterInfo_GetFilterName()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetFilterName(OH_EffectFilterInfo *info, char **name)
```

**描述**

获取滤镜名。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针。 |
| char **name | 指向char数组的指针，返回滤镜名。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilterInfo_SetSupportedBufferTypes()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_BufferType *bufferTypeArray)
```

**描述**

设置滤镜所支持的内存类型。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针。 |
| uint32_t size | 滤镜所支持内存类型[ImageEffect_BufferType](#imageeffect_buffertype)个数。 |
| [ImageEffect_BufferType](#imageeffect_buffertype) *bufferTypeArray | 滤镜所支持内存类型[ImageEffect_BufferType](#imageeffect_buffertype)数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilterInfo_GetSupportedBufferTypes()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_BufferType **bufferTypeArray)
```

**描述**

获取滤镜所支持的内存类型。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针。 |
| uint32_t *size | 滤镜所支持内存类型[ImageEffect_BufferType](#imageeffect_buffertype)个数。 |
| [ImageEffect_BufferType](#imageeffect_buffertype) **bufferTypeArray | 滤镜所支持内存类型[ImageEffect_BufferType](#imageeffect_buffertype)数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilterInfo_SetSupportedFormats()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedFormats(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_Format *formatArray)
```

**描述**

设置滤镜所支持的像素格式。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针。 |
| uint32_t size | 滤镜所支持像素格式[ImageEffect_Format](#imageeffect_format)个数。 |
| [ImageEffect_Format](#imageeffect_format) *formatArray | 滤镜所支持像素格式[ImageEffect_Format](#imageeffect_format)数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilterInfo_GetSupportedFormats()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedFormats(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_Format **formatArray)
```

**描述**

获取滤镜所支持的像素格式。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针。 |
| uint32_t *size | 滤镜所支持像素格式[ImageEffect_Format](#imageeffect_format)个数。 |
| [ImageEffect_Format](#imageeffect_format) **formatArray | 滤镜所支持像素格式[ImageEffect_Format](#imageeffect_format)数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilterInfo_Release()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_Release(OH_EffectFilterInfo *info)
```

**描述**

销毁OH_EffectFilterInfo实例。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_Create()

```
OH_EffectBufferInfo *OH_EffectBufferInfo_Create()
```

**描述**

创建OH_EffectBufferInfo实例，调用[OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release)进行资源释放。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) | 返回一个指向OH_EffectBufferInfo实例的指针，创建失败时返回空指针。 |

### OH_EffectBufferInfo_SetAddr()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetAddr(OH_EffectBufferInfo *info, void *addr)
```

**描述**

设置图像内存地址。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| void *addr | 图像虚拟内存地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_GetAddr()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetAddr(OH_EffectBufferInfo *info, void **addr)
```

**描述**

获取图像内存地址。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| void **addr | 图像虚拟内存地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_SetWidth()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetWidth(OH_EffectBufferInfo *info, int32_t width)
```

**描述**

设置图像宽度。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| int32_t width | 图像宽度，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_GetWidth()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetWidth(OH_EffectBufferInfo *info, int32_t *width)
```

**描述**

获取图像宽度。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| int32_t *width | 图像宽度，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_SetHeight()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetHeight(OH_EffectBufferInfo *info, int32_t height)
```

**描述**

设置图像高度。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| int32_t height | 图像高度，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_GetHeight()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetHeight(OH_EffectBufferInfo *info, int32_t *height)
```

**描述**

获取图像高度。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| int32_t *height | 图像高度，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_SetRowSize()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetRowSize(OH_EffectBufferInfo *info, int32_t rowSize)
```

**描述**

设置图像每一行的字节数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| int32_t rowSize | 图像每一行的字节数，单位：字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_GetRowSize()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetRowSize(OH_EffectBufferInfo *info, int32_t *rowSize)
```

**描述**

获取图像每一行的字节数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| int32_t *rowSize | 图像每一行的字节数，单位：字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_SetEffectFormat()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format format)
```

**描述**

设置图像的像素格式。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| [ImageEffect_Format](#imageeffect_format) format | 图像像素格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_GetEffectFormat()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format *format)
```

**描述**

获取图像的像素格式。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |
| [ImageEffect_Format](#imageeffect_format) *format | 图像像素格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectBufferInfo_Release()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_Release(OH_EffectBufferInfo *info)
```

**描述**

销毁OH_EffectBufferInfo实例。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilterDelegate_SetValue()

```
typedef bool (*OH_EffectFilterDelegate_SetValue)(OH_EffectFilter *filter, const char *key,const ImageEffect_Any *value)
```

**描述**

自定义滤镜设置参数的回调函数，用于开发者校验参数及参数值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |
|  const char *key | 滤镜参数。 |
| const [ImageEffect_Any](capi-imageeffect-any.md) *value | 滤镜参数值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 参数有效时返回true，否则返回false。 |

### OH_EffectFilterDelegate_PushData()

```
typedef void (*OH_EffectFilterDelegate_PushData)(OH_EffectFilter *filter, OH_EffectBufferInfo *info)
```

**描述**

自定义滤镜传递图像信息到下一级滤镜的函数指针。需要在[OH_EffectFilterDelegate_Render](capi-image-effect-filter-h.md#oh_effectfilterdelegate_render)的回调中主动调用该函数指针。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |
|  [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息OH_EffectBufferInfo指针。 |

### OH_EffectFilterDelegate_Render()

```
typedef bool (*OH_EffectFilterDelegate_Render)(OH_EffectFilter *filter, OH_EffectBufferInfo *info,OH_EffectFilterDelegate_PushData pushData)
```

**描述**

自定义滤镜渲染图像的回调函数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |
| [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息OH_EffectBufferInfo指针。 |
| [OH_EffectFilterDelegate_PushData](#oh_effectfilterdelegate_pushdata) pushData | 自定义滤镜传递图像信息到下一级滤镜的函数指针OH_EffectFilterDelegate_PushData。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 执行成功时返回true，否则返回false。 |

### OH_EffectFilterDelegate_Save()

```
typedef bool (*OH_EffectFilterDelegate_Save)(OH_EffectFilter *filter, char **info)
```

**描述**

自定义滤镜序列化的回调函数，按照JSON格式进行滤镜序列化处理。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |
|  char **info | 指向char数组的指针，返回序列化JSON字符串。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 执行成功时返回true，否则返回false。 |

### OH_EffectFilterDelegate_Restore()

```
typedef OH_EffectFilter *(*OH_EffectFilterDelegate_Restore)(const char *info)
```

**描述**

自定义滤镜反序列化的回调函数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *info | 序列化JSON字符串。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) | 执行成功时返回OH_EffectFilter实例，否则返回空指针。 |

### OH_EffectFilter_Create()

```
OH_EffectFilter *OH_EffectFilter_Create(const char *name)
```

**描述**

创建OH_EffectFilter实例，调用[OH_EffectFilter_Release](#oh_effectfilter_release)进行资源释放。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *name | 滤镜名，例如：OH_EFFECT_BRIGHTNESS_FILTER。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) | 返回一个指向OH_EffectFilter实例的指针，创建失败时返回空指针。 |

### OH_EffectFilter_SetValue()

```
ImageEffect_ErrorCode OH_EffectFilter_SetValue(OH_EffectFilter *filter, const char *key, const ImageEffect_Any *value)
```

**描述**

设置滤镜参数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |
| const char *key | 滤镜参数，例如：OH_EFFECT_FILTER_INTENSITY_KEY。 |
| const [ImageEffect_Any](capi-imageeffect-any.md) *value | 滤镜参数值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。<br>         EFFECT_KEY_ERROR：参数无效。<br>         EFFECT_PARAM_ERROR：参数值无效。 |

### OH_EffectFilter_GetValue()

```
ImageEffect_ErrorCode OH_EffectFilter_GetValue(OH_EffectFilter *filter, const char *key, ImageEffect_Any *value)
```

**描述**

获取滤镜参数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |
| const char *key | 滤镜参数，例如：OH_EFFECT_FILTER_INTENSITY_KEY。 |
| [ImageEffect_Any](capi-imageeffect-any.md) *value | 滤镜参数值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。<br>         EFFECT_KEY_ERROR：参数无效。 |

### OH_EffectFilter_Register()

```
ImageEffect_ErrorCode OH_EffectFilter_Register(const OH_EffectFilterInfo *info,const ImageEffect_FilterDelegate *delegate)
```

**描述**

注册自定义滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针OH_EffectFilterInfo。 |
| const [ImageEffect_FilterDelegate](capi-imageeffect-filterdelegate.md) *delegate | 自定义滤镜回调函数ImageEffect_FilterDelegate。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilter_LookupFilters()

```
ImageEffect_FilterNames *OH_EffectFilter_LookupFilters(const char *key)
```

**描述**

查询满足条件的滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *key | 查询条件，可根据“Default”关键词查询所有的滤镜。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_FilterNames](capi-imageeffect-filternames.md) | 滤镜名列表。 |

### OH_EffectFilter_ReleaseFilterNames()

```
void OH_EffectFilter_ReleaseFilterNames()
```

**描述**

释放滤镜名内存资源。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

### OH_EffectFilter_LookupFilterInfo()

```
ImageEffect_ErrorCode OH_EffectFilter_LookupFilterInfo(const char *name, OH_EffectFilterInfo *info)
```

**描述**

查询滤镜信息。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *name | 滤镜名。 |
| [OH_EffectFilterInfo](capi-oh-effectfilterinfo.md) *info | 滤镜信息指针OH_EffectFilterInfo。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针或其他无效值。 |

### OH_EffectFilter_Render()

```
ImageEffect_ErrorCode OH_EffectFilter_Render(OH_EffectFilter *filter, OH_PixelmapNative *inputPixelmap,OH_PixelmapNative *outputPixelmap)
```

**描述**

执行图像渲染。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |
| [OH_PixelmapNative](capi-oh-pixelmapnative.md) *inputPixelmap | 输入图像。 |
| [OH_PixelmapNative](capi-oh-pixelmapnative.md) *outputPixelmap | 输出图像。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |

### OH_EffectFilter_Release()

```
ImageEffect_ErrorCode OH_EffectFilter_Release(OH_EffectFilter *filter)
```

**描述**

销毁OH_EffectFilter实例。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | EFFECT_SUCCESS：方法调用成功。<br>         EFFECT_ERROR_PARAM_INVALID：入参为空指针。 |


