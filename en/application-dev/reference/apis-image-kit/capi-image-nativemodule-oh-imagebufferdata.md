# OH_ImageBufferData

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T03:59:00.348Z pushedAt=2026-08-04T03:02:16.040Z -->

```c
typedef struct {...} OH_ImageBufferData
```

## Overview

**OH_ImageBufferData** is the image data struct encapsulated at the native layer. To obtain an **OH_ImageNative_GetBufferData** object, call [OH_ImageNative_GetBufferData](capi-image-native-h.md#oh_imagenative_getbufferdata).<br> The struct stores the shallow copy of the original image data. Once the original data is released, no read or write operations should be performed on the pointers within this struct; otherwise, undefined behavior will occur.

**Since**: 23

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_native.h](capi-image-native-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t *rowStride | Array of row strides of image color components, in pixels.|
| int32_t *pixelStride | Array of pixel pitches of image color components, in pixels.|
| int32_t numStride | Array length.|
| size_t bufferSize | Buffer size, in bytes.|
| OH_NativeBuffer *nativeBuffer | Pointer to the **OH_NativeBuffer** object of the image.|