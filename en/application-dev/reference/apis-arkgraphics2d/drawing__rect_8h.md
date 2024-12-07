# drawing_rect.h


## Overview

The **drawing_rect.h** file declares the functions related to the rectangle in the drawing module.

**File to include**: <native_drawing/drawing_rect.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \* [OH_Drawing_RectCreate](_drawing.md#oh_drawing_rectcreate) (float left, float top, float right, float bottom) | Creates an **OH_Drawing_Rect** object, without sorting the coordinates passed in. This means that the coordinates of the upper left corner of the rectangle can be greater than those of the lower right corner. | 
| float [OH_Drawing_RectGetHeight](_drawing.md#oh_drawing_rectgetheight) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the height of a rectangle. The height is calculated by using the Y coordinate of the lower right corner of the rectangle minus the Y coordinate of the upper left corner. | 
| float [OH_Drawing_RectGetWidth](_drawing.md#oh_drawing_rectgetwidth) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the width of a rectangle. The width is calculated by using the X coordinate of the lower right corner of the rectangle minus the X coordinate of the upper left corner. | 
| float [OH_Drawing_RectGetLeft](_drawing.md#oh_drawing_rectgetleft) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the X coordinate of the upper left corner of a rectangle. | 
| float [OH_Drawing_RectGetTop](_drawing.md#oh_drawing_rectgettop) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the Y coordinate of the upper left corner of a rectangle. | 
| float [OH_Drawing_RectGetRight](_drawing.md#oh_drawing_rectgetright) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the X coordinate of the lower right corner of a rectangle. | 
| float [OH_Drawing_RectGetBottom](_drawing.md#oh_drawing_rectgetbottom) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the Y coordinate of the lower right corner of a rectangle. | 
| bool [OH_Drawing_RectIntersect](_drawing.md#oh_drawing_rectintersect) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*other) | Checks whether two rectangles intersect and if yes, sets **rect** to the area of intersection. | 
| bool [OH_Drawing_RectJoin](_drawing.md#oh_drawing_rectjoin) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*other) | Obtains the union of two rectangles.| 
| void [OH_Drawing_RectSetLeft](_drawing.md#oh_drawing_rectsetleft) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float left) | Sets the X coordinate of the upper left corner of a rectangle. | 
| void [OH_Drawing_RectSetTop](_drawing.md#oh_drawing_rectsettop) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float top) | Sets the Y coordinate of the upper left corner of a rectangle. | 
| void [OH_Drawing_RectSetRight](_drawing.md#oh_drawing_rectsetright) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float right) | Sets the X coordinate of the lower right corner of a rectangle. | 
| void [OH_Drawing_RectSetBottom](_drawing.md#oh_drawing_rectsetbottom) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float bottom) | Sets the Y coordinate of the lower right corner of a rectangle. | 
| void [OH_Drawing_RectCopy](_drawing.md#oh_drawing_rectcopy) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*sRect, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dRect) | Copies a source rectangle to create a new one. | 
| void [OH_Drawing_RectDestroy](_drawing.md#oh_drawing_rectdestroy) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Destroys an **OH_Drawing_Rect** object and reclaims the memory occupied by the object. | 
| [OH_Drawing_Array](_drawing.md#oh_drawing_array) \* [OH_Drawing_RectCreateArray](_drawing.md#oh_drawing_rectcreatearray) (size_t size) | Creates a rectangle array object to store multiple rectangle objects. | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RectGetArraySize](_drawing.md#oh_drawing_rectgetarraysize) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*rectArray, size_t \*pSize) | Obtains the size of a rectangle array, which is an [OH_Drawing_Array](_drawing.md#oh_drawing_array) object. | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RectGetArrayElement](_drawing.md#oh_drawing_rectgetarrayelement) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*rectArray, size_t index, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*\*rect) | Obtains the rectangle with the specified index in a rectangle array. | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_RectDestroyArray](_drawing.md#oh_drawing_rectdestroyarray) ([OH_Drawing_Array](_drawing.md#oh_drawing_array) \*rectArray) | Destroys an **OH_Drawing_Array** object and reclaims the memory occupied by the object. | 
