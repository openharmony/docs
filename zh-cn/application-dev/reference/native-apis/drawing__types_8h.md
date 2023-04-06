# drawing_types.h


## 概述

文件中定义了用于绘制2d图形的数据类型，包括画布、画笔、画刷、位图和路径。

**起始版本：**

8

**相关模块：**

[Drawing](_drawing.md)


## 汇总


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) | OH_Drawing_Canvas定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字 |
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) | OH_Drawing_Pen定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色 |
| [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) | OH_Drawing_Brush定义为画刷，画刷用于描述填充图形的样式和颜色 |
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) | OH_Drawing_Path定义为路径，路径用于自定义各种形状 |
| [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) | OH_Drawing_Bitmap定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据 |


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) {  COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,   COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888 } | OH_Drawing_ColorFormat用于描述位图像素的存储格式 |
| [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | OH_Drawing_AlphaFormat用于描述位图像素的透明度分量 |
