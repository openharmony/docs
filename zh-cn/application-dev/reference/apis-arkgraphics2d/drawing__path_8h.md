# drawing_path.h


## 概述

文件中定义了与自定义路径相关的功能函数

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


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection) { PATH_DIRECTION_CW, PATH_DIRECTION_CCW } | 添加闭合轮廓方向枚举。 |
| [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype) { PATH_FILL_TYPE_WINDING, PATH_FILL_TYPE_EVEN_ODD, PATH_FILL_TYPE_INVERSE_WINDING, PATH_FILL_TYPE_INVERSE_EVEN_ODD } | 定义路径的填充类型枚举。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* [OH_Drawing_PathCreate](_drawing.md#oh_drawing_pathcreate) (void) | 用于创建一个路径对象。 |
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) \* [OH_Drawing_PathCopy](_drawing.md#oh_drawing_pathcopy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 创建一个路径对象副本[OH_Drawing_Path](_drawing.md#oh_drawing_path)，用于拷贝一个已有路径对象。 |
| void [OH_Drawing_PathDestroy](_drawing.md#oh_drawing_pathdestroy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 用于销毁路径对象并回收该对象占有的内存。 |
| void [OH_Drawing_PathMoveTo](_drawing.md#oh_drawing_pathmoveto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 用于设置自定义路径的起始点位置。 |
| void [OH_Drawing_PathLineTo](_drawing.md#oh_drawing_pathlineto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 用于添加一条从路径的最后点位置到目标点位置的线段。 |
| void [OH_Drawing_PathArcTo](_drawing.md#oh_drawing_patharcto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | 用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆， 然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段。 |
| void [OH_Drawing_PathQuadTo](_drawing.md#oh_drawing_pathquadto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | 用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线。 |
| void [OH_Drawing_PathCubicTo](_drawing.md#oh_drawing_pathcubicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | 用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线。 |
| void [OH_Drawing_PathAddRect](_drawing.md#oh_drawing_pathaddrect) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float left, float top, float right, float bottom, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | 按指定方向，向路径添加矩形轮廓。 |
| void [OH_Drawing_PathAddRoundRect](_drawing.md#oh_drawing_pathaddroundrect) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) \*roundRect, [OH_Drawing_PathDirection](_drawing.md#oh_drawing_pathdirection)) | 按指定方向，向路径添加圆角矩形轮廓。 |
| void [OH_Drawing_PathAddArc](_drawing.md#oh_drawing_pathaddarc) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*, float startAngle, float sweepAngle) | 将弧添加到路径中，作为新轮廓的起点。从起始角度到扫掠角度添加弧， 添加的弧是椭圆边界椭圆的一部分，单位为度。正扫掠表示按顺时针方向延长弧， 负扫掠表示按逆时针方向延长弧。如果扫掠角度&lt;= -360°，或扫掠角度&gt;= 360°， 并且起始角度对90取模接近于0，则添加椭圆而不是弧。 |
| void [OH_Drawing_PathAddPath](_drawing.md#oh_drawing_pathaddpath) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*src, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 将原路径矩阵变换后，添加到当前路径中。 |
| bool [OH_Drawing_PathContains](_drawing.md#oh_drawing_pathcontains) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 判断指定坐标点是否被路径包含。 |
| void [OH_Drawing_PathTransform](_drawing.md#oh_drawing_pathtransform) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 对路径进行矩阵变换。 |
| void [OH_Drawing_PathSetFillType](_drawing.md#oh_drawing_pathsetfilltype) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, [OH_Drawing_PathFillType](_drawing.md#oh_drawing_pathfilltype)) | 设置填充路径的规则。 |
| void [OH_Drawing_PathClose](_drawing.md#oh_drawing_pathclose) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。 |
| void [OH_Drawing_PathReset](_drawing.md#oh_drawing_pathreset) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 用于重置自定义路径数据。 |
