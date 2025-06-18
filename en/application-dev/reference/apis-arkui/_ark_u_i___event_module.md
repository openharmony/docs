# ArkUI_EventModule


## Overview

Declares the UI input event capabilities provided by ArkUI on the native side.

**Since**: 12


## Summary


### Files
| Name| Description| 
| -------- | -------- |
| [ui_input_event.h](ui__input__event_8h.md) | Provides ArkUI event definitions on the native side. | 


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
| { UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN = 0, UI_INPUT_EVENT_SOURCE_TYPE_MOUSE = 1, UI_INPUT_EVENT_SOURCE_TYPE_TOUCH_SCREEN = 2 } | Enumerates the source types of the input event. | 
| [HitTestMode](#hittestmode) { HTM_DEFAULT = 0, HTM_BLOCK, HTM_TRANSPARENT, HTM_NONE } | Enumerates the hit test modes. | 
| { UI_MOUSE_EVENT_ACTION_UNKNOWN = 0, UI_MOUSE_EVENT_ACTION_PRESS = 1, UI_MOUSE_EVENT_ACTION_RELEASE = 2, UI_MOUSE_EVENT_ACTION_MOVE = 3, UI_MOUSE_EVENT_ACTION_CANCEL = 13 } | Enumerates the action codes of the mouse event. | 
| {<br>UI_MOUSE_EVENT_BUTTON_NONE = 0, UI_MOUSE_EVENT_BUTTON_LEFT = 1, UI_MOUSE_EVENT_BUTTON_RIGHT = 2, UI_MOUSE_EVENT_BUTTON_MIDDLE = 3,<br>UI_MOUSE_EVENT_BUTTON_BACK = 4, UI_MOUSE_EVENT_BUTTON_FORWARD = 5<br>} | Enumerates the button types of the mouse event. | 
| [ArkUI_ModifierKeyName](#arkui_modifierkeyname) { ARKUI_MODIFIER_KEY_CTRL = 1 &lt;&lt; 0, ARKUI_MODIFIER_KEY_SHIFT = 1 &lt;&lt; 1, ARKUI_MODIFIER_KEY_ALT = 1 &lt;&lt; 2, ARKUI_MODIFIER_KEY_FN = 1 &lt;&lt; 3 } | Enumerates the modifier keys. | 
| {<br>UI_FOCUS_AXIS_EVENT_ABS_X = 0, UI_FOCUS_AXIS_EVENT_ABS_Y = 1, UI_FOCUS_AXIS_EVENT_ABS_Z = 2, UI_FOCUS_AXIS_EVENT_ABS_RZ = 3,<br>UI_FOCUS_AXIS_EVENT_ABS_GAS = 4, UI_FOCUS_AXIS_EVENT_ABS_BRAKE = 5, UI_FOCUS_AXIS_EVENT_ABS_HAT0X = 6, UI_FOCUS_AXIS_EVENT_ABS_HAT0Y = 7<br>} | Enumerates the axis types for focus axis events. | 
| {<br>ARKUI_EVENT_HAND_NONE = 0, ARKUI_EVENT_HAND_LEFT = 1, ARKUI_EVENT_HAND_RIGHT = 2<br>} | Defines whether an event is triggered by a left-hand or right-hand tap. | 


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
| int32_t [OH_ArkUI_PointerEvent_GetChangedPointerId](#oh_arkui_pointerevent_getchangedpointerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t \*pointerIndex) | Obtains the ID of the touch pointer that triggers the current touch event. | 
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
| int32_t [OH_ArkUI_AxisEvent_GetAxisAction](#oh_arkui_axisevent_getaxisaction)(const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the action type of the current axis event. | 
| int32_t [OH_ArkUI_PointerEvent_SetInterceptHitTestMode](#oh_arkui_pointerevent_setintercepthittestmode) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, [HitTestMode](#hittestmode) mode) | Sets how the component behaves during hit testing. | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseButton](#oh_arkui_mouseevent_getmousebutton) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the button type of a mouse event. | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseAction](#oh_arkui_mouseevent_getmouseaction) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the action type of a mouse event. | 
| int32_t [OH_ArkUI_PointerEvent_SetStopPropagation](#oh_arkui_pointerevent_setstoppropagation) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, bool stopPropagation) | Sets whether to stop event propagation. | 
| int32_t [OH_ArkUI_UIInputEvent_GetDeviceId](#oh_arkui_uiinputevent_getdeviceid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the ID of the input device that triggers a key event. | 
| int32_t [OH_ArkUI_UIInputEvent_GetPressedKeys](#oh_arkui_uiinputevent_getpressedkeys) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t \*pressedKeyCodes, int32_t \*length) | Obtains all pressed keys. Currently, only key events are supported. | 
| double [OH_ArkUI_FocusAxisEvent_GetAxisValue](#oh_arkui_focusaxisevent_getaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t \*axis) | Obtains the axis value of a focus axis event. | 
| int32_t [OH_ArkUI_FocusAxisEvent_SetStopPropagation](#oh_arkui_focusaxisevent_setstoppropagation) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool \*stopPropagation) | Sets whether to prevent a focus axis event from bubbling up. | 
| int32_t [OH_ArkUI_PointerEvent_GetInteractionHand](#oh_arkui_pointerevent_getinteractionhand) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [ArkUI_InteractionHand](_ark_u_i___event_module.md#interactionhand) \*hand) | Checks whether an event is triggered by a left-hand or right-hand tap. | 
| int32_t [OH_ArkUI_PointerEvent_GetInteractionHandByIndex](#oh_arkui_pointerevent_getinteractionhandbyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t pointerIndex, [ArkUI_InteractionHand](_ark_u_i___event_module.md#interactionhand) \*hand) | Checks whether an event is triggered by a left-hand or right-hand tap. | 
| float [OH_ArkUI_UIInputEvent_GetEventTargetWidth](#oh_arkui_uiinputevent_geteventtargetwidth) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | Obtains the width of the component hit by an event. |
| float [OH_ArkUI_UIInputEvent_GetEventTargetHeight](#oh_arkui_uiinputevent_geteventtargetheight) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | Obtains the height of the component hit by an event. |
| float [OH_ArkUI_UIInputEvent_GetEventTargetPositionX](#oh_arkui_uiinputevent_geteventtargetpositionx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | Obtains the X coordinate of the component hit by an event. |
| float [OH_ArkUI_UIInputEvent_GetEventTargetPositionY](#oh_arkui_uiinputevent_geteventtargetpositiony) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | Obtains the Y coordinate of the component hit by an event. |
| float [OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX](#oh_arkui_uiinputevent_geteventtargetglobalpositionx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | Obtains the global X coordinate of the component hit by an event. |
| float [OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY](#oh_arkui_uiinputevent_geteventtargetglobalpositiony) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | Obtains the global Y coordinate of the component hit by an event. |
| int32_t [OH_ArkUI_UIInputEvent_GetModifierKeyStates](#oh_arkui_uiinputevent_getmodifierkeystates) (const [ArkUI_UIInputEvent](#arkui_uiinputevent), uint64_t \*keys) | Obtains the state of the modifier keys in a UI input event. | 
| bool [OH_ArkUI_HoverEvent_IsHovered](#oh_arkui_hoverevent_ishovered) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | Checks whether the cursor is hovering over this component. |    
| int32_t [OH_ArkUI_PointerEvent_CreateClonedEvent](#oh_arkui_pointerevent_createclonedevent) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, [ArkUI_UIInputEvent](#arkui_uiinputevent) \*clonedevent) | Creates a cloned event pointer based on an event pointer. | 
| int32_t [OH_ArkUI_PointerEvent_DestroyClonedEvent](#oh_arkui_pointerevent_destroyclonedevent) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Destroys a cloned event pointer. | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventLocalPosition](#oh_arkui_pointerevent_setclonedeventlocalposition) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, float x, float y) | Sets the X and Y coordinates of a cloned event relative to the upper left corner of the current component. | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex](#oh_arkui_pointerevent_setclonedeventlocalpositionbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, float x, float y, int32_t pointerIndex) | Sets the X and Y coordinates of a specific contact point of a cloned event relative to the upper left corner of the current component. | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventActionType](#oh_arkui_pointerevent_setclonedeventactiontype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t actionType) | Sets the action type of a cloned event. | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId](#oh_arkui_pointerevent_setclonedeventchangedfingerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t fingerId) | Sets the touch point ID of a cloned pointer event. | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex](#oh_arkui_pointerevent_setclonedeventfingeridbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t fingerId, int32_t pointerIndex) | Sets the touch point ID of a specific contact point of a cloned event. | 
| int32_t [OH_ArkUI_PointerEvent_PostClonedEvent](#oh_arkui_pointerevent_postclonedevent) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) \*node, const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Posts a cloned event to a specific node. | 
| int64_t [OH_ArkUI_PointerEvent_GetPressedTimeByIndex](#oh_arkui_pointerevent_getpressedtimebyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t pointerIndex) | Obtains the press time of a specific touch point. | 
| float [OH_ArkUI_MouseEvent_GetRawDeltaX](#oh_arkui_mouseevent_getrawdeltax) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the x-axis offset of the mouse pointer position relative to the position in the previously reported mouse event. This value may be less than the difference between the two reported X coordinates when the mouse pointer is near the screen edge. | 
| float [OH_ArkUI_MouseEvent_GetRawDeltaY](#oh_arkui_mouseevent_getrawdeltay) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the y-axis offset of the mouse pointer position relative to the position in the previously reported mouse event. This value may be less than the difference between the two reported Y coordinates when the mouse pointer is near the screen edge. | 
| int32_t [OH_ArkUI_MouseEvent_GetPressedButtons](#oh_arkui_mouseevent_getpressedbuttons) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t* pressedButtons, int32_t* length) | Obtains the pressed buttons from a mouse event. | 
| int32_t [OH_ArkUI_UIInputEvent_GetTargetDisplayId](#oh_arkui_uiinputevent_gettargetdisplayid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the ID of the screen where the UI input event occurs.| 
| int32_t [OH_ArkUI_AxisEvent_SetPropagation](#oh_arkui_axisevent_setpropagation)(const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, bool propagation) | Sets whether to enable axis event propagation.|
| int32_t [OH_ArkUI_AxisEvent_GetScrollStep](#oh_arkui_axisevent_getscrollstep)(const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | Obtains the scroll step configuration of the mouse wheel axis event.|


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
| UI_INPUT_EVENT_SOURCE_TYPE_MOUSE  | Mouse. | 
| UI_INPUT_EVENT_SOURCE_TYPE_TOUCH_SCREEN  | Touchscreen. | 


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
| UI_MOUSE_EVENT_ACTION_CANCEL  | The mouse button action is canceled. | 


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
| HTM_DEFAULT  | Both the node and its child node respond to the hit test of a touch event, but its sibling node is blocked from the hit test. | 
| HTM_BLOCK  | The node responds to the hit test of a touch event, but its child node and sibling node are blocked from the hit test. | 
| HTM_TRANSPARENT  | Both the node and its child node respond to the hit test of a touch event, and its sibling node is also considered during the hit test. | 
| HTM_NONE  | The node does not respond to the hit test of a touch event, but its child node and sibling node are considered during the hit test. | 


### anonymous enum

```
anonymous enum
```
**Description**

Enumerates the axis types for focus axis events.

**Since**: 15

| Value| Description| 
| -------- | -------- |
| UI_FOCUS_AXIS_EVENT_ABS_X  | Game controller x-axis. | 
| UI_FOCUS_AXIS_EVENT_ABS_Y  | Game controller y-axis.| 
| UI_FOCUS_AXIS_EVENT_ABS_Z  | Game controller z-axis. | 
| UI_FOCUS_AXIS_EVENT_ABS_RZ  | Game controller rz-axis. | 
| UI_FOCUS_AXIS_EVENT_ABS_GAS  | Game controller GAS-axis.| 
| UI_FOCUS_AXIS_EVENT_ABS_BRAKE  | Game controller BRAKE-axis.  | 
| UI_FOCUS_AXIS_EVENT_ABS_HAT0X  | Game controller HAT0X-axis.  | 
| UI_FOCUS_AXIS_EVENT_ABS_HAT0Y  | Game controller HAT0Y-axis.| 

### InteractionHand

```
enum ArkUI_InteractionHand
```
**Description**

Defines whether an event is triggered by a left-hand or right-hand tap.

**Since**: 15

| Value| Description| 
| -------- | -------- |
| ARKUI_EVENT_HAND_NONE  | Unknown. | 
| ARKUI_EVENT_HAND_LEFT  | Left hand. | 
| ARKUI_EVENT_HAND_RIGHT  | Right hand. | 


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

### OH_ArkUI_AxisEvent_GetAxisAction()

```
int32_t OH_ArkUI_AxisEvent_GetAxisAction(const ArkUI_UIInputEvent* event)
```

**Description**

Obtains the action type of the current axis event.

**Since**: 15

**Parameters**

| Name | Description|
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the action type of the current axis event.


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

Obtains the X-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event).

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

Obtains the Y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current screen from a directional input event (such as a touch event, mouse event, or axis event).

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

Obtains the number of touch points in a specific historical event from a directional input event (such as a touch event, mouse event, or axis event).

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

Obtains the pressure applied to the touchscreen in a specific historical event from a directional input event (for example, a touch event).

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

Obtains the angle relative to the YZ plane in a specific historical event from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a rightward tilt.

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

Obtains the angle relative to the XZ plane in a specific historical event from a directional input event (for example, a touch event). The value range is [-90, 90]. A positive value indicates a downward tilt.

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

Obtains the X-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

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

Obtains the Y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current application window from a directional input event (such as a touch event, mouse event, or axis event).

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

Obtains the X-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

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

Obtains the Y-coordinate of a specific touch point in a specific historical event relative to the upper left corner of the current component from a directional input event (such as a touch event, mouse event, or axis event).

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


### OH_ArkUI_PointerEvent_GetChangedPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetChangedPointerId (const ArkUI_UIInputEvent * event, uint32_t * pointerIndex )
```
**Description**

Obtains the ID of the touch pointer that triggers the current touch event.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the status code of the execution. Returns **0** if the operation is successful; returns **401** if the operation fails, possibly because a parameter error, for example, null pointer for the **event** parameter, occurs.


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


### OH_ArkUI_UIInputEvent_GetDeviceId()

```
int32_t OH_ArkUI_UIInputEvent_GetDeviceId (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the ID of the input device that triggers a key event.

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 

**Returns**

Returns the device ID.


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


### OH_ArkUI_UIInputEvent_GetPressedKeys()

```
int32_t OH_ArkUI_UIInputEvent_GetPressedKeys (const ArkUI_UIInputEvent * event, int32_t * pressedKeyCodes, int32_t * length )
```
**Description**

Obtains all pressed keys. Currently, only key events are supported.

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 
| pressedKeyCodes | Array of all pressed keys. The caller is responsible for allocating the memory space to which the array points. | 
| length | Dual-purpose parameter: As input, it indicates the length of the provided **pressedKeyCodes** array; as output, it indicates the number of pressed keys. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH](_ark_u_i___native_module.md) if the memory is insufficient. returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.


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


### OH_ArkUI_FocusAxisEvent_GetAxisValue()

```
double OH_ArkUI_FocusAxisEvent_GetAxisValue (const ArkUI_UIInputEvent * event, int32_t axis)
```
**Description**

Obtains the axis value of a focus axis event.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| axis | Axis type of the focus axis event. | 

**Returns**

Returns the axis value of the focus axis event; returns <b>0.0</b> if any parameter error occurs.


### OH_ArkUI_FocusAxisEvent_SetStopPropagation()

```
int32_t OH_ArkUI_FocusAxisEvent_SetStopPropagation (const ArkUI_UIInputEvent * event, bool stopPropagation)
```
**Description**

Sets whether to prevent a focus axis event from bubbling up.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| stopPropagation | Whether to stop event propagation. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.


### OH_ArkUI_PointerEvent_GetPressedTimeByIndex()

```
int64_t OH_ArkUI_PointerEvent_GetPressedTimeByIndex (const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```
**Description**

Obtains the press time of a specific touch point.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns the press time of the specific touch point; returns **0** if any parameter error occurs.


### OH_ArkUI_MouseEvent_GetRawDeltaX()

```
float OH_ArkUI_MouseEvent_GetRawDeltaX (const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the x-axis offset of the mouse pointer position relative to the position in the previously reported mouse event. This value may be less than the difference between the two reported X coordinates when the mouse pointer is near the screen edge.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the x-axis offset of the mouse pointer position relative to the position in the previously reported mouse event; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_MouseEvent_GetRawDeltaY()

```
float OH_ArkUI_MouseEvent_GetRawDeltaY (const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the x-axis offset of the mouse pointer position relative to the position in the previously reported mouse event. This value may be less than the difference between the two reported Y coordinates when the mouse pointer is near the screen edge.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the y-axis offset of the mouse pointer position relative to the position in the previously reported mouse event; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_MouseEvent_GetPressedButtons()

```
int32_t OH_ArkUI_MouseEvent_GetPressedButtons (const ArkUI_UIInputEvent* event, int32_t* pressedButtons, int32_t* length)
```
**Description**

Obtains the pressed buttons from a mouse event.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pressedButtons | List of buttons that are pressed. An int array must be created beforehand to store the pressed buttons.|
| length | Dual-purpose parameter: As input, it indicates the length of the provided **pressedButtons** array; as output, it indicates the number of pressed keys.|

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; Returns [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](_ark_u_i___native_module.md) if the given buffer size is insufficient.


### OH_ArkUI_UIInputEvent_GetTargetDisplayId()

```
int32_t OH_ArkUI_UIInputEvent_GetTargetDisplayId (const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the ID of the screen where the UI input event occurs.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 

**Returns**

Returns the screen ID; returns **0** if any parameter error occurs.


### OH_ArkUI_PointerEvent_GetInteractionHand()

```
int32_t OH_ArkUI_PointerEvent_GetInteractionHand (const ArkUI_UIInputEvent * event, ArkUI_InteractionHand * hand)
```
**Description**

Checks whether an event is triggered by a left-hand or right-hand tap.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| hand | Returns the interactive hand recognized by the current event. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.


### OH_ArkUI_PointerEvent_GetInteractionHandByIndex()

```
int32_t OH_ArkUI_PointerEvent_GetInteractionHandByIndex (const ArkUI_UIInputEvent * event, int32_t pointerIndex, ArkUI_InteractionHand * hand)
```
**Description**

Checks whether an event is triggered by a left-hand or right-hand tap.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 
| hand | Returns the interactive hand of the specified finger. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.


### OH_ArkUI_UIInputEvent_GetEventTargetWidth()

```
float OH_ArkUI_UIInputEvent_GetEventTargetWidth(const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the width of the component hit by an event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** object. | 

**Returns**

Returns the width of the component hit by the event; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_UIInputEvent_GetEventTargetHeight()

```
float OH_ArkUI_UIInputEvent_GetEventTargetHeight(const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the height of the component hit by an event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** object. | 

**Returns**

Returns the height of the component hit by the event; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_UIInputEvent_GetEventTargetPositionX()

```
float OH_ArkUI_UIInputEvent_GetEventTargetPositionX(const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the X coordinate of the component hit by an event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** object. | 

**Returns**

Returns the X coordinate of the component hit by the event; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_UIInputEvent_GetEventTargetPositionY()

```
float OH_ArkUI_UIInputEvent_GetEventTargetPositionY(const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the Y coordinate of the component hit by an event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** object. | 

**Returns**

Returns the Y coordinate of the component hit by the event; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX()

```
float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX(const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the global X coordinate of the component hit by an event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** object. | 

**Returns**

Returns the global Y coordinate of the component hit by the event; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY()

```
float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY(const ArkUI_UIInputEvent* event)
```
**Description**

Obtains the global Y coordinate of the component hit by an event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** object. | 

**Returns**

Returns the global Y coordinate of the component hit by the event; returns **0.0f** if any parameter error occurs.


### OH_ArkUI_UIInputEvent_GetModifierKeyStates()

```
int32_t OH_ArkUI_UIInputEvent_GetModifierKeyStates(const ArkUI_UIInputEvent* event, uint64_t* keys)
```
**Description**

Obtains the state of the modifier keys in a UI input event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** object. | 
| keys | Indicates the modifier key combination that is being pressed. | 

**Returns**

Returns the modifier key combination that is being pressed. If the parameter is abnormal, 401 is returned.


### OH_ArkUI_HoverEvent_IsHovered()

```
bool OH_ArkUI_HoverEvent_IsHovered(const ArkUI_UIInputEvent* event)
```
**Description**

Checks whether the cursor is hovering over this component.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** object. | 

**Returns**

Returns true if the cursor is hovered over the current component. If the cursor is not hovered over the current component, false is returned.


### OH_ArkUI_PointerEvent_CreateClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_CreateClonedEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)
```
**Description**

Creates a cloned event pointer based on an event pointer.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 
| clonedEvent | Pointer to the ArkUI_UIInputEvent clone event. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful;
returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.

### OH_ArkUI_PointerEvent_DestroyClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_DestroyClonedEvent(const ArkUI_UIInputEvent* event)
```
**Description**

Destroys a cloned event pointer.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful;
returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
Returns [ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) if the input event pointer is not a cloned event pointer.

### OH_ArkUI_PointerEvent_SetClonedEventLocalPosition()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPosition(const ArkUI_UIInputEvent * event, float x, float y)
```
**Description**

Sets the X and Y coordinates of a cloned event relative to the upper left corner of the current component.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 
| x | X coordinate of the event relative to the upper left corner of the current component. | 
| y | Y coordinate of the event relative to the upper left corner of the current component. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful;
returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
Returns [ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) if the input event pointer is not a cloned event pointer.

### OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex(const ArkUI_UIInputEvent * event, 
float x, float y, int32_t pointerIndex)
```
**Description**

Sets the X and Y coordinates of a specific contact point of a cloned event relative to the upper left corner of the current component.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 
| x | X coordinate of the event relative to the upper left corner of the current component. | 
| y | Y coordinate of the event relative to the upper left corner of the current component. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful;
returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
Returns [ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) if the input event pointer is not a cloned event pointer.

### OH_ArkUI_PointerEvent_SetClonedEventActionType()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventActionType(const ArkUI_UIInputEvent * event, int32_t actionType)
```
**Description**

Sets the action type of a cloned event.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 
| actionType | Event type. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful;
returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
Returns [ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) if the input event pointer is not a cloned event pointer.

### OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId(const ArkUI_UIInputEvent * event, int32_t fingerId)
```
**Description**

Sets the touch point ID of a cloned pointer event.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 
| fingerId | ID of the touch point that triggers the event. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful;
returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
Returns [ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) if the input event pointer is not a cloned event pointer.

### OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex(const ArkUI_UIInputEvent * event, 
int32_t fingerId, int32_t pointerIndex)
```
**Description**

Sets the touch point ID of a specific contact point of a cloned event.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 
| fingerId | ID of the touch point that triggers the event. | 
| pointerIndex | Index of the target touch point in the multi-touch data list. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful;
returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
Returns [ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) if the input event pointer is not a cloned event pointer.

### OH_ArkUI_PointerEvent_PostClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_PostClonedEvent(ArkUI_NodeHandle node, const ArkUI_UIInputEvent * event)
```
**Description**

Posts a cloned event to a specific node.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to an **ArkUI_UIInputEvent** object. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful;
returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.
Returns [ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) if the input event pointer is not a cloned event pointer.
Returns [ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL](_ark_u_i___native_module.md) if the component status is abnormal.
Returns [ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT] if no component hit to respond to the event.


### OH_ArkUI_AxisEvent_SetPropagation()

```
int32_t OH_ArkUI_AxisEvent_SetPropagation (const ArkUI_UIInputEvent * event, bool propagation)
```
**Description**

Sets whether to enable axis event propagation.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the UI input event.| 
| propagation | Whether to stop event propagation. | 

**Returns**

Returns [ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) if the operation is successful; returns [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) if a parameter error occurs.


### OH_ArkUI_AxisEvent_GetScrollStep()

```
int32_t OH_ArkUI_AxisEvent_GetScrollStep (const ArkUI_UIInputEvent * event)
```
**Description**

Obtains the scroll step configuration of the mouse wheel axis event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| event | Pointer to the **ArkUI_UIInputEvent** event.| 

**Returns**

Returns the scrolling step of the mouse wheel axis.
