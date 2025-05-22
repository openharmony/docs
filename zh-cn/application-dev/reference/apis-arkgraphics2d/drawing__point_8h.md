# drawing_point.h


## 概述

文件中定义了与坐标点相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_point.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Point](_drawing.md#oh_drawing_point) \* [OH_Drawing_PointCreate](_drawing.md#oh_drawing_pointcreate) (float x, float y) | 用于创建一个坐标点对象。 |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_PointGetX](_drawing.md#oh_drawing_pointgetx) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*point, float \*x) | 用于获取点的x轴坐标。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_PointGetY](_drawing.md#oh_drawing_pointgety) (const [OH_Drawing_Point](_drawing.md#oh_drawing_point) \*point, float \*y) | 用于获取点的y轴坐标。 | 
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode) [OH_Drawing_PointSet](_drawing.md#oh_drawing_pointset) ([OH_Drawing_Point](_drawing.md#oh_drawing_point) \*point, float x, float y) | 用于设置点的x轴和y轴坐标。 | 
| void [OH_Drawing_PointDestroy](_drawing.md#oh_drawing_pointdestroy) ([OH_Drawing_Point](_drawing.md#oh_drawing_point) \*) | 用于销毁坐标点对象并回收该对象占有的内存。 |
