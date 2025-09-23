# OH_Pixelmap_HdrGainmapMetadata

## Overview

The struct describes the gain map metadata values available for the key **HDR_GAINMAP_METADATA**. For details, see ISO 21496-1.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint16_t writerVersion | Version used by the metadata editor.|
| uint16_t miniVersion | Minimum version that needs to be understood for metadata parsing.|
| uint8_t gainmapChannelNum | Number of color channels of the gain map. When the value is 3, the metadata values of the RGB channels are different. When the value is 1, the metadata values of the RGB channels are the same.|
| bool useBaseColorFlag | Whether to use the color space of the base graphic. For details, see ISO 21496-1.|
| float baseHeadroom | Headroom of the base graphic, which means the additional brightness that can be added to the base graphic. For details, see ISO 21496-1.|
| float alternateHeadroom | Headroom of the alternate graphic. For details, see ISO 21496-1.|
| float gainmapMax[3] | Maximum value of the gain map. For details, see ISO 21496-1.|
| float gainmapMin[3] | Minimum value of the gain map. For details, see ISO 21496-1.|
| float gamma[3] | Gamma. For details, see ISO 21496-1.|
| float baselineOffset[3] | Offset of the base graphic. For details, see ISO 21496-1.|
| float alternateOffset[3] | Offset of the alternative graphic that can be extracted. For details, see ISO 21496-1.|
