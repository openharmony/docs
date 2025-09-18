# OH_NativeVSync_ExpectedRateRange

## Overview

Provides the expected frame rate range.

**Since**: 20

**Related module**: [NativeVsync](capi-nativevsync.md)

**Header file**: [native_vsync.h](capi-native-vsync-h.md)

## Summary

### Member Variables

| Name            | Description                |
| ---------------- | -------------------- |
| int32_t min      | Minimum frame rate.|
| int32_t max      | Maximum frame rate.|
| int32_t expected | Expected frame rate.|


### Member Functions

| Name                                                        | typedef Keyword                 | Description                                                        |
| ------------------------------------------------------------ | ------------------------------ | ------------------------------------------------------------ |
| [typedef void (\*OH_NativeVSync_FrameCallback)(long long timestamp, void *data)](#oh_nativevsync_framecallback) | OH_NativeVSync_FrameCallback() | Defines the pointer to a VSync callback function.<br>**Since**: 9<br>**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync|

## Member Function Description

### OH_NativeVSync_FrameCallback()

```
typedef void (*OH_NativeVSync_FrameCallback)(long long timestamp, void *data)
```

**Item**

Defines the pointer to a VSync callback function.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeVsync

**Since**: 9

**Parameters**

| Name             | Description                                                  |
| ------------------- | ------------------------------------------------------ |
| long long timestamp | System timestamp obtained by VSync using **CLOCK_MONOTONIC**, in nanoseconds.|
| void *data          | Pointer to user-defined data.                                      |
