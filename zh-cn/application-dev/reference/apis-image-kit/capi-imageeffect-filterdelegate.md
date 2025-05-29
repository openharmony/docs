# ImageEffect_FilterDelegate

## 概述

自定义滤镜回调函数结构体。

**起始版本：** 12

**相关模块：** [ImageEffect](capi-imageeffect.md)

**所在头文件：** [image_effect_filter.h](capi-image-effect-filter-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| OH_EffectFilterDelegate_SetValue setValue | 参数设置函数指针。 |
| OH_EffectFilterDelegate_Render render | 滤镜渲染函数指针。 |
| OH_EffectFilterDelegate_Save save | 序列化效果器函数指针。 |
| OH_EffectFilterDelegate_Restore restore | 反序列化效果器函数指针。 |


### 成员函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_EffectBufferInfo *OH_EffectBufferInfo_Create()](#oh_effectbufferinfo_create) | OH_EffectBufferInfo_Create() | 创建OH_EffectBufferInfo实例，调用[OH_EffectBufferInfo_Release](capi-imageeffect-filterdelegate.md#oh_effectbufferinfo_release)进行资源释放。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetAddr(OH_EffectBufferInfo *info, void *addr)](#oh_effectbufferinfo_setaddr) | OH_EffectBufferInfo_SetAddr() | 设置图像内存地址。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetAddr(OH_EffectBufferInfo *info, void **addr)](#oh_effectbufferinfo_getaddr) | OH_EffectBufferInfo_GetAddr() | 获取图像内存地址。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetWidth(OH_EffectBufferInfo *info, int32_t width)](#oh_effectbufferinfo_setwidth) | OH_EffectBufferInfo_SetWidth() | 设置图像宽度。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetWidth(OH_EffectBufferInfo *info, int32_t *width)](#oh_effectbufferinfo_getwidth) | OH_EffectBufferInfo_GetWidth() | 获取图像宽度。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetHeight(OH_EffectBufferInfo *info, int32_t height)](#oh_effectbufferinfo_setheight) | OH_EffectBufferInfo_SetHeight() | 设置图像高度。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetHeight(OH_EffectBufferInfo *info, int32_t *height)](#oh_effectbufferinfo_getheight) | OH_EffectBufferInfo_GetHeight() | 获取图像高度。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetRowSize(OH_EffectBufferInfo *info, int32_t rowSize)](#oh_effectbufferinfo_setrowsize) | OH_EffectBufferInfo_SetRowSize() | 设置图像每一行的字节数。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetRowSize(OH_EffectBufferInfo *info, int32_t *rowSize)](#oh_effectbufferinfo_getrowsize) | OH_EffectBufferInfo_GetRowSize() | 获取图像每一行的字节数。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_SetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format format)](#oh_effectbufferinfo_seteffectformat) | OH_EffectBufferInfo_SetEffectFormat() | 设置图像的像素格式。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_GetEffectFormat(OH_EffectBufferInfo *info, ImageEffect_Format *format)](#oh_effectbufferinfo_geteffectformat) | OH_EffectBufferInfo_GetEffectFormat() | 获取图像的像素格式。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectBufferInfo_Release(OH_EffectBufferInfo *info)](#oh_effectbufferinfo_release) | OH_EffectBufferInfo_Release() | 销毁OH_EffectBufferInfo实例。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [typedef bool (\*OH_EffectFilterDelegate_SetValue)(OH_EffectFilter *filter, const char *key,const ImageEffect_Any *value)](#oh_effectfilterdelegate_setvalue) | OH_EffectFilterDelegate_SetValue() | 自定义滤镜设置参数的回调函数，用于开发者校验参数及参数值。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [typedef void (\*OH_EffectFilterDelegate_PushData)(OH_EffectFilter *filter, OH_EffectBufferInfo *info)](#oh_effectfilterdelegate_pushdata) | OH_EffectFilterDelegate_PushData() | 自定义滤镜传递图像信息到下一级滤镜的函数指针。需要在[OH_EffectFilterDelegate_Render](capi-imageeffect-filterdelegate.md#oh_effectfilterdelegate_render)的回调中主动调用该函数指针。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [typedef bool (\*OH_EffectFilterDelegate_Render)(OH_EffectFilter *filter, OH_EffectBufferInfo *info,OH_EffectFilterDelegate_PushData pushData)](#oh_effectfilterdelegate_render) | OH_EffectFilterDelegate_Render() | 自定义滤镜渲染图像的回调函数。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [typedef bool (\*OH_EffectFilterDelegate_Save)(OH_EffectFilter *filter, char **info)](#oh_effectfilterdelegate_save) | OH_EffectFilterDelegate_Save() | 自定义滤镜序列化的回调函数，按照JSON格式进行滤镜序列化处理。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [typedef OH_EffectFilter *(\*OH_EffectFilterDelegate_Restore)(const char *info)](#*) | *() | 自定义滤镜反序列化的回调函数。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |

## 成员函数说明

### OH_EffectBufferInfo_Create()

```
OH_EffectBufferInfo *OH_EffectBufferInfo_Create()
```

**描述**

创建OH_EffectBufferInfo实例，调用[OH_EffectBufferInfo_Release](capi-imageeffect-filterdelegate.md#oh_effectbufferinfo_release)进行资源释放。

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| ImageEffect_Format format | 图像像素格式[ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| ImageEffect_Format *format | 图像像素格式[ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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

自定义滤镜传递图像信息到下一级滤镜的函数指针。需要在[OH_EffectFilterDelegate_Render](capi-imageeffect-filterdelegate.md#oh_effectfilterdelegate_render)的回调中主动调用该函数指针。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_EffectFilter](capi-oh-effectfilter.md) *filter | 滤镜指针。 |
|  [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息[OH_EffectBufferInfo](capi-oh-effectbufferinfo.md)指针。 |

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
|  [OH_EffectBufferInfo](capi-oh-effectbufferinfo.md) *info | 图像信息[OH_EffectBufferInfo](capi-oh-effectbufferinfo.md)指针。 |
| [OH_EffectFilterDelegate_PushData](capi-imageeffect-filterdelegate.md#oh_effectfilterdelegate_pushdata) pushData | 自定义滤镜传递图像信息到下一级滤镜的函数指针[OH_EffectFilterDelegate_PushData](capi-imageeffect-filterdelegate.md#oh_effectfilterdelegate_pushdata)。 |

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

### *()

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


