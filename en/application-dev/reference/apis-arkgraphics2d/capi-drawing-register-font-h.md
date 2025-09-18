# drawing_register_font.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

The **drawing_register_font.h** file declares the functions related to the font manager in the drawing module.

**File to import**: <native_drawing/drawing_register_font.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [uint32_t OH_Drawing_RegisterFont(OH_Drawing_FontCollection*, const char* fontFamily, const char* familySrc)](#oh_drawing_registerfont) | Registers a custom font with the font manager. The supported font file formats are .ttf and .otf.|
| [uint32_t OH_Drawing_RegisterFontBuffer(OH_Drawing_FontCollection*, const char* fontFamily, uint8_t* fontBuffer,size_t length)](#oh_drawing_registerfontbuffer) | Registers a font buffer in the font manager.|
| [uint32_t OH_Drawing_UnregisterFont(OH_Drawing_FontCollection* fontCollection, const char* fontFamily)](#oh_drawing_unregisterfont) | Unregisters custom fonts by font family name.<br> Unregistering the font in use may cause text rendering exceptions, including garbled characters or missing glyphs.<br> All text objects using the font family name that has been unregistered must be destroyed and recreated.|

## Function Description

### OH_Drawing_RegisterFont()

```
uint32_t OH_Drawing_RegisterFont(OH_Drawing_FontCollection*, const char* fontFamily, const char* familySrc)
```

**Description**

Registers a custom font with the font manager. The supported font file formats are .ttf and .otf.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* | Pointer to the [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md) object.|
| const char* fontFamily | Pointer to the family name of the font to register.|
| const char* familySrc | Pointer to the path of the font file.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | An error code. 0: success; 1: file not found; 2: file opening failure; 3: file reading failure; 4: file search failure; 5: file size obtaining failure; 9: file damage.|

### OH_Drawing_RegisterFontBuffer()

```
uint32_t OH_Drawing_RegisterFontBuffer(OH_Drawing_FontCollection*, const char* fontFamily, uint8_t* fontBuffer,size_t length)
```

**Description**

Registers a font buffer with the font manager.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* |  Pointer to the [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md) object.|
| const char* fontFamily | Pointer to the family name of the font to register.|
| uint8_t* fontBuffer | Pointer to the buffer of the font file.|
| size_t length | Length of the font file.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Result code. 0: success; 6: The buffer size is 0. 7: The font set is empty. 9: The file is damaged.|

### OH_Drawing_UnregisterFont()

```
uint32_t OH_Drawing_UnregisterFont(OH_Drawing_FontCollection* fontCollection, const char* fontFamily)
```

**Description**

Cancels the registration of a custom font by font family name.

Canceling the registration of a font that is being used may cause text rendering exceptions, including garbled characters or missing glyphs.

All layout objects using the font family name that is canceled must be destroyed and recreated.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md)* fontCollection | Pointer to the [OH_Drawing_FontCollection](capi-drawing-oh-drawing-fontcollection.md) object.|
| const char* fontFamily | Font family name to be canceled.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Execution result code. 0: success; 8: invalid input parameter; 1: failure.|
