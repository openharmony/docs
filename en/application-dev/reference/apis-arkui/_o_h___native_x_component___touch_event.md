# OH_NativeXComponent_TouchEvent


## Overview

Describes the touch event.

**Since:**
8

**Related Modules:**

[Native XComponent](_o_h___native_x_component.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [id](_o_h___native_x_component.md#id-22) = 0 | Unique identifier of the finger. | 
| [screenX](_o_h___native_x_component.md#screenx-23) = 0.0 |  X coordinate of the touch point relative to the left edge of the screen. | 
| [screenY](_o_h___native_x_component.md#screeny-23) = 0.0 | Y coordinate of the touch point relative to the upper edge of the screen.  | 
| [x](_o_h___native_x_component.md#x-23) = 0.0 | X coordinate of the touch point relative to the left edge of the XComponent. | 
| [y](_o_h___native_x_component.md#y-23) = 0.0 | Y coordinate of the touch point relative to the upper edge of the XComponent. | 
| [type](_o_h___native_x_component.md#type-22) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | Touch type of the touch event. | 
| [size](_o_h___native_x_component.md#size-22) = 0.0 | Contact area between the finger pad and the screen. | 
| [force](_o_h___native_x_component.md#force-22) = 0.0 | Pressure of the current touch event. | 
| [deviceId](_o_h___native_x_component.md#deviceid) = 0 | ID of the device where the current touch event is triggered. | 
| [timeStamp](_o_h___native_x_component.md#timestamp-22) = 0 | Timestamp of the current touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds. | 
| [touchPoints](_o_h___native_x_component.md#touchpoints) [OH_MAX_TOUCH_POINTS_NUMBER] | Array of the current touch points. | 
| [numPoints](_o_h___native_x_component.md#numpoints) = 0 | Number of current touch points. | 
