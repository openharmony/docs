# drawing_memory_stream.h


## Overview

The **drawing_memory_stream.h** file declares the functions related to the memory stream in the drawing module.

**File to include**: &lt;native_drawing/drawing_memory_stream.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream) \* [OH_Drawing_MemoryStreamCreate](_drawing.md#oh_drawing_memorystreamcreate) (const void \*data, size_t length, bool copyData) | Creates an **OH_Drawing_MemoryStream** object.|
| void [OH_Drawing_MemoryStreamDestroy](_drawing.md#oh_drawing_memorystreamdestroy) ([OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream) \*) | Destroys an **OH_Drawing_MemoryStream** object and reclaims the memory occupied by the object.|
