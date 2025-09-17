# drawing_matrix.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

This file declares the functions related to the matrix in the drawing module.

<!--RP1-->
**Sample**: [NDKAPIDrawing (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKAPIDrawing)<!--RP1End-->

**File to include**: <native_drawing/drawing_matrix.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](capi-drawing.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit) | OH_Drawing_ScaleToFit | Defines an enum for the matrix scaling modes.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix* OH_Drawing_MatrixCreate(void)](#oh_drawing_matrixcreate) | Creates an **OH_Drawing_Matrix** object.|
| [OH_Drawing_Matrix* OH_Drawing_MatrixCopy(const OH_Drawing_Matrix* matrix)](#oh_drawing_matrixcopy) | Creates a copy of a matrix object.|
| [OH_Drawing_Matrix* OH_Drawing_MatrixCreateRotation(float deg, float x, float y)](#oh_drawing_matrixcreaterotation) | Creates an **OH_Drawing_Matrix** with the rotation attribute.<br>The matrix is obtained by rotating an identity matrix by a given degree around the rotation point (x, y).|
| [OH_Drawing_Matrix* OH_Drawing_MatrixCreateScale(float sx, float sy, float px, float py)](#oh_drawing_matrixcreatescale) | Creates an **OH_Drawing_Matrix** with the scale attribute.<br>The matrix is obtained by scaling an identity matrix with the factor (sx, sy) at the rotation point (px, py).|
| [OH_Drawing_Matrix* OH_Drawing_MatrixCreateTranslation(float dx, float dy)](#oh_drawing_matrixcreatetranslation) | Creates an **OH_Drawing_Matrix** with the translation attribute.<br>The matrix is obtained by translating the identity matrix by the distance (dx, dy).|
| [void OH_Drawing_MatrixSetMatrix(OH_Drawing_Matrix* matrix, float scaleX, float skewX, float transX,float skewY, float scaleY, float transY, float persp0, float persp1, float persp2)](#oh_drawing_matrixsetmatrix) | Sets matrix parameters for an **OH_Drawing_Matrix** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_MatrixSetRectToRect(OH_Drawing_Matrix* matrix, const OH_Drawing_Rect* src,const OH_Drawing_Rect* dst, OH_Drawing_ScaleToFit stf)](#oh_drawing_matrixsetrecttorect) | Scales a matrix to map a source rectangle to a destination rectangle.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **matrix**, **src**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_MatrixPreRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)](#oh_drawing_matrixprerotate) | Premultiplies a matrix by an identity matrix that rotates by a given degree around the rotation point (px, py).|
| [void OH_Drawing_MatrixPreScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)](#oh_drawing_matrixprescale) | Premultiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).|
| [void OH_Drawing_MatrixPreTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)](#oh_drawing_matrixpretranslate) | Premultiplies a matrix by an identity matrix that translates by a given distance (dx, dy).|
| [void OH_Drawing_MatrixPostRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)](#oh_drawing_matrixpostrotate) | Post multiplies a matrix by an identity matrix that rotates a given degree around the rotation point (px, py).|
| [void OH_Drawing_MatrixPostScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)](#oh_drawing_matrixpostscale) | Post multiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).|
| [void OH_Drawing_MatrixPostTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)](#oh_drawing_matrixposttranslate) | Post multiplies a matrix by an identity matrix that translates by a given distance (dx, dy).|
| [void OH_Drawing_MatrixReset(OH_Drawing_Matrix* matrix)](#oh_drawing_matrixreset) | Resets a matrix to an identity matrix.|
| [void OH_Drawing_MatrixConcat(OH_Drawing_Matrix* total, const OH_Drawing_Matrix* a,const OH_Drawing_Matrix* b)](#oh_drawing_matrixconcat) | Multiplies two matrices to produce a new matrix.|
| [OH_Drawing_ErrorCode OH_Drawing_MatrixGetAll(OH_Drawing_Matrix* matrix, float value[9])](#oh_drawing_matrixgetall) | Obtains all element values of a matrix.|
| [float OH_Drawing_MatrixGetValue(OH_Drawing_Matrix* matrix, int index)](#oh_drawing_matrixgetvalue) | Obtains a matrix value of a given index, which ranges from 0 to 8.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **index** is less than 0 or greater than 8, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [void OH_Drawing_MatrixRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)](#oh_drawing_matrixrotate) | Sets this matrix as an identity matrix and rotates it by a given degree around the rotation point (px, py).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_MatrixTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)](#oh_drawing_matrixtranslate) | Sets a matrix as an identity matrix and translates it by a given distance (dx, dy).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [void OH_Drawing_MatrixScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)](#oh_drawing_matrixscale) | Sets a matrix as an identity matrix and scales it with the factor (sx, sy) at the rotation point (px, py).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_MatrixInvert(OH_Drawing_Matrix* matrix, OH_Drawing_Matrix* inverse)](#oh_drawing_matrixinvert) | Inverts a matrix and returns the result.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **matrix** or **inverse** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_MatrixSetPolyToPoly(OH_Drawing_Matrix* matrix, const OH_Drawing_Point2D* src,const OH_Drawing_Point2D* dst, uint32_t count)](#oh_drawing_matrixsetpolytopoly) | Generates a transformation matrix by setting source points and destination points.<br>Both the number of source points and that of destination points must be in the range [0, 4]. This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **count** is less than 0 or greater than 4, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [void OH_Drawing_MatrixMapPoints(const OH_Drawing_Matrix* matrix, const OH_Drawing_Point2D* src,OH_Drawing_Point2D* dst, int count)](#oh_drawing_matrixmappoints) | Maps a source point array to a destination point array by means of matrix transformation.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **matrix**, **src**, and **dst** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_MatrixMapRect(const OH_Drawing_Matrix* matrix, const OH_Drawing_Rect* src, OH_Drawing_Rect* dst)](#oh_drawing_matrixmaprect) | Maps a rectangle to the smallest rectangle that can enclose the vertices to which the four source vertices are mapped by means of matrix transformation.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **matrix**, **src**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_MatrixIsEqual(OH_Drawing_Matrix* matrix, OH_Drawing_Matrix* other)](#oh_drawing_matrixisequal) | Checks whether two **OH_Drawing_Matrix** objects are equal.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **matrix** or **other** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.|
| [bool OH_Drawing_MatrixIsIdentity(OH_Drawing_Matrix* matrix)](#oh_drawing_matrixisidentity) | Checks whether an **OH_Drawing_Matrix** object is an identity matrix. |
| [void OH_Drawing_MatrixDestroy(OH_Drawing_Matrix* matrix)](#oh_drawing_matrixdestroy) | Destroys an **OH_Drawing_Matrix** object and reclaims the memory occupied by the object.|

## Enum Description

### OH_Drawing_ScaleToFit

```
enum OH_Drawing_ScaleToFit
```

**Description**

Defines an enum for the matrix scaling modes.

**Since**: 12

| Enum| Description|
| -- | -- |
| SCALE_TO_FIT_FILL | Scales the source rectangle both horizontally and vertically to exactly match the destination rectangle.|
| SCALE_TO_FIT_START | Scales the source rectangle and aligns it to the left and top edges of the destination rectangle.|
| SCALE_TO_FIT_CENTER | Scales the source rectangle and aligns it to the center of the destination rectangle.|
| SCALE_TO_FIT_END | Scales the source rectangle and aligns it to the right and bottom edges of the destination rectangle.|


## Function Description

### OH_Drawing_MatrixCreate()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreate(void)
```

**Description**

Creates an **OH_Drawing_Matrix** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | Returns the pointer to the **OH_Drawing_Matrix** object created.|

### OH_Drawing_MatrixCopy()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCopy(const OH_Drawing_Matrix* matrix)
```

**Description**

Creates a copy of a matrix object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object to be copied.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | Returns the pointer to the **OH_Drawing_Matrix** object created.|

### OH_Drawing_MatrixCreateRotation()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateRotation(float deg, float x, float y)
```

**Description**

Creates an **OH_Drawing_Matrix** with the rotation attribute.<br>The matrix is obtained by rotating an identity matrix by a given degree around the rotation point (x, y).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float deg | Angle to rotate, in degrees. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation.|
| float x | Coordinate point on the X axis.|
| float y | Coordinate point on the Y axis.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | Returns a pointer to the created [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|

### OH_Drawing_MatrixCreateScale()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateScale(float sx, float sy, float px, float py)
```

**Description**

Creates an **OH_Drawing_Matrix** with the scale attribute.<br>The matrix is obtained by scaling an identity matrix with the factor (sx, sy) at the rotation point (px, py).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float sx | Scale factor on the X axis. If a negative number is passed in, the matrix is mirrored around y = px before being scaled. The value is a floating point number.|
| float sy | Scale factor on the Y axis. If a negative number is passed in, the matrix is mirrored around x = py before being scaled. The value is a floating point number.|
| float px | Coordinate point on the X axis.|
| float py | Coordinate point on the Y axis.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | Returns a pointer to the created [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|

### OH_Drawing_MatrixCreateTranslation()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateTranslation(float dx, float dy)
```

**Description**

Creates an **OH_Drawing_Matrix** with the translation attribute.<br>The matrix is obtained by translating the identity matrix by the distance (dx, dy).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float dx | Distance to translate on the X axis. A positive number indicates a translation towards the positive direction of the X axis, and a negative number indicates a translation towards the negative direction of the X axis. The value is a floating point number.|
| float dy | Distance to translate on the Y axis. A positive number indicates a translation towards the positive direction of the Y axis, and a negative number indicates a translation towards the negative direction of the Y axis. The value is a floating point number.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* | Returns a pointer to the created [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|

### OH_Drawing_MatrixSetMatrix()

```
void OH_Drawing_MatrixSetMatrix(OH_Drawing_Matrix* matrix, float scaleX, float skewX, float transX,float skewY, float scaleY, float transY, float persp0, float persp1, float persp2)
```

**Description**

Sets matrix parameters for an **OH_Drawing_Matrix** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **OH_Drawing_Matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to an **OH_Drawing_Matrix** object.|
| float scaleX | Scale factor on the X axis.|
| float skewX | Skew factor on the X axis.|
| float transX | Translation coefficient on the X axis.|
| float skewY | Skew factor on the Y axis.|
| float scaleY | Scale factor on the Y axis.|
| float transY | Translation coefficient on the Y axis.|
| float persp0 | Perspective coefficient of the X axis.|
| float persp1 | Perspective coefficient of the Y axis.|
| float persp2 | Perspective scale coefficient.|

### OH_Drawing_MatrixSetRectToRect()

```
bool OH_Drawing_MatrixSetRectToRect(OH_Drawing_Matrix* matrix, const OH_Drawing_Rect* src,const OH_Drawing_Rect* dst, OH_Drawing_ScaleToFit stf)
```

**Description**

Scales a matrix to map a source rectangle to a destination rectangle.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **matrix**, **src**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* src | Pointer to the [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md) object of the mapping source.|
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* dst | Pointer to the [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md) object of the mapping destination.|
| [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit) stf | Scaling mode. For details about the available options, see [OH_Drawing_ScaleToFit](capi-drawing-matrix-h.md#oh_drawing_scaletofit).|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the operation is successful; returns **false** if the operation fails; returns **true** and sets the matrix as follows if the passed-in matrix is empty:<br> If the width or height of **src** is less than or equal to 0, **false** is returned and the matrix is set to an identity matrix.<br> If the width or height of **dst** is less than or equal to 0, **true** is returned and the matrix is set as follows (perspective scale coefficient = 1; other values = 0).|

### OH_Drawing_MatrixPreRotate()

```
void OH_Drawing_MatrixPreRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)
```

**Description**

Premultiplies this matrix by a matrix that is derived from an identity matrix after it has been rotated by a given degree around the rotation point (px, py).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float degree | Angle to rotate, in degrees. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation.|
| float px | X coordinate of the rotation point.|
| float py | Y coordinate of the rotation point.|

### OH_Drawing_MatrixPreScale()

```
void OH_Drawing_MatrixPreScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)
```

**Description**

Premultiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).

This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float sx | Scale factor on the X axis. If a negative number is passed in, the matrix is mirrored around y = px before being scaled. The value is a floating point number.|
| float sy | Scale factor on the Y axis. If a negative number is passed in, the matrix is mirrored around x = py before being scaled. The value is a floating point number.|
| float px | X coordinate of the scale point.|
| float py | Y coordinate of the scale point.|

### OH_Drawing_MatrixPreTranslate()

```
void OH_Drawing_MatrixPreTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)
```

**Description**

Premultiplies this matrix by a matrix that is derived from an identity matrix after it has been translated by a given distance (dx, dy).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float dx | Horizontal distance to translate. A positive number indicates a translation towards the positive direction of the X axis, and a negative number indicates a translation towards the negative direction of the X axis. The value is a floating point number.|
| float dy | Vertical distance to translate. A positive number indicates a translation towards the positive direction of the Y axis, and a negative number indicates a translation towards the negative direction of the Y axis. The value is a floating point number.|

### OH_Drawing_MatrixPostRotate()

```
void OH_Drawing_MatrixPostRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)
```

**Description**

Post multiplies this matrix by a matrix that is derived from an identity matrix after it has been rotated by a given degree around the rotation point (px, py).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float degree | Angle to rotate, in degrees. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation.|
| float px | X coordinate of the rotation point.|
| float py | Y coordinate of the rotation point.|

### OH_Drawing_MatrixPostScale()

```
void OH_Drawing_MatrixPostScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)
```

**Description**

Post multiplies a matrix by an identity matrix that scales with the factor (sx, sy) at the scale point (px, py).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float sx | Scale factor on the X axis. If a negative number is passed in, the matrix is mirrored around y = px before being scaled. The value is a floating point number.|
| float sy | Scale factor on the Y axis. If a negative number is passed in, the matrix is mirrored around x = py before being scaled. The value is a floating point number.|
| float px | X coordinate of the scale point.|
| float py | Y coordinate of the scale point.|

### OH_Drawing_MatrixPostTranslate()

```
void OH_Drawing_MatrixPostTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)
```

**Description**

Post multiplies this matrix by a matrix that is derived from an identity matrix after it has been translated by a given distance (dx, dy).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float dx | Horizontal distance to translate. A positive number indicates a translation towards the positive direction of the X axis, and a negative number indicates a translation towards the negative direction of the X axis. The value is a floating point number.|
| float dy | Vertical distance to translate. A positive number indicates a translation towards the positive direction of the Y axis, and a negative number indicates a translation towards the negative direction of the Y axis. The value is a floating point number.|

### OH_Drawing_MatrixReset()

```
void OH_Drawing_MatrixReset(OH_Drawing_Matrix* matrix)
```

**Description**

Resets a matrix to an identity matrix.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|

### OH_Drawing_MatrixConcat()

```
void OH_Drawing_MatrixConcat(OH_Drawing_Matrix* total, const OH_Drawing_Matrix* a,const OH_Drawing_Matrix* b)
```

**Description**

Multiplies two matrices to produce a new matrix.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **total**, **a**, and **b** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* total | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* a | Pointer to [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object a.|
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* b | Pointer to [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object b.|

### OH_Drawing_MatrixGetAll()

```
OH_Drawing_ErrorCode OH_Drawing_MatrixGetAll(OH_Drawing_Matrix* matrix, float value[9])
```

**Description**

Obtains all element values of a matrix.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| value |  Array used to store the obtained element values.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | Returns an execution result.<br> **OH_DRAWING_SUCCESS** if all element values of the matrix are successfully obtained.<br> **OH_DRAWING_ERROR_INVALID_PARAMETER** if the matrix element values fail to be obtained. The failure cause is that **matrix** or **value** is NULL.|

### OH_Drawing_MatrixGetValue()

```
float OH_Drawing_MatrixGetValue(OH_Drawing_Matrix* matrix, int index)
```

**Description**

Obtains a matrix value of a given index, which ranges from 0 to 8.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **index** is less than 0 or greater than 8, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| int index | Index, which ranges from 0 to 8.|

**Return value**

| Type| Description|
| -- | -- |
| float | Returns the matrix value.|

### OH_Drawing_MatrixRotate()

```
void OH_Drawing_MatrixRotate(OH_Drawing_Matrix* matrix, float degree, float px, float py)
```

**Description**

Sets this matrix as an identity matrix and rotates it by a given degree around the rotation point (px, py).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float degree | Angle to rotate, in degrees. A positive value indicates a clockwise rotation, and a negative value indicates a counterclockwise rotation.|
| float px | Coordinate point on the X axis.|
| float py | Coordinate point on the Y axis.|

### OH_Drawing_MatrixTranslate()

```
void OH_Drawing_MatrixTranslate(OH_Drawing_Matrix* matrix, float dx, float dy)
```

**Description**

Sets a matrix as an identity matrix and translates it by a given distance (dx, dy).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float dx | Distance to translate on the X axis. A positive number indicates a translation towards the positive direction of the X axis, and a negative number indicates a translation towards the negative direction of the X axis. The value is a floating point number.|
| float dy | Distance to translate on the Y axis. A positive number indicates a translation towards the positive direction of the Y axis, and a negative number indicates a translation towards the negative direction of the Y axis. The value is a floating point number.|

### OH_Drawing_MatrixScale()

```
void OH_Drawing_MatrixScale(OH_Drawing_Matrix* matrix, float sx, float sy, float px, float py)
```

**Description**

Sets a matrix as an identity matrix and scales it with the factor (sx, sy) at the rotation point (px, py).<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| float sx | Scale factor on the X axis. If a negative number is passed in, the matrix is mirrored around y = px before being scaled. The value is a floating point number.|
| float sy | Scale factor on the Y axis. If a negative number is passed in, the matrix is mirrored around x = py before being scaled. The value is a floating point number.|
| float px | Coordinate point on the X axis.|
| float py | Coordinate point on the Y axis.|

### OH_Drawing_MatrixInvert()

```
bool OH_Drawing_MatrixInvert(OH_Drawing_Matrix* matrix, OH_Drawing_Matrix* inverse)
```

**Description**

Inverts a matrix and returns the result.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **matrix** or **inverse** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* inverse | Pointer to the inverse [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object. You can call [OH_Drawing_MatrixCreate](capi-drawing-matrix-h.md#oh_drawing_matrixcreate) to create an inverse matrix object.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the matrix is reversible and the passed-in **inverse** is inverted; returns **false** otherwise.|

### OH_Drawing_MatrixSetPolyToPoly()

```
bool OH_Drawing_MatrixSetPolyToPoly(OH_Drawing_Matrix* matrix, const OH_Drawing_Point2D* src,const OH_Drawing_Point2D* dst, uint32_t count)
```

**Description**

Generates a transformation matrix by setting source points and destination points.<br>Both the number of source points and that of destination points must be in the range [0, 4]. This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.<br>If **count** is less than 0 or greater than 4, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| const [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* src | Array of source points. If NULL is passed in, **count** must be 0.|
| const [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* dst | Array of destination points. The number of destination points must be the same as that of source points. If NULL is passed in, **count** must be 0.|
| uint32_t count | Number of source points or destination points. If 0 is passed in, the matrix is set to an identity matrix.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the matrix is generated; returns **false** otherwise.|

### OH_Drawing_MatrixMapPoints()

```
void OH_Drawing_MatrixMapPoints(const OH_Drawing_Matrix* matrix, const OH_Drawing_Point2D* src,OH_Drawing_Point2D* dst, int count)
```

**Description**

Maps a source point array to a destination point array by means of matrix transformation.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **matrix**, **src**, and **dst** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| const [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* src | Array of source points.|
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* dst | Array of destination points. The number of destination points must be the same as that of source points.|
| int count | Number of source points or destination points.|

### OH_Drawing_MatrixMapRect()

```
bool OH_Drawing_MatrixMapRect(const OH_Drawing_Matrix* matrix, const OH_Drawing_Rect* src, OH_Drawing_Rect* dst)
```

**Description**

Maps a rectangle to the smallest rectangle that can enclose the vertices to which the four source vertices are mapped by means of matrix transformation.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of **matrix**, **src**, and **dst** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* src | Source rectangle.|
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* dst | Destination rectangle.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the objects are equal; **false** otherwise.|

### OH_Drawing_MatrixIsEqual()

```
bool OH_Drawing_MatrixIsEqual(OH_Drawing_Matrix* matrix, OH_Drawing_Matrix* other)
```

**Description**

Checks whether two **OH_Drawing_Matrix** objects are equal.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **matrix** or **other** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to one [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* other | Pointer to the other [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the two matrices are equal; returns **false** otherwise.|

### OH_Drawing_MatrixIsIdentity()

```
bool OH_Drawing_MatrixIsIdentity(OH_Drawing_Matrix* matrix)
```

**Description**

Checks whether an **OH_Drawing_Matrix** object is an identity matrix.<br>An identity matrix is as follows: | 1 0 0 || 0 1 0 || 0 0 1 |. This API may return an error code. For details, see [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **matrix** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to the [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the matrix is an identity matrix; returns **false** otherwise.|

### OH_Drawing_MatrixDestroy()

```
void OH_Drawing_MatrixDestroy(OH_Drawing_Matrix* matrix)
```

**Description**

Destroys an **OH_Drawing_Matrix** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | Pointer to an **OH_Drawing_Font** object.|
