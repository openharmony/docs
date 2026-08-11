# OH_Pixelmap_HdrGainmapMetadata
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_Pixelmap_HdrGainmapMetadata {...} OH_Pixelmap_HdrGainmapMetadata
```

## Overview

The struct describes the gain map metadata values available for the key **HDR_GAINMAP_METADATA**. For details, see ISO 21496-1. This struct describes parameters of the HDR gain map, including the version, number of channels, brightening ratio, offset, and gain curves for each channel. It is used as a member of [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) when [OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata) is called. This is applicable to scenarios where HDR image gain mapping metadata needs to be set or retrieved.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint16_t writerVersion | Version of the metadata editor.|
| uint16_t miniVersion | Minimum version required for metadata parsing.|
| uint8_t gainmapChannelNum | Number of color channels of the gain map. The value can be **1** or **3**. When the value is **3**, the metadata values of the RGB channels are different. When the value is **1**, the metadata values of the RGB channels are the same. For details, see ISO 21496-1.|
| bool useBaseColorFlag | Whether to use the color space of the base image. The value **true** indicates yes, and the value **false** indicates no. For details, see ISO 21496-1.|
| float baseHeadroom | Brightening ratio of the base image. The value range is [1.0, +∞). For details, see ISO 21496-1.|
| float alternateHeadroom | Brightening ratio of the alternative image. The value range is [1.0, +∞). For details, see ISO 21496-1.|
| float gainmapMax[3] | Maximum values of the gain map. The values are stored for the R, G, and B channels. The value range is (0, +∞) and must be greater than the corresponding channel value of **gainmapMin**. For details, see ISO 21496-1.|
| float gainmapMin[3] | Minimum values of the gain map. The values are stored for the R, G, and B channels. The value can be 0 or a negative value, but must be less than the corresponding channel value of **gainmapMax**. For details, see ISO 21496-1.|
| float gamma[3] | Gamma correction values of the gain curve. The values are stored for the R, G, and B channels. The value range is (0, +∞). For details, see ISO 21496-1.|
| float baselineOffset[3] | Offsets of the base image. The values are stored for the R, G, and B channels. For details, see ISO 21496-1.|
| float alternateOffset[3] | Offset of the alternative image. The values are stored for the R, G, and B channels. For details, see ISO 21496-1.|
