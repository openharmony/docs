# ImageProcessing_ColorSpaceInfo

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:06:32.512Z pushedAt=2026-08-04T02:13:51.115Z -->

```c
typedef struct ImageProcessing_ColorSpaceInfo {...} ImageProcessing_ColorSpaceInfo
```

## Overview

The struct describes the color space information, which is used in Color Space Conversion (CSC) capability query.

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