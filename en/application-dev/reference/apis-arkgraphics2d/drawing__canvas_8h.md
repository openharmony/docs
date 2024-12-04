# drawing_canvas.h


## Overview

The **drawing_canvas.h** file declares the functions related to the canvas in the drawing module.

By default, the canvas has a black brush with anti-aliasing enabled and without any other style. This brush takes effect only when no brush or pen is proactively set in the canvas.

Canvases that are not set for recording will immediately draw the commands onto the bound bitmap, whereas canvases designated for recording will store the drawing commands for future replay.

**File to include**: &lt;native_drawing/drawing_canvas.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_Drawing_SrcRectConstraint](_drawing.md#oh_drawing_srcrectconstraint)  [OH_Drawing_SrcRectConstraint](_drawing.md#oh_drawing_srcrectconstraint) | Defines an enum for the constraint types of the source rectangle.| 
| typedef enum [OH_Drawing_PointMode](_drawing.md#oh_drawing_pointmode)  [OH_Drawing_PointMode](_drawing.md#oh_drawing_pointmode) | Defines an enum for the modes of drawing multiple points. The modes include discrete points, line segments, and open polygons.| 
| typedef enum [OH_Drawing_VertexMode](_drawing.md#oh_drawing_vertexmode)  [OH_Drawing_VertexMode](_drawing.md#oh_drawing_vertexmode) | Defines an enum for the modes of interpreting the geometry of a given vertex.| 
| typedef enum [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop)  [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) | Defines an enum for the canvas clipping modes.| 
| typedef enum [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) | Defines an enum for the canvas shadow flags.| 

### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_SrcRectConstraint](_drawing.md#oh_drawing_srcrectconstraint) { STRICT_SRC_RECT_CONSTRAINT, FAST_SRC_RECT_CONSTRAINT } | Enumerates the constraint types of the source rectangle.| 
| [OH_Drawing_PointMode](_drawing.md#oh_drawing_pointmode) { POINT_MODE_POINTS, POINT_MODE_LINES, POINT_MODE_POLYGON } | Enumerates the modes of drawing multiple points. The modes include discrete points, line segments, and open polygons.| 
| [OH_Drawing_VertexMode](_drawing.md#oh_drawing_vertexmode) { VERTEX_MODE_TRIANGLES, VERTEX_MODE_TRIANGLESSTRIP, VERTEX_MODE_TRIANGLEFAN } | Enumerates the modes of interpreting the geometry of a given vertex.| 
| [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) { DIFFERENCE, INTERSECT } | Enumerates the canvas clipping modes.| 
| [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) { SHADOW_FLAGS_NONE, SHADOW_FLAGS_TRANSPARENT_OCCLUDER, SHADOW_FLAGS_GEOMETRIC_ONLY, SHADOW_FLAGS_ALL } | Enumerates the canvas shadow flags.| 

### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawSingleCharacter](_drawing.md#oh_drawing_canvasdrawsinglecharacter) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const char \*str, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, float x, float y) | Draws a single character. If the typeface of the current font does not support the character to draw, the system typeface is used to draw the character. |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasClipRegion](_drawing.md#oh_drawing_canvasclipregion) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const [OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp) | Clips a rectangle.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawColor](_drawing.md#oh_drawing_canvasdrawcolor) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, uint32_t color, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) blendMode) | Fills the entire canvas with the specified color and blend mode.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasGetImageInfo](_drawing.md#oh_drawing_canvasgetimageinfo) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*imageInfo) | Obtains the image information of a canvas.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasIsClipEmpty](_drawing.md#oh_drawing_canvasisclipempty) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, bool \*isClipEmpty) | Checks whether the region that can be drawn is empty after cropping.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawPoint](_drawing.md#oh_drawing_canvasdrawpoint) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*point) | Draws a point.| 
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \* [OH_Drawing_CanvasCreate](_drawing.md#oh_drawing_canvascreate) (void) | Creates an **OH_Drawing_Canvas** object.| 
| void [OH_Drawing_CanvasDestroy](_drawing.md#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Destroys an **OH_Drawing_Canvas** object and reclaims the memory occupied by the object.| 
| void [OH_Drawing_CanvasBind](_drawing.md#oh_drawing_canvasbind) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap. (This process is called CPU rendering.) A canvas bound to a bitmap is a non-recording canvas.| 
| void [OH_Drawing_CanvasAttachPen](_drawing.md#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | Attaches a pen to a canvas so that the canvas can use the style and color of the pen to outline a shape.| 
| void [OH_Drawing_CanvasDetachPen](_drawing.md#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Detaches the pen from a canvas so that the canvas can no longer use the style and color of the pen to outline a shape.| 
| void [OH_Drawing_CanvasAttachBrush](_drawing.md#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Attaches a brush to a canvas so that the canvas can use the style and color of the brush to fill in a shape.| 
| void [OH_Drawing_CanvasDetachBrush](_drawing.md#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Detaches the brush from a canvas so that the canvas can no longer use the previously set brush to fill in a shape.| 
| void [OH_Drawing_CanvasSave](_drawing.md#oh_drawing_canvassave) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Saves the current canvas status (canvas matrix) to the top of the stack.| 
| void [OH_Drawing_CanvasSaveLayer](_drawing.md#oh_drawing_canvassavelayer) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Saves the matrix and cropping region, and allocates a bitmap for subsequent drawing. If you call [OH_Drawing_CanvasRestore](_drawing.md#oh_drawing_canvasrestore), the changes made to the matrix and clipping region are discarded, and the bitmap is drawn.| 
| void [OH_Drawing_CanvasRestore](_drawing.md#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Restores the canvas status (canvas matrix) saved on the top of the stack.| 
| uint32_t [OH_Drawing_CanvasGetSaveCount](_drawing.md#oh_drawing_canvasgetsavecount) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Obtains the number of canvas statuses (canvas matrices) saved in the stack.| 
| void [OH_Drawing_CanvasRestoreToCount](_drawing.md#oh_drawing_canvasrestoretocount) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, uint32_t saveCount) | Restores to a given number of canvas statuses (canvas matrices).| 
| void [OH_Drawing_CanvasDrawLine](_drawing.md#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | Draws a line segment.| 
| void [OH_Drawing_CanvasDrawPath](_drawing.md#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | Draws a path.| 
| void [OH_Drawing_CanvasDrawPixelMapRect](_drawing.md#oh_drawing_canvasdrawpixelmaprect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*) | Draws a portion of a pixel map onto a specified area of the canvas.| 
| void [OH_Drawing_CanvasDrawBackground](_drawing.md#oh_drawing_canvasdrawbackground) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | Draws a background filled with a brush.| 
| void [OH_Drawing_CanvasDrawRegion](_drawing.md#oh_drawing_canvasdrawregion) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Region](_drawing.md#oh_drawing_region) \*) | Draws a region.| 
| void [OH_Drawing_CanvasDrawPoints](_drawing.md#oh_drawing_canvasdrawpoints) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_PointMode](_drawing.md#oh_drawing_pointmode) mode, uint32_t count, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*) | Draws multiple points. You can draw a single point, a line segment, or an open polygon.| 
| void [OH_Drawing_CanvasDrawBitmap](_drawing.md#oh_drawing_canvasdrawbitmap) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, float left, float top) | Draws a bitmap. A bitmap, also referred to as a dot matrix image, a pixel map image, or a grid image, includes single points called pixels (image elements).| 
| void [OH_Drawing_CanvasDrawBitmapRect](_drawing.md#oh_drawing_canvasdrawbitmaprect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*) | Draws a portion of a bitmap onto a specified area of the canvas.| 
| void [OH_Drawing_CanvasSetMatrix](_drawing.md#oh_drawing_canvassetmatrix) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Sets the matrix status for a canvas.| 
| void [OH_Drawing_CanvasResetMatrix](_drawing.md#oh_drawing_canvasresetmatrix) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Resets the matrix of a canvas to an identity matrix.| 
| void [OH_Drawing_CanvasDrawImageRectWithSrc](_drawing.md#oh_drawing_canvasdrawimagerectwithsrc) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*, [OH_Drawing_SrcRectConstraint](_drawing.md#oh_drawing_srcrectconstraint)) | Draws a portion of an image onto a specified area of the canvas. The area selected by the source rectangle is scaled and translated to the destination rectangle.| 
| void [OH_Drawing_CanvasDrawImageRect](_drawing.md#oh_drawing_canvasdrawimagerect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*) | Draws an image onto a specified area of the canvas.| 
| void [OH_Drawing_CanvasDrawVertices](_drawing.md#oh_drawing_canvasdrawvertices) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_VertexMode](_drawing.md#oh_drawing_vertexmode) vertexMmode, int32_t vertexCount, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*positions, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*texs, const uint32_t \*colors, int32_t indexCount, const uint16_t \*indices, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) mode) | Draws a triangular grid described by a vertex array.| 
| bool [OH_Drawing_CanvasReadPixels](_drawing.md#oh_drawing_canvasreadpixels) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY) | Copies pixel data from a canvas to a specified address. This function cannot be used for recorded canvases.| 
| bool [OH_Drawing_CanvasReadPixelsToBitmap](_drawing.md#oh_drawing_canvasreadpixelstobitmap) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, int32_t srcX, int32_t srcY) | Copies pixel data from a canvas to an image. This function cannot be used for recorded canvases.| 
| void [OH_Drawing_CanvasDrawRect](_drawing.md#oh_drawing_canvasdrawrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Draws a rectangle.| 
| void [OH_Drawing_CanvasDrawCircle](_drawing.md#oh_drawing_canvasdrawcircle) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*, float radius) | Draws a circle.| 
| void [OH_Drawing_CanvasDrawOval](_drawing.md#oh_drawing_canvasdrawoval) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Draws an oval.| 
| void [OH_Drawing_CanvasDrawArc](_drawing.md#oh_drawing_canvasdrawarc) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float startAngle, float sweepAngle) | Draws an arc.| 
| void [OH_Drawing_CanvasDrawRoundRect](_drawing.md#oh_drawing_canvasdrawroundrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*) | Draws a rounded rectangle.| 
| void [OH_Drawing_CanvasDrawTextBlob](_drawing.md#oh_drawing_canvasdrawtextblob) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*, float x, float y) | Draws a TextBlob. If the typeface used to construct **OH_Drawing_TextBlob** does not support a character, that character will not be drawn.| 
| void [OH_Drawing_CanvasClipRect](_drawing.md#oh_drawing_canvascliprect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | Clips a rectangle.| 
| void [OH_Drawing_CanvasClipRoundRect](_drawing.md#oh_drawing_canvascliproundrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | Clips a rounded rectangle.| 
| void [OH_Drawing_CanvasClipPath](_drawing.md#oh_drawing_canvasclippath) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | Clips a path.| 
| void [OH_Drawing_CanvasRotate](_drawing.md#oh_drawing_canvasrotate) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float degrees, float px, float py) | Rotates a canvas by a given angle. A positive number indicates a clockwise rotation, and a negative number indicates a counterclockwise rotation.| 
| void [OH_Drawing_CanvasTranslate](_drawing.md#oh_drawing_canvastranslate) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float dx, float dy) | Translates a canvas by a given distance.| 
| void [OH_Drawing_CanvasScale](_drawing.md#oh_drawing_canvasscale) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float sx, float sy) | Scales a canvas.| 
| void [OH_Drawing_CanvasSkew](_drawing.md#oh_drawing_canvasskew) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float sx, float sy) | Skews a canvas. This function premultiplies the current canvas matrix by a skew transformation matrix and applies the resulting matrix to the canvas. The skew transformation matrix is as follows: \|1 sx 0\| \|sy 1 0\| \|0 0 1\| | 
| void [OH_Drawing_CanvasClear](_drawing.md#oh_drawing_canvasclear) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, uint32_t color) | Clears a canvas by using a given color.| 
| int32_t [OH_Drawing_CanvasGetWidth](_drawing.md#oh_drawing_canvasgetwidth) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Obtains the canvas width.| 
| int32_t [OH_Drawing_CanvasGetHeight](_drawing.md#oh_drawing_canvasgetheight) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | Obtains the canvas height.| 
| void [OH_Drawing_CanvasGetLocalClipBounds](_drawing.md#oh_drawing_canvasgetlocalclipbounds) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the bounds of the cropping region of a canvas. This function cannot be used for recorded canvases.| 
| void [OH_Drawing_CanvasGetTotalMatrix](_drawing.md#oh_drawing_canvasgettotalmatrix) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Obtains the 3x3 matrix of a canvas.| 
| void [OH_Drawing_CanvasConcatMatrix](_drawing.md#oh_drawing_canvasconcatmatrix) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | Preconcats the existing matrix with the passed-in matrix. The drawing operation triggered before this function is called is not affected.| 
| void [OH_Drawing_CanvasDrawShadow](_drawing.md#oh_drawing_canvasdrawshadow) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) planeParams, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor, [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) flag) | Draws an offset spot shadow and uses a given path to outline the ambient shadow.| 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawRecordCmd](_drawing.md#oh_drawing_canvasdrawrecordcmd) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, [OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) \*recordCmd) | Draws an **OH_Drawing_RecordCmd** object.| 
