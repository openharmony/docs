# drawing_typeface.h


## Overview

The **drawing_typeface.h** file declares the functions related to the typeface in the drawing module. Different platforms have their own default typefaces. You can also parse the .ttf file to obtain the typefaces specified by the third party, such as SimSun and SimHei.

**File to include**: &lt;native_drawing/drawing_typeface.h&gt;;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \* [OH_Drawing_TypefaceCreateDefault](_drawing.md#oh_drawing_typefacecreatedefault) (void) | Creates an **OH_Drawing_Typeface** object, which defines the default font.|
| void [OH_Drawing_TypefaceDestroy](_drawing.md#oh_drawing_typefacedestroy) ([OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) \*) | Destroys an **OH_Drawing_Typeface** object and reclaims the memory occupied by the object.|
