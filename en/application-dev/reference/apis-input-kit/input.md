# Input

## Overview

Provides C APIs for the multimodal input module.

**Since**: 12


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [oh_axis_type.h](oh__axis__type_8h.md) | Defines the axis event structures and enumerations.| 
| [oh_input_manager.h](oh__input__manager_8h.md) | Provides functions such as event injection and status query. | 
| [oh_key_code.h](oh__key__code_8h.md) | Defines key codes of the key device. | 

### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[Input_InterceptorEventCallback](_input___interceptor_event_callback.md) | Defines the structure of the interceptor for callback events, including mouse events, touch events, and axis events. | 
| struct&nbsp;&nbsp;[Input_DeviceListener](_input___device_listener.md) | Defines a listener for device hot swap events. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [InputEvent_AxisType](#inputevent_axistype) [InputEvent_AxisType](#inputevent_axistype) | Provides axis types of the input device. | 
| typedef enum [InputEvent_AxisEventType](#inputevent_axiseventtype) [InputEvent_AxisEventType](#inputevent_axiseventtype) | Provides event types of the input device. | 
| typedef enum [InputEvent_AxisAction](#inputevent_axisaction) [InputEvent_AxisAction](#inputevent_axisaction) | Provides actions of the input device. | 
| typedef enum [Input_KeyStateAction](#input_keystateaction) [Input_KeyStateAction](#input_keystateaction) | Provides the enum values of the key status. | 
| typedef enum [Input_KeyEventAction](#input_keyeventaction) [Input_KeyEventAction](#input_keyeventaction) | Provides the enum values of the key event type. | 
| typedef enum [Input_MouseEventAction](#input_mouseeventaction) [Input_MouseEventAction](#input_mouseeventaction) | Provides the enum values of mouse actions. | 
| typedef enum [InputEvent_MouseAxis](#inputevent_mouseaxis) [InputEvent_MouseAxis](#inputevent_mouseaxis) | Provides the enum values of mouse axis event types. | 
| typedef enum [Input_MouseEventButton](#input_mouseeventbutton) [Input_MouseEventButton](#input_mouseeventbutton) | Provides the enum values of mouse buttons. | 
| typedef enum [Input_TouchEventAction](#input_toucheventaction) [Input_TouchEventAction](#input_toucheventaction) | Provides the enum values of touch actions. | 
| typedef enum [InputEvent_SourceType](#inputevent_sourcetype) [InputEvent_SourceType](#inputevent_sourcetype) | Provides the enum values of event source types. | 
| typedef enum [Input_KeyboardType](#input_keyboardtype) [Input_KeyboardType](#input_keyboardtype) | Provides the enum values of keyboard types of the input device. | 
| typedef struct [Input_KeyState](#input_keystate) [Input_KeyState](#input_keystate) | Defines key information, which identifies a key pressing behavior. For example, the Ctrl key information contains the key value and key type. | 
| typedef struct [Input_KeyEvent](#input_keyevent) [Input_KeyEvent](#input_keyevent) | Defines the key event to be injected. | 
| typedef struct [Input_MouseEvent](#input_mouseevent) [Input_MouseEvent](#input_mouseevent) | Defines the mouse event to be injected. | 
| typedef struct [Input_TouchEvent](#input_touchevent) [Input_TouchEvent](#input_touchevent) | Defines the touch event to be injected. | 
| typedef struct [Input_AxisEvent](#input_axisevent) [Input_AxisEvent](#input_axisevent) | Defines an axis event. | 
| typedef enum [Input_Result](#input_result) [Input_Result](#input_result) | Provides the enum values of error codes. | 
| typedef void(\* [Input_KeyEventCallback](#input_keyeventcallback)) (const [Input_KeyEvent](#input_keyevent) \*keyEvent) | Defines a lifecycle callback for **keyEvent**. If the callback is triggered, **keyEvent** will be destroyed. | 
| typedef void(\* [Input_MouseEventCallback](#input_mouseeventcallback)) (const [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Defines a lifecycle callback for **mouseEvent**. If the callback is triggered, **mouseEvent** will be destroyed. | 
| typedef void(\* [Input_TouchEventCallback](#input_toucheventcallback)) (const [Input_TouchEvent](#input_touchevent) \*touchEvent) | Defines a lifecycle callback for **touchEvent**. If the callback is triggered, **touchEvent** will be destroyed. | 
| typedef void(\* [Input_AxisEventCallback](#input_axiseventcallback)) (const [Input_AxisEvent](#input_axisevent) \*axisEvent) | Defines a lifecycle callback for **axisEvent**. If the callback is triggered, **axisEvent** will be destroyed. | 
| typedef void(\* [Input_HotkeyCallback](#input_hotkeycallback)) ([Input_Hotkey](#input_hotkey) \*hotkey) | Defines the callback used to return shortcut key events. | 
| typedef void(\* [Input_DeviceAddedCallback](#input_deviceaddedcallback)) (int32_t deviceId) | Defines a callback used to receive device insertion events. | 
| typedef void(\* [Input_DeviceRemovedCallback](#input_deviceremovedcallback)) (int32_t deviceId) | Defines a callback used to receive device removal events. | 
| typedef struct [Input_InterceptorEventCallback](_input___interceptor_event_callback.md) [Input_InterceptorEventCallback](#input_interceptoreventcallback) | Defines the structure of the interceptor for callback events, including mouse events, touch events, and axis events. | 
| typedef struct [Input_DeviceListener](_input___device_listener.md) [Input_DeviceListener](#input_devicelistener) |Defines a listener for device hot swap events. | 
| typedef struct [Input_InterceptorOptions](#input_interceptoroptions) [Input_InterceptorOptions](#input_interceptoroptions) | Defines event interception options. | 
| typedef struct [Input_Hotkey](#input_hotkey) [Input_Hotkey](#input_hotkey) | Defines the shortcut key structure. | 
| typedef struct [Input_DeviceInfo](#input_deviceinfo) [Input_DeviceInfo](#input_deviceinfo) | Defines the input device information. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [InputEvent_AxisType](#inputevent_axistype) {<br>AXIS_TYPE_UNKNOWN, AXIS_TYPE_SCROLL_VERTICAL, AXIS_TYPE_SCROLL_HORIZONTAL, AXIS_TYPE_PINCH,<br>AXIS_TYPE_ROTATE<br>} | Axis type of the input device. | 
| [InputEvent_AxisEventType](#inputevent_axiseventtype) { AXIS_EVENT_TYPE_PINCH = 1, AXIS_EVENT_TYPE_SCROLL = 2 } | Event type of the input device. | 
| [InputEvent_AxisAction](#inputevent_axisaction) { AXIS_ACTION_CANCEL = 0, AXIS_ACTION_BEGIN, AXIS_ACTION_UPDATE, AXIS_ACTION_END } | Action of the input device. | 
| [Input_KeyStateAction](#input_keystateaction) {<br>KEY_DEFAULT = -1, KEY_PRESSED = 0, KEY_RELEASED = 1, KEY_SWITCH_ON = 2,<br>KEY_SWITCH_OFF = 3<br>} | Key status. | 
| [Input_KeyEventAction](#input_keyeventaction) { KEY_ACTION_CANCEL = 0, KEY_ACTION_DOWN = 1, KEY_ACTION_UP = 2 } | Key event type. | 
| [Input_MouseEventAction](#input_mouseeventaction) {<br>MOUSE_ACTION_CANCEL = 0, MOUSE_ACTION_MOVE = 1, MOUSE_ACTION_BUTTON_DOWN = 2, MOUSE_ACTION_BUTTON_UP = 3,<br>MOUSE_ACTION_AXIS_BEGIN = 4, MOUSE_ACTION_AXIS_UPDATE = 5, MOUSE_ACTION_AXIS_END = 6<br>} | Mouse action. | 
| [InputEvent_MouseAxis](#inputevent_mouseaxis) { MOUSE_AXIS_SCROLL_VERTICAL = 0, MOUSE_AXIS_SCROLL_HORIZONTAL = 1 } | Mouse axis event type. | 
| [Input_MouseEventButton](#input_mouseeventbutton) {<br>MOUSE_BUTTON_NONE = -1, MOUSE_BUTTON_LEFT = 0, MOUSE_BUTTON_MIDDLE = 1, MOUSE_BUTTON_RIGHT = 2,<br>MOUSE_BUTTON_FORWARD = 3, MOUSE_BUTTON_BACK = 4<br>} | Mouse button. | 
| [Input_TouchEventAction](#input_toucheventaction) { TOUCH_ACTION_CANCEL = 0, TOUCH_ACTION_DOWN = 1, TOUCH_ACTION_MOVE = 2, TOUCH_ACTION_UP = 3 } | Touch action. | 
| [InputEvent_SourceType](#inputevent_sourcetype) { SOURCE_TYPE_MOUSE = 1, SOURCE_TYPE_TOUCHSCREEN = 2, SOURCE_TYPE_TOUCHPAD = 3 } | Event source type. | 
| [Input_KeyboardType](#input_keyboardtype) {<br>KEYBOARD_TYPE_NONE = 0, KEYBOARD_TYPE_UNKNOWN = 1, KEYBOARD_TYPE_ALPHABETIC = 2, KEYBOARD_TYPE_DIGITAL = 3,<br>KEYBOARD_TYPE_STYLUS = 4, KEYBOARD_TYPE_REMOTE_CONTROL = 5<br>} | Keyboard type of the input device. | 
| [Input_Result](#input_result) {<br>INPUT_SUCCESS = 0, INPUT_PERMISSION_DENIED = 201, INPUT_NOT_SYSTEM_APPLICATION = 202, INPUT_PARAMETER_ERROR = 401, INPUT_DEVICE_NOT_SUPPORTED = 801,<br>INPUT_SERVICE_EXCEPTION = 3800001, INPUT_KEYBOARD_DEVICE_NOT_EXIST = 3900002, INPUT_REPEAT_INTERCEPTOR = 4200001, INPUT_OCCUPIED_BY_SYSTEM = 4200002, <br>INPUT_OCCUPIED_BY_OTHER = 4200003<br>} | Error code. | 
| [Input_KeyCode](#input_keycode) {<br>KEYCODE_UNKNOWN = -1, KEYCODE_FN = 0, KEYCODE_VOLUME_UP = 16, KEYCODE_VOLUME_DOWN = 17,<br>KEYCODE_POWER = 18, KEYCODE_CAMERA = 19, KEYCODE_VOLUME_MUTE = 22, KEYCODE_MUTE = 23,<br>KEYCODE_BRIGHTNESS_UP = 40, KEYCODE_BRIGHTNESS_DOWN = 41, KEYCODE_0 = 2000, KEYCODE_1 = 2001,<br>KEYCODE_2 = 2002, KEYCODE_3 = 2003, KEYCODE_4 = 2004, KEYCODE_5 = 2005,<br>KEYCODE_6 = 2006, KEYCODE_7 = 2007, KEYCODE_8 = 2008, KEYCODE_9 = 2009,<br>KEYCODE_STAR = 2010, KEYCODE_POUND = 2011, KEYCODE_DPAD_UP = 2012, KEYCODE_DPAD_DOWN = 2013,<br>KEYCODE_DPAD_LEFT = 2014, KEYCODE_DPAD_RIGHT = 2015, KEYCODE_DPAD_CENTER = 2016, KEYCODE_A = 2017,<br>KEYCODE_B = 2018, KEYCODE_C = 2019, KEYCODE_D = 2020, KEYCODE_E = 2021,<br>KEYCODE_F = 2022, KEYCODE_G = 2023, KEYCODE_H = 2024, KEYCODE_I = 2025,<br>KEYCODE_J = 2026, KEYCODE_K = 2027, KEYCODE_L = 2028, KEYCODE_M = 2029,<br>KEYCODE_N = 2030, KEYCODE_O = 2031, KEYCODE_P = 2032, KEYCODE_Q = 2033,<br>KEYCODE_R = 2034, KEYCODE_S = 2035, KEYCODE_T = 2036, KEYCODE_U = 2037,<br>KEYCODE_V = 2038, KEYCODE_W = 2039, KEYCODE_X = 2040, KEYCODE_Y = 2041,<br>KEYCODE_Z = 2042, KEYCODE_COMMA = 2043, KEYCODE_PERIOD = 2044, KEYCODE_ALT_LEFT = 2045,<br>KEYCODE_ALT_RIGHT = 2046, KEYCODE_SHIFT_LEFT = 2047, KEYCODE_SHIFT_RIGHT = 2048, KEYCODE_TAB = 2049,<br>KEYCODE_SPACE = 2050, KEYCODE_SYM = 2051, KEYCODE_EXPLORER = 2052, KEYCODE_ENVELOPE = 2053,<br>KEYCODE_ENTER = 2054, KEYCODE_DEL = 2055, KEYCODE_GRAVE = 2056, KEYCODE_MINUS = 2057,<br>KEYCODE_EQUALS = 2058, KEYCODE_LEFT_BRACKET = 2059, KEYCODE_RIGHT_BRACKET = 2060, KEYCODE_BACKSLASH = 2061,<br>KEYCODE_SEMICOLON = 2062, KEYCODE_APOSTROPHE = 2063, KEYCODE_SLASH = 2064, KEYCODE_AT = 2065,<br>KEYCODE_PLUS = 2066, KEYCODE_MENU = 2067, KEYCODE_PAGE_UP = 2068, KEYCODE_PAGE_DOWN = 2069,<br>KEYCODE_ESCAPE = 2070, KEYCODE_FORWARD_DEL = 2071, KEYCODE_CTRL_LEFT = 2072, KEYCODE_CTRL_RIGHT = 2073,<br>KEYCODE_CAPS_LOCK = 2074, KEYCODE_SCROLL_LOCK = 2075, KEYCODE_META_LEFT = 2076, KEYCODE_META_RIGHT = 2077,<br>KEYCODE_FUNCTION = 2078, KEYCODE_SYSRQ = 2079, KEYCODE_BREAK = 2080, KEYCODE_MOVE_HOME = 2081,<br>KEYCODE_MOVE_END = 2082, KEYCODE_INSERT = 2083, KEYCODE_FORWARD = 2084, KEYCODE_MEDIA_PLAY = 2085,<br>KEYCODE_MEDIA_PAUSE = 2086, KEYCODE_MEDIA_CLOSE = 2087, KEYCODE_MEDIA_EJECT = 2088, KEYCODE_MEDIA_RECORD = 2089,<br>KEYCODE_F1 = 2090, KEYCODE_F2 = 2091, KEYCODE_F3 = 2092, KEYCODE_F4 = 2093,<br>KEYCODE_F5 = 2094, KEYCODE_F6 = 2095, KEYCODE_F7 = 2096, KEYCODE_F8 = 2097,<br>KEYCODE_F9 = 2098, KEYCODE_F10 = 2099, KEYCODE_F11 = 2100, KEYCODE_F12 = 2101,<br>KEYCODE_NUM_LOCK = 2102, KEYCODE_NUMPAD_0 = 2103, KEYCODE_NUMPAD_1 = 2104, KEYCODE_NUMPAD_2 = 2105,<br>KEYCODE_NUMPAD_3 = 2106, KEYCODE_NUMPAD_4 = 2107, KEYCODE_NUMPAD_5 = 2108, KEYCODE_NUMPAD_6 = 2109,<br>KEYCODE_NUMPAD_7 = 2110, KEYCODE_NUMPAD_8 = 2111, KEYCODE_NUMPAD_9 = 2112, KEYCODE_NUMPAD_DIVIDE = 2113,<br>KEYCODE_NUMPAD_MULTIPLY = 2114, KEYCODE_NUMPAD_SUBTRACT = 2115, KEYCODE_NUMPAD_ADD = 2116, KEYCODE_NUMPAD_DOT = 2117,<br>KEYCODE_NUMPAD_COMMA = 2118, KEYCODE_NUMPAD_ENTER = 2119, KEYCODE_NUMPAD_EQUALS = 2120, KEYCODE_NUMPAD_LEFT_PAREN = 2121,<br>KEYCODE_NUMPAD_RIGHT_PAREN = 2122, KEYCODE_DAGGER_CLICK = 3211, KEYCODE_DAGGER_DOUBLE_CLICK = 3212, KEYCODE_DAGGER_LONG_PRESS = 3213<br>} | Key code value. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Input_Result](#input_result) [OH_Input_GetKeyState](#oh_input_getkeystate) (struct [Input_KeyState](#input_keystate) \*keyState) | Queries a key status enum object. | 
| struct [Input_KeyState](#input_keystate) \* [OH_Input_CreateKeyState](#oh_input_createkeystate) () | Creates a key status enum object. | 
| void [OH_Input_DestroyKeyState](#oh_input_destroykeystate) (struct [Input_KeyState](#input_keystate) \*\*keyState) | Destroys a key status enum object. | 
| void [OH_Input_SetKeyCode](#oh_input_setkeycode) (struct [Input_KeyState](#input_keystate) \*keyState, int32_t keyCode) | Sets the key value of a key status enum object. | 
| int32_t [OH_Input_GetKeyCode](#oh_input_getkeycode) (const struct [Input_KeyState](#input_keystate) \*keyState) | Obtains the key value of a key status enum object. | 
| void [OH_Input_SetKeyPressed](#oh_input_setkeypressed) (struct [Input_KeyState](#input_keystate) \*keyState, int32_t keyAction) | Sets whether the key specific to a key status enum object is pressed. | 
| int32_t [OH_Input_GetKeyPressed](#oh_input_getkeypressed) (const struct [Input_KeyState](#input_keystate) \*keyState) | Checks whether the key specific to a key status enum object is pressed. | 
| void [OH_Input_SetKeySwitch](#oh_input_setkeyswitch) (struct [Input_KeyState](#input_keystate) \*keyState, int32_t keySwitch) | Sets the key switch of the key status enum object. | 
| int32_t [OH_Input_GetKeySwitch](#oh_input_getkeyswitch) (const struct [Input_KeyState](#input_keystate) \*keyState) | Obtains the key switch of the key status enum object. | 
| int32_t [OH_Input_InjectKeyEvent](#oh_input_injectkeyevent) (const struct [Input_KeyEvent](#input_keyevent) \*keyEvent) | Injects a key event. | 
| struct [Input_KeyEvent](#input_keyevent) \* [OH_Input_CreateKeyEvent](#oh_input_createkeyevent) () | Creates a key event object. | 
| void [OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent) (struct [Input_KeyEvent](#input_keyevent) \*\*keyEvent) | Destroys a key event object.| 
| void [OH_Input_SetKeyEventAction](#oh_input_setkeyeventaction) (struct [Input_KeyEvent](#input_keyevent) \*keyEvent, int32_t action) | Sets the key event type. | 
| int32_t [OH_Input_GetKeyEventAction](#oh_input_getkeyeventaction) (const struct [Input_KeyEvent](#input_keyevent) \*keyEvent) | Obtains the key event type. | 
| void [OH_Input_SetKeyEventKeyCode](#oh_input_setkeyeventkeycode) (struct [Input_KeyEvent](#input_keyevent) \*keyEvent, int32_t keyCode) | Sets the key code value for a key event. | 
| int32_t [OH_Input_GetKeyEventKeyCode](#oh_input_getkeyeventkeycode) (const struct [Input_KeyEvent](#input_keyevent) \*keyEvent) | Obtains the key code value of a key event. | 
| void [OH_Input_SetKeyEventActionTime](#oh_input_setkeyeventactiontime) (struct [Input_KeyEvent](#input_keyevent) \*keyEvent, int64_t actionTime) | Sets the time when a key event occurs. | 
| int64_t [OH_Input_GetKeyEventActionTime](#oh_input_getkeyeventactiontime) (const struct [Input_KeyEvent](#input_keyevent) \*keyEvent) | Obtains the time when a key event occurs. | 
| void [OH_Input_SetKeyEventWindowId](#oh_input_setkeyeventwindowid) (struct [Input_KeyEvent](#input_keyevent) \*keyEvent, int32_t windowId) | Sets the window ID of a key event. | 
| int32_t [OH_Input_GetKeyEventWindowId](#oh_input_getkeyeventwindowid) (const struct [Input_KeyEvent](#input_keyevent) \*keyEvent) | Obtains the window ID of a key event. | 
| void [OH_Input_SetKeyEventDisplayId](#oh_input_setkeyeventdisplayid) (struct [Input_KeyEvent](#input_keyevent) \*keyEvent, int32_t displayId) | Sets the screen ID of a key event. | 
| int32_t [OH_Input_GetKeyEventDisplayId](#oh_input_getkeyeventdisplayid) (const struct [Input_KeyEvent](#input_keyevent) \*keyEvent) | Obtains the screen ID of a key event. | 
| int32_t [OH_Input_InjectMouseEvent](#oh_input_injectmouseevent) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Injects a mouse event. | 
| struct [Input_MouseEvent](#input_mouseevent) \* [OH_Input_CreateMouseEvent](#oh_input_createmouseevent) () | Creates a mouse event object. | 
| void [OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent) (struct [Input_MouseEvent](#input_mouseevent) \*\*mouseEvent) | Destroys a mouse event object.| 
| void [OH_Input_SetMouseEventAction](#oh_input_setmouseeventaction) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, int32_t action) | Sets the action for a mouse event. | 
| int32_t [OH_Input_GetMouseEventAction](#oh_input_getmouseeventaction) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the action of a mouse event. | 
| void [OH_Input_SetMouseEventDisplayX](#oh_input_setmouseeventdisplayx) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, int32_t displayX) | Sets the X coordinate for a mouse event. | 
| int32_t [OH_Input_GetMouseEventDisplayX](#oh_input_getmouseeventdisplayx) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the X coordinate of a mouse event. | 
| void [OH_Input_SetMouseEventDisplayY](#oh_input_setmouseeventdisplayy) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, int32_t displayY) | Sets the Y coordinate for a mouse event. | 
| int32_t [OH_Input_GetMouseEventDisplayY](#oh_input_getmouseeventdisplayy) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the Y coordinate of a mouse event. | 
| void [OH_Input_SetMouseEventButton](#oh_input_setmouseeventbutton) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, int32_t button) | Sets the button for a mouse event. | 
| int32_t [OH_Input_GetMouseEventButton](#oh_input_getmouseeventbutton) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the button of a mouse event. | 
| void [OH_Input_SetMouseEventAxisType](#oh_input_setmouseeventaxistype) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, int32_t axisType) | Sets the axis type for a mouse event. | 
| int32_t [OH_Input_GetMouseEventAxisType](#oh_input_getmouseeventaxistype) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the axis type of a mouse event. | 
| void [OH_Input_SetMouseEventAxisValue](#oh_input_setmouseeventaxisvalue) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, float axisValue) | Sets the axis value for a mouse axis event. | 
| float [OH_Input_GetMouseEventAxisValue](#oh_input_getmouseeventaxisvalue) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the axis value of a mouse axis event. | 
| void [OH_Input_SetMouseEventActionTime](#oh_input_setmouseeventactiontime) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, int64_t actionTime) | Sets the time when a mouse event occurs. | 
| int64_t [OH_Input_GetMouseEventActionTime](#oh_input_getmouseeventactiontime) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the time when a mouse event occurs. | 
| void [OH_Input_SetMouseEventWindowId](#oh_input_setmouseeventwindowid) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, int32_t windowId) | Sets the window ID of a mouse event. | 
| int32_t [OH_Input_GetMouseEventWindowId](#oh_input_getmouseeventwindowid) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the window ID of a mouse event. | 
| void [OH_Input_SetMouseEventDisplayId](#oh_input_setmouseeventdisplayid) (struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent, int32_t displayId) | Sets the screen ID of a mouse event. | 
| int32_t [OH_Input_GetMouseEventDisplayId](#oh_input_getmouseeventdisplayid) (const struct [Input_MouseEvent](#input_mouseevent) \*mouseEvent) | Obtains the screen ID of a mouse event. | 
| int32_t [OH_Input_InjectTouchEvent](#oh_input_injecttouchevent) (const struct [Input_TouchEvent](#input_touchevent) \*touchEvent) | Injects a touch event. | 
| struct [Input_TouchEvent](#input_touchevent) \* [OH_Input_CreateTouchEvent](#oh_input_createtouchevent) () | Creates a touch event object. | 
| void [OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent) (struct [Input_TouchEvent](#input_touchevent) \*\*touchEvent) | Destroys a touch event object. | 
| void [OH_Input_SetTouchEventAction](#oh_input_settoucheventaction) (struct [Input_TouchEvent](#input_touchevent) \*touchEvent, int32_t action) | Sets the action for a touch event. | 
| int32_t [OH_Input_GetTouchEventAction](#oh_input_gettoucheventaction) (const struct [Input_TouchEvent](#input_touchevent) \*touchEvent) | Obtains the action of a touch event. | 
| void [OH_Input_SetTouchEventFingerId](#oh_input_settoucheventfingerid) (struct [Input_TouchEvent](#input_touchevent) \*touchEvent, int32_t id) | Sets the finger ID for a touch event. | 
| int32_t [OH_Input_GetTouchEventFingerId](#oh_input_gettoucheventfingerid) (const struct [Input_TouchEvent](#input_touchevent) \*touchEvent) | Obtains the finger ID of a touch event. | 
| void [OH_Input_SetTouchEventDisplayX](#oh_input_settoucheventdisplayx) (struct [Input_TouchEvent](#input_touchevent) \*touchEvent, int32_t displayX) | Sets the X coordinate for a touch event.| 
| int32_t [OH_Input_GetTouchEventDisplayX](#oh_input_gettoucheventdisplayx) (const struct [Input_TouchEvent](#input_touchevent) \*touchEvent) | Obtains the X coordinate of a touch event. | 
| void [OH_Input_SetTouchEventDisplayY](#oh_input_settoucheventdisplayy) (struct [Input_TouchEvent](#input_touchevent) \*touchEvent, int32_t displayY) | Sets the Y coordinate for a touch event. | 
| int32_t [OH_Input_GetTouchEventDisplayY](#oh_input_gettoucheventdisplayy) (const struct [Input_TouchEvent](#input_touchevent) \*touchEvent) | Obtains the Y coordinate of a touch event. | 
| void [OH_Input_SetTouchEventActionTime](#oh_input_settoucheventactiontime) (struct [Input_TouchEvent](#input_touchevent) \*touchEvent, int64_t actionTime) | Sets the time when a touch event occurs. | 
| int64_t [OH_Input_GetTouchEventActionTime](#oh_input_gettoucheventactiontime) (const struct [Input_TouchEvent](#input_touchevent) \*touchEvent) | Obtains the time when a touch event occurs. | 
| void [OH_Input_SetTouchEventWindowId](#oh_input_settoucheventwindowid) (struct [Input_TouchEvent](#input_touchevent) \*touchEvent, int32_t windowId) | Sets the window ID of a touchscreen event. | 
| int32_t [OH_Input_GetTouchEventWindowId](#oh_input_gettoucheventwindowid) (const struct [Input_TouchEvent](#input_touchevent) \*touchEvent) | Obtains the window ID of a touchscreen event. | 
| void [OH_Input_SetTouchEventDisplayId](#oh_input_settoucheventdisplayid) (struct [Input_TouchEvent](#input_touchevent) \*touchEvent, int32_t displayId) | Sets the screen ID of a touchscreen event. | 
| int32_t [OH_Input_GetTouchEventDisplayId](#oh_input_gettoucheventdisplayid) (const struct [Input_TouchEvent](#input_touchevent) \*touchEvent) | Obtains the screen ID of a touchscreen event. | 
| void [OH_Input_CancelInjection](#oh_input_cancelinjection) () | Stops event injection and revokes authorization. | 
| [Input_AxisEvent](#input_axisevent) \* [OH_Input_CreateAxisEvent](#oh_input_createaxisevent) (void) | Creates an axis event object. | 
| [Input_Result](#input_result) [OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent) ([Input_AxisEvent](#input_axisevent) \*\*axisEvent) | Destroys an axis event object. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventAction](#oh_input_setaxiseventaction) ([Input_AxisEvent](#input_axisevent) \*axisEvent, [InputEvent_AxisAction](#inputevent_axisaction) action) | Sets the action for an axis event. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventAction](#oh_input_getaxiseventaction) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, [InputEvent_AxisAction](#inputevent_axisaction) \*action) | Obtains the action of an axis event. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventDisplayX](#oh_input_setaxiseventdisplayx) ([Input_AxisEvent](#input_axisevent) \*axisEvent, float displayX) | Sets the X coordinate for an axis event. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventDisplayX](#oh_input_getaxiseventdisplayx) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, float \*displayX) | Obtains the X coordinate of an axis event. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventDisplayY](#oh_input_setaxiseventdisplayy) ([Input_AxisEvent](#input_axisevent) \*axisEvent, float displayY) | Sets the Y coordinate for an axis event. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventDisplayY](#oh_input_getaxiseventdisplayy) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, float \*displayY) | Obtains the Y coordinate of an axis event. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventAxisValue](#oh_input_setaxiseventaxisvalue) ([Input_AxisEvent](#input_axisevent) \*axisEvent, [InputEvent_AxisType](#inputevent_axistype) axisType, double axisValue) | Sets the axis value of the axis type specified by the axis event. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventAxisValue](#oh_input_getaxiseventaxisvalue) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, [InputEvent_AxisType](#inputevent_axistype) axisType, double \*axisValue) | Obtains the axis value for the specified axis type of the axis event. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventActionTime](#oh_input_setaxiseventactiontime) ([Input_AxisEvent](#input_axisevent) \*axisEvent, int64_t actionTime) | Sets the time when an axis event occurs. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventActionTime](#oh_input_getaxiseventactiontime) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, int64_t \*actionTime) | Obtains the time when an axis event occurs. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventType](#oh_input_setaxiseventtype) ([Input_AxisEvent](#input_axisevent) \*axisEvent, [InputEvent_AxisEventType](#inputevent_axiseventtype) axisEventType) | Sets the axis event type. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventType](#oh_input_getaxiseventtype) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, [InputEvent_AxisEventType](#inputevent_axiseventtype) \*axisEventType) | Obtains the axis event type. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventSourceType](#oh_input_setaxiseventsourcetype) ([Input_AxisEvent](#input_axisevent) \*axisEvent, [InputEvent_SourceType](#inputevent_sourcetype) sourceType) | Sets the axis event source type. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventSourceType](#oh_input_getaxiseventsourcetype) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, [InputEvent_SourceType](#inputevent_sourcetype) \*sourceType) | Obtains the axis event source type. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventWindowId](#oh_input_setaxiseventwindowid) ([Input_AxisEvent](#input_axisevent) \*axisEvent, int32_t windowId) | Sets the window ID of an axis event. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventWindowId](#oh_input_getaxiseventwindowid) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, int32_t \*windowId) | Obtains the window ID of an axis event. | 
| [Input_Result](#input_result) [OH_Input_SetAxisEventDisplayId](#oh_input_setaxiseventdisplayid) ([Input_AxisEvent](#input_axisevent) \*axisEvent, int32_t displayId) | Sets the screen ID of an axis event. | 
| [Input_Result](#input_result) [OH_Input_GetAxisEventDisplayId](#oh_input_getaxiseventdisplayid) (const [Input_AxisEvent](#input_axisevent) \*axisEvent, int32_t \*displayId) | Obtains the screen ID of an axis event. | 
| [Input_Result](#input_result) [OH_Input_AddKeyEventMonitor](#oh_input_addkeyeventmonitor) ([Input_KeyEventCallback](#input_keyeventcallback) callback) | Adds a listener for key events. | 
| [Input_Result](#input_result) [OH_Input_AddMouseEventMonitor](#oh_input_addmouseeventmonitor) ([Input_MouseEventCallback](#input_mouseeventcallback) callback) | Adds a listener for mouse events, including mouse click and movement events, but not scroll wheel events. Scroll wheel events are axis events. | 
| [Input_Result](#input_result) [OH_Input_AddTouchEventMonitor](#oh_input_addtoucheventmonitor) ([Input_TouchEventCallback](#input_toucheventcallback) callback) | Adds a listener for touch events. | 
| [Input_Result](#input_result) [OH_Input_AddAxisEventMonitorForAll](#oh_input_addaxiseventmonitorforall) ([Input_AxisEventCallback](#input_axiseventcallback) callback) | Adds a listener for all types of axis events, which are defined in [InputEvent_AxisEventType](#inputevent_axiseventtype). | 
| [Input_Result](#input_result) [OH_Input_AddAxisEventMonitor](#oh_input_addaxiseventmonitor) ([InputEvent_AxisEventType](#inputevent_axiseventtype) axisEventType, [Input_AxisEventCallback](#input_axiseventcallback) callback) | Adds a listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](#inputevent_axiseventtype). | 
| [Input_Result](#input_result) [OH_Input_RemoveKeyEventMonitor](#oh_input_removekeyeventmonitor) ([Input_KeyEventCallback](#input_keyeventcallback) callback) | Removes the listener for key events. | 
| [Input_Result](#input_result) [OH_Input_RemoveMouseEventMonitor](#oh_input_removemouseeventmonitor) ([Input_MouseEventCallback](#input_mouseeventcallback) callback) | Removes the listener for mouse events. | 
| [Input_Result](#input_result) [OH_Input_RemoveTouchEventMonitor](#oh_input_removetoucheventmonitor) ([Input_TouchEventCallback](#input_toucheventcallback) callback) | Removes the listener for touch events. | 
| [Input_Result](#input_result) [OH_Input_RemoveAxisEventMonitorForAll](#oh_input_removeaxiseventmonitorforall) ([Input_AxisEventCallback](#input_axiseventcallback) callback) | Removes the listener for all types of axis events. | 
| [Input_Result](#input_result) [OH_Input_RemoveAxisEventMonitor](#oh_input_removeaxiseventmonitor) ([InputEvent_AxisEventType](#inputevent_axiseventtype) axisEventType, [Input_AxisEventCallback](#input_axiseventcallback) callback) | Removes the listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](#inputevent_axiseventtype). | 
| [Input_Result](#input_result) [OH_Input_AddKeyEventInterceptor](#oh_input_addkeyeventinterceptor) ([Input_KeyEventCallback](#input_keyeventcallback) callback, [Input_InterceptorOptions](#input_interceptoroptions) \*option) | Adds an interceptor for key events. If multiple interceptors are added, only the first one takes effect. An interception event is reported only when the application gains focus. | 
| [Input_Result](#input_result) [OH_Input_AddInputEventInterceptor](#oh_input_addinputeventinterceptor) ([Input_InterceptorEventCallback](_input___interceptor_event_callback.md) \*callback, [Input_InterceptorOptions](#input_interceptoroptions) \*option) | Adds an interceptor for input events, including mouse, touch, and axis events. If multiple interceptors are added, only the first one takes effect. An interception event is reported only when the application gains focus. | 
| [Input_Result](#input_result) [OH_Input_RemoveKeyEventInterceptor](#oh_input_removekeyeventinterceptor) (void) | Removes the interceptor for key events. | 
| [Input_Result](#input_result) [OH_Input_RemoveInputEventInterceptor](#oh_input_removeinputeventinterceptor) (void) | Removes the interceptor for input events, including mouse, touch, and axis events. | 
| [Input_Result](#input_result) [OH_Input_GetIntervalSinceLastInput](#oh_input_getintervalsincelastinput) (int64_t \*timeInterval) | Obtains the interval since the last system input event. | 
| [Input_Hotkey](#input_hotkey) \* [OH_Input_CreateHotkey](#oh_input_createhotkey) (void) | Creates a shortcut key object. | 
| void [OH_Input_DestroyHotkey](#oh_input_destroyhotkey) ([Input_Hotkey](#input_hotkey) \*\*hotkey) | Destroys a shortcut key object. | 
| void [OH_Input_SetPreKeys](#oh_input_setprekeys) ([Input_Hotkey](#input_hotkey) \*hotkey, int32_t \*preKeys, int32_t size) | Sets the modifier key. | 
| [Input_Result](#input_result) [OH_Input_GetPreKeys](#oh_input_getprekeys) (const [Input_Hotkey](#input_hotkey) \*hotkey, int32_t \*\*preKeys, int32_t \*preKeyCount) | Obtains the modifier key. | 
| void [OH_Input_SetFinalKey](#oh_input_setfinalkey) ([Input_Hotkey](#input_hotkey) \*hotkey, int32_t finalKey) | Sets the modified key. | 
| [Input_Result](#input_result) [OH_Input_GetFinalKey](#oh_input_getfinalkey) (const [Input_Hotkey](#input_hotkey) \*hotkey, int32_t \*finalKeyCode) | Obtains the modified key. | 
| [Input_Hotkey](#input_hotkey) \*\* [OH_Input_CreateAllSystemHotkeys](#oh_input_createallsystemhotkeys) (int32_t count) | Creates an array of [Input_Hotkey](#input_hotkey) instances. | 
| void [OH_Input_DestroyAllSystemHotkeys](#oh_input_destroyallsystemhotkeys) ([Input_Hotkey](#input_hotkey) \*\*hotkeys, int32_t count) | Destroys the array of [Input_Hotkey](#input_hotkey) instances and reclaims the memory. | 
| [Input_Result](#input_result) [OH_Input_GetAllSystemHotkeys](#oh_input_getallsystemhotkeys) ([Input_Hotkey](#input_hotkey) \*\*hotkey, int32_t \*count) | Obtains all configured shortcut keys. | 
| void [OH_Input_SetRepeat](#oh_input_setrepeat) ([Input_Hotkey](#input_hotkey) \*hotkey, bool isRepeat) | Specifies whether to report repeated key events. | 
| [Input_Result](#input_result) [OH_Input_GetRepeat](#oh_input_getrepeat) (const [Input_Hotkey](#input_hotkey) \*hotkey, bool \*isRepeat) | Checks whether to report repeated key events. | 
| [Input_Result](#input_result) [OH_Input_AddHotkeyMonitor](#oh_input_addhotkeymonitor) (const [Input_Hotkey](#input_hotkey) \*hotkey, [Input_HotkeyCallback](#input_hotkeycallback) callback) | Subscribes to shortcut key events. This API is not applicable to wearables and lite wearables. | 
| [Input_Result](#input_result) [OH_Input_RemoveHotkeyMonitor](#oh_input_removehotkeymonitor) (const [Input_Hotkey](#input_hotkey) \*hotkey, [Input_HotkeyCallback](#input_hotkeycallback) callback) | Unsubscribes from shortcut key events. | 
| [Input_Result](#input_result) [OH_Input_GetDeviceIds](#oh_input_getdeviceids) (int32_t \*deviceIds, int32_t inSize, int32_t \*outSize) | Obtains the IDs of all input devices. | 
| [Input_Result](#input_result) [OH_Input_GetDevice](#oh_input_getdevice) (int32_t deviceId, [Input_DeviceInfo](#input_deviceinfo) \*\*deviceInfo) | Obtains information about the input device. | 
| [Input_DeviceInfo](#input_deviceinfo) \* [OH_Input_CreateDeviceInfo](#oh_input_createdeviceinfo) (void) | Creates a **deviceInfo** object. | 
| void [OH_Input_DestroyDeviceInfo](#oh_input_destroydeviceinfo) ([Input_DeviceInfo](#input_deviceinfo) \*\*deviceInfo) | Destroys a **deviceInfo** object. | 
| [Input_Result](#input_result) [OH_Input_GetKeyboardType](#oh_input_getkeyboardtype) (int32_t deviceId, int32_t \*keyboardType) | Obtains the keyboard type of the input device. | 
| [Input_Result](#input_result) [OH_Input_GetDeviceId](#oh_input_getdeviceid) ([Input_DeviceInfo](#input_deviceinfo) \*deviceInfo, int32_t \*id) | Obtains the ID of an input device. | 
| [Input_Result](#input_result) [OH_Input_GetDeviceName](#oh_input_getdevicename) ([Input_DeviceInfo](#input_deviceinfo) \*deviceInfo, char \*\*name) | Obtains the name of an input device. | 
| [Input_Result](#input_result) [OH_Input_GetCapabilities](#oh_input_getcapabilities) ([Input_DeviceInfo](#input_deviceinfo) \*deviceInfo, int32_t \*capabilities) | Obtains the capabilities of an input device, for example, a touchscreen, touchpad, or keyboard. | 
| [Input_Result](#input_result) [OH_Input_GetDeviceVersion](#oh_input_getdeviceversion) ([Input_DeviceInfo](#input_deviceinfo) \*deviceInfo, int32_t \*version) | Obtains the version information of an input device. | 
| [Input_Result](#input_result) [OH_Input_GetDeviceProduct](#oh_input_getdeviceproduct) ([Input_DeviceInfo](#input_deviceinfo) \*deviceInfo, int32_t \*product) | Obtains the product information of an input device. | 
| [Input_Result](#input_result) [OH_Input_GetDeviceVendor](#oh_input_getdevicevendor) ([Input_DeviceInfo](#input_deviceinfo) \*deviceInfo, int32_t \*vendor) | Obtains the vendor information of an input device. | 
| [Input_Result](#input_result) [OH_Input_GetDeviceAddress](#oh_input_getdeviceaddress) ([Input_DeviceInfo](#input_deviceinfo) \*deviceInfo, char \*\*address) | Obtains the physical address of an input device. | 
| [Input_Result](#input_result) [OH_Input_RegisterDeviceListener](#oh_input_registerdevicelistener) ([Input_DeviceListener](_input___device_listener.md) \*listener) | Registers a listener for device hot swap events. | 
| [Input_Result](#input_result) [OH_Input_UnregisterDeviceListener](#oh_input_unregisterdevicelistener) ([Input_DeviceListener](_input___device_listener.md) \*listener) | Unregisters the listener for device hot swap events. | 
| [Input_Result](#input_result) [OH_Input_UnregisterDeviceListeners](#oh_input_unregisterdevicelisteners) () | Unregisters the listener for all device hot swap events. | 
| [Input_Result](#input_result) [OH_Input_GetFunctionKeyState](#oh_input_getfunctionkeystate) (int32_t keyCode, int32_t \*state) | Obtains the function key status. | 


## Type Description


### Input_AxisEvent

```
typedef struct Input_AxisEventInput_AxisEvent
```
**Description**

Defines an axis event.

**Since**: 12


### Input_AxisEventCallback

```
typedef void(* Input_AxisEventCallback) (const Input_AxisEvent *axisEvent)
```
**Description**

Defines a lifecycle callback for **axisEvent**. If the callback is triggered, **axisEvent** will be destroyed.

**Since**: 12

**Parameters**

| Name| Description   | 
| ------ | ------ |
| axisEvent | Axis event object.|

### Input_DeviceAddedCallback

```
typedef void(* Input_DeviceAddedCallback) (int32_t deviceId)
```
**Description**

Defines a callback used to receive device insertion events.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | Device ID. | 

### Input_DeviceInfo

```
typedef struct Input_DeviceInfoInput_DeviceInfo
```
**Description**

Defines the input device information.

**Since**: 13

### Input_DeviceListener

```
typedef struct Input_DeviceListenerInput_DeviceListener
```
**Description**

Defines a listener for device hot swap events.

**Since**: 13

### Input_DeviceRemovedCallback

```
typedef void(* Input_DeviceRemovedCallback) (int32_t deviceId)
```
**Description**

Defines a callback used to receive device removal events.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | Device ID. | 


### Input_Hotkey

```
typedef struct Input_Hotkey Input_Hotkey
```
**Description**

Defines the shortcut key structure.

**Since**: 14


### Input_HotkeyCallback

```
typedef void(* Input_HotkeyCallback) (Input_Hotkey *hotkey)
```
**Description**

Defines the callback used to return shortcut key events.

**Since**: 14


### Input_InterceptorEventCallback

```
typedef struct Input_InterceptorEventCallbackInput_InterceptorEventCallback
```
**Description**

Defines the structure of the interceptor for callback events, including mouse events, touch events, and axis events.

**Since**: 12


### Input_InterceptorOptions

```
typedef struct Input_InterceptorOptionsInput_InterceptorOptions
```
**Description**

Defines event interception options.

**Since**: 12


### Input_KeyboardType

```
typedef enum Input_KeyboardTypeInput_KeyboardType
```
**Description**

Enumerates keyboard types of the input device.

**Since**: 13


### Input_KeyEvent

```
typedef struct Input_KeyEventInput_KeyEvent
```
**Description**

Defines the key event to be injected.

**Since**: 12


### Input_KeyEventAction

```
typedef enum Input_KeyEventActionInput_KeyEventAction
```
**Description**

Provides the enum values of the key event type.

**Since**: 12


### Input_KeyEventCallback

```
typedef void(* Input_KeyEventCallback) (const Input_KeyEvent *keyEvent)
```
**Description**

Defines a lifecycle callback for **keyEvent**. If the callback is triggered, **keyEvent** will be destroyed.

**Since**: 12

**Parameters**

| Name|Description   | 
| ------ | ------ |
| keyEvent | Key event object.|

### Input_KeyState

```
typedef struct Input_KeyStateInput_KeyState
```
**Description**

Defines key information, which identifies a key pressing behavior. For example, the Ctrl key information contains the key value and key type.

**Since**: 12


### Input_KeyStateAction

```
typedef enum Input_KeyStateActionInput_KeyStateAction
```
**Description**

Provides the enum values of the key status.

**Since**: 12


### Input_MouseEvent

```
typedef struct Input_MouseEventInput_MouseEvent
```
**Description**

Defines the mouse event to be injected.

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


### Input_MouseEventCallback

```
typedef void(* Input_MouseEventCallback) (const Input_MouseEvent *mouseEvent)
```
**Description**

Defines a lifecycle callback for **mouseEvent**. If the callback is triggered, **mouseEvent** will be destroyed.

**Since**: 12

**Parameters**

| Name| Description   |
| ------ | ------ |
| mouseEvent | Mouse event object.|

### Input_Result

```
typedef enum Input_ResultInput_Result
```
**Description**

Provides the enum values of error codes.

**Since**: 12


### Input_TouchEvent

```
typedef struct Input_TouchEventInput_TouchEvent
```
**Description**

Defines the touch event to be injected.

**Since**: 12


### Input_TouchEventAction

```
typedef enum Input_TouchEventActionInput_TouchEventAction
```
**Description**

Provides the enum values of touch actions.

**Since**: 12


### Input_TouchEventCallback

```
typedef void(* Input_TouchEventCallback) (const Input_TouchEvent *touchEvent)
```
**Description**

Defines a lifecycle callback for **touchEvent**. If the callback is triggered, **touchEvent** will be destroyed.

**Since**: 12

**Parameters**

| Name| Description   |
| ------ | ------ |
| touchEvent | Touch event object.|

### InputEvent_AxisAction

```
typedef enum InputEvent_AxisActionInputEvent_AxisAction
```
**Description**

Action of the input device.

**Since**: 12


### InputEvent_AxisEventType

```
typedef enum InputEvent_AxisEventTypeInputEvent_AxisEventType
```
**Description**

Event type of the input device.

**Since**: 12


### InputEvent_AxisType

```
typedef enum InputEvent_AxisTypeInputEvent_AxisType
```
**Description**

Defines the axis type of an input device.

**Since**: 12


### InputEvent_MouseAxis

```
typedef enum InputEvent_MouseAxisInputEvent_MouseAxis
```
**Description**

Provides the enum values of mouse axis event types.

**Since**: 12


### InputEvent_SourceType

```
typedef enum InputEvent_SourceTypeInputEvent_SourceType
```
**Description**

Enter the event source type.

**Since**: 12


## Enum Description


### Input_KeyboardType

```
enum Input_KeyboardType
```
**Description**

Enumerates keyboard types of the input device.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| KEYBOARD_TYPE_NONE  | Keyboard without keys.| 
| KEYBOARD_TYPE_UNKNOWN  | Keyboard with unknown keys.| 
| KEYBOARD_TYPE_ALPHABETIC  | Full keyboard.| 
| KEYBOARD_TYPE_DIGITAL  | Numeric keypad.| 
| KEYBOARD_TYPE_STYLUS  | Stylus.| 
| KEYBOARD_TYPE_REMOTE_CONTROL  | Remote control.| 


### Input_KeyCode

```
enum Input_KeyCode
```
**Description**

Enumerates key code values.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| KEYCODE_UNKNOWN  | Unknown key| 
| KEYCODE_FN  | Function (Fn) key| 
| KEYCODE_VOLUME_UP  | Volume Up key| 
| KEYCODE_VOLUME_DOWN  | Volume Down key| 
| KEYCODE_POWER  | Power key| 
| KEYCODE_CAMERA  | Camera key| 
| KEYCODE_VOLUME_MUTE  | Speaker Mute key| 
| KEYCODE_MUTE  | Mute key| 
| KEYCODE_BRIGHTNESS_UP  | Brightness Up key| 
| KEYCODE_BRIGHTNESS_DOWN  | Brightness Down key| 
| KEYCODE_0  | Key 0| 
| KEYCODE_1  | Key 1| 
| KEYCODE_2  | Key 2| 
| KEYCODE_3  | Key 3| 
| KEYCODE_4  | Key 4| 
| KEYCODE_5  | Key 5| 
| KEYCODE_6  | Key 6| 
| KEYCODE_7  | Key 7| 
| KEYCODE_8  | Key 8| 
| KEYCODE_9  | Key 9| 
| KEYCODE_STAR  | Key \*| 
| KEYCODE_POUND  | Key \#| 
| KEYCODE_DPAD_UP  | Up key on D-pad| 
| KEYCODE_DPAD_DOWN  | Down key on D-pad| 
| KEYCODE_DPAD_LEFT  | Left key on D-pad| 
| KEYCODE_DPAD_RIGHT  | Right key on D-pad| 
| KEYCODE_DPAD_CENTER  | Center key on D-pad| 
| KEYCODE_A  | Key A| 
| KEYCODE_B  | Key B| 
| KEYCODE_C  | Key C| 
| KEYCODE_D  | Key D| 
| KEYCODE_E  | Key E| 
| KEYCODE_F  | Key F| 
| KEYCODE_G  | Key G| 
| KEYCODE_H  | Key H| 
| KEYCODE_I  | Key I| 
| KEYCODE_J  | Key J| 
| KEYCODE_K  | Key K| 
| KEYCODE_L  | Key L| 
| KEYCODE_M  | Key M| 
| KEYCODE_N  | Key N| 
| KEYCODE_O  | Key O| 
| KEYCODE_P  | Key P| 
| KEYCODE_Q  | Key Q| 
| KEYCODE_R  | Key R| 
| KEYCODE_S  | Key S| 
| KEYCODE_T  | Key T| 
| KEYCODE_U  | Key U| 
| KEYCODE_V  | Key V| 
| KEYCODE_W  | Key W| 
| KEYCODE_X  | Key X| 
| KEYCODE_Y  | Key Y| 
| KEYCODE_Z  | Key Z| 
| KEYCODE_COMMA  | Key ,| 
| KEYCODE_PERIOD  | Key .| 
| KEYCODE_ALT_LEFT  | Left Alt key| 
| KEYCODE_ALT_RIGHT  | Right Alt key| 
| KEYCODE_SHIFT_LEFT  | Left Shift key| 
| KEYCODE_SHIFT_RIGHT  | Right Shift key| 
| KEYCODE_TAB  | Tab key| 
| KEYCODE_SPACE  | Space key| 
| KEYCODE_SYM  | Symbol key| 
| KEYCODE_EXPLORER  | Explorer key, which is used to start the explorer application| 
| KEYCODE_ENVELOPE  | Email key, which is used to start the email application| 
| KEYCODE_ENTER  | Enter key| 
| KEYCODE_DEL  | Delete key| 
| KEYCODE_GRAVE  | Key `| 
| KEYCODE_MINUS  | Key -| 
| KEYCODE_EQUALS  | Key =| 
| KEYCODE_LEFT_BRACKET  | Key [| 
| KEYCODE_RIGHT_BRACKET  | Key ]| 
| KEYCODE_BACKSLASH  | Key \| 
| KEYCODE_SEMICOLON  | Key ;| 
| KEYCODE_APOSTROPHE  | Key '| 
| KEYCODE_SLASH  | Key /| 
| KEYCODE_AT  | Key \@| 
| KEYCODE_PLUS  | Key +| 
| KEYCODE_MENU  | Menu key| 
| KEYCODE_PAGE_UP  | Page Up key| 
| KEYCODE_PAGE_DOWN  | Page Down key| 
| KEYCODE_ESCAPE  | ESC key| 
| KEYCODE_FORWARD_DEL  | Forward Delete key| 
| KEYCODE_CTRL_LEFT  | Left Ctrl key| 
| KEYCODE_CTRL_RIGHT  | Right Ctrl key.| 
| KEYCODE_CAPS_LOCK  | Caps Lock key| 
| KEYCODE_SCROLL_LOCK  | Scroll Lock key| 
| KEYCODE_META_LEFT  | Left Meta key| 
| KEYCODE_META_RIGHT  | Right Meta key| 
| KEYCODE_FUNCTION  | Function key| 
| KEYCODE_SYSRQ  | System Request/Print Screen key| 
| KEYCODE_BREAK  | Break/Pause key| 
| KEYCODE_MOVE_HOME  | Move to Home key| 
| KEYCODE_MOVE_END  | Move to End key| 
| KEYCODE_INSERT  | Insert key| 
| KEYCODE_FORWARD  | Forward key| 
| KEYCODE_MEDIA_PLAY  | Play key| 
| KEYCODE_MEDIA_PAUSE  | Pause key| 
| KEYCODE_MEDIA_CLOSE  | Close key| 
| KEYCODE_MEDIA_EJECT  | Eject key| 
| KEYCODE_MEDIA_RECORD  | Record key| 
| KEYCODE_F1  | F1 key| 
| KEYCODE_F2  | F2 key| 
| KEYCODE_F3  | F3 key| 
| KEYCODE_F4  | F4 key| 
| KEYCODE_F5  | F5 key| 
| KEYCODE_F6  | F6 key| 
| KEYCODE_F7  | F7 key| 
| KEYCODE_F8  | F8 key| 
| KEYCODE_F9  | F9 key| 
| KEYCODE_F10  | F10 key| 
| KEYCODE_F11  | F11 key| 
| KEYCODE_F12  | F12 key| 
| KEYCODE_NUM_LOCK  | Number Lock key on numeric keypad| 
| KEYCODE_NUMPAD_0  | Key 0 on numeric keypad| 
| KEYCODE_NUMPAD_1  | Key 1 on numeric keypad| 
| KEYCODE_NUMPAD_2  | Key 2 on numeric keypad| 
| KEYCODE_NUMPAD_3  | Key 3 on numeric keypad| 
| KEYCODE_NUMPAD_4  | Key 4 on numeric keypad| 
| KEYCODE_NUMPAD_5  | Key 5 on numeric keypad| 
| KEYCODE_NUMPAD_6  | Key 6 on numeric keypad| 
| KEYCODE_NUMPAD_7  | Key 7 on numeric keypad| 
| KEYCODE_NUMPAD_8  | Key 8 on numeric keypad| 
| KEYCODE_NUMPAD_9  | Key 9 on numeric keypad| 
| KEYCODE_NUMPAD_DIVIDE  | Key / on numeric keypad| 
| KEYCODE_NUMPAD_MULTIPLY  | Key \* on numeric keypad| 
| KEYCODE_NUMPAD_SUBTRACT  | Key - on numeric keypad| 
| KEYCODE_NUMPAD_ADD  | Key + on numeric keypad| 
| KEYCODE_NUMPAD_DOT  | Key . on numeric keypad| 
| KEYCODE_NUMPAD_COMMA  | Key , on numeric keypad| 
| KEYCODE_NUMPAD_ENTER  | Enter key on numeric keypad| 
| KEYCODE_NUMPAD_EQUALS  | Key = on numeric keypad| 
| KEYCODE_NUMPAD_LEFT_PAREN  | Key ( on numeric keypad| 
| KEYCODE_NUMPAD_RIGHT_PAREN  | Key ) on numeric keypad| 
| KEYCODE_DAGGER_CLICK  | Dagger click key on the smart watch<br>**Since**: 18| 
| KEYCODE_DAGGER_DOUBLE_CLICK  | Dagger double-click key on the smart watch<br>**Since**: 18| 
| KEYCODE_DAGGER_LONG_PRESS  | Dagger long-press key on the smart watch<br>**Since**: 18| 


### Input_KeyEventAction

```
enum Input_KeyEventAction
```
**Description**

Provides the enum values of the key event type.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| KEY_ACTION_CANCEL  | Button action canceled.| 
| KEY_ACTION_DOWN  | Key pressed.| 
| KEY_ACTION_UP  | Key released.| 


### Input_KeyStateAction

```
enum Input_KeyStateAction
```
**Description**

Provides the enum values of the key status.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| KEY_DEFAULT  | Default state.| 
| KEY_PRESSED  | Key pressed.| 
| KEY_RELEASED  | Key released.| 
| KEY_SWITCH_ON  | Key switch enabled.| 
| KEY_SWITCH_OFF  | Key switch disabled.| 


### Input_MouseEventAction

```
enum Input_MouseEventAction
```
**Description**

Provides the enum values of mouse actions.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| MOUSE_ACTION_CANCEL  | Mouse action canceled.| 
| MOUSE_ACTION_MOVE  | Mouse pointer moved.| 
| MOUSE_ACTION_BUTTON_DOWN  | Mouse button pressed.| 
| MOUSE_ACTION_BUTTON_UP  | Mouse button released.| 
| MOUSE_ACTION_AXIS_BEGIN  | Mouse axis begun.| 
| MOUSE_ACTION_AXIS_UPDATE  | Mouse axis updated.| 
| MOUSE_ACTION_AXIS_END  | Mouse axis ended.| 


### Input_MouseEventButton

```
enum Input_MouseEventButton
```
**Description**

Provides the enum values of mouse buttons.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| MOUSE_BUTTON_NONE  | Invalid key| 
| MOUSE_BUTTON_LEFT  | Left mouse button| 
| MOUSE_BUTTON_MIDDLE  | Middle mouse button| 
| MOUSE_BUTTON_RIGHT  | Right mouse button| 
| MOUSE_BUTTON_FORWARD  | Mouse forward button| 
| MOUSE_BUTTON_BACK  | Mouse back button| 


### Input_Result

```
enum Input_Result
```
**Description**

Provides the enum values of error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| INPUT_SUCCESS  | Operation succeeded.| 
| INPUT_PERMISSION_DENIED  | Permission verification failed.| 
| INPUT_NOT_SYSTEM_APPLICATION  | Not a system application.| 
| INPUT_PARAMETER_ERROR  | Parameter check failed.| 
| INPUT_DEVICE_NOT_SUPPORTED | Input device not supported.<br>**Since**: API version 14|
| INPUT_SERVICE_EXCEPTION  | Service error.| 
| INPUT_REPEAT_INTERCEPTOR  | Interceptor repeatedly created.| 
| INPUT_OCCUPIED_BY_SYSTEM  | Occupied by a system application.<br>**Since**: API version 14| 
| INPUT_OCCUPIED_BY_OTHER  | Occupied by other applications.<br>**Since**: API version 14| 
| INPUT_KEYBOARD_DEVICE_NOT_EXIST | No keyboard connected.<br>**Since**: API version 15| 


### Input_TouchEventAction

```
enum Input_TouchEventAction
```
**Description**

Provides the enum values of touch actions.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| TOUCH_ACTION_CANCEL  | Cancellation of touch.| 
| TOUCH_ACTION_DOWN  | Pressing of touch.| 
| TOUCH_ACTION_MOVE  | Moving of touch.| 
| TOUCH_ACTION_UP  | Lifting of touch.| 


### InputEvent_AxisAction

```
enum InputEvent_AxisAction
```
**Description**

Action of the input device.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| AXIS_ACTION_CANCEL  | Cancellation of an axis input event.| 
| AXIS_ACTION_BEGIN  | Start of an axis input event.| 
| AXIS_ACTION_UPDATE  | Update of an axis input event.| 
| AXIS_ACTION_END  | End of an axis input event.| 


### InputEvent_AxisEventType

```
enum InputEvent_AxisEventType
```
**Description**

Event type of the input device.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| AXIS_EVENT_TYPE_PINCH  | Two-finger pinch event. The value can be **AXIS_TYPE_PINCH** or **AXIS_TYPE_ROTATE**.| 
| AXIS_EVENT_TYPE_SCROLL  | Scroll axis event. The value can be **AXIS_TYPE_SCROLL_VERTICAL** and **AXIS_TYPE_SCROLL_HORIZONTAL**. For mouse wheel events, the value can only be **AXIS_TYPE_SCROLL_VERTICAL**.| 


### InputEvent_AxisType

```
enum InputEvent_AxisType
```
**Description**

Defines the axis type of an input device.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| AXIS_TYPE_UNKNOWN  | Unknown axis type, which is usually used as the initial value.| 
| AXIS_TYPE_SCROLL_VERTICAL  | Vertical scroll axis. When you scroll the mouse wheel or slide with one or two fingers on the touchpad, the status of the vertical scroll axis changes.| 
| AXIS_TYPE_SCROLL_HORIZONTAL  | Horizontal scroll axis. When you scroll the mouse wheel or slide with two fingers on the touchpad, the status of the horizontal scroll axis changes.| 
| AXIS_TYPE_PINCH  | Pinch axis, which is used to describe a two-finger pinch gesture on the touchpad.| 
| AXIS_TYPE_ROTATE  | Rotation axis, which is used to describe a two-finger rotation gesture on the touchpad.| 


### InputEvent_MouseAxis

```
enum InputEvent_MouseAxis
```
**Description**

Provides the enum values of mouse axis event types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| MOUSE_AXIS_SCROLL_VERTICAL  | Vertical scroll axis.| 
| MOUSE_AXIS_SCROLL_HORIZONTAL  | Horizontal scroll axis.| 


### InputEvent_SourceType

```
enum InputEvent_SourceType
```
**Description**

Enter the event source type.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| SOURCE_TYPE_MOUSE  | Source that generates events similar to mouse cursor movement, button press and release, and wheel scrolling.| 
| SOURCE_TYPE_TOUCHSCREEN  | Source that generates a touchscreen multi-touch event.| 
| SOURCE_TYPE_TOUCHPAD  | Source that generates a touchpad multi-touch event.| 


## Function Description


### OH_Input_AddAxisEventMonitor()

```
Input_Result OH_Input_AddAxisEventMonitor (InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback )
```
**Description**

Adds a listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](#inputevent_axiseventtype).

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEventType | Type of the axis event. The event type is defined in [InputEvent_AxisEventType](#inputevent_axiseventtype). | 
| callback | Callback used to receive the specified type of axis events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PERMISSION_DENIED** if the permission verification fails; **INPUT_PARAMETER_ERROR** if the callback is empty; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_AddAxisEventMonitorForAll()

```
Input_Result OH_Input_AddAxisEventMonitorForAll (Input_AxisEventCallback callback)
```
**Description**

Adds a listener for all types of axis events, which are defined in [InputEvent_AxisEventType](#inputevent_axiseventtype).

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback used to receive axis events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PERMISSION_DENIED** if the permission verification fails; **INPUT_PARAMETER_ERROR** if the callback is empty; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_AddHotkeyMonitor()

```
Input_Result OH_Input_AddHotkeyMonitor (const Input_Hotkey * hotkey, Input_HotkeyCallback callback )
```
**Description**

Subscribes to shortcut key events. This API is not applicable to wearables and lite wearables.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 
| callback | Defines the callback used to return shortcut key events. | 

**Returns**

OH_Input_AddHotkeyMonitor status code, specifically,

**INPUT_SUCCESS** if the operation is successful;

INPUT_PARAMETER_ERROR if parameter check fails;

INPUT_OCCUPIED_BY_SYSTEM if the shortcut key has been occupied by the system (you can use [OH_Input_GetAllSystemHotkeys](#oh_input_getallsystemhotkeys) to query allsystem shortcut keys);

INPUT_OCCUPIED_BY_OTHER if the shortcut key has been occupied by another application. 

**INPUT_DEVICE_NOT_SUPPORTED** if the input device is not supported.

### OH_Input_AddInputEventInterceptor()

```
Input_Result OH_Input_AddInputEventInterceptor (Input_InterceptorEventCallback *callback, Input_InterceptorOptions * option)
```
**Description**

Adds an interceptor for input events, including mouse, touch, and axis events. If multiple interceptors are added, only the first one takes effect. An interception event is reported only when the application gains focus.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Pointer to the input event callback. For details, see [Input_InterceptorEventCallback](_input___interceptor_event_callback.md). | 
| option | Options for event interception. If **null** is passed, the default value is used. | 

**Required Permissions**

ohos.permission.INTERCEPT_INPUT_EVENT

**Returns**

**INTO_SUCCESS** if the operation is successful;

**INPUT_PERMISSION_DENIED** if the permission verification fails;

**INPUT_PARAMETER_ERROR** if the callback is empty;

**INPUT_REPEAT_INTERCEPTOR** if an interceptor is repeatedly added;
 
or **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_AddKeyEventInterceptor()

```
Input_Result OH_Input_AddKeyEventInterceptor (Input_KeyEventCallback callback, Input_InterceptorOptions * option )
```
**Description**

Adds an interceptor for key events. If multiple interceptors are added, only the first one takes effect. An interception event is reported only when the application gains focus.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback used to receive key events. | 
| option | Options for event interception. If **null** is passed, the default value is used. | 

**Required Permissions**

ohos.permission.INTERCEPT_INPUT_EVENT

**Returns**

**INTO_SUCCESS** if the operation is successful;

**INPUT_PERMISSION_DENIED** if the permission verification fails;

**INPUT_PARAMETER_ERROR** if the callback is empty;

**INPUT_REPEAT_INTERCEPTOR** if an interceptor is repeatedly added;

or **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_AddKeyEventMonitor()

```
Input_Result OH_Input_AddKeyEventMonitor (Input_KeyEventCallback callback)
```
**Description**

Adds a listener for key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback used to receive key events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful;

**INPUT_PERMISSION_DENIED** if the permission verification fails;

**INPUT_PARAMETER_ERROR** if the callback is empty;

or **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_AddMouseEventMonitor()

```
Input_Result OH_Input_AddMouseEventMonitor (Input_MouseEventCallback callback)
```
**Description**

Adds a listener for mouse events, including mouse click and movement events, but not scroll wheel events. Scroll wheel events are axis events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback used to receive mouse events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful;

**INPUT_PERMISSION_DENIED** if the permission verification fails;

**INPUT_PARAMETER_ERROR** if the callback is empty;

or **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_AddTouchEventMonitor()

```
Input_Result OH_Input_AddTouchEventMonitor (Input_TouchEventCallback callback)
```
**Description**

Adds a listener for touch events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback used to receive touch events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PERMISSION_DENIED** if the permission verification fails; **INPUT_PARAMETER_ERROR** if the callback is empty; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_CancelInjection()

```
void OH_Input_CancelInjection ()
```
**Description**

Stops event injection and revokes authorization.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


### OH_Input_CreateAllSystemHotkeys()

```
Input_Hotkey** OH_Input_CreateAllSystemHotkeys (int32_t count)
```
**Description**

Creates an array of [Input_Hotkey](#input_hotkey) instances.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| count | Number of [Input_Hotkey](#input_hotkey) instances to be created. | 

**Returns**

OH_Input_CreateAllSystemHotkey status code, which is **INPUT_SUCCESS** if a double pointer to the instance array is successfully created or an error code otherwise.


### OH_Input_CreateAxisEvent()

```
Input_AxisEvent* OH_Input_CreateAxisEvent ( void )
```
**Description**

Creates an axis event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

An [Input_AxisEvent](#input_axisevent) object if the operation is successful; **null** otherwise.


### OH_Input_CreateDeviceInfo()

```
Input_DeviceInfo* OH_Input_CreateDeviceInfo (void )
```
**Description**

Creates a **deviceInfo** object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Returns**

Pointer to an [Input_DeviceInfo](#input_deviceinfo) object if the operation is successful; a null pointer otherwise (possibly because of a memory allocation failure).


### OH_Input_CreateHotkey()

```
Input_Hotkey* OH_Input_CreateHotkey (void)
```
**Description**

Creates a shortcut key object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Returns**

An [Input_Hotkey](#input_hotkey) pointer object if the operation is successful; a null pointer otherwise (possibly because of a memory allocation failure).


### OH_Input_CreateKeyEvent()

```
struct Input_KeyEvent* OH_Input_CreateKeyEvent ()
```
**Description**

Creates a key event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

An [Input_KeyEvent](#input_keyevent) pointer object if the operation is successful; a null pointer otherwise.


### OH_Input_CreateKeyState()

```
struct Input_KeyState* OH_Input_CreateKeyState ()
```
**Description**

Creates a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

An [Input_KeyState](#input_keystate) pointer object if the operation is successful; a null pointer otherwise.


### OH_Input_CreateMouseEvent()

```
struct Input_MouseEvent* OH_Input_CreateMouseEvent ()
```
**Description**

Creates a mouse event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

An [Input_MouseEvent](#input_mouseevent) pointer object if the operation is successful; a null pointer otherwise.


### OH_Input_CreateTouchEvent()

```
struct Input_TouchEvent* OH_Input_CreateTouchEvent ()
```
**Description**

Creates a touch event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

An [Input_TouchEvent](#input_touchevent) pointer object if the operation is successful; a null pointer otherwise.


### OH_Input_DestroyAllSystemHotkeys()

```
void OH_Input_DestroyAllSystemHotkeys (Input_Hotkey ** hotkeys, int32_t count )
```
**Description**

Destroys the array of [Input_Hotkey](#input_hotkey) instances and reclaims the memory.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkeys | Double pointer to the array of [Input_Hotkey](#input_hotkey) instances. | 
| count | Number of [Input_Hotkey](#input_hotkey) instances to be destroyed. | 


### OH_Input_DestroyAxisEvent()

```
Input_Result OH_Input_DestroyAxisEvent (Input_AxisEvent ** axisEvent)
```
**Description**

Destroys an axis event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Pointer to the axis event object. | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **\*axisEvent** is **NULL**.


### OH_Input_DestroyDeviceInfo()

```
void OH_Input_DestroyDeviceInfo (Input_DeviceInfo ** deviceInfo)
```
**Description**

Destroys a **deviceInfo** object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceInfo | **deviceInfo** object. | 


### OH_Input_DestroyHotkey()

```
void OH_Input_DestroyHotkey (Input_Hotkey ** hotkey)
```
**Description**

Destroys a shortcut key object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 


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
| keyEvent | Key event object. | 


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
| keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).| 


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
| mouseEvent | Mouse event object. | 


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
| touchEvent | Touch event object. | 


### OH_Input_GetAllSystemHotkeys()

```
Input_Result OH_Input_GetAllSystemHotkeys (Input_Hotkey ** hotkey, int32_t * count )
```
**Description**

Obtains all configured shortcut keys.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | An array of [Input_Hotkey](#input_hotkey) instances. When calling this API for the first time, you can pass **NULL** to obtain the array length. | 
| count | Number of supported shortcut keys. | 

**Returns**

Status code of the **OH_Input_GetAllSystemHotkeys** function, which is

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** otherwise.


### OH_Input_GetAxisEventAction()

```
Input_Result OH_Input_GetAxisEventAction (const Input_AxisEvent * axisEvent, InputEvent_AxisAction * action )
```
**Description**

Obtains the action of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| action | Action of the axis event. For details, see [InputEvent_AxisAction](#inputevent_axisaction). | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **action** is **NULL**.

### OH_Input_GetAxisEventActionTime()

```
Input_Result OH_Input_GetAxisEventActionTime (const Input_AxisEvent * axisEvent, int64_t * actionTime )
```
**Description**

Obtains the time when an axis event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. For details, see [Input_AxisEvent](#input_axisevent). | 
| actionTime | Time when an axis event occurs. | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **actionTime** is **NULL**.


### OH_Input_GetAxisEventAxisValue()

```
Input_Result OH_Input_GetAxisEventAxisValue (const Input_AxisEvent * axisEvent, InputEvent_AxisType axisType, double * axisValue )
```
**Description**

Obtains the axis value for the specified axis type of the axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. For details, see [Input_AxisEvent](#input_axisevent). | 
| axisType | Axis type. For details, see [InputEvent_AxisType](#inputevent_axistype). | 
| axisValue | Axis value of the axis event. | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **axisValue** is **NULL**.


### OH_Input_GetAxisEventDisplayId()

```
Input_Result OH_Input_GetAxisEventDisplayId (const Input_AxisEvent * axisEvent, int32_t * displayId )
```
**Description**

Obtains the screen ID of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| displayId | Screen ID of the axis event. | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **displayId** is **NULL**.


### OH_Input_GetAxisEventDisplayX()

```
Input_Result OH_Input_GetAxisEventDisplayX (const Input_AxisEvent * axisEvent, float * displayX )
```
**Description**

Obtains the X coordinate of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| displayX | X coordinate of the axis event. | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **displayX** is **NULL**.


### OH_Input_GetAxisEventDisplayY()

```
Input_Result OH_Input_GetAxisEventDisplayY (const Input_AxisEvent * axisEvent, float * displayY )
```
**Description**

Obtains the Y coordinate of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. For details, see [Input_AxisEvent](#input_axisevent). | 
| displayY | Y coordinate of the axis event. | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **displayY** is **NULL**.


### OH_Input_GetAxisEventSourceType()

```
Input_Result OH_Input_GetAxisEventSourceType (const Input_AxisEvent * axisEvent, InputEvent_SourceType * sourceType )
```
**Description**

Obtains the axis event source type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| sourceType | Axis event source type. For details, see [InputEvent_SourceType](#inputevent_sourcetype). | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **sourceType** is **NULL**.


### OH_Input_GetAxisEventType()

```
Input_Result OH_Input_GetAxisEventType (const Input_AxisEvent * axisEvent, InputEvent_AxisEventType * axisEventType )
```
**Description**

Obtains the axis event type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| axisEventType | Axis event type. For details, see [InputEvent_AxisEventType](#inputevent_axiseventtype). | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **axisEventType** is **NULL**.


### OH_Input_GetAxisEventWindowId()

```
Input_Result OH_Input_GetAxisEventWindowId (const Input_AxisEvent * axisEvent, int32_t * windowId )
```
**Description**

Obtains the window ID of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| windowId | Window ID of the axis event. | 

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** or **windowId** is **NULL**.


### OH_Input_GetCapabilities()

```
Input_Result OH_Input_GetCapabilities (Input_DeviceInfo * deviceInfo, int32_t * capabilities )
```
**Description**

Obtains the capabilities of an input device, for example, a touchscreen, touchpad, or keyboard.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceInfo | [Input_DeviceInfo](#input_deviceinfo) object. | 
| capabilities | Pointer to the capability information of the input device. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **deviceInfo** or **capabilities** is a null pointer.


### OH_Input_GetDevice()

```
Input_Result OH_Input_GetDevice (int32_t deviceId, Input_DeviceInfo ** deviceInfo )
```
**Description**

Obtains information about the input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | Device ID. | 
| deviceInfo | Pointer to the [Input_DeviceInfo](#input_deviceinfo) object. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful;

**INPUT_PARAMETER_ERROR** if **deviceInfo** is a null pointer or **deviceId** is invalid. You can use [OH_Input_GetDeviceIds](#oh_input_getdeviceids) to query the device IDs supported by the system.


### OH_Input_GetDeviceAddress()

```
Input_Result OH_Input_GetDeviceAddress (Input_DeviceInfo * deviceInfo, char ** address )
```
**Description**

Obtains the physical address of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceInfo | [Input_DeviceInfo](#input_deviceinfo) object. | 
| address | Pointer to the physical address of the input device. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **deviceInfo** or **address** is a null pointer.


### OH_Input_GetDeviceId()

```
Input_Result OH_Input_GetDeviceId (Input_DeviceInfo * deviceInfo, int32_t * id )
```
**Description**

Obtains the ID of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceInfo | Input device information. For details, see [Input_DeviceInfo](#input_deviceinfo). | 
| id | Pointer to the input device ID. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **deviceInfo** or **id** is a null pointer.


### OH_Input_GetDeviceIds()

```
Input_Result OH_Input_GetDeviceIds (int32_t * deviceIds, int32_t inSize, int32_t * outSize )
```
**Description**

Obtains the IDs of all input devices.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceIds | List of input device IDs. | 
| inSize | Size of the input device ID list. | 
| outSize | Length of the input device ID list. The value must be less than or equal to the value of **inSize**. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **deviceIds** or **outSize** is a null pointer or **inSize** is less than **0**.


### OH_Input_GetDeviceName()

```
Input_Result OH_Input_GetDeviceName (Input_DeviceInfo * deviceInfo, char ** name )
```
**Description**

Obtains the name of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceInfo | Input device information. For details, see [Input_DeviceInfo](#input_deviceinfo). | 
| name | Pointer to the input device name. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **deviceInfo** or **name** is a null pointer.


### OH_Input_GetDeviceProduct()

```
Input_Result OH_Input_GetDeviceProduct (Input_DeviceInfo * deviceInfo, int32_t * product )
```
**Description**

Obtains the product information of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceInfo | Input device information. For details, see [Input_DeviceInfo](#input_deviceinfo). | 
| product | Pointer to the product information of the input device. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **deviceInfo** or **product** is a null pointer.


### OH_Input_GetDeviceVendor()

```
Input_Result OH_Input_GetDeviceVendor (Input_DeviceInfo * deviceInfo, int32_t * vendor )
```
**Description**

Obtains the vendor information of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceInfo | Input device information. For details, see [Input_DeviceInfo](#input_deviceinfo). | 
| vendor | Pointer to the vendor information of the input device. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **deviceInfo** or **vendor** is a null pointer.


### OH_Input_GetDeviceVersion()

```
Input_Result OH_Input_GetDeviceVersion (Input_DeviceInfo * deviceInfo, int32_t * version )
```
**Description**

Obtains the version information of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceInfo | Input device information. For details, see [Input_DeviceInfo](#input_deviceinfo). | 
| version | Pointer to the version information of the input device. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **deviceInfo** or **version** is a null pointer.


### OH_Input_GetFinalKey()

```
Input_Result OH_Input_GetFinalKey (const Input_Hotkey * hotkey, int32_t * finalKeyCode )
```
**Description**

Obtains the modified key.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 
| finalKeyCode | Modified key. | 

**Returns**

Status code of the **OH_Input_GetfinalKey** function, which is **INPUT_SUCCESS** if the operation is successful or

**INPUT_PARAMETER_ERROR** otherwise.


### OH_Input_GetFunctionKeyState()

```
Input_Result OH_Input_GetFunctionKeyState (int32_t keyCode, int32_t * state )
```
**Description**

Obtains the function key status.

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyCode | Function key. Only the **CapsLock** key is supported. | 
| state | Function key status. The value **0** indicates that the function key is disabled, and the value **1** indicates that the function key is enabled. | 

**Returns**

**OH_Input_GetFunctionKeyState** status code, specifically:
**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if the parameter is incorrect; **INPUT_DEVICE_NOT_EXIST** if the keyboard does not exist.


### OH_Input_GetIntervalSinceLastInput()

```
Input_Result OH_Input_GetIntervalSinceLastInput (int64_t * timeInterval)
```
**Description**

Obtains the interval since the last system input event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| timeInterval | Interval, in microseconds. | 

**Returns**

Status code of the **OH_Input_GetIntervalSinceLastInput** function,

which is **INPUT_SUCCESS** if the operation is successful; **INPUT_SERVICE_EXCEPTION** otherwise.


### OH_Input_GetKeyboardType()

```
Input_Result OH_Input_GetKeyboardType (int32_t deviceId, int32_t * keyboardType )
```
**Description**

Obtains the keyboard type of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| deviceId | Device ID. | 
| keyboardType | Pointer to the keyboard type of the input device. | 

**Returns**

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if the device ID is invalid or **keyboardType** is a null pointer.


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
| keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).| 

**Returns**

Key value of the key status enum object.


### OH_Input_GetKeyEventAction()

```
int32_t OH_Input_GetKeyEventAction (const struct Input_KeyEvent * keyEvent)
```
**Description**

Obtains the key event action.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object.| 

**Returns**

Key event action.


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
| keyEvent | Key event object. | 

**Returns**

Time when a key event occurs.


### OH_Input_GetKeyEventDisplayId()

```
int32_t OH_Input_GetKeyEventDisplayId (const struct Input_KeyEvent * keyEvent)
```
**Description**

Obtains the screen ID of a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object. | 

**Returns**

Screen ID of the key event.


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
| keyEvent | Key event object. | 

**Returns**

Key code.


### OH_Input_GetKeyEventWindowId()

```
int32_t OH_Input_GetKeyEventWindowId (const struct Input_KeyEvent * keyEvent)
```
**Description**

Obtains the window ID of a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object. | 

**Returns**

Window ID of the key event.


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
| keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).| 

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
| keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).| 

**Returns**

**Input_Result#INPUT_SUCCESS** if the operation is successful; an error code defined in [Input_Result](#input_result) otherwise.


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
| keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).| 

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
| mouseEvent | Mouse event object. | 

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
| keyEvent | Mouse event object. | 

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
| mouseEvent | Mouse event object. | 

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
| mouseEvent | Mouse event object. | 

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
| mouseEvent | Mouse event object. | 

**Returns**

Enumerates mouse buttons.


### OH_Input_GetMouseEventDisplayId()

```
int32_t OH_Input_GetMouseEventDisplayId (const struct Input_MouseEvent * mouseEvent)
```
**Description**

Obtains the screen ID of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object. | 

**Returns**

Screen ID of the mouse event.


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
| mouseEvent | Mouse event object. | 

**Returns**

X coordinate on the screen.


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
| mouseEvent | Mouse event object. | 

**Returns**

Y coordinate on the screen.


### OH_Input_GetMouseEventWindowId()

```
int32_t OH_Input_GetMouseEventWindowId (const struct Input_MouseEvent * mouseEvent)
```
**Description**

Obtains the window ID of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object. | 

**Returns**

Window ID of the mouse event.


### OH_Input_GetPreKeys()

```
Input_Result OH_Input_GetPreKeys (const Input_Hotkey * hotkey, int32_t ** preKeys, int32_t * preKeyCount )
```
**Description**

Obtains the modifier key.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 
| preKeys | List of modifier keys. | 
| preKeyCount | Number of modifier keys. | 

**Returns**

Status code of the **OH_Input_GetpressedKeys** function, which is **INPUT_SUCCESS** if the operation is successful or

**INPUT_PARAMETER_ERROR** otherwise.

### OH_Input_GetRepeat()

```
Input_Result OH_Input_GetRepeat (const Input_Hotkey * hotkey, bool * isRepeat )
```
**Description**

Checks whether to report repeated key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 
| isRepeat | Whether the reported key events is repeated. | 

**Returns**

OH_Input_GetIsRepeat status code, specifically, **INPUT_SUCCESS** if the operation is successful or

**INPUT_PARAMETER_ERROR** otherwise.

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
| touchEvent | Touch event object. | 

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
| keyEvent | Touch event object. | 

**Returns**

Time when the touch event occurs.


### OH_Input_GetTouchEventDisplayId()

```
int32_t OH_Input_GetTouchEventDisplayId (const struct Input_TouchEvent * touchEvent)
```
**Description**

Obtains the screen ID of a touchscreen event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object. | 

**Returns**

Screen ID of the touchscreen event.


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
| touchEvent | Touch event object. | 

**Returns**

X coordinate on the touchscreen.


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
| touchEvent | Touch event object. | 

**Returns**

Y coordinate on the touchscreen.


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
| touchEvent | Touch event object. | 

**Returns**

Finger ID of a touch event.


### OH_Input_GetTouchEventWindowId()

```
int32_t OH_Input_GetTouchEventWindowId (const struct Input_TouchEvent * touchEvent)
```
**Description**

Obtains the window ID of a touchscreen event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object. | 

**Returns**

Window ID of the touchscreen event.


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
| keyEvent | Defines the key event to be injected. | 

**Returns**

**0** if the operation is successful; **201** if the required permission is missing; **401** if the parameter is invalid.


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
| mouseEvent |  Defines the mouse event to be injected. | 

**Returns**

**0** if the operation is successful; **201** if the required permission is missing; **401** if the parameter is invalid.


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
| touchEvent | Defines the touch event to be injected. | 

**Returns**

**0** if the operation is successful; **201** if the required permission is missing; **401** if the parameter is invalid.

### OH_Input_RegisterDeviceListener()

```
Input_Result OH_Input_RegisterDeviceListener (Input_DeviceListener * listener)
```
**Description**

Registers a listener for device hot swap events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| listener | Pointer to the [Input_DeviceListener](_input___device_listener.md) object. | 

**Returns**

**OH_Input_RegisterDeviceListener** status code, specifically:

**INPUT_SUCCESS** if the operation is successful; **INPUT_PARAMETER_ERROR** if **listener** is **NULL**.

### OH_Input_RemoveAxisEventMonitor()

```
Input_Result OH_Input_RemoveAxisEventMonitor (InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback )
```
**Description**

Removes the listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](#inputevent_axiseventtype).

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEventType | Axis event type, which is defined in [InputEvent_AxisEventType](#inputevent_axiseventtype). | 
| callback | Callback for the specified type of axis events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PERMISSION_DENIED** if the permission verification fails; **INPUT_PARAMETER_ERROR** if the callback is empty or no listener is added; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_RemoveAxisEventMonitorForAll()

```
Input_Result OH_Input_RemoveAxisEventMonitorForAll (Input_AxisEventCallback callback)
```
**Description**

Removes the listener for all types of axis events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback for the all types of axis events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PERMISSION_DENIED** if the permission verification fails; **INPUT_PARAMETER_ERROR** if the callback is empty or no listener is added; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_RemoveHotkeyMonitor()

```
Input_Result OH_Input_RemoveHotkeyMonitor (const Input_Hotkey * hotkey, Input_HotkeyCallback callback )
```
**Description**

Unsubscribes from shortcut key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 
| callback | Defines the callback used to return shortcut key events. | 

**Returns**

OH_Input_RemoveHotkeyMonitor status code, specifically, **INPUT_SUCCESS** if the operation is successful or

**INPUT_PARAMETER_ERROR** if parameter check fails.


### OH_Input_RemoveInputEventInterceptor()

```
Input_Result OH_Input_RemoveInputEventInterceptor (void)
```
**Description**

Removes the interceptor for input events, including mouse, touch, and axis events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Required Permissions**

ohos.permission.INTERCEPT_INPUT_EVENT

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PERMISSION_DENIED** if permission verification fails; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_RemoveKeyEventInterceptor()

```
Input_Result OH_Input_RemoveKeyEventInterceptor (void)
```
**Description**

Removes the interceptor for key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Required Permissions**

ohos.permission.INTERCEPT_INPUT_EVENT

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PERMISSION_DENIED** if permission verification fails; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_RemoveKeyEventMonitor()

```
Input_Result OH_Input_RemoveKeyEventMonitor (Input_KeyEventCallback callback)
```
**Description**

Removes the listener for key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback for key events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PERMISSION_DENIED** if the permission verification fails; **INPUT_PARAMETER_ERROR** if the callback is empty or no listener is added; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_RemoveMouseEventMonitor()

```
Input_Result OH_Input_RemoveMouseEventMonitor (Input_MouseEventCallback callback)
```
**Description**

Removes the listener for mouse events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback for mouse events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PERMISSION_DENIED** if the permission verification fails; **INPUT_PARAMETER_ERROR** if the callback is empty or no listener is added; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_RemoveTouchEventMonitor()

```
Input_Result OH_Input_RemoveTouchEventMonitor (Input_TouchEventCallback callback)
```
**Description**

Removes the listener for touch events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| callback | Callback for touch events. | 

**Required Permissions**

ohos.permission.INPUT_MONITORING

**Returns**

**INTO_SUCCESS** if the operation is successful; **INPUT_PERMISSION_DENIED** if the permission verification fails; **INPUT_PARAMETER_ERROR** if the callback is empty or no listener is added; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_SetAxisEventAction()

```
Input_Result OH_Input_SetAxisEventAction (Input_AxisEvent * axisEvent, InputEvent_AxisAction action )
```
**Description**

Sets the action for an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| action | Action of the axis event. For details, see [InputEvent_AxisAction](#inputevent_axisaction). | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.

### OH_Input_SetAxisEventActionTime()

```
Input_Result OH_Input_SetAxisEventActionTime (Input_AxisEvent * axisEvent, int64_t actionTime )
```
**Description**

Sets the time when an axis event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. For details, see [Input_AxisEvent](#input_axisevent). | 
| actionTime | Time when an event occurs. | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.


### OH_Input_SetAxisEventAxisValue()

```
Input_Result OH_Input_SetAxisEventAxisValue (Input_AxisEvent * axisEvent, InputEvent_AxisType axisType, double axisValue )
```
**Description**

Sets the axis value of the axis type specified by the axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. For details, see [Input_AxisEvent](#input_axisevent). | 
| axisType | Axis type. For details, see [InputEvent_AxisType](#inputevent_axistype). | 
| axisValue | Axis event axis value. | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.


### OH_Input_SetAxisEventDisplayId()

```
Input_Result OH_Input_SetAxisEventDisplayId (Input_AxisEvent * axisEvent, int32_t displayId )
```
**Description**

Sets the screen ID of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| displayId | Screen ID of the axis event. | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.


### OH_Input_SetAxisEventDisplayX()

```
Input_Result OH_Input_SetAxisEventDisplayX (Input_AxisEvent * axisEvent, float displayX )
```
**Description**

Sets the X coordinate for an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| displayX | X coordinate of the axis event. | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.


### OH_Input_SetAxisEventDisplayY()

```
Input_Result OH_Input_SetAxisEventDisplayY (Input_AxisEvent * axisEvent, float displayY )
```
**Description**

Sets the Y coordinate for an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. For details, see [Input_AxisEvent](#input_axisevent). | 
| displayY | Y coordinate of the axis event. | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.


### OH_Input_SetAxisEventSourceType()

```
Input_Result OH_Input_SetAxisEventSourceType (Input_AxisEvent * axisEvent, InputEvent_SourceType sourceType )
```
**Description**

Sets the axis event source type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| sourceType | Axis event source type. For details, see [InputEvent_SourceType](#inputevent_sourcetype). | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.


### OH_Input_SetAxisEventType()

```
Input_Result OH_Input_SetAxisEventType (Input_AxisEvent * axisEvent, InputEvent_AxisEventType axisEventType )
```
**Description**

Sets the axis event type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. For details, see [Input_AxisEvent](#input_axisevent). | 
| axisEventType | Axis event type. For details, see [InputEvent_AxisEventType](#inputevent_axiseventtype). | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.


### OH_Input_SetAxisEventWindowId()

```
Input_Result OH_Input_SetAxisEventWindowId (Input_AxisEvent * axisEvent, int32_t windowId )
```
**Description**

Sets the window ID of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| axisEvent | Axis event object. | 
| windowId | Window ID of the axis event. | 

**Returns**

**INTO_SUCCESS** if operation is successful; **INPUT_PARAMETER_ERROR** if **axisEvent** is NULL.


### OH_Input_SetFinalKey()

```
void OH_Input_SetFinalKey (Input_Hotkey * hotkey, int32_t finalKey )
```
**Description**

Sets the modified key.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 
| finalKey | Modifier key value. Only one modifier key value is allowed. | 


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
| keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).| 
| keyCode | Key code. | 


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
| keyEvent | Key event object. | 
| action | Key event type.| 


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
| actionTime | Time when a key event occurs. | 


### OH_Input_SetKeyEventDisplayId()

```
void OH_Input_SetKeyEventDisplayId (struct Input_KeyEvent * keyEvent, int32_t displayId )
```
**Description**

Sets the screen ID of a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object. | 
| displayId | Screen ID of the key event. | 


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
| keyEvent | Key event object. | 
| keyCode | Key value. | 


### OH_Input_SetKeyEventWindowId()

```
void OH_Input_SetKeyEventWindowId (struct Input_KeyEvent * keyEvent, int32_t windowId )
```
**Description**

Sets the window ID of a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Key event object. | 
| windowId | Window ID of the key event. | 


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
| keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).| 
| keyAction | Whether a key is pressed. For details, see [Input_KeyEventAction](#input_keyeventaction).| 


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
| keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).| 
| keySwitch | Key switch. | 


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
| mouseEvent | Mouse event object. | 
| action | Mouse action. | 


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
| mouseEvent | Mouse event object. | 
| actionTime | Time when a mouse event occurs. | 


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
| axisType | Axis type, for example, X axis or Y axis. | 


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
| mouseEvent | Mouse event object. | 
| axisValue | Axis value. A positive value means scrolling forward, and a negative number means scrolling backward. | 


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
| mouseEvent | Mouse event object. | 
| button | Enumerates mouse buttons. | 


### OH_Input_SetMouseEventDisplayId()

```
void OH_Input_SetMouseEventDisplayId (struct Input_MouseEvent * mouseEvent, int32_t displayId )
```
**Description**

Sets the screen ID of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object. | 
| displayId | Screen ID of the mouse event. | 


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
| mouseEvent | Mouse event object. | 
| displayX | X coordinate on the screen. | 


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
| mouseEvent | Mouse event object. | 
| displayY | Y coordinate on the screen. | 


### OH_Input_SetMouseEventWindowId()

```
void OH_Input_SetMouseEventWindowId (struct Input_MouseEvent * mouseEvent, int32_t windowId )
```
**Description**

Sets the window ID of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| mouseEvent | Mouse event object. | 
| windowId | Window ID of the mouse event. | 


### OH_Input_SetPreKeys()

```
void OH_Input_SetPreKeys (Input_Hotkey * hotkey, int32_t * preKeys, int32_t size )
```
**Description**

Sets the modifier keys.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 
| preKeys | List of modifier keys. | 
| size | Number of modifier keys. One or two modifier keys are supported. | 


### OH_Input_SetRepeat()

```
void OH_Input_SetRepeat (Input_Hotkey * hotkey, bool isRepeat )
```
**Description**

Specifies whether to report repeated key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| hotkey | Shortcut key object. | 
| isRepeat | Whether to report repeated key events. The value **true** means to report repeated key events, and the value **false** means the opposite. | 


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
| touchEvent | Touch event object. | 
|  action| Action of the touch event.| 


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
| actionTime | Time when a touch event occurs. | 


### OH_Input_SetTouchEventDisplayId()

```
void OH_Input_SetTouchEventDisplayId (struct Input_TouchEvent * touchEvent, int32_t displayId )
```
**Description**

Sets the screen ID of a touchscreen event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object. | 
| displayId | Screen ID of the touchscreen event. | 


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
| touchEvent | Touch event object. | 
|   displayX| X coordinate on the touchscreen.|


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
| touchEvent | Touch event object. | 
|  displayY | Y coordinate on the touchscreen.|


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


### OH_Input_SetTouchEventWindowId()

```
void OH_Input_SetTouchEventWindowId (struct Input_TouchEvent * touchEvent, int32_t windowId )
```
**Description**

Sets the window ID of a touchscreen event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| touchEvent | Touch event object. | 
| windowId | Window ID of the touchscreen event. | 


### OH_Input_UnregisterDeviceListener()

```
Input_Result OH_Input_UnregisterDeviceListener (Input_DeviceListener * listener)
```
**Description**

Unregisters the listener for device hot swap events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| listener | Pointer to the [Input_DeviceListener](_input___device_listener.md) object. | 

**Returns**

**OH_Input_UnregisterDeviceListener** status code, specifically:

**INPUT_SUCCESS** if the operation is successful;

**INPUT_PARAMETER_ERROR** if **listener** is **NULL** or the listener is not registered;

**INPUT_SERVICE_EXCEPTION** if the service is abnormal.


### OH_Input_UnregisterDeviceListeners()

```
Input_Result OH_Input_UnregisterDeviceListeners ()
```
**Description**

Unregisters the listener for all device hot swap events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Returns**

**OH_Input_UnregisterDeviceListener** status code, specifically:

**INPUT_SUCCESS** if the operation is successful; **INPUT_SERVICE_EXCEPTION** if the service is abnormal.

### OH_Input_GetFunctionKeyState()

```
Input_Result OH_Input_GetFunctionKeyState(int32_t keyCode, int32_t *state)
```
**Description**

Obtains the function key status.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyCode | Function key. Only the **CapsLock** key is supported. |
| state | Function key status. The value **0** indicates that the function key is disabled, and the value **1** indicates that the function key is enabled. | 

**Returns**

**OH_Input_GetFunctionKeyState** status code, specifically:

 **INPUT_SUCCESS** if the operation is successful;

 **INPUT_PARAMETER_ERROR** if the parameter is incorrect;

 **INPUT_DEVICE_NOT_EXIST** if the keyboard does not exist.
