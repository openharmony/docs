# ImageEffect


## 概述

提供图片编辑能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [image_effect.h](image__effect_8h.md) | 声明效果器相关接口。 | 
| [image_effect_errors.h](image__effect__errors_8h.md) | 声明图片效果器错误码。 | 
| [image_effect_filter.h](image__effect__filter_8h.md) | 声明滤镜相关接口。 | 


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
| [OH_EFFECT_BRIGHTNESS_FILTER](#oh_effect_brightness_filter)   "Brightness" | 亮度滤镜，对应的参数为OH_EFFECT_FILTER_INTENSITY_KEY，参数类型为EFFECT_DATA_TYPE_FLOAT。 | 
| [OH_EFFECT_CONTRAST_FILTER](#oh_effect_contrast_filter)   "Contrast" | 对比度滤镜，对应的参数为OH_EFFECT_FILTER_INTENSITY_KEY，参数类型为EFFECT_DATA_TYPE_FLOAT。 | 
| [OH_EFFECT_CROP_FILTER](#oh_effect_crop_filter)   "Crop" | 裁剪滤镜，对应的参数为OH_EFFECT_FILTER_REGION_KEY，参数类型为EFFECT_DATA_TYPE_PTR， 参数值为结构体 [ImageEffect_Region](_image_effect___region.md)。 | 
| [OH_EFFECT_FILTER_INTENSITY_KEY](#oh_effect_filter_intensity_key)   "FilterIntensity" | 强度参数。 | 
| [OH_EFFECT_FILTER_REGION_KEY](#oh_effect_filter_region_key)   "FilterRegion" | 图像区域参数。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_ImageEffect](#oh_imageeffect) [OH_ImageEffect](#oh_imageeffect) | 定义效果器结构类型。 | 
| typedef enum [ImageEffect_ErrorCode](#imageeffect_errorcode-1) [ImageEffect_ErrorCode](#imageeffect_errorcode) | 效果器错误码。 | 
| typedef struct [OH_EffectFilter](#oh_effectfilter) [OH_EffectFilter](#oh_effectfilter) | 定义滤镜结构类型。 | 
| typedef enum [ImageEffect_DataType](#imageeffect_datatype) [ImageEffect_DataType](#imageeffect_datatype) | 数据类型枚举值。 | 
| typedef union [ImageEffect_DataValue](union_image_effect___data_value.md) [ImageEffect_DataValue](#imageeffect_datavalue) | 数据值联合体。 | 
| typedef struct [ImageEffect_Any](_image_effect___any.md) [ImageEffect_Any](#imageeffect_any) | 参数结构体。 | 
| typedef enum [ImageEffect_Format](#imageeffect_format-1) [ImageEffect_Format](#imageeffect_format) | 像素格式枚举值。 | 
| typedef enum [ImageEffect_BufferType](#imageeffect_buffertype-1) [ImageEffect_BufferType](#imageeffect_buffertype) | 内存类型枚举值。 | 
| typedef struct [OH_EffectFilterInfo](#oh_effectfilterinfo) [OH_EffectFilterInfo](#oh_effectfilterinfo) | 定义滤镜信息结构体。 | 
| typedef struct [ImageEffect_FilterNames](_image_effect___filter_names.md) [ImageEffect_FilterNames](#imageeffect_filternames) | 滤镜名信息。 | 
| typedef struct [OH_EffectBufferInfo](#oh_effectbufferinfo) [OH_EffectBufferInfo](#oh_effectbufferinfo) | 定义图像信息。 | 
| typedef bool(\* [OH_EffectFilterDelegate_SetValue](#oh_effectfilterdelegate_setvalue)) ([OH_EffectFilter](#oh_effectfilter) \*filter, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | 自定义滤镜设置参数的回调函数，用于开发者校验参数及参数值。 | 
| typedef void(\* [OH_EffectFilterDelegate_PushData](#oh_effectfilterdelegate_pushdata)) ([OH_EffectFilter](#oh_effectfilter) \*filter, [OH_EffectBufferInfo](#oh_effectbufferinfo) \*info) | 自定义滤镜传递图像信息到下一级滤镜的函数指针。 | 
| typedef bool(\* [OH_EffectFilterDelegate_Render](#oh_effectfilterdelegate_render)) ([OH_EffectFilter](#oh_effectfilter) \*filter, [OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, [OH_EffectFilterDelegate_PushData](#oh_effectfilterdelegate_pushdata) pushData) | 自定义滤镜渲染图像的回调函数。 | 
| typedef bool(\* [OH_EffectFilterDelegate_Save](#oh_effectfilterdelegate_save)) ([OH_EffectFilter](#oh_effectfilter) \*filter, char \*\*info) | 自定义滤镜序列化的回调函数，按照JSON格式进行滤镜序列化处理。 | 
| typedef [OH_EffectFilter](#oh_effectfilter) \*(\* [OH_EffectFilterDelegate_Restore](#oh_effectfilterdelegate_restore)) (const char \*info) | 自定义滤镜反序列化的回调函数。 | 
| typedef struct [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) [ImageEffect_FilterDelegate](#imageeffect_filterdelegate) | 自定义滤镜回调函数结构体。 | 
| typedef struct [ImageEffect_Region](_image_effect___region.md) [ImageEffect_Region](#imageeffect_region) | 图像区域结构体。 | 
| typedef struct [ImageEffect_Size](_image_effect___size.md) [ImageEffect_Size](#imageeffect_size) | 图像尺寸结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ImageEffect_ErrorCode](#imageeffect_errorcode-1) {<br/>EFFECT_SUCCESS = 0, EFFECT_ERROR_PERMISSION_DENIED = 201,<br/>EFFECT_ERROR_PARAM_INVALID = 401, EFFECT_BUFFER_SIZE_NOT_MATCH = 29000001,<br/>EFFECT_COLOR_SPACE_NOT_MATCH = 29000002, EFFECT_INPUT_OUTPUT_NOT_MATCH = 29000101,<br/>EFFECT_EFFECT_NUMBER_LIMITED = 29000102, EFFECT_INPUT_OUTPUT_NOT_SUPPORTED = 29000103,<br/>EFFECT_ALLOCATE_MEMORY_FAILED = 29000104, EFFECT_PARAM_ERROR = 29000121,<br/>EFFECT_KEY_ERROR = 29000122, EFFECT_UNKNOWN = 29000199<br/>} | 效果器错误码。 | 
| [ImageEffect_DataType](#imageeffect_datatype-1) {<br/>EFFECT_DATA_TYPE_UNKNOWN = 0, EFFECT_DATA_TYPE_INT32 = 1,<br/>EFFECT_DATA_TYPE_FLOAT = 2, EFFECT_DATA_TYPE_DOUBLE = 3,<br/>EFFECT_DATA_TYPE_CHAR = 4, EFFECT_DATA_TYPE_LONG = 5,<br/>EFFECT_DATA_TYPE_BOOL = 6, EFFECT_DATA_TYPE_PTR = 7<br/>} | 数据类型枚举值。 | 
| [ImageEffect_Format](#imageeffect_format-1) {<br/>EFFECT_PIXEL_FORMAT_UNKNOWN = 0, EFFECT_PIXEL_FORMAT_RGBA8888 = 1,<br/>EFFECT_PIXEL_FORMAT_NV21 = 2, EFFECT_PIXEL_FORMAT_NV12 = 3,<br/>EFFECT_PIXEL_FORMAT_RGBA1010102 = 4, EFFECT_PIXEL_FORMAT_YCBCR_P010 = 5,<br/>EFFECT_PIXEL_FORMAT_YCRCB_P010 = 6<br/>} | 像素格式枚举值。 | 
| [ImageEffect_BufferType](#imageeffect_buffertype-1) { EFFECT_BUFFER_TYPE_UNKNOWN = 0,<br/>EFFECT_BUFFER_TYPE_PIXEL = 1, EFFECT_BUFFER_TYPE_TEXTURE = 2 } | 内存类型枚举值。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_ImageEffect](#oh_imageeffect) \* [OH_ImageEffect_Create](#oh_imageeffect_create) (const char \*name) | 创建OH_ImageEffect实例，调用[OH_ImageEffect_Release](#oh_imageeffect_release)进行资源释放。 | 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_ImageEffect_AddFilter](#oh_imageeffect_addfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*filterName) | 添加滤镜。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_AddFilterByFilter](#oh_imageeffect_addfilterbyfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, [OH_EffectFilter](#oh_effectfilter) \*filter) | 添加指定滤镜。  | 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_ImageEffect_InsertFilter](#oh_imageeffect_insertfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, uint32_t index, const char \*filterName) | 插入滤镜。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_InsertFilterByFilter](#oh_imageeffect_insertfilterbyfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, uint32_t index, [OH_EffectFilter](#oh_effectfilter) \*filter) | 按指定位置插入滤镜。  | 
| int32_t [OH_ImageEffect_RemoveFilter](#oh_imageeffect_removefilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*filterName) | 移除滤镜。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_RemoveFilterByIndex](#oh_imageeffect_removefilterbyindex) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, uint32_t index) | 移除指定位置滤镜。  | 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_ImageEffect_ReplaceFilter](#oh_imageeffect_replacefilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, uint32_t index, const char \*filterName) | 替换滤镜。  | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_ReplaceFilterByFilter](#oh_imageeffect_replacefilterbyfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, uint32_t index, const char \*filterName) | 替换指定位置滤镜。  | 
| int32_t [OH_ImageEffect_GetFilterCount](#oh_imageeffect_getfiltercount) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect) | 查询已添加滤镜个数。 | 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_ImageEffect_GetFilter](#oh_imageeffect_getfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, uint32_t index) | 查询已添加滤镜。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Configure](#oh_imageeffect_configure) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | 设置配置信息。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetOutputSurface](#oh_imageeffect_setoutputsurface) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OHNativeWindow \*nativeWindow) | 设置输出Surface。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_GetInputSurface](#oh_imageeffect_getinputsurface) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OHNativeWindow \*\*nativeWindow) | 获取输入Surface。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetInputPixelmap](#oh_imageeffect_setinputpixelmap) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OH_PixelmapNative \*pixelmap) | 设置输入的Pixelmap。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetOutputPixelmap](#oh_imageeffect_setoutputpixelmap) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OH_PixelmapNative \*pixelmap) | 设置输出的Pixelmap。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetInputNativeBuffer](#oh_imageeffect_setinputnativebuffer) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OH_NativeBuffer \*nativeBuffer) | 设置输入的NativeBuffer。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetOutputNativeBuffer](#oh_imageeffect_setoutputnativebuffer) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OH_NativeBuffer \*nativeBuffer) | 设置输出的NativeBuffer。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetInputUri](#oh_imageeffect_setinputuri) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*uri) | 设置输入的URI。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetOutputUri](#oh_imageeffect_setoutputuri) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*uri) | 设置输出的URI。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Start](#oh_imageeffect_start) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect) | 启动效果器。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Stop](#oh_imageeffect_stop) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect) | 停止生效效果。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Release](#oh_imageeffect_release) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect) | 释放OH_ImageEffect实例资源。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Save](#oh_imageeffect_save) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, char \*\*info) | 序列化效果器。 | 
| [OH_ImageEffect](#oh_imageeffect) \* [OH_ImageEffect_Restore](#oh_imageeffect_restore) (const char \*info) | 反序列化效果器。 | 
| [OH_EffectFilterInfo](#oh_effectfilterinfo) \* [OH_EffectFilterInfo_Create](#oh_effectfilterinfo_create) () | 创建OH_EffectFilterInfo实例，调用[OH_EffectFilterInfo_Release](#oh_effectfilterinfo_release)进行资源释放。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_SetFilterName](#oh_effectfilterinfo_setfiltername) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, const char \*name) | 设置滤镜名。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_GetFilterName](#oh_effectfilterinfo_getfiltername) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, char \*\*name) | 获取滤镜名。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_SetSupportedBufferTypes](#oh_effectfilterinfo_setsupportedbuffertypes) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, uint32_t size, [ImageEffect_BufferType](#imageeffect_buffertype) \*bufferTypeArray) | 设置滤镜所支持的内存类型。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_GetSupportedBufferTypes](#oh_effectfilterinfo_getsupportedbuffertypes) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, uint32_t \*size, [ImageEffect_BufferType](#imageeffect_buffertype) \*\*bufferTypeArray) | 获取滤镜所支持的内存类型。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_SetSupportedFormats](#oh_effectfilterinfo_setsupportedformats) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, uint32_t size, [ImageEffect_Format](#imageeffect_format) \*formatArray) | 设置滤镜所支持的像素格式。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_GetSupportedFormats](#oh_effectfilterinfo_getsupportedformats) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, uint32_t \*size, [ImageEffect_Format](#imageeffect_format) \*\*formatArray) | 获取滤镜所支持的像素格式。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_Release](#oh_effectfilterinfo_release) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info) | 销毁OH_EffectFilterInfo实例。 | 
| [OH_EffectBufferInfo](#oh_effectbufferinfo) \* [OH_EffectBufferInfo_Create](#oh_effectbufferinfo_create) () | 创建OH_EffectBufferInfo实例，调用[OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release)进行资源释放。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetAddr](#oh_effectbufferinfo_setaddr) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, void \*addr) | 设置图像内存地址。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetAddr](#oh_effectbufferinfo_getaddr) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, void \*\*addr) | 获取图像内存地址。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetWidth](#oh_effectbufferinfo_setwidth) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t width) | 设置图像宽度。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetWidth](#oh_effectbufferinfo_getwidth) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t \*width) | 获取图像宽度。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetHeight](#oh_effectbufferinfo_setheight) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t height) | 设置图像高度。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetHeight](#oh_effectbufferinfo_getheight) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t \*height) | 获取图像高度。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetRowSize](#oh_effectbufferinfo_setrowsize) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t rowSize) | 设置图像每一行的字节数。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetRowSize](#oh_effectbufferinfo_getrowsize) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t \*rowSize) | 获取图像每一行的字节数。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetEffectFormat](#oh_effectbufferinfo_seteffectformat) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, [ImageEffect_Format](#imageeffect_format) format) | 设置图像的像素格式。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetEffectFormat](#oh_effectbufferinfo_geteffectformat) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, [ImageEffect_Format](#imageeffect_format) \*format) | 获取图像的像素格式。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info) | 销毁OH_EffectBufferInfo实例。 | 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_EffectFilter_Create](#oh_effectfilter_create) (const char \*name) | 创建OH_EffectFilter实例，调用[OH_EffectFilter_Release](#oh_effectfilter_release)进行资源释放。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_SetValue](#oh_effectfilter_setvalue) ([OH_EffectFilter](#oh_effectfilter) \*filter, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | 设置滤镜参数。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_GetValue](#oh_effectfilter_getvalue) ([OH_EffectFilter](#oh_effectfilter) \*filter, const char \*key, [ImageEffect_Any](_image_effect___any.md) \*value) | 获取滤镜参数。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_Register](#oh_effectfilter_register) (const [OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, const [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) \*delegate) | 注册自定义滤镜。 | 
| [ImageEffect_FilterNames](_image_effect___filter_names.md) \* [OH_EffectFilter_LookupFilters](#oh_effectfilter_lookupfilters) (const char \*key) | 查询满足条件的滤镜。 | 
| void [OH_EffectFilter_ReleaseFilterNames](#oh_effectfilter_releasefilternames) () | 释放滤镜名内存资源。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_LookupFilterInfo](#oh_effectfilter_lookupfilterinfo) (const char \*name, [OH_EffectFilterInfo](#oh_effectfilterinfo) \*info) | 查询滤镜信息。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_Render](#oh_effectfilter_render) ([OH_EffectFilter](#oh_effectfilter) \*filter, OH_PixelmapNative \*inputPixelmap, OH_PixelmapNative \*outputPixelmap) | 执行图像渲染。 | 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_Release](#oh_effectfilter_release) ([OH_EffectFilter](#oh_effectfilter) \*filter) | 销毁OH_EffectFilter实例。 | 


## 宏定义说明


### OH_EFFECT_BRIGHTNESS_FILTER

```
#define OH_EFFECT_BRIGHTNESS_FILTER   "Brightness"
```

**描述**

亮度滤镜，对应的参数为OH_EFFECT_FILTER_INTENSITY_KEY，参数类型为EFFECT_DATA_TYPE_FLOAT。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_EFFECT_CONTRAST_FILTER

```
#define OH_EFFECT_CONTRAST_FILTER   "Contrast"
```

**描述**

对比度滤镜，对应的参数为OH_EFFECT_FILTER_INTENSITY_KEY，参数类型为EFFECT_DATA_TYPE_FLOAT。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_EFFECT_CROP_FILTER

```
#define OH_EFFECT_CROP_FILTER   "Crop"
```

**描述**

裁剪滤镜，对应的参数为OH_EFFECT_FILTER_REGION_KEY，参数类型为EFFECT_DATA_TYPE_PTR， 参数值为结构体 [ImageEffect_Region](_image_effect___region.md)。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_EFFECT_FILTER_INTENSITY_KEY

```
#define OH_EFFECT_FILTER_INTENSITY_KEY   "FilterIntensity"
```

**描述**

强度参数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_EFFECT_FILTER_REGION_KEY

```
#define OH_EFFECT_FILTER_REGION_KEY   "FilterRegion"
```

**描述**

图像区域参数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


## 类型定义说明


### ImageEffect_Any

```
typedef struct ImageEffect_Any ImageEffect_Any
```

**描述**

参数结构体。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_BufferType

```
typedef enum ImageEffect_BufferType ImageEffect_BufferType
```

**描述**

内存类型枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_DataType

```
typedef enum ImageEffect_DataType ImageEffect_DataType
```

**描述**

数据类型枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_DataValue

```
typedef union ImageEffect_DataValue ImageEffect_DataValue
```

**描述**

数据值联合体。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_ErrorCode

```
typedef enum ImageEffect_ErrorCode ImageEffect_ErrorCode
```

**描述**

效果器错误码。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_FilterDelegate

```
typedef struct ImageEffect_FilterDelegate ImageEffect_FilterDelegate
```

**描述**

自定义滤镜回调函数结构体。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_FilterNames

```
typedef struct ImageEffect_FilterNames ImageEffect_FilterNames
```

**描述**

滤镜名信息。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_Format

```
typedef enum ImageEffect_Format ImageEffect_Format
```

**描述**

像素格式枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_Region

```
typedef struct ImageEffect_Region ImageEffect_Region
```

**描述**

图像区域结构体。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### ImageEffect_Size

```
typedef struct ImageEffect_Size ImageEffect_Size
```

**描述**

图像尺寸结构体。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_EffectBufferInfo

```
typedef struct OH_EffectBufferInfo OH_EffectBufferInfo
```

**描述**

定义图像信息。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_EffectFilter

```
typedef struct OH_EffectFilter OH_EffectFilter
```

**描述**

定义滤镜结构类型。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_EffectFilterDelegate_PushData

```
typedef void(* OH_EffectFilterDelegate_PushData) (OH_EffectFilter *filter, OH_EffectBufferInfo *info)
```

**描述**

自定义滤镜传递图像信息到下一级滤镜的函数指针。需要在[OH_EffectFilterDelegate_Render](#oh_effectfilterdelegate_render) 的回调中主动调用该函数指针。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| info | 图像信息[OH_EffectBufferInfo](#oh_effectbufferinfo)指针。 | 


### OH_EffectFilterDelegate_Render

```
typedef bool(* OH_EffectFilterDelegate_Render) (OH_EffectFilter *filter, OH_EffectBufferInfo *info, OH_EffectFilterDelegate_PushData pushData)
```

**描述**

自定义滤镜渲染图像的回调函数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| info | 图像信息[OH_EffectBufferInfo](#oh_effectbufferinfo)指针。 | 
| pushData | 自定义滤镜传递图像信息到下一级滤镜的函数指针[OH_EffectFilterDelegate_PushData](#oh_effectfilterdelegate_pushdata)。 | 

**返回：**

执行成功时返回true，否则返回false。


### OH_EffectFilterDelegate_Restore

```
typedef OH_EffectFilter*(* OH_EffectFilterDelegate_Restore) (const char *info)
```

**描述**

自定义滤镜反序列化的回调函数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 序列化JSON字符串。 | 

**返回：**

执行成功时返回OH_EffectFilter实例，否则返回空指针。


### OH_EffectFilterDelegate_Save

```
typedef bool(* OH_EffectFilterDelegate_Save) (OH_EffectFilter *filter, char **info)
```

**描述**

自定义滤镜序列化的回调函数，按照JSON格式进行滤镜序列化处理。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| info | 指向char数组的指针，返回序列化JSON字符串。 | 

**返回：**

执行成功时返回true，否则返回false。


### OH_EffectFilterDelegate_SetValue

```
typedef bool(* OH_EffectFilterDelegate_SetValue) (OH_EffectFilter *filter, const char *key, const ImageEffect_Any *value)
```

**描述**

自定义滤镜设置参数的回调函数，用于开发者校验参数及参数值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| key | 滤镜参数。 | 
| value | 滤镜参数值。 | 

**返回：**

参数有效时返回true，否则返回false。


### OH_EffectFilterInfo

```
typedef struct OH_EffectFilterInfo OH_EffectFilterInfo
```

**描述**

定义滤镜信息结构体。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_ImageEffect

```
typedef struct OH_ImageEffect OH_ImageEffect
```

**描述**

定义效果器结构类型。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


## 枚举类型说明


### ImageEffect_BufferType

```
enum ImageEffect_BufferType
```

**描述**

内存类型枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| EFFECT_BUFFER_TYPE_UNKNOWN | 未定义类型。 | 
| EFFECT_BUFFER_TYPE_PIXEL | 像素图类型。 | 
| EFFECT_BUFFER_TYPE_TEXTURE | 纹理类型。 | 


### ImageEffect_DataType

```
enum ImageEffect_DataType
```

**描述**

数据类型枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| EFFECT_DATA_TYPE_UNKNOWN | 未定义类型。 | 
| EFFECT_DATA_TYPE_INT32 | 整形。 | 
| EFFECT_DATA_TYPE_FLOAT | 单精度浮点型。 | 
| EFFECT_DATA_TYPE_DOUBLE | 双精度浮点型。 | 
| EFFECT_DATA_TYPE_CHAR | 字节类型。 | 
| EFFECT_DATA_TYPE_LONG | 长整型。 | 
| EFFECT_DATA_TYPE_BOOL | 布尔类型。 | 
| EFFECT_DATA_TYPE_PTR | 指针类型。 | 


### ImageEffect_ErrorCode

```
enum ImageEffect_ErrorCode
```

**描述**

效果器错误码。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| EFFECT_SUCCESS | 操作成功。 | 
| EFFECT_ERROR_PERMISSION_DENIED | 权限校验失败。 | 
| EFFECT_ERROR_PARAM_INVALID | 参数检查失败。 | 
| EFFECT_BUFFER_SIZE_NOT_MATCH | 输出buffer尺寸不匹配。 | 
| EFFECT_COLOR_SPACE_NOT_MATCH | 输入输出色彩空间不匹配。 | 
| EFFECT_INPUT_OUTPUT_NOT_MATCH | 输入输出配置不一致。比如：输入Surface，输出Pixelmap。 | 
| EFFECT_EFFECT_NUMBER_LIMITED | 超出管线最大规格。 | 
| EFFECT_INPUT_OUTPUT_NOT_SUPPORTED | 输入、输出配置不支持。 | 
| EFFECT_ALLOCATE_MEMORY_FAILED | 申请内存失败。 | 
| EFFECT_PARAM_ERROR | 参数值错误。 例如：滤镜无效的参数值。 | 
| EFFECT_KEY_ERROR | 参数错误。例如：滤镜无效的参数。 | 
| EFFECT_UNKNOWN | 未定义错误。 | 


### ImageEffect_Format

```
enum ImageEffect_Format
```

**描述**

像素格式枚举值。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| EFFECT_PIXEL_FORMAT_UNKNOWN | 未定义类型。 | 
| EFFECT_PIXEL_FORMAT_RGBA8888 | RGBA8888类型。 | 
| EFFECT_PIXEL_FORMAT_NV21 | NV21类型。 | 
| EFFECT_PIXEL_FORMAT_NV12 | NV12类型。 | 
| EFFECT_PIXEL_FORMAT_RGBA1010102 | 10bit RGBA类型。 | 
| EFFECT_PIXEL_FORMAT_YCBCR_P010 | 10bit YCBCR420类型。 | 
| EFFECT_PIXEL_FORMAT_YCRCB_P010 | 10bit YCRCB420类型。 | 


## 函数说明


### OH_EffectBufferInfo_Create()

```
OH_EffectBufferInfo* OH_EffectBufferInfo_Create ()
```

**描述**

创建OH_EffectBufferInfo实例，调用[OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release)进行资源释放。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**返回：**

返回一个指向OH_EffectBufferInfo实例的指针，创建失败时返回空指针。


### OH_EffectBufferInfo_GetAddr()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetAddr (OH_EffectBufferInfo * info, void ** addr )
```

**描述**

获取图像内存地址。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| addr | 图像虚拟内存地址。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_GetEffectFormat()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetEffectFormat (OH_EffectBufferInfo * info, ImageEffect_Format * format )
```

**描述**

获取图像的像素格式。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| format | 图像像素格式[ImageEffect_Format](#imageeffect_format)。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_GetHeight()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetHeight (OH_EffectBufferInfo * info, int32_t * height )
```

**描述**

获取图像高度。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| height | 图像高度，单位：像素。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_GetRowSize()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetRowSize (OH_EffectBufferInfo * info, int32_t * rowSize )
```

**描述**

获取图像每一行的字节数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| rowSize | 图像每一行的字节数，单位：字节。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_GetWidth()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetWidth (OH_EffectBufferInfo * info, int32_t * width )
```

**描述**

获取图像宽度。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| width | 图像宽度，单位：像素。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_Release()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_Release (OH_EffectBufferInfo * info)
```

**描述**

销毁OH_EffectBufferInfo实例。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_SetAddr()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetAddr (OH_EffectBufferInfo * info, void * addr )
```

**描述**

设置图像内存地址。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| addr | 图像虚拟内存地址。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_SetEffectFormat()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetEffectFormat (OH_EffectBufferInfo * info, ImageEffect_Format format )
```

**描述**

设置图像的像素格式。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| format | 图像像素格式[ImageEffect_Format](#imageeffect_format)。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_SetHeight()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetHeight (OH_EffectBufferInfo * info, int32_t height )
```

**描述**

设置图像高度。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| height | 图像高度，单位：像素。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_SetRowSize()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetRowSize (OH_EffectBufferInfo * info, int32_t rowSize )
```

**描述**

设置图像每一行的字节数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| rowSize | 图像每一行的字节数，单位：字节。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectBufferInfo_SetWidth()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetWidth (OH_EffectBufferInfo * info, int32_t width )
```

**描述**

设置图像宽度。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 图像信息指针。 | 
| width | 图像宽度，单位：像素。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilter_Create()

```
OH_EffectFilter* OH_EffectFilter_Create (const char * name)
```

**描述**

创建OH_EffectFilter实例，调用[OH_EffectFilter_Release](#oh_effectfilter_release)进行资源释放。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 滤镜名，例如：OH_EFFECT_BRIGHTNESS_FILTER。 | 

**返回：**

返回一个指向OH_EffectFilter实例的指针，创建失败时返回空指针。


### OH_EffectFilter_GetValue()

```
ImageEffect_ErrorCode OH_EffectFilter_GetValue (OH_EffectFilter * filter, const char * key, ImageEffect_Any * value )
```

**描述**

获取滤镜参数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| key | 滤镜参数，例如：OH_EFFECT_FILTER_INTENSITY_KEY。 | 
| value | 滤镜参数值。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。 EFFECT_KEY_ERROR如果参数无效。


### OH_EffectFilter_LookupFilterInfo()

```
ImageEffect_ErrorCode OH_EffectFilter_LookupFilterInfo (const char * name, OH_EffectFilterInfo * info )
```

**描述**

查询滤镜信息。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 滤镜名。 | 
| info | 滤镜信息指针[OH_EffectFilterInfo](#oh_effectfilterinfo)。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针或其他无效值。


### OH_EffectFilter_LookupFilters()

```
ImageEffect_FilterNames* OH_EffectFilter_LookupFilters (const char * key)
```

**描述**

查询满足条件的滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| key | 查询条件，可根据“Default”关键词查询所有的滤镜。 | 

**返回：**

滤镜名列表[ImageEffect_FilterNames](_image_effect___filter_names.md)。


### OH_EffectFilter_Register()

```
ImageEffect_ErrorCode OH_EffectFilter_Register (const OH_EffectFilterInfo * info, const ImageEffect_FilterDelegate * delegate )
```

**描述**

注册自定义滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 滤镜信息指针[OH_EffectFilterInfo](#oh_effectfilterinfo)。 | 
| delegate | 自定义滤镜回调函数[ImageEffect_FilterDelegate](_image_effect___filter_delegate.md)。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilter_Release()

```
ImageEffect_ErrorCode OH_EffectFilter_Release (OH_EffectFilter * filter)
```

**描述**

销毁OH_EffectFilter实例。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilter_ReleaseFilterNames()

```
void OH_EffectFilter_ReleaseFilterNames ()
```

**描述**

释放滤镜名内存资源。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12


### OH_EffectFilter_Render()

```
ImageEffect_ErrorCode OH_EffectFilter_Render (OH_EffectFilter * filter, OH_PixelmapNative * inputPixelmap, OH_PixelmapNative * outputPixelmap )
```

**描述**

执行图像渲染。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| inputPixelmap | 输入图像。 | 
| outputPixelmap | 输出图像。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilter_SetValue()

```
ImageEffect_ErrorCode OH_EffectFilter_SetValue (OH_EffectFilter * filter, const char * key, const ImageEffect_Any * value )
```

**描述**

设置滤镜参数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 滤镜指针。 | 
| key | 滤镜参数，例如：OH_EFFECT_FILTER_INTENSITY_KEY。 | 
| value | 滤镜参数值。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。 EFFECT_KEY_ERROR如果参数无效。 EFFECT_PARAM_ERROR如果参数值无效。


### OH_EffectFilterInfo_Create()

```
OH_EffectFilterInfo* OH_EffectFilterInfo_Create ()
```

**描述**

创建OH_EffectFilterInfo实例，调用[OH_EffectFilterInfo_Release](#oh_effectfilterinfo_release)进行资源释放。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**返回：**

返回一个指向OH_EffectFilterInfo实例的指针，创建失败时返回空指针。


### OH_EffectFilterInfo_GetFilterName()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetFilterName (OH_EffectFilterInfo * info, char ** name )
```

**描述**

获取滤镜名。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 滤镜信息指针。 | 
| name | 指向char数组的指针，返回滤镜名。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilterInfo_GetSupportedBufferTypes()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedBufferTypes (OH_EffectFilterInfo * info, uint32_t * size, ImageEffect_BufferType ** bufferTypeArray )
```

**描述**

获取滤镜所支持的内存类型。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 滤镜信息指针。 | 
| size | 滤镜所支持内存类型[ImageEffect_BufferType](#imageeffect_buffertype)个数。 | 
| bufferTypeArray | 滤镜所支持内存类型[ImageEffect_BufferType](#imageeffect_buffertype)数组。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilterInfo_GetSupportedFormats()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedFormats (OH_EffectFilterInfo * info, uint32_t * size, ImageEffect_Format ** formatArray )
```

**描述**

获取滤镜所支持的像素格式。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 滤镜信息指针。 | 
| size | 滤镜所支持像素格式[ImageEffect_Format](#imageeffect_format)个数。 | 
| formatArray | 滤镜所支持像素格式[ImageEffect_Format](#imageeffect_format)数组。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilterInfo_Release()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_Release (OH_EffectFilterInfo * info)
```

**描述**

销毁OH_EffectFilterInfo实例。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 滤镜信息指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilterInfo_SetFilterName()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetFilterName (OH_EffectFilterInfo * info, const char * name )
```

**描述**

设置滤镜名。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 滤镜信息指针。 | 
| name | 滤镜名，例如：OH_EFFECT_BRIGHTNESS_FILTER。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilterInfo_SetSupportedBufferTypes()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedBufferTypes (OH_EffectFilterInfo * info, uint32_t size, ImageEffect_BufferType * bufferTypeArray )
```

**描述**

设置滤镜所支持的内存类型。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 滤镜信息指针。 | 
| size | 滤镜所支持内存类型[ImageEffect_BufferType](#imageeffect_buffertype)个数。 | 
| bufferTypeArray | 滤镜所支持内存类型[ImageEffect_BufferType](#imageeffect_buffertype)数组。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_EffectFilterInfo_SetSupportedFormats()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedFormats (OH_EffectFilterInfo * info, uint32_t size, ImageEffect_Format * formatArray )
```

**描述**

设置滤镜所支持的像素格式。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 滤镜信息指针。 | 
| size | 滤镜所支持像素格式[ImageEffect_Format](#imageeffect_format)个数。 | 
| formatArray | 滤镜所支持像素格式[ImageEffect_Format](#imageeffect_format)数组。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_AddFilter()

```
OH_EffectFilter* OH_ImageEffect_AddFilter (OH_ImageEffect * imageEffect, const char * filterName )
```

**描述**

添加滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| filterName | 滤镜名。 | 

**返回：**

返回一个指向OH_EffectFilter实例的指针，滤镜名无效时返回空指针。


### OH_ImageEffect_AddFilterByFilter()

```
ImageEffect_ErrorCode OH_ImageEffect_AddFilterByFilter(OH_ImageEffect *imageEffect, OH_EffectFilter *filter)
```
**描述**
添加指定滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。  | 
| filter | 滤镜指针。  | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_Configure()

```
ImageEffect_ErrorCode OH_ImageEffect_Configure (OH_ImageEffect * imageEffect, const char * key, const ImageEffect_Any * value )
```

**描述**

设置配置信息。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| key | 配置参数。 | 
| value | 配置参数值。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。 EFFECT_KEY_ERROR如果参数无效。 EFFECT_PARAM_ERROR如果参数值无效。


### OH_ImageEffect_Create()

```
OH_ImageEffect* OH_ImageEffect_Create (const char * name)
```

**描述**

创建OH_ImageEffect实例，调用[OH_ImageEffect_Release](#oh_imageeffect_release)进行资源释放。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 效果器名，用于标识效果器，由用户自定义，建议为非空的字符串。 | 

**返回：**

返回一个指向OH_ImageEffect实例的指针，创建失败时返回空指针。


### OH_ImageEffect_GetFilter()

```
OH_EffectFilter* OH_ImageEffect_GetFilter (OH_ImageEffect * imageEffect, uint32_t index )
```

**描述**

查询已添加滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| index | 待查询滤镜位置索引。 | 

**返回：**

返回一个指向OH_EffectFilter实例的指针，参数无效时返回空指针。


### OH_ImageEffect_GetFilterCount()

```
int32_t OH_ImageEffect_GetFilterCount (OH_ImageEffect * imageEffect)
```

**描述**

查询已添加滤镜个数。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 

**返回：**

已添加的滤镜个数。


### OH_ImageEffect_GetInputSurface()

```
ImageEffect_ErrorCode OH_ImageEffect_GetInputSurface (OH_ImageEffect * imageEffect, OHNativeWindow ** nativeWindow )
```

**描述**

获取输入Surface。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| nativeWindow | 指向OHNativeWindow实例的指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_InsertFilter()

```
OH_EffectFilter* OH_ImageEffect_InsertFilter (OH_ImageEffect * imageEffect, uint32_t index, const char * filterName )
```

**描述**

插入滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| index | 插入滤镜位置索引。 | 
| filterName | 滤镜名。 | 

**返回：**

返回一个指向OH_EffectFilter实例的指针，参数无效时返回空指针。


### OH_ImageEffect_InsertFilterByFilter()

```
ImageEffect_ErrorCode OH_ImageEffect_InsertFilterByFilter(OH_ImageEffect *imageEffect, uint32_t index, OH_EffectFilter *filter);
```
**描述**
按指定位置插入滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。  | 
| index | 插入滤镜位置索引。  | 
| filter | 滤镜指针。  | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_Release()

```
ImageEffect_ErrorCode OH_ImageEffect_Release (OH_ImageEffect * imageEffect)
```

**描述**

释放OH_ImageEffect实例资源。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_RemoveFilter()

```
int32_t OH_ImageEffect_RemoveFilter (OH_ImageEffect * imageEffect, const char * filterName )
```

**描述**

移除滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| filterName | 滤镜名。 | 

**返回：**

所删除的滤镜个数。


### OH_ImageEffect_RemoveFilterByIndex()

```
ImageEffect_ErrorCode OH_ImageEffect_RemoveFilterByIndex(OH_ImageEffect *imageEffect, uint32_t index)
```
**描述**
移除指定位置滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。  | 
| index | 移除滤镜位置索引。  | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_ReplaceFilter()

```
OH_EffectFilter *OH_ImageEffect_ReplaceFilter(OH_ImageEffect *imageEffect, uint32_t index, const char *filterName)
```
**描述**
替换滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。  | 
| filterName | 滤镜名。  | 

**返回：**

返回一个指向OH_EffectFilter实例的指针，替换失败时返回空指针。


### OH_ImageEffect_ReplaceFilterByFilter()

```
ImageEffect_ErrorCode OH_ImageEffect_ReplaceFilterByFilter(OH_ImageEffect *imageEffect, uint32_t index, const char *filterName);
```
**描述**
替换指定位置滤镜。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。  | 
| index | 替换滤镜位置索引。  | 
| filterName | 滤镜名。  | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_Restore()

```
OH_ImageEffect* OH_ImageEffect_Restore (const char * info)
```

**描述**

反序列化效果器。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 序列化JSON字符串。 | 

**返回：**

反序列化成功时返回OH_ImageEffect实例，否则返回空指针。


### OH_ImageEffect_Save()

```
ImageEffect_ErrorCode OH_ImageEffect_Save (OH_ImageEffect * imageEffect, char ** info )
```

**描述**

序列化效果器。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| info | 指向char数组的指针，返回序列化JSON字符串。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_SetInputNativeBuffer()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputNativeBuffer (OH_ImageEffect * imageEffect, OH_NativeBuffer * nativeBuffer )
```

**描述**

设置输入的NativeBuffer。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| nativeBuffer | 指向OH_NativeBuffer实例的指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_SetInputPixelmap()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputPixelmap (OH_ImageEffect * imageEffect, OH_PixelmapNative * pixelmap )
```

**描述**

设置输入的Pixelmap。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| pixelmap | 指向OH_PixelmapNative实例的指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_SetInputUri()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputUri (OH_ImageEffect * imageEffect, const char * uri )
```

**描述**

设置输入的URI。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| uri | 图片URI。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_SetOutputNativeBuffer()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputNativeBuffer (OH_ImageEffect * imageEffect, OH_NativeBuffer * nativeBuffer )
```

**描述**

设置输出的NativeBuffer。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| imageEffect | 效果器指针。 |
| nativeBuffer | 指向OH_NativeBuffer实例的指针，允许为空，当输入为空时渲染结果返回到输入的OH_NativeBuffer对象上。 |

**返回：**

EFFECT_SUCCESS，如果方法调用成功。

EFFECT_ERROR_PARAM_INVALID，如果效果器入参为空指针。

EFFECT_PARAM_ERROR，如果参数异常导致方法调用失败。


### OH_ImageEffect_SetOutputPixelmap()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputPixelmap (OH_ImageEffect * imageEffect, OH_PixelmapNative * pixelmap )
```

**描述**

设置输出的Pixelmap。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| imageEffect | 效果器指针。 |
| pixelmap | 指向OH_PixelmapNative实例的指针，允许为空，当输入为空时渲染结果返回到输入的OH_PixelmapNative对象上。 |

**返回：**

EFFECT_SUCCESS，如果方法调用成功。

EFFECT_ERROR_PARAM_INVALID，如果效果器入参为空指针。

EFFECT_PARAM_ERROR，如果参数异常导致方法调用失败。


### OH_ImageEffect_SetOutputSurface()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputSurface (OH_ImageEffect * imageEffect, OHNativeWindow * nativeWindow )
```

**描述**

设置输出Surface。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| nativeWindow | 指向OHNativeWindow实例的指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_SetOutputUri()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputUri (OH_ImageEffect * imageEffect, const char * uri )
```

**描述**

设置输出的URI。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 
| uri | 图片URI。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。


### OH_ImageEffect_Start()

```
ImageEffect_ErrorCode OH_ImageEffect_Start (OH_ImageEffect * imageEffect)
```

**描述**

启动效果器。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。 EFFECT_INPUT_OUTPUT_NOT_SUPPORTED如果待处理输入、输出图像数据类型不一致。 EFFECT_COLOR_SPACE_NOT_MATCH如果输入、输出图像色彩空间不配置。 EFFECT_ALLOCATE_MEMORY_FAILED如果内存申请失败。


### OH_ImageEffect_Stop()

```
ImageEffect_ErrorCode OH_ImageEffect_Stop (OH_ImageEffect * imageEffect)
```

**描述**

停止生效效果。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageEffect | 效果器指针。 | 

**返回：**

EFFECT_SUCCESS如果方法调用成功。 EFFECT_ERROR_PARAM_INVALID如果入参为空指针。
