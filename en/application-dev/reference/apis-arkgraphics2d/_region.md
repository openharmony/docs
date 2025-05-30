# Region


## Overview

The **Region** struct describes the rectangle (dirty region) where the content is to be updated in the local **OHNativeWindow**.

**Since**: 8

**Related module**: [NativeWindow](_native_window.md)

**Header file**: [external_window.h](external__window_8h.md)

## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[Rect](_rect.md) | Describes a rectangle.| 


### Member Variables

| Name| Description| 
| -------- | -------- |
| struct [Region::Rect](_rect.md) \* rects | If **rects** is a null pointer, the buffer size is the same as the size of the dirty region by default.| 
| int32_t [rectNumber](#rectnumber) | If **rectNumber** is **0**, the buffer size is the same as the size of the dirty region by default.| 


## Member Variable Description


### rectNumber

```
int32_t Region::rectNumber
```

**Description**

If **rectNumber** is **0**, the buffer size is the same as the size of the dirty region by default.


### \*rects

```
struct Rect Region::*rects
```

**Description**

Pointer to the struct. The type is [Rect](_rect.md). If **rects** is a null pointer, the buffer size is the same as the size of the dirty region by default.
