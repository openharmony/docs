# Drawing


## 概述

Drawing模块提供包括2D图形渲染、文字绘制和图片显示等功能函数。

本模块不提供像素单位，和应用上下文环境保持一致。如果处于ArkUI开发环境中，采用框架默认像素单位vp。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [drawing_bitmap.h](drawing__bitmap_8h.md) | 文件中定义了与位图相关的功能函数 | 
| [drawing_brush.h](drawing__brush_8h.md) | 文件中定义了与画刷相关的功能函数。 | 
| [drawing_canvas.h](drawing__canvas_8h.md) | 文件中定义了与画布相关的功能函数。 | 
| [drawing_color.h](drawing__color_8h.md) | 文件中定义了与颜色相关的功能函数。 | 
| [drawing_color_filter.h](drawing__color__filter_8h.md) | 声明与绘图模块中的颜色滤波器对象相关的函数。 | 
| [drawing_filter.h](drawing__filter_8h.md) | 声明与绘图模块中的滤波器对象相关的函数。 | 
| [drawing_font.h](drawing__font_8h.md) | 文件中定义了与字体相关的功能函数。 | 
| [drawing_font_collection.h](drawing__font__collection_8h.md) | 定义绘制模块中与字体集合相关的函数。 | 
| [drawing_image.h](drawing__image_8h.md) | 文件中定义了与图片相关的功能函数。 | 
| [drawing_mask_filter.h](drawing__mask__filter_8h.md) | 声明与绘图模块中的对象相关的函数。 | 
| [drawing_matrix.h](drawing__matrix_8h.md) | 文件中定义了与矩阵相关的功能函数。 | 
| [drawing_memory_stream.h](drawing__memory__stream_8h.md) | 文件中定义了与内存流相关的功能函数。 | 
| [drawing_path.h](drawing__path_8h.md) | 文件中定义了与自定义路径相关的功能函数 | 
| [drawing_path_effect.h](drawing__path__effect_8h.md) | 文件中定义了与路径效果相关的功能函数。 | 
| [drawing_pen.h](drawing__pen_8h.md) | 文件中定义了与画笔相关的功能函数。 | 
| [drawing_point.h](drawing__point_8h.md) | 文件中定义了与坐标点相关的功能函数。 | 
| [drawing_rect.h](drawing__rect_8h.md) | 文件中定义了与矩形相关的功能函数。 | 
| [drawing_round_rect.h](drawing__round__rect_8h.md) | 文件中定义了与圆角矩形相关的功能函数。 | 
| [drawing_sampling_options.h](drawing__sampling__options_8h.md) | 文件中定义了与采样相关的功能函数。用于图片或者纹理等图像的采样。 | 
| [drawing_shader_effect.h](drawing__shader__effect_8h.md) | 声明与绘图模块中的着色器对象相关的函数。 | 
| [drawing_text_blob.h](drawing__text__blob_8h.md) | 文件中定义了与文字相关的功能函数。 | 
| [drawing_text_declaration.h](drawing__text__declaration_8h.md) | 提供2D绘制文本相关的数据结构声明 | 
| [drawing_text_typography.h](drawing__text__typography_8h.md) | 定义绘制模块中排版相关的函数。 | 
| [drawing_typeface.h](drawing__typeface_8h.md) | 文件中定义了与字形相关的功能函数。 不同的平台有自己的默认字形，也可以从ttf文件解析出三方指定字形，如宋体、黑体字形等。 | 
| [drawing_types.h](drawing__types_8h.md) | 文件中定义了用于绘制2D图形的数据类型，包括画布、画笔、画刷、位图和路径。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型 | 
| struct  [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | 定义字体度量信息的结构体。 | 
| struct  [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) | 结构体用于描述一块内存，描述文字和位置信息。 | 
| struct  [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | 用于描述位占位符跨度的结构体 | 
| struct  [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | 描述系统字体详细信息的结构体。 | 
| struct  [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | 文字行位置信息。 | 
| struct  [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | 定义一个二维的坐标点。 | 
| struct  [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) | 定义一个三维的坐标点。 | 
| struct  [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | 定义图片信息结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md)  [OH_Drawing_BitmapFormat](#oh_drawing_bitmapformat) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型。 | 
| typedef enum [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop)  [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) | 画布裁剪方式的枚举集合。 | 
| typedef struct [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)  [OH_Drawing_Font_Metrics](#oh_drawing_font_metrics) | 定义字体度量信息的结构体。 | 
| typedef enum [OH_Drawing_BlurType](#oh_drawing_blurtype)  [OH_Drawing_BlurType](#oh_drawing_blurtype) | 蒙版滤波器模糊操作类型的枚举。 | 
| typedef enum [OH_Drawing_PathDirection](#oh_drawing_pathdirection)  [OH_Drawing_PathDirection](#oh_drawing_pathdirection) | 添加闭合轮廓方向枚举。 | 
| typedef enum [OH_Drawing_PathFillType](#oh_drawing_pathfilltype)  [OH_Drawing_PathFillType](#oh_drawing_pathfilltype) | 定义路径的填充类型枚举。 | 
| typedef enum [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)  [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。 | 
| typedef enum [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)  [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。 | 
| typedef enum [OH_Drawing_FilterMode](#oh_drawing_filtermode)  [OH_Drawing_FilterMode](#oh_drawing_filtermode) | 过滤模式枚举。 | 
| typedef enum [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode)  [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) | 多级渐远纹理模式枚举。 | 
| typedef enum [OH_Drawing_TileMode](#oh_drawing_tilemode)  [OH_Drawing_TileMode](#oh_drawing_tilemode) | 着色器效果平铺模式的枚举。 | 
| typedef struct [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md)  [OH_Drawing_RunBuffer](#oh_drawing_runbuffer) | 结构体用于描述一块内存，描述文字和位置信息。 | 
| typedef struct [OH_Drawing_FontCollection](#oh_drawing_fontcollection)  [OH_Drawing_FontCollection](#oh_drawing_fontcollection) | 用于加载字体。 | 
| typedef struct [OH_Drawing_Typography](#oh_drawing_typography)  [OH_Drawing_Typography](#oh_drawing_typography) | 用于管理排版的布局和显示等。 | 
| typedef struct [OH_Drawing_TextStyle](#oh_drawing_textstyle)  [OH_Drawing_TextStyle](#oh_drawing_textstyle) | 用于管理字体颜色、装饰等。 | 
| typedef struct [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)  [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) | 用于管理排版风格，如文字方向等。 | 
| typedef struct [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)  [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) | 用于创建[OH_Drawing_Typography](#oh_drawing_typography)。 | 
| typedef struct [OH_Drawing_TextBox](#oh_drawing_textbox)  [OH_Drawing_TextBox](#oh_drawing_textbox) | 用于接收文本框的矩形大小、方向和数量大小。 | 
| typedef struct [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity)  [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) | 用于接收字体的位置和亲和性。 | 
| typedef struct [OH_Drawing_Range](#oh_drawing_range)  [OH_Drawing_Range](#oh_drawing_range) | 用于接收字体的起始位置和结束位置。 | 
| typedef struct [OH_Drawing_TextShadow](#oh_drawing_textshadow)  [OH_Drawing_TextShadow](#oh_drawing_textshadow) | 用于管理文本阴影。 | 
| typedef struct [OH_Drawing_FontParser](#oh_drawing_fontparser)  [OH_Drawing_FontParser](#oh_drawing_fontparser) | 用来解析系统字体文件。 | 
| typedef enum [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment)  [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment) | 占位符垂直对齐枚举。 | 
| typedef struct [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md)  [OH_Drawing_PlaceholderSpan](#oh_drawing_placeholderspan) | 用于描述位占位符跨度的结构体。 | 
| typedef enum [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle)  [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) | 文本装饰样式枚举。 | 
| typedef enum [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)  [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) | 省略号样式枚举。 | 
| typedef enum [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy)  [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) | 文本的中断策略枚举。 | 
| typedef enum [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype)  [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) | 单词的断词方式枚举。 | 
| typedef enum [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle)  [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) | 矩形框高度样式枚举。 | 
| typedef enum [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)  [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) | 矩形框宽度样式枚举。 | 
| typedef struct [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)  [OH_Drawing_FontDescriptor](#oh_drawing_fontdescriptor) | 描述系统字体详细信息的结构体。 | 
| typedef struct [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)  [OH_Drawing_LineMetrics](#oh_drawing_linemetrics) | 文字行位置信息。 | 
| typedef struct [OH_Drawing_Canvas](#oh_drawing_canvas)  [OH_Drawing_Canvas](#oh_drawing_canvas) | 定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字。 | 
| typedef struct [OH_Drawing_Pen](#oh_drawing_pen)  [OH_Drawing_Pen](#oh_drawing_pen) | 定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色。 | 
| typedef struct [OH_Drawing_Brush](#oh_drawing_brush)  [OH_Drawing_Brush](#oh_drawing_brush) | 定义为画刷，画刷用于描述填充图形的样式和颜色。 | 
| typedef struct [OH_Drawing_Path](#oh_drawing_path)  [OH_Drawing_Path](#oh_drawing_path) | 定义为路径，路径用于自定义各种形状。 | 
| typedef struct [OH_Drawing_Bitmap](#oh_drawing_bitmap)  [OH_Drawing_Bitmap](#oh_drawing_bitmap) | 定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据。 | 
| typedef struct [OH_Drawing_Point](#oh_drawing_point)  [OH_Drawing_Point](#oh_drawing_point) | 定义一个点，用于描述坐标点。 | 
| typedef struct [OH_Drawing_Point2D](_o_h___drawing___point2_d.md)  [OH_Drawing_Point2D](#oh_drawing_point2d) | 定义一个二维的坐标点。 | 
| typedef struct [OH_Drawing_Point3D](_o_h___drawing___point3_d.md)  [OH_Drawing_Point3D](#oh_drawing_point3d) | 定义一个三维的坐标点。 | 
| typedef struct [OH_Drawing_PathEffect](#oh_drawing_patheffect)  [OH_Drawing_PathEffect](#oh_drawing_patheffect) | 定义一个路径效果，用于影响描边路径。 | 
| typedef struct [OH_Drawing_Rect](#oh_drawing_rect)  [OH_Drawing_Rect](#oh_drawing_rect) | 用于描述矩形。 | 
| typedef struct [OH_Drawing_RoundRect](#oh_drawing_roundrect)  [OH_Drawing_RoundRect](#oh_drawing_roundrect) | 用于描述圆角矩形。 | 
| typedef struct [OH_Drawing_Matrix](#oh_drawing_matrix)  [OH_Drawing_Matrix](#oh_drawing_matrix) | 定义一个矩阵，用于描述坐标变换。 | 
| typedef struct [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)  [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) | 定义一个着色器，用于描述绘制内容的源颜色。 | 
| typedef struct [OH_Drawing_Filter](#oh_drawing_filter)  [OH_Drawing_Filter](#oh_drawing_filter) | 定义一个滤波器，用于存储颜色滤波器和模板滤波器。 | 
| typedef struct [OH_Drawing_MaskFilter](#oh_drawing_maskfilter)  [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) | 定义模板滤波器，用于在绘制模板前对其进行转换。 | 
| typedef struct [OH_Drawing_ColorFilter](#oh_drawing_colorfilter)  [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) | 定义颜色滤波器，传入一个颜色并返回一个新的颜色。 | 
| typedef struct [OH_Drawing_Font](#oh_drawing_font)  [OH_Drawing_Font](#oh_drawing_font) | 用于描述字体。 | 
| typedef struct [OH_Drawing_MemoryStream](#oh_drawing_memorystream)  [OH_Drawing_MemoryStream](#oh_drawing_memorystream) | 用于描述内存流。 | 
| typedef struct [OH_Drawing_Typeface](#oh_drawing_typeface)  [OH_Drawing_Typeface](#oh_drawing_typeface) | 用于描述字形。 | 
| typedef struct [OH_Drawing_TextBlob](#oh_drawing_textblob)  [OH_Drawing_TextBlob](#oh_drawing_textblob) | 定义一个文本对象，表示将多个文本组合到一个不可变的容器中。 每个文本行由字形和位置组成。 | 
| typedef struct [OH_Drawing_Image](#oh_drawing_image)  [OH_Drawing_Image](#oh_drawing_image) | 定义一个用于描述绘制二维像素数组的图片。 | 
| typedef struct [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)  [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) | 定义一个采样选项，用于描述图片、位图等图像的采样方法。 | 
| typedef struct [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder)  [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) | 定义文本构建器，用于构建文本。 | 
| typedef enum [OH_Drawing_ColorFormat](#oh_drawing_colorformat)  [OH_Drawing_ColorFormat](#oh_drawing_colorformat) | 用于描述位图像素的存储格式。 | 
| typedef enum [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat)  [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) | 用于描述位图像素的透明度分量。 | 
| typedef enum [OH_Drawing_BlendMode](#oh_drawing_blendmode)  [OH_Drawing_BlendMode](#oh_drawing_blendmode) | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在4个颜色通道（红、绿、蓝、透明度）上是相同的。 对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。 | 
| typedef struct [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)  [OH_Drawing_Image_Info](#oh_drawing_image_info) | 定义图片信息结构体。 | 
| typedef enum [OH_Drawing_TextEncoding](#oh_drawing_textencoding)  [OH_Drawing_TextEncoding](#oh_drawing_textencoding) | 文本编码类型枚举。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) { DIFFERENCE, INTERSECT } | 画布裁剪方式的枚举集合。 | 
| [OH_Drawing_BlurType](#oh_drawing_blurtype) { NORMAL, SOLID, OUTER, INNER } | 蒙版滤波器模糊操作类型的枚举。 | 
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection) { PATH_DIRECTION_CW, PATH_DIRECTION_CCW } | 添加闭合轮廓方向枚举。 | 
| [OH_Drawing_PathFillType](#oh_drawing_pathfilltype) { PATH_FILL_TYPE_WINDING, PATH_FILL_TYPE_EVEN_ODD, PATH_FILL_TYPE_INVERSE_WINDING, PATH_FILL_TYPE_INVERSE_EVEN_ODD } | 定义路径的填充类型枚举。 | 
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。 | 
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。 | 
| [OH_Drawing_FilterMode](#oh_drawing_filtermode) { FILTER_MODE_NEAREST, FILTER_MODE_LINEAR } | 过滤模式枚举。 | 
| [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode) { MIPMAP_MODE_NONE, MIPMAP_MODE_NEAREST, MIPMAP_MODE_LINEAR } | 多级渐远纹理模式枚举。 | 
| [OH_Drawing_TileMode](#oh_drawing_tilemode) { CLAMP, REPEAT, MIRROR, DECAL } | 着色器效果平铺模式的枚举。 | 
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | 文字方向 | 
| [OH_Drawing_TextAlign](#oh_drawing_textalign) {<br/>TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,<br/>TEXT_ALIGN_START, TEXT_ALIGN_END<br/>} | 文字对齐方式 | 
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) {<br/>FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,<br/>FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,<br/>FONT_WEIGHT_900<br/>} | 字重 | 
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | 基线位置 | 
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | 文本装饰 | 
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC } | 区分字体是否为斜体 | 
| [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment) {<br/>ALIGNMENT_OFFSET_AT_BASELINE, ALIGNMENT_ABOVE_BASELINE, ALIGNMENT_BELOW_BASELINE, ALIGNMENT_TOP_OF_ROW_BOX,<br/>ALIGNMENT_BOTTOM_OF_ROW_BOX, ALIGNMENT_CENTER_OF_ROW_BOX<br/>} | 占位符垂直对齐枚举 | 
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) {<br/>TEXT_DECORATION_STYLE_SOLID, TEXT_DECORATION_STYLE_DOUBLE, TEXT_DECORATION_STYLE_DOTTED, TEXT_DECORATION_STYLE_DASHED,<br/>TEXT_DECORATION_STYLE_WAVY<br/>} | 文本装饰样式枚举 | 
| [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) { ELLIPSIS_MODAL_HEAD = 0, ELLIPSIS_MODAL_MIDDLE = 1, ELLIPSIS_MODAL_TAIL = 2 } | 省略号样式枚举 | 
| [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) { BREAK_STRATEGY_GREEDY = 0, BREAK_STRATEGY_HIGH_QUALITY = 1, BREAK_STRATEGY_BALANCED = 2 } | 文本的中断策略枚举 | 
| [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) { WORD_BREAK_TYPE_NORMAL = 0, WORD_BREAK_TYPE_BREAK_ALL = 1, WORD_BREAK_TYPE_BREAK_WORD = 2 } | 单词的断词方式枚举 | 
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) {<br/>RECT_HEIGHT_STYLE_TIGHT, RECT_HEIGHT_STYLE_MAX, RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE, RECT_HEIGHT_STYLE_INCLUDELINESPACETOP,<br/>RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM, RECT_HEIGHT_STYLE_STRUCT<br/>} | 矩形框高度样式枚举 | 
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) { RECT_WIDTH_STYLE_TIGHT, RECT_WIDTH_STYLE_MAX } | 矩形框宽度样式枚举 | 
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat) {<br/>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,<br/>COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br/>} | 用于描述位图像素的存储格式。 | 
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | 用于描述位图像素的透明度分量。 | 
| [OH_Drawing_BlendMode](#oh_drawing_blendmode) {<br/>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br/>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br/>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br/>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br/>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br/>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br/>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br/>BLEND_MODE_LUMINOSITY<br/>} | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在4个颜色通道（红、绿、蓝、透明度）上是相同的。 对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。 | 
| [OH_Drawing_TextEncoding](#oh_drawing_textencoding) { TEXT_ENCODING_UTF8, TEXT_ENCODING_UTF16, TEXT_ENCODING_UTF32, TEXT_ENCODING_GLYPH_ID } | 文本编码类型枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreate](#oh_drawing_bitmapcreate) (void) | 用于创建一个位图对象。 | 
| void [OH_Drawing_BitmapDestroy](#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于销毁位图对象并回收该对象占有内存。 | 
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreateFromPixels](#oh_drawing_bitmapcreatefrompixels) ([OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*pixels, uint32_t rowBytes) | 用于创建一个位图对象，并将位图像素存储内存地址设置为开发者申请内存的地址。 | 
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
| void [OH_Drawing_BrushSetBlendMode](#oh_drawing_brushsetblendmode) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | 为画刷设置一个混合器，该混合器实现了指定的混合模式枚举。 | 
| [OH_Drawing_Canvas](#oh_drawing_canvas) \* [OH_Drawing_CanvasCreate](#oh_drawing_canvascreate) (void) | 用于创建一个画布对象。 | 
| void [OH_Drawing_CanvasDestroy](#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于销毁画布对象并回收该对象占有的内存。 | 
| void [OH_Drawing_CanvasBind](#oh_drawing_canvasbind) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。 | 
| void [OH_Drawing_CanvasAttachPen](#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。 | 
| void [OH_Drawing_CanvasDetachPen](#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。 | 
| void [OH_Drawing_CanvasAttachBrush](#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。 | 
| void [OH_Drawing_CanvasDetachBrush](#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于去除掉画布中的画刷，使用后画布将不去填充图形形状。 | 
| void [OH_Drawing_CanvasSave](#oh_drawing_canvassave) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于保存当前画布的状态（画布矩阵）到一个栈顶。 | 
| void [OH_Drawing_CanvasSaveLayer](#oh_drawing_canvassavelayer) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 保存矩阵和裁剪区域，为后续绘制分配位图。调用恢复接口[OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore)将放弃对矩阵和剪切区域所做的更改，并绘制位图。 | 
| void [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于恢复保存在栈顶的画布状态（画布矩阵）。 | 
| uint32_t [OH_Drawing_CanvasGetSaveCount](#oh_drawing_canvasgetsavecount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于获取栈中保存的画布状态（画布矩阵）的数量。 | 
| void [OH_Drawing_CanvasRestoreToCount](#oh_drawing_canvasrestoretocount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t saveCount) | 用于恢复到指定数量的画布状态（画布矩阵）。 | 
| void [OH_Drawing_CanvasDrawLine](#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | 用于画一条直线段。 | 
| void [OH_Drawing_CanvasDrawPath](#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*) | 用于画一个自定义路径。 | 
| void [OH_Drawing_CanvasDrawBitmap](#oh_drawing_canvasdrawbitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, float left, float top) | 用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。 | 
| void [OH_Drawing_CanvasDrawBitmapRect](#oh_drawing_canvasdrawbitmaprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | 将位图的指定区域绘制到画布的指定区域。 | 
| void [OH_Drawing_CanvasSetMatrix](#oh_drawing_canvassetmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 设置画布的矩阵状态。 | 
| void [OH_Drawing_CanvasDrawImageRect](#oh_drawing_canvasdrawimagerect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*dst, [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | 将图片绘制到画布的指定区域上。 | 
| bool [OH_Drawing_CanvasReadPixels](#oh_drawing_canvasreadpixels) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY) | 从画布中拷贝像素数据到指定地址。该接口不可用于录制类型画布。 | 
| bool [OH_Drawing_CanvasReadPixelsToBitmap](#oh_drawing_canvasreadpixelstobitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, int32_t srcX, int32_t srcY) | 从画布拷贝像素数据到位图中。该接口不可用于录制类型画布。 | 
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
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontGetTypeface](#oh_drawing_fontgettypeface) ([OH_Drawing_Font](#oh_drawing_font) \*) | 获取字形对象。 | 
| void [OH_Drawing_FontSetTextSize](#oh_drawing_fontsettextsize) ([OH_Drawing_Font](#oh_drawing_font) \*, float textSize) | 用于给字体设置文字大小。 | 
| int [OH_Drawing_FontCountText](#oh_drawing_fontcounttext) ([OH_Drawing_Font](#oh_drawing_font) \*, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding) | 获取文本所表示的字符数量。 | 
| void [OH_Drawing_FontSetLinearText](#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isLinearText) | 用于设置线性可缩放字体。 | 
| void [OH_Drawing_FontSetTextSkewX](#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](#oh_drawing_font) \*, float skewX) | 用于给字体设置文本倾斜。 | 
| void [OH_Drawing_FontSetFakeBoldText](#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isFakeBoldText) | 用于设置增加描边宽度以近似粗体字体效果。 | 
| void [OH_Drawing_FontDestroy](#oh_drawing_fontdestroy) ([OH_Drawing_Font](#oh_drawing_font) \*) | 用于销毁字体对象并回收该对象占有的内存。 | 
| float [OH_Drawing_FontGetMetrics](#oh_drawing_fontgetmetrics) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | 获取字体度量信息。 | 
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \* [OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection) (void) | 创建字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)。 | 
| void [OH_Drawing_DestroyFontCollection](#oh_drawing_destroyfontcollection) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | 释放被字体集对象占据的内存。 | 
| void [OH_Drawing_DisableFontCollectionFallback](#oh_drawing_disablefontcollectionfallback) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*fontCollection) | 禁用备用字体。 | 
| void [OH_Drawing_DisableFontCollectionSystemFont](#oh_drawing_disablefontcollectionsystemfont) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*fontCollection) | 禁用系统字体。 | 
| [OH_Drawing_Image](#oh_drawing_image) \* [OH_Drawing_ImageCreate](#oh_drawing_imagecreate) (void) | 创建一个图片对象，描述了要绘制的二维像素数组。 | 
| void [OH_Drawing_ImageDestroy](#oh_drawing_imagedestroy) ([OH_Drawing_Image](#oh_drawing_image) \*) | 销毁图片对象并回收该对象占有内存。 | 
| bool [OH_Drawing_ImageBuildFromBitmap](#oh_drawing_imagebuildfrombitmap) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 从位图构造图片对象内容，共享或复制位图像素。如果位图被标记为不可变状态， 像素内存是共享的，不是复制。 | 
| int32_t [OH_Drawing_ImageGetWidth](#oh_drawing_imagegetwidth) ([OH_Drawing_Image](#oh_drawing_image) \*) | 获取图片宽度，即每行的像素个数。 | 
| int32_t [OH_Drawing_ImageGetHeight](#oh_drawing_imagegetheight) ([OH_Drawing_Image](#oh_drawing_image) \*) | 获取图片高度，即像素行数。 | 
| void [OH_Drawing_ImageGetImageInfo](#oh_drawing_imagegetimageinfo) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | 获取图片信息。调用该接口后，传入的图片信息对象被填充。 | 
| [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \* [OH_Drawing_MaskFilterCreateBlur](#oh_drawing_maskfiltercreateblur) ([OH_Drawing_BlurType](#oh_drawing_blurtype) blurType, float sigma, bool respectCTM) | 创建具有模糊效果的模板滤波器。 | 
| void [OH_Drawing_MaskFilterDestroy](#oh_drawing_maskfilterdestroy) ([OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | 销毁模板滤波器对象，并收回该对象占用的内存。 | 
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate) (void) | 用于创建一个矩阵对象。 | 
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateRotation](#oh_drawing_matrixcreaterotation) (float deg, float x, float y) | 创建一个带旋转属性的矩阵对象。 该矩阵对象为：单位矩阵在(x, y)旋转点以度为单位进行旋转。 | 
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateScale](#oh_drawing_matrixcreatescale) (float sx, float sy, float px, float py) | 创建一个带缩放属性的矩阵对象。 该矩阵对象为：单位矩阵在(px, py)旋转点以sx和sy为缩放因子进行缩放。 | 
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateTranslation](#oh_drawing_matrixcreatetranslation) (float dx, float dy) | 创建一个带平移属性的矩阵对象。 | 