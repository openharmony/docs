# drawing_font.h


## Overview

The **drawing_font.h** file declares the functions related to the font in the drawing module.

**File to include**: &lt;native_drawing/drawing_font.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) | Describes the measurement information about a font.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md)  [OH_Drawing_Font_Metrics](_drawing.md#oh_drawing_font_metrics) | Defines a struct that describes the measurement information about a font.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_Font](_drawing.md#oh_drawing_font) \* [OH_Drawing_FontCreate](_drawing.md#oh_drawing_fontcreate) (void) | Creates an **OH_Drawing_Font** object.| 
| void [OH_Drawing_FontSetTypeface](_drawing.md#oh_drawing_fontsettypeface) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*) | Sets a typeface for a font.| 
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_FontGetTypeface](_drawing.md#oh_drawing_fontgettypeface) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Obtains the typeface of a font.| 
| void [OH_Drawing_FontSetTextSize](_drawing.md#oh_drawing_fontsettextsize) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float textSize) | Sets the text size for a font.| 
| int [OH_Drawing_FontCountText](_drawing.md#oh_drawing_fontcounttext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, const void \*text, size_t byteLength, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding) encoding) | Obtains the number of glyphs represented by text.| 
| void [OH_Drawing_FontSetLinearText](_drawing.md#oh_drawing_fontsetlineartext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isLinearText) | Sets linear scaling for a font.| 
| void [OH_Drawing_FontSetTextSkewX](_drawing.md#oh_drawing_fontsettextskewx) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, float skewX) | Sets a horizontal skew factor for a font.| 
| void [OH_Drawing_FontSetFakeBoldText](_drawing.md#oh_drawing_fontsetfakeboldtext) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, bool isFakeBoldText) | Sets fake bold for a font by increasing the stroke width.| 
| void [OH_Drawing_FontDestroy](_drawing.md#oh_drawing_fontdestroy) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*) | Destroys an **OH_Drawing_Font** object and reclaims the memory occupied by the object.| 
| float [OH_Drawing_FontGetMetrics](_drawing.md#oh_drawing_fontgetmetrics) ([OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) \*) | Obtains the measurement information about a font.| 
