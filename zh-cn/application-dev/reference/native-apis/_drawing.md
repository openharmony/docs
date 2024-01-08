# Drawing


## 概述

Drawing模块提供包括2D图形渲染、文字绘制和图片显示等功能函数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [drawing_bitmap.h](drawing__bitmap_8h.md) | 文件中定义了与位图相关的功能函数。 |
| [drawing_brush.h](drawing__brush_8h.md) | 文件中定义了与画刷相关的功能函数。 |
| [drawing_canvas.h](drawing__canvas_8h.md) | 文件中定义了与画布相关的功能函数。 |
| [drawing_color.h](drawing__color_8h.md) | 文件中定义了与颜色相关的功能函数。 |
| [drawing_color_filter.h](drawing__color__filter_8h.md) | 声明与绘图模块中的颜色滤波器对象相关的函数。 |
| [drawing_filter.h](drawing__filter_8h.md) | 声明与绘图模块中的滤波器对象相关的函数。 |
| [drawing_font.h](drawing__font_8h.md) | 文件中定义了与字体相关的功能函数。 |
| [drawing_font_collection.h](drawing__font__collection_8h.md) | 定义绘制模块中与字体集合相关的函数。 |
| [drawing_mask_filter.h](drawing__mask__filter_8h.md) | 声明与绘图模块中的对象相关的函数。 |
| [drawing_matrix.h](drawing__matrix_8h.md) | 文件中定义了与矩阵相关的功能函数。 |
| [drawing_path.h](drawing__path_8h.md) | 文件中定义了与自定义路径相关的功能函数 |
| [drawing_pen.h](drawing__pen_8h.md) | 文件中定义了与画笔相关的功能函数。 |
| [drawing_point.h](drawing__point_8h.md) | 文件中定义了与坐标点相关的功能函数。 |
| [drawing_rect.h](drawing__rect_8h.md) | 文件中定义了与矩形相关的功能函数。 |
| [drawing_round_rect.h](drawing__round__rect_8h.md) | 文件中定义了与圆角矩形相关的功能函数。 |
| [drawing_shader_effect.h](drawing__shader__effect_8h.md) | 声明与绘图模块中的着色器对象相关的函数。 |
| [drawing_text_blob.h](drawing__text__blob_8h.md) | 文件中定义了与文字相关的功能函数。 |
| [drawing_text_declaration.h](drawing__text__declaration_8h.md) | 提供2D绘制文本相关的数据结构声明。 |
| [drawing_text_typography.h](drawing__text__typography_8h.md) | 定义绘制模块中排版相关的函数。 |
| [drawing_typeface.h](drawing__typeface_8h.md) | 文件中定义了与字形相关的功能函数。 不同的平台有自己的默认字形，也可以从ttf文件解析出三方指定字形，如宋体、黑体字形等。 |
| [drawing_types.h](drawing__types_8h.md) | 文件中定义了用于绘制2D图形的数据类型，包括画布、画笔、画刷、位图和路径。 |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型。 |
| [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) | 结构体用于描述一块内存，描述文字和位置信息。 |
| [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | 用于描述位占位符跨度的结构体。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection) | 用于加载字体。 |
| [OH_Drawing_Typography](#oh_drawing_typography) | 用于管理排版的布局和显示等。 |
| [OH_Drawing_TextStyle](#oh_drawing_textstyle) | 用于管理字体颜色、装饰等。 |
| [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) | 用于管理排版风格，如文字方向等。 |
| [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) | 用于创建[OH_Drawing_Typography](#oh_drawing_typography)。 |
| [OH_Drawing_TextBox](#oh_drawing_textbox) | 用于接收文本框的矩形大小、方向和数量大小 |
| [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) | 用于接收字体的位置和亲和性 |
| [OH_Drawing_Range](#oh_drawing_range) | 用于接收字体的起始位置和结束位置 |
| [OH_Drawing_Canvas](#oh_drawing_canvas) | 定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字。 |
| [OH_Drawing_Pen](#oh_drawing_pen) | 定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色。 |
| [OH_Drawing_Brush](#oh_drawing_brush) | 定义为画刷，画刷用于描述填充图形的样式和颜色。 |
| [OH_Drawing_Path](#oh_drawing_path) | 定义为路径，路径用于自定义各种形状。 |
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) | 定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据。 |
| [OH_Drawing_Point](#oh_drawing_point) | 定义一个点，用于描述坐标点。 |
| [OH_Drawing_Rect](#oh_drawing_rect) | 用于描述矩形。 |
| [OH_Drawing_RoundRect](#oh_drawing_roundrect) | 用于描述圆角矩形。 |
| [OH_Drawing_Matrix](#oh_drawing_matrix) | 定义一个矩阵，用于描述坐标变换。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) | 定义一个着色器，用于描述绘制内容的源颜色。 |
| [OH_Drawing_Filter](#oh_drawing_filter) | 定义一个滤波器，用于存储颜色滤波器和模板滤波器。 |
| [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) | 定义模板滤波器，用于在绘制模板前对其进行转换。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) | 定义颜色滤波器，传入一个颜色并返回一个新的颜色。 |
| [OH_Drawing_Font](#oh_drawing_font) | 用于描述字体。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) | 用于描述字形。 |
| [OH_Drawing_TextBlob](#oh_drawing_textblob) | 定义一个文本对象，表示将多个文本组合到一个不可变的容器中。 每个文本行由字形和位置组成。 |
| [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) | 定义文本构建器，用于构建文本。 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) { DIFFERENCE, INTERSECT } | 画布裁剪方式的枚举集合。 |
| [OH_Drawing_BlurType](#oh_drawing_blurtype) { NORMAL, SOLID, OUTER, INNER } | 枚举模糊类型。 |
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。 |
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。 |
| [OH_Drawing_TileMode](#oh_drawing_tilemode) { CLAMP, REPEAT, MIRROR, DECAL } | 着色器效果平铺模式的枚举。 |
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | 文字方向。 |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) {<br/>TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,<br/>TEXT_ALIGN_START, TEXT_ALIGN_END<br/>} | 文字对齐方式。 |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) {<br/>FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,<br/>FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,<br/>FONT_WEIGHT_900<br/>} | 字重。 |
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) {<br/>TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC<br/>} | 基线位置。 |
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) {<br/>TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4<br/>} | 文本装饰。 |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) {<br/>FONT_STYLE_NORMAL, FONT_STYLE_ITALIC<br/>} | 区分字体是否为斜体。 |
| [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment) {<br/>ALIGNMENT_OFFSET_AT_BASELINE, ALIGNMENT_ABOVE_BASELINE, ALIGNMENT_BELOW_BASELINE, ALIGNMENT_TOP_OF_ROW_BOX,<br/>ALIGNMENT_BOTTOM_OF_ROW_BOX, ALIGNMENT_CENTER_OF_ROW_BOX<br/>} | 占位符垂直对齐枚举。 |
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) {<br/>TEXT_DECORATION_STYLE_SOLID, TEXT_DECORATION_STYLE_DOUBLE, TEXT_DECORATION_STYLE_DOTTED, TEXT_DECORATION_STYLE_DASHED,<br/>TEXT_DECORATION_STYLE_WAVY<br/>} | 文本装饰样式枚举。 |
| [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) {<br/>ELLIPSIS_MODAL_HEAD = 0, ELLIPSIS_MODAL_MIDDLE = 1, ELLIPSIS_MODAL_TAIL = 2<br/>} | 省略号样式枚举。 |
| [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) {<br/>BREAK_STRATEGY_GREEDY = 0, BREAK_STRATEGY_HIGH_QUALITY = 1, BREAK_STRATEGY_BALANCED = 2<br/>} | 文本的中断策略枚举。 |
| [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) {<br/>WORD_BREAK_TYPE_NORMAL = 0, WORD_BREAK_TYPE_BREAK_ALL = 1, WORD_BREAK_TYPE_BREAK_WORD = 2<br/>} | 单词的断词方式枚举。 |
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) {<br/>RECT_HEIGHT_STYLE_TIGHT, RECT_HEIGHT_STYLE_MAX, RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE, RECT_HEIGHT_STYLE_INCLUDELINESPACETOP,<br/>RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM, RECT_HEIGHT_STYLE_STRUCT<br/>} | 矩形框高度样式枚举。 |
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) {<br/>RECT_WIDTH_STYLE_TIGHT, RECT_WIDTH_STYLE_MAX<br/>} | 矩形框宽度样式枚举。 |
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat) {<br/>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,<br/>COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br/>} | 用于描述位图像素的存储格式。 |
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) {<br/>ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL<br/>} | 用于描述位图像素的透明度分量。 |
| [OH_Drawing_BlendMode](#oh_drawing_blendmode) {<br/>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br/>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br/>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br/>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br/>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br/>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br/>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br/>BLEND_MODE_LUMINOSITY<br/>} | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在4个颜色通道（红、绿、蓝、透明度）上是相同的。 对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreate](#oh_drawing_bitmapcreate) (void) | 用于创建一个位图对象。 |
| void [OH_Drawing_BitmapDestroy](#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于销毁位图对象并回收该对象占有内存。 |
| void [OH_Drawing_BitmapBuild](#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | 用于初始化位图对象的宽度和高度，并且为该位图设置像素格式。 |
| uint32_t [OH_Drawing_BitmapGetWidth](#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于获取指定位图的宽度。 |
| uint32_t [OH_Drawing_BitmapGetHeight](#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于获取指定位图的高度。 |
| void \* [OH_Drawing_BitmapGetPixels](#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据。 |
| [OH_Drawing_Brush](#oh_drawing_brush) \* [OH_Drawing_BrushCreate](#oh_drawing_brushcreate) (void) | 用于创建一个画刷对象。 |
| void [OH_Drawing_BrushDestroy](#oh_drawing_brushdestroy) ([OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于销毁画刷对象并回收该对象占有的内存。 |
| bool [OH_Drawing_BrushIsAntiAlias](#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 |
| void [OH_Drawing_BrushSetAntiAlias](#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](#oh_drawing_brush) \*, bool) | 用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 |
| uint32_t [OH_Drawing_BrushGetColor](#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。 |
| void [OH_Drawing_BrushSetColor](#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint32_t color) | 用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。 |
| uint8_t [OH_Drawing_BrushGetAlpha](#oh_drawing_brushgetalpha) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 获取画刷的透明度值。画刷在填充形状时透明通道会使用该值。 |
| void [OH_Drawing_BrushSetAlpha](#oh_drawing_brushsetalpha) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint8_t alpha) | 为画刷设置透明度值。画刷在填充形状时透明通道会使用该值。 |
| void [OH_Drawing_BrushSetShaderEffect](#oh_drawing_brushsetshadereffect) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | 为画刷设置着色器效果。 |
| void [OH_Drawing_BrushSetFilter](#oh_drawing_brushsetfilter) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | 为画刷设置滤波器[OH_Drawing_Filter](#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。 |
| [OH_Drawing_Canvas](#oh_drawing_canvas) \* [OH_Drawing_CanvasCreate](#oh_drawing_canvascreate) (void) | 用于创建一个画布对象。 |
| void [OH_Drawing_CanvasDestroy](#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于销毁画布对象并回收该对象占有的内存。 |
| void [OH_Drawing_CanvasBind](#oh_drawing_canvasbind) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。 |
| void [OH_Drawing_CanvasAttachPen](#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。 |
| void [OH_Drawing_CanvasDetachPen](#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。 |
| void [OH_Drawing_CanvasAttachBrush](#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。 |
| void [OH_Drawing_CanvasDetachBrush](#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于去除掉画布中的画刷，使用后画布将不去填充图形形状。 |
| void [OH_Drawing_CanvasSave](#oh_drawing_canvassave) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于保存当前画布的状态（画布矩阵）到一个栈顶。 |
| void [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于恢复保存在栈顶的画布状态（画布矩阵）。 |
| uint32_t [OH_Drawing_CanvasGetSaveCount](#oh_drawing_canvasgetsavecount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于获取栈中保存的画布状态（画布矩阵）的数量。 |
| void [OH_Drawing_CanvasRestoreToCount](#oh_drawing_canvasrestoretocount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t saveCount) | 用于恢复到指定数量的画布状态（画布矩阵）。 |
| void [OH_Drawing_CanvasDrawLine](#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | 用于画一条直线段。 |
| void [OH_Drawing_CanvasDrawPath](#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*) | 用于画一个自定义路径。 |
| void [OH_Drawing_CanvasDrawBitmap](#oh_drawing_canvasdrawbitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, float left, float top) | 用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。 |
| void [OH_Drawing_CanvasDrawRect](#oh_drawing_canvasdrawrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于画一个矩形。 |
| void [OH_Drawing_CanvasDrawCircle](#oh_drawing_canvasdrawcircle) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Point](#oh_drawing_point) \*, float radius) | 用于画一个圆形。 |
| void [OH_Drawing_CanvasDrawOval](#oh_drawing_canvasdrawoval) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于画一个椭圆。 |
| void [OH_Drawing_CanvasDrawArc](#oh_drawing_canvasdrawarc) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, float startAngle, float sweepAngle) | 用于画一个弧。 |
| void [OH_Drawing_CanvasDrawRoundRect](#oh_drawing_canvasdrawroundrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*) | 用于画一个圆角矩形。 |
| void [OH_Drawing_CanvasDrawTextBlob](#oh_drawing_canvasdrawtextblob) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_TextBlob](#oh_drawing_textblob) \*, float x, float y) | 用于画一段文字。 |
| uint32_t [OH_Drawing_ColorSetArgb](#oh_drawing_colorsetargb) (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue) | 用于将4个变量（分别描述透明度、红色、绿色和蓝色）转化为一个描述颜色的32位（ARGB）变量。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateBlendMode](#oh_drawing_colorfiltercreateblendmode) (uint32_t color, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | 创建具有混合模式的颜色滤波器。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateCompose](#oh_drawing_colorfiltercreatecompose) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter1, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter2) | 将两个颜色滤波器合成一个新的颜色滤波器。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateMatrix](#oh_drawing_colorfiltercreatematrix) (const float matrix[20]) | 创建具有5x4颜色矩阵的颜色滤波器。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLinearToSrgbGamma](#oh_drawing_colorfiltercreatelineartosrgbgamma) (void) | 创建一个颜色滤波器将SRGB的伽玛曲线应用到RGB颜色通道。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateSrgbGammaToLinear](#oh_drawing_colorfiltercreatesrgbgammatolinear) (void) | 创建颜色滤波器将RGB颜色通道应用于SRGB的伽玛曲线。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLuma](#oh_drawing_colorfiltercreateluma) (void) | 创建一个颜色滤波器将其输入的亮度值乘以透明度通道， 并将红色、绿色和蓝色通道设置为零。 |
| void [OH_Drawing_ColorFilterDestroy](#oh_drawing_colorfilterdestroy) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | 销毁颜色滤波器对象，并收回该对象占用的内存。 |
| [OH_Drawing_Filter](#oh_drawing_filter) \* [OH_Drawing_FilterCreate](#oh_drawing_filtercreate) (void) | 创建一个滤波器对象。 |
| void [OH_Drawing_FilterSetMaskFilter](#oh_drawing_filtersetmaskfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | 为滤波器对象设置蒙板滤波器对象。 |
| void [OH_Drawing_FilterSetColorFilter](#oh_drawing_filtersetcolorfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | 为滤波器对象设置颜色滤波器对象。 |
| void [OH_Drawing_FilterDestroy](#oh_drawing_filterdestroy) ([OH_Drawing_Filter](#oh_drawing_filter) \*) | 销毁滤波器对象，并收回该对象占用的内存。 |
| [OH_Drawing_Font](#oh_drawing_font) \* [OH_Drawing_FontCreate](#oh_drawing_fontcreate) (void) | 用于创建一个字体对象。 |
| void [OH_Drawing_FontSetTypeface](#oh_drawing_fontsettypeface) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_Typeface](#oh_drawing_typeface) \*) | 用于给字体设置字形。 |
| void [OH_Drawing_FontSetTextSize](#oh_drawing_fontsettextsize) ([OH_Drawing_Font](#oh_drawing_font) \*, float textSize) | 用于给字体设置文字大小。 |
| void [OH_Drawing_FontSetLinearText](#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isLinearText) | 用于设置线性可缩放字体。 |
| void [OH_Drawing_FontSetTextSkewX](#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](#oh_drawing_font) \*, float skewX) | 用于给字体设置文本倾斜。 |
| void [OH_Drawing_FontSetFakeBoldText](#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isFakeBoldText) | 用于设置增加描边宽度以近似粗体字体效果。 |
| void [OH_Drawing_FontDestroy](#oh_drawing_fontdestroy) ([OH_Drawing_Font](#oh_drawing_font) \*) | 用于销毁字体对象并回收该对象占有的内存。 |
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \* [OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection) (void) | 创建字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)。 |
| void [OH_Drawing_DestroyFontCollection](#oh_drawing_destroyfontcollection) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | 释放被字体集对象占据的内存。 |
| [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \* [OH_Drawing_MaskFilterCreateBlur](#oh_drawing_maskfiltercreateblur) ([OH_Drawing_BlurType](#oh_drawing_blurtype) blurType, float sigma, bool respectCTM) | 创建具有模糊效果的模板滤波器。 |
| void [OH_Drawing_MaskFilterDestroy](#oh_drawing_maskfilterdestroy) ([OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | 销毁模板滤波器对象，并收回该对象占用的内存。 |
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate) (void) | 用于创建一个矩阵对象。 |
| void [OH_Drawing_MatrixSetMatrix](#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | 用于给矩阵对象设置参数。 |
| void [OH_Drawing_MatrixDestroy](#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 用于销毁矩阵对象并回收该对象占有的内存。 |
| [OH_Drawing_Path](#oh_drawing_path) \* [OH_Drawing_PathCreate](#oh_drawing_pathcreate) (void) | 用于创建一个路径对象。 |
| void [OH_Drawing_PathDestroy](#oh_drawing_pathdestroy) ([OH_Drawing_Path](#oh_drawing_path) \*) | 用于销毁路径对象并回收该对象占有的内存。 |
| void [OH_Drawing_PathMoveTo](#oh_drawing_pathmoveto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | 用于设置自定义路径的起始点位置。 |
| void [OH_Drawing_PathLineTo](#oh_drawing_pathlineto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | 用于添加一条从路径的最后点位置到目标点位置的线段。 |
| void [OH_Drawing_PathArcTo](#oh_drawing_patharcto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | 用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆， 然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段。 |
| void [OH_Drawing_PathQuadTo](#oh_drawing_pathquadto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | 用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线。 |
| void [OH_Drawing_PathCubicTo](#oh_drawing_pathcubicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | 用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线。 |
| void [OH_Drawing_PathClose](#oh_drawing_pathclose) ([OH_Drawing_Path](#oh_drawing_path) \*) | 用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。 |
| void [OH_Drawing_PathReset](#oh_drawing_pathreset) ([OH_Drawing_Path](#oh_drawing_path) \*) | 用于重置自定义路径数据。 |
| [OH_Drawing_Pen](#oh_drawing_pen) \* [OH_Drawing_PenCreate](#oh_drawing_pencreate) (void) | 用于创建一个画笔对象。 |
| void [OH_Drawing_PenDestroy](#oh_drawing_pendestroy) ([OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于销毁画笔对象并回收该对象占有的内存。 |
| bool [OH_Drawing_PenIsAntiAlias](#oh_drawing_penisantialias) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 |
| void [OH_Drawing_PenSetAntiAlias](#oh_drawing_pensetantialias) ([OH_Drawing_Pen](#oh_drawing_pen) \*, bool) | 用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 |
| uint32_t [OH_Drawing_PenGetColor](#oh_drawing_pengetcolor) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示。 |
| void [OH_Drawing_PenSetColor](#oh_drawing_pensetcolor) ([OH_Drawing_Pen](#oh_drawing_pen) \*, uint32_t color) | 用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示。 |
| uint8_t [OH_Drawing_PenGetAlpha](#oh_drawing_pengetalpha) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 获取画笔的透明度值。画笔在勾勒图形时透明通道会使用该值。 |
| void [OH_Drawing_PenSetAlpha](#oh_drawing_pensetalpha) ([OH_Drawing_Pen](#oh_drawing_pen) \*, uint8_t alpha) | 为画笔设置透明度值。画笔在勾勒图形时透明通道会使用该值。 |
| float [OH_Drawing_PenGetWidth](#oh_drawing_pengetwidth) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于获取画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度。 |
| void [OH_Drawing_PenSetWidth](#oh_drawing_pensetwidth) ([OH_Drawing_Pen](#oh_drawing_pen) \*, float width) | 用于设置画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度。 |
| float [OH_Drawing_PenGetMiterLimit](#oh_drawing_pengetmiterlimit) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角。 |
| void [OH_Drawing_PenSetMiterLimit](#oh_drawing_pensetmiterlimit) ([OH_Drawing_Pen](#oh_drawing_pen) \*, float miter) | 用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角。 |
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)[OH_Drawing_PenGetCap](#oh_drawing_pengetcap) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于获取画笔笔帽的样式。 |
| void [OH_Drawing_PenSetCap](#oh_drawing_pensetcap) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)) | 用于设置画笔笔帽样式。 |
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)[OH_Drawing_PenGetJoin](#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于获取画笔绘制折线转角的样式。 |
| void [OH_Drawing_PenSetJoin](#oh_drawing_pensetjoin) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)) | 用于设置画笔绘制转角的样式。 |
| [OH_Drawing_Point](#oh_drawing_point) \* [OH_Drawing_PointCreate](#oh_drawing_pointcreate) (float x, float y) | 用于创建一个坐标点对象。 |
| void [OH_Drawing_PointDestroy](#oh_drawing_pointdestroy) ([OH_Drawing_Point](#oh_drawing_point) \*) | 用于销毁坐标点对象并回收该对象占有的内存。 |
| [OH_Drawing_Rect](#oh_drawing_rect) \* [OH_Drawing_RectCreate](#oh_drawing_rectcreate) (float left, float top, float right, float bottom) | 用于创建一个矩形对象。 |
| void [OH_Drawing_RectDestroy](#oh_drawing_rectdestroy) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于销毁矩形对象并回收该对象占有的内存。 |
| [OH_Drawing_RoundRect](#oh_drawing_roundrect) \* [OH_Drawing_RoundRectCreate](#oh_drawing_roundrectcreate) (const [OH_Drawing_Rect](#oh_drawing_rect) \*, float xRad, float yRad) | 用于创建一个圆角矩形对象。 |
| void [OH_Drawing_RoundRectDestroy](#oh_drawing_roundrectdestroy) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*) | 用于销毁圆角矩形对象并回收该对象占有的内存。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradient](#oh_drawing_shadereffectcreatelineargradient) (const [OH_Drawing_Point](#oh_drawing_point) \*startPt, const [OH_Drawing_Point](#oh_drawing_point) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | 创建着色器，在两个指定点之间生成线性渐变。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradient](#oh_drawing_shadereffectcreateradialgradient) (const [OH_Drawing_Point](#oh_drawing_point) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | 创建着色器，在给定圆心和半径的情况下生成径向渐变。 从起点到终点颜色从内到外进行圆形渐变（从中间向外拉）被称为径向渐变。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateSweepGradient](#oh_drawing_shadereffectcreatesweepgradient) (const [OH_Drawing_Point](#oh_drawing_point) \*centerPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | 创建着色器，在给定中心的情况下生成扇形渐变。 |
| void [OH_Drawing_ShaderEffectDestroy](#oh_drawing_shadereffectdestroy) ([OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | 销毁着色器对象，并收回该对象占用的内存。 |
| [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \* [OH_Drawing_TextBlobBuilderCreate](#oh_drawing_textblobbuildercreate) (void) | 用于创建一个文本构造器对象。 |
| const [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) \* [OH_Drawing_TextBlobBuilderAllocRunPos](#oh_drawing_textblobbuilderallocrunpos) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*, const [OH_Drawing_Font](#oh_drawing_font) \*, int32_t count, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | 申请一块内存，用于存储文字和位置信息。返回的指针无需调用者管理， 当调用[OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake)后禁止使用。 |
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*) | 用于从文本构造器中创建文本对象。 |
| void [OH_Drawing_TextBlobDestroy](#oh_drawing_textblobdestroy) ([OH_Drawing_TextBlob](#oh_drawing_textblob) \*) | 用于销毁文本对象并回收该对象占有的内存。 |
| void [OH_Drawing_TextBlobBuilderDestroy](#oh_drawing_textblobbuilderdestroy) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*) | 用于销毁文本构造器对象并回收该对象占有的内存。 |
| [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \* [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle) (void) | 创建OH_Drawing_TypographyStyle |
| void [OH_Drawing_DestroyTypographyStyle](#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 释放被OH_Drawing_TypographyStyle对象占据的内存。 |
| void [OH_Drawing_SetTypographyTextDirection](#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本方向。 |
| void [OH_Drawing_SetTypographyTextAlign](#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本对齐方式。 |
| void [OH_Drawing_SetTypographyTextMaxLines](#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本最大行数。 |
| [OH_Drawing_TextStyle](#oh_drawing_textstyle) \* [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle) (void) | 创建OH_Drawing_TextStyle。 |
| void [OH_Drawing_DestroyTextStyle](#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 释放被OH_Drawing_TextStyle对象占据的内存。 |
| void [OH_Drawing_SetTextStyleColor](#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | 设置文本颜色。 |
| void [OH_Drawing_SetTextStyleFontSize](#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置字号。 |
| void [OH_Drawing_SetTextStyleFontWeight](#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置字重。 |
| void [OH_Drawing_SetTextStyleBaseLine](#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置字体基线位置。 |
| void [OH_Drawing_SetTextStyleDecoration](#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置装饰。 |
| void [OH_Drawing_SetTextStyleDecorationColor](#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | 设置装饰颜色。 |
| void [OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置字体高度。 |
| void [OH_Drawing_SetTextStyleFontFamilies](#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | 设置字体类型。 |
| void [OH_Drawing_SetTextStyleFontStyle](#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置字体风格。 |
| void [OH_Drawing_SetTextStyleLocale](#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | 设置语言区域。 |
| [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \* [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | 创建指向OH_Drawing_TypographyCreate对象的指针。 |
| void [OH_Drawing_DestroyTypographyHandler](#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | 释放被OH_Drawing_TypographyCreate对象占据的内存。 |
| void [OH_Drawing_TypographyHandlerPushTextStyle](#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 设置排版风格。 |
| void [OH_Drawing_TypographyHandlerAddText](#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, const char \*) | 设置文本内容。 |
| void [OH_Drawing_TypographyHandlerPopTextStyle](#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | 排版弹出。 |
| [OH_Drawing_Typography](#oh_drawing_typography) \* [OH_Drawing_CreateTypography](#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | 创建OH_Drawing_Typography。 |
| void [OH_Drawing_DestroyTypography](#oh_drawing_destroytypography) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 释放OH_Drawing_Typography对象占据的内存。 |
| void [OH_Drawing_TypographyLayout](#oh_drawing_typographylayout) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double) | 排版布局。 |
| void [OH_Drawing_TypographyPaint](#oh_drawing_typographypaint) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_Canvas](#oh_drawing_canvas) \*, double, double) | 显示文本。 |
| double [OH_Drawing_TypographyGetMaxWidth](#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取最大宽度。 |
| double [OH_Drawing_TypographyGetHeight](#oh_drawing_typographygetheight) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取高度。 |
| double [OH_Drawing_TypographyGetLongestLine](#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取最长行。 |
| double [OH_Drawing_TypographyGetMinIntrinsicWidth](#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取最小固有宽度。 |
| double [OH_Drawing_TypographyGetMaxIntrinsicWidth](#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取最大固有宽度。 |
| double [OH_Drawing_TypographyGetAlphabeticBaseline](#oh_drawing_typographygetalphabeticbaseline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取字母文字基线。 |
| double [OH_Drawing_TypographyGetIdeographicBaseline](#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取表意文字基线。 |
| void [OH_Drawing_TypographyHandlerAddPlaceholder](#oh_drawing_typographyhandleraddplaceholder) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) \*) | 设置占位符 |
| bool [OH_Drawing_TypographyDidExceedMaxLines](#oh_drawing_typographydidexceedmaxlines) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取文本是否超过最大行 |
| [OH_Drawing_TextBox](#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t, size_t, [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle), [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)) | 获取指定范围内的文本框 |
| [OH_Drawing_TextBox](#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取占位符的文本框 |
| float [OH_Drawing_GetLeftFromTextBox](#oh_drawing_getleftfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框左侧位置 |
| float [OH_Drawing_GetRightFromTextBox](#oh_drawing_getrightfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框右侧位置 |
| float [OH_Drawing_GetTopFromTextBox](#oh_drawing_gettopfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框顶部位置 |
| float [OH_Drawing_GetBottomFromTextBox](#oh_drawing_getbottomfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框底部位置 |
| int [OH_Drawing_GetTextDirectionFromTextBox](#oh_drawing_gettextdirectionfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框方向 |
| size_t [OH_Drawing_GetSizeOfTextBox](#oh_drawing_getsizeoftextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*) | 获取文本框数量大小 |
| [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double, double) | 获取坐标处文本的索引位置和亲和性 |
| [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double, double) | 获取坐标处文本所属字符簇的索引位置和亲和性，字符簇指一个或多个字符组成的整体 |
| size_t [OH_Drawing_GetPositionFromPositionAndAffinity](#oh_drawing_getpositionfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \*) | 获取OH_Drawing_PositionAndAffinity对象的位置属性 |
| int [OH_Drawing_GetAffinityFromPositionAndAffinity](#oh_drawing_getaffinityfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \*) | 获取OH_Drawing_PositionAndAffinity对象的亲和性，根据亲和性可判断字体会靠近前方文本还是后方文本 |
| [OH_Drawing_Range](#oh_drawing_range) \* [OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t) | 获取单词的边界 |
| size_t [OH_Drawing_GetStartFromRange](#oh_drawing_getstartfromrange) ([OH_Drawing_Range](#oh_drawing_range) \*) | 获取OH_Drawing_Range对象开始位置 |
| size_t [OH_Drawing_GetEndFromRange](#oh_drawing_getendfromrange) ([OH_Drawing_Range](#oh_drawing_range) \*) | 获取OH_Drawing_Range对象结束位置 |
| size_t [OH_Drawing_TypographyGetLineCount](#oh_drawing_typographygetlinecount) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取文本行数 |
| void [OH_Drawing_SetTextStyleDecorationStyle](#oh_drawing_settextstyledecorationstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置文本装饰样式 |
| void [OH_Drawing_SetTextStyleDecorationThicknessScale](#oh_drawing_settextstyledecorationthicknessscale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置文本装饰线的厚度缩放比例 |
| void [OH_Drawing_SetTextStyleLetterSpacing](#oh_drawing_settextstyleletterspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置文本的字符间距 |
| void [OH_Drawing_SetTextStyleWordSpacing](#oh_drawing_settextstylewordspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置文本的单词间距 |
| void [OH_Drawing_SetTextStyleHalfLeading](#oh_drawing_settextstylehalfleading) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, bool) | 设置文本为一半行间距 |
| void [OH_Drawing_SetTextStyleEllipsis](#oh_drawing_settextstyleellipsis) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | 设置文本的省略号内容 |
| void [OH_Drawing_SetTextStyleEllipsisModal](#oh_drawing_settextstyleellipsismodal) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置文本的省略号样式 |
| void [OH_Drawing_SetTypographyTextBreakStrategy](#oh_drawing_settypographytextbreakstrategy) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本的中断策略 |
| void [OH_Drawing_SetTypographyTextWordBreakType](#oh_drawing_settypographytextwordbreaktype) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置单词的断词方式 |
| void [OH_Drawing_SetTypographyTextEllipsisModal](#oh_drawing_settypographytextellipsismodal) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本的省略号样式 |
| double [OH_Drawing_TypographyGetLineHeight](#oh_drawing_typographygetlineheight) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | 获取指定行的行高 |
| double [OH_Drawing_TypographyGetLineWidth](#oh_drawing_typographygetlinewidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | 获取指定行的行宽 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateDefault](#oh_drawing_typefacecreatedefault) (void) | 用于创建一个默认的字形对象。 |
| void [OH_Drawing_TypefaceDestroy](#oh_drawing_typefacedestroy) ([OH_Drawing_Typeface](#oh_drawing_typeface) \*) | 用于销毁字形对象并回收该对象占有的内存。 |
| void [OH_Drawing_CanvasClipRect](#oh_drawing_canvascliprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个矩形。 |
| void [OH_Drawing_CanvasClipPath](#oh_drawing_canvasclippath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个自定义路径。 |
| void [OH_Drawing_CanvasRotate](#oh_drawing_canvasrotate) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float degrees, float px, float py) | 用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。 |
| void [OH_Drawing_CanvasTranslate](#oh_drawing_canvastranslate) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float dx, float dy) | 用于平移画布一段距离。 |
| void [OH_Drawing_CanvasScale](#oh_drawing_canvasscale) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float sx, float sy) | 用于画布缩放。 |
| void [OH_Drawing_CanvasClear](#oh_drawing_canvasclear) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t color) | 用于使用指定颜色去清空画布。 |

## 类型定义说明


### OH_Drawing_Bitmap

```
typedef struct OH_Drawing_Bitmap OH_Drawing_Bitmap
```

**描述**

定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据。

**起始版本：** 8


### OH_Drawing_Brush

```
typedef struct OH_Drawing_Brush OH_Drawing_Brush
```

**描述**

定义为画刷，画刷用于描述填充图形的样式和颜色。

**起始版本：** 8


### OH_Drawing_Canvas

```
typedef struct OH_Drawing_Canvas OH_Drawing_Canvas
```

**描述**

定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字。

**起始版本：** 8


### OH_Drawing_ColorFilter

```
typedef struct OH_Drawing_ColorFilter OH_Drawing_ColorFilter
```

**描述**

定义颜色滤波器，传入一个颜色并返回一个新的颜色。

**起始版本：** 11


### OH_Drawing_Filter

```
typedef struct OH_Drawing_Filter OH_Drawing_Filter
```

**描述**

定义一个滤波器，用于存储颜色滤波器和模板滤波器。

**起始版本：** 11


### OH_Drawing_Font

```
typedef struct OH_Drawing_Font OH_Drawing_Font
```

**描述**

用于描述字体。

**起始版本：** 11


### OH_Drawing_FontCollection

```
typedef struct OH_Drawing_FontCollection OH_Drawing_FontCollection
```

**描述**

用于加载字体。

**起始版本：** 8


### OH_Drawing_MaskFilter

```
typedef struct OH_Drawing_MaskFilter OH_Drawing_MaskFilter
```

**描述**

定义模板滤波器，用于在绘制模板前对其进行转换。

**起始版本：** 11


### OH_Drawing_Matrix

```
typedef struct OH_Drawing_MatrixOH_Drawing_Matrix
```

**描述**

定义一个矩阵，用于描述坐标变换。

**起始版本：** 11


### OH_Drawing_Path

```
typedef struct OH_Drawing_PathOH_Drawing_Path
```

**描述**

定义为路径，路径用于自定义各种形状。

**起始版本：** 8


### OH_Drawing_Pen

```
typedef struct OH_Drawing_Pen OH_Drawing_Pen
```

**描述**

定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色。

**起始版本：** 8


### OH_Drawing_Point

```
typedef struct OH_Drawing_Point OH_Drawing_Point
```

**描述**

定义一个点，用于描述坐标点。

**起始版本：** 11


### OH_Drawing_PositionAndAffinity

```
typedef struct OH_Drawing_PositionAndAffinity OH_Drawing_PositionAndAffinity
```

**描述**

用于接收字体的位置和亲和性

**起始版本：** 11


### OH_Drawing_Range

```
typedef struct OH_Drawing_Range OH_Drawing_Range
```

**描述**

用于接收字体的起始位置和结束位置

**起始版本：** 11


### OH_Drawing_Rect

```
typedef struct OH_Drawing_Rect OH_Drawing_Rect
```

**描述**

用于描述矩形。

**起始版本：** 11


### OH_Drawing_RoundRect

```
typedef struct OH_Drawing_RoundRect OH_Drawing_RoundRect
```

**描述**

用于描述圆角矩形。

**起始版本：** 11


### OH_Drawing_ShaderEffect

```
typedef struct OH_Drawing_ShaderEffectOH_Drawing_ShaderEffect
```

**描述**

定义一个着色器，用于描述绘制内容的源颜色。

**起始版本：** 11


### OH_Drawing_TextBlob

```
typedef struct OH_Drawing_TextBlobOH_Drawing_TextBlob
```

**描述**

定义一个文本对象，表示将多个文本组合到一个不可变的容器中。 每个文本行由字形和位置组成。

**起始版本：** 11


### OH_Drawing_TextBlobBuilder

```
typedef struct OH_Drawing_TextBlobBuilderOH_Drawing_TextBlobBuilder
```

**描述**

定义文本构建器，用于构建文本。

**起始版本：** 11


### OH_Drawing_TextBox

```
typedef struct OH_Drawing_TextBoxOH_Drawing_TextBox
```

**描述**

用于接收文本框的矩形大小、方向和数量大小

**起始版本：** 11


### OH_Drawing_TextStyle

```
typedef struct OH_Drawing_TextStyleOH_Drawing_TextStyle
```

**描述**

用于管理字体颜色、装饰等。

**起始版本：** 8


### OH_Drawing_Typeface

```
typedef struct OH_Drawing_TypefaceOH_Drawing_Typeface
```

**描述**

用于描述字形。

**起始版本：** 11


### OH_Drawing_Typography

```
typedef struct OH_Drawing_TypographyOH_Drawing_Typography
```

**描述**

用于管理排版的布局和显示等。

**起始版本：** 8


### OH_Drawing_TypographyCreate

```
typedef struct OH_Drawing_TypographyCreateOH_Drawing_TypographyCreate
```

**描述**

用于创建[OH_Drawing_Typography](#oh_drawing_typography)。

**起始版本：** 8


### OH_Drawing_TypographyStyle

```
typedef struct OH_Drawing_TypographyStyleOH_Drawing_TypographyStyle
```

**描述**

用于管理排版风格，如文字方向等。

**起始版本：** 8


## 枚举类型说明


### OH_Drawing_AlphaFormat

```
enum OH_Drawing_AlphaFormat
```

**描述**

用于描述位图像素的透明度分量。

**起始版本：** 8

| 枚举值 | 描述 |
| -------- | -------- |
| ALPHA_FORMAT_UNKNOWN | 未知格式 |
| ALPHA_FORMAT_OPAQUE | 位图无透明度 |
| ALPHA_FORMAT_PREMUL | 每个像素的颜色组件由透明度分量预先乘以 |
| ALPHA_FORMAT_UNPREMUL | 每个像素的颜色组件未由透明度分量预先乘以 |


### OH_Drawing_BlendMode

```
enum OH_Drawing_BlendMode
```

**描述**

混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在4个颜色通道（红、绿、蓝、透明度）上是相同的。 对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。

为简洁起见，我们使用以下缩写：

s : source 源的缩写。 d : destination 目标的缩写。 sa : source alpha 源透明度的缩写。 da : destination alpha 目标透明度的缩写。

计算结果用如下缩写表示：

r : 如果4个通道的计算方式相同，用r表示。 ra : 如果只操作透明度通道，用ra表示。 rc : 如果操作3个颜色通道，用rc表示。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| BLEND_MODE_CLEAR | 清除模式，r = 0。 |
| BLEND_MODE_SRC | r = s（result的4个通道，都等于source的4个通道，即结果等于源。） |
| BLEND_MODE_DST | r = d（result的4个通道，都等于destination的4个通道，即结果等于目标。） |
| BLEND_MODE_SRC_OVER | r = s + (1 - sa) \* d |
| BLEND_MODE_DST_OVER | r = d + (1 - da) \* s |
| BLEND_MODE_SRC_IN | r = s \* da |
| BLEND_MODE_DST_IN | r = d \* sa |
| BLEND_MODE_SRC_OUT | r = s \* (1 - da) |
| BLEND_MODE_DST_OUT | r = d \* (1 - sa) |
| BLEND_MODE_SRC_ATOP | r = s \* da + d \* (1 - sa) |
| BLEND_MODE_DST_ATOP | r = d \* sa + s \* (1 - da) |
| BLEND_MODE_XOR | r = s \* (1 - da) + d \* (1 - sa) |
| BLEND_MODE_PLUS | r = min(s + d, 1) |
| BLEND_MODE_MODULATE | r = s \* d |
| BLEND_MODE_SCREEN | 滤色模式，r = s + d - s \* d |
| BLEND_MODE_OVERLAY | 叠加模式 |
| BLEND_MODE_DARKEN | 变暗模式，rc = s + d - max(s \* da, d \* sa), ra = s + (1 - sa) \* d |
| BLEND_MODE_LIGHTEN | 变亮模式，rc = s + d - min(s \* da, d \* sa), ra = s + (1 - sa) \* d |
| BLEND_MODE_COLOR_DODGE | 颜色减淡模式 |
| BLEND_MODE_COLOR_BURN | 颜色加深模式 |
| BLEND_MODE_HARD_LIGHT | 强光模式 |
| BLEND_MODE_SOFT_LIGHT | 柔光模式 |
| BLEND_MODE_DIFFERENCE | 差值模式，rc = s + d - 2 \* (min(s \* da, d \* sa)), ra = s + (1 - sa) \* d |
| BLEND_MODE_EXCLUSION | 排除模式，rc = s + d - two(s \* d), ra = s + (1 - sa) \* d |
| BLEND_MODE_MULTIPLY | 正片叠底，r = s \* (1 - da) + d \* (1 - sa) + s \* d |
| BLEND_MODE_HUE | 色相模式 |
| BLEND_MODE_SATURATION | 饱和度模式 |
| BLEND_MODE_COLOR | 颜色模式 |
| BLEND_MODE_LUMINOSITY | 亮度模式 |


### OH_Drawing_BlurType

```
enum OH_Drawing_BlurType
```

**描述**

枚举模糊类型。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| NORMAL | 内外模糊。 |
| SOLID | 内部实体，外部模糊。 |
| OUTER | 内部空白，外部模糊。 |
| INNER | 内部模糊，外部空白。 |


### OH_Drawing_BreakStrategy

```
enum OH_Drawing_BreakStrategy
```

**描述**

文本的中断策略枚举

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| BREAK_STRATEGY_GREEDY | 贪心策略，换行时尽可能填满每一行 |
| BREAK_STRATEGY_HIGH_QUALITY | 高质量策略，换行时优先考虑文本的连续性 |
| BREAK_STRATEGY_BALANCED | 平衡策略，换行时在单词边界换行 |


### OH_Drawing_CanvasClipOp

```
enum OH_Drawing_CanvasClipOp
```

**描述**

画布裁剪方式的枚举集合。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| DIFFERENCE | 将指定区域裁剪（取差集）。 |
| INTERSECT | 将指定区域保留（取交集）。 |


### OH_Drawing_ColorFormat

```
enum OH_Drawing_ColorFormat
```

**描述**

用于描述位图像素的存储格式。

**起始版本：** 8

| 枚举值 | 描述 |
| -------- | -------- |
| COLOR_FORMAT_UNKNOWN | 未知格式. |
| COLOR_FORMAT_ALPHA_8 | 每个像素用一个8位的量表示，8个位比特位表示透明度 |
| COLOR_FORMAT_RGB_565 | 每个像素用一个16位的量表示，高位到低位依次是5个比特位表示红，6个比特位表示绿，5个比特位表示蓝 |
| COLOR_FORMAT_ARGB_4444 | 每个像素用一个16位的量表示，高位到低位依次是4个比特位表示透明度，4个比特位表示红，4个比特位表示绿，4个比特位表示蓝 |
| COLOR_FORMAT_RGBA_8888 | 每个像素用一个32位的量表示，高位到低位依次是8个比特位表示透明度，8个比特位表示红，8个比特位表示绿，8个比特位表示蓝 |
| COLOR_FORMAT_BGRA_8888 | 每个像素用一个32位的量表示，高位到低位依次是8个比特位表示蓝，8个比特位表示绿，8个比特位表示红，8个比特位表示透明度 |


### OH_Drawing_EllipsisModal

```
enum OH_Drawing_EllipsisModal
```

**描述**

省略号样式枚举

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ELLIPSIS_MODAL_HEAD | 头部模式，即省略号放在文本头部 |
| ELLIPSIS_MODAL_MIDDLE | 中部模式，即省略号放在文本中部 |
| ELLIPSIS_MODAL_TAIL | 尾部模式，即省略号放在文本尾部 |


### OH_Drawing_FontStyle

```
enum OH_Drawing_FontStyle
```

**描述**

区分字体是否为斜体

**起始版本：** 8

| 枚举值 | 描述 |
| -------- | -------- |
| FONT_STYLE_NORMAL | 非斜体 |
| FONT_STYLE_ITALIC | 斜体 |


### OH_Drawing_FontWeight

```
enum OH_Drawing_FontWeight
```

**描述**

字重

**起始版本：** 8

| 枚举值 | 描述 |
| -------- | -------- |
| FONT_WEIGHT_100 | 字重为thin |
| FONT_WEIGHT_200 | 字重为extra-light |
| FONT_WEIGHT_300 | 字重为light |
| FONT_WEIGHT_400 | 字重为normal/regular |
| FONT_WEIGHT_500 | 字重为medium |
| FONT_WEIGHT_600 | 字重为semi-bold |
| FONT_WEIGHT_700 | 字重为bold |
| FONT_WEIGHT_800 | 字重为extra-bold |
| FONT_WEIGHT_900 | 字重为black |


### OH_Drawing_PenLineCapStyle

```
enum OH_Drawing_PenLineCapStyle
```

**描述**

枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。

**起始版本：** 8

| 枚举值 | 描述 |
| -------- | -------- |
| LINE_FLAT_CAP | 没有笔帽样式，线条头尾端点处横切 |
| LINE_SQUARE_CAP | 笔帽的样式为方框，线条的头尾端点处多出一个方框，方框宽度和线段一样宽，高度时线段厚度的一半 |
| LINE_ROUND_CAP | 笔帽的样式为圆弧，线条的头尾端点处多出一个半圆弧，半圆的直径与线段厚度一致 |


### OH_Drawing_PenLineJoinStyle

```
enum OH_Drawing_PenLineJoinStyle
```

**描述**

枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。

**起始版本：** 8

| 枚举值 | 描述 |
| -------- | -------- |
| LINE_MITER_JOIN | 转角类型为尖角，如果折线角度比较小，则尖角会很长，需要使用限制值（miter limit）进行限制 |
| LINE_ROUND_JOIN | 转角类型为圆头 |
| LINE_BEVEL_JOIN | 转角类型为平头 |


### OH_Drawing_PlaceholderVerticalAlignment

```
enum OH_Drawing_PlaceholderVerticalAlignment
```

**描述**

占位符垂直对齐枚举

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| ALIGNMENT_OFFSET_AT_BASELINE | 偏移于基线对齐 |
| ALIGNMENT_ABOVE_BASELINE | 高于基线对齐 |
| ALIGNMENT_BELOW_BASELINE | 低于基线对齐 |
| ALIGNMENT_TOP_OF_ROW_BOX | 行框顶部对齐 |
| ALIGNMENT_BOTTOM_OF_ROW_BOX | 行框底部对齐 |
| ALIGNMENT_CENTER_OF_ROW_BOX | 行框中心对齐 |


### OH_Drawing_RectHeightStyle

```
enum OH_Drawing_RectHeightStyle
```

**描述**

矩形框高度样式枚举

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RECT_HEIGHT_STYLE_TIGHT | 紧密样式 |
| RECT_HEIGHT_STYLE_MAX | 最大样式 |
| RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE | 包含行间距中间样式 |
| RECT_HEIGHT_STYLE_INCLUDELINESPACETOP | 包含行间距顶部样式 |
| RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM | 包含行间距底部样式 |
| RECT_HEIGHT_STYLE_STRUCT | 结构样式 |


### OH_Drawing_RectWidthStyle

```
enum OH_Drawing_RectWidthStyle
```

**描述**

矩形框宽度样式枚举

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| RECT_WIDTH_STYLE_TIGHT | 紧密样式 |
| RECT_WIDTH_STYLE_MAX | 最大样式 |


### OH_Drawing_TextAlign

```
enum OH_Drawing_TextAlign
```

**描述**

文字对齐方式

**起始版本：**8

| 枚举值 | 描述 |
| -------- | -------- |
| TEXT_ALIGN_LEFT | 左对齐 |
| TEXT_ALIGN_RIGHT | 右对齐 |
| TEXT_ALIGN_CENTER | 居中对齐 |
| TEXT_ALIGN_JUSTIFY | 两端对齐，即紧靠左和右边缘，中间单词空隙由空格填充，最后一行除外。 |
| TEXT_ALIGN_START | 当OH_Drawing_TextDirection是TEXT_DIRECTION_LTR时， TEXT_ALIGN_START和TEXT_ALIGN_LEFT相同； 类似地，当OH_Drawing_TextDirection是TEXT_DIRECTION_RTL时， TEXT_ALIGN_START和TEXT_ALIGN_RIGHT相同。 |
| TEXT_ALIGN_END | 当OH_Drawing_TextDirection是TEXT_DIRECTION_LTR时， TEXT_ALIGN_END和TEXT_ALIGN_RIGHT相同； 类似地，当OH_Drawing_TextDirection是TEXT_DIRECTION_RTL时， TEXT_ALIGN_END和TEXT_ALIGN_LEFT相同。 |


### OH_Drawing_TextBaseline

```
enum OH_Drawing_TextBaseline
```

**描述**

基线位置

**起始版本：**8

| 枚举值 | 描述 |
| -------- | -------- |
| TEXT_BASELINE_ALPHABETIC | 用于表音文字，基线在中间偏下的位置 |
| TEXT_BASELINE_IDEOGRAPHIC | 用于表意文字，基线位于底部 |


### OH_Drawing_TextDecoration

```
enum OH_Drawing_TextDecoration
```

**描述**

文本装饰

**起始版本：**8

| 枚举值 | 描述 |
| -------- | -------- |
| TEXT_DECORATION_NONE | 无装饰 |
| TEXT_DECORATION_UNDERLINE | 下划线 |
| TEXT_DECORATION_OVERLINE | 上划线 |
| TEXT_DECORATION_LINE_THROUGH | 删除线 |


### OH_Drawing_TextDecorationStyle

```
enum OH_Drawing_TextDecorationStyle
```

**描述**

文本装饰样式枚举

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| TEXT_DECORATION_STYLE_SOLID | 实心样式 |
| TEXT_DECORATION_STYLE_DOUBLE | 双重样式 |
| TEXT_DECORATION_STYLE_DOTTED | 圆点样式 |
| TEXT_DECORATION_STYLE_DASHED | 虚线样式 |
| TEXT_DECORATION_STYLE_WAVY | 波浪样式 |


### OH_Drawing_TextDirection

```
enum OH_Drawing_TextDirection
```

**描述**

文字方向

**起始版本：**8

| 枚举值 | 描述 |
| -------- | -------- |
| TEXT_DIRECTION_RTL | 方向：从右到左 |
| TEXT_DIRECTION_LTR | 方向：从左到右 |


### OH_Drawing_TileMode

```
enum OH_Drawing_TileMode
```

**描述**

着色器效果平铺模式的枚举。

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| CLAMP | 如果着色器效果超出其原始边界，则复制边缘颜色。 |
| REPEAT | 在水平和垂直方向上重复着色器效果图像。 |
| MIRROR | 水平和垂直重复着色器效果图像，交替镜像。 |
| DECAL | 只在原始区域内绘制，其他地方返回透明黑色。 |


### OH_Drawing_WordBreakType

```
enum OH_Drawing_WordBreakType
```

**描述**

单词的断词方式枚举

**起始版本：** 11

| 枚举值 | 描述 |
| -------- | -------- |
| WORD_BREAK_TYPE_NORMAL | 常规方式 |
| WORD_BREAK_TYPE_BREAK_ALL | 全部中断方式 |
| WORD_BREAK_TYPE_BREAK_WORD | 单词中断方式 |


## 函数说明


### OH_Drawing_BitmapBuild()

```
void OH_Drawing_BitmapBuild (OH_Drawing_Bitmap * , const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat *  )
```

**描述**

用于初始化位图对象的宽度和高度，并且为该位图设置像素格式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 |
| width | 参数是位图要初始化设置的宽度。 |
| height | 参数是位图要初始化设置的高度。 |
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 参数是位图要初始化设置的像素格式，包括像素的颜色类型和透明度类型。 |


### OH_Drawing_BitmapCreate()

```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreate (void )
```

**描述**

用于创建一个位图对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

函数会返回一个指针，指针指向创建的位图对象。


### OH_Drawing_BitmapDestroy()

```
void OH_Drawing_BitmapDestroy (OH_Drawing_Bitmap * )
```

**描述**

用于销毁位图对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 |


### OH_Drawing_BitmapGetHeight()

```
uint32_t OH_Drawing_BitmapGetHeight (OH_Drawing_Bitmap * )
```

**描述**

用于获取指定位图的高度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 |

**返回：**

函数返回位图的高度。


### OH_Drawing_BitmapGetPixels()

```
void* OH_Drawing_BitmapGetPixels (OH_Drawing_Bitmap * )
```

**描述**

用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 |

**返回：**

函数返回位图的像素地址。


### OH_Drawing_BitmapGetWidth()

```
uint32_t OH_Drawing_BitmapGetWidth (OH_Drawing_Bitmap * )
```

**描述**

用于获取指定位图的宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 |

**返回：**

函数返回位图的宽度。


### OH_Drawing_BrushCreate()

```
OH_Drawing_Brush* OH_Drawing_BrushCreate (void )
```

**描述**

用于创建一个画刷对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

函数会返回一个指针，指针指向创建的画刷对象。


### OH_Drawing_BrushDestroy()

```
void OH_Drawing_BrushDestroy (OH_Drawing_Brush * )
```

**描述**

用于销毁画刷对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 |


### OH_Drawing_BrushGetAlpha()

```
uint8_t OH_Drawing_BrushGetAlpha (const OH_Drawing_Brush * )
```

**描述**

获取画刷的透明度值。画刷在填充形状时透明通道会使用该值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 表示指向画刷对象的指针。 |

**返回：**

返回一个8位变量，用于表示透明度值。


### OH_Drawing_BrushGetColor()

```
uint32_t OH_Drawing_BrushGetColor (const OH_Drawing_Brush * )
```

**描述**

用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 |

**返回：**

函数返回一个描述颜色的32位（ARGB）变量。


### OH_Drawing_BrushIsAntiAlias()

```
bool OH_Drawing_BrushIsAntiAlias (const OH_Drawing_Brush * )
```

**描述**

用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 |

**返回：**

函数返回画刷对象是否设置抗锯齿属性，返回真则设置了抗锯齿，返回假则没有设置抗锯齿。


### OH_Drawing_BrushSetAlpha()

```
void OH_Drawing_BrushSetAlpha (OH_Drawing_Brush * , uint8_t alpha )
```

**描述**

为画刷设置透明度值。画刷在填充形状时透明通道会使用该值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 |
| alpha | 表示要设置的透明度值，是一个8位变量。 |


### OH_Drawing_BrushSetAntiAlias()

```
void OH_Drawing_BrushSetAntiAlias (OH_Drawing_Brush * , bool  )
```

**描述**

用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 |
| bool | 参数真为抗锯齿，参数假则不做抗锯齿处理。 |


### OH_Drawing_BrushSetColor()

```
void OH_Drawing_BrushSetColor (OH_Drawing_Brush * , uint32_t color )
```

**描述**

用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 |
| color | 描述颜色的32位（ARGB）变量。 |


### OH_Drawing_BrushSetFilter()

```
void OH_Drawing_BrushSetFilter (OH_Drawing_Brush * , OH_Drawing_Filter *  )
```

**描述**

为画刷设置滤波器[OH_Drawing_Filter](#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 |
| OH_Drawing_Filter | 表示指向滤波器对象的指针。 |


### OH_Drawing_BrushSetShaderEffect()

```
void OH_Drawing_BrushSetShaderEffect (OH_Drawing_Brush * , OH_Drawing_ShaderEffect *  )
```

**描述**

为画刷设置着色器效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 |
| OH_Drawing_ShaderEffect | 表示指向着色器对象的指针。 |


### OH_Drawing_CanvasAttachBrush()

```
void OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas * , const OH_Drawing_Brush *  )
```

**描述**

用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Brush | 指向画刷对象的指针。 |


### OH_Drawing_CanvasAttachPen()

```
void OH_Drawing_CanvasAttachPen (OH_Drawing_Canvas * , const OH_Drawing_Pen *  )
```

**描述**

用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Pen | 指向画笔对象的指针。 |


### OH_Drawing_CanvasBind()

```
void OH_Drawing_CanvasBind (OH_Drawing_Canvas * , OH_Drawing_Bitmap *  )
```

**描述**

用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Bitmap | 指向位图对象的指针。 |


### OH_Drawing_CanvasClear()

```
void OH_Drawing_CanvasClear (OH_Drawing_Canvas * , uint32_t color )
```

**描述**

用于使用指定颜色去清空画布。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| color | 描述颜色的32位（ARGB）变量。 |


### OH_Drawing_CanvasClipPath()

```
void OH_Drawing_CanvasClipPath (OH_Drawing_Canvas * , const OH_Drawing_Path * , OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias )
```

**描述**

用于裁剪一个自定义路径。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Path | 指向路径对象的指针。 |
| clipOp | 裁剪方式。支持可选的具体裁剪方式可见link OH_Drawing_CanvasClipOp}枚举。 |
| doAntiAlias | 参数真为抗锯齿，参数假则不做抗锯齿处理。 |


### OH_Drawing_CanvasClipRect()

```
void OH_Drawing_CanvasClipRect (OH_Drawing_Canvas * , const OH_Drawing_Rect * , OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias )
```

**描述**

用于裁剪一个矩形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Rect | 指向矩形对象的指针。 |
| clipOp | 裁剪方式。支持可选的具体裁剪方式可见link OH_Drawing_CanvasClipOp}枚举。 |
| doAntiAlias | 值为true则做抗锯齿处理，反之不做。 |


### OH_Drawing_CanvasCreate()

```
OH_Drawing_Canvas* OH_Drawing_CanvasCreate (void )
```

**描述**

用于创建一个画布对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

函数会返回一个指针，指针指向创建的画布对象。


### OH_Drawing_CanvasDestroy()

```
void OH_Drawing_CanvasDestroy (OH_Drawing_Canvas * )
```

**描述**

用于销毁画布对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |


### OH_Drawing_CanvasDetachBrush()

```
void OH_Drawing_CanvasDetachBrush (OH_Drawing_Canvas * )
```

**描述**

用于去除掉画布中的画刷，使用后画布将不去填充图形形状。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |


### OH_Drawing_CanvasDetachPen()

```
void OH_Drawing_CanvasDetachPen (OH_Drawing_Canvas * )
```

**描述**

用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |


### OH_Drawing_CanvasDrawArc()

```
void OH_Drawing_CanvasDrawArc (OH_Drawing_Canvas * , const OH_Drawing_Rect * , float startAngle, float sweepAngle )
```

**描述**

用于画一个弧。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Rect | 指向矩形对象的指针。 |
| startAngle | 弧的起始角度。 |
| sweepAngle | 弧的扫描角度。 |


### OH_Drawing_CanvasDrawBitmap()

```
void OH_Drawing_CanvasDrawBitmap (OH_Drawing_Canvas * , const OH_Drawing_Bitmap * , float left, float top )
```

**描述**

用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Bitmap | 指向位图对象的指针。 |
| left | 位图对象左上角的横坐标。 |
| top | 位图对象左上角的纵坐标。 |


### OH_Drawing_CanvasDrawCircle()

```
void OH_Drawing_CanvasDrawCircle (OH_Drawing_Canvas * , const OH_Drawing_Point * , float radius )
```

**描述**

用于画一个圆形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Point | 指向坐标点对象的指针，表示圆心。 |
| radius | 圆形的半径。 |

### OH_Drawing_CanvasDrawLine()

```
void OH_Drawing_CanvasDrawLine (OH_Drawing_Canvas * , float x1, float y1, float x2, float y2 )
```

**描述**

用于画一条直线段。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| x1 | 线段起始点的横坐标。 |
| y1 | 线段起始点的纵坐标。 |
| x2 | 线段结束点的横坐标。 |
| y2 | 线段结束点的纵坐标。 |


### OH_Drawing_CanvasDrawOval()

```
void OH_Drawing_CanvasDrawOval (OH_Drawing_Canvas * , const OH_Drawing_Rect *  )
```

**描述**

用于画一个椭圆。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Rect | 指向矩形对象的指针。 |


### OH_Drawing_CanvasDrawPath()

```
void OH_Drawing_CanvasDrawPath (OH_Drawing_Canvas * , const OH_Drawing_Path *  )
```

**描述**

用于画一个自定义路径。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Path | 指向路径对象的指针。 |


### OH_Drawing_CanvasDrawRect()

```
void OH_Drawing_CanvasDrawRect (OH_Drawing_Canvas * , const OH_Drawing_Rect *  )
```

**描述**

用于画一个矩形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_Rect | 指向矩形对象的指针。 |


### OH_Drawing_CanvasDrawRoundRect()

```
void OH_Drawing_CanvasDrawRoundRect (OH_Drawing_Canvas * , const OH_Drawing_RoundRect *  )
```

**描述**

用于画一个圆角矩形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_RoundRect | 指向圆角矩形对象的指针。 |


### OH_Drawing_CanvasDrawTextBlob()

```
void OH_Drawing_CanvasDrawTextBlob (OH_Drawing_Canvas * , const OH_Drawing_TextBlob * , float x, float y )
```

**描述**

用于画一段文字。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| OH_Drawing_TextBlob | 指向文本对象的指针。 |
| x | 文本对象左下角的横坐标。 |
| y | 文本对象左下角的纵坐标。 |


### OH_Drawing_CanvasGetSaveCount()

```
uint32_t OH_Drawing_CanvasGetSaveCount (OH_Drawing_Canvas * )
```

**描述**

用于获取栈中保存的画布状态（画布矩阵）的数量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |

**返回：**

函数会返回一个32位的值描述画布状态（画布矩阵）的数量。


### OH_Drawing_CanvasRestore()

```
void OH_Drawing_CanvasRestore (OH_Drawing_Canvas * )
```

**描述**

用于恢复保存在栈顶的画布状态（画布矩阵）。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |


### OH_Drawing_CanvasRestoreToCount()

```
void OH_Drawing_CanvasRestoreToCount (OH_Drawing_Canvas * , uint32_t saveCount )
```

**描述**

用于恢复到指定数量的画布状态（画布矩阵）。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| saveCount | 指定的画布状态（画布矩阵）数量。 |


### OH_Drawing_CanvasRotate()

```
void OH_Drawing_CanvasRotate (OH_Drawing_Canvas * , float degrees, float px, float py )
```

**描述**

用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| degrees | 旋转角度。 |
| px | 旋转中心的横坐标。 |
| py | 旋转中心的纵坐标。 |


### OH_Drawing_CanvasSave()

```
void OH_Drawing_CanvasSave (OH_Drawing_Canvas * )
```

**描述**

用于保存当前画布的状态（画布矩阵）到一个栈顶。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |


### OH_Drawing_CanvasScale()

```
void OH_Drawing_CanvasScale (OH_Drawing_Canvas * , float sx, float sy )
```

**描述**

用于画布缩放。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| sx | 水平方向缩放的比例。 |
| sy | 垂直方向缩放的比例。 |


### OH_Drawing_CanvasTranslate()

```
void OH_Drawing_CanvasTranslate (OH_Drawing_Canvas * , float dx, float dy )
```

**描述**

用于平移画布一段距离。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 |
| dx | 水平方向移动的距离。 |
| dy | 垂直方向移动的距离。 |


### OH_Drawing_ColorFilterCreateBlendMode()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateBlendMode (uint32_t color, OH_Drawing_BlendMode  )
```

**描述**

创建具有混合模式的颜色滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| color | 表示颜色，是一个32位（ARGB）变量。 |
| OH_Drawing_BlendMode | 表示混合模式。支持可选的混合模式具体可见[OH_Drawing_BlendMode](#oh_drawing_blendmode)枚举。 |

**返回：**

返回创建的颜色滤波器对象的指针。


### OH_Drawing_ColorFilterCreateCompose()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateCompose (OH_Drawing_ColorFilter * colorFilter1, OH_Drawing_ColorFilter * colorFilter2 )
```

**描述**

将两个颜色滤波器合成一个新的颜色滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_ColorFilter | 指向颜色滤波器对象一的指针。 |
| OH_Drawing_ColorFilter | 指向颜色滤波器对象二的指针。 |

**返回：**

返回创建的颜色滤波器对象的指针。


### OH_Drawing_ColorFilterCreateLinearToSrgbGamma()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLinearToSrgbGamma (void )
```

**描述**

创建一个颜色滤波器将SRGB的伽玛曲线应用到RGB颜色通道。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

返回创建的颜色滤波器对象的指针。


### OH_Drawing_ColorFilterCreateLuma()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLuma (void )
```

**描述**

创建一个颜色滤波器将其输入的亮度值乘以透明度通道， 并将红色、绿色和蓝色通道设置为零。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

返回创建的颜色滤波器对象的指针。


### OH_Drawing_ColorFilterCreateMatrix()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateMatrix (const float matrix[20])
```

**描述**

创建具有5x4颜色矩阵的颜色滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| matrix | 表示矩阵，以长度为20的浮点数组表示。 |

**返回：**

返回创建的颜色滤波器对象的指针。


### OH_Drawing_ColorFilterCreateSrgbGammaToLinear()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateSrgbGammaToLinear (void )
```

**描述**

创建颜色滤波器将RGB颜色通道应用于SRGB的伽玛曲线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

返回创建的颜色滤波器对象的指针。


### OH_Drawing_ColorFilterDestroy()

```
void OH_Drawing_ColorFilterDestroy (OH_Drawing_ColorFilter * )
```

**描述**

销毁颜色滤波器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_ColorFilter | 表示指向颜色滤波器对象的指针。 |


### OH_Drawing_ColorSetArgb()

```
uint32_t OH_Drawing_ColorSetArgb (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue )
```

**描述**

用于将4个变量（分别描述透明度、红色、绿色和蓝色）转化为一个描述颜色的32位（ARGB）变量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| alpha | 描述透明度的变量, 变量范围是0x00~0xFF。 |
| red | 描述红色的变量, 变量范围是0x00~0xFF。 |
| green | 描述绿色的变量, 变量范围是0x00~0xFF。 |
| blue | 描述蓝色的变量, 变量范围是0x00~0xFF。 |

**返回：**

函数返回一个描述颜色的32位（ARGB）变量。


### OH_Drawing_CreateFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection (void )
```

**描述**

创建字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

指向创建的字体集对象的指针。


### OH_Drawing_CreateTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle (void )
```

**描述**

创建OH_Drawing_TextStyle。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

指向创建的OH_Drawing_TextStyle对象的指针。


### OH_Drawing_CreateTypography()

```
OH_Drawing_Typography* OH_Drawing_CreateTypography (OH_Drawing_TypographyCreate * )
```

**描述**

创建OH_Drawing_Typography。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针。 |

**返回：**

指向OH_Drawing_Typography对象的指针。


### OH_Drawing_CreateTypographyHandler()

```
OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler (OH_Drawing_TypographyStyle * , OH_Drawing_FontCollection *  )
```

**描述**

创建指向OH_Drawing_TypographyCreate对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle的指针。 |
| OH_Drawing_FontCollection | 指向OH_Drawing_FontCollection的指针。 |

**返回：**

指向新创建的OH_Drawing_TypographyCreate对象的指针。


### OH_Drawing_CreateTypographyStyle()

```
OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle (void )
```

**描述**

创建OH_Drawing_TypographyStyle

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

指向创建的OH_Drawing_TypographyStyle对象的指针。


### OH_Drawing_DestroyFontCollection()

```
void OH_Drawing_DestroyFontCollection (OH_Drawing_FontCollection * )
```

**描述**

释放被字体集对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_FontCollection | 指向字体集对象的指针。 |


### OH_Drawing_DestroyTextStyle()

```
void OH_Drawing_DestroyTextStyle (OH_Drawing_TextStyle * )
```

**描述**

释放被OH_Drawing_TextStyle对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |


### OH_Drawing_DestroyTypography()

```
void OH_Drawing_DestroyTypography (OH_Drawing_Typography * )
```

**描述**

释放OH_Drawing_Typography对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |


### OH_Drawing_DestroyTypographyHandler()

```
void OH_Drawing_DestroyTypographyHandler (OH_Drawing_TypographyCreate * )
```

**描述**

释放被OH_Drawing_TypographyCreate对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针。 |


### OH_Drawing_DestroyTypographyStyle()

```
void OH_Drawing_DestroyTypographyStyle (OH_Drawing_TypographyStyle * )
```

**描述**

释放被OH_Drawing_TypographyStyle对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针。 |


### OH_Drawing_FilterCreate()

```
OH_Drawing_Filter* OH_Drawing_FilterCreate (void )
```

**描述**

创建一个滤波器对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

返回创建的滤波器对象的指针。


### OH_Drawing_FilterDestroy()

```
void OH_Drawing_FilterDestroy (OH_Drawing_Filter * )
```

**描述**

销毁滤波器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Filter | 指示指向滤波器对象的指针。 |


### OH_Drawing_FilterSetColorFilter()

```
void OH_Drawing_FilterSetColorFilter (OH_Drawing_Filter * , OH_Drawing_ColorFilter *  )
```

**描述**

为滤波器对象设置颜色滤波器对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Filter | 指示指向滤波器对象的指针。 |
| OH_Drawing_ColorFilter | 指示指向颜色滤波器对象的指针。 |


### OH_Drawing_FilterSetMaskFilter()

```
void OH_Drawing_FilterSetMaskFilter (OH_Drawing_Filter * , OH_Drawing_MaskFilter *  )
```

**描述**

为滤波器对象设置蒙板滤波器对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Filter | 指示指向滤波器对象的指针。 |
| OH_Drawing_MaskFilter | 指示指向模板滤波器对象的指针。 |


### OH_Drawing_FontCreate()

```
OH_Drawing_Font* OH_Drawing_FontCreate (void )
```

**描述**

用于创建一个字体对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

函数会返回一个指针，指针指向创建的字体对象。


### OH_Drawing_FontDestroy()

```
void OH_Drawing_FontDestroy (OH_Drawing_Font * )
```

**描述**

用于销毁字体对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 |


### OH_Drawing_FontSetFakeBoldText()

```
void OH_Drawing_FontSetFakeBoldText (OH_Drawing_Font * , bool isFakeBoldText )
```

**描述**

用于设置增加描边宽度以近似粗体字体效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 |
| isFakeBoldText | 参数真为使能增加描边宽度，参数假为不使能。 |


### OH_Drawing_FontSetLinearText()

```
void OH_Drawing_FontSetLinearText (OH_Drawing_Font * , bool isLinearText )
```

**描述**

用于设置线性可缩放字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 |
| isLinearText | 参数真为使能线性可缩放字体，参数假为不使能。 |


### OH_Drawing_FontSetTextSize()

```
void OH_Drawing_FontSetTextSize (OH_Drawing_Font * , float textSize )
```

**描述**

用于给字体设置文字大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 |
| textSize | 字体大小。 |


### OH_Drawing_FontSetTextSkewX()

```
void OH_Drawing_FontSetTextSkewX (OH_Drawing_Font * , float skewX )
```

**描述**

用于给字体设置文本倾斜。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 |
| skewX | X轴相对于Y轴的倾斜度。 |


### OH_Drawing_FontSetTypeface()

```
void OH_Drawing_FontSetTypeface (OH_Drawing_Font * , OH_Drawing_Typeface *  )
```

**描述**

用于给字体设置字形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 |
| OH_Drawing_Typeface | 指向字形对象的指针。 |


### OH_Drawing_GetAffinityFromPositionAndAffinity()

```
int OH_Drawing_GetAffinityFromPositionAndAffinity (OH_Drawing_PositionAndAffinity * )
```

**描述**

获取OH_Drawing_PositionAndAffinity对象的亲和性，根据亲和性可判断字体会靠近前方文本还是后方文本

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_PositionAndAffinity | 指向OH_Drawing_PositionAndAffinity对象的指针，由[OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate)或[OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster)获取。 |

**返回：**

返回OH_Drawing_PositionAndAffinity对象的亲和性


### OH_Drawing_GetBottomFromTextBox()

```
float OH_Drawing_GetBottomFromTextBox (OH_Drawing_TextBox * , int  )
```

**描述**

获取文本框底部位置

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int | 文本框的索引 |

**返回：**

返回文本框底部位置


### OH_Drawing_GetEndFromRange()

```
size_t OH_Drawing_GetEndFromRange (OH_Drawing_Range * )
```

**描述**

获取OH_Drawing_Range对象结束位置

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Range | 指向OH_Drawing_Range对象的指针，由[OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary)获取。 |

**返回：**

返回OH_Drawing_Range对象结束位置


### OH_Drawing_GetLeftFromTextBox()

```
float OH_Drawing_GetLeftFromTextBox (OH_Drawing_TextBox * , int  )
```

**描述**

获取文本框左侧位置

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int | 文本框的索引 |

**返回：**

返回文本框左侧位置


### OH_Drawing_GetPositionFromPositionAndAffinity()

```
size_t OH_Drawing_GetPositionFromPositionAndAffinity (OH_Drawing_PositionAndAffinity * )
```

**描述**

获取OH_Drawing_PositionAndAffinity对象的位置属性

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_PositionAndAffinity | 指向OH_Drawing_PositionAndAffinity对象的指针，由[OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate)或[OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster)获取。|

**返回：**

返回OH_Drawing_PositionAndAffinity对象的位置属性


### OH_Drawing_GetRightFromTextBox()

```
float OH_Drawing_GetRightFromTextBox (OH_Drawing_TextBox * , int  )
```

**描述**

获取文本框右侧位置

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int | 文本框的索引 |

**返回：**

返回文本框右侧位置


### OH_Drawing_GetSizeOfTextBox()

```
size_t OH_Drawing_GetSizeOfTextBox (OH_Drawing_TextBox * )
```

**描述**

获取文本框数量大小

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。|

**返回：**

返回文本框数量大小


### OH_Drawing_GetStartFromRange()

```
size_t OH_Drawing_GetStartFromRange (OH_Drawing_Range * )
```

**描述**

获取OH_Drawing_Range对象开始位置

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Range | 指向OH_Drawing_Range对象的指针，由[OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary)获取。 |

**返回：**

返回OH_Drawing_Range对象开始位置


### OH_Drawing_GetTextDirectionFromTextBox()

```
int OH_Drawing_GetTextDirectionFromTextBox (OH_Drawing_TextBox * , int  )
```

**描述**

获取文本框方向

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 |
| int | 文本框的索引 |

**返回：**

返回文本框方向


### OH_Drawing_GetTopFromTextBox()

```
float OH_Drawing_GetTopFromTextBox (OH_Drawing_TextBox * , int  )
```

**描述**

获取文本框顶部位置

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或[OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。|
| int | 文本框的索引 |

**返回：**

返回文本框顶部位置


### OH_Drawing_MaskFilterCreateBlur()

```
OH_Drawing_MaskFilter* OH_Drawing_MaskFilterCreateBlur (OH_Drawing_BlurType blurType, float sigma, bool respectCTM )
```

**描述**

创建具有模糊效果的模板滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| blurType | 表示模糊类型。 |
| sigma | 表示要应用的高斯模糊的标准偏差。必须大于0。 |
| respectCTM | 表示模糊标准差值被CTM修改，默认为真。 |

**返回：**

返回创建的模板滤波器对象的指针。


### OH_Drawing_MaskFilterDestroy()

```
void OH_Drawing_MaskFilterDestroy (OH_Drawing_MaskFilter * )
```

**描述**

销毁模板滤波器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_MaskFilter | 表示指向模板滤波器对象的指针。 |


### OH_Drawing_MatrixCreate()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreate (void )
```

**描述**

用于创建一个矩阵对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

函数会返回一个指针，指针指向创建的矩阵对象。


### OH_Drawing_MatrixDestroy()

```
void OH_Drawing_MatrixDestroy (OH_Drawing_Matrix * )
```

**描述**

用于销毁矩阵对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Matrix | 指向字体对象的指针。 |


### OH_Drawing_MatrixSetMatrix()

```
void OH_Drawing_MatrixSetMatrix (OH_Drawing_Matrix * , float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2 )
```

**描述**

用于给矩阵对象设置参数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象的指针。 |
| scaleX | 水平缩放系数。 |
| skewX | 水平倾斜系数。 |
| transX | 水平位移系数。 |
| skewY | 垂直倾斜系数。 |
| scaleY | 垂直缩放系数。 |
| transY | 垂直位移系数。 |
| persp0 | X轴透视系数。 |
| persp1 | Y轴透视系数。 |
| persp2 | 透视缩放系数。 |


### OH_Drawing_PathArcTo()

```
void OH_Drawing_PathArcTo (OH_Drawing_Path * , float x1, float y1, float x2, float y2, float startDeg, float sweepDeg )
```

**描述**

用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆， 然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 |
| x1 | 包围椭圆的矩形左上角点位置的横坐标。 |
| y1 | 包围椭圆的矩形左上角点位置的纵坐标。 |
| x2 | 包围椭圆的矩形右下角点位置的横坐标。 |
| y2 | 包围椭圆的矩形右下角点位置的纵坐标。 |
| startDeg | 起始的角度。 |
| sweepDeg | 扫描的度数。 |


### OH_Drawing_PathClose()

```
void OH_Drawing_PathClose (OH_Drawing_Path * )
```

**描述**

用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 |


### OH_Drawing_PathCreate()

```
OH_Drawing_Path* OH_Drawing_PathCreate (void )
```

**描述**

用于创建一个路径对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

函数会返回一个指针，指针指向创建的路径对象。


### OH_Drawing_PathCubicTo()

```
void OH_Drawing_PathCubicTo (OH_Drawing_Path * , float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY )
```

**描述**

用于添加一条从路径最后点位置到目标点位置的三阶贝塞尔圆滑曲线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 |
| ctrlX1 | 第一个控制点位置的横坐标。 |
| ctrlY1 | 第一个控制点位置的纵坐标。 |
| ctrlX2 | 第二个控制点位置的横坐标。 |
| ctrlY2 | 第二个控制点位置的纵坐标。 |
| endX | 目标点位置的横坐标。 |
| endY | 目标点位置的纵坐标。 |


### OH_Drawing_PathDestroy()

```
void OH_Drawing_PathDestroy (OH_Drawing_Path * )
```

**描述**

用于销毁路径对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 |


### OH_Drawing_PathLineTo()

```
void OH_Drawing_PathLineTo (OH_Drawing_Path * , float x, float y )
```

**描述**

用于添加一条从路径的最后点位置到目标点位置的线段。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 |
| x | 目标点的横坐标。 |
| y | 目标点的纵坐标。 |


### OH_Drawing_PathMoveTo()

```
void OH_Drawing_PathMoveTo (OH_Drawing_Path * , float x, float y )
```

**描述**

用于设置自定义路径的起始点位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 |
| x | 起始点的横坐标。 |
| y | 起始点的纵坐标。 |


### OH_Drawing_PathQuadTo()

```
void OH_Drawing_PathQuadTo (OH_Drawing_Path * , float ctrlX, float ctrlY, float endX, float endY )
```

**描述**

用于添加一条从路径最后点位置到目标点位置的二阶贝塞尔圆滑曲线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 |
| ctrlX | 控制点位置的横坐标。 |
| ctrlY | 控制点位置的纵坐标。 |
| endX | 目标点位置的横坐标。 |
| endY | 目标点位置的纵坐标。 |


### OH_Drawing_PathReset()

```
void OH_Drawing_PathReset (OH_Drawing_Path * )
```

**描述**

用于重置自定义路径数据。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 |


### OH_Drawing_PenCreate()

```
OH_Drawing_Pen* OH_Drawing_PenCreate (void )
```

**描述**

用于创建一个画笔对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

函数会返回一个指针，指针指向创建的画笔对象。


### OH_Drawing_PenDestroy()

```
void OH_Drawing_PenDestroy (OH_Drawing_Pen * )
```

**描述**

用于销毁画笔对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |


### OH_Drawing_PenGetAlpha()

```
uint8_t OH_Drawing_PenGetAlpha (const OH_Drawing_Pen * )
```

**描述**

获取画笔的透明度值。画笔在勾勒图形时透明通道会使用该值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 表示指向画笔对象的指针。 |

**返回：**

返回一个8比特的值表示透明度。


### OH_Drawing_PenGetCap()

```
OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap (const OH_Drawing_Pen * )
```

**描述**

用于获取画笔笔帽的样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |

**返回：**

函数返回画笔笔帽样式。


### OH_Drawing_PenGetColor()

```
uint32_t OH_Drawing_PenGetColor (const OH_Drawing_Pen * )
```

**描述**

用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |

**返回：**

函数返回一个描述颜色的32位（ARGB）变量。


### OH_Drawing_PenGetJoin()

```
OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin (const OH_Drawing_Pen * )
```

**描述**

用于获取画笔绘制折线转角的样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |

**返回：**

函数返回折线转角的样式。


### OH_Drawing_PenGetMiterLimit()

```
float OH_Drawing_PenGetMiterLimit (const OH_Drawing_Pen * )
```

**描述**

用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |

**返回：**

函数返回尖角的限制值。


### OH_Drawing_PenGetWidth()

```
float OH_Drawing_PenGetWidth (const OH_Drawing_Pen * )
```

**描述**

用于获取画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |

**返回：**

函数返回画笔的厚度。


### OH_Drawing_PenIsAntiAlias()

```
bool OH_Drawing_PenIsAntiAlias (const OH_Drawing_Pen * )
```

**描述**

用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |

**返回：**

函数返回画笔对象是否设置抗锯齿属性，返回真则设置了抗锯齿，返回假则没有设置抗锯齿。


### OH_Drawing_PenSetAlpha()

```
void OH_Drawing_PenSetAlpha (OH_Drawing_Pen * , uint8_t alpha )
```

**描述**

为画笔设置透明度值。画笔在勾勒图形时透明通道会使用该值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 表示指向画笔对象的指针。 |
| alpha | 表示要设置的透明度值，是一个8比特的变量。 |


### OH_Drawing_PenSetAntiAlias()

```
void OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen * , bool  )
```

**描述**

用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |
| bool | 参数真为抗锯齿，参数假则不做抗锯齿处理。 |


### OH_Drawing_PenSetCap()

```
void OH_Drawing_PenSetCap (OH_Drawing_Pen * , OH_Drawing_PenLineCapStyle  )
```

**描述**

用于设置画笔笔帽样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |
| OH_Drawing_PenLineCapStyle | 描述画笔笔帽样式的变量。 |


### OH_Drawing_PenSetColor()

```
void OH_Drawing_PenSetColor (OH_Drawing_Pen * , uint32_t color )
```

**描述**

用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |
| color | 描述颜色的32位（ARGB）变量。 |


### OH_Drawing_PenSetJoin()

```
void OH_Drawing_PenSetJoin (OH_Drawing_Pen * , OH_Drawing_PenLineJoinStyle  )
```

**描述**

用于设置画笔绘制转角的样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |
| OH_Drawing_PenLineJoinStyle | 描述折线转角样式的变量。 |


### OH_Drawing_PenSetMiterLimit()

```
void OH_Drawing_PenSetMiterLimit (OH_Drawing_Pen * , float miter )
```

**描述**

用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |
| miter | 描述尖角限制值的变量。 |


### OH_Drawing_PenSetWidth()

```
void OH_Drawing_PenSetWidth (OH_Drawing_Pen * , float width )
```

**描述**

用于设置画笔的厚度属性，厚度属性描述了画笔绘制图形轮廓的宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 |
| width | 描述画笔厚度的变量。 |


### OH_Drawing_PointCreate()

```
OH_Drawing_Point* OH_Drawing_PointCreate (float x, float y )
```

**描述**

用于创建一个坐标点对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| x | X轴坐标。 |
| y | Y轴坐标。 |

**返回：**

函数会返回一个指针，指针指向创建的坐标点对象。


### OH_Drawing_PointDestroy()

```
void OH_Drawing_PointDestroy (OH_Drawing_Point * )
```

**描述**

用于销毁坐标点对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Point | 指向坐标点对象的指针。 |


### OH_Drawing_RectCreate()

```
OH_Drawing_Rect* OH_Drawing_RectCreate (float left, float top, float right, float bottom )
```

**描述**

用于创建一个矩形对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| left | 矩形左上角的横坐标。 |
| top | 矩形左上角的纵坐标。 |
| right | 矩形右下角的横坐标。 |
| bottom | 矩形右下角的纵坐标。 |

**返回：**

函数会返回一个指针，指针指向创建的矩形对象。


### OH_Drawing_RectDestroy()

```
void OH_Drawing_RectDestroy (OH_Drawing_Rect * )
```

**描述**

用于销毁矩形对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 |


### OH_Drawing_RoundRectCreate()

```
OH_Drawing_RoundRect* OH_Drawing_RoundRectCreate (const OH_Drawing_Rect * , float xRad, float yRad )
```

**描述**

用于创建一个圆角矩形对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 |
| xRad | X轴上的圆角半径。 |
| yRad | Y轴上的圆角半径。 |

**返回：**

函数会返回一个指针，指针指向创建的圆角矩形对象。


### OH_Drawing_RoundRectDestroy()

```
void OH_Drawing_RoundRectDestroy (OH_Drawing_RoundRect * )
```

**描述**

用于销毁圆角矩形对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_RoundRect | 指向圆角矩形对象的指针。 |


### OH_Drawing_SetTextStyleBaseLine()

```
void OH_Drawing_SetTextStyleBaseLine (OH_Drawing_TextStyle * , int  )
```

**描述**

设置字体基线位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| int | OH_Drawing_TextBaseline枚举类型。 |


### OH_Drawing_SetTextStyleColor()

```
void OH_Drawing_SetTextStyleColor (OH_Drawing_TextStyle * , uint32_t  )
```

**描述**

设置文本颜色。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| uint32_t | 颜色。 |


### OH_Drawing_SetTextStyleDecoration()

```
void OH_Drawing_SetTextStyleDecoration (OH_Drawing_TextStyle * , int  )
```

**描述**

设置装饰。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| int | OH_Drawing_TextDecoration枚举类型。 |


### OH_Drawing_SetTextStyleDecorationColor()

```
void OH_Drawing_SetTextStyleDecorationColor (OH_Drawing_TextStyle * , uint32_t  )
```

**描述**

设置装饰颜色。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| uint32_t | 颜色。 |


### OH_Drawing_SetTextStyleDecorationStyle()

```
void OH_Drawing_SetTextStyleDecorationStyle (OH_Drawing_TextStyle * , int  )
```

**描述**

设置文本装饰样式

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 |
| int | 设置的文本装饰样式，支持可选的装饰样式具体可见[OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle)枚举。 |


### OH_Drawing_SetTextStyleDecorationThicknessScale()

```
void OH_Drawing_SetTextStyleDecorationThicknessScale (OH_Drawing_TextStyle * , double  )
```

**描述**

设置文本装饰线的厚度缩放比例

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 |
| double | 缩放比例 |


### OH_Drawing_SetTextStyleEllipsis()

```
void OH_Drawing_SetTextStyleEllipsis (OH_Drawing_TextStyle * , const char *  )
```

**描述**

设置文本的省略号内容

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 |
| char\* | 设置省略号内容，数据类型为指向char的指针 |


### OH_Drawing_SetTextStyleEllipsisModal()

```
void OH_Drawing_SetTextStyleEllipsisModal (OH_Drawing_TextStyle * , int  )
```

**描述**

设置文本的省略号样式

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 |
| int | 设置省略号样式，支持可选的省略号样式具体可见[OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)枚举。 |


### OH_Drawing_SetTextStyleFontFamilies()

```
void OH_Drawing_SetTextStyleFontFamilies (OH_Drawing_TextStyle * , int , const char * fontFamilies[] )
```

**描述**

设置字体类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| int | 字体名称数量。 |
| char | 指向字体类型的指针。 |


### OH_Drawing_SetTextStyleFontHeight()

```
void OH_Drawing_SetTextStyleFontHeight (OH_Drawing_TextStyle * , double  )
```

**描述**

设置字体高度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| double | 字体高度。 |


### OH_Drawing_SetTextStyleFontSize()

```
void OH_Drawing_SetTextStyleFontSize (OH_Drawing_TextStyle * , double  )
```

**描述**

设置字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| double | 字号。 |


### OH_Drawing_SetTextStyleFontStyle()

```
void OH_Drawing_SetTextStyleFontStyle (OH_Drawing_TextStyle * , int  )
```

**描述**

设置字体风格。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| int | OH_Drawing_FontStyle枚举类型。 |


### OH_Drawing_SetTextStyleFontWeight()

```
void OH_Drawing_SetTextStyleFontWeight (OH_Drawing_TextStyle * , int  )
```

**描述**

设置字重。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| int | OH_Drawing_FontWeight枚举类型。 |


### OH_Drawing_SetTextStyleHalfLeading()

```
void OH_Drawing_SetTextStyleHalfLeading (OH_Drawing_TextStyle * , bool  )
```

**描述**

设置文本为一半行间距

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 |
| bool | 设置一半行间距是否生效，true表示生效，false表示不生效 |


### OH_Drawing_SetTextStyleLetterSpacing()

```
void OH_Drawing_SetTextStyleLetterSpacing (OH_Drawing_TextStyle * , double  )
```

**描述**

设置文本的字符间距

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 |
| double | 间距大小 |


### OH_Drawing_SetTextStyleLocale()

```
void OH_Drawing_SetTextStyleLocale (OH_Drawing_TextStyle * , const char *  )
```

**描述**

设置语言区域。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |
| char | 语言区域，数据类型为指向char的指针。 |


### OH_Drawing_SetTextStyleWordSpacing()

```
void OH_Drawing_SetTextStyleWordSpacing (OH_Drawing_TextStyle * , double  )
```

**描述**

设置文本的单词间距

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针 |
| double | 间距大小 |


### OH_Drawing_SetTypographyTextAlign()

```
void OH_Drawing_SetTypographyTextAlign (OH_Drawing_TypographyStyle * , int  )
```

**描述**

设置文本对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针。 |
| int | OH_Drawing_TextAlign枚举类型。 |


### OH_Drawing_SetTypographyTextBreakStrategy()

```
void OH_Drawing_SetTypographyTextBreakStrategy (OH_Drawing_TypographyStyle * , int  )
```

**描述**

设置文本的中断策略

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针 |
| int | 设置中断策略，支持可选的中断策略具体可见[OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy)枚举。 |


### OH_Drawing_SetTypographyTextDirection()

```
void OH_Drawing_SetTypographyTextDirection (OH_Drawing_TypographyStyle * , int  )
```

**描述**

设置文本方向。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针。 |
| int | OH_Drawing_TextDirection枚举类型。 |


### OH_Drawing_SetTypographyTextEllipsisModal()

```
void OH_Drawing_SetTypographyTextEllipsisModal (OH_Drawing_TypographyStyle * , int  )
```

**描述**

设置文本的省略号样式

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针 |
| int | 设置省略号样式，支持可选的省略号样式样式具体可见[OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)枚举。 |


### OH_Drawing_SetTypographyTextMaxLines()

```
void OH_Drawing_SetTypographyTextMaxLines (OH_Drawing_TypographyStyle * , int  )
```

**描述**

设置文本最大行数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针。 |
| int | 最大行数。 |


### OH_Drawing_SetTypographyTextWordBreakType()

```
void OH_Drawing_SetTypographyTextWordBreakType (OH_Drawing_TypographyStyle * , int  )
```

**描述**

设置单词的断词方式

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针 |
| int | 设置断词方式，支持可选的断词方式样式具体可见[OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype)枚举。 |


### OH_Drawing_ShaderEffectCreateLinearGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateLinearGradient (const OH_Drawing_Point * startPt, const OH_Drawing_Point * endPt, const uint32_t * colors, const float * pos, uint32_t size, OH_Drawing_TileMode  )
```

**描述**

创建着色器，在两个指定点之间生成线性渐变。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| startPt | 表示渐变的起点。 |
| endPt | 表示渐变的终点。 |
| colors | 表示在两个点之间分布的颜色。 |
| pos | 表示每种对应颜色在颜色数组中的相对位置。 |
| size | 表示颜色和位置的数量。 |
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode)枚举。 |

**返回：**

返回创建的着色器对象的指针。


### OH_Drawing_ShaderEffectCreateRadialGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateRadialGradient (const OH_Drawing_Point * centerPt, float radius, const uint32_t * colors, const float * pos, uint32_t size, OH_Drawing_TileMode  )
```

**描述**

创建着色器，在给定圆心和半径的情况下生成径向渐变。 从起点到终点颜色从内到外进行圆形渐变（从中间向外拉）被称为径向渐变。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| centerPt | 指示渐变的圆心。 |
| radius | 指示此渐变的圆半径。 |
| colors | 表示在两个点之间分布的颜色。 |
| pos | 表示每种对应颜色在颜色数组中的相对位置。 |
| size | 表示颜色和位置的数量。 |
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode)枚举。 |

**返回：**

返回创建的着色器对象的指针。


### OH_Drawing_ShaderEffectCreateSweepGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateSweepGradient (const OH_Drawing_Point * centerPt, const uint32_t * colors, const float * pos, uint32_t size, OH_Drawing_TileMode  )
```

**描述**

创建着色器，在给定中心的情况下生成扇形渐变。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| centerPt | 表示渐变的圆心。 |
| colors | 表示在两个点之间分布的颜色。 |
| pos | 表示每种对应颜色在颜色数组中的相对位置。 |
| size | 表示颜色和位置的数量。 |
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode)枚举。 |

**返回：**

返回创建的着色器对象的指针。


### OH_Drawing_ShaderEffectDestroy()

```
void OH_Drawing_ShaderEffectDestroy (OH_Drawing_ShaderEffect * )
```

**描述**

销毁着色器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_ShaderEffect | 表示指向着色器对象的指针。 |


### OH_Drawing_TextBlobBuilderAllocRunPos()

```
const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos (OH_Drawing_TextBlobBuilder * , const OH_Drawing_Font * , int32_t count, const OH_Drawing_Rect *  )
```

**描述**

申请一块内存，用于存储文字和位置信息。返回的指针无需调用者管理， 当调用[OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake)后禁止使用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBlobBuilder | 指向文本构造器对象的指针。 |
| OH_Drawing_Font | 指向字体对象的指针。 |
| count | 文字的数量。 |
| OH_Drawing_Rect | 文本的边界框。 |


### OH_Drawing_TextBlobBuilderCreate()

```
OH_Drawing_TextBlobBuilder* OH_Drawing_TextBlobBuilderCreate (void )
```

**描述**

用于创建一个文本构造器对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

函数会返回一个指针，指针指向创建的文本构造器对象。


### OH_Drawing_TextBlobBuilderDestroy()

```
void OH_Drawing_TextBlobBuilderDestroy (OH_Drawing_TextBlobBuilder * )
```

**描述**

用于销毁文本构造器对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBlobBuilder | 指向文本构造器对象的指针。 |


### OH_Drawing_TextBlobBuilderMake()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake (OH_Drawing_TextBlobBuilder * )
```

**描述**

用于从文本构造器中创建文本对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBlobBuilder | 指向文本构造器对象的指针。 |

**返回：**

返回一个指针，指针指向创建的文本对象。


### OH_Drawing_TextBlobDestroy()

```
void OH_Drawing_TextBlobDestroy (OH_Drawing_TextBlob * )
```

**描述**

用于销毁文本对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextBlob | 指向文本对象的指针。 |


### OH_Drawing_TypefaceCreateDefault()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateDefault (void )
```

**描述**

用于创建一个默认的字形对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

返回一个指针，指针指向创建的字形对象。


### OH_Drawing_TypefaceDestroy()

```
void OH_Drawing_TypefaceDestroy (OH_Drawing_Typeface * )
```

**描述**

用于销毁字形对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typeface | 指向字形对象的指针。 |


### OH_Drawing_TypographyDidExceedMaxLines()

```
bool OH_Drawing_TypographyDidExceedMaxLines (OH_Drawing_Typography * )
```

**描述**

获取文本是否超过最大行

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |

**返回：**

返回文本是否超过最大行，true表示超过，false表示未超过


### OH_Drawing_TypographyGetAlphabeticBaseline()

```
double OH_Drawing_TypographyGetAlphabeticBaseline (OH_Drawing_Typography * )
```

**描述**

获取字母文字基线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |

**返回：**

返回字母文字基线。


### OH_Drawing_TypographyGetGlyphPositionAtCoordinate()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinate (OH_Drawing_Typography * , double , double  )
```

**描述**

获取坐标处文本的索引位置和亲和性

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |
| double | 光标的x坐标 |
| double | 光标的y坐标 |

**返回：**

返回坐标处字体的索引位置和亲和性，返回类型为[OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity)结构体。


### OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster (OH_Drawing_Typography * , double , double  )
```

**描述**

获取坐标处文本所属字符簇的索引位置和亲和性，字符簇指一个或多个字符组成的整体

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |
| double | 光标的x坐标 |
| double | 光标的y坐标 |

**返回：**

返回坐标处指定类型字体的索引位置和亲和性，返回类型为[OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity)结构体。


### OH_Drawing_TypographyGetHeight()

```
double OH_Drawing_TypographyGetHeight (OH_Drawing_Typography * )
```

**描述**

获取高度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |

**返回：**

返回高度。


### OH_Drawing_TypographyGetIdeographicBaseline()

```
double OH_Drawing_TypographyGetIdeographicBaseline (OH_Drawing_Typography * )
```

**描述**

获取表意文字基线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |

**返回：**

返回表意文字基线。


### OH_Drawing_TypographyGetLineCount()

```
size_t OH_Drawing_TypographyGetLineCount (OH_Drawing_Typography * )
```

**描述**

获取文本行数

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |

**返回：**

返回行数


### OH_Drawing_TypographyGetLineHeight()

```
double OH_Drawing_TypographyGetLineHeight (OH_Drawing_Typography * , int  )
```

**描述**

获取指定行的行高

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |
| int | 要指定的行数 |

**返回：**

返回指定行的行高


### OH_Drawing_TypographyGetLineWidth()

```
double OH_Drawing_TypographyGetLineWidth (OH_Drawing_Typography * , int  )
```

**描述**

获取指定行的行宽

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |
| int | 要指定的行数 |

**返回：**

返回指定行的行宽


### OH_Drawing_TypographyGetLongestLine()

```
double OH_Drawing_TypographyGetLongestLine (OH_Drawing_Typography * )
```

**描述**

获取最长行。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |

**返回：**

返回最长行。


### OH_Drawing_TypographyGetMaxIntrinsicWidth()

```
double OH_Drawing_TypographyGetMaxIntrinsicWidth (OH_Drawing_Typography * )
```

**描述**

获取最大固有宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |

**返回：**

返回最大固有宽度。


### OH_Drawing_TypographyGetMaxWidth()

```
double OH_Drawing_TypographyGetMaxWidth (OH_Drawing_Typography * )
```

**描述**

获取最大宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |

**返回：**

返回最大宽度。


### OH_Drawing_TypographyGetMinIntrinsicWidth()

```
double OH_Drawing_TypographyGetMinIntrinsicWidth (OH_Drawing_Typography * )
```

**描述**

获取最小固有宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |

**返回：**

返回最小固有宽度。


### OH_Drawing_TypographyGetRectsForPlaceholders()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForPlaceholders (OH_Drawing_Typography * )
```

**描述**

获取占位符的文本框

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |

**返回：**

返回占位符的文本框，返回类型为[OH_Drawing_TextBox](#oh_drawing_textbox)结构体。


### OH_Drawing_TypographyGetRectsForRange()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForRange (OH_Drawing_Typography * , size_t , size_t , OH_Drawing_RectHeightStyle , OH_Drawing_RectWidthStyle  )
```

**描述**

获取指定范围内的文本框

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |
| size_t | 设置开始位置 |
| size_t | 设置结束位置 |
| OH_Drawing_RectHeightStyle | 设置高度样式，支持可选的高度样式具体可见[OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle)枚举。 |
| OH_Drawing_RectWidthStyle | 设置宽度样式，支持可选的宽度样式具体可见[OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)枚举。 |

**返回：**

返回指定范围内的文本框，具体可见[OH_Drawing_TextBox](#oh_drawing_textbox)结构体。


### OH_Drawing_TypographyGetWordBoundary()

```
OH_Drawing_Range* OH_Drawing_TypographyGetWordBoundary (OH_Drawing_Typography * , size_t  )
```

**描述**

获取单词的边界

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针 |
| size_t | 单词索引 |

**返回：**

返回单词边界，返回类型为[OH_Drawing_Range](#oh_drawing_range)结构体。


### OH_Drawing_TypographyHandlerAddPlaceholder()

```
void OH_Drawing_TypographyHandlerAddPlaceholder (OH_Drawing_TypographyCreate * , OH_Drawing_PlaceholderSpan *  )
```

**描述**

设置占位符

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针 |
| [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | 指向OH_Drawing_PlaceholderSpan对象的指针 |


### OH_Drawing_TypographyHandlerAddText()

```
void OH_Drawing_TypographyHandlerAddText (OH_Drawing_TypographyCreate * , const char *  )
```

**描述**

设置文本内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针。 |
| char | 指向文本内容的指针。 |


### OH_Drawing_TypographyHandlerPopTextStyle()

```
void OH_Drawing_TypographyHandlerPopTextStyle (OH_Drawing_TypographyCreate * )
```

**描述**

排版弹出。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针。 |


### OH_Drawing_TypographyHandlerPushTextStyle()

```
void OH_Drawing_TypographyHandlerPushTextStyle (OH_Drawing_TypographyCreate * , OH_Drawing_TextStyle *  )
```

**描述**

设置排版风格。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向OH_Drawing_TypographyCreate对象的指针。 |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针。 |


### OH_Drawing_TypographyLayout()

```
void OH_Drawing_TypographyLayout (OH_Drawing_Typography * , double  )
```

**描述**

排版布局。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |
| double | 文本最大宽度 |


### OH_Drawing_TypographyPaint()

```
void OH_Drawing_TypographyPaint (OH_Drawing_Typography * , OH_Drawing_Canvas * , double , double  )
```

**描述**

显示文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针。 |
| OH_Drawing_Canvas | 指向OH_Drawing_Canvas对象的指针。 |
| double | x坐标。 |
| double | y坐标。 |
