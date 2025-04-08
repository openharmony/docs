# oh_input_manager.h


## Overview

Provides functions such as event injection and status query.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Library**: libohinput.so

**Since**: 12

**Related module**: [Input](input.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[Input_InterceptorEventCallback](_input___interceptor_event_callback.md) | Defines the structure of the interceptor for callback events, including mouse events, touch events, and axis events. | 
| struct&nbsp;&nbsp;[Input_DeviceListener](_input___device_listener.md) | Defines a listener for device hot swap events. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Input_KeyStateAction](input.md#input_keystateaction) [Input_KeyStateAction](input.md#input_keystateaction) | Provides the enum values of the key status. | 
| typedef enum [Input_KeyEventAction](input.md#input_keyeventaction) [Input_KeyEventAction](input.md#input_keyeventaction) | Provides the enum values of the key event type. | 
| typedef enum [Input_MouseEventAction](input.md#input_mouseeventaction) [Input_MouseEventAction](input.md#input_mouseeventaction) | Provides the enum values of mouse actions. | 
| typedef enum [InputEvent_MouseAxis](input.md#inputevent_mouseaxis) [InputEvent_MouseAxis](input.md#inputevent_mouseaxis) | Provides the enum values of mouse axis event types. | 
| typedef enum [Input_MouseEventButton](input.md#input_mouseeventbutton) [Input_MouseEventButton](input.md#input_mouseeventbutton) | Provides the enum values of mouse buttons. | 
| typedef enum [Input_TouchEventAction](input.md#input_toucheventaction) [Input_TouchEventAction](input.md#input_toucheventaction) | Provides the enum values of touch actions. | 
| typedef enum [InputEvent_SourceType](input.md#inputevent_sourcetype) [InputEvent_SourceType](input.md#inputevent_sourcetype) | Provides the enum values of event source types. | 
| typedef enum [Input_KeyboardType](input.md#input_keyboardtype) [Input_KeyboardType](input.md#input_keyboardtype) | Provides the enum values of keyboard types of the input device. | 
| typedef struct [Input_KeyState](input.md#input_keystate) [Input_KeyState](input.md#input_keystate) | Defines key information, which identifies a key pressing behavior. For example, the Ctrl key information contains the key value and key type. | 
| typedef struct [Input_KeyEvent](input.md#input_keyevent) [Input_KeyEvent](input.md#input_keyevent) | Defines the key event to be injected. | 
| typedef struct [Input_MouseEvent](input.md#input_mouseevent) [Input_MouseEvent](input.md#input_mouseevent) | Defines the mouse event to be injected. | 
| typedef struct [Input_TouchEvent](input.md#input_touchevent) [Input_TouchEvent](input.md#input_touchevent) | Defines the touch event to be injected. | 
| typedef struct [Input_AxisEvent](input.md#input_axisevent) [Input_AxisEvent](input.md#input_axisevent) | Defines an axis event. | 
| typedef enum [Input_Result](input.md#input_result) [Input_Result](input.md#input_result) | Provides the enum values of error codes. | 
| typedef void(\* [Input_KeyEventCallback](input.md#input_keyeventcallback)) (const [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | Defines a lifecycle callback for **keyEvent**. If the callback is triggered, **keyEvent** will be destroyed. | 
| typedef void(\* [Input_MouseEventCallback](input.md#input_mouseeventcallback)) (const [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Defines a lifecycle callback for **mouseEvent**. If the callback is triggered, **mouseEvent** will be destroyed. | 
| typedef void(\* [Input_TouchEventCallback](input.md#input_toucheventcallback)) (const [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Defines a lifecycle callback for **touchEvent**. If the callback is triggered, **touchEvent** will be destroyed. | 
| typedef void(\* [Input_AxisEventCallback](input.md#input_axiseventcallback)) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent) | Defines a lifecycle callback for **axisEvent**. If the callback is triggered, **axisEvent** will be destroyed. | 
| typedef void(\* [Input_HotkeyCallback](input.md#input_hotkeycallback)) ([Input_Hotkey](input.md#input_hotkey) \*hotkey) | Defines the callback used to return shortcut key events. |
| typedef void(\* [Input_DeviceAddedCallback](input.md#input_deviceaddedcallback)) (int32_t deviceId) | Defines a callback used to receive device insertion events. | 
| typedef void(\* [Input_DeviceRemovedCallback](input.md#input_deviceremovedcallback)) (int32_t deviceId) | Defines a callback used to receive device removal events. | 
| typedef struct [Input_InterceptorEventCallback](_input___interceptor_event_callback.md) [Input_InterceptorEventCallback](input.md#input_interceptoreventcallback) | Defines the structure of the interceptor for callback events, including mouse events, touch events, and axis events. | 
| typedef struct [Input_DeviceListener](_input___device_listener.md) [Input_DeviceListener](input.md#input_devicelistener) | Defines a listener for device hot swap events. | 
| typedef struct [Input_InterceptorOptions](input.md#input_interceptoroptions) [Input_InterceptorOptions](input.md#input_interceptoroptions) | Defines event interception options. | 
| typedef struct [Input_Hotkey](input.md#input_hotkey) [Input_Hotkey](input.md#input_hotkey) | Defines the shortcut key structure. | 
| typedef struct [Input_DeviceInfo](input.md#input_deviceinfo) [Input_DeviceInfo](input.md#input_deviceinfo) | Defines the input device information. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [Input_KeyStateAction](input.md#input_keystateaction) {<br>KEY_DEFAULT = -1, KEY_PRESSED = 0, KEY_RELEASED = 1, KEY_SWITCH_ON = 2,<br>KEY_SWITCH_OFF = 3<br>} | Provides the enum values of the key status. | 
| [Input_KeyEventAction](input.md#input_keyeventaction) { KEY_ACTION_CANCEL = 0, KEY_ACTION_DOWN = 1, KEY_ACTION_UP = 2 } | Provides the enum values of the key event type. | 
| [Input_MouseEventAction](input.md#input_mouseeventaction) {<br>MOUSE_ACTION_CANCEL = 0, MOUSE_ACTION_MOVE = 1, MOUSE_ACTION_BUTTON_DOWN = 2, MOUSE_ACTION_BUTTON_UP = 3,<br>MOUSE_ACTION_AXIS_BEGIN = 4, MOUSE_ACTION_AXIS_UPDATE = 5, MOUSE_ACTION_AXIS_END = 6<br>} | Provides the enum values of mouse actions. | 
| [InputEvent_MouseAxis](input.md#inputevent_mouseaxis) { MOUSE_AXIS_SCROLL_VERTICAL = 0, MOUSE_AXIS_SCROLL_HORIZONTAL = 1 } | Provides the enum values of mouse axis event types. | 
| [Input_MouseEventButton](input.md#input_mouseeventbutton) {<br>MOUSE_BUTTON_NONE = -1, MOUSE_BUTTON_LEFT = 0, MOUSE_BUTTON_MIDDLE = 1, MOUSE_BUTTON_RIGHT = 2,<br>MOUSE_BUTTON_FORWARD = 3, MOUSE_BUTTON_BACK = 4<br>} | Provides the enum values of mouse buttons. | 
| [Input_TouchEventAction](input.md#input_toucheventaction) { TOUCH_ACTION_CANCEL = 0, TOUCH_ACTION_DOWN = 1, TOUCH_ACTION_MOVE = 2, TOUCH_ACTION_UP = 3 } | Provides the enum values of touch actions. | 
| [InputEvent_SourceType](input.md#inputevent_sourcetype) { SOURCE_TYPE_MOUSE = 1, SOURCE_TYPE_TOUCHSCREEN = 2, SOURCE_TYPE_TOUCHPAD = 3 } | Provides the enum values of event source types. | 
| [Input_KeyboardType](input.md#input_keyboardtype) {<br>KEYBOARD_TYPE_NONE = 0, KEYBOARD_TYPE_UNKNOWN = 1, KEYBOARD_TYPE_ALPHABETIC = 2, KEYBOARD_TYPE_DIGITAL = 3,<br>KEYBOARD_TYPE_STYLUS = 4, KEYBOARD_TYPE_REMOTE_CONTROL = 5<br>} | Provides the enum values of keyboard types of the input device. | 
| [Input_Result](input.md#input_result) {<br>INPUT_SUCCESS = 0, INPUT_PERMISSION_DENIED = 201, INPUT_NOT_SYSTEM_APPLICATION = 202, INPUT_PARAMETER_ERROR = 401, INPUT_DEVICE_NOT_SUPPORTED = 801, INPUT_SERVICE_EXCEPTION = 3800001, INPUT_KEYBOARD_DEVICE_NOT_EXIST = 3900002, INPUT_REPEAT_INTERCEPTOR = 4200001, INPUT_OCCUPIED_BY_SYSTEM = 4200002, INPUT_OCCUPIED_BY_OTHER = 4200003<br>} | Provides the enum values of error codes. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Input_Result](input.md#input_result) [OH_Input_GetKeyState](input.md#oh_input_getkeystate) (struct [Input_KeyState](input.md#input_keystate) \*keyState) | Queries an enum object of the key status. | 
| struct [Input_KeyState](input.md#input_keystate) \* [OH_Input_CreateKeyState](input.md#oh_input_createkeystate) () | Creates an enum object of the key status. | 
| void [OH_Input_DestroyKeyState](input.md#oh_input_destroykeystate) (struct [Input_KeyState](input.md#input_keystate) \*\*keyState) | Destroys an enum object of the key status. | 
| void [OH_Input_SetKeyCode](input.md#oh_input_setkeycode) (struct [Input_KeyState](input.md#input_keystate) \*keyState, int32_t keyCode) | Sets the key value of a key status enum object. | 
| int32_t [OH_Input_GetKeyCode](input.md#oh_input_getkeycode) (const struct [Input_KeyState](input.md#input_keystate) \*keyState) | Obtains the key value of a key status enum object. | 
| void [OH_Input_SetKeyPressed](input.md#oh_input_setkeypressed) (struct [Input_KeyState](input.md#input_keystate) \*keyState, int32_t keyAction) | Sets whether the key specific to a key status enum object is pressed. | 
| int32_t [OH_Input_GetKeyPressed](input.md#oh_input_getkeypressed) (const struct [Input_KeyState](input.md#input_keystate) \*keyState) | Checks whether the key specific to a key status enum object is pressed. | 
| void [OH_Input_SetKeySwitch](input.md#oh_input_setkeyswitch) (struct [Input_KeyState](input.md#input_keystate) \*keyState, int32_t keySwitch) | Sets the key switch of the key status enum object. | 
| int32_t [OH_Input_GetKeySwitch](input.md#oh_input_getkeyswitch) (const struct [Input_KeyState](input.md#input_keystate) \*keyState) | Obtains the key switch of the key status enum object. | 
| int32_t [OH_Input_InjectKeyEvent](input.md#oh_input_injectkeyevent) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | Injects a key event. | 
| struct [Input_KeyEvent](input.md#input_keyevent) \* [OH_Input_CreateKeyEvent](input.md#oh_input_createkeyevent) () | Creates a key event object. | 
| void [OH_Input_DestroyKeyEvent](input.md#oh_input_destroykeyevent) (struct [Input_KeyEvent](input.md#input_keyevent) \*\*keyEvent) | Destroys a key event object. | 
| void [OH_Input_SetKeyEventAction](input.md#oh_input_setkeyeventaction) (struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent, int32_t action) | Sets the key event type. | 
| int32_t [OH_Input_GetKeyEventAction](input.md#oh_input_getkeyeventaction) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | Obtains the key event type. | 
| void [OH_Input_SetKeyEventKeyCode](input.md#oh_input_setkeyeventkeycode) (struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent, int32_t keyCode) | Sets the key code value for a key event. | 
| int32_t [OH_Input_GetKeyEventKeyCode](input.md#oh_input_getkeyeventkeycode) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | Obtains the key code value of a key event. | 
| void [OH_Input_SetKeyEventActionTime](input.md#oh_input_setkeyeventactiontime) (struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent, int64_t actionTime) | Sets the time when a key event occurs. | 
| int64_t [OH_Input_GetKeyEventActionTime](input.md#oh_input_getkeyeventactiontime) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | Obtains the time when a key event occurs. | 
| void [OH_Input_SetKeyEventWindowId](input.md#oh_input_setkeyeventwindowid) (struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent, int32_t windowId) | Sets the window ID of a key event. | 
| int32_t [OH_Input_GetKeyEventWindowId](input.md#oh_input_getkeyeventwindowid) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | Obtains the window ID of a key event. | 
| void [OH_Input_SetKeyEventDisplayId](input.md#oh_input_setkeyeventdisplayid) (struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent, int32_t displayId) | Sets the screen ID of a key event. | 
| int32_t [OH_Input_GetKeyEventDisplayId](input.md#oh_input_getkeyeventdisplayid) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | Obtains the screen ID of a key event. | 
| int32_t [OH_Input_InjectMouseEvent](input.md#oh_input_injectmouseevent) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Injects a mouse event. | 
| struct [Input_MouseEvent](input.md#input_mouseevent) \* [OH_Input_CreateMouseEvent](input.md#oh_input_createmouseevent) () | Creates a mouse event object. | 
| void [OH_Input_DestroyMouseEvent](input.md#oh_input_destroymouseevent) (struct [Input_MouseEvent](input.md#input_mouseevent) \*\*mouseEvent) | Destroys a mouse event object. | 
| void [OH_Input_SetMouseEventAction](input.md#oh_input_setmouseeventaction) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t action) | Sets the action for a mouse event. | 
| int32_t [OH_Input_GetMouseEventAction](input.md#oh_input_getmouseeventaction) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the action of a mouse event. | 
| void [OH_Input_SetMouseEventDisplayX](input.md#oh_input_setmouseeventdisplayx) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t displayX) | Sets the X coordinate for a mouse event. | 
| int32_t [OH_Input_GetMouseEventDisplayX](input.md#oh_input_getmouseeventdisplayx) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the X coordinate of a mouse event.| 
| void [OH_Input_SetMouseEventDisplayY](input.md#oh_input_setmouseeventdisplayy) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t displayY) | Sets the Y coordinate for a mouse event. | 
| int32_t [OH_Input_GetMouseEventDisplayY](input.md#oh_input_getmouseeventdisplayy) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the Y coordinate of a mouse event. | 
| void [OH_Input_SetMouseEventButton](input.md#oh_input_setmouseeventbutton) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t button) | Sets the button for a mouse event. | 
| int32_t [OH_Input_GetMouseEventButton](input.md#oh_input_getmouseeventbutton) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the button of a mouse event. | 
| void [OH_Input_SetMouseEventAxisType](input.md#oh_input_setmouseeventaxistype) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t axisType) | Sets the axis type for a mouse event. | 
| int32_t [OH_Input_GetMouseEventAxisType](input.md#oh_input_getmouseeventaxistype) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the axis type of a mouse event. | 
| void [OH_Input_SetMouseEventAxisValue](input.md#oh_input_setmouseeventaxisvalue) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, float axisValue) | Sets the axis value for a mouse axis event. | 
| float [OH_Input_GetMouseEventAxisValue](input.md#oh_input_getmouseeventaxisvalue) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the axis value of a mouse axis event. | 
| void [OH_Input_SetMouseEventActionTime](input.md#oh_input_setmouseeventactiontime) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int64_t actionTime) | Sets the time when a mouse event occurs.| 
| int64_t [OH_Input_GetMouseEventActionTime](input.md#oh_input_getmouseeventactiontime) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the time when a mouse event occurs. | 
| void [OH_Input_SetMouseEventWindowId](input.md#oh_input_setmouseeventwindowid) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t windowId) | Sets the window ID of a mouse event. | 
| int32_t [OH_Input_GetMouseEventWindowId](input.md#oh_input_getmouseeventwindowid) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the window ID of a mouse event. | 
| void [OH_Input_SetMouseEventDisplayId](input.md#oh_input_setmouseeventdisplayid) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t displayId) | Sets the screen ID of a mouse event. | 
| int32_t [OH_Input_GetMouseEventDisplayId](input.md#oh_input_getmouseeventdisplayid) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | Obtains the screen ID of a mouse event. | 
| int32_t [OH_Input_InjectTouchEvent](input.md#oh_input_injecttouchevent) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Injects a touch event. | 
| struct [Input_TouchEvent](input.md#input_touchevent) \* [OH_Input_CreateTouchEvent](input.md#oh_input_createtouchevent) () | Creates a touch event object. | 
| void [OH_Input_DestroyTouchEvent](input.md#oh_input_destroytouchevent) (struct [Input_TouchEvent](input.md#input_touchevent) \*\*touchEvent) | Destroys a touch event object. | 
| void [OH_Input_SetTouchEventAction](input.md#oh_input_settoucheventaction) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t action) | Sets the action for a touch event. | 
| int32_t [OH_Input_GetTouchEventAction](input.md#oh_input_gettoucheventaction) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Obtains the action of a touch event. | 
| void [OH_Input_SetTouchEventFingerId](input.md#oh_input_settoucheventfingerid) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t id) | Sets the finger ID for a touch event. | 
| int32_t [OH_Input_GetTouchEventFingerId](input.md#oh_input_gettoucheventfingerid) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Obtains the finger ID of a touch event. | 
| void [OH_Input_SetTouchEventDisplayX](input.md#oh_input_settoucheventdisplayx) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t displayX) | Sets the X coordinate for a touch event. | 
| int32_t [OH_Input_GetTouchEventDisplayX](input.md#oh_input_gettoucheventdisplayx) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Obtains the X coordinate of a touch event. | 
| void [OH_Input_SetTouchEventDisplayY](input.md#oh_input_settoucheventdisplayy) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t displayY) | Sets the Y coordinate for a touch event. | 
| int32_t [OH_Input_GetTouchEventDisplayY](input.md#oh_input_gettoucheventdisplayy) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Obtains the Y coordinate of a touch event. | 
| void [OH_Input_SetTouchEventActionTime](input.md#oh_input_settoucheventactiontime) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int64_t actionTime) | Sets the time when a touch event occurs. | 
| int64_t [OH_Input_GetTouchEventActionTime](input.md#oh_input_gettoucheventactiontime) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Obtains the time when a touch event occurs. | 
| void [OH_Input_SetTouchEventWindowId](input.md#oh_input_settoucheventwindowid) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t windowId) | Sets the window ID of a touchscreen event. | 
| int32_t [OH_Input_GetTouchEventWindowId](input.md#oh_input_gettoucheventwindowid) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Obtains the window ID of a touchscreen event. | 
| void [OH_Input_SetTouchEventDisplayId](input.md#oh_input_settoucheventdisplayid) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t displayId) | Sets the screen ID of a touchscreen event. | 
| int32_t [OH_Input_GetTouchEventDisplayId](input.md#oh_input_gettoucheventdisplayid) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | Obtains the screen ID of a touchscreen event. | 
| void [OH_Input_CancelInjection](input.md#oh_input_cancelinjection) () | Stops event injection and revokes authorization. | 
| [Input_AxisEvent](input.md#input_axisevent) \* [OH_Input_CreateAxisEvent](input.md#oh_input_createaxisevent) (void) | Creates an axis event object. | 
| [Input_Result](input.md#input_result) [OH_Input_DestroyAxisEvent](input.md#oh_input_destroyaxisevent) ([Input_AxisEvent](input.md#input_axisevent) \*\*axisEvent) | Destroys an axis event object. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventAction](input.md#oh_input_setaxiseventaction) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisAction](input.md#inputevent_axisaction) action) | Sets the action for an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventAction](input.md#oh_input_getaxiseventaction) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisAction](input.md#inputevent_axisaction) \*action) | Obtains the action of an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventDisplayX](input.md#oh_input_setaxiseventdisplayx) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, float displayX) | Sets the X coordinate for an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventDisplayX](input.md#oh_input_getaxiseventdisplayx) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, float \*displayX) | Obtains the X coordinate of an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventDisplayY](input.md#oh_input_setaxiseventdisplayy) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, float displayY) | Sets the Y coordinate for an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventDisplayY](input.md#oh_input_getaxiseventdisplayy) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, float \*displayY) | Obtains the Y coordinate of an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventAxisValue](input.md#oh_input_setaxiseventaxisvalue) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisType](input.md#inputevent_axistype) axisType, double axisValue) | Sets the axis value of the axis type specified by the axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventAxisValue](input.md#oh_input_getaxiseventaxisvalue) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisType](input.md#inputevent_axistype) axisType, double \*axisValue) | Obtains the axis value for the specified axis type of the axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventActionTime](input.md#oh_input_setaxiseventactiontime) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, int64_t actionTime) | Sets the time when an axis event occurs. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventActionTime](input.md#oh_input_getaxiseventactiontime) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, int64_t \*actionTime) | Obtains the time when an axis event occurs. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventType](input.md#oh_input_setaxiseventtype) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) axisEventType) | Sets the axis event type. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventType](input.md#oh_input_getaxiseventtype) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) \*axisEventType) | Obtains the axis event type. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventSourceType](input.md#oh_input_setaxiseventsourcetype) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_SourceType](input.md#inputevent_sourcetype) sourceType) | Sets the axis event source type. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventSourceType](input.md#oh_input_getaxiseventsourcetype) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_SourceType](input.md#inputevent_sourcetype) \*sourceType) | Obtains the axis event source type. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventWindowId](input.md#oh_input_setaxiseventwindowid) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, int32_t windowId) | Sets the window ID of an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventWindowId](input.md#oh_input_getaxiseventwindowid) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, int32_t \*windowId) | Obtains the window ID of an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventDisplayId](input.md#oh_input_setaxiseventdisplayid) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, int32_t displayId) | Sets the screen ID of an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventDisplayId](input.md#oh_input_getaxiseventdisplayid) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, int32_t \*displayId) | Obtains the screen ID of an axis event. | 
| [Input_Result](input.md#input_result) [OH_Input_AddKeyEventMonitor](input.md#oh_input_addkeyeventmonitor) ([Input_KeyEventCallback](input.md#input_keyeventcallback) callback) | Adds a listener for key events. | 
| [Input_Result](input.md#input_result) [OH_Input_AddMouseEventMonitor](input.md#oh_input_addmouseeventmonitor) ([Input_MouseEventCallback](input.md#input_mouseeventcallback) callback) | Adds a listener for mouse events, including mouse click and movement events, but not scroll wheel events. Scroll wheel events are axis events. | 
| [Input_Result](input.md#input_result) [OH_Input_AddTouchEventMonitor](input.md#oh_input_addtoucheventmonitor) ([Input_TouchEventCallback](input.md#input_toucheventcallback) callback) | Adds a listener for touch events. | 
| [Input_Result](input.md#input_result) [OH_Input_AddAxisEventMonitorForAll](input.md#oh_input_addaxiseventmonitorforall) ([Input_AxisEventCallback](input.md#input_axiseventcallback) callback) | Adds a listener for all types of axis events, which are defined in [InputEvent_AxisEventType](input.md#inputevent_axiseventtype). | 
| [Input_Result](input.md#input_result) [OH_Input_AddAxisEventMonitor](input.md#oh_input_addaxiseventmonitor) ([InputEvent_AxisEventType](input.md#inputevent_axiseventtype) axisEventType, [Input_AxisEventCallback](input.md#input_axiseventcallback) callback) | Adds a listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](input.md#inputevent_axiseventtype). | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveKeyEventMonitor](input.md#oh_input_removekeyeventmonitor) ([Input_KeyEventCallback](input.md#input_keyeventcallback) callback) | Removes the listener for key events. | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveMouseEventMonitor](input.md#oh_input_removemouseeventmonitor) ([Input_MouseEventCallback](input.md#input_mouseeventcallback) callback) | Removes the listener for mouse events. | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveTouchEventMonitor](input.md#oh_input_removetoucheventmonitor) ([Input_TouchEventCallback](input.md#input_toucheventcallback) callback) | Removes the listener for touch events. | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveAxisEventMonitorForAll](input.md#oh_input_removeaxiseventmonitorforall) ([Input_AxisEventCallback](input.md#input_axiseventcallback) callback) | Removes the listener for all types of axis events. | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveAxisEventMonitor](input.md#oh_input_removeaxiseventmonitor) ([InputEvent_AxisEventType](input.md#inputevent_axiseventtype) axisEventType, [Input_AxisEventCallback](input.md#input_axiseventcallback) callback) | Removes the listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](input.md#inputevent_axiseventtype). | 
| [Input_Result](input.md#input_result) [OH_Input_AddKeyEventInterceptor](input.md#oh_input_addkeyeventinterceptor) ([Input_KeyEventCallback](input.md#input_keyeventcallback) callback, [Input_InterceptorOptions](input.md#input_interceptoroptions) \*option) | Adds an interceptor for key events. If multiple interceptors are added, only the first one takes effect. An interception event is reported only when the application gains focus. | 
| [Input_Result](input.md#input_result) [OH_Input_AddInputEventInterceptor](input.md#oh_input_addinputeventinterceptor) ([Input_InterceptorEventCallback](_input___interceptor_event_callback.md) \*callback, [Input_InterceptorOptions](input.md#input_interceptoroptions) \*option) | Adds an interceptor for input events, including mouse, touch, and axis events. If multiple interceptors are added, only the first one takes effect. An interception event is reported only when the application gains focus. | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveKeyEventInterceptor](input.md#oh_input_removekeyeventinterceptor) (void) | Removes the interceptor for key events. | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveInputEventInterceptor](input.md#oh_input_removeinputeventinterceptor) (void) | Removes the interceptor for input events, including mouse, touch, and axis events. | 
| [Input_Result](input.md#input_result)  [OH_Input_GetIntervalSinceLastInput](input.md#oh_input_getintervalsincelastinput) (int64_t \*timeInterval) | Obtains the interval since the last system input event. | 
| [Input_Hotkey](input.md#input_hotkey) \* [OH_Input_CreateHotkey](input.md#oh_input_createhotkey) (void) | Creates a shortcut key object. | 
| void [OH_Input_DestroyHotkey](input.md#oh_input_destroyhotkey) ([Input_Hotkey](input.md#input_hotkey) \*\*hotkey) | Destroys a shortcut key object. | 
| void [OH_Input_SetPreKeys](input.md#oh_input_setprekeys) ([Input_Hotkey](input.md#input_hotkey) \*hotkey, int32_t \*preKeys, int32_t size) | Sets the modifier key. | 
| [Input_Result](input.md#input_result) [OH_Input_GetPreKeys](input.md#oh_input_getprekeys) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, int32_t \*\*preKeys, int32_t \*preKeyCount) | Obtains the modifier key. | 
| void [OH_Input_SetFinalKey](input.md#oh_input_setfinalkey) ([Input_Hotkey](input.md#input_hotkey) \*hotkey, int32_t finalKey) | Sets the modified key. | 
| [Input_Result](input.md#input_result) [OH_Input_GetFinalKey](input.md#oh_input_getfinalkey) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, int32_t \*finalKeyCode) | Obtains the modified key. | 
| [Input_Hotkey](input.md#input_hotkey) \*\* [OH_Input_CreateAllSystemHotkeys](input.md#oh_input_createallsystemhotkeys) (int32_t count) | Creates an array of [Input_Hotkey](input.md#input_hotkey) instances. | 
| void [OH_Input_DestroyAllSystemHotkeys](input.md#oh_input_destroyallsystemhotkeys) ([Input_Hotkey](input.md#input_hotkey) \*\*hotkeys, int32_t count) | Destroys the array of [Input_Hotkey](input.md#input_hotkey) instances and reclaims the memory. | 
| [Input_Result](input.md#input_result) [OH_Input_GetAllSystemHotkeys](input.md#oh_input_getallsystemhotkeys) ([Input_Hotkey](input.md#input_hotkey) \*\*hotkey, int32_t \*count) | Obtains all configured shortcut keys. | 
| void [OH_Input_SetRepeat](input.md#oh_input_setrepeat) ([Input_Hotkey](input.md#input_hotkey) \*hotkey, bool isRepeat) | Specifies whether to report repeated key events. | 
| [Input_Result](input.md#input_result) [OH_Input_GetRepeat](input.md#oh_input_getrepeat) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, bool \*isRepeat) | Checks whether to report repeated key events. | 
| [Input_Result](input.md#input_result) [OH_Input_AddHotkeyMonitor](input.md#oh_input_addhotkeymonitor) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, [Input_HotkeyCallback](input.md#input_hotkeycallback) callback) | Subscribes to shortcut key events. This API is not applicable to wearables and lite wearables. | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveHotkeyMonitor](input.md#oh_input_removehotkeymonitor) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, [Input_HotkeyCallback](input.md#input_hotkeycallback) callback) | Unsubscribes from shortcut key events. | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceIds](input.md#oh_input_getdeviceids) (int32_t \*deviceIds, int32_t inSize, int32_t \*outSize) | Obtains the IDs of all input devices. | 
| [Input_Result](input.md#input_result) [OH_Input_GetDevice](input.md#oh_input_getdevice) (int32_t deviceId, [Input_DeviceInfo](input.md#input_deviceinfo) \*\*deviceInfo) | Obtains information about the input device. | 
| [Input_DeviceInfo](input.md#input_deviceinfo) \* [OH_Input_CreateDeviceInfo](input.md#oh_input_createdeviceinfo) (void) | Creates a **deviceInfo** object. | 
| void [OH_Input_DestroyDeviceInfo](input.md#oh_input_destroydeviceinfo) ([Input_DeviceInfo](input.md#input_deviceinfo) \*\*deviceInfo) | Destroys a **deviceInfo** object. | 
| [Input_Result](input.md#input_result) [OH_Input_GetKeyboardType](input.md#oh_input_getkeyboardtype) (int32_t deviceId, int32_t \*keyboardType) | Obtains the keyboard type of the input device. | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceId](input.md#oh_input_getdeviceid) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*id) | Obtains the ID of an input device. | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceName](input.md#oh_input_getdevicename) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, char \*\*name) | Obtains the name of an input device. | 
| [Input_Result](input.md#input_result) [OH_Input_GetCapabilities](input.md#oh_input_getcapabilities) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*capabilities) | Obtains the capabilities of an input device, for example, a touchscreen, touchpad, or keyboard. | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceVersion](input.md#oh_input_getdeviceversion) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*version) | Obtains the version information of an input device. | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceProduct](input.md#oh_input_getdeviceproduct) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*product) | Obtains the product information of an input device. | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceVendor](input.md#oh_input_getdevicevendor) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*vendor) | Obtains the vendor information of an input device. | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceAddress](input.md#oh_input_getdeviceaddress) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, char \*\*address) | Obtains the physical address of an input device. | 
| [Input_Result](input.md#input_result) [OH_Input_RegisterDeviceListener](input.md#oh_input_registerdevicelistener) ([Input_DeviceListener](_input___device_listener.md) \*listener) | Registers a listener for device hot swap events. | 
| [Input_Result](input.md#input_result) [OH_Input_UnregisterDeviceListener](input.md#oh_input_unregisterdevicelistener) ([Input_DeviceListener](_input___device_listener.md) \*listener) | Unregisters the listener for device hot swap events. | 
| [Input_Result](input.md#input_result) [OH_Input_UnregisterDeviceListeners](input.md#oh_input_unregisterdevicelisteners) () | Unregisters the listener for all device hot swap events. | 
| [Input_Result](input.md#input_result) [OH_Input_GetFunctionKeyState](input.md#oh_input_getfunctionkeystate) (int32_t keyCode, int32_t \*state) | Obtains the function key status. | 
