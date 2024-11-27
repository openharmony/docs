# ImageProcessing


## 概述

ImageProcessing模块提供图片处理功能的API接口，包括颜色空间转换和元数据生成。

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [image_processing.h](image__processing_8h.md) | 声明图片处理函数。 | 
| [image_processing_types.h](image__processing__types_8h.md) | 图片处理的类型定义。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) | 色彩空间信息，用于色彩空间转换能力查询。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_ImageProcessing](#oh_imageprocessing) [OH_ImageProcessing](#oh_imageprocessing) | 提供OH_ImageProcessing结构体声明。 | 
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) [OH_PixelmapNative](#oh_pixelmapnative) | 提供OH_PixelmapNative结构体声明。 | 
| typedef struct [OH_AVFormat](#oh_avformat) [OH_AVFormat](#oh_avformat) | 提供OH_AVFormat结构体声明。 | 
| typedef struct [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) [ImageProcessing_ColorSpaceInfo](#imageprocessing_colorspaceinfo) | 色彩空间信息，用于色彩空间转换能力查询。 | 
| typedef enum [ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel-1) [ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel) | 质量级别，用于细节增强能力。 | 
| typedef enum [ImageProcessing_ErrorCode](#imageprocessing_errorcode-1) [ImageProcessing_ErrorCode](#imageprocessing_errorcode) | 图片处理接口错误码说明。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel-1) { <br/>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_NONE,<br/>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_LOW,<br/>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM,<br/>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH } | 质量级别，用于细节增强能力。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode-1) {<br/>IMAGE_PROCESSING_SUCCESS,<br/>IMAGE_PROCESSING_ERROR_INVALID_PARAMETER = 401,<br/>IMAGE_PROCESSING_ERROR_UNKNOWN = 29200001,<br/>IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED,<br/>IMAGE_PROCESSING_ERROR_CREATE_FAILED,<br/>IMAGE_PROCESSING_ERROR_PROCESS_FAILED,<br/>IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,<br/>IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,<br/>IMAGE_PROCESSING_ERROR_NO_MEMORY,<br/>IMAGE_PROCESSING_ERROR_INVALID_INSTANCE,<br/>IMAGE_PROCESSING_ERROR_INVALID_VALUE<br/>} | 图片处理接口错误码说明。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment) (void) | 初始化图片处理模块的全局环境。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_DeinitializeEnvironment](#oh_imageprocessing_deinitializeenvironment) (void) | 反初始化图片处理模块的全局环境。 | 
| bool [OH_ImageProcessing_IsColorSpaceConversionSupported](#oh_imageprocessing_iscolorspaceconversionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo) | 查询是否支持当前图片色彩空间转换能力。 | 
| bool [OH_ImageProcessing_IsCompositionSupported](#oh_imageprocessing_iscompositionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceGainmapInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo) | 查询是否支持HDR双层图片转换为HDR单层图片。 | 
| bool [OH_ImageProcessing_IsDecompositionSupported](#oh_imageprocessing_isdecompositionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationGainmapInfo) | 查询是否支持HDR单层图片转换为HDR双层图片。 | 
| bool [OH_ImageProcessing_IsMetadataGenerationSupported](#oh_imageprocessing_ismetadatagenerationsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo) | 查询是否支持图片元数据生成能力。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_Create](#oh_imageprocessing_create) ([OH_ImageProcessing](#oh_imageprocessing) \*\*imageProcessor, int32_t type) | 创建一个图片处理模块实例。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_Destroy](#oh_imageprocessing_destroy) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor) | 销毁当前图片处理模块实例。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_SetParameter](#oh_imageprocessing_setparameter) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, const [OH_AVFormat](#oh_avformat) \*parameter) | 设置图片处理模块参数。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_GetParameter](#oh_imageprocessing_getparameter) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_AVFormat](#oh_avformat) \*parameter) | 获取图片处理模块参数。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_ConvertColorSpace](#oh_imageprocessing_convertcolorspace) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationImage) | 实现单层图片间转换。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_Compose](#oh_imageprocessing_compose) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceGainmap, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationImage) | 实现HDR双层图片到HDR单层图片的转换。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_Decompose](#oh_imageprocessing_decompose) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationImage, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationGainmap) | 实现HDR单层图片到HDR双层图片的转换。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_GenerateMetadata](#oh_imageprocessing_generatemetadata) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage) | 生成HDR图片元数据。 | 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_EnhanceDetail](#oh_imageprocessing_enhancedetail) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationImage) | 进行图片清晰度/细节增强。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const int32_t [IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](#image_processing_type_color_space_conversion) | 用于创建色彩空间转换的图片处理实例。 | 
| const int32_t [IMAGE_PROCESSING_TYPE_COMPOSITION](#image_processing_type_composition) | 用于创建双层HDR图片转换单层HDR图片的图片处理实例。 | 
| const int32_t [IMAGE_PROCESSING_TYPE_DECOMPOSITION](#image_processing_type_decomposition) | 用于创建单层HDR图片转换双层HDR图片的图片处理实例。 | 
| const int32_t [IMAGE_PROCESSING_TYPE_METADATA_GENERATION](#image_processing_type_metadata_generation) | 用于创建元数据生成的图片处理实例。 | 
| const int32_t [IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER](#image_processing_type_detail_enhancer) | 用于创建细节增强的图片处理实例。 | 
| const char \* [IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#image_detail_enhancer_parameter_key_quality_level) | 用于设定图像细节增强的质量级别。 | 


## 类型定义说明


### ImageDetailEnhancer_QualityLevel

```
typedef enum ImageDetailEnhancer_QualityLevel ImageDetailEnhancer_QualityLevel
```

**描述**

质量级别，用于细节增强能力。

键参数的值[IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#image_detail_enhancer_parameter_key_quality_level)。

**起始版本：** 13

**参见：**

[OH_ImageProcessing_SetParameter](#oh_imageprocessing_setparameter)

[OH_ImageProcessing_GetParameter](#oh_imageprocessing_getparameter)


### ImageProcessing_ColorSpaceInfo

```
typedef struct ImageProcessing_ColorSpaceInfo ImageProcessing_ColorSpaceInfo
```

**描述**

色彩空间信息，用于色彩空间转换能力查询。

**起始版本：** 13

**参见：**

[OH_ImageProcessing_IsColorSpaceConversionSupported](#oh_imageprocessing_iscolorspaceconversionsupported)

[OH_ImageProcessing_IsCompositionSupported](#oh_imageprocessing_iscompositionsupported)

[OH_ImageProcessing_IsDecompositionSupported](#oh_imageprocessing_isdecompositionsupported)


### ImageProcessing_ErrorCode

```
typedef enum ImageProcessing_ErrorCode ImageProcessing_ErrorCode
```

**描述**

图片处理接口错误码说明。

**起始版本：** 13


### OH_AVFormat

```
typedef struct OH_AVFormat OH_AVFormat
```

**描述**

提供OH_AVFormat结构体声明。

**起始版本：** 13


### OH_ImageProcessing

```
typedef struct OH_ImageProcessing OH_ImageProcessing
```

**描述**

提供OH_ImageProcessing结构体声明。

定义了OH_ImageProcessing的空指针并调用[OH_ImageProcessing_Create](#oh_imageprocessing_create)来创建图片处理实例。在创建实例之前，指针应为空。用户可以为不同的处理类型创建多个图片实例。

**起始版本：** 13


### OH_PixelmapNative

```
typedef struct OH_PixelmapNative OH_PixelmapNative
```

**描述**

提供OH_PixelmapNative结构体声明。

**起始版本：** 13


## 枚举类型说明


### ImageDetailEnhancer_QualityLevel

```
enum ImageDetailEnhancer_QualityLevel
```

**描述**

质量级别，用于细节增强能力。

键参数的值[IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#image_detail_enhancer_parameter_key_quality_level)。

**起始版本：** 13

**参见：**

[OH_ImageProcessing_SetParameter](#oh_imageprocessing_setparameter)

[OH_ImageProcessing_GetParameter](#oh_imageprocessing_getparameter)

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_NONE | 无细节增强。 | 
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_LOW | 细节增强质量较低，但速度较快。默认级别。 | 
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM | 细节增强质量中等，速度介于低级别与高级别之间。 | 
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH | 细节增强质量较高，但速度较慢。 | 


### ImageProcessing_ErrorCode

```
enum ImageProcessing_ErrorCode
```

**描述**

图片处理接口错误码说明。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_PROCESSING_SUCCESS | 成功。 | 
| IMAGE_PROCESSING_ERROR_INVALID_PARAMETER | 输入参数无效。<br>在以下错误条件返回该错误码： <br>1 - 输入或输出buffer无效，例如图片buffer为空。 <br>2 - 参数无效，例如参数为空。 <br>3 - 类型无效，例如在创建函数中传入的类型不存在。 | 
| IMAGE_PROCESSING_ERROR_UNKNOWN | 未知错误，例如GPU计算失败或memcpy失败。 | 
| IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED | 全局环境初始化失败，例如GPU环境初始化失败。 | 
| IMAGE_PROCESSING_ERROR_CREATE_FAILED | 创建图片处理实例失败，例如实例数量超过上限。 | 
| IMAGE_PROCESSING_ERROR_PROCESS_FAILED | 处理图片buffer失败，例如处理超时。 | 
| IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING | 当前处理不支持，可以通过“OH_ImageProcessing_IsXXXSupported”接口查询是否支持该能力。 | 
| IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED | 无权限操作，可能由于状态不正确导致。 | 
| IMAGE_PROCESSING_ERROR_NO_MEMORY | 内存不足。 | 
| IMAGE_PROCESSING_ERROR_INVALID_INSTANCE | 无效的图片处理实例，可能由于实例为空导致。 | 
| IMAGE_PROCESSING_ERROR_INVALID_VALUE | 输入值无效。<br>在以下错误条件下返回该错误码： <br>1 - 输入或输出图片buffer无效，例如图片buffer的宽度（高度）过大或颜色空间不正确。 <br>2 - 参数无效，例如参数不包括有效信息，例如细节增强的质量级别不正确。 | 


## 函数说明


### OH_ImageProcessing_Compose()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Compose(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* sourceGainmap, OH_PixelmapNative* destinationImage)
```

**描述**

实现HDR双层图片到HDR单层图片的转换。

此函数通过输入图片与输入Gainmap生成输出图片。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 指向图片处理模块实例的指针。该实例应该由[IMAGE_PROCESSING_TYPE_COMPOSITION](#image_processing_type_composition)类型创建。 | 
| sourceImage | 指向输入图片的指针。 | 
| sourceGainmap | 指向输入Gainmap的指针。 | 
| destinationImage | 指向输出图片的指针。 | 

**返回：**

- 如果图片处理成功，则返回IMAGE_PROCESSING_SUCCESS。
- 当该实例为空或该实例不是图片处理模块实例时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。 
- 当图片为空时，返回IMAGE_PROCESSING_ERROR_INVALID_PARAMETER。 
- 当图片的某些属性无效时，返回IMAGE_PROCESSING_ERROR_INVALID_VALUE，例如图片的色彩空间时不支持的。 
- 当该图片处理不支持时，返回IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。 
- 当该图片处理中返回错误时，返回IMAGE_PROCESSING_ERROR_PROCESS_FAILED。 
- 当内存分配失败时，返回IMAGE_PROCESSING_ERROR_NO_MEMORY。


### OH_ImageProcessing_ConvertColorSpace()

```
ImageProcessing_ErrorCode OH_ImageProcessing_ConvertColorSpace(OH_ImageProcessing* imageProcessor, OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage)
```

**描述**

实现单层图片间转换。

此函数包括HDR图片到SDR图片的色彩空间转换，SDR图片到HDR图片的色彩空间转换，SDR图片到SDR图片的色彩空间转换和HDR图片的色彩空间转换。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 指向图片处理模块实例的指针。该实例应该由[IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](#image_processing_type_color_space_conversion)类型创建。 | 
| sourceImage | 指向输入图片的指针。 | 
| destinationImage | 指向输出图片的指针。 | 

**返回：**

- 如果图片处理成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 当该实例为空或该实例不是图片处理模块实例时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。 
- 当图片为空时，返回IMAGE_PROCESSING_ERROR_INVALID_PARAMETER。 
- 当图片的某些属性无效时，返回IMAGE_PROCESSING_ERROR_INVALID_VALUE，例如图片的色彩空间时不支持的。 
- 当该图片处理不支持时，返回IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。 
- 当该图片处理中返回错误时，返回IMAGE_PROCESSING_ERROR_PROCESS_FAILED。 
- 当内存分配失败时，返回IMAGE_PROCESSING_ERROR_NO_MEMORY。


### OH_ImageProcessing_Create()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Create(OH_ImageProcessing** imageProcessor, int32_t type)
```

**描述**

创建一个图片处理模块实例。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 输出参数。指针\*imageProcessor指向一个新的图片处理对象。 指针\*imageProcessor在传递前必须是一个空指针。 | 
| type | 使用IMAGE_PROCESSING_TYPE_XXX来指定图片处理类型。此实例的类型在创建后不能更改。 | 

**返回：**

- 如果创建成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 当指定的图片处理类型不支持时，返回IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING，例如如果不支持图片元数据生成能力，则返回不支持该处理类型。 
- 当创建失败时，返回IMAGE_PROCESSING_ERROR_CREATE_FAILED。 
- 当该实例为空或指向该实例的指针为空时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。 
- 当指定的图片处理类型无效时，返回IMAGE_PROCESSING_ERROR_INVALID_PARAMETER。


### OH_ImageProcessing_Decompose()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Decompose(OH_ImageProcessing* imageProcessor, OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage, OH_PixelmapNative* destinationGainmap)
```

**描述**

实现HDR单层图片到HDR双层图片的转换。

此函数通过输入图片生成输出图片和输出Gainmap。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 指向图片处理模块实例的指针。该实例应该由[IMAGE_PROCESSING_TYPE_DECOMPOSITION](#image_processing_type_decomposition)类型创建。 | 
| sourceImage | 指向输入图片的指针。 | 
| destinationImage | 指向输出图片的指针。 | 
| destinationGainmap | 指向输出Gainmap的指针。 | 

**返回：**

- 如果图片处理成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 当该实例为空或该实例不是图片处理模块实例时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。 
- 当图片为空时，返回IMAGE_PROCESSING_ERROR_INVALID_PARAMETER。 
- 当图片的某些属性无效时，返回IMAGE_PROCESSING_ERROR_INVALID_VALUE，例如图片的色彩空间时不支持的。 当该图片处理不支持时，返回IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。 
- 当该图片处理中返回错误时，返回IMAGE_PROCESSING_ERROR_PROCESS_FAILED。 
- 当内存分配失败时，返回IMAGE_PROCESSING_ERROR_NO_MEMORY。


### OH_ImageProcessing_DeinitializeEnvironment()

```
ImageProcessing_ErrorCode OH_ImageProcessing_DeinitializeEnvironment(void)
```

**描述**

反初始化图片处理模块的全局环境。

如果[OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment)被调用，则此函数为必需函数。 通常此函数在主进程准备退出时被调用，用于反初始化图片处理模块的全局环境（由[OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment)接口 初始化）。 如果此时存在图片处理实例，则不应调用此函数。 如果[OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment)未被调用，则不应调用此函数。

**起始版本：** 13

**返回：**

- 如果反初始化成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 如果存在图片处理实例未被销毁或[OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment)接口未被调用，则返回 IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED。


### OH_ImageProcessing_Destroy()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Destroy(OH_ImageProcessing* imageProcessor)
```

**描述**

销毁当前图片处理模块实例。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 指向图片处理模块实例的指针。当实例被销毁时，建议该指针设置为空。 | 

**返回：**

- 如果销毁成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 当该实例为空或该实例不是图片处理模块实例时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。


### OH_ImageProcessing_EnhanceDetail()

```
ImageProcessing_ErrorCode OH_ImageProcessing_EnhanceDetail(OH_ImageProcessing* imageProcessor, OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage)
```

**描述**

进行图片清晰度/细节增强。

此函数根据输入图片和输出图片预设的尺寸，对源图片进行必要的缩放操作生成目标图片，并提供了多种缩放方法以平衡性能和图像质量。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 指向图片处理模块实例的指针。该实例应该由[IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER](#image_processing_type_detail_enhancer)类型创建。 | 
| sourceImage | 指向输入图片的指针。 | 
| destinationImage | 指向输出图片的指针。 | 

**返回：**

- 如果图片处理成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 当该实例为空或该实例不是图片处理模块实例时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。 
- 当图片为空时，返回IMAGE_PROCESSING_ERROR_INVALID_PARAMETER。 
- 当图片的某些属性无效时，返回IMAGE_PROCESSING_ERROR_INVALID_VALUE，例如图片的色彩空间时不支持的。 
- 当该图片处理不支持时，返回IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。 
- 当该图片处理中返回错误时，返回IMAGE_PROCESSING_ERROR_PROCESS_FAILED。 
- 当内存分配失败时，返回IMAGE_PROCESSING_ERROR_NO_MEMORY。


### OH_ImageProcessing_GenerateMetadata()

```
ImageProcessing_ErrorCode OH_ImageProcessing_GenerateMetadata(OH_ImageProcessing* imageProcessor, OH_PixelmapNative* sourceImage)
```

**描述**

生成HDR图片元数据。

此函数为HDR图片生成元数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 指向图片处理模块实例的指针。该实例应该由[IMAGE_PROCESSING_TYPE_METADATA_GENERATION](#image_processing_type_metadata_generation)类型创建。 | 
| sourceImage | 指向输入图片的指针。 | 

**返回：**

- 如果图片处理成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 当该实例为空或该实例不是图片处理模块实例时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。 
- 当图片为空时，返回IMAGE_PROCESSING_ERROR_INVALID_PARAMETER。 
- 当图片的某些属性无效时，返回IMAGE_PROCESSING_ERROR_INVALID_VALUE，例如图片的色彩空间时不支持的。 当该图片处理不支持时，返回IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。 
- 当该图片处理中返回错误时，返回IMAGE_PROCESSING_ERROR_PROCESS_FAILED。 
- 当内存分配失败时，返回IMAGE_PROCESSING_ERROR_NO_MEMORY。


### OH_ImageProcessing_GetParameter()

```
ImageProcessing_ErrorCode OH_ImageProcessing_GetParameter(OH_ImageProcessing* imageProcessor, OH_AVFormat* parameter)
```

**描述**

获取图片处理模块参数。

通过特定参数键获取参数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 指向图片处理模块实例的指针。 | 
| parameter | 该图片处理模块实例使用的参数。 | 

**返回：**

- 如果获取参数不成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 当该实例为空或该实例不是图片处理模块实例时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。 
- 当参数为空时，返回IMAGE_PROCESSING_ERROR_INVALID_PARAMETER。


### OH_ImageProcessing_InitializeEnvironment()

```
ImageProcessing_ErrorCode OH_ImageProcessing_InitializeEnvironment(void)
```

**描述**

初始化图片处理模块的全局环境。

此函数为非必需函数。 通常此函数在主进程启动时被调用，用于图片处理模块的全局环境初始化并可以减少[OH_ImageProcessing_Create](#oh_imageprocessing_create)的耗时。 调用[OH_ImageProcessing_DeinitializeEnvironment](#oh_imageprocessing_deinitializeenvironment)进行全局环境反初始化。 可用于检查设备GPU是否正常工作。

**起始版本：** 13

**返回：**

如果初始化成功，则返回IMAGE_PROCESSING_SUCCESS，否则返回IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED。


### OH_ImageProcessing_IsColorSpaceConversionSupported()

```
bool OH_ImageProcessing_IsColorSpaceConversionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo, const ImageProcessing_ColorSpaceInfo* destinationImageInfo)
```

**描述**

查询是否支持当前图片色彩空间转换能力。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sourceImageInfo | 指向输入图片色彩空间信息的指针。 | 
| destinationImageInfo | 指向输出图片色彩空间信息的指针， | 

**返回：**

如果支持当前色彩空间转换，返回true。如果不支持当前色彩空间转换，返回false。


### OH_ImageProcessing_IsCompositionSupported()

```
bool OH_ImageProcessing_IsCompositionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo, const ImageProcessing_ColorSpaceInfo* sourceGainmapInfo, const ImageProcessing_ColorSpaceInfo* destinationImageInfo)
```

**描述**

查询是否支持HDR双层图片转换为HDR单层图片。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sourceImageInfo | 指向输入图片色彩空间信息的指针。 | 
| sourceGainmapInfo | 指向输入Gainmap色彩空间信息的指针。 | 
| destinationImageInfo | 指向输出图片色彩空间信息的指针。 | 

**返回：**

如果支持HDR双层图片转换HDR单层图片能力，返回true。如果不支持此能力，返回false。


### OH_ImageProcessing_IsDecompositionSupported()

```
bool OH_ImageProcessing_IsDecompositionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo, const ImageProcessing_ColorSpaceInfo* destinationImageInfo, const ImageProcessing_ColorSpaceInfo* destinationGainmapInfo)
```

**描述**

查询是否支持HDR单层图片转换为HDR双层图片。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sourceImageInfo | 指向输入图片色彩空间信息的指针。 | 
| destinationImageInfo | 指向输出图片色彩空间信息的指针。 | 
| destinationGainmapInfo | 指向输出Gainmap色彩空间信息的指针。 | 

**返回：**

如果支持HDR单层图片转换为HDR双层图片能力，返回true。如果不支持此能力，返回false。


### OH_ImageProcessing_IsMetadataGenerationSupported()

```
bool OH_ImageProcessing_IsMetadataGenerationSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo)
```

**描述**

查询是否支持图片元数据生成能力。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sourceImageInfo | 指向输入图片色彩空间信息的指针。 | 

**返回：**

如果支持图片元数据生成能力，返回true。如果不支持此能力，返回false。


### OH_ImageProcessing_SetParameter()

```
ImageProcessing_ErrorCode OH_ImageProcessing_SetParameter(OH_ImageProcessing* imageProcessor, const OH_AVFormat* parameter)
```

**描述**

设置图片处理模块参数。

通过特定参数键添加参数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imageProcessor | 指向图片处理模块实例的指针。 | 
| parameter | 图片处理参数。 | 

**返回：**

- 如果设置参数成功，则返回IMAGE_PROCESSING_SUCCESS。 
- 当该实例为空或该实例不是图片处理模块实例时，返回IMAGE_PROCESSING_ERROR_INVALID_INSTANCE。 
- 当参数为空时，返回IMAGE_PROCESSING_ERROR_INVALID_PARAMETER。 
- 当部分参数无效时，返回IMAGE_PROCESSING_ERROR_INVALID_VALUE，例如参数包含不支持的参数键或值。 
- 当内存分配失败时，返回IMAGE_PROCESSING_ERROR_NO_MEMORY。


## 变量说明


### IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL

```
const char* IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL
```

**描述**

用于设定图像细节增强的质量级别。

使用[ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel)获取其值。 使用[OH_ImageProcessing_SetParameter](#oh_imageprocessing_setparameter)设置质量级别。 使用[OH_ImageProcessing_GetParameter](#oh_imageprocessing_getparameter)获取当前质量级别。

**起始版本：** 13

**参见：**

[OH_VideoProcessing_SetParameter](../apis-media-kit/_video_processing.md#oh_videoprocessing_setparameter)

[OH_VideoProcessing_GetParameter](../apis-media-kit/_video_processing.md#oh_videoprocessing_getparameter)


### IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION

```
const int32_t IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION
```

**描述**

用于创建色彩空间转换的图片处理实例。

色彩空间转换包括单层HDR图片转换SDR图片，SDR图片之间的转换，以及SDR图片转换单层HDR图片，部分能力由厂商支持。 使用**OH_ImageProcessing_IsColorSpaceConversionSuported**查询某种转换是否支持在单层图片之间进行。

**起始版本：** 13

**参见：**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)


### IMAGE_PROCESSING_TYPE_COMPOSITION

```
const int32_t IMAGE_PROCESSING_TYPE_COMPOSITION
```

**描述**

用于创建双层HDR图片转换单层HDR图片的图片处理实例。

包括从双层HDR图片转换为单层HDR图片的能力。部分能力由厂商支持。 使用[OH_ImageProcessing_IsCompositionSupported](#oh_imageprocessing_iscompositionsupported)查询是否支持从双层HDR图片到单层HDR图片的转换。

**起始版本：** 13

**参见：**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)


### IMAGE_PROCESSING_TYPE_DECOMPOSITION

```
const int32_t IMAGE_PROCESSING_TYPE_DECOMPOSITION
```

**描述**

用于创建单层HDR图片转换双层HDR图片的图片处理实例。

包括从单层HDR图片转换为双层HDR图片的能力。部分能力由厂商支持。 使用[OH_ImageProcessing_IsDecompositionSupported](#oh_imageprocessing_isdecompositionsupported)查询是否支持从单层HDR图片到双层HDR图片的转换。

**起始版本：** 13

**参见：**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)


### IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER

```
const int32_t IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER
```

**描述**

用于创建细节增强的图片处理实例。

按指定图像质量缩放或调整图片大小，或仅增强图像细节以在不更改分辨率的情况下渲染图片。

**起始版本：** 13

**参见：**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)


### IMAGE_PROCESSING_TYPE_METADATA_GENERATION

```
const int32_t IMAGE_PROCESSING_TYPE_METADATA_GENERATION
```

**描述**

用于创建元数据生成的图片处理实例。

生成单层HDR图片的HDR Vivid元数据。该能力由厂商支持。如果不支持该能力，[OH_ImageProcessing_Create](#oh_imageprocessing_create)将返回 IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING。

**起始版本：** 13

**参见：**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)
