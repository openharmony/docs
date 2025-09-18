# OH_NativeXComponent_HistoricalPoint
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zjsxstar-->
<!--Designer: @sunbees-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

## Overview

Represents a historical touch point.

**Since**: 10

**Related module**: [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**Header file**: [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t id | Unique identifier of the finger.|
| float screenX | X-coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.|
| float screenY | Y-coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.|
| float x | X-coordinate of the touch point relative to the left edge of the XComponent.|
| float y | Y-coordinate of the touch point relative to the upper edge of the XComponent.|
| [OH_NativeXComponent_TouchEventType](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_toucheventtype) type | Touch type of the touch event.|
| double size | Contact area between the finger pad and the screen.|
| float force | Pressure of the touch event.|
| int64_t timeStamp | Timestamp of the touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.|
| float titlX | Angle between the projection on the x-y plane and the z-axis of the touch event.|
| float titlY | Angle between the projection on the y-z plane and the z-axis of the current touch event.|
| [OH_NativeXComponent_TouchEvent_SourceTool](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_touchevent_sourcetool) sourceTool | Source tool of the touch event.|
