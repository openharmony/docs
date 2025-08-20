# format.h

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## Overview

Declares tensor data formats.

**File to include**: <mindspore/format.h>

**Library**: libmindspore_lite_ndk.so

**System capability**: SystemCapability.Ai.MindSpore

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AI_Format](#oh_ai_format) | OH_AI_Format | Data formats supported by MSTensor.|

## Enum Description

### OH_AI_Format

```
enum OH_AI_Format
```

**Description**

Declares data formats supported by MSTensor.

**Since**: 9

| Enum Item| Description|
| -- | -- |
| OH_AI_FORMAT_NCHW = 0 | Tensor data is stored in the sequence of batch number N, channel C, height H, and width W.|
| OH_AI_FORMAT_NHWC = 1 | Tensor data is stored in the sequence of batch number N, height H, width W, and channel C.|
| OH_AI_FORMAT_NHWC4 = 2 | Tensor data is stored in the sequence of batch number N, height H, width W, and channel C. The C axis is 4-byte aligned.|
| OH_AI_FORMAT_HWKC = 3 | Tensor data is stored in the sequence of height H, width W, core count K, and channel C.|
| OH_AI_FORMAT_HWCK = 4 | Tensor data is stored in the sequence of height H, width W, channel C, and core count K.|
| OH_AI_FORMAT_KCHW = 5 | Tensor data is stored in the sequence of core count K, channel C, height H, and width W.|
| OH_AI_FORMAT_CKHW = 6 | Tensor data is stored in the sequence of channel C, core count K, height H, and width W.|
| OH_AI_FORMAT_KHWC = 7 | Tensor data is stored in the sequence of core count K, height H, width W, and channel C.|
| OH_AI_FORMAT_CHWK = 8 | Tensor data is stored in the sequence of channel C, height H, width W, and core count K.|
| OH_AI_FORMAT_HW = 9 | Tensor data is stored in the sequence of height H and width W.|
| OH_AI_FORMAT_HW4 = 10 | Tensor data is stored in the sequence of height H and width W. The W axis is 4-byte aligned.|
| OH_AI_FORMAT_NC = 11 | Tensor data is stored in the sequence of batch number N and channel C.|
| OH_AI_FORMAT_NC4 = 12 | Tensor data is stored in the sequence of batch number N and channel C. The C axis is 4-byte aligned.|
| OH_AI_FORMAT_NC4HW4 = 13 | Tensor data is stored in the sequence of batch number N, channel C, height H, and width W. The C axis and W axis are 4-byte aligned.|
| OH_AI_FORMAT_NCDHW = 15 | Tensor data is stored in the sequence of batch number N, channel C, depth D, height H, and width W.|
| OH_AI_FORMAT_NWC = 16 | Tensor data is stored in the sequence of batch number N, width W, and channel C.|
| OH_AI_FORMAT_NCW = 17 | Tensor data is stored in the sequence of batch number N, channel C, and width W.|
