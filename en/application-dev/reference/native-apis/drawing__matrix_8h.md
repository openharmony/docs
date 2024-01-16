# drawing_matrix.h


## Overview

The **drawing_matrix.h** file declares the functions related to the matrix in the drawing module.

**File to include**: &lt;native_drawing/drawing_matrix.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](_drawing.md#oh_drawing_matrixcreate) (void) | Creates an **OH_Drawing_Matrix** object.|
| void [OH_Drawing_MatrixSetMatrix](_drawing.md#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | Sets matrix parameters for an **OH_Drawing_Matrix** object.|
| void [OH_Drawing_MatrixDestroy](_drawing.md#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Destroys an **OH_Drawing_Matrix** object and reclaims the memory occupied by the object.|
