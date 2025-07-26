# OH_NativeXComponent_TouchPoint


## Overview

Describes the touch point of the touch event.

**Since**: 8

**Related module**: [Native XComponent](_o_h___native_x_component.md)

**Header file**: [native_interface_xcomponent.h](native__interface__xcomponent_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [id](_o_h___native_x_component.md#id-13) = 0 |  Unique identifier of the finger.| 
| float [screenX](_o_h___native_x_component.md#screenx-14) = 0.0 |   X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.| 
| float [screenY](_o_h___native_x_component.md#screeny-14) = 0.0 |  Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.| 
| float [x](_o_h___native_x_component.md#x-14) = 0.0 |  X coordinate of the touch point relative to the left edge of the XComponent.| 
| float [y](_o_h___native_x_component.md#y-14) = 0.0 |  Y coordinate of the touch point relative to the upper edge of the XComponent.| 
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype)[type](_o_h___native_x_component.md#type-13) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN |  Type of the touch event.| 
| double [size](_o_h___native_x_component.md#size-13) = 0.0 |  Contact area between the finger pad and the screen.| 
| float [force](_o_h___native_x_component.md#force-13) = 0.0 |  Pressure of the touch event.| 
| long long [timeStamp](_o_h___native_x_component.md#timestamp-13) = 0 | Timestamp of the touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.| 
| bool [isPressed](_o_h___native_x_component.md#ispressed) = false |  Whether the touch point is pressed. **true**: The touch point is pressed. **false**: The touch point is not pressed.|
