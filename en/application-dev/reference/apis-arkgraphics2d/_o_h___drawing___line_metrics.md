# OH_Drawing_LineMetrics


## Overview

The **OH_Drawing_LineMetrics** struct describes the measurement information about a line of text.

**Since**: 12

**Related module**: [Drawing](_drawing.md)

**Header file**: [drawing_text_typography.h](drawing__text__typography_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| double [ascender](#ascender) | Part of a lowercase letter that extends beyond the meanline.| 
| double [descender](#descender) | Part of a lowercase letter that extends below the baseline.| 
| double [capHeight](#capheight) | Height of an uppercase letter above the baseline.| 
| double [xHeight](#xheight) | Height of a lowercase letter, specifically the lowercase x, not including ascenders and descenders.| 
| double [width](#width) | Horizontal space taken up by a character.| 
| double [height](#height) | Line height.| 
| double [x](#x) | Distance from the left edge of the leftmost character to the left edge of the container. For left alignment, the value is 0. For right alignment, the value is the container width minus the text width.| 
| double [y](#y) | Height from the top edge of the character to the top of the container. The first line is 0, and the second line is the height of the first line.| 
| size_t [startIndex](#startindex) | Index of the first character in the line.| 
| size_t [endIndex](#endindex) | Index of the last character in the line.| 
| [OH_Drawing_Font_Metrics](_o_h___drawing___font___metrics.md) [firstCharMetrics](#firstcharmetrics) | Measurement information of the first character.| 


## Member Variable Description


### ascender

```
double OH_Drawing_LineMetrics::ascender
```

**Description**

Part of a lowercase letter that extends beyond the meanline.


### capHeight

```
double OH_Drawing_LineMetrics::capHeight
```

**Description**

Height of an uppercase letter above the baseline.


### descender

```
double OH_Drawing_LineMetrics::descender
```

**Description**

Part of a lowercase letter that extends below the baseline.


### endIndex

```
size_t OH_Drawing_LineMetrics::endIndex
```

**Description**

Index of the last character in the line.


### firstCharMetrics

```
OH_Drawing_Font_Metrics OH_Drawing_LineMetrics::firstCharMetrics
```

**Description**

Measurement information of the first character.


### height

```
double OH_Drawing_LineMetrics::height
```

**Description**

Line height.


### startIndex

```
size_t OH_Drawing_LineMetrics::startIndex
```

**Description**

Index of the first character in the line.


### width

```
double OH_Drawing_LineMetrics::width
```

**Description**

Horizontal space taken up by a character.


### x

```
double OH_Drawing_LineMetrics::x
```

**Description**

Distance from the left edge of the leftmost character to the left edge of the container. For left alignment, the value is 0. For right alignment, the value is the container width minus the text width.


### xHeight

```
double OH_Drawing_LineMetrics::xHeight
```

**Description**

Height of a lowercase letter, specifically the lowercase x, not including ascenders and descenders.


### y

```
double OH_Drawing_LineMetrics::y
```

**Description**

Height from the top edge of the character to the top of the container. The first line is 0, and the second line is the height of the first line.
