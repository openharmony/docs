# drawing_path.h


## Overview

Declares functions related to the **path** object in the drawing module.

**Since:**
8

**Related Modules:**

[Drawing](_drawing.md)


## Summary


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_PathCreate](_drawing.md#oh_drawing_pathcreate) (void) | Creates an **OH_Drawing_Path** object.  | 
| [OH_Drawing_PathDestroy](_drawing.md#oh_drawing_pathdestroy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.  | 
| [OH_Drawing_PathMoveTo](_drawing.md#oh_drawing_pathmoveto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Sets the start point of a path.  | 
| [OH_Drawing_PathLineTo](_drawing.md#oh_drawing_pathlineto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Draws a line segment from the last point of a path to the target point.  | 
| [OH_Drawing_PathArcTo](_drawing.md#oh_drawing_patharcto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first, and then a start angle and a sweep angle are specified. The arc is a portion of the ellipse defined by the start angle and the sweep angle. By default, a line segment from the last point of the path to the start point of the arc is also added.  | 
| [OH_Drawing_PathQuadTo](_drawing.md#oh_drawing_pathquadto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | Draws a quadratic Bezier curve from the last point of a path to the target point.  | 
| [OH_Drawing_PathCubicTo](_drawing.md#oh_drawing_pathcubicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | Draws a cubic Bezier curve from the last point of a path to the target point.  | 
| [OH_Drawing_PathClose](_drawing.md#oh_drawing_pathclose) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Closes a path. A line segment from the start point to the last point of the path is added.  | 
| [OH_Drawing_PathReset](_drawing.md#oh_drawing_pathreset) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Resets path data.  | 
