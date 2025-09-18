# drawing_shadow_layer.h

## Overview

The **drawing_shadow_layer.h** file declares the functions related to the shadow in the drawing module.

**File to include:** <native_drawing/drawing_shadow_layer.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_ShadowLayer* OH_Drawing_ShadowLayerCreate(float blurRadius, float x, float y, uint32_t color)](#oh_drawing_shadowlayercreate) | Creates an **OH_Drawing_ShadowLayer** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If blurRadius is less than 0, OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE is returned.|
| [void OH_Drawing_ShadowLayerDestroy(OH_Drawing_ShadowLayer* shadowLayer)](#oh_drawing_shadowlayerdestroy) | Destroys an **OH_Drawing_ShadowLayer** object and reclaims the memory occupied by the object.|

## Function Description

### OH_Drawing_ShadowLayerCreate()

```
OH_Drawing_ShadowLayer* OH_Drawing_ShadowLayerCreate(float blurRadius, float x, float y, uint32_t color)
```

**Description**

Creates an **OH_Drawing_ShadowLayer** object.<br>This API may return an error code. For details, call [OH_Drawing_ErrorCodeGet](capi-drawing-error-code-h.md#oh_drawing_errorcodeget).<br>If **blurRadius** is less than or equal to **0**, **OH_DRAWING_ERROR_PARAMETER_OUT_OF_RANGE** is returned.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| float blurRadius | Radius of the shadow layer. The value must be greater than 0.|
| float x | Offset on the X axis.|
| float y | Offset on the Y axis.|
| uint32_t color | Color of the shadow.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_ShadowLayer](capi-drawing-oh-drawing-shadowlayer.md)* | Pointer to the created shadow layer object.|

### OH_Drawing_ShadowLayerDestroy()

```
void OH_Drawing_ShadowLayerDestroy(OH_Drawing_ShadowLayer* shadowLayer)
```

**Description**

Destroys an **OH_Drawing_ShadowLayer** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_ShadowLayer](capi-drawing-oh-drawing-shadowlayer.md)* shadowLayer | Pointer to the shadow layer.|
