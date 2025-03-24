# image_effect_filter.h


## 概述

声明滤镜相关接口。

开发者可以通过滤镜的接口快速实现基本的效果处理，也可以将滤镜添加到效果器中，组合成滤镜链串联执行。系统提供了如“亮度”、“裁剪”等基本的效果处理滤镜。

**库：** libimage_effect.so

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**相关模块：**[ImageEffect](_image_effect.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| union  [ImageEffect_DataValue](union_image_effect___data_value.md) | 数据值联合体。 | 
| struct  [ImageEffect_Any](_image_effect___any.md) | 参数结构体。 | 
| struct  [ImageEffect_FilterNames](_image_effect___filter_names.md) | 滤镜名信息。 | 
| struct  [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) | 自定义滤镜回调函数结构体。 | 
| struct  [ImageEffect_Region](_image_effect___region.md) | 图像区域结构体。 | 
| struct  [ImageEffect_Size](_image_effect___size.md) | 图像尺寸结构体。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_EFFECT_BRIGHTNESS_FILTER](_image_effect.md#oh_effect_brightness_filter)   "Brightness" | 亮度滤镜，对应的参数为OH_EFFECT_FILTER_INTENSITY_KEY，参数类型为[EFFECT_DATA_TYPE_FLOAT](_image_effect.md)。 | 
| [OH_EFFECT_CONTRAST_FILTER](_image_effect.md#oh_effect_contrast_filter)   "Contrast" | 对比度滤镜，对应的参数为OH_EFFECT_FILTER_INTENSITY_KEY，参数类型为[EFFECT_DATA_TYPE_FLOAT](_image_effect.md)。 | 
| [OH_EFFECT_CROP_FILTER](_image_effect.md#oh_effect_crop_filter)   "Crop" | 裁剪滤镜，对应的参数为OH_EFFECT_FILTER_REGION_KEY，参数类型为[EFFECT_DATA_TYPE_PTR](_image_effect.md)，参数值为结构体 [ImageEffect_Region](_image_effect___region.md)。 | 
| [OH_EFFECT_FILTER_INTENSITY_KEY](_image_effect.md#oh_effect_filter_intensity_key)   "FilterIntensity" | 强度参数。 | 
| [OH_EFFECT_FILTER_REGION_KEY](_image_effect.md#oh_effect_filter_region_key)   "FilterRegion" | 图像区域参数。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_EffectFilter](_image_effect.md#oh_effectfilter) [OH_EffectFilter](_image_effect.md#oh_effectfilter) | 定义滤镜结构类型。 | 
| typedef enum [ImageEffect_DataType](_image_effect.md#imageeffect_datatype-1) [ImageEffect_DataType](_image_effect.md#imageeffect_datatype) | 数据类型枚举值。 | 
| typedef union [ImageEffect_DataValue](union_image_effect___data_value.md) [ImageEffect_DataValue](_image_effect.md#imageeffect_datavalue) | 数据值联合体。 | 
| typedef struct [ImageEffect_Any](_image_effect___any.md) [ImageEffect_Any](_image_effect.md#imageeffect_any) | 参数结构体。 | 
| typedef enum [ImageEffect_Format](_image_effect.md#imageeffect_format) [ImageEffect_Format](_image_effect.md#imageeffect_format) | 像素格式枚举值。 | 
| typedef enum [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype-1) [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype) | 内存类型枚举值。 | 
| typedef struct [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) | 定义滤镜信息结构体。 | 
| typedef struct [ImageEffect_FilterNames](_image_effect___filter_names.md) [ImageEffect_FilterNames](_image_effect.md#imageeffect_filternames) | 滤镜名信息。 | 
| typedef struct [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) | 定义图像信息。 | 
| typedef bool(\* [OH_EffectFilterDelegate_SetValue](_image_effect.md#oh_effectfilterdelegate_setvalue)) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | 自定义滤镜设置参数的回调函数，用于开发者校验参数及参数值。 | 
| typedef void(\* [OH_EffectFilterDelegate_PushData](_image_effect.md#oh_effectfilterdelegate_pushdata)) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info) | 自定义滤镜传递图像信息到下一级滤镜的函数指针。 | 
| typedef bool(\* [OH_EffectFilterDelegate_Render](_image_effect.md#oh_effectfilterdelegate_render)) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, [OH_EffectFilterDelegate_PushData](_image_effect.md#oh_effectfilterdelegate_pushdata) pushData) | 自定义滤镜渲染图像的回调函数。 | 
| typedef bool(\* [OH_EffectFilterDelegate_Save](_image_effect.md#oh_effectfilterdelegate_save)) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, char \*\*info) | 自定义滤镜序列化的回调函数，按照JSON格式进行滤镜序列化处理。 | 
| typedef [OH_EffectFilter](_image_effect.md#oh_effectfilter) \*(\* [OH_EffectFilterDelegate_Restore](_image_effect.md#oh_effectfilterdelegate_restore)) (const char \*info) | 自定义滤镜反序列化的回调函数。 | 
| typedef struct [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) [ImageEffect_FilterDelegate](_image_effect.md#imageeffect_filterdelegate) | 自定义滤镜回调函数结构体。 | 
| typedef struct [ImageEffect_Region](_image_effect___region.md) [ImageEffect_Region](_image_effect.md#imageeffect_region) | 图像区域结构体。 | 
| typedef struct [ImageEffect_Size](_image_effect___size.md) [ImageEffect_Size](_image_effect.md#imageeffect_size) | 图像尺寸结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ImageEffect_DataType](_image_effect.md#imageeffect_datatype-1) {<br/>EFFECT_DATA_TYPE_UNKNOWN = 0, EFFECT_DATA_TYPE_INT32 = 1,<br/>EFFECT_DATA_TYPE_FLOAT = 2, EFFECT_DATA_TYPE_DOUBLE = 3,<br/>EFFECT_DATA_TYPE_CHAR = 4, EFFECT_DATA_TYPE_LONG = 5,<br/>EFFECT_DATA_TYPE_BOOL = 6, EFFECT_DATA_TYPE_PTR = 7<br/>} | 数据类型枚举值。 | 
| [ImageEffect_Format](_image_effect.md#imageeffect_format-1) {<br/>EFFECT_PIXEL_FORMAT_UNKNOWN = 0, EFFECT_PIXEL_FORMAT_RGBA8888 = 1,<br/>EFFECT_PIXEL_FORMAT_NV21 = 2, EFFECT_PIXEL_FORMAT_NV12 = 3,<br/>EFFECT_PIXEL_FORMAT_RGBA1010102 = 4, EFFECT_PIXEL_FORMAT_YCBCR_P010 = 5,<br/>EFFECT_PIXEL_FORMAT_YCRCB_P010 = 6<br/>} | 像素格式枚举值。 | 
| [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype-1) { EFFECT_BUFFER_TYPE_UNKNOWN = 0,<br/>EFFECT_BUFFER_TYPE_PIXEL = 1, EFFECT_BUFFER_TYPE_TEXTURE = 2 } | 内存类型枚举值。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \* [OH_EffectFilterInfo_Create](_image_effect.md#oh_effectfilterinfo_create) () | 创建OH_EffectFilterInfo实例，调用[OH_EffectFilterInfo_Release](_image_effect.md#oh_effectfilterinfo_release)进行资源释放。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_SetFilterName](_image_effect.md#oh_effectfilterinfo_setfiltername) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, const char \*name) | 设置滤镜名。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_GetFilterName](_image_effect.md#oh_effectfilterinfo_getfiltername) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, char \*\*name) | 获取滤镜名。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_SetSupportedBufferTypes](_image_effect.md#oh_effectfilterinfo_setsupportedbuffertypes) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, uint32_t size, [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype) \*bufferTypeArray) | 设置滤镜所支持的内存类型。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_GetSupportedBufferTypes](_image_effect.md#oh_effectfilterinfo_getsupportedbuffertypes) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, uint32_t \*size, [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype) \*\*bufferTypeArray) | 获取滤镜所支持的内存类型。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_SetSupportedFormats](_image_effect.md#oh_effectfilterinfo_setsupportedformats) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, uint32_t size, [ImageEffect_Format](_image_effect.md#imageeffect_format) \*formatArray) | 设置滤镜所支持的像素格式。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_GetSupportedFormats](_image_effect.md#oh_effectfilterinfo_getsupportedformats) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, uint32_t \*size, [ImageEffect_Format](_image_effect.md#imageeffect_format) \*\*formatArray) | 获取滤镜所支持的像素格式。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_Release](_image_effect.md#oh_effectfilterinfo_release) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info) | 销毁OH_EffectFilterInfo实例。 | 
| [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \* [OH_EffectBufferInfo_Create](_image_effect.md#oh_effectbufferinfo_create) () | 创建OH_EffectBufferInfo实例，调用[OH_EffectBufferInfo_Release](_image_effect.md#oh_effectbufferinfo_release)进行资源释放。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetAddr](_image_effect.md#oh_effectbufferinfo_setaddr) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, void \*addr) | 设置图像内存地址。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetAddr](_image_effect.md#oh_effectbufferinfo_getaddr) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, void \*\*addr) | 获取图像内存地址。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetWidth](_image_effect.md#oh_effectbufferinfo_setwidth) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t width) | 设置图像宽度。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetWidth](_image_effect.md#oh_effectbufferinfo_getwidth) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t \*width) | 获取图像宽度。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetHeight](_image_effect.md#oh_effectbufferinfo_setheight) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t height) | 设置图像高度。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetHeight](_image_effect.md#oh_effectbufferinfo_getheight) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t \*height) | 获取图像高度。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetRowSize](_image_effect.md#oh_effectbufferinfo_setrowsize) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t rowSize) | 设置图像每一行的字节数。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetRowSize](_image_effect.md#oh_effectbufferinfo_getrowsize) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t \*rowSize) | 获取图像每一行的字节数。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetEffectFormat](_image_effect.md#oh_effectbufferinfo_seteffectformat) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, [ImageEffect_Format](_image_effect.md#imageeffect_format) format) | 设置图像的像素格式。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetEffectFormat](_image_effect.md#oh_effectbufferinfo_geteffectformat) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, [ImageEffect_Format](_image_effect.md#imageeffect_format) \*format) | 获取图像的像素格式。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_Release](_image_effect.md#oh_effectbufferinfo_release) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info) | 销毁OH_EffectBufferInfo实例。 | 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_EffectFilter_Create](_image_effect.md#oh_effectfilter_create) (const char \*name) | 创建OH_EffectFilter实例，调用[OH_EffectFilter_Release](_image_effect.md#oh_effectfilter_release)进行资源释放。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_SetValue](_image_effect.md#oh_effectfilter_setvalue) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | 设置滤镜参数。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_GetValue](_image_effect.md#oh_effectfilter_getvalue) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, const char \*key, [ImageEffect_Any](_image_effect___any.md) \*value) | 获取滤镜参数。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_Register](_image_effect.md#oh_effectfilter_register) (const [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, const [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) \*delegate) | 注册自定义滤镜。 | 
| [ImageEffect_FilterNames](_image_effect___filter_names.md) \* [OH_EffectFilter_LookupFilters](_image_effect.md#oh_effectfilter_lookupfilters) (const char \*key) | 查询满足条件的滤镜。 | 
| void [OH_EffectFilter_ReleaseFilterNames](_image_effect.md#oh_effectfilter_releasefilternames) () | 释放滤镜名内存资源。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_LookupFilterInfo](_image_effect.md#oh_effectfilter_lookupfilterinfo) (const char \*name, [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info) | 查询滤镜信息。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_Render](_image_effect.md#oh_effectfilter_render) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, OH_PixelmapNative \*inputPixelmap, OH_PixelmapNative \*outputPixelmap) | 执行图像渲染。 | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_Release](_image_effect.md#oh_effectfilter_release) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter) | 销毁OH_EffectFilter实例。 | 
