# OH_Drawing_FontConfigInfo
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

This struct describes the information about a system font configuration.

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

**Header file**: [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## Total

### Member Variables

| Name                                          | Description                  |
| ---------------------------------------------- | ---------------------- |
| size_t fontDirSize                             | Number of system font file paths.|
| size_t fontGenericInfoSize                     | Number of generic fonts.  |
| size_t fallbackGroupSize                       | Number of font fallbacks.  |
| char** fontDirSet                              | Double pointer to the system font file paths.|
| [OH_Drawing_FontGenericInfo](capi-drawing-oh-drawing-fontgenericinfo.md)* fontGenericInfoSet | Pointer to a set of generic fonts.      |
| [OH_Drawing_FontFallbackGroup](capi-drawing-oh-drawing-fontfallbackgroup.md)* fallbackGroupSet | Pointer to a set of font fallbacks.      |
