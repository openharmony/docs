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
| struct  [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) | Describes a run, which provides storage for glyphs and positions.|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md)  [OH_Drawing_RunBuffer](_drawing.md#oh_drawing_runbuffer) | Defines a struct that describes a run, which provides storage for glyphs and positions.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \* [OH_Drawing_TextBlobBuilderCreate](_drawing.md#oh_drawing_textblobbuildercreate) (void) | Creates an **OH_Drawing_TextBlobBuilder** object.|
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromText](_drawing.md#oh_drawing_textblobcreatefromtext) (const void \*text, size_t byteLength, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from the text.|
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromPosText](_drawing.md#oh_drawing_textblobcreatefrompostext) (const void \*text, size_t byteLength, [OH_Drawing_Point2D](_o_h___drawing___point2_d.md) \*, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from the text. The coordinates of each character in the **OH_Drawing_TextBlob** object are determined by the coordinate information in the **OH_Drawing_Point2D** array.|
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobCreateFromString](_drawing.md#oh_drawing_textblobcreatefromstring) (const char \*str, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, [OH_Drawing_TextEncoding](_drawing.md#oh_drawing_textencoding)) | Creates an **OH_Drawing_TextBlob** object from a string.|
| void [OH_Drawing_TextBlobGetBounds](_drawing.md#oh_drawing_textblobgetbounds) ([OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*, [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Obtains the bounds of an **OH_Drawing_TextBlob** object.|
| uint32_t [OH_Drawing_TextBlobUniqueID](_drawing.md#oh_drawing_textblobuniqueid) (const [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*) | Obtains the unique identifier of a text blob. The identifier is a non-zero value.| 
| const [OH_Drawing_RunBuffer](_o_h___drawing___run_buffer.md) \* [OH_Drawing_TextBlobBuilderAllocRunPos](_drawing.md#oh_drawing_textblobbuilderallocrunpos) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*, const [OH_Drawing_Font](_drawing.md#oh_drawing_font) \*, int32_t count, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*) | Allocates a run to store glyphs and positions. The pointer returned does not need to be managed by the caller. It can no longer be used after [OH_Drawing_TextBlobBuilderMake](_drawing.md#oh_drawing_textblobbuildermake) is called.|
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \* [OH_Drawing_TextBlobBuilderMake](_drawing.md#oh_drawing_textblobbuildermake) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*) | Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.|
| void [OH_Drawing_TextBlobDestroy](_drawing.md#oh_drawing_textblobdestroy) ([OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) \*) | Destroys an **OH_Drawing_TextBlob** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_TextBlobBuilderDestroy](_drawing.md#oh_drawing_textblobbuilderdestroy) ([OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) \*) | Destroys an **OH_Drawing_TextBlobBuilder** object and reclaims the memory occupied by the object.|
