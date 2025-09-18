# drawing_color.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_color.h** file declares the functions related to the color in the drawing module.

**File to import**: <native_drawing/drawing_color.h>

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [uint32_t OH_Drawing_ColorSetArgb(uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue)](#oh_drawing_colorsetargb) | Converts four variables (alpha, red, green, and blue) into a 32-bit (ARGB) variable that describes a color.|

## Function Description

### OH_Drawing_ColorSetArgb()

```
uint32_t OH_Drawing_ColorSetArgb(uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue)
```

**Description**

Converts four variables (alpha, red, green, and blue) into a 32-bit (ARGB) variable that describes a color.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 8


**Parameters**

| Name| Description|
| -- | -- |
| uint32_t alpha | Alpha, which is a variable ranging from 0x00 to 0xFF.|
| uint32_t red | Read, which is a variable ranging from 0x00 to 0xFF.|
| uint32_t green | Green, which is a variable ranging from 0x00 to 0xFF.|
| uint32_t blue | Blue, which is a variable ranging from 0x00 to 0xFF.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Returns a 32-bit (ARGB) variable that describes the color.|
