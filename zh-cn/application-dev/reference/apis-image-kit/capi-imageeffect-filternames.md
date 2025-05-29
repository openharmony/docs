# ImageEffect_FilterNames

## 概述

滤镜名信息。

**起始版本：** 12

**相关模块：** [ImageEffect](capi-imageeffect.md)

**所在头文件：** [image_effect_filter.h](capi-image-effect-filter-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| uint32_t size = 0 | 滤镜名个数。 |
| const char** nameList = nullptr | 滤镜名列表。 |


### 成员函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_EffectFilterInfo *OH_EffectFilterInfo_Create()](#oh_effectfilterinfo_create) | OH_EffectFilterInfo_Create() | 创建OH_EffectFilterInfo实例，调用[OH_EffectFilterInfo_Release](capi-imageeffect-filternames.md#oh_effectfilterinfo_release)进行资源释放。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetFilterName(OH_EffectFilterInfo *info, const char *name)](#oh_effectfilterinfo_setfiltername) | OH_EffectFilterInfo_SetFilterName() | 设置滤镜名。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetFilterName(OH_EffectFilterInfo *info, char **name)](#oh_effectfilterinfo_getfiltername) | OH_EffectFilterInfo_GetFilterName() | 获取滤镜名。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_BufferType *bufferTypeArray)](#oh_effectfilterinfo_setsupportedbuffertypes) | OH_EffectFilterInfo_SetSupportedBufferTypes() | 设置滤镜所支持的内存类型。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedBufferTypes(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_BufferType **bufferTypeArray)](#oh_effectfilterinfo_getsupportedbuffertypes) | OH_EffectFilterInfo_GetSupportedBufferTypes() | 获取滤镜所支持的内存类型。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedFormats(OH_EffectFilterInfo *info, uint32_t size,ImageEffect_Format *formatArray)](#oh_effectfilterinfo_setsupportedformats) | OH_EffectFilterInfo_SetSupportedFormats() | 设置滤镜所支持的像素格式。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedFormats(OH_EffectFilterInfo *info, uint32_t *size,ImageEffect_Format **formatArray)](#oh_effectfilterinfo_getsupportedformats) | OH_EffectFilterInfo_GetSupportedFormats() | 获取滤镜所支持的像素格式。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |
| [ImageEffect_ErrorCode OH_EffectFilterInfo_Release(OH_EffectFilterInfo *info)](#oh_effectfilterinfo_release) | OH_EffectFilterInfo_Release() | 销毁OH_EffectFilterInfo实例。<br>**起始版本：** 12<br>**系统能力：** SystemCapability.Multimedia.ImageEffect.Core |

## 成员函数说明

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| uint32_t size | 滤镜所支持内存类型[ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype)个数。 |
| ImageEffect_BufferType *bufferTypeArray | 滤镜所支持内存类型[ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype)数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| uint32_t *size | 滤镜所支持内存类型[ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype)个数。 |
| ImageEffect_BufferType **bufferTypeArray | 滤镜所支持内存类型[ImageEffect_BufferType](capi-image-effect-filter-h.md#imageeffect_buffertype)数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| uint32_t size | 滤镜所支持像素格式[ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format)个数。 |
| ImageEffect_Format *formatArray | 滤镜所支持像素格式[ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format)数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| uint32_t *size | 滤镜所支持像素格式[ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format)个数。 |
| ImageEffect_Format **formatArray | 滤镜所支持像素格式[ImageEffect_Format](capi-image-effect-filter-h.md#imageeffect_format)数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |

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
| [ImageEffect_ErrorCode](capi-image-effect-errors-h.md#imageeffect_errorcode) | [EFFECT_SUCCESS](capi-image-effect-errors-h.md#imageeffect_errorcode)如果方法调用成功。<br>         [EFFECT_ERROR_PARAM_INVALID](capi-image-effect-errors-h.md#imageeffect_errorcode)如果入参为空指针。 |


