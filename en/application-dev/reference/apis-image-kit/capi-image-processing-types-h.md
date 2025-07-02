# image_processing_types.h

## Overview

The **image_processing_types.h** file declares the image processing types.

**Library**: libimage_processing.so

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Since**: 13

**Related module**: [ImageProcessing](capi-imageprocessing.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md) | ImageProcessing_ColorSpaceInfo | Describes the color space information, which is used in Color Space Conversion (CSC) capability query.|
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md) | OH_ImageProcessing | Provides the declaration of the OH_ImageProcessing struct.<br>To use it, first declare a null pointer of OH_ImageProcessing, and then initialize it by calling [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create). This function creates an image processing instance. Multiple instances can be created for different image processing tasks.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) | OH_PixelmapNative | Provides the declaration of the OH_PixelmapNative struct.|
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat) | OH_AVFormat | Provides the declaration of the OH_AVFormat struct.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ImageDetailEnhancer_QualityLevel](#imagedetailenhancer_qualitylevel) | ImageDetailEnhancer_QualityLevel | Enumerates the quality levels, which are used for detail enhancement.<br>Corresponding key: IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL.|
| [ImageProcessing_ErrorCode](#imageprocessing_errorcode) | ImageProcessing_ErrorCode | Enumerates the error codes used in image processing.|

### Variables

| Name| Description|
| -- | -- |
| const int32_t IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION | Used to create an image processing instance for CSC.<br>CSC includes conversion from single-layer HDR images to SDR images, conversion between SDR images, and conversion from SDR images to single-layer HDR images. Some capabilities are supported by vendors. Use [OH_ImageProcessing_IsColorSpaceConversionSuported](capi-image-processing-h.md#oh_imageprocessing_iscolorspaceconversionsupported) to check whether a conversion can be performed between single-layer images.<br>**Since**: 13<br>**Reference**: [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create)|
| const int32_t IMAGE_PROCESSING_TYPE_COMPOSITION | Used to create an image processing instance for converting a dual-layer HDR image into a single-layer HDR image.<br>The instance provides the capability of converting dual-layer HDR images into single-layer HDR images. Some capabilities are supported by vendors. Use [OH_ImageProcessing_IsCompositionSupported](capi-image-processing-h.md#oh_imageprocessing_iscompositionsupported) to check whether the conversion from a dual-layer HDR image into a single-layer HDR image is supported.<br>**Since**: 13<br>**Reference**: [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create)|
| const int32_t IMAGE_PROCESSING_TYPE_DECOMPOSITION | Used to create an image processing instance for converting a single-layer HDR image into a dual-layer HDR image.<br>The instance provides the capability of converting single-layer HDR images into dual-layer HDR images. Some capabilities are supported by vendors. Use [OH_ImageProcessing_IsDecompositionSupported](capi-image-processing-h.md#oh_imageprocessing_isdecompositionsupported) to check whether the conversion from a single-layer HDR image into a dual-layer HDR image is supported.<br>**Since**: 13<br>**Reference**: [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create)|
| const int32_t IMAGE_PROCESSING_TYPE_METADATA_GENERATION | Used to create an image processing instance for metadata generation.<br>This variable generates the HDR Vivid metadata of a single-layer HDR image. Some capabilities are supported by vendors. If the capability is not supported, [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create) returns [IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING](capi-image-processing-types-h.md#imageprocessing_errorcode).<br>**Since**: 13<br>**Reference**: [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create)|
| const int32_t IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER | Used to create an image processing instance for detail enhancement.<br>This variable scales or resizes the image based on the specified image quality, or only enhances the image details to render the image without changing the resolution.<br>**Since**: 13<br>**Reference**: [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create)|
| const char * IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL | Used to set the quality level for image detail enhancement.<br>Use [ImageDetailEnhancer_QualityLevel](capi-image-processing-types-h.md#imagedetailenhancer_qualitylevel) to obtain the quality level. Use [OH_ImageProcessing_SetParameter](capi-image-processing-h.md#oh_imageprocessing_setparameter) to set the quality level. Use [OH_ImageProcessing_GetParameter](capi-image-processing-h.md#oh_imageprocessing_getparameter) to obtain the quality level in use.<br>**Since**: 13|

## Enum Description

### ImageDetailEnhancer_QualityLevel

```
enum ImageDetailEnhancer_QualityLevel
```

**Description**

Enumerates the quality levels, which are used for detail enhancement.

Corresponding key: IMAGE_DETAIL_ENHANCER_PARAMETER_KEY_QUALITY_LEVEL.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_NONE | No detail enhancement.|
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_LOW | Low-quality detail enhancement, which features fast speed. This is the default value.|
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_MEDIUM | Medium-quality detail enhancement, which features moderate speed.|
| IMAGE_DETAIL_ENHANCER_QUALITY_LEVEL_HIGH | High-quality detail enhancement, which features slow speed.|

**See also**

[OH_ImageProcessing_SetParameter](capi-image-processing-h.md#oh_imageprocessing_setparameter), [OH_ImageProcessing_GetParameter](capi-image-processing-h.md#oh_imageprocessing_getparameter)

### ImageProcessing_ErrorCode

```
enum ImageProcessing_ErrorCode
```

**Description**

Enumerates the error codes used in image processing.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| IMAGE_PROCESSING_SUCCESS | The operation is successful.|
| IMAGE_PROCESSING_ERROR_INVALID_PARAMETER = 401 | An input parameter is invalid.<br>This error code is returned in the following cases:<br>1. The input or output buffer is either invalid or empty.<br>2. The provided parameter is invalid or missing.<br>3. The type is invalid. For example, the type passed in the creation function does not exist.|
| IMAGE_PROCESSING_ERROR_UNKNOWN = 29200001 | An unknown error occurs. For example, the GPU computing or memcpy fails.|
| IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED | The global environment, for example, the GPU environment, fails to be initialized.|
| IMAGE_PROCESSING_ERROR_CREATE_FAILED | Creating the image processing instance fails. For example, the total number of instances exceeds the upper limit.|
| IMAGE_PROCESSING_ERROR_PROCESS_FAILED | The processing fails. For example, the processing times out.|
| IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING | The processing type is not supported. You can call OH_ImageProcessing_Is*XXX*Supported to check whether a specific processing type is supported.|
| IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED | The operation is not allowed. For example, the function is called in an incorrect running state.|
| IMAGE_PROCESSING_ERROR_NO_MEMORY | Insufficient memory.|
| IMAGE_PROCESSING_ERROR_INVALID_INSTANCE | The image processing instance is invalid, for example, a null instance.|
| IMAGE_PROCESSING_ERROR_INVALID_VALUE | The input value is invalid.<br>This error code is returned in the following cases:<br>1. The input or output image buffer is invalid. For example, the width (height) of the image buffer is too large or the color space is incorrect.<br>2. The parameter is invalid. For example, the parameter does not contain valid information, such as invalid quality level for detail enhancement.|
