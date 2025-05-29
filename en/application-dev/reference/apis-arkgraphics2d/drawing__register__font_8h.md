# drawing_register_font.h


## Overview

The **drawing_register_font.h** file declares the functions related to the font manager in the drawing module.

**File to include**: &lt;native_drawing/drawing_register_font.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| uint32_t [OH_Drawing_RegisterFont](_drawing.md#oh_drawing_registerfont) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection)\*, const char\* fontFamily, const char\* familySrc) | Registers a custom font with the font manager. The supported font file formats are .ttf and .otf.| 
| uint32_t [OH_Drawing_RegisterFontBuffer](_drawing.md#oh_drawing_registerfontbuffer) ([OH_Drawing_FontCollection](_drawing.md#oh_drawing_fontcollection)\*, const char\* fontFamily, uint8_t\* fontBuffer, size_t length) | Registers a font buffer with the font manager.| 
