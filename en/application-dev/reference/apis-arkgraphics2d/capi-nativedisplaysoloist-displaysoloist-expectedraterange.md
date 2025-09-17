# DisplaySoloist_ExpectedRateRange
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hudi33-->
<!--Designer: @hudi33-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->

## Overview

This struct describes the expected frame rate range.

**Since**: 12

**Related module**: [NativeDisplaySoloist](capi-nativedisplaysoloist.md)

**Header file**: [native_display_soloist.h](capi-native-display-soloist-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t min | Minimum value of the expected frame rate range. The value range is [0,120].|
| int32_t max | Maximum value of the expected frame rate range. The value range is [0,120].|
| int32_t expected | Expected frame rate. The value range is [0,120].|


### Member Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_DisplaySoloist_FrameCallback)(long long timestamp, long long targetTimestamp, void* data)](#oh_displaysoloist_framecallback) | OH_DisplaySoloist_FrameCallback() | Defines the pointer to an OH_DisplaySoloist callback function.<br>**Since**: 12|

## Member Function Description

### OH_DisplaySoloist_FrameCallback()

```
typedef void (*OH_DisplaySoloist_FrameCallback)(long long timestamp, long long targetTimestamp, void* data)
```

**Description**

Defines the pointer to an OH_DisplaySoloist callback function.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| long long timestamp | Current frame VSync timestamp.|
|  long long targetTimestamp | Expected VSync timestamp of the next frame.|
|  void* data | Pointer to user-defined data.|
