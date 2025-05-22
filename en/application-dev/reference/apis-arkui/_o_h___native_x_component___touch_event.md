# OH_NativeXComponent_TouchEvent


## Overview

Defines the touch event.

**Since**: 8

**Related module**: [Native XComponent](_o_h___native_x_component.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [id](_o_h___native_x_component.md#id-22) = 0 |  Unique identifier of the finger.| 
| float [screenX](_o_h___native_x_component.md#screenx-23) = 0.0 |  X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.| 
| float [screenY](_o_h___native_x_component.md#screeny-23) = 0.0 |  Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.| 
| float [x](_o_h___native_x_component.md#x-23) = 0.0 |  X coordinate of the touch point relative to the left edge of the XComponent.| 
| float [y](_o_h___native_x_component.md#y-23) = 0.0 |  Y coordinate of the touch point relative to the upper edge of the XComponent.| 
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype)[type](_o_h___native_x_component.md#type-22) = [OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN](_o_h___native_x_component.md) | Touch type of the touch event.| 
| double [size](_o_h___native_x_component.md#size-22) = 0.0 |  Contact area between the finger pad and the screen.| 
| float [force](_o_h___native_x_component.md#force-22) = 0.0 |  Pressure of the touch event.| 
| int64_t [deviceId](_o_h___native_x_component.md#deviceid) = 0 |  ID of the device where the current touch event is triggered.| 
| long long [timeStamp](_o_h___native_x_component.md#timestamp-22) = 0 |  Timestamp of the touch point. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.| 
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) [touchPoints](_o_h___native_x_component.md#touchpoints) [OH_MAX_TOUCH_POINTS_NUMBER] |  Array of the touch points.| 
| uint32_t [numPoints](_o_h___native_x_component.md#numpoints) = 0 |  Number of current touch points.| 
