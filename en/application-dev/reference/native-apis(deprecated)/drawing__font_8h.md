# drawing_font.h


## Overview

The **drawing_font.h** file declares the functions related to the font in the drawing module.

**File to include**: &lt;native_drawing/drawing_font.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Font](_drawing.md#oh_drawing_font) \* [OH_Drawing_FontCreate](_drawing.md#oh_drawing_fontcreate) (void) | Creates an **OH_Drawing_Font** object.|
| void [OH_Drawing_FontSetTypeface](_drawing.md#oh_drawing_fontsettypeface) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*) | Sets the typeface for a font.|
| void [OH_Drawing_FontSetTextSize](_drawing.md#oh_drawing_fontsettextsize) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float textSize) | Sets the font size.|
| void [OH_Drawing_FontSetLinearText](_drawing.md#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isLinearText) | Sets linear scaling for a font.|
| void [OH_Drawing_FontSetTextSkewX](_drawing.md#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float skewX) | Sets a horizontal skew factor for a font.|
| void [OH_Drawing_FontSetFakeBoldText](_drawing.md#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isFakeBoldText) | Sets fake bold for a font by increasing the stroke width.|
| void [OH_Drawing_FontDestroy](_drawing.md#oh_drawing_fontdestroy) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Destroys an **OH_Drawing_Font** object and reclaims the memory occupied by the object.|
