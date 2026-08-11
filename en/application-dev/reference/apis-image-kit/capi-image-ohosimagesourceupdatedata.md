# OhosImageSourceUpdateData

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:04:21.399Z pushedAt=2026-08-04T02:52:58.182Z -->

```c
struct OhosImageSourceUpdateData {...}
```

## Overview

The struct describes the update data option of the image source. It is obtained by calling [OH_ImageSource_UpdateData](capi-image-source-mdk-h.md#oh_imagesource_updatedata).

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_source_mdk.h](capi-image-source-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t* buffer = nullptr | Pointer to the buffer for storing the update data.|
| size_t bufferSize = 0 | Size of the buffer.|
| uint32_t offset = 0 | Offset of the update data in the buffer.|
| uint32_t updateLength = 0 | Length of the update data in the buffer.|
| int8_t isCompleted = 0 | Whether the image source data update is completed.|