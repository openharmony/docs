# OH_ImageRawData

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=80c0a43cc0af3435c23af3413e3b0da162d4ceb8 translatedAt=2026-08-03T04:00:13.846Z pushedAt=2026-08-04T04:31:11.819Z -->

```c
typedef struct OH_ImageRawData OH_ImageRawData
```

## Overview

OH_ImageRawData is used to carry the raw data in an image.

Create an OH_ImageRawData object from an OH_ImageSourceNative object using the [OH_ImageSourceNative_CreateImageRawData](capi-image-source-native-h.md#oh_imagesourcenative_createimagerawdata) function.

Destroy an OH_ImageRawData object using the [OH_ImageSourceNative_DestroyImageRawData](capi-image-source-native-h.md#oh_imagesourcenative_destroyimagerawdata) function.

Resource management: After OH_ImageRawData is used, [OH_ImageSourceNative_DestroyImageRawData](capi-image-source-native-h.md#oh_imagesourcenative_destroyimagerawdata) must be called to destroy it. Releasing the OH_ImageSourceNative object does not automatically destroy the OH_ImageRawData object; the lifecycles of the two are independent of each other. The **data** pointer obtained through [OH_ImageSourceNative_GetBufferFromRawData](capi-image-source-native-h.md#oh_imagesourcenative_getbufferfromrawdata) points to the internal buffer of the OH_ImageRawData object, and the caller must not call **free()** on **data**. After the OH_ImageRawData object is destroyed, **data** becomes invalid. If the data needs to be used after the OH_ImageRawData object is destroyed, it must be copied before destruction.

The OH_ImageRawData struct contains the following fields and can be operated as follows.

| Field Type | Field Name | Field Description | Field Getter |
| -- | -- | -- | -- |
| uint8_t * | data | Starting address of the raw data buffer. | [OH_ImageSourceNative_GetBufferFromRawData](capi-image-source-native-h.md#oh_imagesourcenative_getbufferfromrawdata) |
| size_t | length | Length of the raw data buffer. | [OH_ImageSourceNative_GetBufferFromRawData](capi-image-source-native-h.md#oh_imagesourcenative_getbufferfromrawdata) |
| uint8_t | bitsPerPixel | Number of bits actually occupied by each pixel in the buffer data. | [OH_ImageSourceNative_GetBitsPerPixelFromRawData](capi-image-source-native-h.md#oh_imagesourcenative_getbitsperpixelfromrawdata) |

**Since**: 24

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_source_native.h](capi-image-source-native-h.md)