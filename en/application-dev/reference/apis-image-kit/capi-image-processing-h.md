# image_processing.h

## Overview

The **image_processing.h** file declares the image processing functions. It provides capabilities such as Color Space Conversion (CSC), metadata generation, and image scaling.

**Library**: libimage_processing.so

**System capability**: SystemCapability.Multimedia.VideoProcessingEngine

**Since**: 13

**Related module**: [ImageProcessing](capi-imageprocessing.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [ImageProcessing_ErrorCode OH_ImageProcessing_InitializeEnvironment(void)](#oh_imageprocessing_initializeenvironment) | Initializes the global environment of the image processing module.<br>This function is optional. Generally, this function is called when the main process is started. It is used to initialize the global environment of the image processing module and reduce the time consumed by [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create). It must be used in pair with [OH_ImageProcessing_DeinitializeEnvironment](capi-image-processing-h.md#oh_imageprocessing_deinitializeenvironment), which is used to deinitialize the global environment. This function can be used to check whether the GPU works properly.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_DeinitializeEnvironment(void)](#oh_imageprocessing_deinitializeenvironment) | Deinitializes the global environment of the image processing module.<br>This function must be called after [OH_ImageProcessing_InitializeEnvironment](capi-image-processing-h.md#oh_imageprocessing_initializeenvironment) is called. Generally, this function is called when the main process is about to exit. Do not call this function when an image processing instance exists or when [OH_ImageProcessing_InitializeEnvironment](capi-image-processing-h.md#oh_imageprocessing_initializeenvironment) is not called.|
| [bool OH_ImageProcessing_IsColorSpaceConversionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo,const ImageProcessing_ColorSpaceInfo* destinationImageInfo)](#oh_imageprocessing_iscolorspaceconversionsupported) | Checks whether CSC is supported for an image.|
| [bool OH_ImageProcessing_IsCompositionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo,const ImageProcessing_ColorSpaceInfo* sourceGainmapInfo,const ImageProcessing_ColorSpaceInfo* destinationImageInfo)](#oh_imageprocessing_iscompositionsupported) | Checks whether a dual-layer HDR image can be converted into a single-layer HDR image.|
| [bool OH_ImageProcessing_IsDecompositionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo,const ImageProcessing_ColorSpaceInfo* destinationImageInfo,const ImageProcessing_ColorSpaceInfo* destinationGainmapInfo)](#oh_imageprocessing_isdecompositionsupported) | Checks whether a single-layer HDR image can be converted into a dual-layer HDR image.|
| [bool OH_ImageProcessing_IsMetadataGenerationSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo)](#oh_imageprocessing_ismetadatagenerationsupported) | Checks whether metadata generation is supported for an image.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_Create(OH_ImageProcessing** imageProcessor, int32_t type)](#oh_imageprocessing_create) | Creates an image processing instance.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_Destroy(OH_ImageProcessing* imageProcessor)](#oh_imageprocessing_destroy) | Destroys an image processing instance.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_SetParameter(OH_ImageProcessing* imageProcessor,const OH_AVFormat* parameter)](#oh_imageprocessing_setparameter) | Sets a parameter for the image processing module. This function sets the parameter by key.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_GetParameter(OH_ImageProcessing* imageProcessor,OH_AVFormat* parameter)](#oh_imageprocessing_getparameter) | Obtains a parameter of the image processing module. This function obtains the parameter by key.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_ConvertColorSpace(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage)](#oh_imageprocessing_convertcolorspace) | Converts the color space for a single-layer image. This function enables CSC from HDR images to SDR images, CSC from SDR images to HDR images, CSC from SDR images to SDR images, and CSC from HDR images to SDR images.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_Compose(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* sourceGainmap, OH_PixelmapNative* destinationImage)](#oh_imageprocessing_compose) | Converts a dual-layer HDR image into a single-layer HDR image. This function is used to generate an output image based on an input image and input gain map.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_Decompose(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage, OH_PixelmapNative* destinationGainmap)](#oh_imageprocessing_decompose) | Converts a single-layer HDR image into a double-layer HDR image. This function is used to generate an output image and output gain map based on an input image.|
| [ImageProcessing_ErrorCode OH_ImageProcessing_GenerateMetadata(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage)](#oh_imageprocessing_generatemetadata) | Generates metadata for an HDR image.  |
| [ImageProcessing_ErrorCode OH_ImageProcessing_EnhanceDetail(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage)](#oh_imageprocessing_enhancedetail) | Enhances the image definition and details. This function performs necessary scaling operations on the source image based on the preset sizes of the input and output images to generate the target image. It uses multiple scaling methods to balance performance and image quality.|

## Function Description

### OH_ImageProcessing_InitializeEnvironment()

```
ImageProcessing_ErrorCode OH_ImageProcessing_InitializeEnvironment(void)
```

**Description**

Initializes the global environment of the image processing module.

This function is optional. Generally, this function is called when the main process is started. It is used to initialize the global environment of the image processing module and reduce the time consumed by [OH_ImageProcessing_Create](capi-image-processing-h.md#oh_imageprocessing_create). It must be used in pair with [OH_ImageProcessing_DeinitializeEnvironment](capi-image-processing-h.md#oh_imageprocessing_deinitializeenvironment), which is used to deinitialize the global environment. This function can be used to check whether the GPU works properly.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: The initialization is successful.<br>**IMAGE_PROCESSING_ERROR_INITIALIZE_FAILED**: The initialization fails.|

### OH_ImageProcessing_DeinitializeEnvironment()

```
ImageProcessing_ErrorCode OH_ImageProcessing_DeinitializeEnvironment(void)
```

**Description**

Deinitializes the global environment of the image processing module.

This function must be called after [OH_ImageProcessing_InitializeEnvironment](capi-image-processing-h.md#oh_imageprocessing_initializeenvironment) is called. Generally, this function is called when the main process is about to exit. Do not call this function when an image processing instance exists or when [OH_ImageProcessing_InitializeEnvironment](capi-image-processing-h.md#oh_imageprocessing_initializeenvironment) is not called.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: Deinitialization is successful.<br> **IMAGE_PROCESSING_ERROR_OPERATION_NOT_PERMITTED**: The image processing instance is not destroyed or [OH_ImageProcessing_InitializeEnvironment](capi-image-processing-h.md#oh_imageprocessing_initializeenvironment) is not called.|

### OH_ImageProcessing_IsColorSpaceConversionSupported()

```
bool OH_ImageProcessing_IsColorSpaceConversionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo,const ImageProcessing_ColorSpaceInfo* destinationImageInfo)
```

**Description**

Checks whether CSC is supported for an image.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* sourceImageInfo | Pointer to the color space information of the input image.|
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* destinationImageInfo | Pointer to the color space information of the output image.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** is returned if CSC is supported.<br> **false** is returned otherwise.|

### OH_ImageProcessing_IsCompositionSupported()

```
bool OH_ImageProcessing_IsCompositionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo,const ImageProcessing_ColorSpaceInfo* sourceGainmapInfo,const ImageProcessing_ColorSpaceInfo* destinationImageInfo)
```

**Description**

Checks whether a dual-layer HDR image can be converted into a single-layer HDR image.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* sourceImageInfo | Pointer to the color space information of the input image.|
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* sourceGainmapInfo | Pointer to the color space information of the input gain map.|
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* destinationImageInfo | Pointer to the color space information of the output image.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** is returned if such a conversion is supported.<br> **false** is returned otherwise.|

### OH_ImageProcessing_IsDecompositionSupported()

```
bool OH_ImageProcessing_IsDecompositionSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo,const ImageProcessing_ColorSpaceInfo* destinationImageInfo,const ImageProcessing_ColorSpaceInfo* destinationGainmapInfo)
```

**Description**

Checks whether a single-layer HDR image can be converted into a dual-layer HDR image.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* sourceImageInfo | Pointer to the color space information of the input image.|
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* destinationImageInfo | Pointer to the color space information of the output image.|
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* destinationGainmapInfo | Pointer to the color space information of the output gain map.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** is returned if such a conversion is supported.<br> **false** is returned otherwise.|

### OH_ImageProcessing_IsMetadataGenerationSupported()

```
bool OH_ImageProcessing_IsMetadataGenerationSupported(const ImageProcessing_ColorSpaceInfo* sourceImageInfo)
```

**Description**

Checks whether metadata generation is supported for an image.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| const [ImageProcessing_ColorSpaceInfo](capi-imageprocessing-imageprocessing-colorspaceinfo.md)* sourceImageInfo | Pointer to the color space information of the input image.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** is returned if metadata generation is supported.<br> **false** is returned otherwise.|

### OH_ImageProcessing_Create()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Create(OH_ImageProcessing** imageProcessor, int32_t type)
```

**Description**

Creates an image processing instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)** imageProcessor | Double pointer to the image processing instance created. The pointer **\*imageProcessor** points to a new image processing object and must be a null pointer before being passed.|
| int32_t type | Image processing type. The processing type cannot be changed after the instance is created.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: The instance is created successfully.<br> **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: The specified image processing type is not supported, for example, if metadata generation is not supported.<br> **IMAGE_PROCESSING_ERROR_CREATE_FAILED**: The instance fails to be created.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or the pointer to the instance is null.<br> **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER**: The specified image processing type is invalid.|

### OH_ImageProcessing_Destroy()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Destroy(OH_ImageProcessing* imageProcessor)
```

**Description**

Destroys an image processing instance.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)* imageProcessor | Pointer to an image processing instance. You are advised to set the pointer to a null pointer after the instance is destroyed.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: The instance is destroyed.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not an image processing instance.|

### OH_ImageProcessing_SetParameter()

```
ImageProcessing_ErrorCode OH_ImageProcessing_SetParameter(OH_ImageProcessing* imageProcessor,const OH_AVFormat* parameter)
```

**Description**

Sets a parameter for the image processing module. This function sets the parameter by key.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)* imageProcessor | Pointer to an image processing instance.|
| const [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* parameter | Pointer to the parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: The operation is successful.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not an image processing instance.<br> **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER**: **parameter** is empty.<br> **IMAGE_PROCESSING_ERROR_INVALID_VALUE**: **parameter** is invalid, for example, if **parameter** contains an unsupported parameter key or value.<br> **IMAGE_PROCESSING_ERROR_NO_MEMORY**: Memory allocation fails.|

### OH_ImageProcessing_GetParameter()

```
ImageProcessing_ErrorCode OH_ImageProcessing_GetParameter(OH_ImageProcessing* imageProcessor,OH_AVFormat* parameter)
```

**Description**

Obtains a parameter of the image processing module. This function obtains the parameter by key.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)* imageProcessor | Pointer to an image processing instance.|
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* parameter | Pointer to the parameter.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: The operation is successful.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not an image processing instance.<br> **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER**: **parameter** is empty.|

### OH_ImageProcessing_ConvertColorSpace()

```
ImageProcessing_ErrorCode OH_ImageProcessing_ConvertColorSpace(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage)
```

**Description**

Converts the color space for a single-layer image. This function enables CSC from HDR images to SDR images, CSC from SDR images to HDR images, CSC from SDR images to SDR images, and CSC from HDR images to SDR images.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)* imageProcessor | Pointer to an image processing instance, which is created by **IMAGE_PROCESSING_TYPE_COLOR_SPACE_CONVERSION**.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* sourceImage | Pointer to the input image.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* destinationImage | Pointer to the output image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: Image processing is successful.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not an image processing instance.<br> **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER**: The image is empty.<br> **IMAGE_PROCESSING_ERROR_INVALID_VALUE**: An image property is invalid, for example, unsupported color space.<br> **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: Image processing is not supported.<br> **IMAGE_PROCESSING_ERROR_PROCESS_FAILED**: An error occurs during image processing.<br> **IMAGE_PROCESSING_ERROR_NO_MEMORY**: Memory allocation fails.|

### OH_ImageProcessing_Compose()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Compose(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* sourceGainmap, OH_PixelmapNative* destinationImage)
```

**Description**

Converts a dual-layer HDR image into a single-layer HDR image. This function is used to generate an output image based on an input image and input gain map.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)* imageProcessor | Pointer to an image processing instance, which is created by **IMAGE_PROCESSING_TYPE_COMPOSITION**.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* sourceImage | Pointer to the input image.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* sourceGainmap | Pointer to the input gain map.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* destinationImage | Pointer to the output image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: Image processing is successful.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not an image processing instance.<br> **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER**: The image is empty.<br> **IMAGE_PROCESSING_ERROR_INVALID_VALUE**: An image property is invalid, for example, unsupported color space.<br> **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: Image processing is not supported.<br> **IMAGE_PROCESSING_ERROR_PROCESS_FAILED**: An error occurs during image processing.<br> **IMAGE_PROCESSING_ERROR_NO_MEMORY**: Memory allocation fails.|

### OH_ImageProcessing_Decompose()

```
ImageProcessing_ErrorCode OH_ImageProcessing_Decompose(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage, OH_PixelmapNative* destinationGainmap)
```

**Description**

Converts a single-layer HDR image into a double-layer HDR image. This function is used to generate an output image and output gain map based on an input image.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)* imageProcessor | Pointer to an image processing instance, which is created by **IMAGE_PROCESSING_TYPE_DECOMPOSITION**.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* sourceImage | Pointer to the input image.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* destinationImage | Pointer to the output image.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* destinationGainmap | Pointer to the output gain map.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: Image processing is successful.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not an image processing instance.<br> **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER**: The image is empty.<br> **IMAGE_PROCESSING_ERROR_INVALID_VALUE**: An image property is invalid, for example, unsupported color space.<br> **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: Image processing is not supported.<br> **IMAGE_PROCESSING_ERROR_PROCESS_FAILED**: An error occurs during image processing.<br> **IMAGE_PROCESSING_ERROR_NO_MEMORY**: Memory allocation fails.|

### OH_ImageProcessing_GenerateMetadata()

```
ImageProcessing_ErrorCode OH_ImageProcessing_GenerateMetadata(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage)
```

**Description**

Generates metadata for an HDR image. This function is used to generate metadata for HDR images.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)* imageProcessor | Pointer to an image processing instance, which is created by **IMAGE_PROCESSING_TYPE_METADATA_GENERATION**.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* sourceImage | Pointer to the input image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: Image processing is successful.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not an image processing instance.<br> **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER**: The image is empty.<br> **IMAGE_PROCESSING_ERROR_INVALID_VALUE**: An image property is invalid, for example, unsupported color space.<br> **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: Image processing is not supported.<br> **IMAGE_PROCESSING_ERROR_PROCESS_FAILED**: An error occurs during image processing.<br> **IMAGE_PROCESSING_ERROR_NO_MEMORY**: Memory allocation fails.|

### OH_ImageProcessing_EnhanceDetail()

```
ImageProcessing_ErrorCode OH_ImageProcessing_EnhanceDetail(OH_ImageProcessing* imageProcessor,OH_PixelmapNative* sourceImage, OH_PixelmapNative* destinationImage)
```

**Description**

Enhances the image definition and details. This function performs necessary scaling operations on the source image based on the preset sizes of the input and output images to generate the target image. It uses multiple scaling methods to balance performance and image quality.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_ImageProcessing](capi-imageprocessing-oh-imageprocessing.md)* imageProcessor | Pointer to an image processing instance, which is created by **IMAGE_PROCESSING_TYPE_DETAIL_ENHANCER**.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* sourceImage | Pointer to the input image.|
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* destinationImage | Pointer to the output image.|

**Returns**

| Type| Description|
| -- | -- |
| [ImageProcessing_ErrorCode](capi-image-processing-types-h.md#imageprocessing_errorcode) | **IMAGE_PROCESSING_SUCCESS**: Image processing is successful.<br> **IMAGE_PROCESSING_ERROR_INVALID_INSTANCE**: The instance is null or is not an image processing instance.<br> **IMAGE_PROCESSING_ERROR_INVALID_PARAMETER**: The image is empty.<br> **IMAGE_PROCESSING_ERROR_INVALID_VALUE**: An image property is invalid, for example, unsupported color space.<br> **IMAGE_PROCESSING_ERROR_UNSUPPORTED_PROCESSING**: Image processing is not supported.<br> **IMAGE_PROCESSING_ERROR_PROCESS_FAILED**: An error occurs during image processing.<br> **IMAGE_PROCESSING_ERROR_NO_MEMORY**: Memory allocation fails.|
