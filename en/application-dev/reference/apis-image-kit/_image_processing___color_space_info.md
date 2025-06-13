# ImageProcessing_ColorSpaceInfo


## Overview

The ImageProcessing_ColorSpaceInfo struct describes the color space information, which is used in Color Space Conversion (CSC) capability query.

See:

[OH_ImageProcessing_IsColorSpaceConversionSupported](_image_processing.md#oh_imageprocessing_iscolorspaceconversionsupported)

[OH_ImageProcessing_IsCompositionSupported](_image_processing.md#oh_imageprocessing_iscompositionsupported)

[OH_ImageProcessing_IsDecompositionSupported](_image_processing.md#oh_imageprocessing_isdecompositionsupported)

**Since**: 13

**Related module**: [ImageProcessing](_image_processing.md)

**Header file**: [image_processing_types.h](image__processing__types_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [metadataType](#metadatatype) | Metadata type, which is used in [OH_Pixelmap_HdrMetadataKey](../apis-image-kit/_image___native_module.md#oh_pixelmap_hdrmetadatakey).| 
| int32_t [colorSpace](#colorspace) | Color space, which is specified by [ColorSpaceName](../apis-arkgraphics2d/_native_color_space_manager.md#colorspacename-1).| 
| int32_t [pixelFormat](#pixelformat) | Pixel format, which is specified by [PIXEL_FORMAT](../apis-image-kit/_image___native_module.md#pixel_format).| 


## Member Variable Description


### colorSpace

```
int32_t ImageProcessing_ColorSpaceInfo::colorSpace
```

**Description**

Color space, which is specified by [ColorSpaceName](../apis-arkgraphics2d/_native_color_space_manager.md#colorspacename-1).


### metadataType

```
int32_t ImageProcessing_ColorSpaceInfo::metadataType
```

**Description**

Metadata type, which is used in [OH_Pixelmap_HdrMetadataKey](../apis-image-kit/_image___native_module.md#oh_pixelmap_hdrmetadatakey).


### pixelFormat

```
int32_t ImageProcessing_ColorSpaceInfo::pixelFormat
```

**Description**

Pixel format, which is specified by [PIXEL_FORMAT](../apis-image-kit/_image___native_module.md#pixel_format).
