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
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateRotation](_drawing.md#oh_drawing_matrixcreaterotation) (float deg, float x, float y) | Creates an **OH_Drawing_Matrix** with the rotation attribute. The matrix can rotate by a given degree around the rotation point (x, y).|
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateScale](_drawing.md#oh_drawing_matrixcreatescale) (float sx, float sy, float px, float py) | Creates an **OH_Drawing_Matrix** with the scale attribute. The matrix can be scaled with the factor (sx, sy) at the rotation point (px, py).|
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateTranslation](_drawing.md#oh_drawing_matrixcreatetranslation) (float dx, float dy) | Creates an **OH_Drawing_Matrix** with the translation attribute.|
| void [OH_Drawing_MatrixSetMatrix](_drawing.md#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | Sets matrix parameters for an **OH_Drawing_Matrix** object.|
| void [OH_Drawing_MatrixConcat](_drawing.md#oh_drawing_matrixconcat) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*total, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*a, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*b) | Multiplies two matrices to produce a new matrix.|
| float [OH_Drawing_MatrixGetValue](_drawing.md#oh_drawing_matrixgetvalue) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, int index) | Obtains a matrix value of a given index. The index ranges from 0 to 8.|
| void [OH_Drawing_MatrixRotate](_drawing.md#oh_drawing_matrixrotate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float degree, float px, float py) | Rotates a matrix by a given degree around the rotation point (px, py).|
| void [OH_Drawing_MatrixTranslate](_drawing.md#oh_drawing_matrixtranslate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float dx, float dy) | Translates a matrix by a given distance (dx, dy).|
| void [OH_Drawing_MatrixScale](_drawing.md#oh_drawing_matrixscale) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | Scales a matrix with the factor (sx, sy) at the rotation point (px, py).|
| bool [OH_Drawing_MatrixInvert](_drawing.md#oh_drawing_matrixinvert) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*inverse) | Inverts a matrix and returns the result.|
| bool [OH_Drawing_MatrixIsEqual](_drawing.md#oh_drawing_matrixisequal) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*other) | Checks whether two **OH_Drawing_Matrix** objects are equal.|
| bool [OH_Drawing_MatrixIsIdentity](_drawing.md#oh_drawing_matrixisidentity) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Checks whether an **OH_Drawing_Matrix** object is an identity matrix.|
| void [OH_Drawing_MatrixDestroy](_drawing.md#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Destroys an **OH_Drawing_Matrix** object and reclaims the memory occupied by the object.|
