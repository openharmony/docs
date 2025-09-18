# drawing_text_lineTypography.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

The **drawing_text_lineTypography.h** file declares the functions related to line typography, including functions to determine the number of characters that can be formatted from a given position within the text.

**Header file**: <native_drawing/drawing_text_lineTypography.h>

**Library**: libnative_drawing.so

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_LineTypography* OH_Drawing_CreateLineTypography(OH_Drawing_TypographyCreate* handler)](#oh_drawing_createlinetypography) | Creates a pointer to a text line object [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md). The text line object stores text content and styles, and can be used to calculate single-line layout information.|
| [void OH_Drawing_DestroyLineTypography(OH_Drawing_LineTypography* lineTypography)](#oh_drawing_destroylinetypography) | Releases the memory occupied by the text line object [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md).|
| [size_t OH_Drawing_LineTypographyGetLineBreak(OH_Drawing_LineTypography* lineTypography,size_t startIndex, double width)](#oh_drawing_linetypographygetlinebreak) | Obtains the number of characters that can fit in the layout from the specified position within a limited layout width.|
| [OH_Drawing_TextLine* OH_Drawing_LineTypographyCreateLine(OH_Drawing_LineTypography* lineTypography,size_t startIndex, size_t count)](#oh_drawing_linetypographycreateline) | Creates a pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object based on the text content in a specified range.|

## Function Description

### OH_Drawing_CreateLineTypography()

```
OH_Drawing_LineTypography* OH_Drawing_CreateLineTypography(OH_Drawing_TypographyCreate* handler)
```

**Description**

Creates a pointer to the [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md) object. The layout line object is a carrier of text content and style, and can be used to calculate the layout information of a single line.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md)* handler | Pointer to the [OH_Drawing_TypographyCreate](capi-drawing-oh-drawing-typographycreate.md) object, which is obtained from [OH_Drawing_CreateTypographyHandler](capi-drawing-text-typography-h.md#oh_drawing_createtypographyhandler).|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md)* | Pointer to the [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md) object.|

### OH_Drawing_DestroyLineTypography()

```
void OH_Drawing_DestroyLineTypography(OH_Drawing_LineTypography* lineTypography)
```

**Description**

Releases the memory occupied by the [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md) object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md)* lineTypography | Pointer to the [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md) object, which is obtained from [OH_Drawing_CreateLineTypography](capi-drawing-text-linetypography-h.md#oh_drawing_createlinetypography).|

### OH_Drawing_LineTypographyGetLineBreak()

```
size_t OH_Drawing_LineTypographyGetLineBreak(OH_Drawing_LineTypography* lineTypography,size_t startIndex, double width)
```

**Description**

Obtains the number of characters that can fit in the layout from the specified position within a limited layout width.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md)* lineTypography | Pointer to the typeset line object [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md), which is obtained from [OH_Drawing_CreateLineTypography](capi-drawing-text-linetypography-h.md#oh_drawing_createlinetypography).|
| size_t startIndex | Start position (inclusive) for layout calculation. The value must be an integer in the range [0, total number of text characters].|
| double width | Layout width. The value is a floating point number greater than 0, in px.|

**Return value**

| Type| Description|
| -- | -- |
| size_t | Total number of characters that can be typeset at a specified position within the specified width. The value is an integer.|

### OH_Drawing_LineTypographyCreateLine()

```
OH_Drawing_TextLine* OH_Drawing_LineTypographyCreateLine(OH_Drawing_LineTypography* lineTypography,size_t startIndex, size_t count)
```

**Description**

Creates a pointer to the text line object [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) based on the text content in a specified range.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md)* lineTypography | Pointer to the [OH_Drawing_LineTypography](capi-drawing-oh-drawing-linetypography.md) object, which is obtained from [OH_Drawing_CreateLineTypography](capi-drawing-text-linetypography-h.md#oh_drawing_createlinetypography).|
| size_t startIndex | Start position for layout calculation. The value is an integer in the range [0, total number of text characters).|
| size_t count | Number of characters from the specified start position. The value is an integer in the range [0, total number of text characters). The sum of **startIndex** and **count** cannot be greater than the total number of text characters.<br>You can use [OH_Drawing_LineTypographyGetLineBreak](capi-drawing-text-linetypography-h.md#oh_drawing_linetypographygetlinebreak) to obtain the number of characters that can be typeset. If this parameter is set to 0, nullptr is returned.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md)* | Pointer to the [OH_Drawing_TextLine](capi-drawing-oh-drawing-textline.md) object.|
