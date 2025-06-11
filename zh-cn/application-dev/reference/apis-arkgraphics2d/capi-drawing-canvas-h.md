# drawing_canvas.h

## 概述

文件中定义了与画布相关的功能函数。<br>画布自带一个黑色，开启抗锯齿，不具备其他任何样式的默认画刷，当且仅当画布中主动设置的画刷和画笔都不存在时生效。

<!--RP1-->
**相关示例：** [NDKAPIDrawing (API14)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKAPIDrawing)<!--RP1End-->

**引用文件：** <native_drawing/drawing_canvas.h>

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint) | OH_Drawing_SrcRectConstraint | 源矩形区域约束类型枚举。 |
| [OH_Drawing_PointMode](#oh_drawing_pointmode) | OH_Drawing_PointMode | 绘制多个点的方式枚举，方式分为离散点、直线或开放多边形。 |
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) | OH_Drawing_CanvasClipOp | 画布裁剪方式的枚举集合。 |
| [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) | OH_Drawing_CanvasShadowFlags | 阴影标志枚举。 |
| [OH_Drawing_VertexMode](#oh_drawing_vertexmode) | OH_Drawing_VertexMode | 用于指定如何解释给定顶点的几何形状的枚举类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas* OH_Drawing_CanvasCreate(void)](#oh_drawing_canvascreate) | 用于创建一个画布对象。 |
| [OH_Drawing_Canvas* OH_Drawing_CanvasCreateWithPixelMap(OH_Drawing_PixelMap* pixelMap)](#oh_drawing_canvascreatewithpixelmap) | 用于将一个像素图对象绑定到画布中，使得画布绘制的内容输出到像素图中（即CPU渲染）。绑定像素图对象后的画布为非录制类型画布。<br>像素图对象应该在销毁画布对象之后调用[OH_Drawing_PixelMapDissolve](capi-drawing-pixel-map-h.md#oh_drawing_pixelmapdissolve)解除绑定。 |
| [void OH_Drawing_CanvasDestroy(OH_Drawing_Canvas* canvas)](#oh_drawing_canvasdestroy) | 用于销毁画布对象并回收该对象占有的内存。 |
| [void OH_Drawing_CanvasBind(OH_Drawing_Canvas* canvas, OH_Drawing_Bitmap* bitmap)](#oh_drawing_canvasbind) | 用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。绑定位图对象后的画布为非录制类型画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasAttachPen(OH_Drawing_Canvas* canvas, const OH_Drawing_Pen* pen)](#oh_drawing_canvasattachpen) | 用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。执行该方法后，若画笔的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、pen任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDetachPen(OH_Drawing_Canvas* canvas)](#oh_drawing_canvasdetachpen) | 用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasAttachBrush(OH_Drawing_Canvas* canvas, const OH_Drawing_Brush* brush)](#oh_drawing_canvasattachbrush) | 用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。执行该方法后，若画刷的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、brush任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDetachBrush(OH_Drawing_Canvas* canvas)](#oh_drawing_canvasdetachbrush) | 用于去除掉画布中的画刷，使用后画布将不使用此前设置的画刷去填充图形形状。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasSave(OH_Drawing_Canvas* canvas)](#oh_drawing_canvassave) | 用于保存当前画布的状态（画布矩阵）到一个栈顶。需要与恢复接口[OH_Drawing_CanvasRestore](capi-drawing-canvas-h.md#oh_drawing_canvasrestore)配合使用。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasSaveLayer(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect, const OH_Drawing_Brush* brush)](#oh_drawing_canvassavelayer) | 保存矩阵和裁剪区域，为后续绘制分配位图。调用恢复接口。<br>[OH_Drawing_CanvasRestore](capi-drawing-canvas-h.md#oh_drawing_canvasrestore)将放弃对矩阵和剪切区域所做的更改，并绘制位图。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasRestore(OH_Drawing_Canvas* canvas)](#oh_drawing_canvasrestore) | 用于恢复保存在栈顶的画布状态（画布矩阵）。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [uint32_t OH_Drawing_CanvasGetSaveCount(OH_Drawing_Canvas* canvas)](#oh_drawing_canvasgetsavecount) | 用于获取栈中保存的画布状态（画布矩阵）的数量。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasRestoreToCount(OH_Drawing_Canvas* canvas, uint32_t saveCount)](#oh_drawing_canvasrestoretocount) | 用于恢复到指定数量的画布状态（画布矩阵）。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawLine(OH_Drawing_Canvas* canvas, float x1, float y1, float x2, float y2)](#oh_drawing_canvasdrawline) | 用于画一条直线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawPath(OH_Drawing_Canvas* canvas, const OH_Drawing_Path* path)](#oh_drawing_canvasdrawpath) | 用于画一个自定义路径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasDrawPixelMapNine(OH_Drawing_Canvas* canvas, OH_Drawing_PixelMap* pixelMap,const OH_Drawing_Rect* center, const OH_Drawing_Rect* dst, OH_Drawing_FilterMode mode)](#oh_drawing_canvasdrawpixelmapnine) | 通过绘制两条水平线和两条垂直线将像素图分割成9个部分：四个边，四个角和中心。<br>若角落的4个区域尺寸不超过目标矩形，则会在不缩放的情况下被绘制在目标矩形，反之则会按比例缩放绘制在目标矩形。<br>如果还有剩余空间，剩下的5个区域会通过拉伸或压缩来绘制，以便能够完全覆盖目标矩形。 |
| [void OH_Drawing_CanvasDrawPixelMapRect(OH_Drawing_Canvas* canvas, OH_Drawing_PixelMap* pixelMap,const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions* samplingOptions)](#oh_drawing_canvasdrawpixelmaprect) | 用于将像素图的指定区域绘制到画布的指定区域。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、pixelMap、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawBackground(OH_Drawing_Canvas* canvas, const OH_Drawing_Brush* brush)](#oh_drawing_canvasdrawbackground) | 用于画一个背景，此背景以画刷填充。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、brush任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawRegion(OH_Drawing_Canvas* canvas, const OH_Drawing_Region* region)](#oh_drawing_canvasdrawregion) | 用于画一块区域。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、region任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasDrawPoint(OH_Drawing_Canvas* canvas, const OH_Drawing_Point2D* point)](#oh_drawing_canvasdrawpoint) | 用于画一个点。 |
| [void OH_Drawing_CanvasDrawPoints(OH_Drawing_Canvas* canvas, OH_Drawing_PointMode mode,uint32_t count, const OH_Drawing_Point2D* point2D)](#oh_drawing_canvasdrawpoints) | 用于画多个点，绘制方式分为绘制单独的点、绘制成线段或绘制成开放多边形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、point2D任意一个为NULL或者count等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER；mode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_CanvasDrawBitmap(OH_Drawing_Canvas* canvas, const OH_Drawing_Bitmap* bitmap, float left, float top)](#oh_drawing_canvasdrawbitmap) | 用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawBitmapRect(OH_Drawing_Canvas* canvas, const OH_Drawing_Bitmap* bitmap,const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions* samplingOptions)](#oh_drawing_canvasdrawbitmaprect) | 将位图的指定区域绘制到画布的指定区域。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、bitmap、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawRect(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect)](#oh_drawing_canvasdrawrect) | 用于画一个矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawCircle(OH_Drawing_Canvas* canvas, const OH_Drawing_Point* point, float radius)](#oh_drawing_canvasdrawcircle) | 用于画一个圆形。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。canvas、point任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>radius小于等于0时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasDrawColor(OH_Drawing_Canvas* canvas, uint32_t color,OH_Drawing_BlendMode blendMode)](#oh_drawing_canvasdrawcolor) | 用于使用指定的颜色及混合模式来填充整个画布。 |
| [void OH_Drawing_CanvasDrawOval(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect)](#oh_drawing_canvasdrawoval) | 用于画一个椭圆。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。canvas、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawArc(OH_Drawing_Canvas* canvas,const OH_Drawing_Rect* rect, float startAngle, float sweepAngle)](#oh_drawing_canvasdrawarc) | 用于画一个弧。当扫描角度的绝对值大于360度时，本接口绘制的是一个椭圆。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasDrawArcWithCenter(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect,float startAngle, float sweepAngle, bool useCenter)](#oh_drawing_canvasdrawarcwithcenter) | 绘制一段圆弧。该方法允许指定圆弧的起始角度、扫描角度以及圆弧的起点和终点是否连接圆弧的中心点。 |
| [void OH_Drawing_CanvasDrawRoundRect(OH_Drawing_Canvas* canvas, const OH_Drawing_RoundRect* roundRect)](#oh_drawing_canvasdrawroundrect) | 用于画一个圆角矩形。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。canvas、roundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasDrawNestedRoundRect(OH_Drawing_Canvas* canvas, const OH_Drawing_RoundRect* outer,const OH_Drawing_RoundRect* inner)](#oh_drawing_canvasdrawnestedroundrect) | 绘制两个嵌套的圆角矩形，外部矩形边界必须包含内部矩形边界，否则无绘制效果。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasDrawSingleCharacter(OH_Drawing_Canvas* canvas, const char* str,const OH_Drawing_Font* font, float x, float y)](#oh_drawing_canvasdrawsinglecharacter) | 用于绘制单个字符。当前字型中的字体不支持待绘制字符时，退化到使用系统字体绘制字符。 |
| [void OH_Drawing_CanvasDrawTextBlob(OH_Drawing_Canvas* canvas, const OH_Drawing_TextBlob* textBlob, float x, float y)](#oh_drawing_canvasdrawtextblob) | 用于画一段文字。若构造OH_Drawing_TextBlob的字体不支持待绘制字符，则该部分字符无法绘制。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、textBlob任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasClipRect(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect,OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias)](#oh_drawing_canvascliprect) | 用于裁剪一个矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_CanvasClipRoundRect(OH_Drawing_Canvas* canvas, const OH_Drawing_RoundRect* roundRect,OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias)](#oh_drawing_canvascliproundrect) | 用于裁剪一个圆角矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、roundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_CanvasClipPath(OH_Drawing_Canvas* canvas, const OH_Drawing_Path* path,OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias)](#oh_drawing_canvasclippath) | 用于裁剪一个自定义路径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasClipRegion(OH_Drawing_Canvas* canvas, const OH_Drawing_Region* region,OH_Drawing_CanvasClipOp clipOp)](#oh_drawing_canvasclipregion) | 用于裁剪一个区域。 |
| [void OH_Drawing_CanvasRotate(OH_Drawing_Canvas* canvas, float degrees, float px, float py)](#oh_drawing_canvasrotate) | 用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasTranslate(OH_Drawing_Canvas* canvas, float dx, float dy)](#oh_drawing_canvastranslate) | 用于平移画布一段距离。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasScale(OH_Drawing_Canvas* canvas, float sx, float sy)](#oh_drawing_canvasscale) | 用于画布缩放。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasSkew(OH_Drawing_Canvas* canvas, float sx, float sy)](#oh_drawing_canvasskew) | 用于画布倾斜变换。等同于将当前画布矩阵左乘（premultiply）倾斜变换矩阵，并应用到画布上。其中倾斜变换矩阵为：<br>|1 sx 0|  <br>|sy 1 0|  <br>|0  0 1|。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [int32_t OH_Drawing_CanvasGetWidth(OH_Drawing_Canvas* canvas)](#oh_drawing_canvasgetwidth) | 获取画布宽度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [int32_t OH_Drawing_CanvasGetHeight(OH_Drawing_Canvas* canvas)](#oh_drawing_canvasgetheight) | 获取画布高度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasGetLocalClipBounds(OH_Drawing_Canvas* canvas, OH_Drawing_Rect* rect)](#oh_drawing_canvasgetlocalclipbounds) | 获取画布裁剪区域的边界。该接口不可用于录制类型画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasGetTotalMatrix(OH_Drawing_Canvas* canvas, OH_Drawing_Matrix* matrix)](#oh_drawing_canvasgettotalmatrix) | 获取画布3x3矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasConcatMatrix(OH_Drawing_Canvas* canvas, OH_Drawing_Matrix* matrix)](#oh_drawing_canvasconcatmatrix) | 画布现有矩阵左乘以传入矩阵，不影响该接口之前的绘制操作。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawShadow(OH_Drawing_Canvas* canvas, OH_Drawing_Path* path, OH_Drawing_Point3D planeParams,OH_Drawing_Point3D devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor,OH_Drawing_CanvasShadowFlags flag)](#oh_drawing_canvasdrawshadow) | 绘制射灯类型阴影，使用路径描述环境光阴影的轮廓。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>flag不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_CanvasClear(OH_Drawing_Canvas* canvas, uint32_t color)](#oh_drawing_canvasclear) | 用于使用指定颜色去清空画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasSetMatrix(OH_Drawing_Canvas* canvas, OH_Drawing_Matrix* matrix)](#oh_drawing_canvassetmatrix) | 设置画布的矩阵状态。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasResetMatrix(OH_Drawing_Canvas* canvas)](#oh_drawing_canvasresetmatrix) | 重置当前画布的矩阵为单位矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawImageRectWithSrc(OH_Drawing_Canvas* canvas, const OH_Drawing_Image* image,const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions* samplingOptions,OH_Drawing_SrcRectConstraint srcRectConstraint)](#oh_drawing_canvasdrawimagerectwithsrc) | 将图片绘制到画布的指定区域上，源矩形选定的区域会缩放平移到目标矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、image、src、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawImageRect(OH_Drawing_Canvas* canvas, OH_Drawing_Image* image,OH_Drawing_Rect* rect, OH_Drawing_SamplingOptions* samplingOptions)](#oh_drawing_canvasdrawimagerect) | 将图片绘制到画布的指定区域上。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、image、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_CanvasDrawVertices(OH_Drawing_Canvas* canvas, OH_Drawing_VertexMode vertexMmode,int32_t vertexCount, const OH_Drawing_Point2D* positions, const OH_Drawing_Point2D* texs,const uint32_t* colors, int32_t indexCount, const uint16_t* indices, OH_Drawing_BlendMode mode)](#oh_drawing_canvasdrawvertices) | 用于画顶点数组描述的三角网格。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas或positions为NULL、vertexCount值小于3、indexCount值小于3且不为0，存在以上任意一种情况时设置错误码为OH_DRAWING_ERROR_INVALID_PARAMETER；<br>vertexMmode、mode任意一个不在枚举范围内时设置错误码为OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [bool OH_Drawing_CanvasReadPixels(OH_Drawing_Canvas* canvas, OH_Drawing_Image_Info* imageInfo,void* dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY)](#oh_drawing_canvasreadpixels) | 从画布中拷贝像素数据到指定地址。该接口不可用于录制类型画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、imageInfo、dstPixels任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_CanvasReadPixelsToBitmap(OH_Drawing_Canvas* canvas,OH_Drawing_Bitmap* bitmap, int32_t srcX, int32_t srcY)](#oh_drawing_canvasreadpixelstobitmap) | 从画布拷贝像素数据到位图中。该接口不可用于录制类型画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasIsClipEmpty(OH_Drawing_Canvas* canvas, bool* isClipEmpty)](#oh_drawing_canvasisclipempty) | 用于判断裁剪后可绘制区域是否为空。<br> |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasGetImageInfo(OH_Drawing_Canvas* canvas, OH_Drawing_Image_Info* imageInfo)](#oh_drawing_canvasgetimageinfo) | 用于获取画布的图像信息。<br> |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasDrawRecordCmd(OH_Drawing_Canvas* canvas, OH_Drawing_RecordCmd* recordCmd)](#oh_drawing_canvasdrawrecordcmd) | 用于绘制录制指令对象。<br> |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasDrawRecordCmdNesting(OH_Drawing_Canvas* canvas, OH_Drawing_RecordCmd* recordCmd)](#oh_drawing_canvasdrawrecordcmdnesting) | 用于绘制录制指令对象，支持嵌套。<br> 本接口支持[OH_Drawing_RecordCmdUtilsBeginRecording](capi-drawing-record-cmd-h.md#oh_drawing_recordcmdutilsbeginrecording)接口生成的画布对象作为入参，嵌套调用。不建议多层嵌套，会影响性能。 |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasQuickRejectPath(OH_Drawing_Canvas* canvas, const OH_Drawing_Path* path,bool* quickReject)](#oh_drawing_canvasquickrejectpath) | 判断路径与画布区域是否不相交。画布区域包含边界。<br> |
| [OH_Drawing_ErrorCode OH_Drawing_CanvasQuickRejectRect(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect,bool* quickReject)](#oh_drawing_canvasquickrejectrect) | 判断矩形和画布区域是否不相交。画布区域包含边界。<br> |

## 枚举类型说明

### OH_Drawing_SrcRectConstraint

```
enum OH_Drawing_SrcRectConstraint
```

**描述**

源矩形区域约束类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| STRICT_SRC_RECT_CONSTRAINT | 严格约束，源矩形区域必须完全包含在图像中。 |
| FAST_SRC_RECT_CONSTRAINT | 快速约束，源矩形区域可以部分位于图像之外。 |

### OH_Drawing_PointMode

```
enum OH_Drawing_PointMode
```

**描述**

绘制多个点的方式枚举，方式分为离散点、直线或开放多边形。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| POINT_MODE_POINTS | 分别绘制每个点。 |
| POINT_MODE_LINES | 将每两个点绘制为线段。 |
| POINT_MODE_POLYGON | 将点阵列绘制为开放多边形。 |

### OH_Drawing_CanvasClipOp

```
enum OH_Drawing_CanvasClipOp
```

**描述**

画布裁剪方式的枚举集合。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| DIFFERENCE | 将指定区域裁剪（取差集）。 |
| INTERSECT | 将指定区域保留（取交集）。 |

### OH_Drawing_CanvasShadowFlags

```
enum OH_Drawing_CanvasShadowFlags
```

**描述**

阴影标志枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| SHADOW_FLAGS_NONE | 无阴影标志。 |
| SHADOW_FLAGS_TRANSPARENT_OCCLUDER | 遮挡物对象不透明标志。 |
| SHADOW_FLAGS_GEOMETRIC_ONLY | 不分析阴影标志。 |
| SHADOW_FLAGS_ALL | 使能以上所有阴影标志。 |

### OH_Drawing_VertexMode

```
enum OH_Drawing_VertexMode
```

**描述**

用于指定如何解释给定顶点的几何形状的枚举类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| VERTEX_MODE_TRIANGLES | 每三个顶点表示一个三角形，如果顶点数不是3的倍数，则多余的顶点会被忽略。 |
| VERTEX_MODE_TRIANGLESSTRIP | 相邻三个顶点表示一个三角形，每个新的顶点将与前两个顶点组成一个新的三角形。 |
| VERTEX_MODE_TRIANGLEFAN | 第一个顶点作为中心点，后续的每个顶点都与前一个顶点和中心点组成一个三角形。 |


## 函数说明

### OH_Drawing_CanvasDrawRecordCmdNesting()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawRecordCmdNesting(OH_Drawing_Canvas* canvas, OH_Drawing_RecordCmd* recordCmd)
```

**描述**

用于绘制录制指令对象，支持嵌套。

本接口支持[OH_Drawing_RecordCmdUtilsBeginRecording](capi-drawing-record-cmd-h.md#oh_drawing_recordcmdutilsbeginrecording)接口生成的画布对象作为入参，嵌套调用。不建议多层嵌套，会影响性能。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_Drawing_Canvas* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针，仅支持录制类型画布。 |
| OH_Drawing_RecordCmd* recordCmd | 指向录制指令对象[OH_Drawing_RecordCmd](capi-oh-drawing-recordcmd.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行操作码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者recordCmd为空。 |

### OH_Drawing_CanvasCreate()

```
OH_Drawing_Canvas* OH_Drawing_CanvasCreate(void)
```

**描述**

用于创建一个画布对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* | 函数会返回一个指针，指针指向创建的画布对象。 |

### OH_Drawing_CanvasCreateWithPixelMap()

```
OH_Drawing_Canvas* OH_Drawing_CanvasCreateWithPixelMap(OH_Drawing_PixelMap* pixelMap)
```

**描述**

用于将一个像素图对象绑定到画布中，使得画布绘制的内容输出到像素图中（即CPU渲染）。绑定像素图对象后的画布为非录制类型画布。<br>像素图对象应该在销毁画布对象之后调用[OH_Drawing_PixelMapDissolve](capi-drawing-pixel-map-h.md#oh_drawing_pixelmapdissolve)解除绑定。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_PixelMap](capi-oh-drawing-pixelmap.md)* pixelMap | 指向像素图[OH_Drawing_PixelMap](capi-oh-drawing-pixelmap.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* | 函数会返回一个指针，指针指向创建的画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)，如果对象返回为NULL，则创建失败，原因可能是可用内存不足或者像素图对象为空。 |

### OH_Drawing_CanvasDestroy()

```
void OH_Drawing_CanvasDestroy(OH_Drawing_Canvas* canvas)
```

**描述**

用于销毁画布对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |

### OH_Drawing_CanvasBind()

```
void OH_Drawing_CanvasBind(OH_Drawing_Canvas* canvas, OH_Drawing_Bitmap* bitmap)
```

**描述**

用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。绑定位图对象后的画布为非录制类型画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| [OH_Drawing_Bitmap](capi-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |

### OH_Drawing_CanvasAttachPen()

```
void OH_Drawing_CanvasAttachPen(OH_Drawing_Canvas* canvas, const OH_Drawing_Pen* pen)
```

**描述**

用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。执行该方法后，若画笔的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、pen任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Pen](capi-oh-drawing-pen.md)* pen | 指向画笔对象的指针。 |

### OH_Drawing_CanvasDetachPen()

```
void OH_Drawing_CanvasDetachPen(OH_Drawing_Canvas* canvas)
```

**描述**

用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |

### OH_Drawing_CanvasAttachBrush()

```
void OH_Drawing_CanvasAttachBrush(OH_Drawing_Canvas* canvas, const OH_Drawing_Brush* brush)
```

**描述**

用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。执行该方法后，若画刷的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、brush任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Brush](capi-oh-drawing-brush.md)* brush | 指向画刷对象的指针。 |

### OH_Drawing_CanvasDetachBrush()

```
void OH_Drawing_CanvasDetachBrush(OH_Drawing_Canvas* canvas)
```

**描述**

用于去除掉画布中的画刷，使用后画布将不使用此前设置的画刷去填充图形形状。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |

### OH_Drawing_CanvasSave()

```
void OH_Drawing_CanvasSave(OH_Drawing_Canvas* canvas)
```

**描述**

用于保存当前画布的状态（画布矩阵）到一个栈顶。需要与恢复接口[OH_Drawing_CanvasRestore](capi-drawing-canvas-h.md#oh_drawing_canvasrestore)配合使用。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |

### OH_Drawing_CanvasSaveLayer()

```
void OH_Drawing_CanvasSaveLayer(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect, const OH_Drawing_Brush* brush)
```

**描述**

保存矩阵和裁剪区域，为后续绘制分配位图。调用恢复接口。<br>[OH_Drawing_CanvasRestore](capi-drawing-canvas-h.md#oh_drawing_canvasrestore)将放弃对矩阵和剪切区域所做的更改，并绘制位图。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针，用于限制图层大小，为NULL表示无限制。 |
| const [OH_Drawing_Brush](capi-oh-drawing-brush.md)* brush | 指向画刷对象[OH_Drawing_Brush](capi-oh-drawing-brush.md)的指针，绘制位图时会应用画刷对象的透明度，滤波器效果，混合模式，为NULL表示不应用任何效果。 |

### OH_Drawing_CanvasRestore()

```
void OH_Drawing_CanvasRestore(OH_Drawing_Canvas* canvas)
```

**描述**

用于恢复保存在栈顶的画布状态（画布矩阵）。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |

### OH_Drawing_CanvasGetSaveCount()

```
uint32_t OH_Drawing_CanvasGetSaveCount(OH_Drawing_Canvas* canvas)
```

**描述**

用于获取栈中保存的画布状态（画布矩阵）的数量。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 函数会返回一个32位的值描述画布状态（画布矩阵）的数量，画布初始状态数量为1。 |

### OH_Drawing_CanvasRestoreToCount()

```
void OH_Drawing_CanvasRestoreToCount(OH_Drawing_Canvas* canvas, uint32_t saveCount)
```

**描述**

用于恢复到指定数量的画布状态（画布矩阵）。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| uint32_t saveCount | 要恢复的画布状态深度。小于等于1时，恢复为初始状态；大于已保存的画布状态数量时，不执行任何操作。 |

### OH_Drawing_CanvasDrawLine()

```
void OH_Drawing_CanvasDrawLine(OH_Drawing_Canvas* canvas, float x1, float y1, float x2, float y2)
```

**描述**

用于画一条直线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| float x1 | 线段起始点的横坐标。 |
| float y1 | 线段起始点的纵坐标。 |
| float x2 | 线段结束点的横坐标。 |
| float y2 | 线段结束点的纵坐标。 |

### OH_Drawing_CanvasDrawPath()

```
void OH_Drawing_CanvasDrawPath(OH_Drawing_Canvas* canvas, const OH_Drawing_Path* path)
```

**描述**

用于画一个自定义路径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Path](capi-oh-drawing-path.md)* path | 指向路径对象的指针。 |

### OH_Drawing_CanvasDrawPixelMapNine()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawPixelMapNine(OH_Drawing_Canvas* canvas, OH_Drawing_PixelMap* pixelMap,const OH_Drawing_Rect* center, const OH_Drawing_Rect* dst, OH_Drawing_FilterMode mode)
```

**描述**

通过绘制两条水平线和两条垂直线将像素图分割成9个部分：四个边，四个角和中心。<br>若角落的4个区域尺寸不超过目标矩形，则会在不缩放的情况下被绘制在目标矩形，反之则会按比例缩放绘制在目标矩形。<br>如果还有剩余空间，剩下的5个区域会通过拉伸或压缩来绘制，以便能够完全覆盖目标矩形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_PixelMap](capi-oh-drawing-pixelmap.md)* pixelMap | 指向像素图[OH_Drawing_PixelMap](capi-oh-drawing-pixelmap.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* center | 指向矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针，表示分割像素图的中心矩形。矩形四条边所在的直线将像素图分成了9个部分。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* dst | 指向矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针，表示画布上的目标区域。 |
| [OH_Drawing_FilterMode](capi-drawing-sampling-options-h.md#oh_drawing_filtermode) mode | 过滤模式枚举[OH_Drawing_FilterMode](capi-drawing-sampling-options-h.md#oh_drawing_filtermode)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、pixelMap或dst为空。 |

### OH_Drawing_CanvasDrawPixelMapRect()

```
void OH_Drawing_CanvasDrawPixelMapRect(OH_Drawing_Canvas* canvas, OH_Drawing_PixelMap* pixelMap,const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions* samplingOptions)
```

**描述**

用于将像素图的指定区域绘制到画布的指定区域。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、pixelMap、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_PixelMap](capi-oh-drawing-pixelmap.md)* pixelMap | 指向像素图[OH_Drawing_PixelMap](capi-oh-drawing-pixelmap.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* src | 像素图指定矩形区域，为NULL将指定整个像素图区域。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* dst | 目标画布指定矩形区域。 |
| const [OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)* samplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)的指针，为NULL将使用默认采样选项。 |

### OH_Drawing_CanvasDrawBackground()

```
void OH_Drawing_CanvasDrawBackground(OH_Drawing_Canvas* canvas, const OH_Drawing_Brush* brush)
```

**描述**

用于画一个背景，此背景以画刷填充。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、brush任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Brush](capi-oh-drawing-brush.md)* brush | 指向画刷对象的指针。 |

### OH_Drawing_CanvasDrawRegion()

```
void OH_Drawing_CanvasDrawRegion(OH_Drawing_Canvas* canvas, const OH_Drawing_Region* region)
```

**描述**

用于画一块区域。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、region任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Region](capi-oh-drawing-region.md)* region | 指向区域对象的指针。 |

### OH_Drawing_CanvasDrawPoint()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawPoint(OH_Drawing_Canvas* canvas, const OH_Drawing_Point2D* point)
```

**描述**

用于画一个点。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_Point2D](capi-oh-drawing-point2d.md)* point | 指向点对象[OH_Drawing_Point2D](capi-oh-drawing-point2d.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者point为空。 |

### OH_Drawing_CanvasDrawPoints()

```
void OH_Drawing_CanvasDrawPoints(OH_Drawing_Canvas* canvas, OH_Drawing_PointMode mode,uint32_t count, const OH_Drawing_Point2D* point2D)
```

**描述**

用于画多个点，绘制方式分为绘制单独的点、绘制成线段或绘制成开放多边形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、point2D任意一个为NULL或者count等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER；mode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| [OH_Drawing_PointMode](#oh_drawing_pointmode) mode | 绘制多个点的方式，支持方式参考[OH_Drawing_PointMode](capi-drawing-canvas-h.md#oh_drawing_pointmode)。 |
| uint32_t count | 点的数量，即点数组中点的个数。 |
| const [OH_Drawing_Point2D](capi-oh-drawing-point2d.md)* point2D | 指向多个点的数组。 |

### OH_Drawing_CanvasDrawBitmap()

```
void OH_Drawing_CanvasDrawBitmap(OH_Drawing_Canvas* canvas, const OH_Drawing_Bitmap* bitmap, float left, float top)
```

**描述**

用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Bitmap](capi-oh-drawing-bitmap.md)* bitmap | 指向位图对象的指针。 |
| float left | 位图对象左上角的横坐标。 |
| float top | 位图对象左上角的纵坐标。 |

### OH_Drawing_CanvasDrawBitmapRect()

```
void OH_Drawing_CanvasDrawBitmapRect(OH_Drawing_Canvas* canvas, const OH_Drawing_Bitmap* bitmap,const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions* samplingOptions)
```

**描述**

将位图的指定区域绘制到画布的指定区域。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、bitmap、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_Bitmap](capi-oh-drawing-bitmap.md)* bitmap | 指向位图对象[OH_Drawing_Bitmap](capi-oh-drawing-bitmap.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* src | 源位图指定矩形区域，为NULL将指定整个源位图区域。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* dst | 目标画布指定矩形区域。 |
| const [OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)* samplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)的指针，为NULL将使用默认采样选项。 |

### OH_Drawing_CanvasDrawRect()

```
void OH_Drawing_CanvasDrawRect(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect)
```

**描述**

用于画一个矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

### OH_Drawing_CanvasDrawCircle()

```
void OH_Drawing_CanvasDrawCircle(OH_Drawing_Canvas* canvas, const OH_Drawing_Point* point, float radius)
```

**描述**

用于画一个圆形。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。canvas、point任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>radius小于等于0时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Point](capi-oh-drawing-point.md)* point | 指向坐标点对象的指针，表示圆心。 |
| float radius | 圆形的半径，小于等于0时无效。 |

### OH_Drawing_CanvasDrawColor()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawColor(OH_Drawing_Canvas* canvas, uint32_t color,OH_Drawing_BlendMode blendMode)
```

**描述**

用于使用指定的颜色及混合模式来填充整个画布。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| uint32_t color | 表示指定的颜色，用一个32位（ARGB）的变量表示。 |
| [OH_Drawing_BlendMode](capi-drawing-types-h.md#oh_drawing_blendmode) blendMode | 表示指定的混合模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas为空。<br> 返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE，表示blendMode不在枚举范围内。 |

### OH_Drawing_CanvasDrawOval()

```
void OH_Drawing_CanvasDrawOval(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect)
```

**描述**

用于画一个椭圆。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。canvas、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |

### OH_Drawing_CanvasDrawArc()

```
void OH_Drawing_CanvasDrawArc(OH_Drawing_Canvas* canvas,const OH_Drawing_Rect* rect, float startAngle, float sweepAngle)
```

**描述**

用于画一个弧。当扫描角度的绝对值大于360度时，本接口绘制的是一个椭圆。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| float startAngle | 弧的起始角度，0度时起始点位于椭圆的右端点，正数时以顺时针方向放置起始点，负数时以逆时针方向放置起始点。 |
| float sweepAngle | 弧的扫描角度，正数时顺时针扫描，负数时逆时针扫描。它的有效范围在-360度到360度之间，当绝对值大于360度时，该函数绘制的是一个椭圆。 |

### OH_Drawing_CanvasDrawArcWithCenter()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawArcWithCenter(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect,float startAngle, float sweepAngle, bool useCenter)
```

**描述**

绘制一段圆弧。该方法允许指定圆弧的起始角度、扫描角度以及圆弧的起点和终点是否连接圆弧的中心点。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针。 |
| float startAngle | 弧的起始角度，单位为度，该参数为浮点数。0度时起始点位于椭圆的右端点，为正数时以顺时针方向放置起始点，为负数时以逆时针方向放置起始点。 |
| float sweepAngle | 弧的扫描角度，单位为度，该参数为浮点数。为正数时顺时针扫描，为负数时逆时针扫描。扫描角度可以超过360度，将绘制一个完整的椭圆。 |
| bool useCenter | 表示绘制时弧形的起点和终点是否连接弧形的中心点。true表示连接，false表示不连接。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者rect为空。 |

### OH_Drawing_CanvasDrawRoundRect()

```
void OH_Drawing_CanvasDrawRoundRect(OH_Drawing_Canvas* canvas, const OH_Drawing_RoundRect* roundRect)
```

**描述**

用于画一个圆角矩形。本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。canvas、roundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_RoundRect](capi-oh-drawing-roundrect.md)* roundRect | 指向圆角矩形对象的指针。 |

### OH_Drawing_CanvasDrawNestedRoundRect()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawNestedRoundRect(OH_Drawing_Canvas* canvas, const OH_Drawing_RoundRect* outer,const OH_Drawing_RoundRect* inner)
```

**描述**

绘制两个嵌套的圆角矩形，外部矩形边界必须包含内部矩形边界，否则无绘制效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_RoundRect](capi-oh-drawing-roundrect.md)* outer | 指向圆角矩形对象[OH_Drawing_RoundRect](capi-oh-drawing-roundrect.md)的指针，表示外部圆角矩形边界。 |
| const [OH_Drawing_RoundRect](capi-oh-drawing-roundrect.md)* inner | 指向圆角矩形对象[OH_Drawing_RoundRect](capi-oh-drawing-roundrect.md)的指针，表示内部圆角矩形边界。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、outer或者inner为空。 |

### OH_Drawing_CanvasDrawSingleCharacter()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawSingleCharacter(OH_Drawing_Canvas* canvas, const char* str,const OH_Drawing_Font* font, float x, float y)
```

**描述**

用于绘制单个字符。当前字型中的字体不支持待绘制字符时，退化到使用系统字体绘制字符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const char* str | 待绘制的单个字符。可以传入字符串，但只会以UTF-8编码解析并绘制字符串中的首个字符。 |
| const [OH_Drawing_Font](capi-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-oh-drawing-font.md)的指针。 |
| float x | 字符对象基线左端点（靠近字符左下角）的横坐标。 |
| float y | 字符对象基线左端点（靠近字符左下角）的纵坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、str、font任意一个为NULL或者str的长度为0。 |

### OH_Drawing_CanvasDrawTextBlob()

```
void OH_Drawing_CanvasDrawTextBlob(OH_Drawing_Canvas* canvas, const OH_Drawing_TextBlob* textBlob, float x, float y)
```

**描述**

用于画一段文字。若构造OH_Drawing_TextBlob的字体不支持待绘制字符，则该部分字符无法绘制。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、textBlob任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_TextBlob](capi-oh-drawing-textblob.md)* textBlob | 指向文本对象的指针。 |
| float x | 文本对象基线左端点（靠近文本左下角）的横坐标。 |
| float y | 文本对象基线左端点（靠近文本左下角）的纵坐标。 |

### OH_Drawing_CanvasClipRect()

```
void OH_Drawing_CanvasClipRect(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect,OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias)
```

**描述**

用于裁剪一个矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象的指针。 |
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp | 裁剪方式。支持可选的具体裁剪方式可见@{link OH_Drawing_CanvasClipOp}枚举。 |
| bool doAntiAlias | 值为true则做抗锯齿处理，反之不做。 |

### OH_Drawing_CanvasClipRoundRect()

```
void OH_Drawing_CanvasClipRoundRect(OH_Drawing_Canvas* canvas, const OH_Drawing_RoundRect* roundRect,OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias)
```

**描述**

用于裁剪一个圆角矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、roundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_RoundRect](capi-oh-drawing-roundrect.md)* roundRect | 指向圆角矩形对象的指针。 |
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp | 裁剪方式。支持可选的具体裁剪方式可见@{link OH_Drawing_CanvasClipOp}枚举。 |
| bool doAntiAlias | 表示是否需要做抗锯齿处理，值为true时为需要，为false时为不需要。 |

### OH_Drawing_CanvasClipPath()

```
void OH_Drawing_CanvasClipPath(OH_Drawing_Canvas* canvas, const OH_Drawing_Path* path,OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias)
```

**描述**

用于裁剪一个自定义路径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| const [OH_Drawing_Path](capi-oh-drawing-path.md)* path | 指向路径对象的指针。 |
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp | 裁剪方式。支持可选的具体裁剪方式可见@{link OH_Drawing_CanvasClipOp}枚举。 |
| bool doAntiAlias | 真为抗锯齿，假则不做抗锯齿处理。 |

### OH_Drawing_CanvasClipRegion()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasClipRegion(OH_Drawing_Canvas* canvas, const OH_Drawing_Region* region,OH_Drawing_CanvasClipOp clipOp)
```

**描述**

用于裁剪一个区域。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_Region](capi-oh-drawing-region.md)* region | 指向区域对象[OH_Drawing_Region](capi-oh-drawing-region.md)的指针。 |
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp | 表示裁剪类型。支持可选的具体裁剪方式可见@{link OH_Drawing_CanvasClipOp}枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者region为空。<br> 返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE，表示clipOp不在枚举范围内。 |

### OH_Drawing_CanvasRotate()

```
void OH_Drawing_CanvasRotate(OH_Drawing_Canvas* canvas, float degrees, float px, float py)
```

**描述**

用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| float degrees | 旋转角度。 |
| float px | 旋转中心的横坐标。 |
| float py | 旋转中心的纵坐标。 |

### OH_Drawing_CanvasTranslate()

```
void OH_Drawing_CanvasTranslate(OH_Drawing_Canvas* canvas, float dx, float dy)
```

**描述**

用于平移画布一段距离。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| float dx | 轴方向的移动距离。 |
| float dy | 轴方向的移动距离。 |

### OH_Drawing_CanvasScale()

```
void OH_Drawing_CanvasScale(OH_Drawing_Canvas* canvas, float sx, float sy)
```

**描述**

用于画布缩放。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| float sx | 轴方向的缩放比例。 |
| float sy | 轴方向的缩放比例。 |

### OH_Drawing_CanvasSkew()

```
void OH_Drawing_CanvasSkew(OH_Drawing_Canvas* canvas, float sx, float sy)
```

**描述**

用于画布倾斜变换。等同于将当前画布矩阵左乘（premultiply）倾斜变换矩阵，并应用到画布上。其中倾斜变换矩阵为：<br>|1 sx 0|  <br>|sy 1 0|  <br>|0  0 1|。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| float sx | 沿x轴的倾斜量。正值会使绘制沿y轴增量方向向右倾斜；负值会使绘制沿y轴增量方向向左倾斜。 |
| float sy | 沿y轴的倾斜量。正值会使绘制沿x轴增量方向向下倾斜；负值会使绘制沿x轴增量方向向上倾斜。 |

### OH_Drawing_CanvasGetWidth()

```
int32_t OH_Drawing_CanvasGetWidth(OH_Drawing_Canvas* canvas)
```

**描述**

获取画布宽度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 函数返回画布宽度，单位为像素。 |

### OH_Drawing_CanvasGetHeight()

```
int32_t OH_Drawing_CanvasGetHeight(OH_Drawing_Canvas* canvas)
```

**描述**

获取画布高度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 函数返回画布高度，单位为像素。 |

### OH_Drawing_CanvasGetLocalClipBounds()

```
void OH_Drawing_CanvasGetLocalClipBounds(OH_Drawing_Canvas* canvas, OH_Drawing_Rect* rect)
```

**描述**

获取画布裁剪区域的边界。该接口不可用于录制类型画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针，开发者可调用[OH_Drawing_RectCreate](capi-drawing-rect-h.md#oh_drawing_rectcreate)接口创建。 |

### OH_Drawing_CanvasGetTotalMatrix()

```
void OH_Drawing_CanvasGetTotalMatrix(OH_Drawing_Canvas* canvas, OH_Drawing_Matrix* matrix)
```

**描述**

获取画布3x3矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Matrix](capi-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-oh-drawing-matrix.md)的指针，开发者可调用[OH_Drawing_MatrixCreate](capi-drawing-matrix-h.md#oh_drawing_matrixcreate)接口创建。 |

### OH_Drawing_CanvasConcatMatrix()

```
void OH_Drawing_CanvasConcatMatrix(OH_Drawing_Canvas* canvas, OH_Drawing_Matrix* matrix)
```

**描述**

画布现有矩阵左乘以传入矩阵，不影响该接口之前的绘制操作。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Matrix](capi-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-oh-drawing-matrix.md)的指针。 |

### OH_Drawing_CanvasDrawShadow()

```
void OH_Drawing_CanvasDrawShadow(OH_Drawing_Canvas* canvas, OH_Drawing_Path* path, OH_Drawing_Point3D planeParams,OH_Drawing_Point3D devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor,OH_Drawing_CanvasShadowFlags flag)
```

**描述**

绘制射灯类型阴影，使用路径描述环境光阴影的轮廓。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>flag不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Path](capi-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-oh-drawing-path.md)的指针，用于生成阴影。 |
| [OH_Drawing_Point3D](capi-oh-drawing-point3d.md) planeParams | 表示遮挡物相对于画布在Z轴上的偏移量，其值取决于x与y坐标。 |
| [OH_Drawing_Point3D](capi-oh-drawing-point3d.md) devLightPos | 光线相对于画布的位置。 |
| float lightRadius | 光源半径，需大于或等于0。 |
| uint32_t ambientColor | 环境阴影颜色，用一个32位（ARGB）的变量表示。 |
| uint32_t spotColor | 点阴影颜色，用一个32位（ARGB）的变量表示。 |
| [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) flag | 阴影标志枚举[OH_Drawing_CanvasShadowFlags](capi-drawing-canvas-h.md#oh_drawing_canvasshadowflags)。 |

### OH_Drawing_CanvasClear()

```
void OH_Drawing_CanvasClear(OH_Drawing_Canvas* canvas, uint32_t color)
```

**描述**

用于使用指定颜色去清空画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| uint32_t color | 描述颜色的32位（ARGB）变量。 |

### OH_Drawing_CanvasSetMatrix()

```
void OH_Drawing_CanvasSetMatrix(OH_Drawing_Canvas* canvas, OH_Drawing_Matrix* matrix)
```

**描述**

设置画布的矩阵状态。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Matrix](capi-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-oh-drawing-matrix.md)的指针，开发者可调用[OH_Drawing_MatrixCreate](capi-drawing-matrix-h.md#oh_drawing_matrixcreate)接口创建。 |

### OH_Drawing_CanvasResetMatrix()

```
void OH_Drawing_CanvasResetMatrix(OH_Drawing_Canvas* canvas)
```

**描述**

重置当前画布的矩阵为单位矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |

### OH_Drawing_CanvasDrawImageRectWithSrc()

```
void OH_Drawing_CanvasDrawImageRectWithSrc(OH_Drawing_Canvas* canvas, const OH_Drawing_Image* image,const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions* samplingOptions,OH_Drawing_SrcRectConstraint srcRectConstraint)
```

**描述**

将图片绘制到画布的指定区域上，源矩形选定的区域会缩放平移到目标矩形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、image、src、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_Image](capi-oh-drawing-image.md)* image | 指向图片对象[OH_Drawing_Image](capi-oh-drawing-image.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* src | 指向源矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* dst | 指向目标矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针。 |
| const [OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)* samplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)的指针，为NULL将使用默认采样选项。 |
| [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint) srcRectConstraint | 约束类型，支持可选的具体类型可见[OH_Drawing_SrcRectConstraint](capi-drawing-canvas-h.md#oh_drawing_srcrectconstraint)枚举。 |

### OH_Drawing_CanvasDrawImageRect()

```
void OH_Drawing_CanvasDrawImageRect(OH_Drawing_Canvas* canvas, OH_Drawing_Image* image,OH_Drawing_Rect* rect, OH_Drawing_SamplingOptions* samplingOptions)
```

**描述**

将图片绘制到画布的指定区域上。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、image、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Image](capi-oh-drawing-image.md)* image | 指向图片对象[OH_Drawing_Image](capi-oh-drawing-image.md)的指针。 |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针。 |
| [OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)* samplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md)的指针，为NULL将使用默认采样选项。 |

### OH_Drawing_CanvasDrawVertices()

```
void OH_Drawing_CanvasDrawVertices(OH_Drawing_Canvas* canvas, OH_Drawing_VertexMode vertexMmode,int32_t vertexCount, const OH_Drawing_Point2D* positions, const OH_Drawing_Point2D* texs,const uint32_t* colors, int32_t indexCount, const uint16_t* indices, OH_Drawing_BlendMode mode)
```

**描述**

用于画顶点数组描述的三角网格。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas或positions为NULL、vertexCount值小于3、indexCount值小于3且不为0，存在以上任意一种情况时设置错误码为OH_DRAWING_ERROR_INVALID_PARAMETER；<br>vertexMmode、mode任意一个不在枚举范围内时设置错误码为OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象的指针。 |
| [OH_Drawing_VertexMode](#oh_drawing_vertexmode) vertexMmode | 绘制顶点的连接方式，支持方式参考[OH_Drawing_VertexMode](capi-drawing-canvas-h.md#oh_drawing_vertexmode)。 |
| int32_t vertexCount | 顶点数组元素的数量，值必须大于等于3。 |
| const [OH_Drawing_Point2D](capi-oh-drawing-point2d.md)* positions | 描述顶点位置的数组指针，不能为空，其长度必须等于vertexCount。 |
| const [OH_Drawing_Point2D](capi-oh-drawing-point2d.md)* texs | 描述顶点对应纹理空间坐标的数组指针，可以为空，若不为空其长度必须等于vertexCount。 |
| const uint32_t* colors | 描述顶点对应颜色的数组指针，用于在三角形中进行插值，可以为空，若不为空其长度必须等于vertexCount。 |
| int32_t indexCount | 索引的数量，可以为0，若不为0则值必须大于等于3。 |
| const uint16_t* indices | 描述顶点对应索引的数组指针，可以为空，若不为空其长度必须等于indexCount。 |
| [OH_Drawing_BlendMode](capi-drawing-types-h.md#oh_drawing_blendmode) mode | 混合模式枚举，支持方式参考[OH_Drawing_BlendMode](capi-drawing-types-h.md#oh_drawing_blendmode)。 |

### OH_Drawing_CanvasReadPixels()

```
bool OH_Drawing_CanvasReadPixels(OH_Drawing_Canvas* canvas, OH_Drawing_Image_Info* imageInfo,void* dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY)
```

**描述**

从画布中拷贝像素数据到指定地址。该接口不可用于录制类型画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、imageInfo、dstPixels任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Image_Info](capi-oh-drawing-image-info.md)* imageInfo | 指向图片信息[OH_Drawing_Image_Info](capi-oh-drawing-image-info.md)的指针。 |
| void* dstPixels | 目标像素存储首地址。 |
| uint32_t dstRowBytes | 一行像素的大小，小于等于0时无效。 |
| int32_t srcX | 画布像素的x轴偏移量，单位为像素。 |
| int32_t srcY | 画布像素的y轴偏移量，单位为像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回true表示像素成功拷贝到目标像素存储首地址，函数返回false表示拷贝失败。 |

### OH_Drawing_CanvasReadPixelsToBitmap()

```
bool OH_Drawing_CanvasReadPixelsToBitmap(OH_Drawing_Canvas* canvas,OH_Drawing_Bitmap* bitmap, int32_t srcX, int32_t srcY)
```

**描述**

从画布拷贝像素数据到位图中。该接口不可用于录制类型画布。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>canvas、bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Bitmap](capi-oh-drawing-bitmap.md)* bitmap | 指向位图对象[OH_Drawing_Bitmap](capi-oh-drawing-bitmap.md)的指针。 |
| int32_t srcX | 画布像素的x轴偏移量，单位为像素。 |
| int32_t srcY | 画布像素的y轴偏移量，单位为像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回true表示像素成功拷贝到位图，函数返回false表示拷贝失败。 |

### OH_Drawing_CanvasIsClipEmpty()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasIsClipEmpty(OH_Drawing_Canvas* canvas, bool* isClipEmpty)
```

**描述**

用于判断裁剪后可绘制区域是否为空。<br>

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| bool* isClipEmpty | 表示裁剪后可绘制区域是否为空。true表示为空，false表示不为空。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者isClipEmpty为空。 |

### OH_Drawing_CanvasGetImageInfo()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasGetImageInfo(OH_Drawing_Canvas* canvas, OH_Drawing_Image_Info* imageInfo)
```

**描述**

用于获取画布的图像信息。<br>

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| [OH_Drawing_Image_Info](capi-oh-drawing-image-info.md)* imageInfo | 指向图像信息对象[OH_Drawing_Image_Info](capi-oh-drawing-image-info.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者imageInfo为空。 |

### OH_Drawing_CanvasDrawRecordCmd()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawRecordCmd(OH_Drawing_Canvas* canvas, OH_Drawing_RecordCmd* recordCmd)
```

**描述**

用于绘制录制指令对象。<br>

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针，仅支持录制类型画布。 |
| [OH_Drawing_RecordCmd](capi-oh-drawing-recordcmd.md)* recordCmd | 指向录制指令对象[OH_Drawing_RecordCmd](capi-oh-drawing-recordcmd.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者recordCmd为空。 |

### OH_Drawing_CanvasQuickRejectPath()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasQuickRejectPath(OH_Drawing_Canvas* canvas, const OH_Drawing_Path* path,bool* quickReject)
```

**描述**

判断路径与画布区域是否不相交。画布区域包含边界。<br>

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_Path](capi-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-oh-drawing-path.md)的指针。 |
| bool* quickReject | 表示路径与画布区域是否不相交，true表示路径与画布区域不相交，false表示路径与画布区域相交。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、path或者quickReject为空。 |

### OH_Drawing_CanvasQuickRejectRect()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasQuickRejectRect(OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect,bool* quickReject)
```

**描述**

判断矩形和画布区域是否不相交。画布区域包含边界。<br>

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md)* canvas | 指向画布对象[OH_Drawing_Canvas](capi-oh-drawing-canvas.md)的指针。 |
| const [OH_Drawing_Rect](capi-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-oh-drawing-rect.md)的指针。 |
| bool* quickReject | 表示矩形与画布区域是否不相交，true表示矩形与画布区域不相交，false表示矩形与画布区域相交。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、rect或者quickReject为空。 |


