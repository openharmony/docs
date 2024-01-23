# drawing_text_blob.h


## Overview

The **drawing_text_blob.h** file declares the functions related to the text blob in the drawing module.

**File to include**: &lt;native_drawing/drawing_text_blob.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) | Describes a run, which provides storage for glyphs and positions.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \* [OH_Drawing_TextBlobBuilderCreate](_drawing.md#oh_drawing_textblobbuildercreate) (void) | Creates an **OH_Drawing_TextBlobBuilder** object.|
| const [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) \* [OH_Drawing_TextBlobBuilderAllocRunPos](_drawing.md#oh_drawing_textblobbuilderallocrunpos) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, int32_t count, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Allocates a run to store glyphs and positions. The pointer returned does not need to be managed by the caller. It can no longer be used after [OH_Drawing_TextBlobBuilderMake](_drawing.md#oh_drawing_textblobbuildermake) is called.|
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobBuilderMake](_drawing.md#oh_drawing_textblobbuildermake) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*) | Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.|
| void [OH_Drawing_TextBlobDestroy](_drawing.md#oh_drawing_textblobdestroy) ([OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*) | Destroys an **OH_Drawing_TextBlob** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_TextBlobBuilderDestroy](_drawing.md#oh_drawing_textblobbuilderdestroy) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*) | Destroys an **OH_Drawing_TextBlobBuilder** object and reclaims the memory occupied by the object.|
