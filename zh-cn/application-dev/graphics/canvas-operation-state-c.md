# 画布操作及状态处理（C/C++）


## 场景介绍

创建或获取得到Canvas画布之后，可以基于画布进一步地进行图形操作和状态处理。画布操作属于可选操作，开发者可以根据场景需要进行。需要先进行画布操作，再进行后续绘制，只有这样画布操作才有效果。

常见的画布操作如下：

- 裁剪。

- 矩阵变换，如平移、缩放、旋转等。

- 状态保存与恢复。


## 裁剪操作

裁剪是图形处理中的常见操作，裁剪针对的是画布本身，可以用于限制绘图区域，只在指定的区域内容进行绘制。需要先进行裁剪操作，再进行绘制，才会有对应效果。

当前支持的裁剪操作主要如下：

- 裁剪矩形。

- 裁剪圆角矩形。

- 裁剪自定义路径。

- 裁剪一个区域。


### 接口说明

裁剪操作常用接口如下表所示，详细的使用和参数说明请见[drawing_canvas.h](../reference/apis-arkgraphics2d/drawing__canvas_8h.md)。

| 接口 | 描述 |
| -------- | -------- |
| void OH_Drawing_CanvasClipRect (OH_Drawing_Canvas \*, const OH_Drawing_Rect \*, OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias) | 用于裁剪一个矩形。 |
| void OH_Drawing_CanvasClipRoundRect (OH_Drawing_Canvas \*, const OH_Drawing_RoundRect \*, OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias) | 用于裁剪一个圆角矩形。 |
| void OH_Drawing_CanvasClipPath (OH_Drawing_Canvas \*, const OH_Drawing_Path \*, OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias) | 用于裁剪一个自定义路径。 |
| OH_Drawing_ErrorCode OH_Drawing_CanvasClipRegion (OH_Drawing_Canvas \*canvas, const OH_Drawing_Region \*region, OH_Drawing_CanvasClipOp clipOp) | 用于裁剪一个区域。 |


### 开发示例

此处以在画布上裁剪矩形为例给出示例和效果图，其他裁剪操作的逻辑基本相同，注意调用对应的接口并确保要裁剪的数据类型对应准确即可，此处不再一一展开。具体详细的使用和参数说明请见[drawing_canvas.h](../reference/apis-arkgraphics2d/drawing__canvas_8h.md)。

使用OH_Drawing_CanvasClipRect接口裁剪矩形。有以下四个入参：
- 第一个参数是画布Canvas，裁剪操作将在这个画布上进行。请确保已创建或获取得到画布Canvas，具体可见[画布的获取与绘制结果的显示（C/C++）](canvas-get-result-draw-c.md)。

- 第二个参数是要裁剪的矩形区域。

- 第三个参数是裁剪的操作类型，包括交集（INTERSECT）和差集（DIFFERENCE）。

- 第四个参数表示是否需要进行抗锯齿处理。

```c++
// 创建画刷对象
OH_Drawing_Brush *brush = OH_Drawing_BrushCreate();
// 设置画刷填充颜色为蓝色
OH_Drawing_BrushSetColor(brush, 0xff0000ff);
// 在画布中设置画刷
OH_Drawing_CanvasAttachBrush(canvas, brush); 
OH_Drawing_Rect *rect = OH_Drawing_RectCreate(400, 400, 1200, 1200);
// 裁剪矩形区域
OH_Drawing_CanvasClipRect(canvas, rect, OH_Drawing_CanvasClipOp::INTERSECT, true); 
OH_Drawing_Point *point = OH_Drawing_PointCreate(600, 600);
// 绘制圆形
OH_Drawing_CanvasDrawCircle(canvas, point, 600); 
// 去除画布中的画刷
OH_Drawing_CanvasDetachBrush(canvas);
// 销毁画刷对象并收回其占的内存
OH_Drawing_BrushDestroy(brush);
```

| 原始图 | 裁剪后的图 |
| -------- | -------- |
| ![Screenshot_20250120154655737](figures/Screenshot_20250120154655737.jpg) | ![Screenshot_20250118152812670](figures/Screenshot_20250118152812670.jpg) |


## 矩阵变化操作

矩阵变换也是常见的画布操作，是一种坐标系的转换，用于进行图形的变化。

