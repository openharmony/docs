# OH_NativeXComponent_MouseEvent

## Overview

Defines a mouse event.

**Since**: 9

**Related module**: [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**Header file**: [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| float x | X coordinate of the clicked point relative to the upper left corner of the component.|
| float y | Y-coordinate of the clicked point relative to the upper left corner of the component.|
| float screenX | X coordinate of the click point relative to the upper left corner of the application screen where the XComponent is located.|
| float screenY | Y coordinate of the click point relative to the upper left corner of the application screen where the XComponent is located.|
| int64_t timestamp | Timestamp of the mouse event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.|
| OH_NativeXComponent_MouseEventAction action | Action of the mouse event.|
| OH_NativeXComponent_MouseEventButton button | Button of the mouse event.|
