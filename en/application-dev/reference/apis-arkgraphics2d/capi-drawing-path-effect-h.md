# drawing_path_effect.h

## Overview

The **drawing_path_effect.h** file declares the functions related to the path effect in the drawing module.

**Header file**: <native_drawing/drawing_path_effect.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle) | OH_Drawing_PathDashStyle | Defines an enum for the drawing styles for path effects.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_PathEffect* OH_Drawing_CreateComposePathEffect(OH_Drawing_PathEffect* outer, OH_Drawing_PathEffect* inner)](#oh_drawing_createcomposepatheffect) | Creates a path effect by sequentially applying the inner effect and then the outer effect.|
| [OH_Drawing_PathEffect* OH_Drawing_CreateCornerPathEffect(float radius)](#oh_drawing_createcornerpatheffect) | Creates a path effect that transforms the sharp angle between line segments into a rounded corner with the specified radius.|
| [OH_Drawing_PathEffect* OH_Drawing_CreateDashPathEffect(float* intervals, int count, float phase)](#oh_drawing_createdashpatheffect) | Creates a dashed path effect, The dashed line effect is determined by a group of "on" and "off" intervals.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If intervals is null or count is less than or equal to 0, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [OH_Drawing_PathEffect* OH_Drawing_CreateDiscretePathEffect(float segLength, float deviation)](#oh_drawing_creatediscretepatheffect) | Creates a path effect that segments the path and scatters the segments in an irregular pattern along the path.|
| [OH_Drawing_PathEffect* OH_Drawing_CreatePathDashEffect(const OH_Drawing_Path* path, float advance, float phase,OH_Drawing_PathDashStyle type)](#oh_drawing_createpathdasheffect) | Creates a dashed path effect.|
| [OH_Drawing_PathEffect* OH_Drawing_CreateSumPathEffect(OH_Drawing_PathEffect* firstPathEffect,OH_Drawing_PathEffect* secondPathEffect)](#oh_drawing_createsumpatheffect) | Creates an overlay path effect based on two distinct path effects that take effect separately.|
| [void OH_Drawing_PathEffectDestroy(OH_Drawing_PathEffect* pathEffect)](#oh_drawing_patheffectdestroy) | Destroys an **OH_Drawing_PathEffect** object and reclaims the memory occupied by the object.|

## Enum Description

### OH_Drawing_PathDashStyle

```
enum OH_Drawing_PathDashStyle
```

**Description**

Enumerates the drawing styles for path effects.

**Since**: 18

| Value| Description|
| -- | -- |
| DRAWING_PATH_DASH_STYLE_TRANSLATE | Indicates the translation effect.|
| DRAWING_PATH_DASH_STYLE_ROTATE | Indicates the rotation effect.|
| DRAWING_PATH_DASH_STYLE_MORPH | Indicates the deformation effect.|


## Function Description

### OH_Drawing_CreateComposePathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateComposePathEffect(OH_Drawing_PathEffect* outer, OH_Drawing_PathEffect* inner)
```

**Description**

Creates a path effect by sequentially applying the inner effect and then the outer effect.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* outer | Pointer to the external path effect [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md) in the path combination effect.|
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* inner | Pointer to the internal path effect [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md) in the path combination effect.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | A pointer to the created path effect object [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md).<br> If nullptr is returned, the creation fails. The possible cause is that outer or inner is nullptr.|

### OH_Drawing_CreateCornerPathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateCornerPathEffect(float radius)
```

**Description**

Creates a path effect that transforms the sharp angle between line segments into a rounded corner with the specified radius.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| float radius | Radius of the rounded corner. The value is valid only when it is greater than 0.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | A pointer to the created path effect object [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md).<br> If nullptr is returned, the creation fails. The possible cause is that the value of radius is less than or equal to 0.|

### OH_Drawing_CreateDashPathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateDashPathEffect(float* intervals, int count, float phase)
```

**Description**

Creates a dashed path effect, The dashed line effect is determined by a group of "on" and "off" intervals.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **intervals** is NULL or **count** is less than or equal to 0, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float* intervals | Start address of the dashed line interval array. The value of an even item indicates the length of the dashed line interval, and the value of an odd item indicates the length of the dashed line interval. The unit is pixel.|
| int count | Number of entries in the dashed line interval array. The value must be an even number greater than 0.|
| float phase | Offset in the dashed line interval array.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | A pointer to the created path effect object [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md).|

### OH_Drawing_CreateDiscretePathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateDiscretePathEffect(float segLength, float deviation)
```

**Description**

Creates a path effect that segments the path and scatters the segments in an irregular pattern along the path.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| float segLength | Distance along the path at which each segment is fragmented. An effect is created when it is greater than 0.|
| float deviation | Maximum amount by which the end points of the segments can be randomly displaced during rendering.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md) of the created path effect object.|

### OH_Drawing_CreatePathDashEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreatePathDashEffect(const OH_Drawing_Path* path, float advance, float phase,OH_Drawing_PathDashStyle type)
```

**Description**

Creates a dashed path effect,

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | Pointer to the path object [OH_Drawing_Path](capi-drawing-oh-drawing-path.md) in the dashed line style.|
| float advance | Length of each dashed line segment.|
| float phase | Offset of the pattern within the dash segment length.|
| [OH_Drawing_PathDashStyle](#oh_drawing_pathdashstyle) type | Style of the dashed path effect.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | A pointer to the created path effect object [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md).<br> If nullptr is returned, the creation fails. The possible cause is that path is nullptr or advance is less than or equal to 0.|

### OH_Drawing_CreateSumPathEffect()

```
OH_Drawing_PathEffect* OH_Drawing_CreateSumPathEffect(OH_Drawing_PathEffect* firstPathEffect,OH_Drawing_PathEffect* secondPathEffect)
```

**Description**

Creates an overlay path effect based on two distinct path effects that take effect separately.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* firstPathEffect | Pointer to the path object [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md).|
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* secondPathEffect | Pointer to the path object [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md).|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* | The function returns a pointer that points to the created path effect object [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md).<br> If nullptr is returned, the creation fails. The possible cause is that the value of firstPathEffect or secondPathEffect is nullptr.|

### OH_Drawing_PathEffectDestroy()

```
void OH_Drawing_PathEffectDestroy(OH_Drawing_PathEffect* pathEffect)
```

**Description**

Destroys an **OH_Drawing_PathEffect** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md)* pathEffect | Pointer to the path effect object [OH_Drawing_PathEffect](capi-drawing-oh-drawing-patheffect.md).|
