# drawing_matrix.h


## Overview

The **drawing_matrix.h** file declares the functions related to the matrix in the drawing module.

**File to include**: &lt;native_drawing/drawing_matrix.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_Drawing_ScaleToFit](_drawing.md#oh_drawing_scaletofit)  [OH_Drawing_ScaleToFit](_drawing.md#oh_drawing_scaletofit) | Defines an enum for the matrix scaling modes.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ScaleToFit](_drawing.md#oh_drawing_scaletofit) { SCALE_TO_FIT_FILL, SCALE_TO_FIT_START, SCALE_TO_FIT_CENTER, SCALE_TO_FIT_END } | Enumerates the matrix scaling modes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode)  [OH_Drawing_MatrixGetAll](_drawing.md#oh_drawing_matrixgetall) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*matrix, float value[9]) | Obtains all element values of a matrix.|
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](_drawing.md#oh_drawing_matrixcreate) (void) | Creates an **OH_Drawing_Matrix** object.| 
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateRotation](_drawing.md#oh_drawing_matrixcreaterotation) (float deg, float x, float y) | Creates an **OH_Drawing_Matrix** with the rotation attribute. The matrix is obtained by rotating an identity matrix by a given degree around the rotation point (x, y).| 
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateScale](_drawing.md#oh_drawing_matrixcreatescale) (float sx, float sy, float px, float py) | Creates an **OH_Drawing_Matrix** with the scale attribute. The matrix is obtained by scaling an identity matrix with the factor (sx, sy) at the rotation point (px, py).| 
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateTranslation](_drawing.md#oh_drawing_matrixcreatetranslation) (float dx, float dy) | Creates an **OH_Drawing_Matrix** with the translation attribute. The matrix is obtained by translating the identity matrix by the distance (dx, dy).| 
| void [OH_Drawing_MatrixSetMatrix](_drawing.md#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | Sets matrix parameters for an **OH_Drawing_Matrix** object.| 
| bool [OH_Drawing_MatrixSetRectToRect](_drawing.md#oh_drawing_matrixsetrecttorect) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, [OH_Drawing_ScaleToFit](_drawing.md#oh_drawing_scaletofit) stf) | Scales a matrix to map a source rectangle to a destination rectangle.| 
| void [OH_Drawing_MatrixPreRotate](_drawing.md#oh_drawing_matrixprerotate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float degree, float px, float py) | Premultiplies a matrix by an identity matrix that rotates by a given degree around the rotation point (px, py).| 
| void [OH_Drawing_MatrixPreScale](_drawing.md#oh_drawing_matrixprescale) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | Premultiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).| 
| void [OH_Drawing_MatrixPreTranslate](_drawing.md#oh_drawing_matrixpretranslate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float dx, float dy) | Premultiplies a matrix by an identity matrix that translates by a given distance (dx, dy).| 
| void [OH_Drawing_MatrixPostRotate](_drawing.md#oh_drawing_matrixpostrotate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float degree, float px, float py) | Post multiplies a matrix by an identity matrix that rotates a given degree around the rotation point (px, py). | 
| void [OH_Drawing_MatrixPostScale](_drawing.md#oh_drawing_matrixpostscale) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | Post multiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).| 
| void [OH_Drawing_MatrixPostTranslate](_drawing.md#oh_drawing_matrixposttranslate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float dx, float dy) | Post multiplies a matrix by an identity matrix that translates by a given distance (dx, dy).| 
| void [OH_Drawing_MatrixReset](_drawing.md#oh_drawing_matrixreset) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Resets a matrix to an identity matrix.| 
| void [OH_Drawing_MatrixConcat](_drawing.md#oh_drawing_matrixconcat) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*total, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*a, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*b) | Multiplies two matrices to produce a new matrix.| 
| float [OH_Drawing_MatrixGetValue](_drawing.md#oh_drawing_matrixgetvalue) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, int index) | Obtains a matrix value of a given index. The index ranges from 0 to 8.| 
| void [OH_Drawing_MatrixRotate](_drawing.md#oh_drawing_matrixrotate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float degree, float px, float py) | Sets a matrix as an identity matrix and rotates it by a given degree around the rotation point (px, py).| 
| void [OH_Drawing_MatrixTranslate](_drawing.md#oh_drawing_matrixtranslate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float dx, float dy) | Sets a matrix as an identity matrix and translates it by a given distance (dx, dy).| 
| void [OH_Drawing_MatrixScale](_drawing.md#oh_drawing_matrixscale) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | Sets a matrix as an identity matrix and scales it with the factor (sx, sy) at the rotation point (px, py).| 
| bool [OH_Drawing_MatrixInvert](_drawing.md#oh_drawing_matrixinvert) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*inverse) | Inverts a matrix and returns the result.| 
| bool [OH_Drawing_MatrixSetPolyToPoly](_drawing.md#oh_drawing_matrixsetpolytopoly) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*src, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*dst, uint32_t count) | Generates a transform matrix by setting source points and destination points. Both the number of source points and that of destination points must be in the range [0, 4].| 
| void [OH_Drawing_MatrixMapPoints](_drawing.md#oh_drawing_matrixmappoints) (const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*src, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*dst, int count) | Maps a source point array to a destination point array by means of matrix transformation.| 
| bool [OH_Drawing_MatrixMapRect](_drawing.md#oh_drawing_matrixmaprect) (const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst) | Maps a rectangle to the smallest rectangle that can enclose the vertices to which the four source vertices are mapped by means of matrix transformation.| 
| bool [OH_Drawing_MatrixIsEqual](_drawing.md#oh_drawing_matrixisequal) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*other) | Checks whether two **OH_Drawing_Matrix** objects are equal.| 
| bool [OH_Drawing_MatrixIsIdentity](_drawing.md#oh_drawing_matrixisidentity) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Checks whether an **OH_Drawing_Matrix** object is an identity matrix.| 
| void [OH_Drawing_MatrixDestroy](_drawing.md#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Destroys an **OH_Drawing_Matrix** object and reclaims the memory occupied by the object.| 
