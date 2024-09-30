# image_processing.h


## 概述

声明图片处理函数。

提供图片处理能力，包括色彩空间转换，元数据生成及图片缩放。

**库：** libimage_processing.so

**系统能力：** SystemCapability.Multimedia.VideoProcessingEngine

**起始版本：** 13

**相关模块：**[ImageProcessing](_image_processing.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_InitializeEnvironment](_image_processing.md#oh_imageprocessing_initializeenvironment) (void) | 初始化图片处理模块的全局环境。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_DeinitializeEnvironment](_image_processing.md#oh_imageprocessing_deinitializeenvironment) (void) | 反初始化图片处理模块的全局环境。 | 
| bool [OH_ImageProcessing_IsColorSpaceConversionSupported](_image_processing.md#oh_imageprocessing_iscolorspaceconversionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo) | 查询是否支持当前图片色彩空间转换能力。 | 
| bool [OH_ImageProcessing_IsCompositionSupported](_image_processing.md#oh_imageprocessing_iscompositionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceGainmapInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo) | 查询是否支持HDR双层图片转换为HDR单层图片。 | 
| bool [OH_ImageProcessing_IsDecompositionSupported](_image_processing.md#oh_imageprocessing_isdecompositionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationGainmapInfo) | 查询是否支持HDR单层图片转换为HDR双层图片。 | 
| bool [OH_ImageProcessing_IsMetadataGenerationSupported](_image_processing.md#oh_imageprocessing_ismetadatagenerationsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo) | 查询是否支持图片元数据生成能力。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_Create](_image_processing.md#oh_imageprocessing_create) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*\*imageProcessor, int32_t type) | 创建一个图片处理模块实例。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_Destroy](_image_processing.md#oh_imageprocessing_destroy) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor) | 销毁当前图片处理模块实例。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_SetParameter](_image_processing.md#oh_imageprocessing_setparameter) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, const [OH_AVFormat](_image_processing.md#oh_avformat) \*parameter) | 设置图片处理模块参数。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_GetParameter](_image_processing.md#oh_imageprocessing_getparameter) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_AVFormat](_image_processing.md#oh_avformat) \*parameter) | 获取图片处理模块参数。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_ConvertColorSpace](_image_processing.md#oh_imageprocessing_convertcolorspace) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationImage) | 实现单层图片间转换。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_Compose](_image_processing.md#oh_imageprocessing_compose) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceGainmap, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationImage) | 实现HDR双层图片到HDR单层图片的转换。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_Decompose](_image_processing.md#oh_imageprocessing_decompose) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationGainmap) | 实现HDR单层图片到HDR双层图片的转换。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_GenerateMetadata](_image_processing.md#oh_imageprocessing_generatemetadata) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage) | 生成HDR图片元数据。 | 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_EnhanceDetail](_image_processing.md#oh_imageprocessing_enhancedetail) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationImage) | 进行图片清晰度/细节增强。 | 
