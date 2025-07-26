# OH_NativeXComponent_HistoricalPoint


## Overview

Represents a historical touch point.

**Since**: 10

**Related module**: [Native XComponent](_o_h___native_x_component.md)

**Header file**: [native_interface_xcomponent.h](native__interface__xcomponent_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [id](_o_h___native_x_component.md#id-33) = 0 |  Unique identifier of the finger.| 
| float [screenX](_o_h___native_x_component.md#screenx-44) = 0.0 |  X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.| 
| float [screenY](_o_h___native_x_component.md#screeny-44) = 0.0 |  Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.| 
| float [x](_o_h___native_x_component.md#x-44) = 0.0 |  X coordinate of the touch point relative to the left edge of the XComponent.| 
| float [y](_o_h___native_x_component.md#y-44) = 0.0 |  Y coordinate of the touch point relative to the upper edge of the XComponent.| 
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype) [type](_o_h___native_x_component.md#type-33) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | Touch type of the touch event.| 
| double [size](_o_h___native_x_component.md#size-33) = 0.0 |  Contact area between the finger pad and the screen.| 
| float [force](_o_h___native_x_component.md#force-33) = 0.0 |  Pressure of the touch event.| 
| int64_t [timeStamp](_o_h___native_x_component.md#timestamp-33) = 0 |  Timestamp of the touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.| 
| float [titlX](_o_h___native_x_component.md#titlx) = 0.0 | Angle between the projection on the x-y plane and the z-axis of the touch event.|
| float [titlY](_o_h___native_x_component.md#titly) = 0.0 | Angle between the projection on the y-z plane and the z-axis of the current touch event.|
| [OH_NativeXComponent_TouchEvent_SourceTool](_o_h___native_x_component.md#oh_nativexcomponent_touchevent_sourcetool) [sourceTool](_o_h___native_x_component.md#sourcetool) |  Source tool of the touch event.| 
