# Drawing


## 概述

Drawing模块提供包括2D图形渲染、文字绘制和图片显示等功能函数。 本模块采用屏幕物理像素单位px。本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [drawing_bitmap.h](drawing__bitmap_8h.md) | 文件中定义了与位图相关的功能函数。 | 
| [drawing_brush.h](drawing__brush_8h.md) | 文件中定义了与画刷相关的功能函数。 | 
| [drawing_canvas.h](drawing__canvas_8h.md) | 文件中定义了与画布相关的功能函数。画布自带一个黑色，开启抗锯齿，不具备其他任何样式的默认画刷，当且仅当画布中主动设置的画刷和画笔都不存在时生效。非录制类型画布会将绘制指令直接绘制到绑定的位图中，录制类型画布会将绘制指令录制下来用于后续的回放。 | 
| [drawing_color.h](drawing__color_8h.md) | 文件中定义了与颜色相关的功能函数。 | 
| [drawing_color_filter.h](drawing__color__filter_8h.md) | 声明与绘图模块中的颜色滤波器对象相关的函数。 | 
| [drawing_error_code.h](drawing__error__code_8h.md) | 声明与绘图模块中的错误码相关的函数。 | 
| [drawing_color_space.h](drawing__color__space_8h.md) | 文件中定义了与颜色空间相关的功能函数。 | 
| [drawing_filter.h](drawing__filter_8h.md) | 声明与绘图模块中的滤波器对象相关的函数。 | 
| [drawing_font.h](drawing__font_8h.md) | 文件中定义了与字体相关的功能函数。 | 
| [drawing_font_collection.h](drawing__font__collection_8h.md) | 定义绘制模块中与字体集合相关的函数。 | 
| [drawing_font_mgr.h](drawing__font__mgr_8h.md) | 文件中定义了与字体管理相关的功能函数，用于加载和匹配系统中可用的字体。 | 
| [drawing_gpu_context.h](drawing__gpu__context_8h.md) | 声明与绘图模块中的图形处理器上下文对象相关的函数。 | 
| [drawing_image.h](drawing__image_8h.md) | 文件中定义了与图片相关的功能函数。 | 
| [drawing_image_filter.h](drawing__image__filter_8h.md) | 声明与绘图模块中的图像滤波器对象相关的函数。 | 
| [drawing_mask_filter.h](drawing__mask__filter_8h.md) | 声明与绘图模块中的对象相关的函数。 | 
| [drawing_matrix.h](drawing__matrix_8h.md) | 文件中定义了与矩阵相关的功能函数。 | 
| [drawing_memory_stream.h](drawing__memory__stream_8h.md) | 文件中定义了与内存流相关的功能函数。 | 
| [drawing_path.h](drawing__path_8h.md) | 文件中定义了与自定义路径相关的功能函数。 | 
| [drawing_path_effect.h](drawing__path__effect_8h.md) | 文件中定义了与路径效果相关的功能函数。 | 
| [drawing_pen.h](drawing__pen_8h.md) | 文件中定义了与画笔相关的功能函数。 | 
| [drawing_pixel_map.h](drawing__pixel__map_8h.md) | 声明与绘图模块中的像素图对象相关的函数。 | 
| [drawing_point.h](drawing__point_8h.md) | 文件中定义了与坐标点相关的功能函数。 | 
| [drawing_record_cmd.h](drawing__record__cmd_8h.md) | 文件中定义了与录制指令对象相关的功能函数。 |
| [drawing_rect.h](drawing__rect_8h.md) | 文件中定义了与矩形相关的功能函数。 | 
| [drawing_region.h](drawing__region_8h.md) | 定义了与区域相关的功能函数，包括区域的创建，边界设置和销毁等。 | 
| [drawing_register_font.h](drawing__register__font_8h.md) | 定义绘制模块中字体管理器相关的函数。 | 
| [drawing_round_rect.h](drawing__round__rect_8h.md) | 文件中定义了与圆角矩形相关的功能函数。 | 
| [drawing_sampling_options.h](drawing__sampling__options_8h.md) | 文件中定义了与采样相关的功能函数。用于图片或者纹理等图像的采样。 | 
| [drawing_shader_effect.h](drawing__shader__effect_8h.md) | 声明与绘图模块中的着色器对象相关的函数。 | 
| [drawing_shadow_layer.h](drawing__shadow__layer_8h.md) | 声明与绘图模块中的阴影层对象相关的函数。 | 
| [drawing_surface.h](drawing__surface_8h.md) | 文件中定义与surface相关的功能函数，包括surface的创建、销毁和使用等。 | 
| [drawing_text_blob.h](drawing__text__blob_8h.md) | 文件中定义了与文字相关的功能函数。 | 
| [drawing_text_declaration.h](drawing__text__declaration_8h.md) | 提供2d 绘制文本相关的数据结构声明。 | 
| [drawing_text_font_descriptor.h](drawing__text__font__descriptor_8h.md) | 定义了字体信息的相关接口，比如获取字体信息，查找指定字体等。 |
| [drawing_text_line.h](drawing__text__line_8h.md) | 提供获取文本行内的字符位置、获取渲染单元信息和按行截断等功能。 |
| [drawing_text_lineTypography.h](drawing__text__line_typography_8h.md) | 提供排版行相关的接口，比如获取指定位置处开始可以排版的字符个数等函数。 | 
| [drawing_text_run.h](drawing__text__run_8h.md) | 提供字体渲染单元的相关接口，比如绘制功能、获取排版边界功能等。  |
| [drawing_text_typography.h](drawing__text__typography_8h.md) | 定义绘制模块中排版相关的函数。 | 
| [drawing_typeface.h](drawing__typeface_8h.md) | 文件中定义了与字形相关的功能函数。 不同的平台有自己的默认字形，也可以从ttf文件解析出三方指定字形，如宋体、黑体字形等。 | 
| [drawing_types.h](drawing__types_8h.md) | 文件中定义了用于绘制2d图形的数据类型，包括画布、画笔、画刷、位图和路径。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_Drawing_String](_o_h___drawing___string.md) | 采用UTF-16编码的字符串信息结构体。 |
| struct  [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型。 | 
| struct  [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | 定义字体度量信息的结构体。 | 
| struct  [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md) | 定义有关图形处理器上下文的选项。 | 
| struct  [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) | 结构体用于描述一块内存，描述文字和位置信息。 | 
| struct  [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) | 用于描述占位符跨度的结构体。 | 
| struct  [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | 描述系统字体详细信息的结构体。 | 
| struct  [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | 文字行位置信息。 | 
| struct  [OH_Drawing_FontFallbackInfo](_o_h___drawing___font_fallback_info.md) | 备用字体信息结构体。 | 
| struct  [OH_Drawing_FontFallbackGroup](_o_h___drawing___font_fallback_group.md) | 备用字体集信息结构体。 | 
| struct  [OH_Drawing_FontAdjustInfo](_o_h___drawing___font_adjust_info.md) | 字重映射信息结构体。 | 
| struct  [OH_Drawing_FontAliasInfo](_o_h___drawing___font_alias_info.md) | 别名字体信息结构体。 | 
| struct  [OH_Drawing_FontGenericInfo](_o_h___drawing___font_generic_info.md) | 系统所支持的通用字体集信息结构体。 | 
| struct  [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) | 系统字体配置信息结构体。 | 
| struct  [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | 定义字体样式信息的结构体。 | 
| struct  [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) | 描述文本字体特征结构体。 | 
| struct  [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) | 用于描述支柱样式的结构体。支柱样式用于控制绘制文本时行之间的间距、基线对齐方式以及其他与行高相关的属性。 | 
| struct  [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | 定义一个二维的坐标点。 | 
| struct  [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) | 定义一个三维的坐标点。 | 
| struct  [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | 定义图片信息结构体。 | 
| struct  [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) | 定义矩形框样式结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle) [OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle) | 路径效果的绘制样式枚举。  | 
| typedef struct [OH_Drawing_String](_o_h___drawing___string.md) [OH_Drawing_String](#oh_drawing_string) | 采用UTF-16编码的字符串信息结构体。 |
| typedef enum [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype) | 字体类型的枚举。 |
| typedef bool(\* [Drawing_CaretOffsetsCallback](#drawing_caretoffsetscallback)) (double offset, int32_t index, bool leadingEdge) | 用户自定义的回调函数。将文本行对象中每个字符的偏移量、索引值作为参数传递给用户自定义的回调函数。 |
| typedef struct [OH_Drawing_LineTypography](#oh_drawing_linetypography) [OH_Drawing_LineTypography](#oh_drawing_linetypography) | 用于从一段文字中提取单行数据进行排版。 |
| typedef struct [OH_Drawing_TextTab](#oh_drawing_texttab) [OH_Drawing_TextTab](#oh_drawing_texttab) | 用于管理文本制表符。 |
| typedef struct [OH_Drawing_TextLine](#oh_drawing_textline) [OH_Drawing_TextLine](#oh_drawing_textline) | 用于管理文本行。 | 
| typedef struct [OH_Drawing_Run](#oh_drawing_run) [OH_Drawing_Run](#oh_drawing_run) | 用于管理文本渲染单元。 | 
| typedef struct [OH_Drawing_Array](#oh_drawing_array) [OH_Drawing_Array](#oh_drawing_array) | 定义数组对象, 用于存储多个同类型对象。 |
| typedef struct [OH_Drawing_FontArguments](#oh_drawing_fontarguments) [OH_Drawing_FontArguments](#oh_drawing_fontarguments) | 用于描述字型参数。 | 
| typedef struct [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) | 定义指令录制工具，用于生成录制指令。 | 
| typedef struct [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) | 定义录制指令类, 用于存储录制指令的集合。 |
| typedef enum [OH_Drawing_ErrorCode](#oh_drawing_errorcode)  [OH_Drawing_ErrorCode](#oh_drawing_errorcode) | 枚举本模块可能产生的错误码。 | 
| typedef enum [OH_Drawing_PathOpMode](#oh_drawing_pathopmode)  [OH_Drawing_PathOpMode](#oh_drawing_pathopmode) | 路径操作类型枚举。 | 
| typedef enum [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags)  [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags) | 路径测量获取相应矩阵信息维度枚举。 |
| typedef enum [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode)  [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode) | 区域操作类型枚举。 | 
| typedef struct [OH_Drawing_ImageFilter](#oh_drawing_imagefilter)  [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) | 定义图像滤波器, 用于对构成图像像素的所有颜色位进行操作。 | 
| typedef struct [OH_Drawing_Filter](#oh_drawing_filter)  [OH_Drawing_Filter](#oh_drawing_filter) | 定义一个滤波器，用于存储颜色滤波器，蒙版滤波器和图像滤波器。 | 
| typedef struct [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md)  [OH_Drawing_BitmapFormat](#oh_drawing_bitmapformat) | 结构体用于描述位图像素的格式，包括颜色类型和透明度类型。 | 
| typedef enum [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint)  [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint) | 源矩形区域约束类型枚举。 | 
| typedef enum [OH_Drawing_PointMode](#oh_drawing_pointmode)  [OH_Drawing_PointMode](#oh_drawing_pointmode) | 绘制多个点的方式枚举，方式分为离散点、直线或开放多边形。 | 
| typedef enum [OH_Drawing_VertexMode](#oh_drawing_vertexmode)  [OH_Drawing_VertexMode](#oh_drawing_vertexmode) | 用于指定如何解释给定顶点的几何形状的枚举类型。 | 
| typedef enum [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop)  [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) | 画布裁剪方式的枚举集合。 | 
| typedef enum [OH_Drawing_FontEdging](#oh_drawing_fontedging)  [OH_Drawing_FontEdging](#oh_drawing_fontedging) | 字型边缘效果类型枚举。 | 
| typedef enum [OH_Drawing_FontHinting](#oh_drawing_fonthinting)  [OH_Drawing_FontHinting](#oh_drawing_fonthinting) | 字型轮廓效果类型枚举。 | 
| typedef struct [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)  [OH_Drawing_Font_Metrics](#oh_drawing_font_metrics) | 定义字体度量信息的结构体。 | 
| typedef struct [OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)  [OH_Drawing_GpuContextOptions](#oh_drawing_gpucontextoptions) | 定义有关图形处理器上下文的选项。 | 
| typedef enum [OH_Drawing_BlurType](#oh_drawing_blurtype)  [OH_Drawing_BlurType](#oh_drawing_blurtype) | 蒙版滤波器模糊操作类型的枚举。 | 
| typedef enum [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit)  [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit) | 矩阵缩放方式枚举。 | 
| typedef enum [OH_Drawing_PathDirection](#oh_drawing_pathdirection)  [OH_Drawing_PathDirection](#oh_drawing_pathdirection) | 添加闭合轮廓方向枚举。 | 
| typedef enum [OH_Drawing_PathFillType](#oh_drawing_pathfilltype)  [OH_Drawing_PathFillType](#oh_drawing_pathfilltype) | 定义路径的填充类型枚举。 | 
| typedef enum [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)  [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode) | 用于指定路径添加模式的枚举类型。 | 
| typedef enum [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)  [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。 | 
| typedef enum [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)  [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。 | 
| typedef enum [OH_Drawing_CornerPos](#oh_drawing_cornerpos)  [OH_Drawing_CornerPos](#oh_drawing_cornerpos) | 用于描述圆角位置的枚举。 | 
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
| typedef struct [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md)  [OH_Drawing_PlaceholderSpan](#oh_drawing_placeholderspan) | 用于描述占位符跨度的结构体。 | 
| typedef enum [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle)  [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) | 文本装饰样式枚举。 | 
| typedef enum [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)  [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal) | 省略号样式枚举。 | 
| typedef enum [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy)  [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy) | 文本的中断策略枚举。 | 
| typedef enum [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype)  [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype) | 单词的断词方式枚举。 | 
| typedef enum [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle)  [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle) | 矩形框高度样式枚举。 | 
| typedef enum [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)  [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle) | 矩形框宽度样式枚举。 | 
| typedef struct [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)  [OH_Drawing_FontDescriptor](#oh_drawing_fontdescriptor) | 描述系统字体详细信息的结构体。 | 
| typedef struct [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)  [OH_Drawing_LineMetrics](#oh_drawing_linemetrics) | 文字行位置信息。 | 
| typedef struct [OH_Drawing_FontFallbackInfo](_o_h___drawing___font_fallback_info.md)  [OH_Drawing_FontFallbackInfo](#oh_drawing_fontfallbackinfo) | 备用字体信息结构体。 | 
| typedef struct [OH_Drawing_FontFallbackGroup](_o_h___drawing___font_fallback_group.md)  [OH_Drawing_FontFallbackGroup](#oh_drawing_fontfallbackgroup) | 备用字体集信息结构体。 | 
| typedef struct [OH_Drawing_FontAdjustInfo](_o_h___drawing___font_adjust_info.md)  [OH_Drawing_FontAdjustInfo](#oh_drawing_fontadjustinfo) | 字重映射信息结构体。 | 
| typedef struct [OH_Drawing_FontAliasInfo](_o_h___drawing___font_alias_info.md)  [OH_Drawing_FontAliasInfo](#oh_drawing_fontaliasinfo) | 别名字体信息结构体。 | 
| typedef struct [OH_Drawing_FontGenericInfo](_o_h___drawing___font_generic_info.md)  [OH_Drawing_FontGenericInfo](#oh_drawing_fontgenericinfo) | 系统所支持的通用字体集信息结构体。 | 
| typedef struct [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md)  [OH_Drawing_FontConfigInfo](#oh_drawing_fontconfiginfo) | 系统字体配置信息结构体。 | 
| typedef struct [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md)  [OH_Drawing_FontStyleStruct](#oh_drawing_fontstylestruct) | 定义字体样式信息的结构体。 | 
| typedef struct [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md)  [OH_Drawing_StrutStyle](#oh_drawing_strutstyle) | 用于描述支柱样式的结构体。支柱样式用于控制绘制文本时行之间的间距、基线对齐方式以及其他与行高相关的属性。 | 
| typedef struct [OH_Drawing_Canvas](#oh_drawing_canvas)  [OH_Drawing_Canvas](#oh_drawing_canvas) | 定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字。 | 
| typedef struct [OH_Drawing_Pen](#oh_drawing_pen)  [OH_Drawing_Pen](#oh_drawing_pen) | 定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色。 | 
| typedef struct [OH_Drawing_Region](#oh_drawing_region)  [OH_Drawing_Region](#oh_drawing_region) | 定义一个区域，用于表示画布上的封闭区域，实现更精确的图形控制。 | 
| typedef struct [OH_Drawing_Brush](#oh_drawing_brush)  [OH_Drawing_Brush](#oh_drawing_brush) | 定义为画刷，画刷用于描述填充图形的样式和颜色。 | 
| typedef struct [OH_Drawing_Path](#oh_drawing_path)  [OH_Drawing_Path](#oh_drawing_path) | 定义为路径，路径用于自定义各种形状。 | 
| typedef struct [OH_Drawing_PixelMap](#oh_drawing_pixelmap)  [OH_Drawing_PixelMap](#oh_drawing_pixelmap) | 定义像素图，用于包装图像框架支持的真实像素图。 | 
| typedef struct [OH_Drawing_Bitmap](#oh_drawing_bitmap)  [OH_Drawing_Bitmap](#oh_drawing_bitmap) | 定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据。 | 
| typedef struct [OH_Drawing_Point](#oh_drawing_point)  [OH_Drawing_Point](#oh_drawing_point) | 定义一个点，用于描述坐标点。 | 
| typedef struct [OH_Drawing_ColorSpace](#oh_drawing_colorspace)  [OH_Drawing_ColorSpace](#oh_drawing_colorspace) | 定义色彩空间，用于解释颜色信息。 | 
| typedef struct [OH_Drawing_Point2D](_o_h___drawing___point2_d.md)  [OH_Drawing_Point2D](#oh_drawing_point2d) | 定义一个二维的坐标点。 | 
| typedef [OH_Drawing_Point2D](_o_h___drawing___point2_d.md)  [OH_Drawing_Corner_Radii](#oh_drawing_corner_radii) | 定义一个圆角半径，该圆角半径由x轴方向和y轴方向上的半径组成。 | 
| typedef struct [OH_Drawing_Point3D](_o_h___drawing___point3_d.md)  [OH_Drawing_Point3D](#oh_drawing_point3d) | 定义一个三维的坐标点。 | 
| typedef struct [OH_Drawing_PathEffect](#oh_drawing_patheffect)  [OH_Drawing_PathEffect](#oh_drawing_patheffect) | 定义一个路径效果，用于影响描边路径。 | 
| typedef struct [OH_Drawing_Rect](#oh_drawing_rect)  [OH_Drawing_Rect](#oh_drawing_rect) | 用于描述矩形。 | 
| typedef struct [OH_Drawing_RoundRect](#oh_drawing_roundrect)  [OH_Drawing_RoundRect](#oh_drawing_roundrect) | 用于描述圆角矩形。 | 
| typedef struct [OH_Drawing_Matrix](#oh_drawing_matrix)  [OH_Drawing_Matrix](#oh_drawing_matrix) | 定义一个矩阵，用于描述坐标变换。 | 
| typedef struct [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)  [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) | 定义一个着色器，用于描述绘制内容的源颜色。 | 
| typedef struct [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer)  [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) | 定义一个阴影层，用于描述绘制内容的阴影层。 | 
| typedef struct [OH_Drawing_Filter](#oh_drawing_filter)  [OH_Drawing_Filter](#oh_drawing_filter) | 定义一个滤波器，用于存储颜色滤波器和蒙版滤波器。 | 
| typedef struct [OH_Drawing_MaskFilter](#oh_drawing_maskfilter)  [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) | 定义蒙版滤波器。 | 
| typedef struct [OH_Drawing_ColorFilter](#oh_drawing_colorfilter)  [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) | 定义颜色滤波器，传入一个颜色并返回一个新的颜色。 | 
| typedef struct [OH_Drawing_Font](#oh_drawing_font)  [OH_Drawing_Font](#oh_drawing_font) | 用于描述字体。 | 
| typedef struct [OH_Drawing_MemoryStream](#oh_drawing_memorystream)  [OH_Drawing_MemoryStream](#oh_drawing_memorystream) | 用于描述内存流。 | 
| typedef struct [OH_Drawing_Typeface](#oh_drawing_typeface)  [OH_Drawing_Typeface](#oh_drawing_typeface) | 用于描述字形。 | 
| typedef struct [OH_Drawing_TextBlob](#oh_drawing_textblob)  [OH_Drawing_TextBlob](#oh_drawing_textblob) | 定义一个文本对象，表示将多个文本组合到一个不可变的容器中。 每个文本行由字形和位置组成。 | 
| typedef struct [OH_Drawing_Image](#oh_drawing_image)  [OH_Drawing_Image](#oh_drawing_image) | 定义一个用于描述绘制二维像素数组的图片。 | 
| typedef struct [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)  [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) | 定义一个采样选项，用于描述图片、位图等图像的采样方法。 | 
| typedef struct [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder)  [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) | 定义文本构建器，用于构建文本。 | 
| typedef struct [OH_Drawing_GpuContext](#oh_drawing_gpucontext)  [OH_Drawing_GpuContext](#oh_drawing_gpucontext) | 定义图形处理器上下文，用于描述图形处理器后端上下文。 | 
| typedef struct [OH_Drawing_Surface](#oh_drawing_surface)  [OH_Drawing_Surface](#oh_drawing_surface) | 定义surface，用于管理画布绘制的内容。 | 
| typedef enum [OH_Drawing_ColorFormat](#oh_drawing_colorformat)  [OH_Drawing_ColorFormat](#oh_drawing_colorformat) | 用于描述位图像素的存储格式。 | 
| typedef enum [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat)  [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) | 用于描述位图像素的透明度分量。 | 
| typedef enum [OH_Drawing_BlendMode](#oh_drawing_blendmode)  [OH_Drawing_BlendMode](#oh_drawing_blendmode) | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在红、绿、蓝3个颜色通道上是相同的（透明度有另外的处理规则）。 | 
| typedef struct [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)  [OH_Drawing_Image_Info](#oh_drawing_image_info) | 定义图片信息结构体。 | 
| typedef struct [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md)  [OH_Drawing_RectStyle_Info](#oh_drawing_rectstyle_info) | 定义矩形框样式结构体。 | 
| typedef enum [OH_Drawing_TextEncoding](#oh_drawing_textencoding)  [OH_Drawing_TextEncoding](#oh_drawing_textencoding) | 文本编码类型枚举。 | 
| typedef struct [OH_Drawing_FontMgr](#oh_drawing_fontmgr)  [OH_Drawing_FontMgr](#oh_drawing_fontmgr) | 定义字体管理类, 用于字体管理。 | 
| typedef struct [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)  [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) | 定义字体样式集, 用于字体样式族匹配。 | 
| typedef enum [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) | 阴影标志枚举。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle-1) { DRAWING_PATH_DASH_STYLE_TRANSLATE, DRAWING_PATH_DASH_STYLE_ROTATE, DRAWING_PATH_DASH_STYLE_MORPH } | 路径效果的绘制样式枚举。  | 
| [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype-1) { ALL = 1 &lt;&lt; 0, GENERIC = 1 &lt;&lt; 1, STYLISH = 1 &lt;&lt; 2, INSTALLED = 1 &lt;&lt; 3, CUSTOMIZED = 1 &lt;&lt; 4 } | 字体类型的枚举。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode-1) { OH_DRAWING_SUCCESS = 0, OH_DRAWING_ERROR_NO_PERMISSION = 201, OH_DRAWING_ERROR_INVALID_PARAMETER = 401, OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE = 26200001,OH_DRAWING_ERROR_ALLOCATION_FAILED = 26200002 } | 枚举本模块可能产生的错误码。 | 
| [OH_Drawing_PathOpMode](#oh_drawing_pathopmode-1) {<br/>PATH_OP_MODE_DIFFERENCE, PATH_OP_MODE_INTERSECT, PATH_OP_MODE_UNION, PATH_OP_MODE_XOR,<br/>PATH_OP_MODE_REVERSE_DIFFERENCE<br/>} | 路径操作类型枚举。 | 
| [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags-1) { GET_POSITION_MATRIX, GET_TANGENT_MATRIX, GET_POSITION_AND_TANGENT_MATRIX } | 路径测量获取相应矩阵信息维度枚举。 | 
| [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode-1) {<br/>REGION_OP_MODE_DIFFERENCE, REGION_OP_MODE_INTERSECT, REGION_OP_MODE_UNION, REGION_OP_MODE_XOR,<br/>REGION_OP_MODE_REVERSE_DIFFERENCE, REGION_OP_MODE_REPLACE<br/>} | 区域操作类型枚举。 | 
| [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint-1) { STRICT_SRC_RECT_CONSTRAINT, FAST_SRC_RECT_CONSTRAINT } | 源矩形区域约束类型枚举。 | 
| [OH_Drawing_PointMode](#oh_drawing_pointmode-1) { POINT_MODE_POINTS, POINT_MODE_LINES, POINT_MODE_POLYGON } | 绘制多个点的方式枚举，方式分为离散点、直线或开放多边形。 | 
| [OH_Drawing_VertexMode](#oh_drawing_vertexmode-1) { VERTEX_MODE_TRIANGLES, VERTEX_MODE_TRIANGLESSTRIP, VERTEX_MODE_TRIANGLEFAN } | 用于指定如何解释给定顶点的几何形状的枚举类型。 | 
| [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop-1) { DIFFERENCE, INTERSECT } | 画布裁剪方式的枚举集合。 | 
| [OH_Drawing_FontEdging](#oh_drawing_fontedging-1) { FONT_EDGING_ALIAS, FONT_EDGING_ANTI_ALIAS, FONT_EDGING_SUBPIXEL_ANTI_ALIAS } | 字型边缘效果类型枚举。 | 
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting-1) { FONT_HINTING_NONE, FONT_HINTING_SLIGHT, FONT_HINTING_NORMAL, FONT_HINTING_FULL } | 字型轮廓效果类型枚举。 | 
| [OH_Drawing_BlurType](#oh_drawing_blurtype-1) { NORMAL, SOLID, OUTER, INNER } | 蒙版滤波器模糊操作类型的枚举。 | 
| [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit-1) { SCALE_TO_FIT_FILL, SCALE_TO_FIT_START, SCALE_TO_FIT_CENTER, SCALE_TO_FIT_END } | 矩阵缩放方式枚举。 | 
| [OH_Drawing_PathDirection](#oh_drawing_pathdirection-1) { PATH_DIRECTION_CW, PATH_DIRECTION_CCW } | 添加闭合轮廓方向枚举。 | 
| [OH_Drawing_PathFillType](#oh_drawing_pathfilltype-1) { PATH_FILL_TYPE_WINDING, PATH_FILL_TYPE_EVEN_ODD, PATH_FILL_TYPE_INVERSE_WINDING, PATH_FILL_TYPE_INVERSE_EVEN_ODD } | 定义路径的填充类型枚举。 | 
| [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode-1) { PATH_ADD_MODE_APPEND, PATH_ADD_MODE_EXTEND } | 用于指定路径添加模式的枚举类型。 | 
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle-1) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | 枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。 | 
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle-1) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | 枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。 | 
| [OH_Drawing_CornerPos](#oh_drawing_cornerpos-1) { CORNER_POS_TOP_LEFT, CORNER_POS_TOP_RIGHT, CORNER_POS_BOTTOM_RIGHT, CORNER_POS_BOTTOM_LEFT } | 用于描述圆角位置的枚举。 | 
| [OH_Drawing_FilterMode](#oh_drawing_filtermode-1) { FILTER_MODE_NEAREST, FILTER_MODE_LINEAR } | 过滤模式枚举。 | 
| [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode-1) { MIPMAP_MODE_NONE, MIPMAP_MODE_NEAREST, MIPMAP_MODE_LINEAR } | 多级渐远纹理模式枚举。 | 
| [OH_Drawing_TileMode](#oh_drawing_tilemode-1) { CLAMP, REPEAT, MIRROR, DECAL } | 着色器效果平铺模式的枚举。 | 
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | 文字方向。 | 
| [OH_Drawing_TextAlign](#oh_drawing_textalign) {<br/>TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,<br/>TEXT_ALIGN_START, TEXT_ALIGN_END<br/>} | 文字对齐方式。 | 
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) {<br/>FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,<br/>FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,<br/>FONT_WEIGHT_900<br/>} | 字重。 | 
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | 基线位置。 | 
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | 文本装饰。 | 
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC, FONT_STYLE_OBLIQUE } | 区分字体是否为斜体。 | 
| [OH_Drawing_PlaceholderVerticalAlignment](#oh_drawing_placeholderverticalalignment-1) {<br/>ALIGNMENT_OFFSET_AT_BASELINE, ALIGNMENT_ABOVE_BASELINE, ALIGNMENT_BELOW_BASELINE, ALIGNMENT_TOP_OF_ROW_BOX,<br/>ALIGNMENT_BOTTOM_OF_ROW_BOX, ALIGNMENT_CENTER_OF_ROW_BOX<br/>} | 占位符垂直对齐枚举。 | 
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle-1) {<br/>TEXT_DECORATION_STYLE_SOLID, TEXT_DECORATION_STYLE_DOUBLE, TEXT_DECORATION_STYLE_DOTTED, TEXT_DECORATION_STYLE_DASHED,<br/>TEXT_DECORATION_STYLE_WAVY<br/>} | 文本装饰样式枚举。 | 
| [OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal-1) { ELLIPSIS_MODAL_HEAD = 0, ELLIPSIS_MODAL_MIDDLE = 1, ELLIPSIS_MODAL_TAIL = 2 } | 省略号样式枚举。 | 
| [OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy-1) { BREAK_STRATEGY_GREEDY = 0, BREAK_STRATEGY_HIGH_QUALITY = 1, BREAK_STRATEGY_BALANCED = 2 } | 文本的中断策略枚举。 | 
| [OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype-1) { WORD_BREAK_TYPE_NORMAL = 0, WORD_BREAK_TYPE_BREAK_ALL = 1, WORD_BREAK_TYPE_BREAK_WORD = 2, WORD_BREAK_TYPE_BREAK_HYPHEN = 3 } | 单词的断词方式枚举。 | 
| [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle-1) {<br/>RECT_HEIGHT_STYLE_TIGHT, RECT_HEIGHT_STYLE_MAX, RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE, RECT_HEIGHT_STYLE_INCLUDELINESPACETOP,<br/>RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM, RECT_HEIGHT_STYLE_STRUCT<br/>} | 矩形框高度样式枚举。 | 
| [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle-1) { RECT_WIDTH_STYLE_TIGHT, RECT_WIDTH_STYLE_MAX } | 矩形框宽度样式枚举。 | 
| [OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode) {<br/>SUCCESS_FONT_CONFIG_INFO = 0, ERROR_FONT_CONFIG_INFO_UNKNOWN = 1, ERROR_FONT_CONFIG_INFO_PARSE_FILE = 2, ERROR_FONT_CONFIG_INFO_ALLOC_MEMORY = 3,<br/>ERROR_FONT_CONFIG_INFO_COPY_STRING_DATA = 4<br/>} | 获取系统字体配置信息列表结果枚举。 | 
| [OH_Drawing_FontWidth](#oh_drawing_fontwidth) {<br/>ULTRA_CONDENSED_WIDTH = 1, EXTRA_CONDENSED_WIDTH = 2, CONDENSED_WIDTH = 3, SEMI_CONDENSED_WIDTH = 4,<br/>NORMAL_WIDTH = 5, SEMI_EXPANDED_WIDTH = 6, EXPANDED_WIDTH = 7, EXTRA_EXPANDED_WIDTH = 8,<br/>ULTRA_EXPANDED_WIDTH = 9<br/>} | 字体宽度的枚举。 | 
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) { TEXT_HEIGHT_ALL = 0x0, TEXT_HEIGHT_DISABLE_FIRST_ASCENT = 0x1, TEXT_HEIGHT_DISABLE_LAST_ASCENT = 0x2, TEXT_HEIGHT_DISABLE_ALL = 0x1 \| 0x2 } | 文本高度修饰符模式枚举。 | 
| [OH_Drawing_TextStyleType](#oh_drawing_textstyletype) {<br/>TEXT_STYLE_NONE, TEXT_STYLE_ALL_ATTRIBUTES, TEXT_STYLE_FONT, TEXT_STYLE_FOREGROUND,<br/>TEXT_STYLE_BACKGROUND, TEXT_STYLE_SHADOW, TEXT_STYLE_DECORATIONS, TEXT_STYLE_LETTER_SPACING,<br/>TEXT_STYLE_WORD_SPACING<br/>} | 文本样式类型枚举。 | 
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat-1) {<br/>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,<br/>COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br/>} | 用于描述位图像素的存储格式。 | 
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat-1) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | 用于描述位图像素的透明度分量。 | 
| [OH_Drawing_BlendMode](#oh_drawing_blendmode-1) {<br/>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br/>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br/>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br/>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br/>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br/>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br/>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br/>BLEND_MODE_LUMINOSITY<br/>} | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在红、绿、蓝3个颜色通道上是相同的（透明度有另外的处理规则）。 | 
| [OH_Drawing_TextEncoding](#oh_drawing_textencoding-1) { TEXT_ENCODING_UTF8, TEXT_ENCODING_UTF16, TEXT_ENCODING_UTF32, TEXT_ENCODING_GLYPH_ID } | 文本编码类型枚举。 | 
| [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags-1) { SHADOW_FLAGS_NONE, SHADOW_FLAGS_TRANSPARENT_OCCLUDER, SHADOW_FLAGS_GEOMETRIC_ONLY, SHADOW_FLAGS_ALL } | 阴影标志枚举。 | 

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_PathEffect](#oh_drawing_patheffect) \* [OH_Drawing_CreateSumPathEffect](#oh_drawing_createsumpatheffect) ([OH_Drawing_PathEffect](#oh_drawing_patheffect) \*firstPathEffect, [OH_Drawing_PathEffect](#oh_drawing_patheffect) \*secondPathEffect) | 创建一个使用两种路径效果分别生效后叠加的路径效果对象。  |
| [OH_Drawing_PathEffect](#oh_drawing_patheffect) \* [OH_Drawing_CreatePathDashEffect](#oh_drawing_createpathdasheffect) (const [OH_Drawing_Path](#oh_drawing_path) \*path, float advance, float phase, [OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle) type) | 创建一个虚线效果的路径效果对象。  |
| [OH_Drawing_PathEffect](#oh_drawing_patheffect) \* [OH_Drawing_CreateDiscretePathEffect](#oh_drawing_creatediscretepatheffect) (float segLength, float deviation) | 创建一种将路径打散并且在路径上产生不规则分布的路径效果对象。  | 
| [OH_Drawing_PathEffect](#oh_drawing_patheffect) \* [OH_Drawing_CreateCornerPathEffect](#oh_drawing_createcornerpatheffect) (float radius) | 创建一个将路径的夹角变成指定半径的圆角的路径效果对象。  | 
| [OH_Drawing_PathEffect](#oh_drawing_patheffect) \* [OH_Drawing_CreateComposePathEffect](#oh_drawing_createcomposepatheffect) ([OH_Drawing_PathEffect](#oh_drawing_patheffect) \*outer, [OH_Drawing_PathEffect](#oh_drawing_patheffect) \*inner) | 创建路径组合的路径效果对象。首先应用内部路径效果，然后应用外部路径效果。  | 
| [OH_Drawing_GpuContext](#oh_drawing_gpucontext) \* [OH_Drawing_GpuContextCreate](#oh_drawing_gpucontextcreate) () | 用于创建一个图形处理器上下文对象, 使用的后端类型取决于运行设备。  | 
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawArcWithCenter](#oh_drawing_canvasdrawarcwithcenter) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const [OH_Drawing_Rect](#oh_drawing_rect) \*rect, float startAngle, float sweepAngle, bool useCenter) | 绘制一段圆弧。该方法允许指定圆弧的起始角度、扫描角度以及圆弧的起点和终点是否连接圆弧的中心点。  | 
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawNestedRoundRect](#oh_drawing_canvasdrawnestedroundrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*outer, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*inner) | 绘制两个嵌套的圆角矩形，外部矩形边界必须包含内部矩形边界，否则无绘制效果。| 
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasQuickRejectPath](#oh_drawing_canvasquickrejectpath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const [OH_Drawing_Path](#oh_drawing_path) \*path, bool \*quickReject) | 判断路径与画布区域是否不相交。画布区域包含边界。  | 
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasQuickRejectRect](#oh_drawing_canvasquickrejectrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const [OH_Drawing_Rect](#oh_drawing_rect) \*rect, bool \*quickReject) | 判断矩形和画布区域是否不相交。画布区域包含边界。  | 
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawPixelMapNine](#oh_drawing_canvasdrawpixelmapnine) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, [OH_Drawing_PixelMap](#oh_drawing_pixelmap) \*pixelMap, const [OH_Drawing_Rect](#oh_drawing_rect) \*center, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, [OH_Drawing_FilterMode](#oh_drawing_filtermode) mode) | 通过绘制两条水平线和两条垂直线将像素图分割成9个部分：四个边，四个角和中心。 若角落的4个区域尺寸不超过目标矩形，则会在不缩放的情况下被绘制在目标矩形，反之则会按比例缩放绘制在目标矩形。 如果还有剩余空间，剩下的5个区域会通过拉伸或压缩来绘制，以便能够完全覆盖目标矩形。  | 
| [OH_Drawing_Surface](#oh_drawing_surface) \* [OH_Drawing_SurfaceCreateOnScreen](#oh_drawing_surfacecreateonscreen) ([OH_Drawing_GpuContext](#oh_drawing_gpucontext) \*gpuContext, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) imageInfo, void \*window) | 使用图形处理器上下文创建一个与屏幕窗口绑定的surface对象，用于管理画布绘制的内容。  | 
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_SurfaceFlush](#oh_drawing_surfaceflush) ([OH_Drawing_Surface](#oh_drawing_surface) \*surface) | 将surface对象上的画布绘制内容提交给GPU处理，完成绘制内容上屏显示。  | 
| void [OH_Drawing_ErrorCodeReset](#oh_drawing_errorcodereset) (void) | 将本模块的错误码重置为OH_DRAWING_SUCCESS。<br/>通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)获取的本模块错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，但是不会在执行成功后被重置为OH_DRAWING_SUCCESS。<br/>调用本接口可将错误码重置为OH_DRAWING_SUCCESS，避免多个接口间互相干扰，方便开发者调试。 | 
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontSetThemeFontFollowed](#oh_drawing_fontsetthemefontfollowed) ([OH_Drawing_Font](#oh_drawing_font) \*font, bool followed) | 设置字型中的字体是否跟随主题字体。设置跟随主题字体后，若系统启用主题字体并且字型未被设置字体，字型会使用该主题字体。 | 
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontIsThemeFontFollowed](#oh_drawing_fontisthemefontfollowed) (const [OH_Drawing_Font](#oh_drawing_font) \*font, bool \*followed) | 获取字型中的字体是否跟随主题字体。默认不跟随主题字体。 | 
| OH_Drawing_FontCollection \* [OH_Drawing_GetFontCollectionGlobalInstance](#oh_drawing_getfontcollectionglobalinstance) (void) | 获取全局字体集对象OH_Drawing_FontCollection，可感知主题字信息，禁止释放该对象。  | 
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreate](#oh_drawing_bitmapcreate) (void) | 用于创建一个位图对象。 |
| void [OH_Drawing_BitmapDestroy](#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于销毁位图对象并回收该对象占有内存。 |
| [OH_Drawing_Bitmap](#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreateFromPixels](#oh_drawing_bitmapcreatefrompixels) ([OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*pixels, uint32_t rowBytes) | 用于创建一个位图对象，并将位图像素存储内存地址设置为开发者申请内存的地址。 |
| void [OH_Drawing_BitmapBuild](#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | 用于初始化位图对象的宽度和高度，并且为该位图设置像素格式。 |
| uint32_t [OH_Drawing_BitmapGetWidth](#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于获取指定位图的宽度。 |
| uint32_t [OH_Drawing_BitmapGetHeight](#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于获取指定位图的高度。 |
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat) [OH_Drawing_BitmapGetColorFormat](#oh_drawing_bitmapgetcolorformat) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于获取指定位图的像素存储格式。 |
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) [OH_Drawing_BitmapGetAlphaFormat](#oh_drawing_bitmapgetalphaformat) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于获取指定位图的像素透明度分量。 |
| void \* [OH_Drawing_BitmapGetPixels](#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据。 |
| void [OH_Drawing_BitmapGetImageInfo](#oh_drawing_bitmapgetimageinfo) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | 用于获取指定位图的信息。 |
| bool [OH_Drawing_BitmapReadPixels](#oh_drawing_bitmapreadpixels) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*dstInfo, void \*dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY) | 将位图中的矩形区域像素数据读取到指定的内存缓冲区中。 |
| [OH_Drawing_Brush](#oh_drawing_brush) \* [OH_Drawing_BrushCreate](#oh_drawing_brushcreate) (void) | 用于创建一个画刷对象。 |
| [OH_Drawing_Brush](#oh_drawing_brush) \* [OH_Drawing_BrushCopy](#oh_drawing_brushcopy) ([OH_Drawing_Brush](#oh_drawing_brush) \*brush) | 创建一个画刷对象副本[OH_Drawing_Brush](#oh_drawing_brush)，用于拷贝一个已有画刷对象。 |
| void [OH_Drawing_BrushDestroy](#oh_drawing_brushdestroy) ([OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于销毁画刷对象并回收该对象占有的内存。 |
| bool [OH_Drawing_BrushIsAntiAlias](#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 |
| void [OH_Drawing_BrushSetAntiAlias](#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](#oh_drawing_brush) \*, bool) | 用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理。 |
| uint32_t [OH_Drawing_BrushGetColor](#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。 |
| void [OH_Drawing_BrushSetColor](#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint32_t color) | 用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。 |
| uint8_t [OH_Drawing_BrushGetAlpha](#oh_drawing_brushgetalpha) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 获取画刷的透明度值。画刷在填充形状时透明通道会使用该值。 |
| void [OH_Drawing_BrushSetAlpha](#oh_drawing_brushsetalpha) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint8_t alpha) | 为画刷设置透明度值。画刷在填充形状时透明通道会使用该值。 |
| void [OH_Drawing_BrushSetShaderEffect](#oh_drawing_brushsetshadereffect) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | 为画刷设置着色器效果。 |
| void [OH_Drawing_BrushSetShadowLayer](#oh_drawing_brushsetshadowlayer) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) \*) | 为画刷设置阴影层，设置的阴影层效果当前仅在绘制文字时生效。 |
| void [OH_Drawing_BrushSetFilter](#oh_drawing_brushsetfilter) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | 为画刷设置滤波器[OH_Drawing_Filter](#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。 |
| void [OH_Drawing_BrushGetFilter](#oh_drawing_brushgetfilter) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | 从画刷获取滤波器[OH_Drawing_Filter](#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。 |
| void [OH_Drawing_BrushSetBlendMode](#oh_drawing_brushsetblendmode) ([OH_Drawing_Brush](#oh_drawing_brush) \*, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | 为画刷设置一个混合器，该混合器实现了指定的混合模式枚举。 |
| void [OH_Drawing_BrushReset](#oh_drawing_brushreset) ([OH_Drawing_Brush](#oh_drawing_brush) \*) | 将画刷重置至初始状态，清空所有已设置的属性。 |
| [OH_Drawing_Canvas](#oh_drawing_canvas) \* [OH_Drawing_CanvasCreate](#oh_drawing_canvascreate) (void) | 用于创建一个画布对象。 |
| void [OH_Drawing_CanvasDestroy](#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于销毁画布对象并回收该对象占有的内存。 |
| void [OH_Drawing_CanvasBind](#oh_drawing_canvasbind) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。 |
| void [OH_Drawing_CanvasAttachPen](#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。执行该方法后，若画笔的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。 |
| void [OH_Drawing_CanvasDetachPen](#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。 |
| void [OH_Drawing_CanvasAttachBrush](#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。执行该方法后，若画刷的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。 |
| void [OH_Drawing_CanvasDetachBrush](#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于去除掉画布中的画刷，使用后画布将不使用此前设置的画刷去填充图形形状。 |
| void [OH_Drawing_CanvasSave](#oh_drawing_canvassave) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于保存当前画布的状态（画布矩阵）到一个栈顶。需要与恢复接口[OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore)配合使用。 |
| void [OH_Drawing_CanvasSaveLayer](#oh_drawing_canvassavelayer) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 保存矩阵和裁剪区域，为后续绘制分配位图。调用恢复接口 [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore)将放弃对矩阵和剪切区域所做的更改，并绘制位图。 |
| void [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于恢复保存在栈顶的画布状态（画布矩阵）。 |
| uint32_t [OH_Drawing_CanvasGetSaveCount](#oh_drawing_canvasgetsavecount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 用于获取栈中保存的画布状态（画布矩阵）的数量。 |
| void [OH_Drawing_CanvasRestoreToCount](#oh_drawing_canvasrestoretocount) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t saveCount) | 用于恢复到指定数量的画布状态（画布矩阵）。 |
| void [OH_Drawing_CanvasDrawLine](#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | 用于画一条直线段。 |
| void [OH_Drawing_CanvasDrawPath](#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*) | 用于画一个自定义路径。 |
| void [OH_Drawing_CanvasDrawPixelMapRect](#oh_drawing_canvasdrawpixelmaprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_PixelMap](#oh_drawing_pixelmap) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | 用于将像素图的指定区域绘制到画布的指定区域。 |
| void [OH_Drawing_CanvasDrawBackground](#oh_drawing_canvasdrawbackground) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | 用于画一个背景，此背景以画刷填充。 |
| void [OH_Drawing_CanvasDrawRegion](#oh_drawing_canvasdrawregion) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Region](#oh_drawing_region) \*) | 用于画一块区域。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawPoint](#oh_drawing_canvasdrawpoint) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*point) | 用于画一个点。 |
| void [OH_Drawing_CanvasDrawPoints](#oh_drawing_canvasdrawpoints) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_PointMode](#oh_drawing_pointmode) mode, uint32_t count, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*) | 用于画多个点，绘制方式分为绘制单独的点、绘制成线段或绘制成开放多边形。 |
| void [OH_Drawing_CanvasDrawBitmap](#oh_drawing_canvasdrawbitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, float left, float top) | 用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。 |
| void [OH_Drawing_CanvasDrawBitmapRect](#oh_drawing_canvasdrawbitmaprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | 将位图的指定区域绘制到画布的指定区域。 |
| void [OH_Drawing_CanvasSetMatrix](#oh_drawing_canvassetmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 设置画布的矩阵状态。 |
| void [OH_Drawing_CanvasResetMatrix](#oh_drawing_canvasresetmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 重置当前画布的矩阵为单位矩阵。 |
| void [OH_Drawing_CanvasDrawImageRectWithSrc](#oh_drawing_canvasdrawimagerectwithsrc) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Image](#oh_drawing_image) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*, [OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint)) | 将图片绘制到画布的指定区域上，源矩形选定的区域会缩放平移到目标矩形。 |
| void [OH_Drawing_CanvasDrawImageRect](#oh_drawing_canvasdrawimagerect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*dst, [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | 将图片绘制到画布的指定区域上。 |
| void [OH_Drawing_CanvasDrawVertices](#oh_drawing_canvasdrawvertices) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_VertexMode](#oh_drawing_vertexmode) vertexMmode, int32_t vertexCount, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*positions, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*texs, const uint32_t \*colors, int32_t indexCount, const uint16_t \*indices, [OH_Drawing_BlendMode](#oh_drawing_blendmode) mode) | 用于画顶点数组描述的三角网格。 |
| bool [OH_Drawing_CanvasReadPixels](#oh_drawing_canvasreadpixels) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*, void \*dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY) | 从画布中拷贝像素数据到指定地址。该接口不可用于录制类型画布。 |
| bool [OH_Drawing_CanvasReadPixelsToBitmap](#oh_drawing_canvasreadpixelstobitmap) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, int32_t srcX, int32_t srcY) | 从画布拷贝像素数据到位图中。该接口不可用于录制类型画布。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasIsClipEmpty](#oh_drawing_canvasisclipempty) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, bool \*isClipEmpty) | 用于判断裁剪后可绘制区域是否为空。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasGetImageInfo](#oh_drawing_canvasgetimageinfo) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*imageInfo) | 用于获取画布的图像信息。 |
| void [OH_Drawing_CanvasDrawRect](#oh_drawing_canvasdrawrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于画一个矩形。 |
| void [OH_Drawing_CanvasDrawCircle](#oh_drawing_canvasdrawcircle) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Point](#oh_drawing_point) \*, float radius) | 用于画一个圆形。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawColor](#oh_drawing_canvasdrawcolor) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, uint32_t color, [OH_Drawing_BlendMode](#oh_drawing_blendmode) blendMode) | 用于使用指定的颜色及混合模式来填充整个画布。 |
| void [OH_Drawing_CanvasDrawOval](#oh_drawing_canvasdrawoval) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于画一个椭圆。 |
| void [OH_Drawing_CanvasDrawArc](#oh_drawing_canvasdrawarc) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, float startAngle, float sweepAngle) | 用于画一个弧。当扫描角度的绝对值大于360度时，本接口绘制的是一个椭圆。 |
| void [OH_Drawing_CanvasDrawRoundRect](#oh_drawing_canvasdrawroundrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*) | 用于画一个圆角矩形。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawSingleCharacter](#oh_drawing_canvasdrawsinglecharacter) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const char \*str, const [OH_Drawing_Font](#oh_drawing_font) \*font, float x, float y) | 用于绘制单个字符。当前字型中的字体不支持待绘制字符时，退化到使用系统字体绘制字符。 |
| void [OH_Drawing_CanvasDrawTextBlob](#oh_drawing_canvasdrawtextblob) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_TextBlob](#oh_drawing_textblob) \*, float x, float y) | 用于画一段文字。若构造OH_Drawing_TextBlob的字体不支持待绘制字符，则该部分字符无法绘制。 |
| uint32_t [OH_Drawing_ColorSetArgb](#oh_drawing_colorsetargb) (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue) | 用于将4个变量（分别描述透明度、红色、绿色和蓝色）转化为一个描述颜色的32位（ARGB）变量。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateBlendMode](#oh_drawing_colorfiltercreateblendmode) (uint32_t color, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | 创建具有混合模式的颜色滤波器。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateCompose](#oh_drawing_colorfiltercreatecompose) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter1, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter2) | 将两个颜色滤波器合成一个新的颜色滤波器。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateMatrix](#oh_drawing_colorfiltercreatematrix) (const float matrix[20]) | 创建具有5x4颜色矩阵的颜色滤波器。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLinearToSrgbGamma](#oh_drawing_colorfiltercreatelineartosrgbgamma) (void) | 创建一个从线性颜色空间转换到SRGB颜色空间的颜色滤波器。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateSrgbGammaToLinear](#oh_drawing_colorfiltercreatesrgbgammatolinear) (void) | 创建颜色滤波器将RGB颜色通道应用于SRGB的伽玛曲线。 |
| [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLuma](#oh_drawing_colorfiltercreateluma) (void) | 创建一个颜色滤波器将其输入的亮度值乘以透明度通道， 并将红色、绿色和蓝色通道设置为零。 |
| void [OH_Drawing_ColorFilterDestroy](#oh_drawing_colorfilterdestroy) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | 销毁颜色滤波器对象，并收回该对象占用的内存。 |
| [OH_Drawing_ColorSpace](#oh_drawing_colorspace) \* [OH_Drawing_ColorSpaceCreateSrgb](#oh_drawing_colorspacecreatesrgb) (void) | 创建一个标准颜色空间。 |
| [OH_Drawing_ColorSpace](#oh_drawing_colorspace) \* [OH_Drawing_ColorSpaceCreateSrgbLinear](#oh_drawing_colorspacecreatesrgblinear) (void) | 创建一个Gamma 1.0空间上的颜色空间。 |
| void [OH_Drawing_ColorSpaceDestroy](#oh_drawing_colorspacedestroy) ([OH_Drawing_ColorSpace](#oh_drawing_colorspace) \*) | 销毁颜色空间对象，并回收该对象占有内存。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget) () | 获取本模块的错误码。 |
| [OH_Drawing_Filter](#oh_drawing_filter) \* [OH_Drawing_FilterCreate](#oh_drawing_filtercreate) (void) | 创建一个滤波器对象。 |
| void [OH_Drawing_FilterSetImageFilter](#oh_drawing_filtersetimagefilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \*) | 为滤波器对象设置图像滤波器对象。 |
| void [OH_Drawing_FilterSetMaskFilter](#oh_drawing_filtersetmaskfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | 为滤波器对象设置蒙版滤波器对象。 |
| void [OH_Drawing_FilterSetColorFilter](#oh_drawing_filtersetcolorfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | 为滤波器对象设置颜色滤波器对象。 |
| void [OH_Drawing_FilterGetColorFilter](#oh_drawing_filtergetcolorfilter) ([OH_Drawing_Filter](#oh_drawing_filter) \*, [OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*) | 从滤波器对象获取颜色滤波器对象。 |
| void [OH_Drawing_FilterDestroy](#oh_drawing_filterdestroy) ([OH_Drawing_Filter](#oh_drawing_filter) \*) | 销毁滤波器对象，并收回该对象占用的内存。 |
| void [OH_Drawing_FontSetBaselineSnap](#oh_drawing_fontsetbaselinesnap) ([OH_Drawing_Font](#oh_drawing_font) \*, bool baselineSnap) | 当前画布矩阵轴对齐时，将字型基线设置为是否与像素对齐。 |
| bool [OH_Drawing_FontIsBaselineSnap](#oh_drawing_fontisbaselinesnap) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 当前画布矩阵轴对齐时，获取字型基线是否与像素对齐。 |
| void [OH_Drawing_FontSetEdging](#oh_drawing_fontsetedging) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_FontEdging](#oh_drawing_fontedging)) | 用于设置字型边缘效果。 |
| [OH_Drawing_FontEdging](#oh_drawing_fontedging) [OH_Drawing_FontGetEdging](#oh_drawing_fontgetedging) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型边缘效果。 |
| void [OH_Drawing_FontSetForceAutoHinting](#oh_drawing_fontsetforceautohinting) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isForceAutoHinting) | 用于设置是否自动调整字型轮廓。 |
| bool [OH_Drawing_FontIsForceAutoHinting](#oh_drawing_fontisforceautohinting) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型轮廓是否自动调整。 |
| void [OH_Drawing_FontSetSubpixel](#oh_drawing_fontsetsubpixel) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isSubpixel) | 设置字型是否使用次像素渲染。 |
| bool [OH_Drawing_FontIsSubpixel](#oh_drawing_fontissubpixel) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型是否使用次像素渲染。 |
| [OH_Drawing_Font](#oh_drawing_font) \* [OH_Drawing_FontCreate](#oh_drawing_fontcreate) (void) | 用于创建一个字型对象。 |
| void [OH_Drawing_FontSetTypeface](#oh_drawing_fontsettypeface) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_Typeface](#oh_drawing_typeface) \*) | 用于给字型设置字体。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontGetTypeface](#oh_drawing_fontgettypeface) ([OH_Drawing_Font](#oh_drawing_font) \*) | 获取字体对象。 |
| void [OH_Drawing_FontSetTextSize](#oh_drawing_fontsettextsize) ([OH_Drawing_Font](#oh_drawing_font) \*, float textSize) | 用于给字型设置文字大小。 |
| float [OH_Drawing_FontGetTextSize](#oh_drawing_fontgettextsize) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型文字大小。 |
| int [OH_Drawing_FontCountText](#oh_drawing_fontcounttext) ([OH_Drawing_Font](#oh_drawing_font) \*, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding) | 获取文本所表示的字符数量。 |
| uint32_t [OH_Drawing_FontTextToGlyphs](#oh_drawing_fonttexttoglyphs) (const [OH_Drawing_Font](#oh_drawing_font) \*, const void \*text, uint32_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding, uint16_t \*glyphs, int maxGlyphCount) | 用于将文本转换为字形索引。 |
| void [OH_Drawing_FontGetWidths](#oh_drawing_fontgetwidths) (const [OH_Drawing_Font](#oh_drawing_font) \*, const uint16_t \*glyphs, int count, float \*widths) | 用于获取字符串中每个字符的宽度。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontMeasureSingleCharacter](#oh_drawing_fontmeasuresinglecharacter) (const [OH_Drawing_Font](#oh_drawing_font) \*font, const char \*str, float \*textWidth) | 用于测量单个字符的宽度。当前字型中的字体不支持待测量字符时，退化到使用系统字体测量字符宽度。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontMeasureText](#oh_drawing_fontmeasuretext) (const [OH_Drawing_Font](#oh_drawing_font) \*font, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding, [OH_Drawing_Rect](#oh_drawing_rect) \*bounds, float \*textWidth) | 用于获取文本的宽度和边界框。 |
| void [OH_Drawing_FontSetLinearText](#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isLinearText) | 用于设置线性可缩放字型。 |
| bool [OH_Drawing_FontIsLinearText](#oh_drawing_fontislineartext) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型是否使用线性缩放。 |
| void [OH_Drawing_FontSetTextSkewX](#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](#oh_drawing_font) \*, float skewX) | 用于给字型设置文本倾斜。 |
| float [OH_Drawing_FontGetTextSkewX](#oh_drawing_fontgettextskewx) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型文本在x轴上的倾斜度。 |
| void [OH_Drawing_FontSetFakeBoldText](#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isFakeBoldText) | 用于设置增加描边宽度以近似粗体字体效果。 |
| bool [OH_Drawing_FontIsFakeBoldText](#oh_drawing_fontisfakeboldtext) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取是否增加笔画宽度以接近粗体字体。 |
| void [OH_Drawing_FontSetScaleX](#oh_drawing_fontsetscalex) ([OH_Drawing_Font](#oh_drawing_font) \*, float scaleX) | 用于设置字型对象在x轴上的缩放比例。 |
| float [OH_Drawing_FontGetScaleX](#oh_drawing_fontgetscalex) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型对象在x轴上的缩放比例。 |
| void [OH_Drawing_FontSetHinting](#oh_drawing_fontsethinting) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_FontHinting](#oh_drawing_fonthinting)) | 用于设置字型轮廓效果。 |
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting) [OH_Drawing_FontGetHinting](#oh_drawing_fontgethinting) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型轮廓效果枚举类型。 |
| void [OH_Drawing_FontSetEmbeddedBitmaps](#oh_drawing_fontsetembeddedbitmaps) ([OH_Drawing_Font](#oh_drawing_font) \*, bool isEmbeddedBitmaps) | 用于设置字型是否转换成位图处理。 |
| bool [OH_Drawing_FontIsEmbeddedBitmaps](#oh_drawing_fontisembeddedbitmaps) (const [OH_Drawing_Font](#oh_drawing_font) \*) | 获取字型是否转换成位图处理。 |
| void [OH_Drawing_FontDestroy](#oh_drawing_fontdestroy) ([OH_Drawing_Font](#oh_drawing_font) \*) | 用于销毁字型对象并回收该对象占有的内存。 |
| float [OH_Drawing_FontGetMetrics](#oh_drawing_fontgetmetrics) ([OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | 获取字体度量信息。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontGetBounds](#oh_drawing_fontgetbounds) (const [OH_Drawing_Font](#oh_drawing_font) \*font, const uint16_t \*glyphs, uint32_t count, [OH_Drawing_Array](#oh_drawing_array) \*bounds) | 获取字体指定字形索引的矩形边界。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontGetPathForGlyph](#oh_drawing_fontgetpathforglyph) (const [OH_Drawing_Font](#oh_drawing_font) \*font, uint16_t glyph, [OH_Drawing_Path](#oh_drawing_path) \*path) | 获取字体指定字形索引的轮廓。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontGetTextPath](#oh_drawing_fontgettextpath) (const [OH_Drawing_Font](#oh_drawing_font) \*font, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](#oh_drawing_textencoding) encoding, float x, float y, [OH_Drawing_Path](#oh_drawing_path) \*path) | 获取文字轮廓路径。 |
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \* [OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection) (void) | 创建字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)。 |
| void [OH_Drawing_DestroyFontCollection](#oh_drawing_destroyfontcollection) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | 释放被字体集对象占据的内存。 |
| void [OH_Drawing_DisableFontCollectionFallback](#oh_drawing_disablefontcollectionfallback) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*fontCollection) | 禁用系统字体。 |
| void [OH_Drawing_DisableFontCollectionSystemFont](#oh_drawing_disablefontcollectionsystemfont) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*fontCollection) | 禁用系统字体。 |
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \* [OH_Drawing_CreateSharedFontCollection](#oh_drawing_createsharedfontcollection) (void) | 创建可共享的字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)。 |
| void [OH_Drawing_ClearFontCaches](#oh_drawing_clearfontcaches) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | 清理字体排版缓存（字体排版缓存本身设有内存上限和清理机制，所占内存有限，如无内存要求，不建议清理）。 |
| [OH_Drawing_FontMgr](#oh_drawing_fontmgr) \* [OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate) (void) | 创建字体管理对象，只支持管理系统字体。 |
| void [OH_Drawing_FontMgrDestroy](#oh_drawing_fontmgrdestroy) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*) | 释放字体管理对象占用的内存。 |
| int [OH_Drawing_FontMgrGetFamilyCount](#oh_drawing_fontmgrgetfamilycount) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*) | 获取字体家族的数量。 |
| char \* [OH_Drawing_FontMgrGetFamilyName](#oh_drawing_fontmgrgetfamilyname) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, int index) | 由索引值获取字体家族名称。 |
| void [OH_Drawing_FontMgrDestroyFamilyName](#oh_drawing_fontmgrdestroyfamilyname) (char \*familyName) | 释放指定字体家族名称占用的内存。 |
| [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \* [OH_Drawing_FontMgrCreateFontStyleSet](#oh_drawing_fontmgrcreatefontstyleset) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, int index) | 由字体管理对象构造字体样式集对象。 |
| void [OH_Drawing_FontMgrDestroyFontStyleSet](#oh_drawing_fontmgrdestroyfontstyleset) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*) | 释放字体样式集对象占用的内存。 |
| [OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \* [OH_Drawing_FontMgrMatchFamily](#oh_drawing_fontmgrmatchfamily) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, const char \*familyName) | 由指定的字体家族名称，获取字体样式集对象。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontMgrMatchFamilyStyle](#oh_drawing_fontmgrmatchfamilystyle) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, const char \*familyName, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md)) | 根据指定的字体样式信息和字体家族名称，获取字型对象。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontMgrMatchFamilyStyleCharacter](#oh_drawing_fontmgrmatchfamilystylecharacter) ([OH_Drawing_FontMgr](#oh_drawing_fontmgr) \*, const char \*familyName, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md), const char \*bcp47[], int bcp47Count, int32_t character) | 为指定字符获取字型对象，仅在传入字体管理对象中无法找到传入UTF8字符值对应的字型对象时返回空指针。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontStyleSetCreateTypeface](#oh_drawing_fontstylesetcreatetypeface) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*, int index) | 为指定索引获取字型对象。 |
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_FontStyleSetGetStyle](#oh_drawing_fontstylesetgetstyle) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*, int32_t index, char \*\*styleName) | 获取字体样式。 |
| void [OH_Drawing_FontStyleSetFreeStyleName](#oh_drawing_fontstylesetfreestylename) (char \*\*styleName) | 释放指定字体样式的内存。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_FontStyleSetMatchStyle](#oh_drawing_fontstylesetmatchstyle) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyleStruct) | 获取最接近字体样式的字型对象。 |
| int [OH_Drawing_FontStyleSetCount](#oh_drawing_fontstylesetcount) ([OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset) \*) | 获取字体样式集中字体的个数。 |
| [OH_Drawing_GpuContext](#oh_drawing_gpucontext) \* [OH_Drawing_GpuContextCreateFromGL](#oh_drawing_gpucontextcreatefromgl) ([OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)) | 用于创建一个使用OpenGL作为后端接口的图形处理器上下文对象。 |
| void [OH_Drawing_GpuContextDestroy](#oh_drawing_gpucontextdestroy) ([OH_Drawing_GpuContext](#oh_drawing_gpucontext) \*) | 用于销毁图形处理器上下文对象并回收该对象占用的内存。 |
| [OH_Drawing_Image](#oh_drawing_image) \* [OH_Drawing_ImageCreate](#oh_drawing_imagecreate) (void) | 创建一个图片对象，描述了要绘制的二维像素数组。 |
| void [OH_Drawing_ImageDestroy](#oh_drawing_imagedestroy) ([OH_Drawing_Image](#oh_drawing_image) \*) | 销毁图片对象并回收该对象占有内存。 |
| bool [OH_Drawing_ImageBuildFromBitmap](#oh_drawing_imagebuildfrombitmap) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | 从位图构造图片对象内容，共享或复制位图像素。如果位图被标记为不可变状态， 像素内存是共享的，不是复制。 |
| int32_t [OH_Drawing_ImageGetWidth](#oh_drawing_imagegetwidth) ([OH_Drawing_Image](#oh_drawing_image) \*) | 获取图片宽度，即每行的像素个数。 |
| int32_t [OH_Drawing_ImageGetHeight](#oh_drawing_imagegetheight) ([OH_Drawing_Image](#oh_drawing_image) \*) | 获取图片高度，即像素行数。 |
| void [OH_Drawing_ImageGetImageInfo](#oh_drawing_imagegetimageinfo) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) \*) | 获取图片信息。调用该接口后，传入的图片信息对象被填充。 |
| [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \* [OH_Drawing_ImageFilterCreateBlur](#oh_drawing_imagefiltercreateblur) (float sigmaX, float sigmaY, [OH_Drawing_TileMode](#oh_drawing_tilemode), [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \*input) | 创建具有模糊效果的图像滤波器。 |
| [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \* [OH_Drawing_ImageFilterCreateFromColorFilter](#oh_drawing_imagefiltercreatefromcolorfilter) ([OH_Drawing_ColorFilter](#oh_drawing_colorfilter) \*colorFilter, [OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \*input) | 创建具有颜色变换效果的图像滤波器。 |
| void [OH_Drawing_ImageFilterDestroy](#oh_drawing_imagefilterdestroy) ([OH_Drawing_ImageFilter](#oh_drawing_imagefilter) \*) | 销毁图像滤波器对象并回收该对象占有内存。 |
| [OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \* [OH_Drawing_MaskFilterCreateBlur](#oh_drawing_maskfiltercreateblur) ([OH_Drawing_BlurType](#oh_drawing_blurtype) blurType, float sigma, bool respectCTM) | 创建具有模糊效果的蒙版滤波器。 |
| void [OH_Drawing_MaskFilterDestroy](#oh_drawing_maskfilterdestroy) ([OH_Drawing_MaskFilter](#oh_drawing_maskfilter) \*) | 销毁蒙版滤波器对象，并收回该对象占用的内存。 |
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate) (void) | 用于创建一个矩阵对象。 |
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateRotation](#oh_drawing_matrixcreaterotation) (float deg, float x, float y) | 创建一个带旋转属性的矩阵对象。 该矩阵对象为：单位矩阵在(x, y)旋转点以度为单位进行旋转后得到的矩阵。 |
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateScale](#oh_drawing_matrixcreatescale) (float sx, float sy, float px, float py) | 创建一个带缩放属性的矩阵对象。 该矩阵对象为：单位矩阵在(px, py)旋转点以sx和sy为缩放因子进行缩放后得到的矩阵。 |
| [OH_Drawing_Matrix](#oh_drawing_matrix) \* [OH_Drawing_MatrixCreateTranslation](#oh_drawing_matrixcreatetranslation) (float dx, float dy) | 创建一个带平移属性的矩阵对象。 该矩阵对象为：单位矩阵平移(dx, dy)后得到的矩阵。 |
| void [OH_Drawing_MatrixSetMatrix](#oh_drawing_matrixsetmatrix) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2) | 用于给矩阵对象设置参数。 |
| bool [OH_Drawing_MatrixSetRectToRect](#oh_drawing_matrixsetrecttorect) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, const [OH_Drawing_Rect](#oh_drawing_rect) \*dst, [OH_Drawing_ScaleToFit](#oh_drawing_scaletofit) stf) | 将矩阵以缩放方式适配目标矩阵。 |
| void [OH_Drawing_MatrixPreRotate](#oh_drawing_matrixprerotate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float degree, float px, float py) | 将矩阵设置为矩阵左乘围绕轴心点旋转一定角度的单位矩阵后得到的矩阵。 |
| void [OH_Drawing_MatrixPreScale](#oh_drawing_matrixprescale) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | 将矩阵设置为矩阵左乘围绕轴心点按一定缩放因子缩放后的单位矩阵后得到的矩阵。 |
| void [OH_Drawing_MatrixPreTranslate](#oh_drawing_matrixpretranslate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float dx, float dy) | 将矩阵设置为矩阵左乘平移一定距离后的单位矩阵后得到的矩阵。 |
| void [OH_Drawing_MatrixPostRotate](#oh_drawing_matrixpostrotate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float degree, float px, float py) | 将矩阵设置为矩阵右乘围绕轴心点旋转一定角度的单位矩阵后得到的矩阵。 |
| void [OH_Drawing_MatrixPostScale](#oh_drawing_matrixpostscale) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | 将矩阵设置为矩阵右乘围绕轴心点按一定缩放因子缩放后的单位矩阵后得到的矩阵。 |
| void [OH_Drawing_MatrixPostTranslate](#oh_drawing_matrixposttranslate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float dx, float dy) | 将矩阵设置为矩阵右乘平移一定距离后的单位矩阵后得到的矩阵。 |
| void [OH_Drawing_MatrixReset](#oh_drawing_matrixreset) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 重置当前矩阵为单位矩阵。 |
| void [OH_Drawing_MatrixConcat](#oh_drawing_matrixconcat) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*total, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*a, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*b) | 将矩阵total设置为矩阵a乘以矩阵b。 例如给定矩阵a和矩阵b如下所示: \| A B C \| \| J K L \| a = \| D E F \|, b = \| M N O \| \| G H I \| \| P Q R \| 设置的最终矩阵total为: \| A B C \| \| J K L \| \| AJ+BM+CP AK+BN+CQ AL+BO+CR \| total = a \* b = \| D E F \| \* \| M N O \| = \| DJ+EM+FP DK+EN+FQ DL+EO+FR \| \| G H I \| \| P Q R \| \| GJ+HM+IP GK+HN+IQ GL+HO+IR \| |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_MatrixGetAll](#oh_drawing_matrixgetall) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*matrix, float value[9]) | 获取矩阵所有元素值。 |
| float [OH_Drawing_MatrixGetValue](#oh_drawing_matrixgetvalue) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, int index) | 获取矩阵给定索引位的值。索引范围0-8。 |
| void [OH_Drawing_MatrixRotate](#oh_drawing_matrixrotate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float degree, float px, float py) | 设置矩阵为单位矩阵，并围绕位于(px, py)的旋转轴点进行旋转。 |
| void [OH_Drawing_MatrixTranslate](#oh_drawing_matrixtranslate) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float dx, float dy) | 设置矩阵为单位矩阵，并平移(dx, dy)。 |
| void [OH_Drawing_MatrixScale](#oh_drawing_matrixscale) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, float sx, float sy, float px, float py) | 设置矩阵为单位矩阵，并围绕位于(px, py)的旋转轴点，以sx和sy进行缩放。 |
| bool [OH_Drawing_MatrixInvert](#oh_drawing_matrixinvert) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*inverse) | 将矩阵inverse设置为矩阵的倒数，并返回结果。 |
| bool [OH_Drawing_MatrixSetPolyToPoly](#oh_drawing_matrixsetpolytopoly) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*src, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*dst, uint32_t count) | 通过设置源点以及目标点，生成对应的变换矩阵。 源点以及目标点的个数要大于等于0，小于等于4。 |
| void [OH_Drawing_MatrixMapPoints](#oh_drawing_matrixmappoints) (const [OH_Drawing_Matrix](#oh_drawing_matrix) \*, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*src, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*dst, int count) | 通过矩阵变换将源点数组映射到目标点数组。 |
| bool [OH_Drawing_MatrixMapRect](#oh_drawing_matrixmaprect) (const [OH_Drawing_Matrix](#oh_drawing_matrix) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*src, [OH_Drawing_Rect](#oh_drawing_rect) \*dst) | 将目标矩形设置为一个新的矩形，该矩形是能够包围源矩形的四个顶点通过矩阵变换映射后形成的新顶点的最小矩形。 |
| bool [OH_Drawing_MatrixIsEqual](#oh_drawing_matrixisequal) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*other) | 判断两个矩阵是否相等。 |
| bool [OH_Drawing_MatrixIsIdentity](#oh_drawing_matrixisidentity) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 判断矩阵是否是单位矩阵。 |
| void [OH_Drawing_MatrixDestroy](#oh_drawing_matrixdestroy) ([OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 用于销毁矩阵对象并回收该对象占有的内存。 |
| [OH_Drawing_MemoryStream](#oh_drawing_memorystream) \* [OH_Drawing_MemoryStreamCreate](#oh_drawing_memorystreamcreate) (const void \*data, size_t length, bool copyData) | 创建一个内存流对象。 |
| void [OH_Drawing_MemoryStreamDestroy](#oh_drawing_memorystreamdestroy) ([OH_Drawing_MemoryStream](#oh_drawing_memorystream) \*) | 销毁内存流对象并回收该对象占有内存。 |
| [OH_Drawing_Path](#oh_drawing_path) \* [OH_Drawing_PathCreate](#oh_drawing_pathcreate) (void) | 用于创建一个路径对象。 |
| [OH_Drawing_Path](#oh_drawing_path) \* [OH_Drawing_PathCopy](#oh_drawing_pathcopy) ([OH_Drawing_Path](#oh_drawing_path) \*) | 创建一个路径对象副本[OH_Drawing_Path](#oh_drawing_path)，用于拷贝一个已有路径对象。 |
| void [OH_Drawing_PathDestroy](#oh_drawing_pathdestroy) ([OH_Drawing_Path](#oh_drawing_path) \*) | 用于销毁路径对象并回收该对象占有的内存。 |
| void [OH_Drawing_PathMoveTo](#oh_drawing_pathmoveto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | 用于设置自定义路径的起始点位置。 |
| void [OH_Drawing_PathLineTo](#oh_drawing_pathlineto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | 用于添加一条从路径的最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。 |
| void [OH_Drawing_PathArcTo](#oh_drawing_patharcto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | 用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框， 矩形边框的内切椭圆将会被用来截取弧线，然后会指定一个起始角度和扫描度数， 从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。若路径有内容则会默认添加一条从路径的最后点位置到弧线起始点位置的线段。 |
| void [OH_Drawing_PathQuadTo](#oh_drawing_pathquadto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | 用于添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。 |
| void [OH_Drawing_PathConicTo](#oh_drawing_pathconicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY, float weight) | 在当前路径上添加一条路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的圆锥曲线段，其控制点为 (ctrlX, ctrlY)，结束点为 (endX, endY)。 |
| void [OH_Drawing_PathCubicTo](#oh_drawing_pathcubicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | 用于添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的三阶贝塞尔圆滑曲线。 |
| void [OH_Drawing_PathRMoveTo](#oh_drawing_pathrmoveto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | 用于设置一个相对于当前路径终点（若路径没有内容则默认为 (0, 0)）的路径起始点位置。 |
| void [OH_Drawing_PathRLineTo](#oh_drawing_pathrlineto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。 |
| void [OH_Drawing_PathRQuadTo](#oh_drawing_pathrquadto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。 |
| void [OH_Drawing_PathRConicTo](#oh_drawing_pathrconicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY, float weight) | 使用相对位置在当前路径上添加一条路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的圆锥曲线段。 |
| void [OH_Drawing_PathRCubicTo](#oh_drawing_pathrcubicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | 使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的三阶贝塞尔圆滑曲线。 |
| void [OH_Drawing_PathAddRect](#oh_drawing_pathaddrect) ([OH_Drawing_Path](#oh_drawing_path) \*, float left, float top, float right, float bottom, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | 按指定方向，将矩形添加到路径中，添加的路径的起始点为矩形左上角。 |
| void [OH_Drawing_PathAddRectWithInitialCorner](#oh_drawing_pathaddrectwithinitialcorner) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, [OH_Drawing_PathDirection](#oh_drawing_pathdirection), uint32_t start) | 按指定方向，向路径添加矩形轮廓。 |
| void [OH_Drawing_PathAddRoundRect](#oh_drawing_pathaddroundrect) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*roundRect, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | 按指定方向，向路径添加圆角矩形轮廓。路径添加方向为顺时针时，起始点位于圆角矩形左下方圆角与左边界的交点；路径添加方向为逆时针时，起始点位于圆角矩形左上方圆角与左边界的交点。 |
| void [OH_Drawing_PathAddOvalWithInitialPoint](#oh_drawing_pathaddovalwithinitialpoint) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, uint32_t start, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | 将椭圆添加到路径中，其中矩形对象作为椭圆的外切矩形区域，绘制方向用来指定绘制时是顺时针或者逆时针方向。 |
| void [OH_Drawing_PathAddArc](#oh_drawing_pathaddarc) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, float startAngle, float sweepAngle) | 将圆弧添加到路径中，作为新轮廓的起点。从起始角度到扫描角度添加弧， 添加的弧是矩形内切椭圆的一部分，如果扫描角度&lt;= -360°，或&gt;= 360°， 并且起始角度对90取模接近于0，则添加椭圆而不是弧。 |
| void [OH_Drawing_PathAddPath](#oh_drawing_pathaddpath) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Path](#oh_drawing_path) \*src, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 将源路径矩阵变换后，添加到当前路径中。 |
| void [OH_Drawing_PathAddPathWithMatrixAndMode](#oh_drawing_pathaddpathwithmatrixandmode) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Path](#oh_drawing_path) \*src, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)) | 将源路径矩阵变换后，以规定模式添加到当前路径中。 |
| void [OH_Drawing_PathAddPathWithMode](#oh_drawing_pathaddpathwithmode) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Path](#oh_drawing_path) \*src, [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)) | 将源路径以规定模式添加到当前路径中。 |
| void [OH_Drawing_PathAddPathWithOffsetAndMode](#oh_drawing_pathaddpathwithoffsetandmode) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Path](#oh_drawing_path) \*src, float dx, float dy, [OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)) | 将源路径偏移后，以规定模式添加到当前路径中。 |
| void [OH_Drawing_PathAddPolygon](#oh_drawing_pathaddpolygon) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*points, uint32_t count, bool isClosed) | 向路径添加多边形。 |
| void [OH_Drawing_PathAddCircle](#oh_drawing_pathaddcircle) ([OH_Drawing_Path](#oh_drawing_path) \*path, float x, float y, float radius, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | 按指定方向，向路径添加圆形。 |
| void [OH_Drawing_PathAddOval](#oh_drawing_pathaddoval) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, [OH_Drawing_PathDirection](#oh_drawing_pathdirection)) | 按指定方向，向路径添加椭圆。 |
| bool [OH_Drawing_PathBuildFromSvgString](#oh_drawing_pathbuildfromsvgstring) ([OH_Drawing_Path](#oh_drawing_path) \*path, const char \*str) | 解析SVG字符串表示的路径。 |
| bool [OH_Drawing_PathContains](#oh_drawing_pathcontains) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | 判断指定坐标点是否被路径包含，判定是否被路径包含的规则参考[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)。 |
| void [OH_Drawing_PathTransform](#oh_drawing_pathtransform) ([OH_Drawing_Path](#oh_drawing_path) \*, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 对路径进行矩阵变换。 |
| void [OH_Drawing_PathTransformWithPerspectiveClip](#oh_drawing_pathtransformwithperspectiveclip) ([OH_Drawing_Path](#oh_drawing_path) \*src, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*, [OH_Drawing_Path](#oh_drawing_path) \*dst, bool applyPerspectiveClip) | 对路径进行矩阵变换。用转换后的路径替换目标路径，如果目标路径为NULL，则替换源路径。 |
| void [OH_Drawing_PathSetFillType](#oh_drawing_pathsetfilltype) ([OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_PathFillType](#oh_drawing_pathfilltype)) | 设置路径的填充类型，这个决定了路径内部区域的定义方式。 |
| float [OH_Drawing_PathGetLength](#oh_drawing_pathgetlength) ([OH_Drawing_Path](#oh_drawing_path) \*, bool forceClosed) | 获取当前路径的长度。 |
| void [OH_Drawing_PathGetBounds](#oh_drawing_pathgetbounds) ([OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*) | 获取包含路径的最小边界框。 |
| void [OH_Drawing_PathClose](#oh_drawing_pathclose) ([OH_Drawing_Path](#oh_drawing_path) \*) | 用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。 |
| bool [OH_Drawing_PathIsClosed](#oh_drawing_pathisclosed) ([OH_Drawing_Path](#oh_drawing_path) \*path, bool forceClosed) | 获取路径是否闭合。 |
| bool [OH_Drawing_PathGetPositionTangent](#oh_drawing_pathgetpositiontangent) ([OH_Drawing_Path](#oh_drawing_path) \*path, bool forceClosed, float distance, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*position, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*tangent) | 获取距路径起始点指定距离的坐标点和切线值。 |
| bool [OH_Drawing_PathOp](#oh_drawing_pathop) ([OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Path](#oh_drawing_path) \*other, [OH_Drawing_PathOpMode](#oh_drawing_pathopmode) op) | 将两个路径按照指定的路径操作类型合并。 |
| bool [OH_Drawing_PathGetMatrix](#oh_drawing_pathgetmatrix) ([OH_Drawing_Path](#oh_drawing_path) \*path, bool forceClosed, float distance, [OH_Drawing_Matrix](#oh_drawing_matrix) \*matrix, [OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags) flag) | 获取距路径起始点指定距离的相应变换矩阵。 |
| void [OH_Drawing_PathOffset](#oh_drawing_pathoffset) ([OH_Drawing_Path](#oh_drawing_path) \*path, [OH_Drawing_Path](#oh_drawing_path) \*dst, float dx, float dy) | 将路径中的所有点沿着x轴和y轴方向偏移一定距离，并将结果存储到目标路径对象中。 |
| void [OH_Drawing_PathReset](#oh_drawing_pathreset) ([OH_Drawing_Path](#oh_drawing_path) \*) | 用于重置自定义路径数据。 |
| [OH_Drawing_PathEffect](#oh_drawing_patheffect) \* [OH_Drawing_CreateDashPathEffect](#oh_drawing_createdashpatheffect) (float \*intervals, int count, float phase) | 创建一个虚线效果的路径效果对象。虚线效果由一组虚线开的间隔、虚线关的间隔数据决定。 |
| void [OH_Drawing_PathEffectDestroy](#oh_drawing_patheffectdestroy) ([OH_Drawing_PathEffect](#oh_drawing_patheffect) \*) | 销毁路径效果对象并回收该对象占有内存。 |
| [OH_Drawing_Pen](#oh_drawing_pen) \* [OH_Drawing_PenCreate](#oh_drawing_pencreate) (void) | 用于创建一个画笔对象。 |
| [OH_Drawing_Pen](#oh_drawing_pen) \* [OH_Drawing_PenCopy](#oh_drawing_pencopy) ([OH_Drawing_Pen](#oh_drawing_pen) \*pen) | 创建一个画笔对象副本[OH_Drawing_Pen](#oh_drawing_pen)，用于拷贝一个已有画笔对象。 |
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
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) [OH_Drawing_PenGetCap](#oh_drawing_pengetcap) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于获取画笔笔帽的样式。 |
| void [OH_Drawing_PenSetCap](#oh_drawing_pensetcap) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)) | 用于设置画笔笔帽样式。 |
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) [OH_Drawing_PenGetJoin](#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | 用于获取画笔绘制折线转角的样式。 |
| void [OH_Drawing_PenSetJoin](#oh_drawing_pensetjoin) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)) | 用于设置画笔绘制转角的样式。 |
| void [OH_Drawing_PenSetShaderEffect](#oh_drawing_pensetshadereffect) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | 设置画笔着色器效果。 |
| void [OH_Drawing_PenSetShadowLayer](#oh_drawing_pensetshadowlayer) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) \*) | 设置画笔阴影层效果，设置的阴影层效果当前仅在绘制文字时生效。 |
| void [OH_Drawing_PenSetPathEffect](#oh_drawing_pensetpatheffect) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PathEffect](#oh_drawing_patheffect) \*) | 设置画笔路径效果。 |
| void [OH_Drawing_PenSetFilter](#oh_drawing_pensetfilter) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | 设置画笔滤波器。 |
| void [OH_Drawing_PenGetFilter](#oh_drawing_pengetfilter) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_Filter](#oh_drawing_filter) \*) | 从画笔获取滤波器[OH_Drawing_Filter](#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。 |
| void [OH_Drawing_PenSetBlendMode](#oh_drawing_pensetblendmode) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_BlendMode](#oh_drawing_blendmode)) | 为画笔设置一个混合器，该混合器实现了指定的混合模式枚举。 |
| bool [OH_Drawing_PenGetFillPath](#oh_drawing_pengetfillpath) ([OH_Drawing_Pen](#oh_drawing_pen) \*, const [OH_Drawing_Path](#oh_drawing_path) \*src, [OH_Drawing_Path](#oh_drawing_path) \*dst, const [OH_Drawing_Rect](#oh_drawing_rect) \*, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 获取使用画笔绘制的源路径轮廓，并用目标路径表示。 |
| void [OH_Drawing_PenReset](#oh_drawing_penreset) ([OH_Drawing_Pen](#oh_drawing_pen) \*) | 将画笔重置至初始值。 |
| [OH_Drawing_PixelMap](#oh_drawing_pixelmap) \* [OH_Drawing_PixelMapGetFromNativePixelMap](#oh_drawing_pixelmapgetfromnativepixelmap) (NativePixelMap_ \*) | 从图像框架定义的像素图对象中获取本模块定义的像素图对象。 |
| [OH_Drawing_PixelMap](#oh_drawing_pixelmap) \* [OH_Drawing_PixelMapGetFromOhPixelMapNative](#oh_drawing_pixelmapgetfromohpixelmapnative) (OH_PixelmapNative \*) | 从图像框架定义的像素图对象中获取本模块定义的像素图对象。 |
| void [OH_Drawing_PixelMapDissolve](#oh_drawing_pixelmapdissolve) ([OH_Drawing_PixelMap](#oh_drawing_pixelmap) \*) | 解除本模块定义的像素图对象和图像框架定义的像素图对象之间的关系，该关系通过调用 [OH_Drawing_PixelMapGetFromNativePixelMap](#oh_drawing_pixelmapgetfromnativepixelmap)或[OH_Drawing_PixelMapGetFromOhPixelMapNative](#oh_drawing_pixelmapgetfromohpixelmapnative)建立。 |
| [OH_Drawing_Point](#oh_drawing_point) \* [OH_Drawing_PointCreate](#oh_drawing_pointcreate) (float x, float y) | 用于创建一个坐标点对象。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_PointGetX](#oh_drawing_pointgetx) (const [OH_Drawing_Point](#oh_drawing_point) \*point, float \*x) | 用于获取点的x轴坐标。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_PointGetY](#oh_drawing_pointgety) (const [OH_Drawing_Point](#oh_drawing_point) \*point, float \*y) | 用于获取点的y轴坐标。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_PointSet](#oh_drawing_pointset) ([OH_Drawing_Point](#oh_drawing_point) \*point, float x, float y) | 用于设置点的x轴和y轴坐标。 |
| void [OH_Drawing_PointDestroy](#oh_drawing_pointdestroy) ([OH_Drawing_Point](#oh_drawing_point) \*) | 用于销毁坐标点对象并回收该对象占有的内存。 |
| [OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) \* [OH_Drawing_RecordCmdUtilsCreate](#oh_drawing_recordcmdutilscreate) (void) | 创建一个录制指令工具对象。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsDestroy](#oh_drawing_recordcmdutilsdestroy) ([OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) \*recordCmdUtils) | 销毁一个录制指令工具对象，并回收该对象占有的内存。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording) ([OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) \*recordCmdUtils, int32_t width, int32_t height, [OH_Drawing_Canvas](#oh_drawing_canvas) \*\*canvas) | 开始录制。此接口需要与[OH_Drawing_RecordCmdUtilsFinishRecording](#oh_drawing_recordcmdutilsfinishrecording)接口成对使用。<br/>指令录制工具生成录制类型的画布对象，可调用drawing的绘制接口，记录接下来所有的绘制指令。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RecordCmdUtilsFinishRecording](#oh_drawing_recordcmdutilsfinishrecording) ([OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils) \*recordCmdUtils, [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) \*\*recordCmd) | 结束录制。在调用此接口前，需要先调用[OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording)接口。<br/>指令录制工具结束录制指令，将录制类型画布对象记录的绘制指令存入生成的录制指令对象。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RecordCmdDestroy](#oh_drawing_recordcmddestroy) ([OH_Drawing_RecordCmd](#oh_drawing_recordcmd) \*recordCmd) | 销毁录制指令对象，并回收该对象占有的内存。 |
| [OH_Drawing_Rect](#oh_drawing_rect) \* [OH_Drawing_RectCreate](#oh_drawing_rectcreate) (float left, float top, float right, float bottom) | 用于创建一个矩形对象，不会对设置的坐标排序，即允许矩形设置的左上角坐标大于对应的矩形右下角坐标。 |
| float [OH_Drawing_RectGetHeight](#oh_drawing_rectgetheight) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于获取矩形对象高度，计算方式为设置的矩形的右下角纵坐标减去左上角纵坐标。 |
| float [OH_Drawing_RectGetWidth](#oh_drawing_rectgetwidth) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于获取矩形对象的宽度，计算方式为设置的矩形的右下角横坐标减去左上角横坐标。 |
| float [OH_Drawing_RectGetLeft](#oh_drawing_rectgetleft) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于获取给矩形设置的左上角的横坐标。 |
| float [OH_Drawing_RectGetTop](#oh_drawing_rectgettop) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于获取给矩形设置的左上角的纵坐标。 |
| float [OH_Drawing_RectGetRight](#oh_drawing_rectgetright) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于获取给矩形设置的右下角的横坐标。 |
| float [OH_Drawing_RectGetBottom](#oh_drawing_rectgetbottom) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于获取给矩形设置的右下角的纵坐标。 |
| bool [OH_Drawing_RectIntersect](#oh_drawing_rectintersect) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](#oh_drawing_rect) \*other) | 用于判断两个矩形是否相交，若相交，将rect设置为两个矩形的交集。 |
| bool [OH_Drawing_RectJoin](#oh_drawing_rectjoin) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, const [OH_Drawing_Rect](#oh_drawing_rect) \*other) | 将两个矩形取并集。 |
| void [OH_Drawing_RectSetLeft](#oh_drawing_rectsetleft) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, float left) | 用于设置矩形左上角的横坐标。 |
| void [OH_Drawing_RectSetTop](#oh_drawing_rectsettop) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, float top) | 用于设置矩形左上角的纵坐标。 |
| void [OH_Drawing_RectSetRight](#oh_drawing_rectsetright) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, float right) | 用于设置矩形右下角的横坐标。 |
| void [OH_Drawing_RectSetBottom](#oh_drawing_rectsetbottom) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect, float bottom) | 用于设置矩形右下角的纵坐标。 |
| void [OH_Drawing_RectCopy](#oh_drawing_rectcopy) ([OH_Drawing_Rect](#oh_drawing_rect) \*sRect, [OH_Drawing_Rect](#oh_drawing_rect) \*dRect) | 用于将源矩形对象复制到目标矩形对象。 |
| void [OH_Drawing_RectDestroy](#oh_drawing_rectdestroy) ([OH_Drawing_Rect](#oh_drawing_rect) \*) | 用于销毁矩形对象并回收该对象占有的内存。 |
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_RectCreateArray](#oh_drawing_rectcreatearray) (size_t size) | 用于创建一个矩形数组对象, 用来存储多个矩形对象。不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_RectDestroyArray](#oh_drawing_rectdestroyarray)接口释放该对象的指针。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RectGetArraySize](#oh_drawing_rectgetarraysize) ([OH_Drawing_Array](#oh_drawing_array) \*rectArray, size_t \*pSize) | 用于获取矩形数组对象[OH_Drawing_Array](#oh_drawing_array)的大小。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RectGetArrayElement](#oh_drawing_rectgetarrayelement) ([OH_Drawing_Array](#oh_drawing_array) \*rectArray, size_t index, [OH_Drawing_Rect](#oh_drawing_rect) \*\*rect) | 用于获取矩形数组对象中指定索引的矩形对象。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RectDestroyArray](#oh_drawing_rectdestroyarray) ([OH_Drawing_Array](#oh_drawing_array) \*rectArray) | 用于销毁矩形数组对象并回收该对象占有的内存。 |
| [OH_Drawing_Region](#oh_drawing_region) \* [OH_Drawing_RegionCreate](#oh_drawing_regioncreate) (void) | 用于创建一个区域对象，实现更精确的图形控制。 |
| bool [OH_Drawing_RegionContains](#oh_drawing_regioncontains) ([OH_Drawing_Region](#oh_drawing_region) \*region, int32_t x, int32_t y) | 判断区域是否包含指定坐标点。 |
| bool [OH_Drawing_RegionOp](#oh_drawing_regionop) ([OH_Drawing_Region](#oh_drawing_region) \*region, const [OH_Drawing_Region](#oh_drawing_region) \*other, [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode) op) | 将两个区域按照指定的区域操作类型合并。 |
| bool [OH_Drawing_RegionSetRect](#oh_drawing_regionsetrect) ([OH_Drawing_Region](#oh_drawing_region) \*region, const [OH_Drawing_Rect](#oh_drawing_rect) \*rect) | 用于尝试给区域对象设置矩形边界。 |
| bool [OH_Drawing_RegionSetPath](#oh_drawing_regionsetpath) ([OH_Drawing_Region](#oh_drawing_region) \*region, const [OH_Drawing_Path](#oh_drawing_path) \*path, const [OH_Drawing_Region](#oh_drawing_region) \*clip) | 给区域对象设置为指定区域内路径表示的范围。 |
| void [OH_Drawing_RegionDestroy](#oh_drawing_regiondestroy) ([OH_Drawing_Region](#oh_drawing_region) \*) | 用于销毁区域对象并回收该对象占有的内存。 |
| uint32_t [OH_Drawing_RegisterFont](#oh_drawing_registerfont) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*, const char \*fontFamily, const char \*familySrc) | 用于在字体管理器中注册自定义字体，支持的字体文件格式包含：ttf、otf。 |
| uint32_t [OH_Drawing_RegisterFontBuffer](#oh_drawing_registerfontbuffer) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*, const char \*fontFamily, uint8_t \*fontBuffer, size_t length) | 用于在字体管理器中注册字体缓冲区。 |
| [OH_Drawing_RoundRect](#oh_drawing_roundrect) \* [OH_Drawing_RoundRectCreate](#oh_drawing_roundrectcreate) (const [OH_Drawing_Rect](#oh_drawing_rect) \*, float xRad, float yRad) | 用于创建一个圆角矩形对象。 |
| void [OH_Drawing_RoundRectSetCorner](#oh_drawing_roundrectsetcorner) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*, [OH_Drawing_CornerPos](#oh_drawing_cornerpos) pos, [OH_Drawing_Corner_Radii](#oh_drawing_corner_radii)) | 用于设置圆角矩形中指定圆角位置的圆角半径。 |
| [OH_Drawing_Corner_Radii](#oh_drawing_corner_radii) [OH_Drawing_RoundRectGetCorner](#oh_drawing_roundrectgetcorner) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*, [OH_Drawing_CornerPos](#oh_drawing_cornerpos) pos) | 用于获取圆角矩形中指定圆角位置的圆角半径。 |
| void [OH_Drawing_RoundRectDestroy](#oh_drawing_roundrectdestroy) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*) | 用于销毁圆角矩形对象并回收该对象占有的内存。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_RoundRectOffset](#oh_drawing_roundrectoffset) ([OH_Drawing_RoundRect](#oh_drawing_roundrect) \*roundRect, float dx, float dy) | 用于将圆角矩形沿x轴方向和y轴方向平移指定距离。 |
| [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \* [OH_Drawing_SamplingOptionsCreate](#oh_drawing_samplingoptionscreate) ([OH_Drawing_FilterMode](#oh_drawing_filtermode), [OH_Drawing_MipmapMode](#oh_drawing_mipmapmode)) | 创建一个采样选项对象。 |
| void [OH_Drawing_SamplingOptionsDestroy](#oh_drawing_samplingoptionsdestroy) ([OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*) | 销毁采样选项对象并回收该对象占有内存。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateColorShader](#oh_drawing_shadereffectcreatecolorshader) (const uint32_t color) | 创建具有单一颜色的着色器。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradient](#oh_drawing_shadereffectcreatelineargradient) (const [OH_Drawing_Point](#oh_drawing_point) \*startPt, const [OH_Drawing_Point](#oh_drawing_point) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | 创建着色器，在两个指定点之间生成线性渐变。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateLinearGradientWithLocalMatrix](#oh_drawing_shadereffectcreatelineargradientwithlocalmatrix) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*startPt, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*endPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode), const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 创建着色器，在两个指定点之间生成线性渐变。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradient](#oh_drawing_shadereffectcreateradialgradient) (const [OH_Drawing_Point](#oh_drawing_point) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | 创建着色器，在给定圆心和半径的情况下生成径向渐变。 从起点到终点颜色从内到外进行圆形渐变（从中间向外拉）被称为径向渐变。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateRadialGradientWithLocalMatrix](#oh_drawing_shadereffectcreateradialgradientwithlocalmatrix) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*centerPt, float radius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode), const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 创建着色器，在给定圆心和半径的情况下生成径向渐变。 从起点到终点颜色从内到外进行圆形渐变（从中间向外拉）被称为径向渐变。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateSweepGradient](#oh_drawing_shadereffectcreatesweepgradient) (const [OH_Drawing_Point](#oh_drawing_point) \*centerPt, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode)) | 创建着色器，在给定中心的情况下生成扇形渐变。 颜色从0°到360°渐变被称为扇形渐变。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateImageShader](#oh_drawing_shadereffectcreateimageshader) ([OH_Drawing_Image](#oh_drawing_image) \*, [OH_Drawing_TileMode](#oh_drawing_tilemode) tileX, [OH_Drawing_TileMode](#oh_drawing_tilemode) tileY, const [OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions) \*, const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 创建图像着色器。此接口不建议用于录制类型的画布，会影响性能。 |
| [OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \* [OH_Drawing_ShaderEffectCreateTwoPointConicalGradient](#oh_drawing_shadereffectcreatetwopointconicalgradient) (const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*startPt, float startRadius, const [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*endPt, float endRadius, const uint32_t \*colors, const float \*pos, uint32_t size, [OH_Drawing_TileMode](#oh_drawing_tilemode), const [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 创建着色器，在给定两个圆之间生成渐变。 |
| void [OH_Drawing_ShaderEffectDestroy](#oh_drawing_shadereffectdestroy) ([OH_Drawing_ShaderEffect](#oh_drawing_shadereffect) \*) | 销毁着色器对象，并收回该对象占用的内存。 |
| [OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) \* [OH_Drawing_ShadowLayerCreate](#oh_drawing_shadowlayercreate) (float blurRadius, float x, float y, uint32_t color) | 创建一个阴影层对象。 |
| void [OH_Drawing_ShadowLayerDestroy](#oh_drawing_shadowlayerdestroy) ([OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer) \*) | 销毁阴影层对象，并收回该对象占用的内存。 |
| [OH_Drawing_Surface](#oh_drawing_surface) \* [OH_Drawing_SurfaceCreateFromGpuContext](#oh_drawing_surfacecreatefromgpucontext) ([OH_Drawing_GpuContext](#oh_drawing_gpucontext) \*, bool budgeted, [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)) | 使用图形处理器上下文创建一个surface对象，用于管理画布绘制的内容。 |
| [OH_Drawing_Canvas](#oh_drawing_canvas) \* [OH_Drawing_SurfaceGetCanvas](#oh_drawing_surfacegetcanvas) ([OH_Drawing_Surface](#oh_drawing_surface) \*) | 通过surface对象获取画布对象。 |
| void [OH_Drawing_SurfaceDestroy](#oh_drawing_surfacedestroy) ([OH_Drawing_Surface](#oh_drawing_surface) \*) | 销毁surface对象并回收该对象占用的内存。 |
| [OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \* [OH_Drawing_TextBlobBuilderCreate](#oh_drawing_textblobbuildercreate) (void) | 用于创建一个文本构造器对象。 |
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromText](#oh_drawing_textblobcreatefromtext) (const void \*text, size_t byteLength, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | 使用文本创建一个文本对象。 |
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromPosText](#oh_drawing_textblobcreatefrompostext) (const void \*text, size_t byteLength, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | 使用文本创建文本对象，文本对象中每个字符的坐标由OH_Drawing_Point2D数组中对应的坐标信息决定。 |
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromString](#oh_drawing_textblobcreatefromstring) (const char \*str, const [OH_Drawing_Font](#oh_drawing_font) \*, [OH_Drawing_TextEncoding](#oh_drawing_textencoding)) | 使用字符串创建文本对象。 |
| void [OH_Drawing_TextBlobGetBounds](#oh_drawing_textblobgetbounds) ([OH_Drawing_TextBlob](#oh_drawing_textblob) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*) | 获取文本对象的边界范围。 |
| uint32_t [OH_Drawing_TextBlobUniqueID](#oh_drawing_textblobuniqueid) (const [OH_Drawing_TextBlob](#oh_drawing_textblob) \*) | 获取文本的标识符，该标识符是唯一的非零值。 |
| const [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) \* [OH_Drawing_TextBlobBuilderAllocRunPos](#oh_drawing_textblobbuilderallocrunpos) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*, const [OH_Drawing_Font](#oh_drawing_font) \*, int32_t count, const [OH_Drawing_Rect](#oh_drawing_rect) \*) | 申请一块内存，用于存储文字和位置信息。返回的指针无需调用者管理， 当调用[OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake)后禁止使用。 |
| [OH_Drawing_TextBlob](#oh_drawing_textblob) \* [OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*) | 用于从文本构造器中创建文本对象。 |
| void [OH_Drawing_TextBlobDestroy](#oh_drawing_textblobdestroy) ([OH_Drawing_TextBlob](#oh_drawing_textblob) \*) | 用于销毁文本对象并回收该对象占有的内存。 |
| void [OH_Drawing_TextBlobBuilderDestroy](#oh_drawing_textblobbuilderdestroy) ([OH_Drawing_TextBlobBuilder](#oh_drawing_textblobbuilder) \*) | 用于销毁文本构造器对象并回收该对象占有的内存。 |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_MatchFontDescriptors](#oh_drawing_matchfontdescriptors) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*, size_t \*) | 获取与指定字体描述符匹配的所有系统字体描述符，其中[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)的path字段不作为有效的匹配字段，其余字段不是默认值时生效，如果参数[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)的所有字段都是默认值，则获取所有系统字体描述符。如果匹配失败，返回NULL。不再需要[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptors](_drawing.md#oh_drawing_destroyfontdescriptors)接口释放该对象的指针。 |
| void [OH_Drawing_DestroyFontDescriptors](#oh_drawing_destroyfontdescriptors) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*, size_t) | 释放字体描述符[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)数组。 |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_GetFontDescriptorByFullName](#oh_drawing_getfontdescriptorbyfullname) (const [OH_Drawing_String](_o_h___drawing___string.md) \*, [OH_Drawing_SystemFontType](#oh_drawing_systemfonttype)) | 根据字体名称和字体类型获取指定的字体描述符，支持系统字体、风格字体和用户已安装字体。 字体描述符是描述字体特征的一种数据结构，它包含了定义字体外观和属性的详细信息。 |
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_GetSystemFontFullNamesByType](#oh_drawing_getsystemfontfullnamesbytype) ([OH_Drawing_SystemFontType](#oh_drawing_systemfonttype)) | 根据字体类型获取对应字体的字体名称数组。 |
| const [OH_Drawing_String](_o_h___drawing___string.md) \* [OH_Drawing_GetSystemFontFullNameByIndex](#oh_drawing_getsystemfontfullnamebyindex) ([OH_Drawing_Array](#oh_drawing_array) \*, size_t) | 在字体名称数组中通过索引获取对应位置的字体名称。 |
| void [OH_Drawing_DestroySystemFontFullNames](#oh_drawing_destroysystemfontfullnames) ([OH_Drawing_Array](#oh_drawing_array) \*) | 释放通过字体类型获取的对应字体的字体名称数组占用的内存。 |
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_TypographyGetTextLines](#oh_drawing_typographygettextlines) ([OH_Drawing_Typography](#oh_drawing_typography) \*typography) | 获取排版对象的文本行数组。文本行数组中包含一个或多个文本行对象。不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_DestroyTextLines](#oh_drawing_destroytextlines)接口释放该对象的指针。 |
| void [OH_Drawing_DestroyTextLines](#oh_drawing_destroytextlines) ([OH_Drawing_Array](#oh_drawing_array) \*lines) | 释放文本行数组的内存。 |
| void [OH_Drawing_DestroyTextLine](#oh_drawing_destroytextline) (OH_Drawing_TextLine \*line) | 释放单个文本行对象的内存。只能释放单独申请内存的文本行对象，不能释放文本行数组中的某一个文本行对象的内存。 |
| OH_Drawing_TextLine \* [OH_Drawing_GetTextLineByIndex](#oh_drawing_gettextlinebyindex) ([OH_Drawing_Array](#oh_drawing_array) \*lines, size_t index) | 获取文本行数组指定索引处的文本行对象。 |
| double [OH_Drawing_TextLineGetGlyphCount](#oh_drawing_textlinegetglyphcount) (OH_Drawing_TextLine \*line) | 获取文本行对象中字形的数量。 |
| void [OH_Drawing_TextLineGetTextRange](#oh_drawing_textlinegettextrange) (OH_Drawing_TextLine \*line, size_t \*start, size_t \*end) | 获取文本行对象中的文本在整个段落文本中的索引区间。 |
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_TextLineGetGlyphRuns](#oh_drawing_textlinegetglyphruns) (OH_Drawing_TextLine \*line) | 获取文本行对象中的文本渲染单元数组。 |
| void [OH_Drawing_DestroyRuns](#oh_drawing_destroyruns) ([OH_Drawing_Array](#oh_drawing_array) \*runs) | 释放文本渲染单元数组的内存。 |
| OH_Drawing_Run \* [OH_Drawing_GetRunByIndex](#oh_drawing_getrunbyindex) ([OH_Drawing_Array](#oh_drawing_array) \*runs, size_t index) | 获取文本渲染单元数组指定索引处的文本渲染单元对象。 |
| void [OH_Drawing_TextLinePaint](#oh_drawing_textlinepaint) (OH_Drawing_TextLine \*line, [OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, double x, double y) | 在画布上以坐标点 (x, y) 为左上角位置绘制文本行。 |
| OH_Drawing_TextLine \* [OH_Drawing_TextLineCreateTruncatedLine](#oh_drawing_textlinecreatetruncatedline) (OH_Drawing_TextLine \*line, double width, int mode, const char \*ellipsis) | 创建一个截断的文本行对象。 |
| double [OH_Drawing_TextLineGetTypographicBounds](#oh_drawing_textlinegettypographicbounds) (OH_Drawing_TextLine \*line, double \*ascent, double \*descent, double \*leading) | 获取文本行对象的排版边界。文本行排版边界与排版字体、排版字号有关，与字符本身无关。 例如字符串为" a b "，'a'字符前面有1个空格，'b'字符后面有1个空格，排版边界就包括行首和末尾空格的边界。例如字符串为"j"或"E"，排版边界相同，即与字符本身无关。 |
| [OH_Drawing_Rect](#oh_drawing_rect) \* [OH_Drawing_TextLineGetImageBounds](#oh_drawing_textlinegetimagebounds) (OH_Drawing_TextLine \*line) | 获取文本行对象的图像边界。文本行图像边界与排版字体、排版字号、字符本身都有关，相当于视觉边界。 例如字符串为" a b "，'a'字符前面有1个空格，'b'字符后面有1个空格,用户在界面上只能看到"a b"，图像边界即为不包括带行首和末尾空格的边界。 例如字符串为"j"或"E"，视觉边界不同，即与字符本身有关，"j"字符串的视觉边界宽度小于"E"字符串的视觉边界宽度，"j"字符串的视觉边界高度大于"E"字符串的视觉边界高度。 |
| double [OH_Drawing_TextLineGetTrailingSpaceWidth](#oh_drawing_textlinegettrailingspacewidth) (OH_Drawing_TextLine \*line) | 获取文本行对象尾部空白字符的宽度。 |
| int32_t [OH_Drawing_TextLineGetStringIndexForPosition](#oh_drawing_textlinegetstringindexforposition) (OH_Drawing_TextLine \*line, [OH_Drawing_Point](#oh_drawing_point) \*point) | 获取文本行对象中指定位置处的字符索引。 |
| double [OH_Drawing_TextLineGetOffsetForStringIndex](#oh_drawing_textlinegetoffsetforstringindex) (OH_Drawing_TextLine \*line, int32_t index) | 获取文本行对象中指定字符串索引处的偏移量。 |
| void [OH_Drawing_TextLineEnumerateCaretOffsets](#oh_drawing_textlineenumeratecaretoffsets) (OH_Drawing_TextLine \*line, [Drawing_CaretOffsetsCallback](#drawing_caretoffsetscallback) callback) | 枚举文本行对象中每个字符的偏移量和索引值，传递给用户自定义的回调函数，用户可以使用偏移量和索引值进行其他操作。 |
| double [OH_Drawing_TextLineGetAlignmentOffset](#oh_drawing_textlinegetalignmentoffset) (OH_Drawing_TextLine \*line, double alignmentFactor, double alignmentWidth) | 获取文本行对象根据对齐因子和对齐宽度计算对齐后所需的偏移量。 |
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_GetRunStringIndices](#oh_drawing_getrunstringindices) (OH_Drawing_Run \*run, int64_t start, int64_t length) | 获取渲染单元指定范围内字形的字符索引数组，该索引是相对于整个段落的偏移。 |
| uint64_t [OH_Drawing_GetRunStringIndicesByIndex](#oh_drawing_getrunstringindicesbyindex) ([OH_Drawing_Array](#oh_drawing_array) \*stringIndices, size_t index) | 获取字符索引数组中指定下标的字符索引值。 |
| void [OH_Drawing_DestroyRunStringIndices](#oh_drawing_destroyrunstringindices) ([OH_Drawing_Array](#oh_drawing_array) \*stringIndices) | 释放字形的字符索引数组对象指针。 |
| void [OH_Drawing_GetRunStringRange](#oh_drawing_getrunstringrange) (OH_Drawing_Run \*run, uint64_t \*location, uint64_t \*length) | 获取渲染单元生成字形的字符范围。 |
| float [OH_Drawing_GetRunTypographicBounds](#oh_drawing_getruntypographicbounds) (OH_Drawing_Run \*run, float \*ascent, float \*descent, float \*leading) | 获取渲染单元的排版边界。文本排版边界与字符本身无关，与排版字号和字体有关。 |
| void [OH_Drawing_RunPaint](#oh_drawing_runpaint) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, OH_Drawing_Run \*run, double x, double y) | 在画布上绘制渲染单元包含的文本。 |
| [OH_Drawing_Rect](#oh_drawing_rect) \* [OH_Drawing_GetRunImageBounds](#oh_drawing_getrunimagebounds) (OH_Drawing_Run \*run) | 获取渲染单元的图像边界，文本图像边界与字符本身有关，相当于视觉边界。 |
| void [OH_Drawing_DestroyRunImageBounds](#oh_drawing_destroyrunimagebounds) ([OH_Drawing_Rect](#oh_drawing_rect) \*rect) | 释放渲染单元图像边界对象指针。 |
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_GetRunGlyphs](#oh_drawing_getrunglyphs) (OH_Drawing_Run \*run, int64_t start, int64_t length) | 获取渲染单元指定范围内的字形数组。 |
| uint16_t [OH_Drawing_GetRunGlyphsByIndex](#oh_drawing_getrunglyphsbyindex) ([OH_Drawing_Array](#oh_drawing_array) \*glyphs, size_t index) | 根据索引获取渲染单元单个字形。 |
| void [OH_Drawing_DestroyRunGlyphs](#oh_drawing_destroyrunglyphs) ([OH_Drawing_Array](#oh_drawing_array) \*glyphs) | 释放渲染单元字形数组对象指针。 |
| [OH_Drawing_Array](#oh_drawing_array) \* [OH_Drawing_GetRunPositions](#oh_drawing_getrunpositions) (OH_Drawing_Run \*run, int64_t start, int64_t length) | 获取渲染单元指定范围内字形的位置。 |
| [OH_Drawing_Point](#oh_drawing_point) \* [OH_Drawing_GetRunPositionsByIndex](#oh_drawing_getrunpositionsbyindex) ([OH_Drawing_Array](#oh_drawing_array) \*positions, size_t index) | 根据索引获取渲染单元中单个字形位置。 |
| void [OH_Drawing_DestroyRunPositions](#oh_drawing_destroyrunpositions) ([OH_Drawing_Array](#oh_drawing_array) \*positions) | 释放渲染单元字形位置数组对象指针。 |
| uint32_t [OH_Drawing_GetRunGlyphCount](#oh_drawing_getrunglyphcount) (OH_Drawing_Run \*run) | 获取渲染单元字形数量。 |
| [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \* [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle) (void) | 创建指向OH_Drawing_TypographyStyle对象的指针。不再需要[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)时，请使用[OH_Drawing_DestroyTypographyStyle](#oh_drawing_destroytypographystyle)接口释放该对象的指针。 |
| void [OH_Drawing_DestroyTypographyStyle](#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 释放被OH_Drawing_TypographyStyle对象占据的内存。 |
| void [OH_Drawing_SetTypographyTextDirection](#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置指定排版样式中的文本方向。 |
| void [OH_Drawing_SetTypographyTextAlign](#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本对齐方式。 |
| int [OH_Drawing_TypographyGetEffectiveAlignment](#oh_drawing_typographygeteffectivealignment) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | 获取文字对齐方式。 |
| void [OH_Drawing_SetTypographyTextMaxLines](#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本最大行数。 |
| [OH_Drawing_TextStyle](#oh_drawing_textstyle) \* [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle) (void) | 创建指向OH_Drawing_TextStyle对象的指针。 |
| [OH_Drawing_TextStyle](#oh_drawing_textstyle) \* [OH_Drawing_TypographyGetTextStyle](#oh_drawing_typographygettextstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | 获取指定排版样式中设置的默认文本样式。 |
| void [OH_Drawing_DestroyTextStyle](#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 释放被OH_Drawing_TextStyle对象占据的内存。 |
| void [OH_Drawing_SetTextStyleColor](#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | 设置文本颜色。 |
| void [OH_Drawing_SetTextStyleFontSize](#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置字号。 |
| void [OH_Drawing_SetTextStyleFontWeight](#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 为指定文本样式设置字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| void [OH_Drawing_SetTextStyleBaseLine](#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置文本样式的字体基线位置。 |
| void [OH_Drawing_SetTextStyleDecoration](#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置指定文本样式中的装饰线类型，只能设置一个装饰线类型，添加多个需要使用[OH_Drawing_AddTextStyleDecoration](#oh_drawing_addtextstyledecoration)。 |
| void [OH_Drawing_AddTextStyleDecoration](#oh_drawing_addtextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 新增指定装饰，可同时显示多种装饰线。 |
| void [OH_Drawing_RemoveTextStyleDecoration](#oh_drawing_removetextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 删除指定装饰。 |
| void [OH_Drawing_SetTextStyleDecorationColor](#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | 设置指定文本样式中的装饰线颜色。 |
| void [OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置行高，按当前字体大小的倍数进行设置。 |
| void [OH_Drawing_SetTextStyleFontFamilies](#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | 设置指定文本样式的字体家族类型。 |
| void [OH_Drawing_SetTextStyleFontStyle](#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 为指定文本样式设置字体样式。 |
| void [OH_Drawing_SetTextStyleLocale](#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | 设置文本语言环境。 |
| void [OH_Drawing_SetTextStyleForegroundBrush](#oh_drawing_settextstyleforegroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | 设置指定文本样式中的前景色画刷。 |
| void [OH_Drawing_TextStyleGetForegroundBrush](#oh_drawing_textstylegetforegroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | 返回设置的前景色画刷。 |
| void [OH_Drawing_SetTextStyleForegroundPen](#oh_drawing_settextstyleforegroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | 设置指定文本样式中的前景色画笔。 |
| void [OH_Drawing_TextStyleGetForegroundPen](#oh_drawing_textstylegetforegroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | 返回设置的前景色画笔。 |
| void [OH_Drawing_SetTextStyleBackgroundBrush](#oh_drawing_settextstylebackgroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | 设置指定文本样式中的背景色画刷。 |
| void [OH_Drawing_TextStyleGetBackgroundBrush](#oh_drawing_textstylegetbackgroundbrush) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Brush](#oh_drawing_brush) \*) | 返回设置的背景色画刷。 |
| void [OH_Drawing_SetTextStyleBackgroundPen](#oh_drawing_settextstylebackgroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | 设置指定文本样式中的背景色画笔。 |
| void [OH_Drawing_TextStyleGetBackgroundPen](#oh_drawing_textstylegetbackgroundpen) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Pen](#oh_drawing_pen) \*) | 返回设置的背景色画笔。 |
| [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \* [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | 创建指向OH_Drawing_TypographyCreate对象的指针。不再需要[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)时，请使用[OH_Drawing_DestroyTypographyHandler](#oh_drawing_destroytypographyhandler)接口释放该对象的指针。 |
| void [OH_Drawing_DestroyTypographyHandler](#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | 释放被OH_Drawing_TypographyCreate对象占据的内存。 |
| void [OH_Drawing_TypographyHandlerPushTextStyle](#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 设置排版风格。 |
| void [OH_Drawing_TypographyHandlerAddText](#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, const char \*) | 设置文本内容。 |
| void [OH_Drawing_TypographyHandlerPopTextStyle](#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | 排版弹出。 |
| [OH_Drawing_Typography](#oh_drawing_typography) \* [OH_Drawing_CreateTypography](#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | 创建指向OH_Drawing_Typography对象的指针。不再需要[OH_Drawing_Typography](#oh_drawing_typography)时，请使用[OH_Drawing_DestroyTypography](#oh_drawing_destroytypography)接口释放该对象的指针。 |
| void [OH_Drawing_DestroyTypography](#oh_drawing_destroytypography) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 释放OH_Drawing_Typography对象占据的内存。 |
| void [OH_Drawing_TypographyLayout](#oh_drawing_typographylayout) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double) | 排版布局。 |
| void [OH_Drawing_TypographyPaint](#oh_drawing_typographypaint) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_Canvas](#oh_drawing_canvas) \*, double, double) | 在指定位置绘制文本，从左上角开始绘制，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用并生效之后调用。 |
| void [OH_Drawing_TypographyPaintOnPath](#oh_drawing_typographypaintonpath) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Path](#oh_drawing_path) \*, double, double) | 沿路径绘制文本。 |
| double [OH_Drawing_TypographyGetMaxWidth](#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取用户设置的排版宽度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| double [OH_Drawing_TypographyGetHeight](#oh_drawing_typographygetheight) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象整体的高度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| double [OH_Drawing_TypographyGetLongestLine](#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象最长行的宽度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。 |
| double [OH_Drawing_TypographyGetLongestLineWithIndent](#oh_drawing_typographygetlongestlinewithindent) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象最长行的宽度（该宽度包含当前行缩进的宽度），该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。 |
| double [OH_Drawing_TypographyGetMinIntrinsicWidth](#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象的最小固有宽度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| double [OH_Drawing_TypographyGetMaxIntrinsicWidth](#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象的最大固有宽度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| double [OH_Drawing_TypographyGetAlphabeticBaseline](#oh_drawing_typographygetalphabeticbaseline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版样式字母文字基线。 |
| double [OH_Drawing_TypographyGetIdeographicBaseline](#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版样式表意文字基线。 |
| void [OH_Drawing_TypographyHandlerAddPlaceholder](#oh_drawing_typographyhandleraddplaceholder) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, [OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md) \*) | 设置占位符。 |
| bool [OH_Drawing_TypographyDidExceedMaxLines](#oh_drawing_typographydidexceedmaxlines) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象中文本是否超过最大行，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用，如果没有通过[OH_Drawing_SetTypographyTextMaxLines](#oh_drawing_settypographytextmaxlines)接口设置最大行，则返回false。 |
| [OH_Drawing_TextBox](#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t, size_t, [OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle), [OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)) | 获取排版对象中指定范围内的文本框，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](#oh_drawing_textbox)时，请使用[OH_Drawing_TypographyDestroyTextBox](#oh_drawing_typographydestroytextbox)接口释放该对象的指针。 |
| [OH_Drawing_TextBox](#oh_drawing_textbox) \* [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象中占位符的文本框，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](#oh_drawing_textbox)时，请使用[OH_Drawing_TypographyDestroyTextBox](#oh_drawing_typographydestroytextbox)接口释放该对象的指针。 |
| float [OH_Drawing_GetLeftFromTextBox](#oh_drawing_getleftfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框左侧位置。 |
| float [OH_Drawing_GetRightFromTextBox](#oh_drawing_getrightfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框右侧位置。 |
| float [OH_Drawing_GetTopFromTextBox](#oh_drawing_gettopfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框顶部位置。 |
| float [OH_Drawing_GetBottomFromTextBox](#oh_drawing_getbottomfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框底部位置。 |
| int [OH_Drawing_GetTextDirectionFromTextBox](#oh_drawing_gettextdirectionfromtextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*, int) | 获取文本框方向。 |
| size_t [OH_Drawing_GetSizeOfTextBox](#oh_drawing_getsizeoftextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*) | 获取文本框数量大小。 |
| [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double, double) | 获取坐标处文本的索引位置和亲和性。 |
| [OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \* [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double, double) | 获取坐标处文本所属字符簇的索引位置和亲和性，字符簇指一个或多个字符组成的整体。 |
| size_t [OH_Drawing_GetPositionFromPositionAndAffinity](#oh_drawing_getpositionfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \*) | 获取OH_Drawing_PositionAndAffinity对象的位置属性。 |
| int [OH_Drawing_GetAffinityFromPositionAndAffinity](#oh_drawing_getaffinityfrompositionandaffinity) ([OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity) \*) | 获取OH_Drawing_PositionAndAffinity对象的亲和性，根据亲和性可判断字体会靠近前方文本还是后方文本。 |
| [OH_Drawing_Range](#oh_drawing_range) \* [OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t) | 获取排版对象中单词的边界。 |
| size_t [OH_Drawing_GetStartFromRange](#oh_drawing_getstartfromrange) ([OH_Drawing_Range](#oh_drawing_range) \*) | 获取OH_Drawing_Range对象开始位置。 |
| size_t [OH_Drawing_GetEndFromRange](#oh_drawing_getendfromrange) ([OH_Drawing_Range](#oh_drawing_range) \*) | 获取OH_Drawing_Range对象结束位置。 |
| size_t [OH_Drawing_TypographyGetLineCount](#oh_drawing_typographygetlinecount) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象中文本行数，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| void [OH_Drawing_SetTextStyleDecorationStyle](#oh_drawing_settextstyledecorationstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置指定文本样式中的装饰线样式。 |
| void [OH_Drawing_SetTextStyleDecorationThicknessScale](#oh_drawing_settextstyledecorationthicknessscale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置文本装饰线的厚度缩放比例。 |
| void [OH_Drawing_SetTextStyleLetterSpacing](#oh_drawing_settextstyleletterspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置文本的字符间距。 |
| void [OH_Drawing_SetTextStyleWordSpacing](#oh_drawing_settextstylewordspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | 设置文本的单词间距。 |
| void [OH_Drawing_SetTextStyleHalfLeading](#oh_drawing_settextstylehalfleading) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, bool) | 设置文本为一半行间距。 |
| void [OH_Drawing_SetTextStyleEllipsis](#oh_drawing_settextstyleellipsis) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | 设置文本的省略号内容。 |
| void [OH_Drawing_SetTextStyleEllipsisModal](#oh_drawing_settextstyleellipsismodal) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 设置文本的省略号样式。 |
| void [OH_Drawing_SetTypographyTextBreakStrategy](#oh_drawing_settypographytextbreakstrategy) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本的中断策略。 |
| void [OH_Drawing_SetTypographyTextWordBreakType](#oh_drawing_settypographytextwordbreaktype) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置单词的断词方式。 |
| void [OH_Drawing_SetTypographyTextEllipsisModal](#oh_drawing_settypographytextellipsismodal) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置排版样式省略模式。 |
| void [OH_Drawing_SetTypographyTextEllipsis](#oh_drawing_settypographytextellipsis) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, const char \*ellipsis) | 设置排版样式省略号文本。 |
| double [OH_Drawing_TypographyGetLineHeight](#oh_drawing_typographygetlineheight) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | 获取排版对象中指定行的行高，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| double [OH_Drawing_TypographyGetLineWidth](#oh_drawing_typographygetlinewidth) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | 获取指定行的行宽，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| void [OH_Drawing_SetTypographyTextSplitRatio](#oh_drawing_settypographytextsplitratio) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, float textSplitRatio) | 设置文本划分比率。 |
| bool [OH_Drawing_TypographyIsLineUnlimited](#oh_drawing_typographyislineunlimited) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | 获取文本是否有最大行数限制。 |
| bool [OH_Drawing_TypographyIsEllipsized](#oh_drawing_typographyisellipsized) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | 获取指定排版样式是否配置省略号。 |
| void [OH_Drawing_SetTypographyTextLocale](#oh_drawing_settypographytextlocale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, const char \*locale) | 设置指定排版样式的语言环境。 |
| bool [OH_Drawing_TextStyleGetFontMetrics](#oh_drawing_textstylegetfontmetrics) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | 获取文本字体属性。 |
| void [OH_Drawing_SetTypographyTextStyle](#oh_drawing_settypographytextstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 设置排版样式。 |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_CreateFontDescriptor](#oh_drawing_createfontdescriptor) (void) | 构造字体描述对象，用于描述系统字体详细信息。 |
| void [OH_Drawing_DestroyFontDescriptor](#oh_drawing_destroyfontdescriptor) ([OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \*) | 释放字体描述对象占用的内存。 |
| [OH_Drawing_FontParser](#oh_drawing_fontparser) \* [OH_Drawing_CreateFontParser](#oh_drawing_createfontparser) (void) | 构造字体解析对象，用于解析系统字体。 |
| void [OH_Drawing_DestroyFontParser](#oh_drawing_destroyfontparser) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*) | 释放字体解析对象占用的内存。 |
| char \*\* [OH_Drawing_FontParserGetSystemFontList](#oh_drawing_fontparsergetsystemfontlist) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*, size_t \*) | 获取系统字体名称列表，此接口仅在2in1、phone设备上可用。 |
| void [OH_Drawing_DestroySystemFontList](#oh_drawing_destroysystemfontlist) (char \*\*, size_t) | 释放系统字体名称列表占用的内存。 |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) \* [OH_Drawing_FontParserGetFontByName](#oh_drawing_fontparsergetfontbyname) ([OH_Drawing_FontParser](#oh_drawing_fontparser) \*, const char \*) | 根据传入的系统字体名称获取系统字体的相关信息。 |
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \* [OH_Drawing_TypographyGetLineMetrics](#oh_drawing_typographygetlinemetrics) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取排版对象的行位置信息，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)时，请使用[OH_Drawing_DestroyLineMetrics](#oh_drawing_destroylinemetrics)接口释放该对象的指针。 |
| size_t [OH_Drawing_LineMetricsGetSize](#oh_drawing_linemetricsgetsize) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | 获取行数量。 |
| void [OH_Drawing_DestroyLineMetrics](#oh_drawing_destroylinemetrics) ([OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | 释放行位置信息对象占用的内存。 |
| bool [OH_Drawing_TypographyGetLineMetricsAt](#oh_drawing_typographygetlinemetricsat) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | 获取排版对象的指定行位置信息，具体参见[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)结构体，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| bool [OH_Drawing_TypographyGetLineInfo](#oh_drawing_typographygetlineinfo) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, bool, bool, [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) \*) | 获取排版对象中指定行的位置信息或指定行第一个字符的位置信息，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。 |
| void [OH_Drawing_SetTypographyTextFontWeight](#oh_drawing_settypographytextfontweight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置排版样式默认字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| void [OH_Drawing_SetTypographyTextFontStyle](#oh_drawing_settypographytextfontstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置排版样式默认的字体样式。 |
| void [OH_Drawing_SetTypographyTextFontFamily](#oh_drawing_settypographytextfontfamily) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, const char \*) | 设置字体家族的名称。 |
| void [OH_Drawing_SetTypographyTextFontSize](#oh_drawing_settypographytextfontsize) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | 设置文本排版字号。 |
| void [OH_Drawing_SetTypographyTextFontHeight](#oh_drawing_settypographytextfontheight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | 设置文本排版字体高度。 |
| void [OH_Drawing_SetTypographyTextHalfLeading](#oh_drawing_settypographytexthalfleading) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | 设置文本排版是否为一半行间距。 |
| void [OH_Drawing_SetTypographyTextUseLineStyle](#oh_drawing_settypographytextuselinestyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | 设置文本排版是否启用行样式。 |
| void [OH_Drawing_SetTypographyTextLineStyleFontWeight](#oh_drawing_settypographytextlinestylefontweight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置排版样式中支柱样式的文本样式字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。 |
| void [OH_Drawing_SetTypographyTextLineStyleFontStyle](#oh_drawing_settypographytextlinestylefontstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | 设置文本排版样式中支柱样式的字体样式。 |
| void [OH_Drawing_SetTypographyTextLineStyleFontFamilies](#oh_drawing_settypographytextlinestylefontfamilies) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int, const char \*fontFamilies[]) | 设置文本排版行样式字体类型。 |
| void [OH_Drawing_SetTypographyTextLineStyleFontSize](#oh_drawing_settypographytextlinestylefontsize) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | 设置文本排版行样式字号。 |
| void [OH_Drawing_SetTypographyTextLineStyleFontHeight](#oh_drawing_settypographytextlinestylefontheight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | 设置文本排版行样式字体高度。 |
| void [OH_Drawing_SetTypographyTextLineStyleHalfLeading](#oh_drawing_settypographytextlinestylehalfleading) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | 设置文本排版行样式中支柱样式是否开启一半行间距。 |
| void [OH_Drawing_SetTypographyTextLineStyleSpacingScale](#oh_drawing_settypographytextlinestylespacingscale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, double) | 设置文本排版行样式间距比例。 |
| void [OH_Drawing_SetTypographyTextLineStyleOnly](#oh_drawing_settypographytextlinestyleonly) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, bool) | 设置文本排版是否仅启用行样式。 |
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow) (void) | 创建指向字体阴影对象的指针。不再需要[OH_Drawing_TextShadow](#oh_drawing_textshadow)时，请使用[OH_Drawing_DestroyTextShadow](#oh_drawing_destroytextshadow)接口释放该对象的指针。 |
| void [OH_Drawing_DestroyTextShadow](#oh_drawing_destroytextshadow) ([OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | 释放被字体阴影对象占据的内存。 |
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadows](#oh_drawing_textstylegetshadows) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取字体阴影容器。不再需要[OH_Drawing_TextShadow](#oh_drawing_textshadow)时，请使用[OH_Drawing_DestroyTextShadows](#oh_drawing_destroytextshadows)接口释放该对象的指针。 |
| int [OH_Drawing_TextStyleGetShadowCount](#oh_drawing_textstylegetshadowcount) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取字体阴影容器的大小。 |
| void [OH_Drawing_TextStyleAddShadow](#oh_drawing_textstyleaddshadow) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const [OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | 字体阴影容器中添加字体阴影元素。 |
| void [OH_Drawing_TextStyleClearShadows](#oh_drawing_textstyleclearshadows) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 清除字体阴影容器中的所有元素。 |
| [OH_Drawing_TextShadow](#oh_drawing_textshadow) \* [OH_Drawing_TextStyleGetShadowWithIndex](#oh_drawing_textstylegetshadowwithindex) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | 根据下标获取字体阴影容器中的元素。 |
| void [OH_Drawing_TypographySetIndents](#oh_drawing_typographysetindents) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, const float indents[]) | 设置文本的排版缩进，不调用此接口默认文本无缩进。 |
| float [OH_Drawing_TypographyGetIndentsWithIndex](#oh_drawing_typographygetindentswithindex) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int) | 根据行索引获取排版对象缩进容器中的元素，行索引从0开始。 |
| [OH_Drawing_Range](#oh_drawing_range) \* [OH_Drawing_TypographyGetLineTextRange](#oh_drawing_typographygetlinetextrange) ([OH_Drawing_Typography](#oh_drawing_typography) \*, int, bool) | 获取排版对象中行的边界，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。该接口只能获取已有行的边界，即输入行索引从0开始，最大行索引为[OH_Drawing_TypographyGetLineCount](#oh_drawing_typographygetlinecount) - 1。 |
| void [OH_Drawing_DestroyTextShadows](#oh_drawing_destroytextshadows) ([OH_Drawing_TextShadow](#oh_drawing_textshadow) \*) | 释放由被字体阴影对象OH_Drawing_TextShadow构成的vector占据的内存。 |
| [OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) \* [OH_Drawing_GetSystemFontConfigInfo](#oh_drawing_getsystemfontconfiginfo) ([OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode) \*) | 获取系统字体配置信息。 |
| void [OH_Drawing_DestroySystemFontConfigInfo](#oh_drawing_destroysystemfontconfiginfo) ([OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md) \*) | 释放系统字体配置信息占用的的内存。 |
| void [OH_Drawing_SetTextStyleFontStyleStruct](#oh_drawing_settextstylefontstylestruct) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*drawingTextStyle, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyle) | 设置文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。 |
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_TextStyleGetFontStyleStruct](#oh_drawing_textstylegetfontstylestruct) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*drawingTextStyle) | 获取文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。 |
| void [OH_Drawing_SetTypographyStyleFontStyleStruct](#oh_drawing_settypographystylefontstylestruct) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*drawingStyle, [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) fontStyle) | 设置排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。 |
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) [OH_Drawing_TypographyStyleGetFontStyleStruct](#oh_drawing_typographystylegetfontstylestruct) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*drawingStyle) | 获取排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。 |
| void [OH_Drawing_TextStyleSetBackgroundRect](#oh_drawing_textstylesetbackgroundrect) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) \*, int styleId) | 设置文本背景矩形框和样式id。样式id仅当背景框为圆角矩形时有效。 |
| void [OH_Drawing_TypographyHandlerAddSymbol](#oh_drawing_typographyhandleraddsymbol) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, uint32_t symbol) | 设置排版创建过程中的符号。 |
| void [OH_Drawing_TextStyleAddFontFeature](#oh_drawing_textstyleaddfontfeature) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*tag, int value) | 设置文本样式中指定字体特征是否启用。 |
| void [OH_Drawing_TextStyleAddFontVariation](#oh_drawing_textstyleaddfontvariation) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*, const float) | 添加可变字体属性。对应的字体文件（.ttf文件）需要支持可变调节，此接口才能生效。当对应的字体不支持可变调节时，此接口调用不生效。 |
| [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) \* [OH_Drawing_TextStyleGetFontFeatures](#oh_drawing_textstylegetfontfeatures) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式的字体特征map容器中所有内容。 |
| void [OH_Drawing_TextStyleDestroyFontFeatures](#oh_drawing_textstyledestroyfontfeatures) ([OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) \*, size_t fontFeatureSize) | 释放存放字体特征所有内容的结构体数组所占用的空间。 |
| size_t [OH_Drawing_TextStyleGetFontFeatureSize](#oh_drawing_textstylegetfontfeaturesize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式中字体特征map容器的大小。 |
| void [OH_Drawing_TextStyleClearFontFeature](#oh_drawing_textstyleclearfontfeature) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 清除指定文本样式的字体特征map容器中所有内容。 |
| double [OH_Drawing_TextStyleGetBaselineShift](#oh_drawing_textstylegetbaselineshift) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取文本的基线偏移。 |
| void [OH_Drawing_TextStyleSetBaselineShift](#oh_drawing_textstylesetbaselineshift) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double lineShift) | 设置文本样式基线偏移。 |
| void [OH_Drawing_TypographyTextSetHeightBehavior](#oh_drawing_typographytextsetheightbehavior) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) heightMode) | 设置文本高度修饰符模式。 |
| [OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior) [OH_Drawing_TypographyTextGetHeightBehavior](#oh_drawing_typographytextgetheightbehavior) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本高度修饰符模式。 |
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \* [OH_Drawing_TypographyGetLineFontMetrics](#oh_drawing_typographygetlinefontmetrics) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t lineNumber, size_t \*fontMetricsSize) | 从排版对象中目标行获取所有字体度量信息，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用，否则会返回空指针。不再需要[OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)时，请使用[OH_Drawing_TypographyDestroyLineFontMetrics](#oh_drawing_typographydestroylinefontmetrics)接口释放该对象的指针。 |
| void [OH_Drawing_TypographyDestroyLineFontMetrics](#oh_drawing_typographydestroylinefontmetrics) ([OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | 释放指定行所有字体度量结构体集合所占用的所有空间。 |
| bool [OH_Drawing_TextStyleIsEqual](#oh_drawing_textstyleisequal) (const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*comparedStyle) | 判断两个文本样式对象是否相等，字宽属性不参与对比。 |
| bool [OH_Drawing_TextStyleIsEqualByFont](#oh_drawing_textstyleisequalbyfont) (const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*comparedStyle) | 判断两个文本样式对象的字体样式属性是否相等。 |
| bool [OH_Drawing_TextStyleIsAttributeMatched](#oh_drawing_textstyleisattributematched) (const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style, const [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*comparedStyle, [OH_Drawing_TextStyleType](#oh_drawing_textstyletype) textStyleType) | 判断两个文本样式对象是否有一样的文本样式类型。 |
| void [OH_Drawing_TextStyleSetPlaceholder](#oh_drawing_textstylesetplaceholder) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style) | 设置占位符。 |
| bool [OH_Drawing_TextStyleIsPlaceholder](#oh_drawing_textstyleisplaceholder) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*style) | 返回是否有设置文本占位符。 |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) [OH_Drawing_TypographyStyleGetEffectiveAlignment](#oh_drawing_typographystylegeteffectivealignment) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | 获取文本对齐模式。 |
| bool [OH_Drawing_TypographyStyleIsHintEnabled](#oh_drawing_typographystyleishintenabled) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style) | 获取文本是否启用字形轮廓自动调整，字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。 |
| void [OH_Drawing_SetTypographyStyleTextStrutStyle](#oh_drawing_settypographystyletextstrutstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*) | 设置文本支柱样式。 |
| [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \* [OH_Drawing_TypographyStyleGetStrutStyle](#oh_drawing_typographystylegetstrutstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本支柱样式。 |
| void [OH_Drawing_TypographyStyleDestroyStrutStyle](#oh_drawing_typographystyledestroystrutstyle) ([OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*) | 释放被支柱样式对象占据的内存。 |
| bool [OH_Drawing_TypographyStyleStrutStyleEquals](#oh_drawing_typographystylestrutstyleequals) ([OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*from, [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) \*to) | 判断支柱样式结构体是否相同。 |
| void [OH_Drawing_TypographyStyleSetHintsEnabled](#oh_drawing_typographystylesethintsenabled) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*style, bool hintsEnabled) | 设置文本是否启用字形轮廓自动调整，字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。 |
| void [OH_Drawing_TypographyMarkDirty](#oh_drawing_typographymarkdirty) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 将排版标记为脏数据，用于初始化排版状态。 |
| int32_t [OH_Drawing_TypographyGetUnresolvedGlyphsCount](#oh_drawing_typographygetunresolvedglyphscount) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | 获取文本中尚未解析的字形的数量，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用并生效之后调用。 |
| void [OH_Drawing_TypographyUpdateFontSize](#oh_drawing_typographyupdatefontsize) ([OH_Drawing_Typography](#oh_drawing_typography) \*, size_t from, size_t to, float fontSize) | 更新排版对象中的字体大小。 |
| bool [OH_Drawing_TypographyTextGetLineStyle](#oh_drawing_typographytextgetlinestyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本排版是否启用行样式。 |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) [OH_Drawing_TypographyTextlineStyleGetFontWeight](#oh_drawing_typographytextlinestylegetfontweight) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取排版样式中支柱样式字重。 |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) [OH_Drawing_TypographyTextlineStyleGetFontStyle](#oh_drawing_typographytextlinestylegetfontstyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本排版样式中支柱样式的字体样式。 |
| char \*\* [OH_Drawing_TypographyTextlineStyleGetFontFamilies](#oh_drawing_typographytextlinestylegetfontfamilies) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, size_t \*num) | 获取文本排版样式中支柱样式的字体家族名。 |
| void [OH_Drawing_TypographyTextlineStyleDestroyFontFamilies](#oh_drawing_typographytextlinestyledestroyfontfamilies) (char \*\*fontFamilies, size_t fontFamiliesNum) | 释放字体类型占用的内存。 |
| double [OH_Drawing_TypographyTextlineStyleGetFontSize](#oh_drawing_typographytextlinestylegetfontsize) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本排版行样式字号。 |
| double [OH_Drawing_TypographyTextlineStyleGetHeightScale](#oh_drawing_typographytextlinestylegetheightscale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本排版行样式的行高缩放系数。 |
| bool [OH_Drawing_TypographyTextlineStyleGetHeightOnly](#oh_drawing_typographytextlinestylegetheightonly) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取字体渲染过程中计算字体块高度相关参数的方法。 |
| bool [OH_Drawing_TypographyTextlineStyleGetHalfLeading](#oh_drawing_typographytextlinestylegethalfleading) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本排版行样式是否为一半行间距。 |
| double [OH_Drawing_TypographyTextlineStyleGetSpacingScale](#oh_drawing_typographytextlinestylegetspacingscale) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本排版行样式间距比例。 |
| bool [OH_Drawing_TypographyTextlineGetStyleOnly](#oh_drawing_typographytextlinegetstyleonly) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本排版是否仅启用行样式。 |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) [OH_Drawing_TypographyGetTextAlign](#oh_drawing_typographygettextalign) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本对齐方式。 |
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) [OH_Drawing_TypographyGetTextDirection](#oh_drawing_typographygettextdirection) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取指定排版样式中的文本方向。 |
| size_t [OH_Drawing_TypographyGetTextMaxLines](#oh_drawing_typographygettextmaxlines) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取文本的最大行数。 |
| char \* [OH_Drawing_TypographyGetTextEllipsis](#oh_drawing_typographygettextellipsis) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | 获取指定排版样式设置的省略号文本。 |
| void [OH_Drawing_TypographyDestroyEllipsis](#oh_drawing_typographydestroyellipsis) (char \*ellipsis) | 释放省略号名称列表占用的内存。 |
| bool [OH_Drawing_TypographyStyleEquals](#oh_drawing_typographystyleequals) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*from, [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*to) | 判断排版样式是否相同，当前文本高度修饰符模式[OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior)没有被纳入比较。 |
| uint32_t [OH_Drawing_TextStyleGetColor](#oh_drawing_textstylegetcolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取文本颜色。 |
| [OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle) [OH_Drawing_TextStyleGetDecorationStyle](#oh_drawing_textstylegetdecorationstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取文本装饰样式。 |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) [OH_Drawing_TextStyleGetFontWeight](#oh_drawing_textstylegetfontweight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式字重。 |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) [OH_Drawing_TextStyleGetFontStyle](#oh_drawing_textstylegetfontstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式的字体样式。 |
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) [OH_Drawing_TextStyleGetBaseline](#oh_drawing_textstylegetbaseline) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式的字体基线位置。 |
| char \*\* [OH_Drawing_TextStyleGetFontFamilies](#oh_drawing_textstylegetfontfamilies) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, size_t \*num) | 获取字体类型名称列表。 |
| void [OH_Drawing_TextStyleDestroyFontFamilies](#oh_drawing_textstyledestroyfontfamilies) (char \*\*fontFamilies, size_t num) | 释放长度为num的字体家族名称列表占用的内存。|
| double [OH_Drawing_TextStyleGetFontSize](#oh_drawing_textstylegetfontsize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式字号。 |
| double [OH_Drawing_TextStyleGetLetterSpacing](#oh_drawing_textstylegetletterspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式的字符间距。 |
| double [OH_Drawing_TextStyleGetWordSpacing](#oh_drawing_textstylegetwordspacing) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式的单词间距。 |
| double [OH_Drawing_TextStyleGetFontHeight](#oh_drawing_textstylegetfontheight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式行高缩放系数。 |
| bool [OH_Drawing_TextStyleGetHalfLeading](#oh_drawing_textstylegethalfleading) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取指定文本样式一半行间距设置开启状态。 |
| const char \* [OH_Drawing_TextStyleGetLocale](#oh_drawing_textstylegetlocale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | 获取语言环境。 |
| void [OH_Drawing_TypographyDestroyTextBox](#oh_drawing_typographydestroytextbox) ([OH_Drawing_TextBox](#oh_drawing_textbox) \*) | 释放文本框占用的内存。 |
| void [OH_Drawing_SetTextShadow](#oh_drawing_settextshadow) ([OH_Drawing_TextShadow](#oh_drawing_textshadow) \*shadow, uint32_t color, [OH_Drawing_Point](#oh_drawing_point) \*offset, double blurRadius) | 设置字体阴影对象的参数。 |
| [OH_Drawing_LineTypography](#oh_drawing_linetypography) \* [OH_Drawing_CreateLineTypography](#oh_drawing_createlinetypography) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*handler) | 创建一个排版行对象[OH_Drawing_LineTypography](#oh_drawing_linetypography)的指针，排版行对象保存着文本内容以及样式的载体， 可以用于计算单行排版信息。 |
| void [OH_Drawing_DestroyLineTypography](#oh_drawing_destroylinetypography) ([OH_Drawing_LineTypography](#oh_drawing_linetypography) \*lineTypography) | 释放排版行对象[OH_Drawing_LineTypography](#oh_drawing_linetypography)占用的内存。 |
| size_t [OH_Drawing_LineTypographyGetLineBreak](#oh_drawing_linetypographygetlinebreak) ([OH_Drawing_LineTypography](#oh_drawing_linetypography) \*lineTypography, size_t startIndex, double width) | 计算在限定排版宽度的情况下，从指定位置处开始可以排版的字符个数。 |
| OH_Drawing_TextLine \* [OH_Drawing_LineTypographyCreateLine](#oh_drawing_linetypographycreateline) ([OH_Drawing_LineTypography](#oh_drawing_linetypography) \*lineTypography, size_t startIndex, size_t count) | 根据指定区间文本内容创建一个指向文本行对象**OH_Drawing_TextLine**的指针。 |
| [OH_Drawing_TextTab](#oh_drawing_texttab) \* [OH_Drawing_CreateTextTab](#oh_drawing_createtexttab) ([OH_Drawing_TextAlign](#oh_drawing_textalign) alignment, float location) | 创建文本制表符对象。 |
| void [OH_Drawing_DestroyTextTab](#oh_drawing_destroytexttab) ([OH_Drawing_TextTab](#oh_drawing_texttab) \*) | 释放文本制表符对象占据的内存。 |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) [OH_Drawing_GetTextTabAlignment](#oh_drawing_gettexttabalignment) ([OH_Drawing_TextTab](#oh_drawing_texttab) \*) | 获取文本制表符对象的对齐方式。 |
| float [OH_Drawing_GetTextTabLocation](#oh_drawing_gettexttablocation) ([OH_Drawing_TextTab](#oh_drawing_texttab) \*) | 获取文本制表符的位置。 |
| void [OH_Drawing_SetTypographyTextTab](#oh_drawing_settypographytexttab) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_TextTab](#oh_drawing_texttab) \*TextTab) | 设置文本制表符对齐方式及位置。当设置了文本对齐方式或者省略号风格时制表符不生效，当制表符位置小于1.0时为替换成空格的效果。 |
| size_t [OH_Drawing_GetDrawingArraySize](#oh_drawing_getdrawingarraysize) ([OH_Drawing_Array](#oh_drawing_array) \*drawingArray) | 获取传入类型为对象数组[OH_Drawing_Array](#oh_drawing_array)中的对象个数。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateDefault](#oh_drawing_typefacecreatedefault) (void) | 用于创建一个默认的字形对象。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFile](#oh_drawing_typefacecreatefromfile) (const char \*path, int index) | 通过文件创建一个字形对象。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromFileWithArguments](#oh_drawing_typefacecreatefromfilewitharguments) (const char \*path, const [OH_Drawing_FontArguments](#oh_drawing_fontarguments) \*fontArguments) | 从指定文件路径创建带有字型参数的字体对象。 如果字体对象不支持字型参数中描述的可变维度，此函数将会创建默认字型参数的字体对象。 在这种情况下，此函数将提供与[OH_Drawing_TypefaceCreateFromFile](#oh_drawing_typefacecreatefromfile)相同的功能。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromCurrent](#oh_drawing_typefacecreatefromcurrent) (const [OH_Drawing_Typeface](#oh_drawing_typeface) \*current, const [OH_Drawing_FontArguments](#oh_drawing_fontarguments) \*fontArguments) | 通过已存在的字体对象创建带有字型参数的字体对象。 |
| [OH_Drawing_Typeface](#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateFromStream](#oh_drawing_typefacecreatefromstream) ([OH_Drawing_MemoryStream](#oh_drawing_memorystream) \*, int32_t index) | 通过内存流创建一个字形对象。如果内存流是无效的字体文件，返回空指针。 内存流传入后，所有权转移，开发者不能再释放它。 |
| void [OH_Drawing_TypefaceDestroy](#oh_drawing_typefacedestroy) ([OH_Drawing_Typeface](#oh_drawing_typeface) \*) | 用于销毁字形对象并回收该对象占有的内存。 |
| [OH_Drawing_FontArguments](#oh_drawing_fontarguments) \* [OH_Drawing_FontArgumentsCreate](#oh_drawing_fontargumentscreate) (void) | 用于创建一个字型参数对象。字型参数用于创建带有自定义属性的字体对象。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontArgumentsAddVariation](#oh_drawing_fontargumentsaddvariation) ([OH_Drawing_FontArguments](#oh_drawing_fontarguments) \*fontArguments, const char \*axis, float value) | 给字型参数对象添加可变维度。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_FontArgumentsDestroy](#oh_drawing_fontargumentsdestroy) ([OH_Drawing_FontArguments](#oh_drawing_fontarguments) \*fontArguments) | 用于销毁一个字型参数对象。 |
| enum&nbsp;&nbsp;[OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) { SHADOW_FLAGS_NONE, SHADOW_FLAGS_TRANSPARENT_OCCLUDER, SHADOW_FLAGS_GEOMETRIC_ONLY, SHADOW_FLAGS_ALL } | 阴影标志枚举。 |
| typedef enum [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) | 阴影标志枚举。 |
| void [OH_Drawing_CanvasClipRect](#oh_drawing_canvascliprect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Rect](#oh_drawing_rect) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个矩形。 |
| void [OH_Drawing_CanvasClipRoundRect](#oh_drawing_canvascliproundrect) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_RoundRect](#oh_drawing_roundrect) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个圆角矩形。 |
| void [OH_Drawing_CanvasClipPath](#oh_drawing_canvasclippath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp, bool doAntiAlias) | 用于裁剪一个自定义路径。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasClipRegion](#oh_drawing_canvasclipregion) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, const [OH_Drawing_Region](#oh_drawing_region) \*region, [OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop) clipOp) | 用于裁剪一个区域。 |
| void [OH_Drawing_CanvasRotate](#oh_drawing_canvasrotate) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float degrees, float px, float py) | 用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。 |
| void [OH_Drawing_CanvasTranslate](#oh_drawing_canvastranslate) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float dx, float dy) | 用于平移画布一段距离。 |
| void [OH_Drawing_CanvasScale](#oh_drawing_canvasscale) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float sx, float sy) | 用于画布缩放。 |
| void [OH_Drawing_CanvasSkew](#oh_drawing_canvasskew) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float sx, float sy) | 用于画布倾斜变换。等同于将当前画布矩阵左乘（premultiply）倾斜变换矩阵，并应用到画布上。其中倾斜变换矩阵为： \|1 sx 0\| \|sy 1 0\| \|0 0 1\|。 |
| void [OH_Drawing_CanvasClear](#oh_drawing_canvasclear) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t color) | 用于使用指定颜色去清空画布。 |
| int32_t [OH_Drawing_CanvasGetWidth](#oh_drawing_canvasgetwidth) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 获取画布宽度。 |
| int32_t [OH_Drawing_CanvasGetHeight](#oh_drawing_canvasgetheight) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | 获取画布高度。 |
| void [OH_Drawing_CanvasGetLocalClipBounds](#oh_drawing_canvasgetlocalclipbounds) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Rect](#oh_drawing_rect) \*) | 获取画布裁剪区域的边界。该接口不可用于录制类型画布。 |
| void [OH_Drawing_CanvasGetTotalMatrix](#oh_drawing_canvasgettotalmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 获取画布3x3矩阵。 |
| void [OH_Drawing_CanvasConcatMatrix](#oh_drawing_canvasconcatmatrix) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Matrix](#oh_drawing_matrix) \*) | 画布现有矩阵左乘以传入矩阵，不影响该接口之前的绘制操作。 |
| void [OH_Drawing_CanvasDrawShadow](#oh_drawing_canvasdrawshadow) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Path](#oh_drawing_path) \*, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) planeParams, [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor, [OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags) flag) | 绘制射灯类型阴影，使用路径描述环境光阴影的轮廓。 |
| [OH_Drawing_ErrorCode](#oh_drawing_errorcode) [OH_Drawing_CanvasDrawRecordCmd](#oh_drawing_canvasdrawrecordcmd) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*canvas, [OH_Drawing_RecordCmd](#oh_drawing_recordcmd) \*recordCmd) | 用于绘制录制指令对象。 |

## 类型定义说明

### OH_Drawing_PathDashStyle

```
typedef enum OH_Drawing_PathDashStyle OH_Drawing_PathDashStyle
```

**描述**

路径效果的绘制样式枚举。

**起始版本：** 18

### OH_Drawing_Array

```
typedef struct OH_Drawing_Array OH_Drawing_Array
```

**描述**

定义数组对象, 用于存储多个同类型对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

### OH_Drawing_LineTypography

```
typedef struct OH_Drawing_LineTypography OH_Drawing_LineTypography
```

**描述**

用于从一段文字中提取单行数据进行排版。

**起始版本：** 18

### OH_Drawing_TextTab

```
typedef struct OH_Drawing_TextTab OH_Drawing_TextTab
```

**描述**

用于管理文本制表符。

**起始版本：** 18

### OH_Drawing_TextLine

```
typedef struct OH_Drawing_TextLine OH_Drawing_TextLine
```

**描述**

用于管理文本行。

**起始版本：** 18

### OH_Drawing_Run

```
typedef struct OH_Drawing_RunOH_Drawing_Run
```

**描述**

用于管理文本渲染单元。

**起始版本：** 18

### Drawing_CaretOffsetsCallback

```
typedef bool(* Drawing_CaretOffsetsCallback) (double offset, int32_t index, bool leadingEdge)
```

**描述**

用户自定义的回调函数。将文本行对象中每个字符的偏移量、索引值作为参数传递给用户自定义的回调函数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| offset | 文本行对象中每个字符的偏移量。 |
| index | 文本行对象中每个字符的索引值。 |
| leadingEdge | 光标是否位于字符的前缘，true表示位于字符前缘，即偏移量不包含该字符宽度，false表示位于字符后缘，即偏移量包含该字符宽度。 |

**返回：**

表示是否停止调用该回调函数，true表示停止调用该回调函数，false表示继续调用该回调函数。

### OH_Drawing_String

```
typedef struct OH_Drawing_String OH_Drawing_String
```

**描述**

采用UTF-16编码的字符串信息结构体。

**起始版本：** 14


### OH_Drawing_SystemFontType

```
typedef enum OH_Drawing_SystemFontType OH_Drawing_SystemFontType
```

**描述**

字体类型的枚举。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14


### OH_Drawing_FontArguments

```
typedef struct OH_Drawing_FontArguments OH_Drawing_FontArguments
```

**描述**

用于描述字型参数。

**起始版本：** 13

### OH_Drawing_RecordCmd

```
typedef struct OH_Drawing_RecordCmd OH_Drawing_RecordCmd
```

**描述**

定义录制指令类, 用于存储录制指令的集合。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13


### OH_Drawing_RecordCmdUtils

```
typedef struct OH_Drawing_RecordCmdUtils OH_Drawing_RecordCmdUtils
```

**描述**

定义指令录制工具，用于生成录制指令。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13


### OH_Drawing_ErrorCode

```
typedef enum OH_Drawing_ErrorCode OH_Drawing_ErrorCode
```


**描述**

枚举本模块可能产生的错误码。

**起始版本：** 12


### OH_Drawing_PathOpMode

```
typedef enum OH_Drawing_PathOpMode OH_Drawing_PathOpMode
```

**描述**

路径操作类型枚举。

**起始版本：** 12


### OH_Drawing_PathMeasureMatrixFlags

```
typedef enum OH_Drawing_PathMeasureMatrixFlags OH_Drawing_PathMeasureMatrixFlags
```

**描述**

路径测量获取相应矩阵信息维度枚举。

**起始版本：** 12


### OH_Drawing_RegionOpMode

```
typedef enum OH_Drawing_RegionOpMode OH_Drawing_RegionOpMode
```

**描述**

区域操作类型枚举。

**起始版本：** 12


### OH_Drawing_ImageFilter

```
typedef struct OH_Drawing_ImageFilter OH_Drawing_ImageFilter
```

**描述**

定义图像滤波器, 用于对构成图像像素的所有颜色位进行操作。

**起始版本：** 12


### OH_Drawing_Filter

```
typedef struct OH_Drawing_Filter OH_Drawing_Filter
```

**描述**

定义一个滤波器，用于存储颜色滤波器，蒙版滤波器和图像滤波器。

**起始版本：** 11

### OH_Drawing_AlphaFormat

```
typedef enum OH_Drawing_AlphaFormat OH_Drawing_AlphaFormat
```

**描述**

用于描述位图像素的透明度分量。

**起始版本：** 8


### OH_Drawing_Bitmap

```
typedef struct OH_Drawing_Bitmap OH_Drawing_Bitmap
```

**描述**

定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据。

**起始版本：** 8


### OH_Drawing_BitmapFormat

```
typedef struct OH_Drawing_BitmapFormat OH_Drawing_BitmapFormat
```

**描述**

结构体用于描述位图像素的格式，包括颜色类型和透明度类型。

**起始版本：** 8


### OH_Drawing_BlendMode

```
typedef enum OH_Drawing_BlendMode OH_Drawing_BlendMode
```

**描述**

混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在红、绿、蓝3个颜色通道上是相同的（透明度有另外的处理规则）。 对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。

为简洁起见，我们使用以下缩写：

s : source，源的缩写。

d : destination，目标的缩写。

sa : source alpha，源透明度的缩写。

da : destination alpha，目标透明度的缩写。

计算结果用如下缩写表示：

r : 如果4个通道的计算方式相同，用r表示。

ra : 如果只操作透明度通道，用ra表示。

rc : 如果操作3个颜色通道，用rc表示。

**起始版本：** 11


### OH_Drawing_BlurType

```
typedef enum OH_Drawing_BlurType OH_Drawing_BlurType
```

**描述**

蒙版滤波器模糊操作类型的枚举。

**起始版本：** 11


### OH_Drawing_BreakStrategy

```
typedef enum OH_Drawing_BreakStrategy OH_Drawing_BreakStrategy
```

**描述**

文本的中断策略枚举。

**起始版本：** 11


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


### OH_Drawing_CanvasClipOp

```
typedef enum OH_Drawing_CanvasClipOp OH_Drawing_CanvasClipOp
```

**描述**

画布裁剪方式的枚举集合。

**起始版本：** 11


### OH_Drawing_CanvasShadowFlags

```
typedef enum OH_Drawing_CanvasShadowFlags OH_Drawing_CanvasShadowFlags
```

**描述**

阴影标志枚举。

**起始版本：** 12


### OH_Drawing_ColorFilter

```
typedef struct OH_Drawing_ColorFilter OH_Drawing_ColorFilter
```

**描述**

定义颜色滤波器，传入一个颜色并返回一个新的颜色。

**起始版本：** 11


### OH_Drawing_ColorFormat

```
typedef enum OH_Drawing_ColorFormat OH_Drawing_ColorFormat
```

**描述**

用于描述位图像素的存储格式。

**起始版本：** 8


### OH_Drawing_ColorSpace

```
typedef struct OH_Drawing_ColorSpace OH_Drawing_ColorSpace
```

**描述**

定义色彩空间，用于解释颜色信息。

**起始版本：** 12


### OH_Drawing_Corner_Radii

```
typedef OH_Drawing_Point2D OH_Drawing_Corner_Radii
```

**描述**

定义一个圆角半径，该圆角半径由x轴方向和y轴方向上的半径组成。

**起始版本：** 12


### OH_Drawing_CornerPos

```
typedef enum OH_Drawing_CornerPos OH_Drawing_CornerPos
```

**描述**

用于描述圆角位置的枚举。

**起始版本：** 12


### OH_Drawing_EllipsisModal

```
typedef enum OH_Drawing_EllipsisModal OH_Drawing_EllipsisModal
```

**描述**

省略号样式枚举。

**起始版本：** 11


### OH_Drawing_FilterMode

```
typedef enum OH_Drawing_FilterMode OH_Drawing_FilterMode
```

**描述**

过滤模式枚举。

**起始版本：** 12


### OH_Drawing_Font

```
typedef struct OH_Drawing_Font OH_Drawing_Font
```

**描述**

用于描述字体。

**起始版本：** 11


### OH_Drawing_Font_Metrics

```
typedef struct OH_Drawing_Font_Metrics OH_Drawing_Font_Metrics
```

**描述**

定义字体度量信息的结构体。

**起始版本：** 12


### OH_Drawing_FontAdjustInfo

```
typedef struct OH_Drawing_FontAdjustInfo OH_Drawing_FontAdjustInfo
```

**描述**

字重映射信息结构体。

**起始版本：** 12


### OH_Drawing_FontAliasInfo

```
typedef struct OH_Drawing_FontAliasInfo OH_Drawing_FontAliasInfo
```

**描述**

别名字体信息结构体。

**起始版本：** 12


### OH_Drawing_FontCollection

```
typedef struct OH_Drawing_FontCollection OH_Drawing_FontCollection
```

**描述**

用于加载字体。

**起始版本：** 8


### OH_Drawing_FontConfigInfo

```
typedef struct OH_Drawing_FontConfigInfo OH_Drawing_FontConfigInfo
```

**描述**

系统字体配置信息结构体。

**起始版本：** 12


### OH_Drawing_FontDescriptor

```
typedef struct OH_Drawing_FontDescriptor OH_Drawing_FontDescriptor
```

**描述**

描述系统字体详细信息的结构体。

**起始版本：** 12


### OH_Drawing_FontEdging

```
typedef enum OH_Drawing_FontEdging OH_Drawing_FontEdging
```

**描述**

字型边缘效果类型枚举。

**起始版本：** 12


### OH_Drawing_FontFallbackGroup

```
typedef struct OH_Drawing_FontFallbackGroup OH_Drawing_FontFallbackGroup
```

**描述**

备用字体集信息结构体。

**起始版本：** 12


### OH_Drawing_FontFallbackInfo

```
typedef struct OH_Drawing_FontFallbackInfo OH_Drawing_FontFallbackInfo
```

**描述**

备用字体信息结构体。

**起始版本：** 12


### OH_Drawing_FontGenericInfo

```
typedef struct OH_Drawing_FontGenericInfo OH_Drawing_FontGenericInfo
```

**描述**

系统所支持的通用字体集信息结构体。

**起始版本：** 12


### OH_Drawing_FontHinting

```
typedef enum OH_Drawing_FontHinting OH_Drawing_FontHinting
```

**描述**

字型轮廓效果类型枚举。

**起始版本：** 12


### OH_Drawing_FontMgr

```
typedef struct OH_Drawing_FontMgr OH_Drawing_FontMgr
```

**描述**

定义字体管理类, 用于字体管理。

**起始版本：** 12


### OH_Drawing_FontParser

```
typedef struct OH_Drawing_FontParser OH_Drawing_FontParser
```

**描述**

用来解析系统字体文件。

**起始版本：** 12


### OH_Drawing_FontStyleSet

```
typedef struct OH_Drawing_FontStyleSet OH_Drawing_FontStyleSet
```

**描述**

定义字体样式集, 用于字体样式族匹配。

**起始版本：** 12


### OH_Drawing_FontStyleStruct

```
typedef struct OH_Drawing_FontStyleStruct OH_Drawing_FontStyleStruct
```

**描述**

定义字体样式信息的结构体。

**起始版本：** 12


### OH_Drawing_GpuContext

```
typedef struct OH_Drawing_GpuContext OH_Drawing_GpuContext
```

**描述**

定义图形处理器上下文，用于描述图形处理器后端上下文。

**起始版本：** 12


### OH_Drawing_GpuContextOptions

```
typedef struct OH_Drawing_GpuContextOptions OH_Drawing_GpuContextOptions
```

**描述**

定义有关图形处理器上下文的选项。

**起始版本：** 12


### OH_Drawing_Image

```
typedef struct OH_Drawing_Image OH_Drawing_Image
```

**描述**

定义一个用于描述绘制二维像素数组的图片。

**起始版本：** 12


### OH_Drawing_Image_Info

```
typedef struct OH_Drawing_Image_Info OH_Drawing_Image_Info
```

**描述**

定义图片信息结构体。

**起始版本：** 12


### OH_Drawing_LineMetrics

```
typedef struct OH_Drawing_LineMetrics OH_Drawing_LineMetrics
```

**描述**

文字行位置信息。

**起始版本：** 12


### OH_Drawing_MaskFilter

```
typedef struct OH_Drawing_MaskFilter OH_Drawing_MaskFilter
```

**描述**

定义蒙版滤波器。

**起始版本：** 11


### OH_Drawing_Matrix

```
typedef struct OH_Drawing_Matrix OH_Drawing_Matrix
```

**描述**

定义一个矩阵，用于描述坐标变换。

**起始版本：** 11


### OH_Drawing_MemoryStream

```
typedef struct OH_Drawing_MemoryStream OH_Drawing_MemoryStream
```

**描述**

用于描述内存流。

**起始版本：** 12


### OH_Drawing_MipmapMode

```
typedef enum OH_Drawing_MipmapMode OH_Drawing_MipmapMode
```

**描述**

多级渐远纹理模式枚举。

**起始版本：** 12


### OH_Drawing_Path

```
typedef struct OH_Drawing_Path OH_Drawing_Path
```

**描述**

定义为路径，路径用于自定义各种形状。

**起始版本：** 8


### OH_Drawing_PathAddMode

```
typedef enum OH_Drawing_PathAddMode OH_Drawing_PathAddMode
```

**描述**

用于指定路径添加模式的枚举类型。

**起始版本：** 12


### OH_Drawing_PathDirection

```
typedef enum OH_Drawing_PathDirection OH_Drawing_PathDirection
```

**描述**

添加闭合轮廓方向枚举。

**起始版本：** 12


### OH_Drawing_PathEffect

```
typedef struct OH_Drawing_PathEffect OH_Drawing_PathEffect
```

**描述**

定义一个路径效果，用于影响描边路径。

**起始版本：** 12


### OH_Drawing_PathFillType

```
typedef enum OH_Drawing_PathFillType OH_Drawing_PathFillType
```

**描述**

定义路径的填充类型枚举。

**起始版本：** 12


### OH_Drawing_Pen

```
typedef struct OH_Drawing_Pen OH_Drawing_Pen
```

**描述**

定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色。

**起始版本：** 8


### OH_Drawing_PenLineCapStyle

```
typedef enum OH_Drawing_PenLineCapStyle OH_Drawing_PenLineCapStyle
```

**描述**

枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。

**起始版本：** 8


### OH_Drawing_PenLineJoinStyle

```
typedef enum OH_Drawing_PenLineJoinStyle OH_Drawing_PenLineJoinStyle
```

**描述**

枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。

**起始版本：** 8


### OH_Drawing_PixelMap

```
typedef struct OH_Drawing_PixelMap OH_Drawing_PixelMap
```

**描述**

定义像素图，用于包装图像框架支持的真实像素图。

**起始版本：** 12


### OH_Drawing_PlaceholderSpan

```
typedef struct OH_Drawing_PlaceholderSpan OH_Drawing_PlaceholderSpan
```

**描述**

用于描述占位符跨度的结构体。

**起始版本：** 11


### OH_Drawing_PlaceholderVerticalAlignment

```
typedef enum OH_Drawing_PlaceholderVerticalAlignment OH_Drawing_PlaceholderVerticalAlignment
```

**描述**

占位符垂直对齐枚举。

**起始版本：** 11


### OH_Drawing_Point

```
typedef struct OH_Drawing_Point OH_Drawing_Point
```

**描述**

定义一个点，用于描述坐标点。

**起始版本：** 11


### OH_Drawing_Point2D

```
typedef struct OH_Drawing_Point2D OH_Drawing_Point2D
```

**描述**

定义一个二维的坐标点。

**起始版本：** 12


### OH_Drawing_Point3D

```
typedef struct OH_Drawing_Point3D OH_Drawing_Point3D
```

**描述**

定义一个三维的坐标点。

**起始版本：** 12


### OH_Drawing_PointMode

```
typedef enum OH_Drawing_PointMode OH_Drawing_PointMode
```

**描述**

绘制多个点的方式枚举，方式分为离散点、直线或开放多边形。

**起始版本：** 12


### OH_Drawing_PositionAndAffinity

```
typedef struct OH_Drawing_PositionAndAffinity OH_Drawing_PositionAndAffinity
```

**描述**

用于接收字体的位置和亲和性。

**起始版本：** 11


### OH_Drawing_Range

```
typedef struct OH_Drawing_Range OH_Drawing_Range
```

**描述**

用于接收字体的起始位置和结束位置。

**起始版本：** 11


### OH_Drawing_Rect

```
typedef struct OH_Drawing_Rect OH_Drawing_Rect
```

**描述**

用于描述矩形。

**起始版本：** 11


### OH_Drawing_RectHeightStyle

```
typedef enum OH_Drawing_RectHeightStyle OH_Drawing_RectHeightStyle
```

**描述**

矩形框高度样式枚举。

**起始版本：** 11


### OH_Drawing_RectStyle_Info

```
typedef struct OH_Drawing_RectStyle_Info OH_Drawing_RectStyle_Info
```

**描述**

定义矩形框样式结构体。

**起始版本：** 12


### OH_Drawing_RectWidthStyle

```
typedef enum OH_Drawing_RectWidthStyle OH_Drawing_RectWidthStyle
```

**描述**

矩形框宽度样式枚举。

**起始版本：** 11


### OH_Drawing_Region

```
typedef struct OH_Drawing_Region OH_Drawing_Region
```

**描述**

定义一个区域，用于表示画布上的封闭区域，实现更精确的图形控制。

**起始版本：** 12


### OH_Drawing_RoundRect

```
typedef struct OH_Drawing_RoundRect OH_Drawing_RoundRect
```

**描述**

用于描述圆角矩形。

**起始版本：** 11


### OH_Drawing_RunBuffer

```
typedef struct OH_Drawing_RunBuffer OH_Drawing_RunBuffer
```

**描述**

结构体用于描述一块内存，描述文字和位置信息。

**起始版本：** 11


### OH_Drawing_SamplingOptions

```
typedef struct OH_Drawing_SamplingOptions OH_Drawing_SamplingOptions
```

**描述**

定义一个采样选项，用于描述图片、位图等图像的采样方法。

**起始版本：** 12


### OH_Drawing_ScaleToFit

```
typedef enum OH_Drawing_ScaleToFit OH_Drawing_ScaleToFit
```

**描述**

矩阵缩放方式枚举。

**起始版本：** 12


### OH_Drawing_ShaderEffect

```
typedef struct OH_Drawing_ShaderEffect OH_Drawing_ShaderEffect
```

**描述**

定义一个着色器，用于描述绘制内容的源颜色。

**起始版本：** 11


### OH_Drawing_ShadowLayer

```
typedef struct OH_Drawing_ShadowLayer OH_Drawing_ShadowLayer
```

**描述**

定义一个阴影层，用于描述绘制内容的阴影层。

**起始版本：** 12


### OH_Drawing_SrcRectConstraint

```
typedef enum OH_Drawing_SrcRectConstraint OH_Drawing_SrcRectConstraint
```

**描述**

源矩形区域约束类型枚举。

**起始版本：** 12


### OH_Drawing_StrutStyle

```
typedef struct OH_Drawing_StrutStyle OH_Drawing_StrutStyle
```

**描述**

用于描述支柱样式的结构体。支柱样式用于控制绘制文本时行之间的间距、基线对齐方式以及其他与行高相关的属性。

**起始版本：** 12


### OH_Drawing_Surface

```
typedef struct OH_Drawing_Surface OH_Drawing_Surface
```

**描述**

定义surface，用于管理画布绘制的内容。

**起始版本：** 12


### OH_Drawing_TextBlob

```
typedef struct OH_Drawing_TextBlob OH_Drawing_TextBlob
```

**描述**

定义一个文本对象，表示将多个文本组合到一个不可变的容器中。 每个文本行由字形和位置组成。

**起始版本：** 11


### OH_Drawing_TextBlobBuilder

```
typedef struct OH_Drawing_TextBlobBuilder OH_Drawing_TextBlobBuilder
```

**描述**

定义文本构建器，用于构建文本。

**起始版本：** 11


### OH_Drawing_TextBox

```
typedef struct OH_Drawing_TextBox OH_Drawing_TextBox
```

**描述**

用于接收文本框的矩形大小、方向和数量大小。

**起始版本：** 11


### OH_Drawing_TextDecorationStyle

```
typedef enum OH_Drawing_TextDecorationStyle OH_Drawing_TextDecorationStyle
```

**描述**

文本装饰样式枚举。

**起始版本：** 11


### OH_Drawing_TextEncoding

```
typedef enum OH_Drawing_TextEncoding OH_Drawing_TextEncoding
```

**描述**

文本编码类型枚举。

**起始版本：** 12


### OH_Drawing_TextShadow

```
typedef struct OH_Drawing_TextShadow OH_Drawing_TextShadow
```

**描述**

用于管理文本阴影。

**起始版本：** 12


### OH_Drawing_TextStyle

```
typedef struct OH_Drawing_TextStyle OH_Drawing_TextStyle
```

**描述**

用于管理字体颜色、装饰等。

**起始版本：** 8


### OH_Drawing_TileMode

```
typedef enum OH_Drawing_TileMode OH_Drawing_TileMode
```

**描述**

着色器效果平铺模式的枚举。

**起始版本：** 11


### OH_Drawing_Typeface

```
typedef struct OH_Drawing_Typeface OH_Drawing_Typeface
```

**描述**

用于描述字形。

**起始版本：** 11


### OH_Drawing_Typography

```
typedef struct OH_Drawing_Typography OH_Drawing_Typography
```

**描述**

用于管理排版的布局和显示等。

**起始版本：** 8


### OH_Drawing_TypographyCreate

```
typedef struct OH_Drawing_TypographyCreate OH_Drawing_TypographyCreate
```

**描述**

用于创建[OH_Drawing_Typography](#oh_drawing_typography)。

**起始版本：** 8


### OH_Drawing_TypographyStyle

```
typedef struct OH_Drawing_TypographyStyle OH_Drawing_TypographyStyle
```

**描述**

用于管理排版风格，如文字方向等。

**起始版本：** 8


### OH_Drawing_VertexMode

```
typedef enum OH_Drawing_VertexMode OH_Drawing_VertexMode
```

**描述**

用于指定如何解释给定顶点的几何形状的枚举类型。

**起始版本：** 12


### OH_Drawing_WordBreakType

```
typedef enum OH_Drawing_WordBreakType OH_Drawing_WordBreakType
```

**描述**

单词的断词方式枚举。

**起始版本：** 11


## 枚举类型说明

### OH_Drawing_PathDashStyle

```
enum OH_Drawing_PathDashStyle
```

**描述**

路径效果的绘制样式枚举。

**起始版本：** 18

| 枚举值 | 描述 | 
| -------- | -------- |
| DRAWING_PATH_DASH_STYLE_TRANSLATE  | 表示路径效果是平移效果。|
| DRAWING_PATH_DASH_STYLE_ROTATE  | 表示路径效果是旋转效果。|
| DRAWING_PATH_DASH_STYLE_MORPH  | 表示路径效果是变形效果。|

### OH_Drawing_SystemFontType

```
enum OH_Drawing_SystemFontType
```

**描述**

字体类型的枚举。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

| 枚举值 | 描述 |
| -------- | -------- |
| ALL | 所有字体类型。 |
| GENERIC | 系统字体类型。 |
| STYLISH | 风格字体类型。 |
| INSTALLED | 用户已安装字体类型。 |
| CUSTOMIZED<sup>18+</sup> | 自定义字体类型。 |

### OH_Drawing_ErrorCode

```
enum OH_Drawing_ErrorCode
```

**描述**

枚举本模块可能产生的错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_DRAWING_SUCCESS | 操作成功完成。 | 
| OH_DRAWING_ERROR_NO_PERMISSION | 权限校验失败。 | 
| OH_DRAWING_ERROR_INVALID_PARAMETER | 无效的输入参数，如参数中传入了NULL。 | 
| OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE | 输入参数不在有效的范围内。 | 
| OH_DRAWING_ERROR_ALLOCATION_FAILED<sup>13+</sup> | 内存分配失败。 | 

### OH_Drawing_PathMeasureMatrixFlags

```
enum OH_Drawing_PathMeasureMatrixFlags
```

**描述**

路径测量获取相应矩阵信息维度枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| GET_POSITION_MATRIX | 获取位置信息对应的矩阵。 | 
| GET_TANGENT_MATRIX | 获取切线信息对应的矩阵。 | 
| GET_POSITION_AND_TANGENT_MATRIX | 获取位置和切线信息对应的矩阵。 | 


### OH_Drawing_PathOpMode

```
enum OH_Drawing_PathOpMode
```

**描述**

路径操作类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PATH_OP_MODE_DIFFERENCE | 差集操作。 | 
| PATH_OP_MODE_INTERSECT | 交集操作。 | 
| PATH_OP_MODE_UNION | 并集操作。 | 
| PATH_OP_MODE_XOR | 异或操作。 | 
| PATH_OP_MODE_REVERSE_DIFFERENCE | 反向差集操作。 | 


### OH_Drawing_RegionOpMode

```
enum OH_Drawing_RegionOpMode
```

**描述**

区域操作类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| REGION_OP_MODE_DIFFERENCE | 差集操作。 | 
| REGION_OP_MODE_INTERSECT | 交集操作。 | 
| REGION_OP_MODE_UNION | 并集操作。 | 
| REGION_OP_MODE_XOR | 异或操作。 | 
| REGION_OP_MODE_REVERSE_DIFFERENCE | 反向差集操作。 | 
| REGION_OP_MODE_REPLACE | 替换操作。 | 


### OH_Drawing_AlphaFormat

```
enum OH_Drawing_AlphaFormat
```

**描述**

用于描述位图像素的透明度分量。

**起始版本：** 8

| 枚举值 | 描述 | 
| -------- | -------- |
| ALPHA_FORMAT_UNKNOWN | 未知格式。 | 
| ALPHA_FORMAT_OPAQUE | 位图无透明度。 | 
| ALPHA_FORMAT_PREMUL | 每个像素的颜色组件由透明度分量预先乘以。 | 
| ALPHA_FORMAT_UNPREMUL | 每个像素的颜色组件未由透明度分量预先乘以。 | 


### OH_Drawing_BlendMode

```
enum OH_Drawing_BlendMode
```

**描述**

混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在红、绿、蓝3个颜色通道上是相同的（透明度有另外的处理规则）。 对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。

为简洁起见，我们使用以下缩写：

s : source，源的缩写。

d : destination，目标的缩写。

sa : source alpha，源透明度的缩写。

da : destination alpha，目标透明度的缩写。

计算结果用如下缩写表示：

r : 如果4个通道的计算方式相同，用r表示。

ra : 如果只操作透明度通道，用ra表示。

rc : 如果操作3个颜色通道，用rc表示。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| BLEND_MODE_CLEAR | 清除模式，r = 0. | 
| BLEND_MODE_SRC | r = s（result的4个通道，都等于source的4个通道，即结果等于源。） | 
| BLEND_MODE_DST | r = d（result的4个通道，都等于destination的4个通道，即结果等于目标。） | 
| BLEND_MODE_SRC_OVER | r = s + (1 - sa) \* d. | 
| BLEND_MODE_DST_OVER | r = d + (1 - da) \* s. | 
| BLEND_MODE_SRC_IN | r = s \* da. | 
| BLEND_MODE_DST_IN | r = d \* sa. | 
| BLEND_MODE_SRC_OUT | r = s \* (1 - da). | 
| BLEND_MODE_DST_OUT | r = d \* (1 - sa). | 
| BLEND_MODE_SRC_ATOP | r = s \* da + d \* (1 - sa). | 
| BLEND_MODE_DST_ATOP | r = d \* sa + s \* (1 - da). | 
| BLEND_MODE_XOR | r = s \* (1 - da) + d \* (1 - sa). | 
| BLEND_MODE_PLUS | r = min(s + d, 1). | 
| BLEND_MODE_MODULATE | r = s \* d. | 
| BLEND_MODE_SCREEN | 滤色模式，r = s + d - s \* d. | 
| BLEND_MODE_OVERLAY | 叠加模式。 | 
| BLEND_MODE_DARKEN | 变暗模式，rc = s + d - max(s \* da, d \* sa), ra = s + (1 - sa) \* d. | 
| BLEND_MODE_LIGHTEN | 变亮模式，rc = s + d - min(s \* da, d \* sa), ra = s + (1 - sa) \* d. | 
| BLEND_MODE_COLOR_DODGE | 颜色减淡模式。 | 
| BLEND_MODE_COLOR_BURN | 颜色加深模式。 | 
| BLEND_MODE_HARD_LIGHT | 强光模式。 | 
| BLEND_MODE_SOFT_LIGHT | 柔光模式。 | 
| BLEND_MODE_DIFFERENCE | 差值模式，rc = s + d - 2 \* (min(s \* da, d \* sa)), ra = s + (1 - sa) \* d. | 
| BLEND_MODE_EXCLUSION | 排除模式，rc = s + d - two(s \* d), ra = s + (1 - sa) \* d. | 
| BLEND_MODE_MULTIPLY | 正片叠底，r = s \* (1 - da) + d \* (1 - sa) + s \* d. | 
| BLEND_MODE_HUE | 色相模式。 | 
| BLEND_MODE_SATURATION | 饱和度模式。 | 
| BLEND_MODE_COLOR | 颜色模式。 | 
| BLEND_MODE_LUMINOSITY | 亮度模式。 | 


### OH_Drawing_BlurType

```
enum OH_Drawing_BlurType
```

**描述**

蒙版滤波器模糊操作类型的枚举。

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

文本的中断策略枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| BREAK_STRATEGY_GREEDY | 贪心策略，换行时尽可能填满每一行。 | 
| BREAK_STRATEGY_HIGH_QUALITY | 高质量策略，换行时优先考虑文本的连续性。 | 
| BREAK_STRATEGY_BALANCED | 平衡策略，换行时在单词边界换行。 | 


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


### OH_Drawing_CanvasShadowFlags

```
enum OH_Drawing_CanvasShadowFlags
```

**描述**

阴影标志枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| SHADOW_FLAGS_NONE | 无阴影标志。 | 
| SHADOW_FLAGS_TRANSPARENT_OCCLUDER | 遮挡物对象不透明标志。 | 
| SHADOW_FLAGS_GEOMETRIC_ONLY | 不分析阴影标志。 | 
| SHADOW_FLAGS_ALL | 使能以上所有阴影标志。 | 


### OH_Drawing_ColorFormat

```
enum OH_Drawing_ColorFormat
```

**描述**

用于描述位图像素的存储格式。

**起始版本：** 8

| 枚举值 | 描述 | 
| -------- | -------- |
| COLOR_FORMAT_UNKNOWN | 未知格式。 | 
| COLOR_FORMAT_ALPHA_8 | 每个像素用一个8位的量表示，8个位比特位表示透明度。 | 
| COLOR_FORMAT_RGB_565 | 每个像素用一个16位的量表示，高位到低位依次是5个比特位表示红，6个比特位表示绿，5个比特位表示蓝。 | 
| COLOR_FORMAT_ARGB_4444 | 每个像素用一个16位的量表示，高位到低位依次是4个比特位表示透明度，4个比特位表示红，4个比特位表示绿，4个比特位表示蓝。 | 
| COLOR_FORMAT_RGBA_8888 | 每个像素用一个32位的量表示，高位到低位依次是8个比特位表示透明度，8个比特位表示红，8个比特位表示绿，8个比特位表示蓝。 | 
| COLOR_FORMAT_BGRA_8888 | 每个像素用一个32位的量表示，高位到低位依次是8个比特位表示蓝，8个比特位表示绿，8个比特位表示红，8个比特位表示透明度。 | 


### OH_Drawing_CornerPos

```
enum OH_Drawing_CornerPos
```

**描述**

用于描述圆角位置的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| CORNER_POS_TOP_LEFT | 左上角圆角位置。 | 
| CORNER_POS_TOP_RIGHT | 右上角圆角位置。 | 
| CORNER_POS_BOTTOM_RIGHT | 右下角圆角位置。 | 
| CORNER_POS_BOTTOM_LEFT | 左下角圆角位置。 | 


### OH_Drawing_EllipsisModal

```
enum OH_Drawing_EllipsisModal
```

**描述**

省略号样式枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| ELLIPSIS_MODAL_HEAD | 头部模式，即省略号放在文本头部。 | 
| ELLIPSIS_MODAL_MIDDLE | 中部模式，即省略号放在文本中部。 | 
| ELLIPSIS_MODAL_TAIL | 尾部模式，即省略号放在文本尾部。 | 


### OH_Drawing_FilterMode

```
enum OH_Drawing_FilterMode
```

**描述**

过滤模式枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| FILTER_MODE_NEAREST | 邻近过滤模式。 | 
| FILTER_MODE_LINEAR | 线性过滤模式。 | 


### OH_Drawing_FontConfigInfoErrorCode

```
enum OH_Drawing_FontConfigInfoErrorCode
```

**描述**

获取系统字体配置信息列表结果枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| SUCCESS_FONT_CONFIG_INFO | 获取系统字体配置信息列表成功。 | 
| ERROR_FONT_CONFIG_INFO_UNKNOWN | 未知错误。 | 
| ERROR_FONT_CONFIG_INFO_PARSE_FILE | 解析系统配置文件失败。 | 
| ERROR_FONT_CONFIG_INFO_ALLOC_MEMORY | 申请内存失败。 | 
| ERROR_FONT_CONFIG_INFO_COPY_STRING_DATA | 拷贝字符串数据失败。 | 


### OH_Drawing_FontEdging

```
enum OH_Drawing_FontEdging
```

**描述**

字型边缘效果类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| FONT_EDGING_ALIAS | 无抗锯齿处理。 | 
| FONT_EDGING_ANTI_ALIAS | 使用抗锯齿来平滑字型边缘。 | 
| FONT_EDGING_SUBPIXEL_ANTI_ALIAS | 使用次像素级别的抗锯齿来平滑字型边缘，可以获得更加平滑的字形渲染效果。 | 


### OH_Drawing_FontHinting

```
enum OH_Drawing_FontHinting
```

**描述**

字型轮廓效果类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| FONT_HINTING_NONE | 不修改字型轮廓。 | 
| FONT_HINTING_SLIGHT | 最小限度修改字型轮廓以改善对比度。 | 
| FONT_HINTING_NORMAL | 修改字型轮廓以提高对比度。 | 
| FONT_HINTING_FULL | 修改字型轮廓以获得最大对比度。 | 


### OH_Drawing_FontStyle

```
enum OH_Drawing_FontStyle
```

**描述**

区分字体是否为斜体。

| 枚举值 | 描述 | 
| -------- | -------- |
| FONT_STYLE_NORMAL | 非斜体。 | 
| FONT_STYLE_ITALIC | 斜体。 | 
| FONT_STYLE_OBLIQUE | 倾斜字体<br/>自从<br/>12 | 


### OH_Drawing_FontWeight

```
enum OH_Drawing_FontWeight
```

**描述**

字重。

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


### OH_Drawing_FontWidth

```
enum OH_Drawing_FontWidth
```

**描述**

字体宽度的枚举。

**起始版本：** 12


### OH_Drawing_MipmapMode

```
enum OH_Drawing_MipmapMode
```

**描述**

多级渐远纹理模式枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MIPMAP_MODE_NONE | 忽略多级渐远纹理级别。 | 
| MIPMAP_MODE_NEAREST | 邻近多级渐远级别采样。 | 
| MIPMAP_MODE_LINEAR | 两个邻近多级渐远纹理之间，线性插值采样。 | 


### OH_Drawing_PathAddMode

```
enum OH_Drawing_PathAddMode
```

**描述**

用于指定路径添加模式的枚举类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PATH_ADD_MODE_APPEND | 以追加的方式添加路径。 | 
| PATH_ADD_MODE_EXTEND | 如果之前的路径未闭合，则添加直线闭合路径。 | 


### OH_Drawing_PathDirection

```
enum OH_Drawing_PathDirection
```

**描述**

添加闭合轮廓方向枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PATH_DIRECTION_CW | 顺时针方向添加闭合轮廓。 | 
| PATH_DIRECTION_CCW | 逆时针方向添加闭合轮廓。 | 


### OH_Drawing_PathFillType

```
enum OH_Drawing_PathFillType
```

**描述**

定义路径的填充类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PATH_FILL_TYPE_WINDING | 绘制区域中的任意一点，向任意方向射出一条射线，对于射线和路径的所有交点，初始计数为0，遇到每个顺时针的交点（路径从射线的左边向右穿过），计数加1，遇到每个逆时针的交点（路径从射线的右边向左穿过），计数减1，若最终的计数结果为0，则认为这个点在路径内部，需要被涂色；若计数为0则不被涂色。 | 
| PATH_FILL_TYPE_EVEN_ODD | 绘制区域中的任意一点，向任意方向射出一条射线，若这条射线和路径相交的次数是奇数，则这个点被认为在路径内部，需要被涂色；若是偶数则不被涂色。 | 
| PATH_FILL_TYPE_INVERSE_WINDING | PATH_FILL_TYPE_WINDING 涂色规则取反。 | 
| PATH_FILL_TYPE_INVERSE_EVEN_ODD | PATH_FILL_TYPE_EVEN_ODD 涂色规则取反。 | 


### OH_Drawing_PenLineCapStyle

```
enum OH_Drawing_PenLineCapStyle
```

**描述**

枚举集合定义了画笔笔帽的样式，即画笔在绘制线段时，在线段头尾端点的样式。

**起始版本：** 8

| 枚举值 | 描述 | 
| -------- | -------- |
| LINE_FLAT_CAP | 没有笔帽样式，线条头尾端点处横切。 | 
| LINE_SQUARE_CAP | 笔帽的样式为方框，线条的头尾端点处多出一个方框，方框宽度和线段一样宽，高度时线段厚度的一半。 | 
| LINE_ROUND_CAP | 笔帽的样式为圆弧，线条的头尾端点处多出一个半圆弧，半圆的直径与线段厚度一致。 | 


### OH_Drawing_PenLineJoinStyle

```
enum OH_Drawing_PenLineJoinStyle
```

**描述**

枚举集合定义了线条转角的样式，即画笔在绘制折线段时，在折线转角处的样式。

**起始版本：** 8

| 枚举值 | 描述 | 
| -------- | -------- |
| LINE_MITER_JOIN | 转角类型为尖角，如果折线角度比较小，则尖角会很长，需要使用限制值（miter limit）进行限制。 | 
| LINE_ROUND_JOIN | 转角类型为圆头。 | 
| LINE_BEVEL_JOIN | 转角类型为平头。 | 


### OH_Drawing_PlaceholderVerticalAlignment

```
enum OH_Drawing_PlaceholderVerticalAlignment
```

**描述**

占位符垂直对齐枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| ALIGNMENT_OFFSET_AT_BASELINE | 偏移于基线对齐。 | 
| ALIGNMENT_ABOVE_BASELINE | 高于基线对齐。 | 
| ALIGNMENT_BELOW_BASELINE | 低于基线对齐。 | 
| ALIGNMENT_TOP_OF_ROW_BOX | 行框顶部对齐。 | 
| ALIGNMENT_BOTTOM_OF_ROW_BOX | 行框底部对齐。 | 
| ALIGNMENT_CENTER_OF_ROW_BOX | 行框中心对齐。 | 


### OH_Drawing_PointMode

```
enum OH_Drawing_PointMode
```

**描述**

绘制多个点的方式枚举，方式分为离散点、直线或开放多边形。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| POINT_MODE_POINTS | 分别绘制每个点。 | 
| POINT_MODE_LINES | 将每两个点绘制为线段。 | 
| POINT_MODE_POLYGON | 将点阵列绘制为开放多边形。 | 


### OH_Drawing_RectHeightStyle

```
enum OH_Drawing_RectHeightStyle
```

**描述**

矩形框高度样式枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| RECT_HEIGHT_STYLE_TIGHT | 紧密样式。 | 
| RECT_HEIGHT_STYLE_MAX | 最大样式。 | 
| RECT_HEIGHT_STYLE_INCLUDELINESPACEMIDDLE | 包含行间距中间样式。 | 
| RECT_HEIGHT_STYLE_INCLUDELINESPACETOP | 包含行间距顶部样式。 | 
| RECT_HEIGHT_STYLE_INCLUDELINESPACEBOTTOM | 包含行间距底部样式。 | 
| RECT_HEIGHT_STYLE_STRUCT | 结构样式。 | 


### OH_Drawing_RectWidthStyle

```
enum OH_Drawing_RectWidthStyle
```

**描述**

矩形框宽度样式枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| RECT_WIDTH_STYLE_TIGHT | 紧密样式。 | 
| RECT_WIDTH_STYLE_MAX | 最大样式。 | 


### OH_Drawing_ScaleToFit

```
enum OH_Drawing_ScaleToFit
```

**描述**

矩阵缩放方式枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| SCALE_TO_FIT_FILL | 按水平轴和垂直轴缩放以填充目标矩形。 | 
| SCALE_TO_FIT_START | 缩放并对齐到左侧和顶部。 | 
| SCALE_TO_FIT_CENTER | 缩放并居中对齐。 | 
| SCALE_TO_FIT_END | 缩放并向右和向下对齐。 | 


### OH_Drawing_SrcRectConstraint

```
enum OH_Drawing_SrcRectConstraint
```

**描述**

源矩形区域约束类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| STRICT_SRC_RECT_CONSTRAINT | 严格约束，源矩形区域必须完全包含在图像中。 | 
| FAST_SRC_RECT_CONSTRAINT | 快速约束，源矩形区域可以部分位于图像之外。 | 


### OH_Drawing_TextAlign

```
enum OH_Drawing_TextAlign
```

**描述**

文字对齐方式。

| 枚举值 | 描述 | 
| -------- | -------- |
| TEXT_ALIGN_LEFT | 左对齐。 | 
| TEXT_ALIGN_RIGHT | 右对齐。 | 
| TEXT_ALIGN_CENTER | 居中对齐。 | 
| TEXT_ALIGN_JUSTIFY | 两端对齐，即紧靠左和右边缘，中间单词空隙由空格填充，最后一行除外。 | 
| TEXT_ALIGN_START | 当OH_Drawing_TextDirection是TEXT_DIRECTION_LTR时， TEXT_ALIGN_START和TEXT_ALIGN_LEFT相同； 类似地，当OH_Drawing_TextDirection是TEXT_DIRECTION_RTL时， TEXT_ALIGN_START和TEXT_ALIGN_RIGHT相同。 | 
| TEXT_ALIGN_END | 当OH_Drawing_TextDirection是TEXT_DIRECTION_LTR时， TEXT_ALIGN_END和TEXT_ALIGN_RIGHT相同； 类似地，当OH_Drawing_TextDirection是TEXT_DIRECTION_RTL时， TEXT_ALIGN_END和TEXT_ALIGN_LEFT相同。 | 


### OH_Drawing_TextBaseline

```
enum OH_Drawing_TextBaseline
```

**描述**

基线位置。

| 枚举值 | 描述 | 
| -------- | -------- |
| TEXT_BASELINE_ALPHABETIC | 用于表音文字，基线在中间偏下的位置。 | 
| TEXT_BASELINE_IDEOGRAPHIC | 用于表意文字，基线位于底部。 | 


### OH_Drawing_TextDecoration

```
enum OH_Drawing_TextDecoration
```

**描述**

文本装饰。

| 枚举值 | 描述 | 
| -------- | -------- |
| TEXT_DECORATION_NONE | 无装饰。 | 
| TEXT_DECORATION_UNDERLINE | 下划线。 | 
| TEXT_DECORATION_OVERLINE | 上划线。 | 
| TEXT_DECORATION_LINE_THROUGH | 删除线。 | 


### OH_Drawing_TextDecorationStyle

```
enum OH_Drawing_TextDecorationStyle
```

**描述**

文本装饰样式枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| TEXT_DECORATION_STYLE_SOLID | 实心样式。 | 
| TEXT_DECORATION_STYLE_DOUBLE | 双重样式。 | 
| TEXT_DECORATION_STYLE_DOTTED | 圆点样式。 | 
| TEXT_DECORATION_STYLE_DASHED | 虚线样式。 | 
| TEXT_DECORATION_STYLE_WAVY | 波浪样式。 | 


### OH_Drawing_TextDirection

```
enum OH_Drawing_TextDirection
```

**描述**

文字方向。

| 枚举值 | 描述 | 
| -------- | -------- |
| TEXT_DIRECTION_RTL | 方向：从右到左。 | 
| TEXT_DIRECTION_LTR | 方向：从左到右。 | 


### OH_Drawing_TextEncoding

```
enum OH_Drawing_TextEncoding
```

**描述**

文本编码类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| TEXT_ENCODING_UTF8 | 单字节，表示UTF-8或ASCII。 | 
| TEXT_ENCODING_UTF16 | 双字节，表示大部分Unicode。 | 
| TEXT_ENCODING_UTF32 | 四字节，表示所有Unicode。 | 
| TEXT_ENCODING_GLYPH_ID | 双字节，表示字形索引。 | 


### OH_Drawing_TextHeightBehavior

```
enum OH_Drawing_TextHeightBehavior
```

**描述**

文本高度修饰符模式枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| TEXT_HEIGHT_ALL | 段落中第一行顶部和段落中最后一行底部[OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight)设置的高度生效。 | 
| TEXT_HEIGHT_DISABLE_FIRST_ASCENT | 禁止段落中第一行顶部[OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight)设置的高度生效。 | 
| TEXT_HEIGHT_DISABLE_LAST_ASCENT | 禁止段落中最后一行底部[OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight)设置的高度生效。 | 
| TEXT_HEIGHT_DISABLE_ALL | 禁止段落中第一行顶部和段落中最后一行底部[OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight)设置的高度生效。 | 


### OH_Drawing_TextStyleType

```
enum OH_Drawing_TextStyleType
```

**描述**

文本样式类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| TEXT_STYLE_NONE | 无文本样式。 | 
| TEXT_STYLE_ALL_ATTRIBUTES | 所有文本样式。 | 
| TEXT_STYLE_FONT | 字体样式。 | 
| TEXT_STYLE_FOREGROUND | 文本前景样式。 | 
| TEXT_STYLE_BACKGROUND | 文本背景样式。 | 
| TEXT_STYLE_SHADOW | 文本阴影样式。 | 
| TEXT_STYLE_DECORATIONS | 文本装饰样式。 | 
| TEXT_STYLE_LETTER_SPACING | 文本字符间距样式。 | 
| TEXT_STYLE_WORD_SPACING | 文本单词间距样式。 | 


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


### OH_Drawing_VertexMode

```
enum OH_Drawing_VertexMode
```

**描述**

用于指定如何解释给定顶点的几何形状的枚举类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| VERTEX_MODE_TRIANGLES | 每三个顶点表示一个三角形，如果顶点数不是3的倍数，则多余的顶点会被忽略。 | 
| VERTEX_MODE_TRIANGLESSTRIP | 相邻三个顶点表示一个三角形，每个新的顶点将与前两个顶点组成一个新的三角形。 | 
| VERTEX_MODE_TRIANGLEFAN | 第一个顶点作为中心点，后续的每个顶点都与前一个顶点和中心点组成一个三角形。 | 


### OH_Drawing_WordBreakType

```
enum OH_Drawing_WordBreakType
```

**描述**

单词的断词方式枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| WORD_BREAK_TYPE_NORMAL | 常规方式。 | 
| WORD_BREAK_TYPE_BREAK_ALL | 全部中断方式。 | 
| WORD_BREAK_TYPE_BREAK_WORD | 单词中断方式。 | 
| WORD_BREAK_TYPE_BREAK_HYPHEN<sup>18+</sup>  | 每行末尾单词尝试通过连字符“-”进行断行，若无法添加连字符“-”，则跟WORD_BREAK_TYPE_BREAK_WORD保持一致。| 



## 函数说明

### OH_Drawing_CreateSumPathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateSumPathEffect (OH_Drawing_PathEffect* firstPathEffect, OH_Drawing_PathEffect* secondPathEffect )
```

**描述**

创建一个使用两种路径效果分别生效后叠加的路径效果对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| firstPathEffect | 指向路径对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)的指针。  | 
| secondPathEffect | 指向路径对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)的指针。  | 

**返回：**

函数返回一个指针，指针指向创建的路径效果对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)。

如果返回nullptr，则创建失败，失败的可能原因是firstPathEffect或者secondPathEffect为nullptr。

### OH_Drawing_CreatePathDashEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreatePathDashEffect (const OH_Drawing_Path* path, float advance, float phase, OH_Drawing_PathDashStyle type )
```

**描述**

创建一个虚线效果的路径效果对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 表示虚线样式的路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。  | 
| advance | 表示虚线段的步长。  | 
| phase | 表示虚线段内图形在虚线步长范围内的偏移量。  | 
| type | 表示虚线路径效果样式。  | 

**返回：**

函数返回一个指针，指针指向创建的路径效果对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)。

如果返回nullptr，则创建失败，失败的可能原因是path为nullptr或者advance小于等于0。

### OH_Drawing_CreateDiscretePathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateDiscretePathEffect (float segLength, float deviation )
```

**描述**

创建一种将路径打散并且在路径上产生不规则分布的路径效果对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| segLength | 表示路径中每进行一次打散操作的长度，该值大于0时有效果。  | 
| deviation | 表示绘制时的末端点的最大移动偏离量。  | 

**返回：**

函数返回一个指针，指针指向创建的路径效果对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)。


### OH_Drawing_CreateCornerPathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateCornerPathEffect (float radius)
```

**描述**

创建一个将路径的夹角变成指定半径的圆角的路径效果对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| radius | 表示圆角的半径，该值必须大于0时才生效。  | 

**返回：**

函数返回一个指针，指针指向创建的路径效果对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)。

如果返回nullptr，则创建失败，失败的可能原因是radius小于等于0。



### OH_Drawing_CreateComposePathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateComposePathEffect (OH_Drawing_PathEffect* outer, OH_Drawing_PathEffect* inner )
```

**描述**

创建路径组合的路径效果对象。首先应用内部路径效果，然后应用外部路径效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| outer | 表示组合路径效果中外部路径效果[OH_Drawing_PathEffect](#oh_drawing_patheffect)的指针。  | 
| inner | 表示组合路径效果中内部路径效果[OH_Drawing_PathEffect](#oh_drawing_patheffect)的指针。  | 

**返回：**

函数返回一个指针，指针指向创建的路径效果对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)。

如果返回nullptr，则创建失败，失败的原因可能是outer或者inner为nullptr。

### OH_Drawing_GpuContextCreate()

```
OH_Drawing_GpuContext* OH_Drawing_GpuContextCreate ()
```

**描述**

用于创建一个图形处理器上下文对象, 使用的后端类型取决于运行设备。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 16

**返回：**

返回一个指针，指针指向创建的图形处理器上下文对象[OH_Drawing_GpuContext](#oh_drawing_gpucontext)。


### OH_Drawing_CanvasDrawArcWithCenter()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawArcWithCenter (OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect, float startAngle, float sweepAngle, bool useCenter )
```

**描述**

绘制一段圆弧。该方法允许指定圆弧的起始角度、扫描角度以及圆弧的起点和终点是否连接圆弧的中心点。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。  | 
| rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。  | 
| startAngle | 弧的起始角度，单位为度，该参数为浮点数。0度时起始点位于椭圆的右端点，为正数时以顺时针方向放置起始点，为负数时以逆时针方向放置起始点。  | 
| sweepAngle | 弧的扫描角度，单位为度，该参数为浮点数。为正数时顺时针扫描，为负数时逆时针扫描。扫描角度可以超过360度，将绘制一个完整的椭圆。  | 
| useCenter | 表示绘制时弧形的起点和终点是否连接弧形的中心点。true表示连接，false表示不连接。  | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者rect为空。

### OH_Drawing_CanvasDrawNestedRoundRect()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawNestedRoundRect (OH_Drawing_Canvas* canvas, const OH_Drawing_RoundRect* outer, const OH_Drawing_RoundRect* inner )
```

**描述**

绘制两个嵌套的圆角矩形，外部矩形边界必须包含内部矩形边界，否则无绘制效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。  | 
| outer | 指向圆角矩形对象[OH_Drawing_RoundRect](#oh_drawing_roundrect)的指针，表示外部圆角矩形边界。  | 
| inner | 指向圆角矩形对象[OH_Drawing_RoundRect](#oh_drawing_roundrect)的指针，表示内部圆角矩形边界。  | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、outer或者inner为空。

### OH_Drawing_CanvasQuickRejectPath()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasQuickRejectPath (OH_Drawing_Canvas* canvas, const OH_Drawing_Path* path, bool* quickReject )
```

**描述**


判断路径与画布区域是否不相交。画布区域包含边界。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。  | 
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。  | 
| quickReject | 表示路径与画布区域是否不相交，true表示路径与画布区域不相交，false表示路径与画布区域相交。  | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、path或者quickReject为空。

### OH_Drawing_CanvasQuickRejectRect()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasQuickRejectRect (OH_Drawing_Canvas* canvas, const OH_Drawing_Rect* rect, bool* quickReject )
```

**描述**

判断矩形和画布区域是否不相交。画布区域包含边界。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。  | 
| rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。  | 
| quickReject | 表示矩形与画布区域是否不相交，true表示矩形与画布区域不相交，false表示矩形与画布区域相交。  | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、rect或者quickReject为空。

### OH_Drawing_CanvasDrawPixelMapNine()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawPixelMapNine (OH_Drawing_Canvas* canvas, OH_Drawing_PixelMap* pixelMap, const OH_Drawing_Rect* center, const OH_Drawing_Rect* dst, OH_Drawing_FilterMode mode )
```

**描述**

通过绘制两条水平线和两条垂直线将像素图分割成9个部分：四个边，四个角和中心。 若角落的4个区域尺寸不超过目标矩形，则会在不缩放的情况下被绘制在目标矩形，反之则会按比例缩放绘制在目标矩形。 如果还有剩余空间，剩下的5个区域会通过拉伸或压缩来绘制，以便能够完全覆盖目标矩形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。  | 
| pixelMap | 指向像素图[OH_Drawing_PixelMap](#oh_drawing_pixelmap)的指针。  | 
| center | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针，表示分割像素图的中心矩形。矩形四条边所在的直线将像素图分成了9个部分。  | 
| dst | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针，表示画布上的目标区域。  | 
| mode | 过滤模式枚举[OH_Drawing_FilterMode](#oh_drawing_filtermode-1)。  | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、pixelMap或dst为空。

### OH_Drawing_SurfaceCreateOnScreen()

```
OH_Drawing_Surface* OH_Drawing_SurfaceCreateOnScreen (OH_Drawing_GpuContext* gpuContext, OH_Drawing_Image_Info imageInfo, void* window )
```
**描述**

使用图形处理器上下文创建一个与屏幕窗口绑定的surface对象，用于管理画布绘制的内容。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码的取值。 gpuContext或window为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 16

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| gpuContext | 指向图形处理器上下文对象的指针[OH_Drawing_GpuContext](#oh_drawing_gpucontext)。 该图形处理器上下文对象必须由[OH_Drawing_GpuContextCreate](#oh_drawing_gpucontextcreate)创建，否则surface对象会创建失败。  | 
| imageInfo | 图片信息[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)结构体。  | 
| window | 指向屏幕窗口对象的指针。  | 

**返回：**

返回一个指针，指针指向创建的surface对象[OH_Drawing_Surface](#oh_drawing_surface)。

### OH_Drawing_SurfaceFlush()

```
OH_Drawing_ErrorCode OH_Drawing_SurfaceFlush (OH_Drawing_Surface* surface)
```

**描述**

将surface对象上的画布绘制内容提交给GPU处理，完成绘制内容上屏显示。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 16

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| surface | 指向创建的surface对象的指针[OH_Drawing_Surface](#oh_drawing_surface)。 该surface对象必须由[OH_Drawing_SurfaceCreateOnScreen](#oh_drawing_surfacecreateonscreen)创建，否则该接口调用将没有任何效果。  | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数surface为空。

### OH_Drawing_ErrorCodeReset()

```
void OH_Drawing_ErrorCodeReset (void )
```

**描述**

将本模块的错误码重置为OH_DRAWING_SUCCESS。

通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)获取的本模块错误码会在不以错误码为返回值的接口执行失败时被置为对应的错误编号，但是不会在执行成功后被重置为OH_DRAWING_SUCCESS。

调用本接口可将错误码重置为OH_DRAWING_SUCCESS，避免多个接口间互相干扰，方便开发者调试。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

### OH_Drawing_FontSetThemeFontFollowed()

```
OH_Drawing_ErrorCode OH_Drawing_FontSetThemeFontFollowed (OH_Drawing_Font* font, bool followed )
```

**描述**

设置字型中的字体是否跟随主题字体。设置跟随主题字体后，若系统启用主题字体并且字型未被设置字体，字型会使用该主题字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| font | 指示字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| followed | 字型中的字体是否跟随主题字体，true表示跟随主题字体，false表示不跟随主题字体。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font为空。

### OH_Drawing_FontIsThemeFontFollowed()

```
OH_Drawing_ErrorCode OH_Drawing_FontIsThemeFontFollowed (const OH_Drawing_Font* font, bool* followed )
```

**描述**

获取字型中的字体是否跟随主题字体。默认不跟随主题字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| font | 指示字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| followed | 返回字型中的字体是否跟随主题字体的结果，true表示跟随主题字体，false表示不跟随主题字体。作为出参使用。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font或者followed其中一个为空。

### OH_Drawing_GetFontCollectionGlobalInstance()

```
OH_Drawing_FontCollection* OH_Drawing_GetFontCollectionGlobalInstance (void )
```
**描述**

获取全局字体集对象OH_Drawing_FontCollection，可感知主题字信息，禁止释放该对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**返回：**

指向全局字体集对象的指针。

### OH_Drawing_CreateLineTypography()

```
OH_Drawing_LineTypography* OH_Drawing_CreateLineTypography (OH_Drawing_TypographyCreate* handler)
```

**描述**

创建一个排版行对象[OH_Drawing_LineTypography](#oh_drawing_linetypography)的指针，排版行对象保存着文本内容以及样式的载体， 可以用于计算单行排版信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| handler | 指向[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象的指针，由[OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler)获取。 |

**返回：**

返回一个指向排版行对象[OH_Drawing_LineTypography](#oh_drawing_linetypography)的指针。

### OH_Drawing_DestroyLineTypography()

```
void OH_Drawing_DestroyLineTypography (OH_Drawing_LineTypography* lineTypography)
```

**描述**

释放排版行对象[OH_Drawing_LineTypography](#oh_drawing_linetypography)占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| lineTypography | 指向排版行对象[OH_Drawing_LineTypography](#oh_drawing_linetypography)的指针，由[OH_Drawing_CreateLineTypography](#oh_drawing_createlinetypography)获取。 |

### OH_Drawing_LineTypographyGetLineBreak()

```
size_t OH_Drawing_LineTypographyGetLineBreak (OH_Drawing_LineTypography* lineTypography, size_t startIndex, double width )
```

**描述**

计算在限定排版宽度的情况下，从指定位置处开始可以排版的字符个数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| lineTypography | 指向排版行对象[OH_Drawing_LineTypography](#oh_drawing_linetypography)的指针，由[OH_Drawing_CreateLineTypography](#oh_drawing_createlinetypography)获取。 |
| startIndex | 开始计算排版的起始位置（包括起始位置）。取值范围需要为[0,文本字符总数）的整数。 |
| width | 换行宽度，大于0的浮点数，单位为物理像素px。 |

**返回：**

返回在限定排版宽度的情况下，从指定位置处开始可以排版的字符总数，取值为整数。

### OH_Drawing_LineTypographyCreateLine()

```
OH_Drawing_TextLine* OH_Drawing_LineTypographyCreateLine (OH_Drawing_LineTypography* lineTypography, size_t startIndex, size_t count )
```

**描述**

根据指定区间文本内容创建一个指向文本行对象**OH_Drawing_TextLine**的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| lineTypography | 指向排版行对象[OH_Drawing_LineTypography](#oh_drawing_linetypography)的指针，由[OH_Drawing_CreateLineTypography](#oh_drawing_createlinetypography)获取。 |
| startIndex | 表示计算排版的起始位置，整数，取值范围为[0, 文本字符总数)。 |
| count | 表示从指定排版起始位置开始进行排版的字符个数，取值为[0,文本字符总数)的整数，startIndex和count之和不能大于文本字符总数。 可以先使用[OH_Drawing_LineTypographyGetLineBreak](#oh_drawing_linetypographygetlinebreak)获得合理的可用于进行排版的字符总数。如果该值设置为0，则返回nullptr。 |

**返回：**

返回一个指向文本行对象**OH_Drawing_TextLine**的指针。

### OH_Drawing_CreateTextTab()

```
OH_Drawing_TextTab* OH_Drawing_CreateTextTab (OH_Drawing_TextAlign alignment, float location )
```

**描述**

创建文本制表符对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| alignment | 制表符之后的文本对齐方式。1为右对齐，2为居中对齐，0或其它为左对齐。 |
| float | 文本制表符之后的文本对齐的位置，相对于当前文本起始位置的偏移。单位为物理像素px，最小值为1.0。 |

**返回：**

OH_Drawing_TextTab 返回指向文本制表符对象的指针。如果返回空指针，表示创建失败。失败的原因可能为没有可用的内存。

### OH_Drawing_DestroyTextTab()

```
void OH_Drawing_DestroyTextTab (OH_Drawing_TextTab* )
```

**描述**

释放文本制表符对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextTab | 指向文本制表符对象的指针。 |

### OH_Drawing_GetTextTabAlignment()

```
OH_Drawing_TextAlign OH_Drawing_GetTextTabAlignment (OH_Drawing_TextTab* )
```

**描述**

获取文本制表符对象的对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextTab | 指向文本制表符对象的指针。 |

**返回：**

返回文本对齐方式。1为右对齐，2为居中对齐，0或其它为左对齐。

### OH_Drawing_GetTextTabLocation()

```
float OH_Drawing_GetTextTabLocation (OH_Drawing_TextTab* )
```

**描述**

获取文本制表符的位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextTab | 指向文本制表符对象的指针。 |

**返回：**

返回文本制表符对象的位置。

### OH_Drawing_SetTypographyTextTab()

```
void OH_Drawing_SetTypographyTextTab (OH_Drawing_TypographyStyle* , OH_Drawing_TextTab* TextTab )
```

**描述**

设置文本制表符对齐方式及位置。当设置了文本对齐方式或者省略号风格时制表符不生效，当制表符位置小于1.0时为替换成空格的效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针。 |
| OH_Drawing_TextTab | 指向文本制表符对象的指针。 |

### OH_Drawing_FontGetBounds()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetBounds (const OH_Drawing_Font* font, const uint16_t* glyphs, uint32_t count, OH_Drawing_Array* bounds )
```

**描述**

获取字体指定字形索引的矩形边界。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| font | 指向字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 |
| glyphs | 字形索引数组。 |
| count | 字形数组的长度。 |
| bounds | 矩形边界数组。 |

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font、glyphs或bounds为空，或者count为零。

### OH_Drawing_FontGetPathForGlyph()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetPathForGlyph (const OH_Drawing_Font* font, uint16_t glyph, OH_Drawing_Path* path )
```

**描述**

获取字体指定字形索引的轮廓。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| font | 指向字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 |
| glyph | 指定的字形索引。 |
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针, 用于存储得到的字形路径。 |

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font或者path为空， 或者指定glyph不存在。

### OH_Drawing_RectCreateArray()

```
OH_Drawing_Array* OH_Drawing_RectCreateArray (size_t size)
```

**描述**

用于创建一个矩形数组对象, 用来存储多个矩形对象。不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_RectDestroyArray](#oh_drawing_rectdestroyarray)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| size | 指定矩形数组的大小，不超过字形索引数量最大值65536。 |

**返回：**

返回创建的数组对象[OH_Drawing_Array](#oh_drawing_array)指针，如果返回的对象指针为空，表示创建失败。 失败的原因可能为：没有可用的内存或参数错误。

### OH_Drawing_RectGetArraySize()

```
OH_Drawing_ErrorCode OH_Drawing_RectGetArraySize (OH_Drawing_Array* rectArray, size_t* pSize )
```

**描述**

用于获取矩形数组对象[OH_Drawing_Array](#oh_drawing_array)的大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rectArray | 指向矩形数组对象[OH_Drawing_Array](#oh_drawing_array)的指针。 |
| pSize | 指向size_t类型的指针，用于存储矩形数组大小，作为出参使用。 |

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数rectArray或者pSize为空。

### OH_Drawing_RectGetArrayElement()

```
OH_Drawing_ErrorCode OH_Drawing_RectGetArrayElement (OH_Drawing_Array* rectArray, size_t index, OH_Drawing_Rect** rect )
```

**描述**

用于获取矩形数组对象中指定索引的矩形对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rectArray | 指向矩形数组对象[OH_Drawing_Array](#oh_drawing_array)的指针。 |
| index | 矩形数组的索引。 |
| rect | 指向[OH_Drawing_Rect](#oh_drawing_rect)的二级指针，作为出参，返回给调用者。 |

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数rectArray或者rect为空，或者index越界。

### OH_Drawing_RectDestroyArray()

```
OH_Drawing_ErrorCode OH_Drawing_RectDestroyArray (OH_Drawing_Array* rectArray)
```

**描述**

用于销毁矩形数组对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rectArray | 指向矩形数组对象[OH_Drawing_Array](#oh_drawing_array)的指针。 |

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数rectArray为空。

### OH_Drawing_TypographyGetTextLines()

```
OH_Drawing_Array* OH_Drawing_TypographyGetTextLines (OH_Drawing_Typography* typography)
```

**描述**

获取排版对象的文本行数组。文本行数组中包含一个或多个文本行对象。不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_DestroyTextLines](#oh_drawing_destroytextlines)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| typography | 指向排版对象[OH_Drawing_Typography](#oh_drawing_typography)的指针。 |

**返回：**

指向文本行数组[OH_Drawing_Array](#oh_drawing_array)的指针。

### OH_Drawing_DestroyTextLines()

```
void OH_Drawing_DestroyTextLines (OH_Drawing_Array* lines)
```

**描述**

释放文本行数组的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| lines | 指向文本行数组[OH_Drawing_Array](#oh_drawing_array)的指针。 |

### OH_Drawing_DestroyTextLine()

```
void OH_Drawing_DestroyTextLine (OH_Drawing_TextLine* line)
```

**描述**

释放单个文本行对象的内存。只能释放单独申请内存的文本行对象，不能释放文本行数组中的某一个文本行对象的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |

### OH_Drawing_GetTextLineByIndex()

```
OH_Drawing_TextLine* OH_Drawing_GetTextLineByIndex (OH_Drawing_Array* lines, size_t index )
```

**描述**

获取文本行数组指定索引处的文本行对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| lines | 指向文本行数组[OH_Drawing_Array](#oh_drawing_array)的指针。 |
| index | 指定的文本行数组的索引。 |

**返回：**

指向指定索引处的文本行对象**OH_Drawing_TextLine**的指针。

### OH_Drawing_TextLineGetGlyphCount()

```
double OH_Drawing_TextLineGetGlyphCount (OH_Drawing_TextLine* line)
```

**描述**

获取文本行对象中字形的数量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |

**返回：**

文本行对象中字形的数量。

### OH_Drawing_TextLineGetTextRange()

```
void OH_Drawing_TextLineGetTextRange (OH_Drawing_TextLine* line, size_t* start, size_t* end )
```

**描述**

获取文本行对象中的文本在整个段落文本中的索引区间。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |
| start | 指向区间左侧端点索引的指针。 |
| end | 指向区间右侧端点索引的指针。 |

### OH_Drawing_TextLineGetGlyphRuns()

```
OH_Drawing_Array* OH_Drawing_TextLineGetGlyphRuns (OH_Drawing_TextLine* line)
```

**描述**

获取文本行对象中的文本渲染单元数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |

**返回：**

指向文本渲染单元**OH_Drawing_Run**数组[OH_Drawing_Array](#oh_drawing_array)的指针，不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_DestroyRuns](#oh_drawing_destroyruns)接口释放该对象的指针。

### OH_Drawing_DestroyRuns()

```
void OH_Drawing_DestroyRuns (OH_Drawing_Array* runs)
```

**描述**

释放文本渲染单元数组的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| runs | 指向文本渲染单元**OH_Drawing_Run**数组[OH_Drawing_Array](#oh_drawing_array)的指针。 |

### OH_Drawing_GetRunByIndex()

```
OH_Drawing_Run* OH_Drawing_GetRunByIndex (OH_Drawing_Array* runs, size_t index )
```

**描述**

获取文本渲染单元数组指定索引处的文本渲染单元对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| runs | 指向文本渲染单元**OH_Drawing_Run**数组[OH_Drawing_Array](#oh_drawing_array)的指针。 |
| index | 文本渲染单元数组的索引。 |

**返回：**

指向指定索引处的文本渲染单元对象**OH_Drawing_Run**的指针。

### OH_Drawing_TextLinePaint()

```
void OH_Drawing_TextLinePaint (OH_Drawing_TextLine* line, OH_Drawing_Canvas* canvas, double x, double y )
```

**描述**

在画布上以坐标点 (x, y) 为左上角位置绘制文本行。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |
| canvas | 指向绘制的目标画布[OH_Drawing_Canvas](#oh_drawing_canvas)。 |
| x | 绘制的左上角位置的横坐标，单位为物理像素px。 |
| y | 绘制的左上角位置的纵坐标，单位为物理像素px。 |

### OH_Drawing_TextLineCreateTruncatedLine()

```
OH_Drawing_TextLine* OH_Drawing_TextLineCreateTruncatedLine (OH_Drawing_TextLine* line, double width, int mode, const char* ellipsis )
```

**描述**

创建一个截断的文本行对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |
| width | 截断后的行宽度。 |
| mode | 截断的类型，取值对应为[OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)枚举，当前仅支持头部截断ELLIPSIS_MODAL_HEAD和尾部截断ELLIPSIS_MODAL_TAIL。 |
| ellipsis | 截断的标记字符串。 |

**返回：**

返回指向截断的文本行对象**OH_Drawing_TextLine**指针。

### OH_Drawing_TextLineGetTypographicBounds()

```
double OH_Drawing_TextLineGetTypographicBounds (OH_Drawing_TextLine* line, double* ascent, double* descent, double* leading )
```

**描述**

获取文本行对象的排版边界。文本行排版边界与排版字体、排版字号有关，与字符本身无关。 例如字符串为" a b "，'a'字符前面有1个空格，'b'字符后面有1个空格，排版边界就包括行首和末尾空格的边界。例如字符串为"j"或"E"，排版边界相同，即与字符本身无关。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。height = ascent + descent + leading。 |
| ascent | 指向文本行对象上升高度的指针。 |
| descent | 指向文本行对象下降高度的指针。 |
| leading | 指向文本行对象行间距的指针。 |

**返回：**

排版边界的总宽度。

### OH_Drawing_TextLineGetImageBounds()

```
OH_Drawing_Rect* OH_Drawing_TextLineGetImageBounds (OH_Drawing_TextLine* line)
```

**描述**

获取文本行对象的图像边界。文本行图像边界与排版字体、排版字号、字符本身都有关，相当于视觉边界。 例如字符串为" a b "，'a'字符前面有1个空格，'b'字符后面有1个空格,用户在界面上只能看到"a b"，图像边界即为不包括带行首和末尾空格的边界。 例如字符串为"j"或"E"，视觉边界不同，即与字符本身有关，"j"字符串的视觉边界宽度小于"E"字符串的视觉边界宽度，"j"字符串的视觉边界高度大于"E"字符串的视觉边界高度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |

**返回：**

指向文本行对象的图像边界[OH_Drawing_Rect](#oh_drawing_rect)的指针，不再需要[OH_Drawing_Rect](#oh_drawing_rect)时，请使用[OH_Drawing_RectDestroy](#oh_drawing_rectdestroy)接口释放该对象的指针。

### OH_Drawing_TextLineGetTrailingSpaceWidth()

```
double OH_Drawing_TextLineGetTrailingSpaceWidth (OH_Drawing_TextLine* line)
```

**描述**

获取文本行对象尾部空白字符的宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |

**返回：**

文本行对象尾部空白字符的宽度。

### OH_Drawing_TextLineGetStringIndexForPosition()

```
int32_t OH_Drawing_TextLineGetStringIndexForPosition (OH_Drawing_TextLine* line, OH_Drawing_Point* point )
```

**描述**

获取文本行对象中指定位置处的字符索引。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |
| point | 指向要查找索引的位置[OH_Drawing_Point](#oh_drawing_point)指针。 |

**返回：**

指定位置处的字符串索引。例如文本字符串为"abc"，"a"字符的索引为0，"b"字符的索引为1，"c"字符的索引为2。如果指定的位置在"a"字符处，则返回0。

### OH_Drawing_TextLineGetOffsetForStringIndex()

```
double OH_Drawing_TextLineGetOffsetForStringIndex (OH_Drawing_TextLine* line, int32_t index )
```

**描述**

获取文本行对象中指定字符串索引处的偏移量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |
| index | 要获取偏移量的字符串索引。 |

**返回：**

指定字符串索引处的偏移量。

### OH_Drawing_TextLineEnumerateCaretOffsets()

```
void OH_Drawing_TextLineEnumerateCaretOffsets (OH_Drawing_TextLine* line, Drawing_CaretOffsetsCallback callback )
```

**描述**

枚举文本行对象中每个字符的偏移量和索引值，传递给用户自定义的回调函数，用户可以使用偏移量和索引值进行其他操作。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |
| callback | 用户自定义函数[Drawing_CaretOffsetsCallback](#drawing_caretoffsetscallback)。 |

### OH_Drawing_TextLineGetAlignmentOffset()

```
double OH_Drawing_TextLineGetAlignmentOffset (OH_Drawing_TextLine* line, double alignmentFactor, double alignmentWidth )
```

**描述**

获取文本行对象根据对齐因子和对齐宽度计算对齐后所需的偏移量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| line | 指向文本行对象**OH_Drawing_TextLine**的指针。 |
| alignmentFactor | 对齐因子，即对齐的程度。小于等于0.0表示左对齐，大于0.0小于0.5表示偏左对齐，0.5表示居中对齐，大于0.5小于1.0表示偏右对齐，大于等于1.0表示右对齐。 |
| alignmentWidth | 对齐宽度，即最终偏移后的文本行对象右下角相对于起始位置的偏移值。如果指定对齐宽度小于文本行对象的实际宽度，则返回0。 |

**返回：**

计算得到的对齐所需偏移量。

### OH_Drawing_AddTextStyleDecoration()

```
void OH_Drawing_AddTextStyleDecoration (OH_Drawing_TextStyle* , int  )
```

**描述**

新增指定装饰，可同时显示多种装饰线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 |
| int | 要新增的装饰。设置1为新增下划线，设置2为新增上划线，设置4为新增删除线。可通过位或操作一次新增多种装饰线，设置非[OH_Drawing_TextDecoration](#oh_drawing_textdecoration)枚举的装饰样式则保持原有装饰。 |

### OH_Drawing_RemoveTextStyleDecoration()

```
void OH_Drawing_RemoveTextStyleDecoration (OH_Drawing_TextStyle* , int  )
```

**描述**

删除指定装饰。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 |
| int | 要删除的装饰。应该与现有的装饰相匹配，设置1为删除下划线，设置2为删除上划线，设置4为删除删除线，可通过位或操作一次删除多种装饰线。 设置非[OH_Drawing_TextDecoration](#oh_drawing_textdecoration)枚举的装饰样式则保持原有装饰。 |

### OH_Drawing_FontGetTextPath()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetTextPath (const OH_Drawing_Font* font, const void* text, size_t byteLength, OH_Drawing_TextEncoding encoding, float x, float y, OH_Drawing_Path* path )
```

**描述**

获取文字轮廓路径。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| font | 指示字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 |
| text | 指示要获取轮廓路径的文本字符串。 |
| byteLength | 指示要获取对应文本路径的字节长度，如果此字节长度大于text字符串的字节长度，会发生未定义行为。 |
| encoding | 指示文本编码格式，支持 UTF-8、UTF-16、UTF-32，以及字形索引，具体类型格式可见[OH_Drawing_TextEncoding](#oh_drawing_textencoding)。 |
| x | 指示文本在绘图区域内以原点为起始位置的X坐标。 |
| y | 指示文本在绘图区域内以原点为起始位置的Y坐标。 |
| path | 返回获取到的文字轮廓路径对象，作为出参使用。 |

**返回：**

返回错误代码。 如果操作成功，则返回 OH_DRAWING_SUCCESS。 如果 font、text 或 path 中的任何一个为空指针，则返回 OH_DRAWING_ERROR_INVALID_PARAMETER。

### OH_Drawing_GetDrawingArraySize()

```
size_t OH_Drawing_GetDrawingArraySize (OH_Drawing_Array* drawingArray)
```

**描述**

获取传入类型为对象数组[OH_Drawing_Array](#oh_drawing_array)中的对象个数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| drawingArray | 指向对象数组[OH_Drawing_Array](#oh_drawing_array)的指针。 |

**返回：**

数组中的对象个数。


### OH_Drawing_GetRunStringIndices()

```
OH_Drawing_Array* OH_Drawing_GetRunStringIndices (OH_Drawing_Run* run, int64_t start, int64_t length )
```

**描述**

获取渲染单元指定范围内字形的字符索引数组，该索引是相对于整个段落的偏移。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| run | 指向渲染单元**OH_Drawing_Run**对象的指针。 |
| start | 渲染单元内指定的开始位置，传入负数时该方法返回空指针。 |
| length | 渲染单元内指定的长度，length为0时获取渲染单元的所有字符索引，length小于0时该方法返回空指针。 |

**返回：**

返回字形的字符索引数组[OH_Drawing_Array](#oh_drawing_array)对象的指针，不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_DestroyRunStringIndices](#oh_drawing_destroyrunstringindices)接口释放该对象的指针。


### OH_Drawing_GetRunStringIndicesByIndex()

```
uint64_t OH_Drawing_GetRunStringIndicesByIndex (OH_Drawing_Array* stringIndices, size_t index )
```

**描述**

获取字符索引数组中指定下标的字符索引值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| stringIndices | 字符索引数组。 |
| index | 渲染单元字形的字符索引数组下标。 |

**返回：**

返回渲染单元单个字形的字符索引。


### OH_Drawing_DestroyRunStringIndices()

```
void OH_Drawing_DestroyRunStringIndices (OH_Drawing_Array* stringIndices)
```

**描述**

释放字形的字符索引数组对象指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| stringIndices | 字符索引数组。 |


### OH_Drawing_GetRunStringRange()

```
void OH_Drawing_GetRunStringRange (OH_Drawing_Run* run, uint64_t* location, uint64_t* length )
```

**描述**

获取渲染单元生成字形的字符范围。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| run | 指向渲染单元**OH_Drawing_Run**对象的指针。 |
| location | 表示渲染单元字形的字符范围的开始位置，该位置是相对于整个段落的偏移。 |
| length | 表示渲染单元字符范围的长度。 |


### OH_Drawing_GetRunTypographicBounds()

```
float OH_Drawing_GetRunTypographicBounds (OH_Drawing_Run* run, float* ascent, float* descent, float* leading )
```

**描述**

获取渲染单元的排版边界。文本排版边界与字符本身无关，与排版字号和字体有关。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| run | 指向渲染单元**OH_Drawing_Run**对象的指针。 |
| ascent | 渲染单元中最高字符到基准线的距离。 |
| descent | 渲染单元中最低字符到基准线的距离。 |
| leading | 渲染单元行间距。 |

**返回：**

返回渲染单元排版宽度。


### OH_Drawing_RunPaint()

```
void OH_Drawing_RunPaint (OH_Drawing_Canvas* canvas, OH_Drawing_Run* run, double x, double y )
```

**描述**

在画布上绘制渲染单元包含的文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| canvas | 指向画布[OH_Drawing_Canvas](#oh_drawing_canvas)对象的指针。 |
| run | 指向渲染单元**OH_Drawing_Run**对象的指针。 |
| x | 渲染单元x坐标。 |
| y | 渲染单元y坐标。 |


### OH_Drawing_GetRunImageBounds()

```
OH_Drawing_Rect* OH_Drawing_GetRunImageBounds (OH_Drawing_Run* run)
```

**描述**

获取渲染单元的图像边界，文本图像边界与字符本身有关，相当于视觉边界。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| run | 指向渲染单元**OH_Drawing_Run**对象的指针。 |

**返回：**

返回指向渲染单元图像边界[OH_Drawing_Rect](#oh_drawing_rect)对象的指针，不再需要[OH_Drawing_Rect](#oh_drawing_rect)时，请使用[OH_Drawing_DestroyRunImageBounds](#oh_drawing_destroyrunimagebounds)接口释放该对象的指针。


### OH_Drawing_DestroyRunImageBounds()

```
void OH_Drawing_DestroyRunImageBounds (OH_Drawing_Rect* rect)
```

**描述**

释放渲染单元图像边界对象指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| rect | 指向渲染单元图像边界[OH_Drawing_Rect](#oh_drawing_rect)对象的指针。 |


### OH_Drawing_GetRunGlyphs()

```
OH_Drawing_Array* OH_Drawing_GetRunGlyphs (OH_Drawing_Run* run, int64_t start, int64_t length )
```

**描述**

获取渲染单元指定范围内的字形数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| run | 指向渲染单元**OH_Drawing_Run**对象的指针。 |
| start | 渲染单元内指定的开始位置，传入负数时该方法返回空指针。 |
| length | 渲染单元内指定的长度，length为0时获取渲染单元的所有字符索引，length小于0时该方法返回空指针。 |

**返回：**

返回指向渲染单元字形数组[OH_Drawing_Array](#oh_drawing_array)对象的指针，不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_DestroyRunGlyphs](#oh_drawing_destroyrunglyphs)接口释放该对象的指针。


### OH_Drawing_GetRunGlyphsByIndex()

```
uint16_t OH_Drawing_GetRunGlyphsByIndex (OH_Drawing_Array* glyphs, size_t index )
```

**描述**

根据索引获取渲染单元单个字形。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| glyphs | 指向渲染单元字形数组[OH_Drawing_Array](#oh_drawing_array)对象的指针。 |
| index | 渲染单元字形数组下标。 |

**返回：**

渲染单元单个字形。


### OH_Drawing_DestroyRunGlyphs()

```
void OH_Drawing_DestroyRunGlyphs (OH_Drawing_Array* glyphs)
```

**描述**

释放渲染单元字形数组对象指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| glyphs | 指向渲染单元字形数组[OH_Drawing_Array](#oh_drawing_array)对象的指针。 |

### OH_Drawing_GetRunPositions()

```
OH_Drawing_Array* OH_Drawing_GetRunPositions (OH_Drawing_Run* run, int64_t start, int64_t length )
```

**描述**

获取渲染单元指定范围内字形的位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| run | 指向渲染单元**OH_Drawing_Run**对象的指针。 |
| start | 渲染单元内指定的开始位置，传入负数时该方法返回空指针。 |
| length | 渲染单元内指定的长度，length为0时获取渲染单元的所有字符索引，length小于0时该方法返回空指针。 |

**返回：**

返回指向渲染单元字形位置数组[OH_Drawing_Array](#oh_drawing_array)对象的指针，不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_DestroyRunPositions](#oh_drawing_destroyrunpositions)接口释放该对象的指针。

### OH_Drawing_GetRunPositionsByIndex()

```
OH_Drawing_Point* OH_Drawing_GetRunPositionsByIndex (OH_Drawing_Array* positions, size_t index )
```

**描述**

根据索引获取渲染单元中单个字形位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| positions | 指向渲染单元字形位置数组[OH_Drawing_Array](#oh_drawing_array)对象的指针。 |
| index | 渲染单元字形位置数组下标。 |

**返回：**

返回指向渲染单元单个字形位置[OH_Drawing_Point](#oh_drawing_point)对象的指针。


### OH_Drawing_DestroyRunPositions()

```
void OH_Drawing_DestroyRunPositions (OH_Drawing_Array* positions)
```

**描述**

释放渲染单元字形位置数组对象指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| positions | 指向渲染单元字形位置数组[OH_Drawing_Array](#oh_drawing_array)对象的指针。 |

### OH_Drawing_GetRunGlyphCount()

```
uint32_t OH_Drawing_GetRunGlyphCount (OH_Drawing_Run* run)
```

**描述**

获取渲染单元字形数量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| run | 指向渲染单元**OH_Drawing_Run**对象的指针。 |

**返回：**

返回渲染单元字形数量。

### OH_Drawing_MatchFontDescriptors()

```
OH_Drawing_FontDescriptor* OH_Drawing_MatchFontDescriptors (OH_Drawing_FontDescriptor* , size_t*  )
```

**描述**

获取与指定字体描述符匹配的所有系统字体描述符，其中[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)的path字段不作为有效的匹配字段，其余字段不是默认值时生效，如果参数[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)的所有字段都是默认值，则获取所有系统字体描述符。如果匹配失败，返回NULL。不再需要[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptors](_drawing.md#oh_drawing_destroyfontdescriptors)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)指针。 建议使用 [OH_Drawing_CreateFontDescriptor](#oh_drawing_createfontdescriptor)获得有效的[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)实例，如果自己创建 [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)实例，请确保不用于匹配的字段是默认值。 |
| size_t                                                       | 表示返回值数组的成员个数。                                   |

**返回：**

[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)数组，释放时请使用[OH_Drawing_DestroyFontDescriptors](#oh_drawing_destroyfontdescriptors)。

### OH_Drawing_DestroyFontDescriptors()

```
void OH_Drawing_DestroyFontDescriptors (OH_Drawing_FontDescriptor* , size_t  )
```

**描述**

释放字体描述符[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)数组。 |
| size_t | [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)数组的成员个数。 |

### OH_Drawing_DestroySystemFontFullNames()

```
void OH_Drawing_DestroySystemFontFullNames (OH_Drawing_Array* )
```

**描述**

释放通过字体类型获取的对应字体的字体名称数组占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Array | 表示字体名称数组[OH_Drawing_Array](#oh_drawing_array)的指针。 |

### OH_Drawing_GetSystemFontFullNameByIndex()

```
const OH_Drawing_String* OH_Drawing_GetSystemFontFullNameByIndex (OH_Drawing_Array* , size_t  )
```

**描述**

在字体名称数组中通过索引获取对应位置的字体名称。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_Array | 表示字体名称数组[OH_Drawing_Array](#oh_drawing_array)的指针。 |
| size_t | 数组的索引。 |

**返回：**

返回对应索引的字体名称[OH_Drawing_String](_o_h___drawing___string.md)的指针。

### OH_Drawing_GetSystemFontFullNamesByType()

```
OH_Drawing_Array* OH_Drawing_GetSystemFontFullNamesByType (OH_Drawing_SystemFontType )
```

**描述**

根据字体类型获取对应字体的字体名称数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_SystemFontType | 表示字体类型的枚举值[OH_Drawing_SystemFontType](#oh_drawing_systemfonttype)。 |

**返回：**

返回对应字体类型的字体名称数组[OH_Drawing_Array](#oh_drawing_array)的指针，不再需要[OH_Drawing_Array](#oh_drawing_array)时，请使用[OH_Drawing_DestroySystemFontFullNames](#oh_drawing_destroysystemfontfullnames)接口释放该对象的指针。

### OH_Drawing_GetFontDescriptorByFullName()

```
OH_Drawing_FontDescriptor* OH_Drawing_GetFontDescriptorByFullName (const OH_Drawing_String* , OH_Drawing_SystemFontType  )
```

**描述**

根据字体名称和字体类型获取指定的字体描述符，支持系统字体、风格字体和用户已安装字体。 字体描述符是描述字体特征的一种数据结构，它包含了定义字体外观和属性的详细信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| [OH_Drawing_String](_o_h___drawing___string.md) | 表示指向字体名称字符串[OH_Drawing_String](_o_h___drawing___string.md)的指针。 |
| OH_Drawing_SystemFontType | 表示字体类型的枚举值[OH_Drawing_SystemFontType](#oh_drawing_systemfonttype)。 |

**返回：**

指向字体描述符对象[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)的指针，不再需要[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)时，请使用[OH_Drawing_DestroyFontDescriptor](#oh_drawing_destroyfontdescriptor)接口释放该对象的指针。

### OH_Drawing_TypefaceCreateFromFileWithArguments()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFileWithArguments (const char* path, const OH_Drawing_FontArguments* fontArguments )
```

**描述**

从指定文件路径创建带有字型参数的字体对象。 如果字体对象不支持字型参数中描述的可变维度，此函数将会创建默认字型参数的字体对象。 在这种情况下，此函数将提供与[OH_Drawing_TypefaceCreateFromFile](#oh_drawing_typefacecreatefromfile)相同的功能。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向字体对象所在文件路径的指针。 | 
| fontArguments | 指向字型参数对象[OH_Drawing_FontArguments](#oh_drawing_fontarguments)的指针。 | 

**返回：**

函数返回一个指针，指针指向创建的字体对象[OH_Drawing_Typeface](#oh_drawing_typeface)。 如果返回的对象指针为空，则表示字体对象创建失败。失败的原因可能为：没有可用的内存、 传入的文件路径对象指针或字型参数为空、传入的路径无效。


### OH_Drawing_TypefaceCreateFromCurrent()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromCurrent (const OH_Drawing_Typeface* current, const OH_Drawing_FontArguments* fontArguments )
```

**描述**

通过已存在的字体对象创建带有字型参数的字体对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| current | 指向字体对象[OH_Drawing_Typeface](#oh_drawing_typeface)的指针。 | 
| fontArguments | 指向字型参数对象[OH_Drawing_FontArguments](#oh_drawing_fontarguments)的指针。 | 

**返回：**

函数返回一个指针，指针指向创建的字体对象[OH_Drawing_Typeface](#oh_drawing_typeface)。 如果返回的对象指针为空，则表示字体对象创建失败。失败的原因可能为：没有可用的内存、 传入的文件路径对象指针或字型参数为空、传入的字体对象不支持字型参数对象中描述的可变维度。


### OH_Drawing_FontArgumentsAddVariation()

```
OH_Drawing_ErrorCode OH_Drawing_FontArgumentsAddVariation (OH_Drawing_FontArguments* fontArguments, const char* axis, float value )
```

**描述**

给字型参数对象添加可变维度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fontArguments | 指向字型参数对象[OH_Drawing_FontArguments](#oh_drawing_fontarguments)的指针。 | 
| axis | 字型参数对象可变维度的标签，必须为4个ASCII字符。具体可支持的标签取决于加载的字体文件，如'wght'即为字重标签。 | 
| value | 可变维度标签对应的取值。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数fontArguments或axis任意一个为NULL或者axis的长度不为4。


### OH_Drawing_FontArgumentsCreate()

```
OH_Drawing_FontArguments* OH_Drawing_FontArgumentsCreate (void)
```

**描述**

用于创建一个字型参数对象。字型参数用于创建带有自定义属性的字体对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**返回：**

返回一个指针，指针指向创建的字型参数对象。


### OH_Drawing_FontArgumentsDestroy()

```
OH_Drawing_ErrorCode OH_Drawing_FontArgumentsDestroy (OH_Drawing_FontArguments* fontArguments)
```

**描述**

用于销毁一个字型参数对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fontArguments | 指向字型参数对象[OH_Drawing_FontArguments](#oh_drawing_fontarguments)的指针。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数fontArguments为NULL。


### OH_Drawing_TypographyGetLongestLineWithIndent()

```
double OH_Drawing_TypographyGetLongestLineWithIndent (OH_Drawing_Typography* )
```

**描述**

获取排版对象最长行的宽度（该宽度包含当前行缩进的宽度），该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向[OH_Drawing_Typography](#oh_drawing_typography)对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回最长行的宽度（该宽度包含当前行缩进的宽度），单位：物理像素px。



### OH_Drawing_RecordCmdDestroy()

```
OH_Drawing_ErrorCode OH_Drawing_RecordCmdDestroy (OH_Drawing_RecordCmd* recordCmd)
```

**描述**

销毁录制指令对象，并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recordCmd | 指向对象[OH_Drawing_RecordCmd](#oh_drawing_recordcmd)的指针。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数recordCmd为空。


### OH_Drawing_RecordCmdUtilsBeginRecording()

```
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsBeginRecording (OH_Drawing_RecordCmdUtils* recordCmdUtils, int32_t width, int32_t height, OH_Drawing_Canvas** canvas )
```

**描述**

开始录制。此接口需要与[OH_Drawing_RecordCmdUtilsFinishRecording](#oh_drawing_recordcmdutilsfinishrecording)接口成对使用。

指令录制工具生成录制类型的画布对象，可调用drawing的绘制接口，记录接下来所有的绘制指令。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recordCmdUtils | 指向录制工具对象[OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils)的指针。 | 
| width | 画布的宽度。 | 
| height | 画布的高度。 | 
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的二级指针，作为出参，开发者无需释放。 该画布对象不支持嵌套调用[OH_Drawing_CanvasDrawRecordCmd](#oh_drawing_canvasdrawrecordcmd)接口。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS, 表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER, 表示参数recordCmdUtils或者canvas为空。 当width和height小于等于0的时，也会返回OH_DRAWING_ERROR_INVALID_PARAMETER。 返回OH_DRAWING_ERROR_ALLOCATION_FAILED，表示系统内存不足。


### OH_Drawing_RecordCmdUtilsCreate()

```
OH_Drawing_RecordCmdUtils* OH_Drawing_RecordCmdUtilsCreate (void )
```

**描述**

创建一个录制指令工具对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**返回：**

返回用于录制指令的工具对象。


### OH_Drawing_RecordCmdUtilsDestroy()

```
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsDestroy (OH_Drawing_RecordCmdUtils* recordCmdUtils)
```

**描述**

销毁一个录制指令工具对象，并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recordCmdUtils | 指向录制指令工具对象[OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils)的指针。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数recordCmdUtils为空。


### OH_Drawing_RecordCmdUtilsFinishRecording()

```
OH_Drawing_ErrorCode OH_Drawing_RecordCmdUtilsFinishRecording (OH_Drawing_RecordCmdUtils* recordCmdUtils, OH_Drawing_RecordCmd** recordCmd )
```

**描述**

结束录制。在调用此接口前，需要先调用[OH_Drawing_RecordCmdUtilsBeginRecording](#oh_drawing_recordcmdutilsbeginrecording)接口。

指令录制工具结束录制指令，将录制类型画布对象记录的绘制指令存入生成的录制指令对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recordCmdUtils | 指向录制指令工具对象[OH_Drawing_RecordCmdUtils](#oh_drawing_recordcmdutils)的指针。 | 
| recordCmd | 指向录制指令对象[OH_Drawing_RecordCmd](#oh_drawing_recordcmd)的二级指针，作为出参，开发者调用[OH_Drawing_CanvasDrawRecordCmd](#oh_drawing_canvasdrawrecordcmd)接口绘制该对象。 需要调用[OH_Drawing_RecordCmdDestroy](#oh_drawing_recordcmddestroy)接口释放。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数recordCmdUtils或者recordCmd为空。 返回OH_DRAWING_ERROR_ALLOCATION_FAILED，表示系统内存不足。


### OH_Drawing_CanvasDrawRecordCmd()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawRecordCmd (OH_Drawing_Canvas* canvas, OH_Drawing_RecordCmd* recordCmd )
```

**描述**

用于绘制录制指令对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针，仅支持录制类型画布。 | 
| recordCmd | 指向录制指令对象[OH_Drawing_RecordCmd](#oh_drawing_recordcmd)的指针。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者recordCmd为空。



### OH_Drawing_TypographyDestroyTextBox()

```
void OH_Drawing_TypographyDestroyTextBox (OH_Drawing_TextBox* )
```

**描述**

释放文本框占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBox | 指向文本框对象[OH_Drawing_TextBox](#oh_drawing_textbox)的指针。 | 


### OH_Drawing_SetTextShadow()

```
void OH_Drawing_SetTextShadow (OH_Drawing_TextShadow* shadow, uint32_t color, OH_Drawing_Point* offset, double blurRadius )
```

**描述**

设置字体阴影对象的参数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextShadow | 指向字体阴影对象[OH_Drawing_TextShadow](#oh_drawing_textshadow)的指针，由[OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow)获取。 | 
| color | 字体阴影的颜色，例如入参为0xAABBCCDD，AA代表透明度，BB代表红色分量的值，CC代表绿色分量的值，DD代表蓝色分量的值。 | 
| OH_Drawing_Point | 指向坐标点对象[OH_Drawing_Point](#oh_drawing_point)的指针，字体阴影基于当前文本的偏移位置。 | 
| blurRadius | 模糊半径，浮点数，没有单位，值为0.0时表示没有模糊效果。 | 



### OH_Drawing_CanvasDrawSingleCharacter()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawSingleCharacter (OH_Drawing_Canvas* canvas, const char* str, const OH_Drawing_Font* font, float x, float y )
```

**描述**

用于绘制单个字符。当前字型中的字体不支持待绘制字符时，退化到使用系统字体绘制字符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| str | 待绘制的单个字符。可以传入字符串，但只会以UTF-8编码解析并绘制字符串中的首个字符。 | 
| font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| x | 字符对象基线左端点（靠近字符左下角）的横坐标。 | 
| y | 字符对象基线左端点（靠近字符左下角）的纵坐标。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas、str、font任意一个为NULL或者str的长度为0。



### OH_Drawing_FontMeasureSingleCharacter()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureSingleCharacter (const OH_Drawing_Font* font, const char* str, float* textWidth )
```

**描述**

用于测量单个字符的宽度。当前字型中的字体不支持待测量字符时，退化到使用系统字体测量字符宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| str | 待测量的单个字符。可以传入字符串，但只会以UTF-8编码解析并测量字符串中的首个字符。 | 
| textWidth | 用于存储得到的字符宽度。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font、str、textWidth任意一个为NULL或者str的长度为0。


 
### OH_Drawing_TypographyPaintOnPath()

```
void OH_Drawing_TypographyPaintOnPath (OH_Drawing_Typography* , OH_Drawing_Canvas* , OH_Drawing_Path* , double , double  )
```

**描述**

沿路径绘制文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| OH_Drawing_Canvas | 指向OH_Drawing_Canvas对象的指针，由[OH_Drawing_CanvasCreate](#oh_drawing_canvascreate)获取。 | 
| OH_Drawing_Path | 指向OH_Drawing_Path对象的指针，由[OH_Drawing_PathCreate](#oh_drawing_pathcreate)获取。 | 
| double | 沿路径方向偏置，从路径起点向前为正，向后为负。 | 
| double | 沿路径垂直方向偏置，沿路径方向左侧为负，右侧为正。 | 


### OH_Drawing_RoundRectOffset()

```
OH_Drawing_ErrorCode OH_Drawing_RoundRectOffset (OH_Drawing_RoundRect* roundRect, float dx, float dy )
```

**描述**

用于将圆角矩形沿x轴方向和y轴方向平移指定距离。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| roundRect | 指向圆角矩形对象[OH_Drawing_Point2D](_o_h___drawing___point2_d.md)的指针。 | 
| dx | x轴方向偏移量。 | 
| dy | y轴方向偏移量。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数roundRect为空。


### OH_Drawing_PointGetX()

```
OH_Drawing_ErrorCode OH_Drawing_PointGetX (const OH_Drawing_Point* point, float* x )
```

**描述**

用于获取点的x轴坐标。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| point | 指向坐标点对象[OH_Drawing_Point](#oh_drawing_point)的指针。 | 
| x | 表示点的x轴坐标。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数point或者x为空。


### OH_Drawing_PointGetY()

```
OH_Drawing_ErrorCode OH_Drawing_PointGetY (const OH_Drawing_Point* point, float* y )
```

**描述**

用于获取点的y轴坐标。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| point | 指向坐标点对象[OH_Drawing_Point](#oh_drawing_point)的指针。 | 
| y | 表示点的y轴坐标。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数point或者y为空。


### OH_Drawing_PointSet()

```
OH_Drawing_ErrorCode OH_Drawing_PointSet (OH_Drawing_Point* point, float x, float y )
```

**描述**

用于设置点的x轴和y轴坐标。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| point | 指向坐标点对象[OH_Drawing_Point](#oh_drawing_point)的指针。 | 
| x | 表示点的x轴坐标。 | 
| y | 表示点的y轴坐标。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数point为空。


### OH_Drawing_FontMeasureText()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureText (const OH_Drawing_Font* font, const void* text, size_t byteLength, OH_Drawing_TextEncoding encoding, OH_Drawing_Rect* bounds, float* textWidth )
```

**描述**

用于获取文本的宽度和边界框。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| font | 指向字形对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| text | 指向文本的指针。 | 
| byteLength | 表示以字节为单位的文本长度。 | 
| encoding | 文本编码类型。 | 
| bounds | 用于承载获取的边界框，可以为NULL。 | 
| textWidth | 表示文本宽度。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font，text，textWidth至少有一个为空， 或者byteLength为0。


### OH_Drawing_CanvasClipRegion()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasClipRegion (OH_Drawing_Canvas* canvas, const OH_Drawing_Region* region, OH_Drawing_CanvasClipOp clipOp )
```

**描述**

用于裁剪一个区域。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| region | 指向区域对象[OH_Drawing_Region](#oh_drawing_region)的指针。 | 
| clipOp | 表示裁剪类型。支持可选的具体裁剪方式可见[OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop)枚举。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者region为空。返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE，表示clipOp不在枚举范围内。


### OH_Drawing_CanvasDrawColor()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawColor (OH_Drawing_Canvas* canvas, uint32_t color, OH_Drawing_BlendMode blendMode )
```

**描述**

用于使用指定的颜色及混合模式来填充整个画布。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| color | 表示指定的颜色，用一个32位（ARGB）的变量表示。 | 
| blendMode | 表示指定的混合模式。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas为空。返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE，表示blendMode不在枚举范围内。


### OH_Drawing_CanvasGetImageInfo()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasGetImageInfo (OH_Drawing_Canvas* canvas, OH_Drawing_Image_Info* imageInfo )
```

**描述**

用于获取画布的图像信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| imageInfo | 指向图像信息对象[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)的指针。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者imageInfo为空。


### OH_Drawing_CanvasIsClipEmpty()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasIsClipEmpty (OH_Drawing_Canvas* canvas, bool* isClipEmpty )
```

**描述**

用于判断裁剪后可绘制区域是否为空。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| isClipEmpty | 表示裁剪后可绘制区域是否为空。true表示为空，false表示不为空。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者isClipEmpty为空。


### OH_Drawing_CanvasDrawPoint()

```
OH_Drawing_ErrorCode OH_Drawing_CanvasDrawPoint (OH_Drawing_Canvas* canvas, const OH_Drawing_Point2D* point )
```

**描述**

用于画一个点。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| point | 指向点对象[OH_Drawing_Point2D](_o_h___drawing___point2_d.md)的指针。 | 

**返回：**

函数返回执行错误码。 返回OH_DRAWING_SUCCESS，表示执行成功。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数canvas或者point为空。


### OH_Drawing_MatrixGetAll()

```
OH_Drawing_ErrorCode OH_Drawing_MatrixGetAll (OH_Drawing_Matrix* matrix, float value[9] )
```

**描述**

获取矩阵所有元素值。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 |
| value | 用于存储得到的矩阵元素值的数组。 |

**返回：**

返回错误码。 返回OH_DRAWING_SUCCESS，表示成功获取矩阵的所有元素值。 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示获取矩阵元素值失败，原因是矩阵对象或者存储矩阵元素值数组为空。



### OH_Drawing_ErrorCodeGet()

```
OH_Drawing_ErrorCode OH_Drawing_ErrorCodeGet ()
```

**描述**

获取本模块的最近一次的错误码。当函数成功运行后，本函数返回的错误码不会被修改。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

函数返回错误码枚举值。

### OH_Drawing_BrushCopy()

```
OH_Drawing_Brush* OH_Drawing_BrushCopy (OH_Drawing_Brush* brush)
```

**描述**

创建一个画刷对象副本[OH_Drawing_Brush](#oh_drawing_brush)，用于拷贝一个已有画刷对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| brush | 指向画刷对象的指针。 | 

**返回：**

函数会返回一个指针，指针指向创建的画刷对象副本[OH_Drawing_Brush](#oh_drawing_brush)。如果对象返回NULL，表示创建失败； 可能的原因是可用内存为空，或者是brush为NULL。



### OH_Drawing_FilterSetImageFilter()

```
void OH_Drawing_FilterSetImageFilter (OH_Drawing_Filter* , OH_Drawing_ImageFilter* )
```

**描述**

为滤波器对象设置图像滤波器对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Filter为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Filter | 指示指向滤波器对象[OH_Drawing_Filter](#oh_drawing_filter)的指针。 | 
| OH_Drawing_ImageFilter | 指示指向图像滤波器[OH_Drawing_ImageFilter](#oh_drawing_imagefilter)对象的指针，为NULL表示清空滤波器对象中的图像滤波器效果。 | 


### OH_Drawing_ImageFilterCreateBlur()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateBlur (float sigmaX, float sigmaY, OH_Drawing_TileMode , OH_Drawing_ImageFilter* input )
```

**描述**

创建具有模糊效果的图像滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sigmaX | 表示沿x轴方向上高斯模糊的标准差，必须大于0。 | 
| sigmaY | 表示沿y轴方向上高斯模糊的标准差，必须大于0。 | 
| OH_Drawing_TileMode | 图像滤波器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode)枚举。 | 
| input | 表示将要和当前图像滤波器叠加的输入滤波器, 如果为NULL，表示直接将当前图像滤波器作用于原始图像。 | 

**返回：**

函数会返回一个指针，指针指向创建的图像滤波器对象[OH_Drawing_ImageFilter](#oh_drawing_imagefilter)。如果对象返回NULL，表示创建失败； 可能的原因是可用内存为空。


### OH_Drawing_ImageFilterCreateFromColorFilter()

```
OH_Drawing_ImageFilter* OH_Drawing_ImageFilterCreateFromColorFilter (OH_Drawing_ColorFilter* colorFilter, OH_Drawing_ImageFilter* input )
```

**描述**

创建具有颜色变换效果的图像滤波器。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

colorFilter为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| colorFilter | 指向具有颜色变换效果的颜色滤波器对象[OH_Drawing_ColorFilter](#oh_drawing_colorfilter)。 | 
| input | 表示将要和当前图像滤波器叠加的输入滤波器, 如果为NULL，表示直接将当前图像滤波器作用于原始图像。 | 

**返回：**

函数会返回一个指针，指针指向创建的图像滤波器对象[OH_Drawing_ImageFilter](#oh_drawing_imagefilter)。如果对象返回NULL，表示创建失败； 可能的原因是可用内存为空，或者是colorFilter为NULL。


### OH_Drawing_ImageFilterDestroy()

```
void OH_Drawing_ImageFilterDestroy (OH_Drawing_ImageFilter* )
```

**描述**

销毁图像滤波器对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_ImageFilter | 指向图像滤波器对象[OH_Drawing_ImageFilter](#oh_drawing_imagefilter)的指针。 | 


### OH_Drawing_MatrixMapPoints()

```
void OH_Drawing_MatrixMapPoints (const OH_Drawing_Matrix* , const OH_Drawing_Point2D* src, OH_Drawing_Point2D* dst, int count )
```

**描述**

通过矩阵变换将源点数组映射到目标点数组。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix、src、dst任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| src | 源点数组。 | 
| dst | 目标点数组，个数要与源点相等。 | 
| count | 源点数组以及目标点数组的个数。 | 


### OH_Drawing_MatrixMapRect()

```
bool OH_Drawing_MatrixMapRect (const OH_Drawing_Matrix* , const OH_Drawing_Rect* src, OH_Drawing_Rect* dst )
```

**描述**

将目标矩形设置为一个新的矩形，该矩形是能够包围源矩形的四个顶点通过矩阵变换映射后形成的新顶点的最小矩形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix、src、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| src | 源矩形。 | 
| dst | 目标矩形。 | 

**返回：**

函数返回源矩形与映射后的目标矩形是否相等。true表示相等，false表示不相等。


### OH_Drawing_PathAddPolygon()

```
void OH_Drawing_PathAddPolygon (OH_Drawing_Path* path, const OH_Drawing_Point2D* points, uint32_t count, bool isClosed )
```

**描述**

向路径添加多边形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path、points任意一个为NULL或者count等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向当前路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| points | 表示多边形的顶点坐标数组。 | 
| count | 表示多边形顶点坐标数组的大小。 | 
| isClosed | 是否添加连接起始点和终止点的线，true表示添加，false表示不添加。 | 


### OH_Drawing_PathAddCircle()

```
void OH_Drawing_PathAddCircle (OH_Drawing_Path* path, float x, float y, float radius, OH_Drawing_PathDirection  )
```

**描述**

按指定方向，向路径添加圆形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

radius小于等于0时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE；

OH_Drawing_PathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| x | 表示圆心的x轴坐标。 | 
| y | 表示圆心的y轴坐标。 | 
| radius | 表示圆形的半径。 | 
| OH_Drawing_PathDirection | 路径方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)。 | 


### OH_Drawing_PathBuildFromSvgString()

```
bool OH_Drawing_PathBuildFromSvgString (OH_Drawing_Path* path, const char* str )
```

**描述**

解析SVG字符串表示的路径。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path、str任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| str | 表示SVG字符串。 | 

**返回：**

函数返回解析SVG字符串是否成功。true表示成功，false表示不成功。


### OH_Drawing_PathGetBounds()

```
void OH_Drawing_PathGetBounds (OH_Drawing_Path* , OH_Drawing_Rect*  )
```

**描述**

获取包含路径的最小边界框。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。 | 


### OH_Drawing_PathIsClosed()

```
bool OH_Drawing_PathIsClosed (OH_Drawing_Path* path, bool forceClosed )
```

**描述**

获取路径是否闭合。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| forceClosed | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 | 

**返回：**

返回路径是否闭合。true表示路径的测量结果为已闭合，false表示路径的测量结果为未闭合。


### OH_Drawing_PathGetPositionTangent()

```
bool OH_Drawing_PathGetPositionTangent (OH_Drawing_Path* path, bool forceClosed, float distance, OH_Drawing_Point2D* position, OH_Drawing_Point2D* tangent )
```

**描述**

获取距路径起始点指定距离的坐标点和切线值。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path、position、tangent任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| forceClosed | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 | 
| distance | 表示距离起始点的距离，小于0时会被视作0，大于路径长度时会被视作路径长度。 | 
| position | 表示距路径起始点指定距离的坐标点。 | 
| tangent | 表示距路径起始点指定距离的切线值，tangent.x表示该点切线的余弦值，tangent.y表示该点切线的正弦值。 | 

**返回：**

返回测量是否成功。true表示成功，false表示失败。


### OH_Drawing_PathOp()

```
bool OH_Drawing_PathOp (OH_Drawing_Path* path, const OH_Drawing_Path* other, OH_Drawing_PathOpMode op )
```

**描述**

将两个路径按照指定的路径操作类型合并。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

op不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针，操作完成后的路径结果将会保存在此路径对象中。 | 
| other | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| op | 路径操作枚举类型，支持可选的具体模式可见[OH_Drawing_PathOpMode](#oh_drawing_pathopmode)枚举。 | 

**返回：**

返回操作后的路径是否为空。true表示路径不为空，false表示路径为空。


### OH_Drawing_PathGetMatrix()

```
bool OH_Drawing_PathGetMatrix (OH_Drawing_Path* path, bool forceClosed, float distance, OH_Drawing_Matrix* matrix, OH_Drawing_PathMeasureMatrixFlags flag )
```

**描述**

获取距路径起始点指定距离的相应变换矩阵。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path、matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

flag不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| forceClosed | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 | 
| distance | 表示距离起始点的距离，小于0时会被视作0，大于路径长度时会被视作路径长度。 | 
| matrix | 表示要获取的变换矩阵。 | 
| flag | 矩阵信息维度枚举，支持可选的具体模式可见[OH_Drawing_PathMeasureMatrixFlags](#oh_drawing_pathmeasurematrixflags)枚举。 | 

**返回：**

返回获取变换矩阵是否成功。true表示获取成功，false表示获取失败，失败的原因可能是path为NULL或者长度为0。


### OH_Drawing_PenGetFillPath()

```
bool OH_Drawing_PenGetFillPath (OH_Drawing_Pen* , const OH_Drawing_Path* src, OH_Drawing_Path* dst, const OH_Drawing_Rect* , const OH_Drawing_Matrix*  )
```

**描述**

获取使用画笔绘制的源路径轮廓，并用目标路径表示。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen、src、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象[OH_Drawing_Pen](#oh_drawing_pen)的指针。 | 
| src | 指向源路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| dst | 指向目标路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针，推荐使用NULL。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针，推荐使用NULL, 默认是一个单位矩阵。 | 

**返回：**

获取目标路径是否成功。true表示获取成功，false表示获取失败。


### OH_Drawing_PenCopy()

```
OH_Drawing_Pen* OH_Drawing_PenCopy (OH_Drawing_Pen* pen)
```

**描述**

创建一个画笔对象副本[OH_Drawing_Pen](#oh_drawing_pen)，用于拷贝一个已有画笔对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pen | 指向画笔对象的指针。 | 

**返回：**

函数会返回一个指针，指针指向创建的画笔对象副本[OH_Drawing_Pen](#oh_drawing_pen)。如果对象返回NULL，表示创建失败； 可能的原因是可用内存为空，或者是pen为NULL。


### OH_Drawing_PixelMapGetFromNativePixelMap()

```
OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromNativePixelMap (NativePixelMap_* )
```

**描述**

从图像框架定义的像素图对象中获取本模块定义的像素图对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| NativePixelMap_ | 指向图像框架定义的像素图对象**NativePixelMap_**的指针。 | 

**返回：**

函数会返回一个指向本模块定义的像素图对象[OH_Drawing_PixelMap](#oh_drawing_pixelmap)的指针。如果对象返回NULL，表示创建失败； 可能的原因是NativePixelMap_为NULL。


### OH_Drawing_PixelMapGetFromOhPixelMapNative()

```
OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromOhPixelMapNative (OH_PixelmapNative* )
```

**描述**

从图像框架定义的像素图对象中获取本模块定义的像素图对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_PixelmapNative | 指向图像框架定义的像素图对象**OH_PixelmapNative**的指针。 | 

**返回：**

函数会返回一个指向本模块定义的像素图对象[OH_Drawing_PixelMap](#oh_drawing_pixelmap)的指针。如果对象返回NULL，表示创建失败； 可能的原因是OH_PixelmapNative为NULL。


### OH_Drawing_PixelMapDissolve()

```
void OH_Drawing_PixelMapDissolve (OH_Drawing_PixelMap* )
```

**描述**

解除本模块定义的像素图对象和图像框架定义的像素图对象之间的关系，该关系通过调用 [OH_Drawing_PixelMapGetFromNativePixelMap](#oh_drawing_pixelmapgetfromnativepixelmap)或[OH_Drawing_PixelMapGetFromOhPixelMapNative](#oh_drawing_pixelmapgetfromohpixelmapnative)建立。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_PixelMap | 指向像素图对象[OH_Drawing_PixelMap](#oh_drawing_pixelmap)的指针。 | 


### OH_Drawing_RectJoin()

```
bool OH_Drawing_RectJoin (OH_Drawing_Rect* rect, const OH_Drawing_Rect* other )
```

**描述**

将两个矩形取并集。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

rect、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rect | 指向矩形对象的指针。 | 
| other | 指向矩形对象的指针。 | 

**返回：**

返回两个矩形取并集的结果。true表示成功，false表示失败，失败的原因可能是两个矩形至少有一个为NULL或者other矩形大小为空。


### OH_Drawing_RegionContains()

```
bool OH_Drawing_RegionContains (OH_Drawing_Region* region, int32_t x, int32_t y )
```

**描述**

判断区域是否包含指定坐标点。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

region为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| region | 指向区域对象[OH_Drawing_Region](#oh_drawing_region)的指针。 | 
| int32_t | 表示指定坐标点的x轴坐标。 | 
| int32_t | 表示指定坐标点的y轴坐标。 | 

**返回：**

返回区域是否包含指定坐标点。true表示区域包含该坐标点，false表示区域不包含该坐标点。


### OH_Drawing_RegionOp()

```
bool OH_Drawing_RegionOp (OH_Drawing_Region* region, const OH_Drawing_Region* other, OH_Drawing_RegionOpMode op )
```

**描述**

将两个区域按照指定的区域操作类型合并。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

region、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

op不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| region | 指向区域对象[OH_Drawing_Region](#oh_drawing_region)的指针，操作完成后的区域结果将会保存在此区域对象中。 | 
| other | 指向区域对象[OH_Drawing_Region](#oh_drawing_region)的指针。 | 
| op | 区域操作枚举类型，支持可选的具体模式可见[OH_Drawing_RegionOpMode](#oh_drawing_regionopmode)枚举。 | 

**返回：**

返回操作后的区域是否为空。true表示区域不为空，false表示区域为空。


### OH_Drawing_RegionSetPath()

```
bool OH_Drawing_RegionSetPath (OH_Drawing_Region* region, const OH_Drawing_Path* path, const OH_Drawing_Region* clip )
```

**描述**

给区域对象设置为指定区域内路径表示的范围。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

region、path、clip任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| region | 指向区域对象[OH_Drawing_Region](#oh_drawing_region)的指针。 | 
| path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| clip | 指向区域对象[OH_Drawing_Region](#oh_drawing_region)的指针。 | 

**返回：**

返回操作后的区域是否为空。true表示区域不为空，false表示区域为空。


### OH_Drawing_ShaderEffectCreateColorShader()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateColorShader (const uint32_t color)
```

**描述**

创建具有单一颜色的着色器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| color | 表示着色器的ARGB格式颜色，该参数为32位无符号整数。| 

**返回：**

函数会返回一个指针，指针指向创建的着色器对象[OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)。如果对象返回NULL，表示创建失败； 可能的原因是可用内存为空。


### OH_Drawing_ShaderEffectCreateLinearGradientWithLocalMatrix()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateLinearGradientWithLocalMatrix (const OH_Drawing_Point2D* startPt, const OH_Drawing_Point2D* endPt, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode , const OH_Drawing_Matrix*  )
```

**描述**

创建着色器，在两个指定点之间生成线性渐变。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

startPt、endPt、colors任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

OH_Drawing_TileMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| startPt | 表示渐变的起点。 | 
| endPt | 表示渐变的终点。 | 
| colors | 表示在两个点之间分布的颜色。 | 
| pos | 表示每种对应颜色在颜色数组中的相对位置，如果pos为NULL, 颜色均匀分布在起点和终点之间。 | 
| size | 表示颜色和位置的数量(如果pos不为NULL)。 | 
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode)枚举。 | 
| OH_Drawing_Matrix | 表示作用于着色器上的矩阵变换，如果matrix是NULL, 默认是一个单位矩阵。 | 

**返回：**

函数会返回一个指针，指针指向创建的着色器对象[OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)。如果对象返回NULL，表示创建失败； 可能的原因是可用内存为空，或者是startPt、endPt、colors至少一个为NULL。


### OH_Drawing_ShaderEffectCreateRadialGradientWithLocalMatrix()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateRadialGradientWithLocalMatrix (const OH_Drawing_Point2D* centerPt, float radius, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode , const OH_Drawing_Matrix*  )
```

**描述**

创建着色器，在给定圆心和半径的情况下生成径向渐变。 从起点到终点颜色从内到外进行圆形渐变（从中间向外拉）被称为径向渐变。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

centerPt、colors任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

OH_Drawing_TileMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| centerPt | 表示渐变的圆心。 | 
| radius | 表示渐变的半径。 | 
| colors | 表示在径向上分布的颜色。 | 
| pos | 表示每种对应颜色在颜色数组中的相对位置，如果pos为NULL, 颜色均匀分布在径向上。 | 
| size | 表示颜色和位置的数量(如果pos不为NULL)。 | 
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode)枚举。 | 
| OH_Drawing_Matrix | 表示作用于着色器上的矩阵变换，如果matrix是NULL, 默认是一个单位矩阵。 | 

**返回：**

函数会返回一个指针，指针指向创建的着色器对象[OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)。如果对象返回NULL，表示创建失败； 可能的原因是可用内存为空，或者是centerPt、colors至少一个为NULL。


### OH_Drawing_ShaderEffectCreateTwoPointConicalGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateTwoPointConicalGradient (const OH_Drawing_Point2D* startPt, float startRadius, const OH_Drawing_Point2D* endPt, float endRadius, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode , const OH_Drawing_Matrix*  )
```

**描述**

创建着色器，在给定两个圆之间生成渐变。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

startPt、endPt、colors任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

OH_Drawing_TileMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| startPt | 表示渐变的起点圆心。 | 
| startRadius | 表示渐变的起点半径，需为非负数。 | 
| endPt | 表示渐变的终点圆心。 | 
| endRadius | 表示渐变的终点半径，需为非负数。 | 
| colors | 表示在两个圆之间分布的颜色。 | 
| pos | 表示每种对应颜色在颜色数组中的相对位置，如果pos为NULL, 颜色均匀分布在两个圆之间。 | 
| size | 表示颜色和位置的数量(如果pos不为NULL)。 | 
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode-1)枚举。 | 
| OH_Drawing_Matrix | 表示作用于着色器上的矩阵变换，如果matrix是NULL, 默认是一个单位矩阵。 | 

**返回：**

函数会返回一个指针，指针指向创建的着色器对象[OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)。如果对象返回NULL，表示创建失败； 可能的原因是可用内存为空，或者是startPt、endPt、colors至少一个为NULL。



### OH_Drawing_TextBlobUniqueID()

```
uint32_t OH_Drawing_TextBlobUniqueID (const OH_Drawing_TextBlob* )
```

**描述**

获取文本的标识符，该标识符是唯一的非零值。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_TextBlob为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBlob | 指向文本对象[OH_Drawing_TextBlob](#oh_drawing_textblob)的指针。 | 

**返回：**

返回文本对象的标识符。


### OH_Drawing_PenSetShadowLayer()

```
void OH_Drawing_PenSetShadowLayer (OH_Drawing_Pen* , OH_Drawing_ShadowLayer* )
```

**描述**

设置画笔阴影层效果，设置的阴影层效果当前仅在绘制文字时生效。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象[OH_Drawing_Pen](#oh_drawing_pen)的指针。 | 
| OH_Drawing_ShadowLayer | 指向阴影层对象[OH_Drawing_ShadowLayer](#oh_drawing_shadowlayer)的指针，为NULL表示清空阴影层效果。 | 


### OH_Drawing_BrushSetShadowLayer()

```
void OH_Drawing_BrushSetShadowLayer (OH_Drawing_Brush* , OH_Drawing_ShadowLayer* )
```

**描述**

为画刷设置阴影层，设置的阴影层效果当前仅在绘制文字时生效。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 | 
| OH_Drawing_ShadowLayer | 表示指向阴影层的指针，为NULL表示清空画刷的阴影层效果。 | 


### OH_Drawing_ShadowLayerCreate()

```
OH_Drawing_ShadowLayer* OH_Drawing_ShadowLayerCreate (float blurRadius, float x, float y, uint32_t color )
```

**描述**

创建一个阴影层对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

blurRadius小于0等于时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| blurRadius | 表示阴影的半径，必须大于零。 | 
| x | 表示x轴上的偏移点。 | 
| y | 表示y轴上的偏移点。 | 
| color | 表示阴影的颜色。 | 

**返回：**

返回创建的阴影层对象的指针。


### OH_Drawing_ShadowLayerDestroy()

```
void OH_Drawing_ShadowLayerDestroy (OH_Drawing_ShadowLayer* )
```

**描述**

销毁阴影层对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_ShadowLayer | 表示指向阴影层对象的指针。 | 


### OH_Drawing_FontSetBaselineSnap()

```
void OH_Drawing_FontSetBaselineSnap (OH_Drawing_Font* , bool baselineSnap )
```

**描述**

当前画布矩阵轴对齐时，将字型基线设置为是否与像素对齐。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| baselineSnap | 指示字型基线是否和像素对齐，true表示对齐，false表示不对齐。 | 


### OH_Drawing_FontIsBaselineSnap()

```
bool OH_Drawing_FontIsBaselineSnap (const OH_Drawing_Font* )
```

**描述**

当前画布矩阵轴对齐时，获取字型基线是否与像素对齐。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回字型基线是否与像素对齐，true为对齐，false为没有对齐。


### OH_Drawing_FontSetEdging()

```
void OH_Drawing_FontSetEdging (OH_Drawing_Font* , OH_Drawing_FontEdging  )
```

**描述**

用于设置字型边缘效果。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_FontEdging不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| OH_Drawing_FontEdging | 字型边缘效果。 | 


### OH_Drawing_FontGetEdging()

```
OH_Drawing_FontEdging OH_Drawing_FontGetEdging (const OH_Drawing_Font* )
```

**描述**

获取字型边缘效果。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回字型边缘效果。



### OH_Drawing_FontSetForceAutoHinting()

```
void OH_Drawing_FontSetForceAutoHinting (OH_Drawing_Font* , bool isForceAutoHinting )
```

**描述**

用于设置是否自动调整字型轮廓。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| isForceAutoHinting | 是否自动调整字型轮廓，true为自动调整，false为不自动调整。 | 


### OH_Drawing_FontIsForceAutoHinting()

```
bool OH_Drawing_FontIsForceAutoHinting (const OH_Drawing_Font* )
```

**描述**

获取字型轮廓是否自动调整。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回字型轮廓是否自动调整，true为自动调整，false为不自动调整。


### OH_Drawing_FontSetSubpixel()

```
void OH_Drawing_FontSetSubpixel (OH_Drawing_Font* , bool isSubpixel )
```

**描述**

设置字型是否使用次像素渲染。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| isSubpixel | 字型是否使用次像素渲染，true为使用，false为不使用。 | 


### OH_Drawing_FontIsSubpixel()

```
bool OH_Drawing_FontIsSubpixel (const OH_Drawing_Font* )
```

**描述**

获取字型是否使用次像素渲染。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回字型是否使用次像素渲染，true为使用，false为不使用。


### OH_Drawing_FontGetTextSize()

```
float OH_Drawing_FontGetTextSize (const OH_Drawing_Font* )
```

**描述**

获取字型文字大小。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回一个浮点数，表示字型文字大小。


### OH_Drawing_FontTextToGlyphs()

```
uint32_t OH_Drawing_FontTextToGlyphs (const OH_Drawing_Font* , const void* text, uint32_t byteLength, OH_Drawing_TextEncoding encoding, uint16_t* glyphs, int maxGlyphCount )
```

**描述**

用于将文本转换为字形索引。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font、text、glyphs任意一个为NULL或者byteLength等于0或者maxGlyphCount小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| text | 文本存储首地址。 | 
| byteLength | 文本长度，单位为字节。 | 
| encoding | 文本编码类型[OH_Drawing_TextEncoding](#oh_drawing_textencoding)。 | 
| glyphs | 字形索引存储首地址，用于存储得到的字形索引。 | 
| maxGlyphCount | 文本所表示的最大字符数量。 | 

**返回：**

返回字形索引数量。


### OH_Drawing_FontGetWidths()

```
void OH_Drawing_FontGetWidths (const OH_Drawing_Font* , const uint16_t* glyphs, int count, float* widths )
```

**描述**

用于获取字符串中每个字符的宽度。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font、glyphs、widths任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| glyphs | 字形索引存储首地址。 | 
| count | 字形索引的数量。 | 
| widths | 字形宽度存储首地址，用于存储得到的字形宽度。 | 


### OH_Drawing_FontIsLinearText()

```
bool OH_Drawing_FontIsLinearText (const OH_Drawing_Font* )
```

**描述**

获取字型是否使用线性缩放。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回字型是否使用线性缩放，true为使用，false为不使用。


### OH_Drawing_FontGetTextSkewX()

```
float OH_Drawing_FontGetTextSkewX (const OH_Drawing_Font* )
```

**描述**

获取字型文本在x轴上的倾斜度。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回一个浮点数，表示x轴上的文本倾斜度。


### OH_Drawing_FontIsFakeBoldText()

```
bool OH_Drawing_FontIsFakeBoldText (const OH_Drawing_Font* )
```

**描述**

获取是否增加笔画宽度以接近粗体字体。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回是否增加笔画宽度以接近粗体字体，true为增加，false为不增加。


### OH_Drawing_FontSetScaleX()

```
void OH_Drawing_FontSetScaleX (OH_Drawing_Font* , float scaleX )
```

**描述**

用于设置字型对象在x轴上的缩放比例。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| scaleX | 文本在x轴上的缩放比例。 | 


### OH_Drawing_FontGetScaleX()

```
float OH_Drawing_FontGetScaleX (const OH_Drawing_Font* )
```

**描述**

获取字型对象在x轴上的缩放比例。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回文本在x轴上的缩放比例。


### OH_Drawing_FontSetHinting()

```
void OH_Drawing_FontSetHinting (OH_Drawing_Font* , OH_Drawing_FontHinting  )
```

**描述**

用于设置字型轮廓效果。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_FontHinting不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| OH_Drawing_FontHinting | 字型轮廓枚举类型[OH_Drawing_FontHinting](#oh_drawing_fonthinting)。 | 


### OH_Drawing_FontGetHinting()

```
OH_Drawing_FontHinting OH_Drawing_FontGetHinting (const OH_Drawing_Font* )
```

**描述**

获取字型轮廓效果枚举类型。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

OH_Drawing_FontHinting 返回字型轮廓效果枚举类型[OH_Drawing_FontHinting](#oh_drawing_fonthinting)。


### OH_Drawing_FontSetEmbeddedBitmaps()

```
void OH_Drawing_FontSetEmbeddedBitmaps (OH_Drawing_Font* , bool isEmbeddedBitmaps )
```

**描述**

用于设置字型是否转换成位图处理。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| isEmbeddedBitmaps | 设置字型是否转换成位图处理，true表示转换成位图处理，false表示不转换成位图处理。 | 


### OH_Drawing_FontIsEmbeddedBitmaps()

```
bool OH_Drawing_FontIsEmbeddedBitmaps (const OH_Drawing_Font* )
```

**描述**

获取字型是否转换成位图处理。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

返回字型是否转换成位图处理，true表示转换成位图处理，false表示不转换成位图处理。


### OH_Drawing_BitmapBuild()

```
void OH_Drawing_BitmapBuild (OH_Drawing_Bitmap* , const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat*  )
```

**描述**

用于初始化位图对象的宽度和高度，并且为该位图设置像素格式。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Bitmap、OH_Drawing_BitmapFormat任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 | 
| width | 位图要初始化设置的宽度。 | 
| height | 位图要初始化设置的高度。 | 
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | 位图要初始化设置的像素格式，包括像素的颜色类型和透明度类型。 | 


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


### OH_Drawing_BitmapCreateFromPixels()

```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreateFromPixels (OH_Drawing_Image_Info* , void* pixels, uint32_t rowBytes )
```

**描述**

用于创建一个位图对象，并将位图像素存储内存地址设置为开发者申请内存的地址。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Image_Info、pixels任意一个为NULL或者rowBytes等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Image_Info | 指向图片信息对象[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)的指针。 | 
| pixels | 指向像素存储的内存首地址，内存由开发者申请，保证有效性。 | 
| rowBytes | 每行像素的大小，小于等于0时无效。 | 

**返回：**

函数返回一个指针，指针指向创建的位图对象[OH_Drawing_Bitmap](#oh_drawing_bitmap)。


### OH_Drawing_BitmapDestroy()

```
void OH_Drawing_BitmapDestroy (OH_Drawing_Bitmap* )
```

**描述**

用于销毁位图对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 | 


### OH_Drawing_BitmapGetAlphaFormat()

```
OH_Drawing_AlphaFormat OH_Drawing_BitmapGetAlphaFormat (OH_Drawing_Bitmap* )
```

**描述**

用于获取指定位图的像素透明度分量。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 | 

**返回：**

函数返回位图的像素透明度分量，支持格式参考[OH_Drawing_AlphaFormat](#oh_drawing_alphaformat)。


### OH_Drawing_BitmapGetColorFormat()

```
OH_Drawing_ColorFormat OH_Drawing_BitmapGetColorFormat (OH_Drawing_Bitmap* )
```

**描述**

用于获取指定位图的像素存储格式。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 | 

**返回：**

函数返回位图的像素存储格式，支持格式参考[OH_Drawing_ColorFormat](#oh_drawing_colorformat)。


### OH_Drawing_BitmapGetHeight()

```
uint32_t OH_Drawing_BitmapGetHeight (OH_Drawing_Bitmap* )
```

**描述**

用于获取指定位图的高度。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 | 

**返回：**

函数返回位图的高度。


### OH_Drawing_BitmapGetImageInfo()

```
void OH_Drawing_BitmapGetImageInfo (OH_Drawing_Bitmap* , OH_Drawing_Image_Info*  )
```

**描述**

用于获取指定位图的信息。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Bitmap、OH_Drawing_Image_Info任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象[OH_Drawing_Bitmap](#oh_drawing_bitmap)的指针。 | 
| OH_Drawing_Image_Info | 指向图片信息对象[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)的指针。 | 


### OH_Drawing_BitmapGetPixels()

```
void* OH_Drawing_BitmapGetPixels (OH_Drawing_Bitmap* )
```

**描述**

用于获取指定位图的像素地址，可以通过像素地址获取到位图的像素数据。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
uint32_t OH_Drawing_BitmapGetWidth (OH_Drawing_Bitmap* )
```

**描述**

用于获取指定位图的宽度。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Bitmap为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象的指针。 | 

**返回：**

函数返回位图的宽度。

### OH_Drawing_BitmapReadPixels()

```
bool OH_Drawing_BitmapReadPixels (OH_Drawing_Bitmap* , const OH_Drawing_Image_Info* dstInfo, void* dstPixels, size_t dstRowBytes, int32_t srcX, int32_t srcY )
```

**描述**

将位图中的矩形区域像素数据读取到指定的内存缓冲区中。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Bitmap、dstInfo、dstPixels任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Bitmap | 指向位图对象[OH_Drawing_Bitmap](#oh_drawing_bitmap)的指针。 | 
| OH_Drawing_Image_Info | 指向图片信息对象[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)的指针。 | 
| dstPixels | 目标像素存储区域。 | 
| dstRowBytes | 目标像素数据每行的字节数，应大于或等于图片信息对象中的最小每行字节数。 | 
| srcX | 源位图中读取像素数据的起始x轴坐标，应小于源位图的宽度。 | 
| srcY | 源位图中读取像素数据的起始y轴坐标，应小于源位图的高度。 | 

**返回：**

返回接口调用成功与否的结果。true表示复制成功，false表示复制失败。


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
void OH_Drawing_BrushDestroy (OH_Drawing_Brush* )
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
uint8_t OH_Drawing_BrushGetAlpha (const OH_Drawing_Brush* )
```

**描述**

获取画刷的透明度值。画刷在填充形状时透明通道会使用该值。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
uint32_t OH_Drawing_BrushGetColor (const OH_Drawing_Brush* )
```

**描述**

用于获取画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 | 

**返回：**

函数返回一个描述颜色的32位（ARGB）变量。


### OH_Drawing_BrushGetFilter()

```
void OH_Drawing_BrushGetFilter (OH_Drawing_Brush* , OH_Drawing_Filter*  )
```

**描述**

从画刷获取滤波器[OH_Drawing_Filter](#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush、OH_Drawing_Filter任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象[OH_Drawing_Brush](#oh_drawing_brush)的指针。 | 
| OH_Drawing_Filter | 表示指向滤波器对象[OH_Drawing_Filter](#oh_drawing_filter)的指针。 | 


### OH_Drawing_BrushIsAntiAlias()

```
bool OH_Drawing_BrushIsAntiAlias (const OH_Drawing_Brush* )
```

**描述**

用于获取画刷是否设置抗锯齿属性，如果为真则说明画刷会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 | 

**返回：**

函数返回画刷对象是否设置抗锯齿属性，返回真则设置了抗锯齿，返回假则没有设置抗锯齿。


### OH_Drawing_BrushReset()

```
void OH_Drawing_BrushReset (OH_Drawing_Brush* )
```

**描述**

将画刷重置至初始状态，清空所有已设置的属性。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象[OH_Drawing_Brush](#oh_drawing_brush)的指针。 | 


### OH_Drawing_BrushSetAlpha()

```
void OH_Drawing_BrushSetAlpha (OH_Drawing_Brush* , uint8_t alpha )
```

**描述**

为画刷设置透明度值。画刷在填充形状时透明通道会使用该值。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 | 
| alpha | 表示要设置的透明度值，是一个8位变量。 | 


### OH_Drawing_BrushSetAntiAlias()

```
void OH_Drawing_BrushSetAntiAlias (OH_Drawing_Brush* , bool  )
```

**描述**

用于设置画刷的抗锯齿属性，设置为真则画刷在绘制图形时会对图形的边缘像素进行半透明的模糊处理。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 | 
| bool | 真为抗锯齿，假则不做抗锯齿处理。 | 


### OH_Drawing_BrushSetBlendMode()

```
void OH_Drawing_BrushSetBlendMode (OH_Drawing_Brush* , OH_Drawing_BlendMode  )
```

**描述**

为画刷设置一个混合器，该混合器实现了指定的混合模式枚举。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_BlendMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象[OH_Drawing_Brush](#oh_drawing_brush)的指针。 | 
| OH_Drawing_BlendMode | 混合模式枚举类型[OH_Drawing_BlendMode](#oh_drawing_blendmode)。 | 


### OH_Drawing_BrushSetColor()

```
void OH_Drawing_BrushSetColor (OH_Drawing_Brush* , uint32_t color )
```

**描述**

用于设置画刷的颜色属性，颜色属性描述了画刷填充图形时使用的颜色，用一个32位（ARGB）的变量表示。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 | 
| color | 描述颜色的32位（ARGB）变量。 | 


### OH_Drawing_BrushSetFilter()

```
void OH_Drawing_BrushSetFilter (OH_Drawing_Brush* , OH_Drawing_Filter*  )
```

**描述**

为画刷设置滤波器[OH_Drawing_Filter](#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 | 
| OH_Drawing_Filter | 表示指向滤波器对象的指针，为NULL表示清空画刷滤波器。 | 


### OH_Drawing_BrushSetShaderEffect()

```
void OH_Drawing_BrushSetShaderEffect (OH_Drawing_Brush* , OH_Drawing_ShaderEffect*  )
```

**描述**

为画刷设置着色器效果。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Brush为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Brush | 指向画刷对象的指针。 | 
| OH_Drawing_ShaderEffect | 表示指向着色器对象的指针，为NULL表示清空画刷的着色器效果。 | 


### OH_Drawing_CanvasAttachBrush()

```
void OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas* , const OH_Drawing_Brush*  )
```

**描述**

用于设置画刷给画布，画布将会使用设置的画刷样式和颜色去填充绘制的图形形状。执行该方法后，若画刷的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Brush任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Brush | 指向画刷对象的指针。 | 


### OH_Drawing_CanvasAttachPen()

```
void OH_Drawing_CanvasAttachPen (OH_Drawing_Canvas* , const OH_Drawing_Pen*  )
```

**描述**

用于设置画笔给画布，画布将会使用设置画笔的样式和颜色去绘制图形形状的轮廓。执行该方法后，若画笔的效果发生改变并且开发者希望该变化生效于接下来的绘制动作，需要再次执行该方法以确保变化生效。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Pen任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Pen | 指向画笔对象的指针。 | 


### OH_Drawing_CanvasBind()

```
void OH_Drawing_CanvasBind (OH_Drawing_Canvas* , OH_Drawing_Bitmap*  )
```

**描述**

用于将一个位图对象绑定到画布中，使得画布绘制的内容输出到位图中（即CPU渲染）。绑定位图对象后的画布为非录制类型画布。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Bitmap | 指向位图对象的指针。 | 


### OH_Drawing_CanvasClear()

```
void OH_Drawing_CanvasClear (OH_Drawing_Canvas* , uint32_t color )
```

**描述**

用于使用指定颜色去清空画布。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| color | 描述颜色的32位（ARGB）变量。 | 


### OH_Drawing_CanvasClipPath()

```
void OH_Drawing_CanvasClipPath (OH_Drawing_Canvas* , const OH_Drawing_Path* , OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias )
```

**描述**

用于裁剪一个自定义路径。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Path | 指向路径对象的指针。 | 
| clipOp | 裁剪方式。支持可选的具体裁剪方式可见[OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop)枚举。 | 
| doAntiAlias | 真为抗锯齿，假则不做抗锯齿处理。 | 


### OH_Drawing_CanvasClipRect()

```
void OH_Drawing_CanvasClipRect (OH_Drawing_Canvas* , const OH_Drawing_Rect* , OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias )
```

**描述**

用于裁剪一个矩形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Rect | 指向矩形对象的指针。 | 
| clipOp | 裁剪方式。支持可选的具体裁剪方式可见[OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop)枚举。 | 
| doAntiAlias | 值为true则做抗锯齿处理，反之不做。 | 

### OH_Drawing_CanvasClipRoundRect()

```
void OH_Drawing_CanvasClipRoundRect (OH_Drawing_Canvas* , const OH_Drawing_RoundRect* , OH_Drawing_CanvasClipOp clipOp, bool doAntiAlias )
```

**描述**

用于裁剪一个圆角矩形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_RoundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

clipOp不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_RoundRect | 指向圆角矩形对象的指针。 | 
| clipOp | 裁剪方式。支持可选的具体裁剪方式可见[OH_Drawing_CanvasClipOp](#oh_drawing_canvasclipop)枚举。 | 
| doAntiAlias | 表示是否需要做抗锯齿处理，值为true时为需要，为false时为不需要。 | 

### OH_Drawing_CanvasConcatMatrix()

```
void OH_Drawing_CanvasConcatMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**描述**

画布现有矩阵左乘以传入矩阵，不影响该接口之前的绘制操作。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 


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
void OH_Drawing_CanvasDestroy (OH_Drawing_Canvas* )
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
void OH_Drawing_CanvasDetachBrush (OH_Drawing_Canvas* )
```

**描述**

用于去除掉画布中的画刷，使用后画布将不使用此前设置的画刷去填充图形形状。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 


### OH_Drawing_CanvasDetachPen()

```
void OH_Drawing_CanvasDetachPen (OH_Drawing_Canvas* )
```

**描述**

用于去除掉画布中的画笔，使用后画布将不去绘制图形形状的轮廓。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 


### OH_Drawing_CanvasDrawArc()

```
void OH_Drawing_CanvasDrawArc (OH_Drawing_Canvas* , const OH_Drawing_Rect* , float startAngle, float sweepAngle )
```

**描述**

用于画一个弧。当扫描角度的绝对值大于360度时，本接口绘制的是一个椭圆。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Rect | 指向矩形对象的指针。 | 
| startAngle | 弧的起始角度，0度时起始点位于椭圆的右端点，正数时以顺时针方向放置起始点，负数时以逆时针方向放置起始点。 | 
| sweepAngle | 弧的扫描角度，正数时顺时针扫描，负数时逆时针扫描。它的有效范围在-360度到360度之间，当绝对值大于360度时，该函数绘制的是一个椭圆。 | 


### OH_Drawing_CanvasDrawBackground()

```
void OH_Drawing_CanvasDrawBackground (OH_Drawing_Canvas* , const OH_Drawing_Brush*  )
```

**描述**

用于画一个背景，此背景以画刷填充。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Brush任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Brush | 指向画刷对象的指针。 | 


### OH_Drawing_CanvasDrawBitmap()

```
void OH_Drawing_CanvasDrawBitmap (OH_Drawing_Canvas* , const OH_Drawing_Bitmap* , float left, float top )
```

**描述**

用于画一个位图，位图又称为点阵图像、像素图或栅格图像，是由像素（图片元素）的单个点组成。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Bitmap | 指向位图对象的指针。 | 
| left | 位图对象左上角的横坐标。 | 
| top | 位图对象左上角的纵坐标。 | 


### OH_Drawing_CanvasDrawBitmapRect()

```
void OH_Drawing_CanvasDrawBitmapRect (OH_Drawing_Canvas* , const OH_Drawing_Bitmap* , const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions*  )
```

**描述**

将位图的指定区域绘制到画布的指定区域。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Bitmap、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Bitmap | 指向位图对象[OH_Drawing_Bitmap](#oh_drawing_bitmap)的指针。 | 
| src | 源位图指定矩形区域，为NULL将指定整个源位图区域。 | 
| dst | 目标画布指定矩形区域。 | 
| OH_Drawing_SamplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)的指针，为NULL将使用默认采样选项。 | 


### OH_Drawing_CanvasDrawCircle()

```
void OH_Drawing_CanvasDrawCircle (OH_Drawing_Canvas* , const OH_Drawing_Point* , float radius )
```

**描述**

用于画一个圆形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Point任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

radius小于等于0时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Point | 指向坐标点对象的指针，表示圆心。 | 
| radius | 圆形的半径，小于等于0时无效。 | 


### OH_Drawing_CanvasDrawImageRect()

```
void OH_Drawing_CanvasDrawImageRect (OH_Drawing_Canvas* , OH_Drawing_Image* , OH_Drawing_Rect* dst, OH_Drawing_SamplingOptions*  )
```

**描述**

将图片绘制到画布的指定区域上。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Image、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Image | 指向图片对象[OH_Drawing_Image](#oh_drawing_image)的指针。 | 
| dst | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。 | 
| OH_Drawing_SamplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)的指针，为NULL将使用默认采样选项。 | 


### OH_Drawing_CanvasDrawImageRectWithSrc()

```
void OH_Drawing_CanvasDrawImageRectWithSrc (OH_Drawing_Canvas* , const OH_Drawing_Image* , const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions* , OH_Drawing_SrcRectConstraint  )
```

**描述**

将图片绘制到画布的指定区域上，源矩形选定的区域会缩放平移到目标矩形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Image、src、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Image | 指向图片对象[OH_Drawing_Image](#oh_drawing_image)的指针。 | 
| src | 指向源矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。 | 
| dst | 指向目标矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。 | 
| OH_Drawing_SamplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)的指针，为NULL将使用默认采样选项。 | 
| OH_Drawing_SrcRectConstraint | 约束类型，支持可选的具体类型可见[OH_Drawing_SrcRectConstraint](#oh_drawing_srcrectconstraint-1)枚举。 | 


### OH_Drawing_CanvasDrawLine()

```
void OH_Drawing_CanvasDrawLine (OH_Drawing_Canvas* , float x1, float y1, float x2, float y2 )
```

**描述**

用于画一条直线段。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
void OH_Drawing_CanvasDrawOval (OH_Drawing_Canvas* , const OH_Drawing_Rect*  )
```

**描述**

用于画一个椭圆。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Rect | 指向矩形对象的指针。 | 


### OH_Drawing_CanvasDrawPath()

```
void OH_Drawing_CanvasDrawPath (OH_Drawing_Canvas* , const OH_Drawing_Path*  )
```

**描述**

用于画一个自定义路径。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Path | 指向路径对象的指针。 | 


### OH_Drawing_CanvasDrawPixelMapRect()

```
void OH_Drawing_CanvasDrawPixelMapRect (OH_Drawing_Canvas* , OH_Drawing_PixelMap* , const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, const OH_Drawing_SamplingOptions*  )
```

**描述**

用于将像素图的指定区域绘制到画布的指定区域。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_PixelMap、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_PixelMap | 指向像素图[OH_Drawing_PixelMap](#oh_drawing_pixelmap)的指针。 | 
| src | 像素图指定矩形区域，为NULL将指定整个像素图区域。 | 
| dst | 目标画布指定矩形区域。 | 
| OH_Drawing_SamplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)的指针，为NULL将使用默认采样选项。 | 


### OH_Drawing_CanvasDrawPoints()

```
void OH_Drawing_CanvasDrawPoints (OH_Drawing_Canvas* , OH_Drawing_PointMode mode, uint32_t count, const OH_Drawing_Point2D*  )
```

**描述**

用于画多个点，绘制方式分为绘制单独的点、绘制成线段或绘制成开放多边形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Point2D任意一个为NULL或者count等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

mode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| mode | 绘制多个点的方式，支持方式参考[OH_Drawing_PointMode](#oh_drawing_pointmode)。 | 
| count | 点的数量，即点数组中点的个数。 | 
| [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | 指向多个点的数组。 | 


### OH_Drawing_CanvasDrawRect()

```
void OH_Drawing_CanvasDrawRect (OH_Drawing_Canvas* , const OH_Drawing_Rect*  )
```

**描述**

用于画一个矩形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Rect | 指向矩形对象的指针。 | 


### OH_Drawing_CanvasDrawRegion()

```
void OH_Drawing_CanvasDrawRegion (OH_Drawing_Canvas* , const OH_Drawing_Region*  )
```

**描述**

用于画一块区域。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Region任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_Region | 指向区域对象的指针。 | 


### OH_Drawing_CanvasDrawRoundRect()

```
void OH_Drawing_CanvasDrawRoundRect (OH_Drawing_Canvas* , const OH_Drawing_RoundRect*  )
```

**描述**

用于画一个圆角矩形。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_RoundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_RoundRect | 指向圆角矩形对象的指针。 | 


### OH_Drawing_CanvasDrawShadow()

```
void OH_Drawing_CanvasDrawShadow (OH_Drawing_Canvas* , OH_Drawing_Path* , OH_Drawing_Point3D planeParams, OH_Drawing_Point3D devLightPos, float lightRadius, uint32_t ambientColor, uint32_t spotColor, OH_Drawing_CanvasShadowFlags flag )
```

**描述**

绘制射灯类型阴影，使用路径描述环境光阴影的轮廓。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Path任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

flag不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针，用于生成阴影。 | 
| planeParams | 表示遮挡物相对于画布在Z轴上的偏移量，其值取决于x与y坐标。 | 
| devLightPos | 光线相对于画布的位置。 | 
| lightRadius | 光源半径，需大于或等于0。 | 
| ambientColor | 环境阴影颜色，是一个32位（ARGB）变量。 | 
| spotColor | 点阴影颜色，是一个32位（ARGB）变量。 | 
| flag | 阴影标志枚举[OH_Drawing_CanvasShadowFlags](#oh_drawing_canvasshadowflags)。 | 


### OH_Drawing_CanvasDrawTextBlob()

```
void OH_Drawing_CanvasDrawTextBlob (OH_Drawing_Canvas* , const OH_Drawing_TextBlob* , float x, float y )
```

**描述**

用于画一段文字。若构造OH_Drawing_TextBlob的字体不支持待绘制字符，则该部分字符无法绘制。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_TextBlob任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| OH_Drawing_TextBlob | 指向文本对象的指针。 | 
| x | 文本对象左下角的横坐标。 | 
| y | 文本对象左下角的纵坐标。 | 


### OH_Drawing_CanvasDrawVertices()

```
void OH_Drawing_CanvasDrawVertices (OH_Drawing_Canvas* , OH_Drawing_VertexMode vertexMmode, int32_t vertexCount, const OH_Drawing_Point2D* positions, const OH_Drawing_Point2D* texs, const uint32_t* colors, int32_t indexCount, const uint16_t* indices, OH_Drawing_BlendMode mode )
```

**描述**

用于画顶点数组描述的三角网格。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas或positions为NULL、vertexCount值小于3、indexCount值小于3且不为0，存在以上任意一种情况时设置错误码为OH_DRAWING_ERROR_INVALID_PARAMETER；

vertexMmode、mode任意一个不在枚举范围内时设置错误码为OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| vertexMmode | 绘制顶点的连接方式，支持方式参考[OH_Drawing_VertexMode](#oh_drawing_vertexmode)。 | 
| vertexCount | 顶点数组元素的数量，值必须大于等于3。 | 
| positions | 描述顶点位置的数组指针，不能为空，其长度必须等于vertexCount。 | 
| texs | 描述顶点对应纹理空间坐标的数组指针，可以为空，若不为空其长度必须等于vertexCount。 | 
| colors | 描述顶点对应颜色的数组指针，用于在三角形中进行插值，可以为空，若不为空其长度必须等于vertexCount。 | 
| indexCount | 索引的数量，可以为0，若不为0则值必须大于等于3。 | 
| indices | 描述顶点对应索引的数组指针，可以为空，若不为空其长度必须等于indexCount。 | 
| mode | 混合模式枚举，支持方式参考[OH_Drawing_BlendMode](#oh_drawing_blendmode)。 | 


### OH_Drawing_CanvasGetHeight()

```
int32_t OH_Drawing_CanvasGetHeight (OH_Drawing_Canvas* )
```

**描述**

获取画布高度。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 

**返回：**

函数返回画布高度，单位为像素。


### OH_Drawing_CanvasGetLocalClipBounds()

```
void OH_Drawing_CanvasGetLocalClipBounds (OH_Drawing_Canvas* , OH_Drawing_Rect*  )
```

**描述**

获取画布裁剪区域的边界。该接口不可用于录制类型画布。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针， 开发者可调用[OH_Drawing_RectCreate](#oh_drawing_rectcreate)接口创建。 | 


### OH_Drawing_CanvasGetSaveCount()

```
uint32_t OH_Drawing_CanvasGetSaveCount (OH_Drawing_Canvas* )
```

**描述**

用于获取栈中保存的画布状态（画布矩阵）的数量。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 

**返回：**

函数会返回一个32位的值描述画布状态（画布矩阵）的数量，画布初始状态数量为1。


### OH_Drawing_CanvasGetTotalMatrix()

```
void OH_Drawing_CanvasGetTotalMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**描述**

获取画布3x3矩阵。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针， 开发者可调用[OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate)接口创建。 | 


### OH_Drawing_CanvasGetWidth()

```
int32_t OH_Drawing_CanvasGetWidth (OH_Drawing_Canvas* )
```

**描述**

获取画布宽度。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 

**返回：**

函数返回画布宽度，单位为像素。


### OH_Drawing_CanvasReadPixels()

```
bool OH_Drawing_CanvasReadPixels (OH_Drawing_Canvas* , OH_Drawing_Image_Info* , void* dstPixels, uint32_t dstRowBytes, int32_t srcX, int32_t srcY )
```

**描述**

从画布中拷贝像素数据到指定地址。该接口不可用于录制类型画布。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Image_Info、dstPixels任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | 指向图片信息[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)的指针。 | 
| dstPixels | 目标像素存储首地址。 | 
| dstRowBytes | 一行像素的大小，小于等于0时无效。 | 
| srcX | 画布像素的x轴偏移量，单位为像素。 | 
| srcY | 画布像素的y轴偏移量，单位为像素。 | 

**返回：**

函数返回true表示像素成功拷贝到目标像素存储首地址，函数返回false表示拷贝失败。


### OH_Drawing_CanvasReadPixelsToBitmap()

```
bool OH_Drawing_CanvasReadPixelsToBitmap (OH_Drawing_Canvas* , OH_Drawing_Bitmap* , int32_t srcX, int32_t srcY )
```

**描述**

从画布拷贝像素数据到位图中。该接口不可用于录制类型画布。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Bitmap | 指向位图对象[OH_Drawing_Bitmap](#oh_drawing_bitmap)的指针。 | 
| srcX | 画布像素的x轴偏移量，单位为像素。 | 
| srcY | 画布像素的y轴偏移量，单位为像素。 | 

**返回：**

函数返回true表示像素成功拷贝到位图，函数返回false表示拷贝失败。


### OH_Drawing_CanvasResetMatrix()

```
void OH_Drawing_CanvasResetMatrix (OH_Drawing_Canvas* )
```

**描述**

重置当前画布的矩阵为单位矩阵。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 


### OH_Drawing_CanvasRestore()

```
void OH_Drawing_CanvasRestore (OH_Drawing_Canvas* )
```

**描述**

用于恢复保存在栈顶的画布状态（画布矩阵）。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 


### OH_Drawing_CanvasRestoreToCount()

```
void OH_Drawing_CanvasRestoreToCount (OH_Drawing_Canvas* , uint32_t saveCount )
```

**描述**

用于恢复到指定数量的画布状态（画布矩阵）。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| saveCount | 要恢复的画布状态深度。小于等于1时，恢复为初始状态；大于已保存的画布状态数量时，不执行任何操作。 | 


### OH_Drawing_CanvasRotate()

```
void OH_Drawing_CanvasRotate (OH_Drawing_Canvas* , float degrees, float px, float py )
```

**描述**

用于画布旋转一定的角度，正数表示顺时针旋转，负数反之。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
void OH_Drawing_CanvasSave (OH_Drawing_Canvas* )
```

**描述**

用于保存当前画布的状态（画布矩阵）到一个栈顶。需要与恢复接口 [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore)配合使用。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 


### OH_Drawing_CanvasSaveLayer()

```
void OH_Drawing_CanvasSaveLayer (OH_Drawing_Canvas* , const OH_Drawing_Rect* , const OH_Drawing_Brush*  )
```

**描述**

保存矩阵和裁剪区域，为后续绘制分配位图。调用恢复接口 [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore)将放弃对矩阵和剪切区域所做的更改，并绘制位图。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针，用于限制图层大小，为NULL表示无限制。 | 
| OH_Drawing_Brush | 指向画刷对象[OH_Drawing_Brush](#oh_drawing_brush)的指针，绘制位图时会应用画刷对象的透明度，滤波器效果，混合模式，为NULL表示不应用任何效果。 | 


### OH_Drawing_CanvasScale()

```
void OH_Drawing_CanvasScale (OH_Drawing_Canvas* , float sx, float sy )
```

**描述**

用于画布缩放。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| sx | x轴方向的缩放比例。 | 
| sy | y轴方向的缩放比例。 | 


### OH_Drawing_CanvasSetMatrix()

```
void OH_Drawing_CanvasSetMatrix (OH_Drawing_Canvas* , OH_Drawing_Matrix*  )
```

**描述**

设置画布的矩阵状态。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas、OH_Drawing_Matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)的指针。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针， 开发者可调用[OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate)接口创建。 | 


### OH_Drawing_CanvasSkew()

```
void OH_Drawing_CanvasSkew (OH_Drawing_Canvas* , float sx, float sy )
```

**描述**

用于画布倾斜变换。等同于将当前画布矩阵左乘（premultiply）倾斜变换矩阵，并应用到画布上。其中倾斜变换矩阵为：\|1 sx 0\| \|sy 1 0\| \|0 0 1\|。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| sx | 沿x轴的倾斜量。正值会使绘制沿y轴增量方向向右倾斜；负值会使绘制沿y轴增量方向向左倾斜。 | 
| sy | 沿y轴的倾斜量。正值会使绘制沿x轴增量方向向下倾斜；负值会使绘制沿x轴增量方向向上倾斜。 | 


### OH_Drawing_CanvasTranslate()

```
void OH_Drawing_CanvasTranslate (OH_Drawing_Canvas* , float dx, float dy )
```

**描述**

用于平移画布一段距离。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Canvas为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Canvas | 指向画布对象的指针。 | 
| dx | x轴方向的移动距离。 | 
| dy | y轴方向的移动距离。 | 


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
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateCompose (OH_Drawing_ColorFilter* colorFilter1, OH_Drawing_ColorFilter* colorFilter2 )
```

**描述**

将两个颜色滤波器合成一个新的颜色滤波器。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

colorFilter1、colorFilter2任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| colorFilter1 | 指向颜色滤波器对象一的指针。 | 
| colorFilter2 | 指向颜色滤波器对象二的指针。 | 

**返回：**

返回创建的颜色滤波器对象的指针。


### OH_Drawing_ColorFilterCreateLinearToSrgbGamma()

```
OH_Drawing_ColorFilter* OH_Drawing_ColorFilterCreateLinearToSrgbGamma (void )
```

**描述**

创建一个从线性颜色空间转换到SRGB颜色空间的颜色滤波器。

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

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
void OH_Drawing_ColorFilterDestroy (OH_Drawing_ColorFilter* )
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


### OH_Drawing_ColorSpaceCreateSrgb()

```
OH_Drawing_ColorSpace* OH_Drawing_ColorSpaceCreateSrgb (void )
```

**描述**

创建一个标准颜色空间。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

函数返回一个指针，指针指向创建的颜色空间对象[OH_Drawing_ColorSpace](#oh_drawing_colorspace)。


### OH_Drawing_ColorSpaceCreateSrgbLinear()

```
OH_Drawing_ColorSpace* OH_Drawing_ColorSpaceCreateSrgbLinear (void )
```

**描述**

创建一个Gamma 1.0空间上的颜色空间。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

函数返回一个指针，指针指向创建的颜色空间对象[OH_Drawing_ColorSpace](#oh_drawing_colorspace)。


### OH_Drawing_ColorSpaceDestroy()

```
void OH_Drawing_ColorSpaceDestroy (OH_Drawing_ColorSpace* )
```

**描述**

销毁颜色空间对象，并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_ColorSpace | 指向颜色空间对象[OH_Drawing_ColorSpace](#oh_drawing_colorspace)的指针。 | 


### OH_Drawing_CreateDashPathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateDashPathEffect (float* intervals, int count, float phase )
```

**描述**

创建一个虚线效果的路径效果对象。虚线效果由一组虚线开的间隔、虚线关的间隔数据决定。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

intervals为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| intervals | 虚线间隔数组首地址，偶数项的值表示虚线开的间隔长度， 奇数项的值表示虚线关的间隔长度，单位为像素。 | 
| count | 虚线间隔数组元素的个数，必须为大于0的偶数。 | 
| phase | 虚线间隔数组中偏移量。 | 

**返回：**

函数返回一个指针，指针指向创建的路径效果对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)。


### OH_Drawing_CreateFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection (void )
```

**描述**

创建字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)。该函数创建的字体集指针对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)只能被一个[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象使用，无法被多个[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象共享使用。如需在多个[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象间共享同一个[OH_Drawing_FontCollection](#oh_drawing_fontcollection)，请使用[OH_Drawing_CreateSharedFontCollection](#oh_drawing_createsharedfontcollection)函数创建[OH_Drawing_FontCollection](#oh_drawing_fontcollection)对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

指向创建的字体集对象的指针。


### OH_Drawing_CreateFontDescriptor()

```
OH_Drawing_FontDescriptor* OH_Drawing_CreateFontDescriptor (void )
```

**描述**

构造字体描述对象，用于描述系统字体详细信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

返回指向已创建的字体描述对象[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)的指针。


### OH_Drawing_CreateFontParser()

```
OH_Drawing_FontParser* OH_Drawing_CreateFontParser (void )
```

**描述**

构造字体解析对象，用于解析系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

返回指向已创建的字体解析对象[OH_Drawing_FontParser](#oh_drawing_fontparser)的指针。


### OH_Drawing_CreateSharedFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateSharedFontCollection (void )
```

**描述**

创建可共享的字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

指向创建的字体集对象的指针。

### OH_Drawing_ClearFontCaches()

```
void OH_Drawing_ClearFontCaches (OH_Drawing_FontCollection* )
```

**描述**

清理字体排版缓存（字体排版缓存本身设有内存上限和清理机制，所占内存有限，如无内存要求，不建议清理）。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontCollection | 指向字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)的指针。 | 

### OH_Drawing_CreateTextShadow()

```
OH_Drawing_TextShadow* OH_Drawing_CreateTextShadow (void )
```

**描述**

创建指向字体阴影对象的指针。不再需要[OH_Drawing_TextShadow](#oh_drawing_textshadow)时，请使用[OH_Drawing_DestroyTextShadow](#oh_drawing_destroytextshadow)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

指向创建的字体阴影对象。


### OH_Drawing_CreateTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle (void )
```

**描述**

创建指向OH_Drawing_TextStyle对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

指向创建的OH_Drawing_TextStyle对象的指针。


### OH_Drawing_CreateTypography()

```
OH_Drawing_Typography* OH_Drawing_CreateTypography (OH_Drawing_TypographyCreate* )
```

**描述**

创建指向OH_Drawing_Typography对象的指针。不再需要[OH_Drawing_Typography](#oh_drawing_typography)时，请使用[OH_Drawing_DestroyTypography](#oh_drawing_destroytypography)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象的指针，由[OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler)获取。 | 

**返回：**

指向OH_Drawing_Typography对象的指针。


### OH_Drawing_CreateTypographyHandler()

```
OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler (OH_Drawing_TypographyStyle* , OH_Drawing_FontCollection*  )
```

**描述**

创建指向OH_Drawing_TypographyCreate对象的指针。不再需要[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)时，请使用[OH_Drawing_DestroyTypographyHandler](#oh_drawing_destroytypographyhandler)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| OH_Drawing_FontCollection | 指向字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)的指针，可由[OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection)或[OH_Drawing_CreateSharedFontCollection](#oh_drawing_createsharedfontcollection)获取，建议使用[OH_Drawing_CreateSharedFontCollection](#oh_drawing_createsharedfontcollection)。 | 

**返回：**

指向新创建的OH_Drawing_TypographyCreate对象的指针。


### OH_Drawing_CreateTypographyStyle()

```
OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle (void )
```

**描述**

创建指向OH_Drawing_TypographyStyle对象的指针。不再需要[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)时，请使用[OH_Drawing_DestroyTypographyStyle](#oh_drawing_destroytypographystyle)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

指向创建的OH_Drawing_TypographyStyle对象的指针。


### OH_Drawing_DestroyFontCollection()

```
void OH_Drawing_DestroyFontCollection (OH_Drawing_FontCollection* )
```

**描述**

释放被字体集对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontCollection | 指向字体集对象的指针。 | 


### OH_Drawing_DestroyFontDescriptor()

```
void OH_Drawing_DestroyFontDescriptor (OH_Drawing_FontDescriptor* )
```

**描述**

释放字体描述对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md) | 指向字体描述对象[OH_Drawing_FontDescriptor](_o_h___drawing___font_descriptor.md)的指针，由[OH_Drawing_CreateFontDescriptor](#oh_drawing_createfontdescriptor)获取。 | 


### OH_Drawing_DestroyFontParser()

```
void OH_Drawing_DestroyFontParser (OH_Drawing_FontParser* )
```

**描述**

释放字体解析对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontParser | 指向字体解析对象[OH_Drawing_FontParser](#oh_drawing_fontparser)的指针，由[OH_Drawing_CreateFontParser](#oh_drawing_createfontparser)获取。 | 


### OH_Drawing_DestroyLineMetrics()

```
void OH_Drawing_DestroyLineMetrics (OH_Drawing_LineMetrics* )
```

**描述**

释放行位置信息对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_LineMetrics | 指向行位置信息对象[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)的指针，由[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)获取。 | 


### OH_Drawing_DestroySystemFontConfigInfo()

```
void OH_Drawing_DestroySystemFontConfigInfo (OH_Drawing_FontConfigInfo* )
```

**描述**

释放系统字体配置信息占用的的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontConfigInfo | 指向系统字体配置信息[OH_Drawing_FontConfigInfo](_o_h___drawing___font_config_info.md)的指针， 由[OH_Drawing_GetSystemFontConfigInfo](#oh_drawing_getsystemfontconfiginfo)获取。 | 


### OH_Drawing_DestroySystemFontList()

```
void OH_Drawing_DestroySystemFontList (char** , size_t  )
```

**描述**

释放系统字体名称列表占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| char\*\* | 指向系统字体名称列表的指针。 | 
| size_t\* | 系统字体名称列表的数量。 | 


### OH_Drawing_DestroyTextShadow()

```
void OH_Drawing_DestroyTextShadow (OH_Drawing_TextShadow* )
```

**描述**

释放被字体阴影对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextShadow | 指向字体阴影对象[OH_Drawing_TextShadow](#oh_drawing_textshadow)的指针，由[OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow)获取。 | 


### OH_Drawing_DestroyTextShadows()

```
void OH_Drawing_DestroyTextShadows (OH_Drawing_TextShadow* )
```

**描述**

释放由被字体阴影对象OH_Drawing_TextShadow构成的vector占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextShadow | 指向字体阴影对象[OH_Drawing_TextShadow](#oh_drawing_textshadow)的指针，由[OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow)获取。 | 


### OH_Drawing_DestroyTextStyle()

```
void OH_Drawing_DestroyTextStyle (OH_Drawing_TextStyle* )
```

**描述**

释放被OH_Drawing_TextStyle对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 


### OH_Drawing_DestroyTypography()

```
void OH_Drawing_DestroyTypography (OH_Drawing_Typography* )
```

**描述**

释放OH_Drawing_Typography对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向[OH_Drawing_Typography](#oh_drawing_typography)对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 


### OH_Drawing_DestroyTypographyHandler()

```
void OH_Drawing_DestroyTypographyHandler (OH_Drawing_TypographyCreate* )
```

**描述**

释放被OH_Drawing_TypographyCreate对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象的指针，由[OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler)获取。 | 


### OH_Drawing_DestroyTypographyStyle()

```
void OH_Drawing_DestroyTypographyStyle (OH_Drawing_TypographyStyle* )
```

**描述**

释放被OH_Drawing_TypographyStyle对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 


### OH_Drawing_DisableFontCollectionFallback()

```
void OH_Drawing_DisableFontCollectionFallback (OH_Drawing_FontCollection* fontCollection)
```

**描述**

禁用系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontCollection | 指向字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)的指针。 | 


### OH_Drawing_DisableFontCollectionSystemFont()

```
void OH_Drawing_DisableFontCollectionSystemFont (OH_Drawing_FontCollection* fontCollection)
```

**描述**

禁用系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontCollection | 指向字体集对象[OH_Drawing_FontCollection](#oh_drawing_fontcollection)的指针。 | 


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
void OH_Drawing_FilterDestroy (OH_Drawing_Filter* )
```

**描述**

销毁滤波器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Filter | 指示指向滤波器对象的指针。 | 


### OH_Drawing_FilterGetColorFilter()

```
void OH_Drawing_FilterGetColorFilter (OH_Drawing_Filter* , OH_Drawing_ColorFilter*  )
```

**描述**

从滤波器对象获取颜色滤波器对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Filter、OH_Drawing_ColorFilter任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Filter | 指示指向滤波器对象[OH_Drawing_Filter](#oh_drawing_filter)的指针。 | 
| OH_Drawing_ColorFilter | 指示指向颜色滤波器对象[OH_Drawing_ColorFilter](#oh_drawing_colorfilter)的指针。 | 


### OH_Drawing_FilterSetColorFilter()

```
void OH_Drawing_FilterSetColorFilter (OH_Drawing_Filter* , OH_Drawing_ColorFilter*  )
```

**描述**

为滤波器对象设置颜色滤波器对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Filter为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Filter | 指示指向滤波器对象的指针。 | 
| OH_Drawing_ColorFilter | 指示指向颜色滤波器对象的指针，为NULL表示清空滤波器对象中的颜色滤波器效果。 | 


### OH_Drawing_FilterSetMaskFilter()

```
void OH_Drawing_FilterSetMaskFilter (OH_Drawing_Filter* , OH_Drawing_MaskFilter*  )
```

**描述**

为滤波器对象设置蒙版滤波器对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Filter为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Filter | 指示指向滤波器对象的指针。 | 
| OH_Drawing_MaskFilter | 指示指向蒙版滤波器对象的指针，为NULL表示清空滤波器对象中的蒙版滤波器效果。 | 


### OH_Drawing_FontCountText()

```
int OH_Drawing_FontCountText (OH_Drawing_Font* , const void* text, size_t byteLength, OH_Drawing_TextEncoding encoding )
```

**描述**

获取文本所表示的字符数量。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font、text任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| text | 文本存储首地址。 | 
| byteLength | 文本长度，单位为字节。 | 
| encoding | 文本编码类型[OH_Drawing_TextEncoding](#oh_drawing_textencoding)。 | 


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
void OH_Drawing_FontDestroy (OH_Drawing_Font* )
```

**描述**

用于销毁字体对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 | 


### OH_Drawing_FontGetMetrics()

```
float OH_Drawing_FontGetMetrics (OH_Drawing_Font* , OH_Drawing_Font_Metrics*  )
```

**描述**

获取字体度量信息。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font、OH_Drawing_Font_Metrics任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| OH_Drawing_Font_Metrics | 指向字体度量信息对象[OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)的指针。 | 

**返回：**

函数返回一个浮点数变量，表示建议的行间距。


### OH_Drawing_FontGetTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontGetTypeface (OH_Drawing_Font* )
```

**描述**

获取字体对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 

**返回：**

OH_Drawing_Typeface 函数返回一个指针，指字体对象[OH_Drawing_Typeface](#oh_drawing_typeface)。


### OH_Drawing_FontMgrCreate()

```
OH_Drawing_FontMgr* OH_Drawing_FontMgrCreate (void )
```

**描述**

创建字体管理对象，只支持管理系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

返回指向已创建的字体管理对象[OH_Drawing_FontMgr](#oh_drawing_fontmgr)的指针。


### OH_Drawing_FontMgrCreateFontStyleSet()

```
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrCreateFontStyleSet (OH_Drawing_FontMgr* , int index )
```

**描述**

由字体管理对象构造字体样式集对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontMgr | 指向字体管理对象[OH_Drawing_FontMgr](#oh_drawing_fontmgr)的指针，由[OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate)获取。 | 
| index | 用于从字体管理对象获取字体样式集对象的索引值。 | 

**返回：**

返回指向已创建的字体样式集对象[OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)的指针。


### OH_Drawing_FontMgrDestroy()

```
void OH_Drawing_FontMgrDestroy (OH_Drawing_FontMgr* )
```

**描述**

释放字体管理对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontMgr | 指向字体管理对象[OH_Drawing_FontMgr](#oh_drawing_fontmgr)的指针，由[OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate)获取。 | 


### OH_Drawing_FontMgrDestroyFamilyName()

```
void OH_Drawing_FontMgrDestroyFamilyName (char* familyName)
```

**描述**

释放指定字体家族名称占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| familyName | 指定字体家族名称数组。 | 


### OH_Drawing_FontMgrDestroyFontStyleSet()

```
void OH_Drawing_FontMgrDestroyFontStyleSet (OH_Drawing_FontStyleSet* )
```

**描述**

释放字体样式集对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)的指针。 | 


### OH_Drawing_FontMgrGetFamilyCount()

```
int OH_Drawing_FontMgrGetFamilyCount (OH_Drawing_FontMgr* )
```

**描述**

获取字体家族的数量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontMgr | 指向字体管理对象[OH_Drawing_FontMgr](#oh_drawing_fontmgr)的指针，由[OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate)获取。 | 

**返回：**

返回字体家族的数量。


### OH_Drawing_FontMgrGetFamilyName()

```
char* OH_Drawing_FontMgrGetFamilyName (OH_Drawing_FontMgr* , int index )
```

**描述**

由索引值获取字体家族名称。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontMgr | 指向字体管理对象[OH_Drawing_FontMgr](#oh_drawing_fontmgr)的指针，由[OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate)获取。 | 
| index | 用于获取对应字体家族名称的索引值。 | 

**返回：**

返回索引值对应的字体家族名称，不再需要时，请使用[OH_Drawing_FontMgrDestroyFamilyName](#oh_drawing_fontmgrdestroyfamilyname)释放该对象指针。          


### OH_Drawing_FontMgrMatchFamily()

```
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrMatchFamily (OH_Drawing_FontMgr* , const char* familyName )
```

**描述**

由指定的字体家族名称，获取字体样式集对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontMgr | 指向字体管理对象[OH_Drawing_FontMgr](#oh_drawing_fontmgr)的指针，由[OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate)获取。 | 
| familyName | 指定的字体家族名称。 | 

**返回：**

返回对应的字体样式集对象[OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)，不再需要时，请使用[OH_Drawing_FontMgrDestroyFontStyleSet](#oh_drawing_fontmgrdestroyfontstyleset)释放该对象指针。


### OH_Drawing_FontMgrMatchFamilyStyle()

```
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyle (OH_Drawing_FontMgr* , const char* familyName, OH_Drawing_FontStyleStruct  )
```

**描述**

根据指定的字体样式信息和字体家族名称，获取字型对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontMgr | 指向字体管理对象[OH_Drawing_FontMgr](#oh_drawing_fontmgr)的指针，由[OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate)获取。 | 
| familyName | 指定的字体家族名称。 | 
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 | 

**返回：**

返回对应的字体样式的字型对象[OH_Drawing_Typeface](#oh_drawing_typeface)，不再需要时，请使用[OH_Drawing_TypefaceDestroy](#oh_drawing_typefacedestroy)释放该对象指针。


### OH_Drawing_FontMgrMatchFamilyStyleCharacter()

```
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyleCharacter (OH_Drawing_FontMgr* , const char* familyName, OH_Drawing_FontStyleStruct , const char* bcp47[], int bcp47Count, int32_t character )
```

**描述**

为指定字符获取字型对象，仅在传入字体管理对象中无法找到传入UTF8字符值对应的字型对象时返回空指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontMgr | 指向字体管理对象[OH_Drawing_FontMgr](#oh_drawing_fontmgr)的指针，由[OH_Drawing_FontMgrCreate](#oh_drawing_fontmgrcreate)获取。 | 
| familyName | 指定的字体家族名称。 | 
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 | 
| bcp47 | 用来指示character语言编码数组，是ISO 639、15924和3166-1语言编码的组合。 | 
| bcp47Count | 参数bcp47数组大小。 | 
| character | 待匹配的UTF8字符值。 | 

**返回：**

返回对应的字型对象[OH_Drawing_Typeface](#oh_drawing_typeface)。


### OH_Drawing_FontParserGetFontByName()

```
OH_Drawing_FontDescriptor* OH_Drawing_FontParserGetFontByName (OH_Drawing_FontParser* , const char*  )
```

**描述**

根据传入的系统字体名称获取系统字体的相关信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontParser | 指向字体解析对象[OH_Drawing_FontParser](#oh_drawing_fontparser)的指针，由[OH_Drawing_CreateFontParser](#oh_drawing_createfontparser)获取。 | 
| char\* | 系统字体名。 | 

**返回：**

返回系统字体描述对象，不再需要时，请使用[OH_Drawing_DestroyFontParser](#oh_drawing_destroyfontparser)释放该对象指针。


### OH_Drawing_FontParserGetSystemFontList()

```
char** OH_Drawing_FontParserGetSystemFontList (OH_Drawing_FontParser* , size_t*  )
```

**描述**

获取系统字体名称列表，此接口仅在2in1、phone设备上可用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontParser | 指向字体解析对象[OH_Drawing_FontParser](#oh_drawing_fontparser)的指针，由[OH_Drawing_CreateFontParser](#oh_drawing_createfontparser)获取。 | 
| size_t | 返回获取到的系统字体名称数量。 | 

**返回：**

返回获取到的系统字体列表。


### OH_Drawing_FontSetFakeBoldText()

```
void OH_Drawing_FontSetFakeBoldText (OH_Drawing_Font* , bool isFakeBoldText )
```

**描述**

用于设置增加描边宽度以近似粗体字体效果。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 | 
| isFakeBoldText | 真为使能增加描边宽度，假为不使能。 | 


### OH_Drawing_FontSetLinearText()

```
void OH_Drawing_FontSetLinearText (OH_Drawing_Font* , bool isLinearText )
```

**描述**

用于设置线性可缩放字体。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 | 
| isLinearText | 真为使能线性可缩放字体，假为不使能。 | 


### OH_Drawing_FontSetTextSize()

```
void OH_Drawing_FontSetTextSize (OH_Drawing_Font* , float textSize )
```

**描述**

用于给字体设置文字大小。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 | 
| textSize | 字体大小，该参数为浮点数，为负数时字体大小会被置为0。字体大小为0时，绘制的文字不会显示。 | 


### OH_Drawing_FontSetTextSkewX()

```
void OH_Drawing_FontSetTextSkewX (OH_Drawing_Font* , float skewX )
```

**描述**

用于给字体设置文本倾斜。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字体对象的指针。 | 
| skewX | X轴相对于Y轴的倾斜度。 | 


### OH_Drawing_FontSetTypeface()

```
void OH_Drawing_FontSetTypeface (OH_Drawing_Font* , OH_Drawing_Typeface*  )
```

**描述**

用于给字型设置字体。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Font | 指向字型对象的指针。 | 
| OH_Drawing_Typeface | 指向字体对象的指针，为NULL会使用系统默认字体对象。 | 


### OH_Drawing_FontStyleSetCount()

```
int OH_Drawing_FontStyleSetCount (OH_Drawing_FontStyleSet* )
```

**描述**

获取字体样式集中字体的个数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)的指针。 | 

**返回：**

返回此字体样式集中字体的个数。


### OH_Drawing_FontStyleSetCreateTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontStyleSetCreateTypeface (OH_Drawing_FontStyleSet* , int index )
```

**描述**

为指定索引获取字型对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)的指针。 | 
| index | 指定的字型对象的索引。 | 

**返回：**

如果成功，返回对应的字型对象[OH_Drawing_Typeface](#oh_drawing_typeface); 如果失败，返回nullptr。


### OH_Drawing_FontStyleSetFreeStyleName()

```
void OH_Drawing_FontStyleSetFreeStyleName (char** styleName)
```

**描述**

释放指定字体样式的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| styleName | 指定字体样式名称的字符串。 | 


### OH_Drawing_FontStyleSetGetStyle()

```
OH_Drawing_FontStyleStruct OH_Drawing_FontStyleSetGetStyle (OH_Drawing_FontStyleSet* , int32_t index, char** styleName )
```

**描述**

获取字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)的指针。 | 
| index | 指定的字体样式的索引。 | 
| styleName | 指定字体样式名称的字符串。 | 

**返回：**

返回对应的字体样式。


### OH_Drawing_FontStyleSetMatchStyle()

```
OH_Drawing_Typeface* OH_Drawing_FontStyleSetMatchStyle (OH_Drawing_FontStyleSet* , OH_Drawing_FontStyleStruct fontStyleStruct )
```

**描述**

获取最接近字体样式的字型对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](#oh_drawing_fontstyleset)的指针。 | 
| fontStyleStruct | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 | 

**返回：**

返回对应的字型对象[OH_Drawing_Typeface](#oh_drawing_typeface)。


### OH_Drawing_GetAffinityFromPositionAndAffinity()

```
int OH_Drawing_GetAffinityFromPositionAndAffinity (OH_Drawing_PositionAndAffinity* )
```

**描述**

获取OH_Drawing_PositionAndAffinity对象的亲和性，根据亲和性可判断字体会靠近前方文本还是后方文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_PositionAndAffinity | 指向OH_Drawing_PositionAndAffinity对象的指针， 由[OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate)或 [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster)获取。 | 

**返回：**

返回OH_Drawing_PositionAndAffinity对象的亲和性。


### OH_Drawing_GetBottomFromTextBox()

```
float OH_Drawing_GetBottomFromTextBox (OH_Drawing_TextBox* , int  )
```

**描述**

获取文本框底部位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或 [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 | 
| int | 文本框的索引。 | 

**返回：**

返回文本框底部位置。


### OH_Drawing_GetEndFromRange()

```
size_t OH_Drawing_GetEndFromRange (OH_Drawing_Range* )
```

**描述**

获取OH_Drawing_Range对象结束位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Range | 指向OH_Drawing_Range对象的指针，由[OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary)获取。 | 

**返回：**

返回OH_Drawing_Range对象结束位置。


### OH_Drawing_GetLeftFromTextBox()

```
float OH_Drawing_GetLeftFromTextBox (OH_Drawing_TextBox* , int  )
```

**描述**

获取文本框左侧位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或 [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 | 
| int | 文本框的索引。 | 

**返回：**

返回文本框左侧位置。


### OH_Drawing_GetPositionFromPositionAndAffinity()

```
size_t OH_Drawing_GetPositionFromPositionAndAffinity (OH_Drawing_PositionAndAffinity* )
```

**描述**

获取OH_Drawing_PositionAndAffinity对象的位置属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_PositionAndAffinity | 指向OH_Drawing_PositionAndAffinity对象的指针， 由[OH_Drawing_TypographyGetGlyphPositionAtCoordinate](#oh_drawing_typographygetglyphpositionatcoordinate)或 [OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster](#oh_drawing_typographygetglyphpositionatcoordinatewithcluster)获取。 | 

**返回：**

返回OH_Drawing_PositionAndAffinity对象的位置属性。


### OH_Drawing_GetRightFromTextBox()

```
float OH_Drawing_GetRightFromTextBox (OH_Drawing_TextBox* , int  )
```

**描述**

获取文本框右侧位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或 [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 | 
| int | 文本框的索引。 | 

**返回：**

返回文本框右侧位置。


### OH_Drawing_GetSizeOfTextBox()

```
size_t OH_Drawing_GetSizeOfTextBox (OH_Drawing_TextBox* )
```

**描述**

获取文本框数量大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或 [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 | 

**返回：**

返回文本框数量大小。


### OH_Drawing_GetStartFromRange()

```
size_t OH_Drawing_GetStartFromRange (OH_Drawing_Range* )
```

**描述**

获取OH_Drawing_Range对象开始位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Range | 指向OH_Drawing_Range对象的指针，由[OH_Drawing_TypographyGetWordBoundary](#oh_drawing_typographygetwordboundary)获取。 | 

**返回：**

返回OH_Drawing_Range对象开始位置。


### OH_Drawing_GetSystemFontConfigInfo()

```
OH_Drawing_FontConfigInfo* OH_Drawing_GetSystemFontConfigInfo (OH_Drawing_FontConfigInfoErrorCode* )
```

**描述**

获取系统字体配置信息。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontConfigJsonInfoCode | 错误码，具体可见[OH_Drawing_FontConfigInfoErrorCode](#oh_drawing_fontconfiginfoerrorcode)枚举。 | 

**返回：**

返回系统字体配置信息的指针，不再需要时，请使用[OH_Drawing_DestroySystemFontConfigInfo](#oh_drawing_destroysystemfontconfiginfo)释放该对象指针。


### OH_Drawing_GetTextDirectionFromTextBox()

```
int OH_Drawing_GetTextDirectionFromTextBox (OH_Drawing_TextBox* , int  )
```

**描述**

获取文本框方向。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBox | 指向[OH_Drawing_TextBox](#oh_drawing_textbox)对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或 [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 | 
| int | 文本框的索引。 | 

**返回：**

返回文本框方向。


### OH_Drawing_GetTopFromTextBox()

```
float OH_Drawing_GetTopFromTextBox (OH_Drawing_TextBox* , int  )
```

**描述**

获取文本框顶部位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBox | 指向OH_Drawing_TextBox对象的指针，由[OH_Drawing_TypographyGetRectsForRange](#oh_drawing_typographygetrectsforrange)或 [OH_Drawing_TypographyGetRectsForPlaceholders](#oh_drawing_typographygetrectsforplaceholders)获取。 | 
| int | 文本框的索引。 | 

**返回：**

返回文本框顶部位置。


### OH_Drawing_GpuContextCreateFromGL()

```
OH_Drawing_GpuContext* OH_Drawing_GpuContextCreateFromGL (OH_Drawing_GpuContextOptions )
```

**描述**

用于创建一个使用OpenGL作为后端接口的图形处理器上下文对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_GpuContextOptions | 图形处理器上下文选项[OH_Drawing_GpuContextOptions](_o_h___drawing___gpu_context_options.md)。 | 

**返回：**

返回一个指针，指针指向创建的图形处理器上下文对象[OH_Drawing_GpuContext](#oh_drawing_gpucontext)。


### OH_Drawing_GpuContextDestroy()

```
void OH_Drawing_GpuContextDestroy (OH_Drawing_GpuContext* )
```

**描述**

用于销毁图形处理器上下文对象并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_GpuContext | 指向图形处理器上下文对象的指针[OH_Drawing_GpuContext](#oh_drawing_gpucontext)。 | 


### OH_Drawing_ImageBuildFromBitmap()

```
bool OH_Drawing_ImageBuildFromBitmap (OH_Drawing_Image* , OH_Drawing_Bitmap*  )
```

**描述**

从位图构造图片对象内容，共享或复制位图像素。如果位图被标记为不可变状态， 像素内存是共享的，不是复制。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Image、OH_Drawing_Bitmap任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Image | 指向图片对象[OH_Drawing_Image](#oh_drawing_image)的指针。 | 
| OH_Drawing_Bitmap | 指向位图对象[OH_Drawing_Bitmap](#oh_drawing_bitmap)的指针。 | 

**返回：**

函数返回true表示构造图片内容成功，函数返回false表示构建图片内容失败。


### OH_Drawing_ImageCreate()

```
OH_Drawing_Image* OH_Drawing_ImageCreate (void )
```

**描述**

创建一个图片对象，描述了要绘制的二维像素数组。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

函数返回一个指针，指针指向创建的图片对象[OH_Drawing_Image](#oh_drawing_image)。


### OH_Drawing_ImageDestroy()

```
void OH_Drawing_ImageDestroy (OH_Drawing_Image* )
```

**描述**

销毁图片对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Image | 指向图片对象[OH_Drawing_Image](#oh_drawing_image)的指针。 | 


### OH_Drawing_ImageGetHeight()

```
int32_t OH_Drawing_ImageGetHeight (OH_Drawing_Image* )
```

**描述**

获取图片高度，即像素行数。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Image为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Image | 指向图片对象[OH_Drawing_Image](#oh_drawing_image)的指针。 | 

**返回：**

函数返回图片高度。


### OH_Drawing_ImageGetImageInfo()

```
void OH_Drawing_ImageGetImageInfo (OH_Drawing_Image* , OH_Drawing_Image_Info*  )
```

**描述**

获取图片信息。调用该接口后，传入的图片信息对象被填充。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Image、OH_Drawing_Image_Info任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Image | 指向图片对象[OH_Drawing_Image](#oh_drawing_image)的指针。 | 
| OH_Drawing_Image_Info | 指向图片信息对象[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)的指针， 开发者可调用[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)创建。 | 


### OH_Drawing_ImageGetWidth()

```
int32_t OH_Drawing_ImageGetWidth (OH_Drawing_Image* )
```

**描述**

获取图片宽度，即每行的像素个数。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Image为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Image | 指向图片对象[OH_Drawing_Image](#oh_drawing_image)的指针。 | 

**返回：**

函数返回图片宽度。


### OH_Drawing_LineMetricsGetSize()

```
size_t OH_Drawing_LineMetricsGetSize (OH_Drawing_LineMetrics* )
```

**描述**

获取行数量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | 指向行位置信息对象[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)的指针，由[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)获取。 | 

**返回：**

返回行数量。


### OH_Drawing_MaskFilterCreateBlur()

```
OH_Drawing_MaskFilter* OH_Drawing_MaskFilterCreateBlur (OH_Drawing_BlurType blurType, float sigma, bool respectCTM )
```

**描述**

创建具有模糊效果的蒙版滤波器。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| blurType | 表示模糊类型。 | 
| sigma | 表示要应用的高斯模糊的标准偏差。必须大于0。 | 
| respectCTM | 表示模糊标准差值被CTM修改，默认为真。 | 

**返回：**

返回创建的蒙版滤波器对象的指针。


### OH_Drawing_MaskFilterDestroy()

```
void OH_Drawing_MaskFilterDestroy (OH_Drawing_MaskFilter* )
```

**描述**

销毁蒙版滤波器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_MaskFilter | 表示指向蒙版滤波器对象的指针。 | 


### OH_Drawing_MatrixConcat()

```
void OH_Drawing_MatrixConcat (OH_Drawing_Matrix* total, const OH_Drawing_Matrix* a, const OH_Drawing_Matrix* b )
```

**描述**

将矩阵total设置为矩阵a乘以矩阵b。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

total、a、b任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| total | 指向最终的矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| a | 指向矩阵对象a[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| b | 指向矩阵对象b[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 


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


### OH_Drawing_MatrixCreateRotation()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateRotation (float deg, float x, float y )
```

**描述**

创建一个带旋转属性的矩阵对象。 该矩阵对象为：单位矩阵在(x, y)旋转点以度为单位进行旋转后得到的矩阵。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deg | 旋转的角度，单位为度。正数表示按顺时针旋转，负数表示按逆时针旋转。 | 
| x | x轴上坐标点。 | 
| y | y轴上坐标点。 | 

**返回：**

函数返回一个指针，指针指向创建的矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)。


### OH_Drawing_MatrixCreateScale()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateScale (float sx, float sy, float px, float py )
```

**描述**

创建一个带缩放属性的矩阵对象。 该矩阵对象为：单位矩阵在(px, py)旋转点以sx和sy为缩放因子进行缩放后得到的矩阵。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sx | x轴方向缩放系数，为负数时可看作是先关于y = px作镜像翻转后再进行缩放，该参数为浮点数。 | 
| sy | y轴方向缩放系数，为负数时可看作是先关于x = py作镜像翻转后再进行缩放，该参数为浮点数。 | 
| px | x轴上坐标点。 | 
| py | y轴上坐标点。 | 

**返回：**

函数返回一个指针，指针指向创建的矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)。


### OH_Drawing_MatrixCreateTranslation()

```
OH_Drawing_Matrix* OH_Drawing_MatrixCreateTranslation (float dx, float dy )
```

**描述**

创建一个带平移属性的矩阵对象。 该矩阵对象为：单位矩阵平移(dx, dy)后得到的矩阵。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| dx | 水平方向平移距离，正数表示往x轴正方向平移，负数表示往x轴负方向平移，该参数为浮点数。 | 
| dy | 垂直方向平移距离，正数表示往y轴正方向平移，负数表示往y轴负方向平移，该参数为浮点数。 | 

**返回：**

函数返回一个指针，指针指向创建的矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)。


### OH_Drawing_MatrixDestroy()

```
void OH_Drawing_MatrixDestroy (OH_Drawing_Matrix* )
```

**描述**

用于销毁矩阵对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向字体对象的指针。 | 


### OH_Drawing_MatrixGetValue()

```
float OH_Drawing_MatrixGetValue (OH_Drawing_Matrix* , int index )
```

**描述**

获取矩阵给定索引位的值。索引范围0-8。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

index小于0或者大于8时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| index | 索引位置，范围0-8。 | 

**返回：**

函数返回矩阵给定索引位对应的值。


### OH_Drawing_MatrixInvert()

```
bool OH_Drawing_MatrixInvert (OH_Drawing_Matrix* , OH_Drawing_Matrix* inverse )
```

**描述**

将矩阵inverse设置为矩阵的倒数，并返回结果。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix、inverse任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| inverse | 指向逆矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针， 开发者可调用[OH_Drawing_MatrixCreate](#oh_drawing_matrixcreate)接口创建。 | 

**返回：**

函数返回true表示矩阵可逆，inverse被填充为逆矩阵；函数返回false表示矩阵不可逆，inverse不被改变。


### OH_Drawing_MatrixIsEqual()

```
bool OH_Drawing_MatrixIsEqual (OH_Drawing_Matrix* , OH_Drawing_Matrix* other )
```

**描述**

判断两个矩阵是否相等。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向用于判断的其中一个矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| other | 指向用于判断的另一个矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 

**返回：**

函数返回两个矩阵的比较结果，返回true表示两个矩阵相等，返回false表示两个矩阵不相等。


### OH_Drawing_MatrixIsIdentity()

```
bool OH_Drawing_MatrixIsIdentity (OH_Drawing_Matrix* )
```

**描述**

判断矩阵是否是单位矩阵。 

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 

**返回：**

函数返回true表示矩阵是单位矩阵，函数返回false表示矩阵不是单位矩阵。


### OH_Drawing_MatrixPostRotate()

```
void OH_Drawing_MatrixPostRotate (OH_Drawing_Matrix* , float degree, float px, float py )
```

**描述**

将矩阵设置为矩阵右乘围绕轴心点旋转一定角度的单位矩阵后得到的矩阵。 

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| degree | 旋转角度，单位为度。正数表示顺时针旋转，负数表示逆时针旋转。 | 
| px | 旋转中心点的横坐标。 | 
| py | 旋转中心点的纵坐标。 | 


### OH_Drawing_MatrixPostScale()

```
void OH_Drawing_MatrixPostScale (OH_Drawing_Matrix* , float sx, float sy, float px, float py )
```

**描述**

将矩阵设置为矩阵右乘围绕轴心点按一定缩放因子缩放后的单位矩阵后得到的矩阵。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。


**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| sx | x轴方向的缩放比例因子，为负数时可看作是先关于y = px作镜像翻转后再进行缩放，该参数为浮点数。 | 
| sy | y轴方向的缩放比例因子，为负数时可看作是先关于x = py作镜像翻转后再进行缩放，该参数为浮点数。 | 
| px | 缩放中心点的横坐标。 | 
| py | 缩放中心点的纵坐标。 | 


### OH_Drawing_MatrixPostTranslate()

```
void OH_Drawing_MatrixPostTranslate (OH_Drawing_Matrix* , float dx, float dy )
```

**描述**

将矩阵设置为矩阵右乘平移一定距离后的单位矩阵后得到的矩阵。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。


**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| dx | 表示在x轴方向上的平移距离。 | 
| dy | 表示在y轴方向上的平移距离。 | 


### OH_Drawing_MatrixPreRotate()

```
void OH_Drawing_MatrixPreRotate (OH_Drawing_Matrix* , float degree, float px, float py )
```

**描述**

将矩阵设置为矩阵左乘围绕轴心点旋转一定角度的单位矩阵后得到的矩阵。 

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。


**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| degree | 旋转角度，单位为度。正数表示顺时针旋转，负数表示逆时针旋转。 | 
| px | 旋转中心点的横坐标。 | 
| py | 旋转中心点的纵坐标。 | 


### OH_Drawing_MatrixPreScale()

```
void OH_Drawing_MatrixPreScale (OH_Drawing_Matrix* , float sx, float sy, float px, float py )
```

**描述**

将矩阵设置为矩阵左乘围绕轴心点按一定缩放因子缩放后的单位矩阵后得到的矩阵。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。


**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| sx | x轴方向的缩放比例因子，为负数时可看作是先关于y = px作镜像翻转后再进行缩放，该参数为浮点数。 | 
| sy | y轴方向的缩放比例因子，为负数时可看作是先关于x = py作镜像翻转后再进行缩放，该参数为浮点数。 | 
| px | 缩放中心点的横坐标。 | 
| py | 缩放中心点的纵坐标。 | 


### OH_Drawing_MatrixPreTranslate()

```
void OH_Drawing_MatrixPreTranslate (OH_Drawing_Matrix* , float dx, float dy )
```

**描述**

将矩阵设置为矩阵左乘平移一定距离后的单位矩阵后得到的矩阵。 

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| dx | 表示在x轴方向上的平移距离。 | 
| dy | 表示在y轴方向上的平移距离。 | 


### OH_Drawing_MatrixReset()

```
void OH_Drawing_MatrixReset (OH_Drawing_Matrix* )
```

**描述**

重置当前矩阵为单位矩阵: | 1 0 0 | | 0 1 0 | | 0 0 1 |。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 


### OH_Drawing_MatrixRotate()

```
void OH_Drawing_MatrixRotate (OH_Drawing_Matrix* , float degree, float px, float py )
```

**描述**

设置矩阵为单位矩阵，并围绕位于(px, py)的旋转轴点进行旋转。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| degree | 角度，单位为度。正数表示顺时针旋转，负数表示逆时针旋转。 | 
| px | x轴上坐标点。 | 
| py | y轴上坐标点。 | 


### OH_Drawing_MatrixScale()

```
void OH_Drawing_MatrixScale (OH_Drawing_Matrix* , float sx, float sy, float px, float py )
```

**描述**

设置矩阵为单位矩阵，并围绕位于(px, py)的旋转轴点，以sx和sy进行缩放。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| sx | 水平缩放因子，为负数时可看作是先关于y = px作镜像翻转后再进行缩放，该参数为浮点数。 | 
| sy | 垂直缩放因子，为负数时可看作是先关于x = py作镜像翻转后再进行缩放，该参数为浮点数。 | 
| px | x轴上坐标点。 | 
| py | y轴上坐标点。 | 


### OH_Drawing_MatrixSetMatrix()

```
void OH_Drawing_MatrixSetMatrix (OH_Drawing_Matrix* , float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2 )
```

**描述**

用于给矩阵对象设置参数。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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


### OH_Drawing_MatrixSetPolyToPoly()

```
bool OH_Drawing_MatrixSetPolyToPoly (OH_Drawing_Matrix* , const OH_Drawing_Point2D* src, const OH_Drawing_Point2D* dst, uint32_t count )
```

**描述**

通过设置源点以及目标点，生成对应的变换矩阵。 源点以及目标点的个数要大于等于0，小于等于4。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

count小于0或者大于4时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| src | 源点数组，为NULL时count应当为0。 | 
| dst | 目标点数组，个数要与源点相等，为NULL时count应当为0。 | 
| count | 源点数组以及目标点数组的个数，为0时将矩阵对象设为单位矩阵。 | 

**返回：**

函数返回是否可以生成对应矩阵以用来完成变换。true表示矩阵生成成功，false表示无法生成对应矩阵。


### OH_Drawing_MatrixSetRectToRect()

```
bool OH_Drawing_MatrixSetRectToRect (OH_Drawing_Matrix* , const OH_Drawing_Rect* src, const OH_Drawing_Rect* dst, OH_Drawing_ScaleToFit stf )
```

**描述**

将矩阵以缩放方式适配目标矩阵。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix、src、dst任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| src | 指向映射源的[OH_Drawing_Rect](#oh_drawing_rect)对象Rect的指针。 | 
| dst | 指向要映射到的[OH_Drawing_Rect](#oh_drawing_rect)对象Rect的指针。 | 
| stf | 缩放方式，支持方式[OH_Drawing_ScaleToFit](#oh_drawing_scaletofit)。 | 

**返回：**

如果设置失败，则返回false；如果设置成功，则返回true；特别地，如果源矩形src的宽高任意一个小于等于0，则返回false，并将矩阵设置为单位矩阵；如果目标矩形dst的宽高任意一个小于等于0，则返回true，并将矩阵设置为除透视缩放系数为1外其余值皆为0的矩阵。

### OH_Drawing_MatrixTranslate()

```
void OH_Drawing_MatrixTranslate (OH_Drawing_Matrix* , float dx, float dy )
```

**描述**

设置矩阵为单位矩阵，并平移(dx, dy)。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Matrix为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| dx | 水平方向平移距离，正数表示往x轴正方向平移，负数表示往x轴负方向平移，该参数为浮点数。 | 
| dy | 垂直方向平移距离，正数表示往y轴正方向平移，负数表示往y轴负方向平移，该参数为浮点数。 | 


### OH_Drawing_MemoryStreamCreate()

```
OH_Drawing_MemoryStream* OH_Drawing_MemoryStreamCreate (const void* data, size_t length, bool copyData )
```

**描述**

创建一个内存流对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

data为NULL或者length等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 数据段。 | 
| length | 数据段长度。 | 
| copyData | 是否拷贝数据。true表示内存流对象会拷贝一份数据段数据， false表示内存流对象直接使用数据段数据，不拷贝。 | 

**返回：**

函数会返回一个指针，指针指向创建的内存流对象[OH_Drawing_MemoryStream](#oh_drawing_memorystream)。


### OH_Drawing_MemoryStreamDestroy()

```
void OH_Drawing_MemoryStreamDestroy (OH_Drawing_MemoryStream* )
```

**描述**

销毁内存流对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_MemoryStream | 指向内存流对象[OH_Drawing_MemoryStream](#oh_drawing_memorystream)的指针。 | 


### OH_Drawing_PathAddArc()

```
void OH_Drawing_PathAddArc (OH_Drawing_Path* , const OH_Drawing_Rect* , float startAngle, float sweepAngle )
```

**描述**

将圆弧添加到路径中，作为新轮廓的起点。从起始角度到扫掠角度添加弧， 添加的弧是椭圆边界椭圆的一部分，单位为度。正扫掠表示按顺时针方向延长弧， 负扫掠表示按逆时针方向延长弧。如果扫掠角度&lt;= -360°，或扫掠角度&gt;= 360°， 并且起始角度对90取模接近于0，则添加椭圆而不是弧。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。 | 
| startAngle | 弧的起始角度，单位为度。 | 
| sweepAngle | 扫描的度数，为正数时顺时针扫描，为负数时逆时针扫描。实际扫描的度数为该入参对360取模的结果。 | 

### OH_Drawing_PathAddOval()

```
void OH_Drawing_PathAddOval (OH_Drawing_Path* , const OH_Drawing_Rect* , OH_Drawing_PathDirection  )
```

**描述**

按指定方向，向路径添加椭圆。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。 | 
| OH_Drawing_PathDirection | 路径方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)。 | 

### OH_Drawing_PathAddOvalWithInitialPoint()

```
void OH_Drawing_PathAddOvalWithInitialPoint (OH_Drawing_Path* , const OH_Drawing_Rect* , uint32_t start, OH_Drawing_PathDirection  )
```

**描述**

将椭圆添加到路径中，其中矩形对象作为椭圆的外切矩形区域，绘制方向用来指定绘制时是顺时针或者逆时针方向。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PathDirection不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。 | 
| start | 表示椭圆初始点的索引。 | 
| OH_Drawing_PathDirection | 表示绘制方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)。 | 


### OH_Drawing_PathAddPath()

```
void OH_Drawing_PathAddPath (OH_Drawing_Path* , const OH_Drawing_Path* src, const OH_Drawing_Matrix*  )
```

**描述**

将源路径矩阵变换后，添加到当前路径中。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向当前路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| src | 指向源路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针，为NULL表示单位矩阵。 | 


### OH_Drawing_PathAddPathWithMatrixAndMode()

```
void OH_Drawing_PathAddPathWithMatrixAndMode (OH_Drawing_Path* path, const OH_Drawing_Path* src, const OH_Drawing_Matrix* , OH_Drawing_PathAddMode  )
```

**描述**

将源路径矩阵变换后，以规定模式添加到当前路径中。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向当前路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| src | 指向源路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针，为NULL表示单位矩阵。 | 
| OH_Drawing_PathAddMode | 路径添加模式[OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)。 | 


### OH_Drawing_PathAddPathWithMode()

```
void OH_Drawing_PathAddPathWithMode (OH_Drawing_Path* path, const OH_Drawing_Path* src, OH_Drawing_PathAddMode  )
```

**描述**

将源路径以规定模式添加到当前路径中。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向当前路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| src | 指向源路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_PathAddMode | 路径添加模式[OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)。 | 


### OH_Drawing_PathAddPathWithOffsetAndMode()

```
void OH_Drawing_PathAddPathWithOffsetAndMode (OH_Drawing_Path* path, const OH_Drawing_Path* src, float dx, float dy, OH_Drawing_PathAddMode  )
```

**描述**

将源路径偏移后，以规定模式添加到当前路径中。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path、src任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

OH_Drawing_PathAddMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向当前路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| src | 指向源路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| dx | 添加到目标路径横坐标的偏移量。 | 
| dy | 添加到目标路径纵坐标的偏移量。 | 
| OH_Drawing_PathAddMode | 路径添加模式[OH_Drawing_PathAddMode](#oh_drawing_pathaddmode)。 | 


### OH_Drawing_PathAddRect()

```
void OH_Drawing_PathAddRect (OH_Drawing_Path* , float left, float top, float right, float bottom, OH_Drawing_PathDirection  )
```

**描述**

按指定方向，将矩形添加到路径中，添加的路径的起始点为矩形左上角。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| left | 矩形左上角的x轴坐标。 | 
| top | 矩形左上角的y轴坐标。 | 
| right | 矩形右下角的x轴坐标。 | 
| bottom | 矩形右下角的y轴坐标。 | 
| OH_Drawing_PathDirection | 路径方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)。 | 


### OH_Drawing_PathAddRectWithInitialCorner()

```
void OH_Drawing_PathAddRectWithInitialCorner (OH_Drawing_Path* , const OH_Drawing_Rect* , OH_Drawing_PathDirection , uint32_t start )
```

**描述**

按指定方向，向路径添加矩形轮廓。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针。 | 
| OH_Drawing_PathDirection | 表示绘制方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)。 | 
| start | 起始点的位置，表示从矩形的哪个角开始绘制路径。0：左上角，1：右上角，2：右下角，3：左下角。 | 


### OH_Drawing_PathAddRoundRect()

```
void OH_Drawing_PathAddRoundRect (OH_Drawing_Path* , const OH_Drawing_RoundRect* roundRect, OH_Drawing_PathDirection  )
```

**描述**

按指定方向，向路径添加圆角矩形轮廓。路径添加方向为顺时针时，起始点位于圆角矩形左下方圆角与左边界的交点；路径添加方向为逆时针时，起始点位于圆角矩形左上方圆角与左边界的交点。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path、roundRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PathDirection不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| roundRect | 指向圆角矩形对象[OH_Drawing_RoundRect](#oh_drawing_roundrect)的指针。 | 
| OH_Drawing_PathDirection | 路径方向[OH_Drawing_PathDirection](#oh_drawing_pathdirection)。 | 


### OH_Drawing_PathArcTo()

```
void OH_Drawing_PathArcTo (OH_Drawing_Path* , float x1, float y1, float x2, float y2, float startDeg, float sweepDeg )
```

**描述**

用于给路径添加一段弧线，绘制弧线的方式为角度弧，该方式首先会指定一个矩形边框，矩形边框会包裹椭圆， 然后会指定一个起始角度和扫描度数，从起始角度扫描截取的椭圆周长一部分即为绘制的弧线。另外会默认添加一条从路径的最后点位置到弧线起始点位置的线段。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
| startDeg | 起始的角度。角度的起始方向（0°）为x轴正方向。 | 
| sweepDeg | 扫描的度数，为正数时顺时针扫描，为负数时逆时针扫描。实际扫描的度数为该入参对360取模的结果。 | 


### OH_Drawing_PathClose()

```
void OH_Drawing_PathClose (OH_Drawing_Path* )
```

**描述**

用于闭合路径，会添加一条从路径起点位置到最后点位置的线段。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 | 


### OH_Drawing_PathConicTo()

```
void OH_Drawing_PathConicTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY, float weight )
```

**描述**

在当前路径上添加一条路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的圆锥曲线，其控制点为 (ctrlX, ctrlY)，结束点为 (endX, endY)。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| ctrlX | 控制点位置的横坐标。 | 
| ctrlY | 控制点位置的纵坐标。 | 
| endX | 结束点位置的横坐标。 | 
| endY | 结束点位置的纵坐标。 | 
| weight | 表示曲线的权重，决定了曲线的形状，越大越接近控制点。若小于等于0则等同于使用[OH_Drawing_PathLineTo](#oh_drawing_pathlineto)添加一条到结束点的线段，若为1则等同于[OH_Drawing_PathQuadTo](#oh_drawing_pathquadto)。 | 


### OH_Drawing_PathContains()

```
bool OH_Drawing_PathContains (OH_Drawing_Path* , float x, float y )
```

**描述**

判断指定坐标点是否被路径包含，判定是否被路径包含的规则参考[OH_Drawing_PathFillType](#oh_drawing_pathfilltype-1)。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| x | x轴上坐标点。 | 
| y | y轴上坐标点。 | 

**返回：**

函数返回true表示点在路径内，函数返回false表示点在路径外。


### OH_Drawing_PathCopy()

```
OH_Drawing_Path* OH_Drawing_PathCopy (OH_Drawing_Path* )
```

**描述**

创建一个路径对象副本[OH_Drawing_Path](#oh_drawing_path)，用于拷贝一个已有路径对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 

**返回：**

函数返回一个指针，指针指向创建的路径对象副本[OH_Drawing_Path](#oh_drawing_path)。


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
void OH_Drawing_PathCubicTo (OH_Drawing_Path* , float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY )
```

**描述**

用于添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的三阶贝塞尔圆滑曲线。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
void OH_Drawing_PathDestroy (OH_Drawing_Path* )
```

**描述**

用于销毁路径对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 | 


### OH_Drawing_PathEffectDestroy()

```
void OH_Drawing_PathEffectDestroy (OH_Drawing_PathEffect* )
```

**描述**

销毁路径效果对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_PathEffect | 指向路径效果对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)的指针。 | 


### OH_Drawing_PathGetLength()

```
float OH_Drawing_PathGetLength (OH_Drawing_Path* , bool forceClosed )
```

**描述**

获取当前路径的长度。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| forceClosed | 表示是否按照闭合路径测量，true表示测量时路径会被强制视为已闭合，false表示会根据路径的实际闭合状态测量。 | 

**返回：**

函数返回当前路径的长度。


### OH_Drawing_PathLineTo()

```
void OH_Drawing_PathLineTo (OH_Drawing_Path* , float x, float y )
```

**描述**

用于添加一条从路径的最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
void OH_Drawing_PathMoveTo (OH_Drawing_Path* , float x, float y )
```

**描述**

用于设置自定义路径的起始点位置。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 | 
| x | 起始点的横坐标。 | 
| y | 起始点的纵坐标。 | 


### OH_Drawing_PathOffset()

```
void OH_Drawing_PathOffset (OH_Drawing_Path* path, OH_Drawing_Path* dst, float dx, float dy )
```

**描述**

将路径中的所有点沿着x轴和y轴方向偏移一定距离，并将结果存储到目标路径对象中。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向当前路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| dst | 指向目标路径对象[OH_Drawing_Path](#oh_drawing_path)的指针，为NULL时会将结果存储到当前路径对象中。 | 
| dx | x轴方向的偏移量。 | 
| dy | y轴方向的偏移量。 | 


### OH_Drawing_PathQuadTo()

```
void OH_Drawing_PathQuadTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY )
```

**描述**

用于添加一条从路径最后点位置（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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


### OH_Drawing_PathRConicTo()

```
void OH_Drawing_PathRConicTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY, float weight )
```

**描述**

使用相对位置在当前路径上添加一条路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的圆锥曲线。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| ctrlX | 相对于路径终点的x轴偏移量，用于指定控制点的横坐标。 | 
| ctrlY | 相对于路径终点的y轴偏移量，用于指定控制点的纵坐标。 | 
| endX | 相对于路径终点的x轴偏移量，用于指定目标点的横坐标。 | 
| endY | 相对于路径终点的y轴偏移量，用于指定目标点的纵坐标。 | 
| weight | 表示曲线的权重，决定了曲线的形状，越大越接近控制点。若小于等于0则等同于使用[OH_Drawing_PathRLineTo](#oh_drawing_pathrlineto)添加一条到结束点的线段，若为1则等同于[OH_Drawing_PathRQuadTo](#oh_drawing_pathrquadto)。 | 


### OH_Drawing_PathRCubicTo()

```
void OH_Drawing_PathRCubicTo (OH_Drawing_Path* , float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY )
```

**描述**

使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的三阶贝塞尔圆滑曲线。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| ctrlX1 | 相对于路径终点的x轴偏移量，用于指定第一个控制点的横坐标。 | 
| ctrlY1 | 相对于路径终点的y轴偏移量，用于指定第一个控制点的纵坐标。 | 
| ctrlX2 | 相对于路径终点的x轴偏移量，用于指定第二个控制点的横坐标。 | 
| ctrlY2 | 相对于路径终点的y轴偏移量，用于指定第二个控制点的纵坐标。 | 
| endX | 相对于路径终点的x轴偏移量，用于指定目标点的横坐标。 | 
| endY | 相对于路径终点的y轴偏移量，用于指定目标点的纵坐标。 | 


### OH_Drawing_PathReset()

```
void OH_Drawing_PathReset (OH_Drawing_Path* )
```

**描述**

用于重置自定义路径数据。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象的指针。 | 


### OH_Drawing_PathRLineTo()

```
void OH_Drawing_PathRLineTo (OH_Drawing_Path* , float x, float y )
```

**描述**

使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的线段。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| x | 相对于当前路径终点的x轴偏移量，用于指定目标点的横坐标。 | 
| y | 相对于当前路径终点的y轴偏移量，用于指定目标点的纵坐标。 | 


### OH_Drawing_PathRMoveTo()

```
void OH_Drawing_PathRMoveTo (OH_Drawing_Path* , float x, float y )
```

**描述**

用于设置一个相对于当前路径终点（若路径没有内容则默认为 (0, 0)）的路径起始点位置。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| x | 目标点相对于当前路径终点的x轴偏移量，正数往x轴正方向偏移，负数往x轴负方向偏移，该参数为浮点数。 | 
| y | 目标点相对于当前路径终点的y轴偏移量，正数往y轴正方向偏移，负数往y轴负方向偏移，该参数为浮点数。 | 


### OH_Drawing_PathRQuadTo()

```
void OH_Drawing_PathRQuadTo (OH_Drawing_Path* , float ctrlX, float ctrlY, float endX, float endY )
```

**描述**

使用相对位置在当前路径上添加一条当前路径终点（若路径没有内容则默认为 (0, 0)）到目标点位置的二阶贝塞尔曲线。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| ctrlX | 相对于路径终点的x轴偏移量，用于指定控制点的横坐标。 | 
| ctrlY | 相对于路径终点的y轴偏移量，用于指定控制点的纵坐标。 | 
| endX | 相对于路径终点的x轴偏移量，用于指定目标点的横坐标。 | 
| endY | 相对于路径终点的y轴偏移量，用于指定目标点的纵坐标。 | 


### OH_Drawing_PathSetFillType()

```
void OH_Drawing_PathSetFillType (OH_Drawing_Path* , OH_Drawing_PathFillType  )
```

**描述**

设置路径的填充类型，这个决定了路径内部区域的定义方式。例如，使用 Winding 填充类型时，路径内部区域由路径环绕的次数决定，而使用 EvenOdd 填充类型时，路径内部区域由路径环绕的次数是否为奇数决定。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PathFillType不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_PathFillType | 路径填充规则[OH_Drawing_PathFillType](#oh_drawing_pathfilltype)。 | 


### OH_Drawing_PathTransform()

```
void OH_Drawing_PathTransform (OH_Drawing_Path* , const OH_Drawing_Matrix*  )
```

**描述**

对路径进行矩阵变换。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Path、OH_Drawing_Matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Path | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 


### OH_Drawing_PathTransformWithPerspectiveClip()

```
void OH_Drawing_PathTransformWithPerspectiveClip (OH_Drawing_Path* src, const OH_Drawing_Matrix* , OH_Drawing_Path* dst, bool applyPerspectiveClip )
```

**描述**

对路径进行矩阵变换。用转换后的路径替换目标路径，如果目标路径为空，则替换源路径。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

src、OH_Drawing_Matrix任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| src | 指向路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。 | 
| dst | 指向目标路径对象[OH_Drawing_Path](#oh_drawing_path)的指针。 | 
| applyPerspectiveClip | 表示变换路径是否应用透视裁剪。true表示应用透视裁剪，false表示不用透视裁剪。 | 


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
void OH_Drawing_PenDestroy (OH_Drawing_Pen* )
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
uint8_t OH_Drawing_PenGetAlpha (const OH_Drawing_Pen* )
```

**描述**

获取画笔的透明度值。画笔在勾勒图形时透明通道会使用该值。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap (const OH_Drawing_Pen* )
```

**描述**

用于获取画笔笔帽的样式。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
uint32_t OH_Drawing_PenGetColor (const OH_Drawing_Pen* )
```

**描述**

用于获取画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 

**返回：**

函数返回一个描述颜色的32位（ARGB）变量。


### OH_Drawing_PenGetFilter()

```
void OH_Drawing_PenGetFilter (OH_Drawing_Pen* , OH_Drawing_Filter*  )
```

**描述**

从画笔获取滤波器[OH_Drawing_Filter](#oh_drawing_filter)。滤波器是一个容器，可以承载蒙版滤波器和颜色滤波器。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen、OH_Drawing_Filter任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象[OH_Drawing_Pen](#oh_drawing_pen)的指针。 | 
| OH_Drawing_Filter | 指向滤波器对象[OH_Drawing_Filter](#oh_drawing_filter)的指针。 | 


### OH_Drawing_PenGetJoin()

```
OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin (const OH_Drawing_Pen* )
```

**描述**

用于获取画笔绘制折线转角的样式。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
float OH_Drawing_PenGetMiterLimit (const OH_Drawing_Pen* )
```

**描述**

用于获取折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

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
float OH_Drawing_PenGetWidth (const OH_Drawing_Pen* )
```

**描述**

获取画笔的线宽，线宽描述了画笔绘制图形轮廓的宽度。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 

**返回：**

函数返回画笔的线宽。


### OH_Drawing_PenIsAntiAlias()

```
bool OH_Drawing_PenIsAntiAlias (const OH_Drawing_Pen* )
```

**描述**

用于获取画笔是否设置抗锯齿属性，如果为真则说明画笔会启用抗锯齿功能，在绘制图形时会对图形的边缘像素进行半透明的模糊处理。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 

**返回：**

函数返回画笔对象是否设置抗锯齿属性，返回真则设置了抗锯齿，返回假则没有设置抗锯齿。


### OH_Drawing_PenReset()

```
void OH_Drawing_PenReset (OH_Drawing_Pen* )
```

**描述**

将画笔重置至初始值。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象[OH_Drawing_Pen](#oh_drawing_pen)的指针。 | 


### OH_Drawing_PenSetAlpha()

```
void OH_Drawing_PenSetAlpha (OH_Drawing_Pen* , uint8_t alpha )
```

**描述**

为画笔设置透明度值。画笔在勾勒图形时透明通道会使用该值。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 表示指向画笔对象的指针。 | 
| alpha | 表示要设置的透明度值，是一个8比特的变量。 | 


### OH_Drawing_PenSetAntiAlias()

```
void OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen* , bool  )
```

**描述**

用于设置画笔的抗锯齿属性，设置为真则画笔在绘制图形时会对图形的边缘像素进行半透明的模糊处理。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 
| bool | 真为抗锯齿，假则不做抗锯齿处理。 | 


### OH_Drawing_PenSetBlendMode()

```
void OH_Drawing_PenSetBlendMode (OH_Drawing_Pen* , OH_Drawing_BlendMode  )
```

**描述**

为画笔设置一个混合器，该混合器实现了指定的混合模式枚举。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_BlendMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象[OH_Drawing_Pen](#oh_drawing_pen)的指针。 | 
| OH_Drawing_BlendMode | 混合模式枚举类型[OH_Drawing_BlendMode](#oh_drawing_blendmode)。 | 


### OH_Drawing_PenSetCap()

```
void OH_Drawing_PenSetCap (OH_Drawing_Pen* , OH_Drawing_PenLineCapStyle  )
```

**描述**

用于设置画笔笔帽样式。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PenLineCapStyle不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 
| OH_Drawing_PenLineCapStyle | 描述画笔笔帽样式的变量。 | 


### OH_Drawing_PenSetColor()

```
void OH_Drawing_PenSetColor (OH_Drawing_Pen* , uint32_t color )
```

**描述**

用于设置画笔的颜色属性，颜色属性描述了画笔绘制图形轮廓时使用的颜色，用一个32位（ARGB）的变量表示。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 
| color | 描述颜色的32位（ARGB）变量。 | 


### OH_Drawing_PenSetFilter()

```
void OH_Drawing_PenSetFilter (OH_Drawing_Pen* , OH_Drawing_Filter*  )
```

**描述**

设置画笔滤波器。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象[OH_Drawing_Pen](#oh_drawing_pen)的指针。 | 
| OH_Drawing_Filter | 指向滤波器[OH_Drawing_Filter](#oh_drawing_filter)的指针，为NULL表示清空画笔滤波器。 | 


### OH_Drawing_PenSetJoin()

```
void OH_Drawing_PenSetJoin (OH_Drawing_Pen* , OH_Drawing_PenLineJoinStyle  )
```

**描述**

用于设置画笔绘制转角的样式。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_PenLineJoinStyle不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 
| OH_Drawing_PenLineJoinStyle | 折线转角样式。 | 


### OH_Drawing_PenSetMiterLimit()

```
void OH_Drawing_PenSetMiterLimit (OH_Drawing_Pen* , float miter )
```

**描述**

用于设置折线尖角的限制值，当画笔绘制一条折线，转角类型设置为尖角时，那么此时该属性用于限制出现尖角的长度范围，如果超出则平角显示，不超出依然为尖角。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 
| miter | 描述尖角限制值的变量。 | 


### OH_Drawing_PenSetPathEffect()

```
void OH_Drawing_PenSetPathEffect (OH_Drawing_Pen* , OH_Drawing_PathEffect*  )
```

**描述**

设置画笔路径效果。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象[OH_Drawing_Pen](#oh_drawing_pen)的指针。 | 
| OH_Drawing_PathEffect | 指向路径效果对象[OH_Drawing_PathEffect](#oh_drawing_patheffect)的指针，为NULL表示清空路径效果。 | 


### OH_Drawing_PenSetShaderEffect()

```
void OH_Drawing_PenSetShaderEffect (OH_Drawing_Pen* , OH_Drawing_ShaderEffect*  )
```

**描述**

设置画笔着色器效果。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象[OH_Drawing_Pen](#oh_drawing_pen)的指针。 | 
| OH_Drawing_ShaderEffect | 指向着色器对象[OH_Drawing_ShaderEffect](#oh_drawing_shadereffect)的指针，为NULL表示清空着色器效果。 | 


### OH_Drawing_PenSetWidth()

```
void OH_Drawing_PenSetWidth (OH_Drawing_Pen* , float width )
```

**描述**

用于设置画笔的线宽。0线宽被视作特殊的极细线宽，在绘制时始终会被绘制为1像素，不随画布的缩放而改变；负数线宽在实际绘制时会被视作0线宽。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Pen为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Pen | 指向画笔对象的指针。 | 
| width | 描述画笔线宽的变量。 | 


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
void OH_Drawing_PointDestroy (OH_Drawing_Point* )
```

**描述**

用于销毁坐标点对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Point | 指向坐标点对象的指针。 | 


### OH_Drawing_RectCopy()

```
void OH_Drawing_RectCopy (OH_Drawing_Rect* sRect, OH_Drawing_Rect* dRect )
```

**描述**

用于将源矩形对象复制到目标矩形对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

sRect、dRect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| sRect | 指向源矩形对象的指针。 | 
| dRect | 指向目标矩形对象的指针。 | 


### OH_Drawing_RectCreate()

```
OH_Drawing_Rect* OH_Drawing_RectCreate (float left, float top, float right, float bottom )
```

**描述**

用于创建一个矩形对象，不会对设置的坐标排序，即允许矩形设置的左上角坐标大于对应的矩形右下角坐标。

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
void OH_Drawing_RectDestroy (OH_Drawing_Rect* )
```

**描述**

用于销毁矩形对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 | 


### OH_Drawing_RectGetBottom()

```
float OH_Drawing_RectGetBottom (OH_Drawing_Rect* )
```

**描述**

用于获取给矩形设置的右下角的纵坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 | 

**返回：**

矩形右下角的纵坐标。


### OH_Drawing_RectGetHeight()

```
float OH_Drawing_RectGetHeight (OH_Drawing_Rect* )
```

**描述**

用于获取矩形对象高度，计算方式为设置的矩形的右下角纵坐标减去左上角纵坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 | 

**返回：**

返回矩形对象的高度，单位为像素。


### OH_Drawing_RectGetLeft()

```
float OH_Drawing_RectGetLeft (OH_Drawing_Rect* )
```

**描述**

用于获取给矩形设置的左上角的横坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 | 

**返回：**

矩形左上角的横坐标。


### OH_Drawing_RectGetRight()

```
float OH_Drawing_RectGetRight (OH_Drawing_Rect* )
```

**描述**

用于获取给矩形设置的右下角的横坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 | 

**返回：**

矩形右下角的横坐标。


### OH_Drawing_RectGetTop()

```
float OH_Drawing_RectGetTop (OH_Drawing_Rect* )
```

**描述**

用于获取给矩形设置的左上角的纵坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 | 

**返回：**

矩形左上角的纵坐标。


### OH_Drawing_RectGetWidth()

```
float OH_Drawing_RectGetWidth (OH_Drawing_Rect* )
```

**描述**

用于获取矩形对象的宽度，计算方式为设置的矩形的右下角横坐标减去左上角横坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 | 

**返回：**

返回矩形对象的宽度，单位为像素。


### OH_Drawing_RectIntersect()

```
bool OH_Drawing_RectIntersect (OH_Drawing_Rect* rect, const OH_Drawing_Rect* other )
```

**描述**

用于判断两个矩形是否相交，若相交，将rect设置为两个矩形的交集。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

rect、other任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rect | 指向矩形对象的指针。 | 
| other | 指向矩形对象的指针。 | 

**返回：**

返回两个矩形是否相交的结果。true表示这两个矩形相交，rect被设置为两个矩形的交集；false表示不相交，rect保持不变。


### OH_Drawing_RectSetBottom()

```
void OH_Drawing_RectSetBottom (OH_Drawing_Rect* rect, float bottom )
```

**描述**

用于设置矩形右下角的纵坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rect | 指向矩形对象的指针。 | 
| bottom | 矩形右下角的纵坐标。 | 


### OH_Drawing_RectSetLeft()

```
void OH_Drawing_RectSetLeft (OH_Drawing_Rect* rect, float left )
```

**描述**

用于设置矩形左上角的横坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rect | 指向矩形对象的指针。 | 
| left | 矩形左上角的横坐标。 | 


### OH_Drawing_RectSetRight()

```
void OH_Drawing_RectSetRight (OH_Drawing_Rect* rect, float right )
```

**描述**

用于设置矩形右下角的横坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rect | 指向矩形对象的指针。 | 
| right | 矩形右下角的横坐标。 | 


### OH_Drawing_RectSetTop()

```
void OH_Drawing_RectSetTop (OH_Drawing_Rect* rect, float top )
```

**描述**

用于设置矩形左上角的纵坐标。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rect | 指向矩形对象的指针。 | 
| top | 矩形左上角的纵坐标。 | 


### OH_Drawing_RegionCreate()

```
OH_Drawing_Region* OH_Drawing_RegionCreate (void )
```

**描述**

用于创建一个区域对象，实现更精确的图形控制。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

函数会返回一个指针，指针指向创建的区域对象。


### OH_Drawing_RegionDestroy()

```
void OH_Drawing_RegionDestroy (OH_Drawing_Region* )
```

**描述**

用于销毁区域对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Region | 指向区域对象的指针。 | 


### OH_Drawing_RegionSetRect()

```
bool OH_Drawing_RegionSetRect (OH_Drawing_Region* region, const OH_Drawing_Rect* rect )
```

**描述**

用于尝试给区域对象设置矩形边界。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

region、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| region | 指向区域对象的指针。 | 
| rect | 指向矩形对象的指针。 | 

**返回：**

返回区域对象设置矩形边界是否成功的结果。true表示设置矩形边界成功，false表示设置矩形边界失败。


### OH_Drawing_RegisterFont()

```
uint32_t OH_Drawing_RegisterFont (OH_Drawing_FontCollection* , const char* fontFamily, const char* familySrc )
```

**描述**

用于在字体管理器中注册自定义字体，支持的字体文件格式包含：ttf、otf。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontCollection | 指向OH_Drawing_FontCollection对象的指针。 | 
| fontFamily | 指需要注册的字体的字体名称。 | 
| familySrc | 指需要注册的字体文件的路径。 | 

**返回：**

返回错误代码，0为成功，1为文件不存在，2为打开文件失败，3为读取文件失败，4为寻找文件失败，5为获取大小失败，9文件损坏。


### OH_Drawing_RegisterFontBuffer()

```
uint32_t OH_Drawing_RegisterFontBuffer (OH_Drawing_FontCollection* , const char* fontFamily, uint8_t* fontBuffer, size_t length )
```

**描述**

用于在字体管理器中注册字体缓冲区。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FontCollection | 指向OH_Drawing_FontCollection对象的指针。 | 
| fontFamily | 指需要注册的字体的字体名称。 | 
| fontBuffer | 指需要注册的字体文件的缓冲区。 | 
| length | 指需要注册的字体文件的长度。 | 

**返回：**

返回错误代码，0为成功，6为缓冲区大小为零，7为字体集合为空，9文件损坏。


### OH_Drawing_RoundRectCreate()

```
OH_Drawing_RoundRect* OH_Drawing_RoundRectCreate (const OH_Drawing_Rect* , float xRad, float yRad )
```

**描述**

用于创建一个圆角矩形对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Rect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Rect | 指向矩形对象的指针。 | 
| xRad | X轴上的圆角半径，小于或等于0时无效。 | 
| yRad | Y轴上的圆角半径，小于或等于0时无效。 | 

**返回：**

函数会返回一个指针，指针指向创建的圆角矩形对象。


### OH_Drawing_RoundRectDestroy()

```
void OH_Drawing_RoundRectDestroy (OH_Drawing_RoundRect* )
```

**描述**

用于销毁圆角矩形对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_RoundRect | 指向圆角矩形对象的指针。 | 


### OH_Drawing_RoundRectGetCorner()

```
OH_Drawing_Corner_Radii OH_Drawing_RoundRectGetCorner (OH_Drawing_RoundRect* , OH_Drawing_CornerPos pos )
```

**描述**

用于获取圆角矩形中指定圆角位置的圆角半径。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_RoundRect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_RoundRect | 指向圆角矩形对象的指针。 | 
| pos | 圆角位置的枚举，支持类型可见[OH_Drawing_CornerPos](#oh_drawing_cornerpos)。 | 

**返回：**

返回指定圆角位置的圆角半径结构体[OH_Drawing_Corner_Radii](#oh_drawing_corner_radii)，其中包含x轴方向和y轴方向上的半径。


### OH_Drawing_RoundRectSetCorner()

```
void OH_Drawing_RoundRectSetCorner (OH_Drawing_RoundRect* , OH_Drawing_CornerPos pos, OH_Drawing_Corner_Radii  )
```

**描述**

用于设置圆角矩形中指定圆角位置的圆角半径。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_RoundRect为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_RoundRect | 指向圆角矩形对象的指针。 | 
| pos | 圆角位置的枚举，支持类型可见[OH_Drawing_CornerPos](#oh_drawing_cornerpos)。 | 
| OH_Drawing_Corner_Radii | 圆角半径结构体[OH_Drawing_Corner_Radii](#oh_drawing_corner_radii)，其中包含x轴方向和y轴方向上的半径，半径需大于或等于0。 | 


### OH_Drawing_SamplingOptionsCreate()

```
OH_Drawing_SamplingOptions* OH_Drawing_SamplingOptionsCreate (OH_Drawing_FilterMode , OH_Drawing_MipmapMode  )
```

**描述**

创建一个采样选项对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_MipmapMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_FilterMode | 过滤采样模式[OH_Drawing_FilterMode](#oh_drawing_filtermode)。 | 
| OH_Drawing_MipmapMode | 多级渐远纹理采样模式[OH_Drawing_MipmapMode](#oh_drawing_mipmapmode)。 | 

**返回：**

函数会返回一个指针，指针指向创建的采样选项对象[OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)。


### OH_Drawing_SamplingOptionsDestroy()

```
void OH_Drawing_SamplingOptionsDestroy (OH_Drawing_SamplingOptions* )
```

**描述**

销毁采样选项对象并回收该对象占有内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_SamplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)的指针。 | 


### OH_Drawing_SetTextStyleBackgroundBrush()

```
void OH_Drawing_SetTextStyleBackgroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**描述**

设置指定文本样式中的背景色画刷。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Brush | 指向画刷[OH_Drawing_Brush](#oh_drawing_brush)对象的指针，由[OH_Drawing_BrushCreate](#oh_drawing_brushcreate)获取。 | 


### OH_Drawing_SetTextStyleBackgroundPen()

```
void OH_Drawing_SetTextStyleBackgroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**描述**

设置指定文本样式中的背景色画笔。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Pen | 指向画笔[OH_Drawing_Pen](#oh_drawing_pen)对象的指针，由[OH_Drawing_PenCreate](#oh_drawing_pencreate)获取。 | 


### OH_Drawing_SetTextStyleBaseLine()

```
void OH_Drawing_SetTextStyleBaseLine (OH_Drawing_TextStyle* , int  )
```

**描述**

设置文本样式的字体基线位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| int | 设置字体基线位置，设置1基线位于底部，设置0或其它基线在中间偏下的位置，具体可见[OH_Drawing_TextBaseline](#oh_drawing_textbaseline)枚举。 | 


### OH_Drawing_SetTextStyleColor()

```
void OH_Drawing_SetTextStyleColor (OH_Drawing_TextStyle* , uint32_t  )
```

**描述**

设置文本颜色。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| uint32_t | 颜色。 | 


### OH_Drawing_SetTextStyleDecoration()

```
void OH_Drawing_SetTextStyleDecoration (OH_Drawing_TextStyle* , int  )
```

**描述**

设置指定文本样式中的装饰线类型，只能设置一个装饰线类型，添加多个需要使用[OH_Drawing_AddTextStyleDecoration](#oh_drawing_addtextstyledecoration)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| int | 设置装饰，设置1为下划线，设置2为上划线，设置3为删除线，设置0或其它为无装饰，具体可见[OH_Drawing_TextDecoration](#oh_drawing_textdecoration)枚举。 | 


### OH_Drawing_SetTextStyleDecorationColor()

```
void OH_Drawing_SetTextStyleDecorationColor (OH_Drawing_TextStyle* , uint32_t  )
```

**描述**

设置指定文本样式中的装饰线颜色。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| uint32_t | 颜色。 | 


### OH_Drawing_SetTextStyleDecorationStyle()

```
void OH_Drawing_SetTextStyleDecorationStyle (OH_Drawing_TextStyle* , int  )
```

**描述**

设置指定文本样式中的装饰线样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| int | 设置的文本装饰样式，支持可选的装饰样式具体可见[OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle)枚举。 | 


### OH_Drawing_SetTextStyleDecorationThicknessScale()

```
void OH_Drawing_SetTextStyleDecorationThicknessScale (OH_Drawing_TextStyle* , double  )
```

**描述**

设置文本装饰线的厚度缩放比例。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| double | 缩放比例。 | 


### OH_Drawing_SetTextStyleEllipsis()

```
void OH_Drawing_SetTextStyleEllipsis (OH_Drawing_TextStyle* , const char*  )
```

**描述**

设置文本的省略号内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| char\* | 设置省略号内容，数据类型为指向char的指针。 | 


### OH_Drawing_SetTextStyleEllipsisModal()

```
void OH_Drawing_SetTextStyleEllipsisModal (OH_Drawing_TextStyle* , int  )
```

**描述**

设置文本的省略号样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| int | 设置省略号样式，支持可选的省略号样式具体可见[OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)枚举。 | 


### OH_Drawing_SetTextStyleFontFamilies()

```
void OH_Drawing_SetTextStyleFontFamilies (OH_Drawing_TextStyle* , int , const char* fontFamilies[] )
```

**描述**

设置指定文本样式的字体家族类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| int | 字体名称数量，禁止填入负数。 | 
| char* | 指向字体家族类型的指针。 | 


### OH_Drawing_SetTextStyleFontHeight()

```
void OH_Drawing_SetTextStyleFontHeight (OH_Drawing_TextStyle* , double  )
```

**描述**

设置行高，按当前字体大小的倍数进行设置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| double | 当前字体大小的倍数。 | 


### OH_Drawing_SetTextStyleFontSize()

```
void OH_Drawing_SetTextStyleFontSize (OH_Drawing_TextStyle* , double  )
```

**描述**

设置字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| double | 字号。 | 


### OH_Drawing_SetTextStyleFontStyle()

```
void OH_Drawing_SetTextStyleFontStyle (OH_Drawing_TextStyle* , int)
```

**描述**

为指定文本样式设置字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| int | 设置字体样式，设置1为斜体，设置0或其它为非斜体，具体可见[OH_Drawing_FontStyle](#oh_drawing_fontstyle)枚举。 | 


### OH_Drawing_SetTextStyleFontStyleStruct()

```
void OH_Drawing_SetTextStyleFontStyleStruct (OH_Drawing_TextStyle* drawingTextStyle, OH_Drawing_FontStyleStruct fontStyle )
```

**描述**

设置文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 |


### OH_Drawing_SetTextStyleFontWeight()

```
void OH_Drawing_SetTextStyleFontWeight (OH_Drawing_TextStyle* , int)
```

**描述**

为指定文本样式设置字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| int | 设置字重，设置0字重为thin，设置1字重为extra-light，设置2字重为light，设置4字重为medium，设置5字重为semi-bold， 设置6字重为bold，设置7字重为extra-bold，设置8字重为black，设置3或其它字重为normal/regular，具体可见[OH_Drawing_FontWeight](#oh_drawing_fontweight)枚举。 | 


### OH_Drawing_SetTextStyleForegroundBrush()

```
void OH_Drawing_SetTextStyleForegroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**描述**

设置指定文本样式中的前景色画刷。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Brush | 指向画刷[OH_Drawing_Brush](#oh_drawing_brush)对象的指针，由[OH_Drawing_BrushCreate](#oh_drawing_brushcreate)获取。 | 


### OH_Drawing_SetTextStyleForegroundPen()

```
void OH_Drawing_SetTextStyleForegroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**描述**

设置指定文本样式中的前景色画笔。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Pen | 指向画笔[OH_Drawing_Pen](#oh_drawing_pen)对象的指针，由[OH_Drawing_PenCreate](#oh_drawing_pencreate)获取。 | 


### OH_Drawing_SetTextStyleHalfLeading()

```
void OH_Drawing_SetTextStyleHalfLeading (OH_Drawing_TextStyle* , bool  )
```

**描述**

设置文本为一半行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| bool | 设置一半行间距是否生效，true表示生效，false表示不生效。 | 


### OH_Drawing_SetTextStyleLetterSpacing()

```
void OH_Drawing_SetTextStyleLetterSpacing (OH_Drawing_TextStyle* , double  )
```

**描述**

设置文本的字符间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| double | 间距大小。 | 


### OH_Drawing_SetTextStyleLocale()

```
void OH_Drawing_SetTextStyleLocale (OH_Drawing_TextStyle* , const char*  )
```

**描述**

设置文本语言环境。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| char | 语言类型，数据类型为指向char的指针，如'en'代表英文，'zh-Hans'代表简体中文，'zh-Hant'代表繁体中文。| 


### OH_Drawing_SetTextStyleWordSpacing()

```
void OH_Drawing_SetTextStyleWordSpacing (OH_Drawing_TextStyle* , double  )
```

**描述**

设置文本的单词间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| double | 间距大小。 | 


### OH_Drawing_SetTypographyStyleFontStyleStruct()

```
void OH_Drawing_SetTypographyStyleFontStyleStruct (OH_Drawing_TypographyStyle* drawingStyle, OH_Drawing_FontStyleStruct fontStyle )
```

**描述**

设置排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| [OH_Drawing_FontStyleStruct](_o_h___drawing___font_style_struct.md) | 设置排版样式中文本样式的支柱样式的字体样式，包括字体字重、字体宽度和字体斜度。 |


### OH_Drawing_SetTypographyStyleTextStrutStyle()

```
void OH_Drawing_SetTypographyStyleTextStrutStyle (OH_Drawing_TypographyStyle* , OH_Drawing_StrutStyle*  )
```

**描述**

设置文本支柱样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) | 指向支柱样式对象[OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md)的指针，由[OH_Drawing_TypographyStyleGetStrutStyle](#oh_drawing_typographystylegetstrutstyle)获取。 | 


### OH_Drawing_SetTypographyTextAlign()

```
void OH_Drawing_SetTypographyTextAlign (OH_Drawing_TypographyStyle* , int  )
```

**描述**

设置文本对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 设置文本对齐方式，设置1为右对齐，设置2为居中对齐，设置3为两端对齐，设置4为与文字方向相同，设置5为文字方向相反，设置0或其它为左对齐，具体可见[OH_Drawing_TextAlign](#oh_drawing_textalign)枚举。 | 


### OH_Drawing_SetTypographyTextBreakStrategy()

```
void OH_Drawing_SetTypographyTextBreakStrategy (OH_Drawing_TypographyStyle* , int  )
```

**描述**

设置文本的中断策略。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 设置中断策略，支持可选的中断策略具体可见[OH_Drawing_BreakStrategy](#oh_drawing_breakstrategy)枚举。 | 


### OH_Drawing_SetTypographyTextDirection()

```
void OH_Drawing_SetTypographyTextDirection (OH_Drawing_TypographyStyle* , int  )
```

**描述**

设置指定排版样式中的文本方向。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 设置文本方向，设置0为从右到左，设置1或其他值为从左到右，具体可见[OH_Drawing_TextDirection](#oh_drawing_textdirection)枚举。 | 


### OH_Drawing_SetTypographyTextEllipsis()

```
void OH_Drawing_SetTypographyTextEllipsis (OH_Drawing_TypographyStyle* style, const char* ellipsis )
```

**描述**

设置排版样式省略号文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| char | 省略号样式。 | 


### OH_Drawing_SetTypographyTextEllipsisModal()

```
void OH_Drawing_SetTypographyTextEllipsisModal (OH_Drawing_TypographyStyle* , int)
```

**描述**

设置排版样式省略模式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向OH_Drawing_TypographyStyle对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 设置省略号样式，支持可选的省略号样式样式具体可见[OH_Drawing_EllipsisModal](#oh_drawing_ellipsismodal)枚举。 | 


### OH_Drawing_SetTypographyTextFontFamily()

```
void OH_Drawing_SetTypographyTextFontFamily (OH_Drawing_TypographyStyle* , const char*  )
```

**描述**

设置字体家族的名称。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| char | 字体家族的名称，数据类型为指向char的指针。 | 


### OH_Drawing_SetTypographyTextFontHeight()

```
void OH_Drawing_SetTypographyTextFontHeight (OH_Drawing_TypographyStyle* , double  )
```

**描述**

设置文本排版字体高度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| double | 字体高度。 | 


### OH_Drawing_SetTypographyTextFontSize()

```
void OH_Drawing_SetTypographyTextFontSize (OH_Drawing_TypographyStyle* , double  )
```

**描述**

设置文本排版字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| double | 字号（大于0）。 | 


### OH_Drawing_SetTypographyTextFontStyle()

```
void OH_Drawing_SetTypographyTextFontStyle (OH_Drawing_TypographyStyle* , int)
```

**描述**

设置排版样式默认的字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 |
| int | 设置字体样式，设置1为斜体，设置0或其它为非斜体，具体可见[OH_Drawing_FontStyle](#oh_drawing_fontstyle)枚举。 |


### OH_Drawing_SetTypographyTextFontWeight()

```
void OH_Drawing_SetTypographyTextFontWeight (OH_Drawing_TypographyStyle* , int)
```

**描述**

设置排版样式默认字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 设置字重，设置0字重为thin，设置1字重为extra-light，设置2字重为light，设置4字重为medium，设置5字重为semi-bold， 设置6字重为bold，设置7字重为extra-bold，设置8字重为black，设置3或其它字重为normal/regular，具体可见[OH_Drawing_FontWeight](#oh_drawing_fontweight)枚举。 |


### OH_Drawing_SetTypographyTextHalfLeading()

```
void OH_Drawing_SetTypographyTextHalfLeading (OH_Drawing_TypographyStyle* , bool  )
```

**描述**

设置文本排版是否为一半行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| bool | 设置一半行间距是否生效，true表示生效，false表示不生效。 | 


### OH_Drawing_SetTypographyTextLineStyleFontFamilies()

```
void OH_Drawing_SetTypographyTextLineStyleFontFamilies (OH_Drawing_TypographyStyle* , int , const char* fontFamilies[] )
```

**描述**

设置文本排版行样式字体类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 字体名称数量。 | 
| char | 指向字体类型的指针。 | 


### OH_Drawing_SetTypographyTextLineStyleFontHeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontHeight (OH_Drawing_TypographyStyle* , double  )
```

**描述**

设置文本排版行样式字体高度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| double | 字体高度。 | 


### OH_Drawing_SetTypographyTextLineStyleFontSize()

```
void OH_Drawing_SetTypographyTextLineStyleFontSize (OH_Drawing_TypographyStyle* , double  )
```

**描述**

设置文本排版行样式字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| double | 字号（大于0）。 | 


### OH_Drawing_SetTypographyTextLineStyleFontStyle()

```
void OH_Drawing_SetTypographyTextLineStyleFontStyle (OH_Drawing_TypographyStyle* , int  )
```

**描述**

设置文本排版样式中支柱样式的字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 设置字体样式，设置1为斜体，设置0或其它为非斜体，具体可见[OH_Drawing_FontStyle](#oh_drawing_fontstyle)枚举。 | 


### OH_Drawing_SetTypographyTextLineStyleFontWeight()

```
void OH_Drawing_SetTypographyTextLineStyleFontWeight (OH_Drawing_TypographyStyle* , int)
```

**描述**

设置排版样式中支柱样式的文本样式字重。目前只有系统默认字体支持字重的调节，其他字体设置字重值小于semi-bold时字体粗细无变化，当设置字重值大于等于semi-bold时可能会触发伪加粗效果。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 设置字重，设置0字重为thin，设置1字重为extra-light，设置2字重为light，设置4字重为medium，设置5字重为semi-bold， 设置6字重为bold，设置7字重为extra-bold，设置8字重为black，设置3或其它字重为normal/regular，具体可见[OH_Drawing_FontWeight](#oh_drawing_fontweight)枚举。 | 


### OH_Drawing_SetTypographyTextLineStyleHalfLeading()

```
void OH_Drawing_SetTypographyTextLineStyleHalfLeading (OH_Drawing_TypographyStyle* , bool  )
```

**描述**

设置文本排版行样式中支柱样式是否开启一半行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本排版样式对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| bool | 设置一半行间距是否生效，true表示生效，false表示不生效。 | 


### OH_Drawing_SetTypographyTextLineStyleOnly()

```
void OH_Drawing_SetTypographyTextLineStyleOnly (OH_Drawing_TypographyStyle* , bool  )
```

**描述**

设置文本排版是否仅启用行样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| bool | 设置仅启用行样式是否生效，true表示生效，false表示不生效。 | 


### OH_Drawing_SetTypographyTextLineStyleSpacingScale()

```
void OH_Drawing_SetTypographyTextLineStyleSpacingScale (OH_Drawing_TypographyStyle* , double  )
```

**描述**

设置文本排版行样式间距比例。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| double | 间距比例。 | 


### OH_Drawing_SetTypographyTextLocale()

```
void OH_Drawing_SetTypographyTextLocale (OH_Drawing_TypographyStyle* style, const char* locale )
```

**描述**

设置指定排版样式的语言环境。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| char |  语言环境，数据类型为指向char的指针，如'en'代表英文，'zh-Hans'代表简体中文，'zh-Hant'代表繁体中文。 | 


### OH_Drawing_SetTypographyTextMaxLines()

```
void OH_Drawing_SetTypographyTextMaxLines (OH_Drawing_TypographyStyle* , int  )
```

**描述**

设置文本最大行数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 最大行数。 | 

### OH_Drawing_SetTypographyTextSplitRatio()

```
void OH_Drawing_SetTypographyTextSplitRatio (OH_Drawing_TypographyStyle* style, float textSplitRatio )
```

**描述**

设置文本划分比率。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| float | 文本划分比率。 | 


### OH_Drawing_SetTypographyTextStyle()

```
void OH_Drawing_SetTypographyTextStyle (OH_Drawing_TypographyStyle* , OH_Drawing_TextStyle*  )
```

**描述**

设置排版样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 


### OH_Drawing_SetTypographyTextUseLineStyle()

```
void OH_Drawing_SetTypographyTextUseLineStyle (OH_Drawing_TypographyStyle* , bool  )
```

**描述**

设置文本排版是否启用行样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| bool | 设置行样式是否启用，true表示启用，false表示不启用。 | 


### OH_Drawing_SetTypographyTextWordBreakType()

```
void OH_Drawing_SetTypographyTextWordBreakType (OH_Drawing_TypographyStyle* , int  )
```

**描述**

设置单词的断词方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| int | 设置断词方式，支持可选的断词方式样式具体可见[OH_Drawing_WordBreakType](#oh_drawing_wordbreaktype)枚举。 | 


### OH_Drawing_ShaderEffectCreateImageShader()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateImageShader (OH_Drawing_Image* , OH_Drawing_TileMode tileX, OH_Drawing_TileMode tileY, const OH_Drawing_SamplingOptions* , const OH_Drawing_Matrix*  )
```

**描述**

创建图像着色器。此接口不建议用于录制类型的画布，会影响性能。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Image、OH_Drawing_SamplingOptions任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

tileX、tileY任意一个不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Image | 指向图片对象[OH_Drawing_Image](#oh_drawing_image)的指针。 | 
| tileX | 水平方向着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode-1)枚举。 | 
| tileY | 垂直方向着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode-1)枚举。 | 
| OH_Drawing_SamplingOptions | 指向采样选项对象[OH_Drawing_SamplingOptions](#oh_drawing_samplingoptions)的指针。 | 
| OH_Drawing_Matrix | 指向矩阵对象[OH_Drawing_Matrix](#oh_drawing_matrix)的指针。如果矩阵指针为空，默认传入单位矩阵。 | 

**返回：**

返回创建的着色器对象的指针。


### OH_Drawing_ShaderEffectCreateLinearGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateLinearGradient (const OH_Drawing_Point* startPt, const OH_Drawing_Point* endPt, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**描述**

创建着色器，在两个指定点之间生成线性渐变。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

startPt、endPt、colors任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

OH_Drawing_TileMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| startPt | 表示渐变的起点。 | 
| endPt | 表示渐变的终点。 | 
| colors | 表示在两个点之间分布的颜色。 | 
| pos | 表示每种对应颜色在颜色数组中的相对位置，如果pos为NULL，颜色均匀分布在起点和终点之间。 | 
| size | 表示颜色和位置的数量（如果pos不为NULL）。 | 
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode-1)枚举。 | 

**返回：**

返回创建的着色器对象的指针。


### OH_Drawing_ShaderEffectCreateRadialGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateRadialGradient (const OH_Drawing_Point* centerPt, float radius, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**描述**

创建着色器，在给定圆心和半径的情况下生成径向渐变。 从起点到终点颜色从内到外进行圆形渐变（从中间向外拉）被称为径向渐变。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

centerPt、colors任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

OH_Drawing_TileMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| centerPt | 表示渐变的圆心。 | 
| radius | 表示渐变的圆半径，需为非负数。 | 
| colors | 表示在径向上分布的颜色。 | 
| pos | 表示每种对应颜色在颜色数组中的相对位置，如果pos为NULL，颜色均匀分布在径向上。 | 
| size | 表示颜色和位置的数量（如果pos不为NULL）。 | 
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode-1)枚举。 | 

**返回：**

返回创建的着色器对象的指针。


### OH_Drawing_ShaderEffectCreateSweepGradient()

```
OH_Drawing_ShaderEffect* OH_Drawing_ShaderEffectCreateSweepGradient (const OH_Drawing_Point* centerPt, const uint32_t* colors, const float* pos, uint32_t size, OH_Drawing_TileMode  )
```

**描述**

创建着色器，在给定中心的情况下生成扇形渐变。颜色从0°到360°渐变被称为扇形渐变。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

centerPt、colors任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

OH_Drawing_TileMode不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| centerPt | 表示渐变的圆心。 | 
| colors | 表示在两个点之间分布的颜色。 | 
| pos | 表示每种对应颜色在颜色数组中的相对位置，如果pos为NULL，颜色均匀分布在0°和360°之间。 | 
| size | 表示颜色和位置的数量（如果pos不为NULL）。 | 
| OH_Drawing_TileMode | 着色器效果平铺模式类型，支持可选的具体模式可见[OH_Drawing_TileMode](#oh_drawing_tilemode-1)枚举。 | 

**返回：**

返回创建的着色器对象的指针。


### OH_Drawing_ShaderEffectDestroy()

```
void OH_Drawing_ShaderEffectDestroy (OH_Drawing_ShaderEffect* )
```

**描述**

销毁着色器对象，并收回该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_ShaderEffect | 表示指向着色器对象的指针。 | 


### OH_Drawing_SurfaceCreateFromGpuContext()

```
OH_Drawing_Surface* OH_Drawing_SurfaceCreateFromGpuContext (OH_Drawing_GpuContext* , bool budgeted, OH_Drawing_Image_Info  )
```

**描述**

使用图形处理器上下文创建一个surface对象，用于管理画布绘制的内容。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_GpuContext为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_GpuContext | 指向图形处理器上下文对象的指针[OH_Drawing_GpuContext](#oh_drawing_gpucontext)。 | 
| budgeted | 用于控制内存分配是否计入缓存预算，true则计入高速缓存预算，false则不计入高速缓存预算。 | 
| [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | 图片信息[OH_Drawing_Image_Info](_o_h___drawing___image___info.md)结构体。 | 

**返回：**

返回一个指针，指针指向创建的surface对象[OH_Drawing_Surface](#oh_drawing_surface)。


### OH_Drawing_SurfaceDestroy()

```
void OH_Drawing_SurfaceDestroy (OH_Drawing_Surface* )
```

**描述**

销毁surface对象并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Surface | 指向创建的surface对象的指针。 | 


### OH_Drawing_SurfaceGetCanvas()

```
OH_Drawing_Canvas* OH_Drawing_SurfaceGetCanvas (OH_Drawing_Surface* )
```

**描述**

通过surface对象获取画布对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_Surface为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Surface | 指向创建的surface对象的指针。 | 

**返回：**

返回一个指针，指针指向创建的画布对象[OH_Drawing_Canvas](#oh_drawing_canvas)。返回的指针不需要由调用者管理。


### OH_Drawing_TextBlobBuilderAllocRunPos()

```
const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos (OH_Drawing_TextBlobBuilder* , const OH_Drawing_Font* , int32_t count, const OH_Drawing_Rect*  )
```

**描述**

申请一块内存，用于存储文字和位置信息。返回的指针无需调用者管理， 当调用[OH_Drawing_TextBlobBuilderMake](#oh_drawing_textblobbuildermake)后禁止使用。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_TextBlobBuilder、OH_Drawing_Font任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBlobBuilder | 指向文本构造器对象的指针。 | 
| OH_Drawing_Font | 指向字体对象的指针。 | 
| count | 文字的数量。 | 
| OH_Drawing_Rect | 文本的边界框，为NULL表示不设置边界框。 | 


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
void OH_Drawing_TextBlobBuilderDestroy (OH_Drawing_TextBlobBuilder* )
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
OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake (OH_Drawing_TextBlobBuilder* )
```

**描述**

用于从文本构造器中创建文本对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_TextBlobBuilder为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBlobBuilder | 指向文本构造器对象的指针。 | 

**返回：**

返回一个指针，指针指向创建的文本对象。


### OH_Drawing_TextBlobCreateFromPosText()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromPosText (const void * text, size_t byteLength, OH_Drawing_Point2D* , const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**描述**

使用文本创建文本对象，文本对象中每个字符的坐标由OH_Drawing_Point2D数组中对应的坐标信息决定。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

text、OH_Drawing_Point2D、OH_Drawing_Font任意一个为NULL或byteLength等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_TextEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| text | 指向文本的指针。 | 
| byteLength | 文本的字节长度。 | 
| [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | 二维点[OH_Drawing_Point2D](_o_h___drawing___point2_d.md)数组首地址，数组个数由[OH_Drawing_FontCountText](#oh_drawing_fontcounttext)计算结果决定。 | 
| OH_Drawing_Font | 指向字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| OH_Drawing_TextEncoding | 文本编码类型[OH_Drawing_TextEncoding](#oh_drawing_textencoding)。 | 

**返回：**

函数返回一个指针，指针指向创建的文本对象[OH_Drawing_TextBlob](#oh_drawing_textblob)。


### OH_Drawing_TextBlobCreateFromString()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromString (const char* str, const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**描述**

使用字符串创建文本对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

str、OH_Drawing_Font任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_TextEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| str | 指向字符串的指针。 | 
| OH_Drawing_Font | 指向字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| OH_Drawing_TextEncoding | 文本编码类型[OH_Drawing_TextEncoding](#oh_drawing_textencoding)。当前只有TEXT_ENCODING_UTF8生效，其余编码类型也会被视为TEXT_ENCODING_UTF8。 | 

**返回：**

函数返回一个指针，指针指向创建的文本对象[OH_Drawing_TextBlob](#oh_drawing_textblob)。


### OH_Drawing_TextBlobCreateFromText()

```
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromText (const void * text, size_t byteLength, const OH_Drawing_Font* , OH_Drawing_TextEncoding  )
```

**描述**

使用文本创建一个文本对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

text、OH_Drawing_Font任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；

OH_Drawing_TextEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| text | 指向文本的指针。 | 
| byteLength | 文本的字节长度。 | 
| OH_Drawing_Font | 指向字体对象[OH_Drawing_Font](#oh_drawing_font)的指针。 | 
| OH_Drawing_TextEncoding | 文本编码类型[OH_Drawing_TextEncoding](#oh_drawing_textencoding)。 | 

**返回：**

函数返回一个指针，指针指向创建的文本对象[OH_Drawing_TextBlob](#oh_drawing_textblob)。


### OH_Drawing_TextBlobDestroy()

```
void OH_Drawing_TextBlobDestroy (OH_Drawing_TextBlob* )
```

**描述**

用于销毁文本对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBlob | 指向文本对象的指针。 | 


### OH_Drawing_TextBlobGetBounds()

```
void OH_Drawing_TextBlobGetBounds (OH_Drawing_TextBlob* , OH_Drawing_Rect*  )
```

**描述**

获取文本对象的边界范围。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_TextBlob、OH_Drawing_Rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextBlob | 指向文本对象[OH_Drawing_TextBlob](#oh_drawing_textblob)的指针。 | 
| OH_Drawing_Rect | 指向矩形对象[OH_Drawing_Rect](#oh_drawing_rect)的指针， 开发者可调用[OH_Drawing_RectCreate](#oh_drawing_rectcreate)接口创建。 | 


### OH_Drawing_TextStyleAddFontFeature()

```
void OH_Drawing_TextStyleAddFontFeature (OH_Drawing_TextStyle* , const char* tag, int value )
```

**描述**

设置文本样式中指定字体特征是否启用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| char | 指向字体特征键值对中关键字所标识的字符串。 | 
| int | 要设置的字体特征键值对的值。 | 


### OH_Drawing_TextStyleAddFontVariation()

```
void OH_Drawing_TextStyleAddFontVariation (OH_Drawing_TextStyle* , const char* , const float  )
```

**描述**

添加可变字体属性。对应的字体文件（.ttf文件）需要支持可变调节，此接口才能生效。当对应的字体不支持可变调节时，此接口调用不生效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 |
| char\* | 可变字体属性键值对中的键。目前仅支持'wght'，表示字重属性。 |
| float | 设置的可变字体属性键值对的值。目前默认字体下字重属性支持的取值范围为[0,900]。 |


### OH_Drawing_TextStyleAddShadow()

```
void OH_Drawing_TextStyleAddShadow (OH_Drawing_TextStyle* , const OH_Drawing_TextShadow*  )
```

**描述**

字体阴影容器中添加字体阴影元素。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_TextShadow | 指向字体阴影对象[OH_Drawing_TextShadow](#oh_drawing_textshadow)的指针，由[OH_Drawing_CreateTextShadow](#oh_drawing_createtextshadow)获取。 | 


### OH_Drawing_TextStyleClearFontFeature()

```
void OH_Drawing_TextStyleClearFontFeature (OH_Drawing_TextStyle* )
```

**描述**

清除指定文本样式的字体特征map容器中所有内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 


### OH_Drawing_TextStyleClearShadows()

```
void OH_Drawing_TextStyleClearShadows (OH_Drawing_TextStyle* )
```

**描述**

清除字体阴影容器中的所有元素。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 |


### OH_Drawing_TextStyleDestroyFontFamilies()

```
void OH_Drawing_TextStyleDestroyFontFamilies (char** fontFamilies, size_t num)
```

**描述**

释放长度为num的字体家族名称列表占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fontFamilies | 指向字体家族名称列表的指针。 |
| num | 字体家族名称列表的长度。 |


### OH_Drawing_TextStyleDestroyFontFeatures()

```
void OH_Drawing_TextStyleDestroyFontFeatures (OH_Drawing_FontFeature* , size_t fontFeatureSize )
```

**描述**

释放存放字体特征所有内容的结构体数组所占用的空间。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) | 指向存放容器所有键值对的结构体数组指针，由[OH_Drawing_TextStyleGetFontFeatures](#oh_drawing_textstylegetfontfeatures)获取。 | 
| fontFeatureSize | 存放容器所有键值对的结构体数组的大小。 | 


### OH_Drawing_TextStyleGetBackgroundBrush()

```
void OH_Drawing_TextStyleGetBackgroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**描述**

返回设置的背景色画刷。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Brush | 指向画刷[OH_Drawing_Brush](#oh_drawing_brush)对象的指针，由[OH_Drawing_BrushCreate](#oh_drawing_brushcreate)获取。 | 


### OH_Drawing_TextStyleGetBackgroundPen()

```
void OH_Drawing_TextStyleGetBackgroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**描述**

返回设置的背景色画笔。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Pen | 指向画笔[OH_Drawing_Pen](#oh_drawing_pen)对象的指针，由[OH_Drawing_PenCreate](#oh_drawing_pencreate)获取。 | 


### OH_Drawing_TextStyleGetBaseline()

```
OH_Drawing_TextBaseline OH_Drawing_TextStyleGetBaseline (OH_Drawing_TextStyle* )
```

**描述**

获取指定文本样式的字体基线位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

返回字体基线位置，具体可见[OH_Drawing_TextBaseline](#oh_drawing_textbaseline)枚举。


### OH_Drawing_TextStyleGetBaselineShift()

```
double OH_Drawing_TextStyleGetBaselineShift (OH_Drawing_TextStyle*)
```

**描述**

获取指定文本样式的基线偏移。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 |

**返回：**

double 基线偏移的值。


### OH_Drawing_TextStyleGetColor()

```
uint32_t OH_Drawing_TextStyleGetColor (OH_Drawing_TextStyle* )
```

**描述**

获取文本颜色。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

uint32_t 返回文本颜色。


### OH_Drawing_TextStyleGetDecorationStyle()

```
OH_Drawing_TextDecorationStyle OH_Drawing_TextStyleGetDecorationStyle (OH_Drawing_TextStyle* )
```

**描述**

获取文本装饰样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

返回文本装饰样式，具体可见[OH_Drawing_TextDecorationStyle](#oh_drawing_textdecorationstyle)枚举。


### OH_Drawing_TextStyleGetFontFamilies()

```
char** OH_Drawing_TextStyleGetFontFamilies (OH_Drawing_TextStyle* , size_t* num )
```

**描述**

获取字体类型名称列表。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| num | 指向字体名称数量的指针。 | 

**返回：**

返回获取到的字体类型列表。


### OH_Drawing_TextStyleGetFontFeatures()

```
OH_Drawing_FontFeature* OH_Drawing_TextStyleGetFontFeatures (OH_Drawing_TextStyle* )
```

**描述**

获取指定文本样式的字体特征map容器中所有内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

[OH_Drawing_FontFeature](_o_h___drawing___font_feature.md) 要获取的字体特征容器的所有内容，指向存放容器所有键值对的一个结构体数组。


### OH_Drawing_TextStyleGetFontFeatureSize()

```
size_t OH_Drawing_TextStyleGetFontFeatureSize (OH_Drawing_TextStyle* )
```

**描述**

获取指定文本样式中字体特征map容器的大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

size_t 字体特征map容器的大小。


### OH_Drawing_TextStyleGetFontHeight()

```
double OH_Drawing_TextStyleGetFontHeight (OH_Drawing_TextStyle* )
```

**描述**

获取指定文本样式行高缩放系数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向字体样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

double 返回字体高度。


### OH_Drawing_TextStyleGetFontMetrics()

```
bool OH_Drawing_TextStyleGetFontMetrics (OH_Drawing_Typography* , OH_Drawing_TextStyle* , OH_Drawing_Font_Metrics*  )
```

**描述**

获取文本字体属性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向文本对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Font_Metrics | 指向字体属性对象[OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)的指针，由[OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)获取。 | 

**返回：**

是否获取到字体属性，true表示获取到字体属性，false表示未获取到字体属性。


### OH_Drawing_TextStyleGetFontSize()

```
double OH_Drawing_TextStyleGetFontSize (OH_Drawing_TextStyle*)
```

**描述**

获取指定文本样式字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

double 返回字号。


### OH_Drawing_TextStyleGetFontStyle()

```
OH_Drawing_FontStyle OH_Drawing_TextStyleGetFontStyle (OH_Drawing_TextStyle* )
```

**描述**

获取指定文本样式的字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向字体样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

返回字体样式，具体可见[OH_Drawing_FontStyle](#oh_drawing_fontstyle)枚举。


### OH_Drawing_TextStyleGetFontStyleStruct()

```
OH_Drawing_FontStyleStruct OH_Drawing_TextStyleGetFontStyleStruct (OH_Drawing_TextStyle* drawingTextStyle)
```

**描述**

获取文本样式中的字体样式，包括字体字重、字体宽度和字体斜度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

返回获取到的字体样式对象，包括字体字重、字体宽度和字体斜度信息。


### OH_Drawing_TextStyleGetFontWeight()

```
OH_Drawing_FontWeight OH_Drawing_TextStyleGetFontWeight (OH_Drawing_TextStyle*)
```

**描述**

获取指定文本样式字重。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

返回字重，具体可见[OH_Drawing_FontWeight](#oh_drawing_fontweight)枚举。


### OH_Drawing_TextStyleGetForegroundBrush()

```
void OH_Drawing_TextStyleGetForegroundBrush (OH_Drawing_TextStyle* , OH_Drawing_Brush*  )
```

**描述**

返回设置的前景色画刷。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Brush | 指向画刷[OH_Drawing_Brush](#oh_drawing_brush)对象的指针，由[OH_Drawing_BrushCreate](#oh_drawing_brushcreate)获取。 | 


### OH_Drawing_TextStyleGetForegroundPen()

```
void OH_Drawing_TextStyleGetForegroundPen (OH_Drawing_TextStyle* , OH_Drawing_Pen*  )
```

**描述**

返回设置的前景色画笔。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| OH_Drawing_Pen | 指向画笔[OH_Drawing_Pen](#oh_drawing_pen)对象的指针，由[OH_Drawing_PenCreate](#oh_drawing_pencreate)获取。 | 


### OH_Drawing_TextStyleGetHalfLeading()

```
bool OH_Drawing_TextStyleGetHalfLeading (OH_Drawing_TextStyle*)
```

**描述**

获取指定文本样式一半行间距开关状态。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

bool 返回当前文本样式一半行间距的开关状态，true表示开启一半行间距，false表示未开启一半行间距。


### OH_Drawing_TextStyleGetLetterSpacing()

```
double OH_Drawing_TextStyleGetLetterSpacing (OH_Drawing_TextStyle*)
```

**描述**

获取指定文本样式的字符间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

double 返回字符间距大小。


### OH_Drawing_TextStyleGetLocale()

```
const char* OH_Drawing_TextStyleGetLocale (OH_Drawing_TextStyle*)
```

**描述**

获取语言环境。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

char 返回语言环境，数据类型为指向char的指针。语言环境格式为：语言-国家。如zh-CN表示中文（中国），en-US表示英语（美国）等。具体参考BCP 47语言标签标准。


### OH_Drawing_TextStyleGetShadowCount()

```
int OH_Drawing_TextStyleGetShadowCount (OH_Drawing_TextStyle* )
```

**描述**

获取字体阴影容器的大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

int 返回字体阴影容器的大小。


### OH_Drawing_TextStyleGetShadows()

```
OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadows (OH_Drawing_TextStyle* )
```

**描述**

获取字体阴影容器。不再需要[OH_Drawing_TextShadow](#oh_drawing_textshadow)时，请使用[OH_Drawing_DestroyTextShadows](#oh_drawing_destroytextshadows)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

返回指向字体阴影容器[OH_Drawing_TextShadow](#oh_drawing_textshadow)的指针。


### OH_Drawing_TextStyleGetShadowWithIndex()

```
OH_Drawing_TextShadow* OH_Drawing_TextStyleGetShadowWithIndex (OH_Drawing_TextStyle* , int  )
```

**描述**

根据下标获取字体阴影容器中的元素。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| int | 下标索引。 | 

**返回：**

返回指向字体阴影对象[OH_Drawing_TextShadow](#oh_drawing_textshadow)的指针。


### OH_Drawing_TextStyleGetWordSpacing()

```
double OH_Drawing_TextStyleGetWordSpacing (OH_Drawing_TextStyle*)
```

**描述**

获取指定文本样式的单词间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

double 返回单词间距大小。


### OH_Drawing_TextStyleIsAttributeMatched()

```
bool OH_Drawing_TextStyleIsAttributeMatched (const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle, OH_Drawing_TextStyleType textStyleType )
```

**描述**

判断两个文本样式对象是否有一样的文本样式类型。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| style | 比较的文本样式对象。 | 
| comparedStyle | 比较的文本样式对象。 | 
| textStyleType | 文本样式类型枚举[OH_Drawing_TextStyleType](#oh_drawing_textstyletype)。 | 

**返回：**

返回两个TextStyle对象是否有对应的文本样式类型一样的结果，true表示其文本样式类型一样，false表示不一样。


### OH_Drawing_TextStyleIsEqual()

```
bool OH_Drawing_TextStyleIsEqual (const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle )
```

**描述**

判断两个文本样式对象是否相等，字宽属性不参与对比。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| style | 比较的文本样式对象。 | 
| comparedStyle | 比较的文本样式对象。 | 

**返回：**

返回两个文本样式对象是否相等，true表示相等，false表示不相等。


### OH_Drawing_TextStyleIsEqualByFont()

```
bool OH_Drawing_TextStyleIsEqualByFont (const OH_Drawing_TextStyle* style, const OH_Drawing_TextStyle* comparedStyle )
```

**描述**

判断两个文本样式对象的字体样式属性是否相等。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| style | 比较的文本样式对象。 | 
| comparedStyle | 比较的文本样式对象。 | 

**返回：**

返回两个文本样式对象的字体样式属性是否相等的结果。


### OH_Drawing_TextStyleIsPlaceholder()

```
bool OH_Drawing_TextStyleIsPlaceholder (OH_Drawing_TextStyle* style)
```

**描述**

返回是否有设置文本占位符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 

**返回：**

返回是否有设置文本占位符，true表示有设置文本占位符，false表示未设置文本占位符。


### OH_Drawing_TextStyleSetBackgroundRect()

```
void OH_Drawing_TextStyleSetBackgroundRect (OH_Drawing_TextStyle* , const OH_Drawing_RectStyle_Info* , int styleId )
```

**描述**

设置文本背景矩形框和样式id。样式id仅当背景框为圆角矩形时有效。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 
| [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) | 指向[OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md)对象的指针。 | 
| int | 要设置的样式id，仅当背景框为圆角矩形时有效。文本处理时会被划分为多个分段，每个分段都有自己的TextStyle，id标识着这个分段将被绘制于第几个背景矩形框中。 若一行中每个分段的id全为0，表示所有分段绘制在同一个圆角矩形背景框中； 若一行中的id为0, 1，则id为0的分段绘制在一个圆角矩形背景框内，id为1的分段绘制在另一个圆角矩形背景框内，以此类推。 | 


### OH_Drawing_TextStyleSetBaselineShift()

```
void OH_Drawing_TextStyleSetBaselineShift (OH_Drawing_TextStyle*, double lineShift)
```

**描述**

设置文本样式基线偏移。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| OH_Drawing_TextStyle | 指向OH_Drawing_TextStyle对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 |
| double | 文本的基线偏移。 |


### OH_Drawing_TextStyleSetPlaceholder()

```
void OH_Drawing_TextStyleSetPlaceholder (OH_Drawing_TextStyle* style)
```

**描述**

设置占位符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TextStyle | 指向文本样式对象[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 


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


### OH_Drawing_TypefaceCreateFromFile()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromFile (const char* path, int index )
```

**描述**

通过文件创建一个字形对象。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

path为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| path | 指向文件路径的指针。 | 
| index | 文件索引。 | 

**返回：**

函数返回一个指针，指针指向创建的字形对象[OH_Drawing_Typeface](#oh_drawing_typeface)。


### OH_Drawing_TypefaceCreateFromStream()

```
OH_Drawing_Typeface* OH_Drawing_TypefaceCreateFromStream (OH_Drawing_MemoryStream* , int32_t index )
```

**描述**

通过内存流创建一个字形对象。如果内存流是无效的字体文件，返回空指针。 内存流传入后，所有权转移，开发者不能再释放它。

本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](#oh_drawing_errorcodeget)查看错误码[OH_Drawing_ErrorCode](#oh_drawing_errorcode)的取值。

OH_Drawing_MemoryStream为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_MemoryStream | 指向内存流对象[OH_Drawing_MemoryStream](#oh_drawing_memorystream)的指针。 | 
| index | 内存流索引。 | 

**返回：**

返回一个指针，指针指向创建的字形对象[OH_Drawing_Typeface](#oh_drawing_typeface)。


### OH_Drawing_TypefaceDestroy()

```
void OH_Drawing_TypefaceDestroy (OH_Drawing_Typeface* )
```

**描述**

用于销毁字形对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typeface | 指向字形对象的指针。 | 


### OH_Drawing_TypographyDestroyEllipsis()

```
void OH_Drawing_TypographyDestroyEllipsis (char* ellipsis)
```

**描述**

释放省略号名称列表占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ellipsis | 表示指向省略号名称列表的指针。 | 


### OH_Drawing_TypographyDestroyLineFontMetrics()

```
void OH_Drawing_TypographyDestroyLineFontMetrics (OH_Drawing_Font_Metrics* )
```

**描述**

释放指定行所有字体度量结构体集合所占用的所有空间。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | 指示要释放空间的指定行所有字体度量结构体集合的第一个地址。 | 


### OH_Drawing_TypographyDidExceedMaxLines()

```
bool OH_Drawing_TypographyDidExceedMaxLines (OH_Drawing_Typography* )
```

**描述**

获取排版对象中文本是否超过最大行，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用，如果没有通过[OH_Drawing_SetTypographyTextMaxLines](#oh_drawing_settypographytextmaxlines)接口设置最大行，则返回false。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回文本是否超过最大行，true表示超过，false表示未超过。


### OH_Drawing_TypographyGetAlphabeticBaseline()

```
double OH_Drawing_TypographyGetAlphabeticBaseline (OH_Drawing_Typography* )
```

**描述**

获取排版样式字母文字基线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回字母文字基线。


### OH_Drawing_TypographyGetEffectiveAlignment()

```
int OH_Drawing_TypographyGetEffectiveAlignment (OH_Drawing_TypographyStyle* style)
```

**描述**

获取文字对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文字对齐方式。


### OH_Drawing_TypographyGetGlyphPositionAtCoordinate()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinate (OH_Drawing_Typography* , double , double  )
```

**描述**

获取坐标处文本的索引位置和亲和性。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| double | 光标的x坐标。 | 
| double | 光标的y坐标。 | 

**返回：**

返回坐标处字体的索引位置和亲和性，返回类型为[OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity)结构体。


### OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster()

```
OH_Drawing_PositionAndAffinity* OH_Drawing_TypographyGetGlyphPositionAtCoordinateWithCluster (OH_Drawing_Typography* , double , double  )
```

**描述**

获取坐标处文本所属字符簇的索引位置和亲和性，字符簇指一个或多个字符组成的整体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| double | 光标的x坐标。 | 
| double | 光标的y坐标。 | 

**返回：**

返回坐标处指定类型字体的索引位置和亲和性，返回类型为[OH_Drawing_PositionAndAffinity](#oh_drawing_positionandaffinity)结构体。


### OH_Drawing_TypographyGetHeight()

```
double OH_Drawing_TypographyGetHeight (OH_Drawing_Typography* )
```

**描述**

获取排版对象整体的高度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回高度。


### OH_Drawing_TypographyGetIdeographicBaseline()

```
double OH_Drawing_TypographyGetIdeographicBaseline (OH_Drawing_Typography* )
```

**描述**

获取排版样式表意文字基线。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回表意文字基线。


### OH_Drawing_TypographyGetIndentsWithIndex()

```
float OH_Drawing_TypographyGetIndentsWithIndex (OH_Drawing_Typography* , int  )
```

**描述**

根据行索引获取排版对象缩进容器中的元素，行索引从0开始。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向文本对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| int | 下标索引。 | 

**返回：**

float 返回索引对应的元素值。


### OH_Drawing_TypographyGetLineCount()

```
size_t OH_Drawing_TypographyGetLineCount (OH_Drawing_Typography* )
```

**描述**

获取排版对象中文本行数，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回行数。


### OH_Drawing_TypographyGetLineFontMetrics()

```
OH_Drawing_Font_Metrics* OH_Drawing_TypographyGetLineFontMetrics (OH_Drawing_Typography* , size_t lineNumber, size_t* fontMetricsSize )
```

**描述**

从排版对象中目标行获取所有字体度量信息，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用，否则会返回空指针。不再需要[OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)时，请使用[OH_Drawing_TypographyDestroyLineFontMetrics](#oh_drawing_typographydestroylinefontmetrics)接口释放该对象的指针。 

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向文本对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| lineNumber | 指定行数，取值为整数，最小有效值为1，最大行取决于文本输入后字体引擎解析出来的行数，若输入值大于最大行会返回错误值并打印错误消息。 | 
| fontMetricsSize | 指示从当前行返回的字体度量结构的大小。 | 

**返回：**

返回当前行的所有字体度量信息。


### OH_Drawing_TypographyGetLineHeight()

```
double OH_Drawing_TypographyGetLineHeight (OH_Drawing_Typography* , int  )
```

**描述**

获取排版对象中指定行的行高，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| int | 要指定的行数。 | 

**返回：**

返回指定行的行高。


### OH_Drawing_TypographyGetLineInfo()

```
bool OH_Drawing_TypographyGetLineInfo (OH_Drawing_Typography* , int , bool , bool , OH_Drawing_LineMetrics*  )
```

**描述**

获取排版对象中指定行的位置信息或指定行第一个字符的位置信息，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向文本对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| int | 行号。 | 
| bool | true为获取整行的位置信息，false为获取第一个字符的位置信息。 | 
| bool | 文字宽度是否包含空白符，true表示不包含空白符，false表示包含空白符。 | 
| OH_Drawing_LineMetrics | 指向行位置信息对象[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)的指针，由[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)获取。 | 

**返回：**

指定行的行位置信息或第一个字符的位置信息是否成功获取，true表示成功获取，false表示未成功获取。


### OH_Drawing_TypographyGetLineMetrics()

```
OH_Drawing_LineMetrics* OH_Drawing_TypographyGetLineMetrics (OH_Drawing_Typography* )
```

**描述**

获取排版对象的行位置信息，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)时，请使用[OH_Drawing_DestroyLineMetrics](#oh_drawing_destroylinemetrics)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向文本对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回指向行位置信息对象[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)的指针。


### OH_Drawing_TypographyGetLineMetricsAt()

```
bool OH_Drawing_TypographyGetLineMetricsAt (OH_Drawing_Typography* , int , OH_Drawing_LineMetrics*  )
```

**描述**

获取排版对象的指定行位置信息，具体参见[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)结构体，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向文本对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| int | 要获取的行数。 | 
| [OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md) | 指向行位置信息对象[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)的指针，由[OH_Drawing_LineMetrics](_o_h___drawing___line_metrics.md)获取。 | 

**返回：**

行位置信息对象是否成功获取，true表示成功获取，false表示未成功获取。


### OH_Drawing_TypographyGetLineTextRange()

```
OH_Drawing_Range* OH_Drawing_TypographyGetLineTextRange (OH_Drawing_Typography* , int , bool  )
```

**描述**

获取排版对象中行的边界，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。该接口只能获取已有行的边界，即输入行索引从0开始，最大行索引为[OH_Drawing_TypographyGetLineCount](#oh_drawing_typographygetlinecount) - 1。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向文本对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| int | 行索引。 | 
| bool | 设置返回的边界是否包含空格，true为包含空格，false为不包含空格。 | 

**返回：**

返回指向行边界对象的指针[OH_Drawing_Range](#oh_drawing_range)。


### OH_Drawing_TypographyGetLineWidth()

```
double OH_Drawing_TypographyGetLineWidth (OH_Drawing_Typography* , int  )
```

**描述**

获取指定行的行宽，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| int | 要指定的行数。 | 

**返回：**

返回指定行的行宽。


### OH_Drawing_TypographyGetLongestLine()

```
double OH_Drawing_TypographyGetLongestLine (OH_Drawing_Typography* )
```

**描述**

获取排版对象最长行的宽度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用，建议实际使用时将返回值向上取整。当文本内容为空时，返回0.0。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回最长行的宽度。


### OH_Drawing_TypographyGetMaxIntrinsicWidth()

```
double OH_Drawing_TypographyGetMaxIntrinsicWidth (OH_Drawing_Typography* )
```

**描述**

获取排版对象的最大固有宽度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回最大固有宽度。


### OH_Drawing_TypographyGetMaxWidth()

```
double OH_Drawing_TypographyGetMaxWidth (OH_Drawing_Typography* )
```

**描述**

获取用户设置的排版宽度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回用户设置的排版宽度。


### OH_Drawing_TypographyGetMinIntrinsicWidth()

```
double OH_Drawing_TypographyGetMinIntrinsicWidth (OH_Drawing_Typography* )
```

**描述**

获取排版对象的最小固有宽度，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回最小固有宽度。


### OH_Drawing_TypographyGetRectsForPlaceholders()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForPlaceholders (OH_Drawing_Typography* )
```

**描述**

获取排版对象中占位符的文本框，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](#oh_drawing_textbox)时，请使用[OH_Drawing_TypographyDestroyTextBox](#oh_drawing_typographydestroytextbox)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回占位符的文本框，返回类型为[OH_Drawing_TextBox](#oh_drawing_textbox)结构体。

### OH_Drawing_TypographyGetRectsForRange()

```
OH_Drawing_TextBox* OH_Drawing_TypographyGetRectsForRange (OH_Drawing_Typography* , size_t , size_t , OH_Drawing_RectHeightStyle , OH_Drawing_RectWidthStyle  )
```

**描述**

获取排版对象中指定范围内的文本框，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用之后调用。不再需要[OH_Drawing_TextBox](#oh_drawing_textbox)时，请使用[OH_Drawing_TypographyDestroyTextBox](#oh_drawing_typographydestroytextbox)接口释放该对象的指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| size_t | 设置开始位置。 | 
| size_t | 设置结束位置。 | 
| OH_Drawing_RectHeightStyle | 设置高度样式，支持可选的高度样式具体可见[OH_Drawing_RectHeightStyle](#oh_drawing_rectheightstyle)枚举。 | 
| OH_Drawing_RectWidthStyle | 设置宽度样式，支持可选的宽度样式具体可见[OH_Drawing_RectWidthStyle](#oh_drawing_rectwidthstyle)枚举。 | 

**返回：**

返回指定范围内的文本框，具体可见[OH_Drawing_TextBox](#oh_drawing_textbox)结构体。


### OH_Drawing_TypographyGetTextAlign()

```
OH_Drawing_TextAlign OH_Drawing_TypographyGetTextAlign (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本对齐方式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本对齐方式。1为右对齐，2为居中对齐，3为两端对齐，4为与文字方向相同，5为文字方向相反，0或其它为左对齐, 具体可见[OH_Drawing_TextAlign](#oh_drawing_textalign)枚举。


### OH_Drawing_TypographyGetTextDirection()

```
OH_Drawing_TextDirection OH_Drawing_TypographyGetTextDirection (OH_Drawing_TypographyStyle* )
```

**描述**

获取指定排版样式中的文本方向。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本方向。0为从右到左，1为从左到右，具体可见[OH_Drawing_TextDirection](#oh_drawing_textdirection)枚举。


### OH_Drawing_TypographyGetTextEllipsis()

```
char* OH_Drawing_TypographyGetTextEllipsis (OH_Drawing_TypographyStyle* )
```

**描述**

获取指定排版样式设置的省略号文本。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回设置的省略号内容。


### OH_Drawing_TypographyGetTextMaxLines()

```
size_t OH_Drawing_TypographyGetTextMaxLines (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本的最大行数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回结果为文本最大行数。


### OH_Drawing_TypographyGetTextStyle()

```
OH_Drawing_TextStyle* OH_Drawing_TypographyGetTextStyle (OH_Drawing_TypographyStyle* style)
```

**描述**

获取指定排版样式中设置的默认文本样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)的指针，不再需要时，请使用[OH_Drawing_DestroyTextStyle](#oh_drawing_destroytextstyle)释放该对象指针。


### OH_Drawing_TypographyGetUnresolvedGlyphsCount()

```
int32_t OH_Drawing_TypographyGetUnresolvedGlyphsCount (OH_Drawing_Typography* )
```

**描述**

获取文本中尚未解析的字形的数量，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用并生效之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 表示指向文本[OH_Drawing_Typography](#oh_drawing_typography)对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 

**返回：**

返回文本中尚未解析的字形的数量。


### OH_Drawing_TypographyGetWordBoundary()

```
OH_Drawing_Range* OH_Drawing_TypographyGetWordBoundary (OH_Drawing_Typography* , size_t  )
```

**描述**

获取排版对象中单词的边界。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| size_t | 单词索引。 | 

**返回：**

返回单词边界，返回类型为[OH_Drawing_Range](#oh_drawing_range)结构体。


### OH_Drawing_TypographyHandlerAddPlaceholder()

```
void OH_Drawing_TypographyHandlerAddPlaceholder (OH_Drawing_TypographyCreate* , OH_Drawing_PlaceholderSpan*  )
```

**描述**

设置占位符。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象的指针，由[OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler)获取。 | 
| OH_Drawing_PlaceholderSpan | 指向[OH_Drawing_PlaceholderSpan](_o_h___drawing___placeholder_span.md)对象的指针。 | 


### OH_Drawing_TypographyHandlerAddSymbol()

```
void OH_Drawing_TypographyHandlerAddSymbol (OH_Drawing_TypographyCreate* , uint32_t symbol )
```

**描述**

设置排版创建过程中的符号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象的指针，由[OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler)获取。 | 
| uint32_t | 要设置的符号，可支持设置的符号参见下面链接json文件中的value值。 [https://gitee.com/openharmony/global_system_resources/blob/master/systemres/main/resources/base/element/symbol.json](https://gitee.com/openharmony/global_system_resources/blob/master/systemres/main/resources/base/element/symbol.json) | 


### OH_Drawing_TypographyHandlerAddText()

```
void OH_Drawing_TypographyHandlerAddText (OH_Drawing_TypographyCreate* , const char*  )
```

**描述**

设置文本内容。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象的指针，由[OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler)获取。 | 
| char | 指向文本内容的指针。 | 


### OH_Drawing_TypographyHandlerPopTextStyle()

```
void OH_Drawing_TypographyHandlerPopTextStyle (OH_Drawing_TypographyCreate* )
```

**描述**

排版弹出。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象的指针，由[OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler)获取。 | 


### OH_Drawing_TypographyHandlerPushTextStyle()

```
void OH_Drawing_TypographyHandlerPushTextStyle (OH_Drawing_TypographyCreate* , OH_Drawing_TextStyle*  )
```

**描述**

设置排版风格。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyCreate | 指向[OH_Drawing_TypographyCreate](#oh_drawing_typographycreate)对象的指针，由[OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler)获取。 | 
| OH_Drawing_TextStyle | 指向文本样式[OH_Drawing_TextStyle](#oh_drawing_textstyle)对象的指针，由[OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle)获取。 | 


### OH_Drawing_TypographyIsEllipsized()

```
bool OH_Drawing_TypographyIsEllipsized (OH_Drawing_TypographyStyle* style)
```

**描述**

获取指定排版样式是否配置省略号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本是否有省略号，true表示有省略号，false表示无省略号。


### OH_Drawing_TypographyIsLineUnlimited()

```
bool OH_Drawing_TypographyIsLineUnlimited (OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本是否有最大行数限制。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本是否有最大行数限制，true表示有最大行数限制，false表示无最大行数限制。


### OH_Drawing_TypographyLayout()

```
void OH_Drawing_TypographyLayout (OH_Drawing_Typography* , double  )
```

**描述**

排版布局。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向排版对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| double | 文本最大宽度。 | 


### OH_Drawing_TypographyMarkDirty()

```
void OH_Drawing_TypographyMarkDirty (OH_Drawing_Typography* )
```

**描述**

将排版标记为脏数据，用于初始化排版状态。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 表示指向文本[OH_Drawing_Typography](#oh_drawing_typography)对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 


### OH_Drawing_TypographyPaint()

```
void OH_Drawing_TypographyPaint (OH_Drawing_Typography* , OH_Drawing_Canvas* , double , double  )
```

**描述**

在指定位置绘制文本，从左上角开始绘制，该接口需要在[OH_Drawing_TypographyLayout](#oh_drawing_typographylayout)接口调用并生效之后调用。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向OH_Drawing_Typography对象的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| OH_Drawing_Canvas | 指向OH_Drawing_Canvas对象的指针，由OH_Drawing_CanvasCreate()获取。 | 
| double | x坐标。 | 
| double | y坐标。 | 


### OH_Drawing_TypographySetIndents()

```
void OH_Drawing_TypographySetIndents (OH_Drawing_Typography* , int , const float indents[] )
```

**描述**

设置文本的排版缩进，不调用此接口默认文本无缩进。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 指向文本对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| int | 为段落设置的缩进数量。该值应小于或等于 indents 数组的长度，以避免访问数组越界导致的显示异常。| 
| float | 指向浮点类型数组的指针，每个数组元素表示一个缩进宽度，单位为物理像素（px）。在应用[OH_Drawing_Typography](#oh_drawing_typography)接口时，需要先声明并初始化该浮点数组。 | 


### OH_Drawing_TypographyStyleDestroyStrutStyle()

```
void OH_Drawing_TypographyStyleDestroyStrutStyle (OH_Drawing_StrutStyle* )
```

**描述**

释放被支柱样式对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md) | 指向支柱样式对象[OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md)的指针，由[OH_Drawing_TypographyStyleGetStrutStyle](#oh_drawing_typographystylegetstrutstyle)获取。 | 


### OH_Drawing_TypographyStyleEquals()

```
bool OH_Drawing_TypographyStyleEquals (OH_Drawing_TypographyStyle* from, OH_Drawing_TypographyStyle* to )
```

**描述**

判断排版样式是否相同，当前文本高度修饰符模式[OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior)没有被纳入比较。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| from | 被比较的排版样式。 | 
| to | 用于比较的排版样式。 | 

**返回：**

返回排版样式是否相同。true表示相同，false表示不相同。


### OH_Drawing_TypographyStyleGetEffectiveAlignment()

```
OH_Drawing_TextAlign OH_Drawing_TypographyStyleGetEffectiveAlignment (OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本对齐模式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本对齐模式的枚举值[OH_Drawing_TextAlign](#oh_drawing_textalign)。


### OH_Drawing_TypographyStyleGetFontStyleStruct()

```
OH_Drawing_FontStyleStruct OH_Drawing_TypographyStyleGetFontStyleStruct (OH_Drawing_TypographyStyle* drawingStyle)
```

**描述**

获取排版样式中默认文本样式的字体样式，包括字体字重、字体宽度和字体斜度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回获取到的字体样式对象，包括字体字重、字体宽度和字体斜度信息。


### OH_Drawing_TypographyStyleGetStrutStyle()

```
OH_Drawing_StrutStyle* OH_Drawing_TypographyStyleGetStrutStyle (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本支柱样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回指向支柱样式对象[OH_Drawing_StrutStyle](_o_h___drawing___strut_style.md)的指针。


### OH_Drawing_TypographyStyleIsHintEnabled()

```
bool OH_Drawing_TypographyStyleIsHintEnabled (OH_Drawing_TypographyStyle* style)
```

**描述**

获取文本是否启用字形轮廓自动调整，字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本是否启用字体提示，true表示启用，false表示不启用。


### OH_Drawing_TypographyStyleSetHintsEnabled()

```
void OH_Drawing_TypographyStyleSetHintsEnabled (OH_Drawing_TypographyStyle* style, bool hintsEnabled )
```

**描述**

设置文本是否启用字形轮廓自动调整，字形轮廓自动调整用于在渲染小字号文本时改善其可读性和外观。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向文本风格对象[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| hintsEnabled | 是否启用字体提示，true表示启用，false表示不启用。 | 


### OH_Drawing_TypographyStyleStrutStyleEquals()

```
bool OH_Drawing_TypographyStyleStrutStyleEquals (OH_Drawing_StrutStyle* from, OH_Drawing_StrutStyle* to )
```

**描述**

判断支柱样式结构体是否相同。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| from | 被比较的支柱样式结构体。 | 
| to | 用于比较的支柱样式结构体。 | 

**返回：**

返回支柱样式结构体是否相同，true表示相同，false表示不相同。

### OH_Drawing_TypographyTextGetHeightBehavior()

```
OH_Drawing_TextHeightBehavior OH_Drawing_TypographyTextGetHeightBehavior (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本高度修饰符模式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本高度修饰符模式，为[OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior)类型的枚举值。


### OH_Drawing_TypographyTextGetLineStyle()

```
bool OH_Drawing_TypographyTextGetLineStyle (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本排版是否启用行样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回行样式是否启用的结果，true表示启用，false表示不启用。


### OH_Drawing_TypographyTextlineGetStyleOnly()

```
bool OH_Drawing_TypographyTextlineGetStyleOnly (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本排版是否仅启用行样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本排版是否仅启用行样式，true表示启用，false表示不启用。


### OH_Drawing_TypographyTextlineStyleDestroyFontFamilies()

```
void OH_Drawing_TypographyTextlineStyleDestroyFontFamilies (char** fontFamilies, size_t fontFamiliesNum )
```

**描述**

释放字体类型占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fontFamilies | 表示指向字体字体类型的指针。 | 
| fontFamiliesNum | 字体名称的数量。 | 


### OH_Drawing_TypographyTextlineStyleGetFontFamilies()

```
char** OH_Drawing_TypographyTextlineStyleGetFontFamilies (OH_Drawing_TypographyStyle* , size_t* num)
```

**描述**

获取文本排版行样式字体家族名。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| num | 指向字体名称数量的指针。 |

**返回：**

返回文本排版行样式字体家族名。


### OH_Drawing_TypographyTextlineStyleGetFontSize()

```
double OH_Drawing_TypographyTextlineStyleGetFontSize (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本排版行样式字号。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本排版行样式字号。


### OH_Drawing_TypographyTextlineStyleGetFontStyle()

```
OH_Drawing_FontStyle OH_Drawing_TypographyTextlineStyleGetFontStyle (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本排版样式中支柱样式的字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

获取文本排版样式中支柱样式的字体样式。1为斜体，0或其它为非斜体，具体可见[OH_Drawing_FontStyle](#oh_drawing_fontstyle)枚举。


### OH_Drawing_TypographyTextlineStyleGetFontWeight()

```
OH_Drawing_FontWeight OH_Drawing_TypographyTextlineStyleGetFontWeight (OH_Drawing_TypographyStyle*)
```

**描述**

获取排版样式中支柱样式字重。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本排版行样式字重。 0字重为thin，1字重为extra-light，2字重为light，4字重为medium，5字重为semi-bold， 6字重为bold，7字重为extra-bold，8字重为black，3或其它字重为normal/regular，具体可见[OH_Drawing_FontWeight](#oh_drawing_fontweight)枚举。


### OH_Drawing_TypographyTextlineStyleGetHalfLeading()

```
bool OH_Drawing_TypographyTextlineStyleGetHalfLeading (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本排版行样式是否为一半行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

文本排版行样式是否为一半行间距，true表示是一半行间距，false表示不是。


### OH_Drawing_TypographyTextlineStyleGetHeightOnly()

```
bool OH_Drawing_TypographyTextlineStyleGetHeightOnly (OH_Drawing_TypographyStyle* )
```

**描述**

获取字体渲染过程中计算字体块高度相关参数的方法。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回计算字体块高度相关参数的方法，true表示以字号为准计算，false表示以行距计算。


### OH_Drawing_TypographyTextlineStyleGetHeightScale()

```
double OH_Drawing_TypographyTextlineStyleGetHeightScale (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本排版行样式的行高缩放系数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本排版行样式的行高缩放系数。


### OH_Drawing_TypographyTextlineStyleGetSpacingScale()

```
double OH_Drawing_TypographyTextlineStyleGetSpacingScale (OH_Drawing_TypographyStyle* )
```

**描述**

获取文本排版行样式间距比例。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 表示指向[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)对象的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 

**返回：**

返回文本排版行样式间距比例。


### OH_Drawing_TypographyTextSetHeightBehavior()

```
void OH_Drawing_TypographyTextSetHeightBehavior (OH_Drawing_TypographyStyle* , OH_Drawing_TextHeightBehavior heightMode )
```

**描述**

设置文本高度修饰符模式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_TypographyStyle | 指向排版样式[OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)的指针，由[OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle)获取。 | 
| heightMode | 文本高度修饰符模式，为[OH_Drawing_TextHeightBehavior](#oh_drawing_textheightbehavior)类型的枚举值。 | 


### OH_Drawing_TypographyUpdateFontSize()

```
void OH_Drawing_TypographyUpdateFontSize (OH_Drawing_Typography* , size_t from, size_t to, float fontSize )
```

**描述**

更新排版对象中的字体大小。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| OH_Drawing_Typography | 表示指向排版对象[OH_Drawing_Typography](#oh_drawing_typography)的指针，由[OH_Drawing_CreateTypography](#oh_drawing_createtypography)获取。 | 
| from | 保留字段，暂未使用。 | 
| to | 保留字段，暂未使用。 | 
| fontSize | 表示更新后的字体大小。 | 