# drawing_matrix.h


## 概述

文件中定义了与矩阵相关的功能函数。

**引用文件：**&lt;native_drawing/drawing_matrix.h&gt;

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_ScaleToFit](_drawing.md#oh_drawing_scaletofit)  [OH_Drawing_ScaleToFit](_drawing.md#oh_drawing_scaletofit) | 矩阵缩放方式枚举。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ScaleToFit](_drawing.md#oh_drawing_scaletofit) { SCALE_TO_FIT_FILL, SCALE_TO_FIT_START, SCALE_TO_FIT_CENTER, SCALE_TO_FIT_END } | 矩阵缩放方式枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ErrorCode](_drawing.md#oh_drawing_errorcode)  [OH_Drawing_MatrixGetAll](_drawing.md#oh_drawing_matrixgetall) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*matrix, float value[9]) | 获取矩阵所有元素值。 |
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](_drawing.md#oh_drawing_matrixcreate) (void) | 用于创建一个矩阵对象。 | 
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateRotation](_drawing.md#oh_drawing_matrixcreaterotation) (float deg, float x, float y) | 创建一个带旋转属性的矩阵对象。 该矩阵对象为：单位矩阵在(x, y)旋转点以度为单位进行旋转后得到的矩阵。 | 
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateScale](_drawing.md#oh_drawing_matrixcreatescale) (float sx, float sy, float px, float py) | 创建一个带缩放属性的矩阵对象。 该矩阵对象为：单位矩阵在(px, py)旋转点以sx和sy为缩放因子进行缩放后得到的矩阵。 | 
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateTranslation](_drawing.md#oh_drawing_matrixcreatetranslation) (float dx, float dy) | 创建一个带平移属性的矩阵对象。 该矩阵对象为：单位矩阵平移(dx, dy)后得到的矩阵。 | 
| void [OH_Drawing_MatrixSetMatrix](_drawing.md#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | 用于给矩阵对象设置参数。 | 
| bool [OH_Drawing_MatrixSetRectToRect](_drawing.md#oh_drawing_matrixsetrecttorect) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst, [OH_Drawing_ScaleToFit](_drawing.md#oh_drawing_scaletofit) stf) | 将矩阵以缩放方式适配目标矩阵。 | 
| void [OH_Drawing_MatrixPreRotate](_drawing.md#oh_drawing_matrixprerotate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float degree, float px, float py) | 将矩阵设置为矩阵左乘围绕轴心点旋转一定角度的单位矩阵后得到的矩阵。 | 
| void [OH_Drawing_MatrixPreScale](_drawing.md#oh_drawing_matrixprescale) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | 将矩阵设置为矩阵左乘围绕轴心点按一定缩放因子缩放后的单位矩阵后得到的矩阵。 | 
| void [OH_Drawing_MatrixPreTranslate](_drawing.md#oh_drawing_matrixpretranslate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float dx, float dy) | 将矩阵设置为矩阵左乘平移一定距离后的单位矩阵后得到的矩阵。 | 
| void [OH_Drawing_MatrixPostRotate](_drawing.md#oh_drawing_matrixpostrotate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float degree, float px, float py) | 将矩阵设置为矩阵右乘围绕轴心点旋转一定角度的单位矩阵后得到的矩阵。  | 
| void [OH_Drawing_MatrixPostScale](_drawing.md#oh_drawing_matrixpostscale) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | 将矩阵设置为矩阵右乘围绕轴心点按一定缩放因子缩放后的单位矩阵后得到的矩阵。 | 
| void [OH_Drawing_MatrixPostTranslate](_drawing.md#oh_drawing_matrixposttranslate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float dx, float dy) | 将矩阵设置为矩阵右乘平移一定距离后的单位矩阵后得到的矩阵。 | 
| void [OH_Drawing_MatrixReset](_drawing.md#oh_drawing_matrixreset) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 重置当前矩阵为单位矩阵。 | 
| void [OH_Drawing_MatrixConcat](_drawing.md#oh_drawing_matrixconcat) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*total, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*a, const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*b) | 将矩阵total设置为矩阵a乘以矩阵b。 | 
| float [OH_Drawing_MatrixGetValue](_drawing.md#oh_drawing_matrixgetvalue) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, int index) | 获取矩阵给定索引位的值。索引范围0-8。 | 
| void [OH_Drawing_MatrixRotate](_drawing.md#oh_drawing_matrixrotate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float degree, float px, float py) | 设置矩阵为单位矩阵，并围绕位于(px, py)的旋转轴点进行旋转。 | 
| void [OH_Drawing_MatrixTranslate](_drawing.md#oh_drawing_matrixtranslate) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float dx, float dy) | 设置矩阵为单位矩阵，并平移(dx, dy)。 | 
| void [OH_Drawing_MatrixScale](_drawing.md#oh_drawing_matrixscale) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | 设置矩阵为单位矩阵，并围绕位于(px, py)的旋转轴点，以sx和sy进行缩放。 | 
| bool [OH_Drawing_MatrixInvert](_drawing.md#oh_drawing_matrixinvert) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*inverse) | 将矩阵inverse设置为矩阵的倒数，并返回结果。 | 
| bool [OH_Drawing_MatrixSetPolyToPoly](_drawing.md#oh_drawing_matrixsetpolytopoly) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*src, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*dst, uint32_t count) | 通过设置源点以及目标点，生成对应的变换矩阵。 源点以及目标点的个数要大于等于0，小于等于4。 | 
| void [OH_Drawing_MatrixMapPoints](_drawing.md#oh_drawing_matrixmappoints) (const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*src, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*dst, int count) | 通过矩阵变换将源点数组映射到目标点数组。 | 
| bool [OH_Drawing_MatrixMapRect](_drawing.md#oh_drawing_matrixmaprect) (const [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*src, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*dst) | 将目标矩形设置为一个新的矩形，该矩形是能够包围源矩形的四个顶点通过矩阵变换映射后形成的新顶点的最小矩形。 | 
| bool [OH_Drawing_MatrixIsEqual](_drawing.md#oh_drawing_matrixisequal) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*, [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*other) | 判断两个矩阵是否相等。 | 
| bool [OH_Drawing_MatrixIsIdentity](_drawing.md#oh_drawing_matrixisidentity) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 判断矩阵是否是单位矩阵。 | 
| void [OH_Drawing_MatrixDestroy](_drawing.md#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) \*) | 用于销毁矩阵对象并回收该对象占有的内存。 | 
