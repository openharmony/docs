# drawing_region.h

## Overview

The **drawing_region.h** file declares the functions related to the region in the drawing module, including creating a region, setting the boundary, and destroying a region.

**Header file**: <native_drawing/drawing_region.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode) | OH_Drawing_RegionOpMode | Defines an enum for the operation modes available for a region.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_Region* OH_Drawing_RegionCreate(void)](#oh_drawing_regioncreate) | Creates an **OH_Drawing_Region** object for more accurate graphical control.|
| [OH_Drawing_Region* OH_Drawing_RegionCopy(const OH_Drawing_Region* region)](#oh_drawing_regioncopy) | Creates a copy of a region object.|
| [bool OH_Drawing_RegionContains(OH_Drawing_Region* region, int32_t x, int32_t y)](#oh_drawing_regioncontains) | Checks whether a region contains the specified point.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If region is null, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [bool OH_Drawing_RegionOp(OH_Drawing_Region* region, const OH_Drawing_Region* other, OH_Drawing_RegionOpMode op)](#oh_drawing_regionop) | Combines two regions based on the specified operation mode.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either region or dst is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.<br>If **op** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.|
| [bool OH_Drawing_RegionSetRect(OH_Drawing_Region* region, const OH_Drawing_Rect* rect)](#oh_drawing_regionsetrect) | Sets the boundary for an **OH_Drawing_Region** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either region or rect is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [bool OH_Drawing_RegionSetPath(OH_Drawing_Region* region, const OH_Drawing_Path* path, const OH_Drawing_Region* clip)](#oh_drawing_regionsetpath) | Sets a region to the area described by the path.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If any of region, path, and clip is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.|
| [void OH_Drawing_RegionDestroy(OH_Drawing_Region* region)](#oh_drawing_regiondestroy) | Destroys an **OH_Drawing_Region** object and reclaims the memory occupied by the object.|

## Enum Description

### OH_Drawing_RegionOpMode

```
enum OH_Drawing_RegionOpMode
```

**Description**

Enumerates the operation modes available for a region.

**Since**: 12

| Value| Description|
| -- | -- |
| REGION_OP_MODE_DIFFERENCE | Difference operation.|
| REGION_OP_MODE_INTERSECT | Intersection operation.|
| REGION_OP_MODE_UNION | Union operation.|
| REGION_OP_MODE_XOR | XOR operation.|
| REGION_OP_MODE_REVERSE_DIFFERENCE | Reverse difference operation.|
| REGION_OP_MODE_REPLACE | Replacement operation.|


## Function Description

### OH_Drawing_RegionCreate()

```
OH_Drawing_Region* OH_Drawing_RegionCreate(void)
```

**Description**

Creates an **OH_Drawing_Region** object for more accurate graphical control.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* | A pointer to the created region object [OH_Drawing_Region](capi-drawing-oh-drawing-region.md).|

### OH_Drawing_RegionCopy()

```
OH_Drawing_Region* OH_Drawing_RegionCopy(const OH_Drawing_Region* region)
```

**Description**

Creates a copy of a region object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* region | Pointer to the region object [OH_Drawing_Region](capi-drawing-oh-drawing-region.md) to be copied.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* | The function returns a pointer pointing to the created region object.|

### OH_Drawing_RegionContains()

```
bool OH_Drawing_RegionContains(OH_Drawing_Region* region, int32_t x, int32_t y)
```

**Description**

Checks whether a region contains the specified point.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **region** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* region | Pointer to the [OH_Drawing_Region](capi-drawing-oh-drawing-region.md) object.|
| int32_t x | X coordinate of the point.|
| int32_t y | Y coordinate of the point.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns true if the region contains the coordinate point; false otherwise.|

### OH_Drawing_RegionOp()

```
bool OH_Drawing_RegionOp(OH_Drawing_Region* region, const OH_Drawing_Region* other, OH_Drawing_RegionOpMode op)
```

**Description**

Combines two regions based on the specified operation mode.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either region or rect is NULL, OH_DRAWING_ERROR_INVALID_PARAMETER is returned.<br>If **op** is not set to one of the enumerated values, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* region | Pointer to the region object [OH_Drawing_Region](capi-drawing-oh-drawing-region.md). The region result after the operation is stored in this region object.|
| const [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* other | Pointer to the [OH_Drawing_Region](capi-drawing-oh-drawing-region.md) object.|
| [OH_Drawing_RegionOpMode](#oh_drawing_regionopmode) op | Enumerated type of the region operation. For details about the supported modes, see [OH_Drawing_RegionOpMode](capi-drawing-region-h.md#oh_drawing_regionopmode).|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns true if the region is not empty; false otherwise.|

### OH_Drawing_RegionSetRect()

```
bool OH_Drawing_RegionSetRect(OH_Drawing_Region* region, const OH_Drawing_Rect* rect)
```

**Description**

Sets the boundary for an **OH_Drawing_Region** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If either **region** or **rect** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* region | Pointer to the [OH_Drawing_Region](capi-drawing-oh-drawing-region.md) object.|
| const [OH_Drawing_Rect](capi-drawing-oh-drawing-rect.md)* rect | Pointer to an **OH_Drawing_Rect** object.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns true if the rectangle boundary is successfully set; false otherwise.|

### OH_Drawing_RegionSetPath()

```
bool OH_Drawing_RegionSetPath(OH_Drawing_Region* region, const OH_Drawing_Path* path, const OH_Drawing_Region* clip)
```

**Description**

Sets a region to the area described by the path.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **region**, **path**, or **clip** is NULL, **OH_DRAWING_ERROR_INVALID_PARAMETER** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* region | Pointer to the [OH_Drawing_Region](capi-drawing-oh-drawing-region.md) object.|
| const [OH_Drawing_Path](capi-drawing-oh-drawing-path.md)* path | Pointer to the [OH_Drawing_Path](capi-drawing-oh-drawing-path.md) object.|
| const [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* clip | Pointer to the [OH_Drawing_Region](capi-drawing-oh-drawing-region.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Returns true if the region is not empty; false otherwise.|

### OH_Drawing_RegionDestroy()

```
void OH_Drawing_RegionDestroy(OH_Drawing_Region* region)
```

**Description**

Destroys an **OH_Drawing_Region** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_Region](capi-drawing-oh-drawing-region.md)* region | Pointer to the [OH_Drawing_Region](capi-drawing-oh-drawing-region.md) object.|
