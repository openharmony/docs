# drawing_matrix.h


## 概述

文件中定义了与矩阵相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_matrix.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](_drawing.md#oh_drawing_matrixcreate) (void) | 用于创建一个矩阵对象。 |
| void [OH_Drawing_MatrixSetMatrix](_drawing.md#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | 用于给矩阵对象设置参数。 |
| void [OH_Drawing_MatrixDestroy](_drawing.md#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 用于销毁矩阵对象并回收该对象占有的内存。 |
