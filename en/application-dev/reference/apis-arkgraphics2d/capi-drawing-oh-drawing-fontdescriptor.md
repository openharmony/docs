# OH_Drawing_FontDescriptor
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @gmiao522; @Lem0nC-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
## Overview

This struct describes the detailed information about a system font.

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

**Header file**: [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## Total

### Member Variables

| Name                | Description                                                        |
| -------------------- | ------------------------------------------------------------ |
| char* path           | File path of the system font.                                        |
| char* postScriptName | PostScript name that uniquely identifies the system font.                                        |
| char* fullName       | Full name of the system font.                                            |
| char* fontFamily     | Family of the system font.                                        |
| char* fontSubfamily  | Subfamily of the system font.                                      |
| int weight           | Weight of the system font.                                        |
| int width            | Width of the system font.                                    |
| int italic           | Slope of the system font.                                            |
| bool monoSpace       | Whether the system font is monospaced. **true** means yes; **false** otherwise.   |
| bool symbolic        | Whether the system font supports symbols. **true** means yes; **false** otherwise.|
