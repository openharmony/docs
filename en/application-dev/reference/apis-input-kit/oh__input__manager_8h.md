# oh_input_manager.h


## Overview

Provides functions such as event injection and status query.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Library**: liboh_input.so

**Since**: 12

**Related module**: [Input](input.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Input_KeyStateAction](input.md#input_keystateaction)[Input_KeyStateAction](input.md#input_keystateaction) | Provides the enum values of the key status.| 
| typedef enum [Input_KeyEventAction](input.md#input_keyeventaction)[Input_KeyEventAction](input.md#input_keyeventaction) | Provides the enum values of the key event type.| 
| typedef enum [Input_MouseEventAction](input.md#input_mouseeventaction)[Input_MouseEventAction](input.md#input_mouseeventaction) | Provides the enum values of mouse actions.| 
| typedef enum [InputEvent_MouseAxis](input.md#inputevent_mouseaxis)[InputEvent_MouseAxis](input.md#inputevent_mouseaxis) | Defines the mouse axis event type.| 
| typedef enum [Input_MouseEventButton](input.md#input_mouseeventbutton)[Input_MouseEventButton](input.md#input_mouseeventbutton) | Provides the enum values of mouse buttons.| 
| typedef enum [Input_TouchEventAction](input.md#input_toucheventaction)[Input_TouchEventAction](input.md#input_toucheventaction) | Provides the enum values of touch actions.| 
| typedef enum [Input_Result](input.md#input_result)[Input_Result](input.md#input_result) | Provides the enum values of error codes.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Input_KeyStateAction](input.md#input_keystateaction) {<br>[KEY_DEFAULT](input.md) = -1, [KEY_PRESSED](input.md) = 0, [KEY_RELEASED](input.md) = 1, [KEY_SWITCH_ON](input.md) = 2,<br>[KEY_SWITCH_OFF](input.md) = 3<br>} | Provides the enum values of the key status.| 
| [Input_KeyEventAction](input.md#input_keyeventaction) { [KEY_ACTION_CANCEL](input.md) = 0, [KEY_ACTION_DOWN](input.md) = 1, [KEY_ACTION_UP](input.md) = 2 } | Provides the enum values of the key event type.| 
| [Input_MouseEventAction](input.md#input_mouseeventaction) {<br>[MOUSE_ACTION_CANCEL](input.md) = 0, [MOUSE_ACTION_MOVE](input.md) = 1, [MOUSE_ACTION_BUTTON_DOWN](input.md) = 2, [MOUSE_ACTION_BUTTON_UP](input.md) = 3,<br>[MOUSE_ACTION_AXIS_BEGIN](input.md) = 4, [MOUSE_ACTION_AXIS_UPDATE](input.md) = 5, [MOUSE_ACTION_AXIS_END](input.md) = 6<br>} | Provides the enum values of mouse actions.| 
| [InputEvent_MouseAxis](input.md#inputevent_mouseaxis) { [MOUSE_AXIS_SCROLL_VERTICAL](input.md) = 0, [MOUSE_AXIS_SCROLL_HORIZONTAL](input.md) = 1 } | Provides the enum values of mouse axis event types.| 
| [Input_MouseEventButton](input.md#input_mouseeventbutton) {<br>[MOUSE_BUTTON_NONE](input.md) = -1, [MOUSE_BUTTON_LEFT](input.md) = 0, [MOUSE_BUTTON_MIDDLE](input.md) = 1, [MOUSE_BUTTON_RIGHT](input.md) = 2,<br>[MOUSE_BUTTON_FORWARD](input.md) = 3, [MOUSE_BUTTON_BACK](input.md) = 4<br>} | Provides the enum values of mouse buttons.| 
| [Input_TouchEventAction](input.md#input_toucheventaction) { [TOUCH_ACTION_CANCEL](input.md) = 0, [TOUCH_ACTION_DOWN](input.md) = 1, [TOUCH_ACTION_MOVE](input.md) = 2, [TOUCH_ACTION_UP](input.md) = 3 } | Provides the enum values of touch actions.| 
| [Input_Result](input.md#input_result) { [INPUT_SUCCESS](input.md) = 0, [INPUT_PERMISSION_DENIED](input.md) = 201, [INPUT_NOT_SYSTEM_APPLICATION](input.md) = 202, [INPUT_PARAMETER_ERROR](input.md) = 401 } | Provides the enum values of error codes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Input_Result](input.md#input_result)[OH_Input_GetKeyState](input.md#oh_input_getkeystate) (struct Input_KeyState \*keyState) | Queries an enum object of the key status.| 
| struct Input_KeyState \* [OH_Input_CreateKeyState](input.md#oh_input_createkeystate) () | Creates an enum object of the key status.| 
| void [OH_Input_DestroyKeyState](input.md#oh_input_destroykeystate) (struct Input_KeyState \*\*keyState) | Destroys an enum object of the key status.| 
| void [OH_Input_SetKeyCode](input.md#oh_input_setkeycode) (struct Input_KeyState \*keyState, int32_t keyCode) | Sets the key value of a key status enum object.| 
| int32_t [OH_Input_GetKeyCode](input.md#oh_input_getkeycode) (const struct Input_KeyState \*keyState) | Obtains the key value of a key status enum object.| 
| void [OH_Input_SetKeyPressed](input.md#oh_input_setkeypressed) (struct Input_KeyState \*keyState, int32_t keyAction) | Sets whether the key specific to a key status enum object is pressed.| 
| int32_t [OH_Input_GetKeyPressed](input.md#oh_input_getkeypressed) (const struct Input_KeyState \*keyState) | Checks whether the key specific to a key status enum object is pressed.| 
| void [OH_Input_SetKeySwitch](input.md#oh_input_setkeyswitch) (struct Input_KeyState \*keyState, int32_t keySwitch) | Sets the key switch of the key status enum object.| 
| int32_t [OH_Input_GetKeySwitch](input.md#oh_input_getkeyswitch) (const struct Input_KeyState \*keyState) | Obtains the key switch of the key status enum object.| 
| int32_t [OH_Input_InjectKeyEvent](input.md#oh_input_injectkeyevent) (const struct Input_KeyEvent \*keyEvent) | Injects a key event.| 
| struct Input_KeyEvent \* [OH_Input_CreateKeyEvent](input.md#oh_input_createkeyevent) () | Creates a key event object.| 
| void [OH_Input_DestroyKeyEvent](input.md#oh_input_destroykeyevent) (struct Input_KeyEvent \*\*keyEvent) | Destroys a key event object.| 
| void [OH_Input_SetKeyEventAction](input.md#oh_input_setkeyeventaction) (struct Input_KeyEvent \*keyEvent, int32_t action) | Sets the key event type.| 
| int32_t [OH_Input_GetKeyEventAction](input.md#oh_input_getkeyeventaction) (const struct Input_KeyEvent \*keyEvent) | Obtains the key event type.| 
| void [OH_Input_SetKeyEventKeyCode](input.md#oh_input_setkeyeventkeycode) (struct Input_KeyEvent \*keyEvent, int32_t keyCode) | Sets the key code value for a key event.| 
| int32_t [OH_Input_GetKeyEventKeyCode](input.md#oh_input_getkeyeventkeycode) (const struct Input_KeyEvent \*keyEvent) | Obtains the key code value of a key event.| 
| void [OH_Input_SetKeyEventActionTime](input.md#oh_input_setkeyeventactiontime) (struct Input_KeyEvent \*keyEvent, int64_t actionTime) | Sets the time when a key event occurs.| 
| int64_t [OH_Input_GetKeyEventActionTime](input.md#oh_input_getkeyeventactiontime) (const struct Input_KeyEvent \*keyEvent) | Obtains the time when a key event occurs.| 
| int32_t [OH_Input_InjectMouseEvent](input.md#oh_input_injectmouseevent) (const struct Input_MouseEvent \*mouseEvent) | Injects a mouse event.| 
| struct Input_MouseEvent \* [OH_Input_CreateMouseEvent](input.md#oh_input_createmouseevent) () | Creates a mouse event object.| 
| void [OH_Input_DestroyMouseEvent](input.md#oh_input_destroymouseevent) (struct Input_MouseEvent \*\*mouseEvent) | Destroys a mouse event object.| 
| void [OH_Input_SetMouseEventAction](input.md#oh_input_setmouseeventaction) (struct Input_MouseEvent \*mouseEvent, int32_t action) | Sets the action for a mouse event.| 
| int32_t [OH_Input_GetMouseEventAction](input.md#oh_input_getmouseeventaction) (const struct Input_MouseEvent \*mouseEvent) | Obtains the action of a mouse event.| 
| void [OH_Input_SetMouseEventDisplayX](input.md#oh_input_setmouseeventdisplayx) (struct Input_MouseEvent \*mouseEvent, int32_t displayX) | Sets the X coordinate for a mouse event.| 
| int32_t [OH_Input_GetMouseEventDisplayX](input.md#oh_input_getmouseeventdisplayx) (const struct Input_MouseEvent \*mouseEvent) | Obtains the X coordinate of a mouse event.| 
| void [OH_Input_SetMouseEventDisplayY](input.md#oh_input_setmouseeventdisplayy) (struct Input_MouseEvent \*mouseEvent, int32_t displayY) | Sets the Y coordinate for a mouse event.| 
| int32_t [OH_Input_GetMouseEventDisplayY](input.md#oh_input_getmouseeventdisplayy) (const struct Input_MouseEvent \*mouseEvent) | Obtains the Y coordinate of a mouse event.| 
| void [OH_Input_SetMouseEventButton](input.md#oh_input_setmouseeventbutton) (struct Input_MouseEvent \*mouseEvent, int32_t button) | Sets the button for a mouse event.| 
| int32_t [OH_Input_GetMouseEventButton](input.md#oh_input_getmouseeventbutton) (const struct Input_MouseEvent \*mouseEvent) | Obtains the button of a mouse event.| 
| void [OH_Input_SetMouseEventAxisType](input.md#oh_input_setmouseeventaxistype) (struct Input_MouseEvent \*mouseEvent, int32_t axisType) | Sets the axis type for a mouse event.| 
| int32_t [OH_Input_GetMouseEventAxisType](input.md#oh_input_getmouseeventaxistype) (const struct Input_MouseEvent \*mouseEvent) | Obtains the axis type of a mouse event.| 
| void [OH_Input_SetMouseEventAxisValue](input.md#oh_input_setmouseeventaxisvalue) (struct Input_MouseEvent \*mouseEvent, float axisValue) | Sets the axis value for a mouse axis event.| 
| float [OH_Input_GetMouseEventAxisValue](input.md#oh_input_getmouseeventaxisvalue) (const struct Input_MouseEvent \*mouseEvent) | Obtains the axis value of a mouse axis event.| 
| void [OH_Input_SetMouseEventActionTime](input.md#oh_input_setmouseeventactiontime) (struct Input_MouseEvent \*mouseEvent, int64_t actionTime) | Sets the time when a mouse event occurs.| 
| int64_t [OH_Input_GetMouseEventActionTime](input.md#oh_input_getmouseeventactiontime) (const struct Input_MouseEvent \*mouseEvent) | Obtains the time when a mouse event occurs.| 
| int32_t [OH_Input_InjectTouchEvent](input.md#oh_input_injecttouchevent) (const struct Input_TouchEvent \*touchEvent) | Injects a touch event.| 
| struct Input_TouchEvent \* [OH_Input_CreateTouchEvent](input.md#oh_input_createtouchevent) () | Creates a touch event object.| 
| void [OH_Input_DestroyTouchEvent](input.md#oh_input_destroytouchevent) (struct Input_TouchEvent \*\*touchEvent) | Destroys a touch event object.| 
| void [OH_Input_SetTouchEventAction](input.md#oh_input_settoucheventaction) (struct Input_TouchEvent \*touchEvent, int32_t action) | Sets the action for a touch event.| 
| int32_t [OH_Input_GetTouchEventAction](input.md#oh_input_gettoucheventaction) (const struct Input_TouchEvent \*touchEvent) | Obtains the action of a touch event.| 
| void [OH_Input_SetTouchEventFingerId](input.md#oh_input_settoucheventfingerid) (struct Input_TouchEvent \*touchEvent, int32_t id) | Sets the finger ID for a touch event.| 
| int32_t [OH_Input_GetTouchEventFingerId](input.md#oh_input_gettoucheventfingerid) (const struct Input_TouchEvent \*touchEvent) | Obtains the finger ID of a touch event.| 
| void [OH_Input_SetTouchEventDisplayX](input.md#oh_input_settoucheventdisplayx) (struct Input_TouchEvent \*touchEvent, int32_t displayX) | Sets the X coordinate for a touch event.| 
| int32_t [OH_Input_GetTouchEventDisplayX](input.md#oh_input_gettoucheventdisplayx) (const struct Input_TouchEvent \*touchEvent) | Obtains the X coordinate of a touch event.| 
| void [OH_Input_SetTouchEventDisplayY](input.md#oh_input_settoucheventdisplayy) (struct Input_TouchEvent \*touchEvent, int32_t displayY) | Sets the Y coordinate for a touch event.| 
| int32_t [OH_Input_GetTouchEventDisplayY](input.md#oh_input_gettoucheventdisplayy) (const struct Input_TouchEvent \*touchEvent) | Obtains the Y coordinate of a touch event.| 
| void [OH_Input_SetTouchEventActionTime](input.md#oh_input_settoucheventactiontime) (struct Input_TouchEvent \*touchEvent, int64_t actionTime) | Sets the time when a touch event occurs.| 
| int64_t [OH_Input_GetTouchEventActionTime](input.md#oh_input_gettoucheventactiontime) (const struct Input_TouchEvent \*touchEvent) | Obtains the time when a touch event occurs.| 
| void [OH_Input_CancelInjection](input.md#oh_input_cancelinjection) () | Stops event injection and revokes authorization.| 
