# ImageProcessing_ColorSpaceInfo

## Overview

Defines a struct for the color space information, which is used in CSC capability query.

**See also**

[OH_ImageProcessing_IsColorSpaceConversionSupported](capi-image-processing-h.md#oh_imageprocessing_iscolorspaceconversionsupported), [OH_ImageProcessing_IsCompositionSupported](capi-image-processing-h.md#oh_imageprocessing_iscompositionsupported), [OH_ImageProcessing_IsDecompositionSupported](capi-image-processing-h.md#oh_imageprocessing_isdecompositionsupported)

**Since**: 13

**Related module**: [ImageProcessing](capi-imageprocessing.md)

**Header file**: [image_processing_types.h](capi-image-processing-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t metadataType | Metadata type. For details, see [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey).|
| int32_t colorSpace | Color space. For details, see [ColorSpaceName](../apis-arkgraphics2d/capi-native-color-space-manager-h.md#colorspacename).|
| int32_t pixelFormat | Pixel format. For details, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format).|
<!--no_check-->