# drawing_font_mgr.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## 概述

文件中定义了与字体管理相关的功能函数，用于加载和匹配系统中可用的字体。

**引用文件：** <native_drawing/drawing_font_mgr.h>

**库：** libnative_drawing.so

**起始版本：** 12

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_FontMgr* OH_Drawing_FontMgrCreate(void)](#oh_drawing_fontmgrcreate) | 创建字体管理对象，只支持管理系统字体。 |
| [void OH_Drawing_FontMgrDestroy(OH_Drawing_FontMgr* drawingFontMgr)](#oh_drawing_fontmgrdestroy) | 释放字体管理对象占用的内存。 |
| [int OH_Drawing_FontMgrGetFamilyCount(OH_Drawing_FontMgr* drawingFontMgr)](#oh_drawing_fontmgrgetfamilycount) | 获取字体家族的数量。 |
| [char* OH_Drawing_FontMgrGetFamilyName(OH_Drawing_FontMgr* drawingFontMgr, int index)](#oh_drawing_fontmgrgetfamilyname) | 由索引值获取字体家族名称。 |
| [void OH_Drawing_FontMgrDestroyFamilyName(char* familyName)](#oh_drawing_fontmgrdestroyfamilyname) | 释放指定字体家族名称占用的内存。 |
| [OH_Drawing_FontStyleSet* OH_Drawing_FontMgrCreateFontStyleSet(OH_Drawing_FontMgr* drawingFontMgr, int index)](#oh_drawing_fontmgrcreatefontstyleset) | 由字体管理对象构造字体样式集对象。 |
| [void OH_Drawing_FontMgrDestroyFontStyleSet(OH_Drawing_FontStyleSet* drawingFontStyleSet)](#oh_drawing_fontmgrdestroyfontstyleset) | 释放字体样式集对象占用的内存。 |
| [OH_Drawing_FontStyleSet* OH_Drawing_FontMgrMatchFamily(OH_Drawing_FontMgr* drawingFontMgr, const char* familyName)](#oh_drawing_fontmgrmatchfamily) | 由指定的字体家族名称，获取字体样式集对象。 |
| [OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyle(OH_Drawing_FontMgr* drawingFontMgr,const char* familyName, OH_Drawing_FontStyleStruct fontStyle)](#oh_drawing_fontmgrmatchfamilystyle) | 根据指定的字体样式信息和字体家族名称，获取字型对象。 |
| [OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyleCharacter(OH_Drawing_FontMgr* drawingFontMgr,const char* familyName, OH_Drawing_FontStyleStruct fontStyle,const char* bcp47[], int bcp47Count, int32_t character)](#oh_drawing_fontmgrmatchfamilystylecharacter) | 为指定字符获取字型对象，仅在传入字体管理对象中无法找到传入UTF8字符值对应的字型对象时返回空指针。 |
| [OH_Drawing_Typeface* OH_Drawing_FontStyleSetCreateTypeface(OH_Drawing_FontStyleSet* fontStyleSet, int index)](#oh_drawing_fontstylesetcreatetypeface) | 为指定索引获取字型对象。 |
| [OH_Drawing_FontStyleStruct OH_Drawing_FontStyleSetGetStyle(OH_Drawing_FontStyleSet* fontStyleSet, int32_t index,char** styleName)](#oh_drawing_fontstylesetgetstyle) | 获取字体样式。 |
| [void OH_Drawing_FontStyleSetFreeStyleName(char** styleName)](#oh_drawing_fontstylesetfreestylename) | 释放指定字体样式的内存。 |
| [OH_Drawing_Typeface* OH_Drawing_FontStyleSetMatchStyle(OH_Drawing_FontStyleSet* fontStyleSet,OH_Drawing_FontStyleStruct fontStyleStruct)](#oh_drawing_fontstylesetmatchstyle) | 获取最接近字体样式的字型对象。 |
| [int OH_Drawing_FontStyleSetCount(OH_Drawing_FontStyleSet* fontStyleSet)](#oh_drawing_fontstylesetcount) | 获取字体样式集中字体的个数。 |

## 函数说明

### OH_Drawing_FontMgrCreate()

```
OH_Drawing_FontMgr* OH_Drawing_FontMgrCreate(void)
```

**描述**

创建字体管理对象，只支持管理系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* | 返回指向已创建的字体管理对象[OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)的指针。 |

### OH_Drawing_FontMgrDestroy()

```
void OH_Drawing_FontMgrDestroy(OH_Drawing_FontMgr* drawingFontMgr)
```

**描述**

释放字体管理对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | 指向字体管理对象[OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)的指针，由[OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate)获取。 |

### OH_Drawing_FontMgrGetFamilyCount()

```
int OH_Drawing_FontMgrGetFamilyCount(OH_Drawing_FontMgr* drawingFontMgr)
```

**描述**

获取字体家族的数量。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | 指向字体管理对象[OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)的指针，由[OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate)获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回字体家族的数量。 |

### OH_Drawing_FontMgrGetFamilyName()

```
char* OH_Drawing_FontMgrGetFamilyName(OH_Drawing_FontMgr* drawingFontMgr, int index)
```

**描述**

由索引值获取字体家族名称。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | 指向字体管理对象[OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)的指针，由[OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate)获取。 |
| int index | 用于获取对应字体家族名称的索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| char* | 返回索引值对应的字体家族名称，不再需要时，请使用[OH_Drawing_FontMgrDestroyFamilyName](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrdestroyfamilyname)释放该对象指针。 |

### OH_Drawing_FontMgrDestroyFamilyName()

```
void OH_Drawing_FontMgrDestroyFamilyName(char* familyName)
```

**描述**

释放指定字体家族名称占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char* familyName | 指定字体家族名称数组。 |

### OH_Drawing_FontMgrCreateFontStyleSet()

```
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrCreateFontStyleSet(OH_Drawing_FontMgr* drawingFontMgr, int index)
```

**描述**

由字体管理对象构造字体样式集对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | 指向字体管理对象[OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)的指针，由[OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate)获取。 |
| int index | 用于从字体管理对象获取字体样式集对象的索引值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* | 返回指向已创建的字体样式集对象[OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)的指针。 |

### OH_Drawing_FontMgrDestroyFontStyleSet()

```
void OH_Drawing_FontMgrDestroyFontStyleSet(OH_Drawing_FontStyleSet* drawingFontStyleSet)
```

**描述**

释放字体样式集对象占用的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* drawingFontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)的指针。 |

### OH_Drawing_FontMgrMatchFamily()

```
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrMatchFamily(OH_Drawing_FontMgr* drawingFontMgr, const char* familyName)
```

**描述**

由指定的字体家族名称，获取字体样式集对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | 指向字体管理对象[OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)的指针，由[OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate)获取。 |
| const char* familyName | 指定的字体家族名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* | 返回对应的字体样式集对象[OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)，不再需要时，请使用[OH_Drawing_FontMgrDestroyFontStyleSet](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrdestroyfontstyleset)释放该对象指针。 |

### OH_Drawing_FontMgrMatchFamilyStyle()

```
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyle(OH_Drawing_FontMgr* drawingFontMgr,const char* familyName, OH_Drawing_FontStyleStruct fontStyle)
```

**描述**

根据指定的字体样式信息和字体家族名称，获取字型对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | 指向字体管理对象[OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)的指针，由[OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate)获取。 |
| const char* familyName | 指定的字体家族名称。 |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyle | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | 返回对应的字体样式的字型对象[OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)，不再需要时，请使用[OH_Drawing_TypefaceDestroy](capi-drawing-typeface-h.md#oh_drawing_typefacedestroy)释放该对象指针。 |

### OH_Drawing_FontMgrMatchFamilyStyleCharacter()

```
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyleCharacter(OH_Drawing_FontMgr* drawingFontMgr,const char* familyName, OH_Drawing_FontStyleStruct fontStyle,const char* bcp47[], int bcp47Count, int32_t character)
```

**描述**

为指定字符获取字型对象，仅在传入字体管理对象中无法找到传入UTF8字符值对应的字型对象时返回空指针。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | 指向字体管理对象[OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)的指针，由[OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate)获取。 |
| const char* familyName | 指定的字体家族名称。 |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyle | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 |
| bcp47 |  用来指示character语言编码数组，是ISO 639、15924和3166-1语言编码的组合。 |
| int bcp47Count | 参数bcp47数组大小。 |
| int32_t character | 待匹配的UTF8字符值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | 返回对应的字型对象[OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)。 |

### OH_Drawing_FontStyleSetCreateTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontStyleSetCreateTypeface(OH_Drawing_FontStyleSet* fontStyleSet, int index)
```

**描述**

为指定索引获取字型对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* fontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)的指针。 |
| int index | 指定的字型对象的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | 如果成功，返回对应的字型对象[OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md); 如果失败，返回nullptr。 |

### OH_Drawing_FontStyleSetGetStyle()

```
OH_Drawing_FontStyleStruct OH_Drawing_FontStyleSetGetStyle(OH_Drawing_FontStyleSet* fontStyleSet, int32_t index,char** styleName)
```

**描述**

获取字体样式。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* fontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)的指针。 |
| int32_t index | 指定的字体样式的索引。 |
| char** styleName | 指定字体样式名称的字符串。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) | 返回对应的字体样式。 |

### OH_Drawing_FontStyleSetFreeStyleName()

```
void OH_Drawing_FontStyleSetFreeStyleName(char** styleName)
```

**描述**

释放指定字体样式的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char** styleName | 指定字体样式名称的字符串。 |

### OH_Drawing_FontStyleSetMatchStyle()

```
OH_Drawing_Typeface* OH_Drawing_FontStyleSetMatchStyle(OH_Drawing_FontStyleSet* fontStyleSet,OH_Drawing_FontStyleStruct fontStyleStruct)
```

**描述**

获取最接近字体样式的字型对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* fontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)的指针。 |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyleStruct | 字体样式对象，包括字体字重、字体宽度和字体斜度信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | 返回对应的字型对象[OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)。 |

### OH_Drawing_FontStyleSetCount()

```
int OH_Drawing_FontStyleSetCount(OH_Drawing_FontStyleSet* fontStyleSet)
```

**描述**

获取字体样式集中字体的个数。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* fontStyleSet | 指向字体样式集对象[OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | 返回此字体样式集中字体的个数。 |