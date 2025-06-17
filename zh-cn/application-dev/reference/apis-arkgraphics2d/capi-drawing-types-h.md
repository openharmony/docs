# drawing_types.h

## 概述

文件中定义了用于绘制2d图形的数据类型，包括画布、画笔、画刷、位图和路径。

**引用文件：** <native_drawing/drawing_types.h>

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_Point2D](capi-oh-drawing-point2d.md) | OH_Drawing_Point2D | 定义一个二维的坐标点。 |
| [OH_Drawing_Point3D](capi-oh-drawing-point3d.md) | OH_Drawing_Point3D | 定义一个三维的坐标点。 |
| [OH_Drawing_Image_Info](capi-oh-drawing-image-info.md) | OH_Drawing_Image_Info | 定义图片信息结构体。 |
| [OH_Drawing_RectStyle_Info](capi-oh-drawing-rectstyle-info.md) | OH_Drawing_RectStyle_Info | 定义矩形框样式结构体。 |
| [OH_Drawing_String](capi-oh-drawing-string.md) | OH_Drawing_String | 采用UTF-16编码的字符串信息结构体。 |
| [OH_Drawing_Canvas](capi-oh-drawing-canvas.md) | OH_Drawing_Canvas | 定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字。 |
| [OH_Drawing_Pen](capi-oh-drawing-pen.md) | OH_Drawing_Pen | 定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色。 |
| [OH_Drawing_Region](capi-oh-drawing-region.md) | OH_Drawing_Region | 定义一个区域，用于表示画布上的封闭区域，实现更精确的图形控制。 |
| [OH_Drawing_Brush](capi-oh-drawing-brush.md) | OH_Drawing_Brush | 定义为画刷，画刷用于描述填充图形的样式和颜色。 |
| [OH_Drawing_Path](capi-oh-drawing-path.md) | OH_Drawing_Path | 定义为路径，路径用于自定义各种形状。 |
| [OH_Drawing_Bitmap](capi-oh-drawing-bitmap.md) | OH_Drawing_Bitmap | 定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据。 |
| [OH_Drawing_Point](capi-oh-drawing-point.md) | OH_Drawing_Point | 定义一个点，用于描述坐标点。 |
| [OH_Drawing_PixelMap](capi-oh-drawing-pixelmap.md) | OH_Drawing_PixelMap | 定义像素图，用于包装图像框架支持的真实像素图。 |
| [OH_Drawing_ColorSpace](capi-oh-drawing-colorspace.md) | OH_Drawing_ColorSpace | 定义色彩空间，用于解释颜色信息。 |
| [OH_Drawing_PathEffect](capi-oh-drawing-patheffect.md) | OH_Drawing_PathEffect | 定义一个路径效果，用于影响描边路径。 |
| [OH_Drawing_Rect](capi-oh-drawing-rect.md) | OH_Drawing_Rect | 用于描述矩形。 |
| [OH_Drawing_RoundRect](capi-oh-drawing-roundrect.md) | OH_Drawing_RoundRect | 用于描述圆角矩形。 |
| [OH_Drawing_Matrix](capi-oh-drawing-matrix.md) | OH_Drawing_Matrix | 定义一个矩阵，用于描述坐标变换。 |
| [OH_Drawing_ShaderEffect](capi-oh-drawing-shadereffect.md) | OH_Drawing_ShaderEffect | 定义一个着色器，用于描述绘制内容的源颜色。 |
| [OH_Drawing_ShadowLayer](capi-oh-drawing-shadowlayer.md) | OH_Drawing_ShadowLayer | 定义一个阴影层，用于描述绘制内容的阴影层。 |
| [OH_Drawing_Filter](capi-oh-drawing-filter.md) | OH_Drawing_Filter | 定义一个滤波器，用于存储颜色滤波器，蒙版滤波器和图像滤波器。 |
| [OH_Drawing_MaskFilter](capi-oh-drawing-maskfilter.md) | OH_Drawing_MaskFilter | 定义蒙版滤波器。 |
| [OH_Drawing_ColorFilter](capi-oh-drawing-colorfilter.md) | OH_Drawing_ColorFilter | 定义颜色滤波器，传入一个颜色并返回一个新的颜色。 |
| [OH_Drawing_Font](capi-oh-drawing-font.md) | OH_Drawing_Font | 用于描述字体。 |
| [OH_Drawing_MemoryStream](capi-oh-drawing-memorystream.md) | OH_Drawing_MemoryStream | 用于描述内存流。 |
| [OH_Drawing_FontArguments](capi-oh-drawing-fontarguments.md) | OH_Drawing_FontArguments | 用于描述字型参数。 |
| [OH_Drawing_Typeface](capi-oh-drawing-typeface.md) | OH_Drawing_Typeface | 用于描述字形。 |
| [OH_Drawing_TextBlob](capi-oh-drawing-textblob.md) | OH_Drawing_TextBlob | 定义一个文本对象，表示将多个文本组合到一个不可变的容器中。每个文本行由字形和位置组成。 |
| [OH_Drawing_Image](capi-oh-drawing-image.md) | OH_Drawing_Image | 定义一个用于描述绘制二维像素数组的图片。 |
| [OH_Drawing_ImageFilter](capi-oh-drawing-imagefilter.md) | OH_Drawing_ImageFilter | 定义图像滤波器, 用于对构成图像像素的所有颜色位进行操作。 |
| [OH_Drawing_SamplingOptions](capi-oh-drawing-samplingoptions.md) | OH_Drawing_SamplingOptions | 定义一个采样选项，用于描述图片、位图等图像的采样方法。 |
| [OH_Drawing_TextBlobBuilder](capi-oh-drawing-textblobbuilder.md) | OH_Drawing_TextBlobBuilder | 定义文本构建器，用于构建文本。 |
| [OH_Drawing_GpuContext](capi-oh-drawing-gpucontext.md) | OH_Drawing_GpuContext | 定义图形处理器上下文，用于描述图形处理器后端上下文。 |
| [OH_Drawing_Surface](capi-oh-drawing-surface.md) | OH_Drawing_Surface | 定义surface，用于管理画布绘制的内容。 |
| [OH_Drawing_FontMgr](capi-oh-drawing-fontmgr.md) | OH_Drawing_FontMgr | 定义字体管理类, 用于字体管理。 |
| [OH_Drawing_FontStyleSet](capi-oh-drawing-fontstyleset.md) | OH_Drawing_FontStyleSet | 定义字体样式集, 用于字体样式族匹配。 |
| [OH_Drawing_RecordCmdUtils](capi-oh-drawing-recordcmdutils.md) | OH_Drawing_RecordCmdUtils | 定义指令录制工具，用于生成录制指令。 |
| [OH_Drawing_RecordCmd](capi-oh-drawing-recordcmd.md) | OH_Drawing_RecordCmd | 定义录制指令类, 用于存储录制指令的集合。 |
| [OH_Drawing_Array](capi-oh-drawing-array.md) | OH_Drawing_Array | 定义数组对象, 用于存储多个同类型对象。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat) | OH_Drawing_ColorFormat | 用于描述位图像素的存储格式。 |
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) | OH_Drawing_AlphaFormat | 用于描述位图像素的透明度分量。 |
| [OH_Drawing_BlendMode](#oh_drawing_blendmode) | OH_Drawing_BlendMode | 混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。<br>这些操作在红、绿、蓝3个颜色通道上是相同的（透明度有另外的处理规则）。<br>对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。为简洁起见，我们使用以下缩写：<br>s  : source，源的缩写。<br>d  : destination，目标的缩写。<br>sa : source alpha，源透明度的缩写。<br>da : destination alpha，目标透明度的缩写。<br>计算结果用如下缩写表示：<br>r  : 如果4个通道的计算方式相同，用r表示。<br>ra : 如果只操作透明度通道，用ra表示。<br>rc : 如果操作3个颜色通道，用rc表示。 |
| [OH_Drawing_TextEncoding](#oh_drawing_textencoding) | OH_Drawing_TextEncoding | 文本编码类型枚举。 |

## 枚举类型说明

### OH_Drawing_ColorFormat

```
enum OH_Drawing_ColorFormat
```

**描述**

用于描述位图像素的存储格式。

**起始版本：** 8

| 枚举项 | 描述 |
| -- | -- |
| COLOR_FORMAT_UNKNOWN | 未知格式。. |
| COLOR_FORMAT_ALPHA_8 | 每个像素用一个8位的量表示，8个位比特位表示透明度。 |
| COLOR_FORMAT_RGB_565 | 每个像素用一个16位的量表示，高位到低位依次是5个比特位表示红，6个比特位表示绿，5个比特位表示蓝。 |
| COLOR_FORMAT_ARGB_4444 | 每个像素用一个16位的量表示，高位到低位依次是4个比特位表示透明度，4个比特位表示红，4个比特位表示绿，4个比特位表示蓝。 |
| COLOR_FORMAT_RGBA_8888 | 每个像素用一个32位的量表示，高位到低位依次是8个比特位表示透明度，8个比特位表示红，8个比特位表示绿，8个比特位表示蓝。 |
| COLOR_FORMAT_BGRA_8888 | 每个像素用一个32位的量表示，高位到低位依次是8个比特位表示蓝，8个比特位表示绿，8个比特位表示红，8个比特位表示透明度。 |

### OH_Drawing_AlphaFormat

```
enum OH_Drawing_AlphaFormat
```

**描述**

用于描述位图像素的透明度分量。

**起始版本：** 8

| 枚举项 | 描述 |
| -- | -- |
| ALPHA_FORMAT_UNKNOWN | 未知格式。 |
| ALPHA_FORMAT_OPAQUE | 位图无透明度。 |
| ALPHA_FORMAT_PREMUL | 每个像素的颜色组件由透明度分量预先乘以。 |
| ALPHA_FORMAT_UNPREMUL | 每个像素的颜色组件未由透明度分量预先乘以。 |

### OH_Drawing_BlendMode

```
enum OH_Drawing_BlendMode
```

**描述**

混合模式枚举。混合模式的操作会为两种颜色（源色、目标色）生成一种新的颜色。<br>这些操作在红、绿、蓝3个颜色通道上是相同的（透明度有另外的处理规则）。<br>对于这些，我们使用透明度通道作为示例，而不是单独命名每个通道。为简洁起见，我们使用以下缩写：<br>s  : source，源的缩写。<br>d  : destination，目标的缩写。<br>sa : source alpha，源透明度的缩写。<br>da : destination alpha，目标透明度的缩写。<br>计算结果用如下缩写表示：<br>r  : 如果4个通道的计算方式相同，用r表示。<br>ra : 如果只操作透明度通道，用ra表示。<br>rc : 如果操作3个颜色通道，用rc表示。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| BLEND_MODE_CLEAR | 清除模式，r = 0。 |
| BLEND_MODE_SRC | r = s（result的4个通道，都等于source的4个通道，即结果等于源。） |
| BLEND_MODE_DST | r = d（result的4个通道，都等于destination的4个通道，即结果等于目标。） |
| BLEND_MODE_SRC_OVER | r = s + (1 - sa) * d。 |
| BLEND_MODE_DST_OVER | r = d + (1 - da) * s。 |
| BLEND_MODE_SRC_IN | r = s * da。 |
| BLEND_MODE_DST_IN | r = d * sa。 |
| BLEND_MODE_SRC_OUT | r = s * (1 - da)。 |
| BLEND_MODE_DST_OUT | r = d * (1 - sa)。 |
| BLEND_MODE_SRC_ATOP | r = s * da + d * (1 - sa)。 |
| BLEND_MODE_DST_ATOP | r = d * sa + s * (1 - da)。 |
| BLEND_MODE_XOR | r = s * (1 - da) + d * (1 - sa)。 |
| BLEND_MODE_PLUS | r = min(s + d, 1)。 |
| BLEND_MODE_MODULATE | r = s * d。 |
| BLEND_MODE_SCREEN | 滤色模式，r = s + d - s * d。 |
| BLEND_MODE_OVERLAY | 叠加模式。 |
| BLEND_MODE_DARKEN | 变暗模式，rc = s + d - max(s * da, d * sa), ra = s + (1 - sa) * d。 |
| BLEND_MODE_LIGHTEN | 变亮模式，rc = s + d - min(s * da, d * sa), ra = s + (1 - sa) * d。 |
| BLEND_MODE_COLOR_DODGE | 颜色减淡模式。 |
| BLEND_MODE_COLOR_BURN | 颜色加深模式。 |
| BLEND_MODE_HARD_LIGHT | 强光模式。 |
| BLEND_MODE_SOFT_LIGHT | 柔光模式。 |
| BLEND_MODE_DIFFERENCE | 差值模式，rc = s + d - 2 * (min(s * da, d * sa)), ra = s + (1 - sa) * d。 |
| BLEND_MODE_EXCLUSION | 排除模式，rc = s + d - two(s * d), ra = s + (1 - sa) * d。 |
| BLEND_MODE_MULTIPLY | 正片叠底，r = s * (1 - da) + d * (1 - sa) + s * d。 |
| BLEND_MODE_HUE | 色相模式。 |
| BLEND_MODE_SATURATION | 饱和度模式。 |
| BLEND_MODE_COLOR | 颜色模式。 |
| BLEND_MODE_LUMINOSITY | 亮度模式。 |

### OH_Drawing_TextEncoding

```
enum OH_Drawing_TextEncoding
```

**描述**

文本编码类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| TEXT_ENCODING_UTF8 | 单字节，表示UTF-8或ASCII。 |
| TEXT_ENCODING_UTF16 | 双字节，表示大部分Unicode。 |
| TEXT_ENCODING_UTF32 | 四字节，表示所有Unicode。 |
| TEXT_ENCODING_GLYPH_ID | 双字节，表示字形索引。 |


