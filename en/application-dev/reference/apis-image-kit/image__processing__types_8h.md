# image_processing_types.h


## Overview

The **image_processing_types.h** file declares the image processing types.

**Library**: libimage_processing.so

**File to include**: &lt;multimedia/video_processing_engine/image_processing_types.h&gt;

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Since**: 13

**Related module**: [ImageProcessing](_image_processing.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) | Describes the color space information, which is used in Color Space Conversion (CSC) capability query.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_ImageProcessing](_image_processing.md#oh_imageprocessing) [OH_ImageProcessing](_image_processing.md#oh_imageprocessing) | Provides the declaration of the **OH_ImageProcessing** struct.| 
| typedef struct [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) [OH_PixelmapNative](_image_processing.md#oh_pixelmapnative) | Provides the declaration of the **OH_PixelmapNative** struct.| 
| typedef struct [OH_AVFormat](_image_processing.md#oh_avformat) [OH_AVFormat](_image_processing.md#oh_avformat) | Provides the declaration of the **OH_AVFormat** struct.| 
| typedef struct [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) [ImageProcessing_ColorSpaceInfo](_image_processing.md#imageprocessing_colorspaceinfo) | Defines a struct for the color space information, which is used in CSC capability query.| 
| typedef enum [ImageDetailEnhancer_QualityLevel](_image_processing.md#imagedetailenhancer_qualitylevel-1) [ImageDetailEnhancer_QualityLevel](_image_processing.md#imagedetailenhancer_qualitylevel) | Defines an enum for the quality levels, which are used for detail enhancement.| 
| typedef enum [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode-1) [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode) | Defines an enum for the error codes used in image processing.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ImageDetailEnhancer_QualityLevel](_image_processing.md#imagedetailenhancer_qualitylevel-1) { <br>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_NONE,<br>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_LOW,<br>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM,<br>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH } | Enumerates the quality levels, which are used for detail enhancement.| 
| [ImageProcessing_ErrorCode](_image_processing.md#imageprocessing_errorcode-1) {<br>IMAGE_PROCESSING_SUCCESS,<br>IMAGE_PROCESSING_ERROR_INVALID_PARAMETER = 401,<br>IMAGE_PROCESSING_ERROR_UNKNOWN = 29200001,<br>IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED,<br>IMAGE_PROCESSING_ERROR_CREATE_FAILED,<br>IMAGE_PROCESSING_ERROR_PROCESS_FAILED,<br>IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,<br>IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,<br>IMAGE_PROCESSING_ERROR_NO_MEMORY,<br>IMAGE_PROCESSING_ERROR_INVALID_INSTANCE,<br>IMAGE_PROCESSING_ERROR_INVALID_VALUE<br>} | Enumerates the error codes used in image processing.| 


### Variables

| Name| Description| 
| -------- | -------- |
| const int32_t [IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](_image_processing.md#image_processing_type_color_space_conversion) | Used to create an image processing instance for CSC.| 
| const int32_t [IMAGE_PROCESSING_TYPE_COMPOSITION](_image_processing.md#image_processing_type_composition) | Used to create an image processing instance for converting a dual-layer HDR image into a single-layer HDR image.| 
| const int32_t [IMAGE_PROCESSING_TYPE_DECOMPOSITION](_image_processing.md#image_processing_type_decomposition) | Used to create an image processing instance for converting a single-layer HDR image into a dual-layer HDR image.| 
| const int32_t [IMAGE_PROCESSING_TYPE_METADATA_GENERATION](_image_processing.md#image_processing_type_metadata_generation) | Used to create an image processing instance for metadata generation.| 
| const int32_t [IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER](_image_processing.md#image_processing_type_detail_enhancer) | Used to create an image processing instance for detail enhancement.| 
| const char \* [IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](_image_processing.md#image_detail_enhancer_parameter_key_quality_level) | Used to set the quality level for image detail enhancement.| 
