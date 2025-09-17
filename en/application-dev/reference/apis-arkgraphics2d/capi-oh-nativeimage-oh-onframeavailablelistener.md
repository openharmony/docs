# OH_OnFrameAvailableListener
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Felix-fangyang; @li_hui180; @dingpy-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## Overview

Defines an **OH_NativeImage** listener, which is registered through [OH_NativeImage_SetOnFrameAvailableListener](capi-native-image-h.md#oh_nativeimage_setonframeavailablelistener). The listener triggers a callback when a frame is available.

**Since**: 11

**Related module**: [OH_NativeImage](capi-oh-nativeimage.md)

**Header file**: [native_image.h](capi-native-image-h.md)

## Summary

### Member Variables

| Name                                                        | Description                                              |
| ------------------------------------------------------------ | -------------------------------------------------- |
| void* context                                                | User-defined context information, which is returned when the callback is triggered.|
| [OH_OnFrameAvailable](capi-native-image-h.md#oh_onframeavailable) onFrameAvailable | Callback function triggered when a frame is available.                  |


### Member Functions

| Name                                                        | typedef Keyword        | Description                                                        |
| ------------------------------------------------------------ | --------------------- | ------------------------------------------------------------ |
| [typedef void (\*OH_OnFrameAvailable)(void *context)](#oh_onframeavailable) | OH_OnFrameAvailable() | Callback function triggered when a frame is available.<br>**Since**: 11<br>**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage|

## Member Function Description

### OH_OnFrameAvailable()

```
typedef void (*OH_OnFrameAvailable)(void *context)
```

**Item**

Callback function triggered when a frame is available.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeImage

**Since**: 11

**Parameters**

| Name       | Description                                              |
| ------------- | -------------------------------------------------- |
| void *context | User-defined context information, which is returned when the callback is triggered.|
