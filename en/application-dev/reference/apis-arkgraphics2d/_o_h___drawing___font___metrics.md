# OH_Drawing_Font_Metrics


## Overview

The **OH_Drawing_Font_Metrics** struct describes the measurement information about a font.

**Since**: 12

**Related module**: [Drawing](_drawing.md)

**Header file**: [drawing_font.h](drawing__font_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [flags](#flags) | Measurement information that is valid.| 
| float [top](#top) | Maximum distance from the baseline to the highest coordinate of a character.| 
| float [ascent](#ascent) | Recommended distance from the baseline to the highest coordinate of a character.| 
| float [descent](#descent) | Recommended distance from the baseline to the lowest coordinate of a character.| 
| float [bottom](#bottom) | Maximum distance from the baseline to the lowest coordinate of a character.| 
| float [leading](#leading) | Interline spacing.| 
| float [avgCharWidth](#avgcharwidth) | Average character width, or zero if unknown.| 
| float [maxCharWidth](#maxcharwidth) | Maximum character width, or zero if unknown.| 
| float [xMin](#xmin) | Maximum distance to the leftmost of the font bounding box. Generally, the value is a negative value. Variable fonts are not recommended.| 
| float [xMax](#xmax) | Maximum distance to the rightmost of the font bounding box. Generally, the value is a negative value. Variable fonts are not recommended.| 
| float [xHeight](#xheight) | Height of a lowercase letter, or zero if unknown. Generally, the value is a negative value.| 
| float [capHeight](#capheight) | Height of an uppercase letter, or zero if unknown. Generally, the value is a negative value.| 
| float [underlineThickness](#underlinethickness) | Thickness of the underline.| 
| float [underlinePosition](#underlineposition) | Position of the underline, that is, vertical distance from the baseline to the top of the underline. Generally, the value is a positive value.| 
| float [strikeoutThickness](#strikeoutthickness) | Thickness of the strikethrough.| 
| float [strikeoutPosition](#strikeoutposition) | Position of the strikethrough, that is, vertical distance from the baseline to the bottom of the strikethrough. Generally, the value is a negative value.| 


## Member Variable Description


### ascent

```
float OH_Drawing_Font_Metrics::ascent
```

**Description**

Recommended distance from the baseline to the highest coordinate of a character.


### avgCharWidth

```
float OH_Drawing_Font_Metrics::avgCharWidth
```

**Description**

Average character width, or zero if unknown.


### bottom

```
float OH_Drawing_Font_Metrics::bottom
```

**Description**

Maximum distance from the baseline to the lowest coordinate of a character.


### capHeight

```
float OH_Drawing_Font_Metrics::capHeight
```

**Description**

Height of an uppercase letter, or zero if unknown. Generally, the value is a negative value.


### descent

```
float OH_Drawing_Font_Metrics::descent
```

**Description**

Recommended distance from the baseline to the lowest coordinate of a character.


### flags

```
uint32_t OH_Drawing_Font_Metrics::flags
```

**Description**

Measurement information that is valid.


### leading

```
float OH_Drawing_Font_Metrics::leading
```

**Description**

Interline spacing.


### maxCharWidth

```
float OH_Drawing_Font_Metrics::maxCharWidth
```

**Description**

Maximum character width, or zero if unknown.


### strikeoutPosition

```
float OH_Drawing_Font_Metrics::strikeoutPosition
```

**Description**

Position of the strikethrough, that is, vertical distance from the baseline to the bottom of the strikethrough. Generally, the value is a negative value.


### strikeoutThickness

```
float OH_Drawing_Font_Metrics::strikeoutThickness
```

**Description**

Thickness of the strikethrough.


### top

```
float OH_Drawing_Font_Metrics::top
```

**Description**

Maximum distance from the baseline to the highest coordinate of a character.


### underlinePosition

```
float OH_Drawing_Font_Metrics::underlinePosition
```

**Description**

Position of the underline, that is, vertical distance from the baseline to the top of the underline. Generally, the value is a positive value.


### underlineThickness

```
float OH_Drawing_Font_Metrics::underlineThickness
```

**Description**

Thickness of the underline.


### xHeight

```
float OH_Drawing_Font_Metrics::xHeight
```

**Description**

Height of a lowercase letter, or zero if unknown. Generally, the value is a negative value.


### xMax

```
float OH_Drawing_Font_Metrics::xMax
```

**Description**

Maximum distance to the rightmost of the font bounding box. Generally, the value is a negative value. Variable fonts are not recommended.


### xMin

```
float OH_Drawing_Font_Metrics::xMin
```

**Description**

Maximum distance to the leftmost of the font bounding box. Generally, the value is a negative value. Variable fonts are not recommended.
