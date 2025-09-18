# drawing_font_collection.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

The **drawing_font_collection.h** file declares the functions related to the font collection in the drawing module.

**File to import**: <native_drawing/drawing_font_collection.h>

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection(void)](#oh_drawing_createfontcollection) | Creates a font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md).|
| [void OH_Drawing_DestroyFontCollection(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_destroyfontcollection) | Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object.|
| [void OH_Drawing_DisableFontCollectionFallback(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_disablefontcollectionfallback) | Disables the system fonts.|
| [void OH_Drawing_DisableFontCollectionSystemFont(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_disablefontcollectionsystemfont) | Disables the system fonts.|
| [OH_Drawing_FontCollection* OH_Drawing_CreateSharedFontCollection(void)](#oh_drawing_createsharedfontcollection) | Creates a shared font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md).|
| [void OH_Drawing_ClearFontCaches(OH_Drawing_FontCollection* fontCollection)](#oh_drawing_clearfontcaches) | Clears the font layout cache. (The font layout cache has a memory upper limit and a clearing mechanism. The memory occupied by the font layout cache is limited. If no memory is required, clearing the font layout cache is not recommended.)|
| [OH_Drawing_FontCollection* OH_Drawing_GetFontCollectionGlobalInstance(void)](#oh_drawing_getfontcollectionglobalinstance) | Obtains the global font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md), which can detect theme information. Do not release this object.|

## Function Description

### OH_Drawing_CreateFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection(void)
```

**Description**

Creates a font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | Returns the pointer to the **OH_Drawing_FontCollection** object created. The font set pointer object OH_Drawing_FontCollection created by this function can be used by only one [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object and cannot be shared by multiple OH_Drawing_TypographyCreate objects. If you need to share the same OH_Drawing_FontCollection object among multiple OH_Drawing_TypographyCreate objects, use the [OH_Drawing_CreateSharedFontCollection](capi-drawing-font-collection-h.md#oh_drawing_createsharedfontcollection) function to create the OH_Drawing_FontCollection object.|

### OH_Drawing_DestroyFontCollection()

```
void OH_Drawing_DestroyFontCollection(OH_Drawing_FontCollection* fontCollection)
```

**Description**

Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | Pointer to an **OH_Drawing_FontCollection** object.|

### OH_Drawing_DisableFontCollectionFallback()

```
void OH_Drawing_DisableFontCollectionFallback(OH_Drawing_FontCollection* fontCollection)
```

**Description**

Disables the system fonts.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | Pointer to the font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md).|

### OH_Drawing_DisableFontCollectionSystemFont()

```
void OH_Drawing_DisableFontCollectionSystemFont(OH_Drawing_FontCollection* fontCollection)
```

**Description**

Disables the system fonts.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | Pointer to the font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md).|

### OH_Drawing_CreateSharedFontCollection()

```
OH_Drawing_FontCollection* OH_Drawing_CreateSharedFontCollection(void)
```

**Description**

Creates a sharable font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | Pointer to the created font set object.|

### OH_Drawing_ClearFontCaches()

```
void OH_Drawing_ClearFontCaches(OH_Drawing_FontCollection* fontCollection)
```

**Description**

Clears the font cache. (The font cache has a memory limit and a clearing mechanism. It occupies limited memory. You are not advised to clear it unless otherwise required.)

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | Pointer to the font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md).|

### OH_Drawing_GetFontCollectionGlobalInstance()

```
OH_Drawing_FontCollection* OH_Drawing_GetFontCollectionGlobalInstance(void)
```

**Description**

Obtains the global font set object [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md), which can detect theme information. Do not release this object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 14

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | Pointer to the global font set object.|
