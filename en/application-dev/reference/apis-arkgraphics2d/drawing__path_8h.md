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
| typedef enum [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)  [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection) | Defines an enum for the directions of a closed contour.| 
| typedef enum [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype)  [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype) | Defines an enum for the fill types of a path.| 
| typedef enum [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode)  [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode) | Defines an enum for the path adding modes.| 
| typedef enum [OH_Drawing_PathOpMode](_drawing.md#oh_drawing_pathopmode)  [OH_Drawing_PathOpMode](_drawing.md#oh_drawing_pathopmode) | Defines an enum for the operation modes available for a path.| 
| typedef enum [OH_Drawing_PathMeasureMatrixFlags](_drawing.md#oh_drawing_pathmeasurematrixflags)  [OH_Drawing_PathMeasureMatrixFlags](_drawing.md#oh_drawing_pathmeasurematrixflags) | Defines an enum for the types of matrix information obtained during path measurement.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection) { PATH_DIRECTION_CW, PATH_DIRECTION_CCW } | Enumerates the directions of a closed contour.| 
| [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype) { PATH_FILL_TYPE_WINDING, PATH_FILL_TYPE_EVEN_ODD, PATH_FILL_TYPE_INVERSE_WINDING, PATH_FILL_TYPE_INVERSE_EVEN_ODD } | Enumerates the fill types of a path.| 
| [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode) { PATH_ADD_MODE_APPEND, PATH_ADD_MODE_EXTEND } | Enumerates the path adding modes.| 
| [OH_Drawing_PathOpMode](_drawing.md#oh_drawing_pathopmode) {<br>PATH_OP_MODE_DIFFERENCE, PATH_OP_MODE_INTERSECT, PATH_OP_MODE_UNION, PATH_OP_MODE_XOR,<br>PATH_OP_MODE_REVERSE_DIFFERENCE<br>} | Enumerates the operation modes available for a path.| 
| [OH_Drawing_PathMeasureMatrixFlags](_drawing.md#oh_drawing_pathmeasurematrixflags) { GET_POSITION_MATRIX, GET_TANGENT_MATRIX, GET_POSITION_AND_TANGENT_MATRIX } | Enumerates the types of matrix information obtained during path measurement.| 

### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_PathGetSegment](_drawing.md#oh_drawing_pathgetsegment) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, bool forceClosed, float start, float stop, bool startWithMoveTo, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*dst, bool \*result) | Extracts a segment of a path and appends it to a destination path. | 
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* [OH_Drawing_PathCreate](_drawing.md#oh_drawing_pathcreate) (void) | Creates an **OH_Drawing_Path** object.| 
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* [OH_Drawing_PathCopy](_drawing.md#oh_drawing_pathcopy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Copies an existing [OH_Drawing_Path](_drawing.md#oh_drawing_path) object to create a new one.| 
| void [OH_Drawing_PathDestroy](_drawing.md#oh_drawing_pathdestroy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_PathMoveTo](_drawing.md#oh_drawing_pathmoveto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Sets the start point of a path.| 
| void [OH_Drawing_PathLineTo](_drawing.md#oh_drawing_pathlineto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Draws a line segment from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathArcTo](_drawing.md#oh_drawing_patharcto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle is specified first, and then a start angle and a sweep angle are specified. The inscribed ellipse of the rectangle will be used to intercept the arc. The arc is a portion of the ellipse defined by the start angle and the sweep angle. If the path is empty, a line segment from the last point of the path to the start point of the arc is also added.| 
| void [OH_Drawing_PathQuadTo](_drawing.md#oh_drawing_pathquadto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | Draws a quadratic Bezier curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathConicTo](_drawing.md#oh_drawing_pathconicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY, float weight) | Draws a conic curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathCubicTo](_drawing.md#oh_drawing_pathcubicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | Draws a cubic Bezier curve from the last point of a path to the target point. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathRMoveTo](_drawing.md#oh_drawing_pathrmoveto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Sets the start position relative to the last point of a path. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathRLineTo](_drawing.md#oh_drawing_pathrlineto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Draws a line segment from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathRQuadTo](_drawing.md#oh_drawing_pathrquadto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | Draws a quadratic Bezier curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathRConicTo](_drawing.md#oh_drawing_pathrconicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY, float weight) | Draws a conic curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathRCubicTo](_drawing.md#oh_drawing_pathrcubicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | Draws a cubic Bezier curve from the last point of a path to a point relative to the last point. If the path is empty, the start point (0, 0) is used.| 
| void [OH_Drawing_PathAddRect](_drawing.md#oh_drawing_pathaddrect) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float left, float top, float right, float bottom, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | Adds a rectangle contour to a path in the specified direction.| 
| void [OH_Drawing_PathAddRectWithInitialCorner](_drawing.md#oh_drawing_pathaddrectwithinitialcorner) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection), uint32_t start) | Adds a rectangle contour to a path in the specified direction.| 
| void [OH_Drawing_PathAddRoundRect](_drawing.md#oh_drawing_pathaddroundrect) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*roundRect, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | Adds a rounded rectangle contour to a path in the specified direction.| 
| void [OH_Drawing_PathAddOvalWithInitialPoint](_drawing.md#oh_drawing_pathaddovalwithinitialpoint) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, uint32_t start, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | Adds an oval to a path. **OH_Drawing_Rect** specifies the outer tangent rectangle of the oval, and **OH_Drawing_PathDirection** specifies whether the drawing is clockwise or anticlockwise.| 
| void [OH_Drawing_PathAddArc](_drawing.md#oh_drawing_pathaddarc) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float startAngle, float sweepAngle) | Adds an arc to a path as the start of a new contour. The arc added is part of the inscribed ellipse of the rectangle, from the start angle through the sweep angle. If the sweep angle is less than or equal to -360°, or if the sweep angle is greater than or equal to 360°, and start angle modulo 90 is nearly zero, an oval instead of an ellipse is added.| 
| void [OH_Drawing_PathAddPath](_drawing.md#oh_drawing_pathaddpath) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Transforms the points in a **src** path by a matrix and adds the new one to the current path.| 
| void [OH_Drawing_PathAddPathWithMatrixAndMode](_drawing.md#oh_drawing_pathaddpathwithmatrixandmode) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode)) | Transforms the points in a **src** path by a matrix and adds the new one to the current path with the specified adding mode.| 
| void [OH_Drawing_PathAddPathWithMode](_drawing.md#oh_drawing_pathaddpathwithmode) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode)) | Adds a **src** path to the current path with the specified adding mode.| 
| void [OH_Drawing_PathAddPathWithOffsetAndMode](_drawing.md#oh_drawing_pathaddpathwithoffsetandmode) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, float dx, float dy, [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode)) | Translates a **src** path by an offset and adds the new one to the current path with the specified adding mode.| 
| void [OH_Drawing_PathAddOval](_drawing.md#oh_drawing_pathaddoval) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | Adds an oval to a path in the specified direction.| 
| bool [OH_Drawing_PathContains](_drawing.md#oh_drawing_pathcontains) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | Checks whether a coordinate point is included in this path. For details, see [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype-1).| 
| void [OH_Drawing_PathTransform](_drawing.md#oh_drawing_pathtransform) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Transforms the points in a path by a matrix.| 
| void [OH_Drawing_PathTransformWithPerspectiveClip](_drawing.md#oh_drawing_pathtransformwithperspectiveclip) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*dst, bool applyPerspectiveClip) | Transforms the points in a **src** path by a matrix and uses the new one to replace the **dst** path. If **dst** is NULL, the **src** path is replaced.| 
| void [OH_Drawing_PathSetFillType](_drawing.md#oh_drawing_pathsetfilltype) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype)) | Sets the fill type for a path.| 
| float [OH_Drawing_PathGetLength](_drawing.md#oh_drawing_pathgetlength) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, bool forceClosed) | Obtains the length of a path.| 
| void [OH_Drawing_PathClose](_drawing.md#oh_drawing_pathclose) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Closes a path by drawing a line segment from the current point to the start point of the path.| 
| void [OH_Drawing_PathOffset](_drawing.md#oh_drawing_pathoffset) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*dst, float dx, float dy) | Translates a path by an offset along the x axis and y axis and adds the new one to the **dst** path.| 
| void [OH_Drawing_PathReset](_drawing.md#oh_drawing_pathreset) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Resets path data.| 
| void [OH_Drawing_PathAddPolygon](_drawing.md#oh_drawing_pathaddpolygon) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*points, uint32_t count, bool isClosed) | Adds a polygon to a path.| 
| void [OH_Drawing_PathAddCircle](_drawing.md#oh_drawing_pathaddcircle) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, float x, float y, float radius, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | Adds a circle to a path in the specified direction.| 
| bool [OH_Drawing_PathBuildFromSvgString](_drawing.md#oh_drawing_pathbuildfromsvgstring) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const char \*str) | Parses the path represented by an SVG string.| 
| void [OH_Drawing_PathGetBounds](_drawing.md#oh_drawing_pathgetbounds) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the minimum bounds that enclose a path.| 
| bool [OH_Drawing_PathIsClosed](_drawing.md#oh_drawing_pathisclosed) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, bool forceClosed) | Checks whether a path is closed.| 
| bool [OH_Drawing_PathGetPositionTangent](_drawing.md#oh_drawing_pathgetpositiontangent) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, bool forceClosed, float distance, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*position, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*tangent) | Obtains the coordinates and tangent at a distance from the start point of a path.| 
| bool [OH_Drawing_PathOp](_drawing.md#oh_drawing_pathop) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*other, [OH_Drawing_PathOpMode](_drawing.md#oh_drawing_pathopmode) op) | Combines two paths based on the specified operation mode.| 
| bool [OH_Drawing_PathGetMatrix](_drawing.md#oh_drawing_pathgetmatrix) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, bool forceClosed, float distance, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*matrix, [OH_Drawing_PathMeasureMatrixFlags](_drawing.md#oh_drawing_pathmeasurematrixflags) flag) | Obtains a transformation matrix at a distance from the start point of a path.| 
