# drawing_text_lineTypography.h


## Overview

The **drawing_text_lineTypography.h** file declares the functions related to line typography, including functions to determine the number of characters that can be formatted from a given position within the text.

**File to include**: &lt;native_drawing/drawing_text_lineTypography.h&gt;

**Library**: libnative_drawing.so

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) \* [OH_Drawing_CreateLineTypography](_drawing.md#oh_drawing_createlinetypography) ([OH_Drawing_TypographyCreate](_drawing.md#oh_drawing_typographycreate) \*handler) | Creates a pointer to an [OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) object, which stores the text content and style and can be used to compute typography details for individual lines of text.|
| void [OH_Drawing_DestroyLineTypography](_drawing.md#oh_drawing_destroylinetypography) ([OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) \*lineTypography) | Releases the memory occupied by an [OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) object.|
| size_t [OH_Drawing_LineTypographyGetLineBreak](_drawing.md#oh_drawing_linetypographygetlinebreak) ([OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) \*lineTypography, size_t startIndex, double width) | Obtains the number of characters that can fit in the layout from the specified position within a limited layout width.|
| [OH_Drawing_TextLine](_drawing.md#oh_drawing_textline) \* [OH_Drawing_LineTypographyCreateLine](_drawing.md#oh_drawing_linetypographycreateline) ([OH_Drawing_LineTypography](_drawing.md#oh_drawing_linetypography) \*lineTypography, size_t startIndex, size_t count) | Creates a pointer to an [OH_Drawing_TextLine](_drawing.md#oh_drawing_textline) object based on the text content in a specified range.|
