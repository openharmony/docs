# drawing_text_global.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

Provides APIs for setting text rendering information, such as the high contrast mode.

**File to import**: <native_drawing/drawing_text_global.h>

**Library**: libnative_drawing.so

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

**Related module**: [Drawing](capi-drawing.md)

## Total

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_TextHighContrast](#oh_drawing_texthighcontrast) | OH_Drawing_TextHighContrast | Enumerates the high contrast modes for text rendering.|
| [OH_Drawing_TextUndefinedGlyphDisplay](#oh_drawing_textundefinedglyphdisplay) | OH_Drawing_TextUndefinedGlyphDisplay | Mode mode for displaying undefined glyphs.|

### Functions

| Name| Description|
| -- | -- |
| [void OH_Drawing_SetTextHighContrast(OH_Drawing_TextHighContrast action)](#oh_drawing_settexthighcontrast) | Sets the high contrast mode for text rendering.|
| [void OH_Drawing_SetTextUndefinedGlyphDisplay(OH_Drawing_TextUndefinedGlyphDisplay undefinedGlyphDisplay)](#oh_drawing_settextundefinedglyphdisplay) | Controls the display mode of undefined glyphs, which affects all subsequent text rendering.|

## Enum Description

### OH_Drawing_TextHighContrast

```
enum OH_Drawing_TextHighContrast
```

**Description**

Enumerates the high contrast text rendering modes.

**Since**: 20

| Value| Description|
| -- | -- |
| TEXT_FOLLOW_SYSTEM_HIGH_CONTRAST | Follow the high contrast text setting in the system settings.|
| TEXT_APP_DISABLE_HIGH_CONTRAST | Disable the high contrast text rendering mode of the app. The priority of this mode is higher than that of the high contrast text setting in the system settings.|
| TEXT_APP_ENABLE_HIGH_CONTRAST | Enable the high contrast text rendering mode of the app. The priority of this mode is higher than that of the high contrast text setting in the system settings.|

### OH_Drawing_TextUndefinedGlyphDisplay

```
enum OH_Drawing_TextUndefinedGlyphDisplay
```

**Description**

Enumerates the ways to display undefined glyphs.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20

| Value| Description|
| -- | -- |
| TEXT_NO_GLYPH_USE_DEFAULT = 0 | Use the default glyph defined in the font file (which may be an empty box, blank, or custom symbol).|
| TEXT_NO_GLYPH_USE_TOFU = 1 | Always use tofu blocks to display missing fonts.|

## Function Description

### OH_Drawing_SetTextHighContrast()

```
void OH_Drawing_SetTextHighContrast(OH_Drawing_TextHighContrast action)
```

**Description**

Sets the high contrast text rendering mode.

The setting of this API takes effect for the entire process. All pages in the process share the same mode.

You can call this API to set the high contrast text rendering mode or enable or disable the high contrast text rendering mode by enabling or disabling the high contrast text setting in the system settings. The priority of using this API to set the high contrast text rendering mode is higher than that of using the system setting.

This API does not take effect for the text self-drawing scenario of an app.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextHighContrast](#oh_drawing_texthighcontrast) action | Enumerates the text rendering high contrast modes, which are of the [OH_Drawing_TextHighContrast](#oh_drawing_texthighcontrast) type.|

### OH_Drawing_SetTextUndefinedGlyphDisplay()

```
void OH_Drawing_SetTextUndefinedGlyphDisplay(OH_Drawing_TextUndefinedGlyphDisplay undefinedGlyphDisplay)
```

**Description**

Controls the display of undefined glyphs, which affects all subsequent text rendering.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TextUndefinedGlyphDisplay](#oh_drawing_textundefinedglyphdisplay) undefinedGlyphDisplay | Enumerates the display modes of undefined glyphs, which are of the [OH_Drawing_TextUndefinedGlyphDisplay](#oh_drawing_textundefinedglyphdisplay) type.|
