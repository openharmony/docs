# image_processing.h


## Overview

The **image_processing.h** file declares the image processing functions.

It provides capabilities such as Color Space Conversion (CSC), metadata generation, and image scaling.

**Library**: libimage_processing.so

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Since**: 13

**Related module**: [ImageProcessing](_image_processing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_InitializeEnvironment](_image_processing.md#oh_imageprocessing_initializeenvironment) (void) | Initializes the global environment of the image processing module.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_DeinitializeEnvironment](_image_processing.md#oh_imageprocessing_deinitializeenvironment) (void) | Deinitializes the global environment of the image processing module.| 
| bool [OH_ImageProcessing_IsColorSpaceConversionSupported](_image_processing.md#oh_imageprocessing_iscolorspaceconversionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo) | Checks whether CSC is supported for an image.| 
| bool [OH_ImageProcessing_IsCompositionSupported](_image_processing.md#oh_imageprocessing_iscompositionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceGainmapInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo) | Checks whether a dual-layer HDR image can be converted into a single-layer HDR image.| 
| bool [OH_ImageProcessing_IsDecompositionSupported](_image_processing.md#oh_imageprocessing_isdecompositionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationGainmapInfo) | Checks whether a single-layer HDR image can be converted into a dual-layer HDR image.| 
| bool [OH_ImageProcessing_IsMetadataGenerationSupported](_image_processing.md#oh_imageprocessing_ismetadatagenerationsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo) | Checks whether metadata generation is supported for an image.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_Create](_image_processing.md#oh_imageprocessing_create) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*\*imageProcessor, int32_t type) | Creates an image processing instance.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_Destroy](_image_processing.md#oh_imageprocessing_destroy) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor) | Destroys an image processing instance.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_SetParameter](_image_processing.md#oh_imageprocessing_setparameter) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, const [OH_AVFormat](_image_processing.md#oh_avformat) \*parameter) | Sets a parameter for the image processing module.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_GetParameter](_image_processing.md#oh_imageprocessing_getparameter) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_AVFormat](_image_processing.md#oh_avformat) \*parameter) | Obtains a parameter of the image processing module.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_ConvertColorSpace](_image_processing.md#oh_imageprocessing_convertcolorspace) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationImage) | Converts the color space for a single-layer image.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_Compose](_image_processing.md#oh_imageprocessing_compose) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceGainmap, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationImage) | Converts a dual-layer HDR image into a single-layer HDR image.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_Decompose](_image_processing.md#oh_imageprocessing_decompose) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationGainmap) | Converts a single-layer HDR image into a double-layer HDR image.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_GenerateMetadata](_image_processing.md#oh_imageprocessing_generatemetadata) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage) | Generates metadata for an HDR image.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) [OH_ImageProcessing_EnhanceDetail](_image_processing.md#oh_imageprocessing_enhancedetail) ([OH_ImageProcessing](_image_processing.md#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) \*destinationImage) | Enhances the image definition and details.| 
