# drawing_canvas.h


## 概述

文件中定义了与画布相关的功能函数。

画布自带一个黑色，开启抗锯齿，不具备其他任何样式的默认画刷，当且仅当画布中主动设置的画刷和画笔都不存在时生效。

非录制类型画布会将绘制指令直接绘制到绑定的位图中，录制类型画布会将绘制指令录制下来用于后续的回放。

**引用文件：**&lt;native_drawing/drawing_canvas.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_SrcRectConstraint](_drawing.md#oh_drawing_srcrectconstraint)  [OH_Drawing_SrcRectConstraint](_drawing.md#oh_drawing_srcrectconstraint) | 源矩形区域约束类型枚举。 | 
| typedef enum [OH_Drawing_PointMode](_drawing.md#oh_drawing_pointmode)  [OH_Drawing_PointMode](_drawing.md#oh_drawing_pointmode) | 绘制多个点的方式枚举，方式分为离散点、直线或开放多边形。 | 
| typedef enum [OH_Drawing_VertexMode](_drawing.md#oh_drawing_vertexmode)  [OH_Drawing_VertexMode](_drawing.md#oh_drawing_vertexmode) | 用于指定如何解释给定顶点的几何形状的枚举类型。 | 
| typedef enum [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop)  [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) | 画布裁剪方式的枚举集合。 | 
| typedef enum [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) | 阴影标志枚举。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_SrcRectConstraint](_drawing.md#oh_drawing_srcrectconstraint-1) { STRICT_SRC_RECT_CONSTRAINT, FAST_SRC_RECT_CONSTRAINT } | 源矩形区域约束类型枚举。 | 
| [OH_Drawing_PointMode](_drawing.md#oh_drawing_pointmode-1) { POINT_MODE_POINTS, POINT_MODE_LINES, POINT_MODE_POLYGON } | 绘制多个点的方式枚举，方式分为离散点、直线或开放多边形。 | 
| [OH_Drawing_VertexMode](_drawing.md#oh_drawing_vertexmode-1) { VERTEX_MODE_TRIANGLES, VERTEX_MODE_TRIANGLESSTRIP, VERTEX_MODE_TRIANGLEFAN } | 用于指定如何解释给定顶点的几何形状的枚举类型。 | 
| [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop-1) { DIFFERENCE, INTERSECT } | 画布裁剪方式的枚举集合。 | 
| [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags-1) { SHADOW_FLAGS_NONE, SHADOW_FLAGS_TRANSPARENT_OCCLUDER, SHADOW_FLAGS_GEOMETRIC_ONLY, SHADOW_FLAGS_ALL } | 阴影标志枚举。 | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \* [OH_Drawing_CanvasCreate](_drawing.md#oh_drawing_canvascreate) (void) | 用于创建一个画布对象。  | 
| void [OH_Drawing_CanvasDestroy](_drawing.md#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于销毁画布对象并回收该对象占有的内存。  | 
| void [OH_Drawing_CanvasBind](_drawing.md#oh_drawing_canvasbind) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。绑定位图对象后的画布为非录制类型画布。  | 
| void [OH_Drawing_CanvasAttachPen](_drawing.md#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。执行该方法后，若画笔的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。  | 
| void [OH_Drawing_CanvasDetachPen](_drawing.md#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。  | 
| void [OH_Drawing_CanvasAttachBrush](_drawing.md#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。执行该方法后，若画刷的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。  | 
| void [OH_Drawing_CanvasDetachBrush](_drawing.md#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于去除掉画布中的画刷，使用后画布将不使用此前设置的画刷去填充图形形状。  | 
| void [OH_Drawing_CanvasSave](_drawing.md#oh_drawing_canvassave) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于保存当前画布的状态（画布矩阵）到一个栈顶。需要与恢复接口[OH_Drawing_CanvasRestore](_drawing.md#oh_drawing_canvasrestore)配合使用。  | 
| void [OH_Drawing_CanvasSaveLayer](_drawing.md#oh_drawing_canvassavelayer) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 保存矩阵和裁剪区域，为后续绘制分配位图。调用恢复接口。 [OH_Drawing_CanvasRestore](_drawing.md#oh_drawing_canvasrestore)将放弃对矩阵和剪切区域所做的更改，并绘制位图。  | 
| void [OH_Drawing_CanvasRestore](_drawing.md#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于恢复保存在栈顶的画布状态（画布矩阵）。  | 
| uint32_t [OH_Drawing_CanvasGetSaveCount](_drawing.md#oh_drawing_canvasgetsavecount) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于获取栈中保存的画布状态（画布矩阵）的数量。  | 
| void [OH_Drawing_CanvasRestoreToCount](_drawing.md#oh_drawing_canvasrestoretocount) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, uint32_t saveCount) | 用于恢复到指定数量的画布状态（画布矩阵）。  | 
| void [OH_Drawing_CanvasDrawLine](_drawing.md#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | 用于画一条直线段。  | 
| void [OH_Drawing_CanvasDrawPath](_drawing.md#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 用于画一个自定义路径。  | 
| void [OH_Drawing_CanvasDrawPixelMapRect](_drawing.md#oh_drawing_canvasdrawpixelmaprect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*) | 用于将像素图的指定区域绘制到画布的指定区域。  | 
| void [OH_Drawing_CanvasDrawBackground](_drawing.md#oh_drawing_canvasdrawbackground) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 用于画一个背景，此背景以画刷填充。  | 
| void [OH_Drawing_CanvasDrawRegion](_drawing.md#oh_drawing_canvasdrawregion) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Region](_drawing.md#oh_drawing_region) \*) | 用于画一块区域。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawPoint](_drawing.md#oh_drawing_canvasdrawpoint) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*point) | 用于画一个点。  | 
| void [OH_Drawing_CanvasDrawPoints](_drawing.md#oh_drawing_canvasdrawpoints) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_PointMode](_drawing.md#oh_drawing_pointmode) mode, uint32_t count, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*) | 用于画多个点，绘制方式分为绘制单独的点、绘制成线段或绘制成开放多边形。  | 
| void [OH_Drawing_CanvasDrawBitmap](_drawing.md#oh_drawing_canvasdrawbitmap) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, float left, float top) | 用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。  | 
| void [OH_Drawing_CanvasDrawBitmapRect](_drawing.md#oh_drawing_canvasdrawbitmaprect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*) | 将位图的指定区域绘制到画布的指定区域。  | 
| void [OH_Drawing_CanvasSetMatrix](_drawing.md#oh_drawing_canvassetmatrix) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 设置画布的矩阵状态。  | 
| void [OH_Drawing_CanvasResetMatrix](_drawing.md#oh_drawing_canvasresetmatrix) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 重置当前画布的矩阵为单位矩阵。  | 
| void [OH_Drawing_CanvasDrawImageRectWithSrc](_drawing.md#oh_drawing_canvasdrawimagerectwithsrc) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*, [OH_Drawing_SrcRectConstraint](_drawing.md#oh_drawing_srcrectconstraint)) | 将图片绘制到画布的指定区域上，源矩形选定的区域会缩放平移到目标矩形。  | 
| void [OH_Drawing_CanvasDrawImageRect](_drawing.md#oh_drawing_canvasdrawimagerect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Image](_drawing.md#oh_drawing_image) \*, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) \*) | 将图片绘制到画布的指定区域上。  | 
| void [OH_Drawing_CanvasDrawVertices](_drawing.md#oh_drawing_canvasdrawvertices) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_VertexMode](_drawing.md#oh_drawing_vertexmode) vertexMmode, int32_t vertexCount, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*positions, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*texs, const uint32_t \*colors, int32_t indexCount, const uint16_t \*indices, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) mode) | 用于画顶点数组描述的三角网格。  | 
| bool [OH_Drawing_CanvasReadPixels](_drawing.md#oh_drawing_canvasreadpixels) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY) | 从画布中拷贝像素数据到指定地址。该接口不可用于录制类型画布。  | 
| bool [OH_Drawing_CanvasReadPixelsToBitmap](_drawing.md#oh_drawing_canvasreadpixelstobitmap) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, int32_t srcX, int32_t srcY) | 从画布拷贝像素数据到位图中。该接口不可用于录制类型画布。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasIsClipEmpty](_drawing.md#oh_drawing_canvasisclipempty) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, bool \*isClipEmpty) | 用于判断裁剪后可绘制区域是否为空。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasGetImageInfo](_drawing.md#oh_drawing_canvasgetimageinfo) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*imageInfo) | 用于获取画布的图像信息。  | 
| void [OH_Drawing_CanvasDrawRect](_drawing.md#oh_drawing_canvasdrawrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于画一个矩形。  | 
| void [OH_Drawing_CanvasDrawCircle](_drawing.md#oh_drawing_canvasdrawcircle) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*, float radius) | 用于画一个圆形。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawColor](_drawing.md#oh_drawing_canvasdrawcolor) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, uint32_t color, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) blendMode) | 用于使用指定的颜色及混合模式来填充整个画布。  | 
| void [OH_Drawing_CanvasDrawOval](_drawing.md#oh_drawing_canvasdrawoval) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于画一个椭圆。  | 
| void [OH_Drawing_CanvasDrawArc](_drawing.md#oh_drawing_canvasdrawarc) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float startAngle, float sweepAngle) | 用于画一个弧。当扫描角度的绝对值大于360度时，本接口绘制的是一个椭圆。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawArcWithCenter](_drawing.md#oh_drawing_canvasdrawarcwithcenter) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, float startAngle, float sweepAngle, bool useCenter) | 绘制一段圆弧。该方法允许指定圆弧的起始角度、扫描角度以及圆弧的起点和终点是否连接圆弧的中心点。  | 
| void [OH_Drawing_CanvasDrawRoundRect](_drawing.md#oh_drawing_canvasdrawroundrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*) | 用于画一个圆角矩形。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawNestedRoundRect](_drawing.md#oh_drawing_canvasdrawnestedroundrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*outer, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*inner) | 绘制两个嵌套的圆角矩形，外部矩形边界必须包含内部矩形边界，否则无绘制效果。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawSingleCharacter](_drawing.md#oh_drawing_canvasdrawsinglecharacter) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const char \*str, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*font, float x, float y) | 用于绘制单个字符。当前字型中的字体不支持待绘制字符时，退化到使用系统字体绘制字符。  | 
| void [OH_Drawing_CanvasDrawTextBlob](_drawing.md#oh_drawing_canvasdrawtextblob) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*, float x, float y) | 用于画一段文字。若构造OH_Drawing_TextBlob的字体不支持待绘制字符，则该部分字符无法绘制。  | 
| enum  [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) { [SHADOW_FLAGS_NONE](_drawing.md), [SHADOW_FLAGS_TRANSPARENT_OCCLUDER](_drawing.md), [SHADOW_FLAGS_GEOMETRIC_ONLY](_drawing.md), [SHADOW_FLAGS_ALL](_drawing.md) } | 阴影标志枚举。  | 
| typedef enum [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) | 阴影标志枚举。  | 
| void [OH_Drawing_CanvasClipRect](_drawing.md#oh_drawing_canvascliprect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个矩形。  | 
| void [OH_Drawing_CanvasClipRoundRect](_drawing.md#oh_drawing_canvascliproundrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个圆角矩形。  | 
| void [OH_Drawing_CanvasClipPath](_drawing.md#oh_drawing_canvasclippath) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个自定义路径。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasClipRegion](_drawing.md#oh_drawing_canvasclipregion) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const [OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp) | 用于裁剪一个区域。  | 
| void [OH_Drawing_CanvasRotate](_drawing.md#oh_drawing_canvasrotate) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float degrees, float px, float py) | 用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。  | 
| void [OH_Drawing_CanvasTranslate](_drawing.md#oh_drawing_canvastranslate) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float dx, float dy) | 用于平移画布一段距离。  | 
| void [OH_Drawing_CanvasScale](_drawing.md#oh_drawing_canvasscale) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float sx, float sy) | 用于画布缩放。  | 
| void [OH_Drawing_CanvasSkew](_drawing.md#oh_drawing_canvasskew) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float sx, float sy) | 用于画布倾斜变换。等同于将当前画布矩阵左乘（premultiply）倾斜变换矩阵，并应用到画布上。其中倾斜变换矩阵为： \|1 sx 0\| \|sy 1 0\| \|0 0 1\|。  | 
| void [OH_Drawing_CanvasClear](_drawing.md#oh_drawing_canvasclear) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, uint32_t color) | 用于使用指定颜色去清空画布。  | 
| int32_t [OH_Drawing_CanvasGetWidth](_drawing.md#oh_drawing_canvasgetwidth) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 获取画布宽度。  | 
| int32_t [OH_Drawing_CanvasGetHeight](_drawing.md#oh_drawing_canvasgetheight) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 获取画布高度。  | 
| void [OH_Drawing_CanvasGetLocalClipBounds](_drawing.md#oh_drawing_canvasgetlocalclipbounds) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 获取画布裁剪区域的边界。该接口不可用于录制类型画布。  | 
| void [OH_Drawing_CanvasGetTotalMatrix](_drawing.md#oh_drawing_canvasgettotalmatrix) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 获取画布3x3矩阵。  | 
| void [OH_Drawing_CanvasConcatMatrix](_drawing.md#oh_drawing_canvasconcatmatrix) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 画布现有矩阵左乘以传入矩阵，不影响该接口之前的绘制操作。  | 
| void [OH_Drawing_CanvasDrawShadow](_drawing.md#oh_drawing_canvasdrawshadow) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) planeParams, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor, [OH_Drawing_CanvasShadowFlags](_drawing.md#oh_drawing_canvasshadowflags) flag) | 绘制射灯类型阴影，使用路径描述环境光阴影的轮廓。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawRecordCmd](_drawing.md#oh_drawing_canvasdrawrecordcmd) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, [OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) \*recordCmd) | 用于绘制录制指令对象。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasQuickRejectPath](_drawing.md#oh_drawing_canvasquickrejectpath) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, bool \*quickReject) | 判断路径与画布区域是否不相交。画布区域包含边界。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasQuickRejectRect](_drawing.md#oh_drawing_canvasquickrejectrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect, bool \*quickReject) | 判断矩形和画布区域是否不相交。画布区域包含边界。  | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_CanvasDrawPixelMapNine](_drawing.md#oh_drawing_canvasdrawpixelmapnine) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*canvas, [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \*pixelMap, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*center, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, [OH_Drawing_FilterMode](_drawing.md#oh_drawing_filtermode) mode) | 通过绘制两条水平线和两条垂直线将像素图分割成9个部分：四个边，四个角和中心。 若角落的4个区域尺寸不超过目标矩形，则会在不缩放的情况下被绘制在目标矩形，反之则会按比例缩放绘制在目标矩形。 如果还有剩余空间，剩下的5个区域会通过拉伸或压缩来绘制，以便能够完全覆盖目标矩形。  | 

<!--RP1-->
## 相关实例

针对Drawing(C/C++)的开发，有以下相关实例可供参考：

- [NDKAPIDrawing (API14)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKAPIDrawing)
<!--RP1End-->