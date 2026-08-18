# drawing_font_collection.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## 概述

定义绘制模块中与字体集相关的函数，用于管理文本排版所需的字体资源，支持创建独立的或可共享的字体集对象，满足不同场景下的文本排版需求。通过字体集对象，可实现自定义字体加载、系统字体管理、字体缓存清理等功能。

**引用文件：** <native_drawing/drawing_font_collection.h>

**库：** libnative_drawing.so

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection(void)](#oh_drawing_createfontcollection) | 创建字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)。 |
| [void OH_Drawing_DestroyFontCollection(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_destroyfontcollection) | 释放被字体集对象占据的内存。 |
| [void OH_Drawing_DisableFontCollectionFallback(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_disablefontcollectionfallback) | 禁用系统字体。 |
| [void OH_Drawing_DisableFontCollectionSystemFont(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_disablefontcollectionsystemfont) | 禁用系统字体。禁用后，该字体集对象仅能使用已注册的自定义字体进行文本渲染。 |
| [OH_Drawing_FontCollection* OH_Drawing_CreateSharedFontCollection(void)](#oh_drawing_createsharedfontcollection) | 创建可共享的字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)。 |
| [void OH_Drawing_ClearFontCaches(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_clearfontcaches) | 清理字体排版缓存（字体排版缓存本身设有内存上限和清理机制，所占内存有限，如无内存要求，不建议清理）。 |
| [OH_Drawing_FontCollection* OH_Drawing_GetFontCollectionGlobalInstance(void)](#oh_drawing_getfontcollectionglobalinstance) | 获取全局字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)，可获取主题字信息，禁止释放该对象。 |

## 函数说明

### OH_Drawing_CreateFontCollection()

```c
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection(void)
```

**描述**

创建字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | 指向创建的字体集对象的指针。该函数创建的字体集指针对象OH_Drawing_FontCollection只能被一个[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象使用，不支持多个OH_Drawing_TypographyCreate对象共享使用。如需在多个OH_Drawing_TypographyCreate对象间共享同一个OH_Drawing_FontCollection，请使用[OH_Drawing_CreateSharedFontCollection](capi-drawing-font-collection-h.md#oh_drawing_createsharedfontcollection)函数创建OH_Drawing_FontCollection对象。 |

### OH_Drawing_DestroyFontCollection()

```c
void OH_Drawing_DestroyFontCollection(OH_Drawing_FontCollection* fontCollection)
```

**描述**

释放被字体集对象占据的内存。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向字体集对象的指针。 |

### OH_Drawing_DisableFontCollectionFallback()

```c
void OH_Drawing_DisableFontCollectionFallback(OH_Drawing_FontCollection* fontCollection)
```

**描述**

禁用系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**废弃版本：** 18

**替代接口：** [OH_Drawing_DisableFontCollectionSystemFont()](#oh_drawing_disablefontcollectionsystemfont)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)的指针。 |

### OH_Drawing_DisableFontCollectionSystemFont()

```c
void OH_Drawing_DisableFontCollectionSystemFont(OH_Drawing_FontCollection* fontCollection)
```

**描述**

禁用系统字体。禁用后，该字体集对象仅能使用已注册的自定义字体进行文本渲染。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向需禁用系统字体的字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)的指针。 |

### OH_Drawing_CreateSharedFontCollection()

```c
OH_Drawing_FontCollection* OH_Drawing_CreateSharedFontCollection(void)
```

**描述**

创建可共享的字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | 指向创建的字体集对象的指针，可以被多个[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象使用。 |

### OH_Drawing_ClearFontCaches()

```c
void OH_Drawing_ClearFontCaches(OH_Drawing_FontCollection* fontCollection)
```

**描述**

清理字体排版缓存（字体排版缓存本身设有内存上限和清理机制，所占内存有限，如无内存要求，不建议清理）。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)的指针。 |

### OH_Drawing_GetFontCollectionGlobalInstance()

```c
OH_Drawing_FontCollection* OH_Drawing_GetFontCollectionGlobalInstance(void)
```

**描述**

获取全局字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)，可获取主题字信息，禁止释放该对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | 指向全局字体集对象的指针，可以被多个[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象使用，禁止释放。 |