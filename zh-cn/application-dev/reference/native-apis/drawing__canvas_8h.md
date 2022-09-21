# drawing_canvas.h


## 概述

文件中定义了与画布相关的功能函数。

**自从：**

8

**相关模块：**

[Drawing](_drawing.md)


## 汇总


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_CanvasCreate](_drawing.md#ohdrawingcanvascreate) (void) | 函数用于创建一个画布对象 |
| [OH_Drawing_CanvasDestroy](_drawing.md#ohdrawingcanvasdestroy) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*) | 函数用于销毁画布对象并回收该对象占有的内存 |
| [OH_Drawing_CanvasBind](_drawing.md#ohdrawingcanvasbind) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*, [OH_Drawing_Bitmap](_drawing.md#ohdrawingbitmap) \*) | 函数用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染） |
| [OH_Drawing_CanvasAttachPen](_drawing.md#ohdrawingcanvasattachpen) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*, const [OH_Drawing_Pen](_drawing.md#ohdrawingpen) \*) | 函数用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓 |
| [OH_Drawing_CanvasDetachPen](_drawing.md#ohdrawingcanvasdetachpen) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*) | 函数用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓 |
| [OH_Drawing_CanvasAttachBrush](_drawing.md#ohdrawingcanvasattachbrush) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*, const [OH_Drawing_Brush](_drawing.md#ohdrawingbrush) \*) | 函数用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状 |
| [OH_Drawing_CanvasDetachBrush](_drawing.md#ohdrawingcanvasdetachbrush) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*) | 函数用于去除掉画布中的画刷，使用后画布将不去填充图形形状 |
| [OH_Drawing_CanvasSave](_drawing.md#ohdrawingcanvassave) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*) | 函数用于保存当前画布的状态（画布矩阵）到一个栈顶 |
| [OH_Drawing_CanvasRestore](_drawing.md#ohdrawingcanvasrestore) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*) | 函数用于恢复保存在栈顶的画布状态（画布矩阵） |
| [OH_Drawing_CanvasDrawLine](_drawing.md#ohdrawingcanvasdrawline) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*, float x1, float y1, float x2, float y2) | 函数用于画一条直线段 |
| [OH_Drawing_CanvasDrawPath](_drawing.md#ohdrawingcanvasdrawpath) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*, const [OH_Drawing_Path](_drawing.md#ohdrawingpath) \*) | 函数用于画一个自定义路径 |
| [OH_Drawing_CanvasClear](_drawing.md#ohdrawingcanvasclear) ([OH_Drawing_Canvas](_drawing.md#ohdrawingcanvas) \*, uint32_t color) | 函数用于使用指定颜色去清空画布 |
