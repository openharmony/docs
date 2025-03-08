# drawing_path.h


## 概述

文件中定义了与自定义路径相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_path.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)  [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection) | 添加闭合轮廓方向枚举。 | 
| typedef enum [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype)  [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype) | 定义路径的填充类型枚举。 | 
| typedef enum [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode)  [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode) | 用于指定路径添加模式的枚举类型。 | 
| typedef enum [OH_Drawing_PathOpMode](_drawing.md#oh_drawing_pathopmode)  [OH_Drawing_PathOpMode](_drawing.md#oh_drawing_pathopmode) | 路径操作类型枚举。 | 
| typedef enum [OH_Drawing_PathMeasureMatrixFlags](_drawing.md#oh_drawing_pathmeasurematrixflags)  [OH_Drawing_PathMeasureMatrixFlags](_drawing.md#oh_drawing_pathmeasurematrixflags) | 路径测量获取相应矩阵信息维度枚举。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection) { PATH_DIRECTION_CW, PATH_DIRECTION_CCW } | 添加闭合轮廓方向枚举。 | 
| [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype) { PATH_FILL_TYPE_WINDING, PATH_FILL_TYPE_EVEN_ODD, PATH_FILL_TYPE_INVERSE_WINDING, PATH_FILL_TYPE_INVERSE_EVEN_ODD } | 定义路径的填充类型枚举。 | 
| [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode) { PATH_ADD_MODE_APPEND, PATH_ADD_MODE_EXTEND } | 用于指定路径添加模式的枚举类型。 | 
| [OH_Drawing_PathOpMode](_drawing.md#oh_drawing_pathopmode) {<br/>PATH_OP_MODE_DIFFERENCE, PATH_OP_MODE_INTERSECT, PATH_OP_MODE_UNION, PATH_OP_MODE_XOR,<br/>PATH_OP_MODE_REVERSE_DIFFERENCE<br/>} | 路径操作类型枚举。 | 
| [OH_Drawing_PathMeasureMatrixFlags](_drawing.md#oh_drawing_pathmeasurematrixflags) { GET_POSITION_MATRIX, GET_TANGENT_MATRIX, GET_POSITION_AND_TANGENT_MATRIX } | 路径测量获取相应矩阵信息维度枚举。 | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* [OH_Drawing_PathCreate](_drawing.md#oh_drawing_pathcreate) (void) | 用于创建一个路径对象。 | 
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* [OH_Drawing_PathCopy](_drawing.md#oh_drawing_pathcopy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 创建一个路径对象副本[OH_Drawing_Path](_drawing.md#oh_drawing_path)，用于拷贝一个已有路径对象。 | 
| void [OH_Drawing_PathDestroy](_drawing.md#oh_drawing_pathdestroy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 用于销毁路径对象并回收该对象占有的内存。 | 
| void [OH_Drawing_PathMoveTo](_drawing.md#oh_drawing_pathmoveto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 用于设置自定义路径的起始点位置。 | 
| void [OH_Drawing_PathLineTo](_drawing.md#oh_drawing_pathlineto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 用于添加一条从路径的最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。 | 
| void [OH_Drawing_PathArcTo](_drawing.md#oh_drawing_patharcto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | 用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框的内切椭圆将会被用来截取弧线，然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。若路径有内容则会默认添加一条从路径的最后点位置到弧线起始点位置的线段。 | 
| void [OH_Drawing_PathQuadTo](_drawing.md#oh_drawing_pathquadto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | 用于添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。 | 
| void [OH_Drawing_PathConicTo](_drawing.md#oh_drawing_pathconicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY, float weight) | 在当前路径上添加一条路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的圆锥曲线，其控制点为 (ctrlX, ctrlY)，结束点为 (endX, endY)。 | 
| void [OH_Drawing_PathCubicTo](_drawing.md#oh_drawing_pathcubicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | 用于添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的三阶贝塞尔圆滑曲线。 | 
| void [OH_Drawing_PathRMoveTo](_drawing.md#oh_drawing_pathrmoveto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 用于设置一个相对于当前路径终点（若路径没有内容则默认为 (0, 0)）的路径起始点位置。 | 
| void [OH_Drawing_PathRLineTo](_drawing.md#oh_drawing_pathrlineto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。 | 
| void [OH_Drawing_PathRQuadTo](_drawing.md#oh_drawing_pathrquadto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。 | 
| void [OH_Drawing_PathRConicTo](_drawing.md#oh_drawing_pathrconicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY, float weight) | 使用相对位置在当前路径上添加一条路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的圆锥曲线。 | 
| void [OH_Drawing_PathRCubicTo](_drawing.md#oh_drawing_pathrcubicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的三阶贝塞尔圆滑曲线。 | 
| void [OH_Drawing_PathAddRect](_drawing.md#oh_drawing_pathaddrect) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float left, float top, float right, float bottom, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | 按指定方向，向路径添加矩形轮廓。 | 
| void [OH_Drawing_PathAddRectWithInitialCorner](_drawing.md#oh_drawing_pathaddrectwithinitialcorner) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection), uint32_t start) | 按指定方向，向路径添加矩形轮廓。 | 
| void [OH_Drawing_PathAddRoundRect](_drawing.md#oh_drawing_pathaddroundrect) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*roundRect, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | 按指定方向，向路径添加圆角矩形轮廓。 | 
| void [OH_Drawing_PathAddOvalWithInitialPoint](_drawing.md#oh_drawing_pathaddovalwithinitialpoint) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, uint32_t start, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | 将椭圆添加到路径中，其中矩形对象作为椭圆的外切矩形区域，绘制方向用来指定绘制时是顺时针或者逆时针方向。 | 
| void [OH_Drawing_PathAddArc](_drawing.md#oh_drawing_pathaddarc) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float startAngle, float sweepAngle) | 将圆弧添加到路径中，作为新轮廓的起点。从起始角度到扫掠角度添加弧， 添加的弧是矩形内切椭圆的一部分，如果扫描角度<= -360°，或>= 360°， 并且起始角度对90取模接近于0，则添加椭圆而不是弧。 | 
| void [OH_Drawing_PathAddPath](_drawing.md#oh_drawing_pathaddpath) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 将源路径矩阵变换后，添加到当前路径中。 | 
| void [OH_Drawing_PathAddPathWithMatrixAndMode](_drawing.md#oh_drawing_pathaddpathwithmatrixandmode) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode)) | 将源路径矩阵变换后，以规定模式添加到当前路径中。 | 
| void [OH_Drawing_PathAddPathWithMode](_drawing.md#oh_drawing_pathaddpathwithmode) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode)) | 将源路径以规定模式添加到当前路径中。 | 
| void [OH_Drawing_PathAddPathWithOffsetAndMode](_drawing.md#oh_drawing_pathaddpathwithoffsetandmode) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, float dx, float dy, [OH_Drawing_PathAddMode](_drawing.md#oh_drawing_pathaddmode)) | 将源路径偏移后，以规定模式添加到当前路径中。 | 
| void [OH_Drawing_PathAddOval](_drawing.md#oh_drawing_pathaddoval) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | 按指定方向，向路径添加椭圆。 | 
| bool [OH_Drawing_PathContains](_drawing.md#oh_drawing_pathcontains) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 判断指定坐标点是否被路径包含，判定是否被路径包含的规则参考[OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype-1)。 | 
| void [OH_Drawing_PathTransform](_drawing.md#oh_drawing_pathtransform) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 对路径进行矩阵变换。 | 
| void [OH_Drawing_PathTransformWithPerspectiveClip](_drawing.md#oh_drawing_pathtransformwithperspectiveclip) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*dst, bool applyPerspectiveClip) | 对路径进行矩阵变换。用转换后的路径替换目标路径，如果目标路径为NULL，则替换源路径。 | 
| void [OH_Drawing_PathSetFillType](_drawing.md#oh_drawing_pathsetfilltype) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype)) | 设置填充路径的规则。 | 
| float [OH_Drawing_PathGetLength](_drawing.md#oh_drawing_pathgetlength) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, bool forceClosed) | 获取当前路径的长度。 | 
| void [OH_Drawing_PathClose](_drawing.md#oh_drawing_pathclose) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。 | 
| void [OH_Drawing_PathOffset](_drawing.md#oh_drawing_pathoffset) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*dst, float dx, float dy) | 将路径中的所有点沿着x轴和y轴方向偏移一定距离，并将结果存储到目标路径对象中。 | 
| void [OH_Drawing_PathReset](_drawing.md#oh_drawing_pathreset) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 用于重置自定义路径数据。 | 
| void [OH_Drawing_PathAddPolygon](_drawing.md#oh_drawing_pathaddpolygon) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*points, uint32_t count, bool isClosed) | 向路径添加多边形。 | 
| void [OH_Drawing_PathAddCircle](_drawing.md#oh_drawing_pathaddcircle) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, float x, float y, float radius, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | 按指定方向，向路径添加圆形。 | 
| bool [OH_Drawing_PathBuildFromSvgString](_drawing.md#oh_drawing_pathbuildfromsvgstring) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const char \*str) | 解析SVG字符串表示的路径。 | 
| void [OH_Drawing_PathGetBounds](_drawing.md#oh_drawing_pathgetbounds) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | 获取包含路径的最小边界框。 | 
| bool [OH_Drawing_PathIsClosed](_drawing.md#oh_drawing_pathisclosed) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, bool forceClosed) | 获取路径是否闭合。 | 
| bool [OH_Drawing_PathGetPositionTangent](_drawing.md#oh_drawing_pathgetpositiontangent) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, bool forceClosed, float distance, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*position, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*tangent) | 获取距路径起始点指定距离的坐标点和切线值。 | 
| bool [OH_Drawing_PathOp](_drawing.md#oh_drawing_pathop) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*other, [OH_Drawing_PathOpMode](_drawing.md#oh_drawing_pathopmode) op) | 将两个路径按照指定的路径操作类型合并。 | 
| bool [OH_Drawing_PathGetMatrix](_drawing.md#oh_drawing_pathgetmatrix) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, bool forceClosed, float distance, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*matrix, [OH_Drawing_PathMeasureMatrixFlags](_drawing.md#oh_drawing_pathmeasurematrixflags) flag) | 获取距路径起始点指定距离的相应变换矩阵。 | 