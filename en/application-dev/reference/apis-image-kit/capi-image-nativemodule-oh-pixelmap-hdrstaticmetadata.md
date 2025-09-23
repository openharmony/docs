# OH_Pixelmap_HdrStaticMetadata

## Overview

The struct describes the static metadata values available for the key **HDR_STATIC_METADATA**.

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| float displayPrimariesX[3] | X coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0].|
| float displayPrimariesY[3] | Y coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0].|
| float whitePointX | X coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].|
| float whitePointY | Y coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].|
| float maxLuminance | Maximum luminance of the main monitor. The unit is 1, and the maximum value is 65535.|
| float minLuminance | Minimum luminance of the main monitor. The unit is 0.0001, and the maximum value is 6.55535.|
| float maxContentLightLevel | Maximum luminance of the displayed content. The unit is 1, and the maximum value is 65535.|
| float maxFrameAverageLightLevel | Maximum average luminance of the displayed content. The unit is 1, and the maximum value is 65535.|