当前支持的矩阵变换主要如下：

- 平移

- 缩放

- 旋转


### 接口说明

矩阵变换操作常用接口如下表所示，详细的使用和参数说明请见[drawing_matrix.h](../reference/apis-arkgraphics2d/drawing__matrix_8h.md)。

| 接口 | 描述 |
| -------- | -------- |
| void OH_Drawing_CanvasTranslate (OH_Drawing_Canvas \*, float dx, float dy) | 用于平移画布一段距离。 |
| void OH_Drawing_CanvasScale (OH_Drawing_Canvas \*, float sx, float sy) | 用于画布缩放。 |
| void OH_Drawing_CanvasRotate (OH_Drawing_Canvas \*, float degrees, float px, float py) | 用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。 |
| void OH_Drawing_CanvasSkew (OH_Drawing_Canvas \*, float sx, float sy) | 用于画布倾斜变换。等同于将当前画布矩阵左乘（premultiply）倾斜变换矩阵，并应用到画布上。其中倾斜变换矩阵为：\|1 sx 0\| \|sy 1 0\| \|0 0 1\|。 |


### 平移

使用OH_Drawing_MatrixCreateTranslation()接口实现画布平移。接口接受2个参数，分别为水平方向和垂直方向的平移量，单位为px。

简单示例和示意图如下所示：

```c++
// 创建画刷对象
OH_Drawing_Brush* brush = OH_Drawing_BrushCreate();
// 设置填充颜色
OH_Drawing_BrushSetColor(brush, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
// 设置画布中的画刷
OH_Drawing_CanvasAttachBrush(canvas, brush); 
// 创建在水平和垂直方向分别平移300px的矩阵对象
OH_Drawing_Matrix *matrix = OH_Drawing_MatrixCreateTranslation(300, 300); 
// 对Canvas进行矩阵变换
OH_Drawing_CanvasConcatMatrix(canvas, matrix);
// 绘制矩形
OH_Drawing_Rect *rect = OH_Drawing_RectCreate(200, 300, 700, 600); 
OH_Drawing_CanvasDrawRect(canvas, rect);
// 去除画布中的画刷
OH_Drawing_CanvasDetachBrush(canvas);
OH_Drawing_RectDestroy(rect);
OH_Drawing_MatrixDestroy(matrix);
```

| 原始图 | 平移后的效果图 |
| -------- | -------- |
| ![zh-cn_image_0000002194110929](figures/zh-cn_image_0000002194110929.png) | ![zh-cn_image_0000002194025285](figures/zh-cn_image_0000002194025285.png) |


### 旋转

使用OH_Drawing_MatrixCreateRotation()接口实现画布旋转，接口接受3个参数，分别为：旋转角度、旋转中心的x坐标和y坐标。

简单示例和示意图如下所示：

```c++
// 创建画刷对象
OH_Drawing_Brush* brush = OH_Drawing_BrushCreate();
// 设置填充颜色
OH_Drawing_BrushSetColor(brush, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
// 设置画布中的画刷
OH_Drawing_CanvasAttachBrush(canvas, brush); 
// 创建旋转的矩阵对象，三个参数分别是旋转角度和旋转中心坐标
OH_Drawing_Matrix* matrix = OH_Drawing_MatrixCreateRotation(45, 200, 300);
// 对Canvas进行矩阵变换
OH_Drawing_CanvasConcatMatrix(canvas, matrix);
// 绘制矩形
OH_Drawing_Rect *rect = OH_Drawing_RectCreate(200, 300, 700, 600); 
OH_Drawing_CanvasDrawRect(canvas, rect);
// 去除画布中的画刷
OH_Drawing_CanvasDetachBrush(canvas);
OH_Drawing_RectDestroy(rect);
OH_Drawing_MatrixDestroy(matrix);
```

| 原始图 | 旋转后的效果图 |
| -------- | -------- |
| ![zh-cn_image_0000002158584410](figures/zh-cn_image_0000002158584410.png) | ![zh-cn_image_0000002158584398](figures/zh-cn_image_0000002158584398.png) |


### 缩放

使用OH_Drawing_MatrixCreateScale()接口进行画布缩放，接口接受4个参数，分别为沿x轴和y轴的缩放因子、旋转中心的x轴和y轴坐标。

