# OhosImageSourceUpdateData


## Overview

The **OhosImageSourceUpdateData** struct defines the update data option of the image source. It is obtained by calling [OH_ImageSource_UpdateData](image.md#oh_imagesource_updatedata).

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [buffer](image.md#buffer-22) = nullptr | Defines a pointer to the buffer for storing the update data.| 
| [bufferSize](image.md#buffersize-22) = 0 | Defines the size of the buffer.| 
| [offset](image.md#offset) = 0 | Defines the offset of the update data in the buffer.| 
| [updateLength](image.md#updatelength) = 0 | Defines the length of the update data in the buffer.| 
| [isCompleted](image.md#iscompleted) = 0 | Defines whether the image source data update is completed.| 
