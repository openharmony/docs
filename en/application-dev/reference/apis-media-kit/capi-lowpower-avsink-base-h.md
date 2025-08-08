# lowpower_avsink_base.h

## Overview

The file declares the basic dependencies for OH_LowPowerAudioSink and OH_LowPowerVideoSink.

**File to include**: <multimedia/player_framework/lowpower_avsink_base.h>

**Library**: liblowpower_avsink.so

**System capability**: SystemCapability.Multimedia.Media.LowPowerAVSink

**Since**: 20

**Related module**: [AVSinkBase](capi-avsinkbase.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md) | OH_AVSamplesBuffer | Describes the input data of the LowPowerAVSink. After receiving the DataNeeded callback, the application must pack data into an OH_AVSamplesBuffer instance and pass it to the corresponding lowpower_avsink.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVErrCode OH_AVSamplesBuffer_AppendOneBuffer(OH_AVSamplesBuffer *samplesBuffer, OH_AVBuffer *avBuffer)](#oh_avsamplesbuffer_appendonebuffer) | Appends data from an OH_AVBuffer instance to an OH_AVSamplesBuffer instance.|
| [int32_t OH_AVSamplesBuffer_GetRemainedCapacity(OH_AVSamplesBuffer *samplesBuffer)](#oh_avsamplesbuffer_getremainedcapacity) | Obtains the remaining capacity available in an OH_AVSamplesBuffer instance.|

## Function Description

### OH_AVSamplesBuffer_AppendOneBuffer()

```
OH_AVErrCode OH_AVSamplesBuffer_AppendOneBuffer(OH_AVSamplesBuffer *samplesBuffer, OH_AVBuffer *avBuffer)
```

**Description**

Appends data from an OH_AVBuffer instance to an OH_AVSamplesBuffer instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md) *samplesBuffer | Pointer to an OH_AVSamplesBuffer instance.|
| [OH_AVBuffer](../apis-avcodec-kit/_core.md#oh_avbuffer) *avBuffer | Pointer to an OH_AVBuffer instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br> **AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br> **AV_ERR_NO_MEMORY**: The framePacketBuffer does not have sufficient remaining capacity to append an OH_AVBuffer.<br> **AV_ERR_UNKNOW**: An unknown error occurs.|

### OH_AVSamplesBuffer_GetRemainedCapacity()

```
int32_t OH_AVSamplesBuffer_GetRemainedCapacity(OH_AVSamplesBuffer *samplesBuffer)
```

**Description**

Obtains the remaining capacity available in an OH_AVSamplesBuffer instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md) *samplesBuffer | Pointer to an OH_AVSamplesBuffer instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Remaining capacity available in the OH_AVSamplesBuffer instance, in bytes. If **sampleBuffer** or data poniter is nullptr or invalid, **-1** is returned.|
