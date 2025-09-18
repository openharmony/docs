# OH_Drawing_FontGenericInfo
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

This struct describes the information about generic fonts supported by the system.

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

**Header file**: [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## Total

### Member Variables

| Name                                    | Description                |
| ---------------------------------------- | -------------------- |
| char* familyName                         | Pointer to the name of a font family.        |
| size_t aliasInfoSize                     | Number of font aliases.|
| size_t adjustInfoSize                    | Number of font weight mappings.|
| [OH_Drawing_FontAliasInfo](capi-drawing-oh-drawing-fontaliasinfo.md)* aliasInfoSet   | Pointer to a set of font aliases.      |
| [OH_Drawing_FontAdjustInfo](capi-drawing-oh-drawing-fontadjustinfo.md)* adjustInfoSet | Pointer to a set of font weight mappings.      |
