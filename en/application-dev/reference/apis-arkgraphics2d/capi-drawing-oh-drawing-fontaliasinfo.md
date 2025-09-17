# OH_Drawing_FontAliasInfo
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

The OH_Drawing_FontAliasInfo struct describes the information about a font alias.

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

**Header file**: [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## Total

### Member Variables

| Name| Description|
| -- | -- |
| char* familyName | Pointer to the name of a font family.|
| int weight | Font weight. If the value is greater than 0, only the fonts with the specified weight in the font family are contained. If the value is 0, all the fonts in the font family are contained.|
