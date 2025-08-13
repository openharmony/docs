# drawing_font_collection.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk;@gmiao522;@Lem0nC-->
<!--SE: @liumingxiang-->
<!--TSE: @yhl0101-->
## 概述

定义绘制模块中与字体集合相关的函数。

**引用文件：** <native_drawing/drawing_font_collection.h>

**库：** libnative_drawing.so

**起始版本：** 8

**相关模块：** [Drawing](capi-drawing.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection(void)](#oh_drawing_createfontcollection) | 创建字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)。 |
| [void OH_Drawing_DestroyFontCollection(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_destroyfontcollection) | 释放被字体集对象占据的内存。 |
| [void OH_Drawing_DisableFontCollectionFallback(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_disablefontcollectionfallback) | 禁用系统字体。 |
| [void OH_Drawing_DisableFontCollectionSystemFont(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_disablefontcollectionsystemfont) | 禁用系统字体。 |
| [OH_Drawing_FontCollection* OH_Drawing_CreateSharedFontCollection(void)](#oh_drawing_createsharedfontcollection) | 创建可共享的字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)。 |
| [void OH_Drawing_ClearFontCaches(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_clearfontcaches) | 清理字体排版缓存（字体排版缓存本身设有内存上限和清理机制，所占内存有限，如无内存要求，不建议清理）。 |
| [OH_Drawing_FontCollection* OH_Drawing_GetFontCollectionGlobalInstance(void)](#oh_drawing_getfontcollectionglobalinstance) | 获取全局字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)，可感知主题字信息，禁止释放该对象。 |

## 函数说明

### OH_Drawing_CreateFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection(void)
```

**描述**

创建字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 8

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | 指向创建的字体集对象的指针。该函数创建的字体集指针对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)只能被一个[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象使用，无法被多个[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象共享使用。如需在多个[OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)对象间共享同一个[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)，请使用[OH_Drawing_CreateSharedFontCollection](capi-drawing-font-collection-h.md#oh_drawing_createsharedfontcollection)函数创建[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)对象。 |

### OH_Drawing_DestroyFontCollection()

```
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

```
void OH_Drawing_DisableFontCollectionFallback(OH_Drawing_FontCollection* fontCollection)
```

**描述**

禁用系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)的指针。 |

### OH_Drawing_DisableFontCollectionSystemFont()

```
void OH_Drawing_DisableFontCollectionSystemFont(OH_Drawing_FontCollection* fontCollection)
```

**描述**

禁用系统字体。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | 指向字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)的指针。 |

### OH_Drawing_CreateSharedFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateSharedFontCollection(void)
```

**描述**

创建可共享的字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | 指向创建的字体集对象的指针。 |

### OH_Drawing_ClearFontCaches()

```
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

```
OH_Drawing_FontCollection* OH_Drawing_GetFontCollectionGlobalInstance(void)
```

**描述**

获取全局字体集对象[OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)，可感知主题字信息，禁止释放该对象。

**系统能力：** SystemCapability.Graphic.Graphic2D.NativeDrawing

**起始版本：** 14

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | 指向全局字体集对象的指针。 |