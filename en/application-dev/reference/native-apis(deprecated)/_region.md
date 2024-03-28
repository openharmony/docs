# Region


## Overview

The **Region** module defines the rectangle (dirty region) where the content is to be updated in the local NativeWindow.

**Since**

8

**Related Modules**

[NativeWindow](_native_window.md)


## Summary


### Member Variables

  | Name| Description| 
| -------- | -------- |
| [*rects](#rects) | If **rects** is a null pointer, the buffer size is the same as the size of the dirty region by default.| 
| [rectNumber](#rectnumber) | If **rectNumber** is **0**, the buffer size is the same as the size of the dirty region by default.| 


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
