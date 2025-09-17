# OH_Drawing_Font_Metrics

## Overview

The **OH_Drawing_Font_Metrics** struct describes the measurement information about a font.

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

**Header File**: [drawing_font.h](capi-drawing-font-h.md)

## Total

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t flags | Measurement information that is valid.|
| float top | Maximum distance from the baseline to the highest coordinate of a character.|
| float ascent | Recommended distance from the baseline to the highest coordinate of a character.|
| float descent | Recommended distance from the baseline to the lowest coordinate of a character.|
| float bottom | Maximum distance from the baseline to the lowest coordinate of a character.|
| float leading | Gap between rows.|
| float avgCharWidth | Average character width, or zero if unknown.|
| float maxCharWidth | Maximum character width, or zero if unknown.|
| float xMin | Maximum distance to the leftmost of the font bounding box. Generally, the value is a negative value. Variable fonts are not recommended.|
| float xMax | Maximum distance to the rightmost of the font bounding box. Generally, the value is a negative value. Variable fonts are not recommended.|
| float xHeight | Height of a lowercase letter, or zero if unknown. Generally, the value is a negative value.|
| float capHeight | Height of an uppercase letter, or zero if unknown. Generally, the value is a negative value.|
| float underlineThickness | Thickness of the underline.|
| float underlinePosition | Position of the underline, that is, vertical distance from the baseline to the top of the underline. Generally, the value is a positive value.|
| float strikeoutThickness | Thickness of the strikethrough.|
| float strikeoutPosition | Position of the strikethrough, that is, vertical distance from the baseline to the bottom of the strikethrough. Generally, the value is a negative value.|
