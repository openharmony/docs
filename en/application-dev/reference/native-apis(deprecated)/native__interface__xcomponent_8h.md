# native_interface_xcomponent.h


## Overview

Declares the APIs for accessing **NativeXComponent**.

**Since**

8

**Related Modules**

[Native XComponent](_o_h___native_x_component.md)


## Summary


### Structs

| Name                                                        | Description                               |
| ------------------------------------------------------------ | ----------------------------------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) | Describes the touch point of the touch event.           |
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | Describes the touch event.                         |
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | Describes the mouse event.                         |
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | Registers callbacks for the surface lifecycle and touch event.|
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | Registers callbacks for the mouse event.               |
| [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) | Defines the expected frame rate range.                 |


### Types

| Name                                      | Description                                  |
| ---------------------------------------- | ------------------------------------ |
| [OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) | Provides an encapsulated **OH_NativeXComponent** instance.         |
| [OH_NativeXComponent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_callback) | Registers callbacks for the surface lifecycle and touch event.               |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_mouseevent_callback) | Registers callbacks for the mouse event.                          |
| [OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) | Provides an encapsulated **OH_NativeXComponent_KeyEvent** instance.|


### Enums

| Name                                    | Description        |
| ---------------------------------------- | ---------- |
| { OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2 } | Enumerates the API access states.|
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype) {<br>OH_NATIVEXCOMPONENT_DOWN = 0, OH_NATIVEXCOMPONENT_UP, OH_NATIVEXCOMPONENT_MOVE, OH_NATIVEXCOMPONENT_CANCEL,<br>OH_NATIVEXCOMPONENT_UNKNOWN<br>} | Enumerates the touch event types.   |
| [OH_NativeXComponent_TouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_touchpointtooltype) {<br>OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN = 0, OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER, OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN, OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER,<br>OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH, OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL, OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH, OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE,<br>OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS<br>} | Enumerates the touch point tool types.  |
| [OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype) {<br>OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN = 0, OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE, OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN, OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD,<br>OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK, OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD<br>} | Enumerates the touch event source types.  |
| [OH_NativeXComponent_MouseEventAction](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventaction) { OH_NATIVEXCOMPONENT_MOUSE_NONE = 0, OH_NATIVEXCOMPONENT_MOUSE_PRESS, OH_NATIVEXCOMPONENT_MOUSE_RELEASE, OH_NATIVEXCOMPONENT_MOUSE_MOVE } | Enumerates the mouse event actions.   |
| [OH_NativeXComponent_MouseEventButton](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventbutton) {<br>OH_NATIVEXCOMPONENT_NONE_BUTTON = 0, OH_NATIVEXCOMPONENT_LEFT_BUTTON = 0x01, OH_NATIVEXCOMPONENT_RIGHT_BUTTON = 0x02, OH_NATIVEXCOMPONENT_MIDDLE_BUTTON = 0x04,<br>OH_NATIVEXCOMPONENT_BACK_BUTTON = 0x08, OH_NATIVEXCOMPONENT_FORWARD_BUTTON = 0x10<br>} | Enumerates the mouse event buttons.   |


### Functions

| Name                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| [OH_NativeXComponent_GetXComponentId](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentid) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, char \*id, uint64_t \*size) | Obtains the ID of the ArkUI XComponent.           |
| [OH_NativeXComponent_GetXComponentSize](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentsize) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, uint64_t \*width, uint64_t \*height) | Obtains the size of the surface held by the ArkUI XComponent. |
| [OH_NativeXComponent_GetXComponentOffset](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentoffset) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, double \*x, double \*y) | Obtains the offset of the ArkUI XComponent relative to the upper left vertex of the screen.|
| [OH_NativeXComponent_GetTouchEvent](_o_h___native_x_component.md#oh_nativexcomponent_gettouchevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) \*touchEvent) | Obtains the touch event scheduled by the ArkUI XComponent.       |
| [OH_NativeXComponent_GetTouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtooltype) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint32_t pointIndex, [OH_NativeXComponent_TouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_touchpointtooltype) \*toolType) | Obtains the ArkUI XComponent touch point tool type.       |
| [OH_NativeXComponent_GetTouchPointTiltX](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtiltx) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltX) | Obtains the angle between the Y-Z plane of the ArkUI XComponent touch point and the x-axis.    |
| [OH_NativeXComponent_GetTouchPointTiltY](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtilty) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltY) | Obtains the angle between the Y-Z plane of the ArkUI XComponent touch point and the y-axis.    |
| [OH_NativeXComponent_GetMouseEvent](_o_h___native_x_component.md#oh_nativexcomponent_getmouseevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) \*mouseEvent) | Obtains the mouse event scheduled by ArkUI XComponent.       |
| [OH_NativeXComponent_RegisterCallback](_o_h___native_x_component.md#oh_nativexcomponent_registercallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) \*callback) | Registers a callback for this **OH_NativeXComponent** instance.          |
| [OH_NativeXComponent_RegisterMouseEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registermouseeventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) \*callback) | Registers the mouse event callback for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_RegisterFocusEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerfocuseventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | Registers the focus obtaining event callback for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_RegisterKeyEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerkeyeventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | Registers the key event callback for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_RegisterBlurEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerblureventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | Registers the focus loss event callback for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_GetKeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_getkeyevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*\*keyEvent) | Obtains the key event scheduled by the ArkUI XComponent.       |
| [OH_NativeXComponent_GetKeyEventAction](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventaction) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_KeyAction](_o_h___native_x_component.md#oh_nativexcomponent_keyaction) \*action) | Obtains the action of the specified key event.                          |
| [OH_NativeXComponent_GetKeyEventCode](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventcode) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_KeyCode](_o_h___native_x_component.md#oh_nativexcomponent_keycode) \*code) | Obtains the key code of the specified key event.                         |
| [OH_NativeXComponent_GetKeyEventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventsourcetype) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype) \*sourceType) | Obtains the source type of the specified key event.                       |
| [OH_NativeXComponent_GetKeyEventDeviceId](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventdeviceid) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, int64_t \*deviceId) | Obtains the device ID of the specified key event.                        |
| [OH_NativeXComponent_GetKeyEventTimeStamp](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventtimestamp) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, int64_t \*timeStamp) | Obtains the timestamp of the specified key event.                         |
| [OH_NativeXComponent_SetExpectedFrameRateRange](_o_h___native_x_component.md#oh_nativexcomponent_setexpectedframeraterange) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) \*range) | Sets the expected frame rate range. |
| [OH_NativeXComponent_RegisterOnFrameCallback](_o_h___native_x_component.md#oh_nativexcomponent_registeronframecallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint64_t timestamp, uint64_t targetTimestamp)) | Registers the display update callback for this **OH_NativeXComponent** instance and enables the callback for each frame. |
| [OH_NativeXComponent_UnregisterOnFrameCallback](_o_h___native_x_component.md#oh_nativexcomponent_unregisteronframecallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component) | Deregisters the display update callback for this **OH_NativeXComponent** instance and diables the callback for each frame. |

### Variables

| Name                                      | Description                       |
| ---------------------------------------- | ------------------------- |
| **OH_XCOMPONENT_ID_LEN_MAX** = 128 | Maximum length of the ArkUI XComponent ID.|
| **OH_MAX_TOUCH_POINTS_NUMBER** = 10 | Maximum number of identifiable touch points in a touch event.      |
