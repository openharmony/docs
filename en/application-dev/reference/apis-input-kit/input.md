# Input


## Overview

Provides C APIs for the multimodal input module.

**Since**: 12


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [oh_input_manager.h](oh__input__manager_8h.md) | Provides functions such as event injection and status query.| 
| [oh_key_code.h](oh__key__code_8h.md) | Defines key codes of the key device.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Input_KeyStateAction](#input_keystateaction)[Input_KeyStateAction](#input_keystateaction) | Provides the enum values of the key status.| 
| typedef enum [Input_KeyEventAction](#input_keyeventaction)[Input_KeyEventAction](#input_keyeventaction) | Provides the enum values of the key event type.| 
| typedef enum [Input_MouseEventAction](#input_mouseeventaction)[Input_MouseEventAction](#input_mouseeventaction) | Provides the enum values of mouse actions.| 
| typedef enum [InputEvent_MouseAxis](#inputevent_mouseaxis)[InputEvent_MouseAxis](#inputevent_mouseaxis) | Provides the enum values of mouse axis event types.| 
| typedef enum [Input_MouseEventButton](#input_mouseeventbutton)[Input_MouseEventButton](#input_mouseeventbutton) | Provides the enum values of mouse buttons.| 
| typedef enum [Input_TouchEventAction](#input_toucheventaction)[Input_TouchEventAction](#input_toucheventaction) | Provides the enum values of touch actions.| 
| typedef enum [Input_Result](#input_result)[Input_Result](#input_result) | Provides the enum values of error codes.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Input_KeyStateAction](#input_keystateaction) {<br>KEY_DEFAULT = -1, KEY_PRESSED = 0, KEY_RELEASED = 1, KEY_SWITCH_ON = 2,<br>KEY_SWITCH_OFF = 3<br>} | Provides the enum values of the key status.| 
| [Input_KeyEventAction](#input_keyeventaction) { KEY_ACTION_CANCEL = 0, KEY_ACTION_DOWN = 1, KEY_ACTION_UP = 2 } | Provides the enum values of the key event type.| 
| [Input_MouseEventAction](#input_mouseeventaction) {<br>MOUSE_ACTION_CANCEL = 0, MOUSE_ACTION_MOVE = 1, MOUSE_ACTION_BUTTON_DOWN = 2, MOUSE_ACTION_BUTTON_UP = 3,<br>MOUSE_ACTION_AXIS_BEGIN = 4, MOUSE_ACTION_AXIS_UPDATE = 5, MOUSE_ACTION_AXIS_END = 6<br>} | Enum values of mouse actions.| 
| [InputEvent_MouseAxis](#inputevent_mouseaxis) { MOUSE_AXIS_SCROLL_VERTICAL = 0, MOUSE_AXIS_SCROLL_HORIZONTAL = 1 } | Provides the enum values of mouse axis event types.| 
| [Input_MouseEventButton](#input_mouseeventbutton) {<br>MOUSE_BUTTON_NONE = -1, MOUSE_BUTTON_LEFT = 0, MOUSE_BUTTON_MIDDLE = 1, MOUSE_BUTTON_RIGHT = 2,<br>MOUSE_BUTTON_FORWARD = 3, MOUSE_BUTTON_BACK = 4<br>} | Provides the enum values of mouse buttons.| 
| [Input_TouchEventAction](#input_toucheventaction) { TOUCH_ACTION_CANCEL = 0, TOUCH_ACTION_DOWN = 1, TOUCH_ACTION_MOVE = 2, TOUCH_ACTION_UP = 3 } | Provides the enum values of touch actions.| 
| [Input_Result](#input_result) { INPUT_SUCCESS = 0, INPUT_PERMISSION_DENIED = 201, INPUT_NOT_SYSTEM_APPLICATION = 202, INPUT_PARAMETER_ERROR = 401 } | Provides the enum values of error codes.| 
| [Input_KeyCode](#input_keycode) {<br>KEYCODE_UNKNOWN = -1, KEYCODE_FN = 0, KEYCODE_VOLUME_UP = 16, KEYCODE_VOLUME_DOWN = 17,<br>KEYCODE_POWER = 18, KEYCODE_CAMERA = 19, KEYCODE_VOLUME_MUTE = 22, KEYCODE_MUTE = 23,<br>KEYCODE_BRIGHTNESS_UP = 40, KEYCODE_BRIGHTNESS_DOWN = 41, KEYCODE_0 = 2000, KEYCODE_1 = 2001,<br>KEYCODE_2 = 2002, KEYCODE_3 = 2003, KEYCODE_4 = 2004, KEYCODE_5 = 2005,<br>KEYCODE_6 = 2006, KEYCODE_7 = 2007, KEYCODE_8 = 2008, KEYCODE_9 = 2009,<br>KEYCODE_STAR = 2010, KEYCODE_POUND = 2011, KEYCODE_DPAD_UP = 2012, KEYCODE_DPAD_DOWN = 2013,<br>KEYCODE_DPAD_LEFT = 2014, KEYCODE_DPAD_RIGHT = 2015, KEYCODE_DPAD_CENTER = 2016, KEYCODE_A = 2017,<br>KEYCODE_B = 2018, KEYCODE_C = 2019, KEYCODE_D = 2020, KEYCODE_E = 2021,<br>KEYCODE_F = 2022, KEYCODE_G = 2023, KEYCODE_H = 2024, KEYCODE_I = 2025,<br>KEYCODE_J = 2026, KEYCODE_K = 2027, KEYCODE_L = 2028, KEYCODE_M = 2029,<br>KEYCODE_N = 2030, KEYCODE_O = 2031, KEYCODE_P = 2032, KEYCODE_Q = 2033,<br>KEYCODE_R = 2034, KEYCODE_S = 2035, KEYCODE_T = 2036, KEYCODE_U = 2037,<br>KEYCODE_V = 2038, KEYCODE_W = 2039, KEYCODE_X = 2040, KEYCODE_Y = 2041,<br>KEYCODE_Z = 2042, KEYCODE_COMMA = 2043, KEYCODE_PERIOD = 2044, KEYCODE_ALT_LEFT = 2045,<br>KEYCODE_ALT_RIGHT = 2046, KEYCODE_SHIFT_LEFT = 2047, KEYCODE_SHIFT_RIGHT = 2048, KEYCODE_TAB = 2049,<br>KEYCODE_SPACE = 2050, KEYCODE_SYM = 2051, KEYCODE_EXPLORER = 2052, KEYCODE_ENVELOPE = 2053,<br>KEYCODE_ENTER = 2054, KEYCODE_DEL = 2055, KEYCODE_GRAVE = 2056, KEYCODE_MINUS = 2057,<br>KEYCODE_EQUALS = 2058, KEYCODE_LEFT_BRACKET = 2059, KEYCODE_RIGHT_BRACKET = 2060, KEYCODE_BACKSLASH = 2061,<br>KEYCODE_SEMICOLON = 2062, KEYCODE_APOSTROPHE = 2063, KEYCODE_SLASH = 2064, KEYCODE_AT = 2065,<br>KEYCODE_PLUS = 2066, KEYCODE_MENU = 2067, KEYCODE_PAGE_UP = 2068, KEYCODE_PAGE_DOWN = 2069,<br>KEYCODE_ESCAPE = 2070, KEYCODE_FORWARD_DEL = 2071, KEYCODE_CTRL_LEFT = 2072, KEYCODE_CTRL_RIGHT = 2073,<br>KEYCODE_CAPS_LOCK = 2074, KEYCODE_SCROLL_LOCK = 2075, KEYCODE_META_LEFT = 2076, KEYCODE_META_RIGHT = 2077,<br>KEYCODE_FUNCTION = 2078, KEYCODE_SYSRQ = 2079, KEYCODE_BREAK = 2080, KEYCODE_MOVE_HOME = 2081,<br>KEYCODE_MOVE_END = 2082, KEYCODE_INSERT = 2083, KEYCODE_FORWARD = 2084, KEYCODE_MEDIA_PLAY = 2085,<br>KEYCODE_MEDIA_PAUSE = 2086, KEYCODE_MEDIA_CLOSE = 2087, KEYCODE_MEDIA_EJECT = 2088, KEYCODE_MEDIA_RECORD = 2089,<br>KEYCODE_F1 = 2090, KEYCODE_F2 = 2091, KEYCODE_F3 = 2092, KEYCODE_F4 = 2093,<br>KEYCODE_F5 = 2094, KEYCODE_F6 = 2095, KEYCODE_F7 = 2096, KEYCODE_F8 = 2097,<br>KEYCODE_F9 = 2098, KEYCODE_F10 = 2099, KEYCODE_F11 = 2100, KEYCODE_F12 = 2101,<br>KEYCODE_NUM_LOCK = 2102, KEYCODE_NUMPAD_0 = 2103, KEYCODE_NUMPAD_1 = 2104, KEYCODE_NUMPAD_2 = 2105,<br>KEYCODE_NUMPAD_3 = 2106, KEYCODE_NUMPAD_4 = 2107, KEYCODE_NUMPAD_5 = 2108, KEYCODE_NUMPAD_6 = 2109,<br>KEYCODE_NUMPAD_7 = 2110, KEYCODE_NUMPAD_8 = 2111, KEYCODE_NUMPAD_9 = 2112, KEYCODE_NUMPAD_DIVIDE = 2113,<br>KEYCODE_NUMPAD_MULTIPLY = 2114, KEYCODE_NUMPAD_SUBTRACT = 2115, KEYCODE_NUMPAD_ADD = 2116, KEYCODE_NUMPAD_DOT = 2117,<br>KEYCODE_NUMPAD_COMMA = 2118, KEYCODE_NUMPAD_ENTER = 2119, KEYCODE_NUMPAD_EQUALS = 2120, KEYCODE_NUMPAD_LEFT_PAREN = 2121,<br>KEYCODE_NUMPAD_RIGHT_PAREN = 2122<br>} | Provides key code values.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Input_Result](#input_result)[OH_Input_GetKeyState](#oh_input_getkeystate) (struct Input_KeyState \*keyState) | Queries a key status enum object.| 
| struct Input_KeyState \* [OH_Input_CreateKeyState](#oh_input_createkeystate) () | Creates a key status enum object.| 
| void [OH_Input_DestroyKeyState](#oh_input_destroykeystate) (struct Input_KeyState \*\*keyState) | Destroys a key status enum object.| 
| void [OH_Input_SetKeyCode](#oh_input_setkeycode) (struct Input_KeyState \*keyState, int32_t keyCode) | Sets the key value of a key status enum object.| 
| int32_t [OH_Input_GetKeyCode](#oh_input_getkeycode) (const struct Input_KeyState \*keyState) | Obtains the key value of a key status enum object.| 
| void [OH_Input_SetKeyPressed](#oh_input_setkeypressed) (struct Input_KeyState \*keyState, int32_t keyAction) | Sets whether the key specific to a key status enum object is pressed.| 
| int32_t [OH_Input_GetKeyPressed](#oh_input_getkeypressed) (const struct Input_KeyState \*keyState) | Checks whether the key specific to a key status enum object is pressed.| 
| void [OH_Input_SetKeySwitch](#oh_input_setkeyswitch) (struct Input_KeyState \*keyState, int32_t keySwitch) | Sets the key switch of the key status enum object.| 
| int32_t [OH_Input_GetKeySwitch](#oh_input_getkeyswitch) (const struct Input_KeyState \*keyState) | Obtains the key switch of the key status enum object.| 
| int32_t [OH_Input_InjectKeyEvent](#oh_input_injectkeyevent) (const struct Input_KeyEvent \*keyEvent) | Injects a key event.| 
| struct Input_KeyEvent \* [OH_Input_CreateKeyEvent](#oh_input_createkeyevent) () | Creates a key event object.| 
| void [OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent) (struct Input_KeyEvent \*\*keyEvent) | Destroys a key event object.| 
| void [OH_Input_SetKeyEventAction](#oh_input_setkeyeventaction) (struct Input_KeyEvent \*keyEvent, int32_t action) | Sets the key event type.| 
| int32_t [OH_Input_GetKeyEventAction](#oh_input_getkeyeventaction) (const struct Input_KeyEvent \*keyEvent) | Obtains the key event type.| 
| void [OH_Input_SetKeyEventKeyCode](#oh_input_setkeyeventkeycode) (struct Input_KeyEvent \*keyEvent, int32_t keyCode) | Sets the key code value for a key event.| 
| int32_t [OH_Input_GetKeyEventKeyCode](#oh_input_getkeyeventkeycode) (const struct Input_KeyEvent \*keyEvent) | Obtains the key code value of a key event.| 
| void [OH_Input_SetKeyEventActionTime](#oh_input_setkeyeventactiontime) (struct Input_KeyEvent \*keyEvent, int64_t actionTime) | Sets the time when a key event occurs.| 
| int64_t [OH_Input_GetKeyEventActionTime](#oh_input_getkeyeventactiontime) (const struct Input_KeyEvent \*keyEvent) | Obtains the time when a key event occurs.| 
| int32_t [OH_Input_InjectMouseEvent](#oh_input_injectmouseevent) (const struct Input_MouseEvent \*mouseEvent) | Injects a mouse event.| 
| struct Input_MouseEvent \* [OH_Input_CreateMouseEvent](#oh_input_createmouseevent) () | Creates a mouse event object.| 
| void [OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent) (struct Input_MouseEvent \*\*mouseEvent) | Destroys a mouse event object.| 
| void [OH_Input_SetMouseEventAction](#oh_input_setmouseeventaction) (struct Input_MouseEvent \*mouseEvent, int32_t action) | Sets the action for a mouse event.| 
| int32_t [OH_Input_GetMouseEventAction](#oh_input_getmouseeventaction) (const struct Input_MouseEvent \*mouseEvent) | Obtains the action of a mouse event.| 
| void [OH_Input_SetMouseEventDisplayX](#oh_input_setmouseeventdisplayx) (struct Input_MouseEvent \*mouseEvent, int32_t displayX) | Sets the X coordinate for a mouse event.| 
| int32_t [OH_Input_GetMouseEventDisplayX](#oh_input_getmouseeventdisplayx) (const struct Input_MouseEvent \*mouseEvent) | Obtains the X coordinate of a mouse event.| 
| void [OH_Input_SetMouseEventDisplayY](#oh_input_setmouseeventdisplayy) (struct Input_MouseEvent \*mouseEvent, int32_t displayY) | Sets the Y coordinate for a mouse event.| 
| int32_t [OH_Input_GetMouseEventDisplayY](#oh_input_getmouseeventdisplayy) (const struct Input_MouseEvent \*mouseEvent) | Obtains the Y coordinate of a mouse event.| 
| void [OH_Input_SetMouseEventButton](#oh_input_setmouseeventbutton) (struct Input_MouseEvent \*mouseEvent, int32_t button) | Sets the button for a mouse event.| 
| int32_t [OH_Input_GetMouseEventButton](#oh_input_getmouseeventbutton) (const struct Input_MouseEvent \*mouseEvent) | Obtains the button of a mouse event.| 
| void [OH_Input_SetMouseEventAxisType](#oh_input_setmouseeventaxistype) (struct Input_MouseEvent \*mouseEvent, int32_t axisType) | Sets the axis type for a mouse event.| 
| int32_t [OH_Input_GetMouseEventAxisType](#oh_input_getmouseeventaxistype) (const struct Input_MouseEvent \*mouseEvent) | Obtains the axis type of a mouse event.| 
| void [OH_Input_SetMouseEventAxisValue](#oh_input_setmouseeventaxisvalue) (struct Input_MouseEvent \*mouseEvent, float axisValue) | Sets the axis value for a mouse axis event.| 
| float [OH_Input_GetMouseEventAxisValue](#oh_input_getmouseeventaxisvalue) (const struct Input_MouseEvent \*mouseEvent) | Obtains the axis value of a mouse axis event.| 
| void [OH_Input_SetMouseEventActionTime](#oh_input_setmouseeventactiontime) (struct Input_MouseEvent \*mouseEvent, int64_t actionTime) | Sets the time when a mouse event occurs.| 
| int64_t [OH_Input_GetMouseEventActionTime](#oh_input_getmouseeventactiontime) (const struct Input_MouseEvent \*mouseEvent) | Obtains the time when a mouse event occurs.| 
| int32_t [OH_Input_InjectTouchEvent](#oh_input_injecttouchevent) (const struct Input_TouchEvent \*touchEvent) | Injects a touch event.| 
| struct Input_TouchEvent \* [OH_Input_CreateTouchEvent](#oh_input_createtouchevent) () | Creates a touch event object.| 
| void [OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent) (struct Input_TouchEvent \*\*touchEvent) | Destroys a touch event object.| 
| void [OH_Input_SetTouchEventAction](#oh_input_settoucheventaction) (struct Input_TouchEvent \*touchEvent, int32_t action) | Sets the action for a touch event.| 
| int32_t [OH_Input_GetTouchEventAction](#oh_input_gettoucheventaction) (const struct Input_TouchEvent \*touchEvent) | Obtains the action of a touch event.| 
| void [OH_Input_SetTouchEventFingerId](#oh_input_settoucheventfingerid) (struct Input_TouchEvent \*touchEvent, int32_t id) | Sets the finger ID for a touch event.| 
| int32_t [OH_Input_GetTouchEventFingerId](#oh_input_gettoucheventfingerid) (const struct Input_TouchEvent \*touchEvent) | Obtains the finger ID of a touch event.| 
| void [OH_Input_SetTouchEventDisplayX](#oh_input_settoucheventdisplayx) (struct Input_TouchEvent \*touchEvent, int32_t displayX) | Sets the X coordinate for a touch event.| 
| int32_t [OH_Input_GetTouchEventDisplayX](#oh_input_gettoucheventdisplayx) (const struct Input_TouchEvent \*touchEvent) | Obtains the X coordinate of a touch event.| 
| void [OH_Input_SetTouchEventDisplayY](#oh_input_settoucheventdisplayy) (struct Input_TouchEvent \*touchEvent, int32_t displayY) | Sets the Y coordinate for a touch event.| 
| int32_t [OH_Input_GetTouchEventDisplayY](#oh_input_gettoucheventdisplayy) (const struct Input_TouchEvent \*touchEvent) | Obtains the Y coordinate of a touch event.| 
| void [OH_Input_SetTouchEventActionTime](#oh_input_settoucheventactiontime) (struct Input_TouchEvent \*touchEvent, int64_t actionTime) | Sets the time when a touch event occurs.| 
| int64_t [OH_Input_GetTouchEventActionTime](#oh_input_gettoucheventactiontime) (const struct Input_TouchEvent \*touchEvent) | Obtains the time when a touch event occurs.| 
| void [OH_Input_CancelInjection](#oh_input_cancelinjection) () | Stops event injection and revokes authorization.| 


## Type Description


### Input_KeyEventAction

```
typedef enum Input_KeyEventActionInput_KeyEventAction
```

**Description**

Provides the enum values of the key event type.

**Since**: 12


### Input_KeyStateAction

```
typedef enum Input_KeyStateActionInput_KeyStateAction
```

**Description**

Provides the enum values of the key status.

**Since**: 12


### Input_MouseEventAction

```
typedef enum Input_MouseEventActionInput_MouseEventAction
```

**Description**

Provides the enum values of mouse actions.

**Since**: 12


### Input_MouseEventButton

```
typedef enum Input_MouseEventButtonInput_MouseEventButton
```

**Description**

Provides the enum values of mouse buttons.

**Since**: 12


### Input_Result

```
typedef enum Input_ResultInput_Result
```

**Description**

Provides the enum values of error codes.

**Since**: 12


### Input_TouchEventAction

```
typedef enum Input_TouchEventActionInput_TouchEventAction
```

**Description**

Provides the enum values of touch actions.

**Since**: 12


### InputEvent_MouseAxis

```
typedef enum InputEvent_MouseAxisInputEvent_MouseAxis
```

**Description**

Provides the enum values of mouse axis event types.

**Since**: 12


## Enum Description


### Input_KeyCode

```
enum Input_KeyCode
```

**Description**

Enumerates key code values.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| KEYCODE_UNKNOWN | Unknown key| 
| KEYCODE_FN | Function (Fn) key| 
| KEYCODE_VOLUME_UP | Volume Up key| 
| KEYCODE_VOLUME_DOWN | Volume Down key| 
| KEYCODE_POWER | Power key| 
| KEYCODE_CAMERA | Camera key| 
| KEYCODE_VOLUME_MUTE | Speaker Mute key| 
| KEYCODE_MUTE | Mute key| 
| KEYCODE_BRIGHTNESS_UP | Brightness Up key| 
| KEYCODE_BRIGHTNESS_DOWN | Brightness Down key| 
| KEYCODE_0 | Key 0| 
| KEYCODE_1 | Key 1| 
| KEYCODE_2 | Key 2| 
| KEYCODE_3 | Key 3| 
| KEYCODE_4 | Key 4| 
| KEYCODE_5 | Key 5| 
| KEYCODE_6 | Key 6| 
| KEYCODE_7 | Key 7| 
| KEYCODE_8 | Key 8| 
| KEYCODE_9 | Key 9| 
| KEYCODE_STAR | Key *| 
| KEYCODE_POUND | Key #| 
| KEYCODE_DPAD_UP | Up key on D-pad| 
| KEYCODE_DPAD_DOWN | Down key on D-pad| 
| KEYCODE_DPAD_LEFT | Left key on D-pad| 
| KEYCODE_DPAD_RIGHT | Right key on D-pad| 
| KEYCODE_DPAD_CENTER | Center key on D-pad| 
| KEYCODE_A | Key A| 
| KEYCODE_B | Key B| 
| KEYCODE_C | Key C| 
| KEYCODE_D | Key D| 
| KEYCODE_E | Key E| 
| KEYCODE_F | Key F| 
| KEYCODE_G | Key G| 
| KEYCODE_H | Key H| 
| KEYCODE_I | Key I| 
| KEYCODE_J | Key J| 
| KEYCODE_K | Key K| 
| KEYCODE_L | Key L| 
| KEYCODE_M | Key M| 
| KEYCODE_N | Key N| 
| KEYCODE_O | Key O| 
| KEYCODE_P | Key P| 
| KEYCODE_Q | Key Q| 
| KEYCODE_R | Key R| 
| KEYCODE_S | Key S| 
| KEYCODE_T | Key T| 
| KEYCODE_U | Key U| 
| KEYCODE_V | Key V| 
| KEYCODE_W | Key W| 
| KEYCODE_X | Key X| 
| KEYCODE_Y | Key Y| 
| KEYCODE_Z | Key Z| 
| KEYCODE_COMMA | Key ,| 
| KEYCODE_PERIOD | Key .| 
| KEYCODE_ALT_LEFT | Left Alt key| 
| KEYCODE_ALT_RIGHT | Right Alt key| 
| KEYCODE_SHIFT_LEFT | Left Shift key| 
| KEYCODE_SHIFT_RIGHT | Right Shift key| 
| KEYCODE_TAB | Tab key| 
| KEYCODE_SPACE | Space key| 
| KEYCODE_SYM | Symbol key| 
| KEYCODE_EXPLORER | Explorer key, used to start the explorer application| 
| KEYCODE_ENVELOPE | Email key, used to start the email application| 
| KEYCODE_ENTER | Enter key| 
| KEYCODE_DEL | Delete key| 
| KEYCODE_GRAVE | Key `| 
| KEYCODE_MINUS | Key -| 
| KEYCODE_EQUALS | Key =| 
| KEYCODE_LEFT_BRACKET | Key [| 
| KEYCODE_RIGHT_BRACKET | Key ]| 
| KEYCODE_BACKSLASH | Key \| 
| KEYCODE_SEMICOLON | Key ;| 
| KEYCODE_APOSTROPHE | Key '| 
| KEYCODE_SLASH | Key /| 
| KEYCODE_AT | Key @| 
| KEYCODE_PLUS | Key +| 
| KEYCODE_MENU | Menu key| 
| KEYCODE_PAGE_UP | Page Up key| 
| KEYCODE_PAGE_DOWN | Page Down key| 
| KEYCODE_ESCAPE | ESC key| 
| KEYCODE_FORWARD_DEL | Forward Delete key| 
| KEYCODE_CTRL_LEFT | Left Ctrl key| 
| KEYCODE_CTRL_RIGHT | Right Ctrl key| 
| KEYCODE_CAPS_LOCK | Caps Lock key| 
| KEYCODE_SCROLL_LOCK | Scroll Lock key| 
| KEYCODE_META_LEFT | Left Meta key| 
| KEYCODE_META_RIGHT | Right Meta key| 
| KEYCODE_FUNCTION | Function key| 
| KEYCODE_SYSRQ | System Request/Print Screen key| 
| KEYCODE_BREAK | Break/Pause key| 
| KEYCODE_MOVE_HOME | Move to Home key| 
| KEYCODE_MOVE_END | Move to End key| 
| KEYCODE_INSERT | Insert key| 
| KEYCODE_FORWARD | Forward key| 
| KEYCODE_MEDIA_PLAY | Play key| 
| KEYCODE_MEDIA_PAUSE | Pause key| 
| KEYCODE_MEDIA_CLOSE | Close key| 
| KEYCODE_MEDIA_EJECT | Eject key| 
| KEYCODE_MEDIA_RECORD | Record key| 
| KEYCODE_F1 | F1 key| 
| KEYCODE_F2 | F2 key| 
| KEYCODE_F3 | F3 key| 
| KEYCODE_F4 | F4 key| 
| KEYCODE_F5 | F5 key| 
| KEYCODE_F6 | F6 key| 
| KEYCODE_F7 | F7 key| 
| KEYCODE_F8 | F8 key| 
| KEYCODE_F9 | F9 key| 
| KEYCODE_F10 | F10 key| 
| KEYCODE_F11 | F11 key| 
| KEYCODE_F12 | F12 key| 
| KEYCODE_NUM_LOCK | Number Lock key| 
| KEYCODE_NUMPAD_0 | Key 0 on numeric keypad| 
| KEYCODE_NUMPAD_1 | Key 1 on numeric keypad| 
| KEYCODE_NUMPAD_2 | Key 2 on numeric keypad| 
| KEYCODE_NUMPAD_3 | Key 3 on numeric keypad| 
| KEYCODE_NUMPAD_4 | Key 4 on numeric keypad| 
| KEYCODE_NUMPAD_5 | Key 5 on numeric keypad| 
| KEYCODE_NUMPAD_6 | Key 6 on numeric keypad| 
| KEYCODE_NUMPAD_7 | Key 7 on numeric keypad| 
| KEYCODE_NUMPAD_8 | Key 8 on numeric keypad| 
| KEYCODE_NUMPAD_9 | Key 9 on numeric keypad| 
| KEYCODE_NUMPAD_DIVIDE | Key / on numeric keypad| 
| KEYCODE_NUMPAD_MULTIPLY | Key * on numeric keypad.| 
| KEYCODE_NUMPAD_SUBTRACT | Key - on numeric keypad| 
| KEYCODE_NUMPAD_ADD | Key + on numeric keypad| 
| KEYCODE_NUMPAD_DOT | Key . on numeric keypad| 
| KEYCODE_NUMPAD_COMMA | Key , on numeric keypad| 
| KEYCODE_NUMPAD_ENTER | Enter key on numeric keypad| 
| KEYCODE_NUMPAD_EQUALS | Key = on numeric keypad| 
| KEYCODE_NUMPAD_LEFT_PAREN | Key ( on numeric keypad| 
| KEYCODE_NUMPAD_RIGHT_PAREN | Key **)** on numeric keypad.| 


### Input_KeyEventAction

```
enum Input_KeyEventAction
```

**Description**

Provides the enum values of the key event type.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| KEY_ACTION_CANCEL | Button action canceled.| 
| KEY_ACTION_DOWN | Pressing of a key.| 
| KEY_ACTION_UP | Release of a key.| 


### Input_KeyStateAction

```
enum Input_KeyStateAction
```

**Description**

Provides the enum values of the key status.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| KEY_DEFAULT | Default status.| 
| KEY_PRESSED | Pressing of a key.| 
| KEY_RELEASED | Release of a key.| 
| KEY_SWITCH_ON | Key switch enabled.| 
| KEY_SWITCH_OFF | Key switch disabled.| 


### Input_MouseEventAction

```
enum Input_MouseEventAction
```

**Description**

Provides the enum values of mouse actions.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| MOUSE_ACTION_CANCEL | Mouse action canceled.| 
| MOUSE_ACTION_MOVE | Moving of the mouse pointer.| 
| MOUSE_ACTION_BUTTON_DOWN | Pressing of the mouse button.| 
| MOUSE_ACTION_BUTTON_UP | Release of the mouse button.| 
| MOUSE_ACTION_AXIS_BEGIN | Beginning of the mouse axis event.| 
| MOUSE_ACTION_AXIS_UPDATE | Updating of the mouse axis event.| 
| MOUSE_ACTION_AXIS_END | End of the mouse axis event.| 


### Input_MouseEventButton

```
enum Input_MouseEventButton
```

**Description**

Provides the enum values of mouse buttons.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| MOUSE_BUTTON_NONE | Invalid key.| 
| MOUSE_BUTTON_LEFT | Left mouse button.| 
| MOUSE_BUTTON_MIDDLE | Middle mouse button.| 
| MOUSE_BUTTON_RIGHT | Right mouse button.| 
| MOUSE_BUTTON_FORWARD | Mouse forward button.| 
| MOUSE_BUTTON_BACK | Mouse back button.| 


### Input_Result

```
enum Input_Result
```

**Description**

Provides the enum values of error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| INPUT_SUCCESS | Operation succeeded.| 
| INPUT_PERMISSION_DENIED | Permission verification failed.| 
| INPUT_NOT_SYSTEM_APPLICATION | Not a system application.| 
| INPUT_PARAMETER_ERROR | Parameter check failed.| 


### Input_TouchEventAction

```
enum Input_TouchEventAction
```

**Description**

Provides the enum values of touch actions.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| TOUCH_ACTION_CANCEL | Cancellation of touch.| 
| TOUCH_ACTION_DOWN | Pressing of touch.| 
| TOUCH_ACTION_MOVE | Moving of touch.| 
| TOUCH_ACTION_UP | Lifting of touch.| 


### InputEvent_MouseAxis

```
enum InputEvent_MouseAxis
```

**Description**

Provides the enum values of mouse axis event types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| MOUSE_AXIS_SCROLL_VERTICAL | Vertical scroll axis.| 
| MOUSE_AXIS_SCROLL_HORIZONTAL | Horizontal scroll axis.| 


## Function Description


### OH_Input_CancelInjection()

```
void OH_Input_CancelInjection ()
```

**Description**

Stops event injection and revokes authorization.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


### OH_Input_CreateKeyEvent()

```
struct Input_KeyEvent* OH_Input_CreateKeyEvent ()
```

**Description**

Creates a key event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

**Input_KeyEvent** pointer object if the operation is successful; a null pointer otherwise.


### OH_Input_CreateKeyState()

```
struct Input_KeyState* OH_Input_CreateKeyState ()
```

**Description**

Creates a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

An **Input_KeyState** pointer object if the operation is successful;

a null pointer otherwise.


### OH_Input_CreateMouseEvent()

```
struct Input_MouseEvent* OH_Input_CreateMouseEvent ()
```

**Description**

Creates a mouse event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

**Input_MouseEvent** pointer object if the operation is successful; a null pointer otherwise.


### OH_Input_CreateTouchEvent()

```
struct Input_TouchEvent* OH_Input_CreateTouchEvent ()
```

**Description**

Creates a touch event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

**Input_TouchEvent** pointer object if the operation is successful; a null pointer otherwise.


### OH_Input_DestroyKeyEvent()

```
void OH_Input_DestroyKeyEvent (struct Input_KeyEvent ** keyEvent)
```

**Description**

Destroys a key event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object.| 


### OH_Input_DestroyKeyState()

```
void OH_Input_DestroyKeyState (struct Input_KeyState ** keyState)
```

**Description**

Destroys a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Key status enum object.| 


### OH_Input_DestroyMouseEvent()

```
void OH_Input_DestroyMouseEvent (struct Input_MouseEvent ** mouseEvent)
```

**Description**

Destroys a mouse event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 


### OH_Input_DestroyTouchEvent()

```
void OH_Input_DestroyTouchEvent (struct Input_TouchEvent ** touchEvent)
```

**Description**

Destroys a touch event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 


### OH_Input_GetKeyCode()

```
int32_t OH_Input_GetKeyCode (const struct Input_KeyState * keyState)
```

**Description**

Obtains the key value of a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Key status enum object.| 

**Returns**

Key value of the key status enum object.


### OH_Input_GetKeyEventAction()

```
int32_t OH_Input_GetKeyEventAction (const struct Input_KeyEvent * keyEvent)
```

**Description**

Obtains the key event type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object.| 

**Returns**

Key event type.


### OH_Input_GetKeyEventActionTime()

```
int64_t OH_Input_GetKeyEventActionTime (const struct Input_KeyEvent * keyEvent)
```

**Description**

Obtains the time when a key event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object.| 

**Returns**

Time when a key event occurs.


### OH_Input_GetKeyEventKeyCode()

```
int32_t OH_Input_GetKeyEventKeyCode (const struct Input_KeyEvent * keyEvent)
```

**Description**

Obtains the key code value of a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object.| 

**Returns**

Key code.


### OH_Input_GetKeyPressed()

```
int32_t OH_Input_GetKeyPressed (const struct Input_KeyState * keyState)
```

**Description**

Checks whether the key specific to a key status enum object is pressed.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Key status enum object.| 

**Returns**

Key pressing status of the key status enum object.


### OH_Input_GetKeyState()

```
Input_Result OH_Input_GetKeyState (struct Input_KeyState * keyState)
```

**Description**

Queries a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Key status enum object.| 

**Returns**

{\@Link Input_Result::INPUT_SUCCESS} if the operation is successful;

an error code defined in {\@Link Input_Result} otherwise.


### OH_Input_GetKeySwitch()

```
int32_t OH_Input_GetKeySwitch (const struct Input_KeyState * keyState)
```

**Description**

Obtains the key switch of the key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Key status enum object.| 

**Returns**

Key switch of the key status enum object.


### OH_Input_GetMouseEventAction()

```
int32_t OH_Input_GetMouseEventAction (const struct Input_MouseEvent * mouseEvent)
```

**Description**

Obtains the action of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 

**Returns**

Mouse action.


### OH_Input_GetMouseEventActionTime()

```
int64_t OH_Input_GetMouseEventActionTime (const struct Input_MouseEvent * mouseEvent)
```

**Description**

Obtains the time when a mouse event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Mouse event object.| 

**Returns**

Time when the mouse event occurs.


### OH_Input_GetMouseEventAxisType()

```
int32_t OH_Input_GetMouseEventAxisType (const struct Input_MouseEvent * mouseEvent)
```

**Description**

Obtains the axis type of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 

**Returns**

Axis type.


### OH_Input_GetMouseEventAxisValue()

```
float OH_Input_GetMouseEventAxisValue (const struct Input_MouseEvent * mouseEvent)
```

**Description**

Obtains the axis value of a mouse axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 

**Returns**

Axis value of the mouse axis event.


### OH_Input_GetMouseEventButton()

```
int32_t OH_Input_GetMouseEventButton (const struct Input_MouseEvent * mouseEvent)
```

**Description**

Obtains the button of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 

**Returns**

Mouse button.


### OH_Input_GetMouseEventDisplayX()

```
int32_t OH_Input_GetMouseEventDisplayX (const struct Input_MouseEvent * mouseEvent)
```

**Description**

Obtains the X coordinate of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 

**Returns**

X coordinate of the mouse event.


### OH_Input_GetMouseEventDisplayY()

```
int32_t OH_Input_GetMouseEventDisplayY (const struct Input_MouseEvent * mouseEvent)
```

**Description**

Obtains the Y coordinate of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 

**Returns**

Y coordinate of the mouse event.


### OH_Input_GetTouchEventAction()

```
int32_t OH_Input_GetTouchEventAction (const struct Input_TouchEvent * touchEvent)
```

**Description**

Obtains the action of a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 

**Returns**

Action of the touch event.


### OH_Input_GetTouchEventActionTime()

```
int64_t OH_Input_GetTouchEventActionTime (const struct Input_TouchEvent * touchEvent)
```

**Description**

Obtains the time when a touch event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Touch event object.| 

**Returns**

Time when the touch event occurs.


### OH_Input_GetTouchEventDisplayX()

```
int32_t OH_Input_GetTouchEventDisplayX (const struct Input_TouchEvent * touchEvent)
```

**Description**

Obtains the X coordinate of a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 

**Returns**

X coordinate of a touch event.


### OH_Input_GetTouchEventDisplayY()

```
int32_t OH_Input_GetTouchEventDisplayY (const struct Input_TouchEvent * touchEvent)
```

**Description**

Obtains the Y coordinate of a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 

**Returns**

Y coordinate of a touch event.


### OH_Input_GetTouchEventFingerId()

```
int32_t OH_Input_GetTouchEventFingerId (const struct Input_TouchEvent * touchEvent)
```

**Description**

Obtains the finger ID of a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 

**Returns**

Finger ID of a touch event.


### OH_Input_InjectKeyEvent()

```
int32_t OH_Input_InjectKeyEvent (const struct Input_KeyEvent * keyEvent)
```

**Description**

Injects a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event to be injected.| 

**Returns**

**0** if the operation is successful; **201** if the required permission is missing; **401** if the input parameter is invalid.


### OH_Input_InjectMouseEvent()

```
int32_t OH_Input_InjectMouseEvent (const struct Input_MouseEvent * mouseEvent)
```

**Description**

Injects a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event to be injected.| 

**Returns**

**0** if the operation is successful; **201** if the required permission is missing; **401** if the input parameter is invalid.


### OH_Input_InjectTouchEvent()

```
int32_t OH_Input_InjectTouchEvent (const struct Input_TouchEvent * touchEvent)
```

**Description**

Injects a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event to be injected.| 

**Returns**

**0** if the operation is successful; **201** if the required permission is missing; **401** if the input parameter is invalid.


### OH_Input_SetKeyCode()

```
void OH_Input_SetKeyCode (struct Input_KeyState * keyState, int32_t keyCode )
```

**Description**

Sets the key value of a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Key status enum object.| 
| keyCode | Key code.| 


### OH_Input_SetKeyEventAction()

```
void OH_Input_SetKeyEventAction (struct Input_KeyEvent * keyEvent, int32_t action )
```

**Description**

Sets the key event type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object.| 
| action | Enumerates key event types.| 


### OH_Input_SetKeyEventActionTime()

```
void OH_Input_SetKeyEventActionTime (struct Input_KeyEvent * keyEvent, int64_t actionTime )
```

**Description**

Sets the time when a key event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object.| 
| actionTime | Time when a key event occurs.| 


### OH_Input_SetKeyEventKeyCode()

```
void OH_Input_SetKeyEventKeyCode (struct Input_KeyEvent * keyEvent, int32_t keyCode )
```

**Description**

Sets the key code value for a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object.| 
| keyCode | Key code value.| 


### OH_Input_SetKeyPressed()

```
void OH_Input_SetKeyPressed (struct Input_KeyState * keyState, int32_t keyAction )
```

**Description**

Sets whether the key specific to a key status enum object is pressed.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Key status enum object.| 
| keyAction | Whether the key is pressed.| 


### OH_Input_SetKeySwitch()

```
void OH_Input_SetKeySwitch (struct Input_KeyState * keyState, int32_t keySwitch )
```

**Description**

Sets the key switch of the key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Key status enum object. For details, see {\@Link Input_KeyStateAction}.| 
| keySwitch | Key switch.| 


### OH_Input_SetMouseEventAction()

```
void OH_Input_SetMouseEventAction (struct Input_MouseEvent * mouseEvent, int32_t action )
```

**Description**

Sets the action for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 
| action | Mouse action.| 


### OH_Input_SetMouseEventActionTime()

```
void OH_Input_SetMouseEventActionTime (struct Input_MouseEvent * mouseEvent, int64_t actionTime )
```

**Description**

Sets the time when a mouse event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 
| actionTime | Time when a mouse event occurs.| 


### OH_Input_SetMouseEventAxisType()

```
void OH_Input_SetMouseEventAxisType (struct Input_MouseEvent * mouseEvent, int32_t axisType )
```

**Description**

Sets the axis type for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 
| axisType | Axis type, for example, X axis or Y axis.| 


### OH_Input_SetMouseEventAxisValue()

```
void OH_Input_SetMouseEventAxisValue (struct Input_MouseEvent * mouseEvent, float axisValue )
```

**Description**

Sets the axis value for a mouse axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 
| axisType | Axis value. A positive value means scrolling forward, and a negative number means scrolling backward.| 


### OH_Input_SetMouseEventButton()

```
void OH_Input_SetMouseEventButton (struct Input_MouseEvent * mouseEvent, int32_t button )
```

**Description**

Sets the button for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 
| button | Mouse button.| 


### OH_Input_SetMouseEventDisplayX()

```
void OH_Input_SetMouseEventDisplayX (struct Input_MouseEvent * mouseEvent, int32_t displayX )
```

**Description**

Sets the X coordinate for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 
| displayX | X coordinate of the mouse event.| 


### OH_Input_SetMouseEventDisplayY()

```
void OH_Input_SetMouseEventDisplayY (struct Input_MouseEvent * mouseEvent, int32_t displayY )
```

**Description**

Sets the Y coordinate for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object.| 
| displayY | Y coordinate of the mouse event.| 


### OH_Input_SetTouchEventAction()

```
void OH_Input_SetTouchEventAction (struct Input_TouchEvent * touchEvent, int32_t action )
```

**Description**

Sets the action for a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 
| Action of the touch event.|  | 


### OH_Input_SetTouchEventActionTime()

```
void OH_Input_SetTouchEventActionTime (struct Input_TouchEvent * touchEvent, int64_t actionTime )
```

**Description**

Sets the time when a touch event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Touch event object.| 
| actionTime | Time when a touch event occurs.| 


### OH_Input_SetTouchEventDisplayX()

```
void OH_Input_SetTouchEventDisplayX (struct Input_TouchEvent * touchEvent, int32_t displayX )
```

**Description**

Sets the X coordinate for a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 
| displayX | X coordinate of a touch event.| 


### OH_Input_SetTouchEventDisplayY()

```
void OH_Input_SetTouchEventDisplayY (struct Input_TouchEvent * touchEvent, int32_t displayY )
```

**Description**

Sets the Y coordinate for a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 
| displayY | Y coordinate of a touch event.| 


### OH_Input_SetTouchEventFingerId()

```
void OH_Input_SetTouchEventFingerId (struct Input_TouchEvent * touchEvent, int32_t id )
```

**Description**

Sets the finger ID for a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object.| 
| id | Finger ID of a touch event.| 
