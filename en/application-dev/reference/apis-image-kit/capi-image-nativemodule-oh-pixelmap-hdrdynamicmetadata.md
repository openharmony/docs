# OH_Pixelmap_HdrDynamicMetadata

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=62f43af624b3dd8e087aab6967d3e43810260062 translatedAt=2026-08-03T04:01:58.294Z pushedAt=2026-08-04T04:51:30.689Z -->

```c
typedef struct OH_Pixelmap_HdrDynamicMetadata {...} OH_Pixelmap_HdrDynamicMetadata
```

## Overview

This struct represents the dynamic metadata value corresponding to the HDR_DYNAMIC_METADATA keyword, used to store the dynamic metadata of an HDR image. HDR dynamic metadata can be used to dynamically adjust the display parameters of an HDR image during the display process, so as to adapt to the capabilities of different display devices and achieve more accurate HDR display effects. It is used as a member of [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) when calling [OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata).

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t *data | Pointer to the dynamic metadata value, pointing to the binary data buffer that stores the dynamic metadata. The buffer length is specified by the **length** member. |
| uint32_t length | Length of the dynamic metadata value, in bytes. The value must be consistent with the actual length of the data buffer pointed to by **data**. |