简单示例和示意图如下所示：

```c++
// 创建画刷对象
OH_Drawing_Brush* brush = OH_Drawing_BrushCreate();
// 设置填充颜色
OH_Drawing_BrushSetColor(brush, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
// 设置画布中的画刷
OH_Drawing_CanvasAttachBrush(canvas, brush); 
// 创建缩放的矩阵对象，4个参数分别是旋转中心坐标和水平垂直方向的缩放因子
OH_Drawing_Matrix* matrix = OH_Drawing_MatrixCreateScale(2, 2, 200, 300);
// 对Canvas进行矩阵变换
OH_Drawing_CanvasConcatMatrix(canvas, matrix);
// 绘制矩形
OH_Drawing_Rect *rect = OH_Drawing_RectCreate(200, 300, 700, 600); 
OH_Drawing_CanvasDrawRect(canvas, rect);
// 去除画布中的画刷
OH_Drawing_CanvasDetachBrush(canvas);
OH_Drawing_RectDestroy(rect);
```

| 原始图 | 放大后的效果图 |
| -------- | -------- |
| ![zh-cn_image_0000002194110925](figures/zh-cn_image_0000002194110925.png) | ![zh-cn_image_0000002158584402](figures/zh-cn_image_0000002158584402.png) |


## 画布状态保存与恢复

保存操作用于保存当前画布的状态到一个栈顶，恢复操作用于恢复保存在栈顶的画布状态，恢复操作一旦执行，保存和恢复操作中间一系列平移、缩放、剪裁等操作都会被清除。


### 接口说明

画布状态保存与恢复使用的接口如下表所示，详细的使用和参数说明请见[drawing_canvas.h](../reference/apis-arkgraphics2d/drawing__canvas_8h.md)。

| 接口 | 描述 |
| -------- | -------- |
| void OH_Drawing_CanvasSave (OH_Drawing_Canvas \*) | 用于保存当前画布的状态（画布矩阵）到一个栈顶。 |
| void OH_Drawing_CanvasRestore (OH_Drawing_Canvas \*) | 用于恢复保存在栈顶的画布状态（画布矩阵）。 |
| void OH_Drawing_CanvasRestoreToCount (OH_Drawing_Canvas \*, uint32_t saveCount) | 用于恢复到指定数量的画布状态（画布矩阵）。 |


### 开发示例

```c++
// 创建画笔对象
OH_Drawing_Pen* pen = OH_Drawing_PenCreate();
// 设置画笔描边颜色
OH_Drawing_PenSetColor(pen, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
// 设置画笔线宽
OH_Drawing_PenSetWidth(pen, 20);
// 在画布中设置画笔
OH_Drawing_CanvasAttachPen(canvas, pen);
// 保存当前画布状态，当前是不存在放大等操作的，这个原始状态会被保存下来
OH_Drawing_CanvasSave(canvas); 
OH_Drawing_Matrix *matrix = OH_Drawing_MatrixCreateScale(2, 2, 2, 2);
// 放大画布
OH_Drawing_CanvasConcatMatrix(canvas, matrix); 
OH_Drawing_Point* point = OH_Drawing_PointCreate(300, 300);
// 绘制圆形，因为执行过放大操作，所以此时绘制的是大圆
OH_Drawing_CanvasDrawCircle(canvas, point, 200); 
// 恢复操作，将恢复到没有放大的原始状态
OH_Drawing_CanvasRestore(canvas); 
// 绘制圆形，因为已经恢复没有放大的原始状态，所以此时绘制的小圆
OH_Drawing_CanvasDrawCircle(canvas, point, 200); 
// 去除画布中的画笔
OH_Drawing_CanvasDetachPen(canvas);
// 销毁画笔对象并收回其占的内存
OH_Drawing_PenDestroy(pen);
OH_Drawing_PointDestroy(point);
OH_Drawing_MatrixDestroy(matrix);
```

![zh-cn_image_0000002158744186](figures/zh-cn_image_0000002158744186.png)

<!--RP1-->
## 相关实例

针对Drawing(C/C++)的开发，有以下相关实例可供参考：

- [NDKGraphicsDraw (API14)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Drawing/NDKGraphicsDraw)
<!--RP1End-->