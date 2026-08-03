# drawing_path.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## 概述

文件中定义了与自定义路径相关的功能函数，能够高效构建复杂几何路径、支持SVG数据交换实现跨平台兼容，并通过配对创建与销毁机制保障内存安全。主要支持以下能力：
- 路径的创建、拷贝与销毁。
- 添加线段、弧线、贝塞尔曲线、圆锥曲线、矩形、椭圆、圆形、多边形等几何图形。
- 路径的矩阵变换、偏移、合并与闭合等操作。
- 路径长度、边界、包含关系等查询和测量能力。

<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

<!--RP1-->
**相关示例：** [NDKAPIDrawing (API20)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/Drawing/NDKAPIDrawing)<!--RP1End-->

**引用文件：** \<native_drawing/drawing_path.h\>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) | OH_Drawing_PathDirection | 添加闭合路径方向枚举。 |
| [OH_Drawing_PathFillType](#oh_drawing_pathfilltype) | OH_Drawing_PathFillType | 定义路径的填充类型枚举。 |
| [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode) | OH_Drawing_PathAddMode | 用于指定路径添加模式的枚举类型。 |
| [OH_Drawing_PathOpMode](#oh_drawing_pathopmode) | OH_Drawing_PathOpMode | 路径操作类型枚举。 |
| [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags) | OH_Drawing_PathMeasureMatrixFlags | 路径测量获取相应矩阵信息维度枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_Path* OH_Drawing_PathCreate(void)](#oh_drawing_pathcreate) | 用于创建一个路径对象。 |
| [OH_Drawing_Path* OH_Drawing_PathCopy(OH_Drawing_Path* path)](#oh_drawing_pathcopy) | 用于拷贝已有路径对象，返回路径对象副本[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathDestroy(OH_Drawing_Path* path)](#oh_drawing_pathdestroy) | 用于销毁路径对象并回收该对象占用的内存。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathSetPath(OH_Drawing_Path* path, OH_Drawing_Path* other)](#oh_drawing_pathsetpath) | 将另一个路径对象的内容设置到当前路径对象中。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIsEmpty(OH_Drawing_Path* path, bool* isEmpty)](#oh_drawing_pathisempty) | 判断一个路径对象是否为空。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIsRect(OH_Drawing_Path* path, OH_Drawing_Rect* rect, bool* isRect)](#oh_drawing_pathisrect) | 判断路径对象是否构成一个矩形。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathGetLastPoint(OH_Drawing_Path* path, OH_Drawing_Point2D* point)](#oh_drawing_pathgetlastpoint) | 用于获取路径的最后一个点的坐标。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIsEqual(OH_Drawing_Path* path, OH_Drawing_Path* other, bool* equal)](#oh_drawing_pathisequal) | 用于检查两个路径是否相等，即判断两个路径在构成数据上是否一致。 |
| [void OH_Drawing_PathMoveTo(OH_Drawing_Path* path, float x, float y)](#oh_drawing_pathmoveto) | 用于设置路径的起始点位置。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathLineTo(OH_Drawing_Path* path, float x, float y)](#oh_drawing_pathlineto) | 用于添加一条从路径的最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathArcTo(OH_Drawing_Path* path, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg)](#oh_drawing_patharcto) | 用于给路径添加一段弧线。绘制方式为角度弧：指定一个矩形边框，其内切椭圆用于截取弧线；再指定起始角度和扫描度数，从起始角度扫描截取的椭圆周长部分即为弧线。若路径已有内容，则默认添加一条从路径最后点位置到弧线起始点位置的线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathQuadTo(OH_Drawing_Path* path, float ctrlX, float ctrlY, float endX, float endY)](#oh_drawing_pathquadto) | 用于添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathConicTo(OH_Drawing_Path* path, float ctrlX, float ctrlY, float endX, float endY, float weight)](#oh_drawing_pathconicto) | 在当前路径上添加一条路径最后点位置（若路径没有内容则默认为(0, 0)）到目标点位置的圆锥曲线段，其控制点为(ctrlX, ctrlY)，结束点为(endX, endY)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathCubicTo(OH_Drawing_Path* path, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY)](#oh_drawing_pathcubicto) | 用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔曲线。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathRMoveTo(OH_Drawing_Path* path, float x, float y)](#oh_drawing_pathrmoveto) | 用于设置一个相对于当前路径终点（若路径没有内容则默认为 (0, 0)）的路径起始点位置。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathRLineTo(OH_Drawing_Path* path, float x, float y)](#oh_drawing_pathrlineto) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathRQuadTo(OH_Drawing_Path* path, float ctrlX, float ctrlY, float endX, float endY)](#oh_drawing_pathrquadto) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathRConicTo(OH_Drawing_Path* path, float ctrlX, float ctrlY, float endX, float endY, float weight)](#oh_drawing_pathrconicto) | 使用相对位置在当前路径上添加一条路径最后点位置（若路径没有内容则默认为(0, 0)）到目标点位置的圆锥曲线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathRCubicTo(OH_Drawing_Path* path, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY)](#oh_drawing_pathrcubicto) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为(0, 0)）到目标点位置的三阶贝塞尔曲线。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathAddRect(OH_Drawing_Path* path, float left, float top, float right, float bottom, OH_Drawing_PathDirection pathDirection)](#oh_drawing_pathaddrect) | 按指定方向，将矩形添加到路径中，该矩形轮廓的起始点为矩形左上角。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_PathAddRectWithInitialCorner(OH_Drawing_Path* path, const OH_Drawing_Rect* rect, OH_Drawing_PathDirection pathDirection, uint32_t start)](#oh_drawing_pathaddrectwithinitialcorner) | 按指定方向，向路径添加矩形轮廓。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_PathAddRoundRect(OH_Drawing_Path* path, const OH_Drawing_RoundRect* roundRect, OH_Drawing_PathDirection pathDirection)](#oh_drawing_pathaddroundrect) | 按指定方向，向路径添加圆角矩形轮廓。路径添加方向为顺时针时，起始点位于圆角矩形左下方圆角与左边界的交点；路径添加方向为逆时针时，起始点位于圆角矩形左上方圆角与左边界的交点。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、roundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_PathAddOvalWithInitialPoint(OH_Drawing_Path* path, const OH_Drawing_Rect* rect, uint32_t start, OH_Drawing_PathDirection pathDirection)](#oh_drawing_pathaddovalwithinitialpoint) | 将椭圆添加到路径中，其中矩形对象作为椭圆的外切矩形区域，绘制方向用来指定绘制时是顺时针或者逆时针方向。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_PathAddOval(OH_Drawing_Path* path, const OH_Drawing_Rect* rect, OH_Drawing_PathDirection pathDirection)](#oh_drawing_pathaddoval) | 按指定方向，向路径添加椭圆，其中矩形对象作为椭圆的外切矩形区域。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_PathAddArc(OH_Drawing_Path* path, const OH_Drawing_Rect* rect, float startAngle, float sweepAngle)](#oh_drawing_pathaddarc) | 将圆弧添加到路径中，作为新轮廓的起点。从起始角度开始，按扫描度数添加弧，添加的弧是矩形内切椭圆的一部分。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathAddPath(OH_Drawing_Path* path, const OH_Drawing_Path* src, const OH_Drawing_Matrix* matrix)](#oh_drawing_pathaddpath) | 将源路径矩阵变换后，添加到当前路径中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathAddPathWithMatrixAndMode(OH_Drawing_Path* path, const OH_Drawing_Path* src, const OH_Drawing_Matrix* matrix, OH_Drawing_PathAddMode pathAddMode)](#oh_drawing_pathaddpathwithmatrixandmode) | 将源路径矩阵变换后，以规定模式添加到当前路径中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_PathAddPathWithMode(OH_Drawing_Path* path, const OH_Drawing_Path* src, OH_Drawing_PathAddMode pathAddMode)](#oh_drawing_pathaddpathwithmode) | 将源路径以规定模式添加到当前路径中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_PathAddPathWithOffsetAndMode(OH_Drawing_Path* path, const OH_Drawing_Path* src, float dx, float dy, OH_Drawing_PathAddMode pathAddMode)](#oh_drawing_pathaddpathwithoffsetandmode) | 将源路径偏移后，以规定模式添加到当前路径中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_PathAddPolygon(OH_Drawing_Path* path, const OH_Drawing_Point2D* points, uint32_t count, bool isClosed)](#oh_drawing_pathaddpolygon) | 向路径添加多边形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、points任意一个为NULL或者count等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathAddCircle(OH_Drawing_Path* path, float x, float y, float radius, OH_Drawing_PathDirection pathDirection)](#oh_drawing_pathaddcircle) | 按指定方向，向路径添加圆形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>radius小于等于0时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE；<br>pathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [bool OH_Drawing_PathBuildFromSvgString(OH_Drawing_Path* path, const char* str)](#oh_drawing_pathbuildfromsvgstring) | 解析SVG字符串表示的路径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、str任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathConvertToSvgString(const OH_Drawing_Path* path, char* str, size_t* strSize)](#oh_drawing_pathconverttosvgstring) | 将路径转换为SVG路径数据字符串。 |
| [bool OH_Drawing_PathContains(OH_Drawing_Path* path, float x, float y)](#oh_drawing_pathcontains) | 判断指定坐标点是否被路径包含，判定规则参考[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathTransform(OH_Drawing_Path* path, const OH_Drawing_Matrix* matrix)](#oh_drawing_pathtransform) | 对路径进行矩阵变换，变换结果直接修改当前路径对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathTransformWithPerspectiveClip(OH_Drawing_Path* src, const OH_Drawing_Matrix* matrix, OH_Drawing_Path* dst, bool applyPerspectiveClip)](#oh_drawing_pathtransformwithperspectiveclip) | 对路径进行矩阵变换。用转换后的路径替换目标路径，如果目标路径为NULL，则替换源路径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>src、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathSetFillType(OH_Drawing_Path* path, OH_Drawing_PathFillType pathFillType)](#oh_drawing_pathsetfilltype) | 设置路径的填充类型，决定路径内部区域的定义方式。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathFillType不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathGetFillType(OH_Drawing_Path* path, OH_Drawing_PathFillType* pathFillType)](#oh_drawing_pathgetfilltype) | 获取路径的填充类型。 |
| [float OH_Drawing_PathGetLength(OH_Drawing_Path* path, bool forceClosed)](#oh_drawing_pathgetlength) | 获取当前路径的长度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathGetBounds(OH_Drawing_Path* path, OH_Drawing_Rect* rect)](#oh_drawing_pathgetbounds) | 获取包含路径的最小边界框。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathClose(OH_Drawing_Path* path)](#oh_drawing_pathclose) | 用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathOffset(OH_Drawing_Path* path, OH_Drawing_Path* dst, float dx, float dy)](#oh_drawing_pathoffset) | 将路径中的所有点沿着x轴和y轴方向偏移一定距离，并将结果存储到目标路径对象中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_PathReset(OH_Drawing_Path* path)](#oh_drawing_pathreset) | 用于重置自定义路径数据。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_PathIsClosed(OH_Drawing_Path* path, bool forceClosed)](#oh_drawing_pathisclosed) | 获取路径是否闭合。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_PathGetPositionTangent(OH_Drawing_Path* path, bool forceClosed, float distance, OH_Drawing_Point2D* position, OH_Drawing_Point2D* tangent)](#oh_drawing_pathgetpositiontangent) | 获取距路径起始点指定距离的坐标点和切线值。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、position、tangent任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathGetSegment(OH_Drawing_Path* path, bool forceClosed, float start, float stop, bool startWithMoveTo, OH_Drawing_Path* dst, bool* result)](#oh_drawing_pathgetsegment) | 截取路径的片段并追加到目标路径上。 |
| [bool OH_Drawing_PathOp(OH_Drawing_Path* path, const OH_Drawing_Path* other, OH_Drawing_PathOpMode op)](#oh_drawing_pathop) | 将两个路径按照指定的路径操作类型合并。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>op不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [bool OH_Drawing_PathGetMatrix(OH_Drawing_Path* path, bool forceClosed, float distance, OH_Drawing_Matrix* matrix, OH_Drawing_PathMeasureMatrixFlags flag)](#oh_drawing_pathgetmatrix) | 获取距路径起始点指定距离的相应变换矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>flag不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathApproximate(OH_Drawing_Path* path, float acceptableError, float* vals, uint32_t* count)](#oh_drawing_pathapproximate) | 将当前路径转化为由连续直线段构成的近似路径。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathGetVerbData(const OH_Drawing_Path* path, OH_Drawing_PathIteratorVerb* verbs, uint32_t* count)](#oh_drawing_pathgetverbdata) | 获取路径的指令数据(verb)。在路径（path）图元中，指令数据verb用于描述路径构造过程中的基本绘图动作。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathGetPointData(const OH_Drawing_Path* path, OH_Drawing_Point2D* points, uint32_t* count)](#oh_drawing_pathgetpointdata) | 获取路径的点数据。<br>在路径（path）图元中，点数据以数值序列的形式存在，与verb指令一一对应，用来精确指定绘图操作的几何坐标位置。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathGetConicWeightData(const OH_Drawing_Path* path, float* conicWeights, uint32_t* count)](#oh_drawing_pathgetconicweightdata) | 获取路径的圆锥曲线权重数据。<br>路径的圆锥曲线权重数据用于描述路径中圆锥曲线的权重信息。<br>在路径（path）图元中，圆锥曲线数据采用有理贝塞尔曲线（Rational Bézier Curve）形式表示，其中每个控制点附带一个权重值（weight）。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathInterpolate(OH_Drawing_Path* path, OH_Drawing_Path* other, float weight, bool* success, OH_Drawing_Path* interpolatedPath)](#oh_drawing_pathinterpolate) | 按照给定权重在当前路径与另一条路径之间进行插值，并将结果存储到目标路径对象中。<br>两条路径点数相同即可插值成功，目标路径按照当前路径的结构进行创建。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIsInterpolate(OH_Drawing_Path* path, OH_Drawing_Path* other, bool* result)](#oh_drawing_pathisinterpolate) | 检查当前路径与另一条路径（other）在结构和操作顺序上是否完全一致，以确定两条路径是否兼容插值，供[OH_Drawing_PathInterpolate](#oh_drawing_pathinterpolate)调用前预检查使用。<br> 若路径中包含圆锥曲线（Conic）操作，则对应操作的权重值也必须一致，才能视为兼容插值。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathIsInverseFillType(const OH_Drawing_Path* path, bool* isInverse)](#oh_drawing_pathisinversefilltype) | 检查路径的填充类型是否是取反类型。<br>取反类型即[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)中的PATH_FILL_TYPE_INVERSE_WINDING和PATH_FILL_TYPE_INVERSE_EVEN_ODD。 |
| [OH_Drawing_ErrorCode OH_Drawing_PathToggleInverseFillType(OH_Drawing_Path* path)](#oh_drawing_pathtoggleinversefilltype) | 切换路径填充类型的取反状态，即在取反类型与非取反类型之间翻转。<br>取反类型即[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)中的PATH_FILL_TYPE_INVERSE_WINDING和PATH_FILL_TYPE_INVERSE_EVEN_ODD。 |

## 枚举类型说明

### OH_Drawing_PathDirection

```c
enum OH_Drawing_PathDirection
```

**描述**

添加闭合路径方向枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| PATH_DIRECTION_CW | 顺时针方向添加闭合轮廓。 |
| PATH_DIRECTION_CCW | 逆时针方向添加闭合轮廓。 |

### OH_Drawing_PathFillType

```c
enum OH_Drawing_PathFillType
```

**描述**

定义路径的填充类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| PATH_FILL_TYPE_WINDING | 绘制区域中的任意一点，向任意方向射出一条射线，对于射线和路径的所有交点，初始计数为0，<br>遇到每个顺时针的交点（路径从射线的左边向右穿过），计数加1，遇到每个逆时针的交点（路径从射线的右边向左穿过），计数减1，若最终的计数结果不为0，则认为这个点在路径内部，需要被涂色；若计数为0则不被涂色。 |
| PATH_FILL_TYPE_EVEN_ODD | 绘制区域中的任意一点，向任意方向射出一条射线，若这条射线和路径相交的次数是奇数，则这个点被认为在路径内部，需要被涂色；若是偶数则不被涂色。 |
| PATH_FILL_TYPE_INVERSE_WINDING | PATH_FILL_TYPE_WINDING 涂色规则取反。 |
| PATH_FILL_TYPE_INVERSE_EVEN_ODD | PATH_FILL_TYPE_EVEN_ODD 涂色规则取反。 |

### OH_Drawing_PathAddMode

```c
enum OH_Drawing_PathAddMode
```

**描述**

用于指定路径添加模式的枚举类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| PATH_ADD_MODE_APPEND | 以追加的方式添加路径。 |
| PATH_ADD_MODE_EXTEND | 如果当前路径未闭合，则添加直线闭合当前路径。 |

### OH_Drawing_PathOpMode

```c
enum OH_Drawing_PathOpMode
```

**描述**

路径操作类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| PATH_OP_MODE_DIFFERENCE | 差集操作。 |
| PATH_OP_MODE_INTERSECT | 交集操作。 |
| PATH_OP_MODE_UNION | 并集操作。 |
| PATH_OP_MODE_XOR | 异或操作。 |
| PATH_OP_MODE_REVERSE_DIFFERENCE | 反向差集操作。 |

### OH_Drawing_PathMeasureMatrixFlags

```c
enum OH_Drawing_PathMeasureMatrixFlags
```

**描述**

路径测量获取相应矩阵信息维度枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| GET_POSITION_MATRIX | 获取位置信息对应的矩阵。 |
| GET_TANGENT_MATRIX | 获取切线信息对应的矩阵。 |
| GET_POSITION_AND_TANGENT_MATRIX | 获取位置和切线信息对应的矩阵。 |


## 函数说明

### OH_Drawing_PathCreate()

```c
OH_Drawing_Path* OH_Drawing_PathCreate(void)
```

**描述**

用于创建一个路径对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* | 函数会返回一个指针，指针指向创建的路径对象。 |

### OH_Drawing_PathCopy()

```c
OH_Drawing_Path* OH_Drawing_PathCopy(OH_Drawing_Path* path)
```

**描述**

用于拷贝已有路径对象，返回路径对象副本[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向需要拷贝的源路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* | 函数返回一个指针，指针指向创建的路径对象副本[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)。 |

### OH_Drawing_PathDestroy()

```c
void OH_Drawing_PathDestroy(OH_Drawing_Path* path)
```

**描述**

用于销毁路径对象并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象的指针。 |

### OH_Drawing_PathSetPath()

```c
OH_Drawing_ErrorCode OH_Drawing_PathSetPath(OH_Drawing_Path* path, OH_Drawing_Path* other)
```

**描述**

将另一个路径对象的内容设置到当前路径对象中。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* other | 指向源路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针，其内容将被设置到当前路径对象中。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数path或者other为空指针。 |

### OH_Drawing_PathIsEmpty()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIsEmpty(OH_Drawing_Path* path, bool* isEmpty)
```

**描述**

判断一个路径对象是否为空。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool* isEmpty | 表示路径对象是否为空。true表示路径对象为空，false表示路径对象不为空。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数path或者isEmpty为空。 |

### OH_Drawing_PathIsRect()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIsRect(OH_Drawing_Path* path, OH_Drawing_Rect* rect, bool* isRect)
```

**描述**

判断路径对象是否构成一个矩形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针，作为出参使用，可以为空。 |
| bool* isRect | 表示路径是否构成矩形。true表示构成矩形，false表示不构成矩形。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数path或者isRect为空。 |

### OH_Drawing_PathGetLastPoint()

```c
OH_Drawing_ErrorCode OH_Drawing_PathGetLastPoint(OH_Drawing_Path* path, OH_Drawing_Point2D* point)
```

**描述**

用于获取路径的最后一个点的坐标。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* point | 指向坐标点对象[OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)的指针，用于存储最后一个点，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数path或point为空指针，或者path为空路径。 |

### OH_Drawing_PathIsEqual()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIsEqual(OH_Drawing_Path* path, OH_Drawing_Path* other, bool* equal)
```

**描述**

用于检查两个路径是否相等，即判断两个路径在构成数据上是否一致。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* other | 指向另一个路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool* equal | 表示两个路径是否相等。true表示两个路径相等，false表示两个路径不相等。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示参数path或other为空指针，或者equal为空指针。 |

### OH_Drawing_PathMoveTo()

```c
void OH_Drawing_PathMoveTo(OH_Drawing_Path* path, float x, float y)
```

**描述**

用于设置路径的起始点位置。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象的指针。 |
| float x | 起始点的横坐标，单位为物理像素px。 |
| float y | 起始点的纵坐标，单位为物理像素px。 |

### OH_Drawing_PathLineTo()

```c
void OH_Drawing_PathLineTo(OH_Drawing_Path* path, float x, float y)
```

**描述**

用于添加一条从路径的最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象的指针。 |
| float x | 目标点的横坐标，单位为物理像素px。 |
| float y | 目标点的纵坐标，单位为物理像素px。 |

### OH_Drawing_PathArcTo()

```c
void OH_Drawing_PathArcTo(OH_Drawing_Path* path, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg)
```

**描述**

用于给路径添加一段弧线。绘制方式为角度弧：指定一个矩形边框，其内切椭圆用于截取弧线；再指定起始角度和扫描度数，从起始角度扫描截取的椭圆周长部分即为弧线。若路径已有内容，则默认添加一条从路径最后点位置到弧线起始点位置的线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象的指针。 |
| float x1 | 包围椭圆的矩形左上角点位置的横坐标，单位为物理像素px。 |
| float y1 | 包围椭圆的矩形左上角点位置的纵坐标，单位为物理像素px。 |
| float x2 | 包围椭圆的矩形右下角点位置的横坐标，单位为物理像素px。 |
| float y2 | 包围椭圆的矩形右下角点位置的纵坐标，单位为物理像素px。 |
| float startDeg | 起始的角度，单位为度。角度的起始方向（0°）为x轴正方向。 |
| float sweepDeg | 扫描的度数，单位为度，为正数时顺时针扫描，为负数时逆时针扫描。实际扫描的度数为该入参对360°取模的结果。 |

### OH_Drawing_PathQuadTo()

```c
void OH_Drawing_PathQuadTo(OH_Drawing_Path* path, float ctrlX, float ctrlY, float endX, float endY)
```

**描述**

用于添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象的指针。 |
| float ctrlX | 控制点位置的横坐标，单位为物理像素px。 |
| float ctrlY | 控制点位置的纵坐标，单位为物理像素px。 |
| float endX | 目标点位置的横坐标，单位为物理像素px。 |
| float endY | 目标点位置的纵坐标，单位为物理像素px。 |

### OH_Drawing_PathConicTo()

```c
void OH_Drawing_PathConicTo(OH_Drawing_Path* path, float ctrlX, float ctrlY, float endX, float endY, float weight)
```

**描述**

在当前路径上添加一条路径最后点位置（若路径没有内容则默认为(0, 0)）到目标点位置的圆锥曲线段，其控制点为(ctrlX, ctrlY)，结束点为(endX, endY)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float ctrlX | 控制点位置的横坐标，单位为物理像素px。 |
| float ctrlY | 控制点位置的纵坐标，单位为物理像素px。 |
| float endX | 目标点位置的横坐标，单位为物理像素px。 |
| float endY | 目标点位置的纵坐标，单位为物理像素px。 |
| float weight | 表示曲线的权重，决定了曲线的形状，越大越接近控制点。<br>若小于等于0则等同于使用[OH_Drawing_PathLineTo](#oh_drawing_pathlineto)添加一条到结束点的线段，<br>若为1则等同于[OH_Drawing_PathQuadTo](#oh_drawing_pathquadto)。 |

### OH_Drawing_PathCubicTo()

```c
void OH_Drawing_PathCubicTo(OH_Drawing_Path* path, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY)
```

**描述**

用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔曲线。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象的指针。 |
| float ctrlX1 | 第一个控制点位置的横坐标，单位为物理像素px。 |
| float ctrlY1 | 第一个控制点位置的纵坐标，单位为物理像素px。 |
| float ctrlX2 | 第二个控制点位置的横坐标，单位为物理像素px。 |
| float ctrlY2 | 第二个控制点位置的纵坐标，单位为物理像素px。 |
| float endX | 目标点位置的横坐标，单位为物理像素px。 |
| float endY | 目标点位置的纵坐标，单位为物理像素px。 |

### OH_Drawing_PathRMoveTo()

```c
void OH_Drawing_PathRMoveTo(OH_Drawing_Path* path, float x, float y)
```

**描述**

用于设置一个相对于当前路径终点（若路径没有内容则默认为 (0, 0)）的路径起始点位置。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float x | 相对于当前路径终点的x轴偏移量，单位为物理像素px，正数往x轴正方向偏移，负数往x轴负方向偏移。 |
| float y | 相对于当前路径终点的y轴偏移量，单位为物理像素px，正数往y轴正方向偏移，负数往y轴负方向偏移。 |

### OH_Drawing_PathRLineTo()

```c
void OH_Drawing_PathRLineTo(OH_Drawing_Path* path, float x, float y)
```

**描述**

使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float x | 相对于当前路径终点的x轴偏移量，单位为物理像素px，用于指定目标点的横坐标。 |
| float y | 相对于当前路径终点的y轴偏移量，单位为物理像素px，用于指定目标点的纵坐标。 |

### OH_Drawing_PathRQuadTo()

```c
void OH_Drawing_PathRQuadTo(OH_Drawing_Path* path, float ctrlX, float ctrlY, float endX, float endY)
```

**描述**

使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float ctrlX | 相对于路径终点的x轴偏移量，单位为物理像素px，用于指定控制点的横坐标。 |
| float ctrlY | 相对于路径终点的y轴偏移量，单位为物理像素px，用于指定控制点的纵坐标。 |
| float endX | 相对于路径终点的x轴偏移量，单位为物理像素px，用于指定目标点的横坐标。 |
| float endY | 相对于路径终点的y轴偏移量，单位为物理像素px，用于指定目标点的纵坐标。 |

### OH_Drawing_PathRConicTo()

```c
void OH_Drawing_PathRConicTo(OH_Drawing_Path* path, float ctrlX, float ctrlY, float endX, float endY, float weight)
```

**描述**

使用相对位置在当前路径上添加一条路径最后点位置（若路径没有内容则默认为(0, 0)）到目标点位置的圆锥曲线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float ctrlX | 相对于路径终点的x轴偏移量，单位为物理像素px，用于指定控制点的横坐标。 |
| float ctrlY | 相对于路径终点的y轴偏移量，单位为物理像素px，用于指定控制点的纵坐标。 |
| float endX | 相对于路径终点的x轴偏移量，单位为物理像素px，用于指定目标点的横坐标。 |
| float endY | 相对于路径终点的y轴偏移量，单位为物理像素px，用于指定目标点的纵坐标。 |
| float weight | 表示曲线的权重，决定了曲线的形状，越大越接近控制点。<br>若小于等于0则等同于使用[OH_Drawing_PathRLineTo](#oh_drawing_pathrlineto)添加一条到结束点的线段，<br>若为1则等同于[OH_Drawing_PathRQuadTo](#oh_drawing_pathrquadto)。 |

### OH_Drawing_PathRCubicTo()

```c
void OH_Drawing_PathRCubicTo(OH_Drawing_Path* path, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY)
```

**描述**

使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为(0, 0)）到目标点位置的三阶贝塞尔曲线。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float ctrlX1 | 相对于路径终点的x轴偏移量，单位为物理像素px，用于指定第一个控制点的横坐标。 |
| float ctrlY1 | 相对于路径终点的y轴偏移量，单位为物理像素px，用于指定第一个控制点的纵坐标。 |
| float ctrlX2 | 相对于路径终点的x轴偏移量，单位为物理像素px，用于指定第二个控制点的横坐标。 |
| float ctrlY2 | 相对于路径终点的y轴偏移量，单位为物理像素px，用于指定第二个控制点的纵坐标。 |
| float endX | 相对于路径终点的x轴偏移量，单位为物理像素px，用于指定目标点的横坐标。 |
| float endY | 相对于路径终点的y轴偏移量，单位为物理像素px，用于指定目标点的纵坐标。 |

### OH_Drawing_PathAddRect()

```c
void OH_Drawing_PathAddRect(OH_Drawing_Path* path, float left, float top, float right, float bottom, OH_Drawing_PathDirection pathDirection)
```

**描述**

按指定方向，将矩形添加到路径中，该矩形轮廓的起始点为矩形左上角。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float left | 矩形左上角的x轴坐标，单位为物理像素px。 |
| float top | 矩形左上角的y轴坐标，单位为物理像素px。 |
| float right | 矩形右下角的x轴坐标，单位为物理像素px。 |
| float bottom | 矩形右下角的y轴坐标，单位为物理像素px。 |
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) pathDirection | 路径添加方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)，用于指定矩形轮廓的绘制方向。 |

### OH_Drawing_PathAddRectWithInitialCorner()

```c
void OH_Drawing_PathAddRectWithInitialCorner(OH_Drawing_Path* path, const OH_Drawing_Rect* rect, OH_Drawing_PathDirection pathDirection, uint32_t start)
```

**描述**

按指定方向，向路径添加矩形轮廓。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针。 |
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) pathDirection | 路径添加方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)，用于指定矩形轮廓的绘制方向。 |
| uint32_t start | 起始点的位置，表示从矩形的哪个角开始绘制路径。取值范围为[0, 3]，0：左上角，1：右上角，2：右下角，3：左下角。 |

### OH_Drawing_PathAddRoundRect()

```c
void OH_Drawing_PathAddRoundRect(OH_Drawing_Path* path, const OH_Drawing_RoundRect* roundRect, OH_Drawing_PathDirection pathDirection)
```

**描述**

按指定方向，向路径添加圆角矩形轮廓。路径添加方向为顺时针时，起始点位于圆角矩形左下方圆角与左边界的交点；路径添加方向为逆时针时，起始点位于圆角矩形左上方圆角与左边界的交点。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、roundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)* roundRect | 指向圆角矩形对象[OH_Drawing_RoundRect](capi-drawing-oh-drawing-roundrect.md)的指针。 |
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) pathDirection | 路径添加方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)，用于指定圆角矩形轮廓的绘制方向。 |

### OH_Drawing_PathAddOvalWithInitialPoint()

```c
void OH_Drawing_PathAddOvalWithInitialPoint(OH_Drawing_Path* path, const OH_Drawing_Rect* rect, uint32_t start, OH_Drawing_PathDirection pathDirection)
```

**描述**

将椭圆添加到路径中，其中矩形对象作为椭圆的外切矩形区域，绘制方向用来指定绘制时是顺时针或者逆时针方向。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针，该矩形作为椭圆的外切矩形区域，用于定义椭圆的形状和大小。 |
| uint32_t start | 表示椭圆初始点的索引。 |
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) pathDirection | 路径添加方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)，用于指定椭圆的绘制方向。 |

### OH_Drawing_PathAddOval()

```c
void OH_Drawing_PathAddOval(OH_Drawing_Path* path, const OH_Drawing_Rect* rect, OH_Drawing_PathDirection pathDirection)
```

**描述**

按指定方向，向路径添加椭圆，其中矩形对象作为椭圆的外切矩形区域。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针，该矩形作为椭圆的外切矩形区域，用于定义椭圆的形状和大小。 |
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) pathDirection | 路径添加方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)，用于指定椭圆的绘制方向。 |

### OH_Drawing_PathAddArc()

```c
void OH_Drawing_PathAddArc(OH_Drawing_Path* path, const OH_Drawing_Rect* rect, float startAngle, float sweepAngle)
```

**描述**

将圆弧添加到路径中，作为新轮廓的起点。从起始角度开始，按扫描度数添加弧，添加的弧是矩形内切椭圆的一部分。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针，该矩形作为弧线的包围矩形，其内切椭圆用于截取弧线。 |
| float startAngle | 弧的起始角度，单位为度。 |
| float sweepAngle | 扫描的度数，单位为度，为正数时顺时针扫描，为负数时逆时针扫描。实际扫描的度数为该入参对360°取模的结果。 |

### OH_Drawing_PathAddPath()

```c
void OH_Drawing_PathAddPath(OH_Drawing_Path* path, const OH_Drawing_Path* src, const OH_Drawing_Matrix* matrix)
```

**描述**

将源路径矩阵变换后，添加到当前路径中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向当前路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* src | 指向源路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针，为NULL时表示单位矩阵。 |

### OH_Drawing_PathAddPathWithMatrixAndMode()

```c
void OH_Drawing_PathAddPathWithMatrixAndMode(OH_Drawing_Path* path, const OH_Drawing_Path* src, const OH_Drawing_Matrix* matrix, OH_Drawing_PathAddMode pathAddMode)
```

**描述**

将源路径矩阵变换后，以规定模式添加到当前路径中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向当前路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* src | 指向源路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针，为NULL表示单位矩阵。 |
| [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode) pathAddMode | 路径添加模式。 |

### OH_Drawing_PathAddPathWithMode()

```c
void OH_Drawing_PathAddPathWithMode(OH_Drawing_Path* path, const OH_Drawing_Path* src, OH_Drawing_PathAddMode pathAddMode)
```

**描述**

将源路径以规定模式添加到当前路径中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向当前路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* src | 指向源路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode) pathAddMode | 路径添加模式。 |

### OH_Drawing_PathAddPathWithOffsetAndMode()

```c
void OH_Drawing_PathAddPathWithOffsetAndMode(OH_Drawing_Path* path, const OH_Drawing_Path* src, float dx, float dy, OH_Drawing_PathAddMode pathAddMode)
```

**描述**

将源路径偏移后，以规定模式添加到当前路径中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向当前路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* src | 指向源路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float dx | 源路径横坐标的偏移量，单位为物理像素px。 |
| float dy | 源路径纵坐标的偏移量，单位为物理像素px。 |
| [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode) pathAddMode | 路径添加模式。 |

### OH_Drawing_PathAddPolygon()

```c
void OH_Drawing_PathAddPolygon(OH_Drawing_Path* path, const OH_Drawing_Point2D* points, uint32_t count, bool isClosed)
```

**描述**

向路径添加多边形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、points任意一个为NULL或者count等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向当前路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* points | 表示多边形的顶点坐标数组。 |
| uint32_t count | 表示多边形顶点坐标数组的大小，取值范围>0。 |
| bool isClosed | 是否添加连接起始点和终止点的线，true表示添加，false表示不添加。 |

### OH_Drawing_PathAddCircle()

```c
void OH_Drawing_PathAddCircle(OH_Drawing_Path* path, float x, float y, float radius, OH_Drawing_PathDirection pathDirection)
```

**描述**

按指定方向，向路径添加圆形。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>radius小于等于0时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE；<br>pathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float x | 表示圆心的x轴坐标，单位为物理像素px。 |
| float y | 表示圆心的y轴坐标，单位为物理像素px。 |
| float radius | 表示圆形的半径，单位为物理像素px。 |
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) pathDirection | 路径添加方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)，用于指定圆形轮廓的绘制方向。 |

### OH_Drawing_PathBuildFromSvgString()

```c
bool OH_Drawing_PathBuildFromSvgString(OH_Drawing_Path* path, const char* str)
```

**描述**

解析SVG字符串表示的路径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、str任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const char* str | 表示SVG路径数据字符串，需符合SVG path语法的格式要求。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回解析SVG字符串是否成功。true表示成功，false表示不成功。 |

### OH_Drawing_PathConvertToSvgString()

```c
OH_Drawing_ErrorCode OH_Drawing_PathConvertToSvgString(const OH_Drawing_Path* path, char* str, size_t* strSize)
```

**描述**

将路径转换为SVG路径数据字符串。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)对象的指针。 |
| char* str | SVG字符串，开发者需要分配和释放对应的内存。可通过传入空指针以获取SVG字符串的内存大小；作为出参使用时，表示路径转换后的SVG字符串结果。 |
| size_t* strSize | SVG字符串内存大小，单位为字节。作为出参使用时，用来获取实际字符串内存大小的值。作为入参使用时，表示str分配的内存大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 返回执行结果。<br>如果操作成功，则返回OH_DRAWING_SUCCESS。<br>如果path或strSize为nullptr，或strSize过小时则返回OH_DRAWING_ERROR_INCORRECT_PARAMETER。 |

### OH_Drawing_PathContains()

```c
bool OH_Drawing_PathContains(OH_Drawing_Path* path, float x, float y)
```

**描述**

判断指定坐标点是否被路径包含，判定规则参考[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float x | 表示待判断的坐标点的x轴坐标，单位为物理像素px。 |
| float y | 表示待判断的坐标点的y轴坐标，单位为物理像素px。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 函数返回true表示点在路径内，函数返回false表示点在路径外。 |

### OH_Drawing_PathTransform()

```c
void OH_Drawing_PathTransform(OH_Drawing_Path* path, const OH_Drawing_Matrix* matrix)
```

**描述**

对路径进行矩阵变换，变换结果直接修改当前路径对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针，用于指定对路径进行变换的矩阵，为NULL时表示单位矩阵（不对路径进行变换）。 |

### OH_Drawing_PathTransformWithPerspectiveClip()

```c
void OH_Drawing_PathTransformWithPerspectiveClip(OH_Drawing_Path* src, const OH_Drawing_Matrix* matrix, OH_Drawing_Path* dst, bool applyPerspectiveClip)
```

**描述**

对路径进行矩阵变换。用转换后的路径替换目标路径，如果目标路径为NULL，则替换源路径。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>src、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* src | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| const [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 指向矩阵对象[OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)的指针，用于指定对路径进行矩阵变换的变换矩阵。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* dst | 指向目标路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool applyPerspectiveClip | 表示变换路径是否应用透视裁剪。true表示对矩阵变换后的路径应用透视裁剪，保留裁剪后的路径部分；false表示不进行透视裁剪，保留变换后的完整路径。 |

### OH_Drawing_PathSetFillType()

```c
void OH_Drawing_PathSetFillType(OH_Drawing_Path* path, OH_Drawing_PathFillType pathFillType)
```

**描述**

设置路径的填充类型，决定路径内部区域的定义方式。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>pathFillType不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_PathFillType](#oh_drawing_pathfilltype) pathFillType | 路径填充类型[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)，决定路径内部区域的定义方式，即路径的涂色规则。 |

### OH_Drawing_PathGetFillType()

```c
OH_Drawing_ErrorCode OH_Drawing_PathGetFillType(OH_Drawing_Path* path, OH_Drawing_PathFillType* pathFillType)
```

**描述**

获取路径的填充类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_PathFillType](#oh_drawing_pathfilltype)* pathFillType | 路径填充类型，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数path或者pathFillType为空。 |

### OH_Drawing_PathGetLength()

```c
float OH_Drawing_PathGetLength(OH_Drawing_Path* path, bool forceClosed)
```

**描述**

获取当前路径的长度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool forceClosed | 表示是否按照闭合路径测量。true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 函数返回当前路径的长度，单位为物理像素px。 |

### OH_Drawing_PathGetBounds()

```c
void OH_Drawing_PathGetBounds(OH_Drawing_Path* path, OH_Drawing_Rect* rect)
```

**描述**

获取包含路径的最小边界框。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 指向矩形对象[OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)的指针，存储路径边界框结果，作为出参使用。 |

### OH_Drawing_PathClose()

```c
void OH_Drawing_PathClose(OH_Drawing_Path* path)
```

**描述**

用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |

### OH_Drawing_PathOffset()

```c
void OH_Drawing_PathOffset(OH_Drawing_Path* path, OH_Drawing_Path* dst, float dx, float dy)
```

**描述**

将路径中的所有点沿着x轴和y轴方向偏移一定距离，并将结果存储到目标路径对象中。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向当前路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* dst | 指向目标路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针，为NULL时会将结果存储到当前路径对象中。 |
| float dx | x轴方向的偏移量，单位为物理像素px。 |
| float dy | y轴方向的偏移量，单位为物理像素px。 |

### OH_Drawing_PathReset()

```c
void OH_Drawing_PathReset(OH_Drawing_Path* path)
```

**描述**

用于重置自定义路径数据。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象的指针。 |

### OH_Drawing_PathIsClosed()

```c
bool OH_Drawing_PathIsClosed(OH_Drawing_Path* path, bool forceClosed)
```

**描述**

获取路径是否闭合。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool forceClosed | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回路径是否闭合。true表示路径的测量结果为已闭合，false表示路径的测量结果为未闭合。 |

### OH_Drawing_PathGetPositionTangent()

```c
bool OH_Drawing_PathGetPositionTangent(OH_Drawing_Path* path, bool forceClosed, float distance, OH_Drawing_Point2D* position, OH_Drawing_Point2D* tangent)
```

**描述**

获取距路径起始点指定距离的坐标点和切线值。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、position、tangent任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool forceClosed | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 |
| float distance | 表示距离起始点的距离，单位为物理像素px，小于0时会被视为0处理，大于路径长度时会被视为路径长度处理。 |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* position | 表示距路径起始点指定距离的坐标点，作为出参使用，用于存储计算得到的坐标点结果。 |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* tangent | 表示距路径起始点指定距离的切线值，作为出参使用。tangent.x表示该点切线的余弦值，tangent.y表示该点切线的正弦值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回测量是否成功。true表示成功，false表示失败。 |

### OH_Drawing_PathGetSegment()

```c
OH_Drawing_ErrorCode OH_Drawing_PathGetSegment(OH_Drawing_Path* path, bool forceClosed, float start, float stop, bool startWithMoveTo, OH_Drawing_Path* dst, bool* result)
```

**描述**

截取路径的片段并追加到目标路径上。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool forceClosed | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 |
| float start | 表示与路径起始点的距离，单位为物理像素px，距离路径起始点start距离的位置即为截取路径片段的起始点，小于0时会被视作0，大于等于stop时会截取失败。 |
| float stop | 表示与路径起始点的距离，单位为物理像素px，距离路径起始点stop距离的位置即为截取路径片段的终点，小于等于start时会截取失败，大于路径长度时会被视作路径长度。 |
| bool startWithMoveTo | 表示是否在目标路径执行[OH_Drawing_PathMoveTo](#oh_drawing_pathmoveto)移动到截取路径片段的起始点位置。true表示执行，false表示不执行。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* dst | 指向目标路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针，截取成功时会将得到的路径片段追加到目标路径上，截取失败时不做改变。 |
| bool* result | 返回是否成功截取路径片段的结果。true表示截取成功，false表示截取失败。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数path、dst、result至少有一个为空指针。 |

### OH_Drawing_PathOp()

```c
bool OH_Drawing_PathOp(OH_Drawing_Path* path, const OH_Drawing_Path* other, OH_Drawing_PathOpMode op)
```

**描述**

将两个路径按照指定的路径操作类型合并。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>op不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针，操作完成后的路径结果将会保存在此路径对象中。 |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* other | 指向参与路径操作的路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针，与当前路径一起按指定操作类型进行运算。 |
| [OH_Drawing_PathOpMode](#oh_drawing_pathopmode) op | 路径操作枚举类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回操作后的路径是否为空。true表示路径不为空，false表示路径为空。 |

### OH_Drawing_PathGetMatrix()

```c
bool OH_Drawing_PathGetMatrix(OH_Drawing_Path* path, bool forceClosed, float distance, OH_Drawing_Matrix* matrix, OH_Drawing_PathMeasureMatrixFlags flag)
```

**描述**

获取距路径起始点指定距离的相应变换矩阵。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>path、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>flag不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool forceClosed | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 |
| float distance | 表示距离起始点的距离，单位为物理像素px，小于0时会被视为0处理，大于路径长度时会被视为路径长度处理。 |
| [OH_Drawing_Matrix](capi-drawing-oh-drawing-matrix.md)* matrix | 表示要获取的变换矩阵，作为出参使用，用于存储距路径起始点指定距离的变换矩阵结果。 |
| [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags) flag | 矩阵信息维度枚举。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回获取变换矩阵是否成功。true表示获取成功，false表示获取失败，失败的原因可能是path为NULL或者长度为0。 |

### OH_Drawing_PathApproximate()

```c
OH_Drawing_ErrorCode OH_Drawing_PathApproximate(OH_Drawing_Path* path, float acceptableError, float* vals, uint32_t* count)
```

**描述**

将当前路径转化为由连续直线段构成的近似路径。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float acceptableError | 表示路径上每条线段的可接受误差，单位为物理像素px，不能小于0。<br> 1.当acceptableError为0时，曲线路径被极度细分，性能和内存消耗显著增加，不建议设置误差值为0。<br> 2.当acceptableError远大于路径尺寸时（即误差容限远超路径几何范围），路径会极度简化，仅保留路径的关键端点，可能会丢失原有形状。<br> 3.对于椭圆等曲线，当acceptableError远大于椭圆半径时（即误差容限远超椭圆几何范围），拟合结果通常只包含椭圆的分段贝塞尔曲线的起止点，椭圆形会被极度简化为多边形。 |
| float* vals | 返回包含路径近似点的数组。<br> 每个点由三个值组成，分别表示：<br> 1.该点所在的位置距离路径起点的长度比例值。<br> 2.点的x坐标。<br> 3.点的y坐标。 |
| uint32_t* count | 返回数组的大小，数组大小至少为6。vals为空指针时返回拟合后的点数据数组的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数path或者count为空指针。<br> 返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE，表示参数acceptableError小于0。 |

### OH_Drawing_PathGetVerbData()

```c
OH_Drawing_ErrorCode OH_Drawing_PathGetVerbData(const OH_Drawing_Path* path, OH_Drawing_PathIteratorVerb* verbs, uint32_t* count)
```

**描述**

获取路径的指令数据(verb)。在路径（path）图元中，指令数据verb用于描述路径构造过程中的基本绘图动作。

指令数据以枚举的形式存在，每个取值对应一种几何操作类型，例如：

- [OH_Drawing_PathMoveTo](#oh_drawing_pathmoveto)：将当前绘图点移至指定坐标，不产生线段。

- [OH_Drawing_PathLineTo](#oh_drawing_pathlineto)：从当前点向指定点绘制直线段。

- [OH_Drawing_PathQuadTo](#oh_drawing_pathquadto)：从当前点向指定点绘制二阶贝塞尔曲线。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)对象的指针。 |
| [OH_Drawing_PathIteratorVerb](capi-drawing-path-iterator-h.md#oh_drawing_pathiteratorverb)* verbs | 作为出参使用，表示路径的指令数据数组。开发者需要分配和释放对应的内存。可通过传入空指针以获取指令数据数组的大小，再根据大小分配内存后再次调用本接口获取完整数据。 |
| uint32_t* count | 作为出参使用时，表示指令数据数组的大小。作为入参使用时，表示verbs分配的内存大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>如果操作成功，则返回OH_DRAWING_SUCCESS。<br>如果path或count为空，则返回OH_DRAWING_ERROR_INCORRECT_PARAMETER。 |

### OH_Drawing_PathGetPointData()

```c
OH_Drawing_ErrorCode OH_Drawing_PathGetPointData(const OH_Drawing_Path* path, OH_Drawing_Point2D* points, uint32_t* count)
```

**描述**

获取路径的点数据。

在路径（path）图元中，点数据以数值序列的形式存在，与verb指令一一对应，用来精确指定绘图操作的几何坐标位置。

点数据的主要类型包括如下：

- 终点坐标：[OH_Drawing_PathMoveTo](#oh_drawing_pathmoveto)、[OH_Drawing_PathLineTo](#oh_drawing_pathlineto) 等指令配合，定义线段或移动的目标位置。

- 控制点坐标：与曲线指令配合，用于定义贝塞尔曲线的形状（如三阶贝塞尔曲线需要两个控制点和一个终点）。

- 闭合点：通常不单独提供坐标，由[OH_Drawing_PathClose](#oh_drawing_pathclose)指令隐式使用路径起点。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)对象的指针。 |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* points | 作为出参使用，表示路径的点数据数组。开发者需要分配和释放对应的内存。可通过传入空指针以获取点数据数组的大小，再根据大小分配内存后再次调用本接口获取完整数据。 |
| uint32_t* count | 作为出参使用时，表示点数据数组的大小。作为入参使用时，表示points分配的内存大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>如果操作成功，则返回OH_DRAWING_SUCCESS。<br>如果path或count为空，则返回OH_DRAWING_ERROR_INCORRECT_PARAMETER。 |

### OH_Drawing_PathGetConicWeightData()

```c
OH_Drawing_ErrorCode OH_Drawing_PathGetConicWeightData(const OH_Drawing_Path* path, float* conicWeights, uint32_t* count)
```

**描述**

获取路径的圆锥曲线权重数据。

路径的圆锥曲线权重数据用于描述路径中圆锥曲线的权重信息。

在路径（path）图元中，圆锥曲线数据采用有理贝塞尔曲线（Rational Bézier Curve）形式表示，其中每个控制点附带一个权重值（weight）。权重属于曲线定义的几何参数，作用如下：

- 形状调控：权重值越大，曲线越靠近对应控制点；权重为1时退化为标准贝塞尔曲线；权重为0时该控制点不起作用。

- 精确表示圆锥曲线：通过组合权重与二次贝塞尔曲线，可以精确表示圆弧、椭圆弧、抛物线等圆锥曲线段，无需使用分段逼近或专用椭圆弧指令。

- 数据组织：权重通常以数组形式与点数据并列，按顺序对应每个控制点，与相应的指令verb（如[OH_Drawing_PathConicTo](#oh_drawing_pathconicto)）配合使用。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)对象的指针。 |
| float* conicWeights | 作为出参使用，表示路径的圆锥曲线权重数据数组。开发者需要分配和释放对应的内存。可通过传入空指针以获取权重数据数组的大小，再根据大小分配内存后再次调用本接口获取完整数据。 |
| uint32_t* count | 作为出参使用时，表示圆锥曲线权重数据数组的大小。作为入参使用时，表示conicWeights分配的内存大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>如果操作成功，则返回OH_DRAWING_SUCCESS。<br>如果path或count为空，则返回OH_DRAWING_ERROR_INCORRECT_PARAMETER。 |

### OH_Drawing_PathInterpolate()

```c
OH_Drawing_ErrorCode OH_Drawing_PathInterpolate(OH_Drawing_Path* path, OH_Drawing_Path* other, float weight, bool* success, OH_Drawing_Path* interpolatedPath)
```

**描述**

按照给定权重在当前路径与另一条路径之间进行插值，并将结果存储到目标路径对象中。<br>两条路径点数相同即可插值成功，目标路径按照当前路径的结构进行创建。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* other | 指向用于插值的另一条路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| float weight | 表示插值权重，范围为[0, 1]。 |
| bool* success | 表示插值是否成功。true表示插值成功，false表示插值失败。作为出参使用。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* interpolatedPath | 指向用于存储插值结果的路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数path、other、success或者interpolatedPath为空指针。<br> 返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE，表示参数weight不在[0, 1]范围内。 |

### OH_Drawing_PathIsInterpolate()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIsInterpolate(OH_Drawing_Path* path, OH_Drawing_Path* other, bool* result)
```

**描述**

检查当前路径与另一条路径（other）在结构和操作顺序上是否完全一致，以确定两条路径是否兼容插值，供[OH_Drawing_PathInterpolate](#oh_drawing_pathinterpolate)调用前预检查使用。<br> 若路径中包含圆锥曲线（Conic）操作，则对应操作的权重值也必须一致，才能视为兼容插值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* other | 指向另一条路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool* result | 表示当前路径与另一条路径是否兼容插值。作为出参使用。<br> 如果路径兼容，则返回true，否则返回false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数path、other或者result为空指针。 |


### OH_Drawing_PathIsInverseFillType()

```c
OH_Drawing_ErrorCode OH_Drawing_PathIsInverseFillType(const OH_Drawing_Path* path, bool* isInverse)
```

**描述**

检查路径的填充类型是否是取反类型。

取反类型即[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)中的PATH_FILL_TYPE_INVERSE_WINDING和PATH_FILL_TYPE_INVERSE_EVEN_ODD。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |
| bool* isInverse | 表示填充类型是否是取反类型。作为出参使用。true表示填充类型是取反类型，false表示填充类型不是取反类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示path或isInverse是空指针。 |

### OH_Drawing_PathToggleInverseFillType()

```c
OH_Drawing_ErrorCode OH_Drawing_PathToggleInverseFillType(OH_Drawing_Path* path)
```

**描述**

切换路径填充类型的取反状态，即在取反类型与非取反类型之间翻转。

取反类型即[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)中的PATH_FILL_TYPE_INVERSE_WINDING和PATH_FILL_TYPE_INVERSE_EVEN_ODD。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行结果。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INCORRECT_PARAMETER，表示path是空指针。 |