# drawing_types.h


## 概述

文件中定义了用于绘制2D图形的数据类型，包括画布、画笔、画刷、位图和路径。

**引用文件：**&lt;native_drawing/drawing_types.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) | 定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字。 |
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) | 定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色。 |
| [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) | 定义为画刷，画刷用于描述填充图形的样式和颜色。 |
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) | 定义为路径，路径用于自定义各种形状。 |
| [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) | 定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据。 |
| [OH_Drawing_Point](_drawing.md#oh_drawing_point) | 定义一个点，用于描述坐标点。 |
| [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) | 用于描述矩形。 |
| [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) | 用于描述圆角矩形。 |
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) | 定义一个矩阵，用于描述坐标变换。 |
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) | 定义一个着色器，用于描述绘制内容的源颜色。 |
| [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) | 定义一个滤波器，用于存储颜色滤波器和模板滤波器。 |
| [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) | 定义模板滤波器，用于在绘制模板前对其进行转换。 |
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) | 定义颜色滤波器，传入一个颜色并返回一个新的颜色。 |
| [OH_Drawing_Font](_drawing.md#oh_drawing_font) | 用于描述字体。 |
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) | 用于描述字形。 |
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) | 定义一个文本对象，表示将多个文本组合到一个不可变的容器中。 每个文本行由字形和位置组成。 |
| [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) | 定义文本构建器，用于构建文本。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) {<br/>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br/>} | 用于描述位图像素的存储格式。 |
| [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) {<br/>ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL<br/>} | 用于描述位图像素的透明度分量。 |
| [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) {<br/>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br/>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br/>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br/>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br/>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br/>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br/>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br/>BLEND_MODE_LUMINOSITY<br/>} | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在4个颜色通道（红、绿、蓝、透明度）上是相同的。 对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。 |
