# OH_Pixelmap_HdrMetadataValue

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=62f43af624b3dd8e087aab6967d3e43810260062 translatedAt=2026-08-03T04:02:31.842Z pushedAt=2026-08-04T06:15:15.945Z -->

```c
typedef struct OH_Pixelmap_HdrMetadataValue {...} OH_Pixelmap_HdrMetadataValue
```

## Overview

This struct defines the HDR metadata value used by the PixelMap, which corresponds to OH_Pixelmap_HdrMetadataKey. When a key in [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey) is passed as an input parameter, this struct can be used to set or obtain the metadata value of the corresponding type. This struct is used in the [OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata) APIs, and is applicable to scenarios where HDR image metadata management and rendering processing are required, helping apps correctly set and obtain HDR metadata to achieve the high dynamic range display effect of HDR images.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_Pixelmap_HdrMetadataType](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatatype) type | HDR metadata value type corresponding to the HDR_METADATA_TYPE key in [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey), used to represent the type of HDR metadata. Different values correspond to different types of HDR metadata. Select an appropriate value based on the actual metadata type of the HDR image and fill in the corresponding metadata member fields. |
| [OH_Pixelmap_HdrStaticMetadata](capi-image-nativemodule-oh-pixelmap-hdrstaticmetadata.md) staticMetadata | Metadata value type corresponding to the HDR_STATIC_METADATA key in [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey), used to store HDR static metadata. |
| [OH_Pixelmap_HdrDynamicMetadata](capi-image-nativemodule-oh-pixelmap-hdrdynamicmetadata.md) dynamicMetadata | Metadata value type corresponding to the HDR_DYNAMIC_METADATA key in [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey), used to store HDR dynamic metadata. The format follows relevant HDR dynamic metadata standards. |
| [OH_Pixelmap_HdrGainmapMetadata](capi-image-nativemodule-oh-pixelmap-hdrgainmapmetadata.md) gainmapMetadata | Metadata value type corresponding to the HDR_GAINMAP_METADATA key in [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey), used to store HDR gain map metadata. For details, see ISO 21496-1. |