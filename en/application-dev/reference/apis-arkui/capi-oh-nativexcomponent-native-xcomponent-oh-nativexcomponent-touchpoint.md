# OH_NativeXComponent_TouchPoint

## Overview

Describes the touch point of the touch event.

**Since**: 8

**Related module**: [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**Header file**: [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t id | Unique identifier of the finger.|
| float screenX | X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.|
| float screenY | Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.|
| float x | X coordinate of the touch point relative to the left edge of the XComponent.|
| float y | Y coordinate of the touch point relative to the upper edge of the XComponent.|
| OH_NativeXComponent_TouchEventType type | Type of the touch event.|
| double size | Contact area between the finger pad and the screen.|
| float force | Pressure of the touch event.|
| int64_t timeStamp | Timestamp of the touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.|
| bool isPressed | Whether the current point is pressed.|
