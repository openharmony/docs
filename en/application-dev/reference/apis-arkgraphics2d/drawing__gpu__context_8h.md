# drawing_gpu_context.h


## Overview

The **drawing_gpu_context.h** file declares the functions related to the GPU context in the drawing module.

**File to include**: &lt;native_drawing/drawing_gpu_context.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md) | Describes the options about the GPU context.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)  [OH_Drawing_GpuContextOptions](_drawing.md#oh_drawing_gpucontextoptions) | Defines a struct for the options about the GPU context.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) \* [OH_Drawing_GpuContextCreateFromGL](_drawing.md#oh_drawing_gpucontextcreatefromgl) ([OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)) | Creates an **OH_Drawing_GpuContext** object that uses OpenGL as the backend interface.| 
| [OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) \* [OH_Drawing_GpuContextCreate](_drawing.md#oh_drawing_gpucontextcreate) (void) | Creates an **OH_Drawing_GpuContext** object, for which the backend type depends on the device. | 
| void [OH_Drawing_GpuContextDestroy](_drawing.md#oh_drawing_gpucontextdestroy) ([OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) \*) | Destroys an **OH_Drawing_GpuContext** object and reclaims the memory occupied by the object.| 
