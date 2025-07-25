# OH_NativeXComponent_MouseEvent


## Overview

Defines a mouse event.

**Since**: 9

**Related module**: [Native XComponent](_o_h___native_x_component.md)

**Header file**: [native_interface_xcomponent.h](native__interface__xcomponent_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| float [x](_o_h___native_x_component.md#x-34) = 0.0 |  X coordinate of the clicked point relative to the upper left corner of the component.| 
| float [y](_o_h___native_x_component.md#y-34) = 0.0|  Y-coordinate of the clicked point relative to the upper left corner of the component.| 
| float [screenX](_o_h___native_x_component.md#screenx-34) = 0.0|  X coordinate of the click point relative to the upper left corner of the application screen where the XComponent is located.| 
| float [screenY](_o_h___native_x_component.md#screeny-34) = 0.0|  Y coordinate of the click point relative to the upper left corner of the application window where the XComponent is located.| 
| int64_t [timestamp](_o_h___native_x_component.md#timestamp) = 0|  Timestamp of the mouse event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.| 
| [OH_NativeXComponent_MouseEventAction](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventaction) [action](_o_h___native_x_component.md#action) = OH_NativeXComponent_MouseEventAction::OH_NATIVEXCOMPONENT_MOUSE_NONE|  Action of the mouse event.| 
| [OH_NativeXComponent_MouseEventButton](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventbutton) [button](_o_h___native_x_component.md#button) = OH_NativeXComponent_MouseEventButton::OH_NATIVEXCOMPONENT_NONE_BUTTON|  Button of the mouse event.| 
