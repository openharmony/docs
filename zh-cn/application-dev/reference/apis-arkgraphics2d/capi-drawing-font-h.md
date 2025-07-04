# drawing_font.h

## 概述

文件中定义了与字体相关的功能函数。

**引用文件：** <native_drawing/drawing_font.h>

**库：** libnative_drawing.so

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md) | OH_Drawing_Font_Metrics | 定义字体度量信息的结构体。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting) | OH_Drawing_FontHinting | 字型轮廓效果类型枚举。 |
| [OH_Drawing_FontEdging](#oh_drawing_fontedging) | OH_Drawing_FontEdging | 字型边缘效果类型枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_ErrorCode OH_Drawing_FontGetSpacing(const OH_Drawing_Font* font, float* spacing)](#oh_drawing_fontgetspacing) | 用于获取推荐的字型行间距。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontGetPos(const OH_Drawing_Font* font, const uint16_t* glyphs, int count,const OH_Drawing_Point* origin, OH_Drawing_Point2D* points)](#oh_drawing_fontgetpos) | 用于从指定的原点开始，获取每个字形的相对位置。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontGetWidthsBounds(const OH_Drawing_Font* font, const uint16_t* glyphs, int count,const OH_Drawing_Brush* brush, const OH_Drawing_Pen* pen, float* widths, OH_Drawing_Array* bounds)](#oh_drawing_fontgetwidthsbounds) | 用于获取字形数组中每个字形的宽度和边界框。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontMeasureTextWithBrushOrPen(const OH_Drawing_Font* font, const void* text,size_t byteLength, OH_Drawing_TextEncoding encoding, const OH_Drawing_Brush* brush, const OH_Drawing_Pen* pen,OH_Drawing_Rect* bounds, float* textWidth)](#oh_drawing_fontmeasuretextwithbrushorpen) | 使用画刷或画笔获取文本的宽度和边界框。 |
| [OH_Drawing_Font* OH_Drawing_FontCreate(void)](#oh_drawing_fontcreate) | 用于创建一个字型对象。 |
| [void OH_Drawing_FontSetBaselineSnap(OH_Drawing_Font* font, bool baselineSnap)](#oh_drawing_fontsetbaselinesnap) | 当前画布矩阵轴对齐时，将字型基线设置为是否与像素对齐。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_FontIsBaselineSnap(const OH_Drawing_Font* font)](#oh_drawing_fontisbaselinesnap) | 当前画布矩阵轴对齐时，获取字型基线是否与像素对齐。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetSubpixel(OH_Drawing_Font* font, bool isSubpixel)](#oh_drawing_fontsetsubpixel) | 设置字型是否使用次像素渲染。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_FontIsSubpixel(const OH_Drawing_Font* font)](#oh_drawing_fontissubpixel) | 获取字型是否使用次像素渲染。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetForceAutoHinting(OH_Drawing_Font* font, bool isForceAutoHinting)](#oh_drawing_fontsetforceautohinting) | 用于设置是否自动调整字型轮廓。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_FontIsForceAutoHinting(const OH_Drawing_Font* font)](#oh_drawing_fontisforceautohinting) | 获取字型轮廓是否自动调整。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetTypeface(OH_Drawing_Font* font, OH_Drawing_Typeface* typeface)](#oh_drawing_fontsettypeface) | 用于给字型设置字体。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_Typeface* OH_Drawing_FontGetTypeface(OH_Drawing_Font* font)](#oh_drawing_fontgettypeface) | 获取字体对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetTextSize(OH_Drawing_Font* font, float textSize)](#oh_drawing_fontsettextsize) | 用于给字型对象设置文字大小。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_FontGetTextSize(const OH_Drawing_Font* font)](#oh_drawing_fontgettextsize) | 获取字型对象的文字大小。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [int OH_Drawing_FontCountText(OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding)](#oh_drawing_fontcounttext) | 获取文本所表示的字符数量。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font、text任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [uint32_t OH_Drawing_FontTextToGlyphs(const OH_Drawing_Font* font, const void* text, uint32_t byteLength,OH_Drawing_TextEncoding encoding, uint16_t* glyphs, int maxGlyphCount)](#oh_drawing_fonttexttoglyphs) | 用于将文本转换为字形索引。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font、text、glyphs任意一个为NULL或者byteLength等于0或者maxGlyphCount小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontGetWidths(const OH_Drawing_Font* font, const uint16_t* glyphs, int count, float* widths)](#oh_drawing_fontgetwidths) | 用于获取字符串中每个字符的宽度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font、glyphs、widths任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontMeasureSingleCharacter(const OH_Drawing_Font* font, const char* str,float* textWidth)](#oh_drawing_fontmeasuresinglecharacter) | 用于测量单个字符的宽度。当前字型中的字体不支持待测量字符时，退化到使用系统字体测量字符宽度。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontMeasureText(const OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding, OH_Drawing_Rect* bounds, float* textWidth)](#oh_drawing_fontmeasuretext) | 用于获取文本的宽度和边界框。 |
| [void OH_Drawing_FontSetLinearText(OH_Drawing_Font* font, bool isLinearText)](#oh_drawing_fontsetlineartext) | 用于设置线性可缩放字型。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_FontIsLinearText(const OH_Drawing_Font* font)](#oh_drawing_fontislineartext) | 获取字型对象是否使用线性缩放。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetTextSkewX(OH_Drawing_Font* font, float skewX)](#oh_drawing_fontsettextskewx) | 用于给字型设置文本倾斜。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_FontGetTextSkewX(const OH_Drawing_Font* font)](#oh_drawing_fontgettextskewx) | 获取字型文本在x轴上的倾斜度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetFakeBoldText(OH_Drawing_Font* font, bool isFakeBoldText)](#oh_drawing_fontsetfakeboldtext) | 用于设置增加描边宽度以近似粗体字体效果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_FontIsFakeBoldText(const OH_Drawing_Font* font)](#oh_drawing_fontisfakeboldtext) | 获取是否增加笔画宽度以接近粗体字体。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetScaleX(OH_Drawing_Font* font, float scaleX)](#oh_drawing_fontsetscalex) | 用于设置字型在x轴上的缩放比例。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [float OH_Drawing_FontGetScaleX(const OH_Drawing_Font* font)](#oh_drawing_fontgetscalex) | 获取字型在x轴上的缩放比例。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetHinting(OH_Drawing_Font* font, OH_Drawing_FontHinting fontHinting)](#oh_drawing_fontsethinting) | 用于设置字型轮廓效果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>fontHinting不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [OH_Drawing_FontHinting OH_Drawing_FontGetHinting(const OH_Drawing_Font* font)](#oh_drawing_fontgethinting) | 获取字型轮廓效果枚举类型。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetEmbeddedBitmaps(OH_Drawing_Font* font, bool isEmbeddedBitmaps)](#oh_drawing_fontsetembeddedbitmaps) | 用于设置字型是否转换成位图处理。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [bool OH_Drawing_FontIsEmbeddedBitmaps(const OH_Drawing_Font* font)](#oh_drawing_fontisembeddedbitmaps) | 获取字型是否转换成位图处理。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontSetEdging(OH_Drawing_Font* font, OH_Drawing_FontEdging fontEdging)](#oh_drawing_fontsetedging) | 用于设置字型边缘效果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>fontEdging不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [OH_Drawing_FontEdging OH_Drawing_FontGetEdging(const OH_Drawing_Font* font)](#oh_drawing_fontgetedging) | 获取字型边缘效果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_FontDestroy(OH_Drawing_Font* font)](#oh_drawing_fontdestroy) | 用于销毁字型对象并回收该对象占有的内存。 |
| [float OH_Drawing_FontGetMetrics(OH_Drawing_Font* font, OH_Drawing_Font_Metrics* fontMetrics)](#oh_drawing_fontgetmetrics) | 获取字体度量信息。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font、fontMetrics任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontGetBounds(const OH_Drawing_Font* font, const uint16_t* glyphs, uint32_t count,OH_Drawing_Array* bounds)](#oh_drawing_fontgetbounds) | 获取字型指定字形索引的矩形边界。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontGetPathForGlyph(const OH_Drawing_Font* font, uint16_t glyph,OH_Drawing_Path* path)](#oh_drawing_fontgetpathforglyph) | 获取字型指定字形索引的轮廓。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontGetTextPath(const OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding, float x, float y, OH_Drawing_Path* path)](#oh_drawing_fontgettextpath) | 获取文字轮廓路径。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontSetThemeFontFollowed(OH_Drawing_Font* font, bool followed)](#oh_drawing_fontsetthemefontfollowed) | 设置字型中的字体是否跟随主题字体。设置跟随主题字体后，若系统启用主题字体并且字型未被设置字体，字型会使用该主题字体。 |
| [OH_Drawing_ErrorCode OH_Drawing_FontIsThemeFontFollowed(const OH_Drawing_Font* font, bool* followed)](#oh_drawing_fontisthemefontfollowed) | 获取字型中的字体是否跟随主题字体。默认不跟随主题字体。 |

## 枚举类型说明

### OH_Drawing_FontHinting

```
enum OH_Drawing_FontHinting
```

**描述**

字型轮廓效果类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| FONT_HINTING_NONE | 不修改字型轮廓。 |
| FONT_HINTING_SLIGHT | 最小限度修改字型轮廓以改善对比度。 |
| FONT_HINTING_NORMAL | 修改字型轮廓以提高对比度。 |
| FONT_HINTING_FULL | 修改字型轮廓以获得最大对比度。 |

### OH_Drawing_FontEdging

```
enum OH_Drawing_FontEdging
```

**描述**

字型边缘效果类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| FONT_EDGING_ALIAS | 无抗锯齿处理。 |
| FONT_EDGING_ANTI_ALIAS | 使用抗锯齿来平滑字型边缘。 |
| FONT_EDGING_SUBPIXEL_ANTI_ALIAS | 使用次像素级别的抗锯齿来平滑字型边缘，可以获得更加平滑的字型渲染效果。 |


## 函数说明

### OH_Drawing_FontMeasureTextWithBrushOrPen()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureTextWithBrushOrPen(const OH_Drawing_Font* font, const void* text,size_t byteLength, OH_Drawing_TextEncoding encoding, const OH_Drawing_Brush* brush, const OH_Drawing_Pen* pen,OH_Drawing_Rect* bounds, float* textWidth)
```

**描述**

使用画刷或画笔获取文本的宽度和边界框。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const OH_Drawing_Font* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const void* text | 指向文本的指针。 |
| size_t byteLength | 表示以字节为单位的文本长度。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | 文本编码类型。 |
| const OH_Drawing_Brush* brush | 指向画刷对象[OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)的指针。 |
| const OH_Drawing_Pen* pen | 指向画笔对象[OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)的指针。 |
| OH_Drawing_Rect* bounds | 用于承载获取的边界框，可以为NULL。 |
| float* textWidth | 表示文本宽度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行操作码。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font、text、textWidth至少有一个为空，或者byteLength为0，或者brush和pen同时存在。 |

### OH_Drawing_FontGetWidthsBounds()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetWidthsBounds(const OH_Drawing_Font* font, const uint16_t* glyphs, int count,const OH_Drawing_Brush* brush, const OH_Drawing_Pen* pen, float* widths, OH_Drawing_Array* bounds)
```

**描述**

用于获取字形数组中每个字形的宽度和边界框。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const OH_Drawing_Font* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const uint16_t* glyphs | 字形索引存储首地址。 |
| int count | 字形索引的数量，大小与glyphs数组大小保持一致。 |
| const OH_Drawing_Brush* brush | 指向画刷对象[OH_Drawing_Brush](capi-drawing-oh-drawing-brush.md)的指针。 |
| const OH_Drawing_Pen* pen | 指向画笔对象[OH_Drawing_Pen](capi-drawing-oh-drawing-pen.md)的指针。 |
| float* widths | 字形宽度存储首地址，用于存储得到的字形宽度，作为返回值返回给调用者。 |
| OH_Drawing_Array* bounds | 字形边界框存储首地址，用于存储得到的字形边界框。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行操作码。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font、glyphs至少有一个为空，或者count不大于0，或者brush和pen同时存在，或者widths和bounds同时为空。 |

### OH_Drawing_FontGetPos()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetPos(const OH_Drawing_Font* font, const uint16_t* glyphs, int count,const OH_Drawing_Point* origin, OH_Drawing_Point2D* points)
```

**描述**

用于从指定的原点开始，获取每个字形的相对位置。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const OH_Drawing_Font* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const uint16_t* glyphs | 字形索引存储首地址。 |
| int count | 字形索引的数量，大小与glyphs数组大小保持一致。 |
| const OH_Drawing_Point* origin | 指向第一个字形的位置，可以为NULL，为NULL默认从(0, 0)开始。 |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* points | 字形相对位置存储首地址，用于存储得到的字形相对位置，作为返回值返回给调用者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行操作码。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font、glyphs、points至少有一个为空，或者count不大于0。 |

### OH_Drawing_FontGetSpacing()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetSpacing(const OH_Drawing_Font* font, float* spacing)
```

**描述**

用于获取推荐的字型行间距。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const OH_Drawing_Font* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| float* spacing | 推荐的字型行间距，作为返回值返回给调用者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行操作码。<br>返回OH_DRAWING_SUCCESS，表示执行成功。<br>返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font、spacing至少有一个为空。 |

### OH_Drawing_FontCreate()

```
OH_Drawing_Font* OH_Drawing_FontCreate(void)
```

**描述**

用于创建一个字型对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* | 函数会返回一个指针，指针指向创建的字型对象。 |

### OH_Drawing_FontSetBaselineSnap()

```
void OH_Drawing_FontSetBaselineSnap(OH_Drawing_Font* font, bool baselineSnap)
```

**描述**

当前画布矩阵轴对齐时，将字型基线设置为是否与像素对齐。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| bool baselineSnap | 指示字型基线是否和像素对齐。true表示对齐，false表示不对齐。 |

### OH_Drawing_FontIsBaselineSnap()

```
bool OH_Drawing_FontIsBaselineSnap(const OH_Drawing_Font* font)
```

**描述**

当前画布矩阵轴对齐时，获取字型基线是否与像素对齐。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回字型基线是否与像素对齐。true为对齐，false为没有对齐。 |

### OH_Drawing_FontSetSubpixel()

```
void OH_Drawing_FontSetSubpixel(OH_Drawing_Font* font, bool isSubpixel)
```

**描述**

设置字型是否使用次像素渲染。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| bool isSubpixel | 字型是否使用次像素渲染。true为使用，false为不使用。 |

### OH_Drawing_FontIsSubpixel()

```
bool OH_Drawing_FontIsSubpixel(const OH_Drawing_Font* font)
```

**描述**

获取字型是否使用次像素渲染。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回字型是否使用次像素渲染。true为使用，false为不使用。 |

### OH_Drawing_FontSetForceAutoHinting()

```
void OH_Drawing_FontSetForceAutoHinting(OH_Drawing_Font* font, bool isForceAutoHinting)
```

**描述**

用于设置是否自动调整字型轮廓。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| bool isForceAutoHinting | 是否自动调整字型轮廓。true为自动调整，false为不自动调整。 |

### OH_Drawing_FontIsForceAutoHinting()

```
bool OH_Drawing_FontIsForceAutoHinting(const OH_Drawing_Font* font)
```

**描述**

获取字型轮廓是否自动调整。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回字型轮廓是否自动调整。true为自动调整，false为不自动调整。 |

### OH_Drawing_FontSetTypeface()

```
void OH_Drawing_FontSetTypeface(OH_Drawing_Font* font, OH_Drawing_Typeface* typeface)
```

**描述**

用于给字型设置字体。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象的指针。 |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* typeface | 指向字体对象的指针，为NULL会使用系统默认字体对象。 |

### OH_Drawing_FontGetTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontGetTypeface(OH_Drawing_Font* font)
```

**描述**

获取字体对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | OH_Drawing_Typeface 函数返回一个指针，指向字体对象[OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)。 |

### OH_Drawing_FontSetTextSize()

```
void OH_Drawing_FontSetTextSize(OH_Drawing_Font* font, float textSize)
```

**描述**

用于给字型对象设置文字大小。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象的指针。 |
| float textSize | 文字大小，该参数为浮点数，为负数时字体大小会被置为0。字体大小为0时，绘制的文字不会显示。 |

### OH_Drawing_FontGetTextSize()

```
float OH_Drawing_FontGetTextSize(const OH_Drawing_Font* font)
```

**描述**

获取字型对象的文字大小。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回一个浮点数，表示文字大小。 |

### OH_Drawing_FontCountText()

```
int OH_Drawing_FontCountText(OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding)
```

**描述**

获取文本所表示的字符数量。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font、text任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const void* text | 文本存储首地址。 |
| size_t byteLength | 文本长度，单位为字节。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | 文本编码类型[OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding)。 |

### OH_Drawing_FontTextToGlyphs()

```
uint32_t OH_Drawing_FontTextToGlyphs(const OH_Drawing_Font* font, const void* text, uint32_t byteLength,OH_Drawing_TextEncoding encoding, uint16_t* glyphs, int maxGlyphCount)
```

**描述**

用于将文本转换为字形索引。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font、text、glyphs任意一个为NULL或者byteLength等于0或者maxGlyphCount小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const void* text | 文本存储首地址。 |
| uint32_t byteLength | 文本长度，单位为字节。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | 文本编码类型[OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding)。 |
| uint16_t* glyphs | 字形索引存储首地址，用于存储得到的字形索引。 |
| int maxGlyphCount | 文本所表示的最大字符数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回字形索引数量。 |

### OH_Drawing_FontGetWidths()

```
void OH_Drawing_FontGetWidths(const OH_Drawing_Font* font, const uint16_t* glyphs, int count, float* widths)
```

**描述**

用于获取字符串中每个字符的宽度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font、glyphs、widths任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const uint16_t* glyphs | 字形索引存储首地址。 |
| int count | 字形索引的数量。 |
| float* widths | 字形宽度存储首地址，用于存储得到的字形宽度。 |

### OH_Drawing_FontMeasureSingleCharacter()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureSingleCharacter(const OH_Drawing_Font* font, const char* str,float* textWidth)
```

**描述**

用于测量单个字符的宽度。当前字型中的字体不支持待测量字符时，退化到使用系统字体测量字符宽度。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const char* str | 待测量的单个字符。可以传入字符串，但只会以UTF-8编码解析并测量字符串中的首个字符。 |
| float* textWidth | 用于存储得到的字符宽度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font、str、textWidth任意一个为NULL或者str的长度为0。 |

### OH_Drawing_FontMeasureText()

```
OH_Drawing_ErrorCode OH_Drawing_FontMeasureText(const OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding, OH_Drawing_Rect* bounds, float* textWidth)
```

**描述**

用于获取文本的宽度和边界框。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const void* text | 指向文本的指针。 |
| size_t byteLength | 表示以字节为单位的文本长度。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | 文本编码类型。 |
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* bounds | 用于承载获取的边界框，可以为NULL。 |
| float* textWidth | 表示文本宽度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font，text，textWidth至少有一个为空，或者byteLength为0。 |

### OH_Drawing_FontSetLinearText()

```
void OH_Drawing_FontSetLinearText(OH_Drawing_Font* font, bool isLinearText)
```

**描述**

用于设置线性可缩放字型。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象的指针。 |
| bool isLinearText | 真为使能线性可缩放字型，假为不使能。 |

### OH_Drawing_FontIsLinearText()

```
bool OH_Drawing_FontIsLinearText(const OH_Drawing_Font* font)
```

**描述**

获取字型对象是否使用线性缩放。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回字型对象是否使用线性缩放，true为使用，false为不使用。 |

### OH_Drawing_FontSetTextSkewX()

```
void OH_Drawing_FontSetTextSkewX(OH_Drawing_Font* font, float skewX)
```

**描述**

用于给字型设置文本倾斜。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象的指针。 |
| float skewX | 轴相对于Y轴的倾斜度。 |

### OH_Drawing_FontGetTextSkewX()

```
float OH_Drawing_FontGetTextSkewX(const OH_Drawing_Font* font)
```

**描述**

获取字型文本在x轴上的倾斜度。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回一个浮点数，表示x轴上的文本倾斜度。 |

### OH_Drawing_FontSetFakeBoldText()

```
void OH_Drawing_FontSetFakeBoldText(OH_Drawing_Font* font, bool isFakeBoldText)
```

**描述**

用于设置增加描边宽度以近似粗体字体效果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象的指针。 |
| bool isFakeBoldText | 真为使能增加描边宽度，假为不使能。 |

### OH_Drawing_FontIsFakeBoldText()

```
bool OH_Drawing_FontIsFakeBoldText(const OH_Drawing_Font* font)
```

**描述**

获取是否增加笔画宽度以接近粗体字体。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回是否增加笔画宽度以接近粗体字体。true为增加，false为不增加。 |

### OH_Drawing_FontSetScaleX()

```
void OH_Drawing_FontSetScaleX(OH_Drawing_Font* font, float scaleX)
```

**描述**

用于设置字型在x轴上的缩放比例。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| float scaleX | 文本在x轴上的缩放比例。 |

### OH_Drawing_FontGetScaleX()

```
float OH_Drawing_FontGetScaleX(const OH_Drawing_Font* font)
```

**描述**

获取字型在x轴上的缩放比例。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 返回文本在x轴上的缩放比例。 |

### OH_Drawing_FontSetHinting()

```
void OH_Drawing_FontSetHinting(OH_Drawing_Font* font, OH_Drawing_FontHinting fontHinting)
```

**描述**

用于设置字型轮廓效果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>fontHinting不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting) fontHinting | 字型轮廓枚举类型[OH_Drawing_FontHinting](capi-drawing-font-h.md#oh_drawing_fonthinting)。 |

### OH_Drawing_FontGetHinting()

```
OH_Drawing_FontHinting OH_Drawing_FontGetHinting(const OH_Drawing_Font* font)
```

**描述**

获取字型轮廓效果枚举类型。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontHinting](#oh_drawing_fonthinting) | OH_Drawing_FontHinting 返回字型轮廓效果枚举类型[OH_Drawing_FontHinting](capi-drawing-font-h.md#oh_drawing_fonthinting)。 |

### OH_Drawing_FontSetEmbeddedBitmaps()

```
void OH_Drawing_FontSetEmbeddedBitmaps(OH_Drawing_Font* font, bool isEmbeddedBitmaps)
```

**描述**

用于设置字型是否转换成位图处理。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| bool isEmbeddedBitmaps | 设置字型是否转换成位图处理，true表示转换成位图处理，false表示不转换成位图处理。 |

### OH_Drawing_FontIsEmbeddedBitmaps()

```
bool OH_Drawing_FontIsEmbeddedBitmaps(const OH_Drawing_Font* font)
```

**描述**

获取字型是否转换成位图处理。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 返回字型是否转换成位图处理，true表示转换成位图处理，false表示不转换成位图处理。 |

### OH_Drawing_FontSetEdging()

```
void OH_Drawing_FontSetEdging(OH_Drawing_Font* font, OH_Drawing_FontEdging fontEdging)
```

**描述**

用于设置字型边缘效果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>fontEdging不在枚举范围内时返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| [OH_Drawing_FontEdging](#oh_drawing_fontedging) fontEdging | 字型边缘效果。 |

### OH_Drawing_FontGetEdging()

```
OH_Drawing_FontEdging OH_Drawing_FontGetEdging(const OH_Drawing_Font* font)
```

**描述**

获取字型边缘效果。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontEdging](#oh_drawing_fontedging) | 返回字型边缘效果。 |

### OH_Drawing_FontDestroy()

```
void OH_Drawing_FontDestroy(OH_Drawing_Font* font)
```

**描述**

用于销毁字型对象并回收该对象占有的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象的指针。 |

### OH_Drawing_FontGetMetrics()

```
float OH_Drawing_FontGetMetrics(OH_Drawing_Font* font, OH_Drawing_Font_Metrics* fontMetrics)
```

**描述**

获取字体度量信息。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>font、fontMetrics任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)* fontMetrics | 指向字体度量信息对象[OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 函数返回一个浮点数变量，表示建议的行间距。 |

### OH_Drawing_FontGetBounds()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetBounds(const OH_Drawing_Font* font, const uint16_t* glyphs, uint32_t count,OH_Drawing_Array* bounds)
```

**描述**

获取字型指定字形索引的矩形边界。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const uint16_t* glyphs | 字形索引数组。 |
| uint32_t count | 字形数组的长度。 |
| [OH_Drawing_Array](capi-drawing-oh-drawing-array.md)* bounds | 矩形边界数组。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font、glyphs或bounds为空，或者count为零。 |

### OH_Drawing_FontGetPathForGlyph()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetPathForGlyph(const OH_Drawing_Font* font, uint16_t glyph,OH_Drawing_Path* path)
```

**描述**

获取字型指定字形索引的轮廓。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| uint16_t glyph | 指定的字形索引。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 指向路径对象[OH_Drawing_Path](capi-drawing-oh-drawing-path.md)的指针, 用于存储得到的字形路径。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font或者path为空， 或者指定glyph不存在。 |

### OH_Drawing_FontGetTextPath()

```
OH_Drawing_ErrorCode OH_Drawing_FontGetTextPath(const OH_Drawing_Font* font, const void* text, size_t byteLength,OH_Drawing_TextEncoding encoding, float x, float y, OH_Drawing_Path* path)
```

**描述**

获取文字轮廓路径。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指示字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| const void* text | 指示要获取轮廓路径的文本字符串。 |
| size_t byteLength | 指示要获取对应文本路径的字节长度，如果此字节长度大于text字符串的字节长度，会发生未定义行为。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) encoding | 指示文本编码格式，支持 UTF-8、UTF-16、UTF-32，以及字形索引，具体类型格式可见[OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding)。 |
| float x | 指示文本在绘图区域内以原点为起始位置的X坐标。 |
| float y | 指示文本在绘图区域内以原点为起始位置的Y坐标。 |
| [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | 返回获取到的文字轮廓路径对象，作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 返回错误代码。<br> 如果操作成功，则返回 [OH_DRAWING_SUCCESS](capi-drawing-error-code-h.md#oh_drawing_errorcode)。<br> 如果 font、text 或 path 中的任何一个为空指针，则返回 [OH_DRAWING_ERROR_INVALID_PARAMETER](capi-drawing-error-code-h.md#oh_drawing_errorcode)。 |

### OH_Drawing_FontSetThemeFontFollowed()

```
OH_Drawing_ErrorCode OH_Drawing_FontSetThemeFontFollowed(OH_Drawing_Font* font, bool followed)
```

**描述**

设置字型中的字体是否跟随主题字体。设置跟随主题字体后，若系统启用主题字体并且字型未被设置字体，字型会使用该主题字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指示字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| bool followed | 字型中的字体是否跟随主题字体，true表示跟随主题字体，false表示不跟随主题字体。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font为空。 |

### OH_Drawing_FontIsThemeFontFollowed()

```
OH_Drawing_ErrorCode OH_Drawing_FontIsThemeFontFollowed(const OH_Drawing_Font* font, bool* followed)
```

**描述**

获取字型中的字体是否跟随主题字体。默认不跟随主题字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指示字型对象[OH_Drawing_Font](capi-drawing-oh-drawing-font.md)的指针。 |
| bool* followed | 返回字型中的字体是否跟随主题字体的结果，true表示跟随主题字体，false表示不跟随主题字体。作为出参使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_ErrorCode](capi-drawing-error-code-h.md#oh_drawing_errorcode) | 函数返回执行错误码。<br> 返回OH_DRAWING_SUCCESS，表示执行成功。<br> 返回OH_DRAWING_ERROR_INVALID_PARAMETER，表示参数font或者followed其中一个为空。 |


