# drawing_path_effect.h


## Overview

The **drawing_path_effect.h** file declares the functions related to the path effect in the drawing module.

**File to include**: &lt;native_drawing/drawing_path_effect.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary

### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_Drawing_PathDashStyle](_drawing.md#oh_drawing_pathdashstyle)  [OH_Drawing_PathDashStyle](_drawing.md#oh_drawing_pathdashstyle) | Defines an enum for the styles of the dashed path effect. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_PathDashStyle](_drawing.md#oh_drawing_pathdashstyle-1) { DRAWING_PATH_DASH_STYLE_TRANSLATE, DRAWING_PATH_DASH_STYLE_ROTATE, DRAWING_PATH_DASH_STYLE_MORPH } | Enumerates the styles of the dashed path effect. | 

### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateComposePathEffect](_drawing.md#oh_drawing_createcomposepatheffect) ([OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*outer, [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*inner) | Creates a path effect by sequentially applying the inner effect and then the outer effect. | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateCornerPathEffect](_drawing.md#oh_drawing_createcornerpatheffect) (float radius) | Creates a path effect that transforms the sharp angle between line segments into a rounded corner with the specified radius. | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateDashPathEffect](_drawing.md#oh_drawing_createdashpatheffect) (float \*intervals, int count, float phase) | Creates a dashed path effect, which is determined by a group of "on" and "off" intervals. | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateDiscretePathEffect](_drawing.md#oh_drawing_creatediscretepatheffect) (float segLength, float deviation) | Creates a path effect that segments the path and scatters the segments in an irregular pattern along the path. | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreatePathDashEffect](_drawing.md#oh_drawing_createpathdasheffect) (const [OH_Drawing_Path](_drawing.md#oh_drawing_path) \*path, float advance, float phase, [OH_Drawing_PathDashStyle](_drawing.md#oh_drawing_pathdashstyle) type) | Creates a dashed path effect. | 
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateSumPathEffect](_drawing.md#oh_drawing_createsumpatheffect) ([OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*firstPathEffect, [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*secondPathEffect) | Creates an overlay path effect based on two distinct path effects that take effect separately. | 
| void [OH_Drawing_PathEffectDestroy](_drawing.md#oh_drawing_patheffectdestroy) ([OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*) | Destroys an **OH_Drawing_PathEffect** object and reclaims the memory occupied by the object. | 
