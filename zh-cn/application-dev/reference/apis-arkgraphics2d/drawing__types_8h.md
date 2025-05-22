# drawing_types.h


## 概述

文件中定义了用于绘制2d图形的数据类型，包括画布、画笔、画刷、位图和路径。

**引用文件：**&lt;native_drawing/drawing_types.h&gt;

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) | 定义一个二维的坐标点。 | 
| struct  [OH_Drawing_Point3D](_o_h___drawing___point3_d.md) | 定义一个三维的坐标点。 | 
| struct  [OH_Drawing_Image_Info](_o_h___drawing___image___info.md) | 定义图片信息结构体。 | 
| struct  [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md) | 定义矩形框样式结构体。 | 
| struct  [OH_Drawing_String](_o_h___drawing___string.md) | 采用UTF-16编码的字符串信息结构体。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Drawing_Array](_drawing.md#oh_drawing_array) [OH_Drawing_Array](_drawing.md#oh_drawing_array) | 定义数组对象，用于存储多个同类型对象。  | 
| typedef struct [OH_Drawing_String](_o_h___drawing___string.md) [OH_Drawing_String](_drawing.md#oh_drawing_string) | 采用UTF-16编码的字符串信息结构体。  | 
| typedef struct [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas)  [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) | 定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字。 | 
| typedef struct [OH_Drawing_Pen](_drawing.md#oh_drawing_pen)  [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) | 定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色。 | 
| typedef struct [OH_Drawing_Region](_drawing.md#oh_drawing_region)  [OH_Drawing_Region](_drawing.md#oh_drawing_region) | 定义一个区域，用于表示画布上的封闭区域，实现更精确的图形控制。 | 
| typedef struct [OH_Drawing_Brush](_drawing.md#oh_drawing_brush)  [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) | 定义为画刷，画刷用于描述填充图形的样式和颜色。 | 
| typedef struct [OH_Drawing_Path](_drawing.md#oh_drawing_path)  [OH_Drawing_Path](_drawing.md#oh_drawing_path) | 定义为路径，路径用于自定义各种形状。 | 
| typedef struct [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap)  [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) | 定义像素图，用于包装图像框架支持的真实像素图。 | 
| typedef struct [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap)  [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) | 定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据。 | 
| typedef struct [OH_Drawing_Point](_drawing.md#oh_drawing_point)  [OH_Drawing_Point](_drawing.md#oh_drawing_point) | 定义一个点，用于描述坐标点。 | 
| typedef struct [OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace)  [OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace) | 定义色彩空间，用于解释颜色信息。 | 
| typedef struct [OH_Drawing_Point2D](_o_h___drawing___point2_d.md)  [OH_Drawing_Point2D](_drawing.md#oh_drawing_point2d) | 定义一个二维的坐标点。 | 
| typedef [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) [OH_Drawing_Corner_Radii](_drawing.md#oh_drawing_corner_radii) | 定义一个圆角半径，该圆角半径由x轴方向和y轴方向上的半径组成。 | 
| typedef struct [OH_Drawing_Point3D](_o_h___drawing___point3_d.md)  [OH_Drawing_Point3D](_drawing.md#oh_drawing_point3d) | 定义一个三维的坐标点。 | 
| typedef struct [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect)  [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) | 定义一个路径效果，用于影响描边路径。 | 
| typedef struct [OH_Drawing_Rect](_drawing.md#oh_drawing_rect)  [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) | 用于描述矩形。 | 
| typedef struct [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect)  [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) | 用于描述圆角矩形。 | 
| typedef struct [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix)  [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) | 定义一个矩阵，用于描述坐标变换。 | 
| typedef struct [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect)  [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) | 定义一个着色器，用于描述绘制内容的源颜色。 | 
| typedef struct [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) [OH_Drawing_ShadowLayer](_drawing.md#oh_drawing_shadowlayer) | 定义一个阴影层，用于描述绘制内容的阴影层。 | 
| typedef struct [OH_Drawing_Filter](_drawing.md#oh_drawing_filter)  [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) | 定义一个滤波器，用于存储颜色滤波器，蒙版滤波器和图像滤波器。 | 
| typedef struct [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter)  [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) | 定义蒙版滤波器。 | 
| typedef struct [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter)  [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) | 定义颜色滤波器，传入一个颜色并返回一个新的颜色。 | 
| typedef struct [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter)  [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) | 定义图像滤波器，用于对构成图像像素的所有颜色位进行操作。 | 
| typedef struct [OH_Drawing_Font](_drawing.md#oh_drawing_font)  [OH_Drawing_Font](_drawing.md#oh_drawing_font) | 用于描述字体。 | 
| typedef struct [OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream)  [OH_Drawing_MemoryStream](_drawing.md#oh_drawing_memorystream) | 用于描述内存流。 | 
| typedef struct [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) [OH_Drawing_FontArguments](_drawing.md#oh_drawing_fontarguments) | 用于描述字型参数。 | 
| typedef struct [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface)  [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) | 用于描述字形。 | 
| typedef struct [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob)  [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) | 定义一个文本对象，表示将多个文本组合到一个不可变的容器中。 每个文本行由字形和位置组成。 | 
| typedef struct [OH_Drawing_Image](_drawing.md#oh_drawing_image)  [OH_Drawing_Image](_drawing.md#oh_drawing_image) | 定义一个用于描述绘制二维像素数组的图片。 | 
| typedef struct [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions)  [OH_Drawing_SamplingOptions](_drawing.md#oh_drawing_samplingoptions) | 定义一个采样选项，用于描述图片、位图等图像的采样方法。 | 
| typedef struct [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder)  [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) | 定义文本构建器，用于构建文本。 | 
| typedef struct [OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext)  [OH_Drawing_GpuContext](_drawing.md#oh_drawing_gpucontext) | 定义图形处理器上下文，用于描述图形处理器后端上下文。 | 
| typedef struct [OH_Drawing_Surface](_drawing.md#oh_drawing_surface)  [OH_Drawing_Surface](_drawing.md#oh_drawing_surface) | 定义surface，用于管理画布绘制的内容。 | 
| typedef enum [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat)  [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) | 用于描述位图像素的存储格式。 | 
| typedef enum [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat)  [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) | 用于描述位图像素的透明度分量。 | 
| typedef enum [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode)  [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在红、绿、蓝3个颜色通道上是相同的（透明度有另外的处理规则）。 | 
| typedef struct [OH_Drawing_Image_Info](_o_h___drawing___image___info.md)  [OH_Drawing_Image_Info](_drawing.md#oh_drawing_image_info) | 定义图片信息结构体。 | 
| typedef struct [OH_Drawing_RectStyle_Info](_o_h___drawing___rect_style___info.md)  [OH_Drawing_RectStyle_Info](_drawing.md#oh_drawing_rectstyle_info) | 定义矩形框样式结构体。 | 
| typedef enum [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding)  [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) | 文本编码类型枚举。 | 
| typedef struct [OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr)  [OH_Drawing_FontMgr](_drawing.md#oh_drawing_fontmgr) | 定义字体管理类，用于字体管理。 | 
| typedef struct [OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset)  [OH_Drawing_FontStyleSet](_drawing.md#oh_drawing_fontstyleset) | 定义字体样式集，用于字体样式族匹配。 | 
| typedef struct [OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) [OH_Drawing_RecordCmdUtils](_drawing.md#oh_drawing_recordcmdutils) | 定义指令录制工具，用于生成录制指令。 | 
| typedef struct [OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) [OH_Drawing_RecordCmd](_drawing.md#oh_drawing_recordcmd) | 定义录制指令类，用于存储录制指令的集合。 |

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) {<br/>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,<br/>COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br/>} | 用于描述位图像素的存储格式。 | 
| [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | 用于描述位图像素的透明度分量。 | 
| [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) {<br/>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br/>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br/>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br/>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br/>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br/>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br/>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br/>BLEND_MODE_LUMINOSITY<br/>} | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。 这些操作在红、绿、蓝3个颜色通道上是相同的（透明度有另外的处理规则）。 | 
| [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) { TEXT_ENCODING_UTF8, TEXT_ENCODING_UTF16, TEXT_ENCODING_UTF32, TEXT_ENCODING_GLYPH_ID } | 文本编码类型枚举。 | 
