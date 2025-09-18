# OH_Drawing_LineMetrics

## Overview

This struct describes the measurement information about a line of text.

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

**Header file**: [drawing_text_typography.h](capi-drawing-text-typography-h.md)

## Summary

### Member Variables

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| double ascender                                              | Part of a lowercase letter that extends beyond the meanline.                                  |
| double descender                                             | Part of a lowercase letter that extends below the baseline.                                  |
| double capHeight                                             | Height of an uppercase letter above the baseline.                                            |
| double xHeight                                               | Height of a lowercase letter, specifically the lowercase x, not including ascenders and descenders.                                            |
| double width                                                 | Horizontal space taken up by a character.                                                  |
| double height                                                | Line height.                                                      |
| double x                                                     | Distance from the left edge of the leftmost character to the left edge of the container. For left alignment, the value is 0. For right alignment, the value is the container width minus the text width.|
| double y                                                     | Height from the top edge of the character to the top of the container. The first line is 0, and the second line is the height of the first line.     |
| size_t startIndex                                            | Index of the first character in the line.                                        |
| size_t endIndex                                              | Index of the last character in the line.                                        |
| [OH_Drawing_Font_Metrics](capi-drawing-oh-drawing-font-metrics.md) firstCharMetrics | Measurement information of the first character.                                        |
