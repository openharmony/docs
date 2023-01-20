# drawing_path.h


## 概述

文件中定义了与自定义路径相关的功能函数。

**起始版本：**

8

**相关模块：**

[Drawing](_drawing.md)


## 汇总


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_PathCreate](_drawing.md#oh_drawing_pathcreate) (void) | 函数用于创建一个路径对象 |
| [OH_Drawing_PathDestroy](_drawing.md#oh_drawing_pathdestroy) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 函数用于销毁路径对象并回收该对象占有的内存 |
| [OH_Drawing_PathMoveTo](_drawing.md#oh_drawing_pathmoveto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 函数用于设置自定义路径的起始点位置 |
| [OH_Drawing_PathLineTo](_drawing.md#oh_drawing_pathlineto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x, float y) | 函数用于添加一条从路径的最后点位置到目标点位置的线段 |
| [OH_Drawing_PathArcTo](_drawing.md#oh_drawing_patharcto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | 函数用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆， 然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段 |
| [OH_Drawing_PathQuadTo](_drawing.md#oh_drawing_pathquadto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | 函数用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线 |
| [OH_Drawing_PathCubicTo](_drawing.md#oh_drawing_pathcubicto) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | 函数用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线 |
| [OH_Drawing_PathClose](_drawing.md#oh_drawing_pathclose) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 函数用于闭合路径，会添加一条从路径起点位置到最后点位置的线段 |
| [OH_Drawing_PathReset](_drawing.md#oh_drawing_pathreset) ([OH_Drawing_Path](_drawing.md#oh_drawing_path) \*) | 函数用于重置自定义路径数据 |
