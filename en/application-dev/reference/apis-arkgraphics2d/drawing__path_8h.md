# drawing_path.h


## Overview

The **drawing_path.h** file declares the functions related to the path in the drawing module.

**File to include**: &lt;native_drawing/drawing_path.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)  [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection) | Defines an enum for directions of a closed contour.|
| typedef enum [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype)  [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype) | Defines an enum for fill types of a path.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection) { PATH_DIRECTION_CW, PATH_DIRECTION_CCW } | Enumerates the directions of a closed contour.|
| [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype) { PATH_FILL_TYPE_WINDING, PATH_FILL_TYPE_EVEN_ODD, PATH_FILL_TYPE_INVERSE_WINDING, PATH_FILL_TYPE_INVERSE_EVEN_ODD } | Enumerates the fill types of a path.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* [OH_Drawing_PathCreate](_drawing.md#oh_drawing_pathcreate) (void) | Creates an **OH_Drawing_Path** object.|
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* [OH_Drawing_PathCopy](_drawing.md#oh_drawing_pathcopy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Copies an existing [OH_Drawing_Path](_drawing.md#oh_drawing_path) object to create a new one.|
| void [OH_Drawing_PathDestroy](_drawing.md#oh_drawing_pathdestroy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_PathMoveTo](_drawing.md#oh_drawing_pathmoveto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Sets the start point of a path.|
| void [OH_Drawing_PathLineTo](_drawing.md#oh_drawing_pathlineto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Draws a line segment from the last point of a path to the target point.|
| void [OH_Drawing_PathArcTo](_drawing.md#oh_drawing_patharcto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first, and then a start angle and a sweep angle are specified. The arc is a portion of the ellipse defined by the start angle and the sweep angle. By default, a line segment from the last point of the path to the start point of the arc is also added.|
| void [OH_Drawing_PathQuadTo](_drawing.md#oh_drawing_pathquadto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | Draws a quadratic Bezier curve from the last point of a path to the target point.|
| void [OH_Drawing_PathCubicTo](_drawing.md#oh_drawing_pathcubicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | Draws a cubic Bezier curve from the last point of a path to the target point.|
| void [OH_Drawing_PathAddRect](_drawing.md#oh_drawing_pathaddrect) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float left, float top, float right, float bottom, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | Adds a rectangle contour to a path in the specified direction.|
| void [OH_Drawing_PathAddRoundRect](_drawing.md#oh_drawing_pathaddroundrect) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*roundRect, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | Adds a rounded rectangle contour to a path in the specified direction.|
| void [OH_Drawing_PathAddArc](_drawing.md#oh_drawing_pathaddarc) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float startAngle, float sweepAngle) | Adds an arc to a path as the start of a new contour. The arc added is part of the ellipse bounded by oval, from the start angle through the sweep angle, measured in degrees. A positive angle indicates a clockwise sweep, and a negative angle indicates a counterclockwise sweep. If the sweep angle is less than or equal to -360°, or if the sweep angle is greater than or equal to 360° and start angle modulo 90 is nearly zero, an oval instead of an ellipse is added.|
| void [OH_Drawing_PathAddPath](_drawing.md#oh_drawing_pathaddpath) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Adds a copy of src to the path, transformed by matrix.|
| bool [OH_Drawing_PathContains](_drawing.md#oh_drawing_pathcontains) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Checks whether a coordinate point is included in a path.|
| void [OH_Drawing_PathTransform](_drawing.md#oh_drawing_pathtransform) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Transforms the points in a path by matrix.|
| void [OH_Drawing_PathSetFillType](_drawing.md#oh_drawing_pathsetfilltype) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype)) | Sets the fill type for a path.|
| void [OH_Drawing_PathClose](_drawing.md#oh_drawing_pathclose) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Closes a path by drawing a line segment from the current point to the start point of the path.|
| void [OH_Drawing_PathReset](_drawing.md#oh_drawing_pathreset) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Resets path data.|
