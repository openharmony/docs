# ArkUI_EventModule


## Overview

Declares the UI input event capabilities provided by ArkUI on the native side.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [ui_input_event.h](ui__input__event_8h.md) | Provides ArkUI event definitions on the native side.<br> **Library**: libace_ndk.z.so| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [ArkUI_UIInputEvent](#arkui_uiinputevent) [ArkUI_UIInputEvent](#arkui_uiinputevent) | Defines the UI input event. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ArkUI_UIInputEvent_Type](#arkui_uiinputevent_type) { ARKUI_UIINPUTEVENT_TYPE_UNKNOWN = 0, ARKUI_UIINPUTEVENT_TYPE_TOUCH = 1, ARKUI_UIINPUTEVENT_TYPE_AXIS = 2, ARKUI_UIINPUTEVENT_TYPE_MOUSE = 3 } | Enumerates the UI input event types. | 
| {<br>OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2, UI_TOUCH_EVENT_ACTION_CANCEL = 0,<br>UI_TOUCH_EVENT_ACTION_DOWN = 1, UI_TOUCH_EVENT_ACTION_MOVE = 2, UI_TOUCH_EVENT_ACTION_UP = 3<br>} | Enumerates the action codes of the input event. | 
| {<br>UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN = 0, UI_INPUT_EVENT_TOOL_TYPE_FINGER = 1, UI_INPUT_EVENT_TOOL_TYPE_PEN = 2, UI_INPUT_EVENT_TOOL_TYPE_MOUSE = 3,<br>UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD = 4, UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK = 5<br>} | Enumerates the tool types of the input event. | 
| { UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN = 0, UI_INPUT_EVENTT_SOURCE_TYPE_MOUSE = 1, UI_INPUT_EVENTT_SOURCE_TYPE_TOUCH_SCREEN = 2 } | Enumerates the source types of the input event. | 
| [HitTestMode](#hittestmode) { HTMDEFAULT = 0, HTMBLOCK, HTMTRANSPARENT, HTMNONE } | Enumerates the hit test modes. | 
| { UI_MOUSE_EVENT_ACTION_UNKNOWN = 0, UI_MOUSE_EVENT_ACTION_PRESS = 1, UI_MOUSE_EVENT_ACTION_RELEASE = 2, UI_MOUSE_EVENT_ACTION_MOVE = 3 } | Enumerates the action codes of the mouse event. | 
| {<br>UI_MOUSE_EVENT_BUTTON_NONE = 0, UI_MOUSE_EVENT_BUTTON_LEFT = 1, UI_MOUSE_EVENT_BUTTON_RIGHT = 2, UI_MOUSE_EVENT_BUTTON_MIDDLE = 3,<br>UI_MOUSE_EVENT_BUTTON_BACK = 4, UI_MOUSE_EVENT_BUTTON_FORWARD = 5<br>} | Enumerates the button types of the mouse event. | 
| [ArkUI_ModifierKeyName](#arkui_modifierkeyname) { ARKUI_MODIFIER_KEY_CTRL = 1 &lt;&lt; 0, ARKUI_MODIFIER_KEY_SHIFT = 1 &lt;&lt; 1, ARKUI_MODIFIER_KEY_ALT = 1 &lt;&lt; 2, ARKUI_MODIFIER_KEY_FN = 1 &lt;&lt; 3 } | Enumerates the modifier keys. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_ArkUI_UIInputEvent_GetType](#oh_arkui_uiinputevent_gettype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the type of a UI input event. | 
| int32_t [OH_ArkUI_UIInputEvent_GetAction](#oh_arkui_uiinputevent_getaction) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the action type of this UI input event. | 
| int32_t [OH_ArkUI_UIInputEvent_GetSourceType](#oh_arkui_uiinputevent_getsourcetype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the source type of a UI input event. | 
| int32_t [OH_ArkUI_UIInputEvent_GetToolType](#oh_arkui_uiinputevent_gettooltype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the tool type of a UI input event. | 
| int64_t [OH_ArkUI_UIInputEvent_GetEventTime](#oh_arkui_uiinputevent_geteventtime) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the time when a specified UI input event occurs. | 
| uint32_t [OH_ArkUI_PointerEvent_GetPointerCount](#oh_arkui_pointerevent_getpointercount) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the number of touch points from a directional input event (such as a touch event, mouse event, or axis event). | 
| int32_t [OH_ArkUI_PointerEvent_GetPointerId](#oh_arkui_pointerevent_getpointerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the ID of a touch point from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetX](#oh_arkui_pointerevent_getx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the X-coordinate relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetXByIndex](#oh_arkui_pointerevent_getxbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the X-coordinate of a specific touch point relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetY](#oh_arkui_pointerevent_gety) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the Y-coordinate relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetYByIndex](#oh_arkui_pointerevent_getybyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the Y-coordinate of a specific touch point relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetWindowX](#oh_arkui_pointerevent_getwindowx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the X-coordinate relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetWindowXByIndex](#oh_arkui_pointerevent_getwindowxbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the X-coordinate of a specific touch point relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetWindowY](#oh_arkui_pointerevent_getwindowy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the Y-coordinate relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetWindowYByIndex](#oh_arkui_pointerevent_getwindowybyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the Y-coordinate of a specific touch point relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetDisplayX](#oh_arkui_pointerevent_getdisplayx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the X-coordinate relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetDisplayXByIndex](#oh_arkui_pointerevent_getdisplayxbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the X-coordinate of a specific touch point relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetDisplayY](#oh_arkui_pointerevent_getdisplayy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the Y-coordinate relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetDisplayYByIndex](#oh_arkui_pointerevent_getdisplayybyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the Y-coordinate of a specific touch point relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetPressure](#oh_arkui_pointerevent_getpressure) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the pressure applied to the touchscreen from a directional input event (for example, a touch event). | 
| float [OH_ArkUI_PointerEvent_GetTiltX](#oh_arkui_pointerevent_gettiltx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the angle relative to the YZ plane from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a rightward tilt. | 
| float [OH_ArkUI_PointerEvent_GetTiltY](#oh_arkui_pointerevent_gettilty) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the angle relative to the XZ plane from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a downward tilt. | 
| float [OH_ArkUI_PointerEvent_GetTouchAreaWidth](#oh_arkui_pointerevent_gettouchareawidth) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the width of the touch area from a directional input event (for example, a touch event). | 
| float [OH_ArkUI_PointerEvent_GetTouchAreaHeight](#oh_arkui_pointerevent_gettouchareaheight) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | Obtains the height of the touch area from a directional input event (for example, a touch event). | 
| uint32_t [OH_ArkUI_PointerEvent_GetHistorySize](#oh_arkui_pointerevent_gethistorysize) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the number of historical events from a directional input event (such as a touch event, mouse event, or axis event). | 
| int64_t [OH_ArkUI_PointerEvent_GetHistoryEventTime](#oh_arkui_pointerevent_gethistoryeventtime) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t historyIndex) | Obtains the occurrence time of a historical event from a directional input event (such as a touch event, mouse event, or axis event). | 
| uint32_t [OH_ArkUI_PointerEvent_GetHistoryPointerCount](#oh_arkui_pointerevent_gethistorypointercount) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t historyIndex) | Obtains the number of touch points in a specific historical event from a directional input event (such as a touch event, mouse event, or axis event). | 
| int32_t [OH_ArkUI_PointerEvent_GetHistoryPointerId](#oh_arkui_pointerevent_gethistorypointerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the ID of a touch point from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryX](#oh_arkui_pointerevent_gethistoryx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the X-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryY](#oh_arkui_pointerevent_gethistoryy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the Y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryWindowX](#oh_arkui_pointerevent_gethistorywindowx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the X-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryWindowY](#oh_arkui_pointerevent_gethistorywindowy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the Y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryDisplayX](#oh_arkui_pointerevent_gethistorydisplayx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the X-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryDisplayY](#oh_arkui_pointerevent_gethistorydisplayy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the Y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryPressure](#oh_arkui_pointerevent_gethistorypressure) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the pressure applied to the touchscreen in a specific historical event from a directional input event (for example, a touch event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryTiltX](#oh_arkui_pointerevent_gethistorytiltx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the angle relative to the YZ plane in a specific historical event from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a rightward tilt. | 
| float [OH_ArkUI_PointerEvent_GetHistoryTiltY](#oh_arkui_pointerevent_gethistorytilty) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the angle relative to the XZ plane in a specific historical event from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a downward tilt. | 
| float [OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth](#oh_arkui_pointerevent_gethistorytouchareawidth) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the width of the touch area in a specific historical event from a directional input event (for example, a touch event). | 
| float [OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight](#oh_arkui_pointerevent_gethistorytouchareaheight) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | Obtains the height of the touch area in a specific historical event from a directional input event (for example, a touch event). | 
| double [OH_ArkUI_AxisEvent_GetVerticalAxisValue](#oh_arkui_axisevent_getverticalaxisvalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the value of the vertical scroll axis for this axis event. | 
| double [OH_ArkUI_AxisEvent_GetHorizontalAxisValue](#oh_arkui_axisevent_gethorizontalaxisvalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the value of the horizontal scroll axis for this axis event. | 
| double [OH_ArkUI_AxisEvent_GetPinchAxisScaleValue](#oh_arkui_axisevent_getpinchaxisscalevalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the scale value of the pinch axis for this axis event. | 
| int32_t [OH_ArkUI_PointerEvent_SetInterceptHitTestMode](#oh_arkui_pointerevent_setintercepthittestmode) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, [HitTestMode](#hittestmode) mode) | Sets how the component behaves during hit testing. | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseButton](#oh_arkui_mouseevent_getmousebutton) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the button type of a mouse event. | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseAction](#oh_arkui_mouseevent_getmouseaction) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the action type of a mouse event. | 
| int32_t [OH_ArkUI_PointerEvent_SetStopPropagation](#oh_arkui_pointerevent_setstoppropagation) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, bool stopPropagation) | Sets whether to stop event propagation. | 


## Type Description


### ArkUI_UIInputEvent

```
typedef struct ArkUI_UIInputEvent ArkUI_UIInputEvent
```
**Description**

Defines the UI input event.

**Since**: 12


## Enum Description


### anonymous enum

```
anonymous enum
```
**Description**

Enumerates the action codes of the input event.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS  | Success. | 
| OH_NATIVEXCOMPONENT_RESULT_FAILED  | Failure. | 
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER  | Invalid parameter. | 
| UI_TOUCH_EVENT_ACTION_CANCEL  | Cancellation of touch. | 
| UI_TOUCH_EVENT_ACTION_DOWN  | Pressing of touch. | 
| UI_TOUCH_EVENT_ACTION_MOVE  | Moving of touch. | 
| UI_TOUCH_EVENT_ACTION_UP  | Lifting of touch. | 


### anonymous enum

```
anonymous enum
```
**Description**

Enumerates the tool types of the input event.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN  | Unknown tool type. | 
| UI_INPUT_EVENT_TOOL_TYPE_FINGER  | Finger. | 
| UI_INPUT_EVENT_TOOL_TYPE_PEN  | Stylus. | 
| UI_INPUT_EVENT_TOOL_TYPE_MOUSE  | Mouse. | 
| UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD  | Touchpad. | 
| UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK  | Joystick. | 


### anonymous enum

```
anonymous enum
```
**Description**

Enumerates the source types of the input event.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN  | Unknown source type. | 
| UI_INPUT_EVENTT_SOURCE_TYPE_MOUSE  | Mouse. | 
| UI_INPUT_EVENTT_SOURCE_TYPE_TOUCH_SCREEN  | Touchscreen. | 


### anonymous enum

```
anonymous enum
```
**Description**

Enumerates the action codes of the mouse event.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| UI_MOUSE_EVENT_ACTION_UNKNOWN  | Unknown action. | 
| UI_MOUSE_EVENT_ACTION_PRESS  | The mouse button is pressed. | 
| UI_MOUSE_EVENT_ACTION_RELEASE  | The mouse button is released. | 
| UI_MOUSE_EVENT_ACTION_MOVE  | The mouse cursor moves. | 


### anonymous enum

```
anonymous enum
```
**Description**

Enumerates the button types of the mouse event.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| UI_MOUSE_EVENT_BUTTON_NONE  | No button. | 
| UI_MOUSE_EVENT_BUTTON_LEFT  | Left button on the mouse. | 
| UI_MOUSE_EVENT_BUTTON_RIGHT  | Right button on the mouse. | 
| UI_MOUSE_EVENT_BUTTON_MIDDLE  | Middle button on the mouse. | 
| UI_MOUSE_EVENT_BUTTON_BACK  | Back button on the left of the mouse. | 
| UI_MOUSE_EVENT_BUTTON_FORWARD  | Forward button on the left of the mouse. | 


### ArkUI_ModifierKeyName

```
enum ArkUI_ModifierKeyName
```
**Description**

Enumerates the modifier keys.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ARKUI_MODIFIER_KEY_CTRL  | Ctrl.  | 
| ARKUI_MODIFIER_KEY_SHIFT  | Shift.  | 
| ARKUI_MODIFIER_KEY_ALT  | Alt.  | 
| ARKUI_MODIFIER_KEY_FN  | Fn.  | 


### ArkUI_UIInputEvent_Type

```
enum ArkUI_UIInputEvent_Type
```
**Description**

Enumerates the UI input event types.

**Since**: 12


### HitTestMode

```
enum HitTestMode
```
**Description**

Enumerates the hit test modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| HTMDEFAULT  | Both the node and its child node respond to the hit test of a touch event, but its sibling node is blocked from the hit test. | 
| HTMBLOCK  | The node responds to the hit test of a touch event, but its child node and sibling node are blocked from the hit test. | 
| HTMTRANSPARENT  | Both the node and its child node respond to the hit test of a touch event, and its sibling node is also considered during the hit test. | 
| HTMNONE  | The node does not respond to the hit test of a touch event, but its child node and sibling node are considered during the hit test. | 


## Function Description


### OH_ArkUI_AxisEvent_GetHorizontalAxisValue()

```
double OH_ArkUI_AxisEvent_GetHorizontalAxisValue (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the value of the horizontal scroll axis for this axis event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the value of the horizontal scroll axis of the current axis event; returns **0.0** if any parameter error occurs.


### OH_ArkUI_AxisEvent_GetPinchAxisScaleValue()

```
double OH_ArkUI_AxisEvent_GetPinchAxisScaleValue (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the scale value of the pinch axis for this axis event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the scale value of the pinch axis of the current axis event; returns **0.0** if any parameter error occurs.


### OH_ArkUI_AxisEvent_GetVerticalAxisValue()

```
double OH_ArkUI_AxisEvent_GetVerticalAxisValue (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the value of the vertical scroll axis for this axis event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the value of the vertical scroll axis of the current axis event; returns **0.0** if any parameter error occurs.


### OH_ArkUI_MouseEvent_GetMouseAction()

```
int32_t OH_ArkUI_MouseEvent_GetMouseAction (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the action type of a mouse event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the mouse action type. The value **1** indicates that the mouse button is pressed, **2** indicates that the mouse button is released, and **3** indicates that the mouse cursor moves.


### OH_ArkUI_MouseEvent_GetMouseButton()

```
int32_t OH_ArkUI_MouseEvent_GetMouseButton (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the button type of a mouse event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the mouse button type. The value **1** indicates the left button, **2** indicates the right button, **3** indicates the middle button, **4** indicates the back button, and **5** indicates the forward button.


### OH_ArkUI_PointerEvent_GetDisplayX()

```
float OH_ArkUI_PointerEvent_GetDisplayX (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the X-coordinate relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current screen; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetDisplayXByIndex()

```
float OH_ArkUI_PointerEvent_GetDisplayXByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the X-coordinate of a specific touch point relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current screen; returns **0.0f** if any parameter error occurs.

### OH_ArkUI_PointerEvent_GetDisplayY()

```
float OH_ArkUI_PointerEvent_GetDisplayY (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the Y-coordinate relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current screen; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetDisplayYByIndex()

```
float OH_ArkUI_PointerEvent_GetDisplayYByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the Y-coordinate of a specific touch point relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current screen; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetHistoryDisplayX()

```
float OH_ArkUI_PointerEvent_GetHistoryDisplayX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the X-coordinate of a specific touch point in a historical event relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current screen; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetHistoryDisplayY()

```
float OH_ArkUI_PointerEvent_GetHistoryDisplayY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the Y-coordinate of a specific touch point in a historical event relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current screen; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetHistoryEventTime()

```
int64_t OH_ArkUI_PointerEvent_GetHistoryEventTime (const ArkUI_UIInputEvent * event, uint32_t historyIndex )
```
**Description**

Obtains the occurrence time of a historical event from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the time when the UI input event occurs; returns **0** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetHistoryPointerCount()

```
uint32_t OH_ArkUI_PointerEvent_GetHistoryPointerCount (const ArkUI_UIInputEvent * event, uint32_t historyIndex )
```
**Description**

Obtains the number of touch points in a historical event from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the number of touch points in the specified historical event


### OH_ArkUI_PointerEvent_GetHistoryPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetHistoryPointerId (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the ID of a touch point from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the ID of the corresponding touch point in the specified historical event.


### OH_ArkUI_PointerEvent_GetHistoryPressure()

```
float OH_ArkUI_PointerEvent_GetHistoryPressure (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the pressure applied to the touchscreen in a historical event from a directional input event (for example, a touch event)..

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the pressure applied to the touchscreen; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetHistorySize()

```
uint32_t OH_ArkUI_PointerEvent_GetHistorySize (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the number of historical events from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the number of historical events.


### OH_ArkUI_PointerEvent_GetHistoryTiltX()

```
float OH_ArkUI_PointerEvent_GetHistoryTiltX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the angle relative to the YZ plane in a historical event from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a rightward tilt.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the angle relative to the YZ plane.


### OH_ArkUI_PointerEvent_GetHistoryTiltY()

```
float OH_ArkUI_PointerEvent_GetHistoryTiltY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the angle relative to the XZ plane in a historical event from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a downward tilt.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the angle relative to the XZ plane.


### OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the height of the touch area in a specific historical event from a directional input event (for example, a touch event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the height of the touch area.


### OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth()

```
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the width of the touch area in a specific historical event from a directional input event (for example, a touch event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the width of the touch area.


### OH_ArkUI_PointerEvent_GetHistoryWindowX()

```
float OH_ArkUI_PointerEvent_GetHistoryWindowX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the X-coordinate of a specific touch point in a historical event relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current application window; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetHistoryWindowY()

```
float OH_ArkUI_PointerEvent_GetHistoryWindowY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the Y-coordinate of a specific touch point in a historical event relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current application window; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetHistoryX()

```
float OH_ArkUI_PointerEvent_GetHistoryX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the X-coordinate of a specific touch point in a historical event relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current component; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetHistoryY()

```
float OH_ArkUI_PointerEvent_GetHistoryY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**Description**

Obtains the Y-coordinate of a specific touch point in a historical event relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| historyIndex | Index of the target historical event. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current component; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetPointerCount()

```
uint32_t OH_ArkUI_PointerEvent_GetPointerCount (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the number of touch points from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the number of touch points for the directional input event.


### OH_ArkUI_PointerEvent_GetPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetPointerId (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the ID of a touch point from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the ID of the corresponding touch point.


### OH_ArkUI_PointerEvent_GetPressure()

```
float OH_ArkUI_PointerEvent_GetPressure (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the pressure applied to the touchscreen from a directional input event (for example, a touch event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the pressure applied to the touchscreen; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetTiltX()

```
float OH_ArkUI_PointerEvent_GetTiltX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the angle relative to the YZ plane from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a rightward tilt.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the angle relative to the YZ plane.


### OH_ArkUI_PointerEvent_GetTiltY()

```
float OH_ArkUI_PointerEvent_GetTiltY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the angle relative to the XZ plane from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a downward tilt.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the angle relative to the XZ plane.


### OH_ArkUI_PointerEvent_GetTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetTouchAreaHeight (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the height of the touch area from a directional input event (for example, a touch event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the height of the touch area.


### OH_ArkUI_PointerEvent_GetTouchAreaWidth()

```
float OH_ArkUI_PointerEvent_GetTouchAreaWidth (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the width of the touch area from a directional input event (for example, a touch event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the width of the touch area.


### OH_ArkUI_PointerEvent_GetWindowX()

```
float OH_ArkUI_PointerEvent_GetWindowX (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the X-coordinate relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current application window; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetWindowXByIndex()

```
float OH_ArkUI_PointerEvent_GetWindowXByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the X-coordinate of a specific touch point relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current application window; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetWindowY()

```
float OH_ArkUI_PointerEvent_GetWindowY (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the Y-coordinate relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current application window; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetWindowYByIndex()

```
float OH_ArkUI_PointerEvent_GetWindowYByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the Y-coordinate of a specific touch point relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current application window; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetX()

```
float OH_ArkUI_PointerEvent_GetX (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the X-coordinate relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current component; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetXByIndex()

```
float OH_ArkUI_PointerEvent_GetXByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the X-coordinate of a specific touch point relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the X-coordinate relative to the upper left corner of the current component; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetY()

```
float OH_ArkUI_PointerEvent_GetY (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the Y-coordinate relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current component; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetYByIndex()

```
float OH_ArkUI_PointerEvent_GetYByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**Description**

Obtains the Y-coordinate of a specific touch point relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the Y-coordinate relative to the upper left corner of the current component; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_PointerEvent_SetInterceptHitTestMode()

```
int32_t OH_ArkUI_PointerEvent_SetInterceptHitTestMode (const ArkUI_UIInputEvent * event, HitTestMode mode )
```
**Description**

Sets how the component behaves during hit testing.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| mode | How the component behaves during hit testing. The parameter type is [HitTestMode](#hittestmode). | 

**Returns**

Returns the status code of the execution.


### OH_ArkUI_PointerEvent_SetStopPropagation()

```
int32_t OH_ArkUI_PointerEvent_SetStopPropagation (const ArkUI_UIInputEvent * event, bool stopPropagation )
```
**Description**

Sets whether to stop event propagation.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| stopPropagation | Whether to stop event propagation. | 

**Returns**

Returns the status code of the execution. Returns **0** if the operation is successful; returns **401** if the operation fails, possibly because a parameter error, for example, null pointer for the **event** parameter, occurs.


### OH_ArkUI_UIInputEvent_GetAction()

```
int32_t OH_ArkUI_UIInputEvent_GetAction (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the action type of this UI input event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the action type of the UI input event; returns **0** if any parameter error occurs.


### OH_ArkUI_UIInputEvent_GetEventTime()

```
int64_t OH_ArkUI_UIInputEvent_GetEventTime (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the time when a specified UI input event occurs.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the time when the UI input event occurs; returns **0** if any parameter error occurs.


### OH_ArkUI_UIInputEvent_GetSourceType()

```
int32_t OH_ArkUI_UIInputEvent_GetSourceType (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the source type of a UI input event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the source type of the UI input event.


### OH_ArkUI_UIInputEvent_GetToolType()

```
int32_t OH_ArkUI_UIInputEvent_GetToolType (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the tool type of a UI input event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the tool type of the UI input event.


### OH_ArkUI_UIInputEvent_GetType()

```
int32_t OH_ArkUI_UIInputEvent_GetType (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the type of a UI input event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the type of the UI input event; returns **0** if any parameter error occurs.
