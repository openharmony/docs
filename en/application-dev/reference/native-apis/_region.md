# Region


## Overview

Defines the rectangle (dirty region) where the content is to be updated in the local native window.

**Related Modules:**

[NativeWindow](_native_window.md)


## Summary



### Member Variables

| Name | Description | 
| -------- | -------- |
| [rects](#rects) | If **rects** is a null pointer, the buffer size is the same as the size of the dirty region by default. | 
| [rectNumber](#rectnumber) | If **rectNumber** is **0**, the buffer size is the same as the size of the dirty region by default.  | 


## Member Variable Description 


### rectNumber

  
```
int32_t Region::rectNumber
```
**Description**<br>
If **rectNumber** is **0**, the buffer size is the same as the size of the dirty region by default.


### *rects

```
struct Rect Region::*rects
```

**Description**<br>
If **rects** is a null pointer, the buffer size is the same as the size of the dirty region by default.

<!--no_check-->