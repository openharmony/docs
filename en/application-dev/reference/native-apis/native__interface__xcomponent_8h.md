# native_interface_xcomponent.h


## Overview

Declares the APIs used to access the native XComponent.

**Since:**

8

**Related Modules:**

[Native XComponent](_o_h___native_x_component.md)


## Summary


### Structs

| Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) | Describes the touch point of the touch event. |
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | Describes the touch event. |
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | Describes the mouse event.|
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | Registers a callback for the surface lifecycle and touch event.  |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | Registers a callback for the mouse event. |


### Types

| Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) | Provides an encapsulated OH_NativeXComponent instance. |
| [OH_NativeXComponent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_callback) | Registers a callback for the surface lifecycle and touch event. |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_mouseevent_callback) | Registers a callback for the mouse event.   |


### Enums

| Name | Description | 
| -------- | -------- |
| { OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, <br/>OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, <br/>OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2} | [Enumerates](_o_h___native_x_component.md#anonymous-enum)the API access states. |
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype) {  <br/>OH_NATIVEXCOMPONENT_DOWN = 0, <br/>OH_NATIVEXCOMPONENT_UP, <br/>OH_NATIVEXCOMPONENT_MOVE, <br/>OH_NATIVEXCOMPONENT_CANCEL,<br/>OH_NATIVEXCOMPONENT_UNKNOWN } | Enumerates the touch event types.   |
| [OH_NativeXComponent_MouseEventAction](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventaction) { <br/>OH_NATIVEXCOMPONENT_MOUSE_NONE = 0, <br/>OH_NATIVEXCOMPONENT_MOUSE_PRESS, <br/>OH_NATIVEXCOMPONENT_MOUSE_RELEASE, <br/>OH_NATIVEXCOMPONENT_MOUSE_MOVE } | Enumerates the mouse event actions.        |
| [OH_NativeXComponent_MouseEventButton](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventbutton) {  <br/>OH_NATIVEXCOMPONENT_NONE_BUTTON = 0, <br/>OH_NATIVEXCOMPONENT_LEFT_BUTTON = 0x01, <br/>OH_NATIVEXCOMPONENT_RIGHT_BUTTON = 0x02, <br/>OH_NATIVEXCOMPONENT_MIDDLE_BUTTON = 0x04,   <br/>OH_NATIVEXCOMPONENT_BACK_BUTTON = 0x08, <br/>OH_NATIVEXCOMPONENT_FORWARD_BUTTON = 0x10 } | Enumerates the mouse event buttons.   |


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent_GetXComponentId](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentid) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, char \*id, uint64_t \*size) | Obtains the ID of the ArkUI XComponent.   |
| [OH_NativeXComponent_GetXComponentSize](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentsize) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, uint64_t \*width, uint64_t \*height) | Obtains the size of the surface held by the ArkUI XComponent.  |
| [OH_NativeXComponent_GetXComponentOffset](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentoffset) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, double \*x, double \*y) | Obtains the offset of the ArkUI XComponent relative to the upper left vertex of the screen. |
| [OH_NativeXComponent_GetTouchEvent](_o_h___native_x_component.md#oh_nativexcomponent_gettouchevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) \*touchEvent) | Obtains the touch event scheduled by the ArkUI XComponent.              |
| [OH_NativeXComponent_GetMouseEvent](_o_h___native_x_component.md#oh_nativexcomponent_getmouseevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) \*mouseEvent) | Obtains the mouse event scheduled by ArkUI XComponent.   |
| [OH_NativeXComponent_RegisterCallback](_o_h___native_x_component.md#oh_nativexcomponent_registercallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) \*callback) | Registers a callback for this **OH_NativeXComponent** instance.  |
| [OH_NativeXComponent_RegisterMouseEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registermouseeventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) \*callback) | Registers a mouse event callback for this **OH_NativeXComponent** instance.     |


### Variables

| Name | Description | 
| -------- | -------- |
| **OH_XCOMPONENT_ID_LEN_MAX** = 128 | Maximum length of an ArkUI XComponent ID. |
| **OH_MAX_TOUCH_POINTS_NUMBER** = 10 | Maximum number of identifiable touch points in a touch event. |
