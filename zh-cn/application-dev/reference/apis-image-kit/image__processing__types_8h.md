# image_processing_types.h


## 概述

图片处理的类型定义。

**库：** libimage_processing.so

**引用文件**：&lt;multimedia/video_processing_engine/image_processing_types.h&gt;

**系统能力：** SystemCapability.Multimedia.VideoProcessingEngine

**起始版本：** 13

**相关模块：**[ImageProcessing](_image_processing.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) | 色彩空间信息，用于色彩空间转换能力查询。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_ImageProcessing](_image_processing.md#oh_imageprocessing) [OH_ImageProcessing](_image_processing.md#oh_imageprocessing) | 提供OH_ImageProcessing结构体声明。 | 
| typedef struct [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) | 提供OH_PixelmapNative结构体声明。 | 
| typedef struct [OH_AVFormat](_image_processing.md#oh_avformat) [OH_AVFormat](_image_processing.md#oh_avformat) | 提供OH_AVFormat结构体声明。 | 
| typedef struct [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) [ImageProcessing_ColorSpaceInfo](_image_processing.md#imageprocessing_colorspaceinfo) | 色彩空间信息，用于色彩空间转换能力查询。 | 
| typedef enum [ImageDetailEnhancer_QualityLevel](_image_processing.md#imagedetailenhancer_qualitylevel-1) [ImageDetailEnhancer_QualityLevel](_image_processing.md#imagedetailenhancer_qualitylevel) | 质量级别，用于细节增强能力。 | 
| typedef enum [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode-1) [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) | 图片处理接口错误码说明。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ImageDetailEnhancer_QualityLevel](_image_processing.md#imagedetailenhancer_qualitylevel-1) { <br/>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_NONE,<br/>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_LOW,<br/>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM,<br/>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH } | 质量级别，用于细节增强能力。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode-1) {<br/>IMAGE_PROCESSING_SUCCESS,<br/>IMAGE_PROCESSING_ERROR_INVALID_PARAMETER = 401,<br/>IMAGE_PROCESSING_ERROR_UNKNOWN = 29200001,<br/>IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED,<br/>IMAGE_PROCESSING_ERROR_CREATE_FAILED,<br/>IMAGE_PROCESSING_ERROR_PROCESS_FAILED,<br/>IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,<br/>IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,<br/>IMAGE_PROCESSING_ERROR_NO_MEMORY,<br/>IMAGE_PROCESSING_ERROR_INVALID_INSTANCE,<br/>IMAGE_PROCESSING_ERROR_INVALID_VALUE<br/>} | 图片处理接口错误码说明。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const int32_t [IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](_image_processing.md#image_processing_type_color_space_conversion) | 用于创建色彩空间转换的图片处理实例。 | 
| const int32_t [IMAGE_PROCESSING_TYPE_COMPOSITION](_image_processing.md#image_processing_type_composition) | 用于创建双层HDR图片转换单层HDR图片的图片处理实例。 | 
| const int32_t [IMAGE_PROCESSING_TYPE_DECOMPOSITION](_image_processing.md#image_processing_type_decomposition) | 用于创建单层HDR图片转换双层HDR图片的图片处理实例。 | 
| const int32_t [IMAGE_PROCESSING_TYPE_METADATA_GENERATION](_image_processing.md#image_processing_type_metadata_generation) | 用于创建元数据生成的图片处理实例。 | 
| const int32_t [IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER](_image_processing.md#image_processing_type_detail_enhancer) | 用于创建细节增强的图片处理实例。 | 
| const char \* [IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](_image_processing.md#image_detail_enhancer_parameter_key_quality_level) | 用于设定图像细节增强的质量级别。 | 
