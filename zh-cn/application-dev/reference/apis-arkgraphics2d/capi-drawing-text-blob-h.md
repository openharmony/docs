# drawing_text_blob.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @dreamyhhh-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## 概述
文件中定义了与文字相关的功能函数。<br>本模块为单线程模型策略，需要调用方自行管理线程安全和上下文状态的切换。

**引用文件：** <native_drawing/drawing_text_blob.h>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Drawing_RunBuffer](capi-drawing-oh-drawing-runbuffer.md) | OH_Drawing_RunBuffer | 结构体用于描述一块内存，该内存用于存储文字和位置信息。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_TextBlobBuilder* OH_Drawing_TextBlobBuilderCreate(void)](#oh_drawing_textblobbuildercreate) | 用于创建一个文本构造器对象。 |
| [OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromText(const void* text, size_t byteLength,const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)](#oh_drawing_textblobcreatefromtext) | 使用文本创建一个文本对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>text、font任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>textEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromPosText(const void* text, size_t byteLength,OH_Drawing_Point2D* point2D, const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)](#oh_drawing_textblobcreatefrompostext) | 使用文本创建文本对象，文本对象中每个字符的坐标由OH_Drawing_Point2D数组中对应的坐标信息决定。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>text、point2D、font任意一个为NULL或byteLength等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>textEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromString(const char* str,const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)](#oh_drawing_textblobcreatefromstring) | 使用字符串创建文本对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>str、font任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>textEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。 |
| [void OH_Drawing_TextBlobGetBounds(OH_Drawing_TextBlob* textBlob, OH_Drawing_Rect* rect)](#oh_drawing_textblobgetbounds) | 获取文本对象的边界范围。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>textBlob、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [uint32_t OH_Drawing_TextBlobUniqueID(const OH_Drawing_TextBlob* textBlob)](#oh_drawing_textblobuniqueid) | 获取文本的标识符，该标识符是唯一的非零值。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>textBlob为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos(OH_Drawing_TextBlobBuilder* textBlobBuilder,const OH_Drawing_Font* font, int32_t count, const OH_Drawing_Rect* rect)](#oh_drawing_textblobbuilderallocrunpos) | 申请一块内存，用于存储文字和位置信息。返回的指针无需调用者管理，当调用[OH_Drawing_TextBlobBuilderMake](capi-drawing-text-blob-h.md#oh_drawing_textblobbuildermake)后禁止使用。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>textBlobBuilder、font任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake(OH_Drawing_TextBlobBuilder* textBlobBuilder)](#oh_drawing_textblobbuildermake) | 用于从文本构造器中创建文本对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>textBlobBuilder为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。 |
| [void OH_Drawing_TextBlobDestroy(OH_Drawing_TextBlob* textBlob)](#oh_drawing_textblobdestroy) | 用于销毁文本对象并回收该对象占用的内存。 |
| [void OH_Drawing_TextBlobBuilderDestroy(OH_Drawing_TextBlobBuilder* textBlobBuilder)](#oh_drawing_textblobbuilderdestroy) | 用于销毁文本构造器对象并回收该对象占用的内存。 |

## 函数说明

### OH_Drawing_TextBlobBuilderCreate()

```c
OH_Drawing_TextBlobBuilder* OH_Drawing_TextBlobBuilderCreate(void)
```

**描述**

用于创建一个文本构造器对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md)* | 函数返回一个指针，指针指向创建的文本构造器对象。 |

### OH_Drawing_TextBlobCreateFromText()

```c
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromText(const void* text, size_t byteLength, const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)
```

**描述**

使用文本创建一个文本对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>text、font任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>textEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const void* text | 指向文本的指针。 |
| size_t byteLength | 文本的字节长度。 |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字体对象OH_Drawing_Font的指针。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) textEncoding | 文本编码类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* | 函数返回一个指针，指针指向创建的文本对象OH_Drawing_TextBlob。 |

### OH_Drawing_TextBlobCreateFromPosText()

```c
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromPosText(const void* text, size_t byteLength, OH_Drawing_Point2D* point2D, const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)
```

**描述**

使用文本创建文本对象，文本对象中每个字符的坐标由OH_Drawing_Point2D数组中对应的坐标信息决定。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>text、point2D、font任意一个为NULL或byteLength等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>textEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const void* text | 指向文本的指针。 |
| size_t byteLength | 文本的字节长度。 |
| [OH_Drawing_Point2D](capi-drawing-oh-drawing-point2d.md)* point2D | 二维点OH_Drawing_Point2D数组首地址，数组个数由[OH_Drawing_FontCountText](capi-drawing-font-h.md#oh_drawing_fontcounttext)的计算结果决定。 |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字体对象OH_Drawing_Font的指针。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) textEncoding | 文本编码类型OH_Drawing_TextEncoding。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* | 函数返回一个指针，指针指向创建的文本对象OH_Drawing_TextBlob。 |

### OH_Drawing_TextBlobCreateFromString()

```c
OH_Drawing_TextBlob* OH_Drawing_TextBlobCreateFromString(const char* str, const OH_Drawing_Font* font, OH_Drawing_TextEncoding textEncoding)
```

**描述**

使用字符串创建文本对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>str、font任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER；<br>textEncoding不在枚举范围内返回OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* str | 指向字符串的指针。 |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字体对象OH_Drawing_Font的指针。 |
| [OH_Drawing_TextEncoding](capi-drawing-types-h.md#oh_drawing_textencoding) textEncoding | 文本编码类型OH_Drawing_TextEncoding。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* | 函数返回一个指针，指针指向创建的文本对象OH_Drawing_TextBlob。 |

### OH_Drawing_TextBlobGetBounds()

```c
void OH_Drawing_TextBlobGetBounds(OH_Drawing_TextBlob* textBlob, OH_Drawing_Rect* rect)
```

**描述**

获取文本对象的边界范围。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>textBlob、rect任意一个为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* textBlob | 指向文本对象OH_Drawing_TextBlob的指针。 |
| [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 指向矩形对象OH_Drawing_Rect的指针，开发者可调用OH_Drawing_Rect接口创建。 |

### OH_Drawing_TextBlobUniqueID()

```c
uint32_t OH_Drawing_TextBlobUniqueID(const OH_Drawing_TextBlob* textBlob)
```

**描述**

获取文本的标识符，该标识符是唯一的非零值。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>textBlob为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* textBlob | 指向文本对象OH_Drawing_TextBlob的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| uint32_t | 返回文本对象的标识符。 |

### OH_Drawing_TextBlobBuilderAllocRunPos()

```c
const OH_Drawing_RunBuffer* OH_Drawing_TextBlobBuilderAllocRunPos(OH_Drawing_TextBlobBuilder* textBlobBuilder, const OH_Drawing_Font* font, int32_t count, const OH_Drawing_Rect* rect)
```

**描述**

申请一块内存，用于存储文字和位置信息。返回的指针无需调用者管理，当调用[OH_Drawing_TextBlobBuilderMake](capi-drawing-text-blob-h.md#oh_drawing_textblobbuildermake)后禁止使用。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>textBlobBuilder、font任意一个为NULL或者count小于等于0时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md)* textBlobBuilder | 指向文本构造器对象的指针。 |
| const [OH_Drawing_Font](capi-drawing-oh-drawing-font.md)* font | 指向字体对象OH_Drawing_Font的指针。 |
| int32_t count | 文字的数量。 |
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | 文本的边界框，为NULL表示不设置边界框。 |

### OH_Drawing_TextBlobBuilderMake()

```c
OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake(OH_Drawing_TextBlobBuilder* textBlobBuilder)
```

**描述**

用于从文本构造器中创建文本对象。<br>本接口会产生错误码，可以通过[OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget)查看错误码的取值。<br>textBlobBuilder为NULL时返回OH_DRAWING_ERROR_INVALID_PARAMETER。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md)* textBlobBuilder | 指向文本构造器对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* | 函数返回一个指针，指针指向创建的文本对象OH_Drawing_TextBlob。 |

### OH_Drawing_TextBlobDestroy()

```c
void OH_Drawing_TextBlobDestroy(OH_Drawing_TextBlob* textBlob)
```

**描述**

用于销毁文本对象并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBlob](capi-drawing-oh-drawing-textblob.md)* textBlob | 指向文本对象OH_Drawing_TextBlob的指针。 |

### OH_Drawing_TextBlobBuilderDestroy()

```c
void OH_Drawing_TextBlobBuilderDestroy(OH_Drawing_TextBlobBuilder* textBlobBuilder)
```

**描述**

用于销毁文本构造器对象并回收该对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_TextBlobBuilder](capi-drawing-oh-drawing-textblobbuilder.md)* textBlobBuilder | 指向文本构造器对象的指针。 |


