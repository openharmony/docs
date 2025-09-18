# drawing_pixel_map.h

## Overview

The **drawing_pixel_map.h** file declares the functions related to the pixel map in the drawing module.

**Header file**: <native_drawing/drawing_pixel_map.h>

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](capi-drawing.md)

## Total

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NativePixelMap_](capi-drawing-nativepixelmap-.md) | NativePixelMap_ | Declares the pixel map object defined by the image framework.|
| [OH_PixelmapNative](capi-drawing-oh-pixelmapnative.md) | OH_PixelmapNative | Declares the pixel map object defined by the image framework.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromNativePixelMap(NativePixelMap_* nativePixelMap)](#oh_drawing_pixelmapgetfromnativepixelmap) | Obtains the pixel map defined by this module from a pixel map defined by the image framework.|
| [OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromOhPixelMapNative(OH_PixelmapNative* pixelmapNative)](#oh_drawing_pixelmapgetfromohpixelmapnative) | Obtains the pixel map defined by this module from a pixel map defined by the image framework.|
| [void OH_Drawing_PixelMapDissolve(OH_Drawing_PixelMap* pixelMap)](#oh_drawing_pixelmapdissolve) | Removes the relationship between the pixel map object defined by this module and the pixel map object defined by the image framework. The relationship is established by calling [OH_Drawing_PixelMapGetFromNativePixelMap](capi-drawing-pixel-map-h.md#oh_drawing_pixelmapgetfromnativepixelmap) or [OH_Drawing_PixelMapGetFromOhPixelMapNative](capi-drawing-pixel-map-h.md#oh_drawing_pixelmapgetfromohpixelmapnative).|

## Function Description

### OH_Drawing_PixelMapGetFromNativePixelMap()

```
OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromNativePixelMap(NativePixelMap_* nativePixelMap)
```

**Description**

Obtains the pixel map defined by this module from a pixel map defined by the image framework.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [NativePixelMap_](capi-drawing-nativepixelmap-.md)* nativePixelMap | Pointer to the pixel map object [NativePixelMap_](capi-drawing-nativepixelmap-.md) defined by the image framework.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_PixelMap](capi-drawing-oh-drawing-pixelmap.md)* | A pointer to the pixel map object [OH_Drawing_PixelMap](capi-drawing-oh-drawing-pixelmap.md) defined by this module. If NULL is returned, the creation fails. The possible cause is that NativePixelMap_ is NULL.|

### OH_Drawing_PixelMapGetFromOhPixelMapNative()

```
OH_Drawing_PixelMap* OH_Drawing_PixelMapGetFromOhPixelMapNative(OH_PixelmapNative* pixelmapNative)
```

**Description**

Obtains the pixel map defined by this module from a pixel map defined by the image framework.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-drawing-oh-pixelmapnative.md)* pixelmapNative | Pointer to the pixel map object [OH_PixelmapNative](capi-drawing-oh-pixelmapnative.md) defined by the image framework.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_PixelMap](capi-drawing-oh-drawing-pixelmap.md)* | Pointer to the pixel map object [OH_Drawing_PixelMap](capi-drawing-oh-drawing-pixelmap.md) defined by the current module. If NULL is returned, the creation fails. The possible cause is that OH_PixelmapNative is NULL.|

### OH_Drawing_PixelMapDissolve()

```
void OH_Drawing_PixelMapDissolve(OH_Drawing_PixelMap* pixelMap)
```

**Description**

Removes the relationship between the pixel map object defined by the current module and the pixel map object defined by the image framework. The relationship is established by calling [OH_Drawing_PixelMapGetFromNativePixelMap](capi-drawing-pixel-map-h.md#oh_drawing_pixelmapgetfromnativepixelmap) or [OH_Drawing_PixelMapGetFromOhPixelMapNative](capi-drawing-pixel-map-h.md#oh_drawing_pixelmapgetfromohpixelmapnative).

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_PixelMap](capi-drawing-oh-drawing-pixelmap.md)* pixelMap | Pointer to the pixel map object [OH_Drawing_PixelMap](capi-drawing-oh-drawing-pixelmap.md).|
