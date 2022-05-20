# drawing_canvas.h


## **Overview**

**Related Modules:**

[Drawing](_drawing.md)

**Description:**

文件中定义了与画布相关的功能函数

**Since:**
8
**Version:**
1.0

## **Summary**


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_Drawing_CanvasCreate](_drawing.md#ga1bfe881a0b018a982678906f3522d4df)&nbsp;(void) | [OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*<br/>函数用于创建一个画布对象 | 
| [OH_Drawing_CanvasDestroy](_drawing.md#ga1a3023ccc48a381cc0b4ae09e2d85c38)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*) | void<br/>函数用于销毁画布对象并回收该对象占有的内存 | 
| [OH_Drawing_CanvasBind](_drawing.md#ga666595bb182a5e31733f4144c1515cae)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*,&nbsp;[OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb)&nbsp;\*) | void<br/>函数用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染） | 
| [OH_Drawing_CanvasAttachPen](_drawing.md#gaaec6db563bd7153dc95d0bfab71a4ed1)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*,&nbsp;const&nbsp;[OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)&nbsp;\*) | void<br/>函数用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓 | 
| [OH_Drawing_CanvasDetachPen](_drawing.md#ga79321b669f2b5dc0460ca929f00dfc47)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*) | void<br/>函数用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓 | 
| [OH_Drawing_CanvasAttachBrush](_drawing.md#ga1b238c829ea5f2ff627766a3e50feaa6)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*,&nbsp;const&nbsp;[OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711)&nbsp;\*) | void<br/>函数用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状 | 
| [OH_Drawing_CanvasDetachBrush](_drawing.md#ga7a6b5e56d2492b5641b8b3f634b096fe)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*) | void<br/>函数用于去除掉画布中的画刷，使用后画布将不去填充图形形状 | 
| [OH_Drawing_CanvasSave](_drawing.md#ga4ebc55405e00ad4b8609303fefc6997a)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*) | void<br/>函数用于保存当前画布的状态（画布矩阵）到一个栈顶 | 
| [OH_Drawing_CanvasRestore](_drawing.md#gadd632be64ccc2601def753ecc1e53944)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*) | void<br/>函数用于恢复保存在栈顶的画布状态（画布矩阵） | 
| [OH_Drawing_CanvasDrawLine](_drawing.md#gadf6bae5efd20587612596f8e78a16144)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*,&nbsp;float&nbsp;x1,&nbsp;float&nbsp;y1,&nbsp;float&nbsp;x2,&nbsp;float&nbsp;y2) | void<br/>函数用于画一条直线段 | 
| [OH_Drawing_CanvasDrawPath](_drawing.md#ga99ebc73abdc27599f4bcc1c1045cb75e)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*,&nbsp;const&nbsp;[OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)&nbsp;\*) | void<br/>函数用于画一个自定义路径 | 
| [OH_Drawing_CanvasClear](_drawing.md#ga7f07cc6f0b223d9b343c133fbb2503f6)&nbsp;([OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)&nbsp;\*,&nbsp;uint32_t&nbsp;color) | void<br/>函数用于使用指定颜色去清空画布 | 
