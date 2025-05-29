# OhosImageSourceUpdateData


## Overview

The **OhosImageSourceUpdateData** struct defines the update data option of the image source. It is obtained by calling [OH_ImageSource_UpdateData](image.md#oh_imagesource_updatedata).

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)

**Header file**: [image_source_mdk.h](image__source__mdk_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t \* [buffer](image.md#buffer-22) = nullptr | Pointer to the buffer for storing the update data.|
| size_t [bufferSize](image.md#buffersize-22) = 0 | Size of the buffer.|
| uint32_t [offset](image.md#offset) = 0 | Offset of the update data in the buffer.|
| uint32_t [updateLength](image.md#updatelength) = 0 | Length of the update data in the buffer.|
| int8_t [isCompleted](image.md#iscompleted) = 0 | Whether the image source data update is completed.|
