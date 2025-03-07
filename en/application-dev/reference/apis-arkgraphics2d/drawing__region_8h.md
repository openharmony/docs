# drawing_region.h


## Overview

The **drawing_region.h** file declares the functions related to the region in the drawing module, including creating a region, setting the boundary, and destroying a region.

**File to include**: &lt;native_drawing/drawing_region.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| typedef enum [OH_Drawing_RegionOpMode](_drawing.md#oh_drawing_regionopmode)  [OH_Drawing_RegionOpMode](_drawing.md#oh_drawing_regionopmode) | Defines an enum for the operation modes available for a region. | 


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_RegionOpMode](_drawing.md#oh_drawing_regionopmode) {<br>REGION_OP_MODE_DIFFERENCE, REGION_OP_MODE_INTERSECT, REGION_OP_MODE_UNION, REGION_OP_MODE_XOR,<br>REGION_OP_MODE_REVERSE_DIFFERENCE, REGION_OP_MODE_REPLACE<br>} | Enumerates the operation modes available for a region. | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_Region](_drawing.md#oh_drawing_region) \* [OH_Drawing_RegionCreate](_drawing.md#oh_drawing_regioncreate) (void) | Creates an **OH_Drawing_Region** object for more accurate graphical control. | 
| bool [OH_Drawing_RegionContains](_drawing.md#oh_drawing_regioncontains) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, int32_t x, int32_t y) | Checks whether a region contains the specified point. |
| bool [OH_Drawing_RegionOp](_drawing.md#oh_drawing_regionop) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, const [OH_Drawing_Region](_drawing.md#oh_drawing_region) \*other, [OH_Drawing_RegionOpMode](_drawing.md#oh_drawing_regionopmode) op) | Combines two regions based on the specified operation mode. | 
| bool [OH_Drawing_RegionSetRect](_drawing.md#oh_drawing_regionsetrect) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, const [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) \*rect) | Sets the boundary for an **OH_Drawing_Region** object. | 
| bool [OH_Drawing_RegionSetPath](_drawing.md#oh_drawing_regionsetpath) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*region, const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, const [OH_Drawing_Region](_drawing.md#oh_drawing_region) \*clip) | Sets a region to the area described by the path. | 
| void [OH_Drawing_RegionDestroy](_drawing.md#oh_drawing_regiondestroy) ([OH_Drawing_Region](_drawing.md#oh_drawing_region) \*) | Destroys an **OH_Drawing_Region** object and reclaims the memory occupied by the object. | 
