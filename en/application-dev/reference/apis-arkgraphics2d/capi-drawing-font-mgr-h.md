# drawing_font_mgr.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

The **drawing_font_mgr.h** file declares the functions related to font management in the drawing module. The functions can be used to load fonts and match available fonts in the system.

**Header file**: <native_drawing/drawing_font_mgr.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_FontMgr* OH_Drawing_FontMgrCreate(void)](#oh_drawing_fontmgrcreate) | Creates an **OH_Drawing_FontMgr** object, which can be used only to manage system fonts.|
| [void OH_Drawing_FontMgrDestroy(OH_Drawing_FontMgr* drawingFontMgr)](#oh_drawing_fontmgrdestroy) | Destroys an **OH_Drawing_FontMgr** object and reclaims the memory occupied by the object.|
| [int OH_Drawing_FontMgrGetFamilyCount(OH_Drawing_FontMgr* drawingFontMgr)](#oh_drawing_fontmgrgetfamilycount) | Obtains the number of font families.|
| [char* OH_Drawing_FontMgrGetFamilyName(OH_Drawing_FontMgr* drawingFontMgr, int index)](#oh_drawing_fontmgrgetfamilyname) | Obtains the font family name based on an index.|
| [void OH_Drawing_FontMgrDestroyFamilyName(char* familyName)](#oh_drawing_fontmgrdestroyfamilyname) | Reclaims the memory occupied by a font family name.|
| [OH_Drawing_FontStyleSet* OH_Drawing_FontMgrCreateFontStyleSet(OH_Drawing_FontMgr* drawingFontMgr, int index)](#oh_drawing_fontmgrcreatefontstyleset) | Creates a font style set from an **OH_Drawing_FontMgr** object.|
| [void OH_Drawing_FontMgrDestroyFontStyleSet(OH_Drawing_FontStyleSet* drawingFontStyleSet)](#oh_drawing_fontmgrdestroyfontstyleset) | Reclaims the memory occupied by a font style set.|
| [OH_Drawing_FontStyleSet* OH_Drawing_FontMgrMatchFamily(OH_Drawing_FontMgr* drawingFontMgr, const char* familyName)](#oh_drawing_fontmgrmatchfamily) | Obtains a font style set based on a font family name.|
| [OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyle(OH_Drawing_FontMgr* drawingFontMgr,const char* familyName, OH_Drawing_FontStyleStruct fontStyle)](#oh_drawing_fontmgrmatchfamilystyle) | Obtains a typeface based on the font style information and font family name.|
| [OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyleCharacter(OH_Drawing_FontMgr* drawingFontMgr,const char* familyName, OH_Drawing_FontStyleStruct fontStyle,const char* bcp47[], int bcp47Count, int32_t character)](#oh_drawing_fontmgrmatchfamilystylecharacter) | Obtains a typeface for the specified character. A null pointer is returned only when no typeface corresponding to the input UTF-8 character is found in the **OH_Drawing_FontMgr** object.|
| [OH_Drawing_Typeface* OH_Drawing_FontStyleSetCreateTypeface(OH_Drawing_FontStyleSet* fontStyleSet, int index)](#oh_drawing_fontstylesetcreatetypeface) | Creates a typeface for the specified index.|
| [OH_Drawing_FontStyleStruct OH_Drawing_FontStyleSetGetStyle(OH_Drawing_FontStyleSet* fontStyleSet, int32_t index,char** styleName)](#oh_drawing_fontstylesetgetstyle) | Obtains the font style. The styleName will apply for memory. If the styleName is no longer needed, use [OH_Drawing_FontStyleSetFreeStyleName](#oh_drawing_fontstylesetfreestylename) to release the object pointer.|
| [void OH_Drawing_FontStyleSetFreeStyleName(char** styleName)](#oh_drawing_fontstylesetfreestylename) | Releases the memory of a specified font style name.|
| [OH_Drawing_Typeface* OH_Drawing_FontStyleSetMatchStyle(OH_Drawing_FontStyleSet* fontStyleSet,OH_Drawing_FontStyleStruct fontStyleStruct)](#oh_drawing_fontstylesetmatchstyle) | Obtains the typeface closest to the font style.|
| [int OH_Drawing_FontStyleSetCount(OH_Drawing_FontStyleSet* fontStyleSet)](#oh_drawing_fontstylesetcount) | Obtains the number of fonts in the font style set.|

## Function Description

### OH_Drawing_FontMgrCreate()

```
OH_Drawing_FontMgr* OH_Drawing_FontMgrCreate(void)
```

**Description**

Creates an **OH_Drawing_FontMgr** object, which can be used only to manage system fonts.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* | Pointer to the created font manager object [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md).|

### OH_Drawing_FontMgrDestroy()

```
void OH_Drawing_FontMgrDestroy(OH_Drawing_FontMgr* drawingFontMgr)
```

**Description**

Destroys an **OH_Drawing_FontMgr** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | Pointer to the font manager object [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md), which is obtained from [OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate).|

### OH_Drawing_FontMgrGetFamilyCount()

```
int OH_Drawing_FontMgrGetFamilyCount(OH_Drawing_FontMgr* drawingFontMgr)
```

**Description**

Obtains the number of font families.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | Pointer to the font management object [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md), which is obtained from [OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate).|

**Return value**

| Type| Description|
| -- | -- |
| int | Number of font families.|

### OH_Drawing_FontMgrGetFamilyName()

```
char* OH_Drawing_FontMgrGetFamilyName(OH_Drawing_FontMgr* drawingFontMgr, int index)
```

**Description**

Obtains the font family name based on an index.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | Pointer to the font management object [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md), which is obtained from [OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate).|
| int index | Index of the font family name.|

**Return value**

| Type| Description|
| -- | -- |
| char* | Name of the font family corresponding to the index. If the returned value is no longer needed, use [OH_Drawing_FontMgrDestroyFamilyName](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrdestroyfamilyname) to release the object pointer.|

### OH_Drawing_FontMgrDestroyFamilyName()

```
void OH_Drawing_FontMgrDestroyFamilyName(char* familyName)
```

**Description**

Reclaims the memory occupied by a font family name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char* familyName | Pointer to a font family name.|

### OH_Drawing_FontMgrCreateFontStyleSet()

```
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrCreateFontStyleSet(OH_Drawing_FontMgr* drawingFontMgr, int index)
```

**Description**

Creates a font style set from an **OH_Drawing_FontMgr** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | Pointer to the font manager object [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md), which is obtained from [OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate).|
| int index | Index of the font style set.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* | Pointer to the created font style set object [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md).|

### OH_Drawing_FontMgrDestroyFontStyleSet()

```
void OH_Drawing_FontMgrDestroyFontStyleSet(OH_Drawing_FontStyleSet* drawingFontStyleSet)
```

**Description**

Reclaims the memory occupied by a font style set.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* drawingFontStyleSet | Pointer to the font style set object [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md).|

### OH_Drawing_FontMgrMatchFamily()

```
OH_Drawing_FontStyleSet* OH_Drawing_FontMgrMatchFamily(OH_Drawing_FontMgr* drawingFontMgr, const char* familyName)
```

**Description**

Obtains a font style set based on a font family name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | Pointer to the font management object [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md), which is obtained from [OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate).|
| const char* familyName | Pointer to a font family name.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* | Returns the font style set object [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md). Use [OH_Drawing_FontMgrDestroyFontStyleSet](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrdestroyfontstyleset) to release the object pointer when it is no longer needed.|

### OH_Drawing_FontMgrMatchFamilyStyle()

```
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyle(OH_Drawing_FontMgr* drawingFontMgr,const char* familyName, OH_Drawing_FontStyleStruct fontStyle)
```

**Description**

Obtains a typeface based on the font style information and font family name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | Pointer to the font management object [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md), which is obtained from [OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate).|
| const char* familyName | Pointer to a font family name.|
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyle | Font style, including the font weight, width, and slant.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | Returns the font object [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md) of the corresponding font style. Use [OH_Drawing_TypefaceDestroy](capi-drawing-typeface-h.md#oh_drawing_typefacedestroy) to release the object pointer when it is no longer needed.|

### OH_Drawing_FontMgrMatchFamilyStyleCharacter()

```
OH_Drawing_Typeface* OH_Drawing_FontMgrMatchFamilyStyleCharacter(OH_Drawing_FontMgr* drawingFontMgr,const char* familyName, OH_Drawing_FontStyleStruct fontStyle,const char* bcp47[], int bcp47Count, int32_t character)
```

**Description**

Obtains a typeface for the specified character. A null pointer is returned only when no typeface corresponding to the input UTF-8 character is found in the **OH_Drawing_FontMgr** object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md)* drawingFontMgr | Pointer to the font manager object [OH_Drawing_FontMgr](capi-drawing-oh-drawing-fontmgr.md), which is obtained from [OH_Drawing_FontMgrCreate](capi-drawing-font-mgr-h.md#oh_drawing_fontmgrcreate).|
| const char* familyName | Pointer to a font family name.|
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyle | Font style, including the font weight, width, and slant.|
| bcp47 |  It indicates the character language code array, which is a combination of ISO 639, 15924, and 3166-1 language codes.|
| int bcp47Count | Size of the character language code array.|
| int32_t character | UTF8 character used for matching.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | The corresponding font object [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md).|

### OH_Drawing_FontStyleSetCreateTypeface()

```
OH_Drawing_Typeface* OH_Drawing_FontStyleSetCreateTypeface(OH_Drawing_FontStyleSet* fontStyleSet, int index)
```

**Description**

Creates a typeface for the specified index.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* fontStyleSet | Pointer to the font style set object [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md).|
| int index | Index of the typeface.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md); if the operation is successful; null if the operation fails.|

### OH_Drawing_FontStyleSetGetStyle()

```
OH_Drawing_FontStyleStruct OH_Drawing_FontStyleSetGetStyle(OH_Drawing_FontStyleSet* fontStyleSet, int32_t index,char** styleName)
```

**Description**

Obtains the font style. The memory is allocated to styleName. If styleName is no longer needed, use [OH_Drawing_FontStyleSetFreeStyleName](#oh_drawing_fontstylesetfreestylename) to release the object pointer.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* fontStyleSet | Pointer to the font style set object [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md).|
| int32_t index | Index of the font style.|
| char** styleName | String of the specified font style name. The memory is allocated. If the string is no longer needed, use [OH_Drawing_FontStyleSetFreeStyleName](#oh_drawing_fontstylesetfreestylename) to release the object pointer.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) | Font style.|

### OH_Drawing_FontStyleSetFreeStyleName()

```
void OH_Drawing_FontStyleSetFreeStyleName(char** styleName)
```

**Description**

Releases the memory of a specified font style name.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char** styleName | Double pointer to the string that specifies the font style name.|

### OH_Drawing_FontStyleSetMatchStyle()

```
OH_Drawing_Typeface* OH_Drawing_FontStyleSetMatchStyle(OH_Drawing_FontStyleSet* fontStyleSet,OH_Drawing_FontStyleStruct fontStyleStruct)
```

**Description**

Obtains the typeface closest to the font style.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* fontStyleSet | Pointer to the font style set object [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md).|
| [OH_Drawing_FontStyleStruct](capi-drawing-oh-drawing-fontstylestruct.md) fontStyleStruct | Font style, including the font weight, width, and slant.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md)* | Font object [OH_Drawing_Typeface](capi-drawing-oh-drawing-typeface.md) that is closest to the font style.|

### OH_Drawing_FontStyleSetCount()

```
int OH_Drawing_FontStyleSetCount(OH_Drawing_FontStyleSet* fontStyleSet)
```

**Description**

Obtains the number of fonts in the font style set.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md)* fontStyleSet | Pointer to the font style set object [OH_Drawing_FontStyleSet](capi-drawing-oh-drawing-fontstyleset.md).|

**Return value**

| Type| Description|
| -- | -- |
| int | The number of fonts in the font style set.|
