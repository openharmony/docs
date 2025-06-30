# OH_Drawing_StrutStyle


## Overview

The OH_Drawing_StrutStyle struct describes a strut style. The strut style determines the line spacing, baseline alignment mode, and other properties related to the line height when drawing text.

**Since**: 12

**Related module**: [Drawing](_drawing.md)

**Header file**: [drawing_text_typography.h](drawing__text__typography_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_FontWeight](_drawing.md#oh_drawing_fontweight) [weight](#weight) | Font weight used for calculating the strut. | 
| [OH_Drawing_FontStyle](_drawing.md#oh_drawing_fontstyle) [style](#style) | Font style used for calculating the strut. | 
| double [size](#size) | Size of the ascent plus descent in the logical pixels. | 
| double [heightScale](#heightscale) | Scale factor of the line height. | 
| bool [heightOverride](#heightoverride) | Whether to enable the feature to override the height. The value **true** means to enable the feature, and **false** means the opposite. | 
| bool [halfLeading](#halfleading) | Whether to enable half leading. The value **true** means to enable half leading, and **false** means the opposite. | 
| double [leading](#leading) | Custom leading to be applied to the strut. | 
| bool [forceStrutHeight](#forcestrutheight) | Whether to forcibly use the strut height for all rows. The value **true** means to forcibly use the strut height for all rows, and **false** means the opposite. | 
| size_t [familiesSize](#familiessize) | Number of font families. | 
| char \*\* [families](#families) | Double pointer to the font families used for calculating the strut. | 


## Member Variable Description


### families

```
char** OH_Drawing_StrutStyle::families
```
**Description**

Double pointer to the font families used for calculating the strut.


### familiesSize

```
size_t OH_Drawing_StrutStyle::familiesSize
```

**Description**

Number of font families.


### forceStrutHeight

```
bool OH_Drawing_StrutStyle::forceStrutHeight
```
**Description**

Whether to forcibly use the strut height for all rows. The value **true** means to forcibly use the strut height for all rows, and **false** means the opposite.


### halfLeading

```
bool OH_Drawing_StrutStyle::halfLeading
```
**Description**

Whether to enable half leading. The value **true** means to enable half leading, and **false** means the opposite.


### heightOverride

```
bool OH_Drawing_StrutStyle::heightOverride
```

**Description**

Whether to enable the feature to override the height. The value **true** means to enable the feature, and **false** means the opposite.


### heightScale

```
double OH_Drawing_StrutStyle::heightScale
```

**Description**

Scale factor of the line height.


### leading

```
double OH_Drawing_StrutStyle::leading
```

**Description**

Custom leading to be applied to the strut.


### size

```
double OH_Drawing_StrutStyle::size
```

**Description**

Size of the ascent plus descent in the logical pixels.


### style

```
OH_Drawing_FontStyle OH_Drawing_StrutStyle::style
```

**Description**

Font style used for calculating the strut.


### weight

```
OH_Drawing_FontWeight OH_Drawing_StrutStyle::weight
```

**Description**

Font weight used for calculating the strut.
