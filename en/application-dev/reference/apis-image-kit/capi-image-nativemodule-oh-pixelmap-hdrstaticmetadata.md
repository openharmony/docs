# OH_Pixelmap_HdrStaticMetadata
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_Pixelmap_HdrStaticMetadata {...} OH_Pixelmap_HdrStaticMetadata
```

## Overview

This struct represents the static metadata value corresponding to the HDR_STATIC_METADATA key, used to describe the capabilities of the HDR display device and content brightness characteristics (such as primary color coordinates, white point coordinates, maximum/minimum luminance, and maximum content light level). It is used as a member of [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) when calling [OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata).

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| float displayPrimariesX[3] | Normalized X coordinates of the display device's three primary colors. The array length is 3, stored in R, G, B order. The unit is 0.00002. The value range is [0.0, 0.99998].|
| float displayPrimariesY[3] | Normalized Y coordinates of the display device's three primary colors. The array length is 3, stored in R, G, B order. The unit is 0.00002. The value range is [0.0, 0.99998].|
| float whitePointX | Normalized X coordinate of the white point. The unit is 0.00002. The value range is [0.0, 0.99998].|
| float whitePointY | Normalized Y coordinate of the white point. The unit is 0.00002. The value range is [0.0, 0.99998].|
| float maxLuminance | Maximum luminance of the primary monitor. The unit is 1, and the value range is [0, 65535]. The unit is nits.|
| float minLuminance | Minimum luminance of the primary monitor. The unit is 0.0001. The value range is [0, 6.5535]. The unit is nits.|
| float maxContentLightLevel | Maximum luminance of the displayed content. The unit is 1, and the value range is [0, 65535]. The unit is nits.|
| float maxFrameAverageLightLevel | Maximum average luminance of the displayed content. The unit is 1, and the value range is [0, 65535]. The unit is nits.|
