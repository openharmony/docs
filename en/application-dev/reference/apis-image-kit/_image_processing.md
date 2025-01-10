# ImageProcessing


## Overview

The ImageProcessing module provides APIs for image processing, including Color Space Conversion (CSC) and metadata generation.

<!--RP1--><!--RP1End-->

**Since**: 13


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [image_processing.h](image__processing_8h.md) | Declares the image processing functions.| 
| [image_processing_types.h](image__processing__types_8h.md) | Declares the image processing types.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) | Describes the color space information, which is used in CSC capability query.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_ImageProcessing](#oh_imageprocessing) [OH_ImageProcessing](#oh_imageprocessing) | Provides the declaration of the **OH_ImageProcessing** struct.| 
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) [OH_PixelmapNative](#oh_pixelmapnative) | Provides the declaration of the **OH_PixelmapNative** struct.| 
| typedef struct [OH_AVFormat](#oh_avformat) [OH_AVFormat](#oh_avformat) | Provides the declaration of the **OH_AVFormat** struct.| 
| typedef struct [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) [ImageProcessing_ColorSpaceInfo](#imageprocessing_colorspaceinfo) | Defines a struct for the color space information, which is used in CSC capability query.| 
| typedef enum [ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel-1) [ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel) | Defines an enum for the quality levels, which are used for detail enhancement.| 
| typedef enum [ImageProcessing_ErrorCode](#imageprocessing_errorcode-1) [ImageProcessing_ErrorCode](#imageprocessing_errorcode) | Defines an enum for the error codes used in image processing.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel-1) { <br>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_NONE,<br>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_LOW,<br>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM,<br>IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH } | Enumerates the quality levels, which are used for detail enhancement.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode-1) {<br>IMAGE_PROCESSING_SUCCESS,<br>IMAGE_PROCESSING_ERROR_INVALID_PARAMETER = 401,<br>IMAGE_PROCESSING_ERROR_UNKNOWN = 29200001,<br>IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED,<br>IMAGE_PROCESSING_ERROR_CREATE_FAILED,<br>IMAGE_PROCESSING_ERROR_PROCESS_FAILED,<br>IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING,<br>IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED,<br>IMAGE_PROCESSING_ERROR_NO_MEMORY,<br>IMAGE_PROCESSING_ERROR_INVALID_INSTANCE,<br>IMAGE_PROCESSING_ERROR_INVALID_VALUE<br>} | Enumerates the error codes used in image processing.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment) (void) | Initializes the global environment of the image processing module.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_DeinitializeEnvironment](#oh_imageprocessing_deinitializeenvironment) (void) | Deinitializes the global environment of the image processing module.| 
| bool [OH_ImageProcessing_IsColorSpaceConversionSupported](#oh_imageprocessing_iscolorspaceconversionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo) | Checks whether CSC is supported for an image.| 
| bool [OH_ImageProcessing_IsCompositionSupported](#oh_imageprocessing_iscompositionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceGainmapInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo) | Checks whether a dual-layer HDR image can be converted into a single-layer HDR image.| 
| bool [OH_ImageProcessing_IsDecompositionSupported](#oh_imageprocessing_isdecompositionsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationImageInfo, const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*destinationGainmapInfo) | Checks whether a single-layer HDR image can be converted into a dual-layer HDR image.| 
| bool [OH_ImageProcessing_IsMetadataGenerationSupported](#oh_imageprocessing_ismetadatagenerationsupported) (const [ImageProcessing_ColorSpaceInfo](_image_processing___color_space_info.md) \*sourceImageInfo) | Checks whether metadata generation is supported for an image.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_Create](#oh_imageprocessing_create) ([OH_ImageProcessing](#oh_imageprocessing) \*\*imageProcessor, int32_t type) | Creates an image processing instance.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_Destroy](#oh_imageprocessing_destroy) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor) | Destroys an image processing instance.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_SetParameter](#oh_imageprocessing_setparameter) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, const [OH_AVFormat](#oh_avformat) \*parameter) | Sets a parameter for the image processing module.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_GetParameter](#oh_imageprocessing_getparameter) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_AVFormat](#oh_avformat) \*parameter) | Obtains a parameter of the image processing module.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_ConvertColorSpace](#oh_imageprocessing_convertcolorspace) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationImage) | Converts the color space for a single-layer image.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_Compose](#oh_imageprocessing_compose) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceGainmap, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationImage) | Converts a dual-layer HDR image into a single-layer HDR image.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_Decompose](#oh_imageprocessing_decompose) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationImage, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationGainmap) | Converts a single-layer HDR image into a double-layer HDR image.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_GenerateMetadata](#oh_imageprocessing_generatemetadata) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage) | Generates metadata for an HDR image.| 
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) [OH_ImageProcessing_EnhanceDetail](#oh_imageprocessing_enhancedetail) ([OH_ImageProcessing](#oh_imageprocessing) \*imageProcessor, [OH_PixelmapNative](#oh_pixelmapnative) \*sourceImage, [OH_PixelmapNative](#oh_pixelmapnative) \*destinationImage) | Enhances the image definition and details.| 


### Variables

| Name| Description| 
| -------- | -------- |
| const int32_t [IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](#image_processing_type_color_space_conversion) | Used to create an image processing instance for CSC.| 
| const int32_t [IMAGE_PROCESSING_TYPE_COMPOSITION](#image_processing_type_composition) | Used to create an image processing instance for converting a dual-layer HDR image into a single-layer HDR image.| 
| const int32_t [IMAGE_PROCESSING_TYPE_DECOMPOSITION](#image_processing_type_decomposition) | Used to create an image processing instance for converting a single-layer HDR image into a dual-layer HDR image.| 
| const int32_t [IMAGE_PROCESSING_TYPE_METADATA_GENERATION](#image_processing_type_metadata_generation) | Used to create an image processing instance for metadata generation.| 
| const int32_t [IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER](#image_processing_type_detail_enhancer) | Used to create an image processing instance for detail enhancement.| 
| const char \* [IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#image_detail_enhancer_parameter_key_quality_level) | Used to set the quality level for image detail enhancement.| 


## Type Description


### ImageDetailEnhancer_QualityLevel

```
typedef enum ImageDetailEnhancer_QualityLevel ImageDetailEnhancer_QualityLevel
```

**Description**

Defines an enum for the quality levels, which are used for detail enhancement.

Corresponding key: [IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#image_detail_enhancer_parameter_key_quality_level)

**Since**: 13

**See**

[OH_ImageProcessing_SetParameter](#oh_imageprocessing_setparameter)

[OH_ImageProcessing_GetParameter](#oh_imageprocessing_getparameter)


### ImageProcessing_ColorSpaceInfo

```
typedef struct ImageProcessing_ColorSpaceInfo ImageProcessing_ColorSpaceInfo
```

**Description**

Defines a struct for the color space information, which is used in CSC capability query.

**Since**: 13

**See**

[OH_ImageProcessing_IsColorSpaceConversionSupported](#oh_imageprocessing_iscolorspaceconversionsupported)

[OH_ImageProcessing_IsCompositionSupported](#oh_imageprocessing_iscompositionsupported)

[OH_ImageProcessing_IsDecompositionSupported](#oh_imageprocessing_isdecompositionsupported)


### ImageProcessing_ErrorCode

```
typedef enum ImageProcessing_ErrorCode ImageProcessing_ErrorCode
```

**Description**

Defines an enum for the error codes used in image processing.

**Since**: 13


### OH_AVFormat

```
typedef struct OH_AVFormat OH_AVFormat
```

**Description**

Provides the declaration of the **OH_AVFormat** struct.

**Since**: 13


### OH_ImageProcessing

```
typedef struct OH_ImageProcessing OH_ImageProcessing
```

**Description**

Provides the declaration of the **OH_ImageProcessing** struct.

Define a null pointer to **OH_ImageProcessing**. Before [OH_ImageProcessing_Create](#oh_imageprocessing_create) is called to create an image processing instance, the pointer must be null. You can create different image processing instances with different processing types.

**Since**: 13


### OH_PixelmapNative

```
typedef struct OH_PixelmapNative OH_PixelmapNative
```

**Description**

Provides the declaration of the **OH_PixelmapNative** struct.

**Since**: 13


## Enum Description


### ImageDetailEnhancer_QualityLevel

```
enum ImageDetailEnhancer_QualityLevel
```

**Description**

Enumerates the quality levels, which are used for detail enhancement.

Corresponding key: [IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL](#image_detail_enhancer_parameter_key_quality_level)

**Since**: 13

**See**

[OH_ImageProcessing_SetParameter](#oh_imageprocessing_setparameter)

[OH_ImageProcessing_GetParameter](#oh_imageprocessing_getparameter)

| Value| Description| 
| -------- | -------- |
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_NONE | No detail enhancement.| 
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_LOW | Low-quality detail enhancement, which features fast speed. This is the default value.| 
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM | Medium-quality detail enhancement, which features moderate speed.| 
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH | High-quality detail enhancement, which features slow speed.| 


### ImageProcessing_ErrorCode

```
enum ImageProcessing_ErrorCode
```

**Description**

Enumerates the error codes used in image processing.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| IMAGE_PROCESSING_SUCCESS | The processing is successful.| 
| IMAGE_PROCESSING_ERROR_INVALID_PARAMETER | An input parameter is invalid.<br>This error code is returned in the following cases:<br>1 - The input or output buffer is either invalid or empty.<br>2 - The provided parameter is invalid or missing.<br>3 - The type is invalid. For example, the type passed in the creation function does not exist.| 
| IMAGE_PROCESSING_ERROR_UNKNOWN | An unknown error occurs. For example, the GPU computing or memcpy fails.| 
| IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED | The global environment, for example, the GPU environment, fails to be initialized.| 
| IMAGE_PROCESSING_ERROR_CREATE_FAILED | Creating the image processing instance fails. For example, the total number of instances exceeds the upper limit.| 
| IMAGE_PROCESSING_ERROR_PROCESS_FAILED | The processing fails. For example, the processing times out.| 
| IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING | The processing type is not supported. You can call OH_ImageProcessing_Is*XXX*Supported to check whether a specific processing type is supported.| 
| IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED | The operation is not allowed. For example, the function is called in an incorrect running state.| 
| IMAGE_PROCESSING_ERROR_NO_MEMORY | Insufficient memory.| 
| IMAGE_PROCESSING_ERROR_INVALID_INSTANCE | The image processing instance is invalid, for example, a null instance.| 
| IMAGE_PROCESSING_ERROR_INVALID_VALUE | The input value is invalid.<br>This error code is returned in the following cases:<br>1 - The input or output image buffer is invalid. For example, the width (height) of the image buffer is too large or the color space is incorrect.<br>2 - The parameter is invalid. For example, the parameter does not contain valid information, such as invalid quality level for detail enhancement.| 


## Function Description


### OH_ImageProcessing_Compose()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Compose(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* sourceGainmap, OH_PixelmapNative* destinationImage)
```

**Description**

Converts a dual-layer HDR image into a single-layer HDR image.

This function is used to generate an output image based on an input image and input gain map.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor | Pointer to an image processing instance, which is created by [IMAGE_PROCESSING_TYPE_COMPOSITION](#image_processing_type_composition).| 
| sourceImage | Pointer to the input image.| 
| sourceGainmap | Pointer to the input gain map.| 
| destinationImage | Pointer to the output image.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if image processing is successful.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not an image processing instance.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER** if the image is empty.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_VALUE** if an image property is invalid, for example, unsupported color space.
- Returns **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** if image processing is not supported.
- Returns **IMAGE_PROCESSING_ERROR_PROCESS_FAILED** if an error occurs during image processing.
- Returns **IMAGE_PROCESSING_ERROR_NO_MEMORY** if memory allocation fails.


### OH_ImageProcessing_ConvertColorSpace()

```
ImageProcessing_ErrorCode OH_ImageProcessing_ConvertColorSpace(OH_ImageProcessing* imageProcessor, OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage)
```

**Description**

Converts the color space for a single-layer image.

This function enables CSC from HDR images to SDR images, CSC from SDR images to HDR images, CSC from SDR images to SDR images, and CSC from HDR images to SDR images.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor | Pointer to an image processing instance, which is created by [IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION](#image_processing_type_color_space_conversion).| 
| sourceImage | Pointer to the input image.| 
| destinationImage | Pointer to the output image.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if image processing is successful.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not an image processing instance.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER** if the image is empty.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_VALUE** if an image property is invalid, for example, unsupported color space.
- Returns **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** if image processing is not supported.
- Returns **IMAGE_PROCESSING_ERROR_PROCESS_FAILED** if an error occurs during image processing.
- Returns **IMAGE_PROCESSING_ERROR_NO_MEMORY** if memory allocation fails.


### OH_ImageProcessing_Create()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Create(OH_ImageProcessing** imageProcessor, int32_t type)
```

**Description**

Creates an image processing instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor |  Double pointer to the image processing instance created. The pointer **\*imageProcessor** points to a new image processing object and must be a null pointer before being passed.| 
| type | Image processing type. The processing type cannot be changed after the instance is created.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if the instance is created successfully.
- Returns **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** if the specified image processing type is not supported, for example, if metadata generation is not supported.
- Returns **IMAGE_PROCESSING_ERROR_CREATE_FAILED** if the instance fails to be created.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or the pointer to the instance is null.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER** if the specified image processing type is invalid.


### OH_ImageProcessing_Decompose()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Decompose(OH_ImageProcessing* imageProcessor, OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage, OH_PixelmapNative* destinationGainmap)
```

**Description**

Converts a single-layer HDR image into a double-layer HDR image.

This function is used to generate an output image and output gain map based on an input image.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor | Pointer to an image processing instance, which is created by [IMAGE_PROCESSING_TYPE_DECOMPOSITION](#image_processing_type_decomposition).| 
| sourceImage | Pointer to the input image.| 
| destinationImage | Pointer to the output image.| 
| destinationGainmap | Pointer to the output gain map.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if image processing is successful.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not an image processing instance.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER** if the image is empty.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_VALUE** if an image property is invalid, for example, unsupported color space.
- Returns **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** if image processing is not supported.
- Returns **IMAGE_PROCESSING_ERROR_PROCESS_FAILED** if an error occurs during image processing.
- Returns **IMAGE_PROCESSING_ERROR_NO_MEMORY** if memory allocation fails.


### OH_ImageProcessing_DeinitializeEnvironment()

```
ImageProcessing_ErrorCode OH_ImageProcessing_DeinitializeEnvironment(void)
```

**Description**

Deinitializes the global environment of the image processing module.

This function must be called after [OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment) is called. Generally, this function is called when the main process is about to exit. Do not call this function when an image processing instance exists or when [OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment) is not called.

**Since**: 13

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if deinitialization is successful.
- Returns **IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED** if the image processing instance is not destroyed or [OH_ImageProcessing_InitializeEnvironment](#oh_imageprocessing_initializeenvironment) is not called.


### OH_ImageProcessing_Destroy()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Destroy(OH_ImageProcessing* imageProcessor)
```

**Description**

Destroys an image processing instance.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor | Pointer to an image processing instance, You are advised to set the pointer to a null pointer after the instance is destroyed.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if the instance is destroyed.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not an image processing instance.


### OH_ImageProcessing_EnhanceDetail()

```
ImageProcessing_ErrorCode OH_ImageProcessing_EnhanceDetail(OH_ImageProcessing* imageProcessor, OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage)
```

**Description**

Enhances the image definition and details.

This function performs necessary scaling operations on the source image based on the preset sizes of the input and output images to generate the target image. It uses multiple scaling methods to balance performance and image quality.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor | Pointer to an image processing instance, which is created by [IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER](#image_processing_type_detail_enhancer).| 
| sourceImage | Pointer to the input image.| 
| destinationImage | Pointer to the output image.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if image processing is successful.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not an image processing instance.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER** if the image is empty.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_VALUE** if an image property is invalid, for example, unsupported color space.
- Returns **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** if image processing is not supported.
- Returns **IMAGE_PROCESSING_ERROR_PROCESS_FAILED** if an error occurs during image processing.
- Returns **IMAGE_PROCESSING_ERROR_NO_MEMORY** if memory allocation fails.


### OH_ImageProcessing_GenerateMetadata()

```
ImageProcessing_ErrorCode OH_ImageProcessing_GenerateMetadata(OH_ImageProcessing* imageProcessor, OH_PixelmapNative* sourceImage)
```

**Description**

Generates metadata for an HDR image.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor | Pointer to an image processing instance, which is created by [IMAGE_PROCESSING_TYPE_METADATA_GENERATION](#image_processing_type_metadata_generation).| 
| sourceImage | Pointer to the input image.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if image processing is successful.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not an image processing instance.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER** if the image is empty.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_VALUE** if an image property is invalid, for example, unsupported color space.
- Returns **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING** if image processing is not supported.
- Returns **IMAGE_PROCESSING_ERROR_PROCESS_FAILED** if an error occurs during image processing.
- Returns **IMAGE_PROCESSING_ERROR_NO_MEMORY** if memory allocation fails.


### OH_ImageProcessing_GetParameter()

```
ImageProcessing_ErrorCode OH_ImageProcessing_GetParameter(OH_ImageProcessing* imageProcessor, OH_AVFormat* parameter)
```

**Description**

Obtains a parameter of the image processing module.

This function obtains the parameter by key.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor | Pointer to an image processing instance.| 
| parameter | Pointer to the parameter used by the image processing instance.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if the parameters fail to be obtained.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not an image processing instance.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER** if **parameter** is empty.


### OH_ImageProcessing_InitializeEnvironment()

```
ImageProcessing_ErrorCode OH_ImageProcessing_InitializeEnvironment(void)
```

**Description**

Initializes the global environment of the image processing module.

This function is optional. Generally, this function is called when the main process is started. It is used to initialize the global environment of the image processing module and reduce the time consumed by [OH_ImageProcessing_Create](#oh_imageprocessing_create). It must be used in pair with [OH_ImageProcessing_DeinitializeEnvironment](#oh_imageprocessing_deinitializeenvironment), which is used to deinitialize the global environment. This function can be used to check whether the GPU works properly.

**Since**: 13

**Returns**

Returns **IMAGE_PROCESSING_SUCCESS** if the initialization is successful; returns **IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED** otherwise.


### OH_ImageProcessing_IsColorSpaceConversionSupported()

```
bool OH_ImageProcessing_IsColorSpaceConversionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo, const ImageProcessing_ColorSpaceInfo* destinationImageInfo)
```

**Description**

Checks whether CSC is supported for an image.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| sourceImageInfo | Pointer to the color space information of the input image.| 
| destinationImageInfo | Pointer to the color space information of the output image.| 

**Returns**

Returns **true** if CSC is supported; returns **false** otherwise.


### OH_ImageProcessing_IsCompositionSupported()

```
bool OH_ImageProcessing_IsCompositionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo, const ImageProcessing_ColorSpaceInfo* sourceGainmapInfo, const ImageProcessing_ColorSpaceInfo* destinationImageInfo)
```

**Description**

Checks whether a dual-layer HDR image can be converted into a single-layer HDR image.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| sourceImageInfo | Pointer to the color space information of the input image.| 
| sourceGainmapInfo | Pointer to the color space information of the input gain map.| 
| destinationImageInfo | Pointer to the color space information of the output image.| 

**Returns**

Returns **true** if such a conversion is supported; returns **false** otherwise.


### OH_ImageProcessing_IsDecompositionSupported()

```
bool OH_ImageProcessing_IsDecompositionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo, const ImageProcessing_ColorSpaceInfo* destinationImageInfo, const ImageProcessing_ColorSpaceInfo* destinationGainmapInfo)
```

**Description**

Checks whether a single-layer HDR image can be converted into a dual-layer HDR image.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| sourceImageInfo | Pointer to the color space information of the input image.| 
| destinationImageInfo | Pointer to the color space information of the output image.| 
| destinationGainmapInfo | Pointer to the color space information of the output gain map.| 

**Returns**

Returns **true** if such a conversion is supported; returns **false** otherwise.


### OH_ImageProcessing_IsMetadataGenerationSupported()

```
bool OH_ImageProcessing_IsMetadataGenerationSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo)
```

**Description**

Checks whether metadata generation is supported for an image.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| sourceImageInfo | Pointer to the color space information of the input image.| 

**Returns**

Returns **true** if metadata generation is supported; returns **false** otherwise.


### OH_ImageProcessing_SetParameter()

```
ImageProcessing_ErrorCode OH_ImageProcessing_SetParameter(OH_ImageProcessing* imageProcessor, const OH_AVFormat* parameter)
```

**Description**

Sets a parameter for the image processing module.

This function sets the parameter by key.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageProcessor | Pointer to an image processing instance.| 
| parameter | Pointer to the parameter.| 

**Returns**

- Returns **IMAGE_PROCESSING_SUCCESS** if the parameter is set successfully.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE** if the instance is null or is not an image processing instance.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER** if **parameter** is empty.
- Returns **IMAGE_PROCESSING_ERROR_INVALID_VALUE** if **parameter** is invalid, for example, if **parameter** contains an unsupported parameter key or value.
- Returns **IMAGE_PROCESSING_ERROR_NO_MEMORY** if memory allocation fails.


## Variable Description


### IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL

```
const char* IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL
```

**Description**

Used to set the quality level for image detail enhancement.

Use [ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel) to obtain the quality level. Use [OH_ImageProcessing_SetParameter](#oh_imageprocessing_setparameter) to set the quality level. Use [OH_ImageProcessing_GetParameter](#oh_imageprocessing_getparameter) to obtain the quality level in use.

**Since**: 13

**See**

[OH_VideoProcessing_SetParameter](../apis-media-kit/_video_processing.md#oh_videoprocessing_setparameter)

[OH_VideoProcessing_GetParameter](../apis-media-kit/_video_processing.md#oh_videoprocessing_getparameter)


### IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION

```
const int32_t IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION
```

**Description**

Used to create an image processing instance for CSC.

CSC includes conversion from single-layer HDR images to SDR images, conversion between SDR images, and conversion from SDR images to single-layer HDR images. Some capabilities are supported by vendors. Use **OH_ImageProcessing_IsColorSpaceConversionSuported** to check whether a conversion can be performed between single-layer images.

**Since**: 13

**See**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)


### IMAGE_PROCESSING_TYPE_COMPOSITION

```
const int32_t IMAGE_PROCESSING_TYPE_COMPOSITION
```

**Description**

Used to create an image processing instance for converting a dual-layer HDR image into a single-layer HDR image.

The instance provides the capability of converting dual-layer HDR images into single-layer HDR images. Some capabilities are supported by vendors. Use [OH_ImageProcessing_IsCompositionSupported](#oh_imageprocessing_iscompositionsupported) to check whether the conversion from a dual-layer HDR image into a single-layer HDR image is supported.

**Since**: 13

**See**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)


### IMAGE_PROCESSING_TYPE_DECOMPOSITION

```
const int32_t IMAGE_PROCESSING_TYPE_DECOMPOSITION
```

**Description**

Used to create an image processing instance for converting a single-layer HDR image into a dual-layer HDR image.

The instance provides the capability of converting single-layer HDR images into dual-layer HDR images. Some capabilities are supported by vendors. Use [OH_ImageProcessing_IsDecompositionSupported](#oh_imageprocessing_isdecompositionsupported) to check whether the conversion from a single-layer HDR image into a dual-layer HDR image is supported.

**Since**: 13

**See**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)


### IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER

```
const int32_t IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER
```

**Description**

Used to create an image processing instance for detail enhancement.

This variable scales or resizes the image based on the specified image quality, or only enhances the image details to render the image without changing the resolution.

**Since**: 13

**See**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)


### IMAGE_PROCESSING_TYPE_METADATA_GENERATION

```
const int32_t IMAGE_PROCESSING_TYPE_METADATA_GENERATION
```

**Description**

Used to create an image processing instance for metadata generation.

This variable generates the HDR Vivid metadata of a single-layer HDR image. Some capabilities are supported by vendors. If the capability is not supported, [OH_ImageProcessing_Create](#oh_imageprocessing_create) returns **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**.

**Since**: 13

**See**

[OH_ImageProcessing_Create](#oh_imageprocessing_create)
