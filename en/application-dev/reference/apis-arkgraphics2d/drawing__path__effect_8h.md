# drawing_path_effect.h


## Overview

The **drawing_path_effect.h** file declares the functions related to the path effect in the drawing module.

**File to include**: &lt;native_drawing/drawing_path_effect.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \* [OH_Drawing_CreateDashPathEffect](_drawing.md#oh_drawing_createdashpatheffect) (float \*intervals, int count, float phase) | Creates an **OH_Drawing_PathEffect** object with a dashed line effect. The dashed line effect is determined by a group of "on" and "off" intervals.|
| void [OH_Drawing_PathEffectDestroy](_drawing.md#oh_drawing_patheffectdestroy) ([OH_Drawing_PathEffect](_drawing.md#oh_drawing_patheffect) \*) | Destroys an **OH_Drawing_PathEffect** object and reclaims the memory occupied by the object.|
