# drawing_canvas.h


## 概述

文件中定义了与画布相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_canvas.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) {<br/>DIFFERENCE, INTERSECT<br/>} | 画布裁剪方式的枚举集合。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \* [OH_Drawing_CanvasCreate](_drawing.md#oh_drawing_canvascreate) (void) | 用于创建一个画布对象。 |
| void [OH_Drawing_CanvasDestroy](_drawing.md#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于销毁画布对象并回收该对象占有的内存。 |
| void [OH_Drawing_CanvasBind](_drawing.md#oh_drawing_canvasbind) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | 用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。 |
| void [OH_Drawing_CanvasAttachPen](_drawing.md#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) \*) | 用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。 |
| void [OH_Drawing_CanvasDetachPen](_drawing.md#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。 |
| void [OH_Drawing_CanvasAttachBrush](_drawing.md#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) \*) | 用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。 |
| void [OH_Drawing_CanvasDetachBrush](_drawing.md#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于去除掉画布中的画刷，使用后画布将不去填充图形形状。 |
| void [OH_Drawing_CanvasSave](_drawing.md#oh_drawing_canvassave) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于保存当前画布的状态（画布矩阵）到一个栈顶。 |
| void [OH_Drawing_CanvasRestore](_drawing.md#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于恢复保存在栈顶的画布状态（画布矩阵）。 |
| uint32_t [OH_Drawing_CanvasGetSaveCount](_drawing.md#oh_drawing_canvasgetsavecount) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*) | 用于获取栈中保存的画布状态（画布矩阵）的数量。 |
| void [OH_Drawing_CanvasRestoreToCount](_drawing.md#oh_drawing_canvasrestoretocount) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, uint32_t saveCount) | 用于恢复到指定数量的画布状态（画布矩阵）。 |
| void [OH_Drawing_CanvasDrawLine](_drawing.md#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | 用于画一条直线段。 |
| void [OH_Drawing_CanvasDrawPath](_drawing.md#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 用于画一个自定义路径。 |
| void [OH_Drawing_CanvasDrawBitmap](_drawing.md#oh_drawing_canvasdrawbitmap) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, float left, float top) | 用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。 |
| void [OH_Drawing_CanvasDrawRect](_drawing.md#oh_drawing_canvasdrawrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于画一个矩形。 |
| void [OH_Drawing_CanvasDrawCircle](_drawing.md#oh_drawing_canvasdrawcircle) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*, float radius) | 用于画一个圆形。 |
| void [OH_Drawing_CanvasDrawOval](_drawing.md#oh_drawing_canvasdrawoval) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 用于画一个椭圆。 |
| void [OH_Drawing_CanvasDrawArc](_drawing.md#oh_drawing_canvasdrawarc) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float startAngle, float sweepAngle) | 用于画一个弧。 |
| void [OH_Drawing_CanvasDrawRoundRect](_drawing.md#oh_drawing_canvasdrawroundrect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*) | 用于画一个圆角矩形。 |
| void [OH_Drawing_CanvasDrawTextBlob](_drawing.md#oh_drawing_canvasdrawtextblob) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*, float x, float y) | 用于画一段文字。 |
| void [OH_Drawing_CanvasClipRect](_drawing.md#oh_drawing_canvascliprect) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个矩形。 |
| void [OH_Drawing_CanvasClipPath](_drawing.md#oh_drawing_canvasclippath) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_CanvasClipOp](_drawing.md#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个自定义路径。 |
| void [OH_Drawing_CanvasRotate](_drawing.md#oh_drawing_canvasrotate) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float degrees, float px, float py) | 用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。 |
| void [OH_Drawing_CanvasTranslate](_drawing.md#oh_drawing_canvastranslate) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float dx, float dy) | 用于平移画布一段距离。 |
| void [OH_Drawing_CanvasScale](_drawing.md#oh_drawing_canvasscale) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, float sx, float sy) | 用于画布缩放。 |
| void [OH_Drawing_CanvasClear](_drawing.md#oh_drawing_canvasclear) ([OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) \*, uint32_t color) | 用于使用指定颜色去清空画布。 |
