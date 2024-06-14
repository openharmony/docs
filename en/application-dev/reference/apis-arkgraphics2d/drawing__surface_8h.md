# drawing_surface.h


## Overview

The **drawing_surface.h** file declares the functions related to the surface in the drawing module, including creating, destroying, and using the surface.

**File to include**: &lt;native_drawing/drawing_surface.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_Surface](_drawing.md#oh_drawing_surface) \* [OH_Drawing_SurfaceCreateFromGpuContext](_drawing.md#oh_drawing_surfacecreatefromgpucontext) ([OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) \*, bool budgeted, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)) | Creates an **OH_Drawing_Surface** object using the GPU context to manage the content drawn on the canvas.| 
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \* [OH_Drawing_SurfaceGetCanvas](_drawing.md#oh_drawing_surfacegetcanvas) ([OH_Drawing_Surface](_drawing.md#oh_drawing_surface) \*) | Obtains a canvas from an **OH_Drawing_Surface** object.| 
| void [OH_Drawing_SurfaceDestroy](_drawing.md#oh_drawing_surfacedestroy) ([OH_Drawing_Surface](_drawing.md#oh_drawing_surface) \*) | Destroys an **OH_Drawing_Surface** object and reclaims the memory occupied.| 
