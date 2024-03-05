# OH_OnFrameAvailableListener


## Overview

The **OH_OnFrameAvailableListener** struct describes an **OH_NativeImage** listener, which is registered through **OH_NativeImage_SetOnFrameAvailableListener**. The listener triggers a callback when a frame is available.

**Since**: 11

**Related module**: [OH_NativeImage](_o_h___native_image.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [context](#context) | User-defined context information, which is returned when the callback is triggered.|
| [onFrameAvailable](#onframeavailable) | Callback function triggered when a frame is available.|


## Member Variable Description


### context

```
void* OH_OnFrameAvailableListener::context
```

**Description**

User-defined context information, which is returned when the callback is triggered.


### onFrameAvailable

```
OH_OnFrameAvailable OH_OnFrameAvailableListener::onFrameAvailable
```

**Description**

Callback function triggered when a frame is available.
