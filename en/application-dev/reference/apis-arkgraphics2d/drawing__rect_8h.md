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
| [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \* [OH_Drawing_RectCreate](_drawing.md#oh_drawing_rectcreate) (float left, float top, float right, float bottom) | Creates an **OH_Drawing_Rect** object. | 
| float [OH_Drawing_RectGetHeight](_drawing.md#oh_drawing_rectgetheight) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the height of a rectangle. | 
| float [OH_Drawing_RectGetWidth](_drawing.md#oh_drawing_rectgetwidth) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the width of a rectangle. | 
| float [OH_Drawing_RectGetLeft](_drawing.md#oh_drawing_rectgetleft) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the horizontal coordinate of the upper left corner of a rectangle. | 
| float [OH_Drawing_RectGetTop](_drawing.md#oh_drawing_rectgettop) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the vertical coordinate of the upper left corner of a rectangle. | 
| float [OH_Drawing_RectGetRight](_drawing.md#oh_drawing_rectgetright) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the horizontal coordinate of the lower right corner of a rectangle. | 
| float [OH_Drawing_RectGetBottom](_drawing.md#oh_drawing_rectgetbottom) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the vertical coordinate of the lower right corner of a rectangle. | 
| bool [OH_Drawing_RectIntersect](_drawing.md#oh_drawing_rectintersect) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*other) | Checks whether two rectangles intersect. | 
| void [OH_Drawing_RectSetLeft](_drawing.md#oh_drawing_rectsetleft) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float left) | Sets the horizontal coordinate of the upper left corner of a rectangle. | 
| void [OH_Drawing_RectSetTop](_drawing.md#oh_drawing_rectsettop) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float top) | Sets the vertical coordinate of the upper left corner of a rectangle. | 
| void [OH_Drawing_RectSetRight](_drawing.md#oh_drawing_rectsetright) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float right) | Sets the horizontal coordinate of the lower right corner of a rectangle. | 
| void [OH_Drawing_RectSetBottom](_drawing.md#oh_drawing_rectsetbottom) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float bottom) | Sets the vertical coordinate of the lower right corner of a rectangle. | 
| void [OH_Drawing_RectCopy](_drawing.md#oh_drawing_rectcopy) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*sRect, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dRect) | Copies a source rectangle to create a new one. | 
| void [OH_Drawing_RectDestroy](_drawing.md#oh_drawing_rectdestroy) ([OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Destroys an **OH_Drawing_Rect** object and reclaims the memory occupied by the object. | 
