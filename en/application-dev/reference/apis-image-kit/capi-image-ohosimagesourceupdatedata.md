# OhosImageSourceUpdateData

## Overview

The OhosImageSourceUpdateData struct describes the update data option of the image source. It is obtained by calling [OH_ImageSource_UpdateData](capi-image-source-mdk-h.md#oh_imagesource_updatedata).

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
