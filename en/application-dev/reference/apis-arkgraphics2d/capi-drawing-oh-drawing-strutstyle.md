# OH_Drawing_StrutStyle
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

This struct describes a strut style. The strut style determines the line spacing, baseline alignment mode, and other properties related to the line height when drawing text.

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

**Header file**: [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## Summary

### Member Variables

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Drawing_FontWeight](capi-drawing-text-typography-h.md#oh_drawing_fontweight) weight | Font weight used for calculating the strut.                                  |
| [OH_Drawing_FontStyle](capi-drawing-text-typography-h.md#oh_drawing_fontstyle) style | Font style used for calculating the strut.                                  |
| double size                                                  | Size of the ascent plus descent in the logical pixels.                              |
| double heightScale                                           | Scale factor of the line height.                                              |
| bool heightOverride                                          | Whether to enable height override. **true**: enabled; **false**: disabled.           |
| bool halfLeading                                             | Whether to enable half leading. **true**: enabled; **false**: disabled.             |
| double leading                                               | Custom leading to be applied to the strut.                              |
| bool forceStrutHeight                                        | Whether to forcibly use the strut height for all rows. **true** means yes; **false** otherwise.|
| size_t familiesSize                                          | Number of font families.                                            |
| char** families                                              | Double pointer to the font families used for calculating the strut.                                  |
