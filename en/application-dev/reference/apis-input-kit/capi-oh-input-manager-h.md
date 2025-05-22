# oh_input_manager.h

## Overview

Provides functions such as event injection and status query.

**Library**: libohinput.so

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Related module**: [input](capi-input.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Input_InterceptorEventCallback](capi-input-interceptoreventcallback.md) | Input_InterceptorEventCallback | Defines the structure of the interceptor for callback events, including mouse events, touch events, and axis events.|
| [Input_DeviceListener](capi-input-devicelistener.md) | Input_DeviceListener | Defines a listener for device hot swap events.|
| [Input_KeyState](capi-input-keystate.md) | Input_KeyState | Defines key information, which identifies a key pressing behavior. For example, the Ctrl key information contains the key value and key type.|
| [Input_KeyEvent](capi-input-keyevent.md) | Input_KeyEvent | Defines the key event to be injected.|
| [Input_MouseEvent](capi-input-mouseevent.md) | Input_MouseEvent | Defines the mouse event to be injected.|
| [Input_TouchEvent](capi-input-touchevent.md) | Input_TouchEvent | Defines the touch event to be injected.|
| [Input_AxisEvent](capi-input-axisevent.md) | Input_AxisEvent | Defines an axis event.|
| [Input_Hotkey](capi-input-hotkey.md) | Input_Hotkey | Defines the shortcut key structure.|
| [Input_DeviceInfo](capi-input-deviceinfo.md) | Input_DeviceInfo | Defines the input device information.|
| [Input_InterceptorOptions](capi-input-interceptoroptions.md) | Input_InterceptorOptions | Defines event interception options.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Input_KeyStateAction](#input_keystateaction) | Input_KeyStateAction | Provides the enum values of the key status.|
| [Input_KeyEventAction](#input_keyeventaction) | Input_KeyEventAction | Provides the enum values of the key event type.|
| [Input_MouseEventAction](#input_mouseeventaction) | Input_MouseEventAction | Provides the enum values of mouse actions.|
| [InputEvent_MouseAxis](#inputevent_mouseaxis) | InputEvent_MouseAxis | Provides the enum values of mouse axis event types.|
| [Input_MouseEventButton](#input_mouseeventbutton) | Input_MouseEventButton | Provides the enum values of mouse buttons.|
| [Input_TouchEventAction](#input_toucheventaction) | Input_TouchEventAction | Provides the enum values of touch actions.|
| [InputEvent_SourceType](#inputevent_sourcetype) | InputEvent_SourceType | Provides the enum values of event source types.|
| [Input_KeyboardType](#input_keyboardtype) | Input_KeyboardType | Provides the enum values of keyboard types of the input device.|
| [Input_Result](#input_result) | Input_Result | Provides the enum values of error codes.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*Input_HotkeyCallback)(Input_Hotkey* hotkey)](#input_hotkeycallback) | Input_HotkeyCallback | Defines the callback used to return shortcut key events.|
| [typedef void (\*Input_KeyEventCallback)(const Input_KeyEvent* keyEvent)](#input_keyeventcallback) | Input_KeyEventCallback | Defines a lifecycle callback for **keyEvent**. If the callback is triggered, **keyEvent** will be destroyed.|
| [typedef void (\*Input_MouseEventCallback)(const Input_MouseEvent* mouseEvent)](#input_mouseeventcallback) | Input_MouseEventCallback | Defines a lifecycle callback for **mouseEvent**. If the callback is triggered, **mouseEvent** will be destroyed.|
| [typedef void (\*Input_TouchEventCallback)(const Input_TouchEvent* touchEvent)](#input_toucheventcallback) | Input_TouchEventCallback | Defines a lifecycle callback for **touchEvent**. If the callback is triggered, **touchEvent** will be destroyed.|
| [typedef void (\*Input_AxisEventCallback)(const Input_AxisEvent* axisEvent)](#input_axiseventcallback) | Input_AxisEventCallback | Defines a lifecycle callback for **axisEvent**. If the callback is triggered, **axisEvent** will be destroyed.|
| [typedef void (\*Input_DeviceAddedCallback)(int32_t deviceId)](#input_deviceaddedcallback) | Input_DeviceAddedCallback | Defines a callback used to receive device insertion events.|
| [typedef void (\*Input_DeviceRemovedCallback)(int32_t deviceId)](#input_deviceremovedcallback) | Input_DeviceRemovedCallback | Defines a callback used to receive device removal events.|
| [Input_Result OH_Input_GetKeyState(struct Input_KeyState* keyState)](#oh_input_getkeystate) | - | Queries a key status enum object.|
| [struct Input_KeyState* OH_Input_CreateKeyState()](#oh_input_createkeystate) | - | Creates a key status enum object.|
| [void OH_Input_DestroyKeyState(struct Input_KeyState** keyState)](#oh_input_destroykeystate) | - | Destroys a key status enum object.|
| [void OH_Input_SetKeyCode(struct Input_KeyState* keyState, int32_t keyCode)](#oh_input_setkeycode) | - | Sets the key value of a key status enum object.|
| [void OH_Input_SetKeyPressed(struct Input_KeyState* keyState, int32_t keyAction)](#oh_input_setkeypressed) | - | Sets whether the key specific to a key status enum object is pressed.|
| [void OH_Input_SetKeySwitch(struct Input_KeyState* keyState, int32_t keySwitch)](#oh_input_setkeyswitch) | - | Sets the key switch of the key status enum object.|
| [struct Input_KeyEvent* OH_Input_CreateKeyEvent()](#oh_input_createkeyevent) | - | Creates a key event object.|
| [void OH_Input_DestroyKeyEvent(struct Input_KeyEvent** keyEvent)](#oh_input_destroykeyevent) | - | Destroys a key event object.|
| [void OH_Input_SetKeyEventAction(struct Input_KeyEvent* keyEvent, int32_t action)](#oh_input_setkeyeventaction) | - | Sets the key event type.|
| [void OH_Input_SetKeyEventKeyCode(struct Input_KeyEvent* keyEvent, int32_t keyCode)](#oh_input_setkeyeventkeycode) | - | Sets the key code value for a key event.|
| [void OH_Input_SetKeyEventActionTime(struct Input_KeyEvent* keyEvent, int64_t actionTime)](#oh_input_setkeyeventactiontime) | - | Sets the time when a key event occurs.|
| [void OH_Input_SetKeyEventWindowId(struct Input_KeyEvent* keyEvent, int32_t windowId)](#oh_input_setkeyeventwindowid) | - | Sets the window ID of a key event.|
| [void OH_Input_SetKeyEventDisplayId(struct Input_KeyEvent* keyEvent, int32_t displayId)](#oh_input_setkeyeventdisplayid) | - | Sets the screen ID of a key event.|
| [struct Input_MouseEvent* OH_Input_CreateMouseEvent()](#oh_input_createmouseevent) | - | Creates a mouse event object.|
| [void OH_Input_DestroyMouseEvent(struct Input_MouseEvent** mouseEvent)](#oh_input_destroymouseevent) | - | Destroys a mouse event object.|
| [void OH_Input_SetMouseEventAction(struct Input_MouseEvent* mouseEvent, int32_t action)](#oh_input_setmouseeventaction) | - | Sets the action for a mouse event.|
| [void OH_Input_SetMouseEventDisplayX(struct Input_MouseEvent* mouseEvent, int32_t displayX)](#oh_input_setmouseeventdisplayx) | - | Sets the X coordinate for a mouse event.|
| [void OH_Input_SetMouseEventDisplayY(struct Input_MouseEvent* mouseEvent, int32_t displayY)](#oh_input_setmouseeventdisplayy) | - | Sets the Y coordinate for a mouse event.|
| [void OH_Input_SetMouseEventButton(struct Input_MouseEvent* mouseEvent, int32_t button)](#oh_input_setmouseeventbutton) | - | Sets the button for a mouse event.|
| [void OH_Input_SetMouseEventAxisType(struct Input_MouseEvent* mouseEvent, int32_t axisType)](#oh_input_setmouseeventaxistype) | - | Sets the axis type for a mouse event.|
| [void OH_Input_SetMouseEventAxisValue(struct Input_MouseEvent* mouseEvent, float axisValue)](#oh_input_setmouseeventaxisvalue) | - | Sets the axis value for a mouse axis event.|
| [void OH_Input_SetMouseEventActionTime(struct Input_MouseEvent* mouseEvent, int64_t actionTime)](#oh_input_setmouseeventactiontime) | - | Sets the time when a mouse event occurs.|
| [void OH_Input_SetMouseEventWindowId(struct Input_MouseEvent* mouseEvent, int32_t windowId)](#oh_input_setmouseeventwindowid) | - | Sets the window ID of a mouse event.|
| [void OH_Input_SetMouseEventDisplayId(struct Input_MouseEvent* mouseEvent, int32_t displayId)](#oh_input_setmouseeventdisplayid) | - | Sets the screen ID of a mouse event.|
| [struct Input_TouchEvent* OH_Input_CreateTouchEvent()](#oh_input_createtouchevent) | - | Creates a touch event object.|
| [void OH_Input_DestroyTouchEvent(struct Input_TouchEvent** touchEvent)](#oh_input_destroytouchevent) | - | Destroys a touch event object.|
| [void OH_Input_SetTouchEventAction(struct Input_TouchEvent* touchEvent, int32_t action)](#oh_input_settoucheventaction) | - | Sets the action for a touch event.|
| [void OH_Input_SetTouchEventFingerId(struct Input_TouchEvent* touchEvent, int32_t id)](#oh_input_settoucheventfingerid) | - | Sets the finger ID for a touch event.|
| [void OH_Input_SetTouchEventDisplayX(struct Input_TouchEvent* touchEvent, int32_t displayX)](#oh_input_settoucheventdisplayx) | - | Sets the X coordinate for a touch event.|
| [void OH_Input_SetTouchEventDisplayY(struct Input_TouchEvent* touchEvent, int32_t displayY)](#oh_input_settoucheventdisplayy) | - | Sets the Y coordinate for a touch event.|
| [void OH_Input_SetTouchEventActionTime(struct Input_TouchEvent* touchEvent, int64_t actionTime)](#oh_input_settoucheventactiontime) | - | Sets the time when a touch event occurs.|
| [void OH_Input_SetTouchEventWindowId(struct Input_TouchEvent* touchEvent, int32_t windowId)](#oh_input_settoucheventwindowid) | - | Sets the window ID of a touchscreen event.|
| [void OH_Input_SetTouchEventDisplayId(struct Input_TouchEvent* touchEvent, int32_t displayId)](#oh_input_settoucheventdisplayid) | - | Sets the screen ID of a touchscreen event.|
| [void OH_Input_CancelInjection()](#oh_input_cancelinjection) | - | Stops event injection and revokes authorization.|
| [Input_AxisEvent* OH_Input_CreateAxisEvent(void)](#oh_input_createaxisevent) | - | Creates an axis event object.|
| [Input_Result OH_Input_DestroyAxisEvent(Input_AxisEvent** axisEvent)](#oh_input_destroyaxisevent) | - | Destroys an axis event object.|
| [Input_Result OH_Input_SetAxisEventAction(Input_AxisEvent* axisEvent, InputEvent_AxisAction action)](#oh_input_setaxiseventaction) | - | Sets the action for an axis event.|
| [Input_Result OH_Input_GetAxisEventAction(const Input_AxisEvent* axisEvent, InputEvent_AxisAction *action)](#oh_input_getaxiseventaction) | - | Obtains the action of an axis event.|
| [Input_Result OH_Input_SetAxisEventDisplayX(Input_AxisEvent* axisEvent, float displayX)](#oh_input_setaxiseventdisplayx) | - | Sets the X coordinate for an axis event.|
| [Input_Result OH_Input_GetAxisEventDisplayX(const Input_AxisEvent* axisEvent, float* displayX)](#oh_input_getaxiseventdisplayx) | - | Obtains the X coordinate of an axis event.|
| [Input_Result OH_Input_SetAxisEventDisplayY(Input_AxisEvent* axisEvent, float displayY)](#oh_input_setaxiseventdisplayy) | - | Sets the Y coordinate for an axis event.|
| [Input_Result OH_Input_GetAxisEventDisplayY(const Input_AxisEvent* axisEvent, float* displayY)](#oh_input_getaxiseventdisplayy) | - | Obtains the Y coordinate of an axis event.|
| [Input_Result OH_Input_SetAxisEventAxisValue(Input_AxisEvent* axisEvent,InputEvent_AxisType axisType, double axisValue)](#oh_input_setaxiseventaxisvalue) | - | Sets the axis value of the axis type specified by the axis event.|
| [Input_Result OH_Input_GetAxisEventAxisValue(const Input_AxisEvent* axisEvent,InputEvent_AxisType axisType, double* axisValue)](#oh_input_getaxiseventaxisvalue) | - | Obtains the axis value for the specified axis type of the axis event.|
| [Input_Result OH_Input_SetAxisEventActionTime(Input_AxisEvent* axisEvent, int64_t actionTime)](#oh_input_setaxiseventactiontime) | - | Sets the time when an axis event occurs.|
| [Input_Result OH_Input_GetAxisEventActionTime(const Input_AxisEvent* axisEvent, int64_t* actionTime)](#oh_input_getaxiseventactiontime) | - | Obtains the time when an axis event occurs.|
| [Input_Result OH_Input_SetAxisEventType(Input_AxisEvent* axisEvent, InputEvent_AxisEventType axisEventType)](#oh_input_setaxiseventtype) | - | Sets the axis event type.|
| [Input_Result OH_Input_GetAxisEventType(const Input_AxisEvent* axisEvent, InputEvent_AxisEventType* axisEventType)](#oh_input_getaxiseventtype) | - | Obtains the axis event type.|
| [Input_Result OH_Input_SetAxisEventSourceType(Input_AxisEvent* axisEvent, InputEvent_SourceType sourceType)](#oh_input_setaxiseventsourcetype) | - | Sets the axis event source type.|
| [Input_Result OH_Input_GetAxisEventSourceType(const Input_AxisEvent* axisEvent, InputEvent_SourceType* sourceType)](#oh_input_getaxiseventsourcetype) | - | Obtains the axis event source type.|
| [Input_Result OH_Input_SetAxisEventWindowId(Input_AxisEvent* axisEvent, int32_t windowId)](#oh_input_setaxiseventwindowid) | - | Sets the window ID of an axis event.|
| [Input_Result OH_Input_GetAxisEventWindowId(const Input_AxisEvent* axisEvent, int32_t* windowId)](#oh_input_getaxiseventwindowid) | - | Obtains the window ID of an axis event.|
| [Input_Result OH_Input_SetAxisEventDisplayId(Input_AxisEvent* axisEvent, int32_t displayId)](#oh_input_setaxiseventdisplayid) | - | Sets the screen ID of an axis event.|
| [Input_Result OH_Input_GetAxisEventDisplayId(const Input_AxisEvent* axisEvent, int32_t* displayId)](#oh_input_getaxiseventdisplayid) | - | Obtains the screen ID of an axis event.|
| [Input_Result OH_Input_AddKeyEventMonitor(Input_KeyEventCallback callback)](#oh_input_addkeyeventmonitor) | - | Adds a listener for key events.|
| [Input_Result OH_Input_AddMouseEventMonitor(Input_MouseEventCallback callback)](#oh_input_addmouseeventmonitor) | - | Adds a listener for mouse events, including mouse click and movement events, but not scroll wheel events. Scroll wheel events are axis events.|
| [Input_Result OH_Input_AddTouchEventMonitor(Input_TouchEventCallback callback)](#oh_input_addtoucheventmonitor) | - | Adds a listener for touch events.|
| [Input_Result OH_Input_AddAxisEventMonitorForAll(Input_AxisEventCallback callback)](#oh_input_addaxiseventmonitorforall) | - | Adds a listener for all types of axis events, which are defined in [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).|
| [Input_Result OH_Input_AddAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback)](#oh_input_addaxiseventmonitor) | - | Adds a listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).|
| [Input_Result OH_Input_RemoveKeyEventMonitor(Input_KeyEventCallback callback)](#oh_input_removekeyeventmonitor) | - | Removes the listener for key events.|
| [Input_Result OH_Input_RemoveMouseEventMonitor(Input_MouseEventCallback callback)](#oh_input_removemouseeventmonitor) | - | Removes the listener for mouse events.|
| [Input_Result OH_Input_RemoveTouchEventMonitor(Input_TouchEventCallback callback)](#oh_input_removetoucheventmonitor) | - | Removes the listener for touch events.|
| [Input_Result OH_Input_RemoveAxisEventMonitorForAll(Input_AxisEventCallback callback)](#oh_input_removeaxiseventmonitorforall) | - | Removes the listener for all types of axis events.|
| [Input_Result OH_Input_RemoveAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback)](#oh_input_removeaxiseventmonitor) | - | Removes the listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).|
| [Input_Result OH_Input_AddKeyEventInterceptor(Input_KeyEventCallback callback, Input_InterceptorOptions *option)](#oh_input_addkeyeventinterceptor) | - | Adds an interceptor for key events. If multiple interceptors are added, only the first one takes effect. Key events are intercepted only when the application gains focus.|
| [Input_Result OH_Input_AddInputEventInterceptor(Input_InterceptorEventCallback *callback,Input_InterceptorOptions *option)](#oh_input_addinputeventinterceptor) | - | Adds an interceptor for input events, including mouse, touch, and axis events. If multiple interceptors are added, only the first one takes effect. Key events are intercepted only when the application window is hit.|
| [Input_Result OH_Input_RemoveKeyEventInterceptor(void)](#oh_input_removekeyeventinterceptor) | - | Removes the interceptor for key events.|
| [Input_Result OH_Input_RemoveInputEventInterceptor(void)](#oh_input_removeinputeventinterceptor) | - | Removes the interceptor for input events, including mouse, touch, and axis events.|
| [Input_Result OH_Input_GetIntervalSinceLastInput(int64_t *timeInterval)](#oh_input_getintervalsincelastinput) | - | Obtains the interval since the last system input event.|
| [Input_Hotkey *OH_Input_CreateHotkey(void)](#oh_input_createhotkey) | - | Creates a shortcut key object.|
| [void OH_Input_DestroyHotkey(Input_Hotkey **hotkey)](#oh_input_destroyhotkey) | - | Destroys a shortcut key object.|
| [void OH_Input_SetPreKeys(Input_Hotkey *hotkey, int32_t *preKeys, int32_t size)](#oh_input_setprekeys) | - | Sets the modifier key.|
| [Input_Result OH_Input_GetPreKeys(const Input_Hotkey *hotkey, int32_t **preKeys, int32_t *preKeyCount)](#oh_input_getprekeys) | - | Obtains the modifier key.|
| [void OH_Input_SetFinalKey(Input_Hotkey* hotkey, int32_t finalKey)](#oh_input_setfinalkey) | - | Sets the modified key.|
| [Input_Result OH_Input_GetFinalKey(const Input_Hotkey* hotkey, int32_t *finalKeyCode)](#oh_input_getfinalkey) | - | Obtains the modified key.|
| [Input_Hotkey **OH_Input_CreateAllSystemHotkeys(int32_t count)](#oh_input_createallsystemhotkeys) | - | Creates an array of [Input_Hotkey](capi-input-hotkey.md) instances.|
| [void OH_Input_DestroyAllSystemHotkeys(Input_Hotkey **hotkeys, int32_t count)](#oh_input_destroyallsystemhotkeys) | - | Destroys the array of [Input_Hotkey](capi-input-hotkey.md) instances and reclaims the memory.|
| [Input_Result OH_Input_GetAllSystemHotkeys(Input_Hotkey **hotkey, int32_t *count)](#oh_input_getallsystemhotkeys) | - | Obtains all configured shortcut keys.|
| [void OH_Input_SetRepeat(Input_Hotkey* hotkey, bool isRepeat)](#oh_input_setrepeat) | - | Specifies whether to report repeated key events.|
| [Input_Result OH_Input_GetRepeat(const Input_Hotkey* hotkey, bool *isRepeat)](#oh_input_getrepeat) | - | Checks whether to report repeated key events.|
| [Input_Result OH_Input_AddHotkeyMonitor(const Input_Hotkey* hotkey, Input_HotkeyCallback callback)](#oh_input_addhotkeymonitor) | - | Subscribes to shortcut key events. This API is not applicable to wearables and lite wearables.|
| [Input_Result OH_Input_RemoveHotkeyMonitor(const Input_Hotkey* hotkey, Input_HotkeyCallback callback)](#oh_input_removehotkeymonitor) | - | Unsubscribes from shortcut key events.|
| [Input_Result OH_Input_RegisterDeviceListener(Input_DeviceListener* listener)](#oh_input_registerdevicelistener) | - | Registers a listener for device hot swap events.|
| [Input_Result OH_Input_UnregisterDeviceListener(Input_DeviceListener* listener)](#oh_input_unregisterdevicelistener) | - | Unregisters the listener for device hot swap events.|
| [Input_Result OH_Input_UnregisterDeviceListeners()](#oh_input_unregisterdevicelisteners) | - | Unregisters the listener for all device hot swap events.|
| [Input_Result OH_Input_GetDeviceIds(int32_t *deviceIds, int32_t inSize, int32_t *outSize)](#oh_input_getdeviceids) | - | Obtains the IDs of all input devices.|
| [Input_Result OH_Input_GetDevice(int32_t deviceId, Input_DeviceInfo **deviceInfo)](#oh_input_getdevice) | - | Obtains information about the input device.|
| [Input_DeviceInfo* OH_Input_CreateDeviceInfo(void)](#oh_input_createdeviceinfo) | - | Creates a **deviceInfo** object.|
| [void OH_Input_DestroyDeviceInfo(Input_DeviceInfo **deviceInfo)](#oh_input_destroydeviceinfo) | - | Destroys a **deviceInfo** object.|
| [Input_Result OH_Input_GetKeyboardType(int32_t deviceId, int32_t *keyboardType)](#oh_input_getkeyboardtype) | - | Obtains the keyboard type of the input device.|
| [Input_Result OH_Input_GetDeviceId(Input_DeviceInfo *deviceInfo, int32_t *id)](#oh_input_getdeviceid) | - | Obtains the ID of an input device.|
| [Input_Result OH_Input_GetDeviceName(Input_DeviceInfo *deviceInfo, char **name)](#oh_input_getdevicename) | - | Obtains the name of an input device.|
| [Input_Result OH_Input_GetCapabilities(Input_DeviceInfo *deviceInfo, int32_t *capabilities)](#oh_input_getcapabilities) | - | Obtains the capabilities of an input device, for example, a touchscreen, touchpad, or keyboard.|
| [Input_Result OH_Input_GetDeviceVersion(Input_DeviceInfo *deviceInfo, int32_t *version)](#oh_input_getdeviceversion) | - | Obtains the version information of an input device.|
| [Input_Result OH_Input_GetDeviceProduct(Input_DeviceInfo *deviceInfo, int32_t *product)](#oh_input_getdeviceproduct) | - | Obtains the product information of an input device.|
| [Input_Result OH_Input_GetDeviceVendor(Input_DeviceInfo *deviceInfo, int32_t *vendor)](#oh_input_getdevicevendor) | - | Obtains the vendor information of an input device.|
| [Input_Result OH_Input_GetDeviceAddress(Input_DeviceInfo *deviceInfo, char **address)](#oh_input_getdeviceaddress) | - | Obtains the physical address of an input device.|
| [Input_Result OH_Input_GetFunctionKeyState(int32_t keyCode, int32_t *state)](#oh_input_getfunctionkeystate) | - | Obtains the function key status.|

## Enum Description

### Input_KeyStateAction

```
enum Input_KeyStateAction
```

**Description**

Provides the enum values of the key status.

**Since**: 12

| Enum| Description|
| -- | -- |
| KEY_DEFAULT = -1 | Default status.|
| KEY_PRESSED = 0 | Pressing of a key.|
| KEY_RELEASED = 1 | Release of a key.|
| KEY_SWITCH_ON = 2 | Key switch enabled.|
| KEY_SWITCH_OFF = 3 | Key switch disabled.|

### Input_KeyEventAction

```
enum Input_KeyEventAction
```

**Description**

Provides the enum values of the key event type.

**Since**: 12

| Enum| Description|
| -- | -- |
| KEY_ACTION_CANCEL = 0 | Button action canceled.|
| KEY_ACTION_DOWN = 1 | Pressing of a key.|
| KEY_ACTION_UP = 2 | Release of a key.|

### Input_MouseEventAction

```
enum Input_MouseEventAction
```

**Description**

Provides the enum values of mouse actions.

**Since**: 12

| Enum| Description|
| -- | -- |
| MOUSE_ACTION_CANCEL = 0 | Mouse action canceled.|
| MOUSE_ACTION_MOVE = 1 | Moving of the mouse pointer.|
| MOUSE_ACTION_BUTTON_DOWN = 2 | Pressing of the mouse button.|
| MOUSE_ACTION_BUTTON_UP = 3 | Release of the mouse button.|
| MOUSE_ACTION_AXIS_BEGIN = 4 | Beginning of the mouse axis event.|
| MOUSE_ACTION_AXIS_UPDATE = 5 | Updating of the mouse axis event.|
| MOUSE_ACTION_AXIS_END = 6 | End of the mouse axis event.|

### InputEvent_MouseAxis

```
enum InputEvent_MouseAxis
```

**Description**

Provides the enum values of mouse axis event types.

**Since**: 12

| Enum| Description|
| -- | -- |
| MOUSE_AXIS_SCROLL_VERTICAL = 0 | Vertical scroll axis.|
| MOUSE_AXIS_SCROLL_HORIZONTAL = 1 | Horizontal scroll axis.|

### Input_MouseEventButton

```
enum Input_MouseEventButton
```

**Description**

Provides the enum values of mouse buttons.

**Since**: 12

| Enum| Description|
| -- | -- |
| MOUSE_BUTTON_NONE = -1 | Invalid key.|
| MOUSE_BUTTON_LEFT = 0 | Left mouse button.|
| MOUSE_BUTTON_MIDDLE = 1 | Middle mouse button.|
| MOUSE_BUTTON_RIGHT = 2 | Right mouse button.|
| MOUSE_BUTTON_FORWARD = 3 | Mouse forward button.|
| MOUSE_BUTTON_BACK = 4 | Mouse back button.|

### Input_TouchEventAction

```
enum Input_TouchEventAction
```

**Description**

Provides the enum values of touch actions.

**Since**: 12

| Enum| Description|
| -- | -- |
| TOUCH_ACTION_CANCEL = 0 | Cancellation of touch.|
| TOUCH_ACTION_DOWN = 1 | Pressing of touch.|
| TOUCH_ACTION_MOVE = 2 | Moving of touch.|
| TOUCH_ACTION_UP = 3 | Lifting of touch.|

### InputEvent_SourceType

```
enum InputEvent_SourceType
```

**Description**

Enter the event source type.

**Since**: 12

| Enum| Description|
| -- | -- |
| SOURCE_TYPE_MOUSE = 1 | Source that generates events similar to mouse cursor movement, button press and release, and wheel scrolling.|
| SOURCE_TYPE_TOUCHSCREEN = 2 | Source that generates a touchscreen multi-touch event.|
| SOURCE_TYPE_TOUCHPAD = 3 | Source that generates a touchpad multi-touch event.|

### Input_KeyboardType

```
enum Input_KeyboardType
```

**Description**

Provides the enum values of keyboard types of the input device.

**Since**: 13

| Enum| Description|
| -- | -- |
| KEYBOARD_TYPE_NONE = 0 | Keyboard without keys.|
| KEYBOARD_TYPE_UNKNOWN = 1 | Keyboard with unknown keys.|
| KEYBOARD_TYPE_ALPHABETIC = 2 | Full keyboard.|
| KEYBOARD_TYPE_DIGITAL = 3 | Numeric keypad.|
| KEYBOARD_TYPE_STYLUS = 4 | Stylus.|
| KEYBOARD_TYPE_REMOTE_CONTROL = 5 | Remote control.|

### Input_Result

```
enum Input_Result
```

**Description**

Provides the enum values of error codes.

**Since**: 12

| Enum| Description|
| -- | -- |
| INPUT_SUCCESS = 0 | Operation succeeded|
| INPUT_PERMISSION_DENIED = 201 | Permission verification failed.|
| INPUT_NOT_SYSTEM_APPLICATION = 202 | Not a system application.|
| INPUT_PARAMETER_ERROR = 401 | Parameter check failed.|
| INPUT_DEVICE_NOT_SUPPORTED = 801 | Input device not supported.<br>**Since**: 14|
| INPUT_SERVICE_EXCEPTION = 3800001 | Service Error|
| INPUT_REPEAT_INTERCEPTOR = 4200001 | Interceptor repeatedly created.|
| INPUT_OCCUPIED_BY_SYSTEM = 4200002 | Input device occupied by a system application.<br>**Since**: 14|
| INPUT_OCCUPIED_BY_OTHER = 4200003 | Input device occupied by another application.<br>**Since**: 14|
| INPUT_KEYBOARD_DEVICE_NOT_EXIST = 3900002 |  No keyboard is connected.<br>**Since**: 15|


## Function Description

### Input_HotkeyCallback()

```
typedef void (*Input_HotkeyCallback)(Input_Hotkey* hotkey)
```

**Description**

Defines the callback used to return shortcut key events.

**Since**: 14

### Input_KeyEventCallback()

```
typedef void (*Input_KeyEventCallback)(const Input_KeyEvent* keyEvent)
```

**Description**

Defines a lifecycle callback for **keyEvent**. If the callback is triggered, **keyEvent** will be destroyed.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_KeyEvent](capi-input-keyevent.md)* keyEvent | Key event object.|

### Input_MouseEventCallback()

```
typedef void (*Input_MouseEventCallback)(const Input_MouseEvent* mouseEvent)
```

**Description**

Defines a lifecycle callback for **mouseEvent**. If the callback is triggered, **mouseEvent** will be destroyed.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|

### Input_TouchEventCallback()

```
typedef void (*Input_TouchEventCallback)(const Input_TouchEvent* touchEvent)
```

**Description**

Defines a lifecycle callback for **touchEvent**. If the callback is triggered, **touchEvent** will be destroyed.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_TouchEvent](capi-input-touchevent.md)* touchEvent | Touch event object.|

### Input_AxisEventCallback()

```
typedef void (*Input_AxisEventCallback)(const Input_AxisEvent* axisEvent)
```

**Description**

Defines a lifecycle callback for **axisEvent**. If the callback is triggered, **axisEvent** will be destroyed.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|

### Input_DeviceAddedCallback()

```
typedef void (*Input_DeviceAddedCallback)(int32_t deviceId)
```

**Description**

Defines a callback used to receive device insertion events.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t deviceId | Device ID.|

### Input_DeviceRemovedCallback()

```
typedef void (*Input_DeviceRemovedCallback)(int32_t deviceId)
```

**Description**

Defines a callback used to receive device removal events.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t deviceId | Device ID.|

### OH_Input_GetKeyState()

```
Input_Result OH_Input_GetKeyState(struct Input_KeyState* keyState)
```

**Description**

Queries a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyState](capi-input-keystate.md)* keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br> an error code defined in [Input_Result](#input_result) otherwise.|

### OH_Input_CreateKeyState()

```
struct Input_KeyState* OH_Input_CreateKeyState()
```

**Description**

Creates a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| struct | [Input_KeyState](capi-input-keystate.md) pointer object if the operation is successful; a null pointer otherwise.|

### OH_Input_DestroyKeyState()

```
void OH_Input_DestroyKeyState(struct Input_KeyState** keyState)
```

**Description**

Destroys a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyState](capi-input-keystate.md)** keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).|

### OH_Input_SetKeyCode()

```
void OH_Input_SetKeyCode(struct Input_KeyState* keyState, int32_t keyCode)
```

**Description**

Sets the key value of a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyState](capi-input-keystate.md)* keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).|
| int32_t keyCode | Key code.|

### OH_Input_SetKeyPressed()

```
void OH_Input_SetKeyPressed(struct Input_KeyState* keyState, int32_t keyAction)
```

**Description**

Sets whether the key specific to a key status enum object is pressed.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyState](capi-input-keystate.md)* keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).|
| int32_t keyAction | Whether a key is pressed. For details, see [Input_KeyEventAction](#input_keyeventaction).|

### OH_Input_SetKeySwitch()

```
void OH_Input_SetKeySwitch(struct Input_KeyState* keyState, int32_t keySwitch)
```

**Description**

Sets the key switch of the key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyState](capi-input-keystate.md)* keyState | Key status enum object. For details, see [Input_KeyStateAction](#input_keystateaction).|
| int32_t keySwitch | Key switch.|

### OH_Input_CreateKeyEvent()

```
struct Input_KeyEvent* OH_Input_CreateKeyEvent()
```

**Description**

Creates a key event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| struct | [Input_KeyEvent](capi-input-keyevent.md) pointer object if the operation is successful; a null pointer otherwise.|

### OH_Input_DestroyKeyEvent()

```
void OH_Input_DestroyKeyEvent(struct Input_KeyEvent** keyEvent)
```

**Description**

Destroys a key event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyEvent](capi-input-keyevent.md)** keyEvent | Key event object.|

### OH_Input_SetKeyEventAction()

```
void OH_Input_SetKeyEventAction(struct Input_KeyEvent* keyEvent, int32_t action)
```

**Description**

Sets the key event type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyEvent](capi-input-keyevent.md)* keyEvent | Key event object.|
| int32_t action | Key event type.|

### OH_Input_SetKeyEventKeyCode()

```
void OH_Input_SetKeyEventKeyCode(struct Input_KeyEvent* keyEvent, int32_t keyCode)
```

**Description**

Sets the key code value for a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyEvent](capi-input-keyevent.md)* keyEvent | Key event object.|
| int32_t keyCode | Key value.|

### OH_Input_SetKeyEventActionTime()

```
void OH_Input_SetKeyEventActionTime(struct Input_KeyEvent* keyEvent, int64_t actionTime)
```

**Description**

Sets the time when a key event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyEvent](capi-input-keyevent.md)* keyEvent | Key event object.|
| int64_t actionTime | Time when a key event occurs.|

### OH_Input_SetKeyEventWindowId()

```
void OH_Input_SetKeyEventWindowId(struct Input_KeyEvent* keyEvent, int32_t windowId)
```

**Description**

Sets the window ID of a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyEvent](capi-input-keyevent.md)* keyEvent | Key event object.|
| int32_t windowId | Window ID of the key event.|

### OH_Input_SetKeyEventDisplayId()

```
void OH_Input_SetKeyEventDisplayId(struct Input_KeyEvent* keyEvent, int32_t displayId)
```

**Description**

Sets the screen ID of a key event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_KeyEvent](capi-input-keyevent.md)* keyEvent | Key event object.|
| int32_t displayId | Screen ID of the key event.|

### OH_Input_CreateMouseEvent()

```
struct Input_MouseEvent* OH_Input_CreateMouseEvent()
```

**Description**

Creates a mouse event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| struct | [Input_MouseEvent](capi-input-mouseevent.md) pointer object if the operation is successful; a null pointer otherwise.|

### OH_Input_DestroyMouseEvent()

```
void OH_Input_DestroyMouseEvent(struct Input_MouseEvent** mouseEvent)
```

**Description**

Destroys a mouse event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)** mouseEvent | Mouse event object.|

### OH_Input_SetMouseEventAction()

```
void OH_Input_SetMouseEventAction(struct Input_MouseEvent* mouseEvent, int32_t action)
```

**Description**

Sets the action for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| int32_t action | Mouse action.|

### OH_Input_SetMouseEventDisplayX()

```
void OH_Input_SetMouseEventDisplayX(struct Input_MouseEvent* mouseEvent, int32_t displayX)
```

**Description**

Sets the X coordinate for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| int32_t displayX | X coordinate on the screen.|

### OH_Input_SetMouseEventDisplayY()

```
void OH_Input_SetMouseEventDisplayY(struct Input_MouseEvent* mouseEvent, int32_t displayY)
```

**Description**

Sets the Y coordinate for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| int32_t displayY | Y coordinate on the screen.|

### OH_Input_SetMouseEventButton()

```
void OH_Input_SetMouseEventButton(struct Input_MouseEvent* mouseEvent, int32_t button)
```

**Description**

Sets the button for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| int32_t button | Mouse button.|

### OH_Input_SetMouseEventAxisType()

```
void OH_Input_SetMouseEventAxisType(struct Input_MouseEvent* mouseEvent, int32_t axisType)
```

**Description**

Sets the axis type for a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| int32_t axisType | Axis type, for example, X axis or Y axis.|

### OH_Input_SetMouseEventAxisValue()

```
void OH_Input_SetMouseEventAxisValue(struct Input_MouseEvent* mouseEvent, float axisValue)
```

**Description**

Sets the axis value for a mouse axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| float axisValue | Axis value. A positive value means scrolling forward, and a negative number means scrolling backward.|

### OH_Input_SetMouseEventActionTime()

```
void OH_Input_SetMouseEventActionTime(struct Input_MouseEvent* mouseEvent, int64_t actionTime)
```

**Description**

Sets the time when a mouse event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| int64_t actionTime | Time when a mouse event occurs.|

### OH_Input_SetMouseEventWindowId()

```
void OH_Input_SetMouseEventWindowId(struct Input_MouseEvent* mouseEvent, int32_t windowId)
```

**Description**

Sets the window ID of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| int32_t windowId | Window ID of the mouse event.|

### OH_Input_SetMouseEventDisplayId()

```
void OH_Input_SetMouseEventDisplayId(struct Input_MouseEvent* mouseEvent, int32_t displayId)
```

**Description**

Sets the screen ID of a mouse event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_MouseEvent](capi-input-mouseevent.md)* mouseEvent | Mouse event object.|
| int32_t displayId | Screen ID of the mouse event.|

### OH_Input_CreateTouchEvent()

```
struct Input_TouchEvent* OH_Input_CreateTouchEvent()
```

**Description**

Creates a touch event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| struct | [Input_TouchEvent](capi-input-touchevent.md) pointer object if the operation is successful; a null pointer otherwise.|

### OH_Input_DestroyTouchEvent()

```
void OH_Input_DestroyTouchEvent(struct Input_TouchEvent** touchEvent)
```

**Description**

Destroys a touch event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_TouchEvent](capi-input-touchevent.md)** touchEvent | Touch event object.|

### OH_Input_SetTouchEventAction()

```
void OH_Input_SetTouchEventAction(struct Input_TouchEvent* touchEvent, int32_t action)
```

**Description**

Sets the action for a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_TouchEvent](capi-input-touchevent.md)* touchEvent | Touch event object.|
| int32_t action | Action of the touch event.|

### OH_Input_SetTouchEventFingerId()

```
void OH_Input_SetTouchEventFingerId(struct Input_TouchEvent* touchEvent, int32_t id)
```

**Description**

Sets the finger ID for a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_TouchEvent](capi-input-touchevent.md)* touchEvent | Touch event object.|
| int32_t id | Finger ID of a touch event.|

### OH_Input_SetTouchEventDisplayX()

```
void OH_Input_SetTouchEventDisplayX(struct Input_TouchEvent* touchEvent, int32_t displayX)
```

**Description**

Sets the X coordinate for a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_TouchEvent](capi-input-touchevent.md)* touchEvent | Touch event object.|
| int32_t displayX | X coordinate on the touchscreen.|

### OH_Input_SetTouchEventDisplayY()

```
void OH_Input_SetTouchEventDisplayY(struct Input_TouchEvent* touchEvent, int32_t displayY)
```

**Description**

Sets the Y coordinate for a touch event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_TouchEvent](capi-input-touchevent.md)* touchEvent | Touch event object.|
| int32_t displayY | Y coordinate on the touchscreen.|

### OH_Input_SetTouchEventActionTime()

```
void OH_Input_SetTouchEventActionTime(struct Input_TouchEvent* touchEvent, int64_t actionTime)
```

**Description**

Sets the time when a touch event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| keyEvent | Touch event object.|
| int64_t actionTime | Time when a touch event occurs.|

### OH_Input_SetTouchEventWindowId()

```
void OH_Input_SetTouchEventWindowId(struct Input_TouchEvent* touchEvent, int32_t windowId)
```

**Description**

Sets the window ID of a touchscreen event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_TouchEvent](capi-input-touchevent.md)* touchEvent | Touch event object.|
| int32_t windowId | Window ID of the touchscreen event.|

### OH_Input_SetTouchEventDisplayId()

```
void OH_Input_SetTouchEventDisplayId(struct Input_TouchEvent* touchEvent, int32_t displayId)
```

**Description**

Sets the screen ID of a touchscreen event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| struct [Input_TouchEvent](capi-input-touchevent.md)* touchEvent | Touch event object.|
| int32_t displayId | Screen ID of the touchscreen event.|

### OH_Input_CancelInjection()

```
void OH_Input_CancelInjection()
```

**Description**

Stops event injection and revokes authorization.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

### OH_Input_CreateAxisEvent()

```
Input_AxisEvent* OH_Input_CreateAxisEvent(void)
```

**Description**

Creates an axis event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| Input_AxisEvent* | [Input_AxisEvent](capi-input-axisevent.md) object if the operation is successful; **null** otherwise.|

### OH_Input_DestroyAxisEvent()

```
Input_Result OH_Input_DestroyAxisEvent(Input_AxisEvent** axisEvent)
```

**Description**

Destroys an axis event object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)** axisEvent | Pointer to the axis event object.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_SetAxisEventAction()

```
Input_Result OH_Input_SetAxisEventAction(Input_AxisEvent* axisEvent, InputEvent_AxisAction action)
```

**Description**

Sets the action for an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| [InputEvent_AxisAction](capi-oh-axis-type-h.md#inputevent_axisaction) action | Axis event action. For details, see [InputEvent_AxisAction](capi-oh-axis-type-h.md#inputevent_axis).|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventAction()

```
Input_Result OH_Input_GetAxisEventAction(const Input_AxisEvent* axisEvent, InputEvent_AxisAction *action)
```

**Description**

Obtains the action of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| [InputEvent_AxisAction](capi-oh-axis-type-h.md#inputevent_axisaction) *action | Axis event action. For details, see [InputEvent_AxisAction](capi-oh-axis-type-h.md#inputevent_axisaction).|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **action** is null.|

### OH_Input_SetAxisEventDisplayX()

```
Input_Result OH_Input_SetAxisEventDisplayX(Input_AxisEvent* axisEvent, float displayX)
```

**Description**

Sets the X coordinate for an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| float displayX | X coordinate of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventDisplayX()

```
Input_Result OH_Input_GetAxisEventDisplayX(const Input_AxisEvent* axisEvent, float* displayX)
```

**Description**

Obtains the X coordinate of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| float* displayX | X coordinate of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **displayX** is null.|

### OH_Input_SetAxisEventDisplayY()

```
Input_Result OH_Input_SetAxisEventDisplayY(Input_AxisEvent* axisEvent, float displayY)
```

**Description**

Sets the Y coordinate for an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object. For details, see [Input_AxisEvent](capi-input-axisevent.md).|
| float displayY | Y coordinate of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventDisplayY()

```
Input_Result OH_Input_GetAxisEventDisplayY(const Input_AxisEvent* axisEvent, float* displayY)
```

**Description**

Obtains the Y coordinate of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object. For details, see [Input_AxisEvent](capi-input-axisevent.md).|
| float* displayY | Y coordinate of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **displayY** is null.|

### OH_Input_SetAxisEventAxisValue()

```
Input_Result OH_Input_SetAxisEventAxisValue(Input_AxisEvent* axisEvent,InputEvent_AxisType axisType, double axisValue)
```

**Description**

Sets the axis value of the axis type specified by the axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object. For details, see [Input_AxisEvent](capi-input-axisevent.md).|
| [InputEvent_AxisType](capi-oh-axis-type-h.md#inputevent_axistype) axisType | Axis type. For details, see [InputEvent_AxisType](capi-oh-axis-type-h.md#inputevent_axistype).|
| double axisValue | Axis event axis value.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventAxisValue()

```
Input_Result OH_Input_GetAxisEventAxisValue(const Input_AxisEvent* axisEvent,InputEvent_AxisType axisType, double* axisValue)
```

**Description**

Obtains the axis value for the specified axis type of the axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object. For details, see [Input_AxisEvent](capi-input-axisevent.md).|
| [InputEvent_AxisType](capi-oh-axis-type-h.md#inputevent_axistype) axisType | Axis type. For details, see [InputEvent_AxisType](capi-oh-axis-type-h.md#inputevent_axistype).|
| double* axisValue | Axis value of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **axisValue** is null.|

### OH_Input_SetAxisEventActionTime()

```
Input_Result OH_Input_SetAxisEventActionTime(Input_AxisEvent* axisEvent, int64_t actionTime)
```

**Description**

Sets the time when an axis event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object. For details, see [Input_AxisEvent](capi-input-axisevent.md).|
| int64_t actionTime | Time when an event occurs.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventActionTime()

```
Input_Result OH_Input_GetAxisEventActionTime(const Input_AxisEvent* axisEvent, int64_t* actionTime)
```

**Description**

Obtains the time when an axis event occurs.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object. For details, see [Input_AxisEvent](capi-input-axisevent.md).|
| int64_t* actionTime | Time when an axis event occurs.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **actionTime** is null.|

### OH_Input_SetAxisEventType()

```
Input_Result OH_Input_SetAxisEventType(Input_AxisEvent* axisEvent, InputEvent_AxisEventType axisEventType)
```

**Description**

Sets the axis event type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object. For details, see [Input_AxisEvent](capi-input-axisevent.md).|
| [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype) axisEventType | Axis event type. For details, see [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventType()

```
Input_Result OH_Input_GetAxisEventType(const Input_AxisEvent* axisEvent, InputEvent_AxisEventType* axisEventType)
```

**Description**

Obtains the axis event type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)* axisEventType | Axis event type. For details, see [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **axisEventType** is null.|

### OH_Input_SetAxisEventSourceType()

```
Input_Result OH_Input_SetAxisEventSourceType(Input_AxisEvent* axisEvent, InputEvent_SourceType sourceType)
```

**Description**

Sets the axis event source type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| [InputEvent_SourceType](#inputevent_sourcetype) sourceType | Axis event source type. For details, see [InputEvent_SourceType](#inputevent_sourcetype).|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventSourceType()

```
Input_Result OH_Input_GetAxisEventSourceType(const Input_AxisEvent* axisEvent, InputEvent_SourceType* sourceType)
```

**Description**

Obtains the axis event source type.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| [InputEvent_SourceType](#inputevent_sourcetype)* sourceType | Axis event source type. For details, see [InputEvent_SourceType](#inputevent_sourcetype).|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **sourceType** is null.|

### OH_Input_SetAxisEventWindowId()

```
Input_Result OH_Input_SetAxisEventWindowId(Input_AxisEvent* axisEvent, int32_t windowId)
```

**Description**

Sets the window ID of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| int32_t windowId | Window ID of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventWindowId()

```
Input_Result OH_Input_GetAxisEventWindowId(const Input_AxisEvent* axisEvent, int32_t* windowId)
```

**Description**

Obtains the window ID of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| int32_t* windowId | Window ID of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **windowId** is null.|

### OH_Input_SetAxisEventDisplayId()

```
Input_Result OH_Input_SetAxisEventDisplayId(Input_AxisEvent* axisEvent, int32_t displayId)
```

**Description**

Sets the screen ID of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| int32_t displayId | Screen ID of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** is null.|

### OH_Input_GetAxisEventDisplayId()

```
Input_Result OH_Input_GetAxisEventDisplayId(const Input_AxisEvent* axisEvent, int32_t* displayId)
```

**Description**

Obtains the screen ID of an axis event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_AxisEvent](capi-input-axisevent.md)* axisEvent | Axis event object.|
| int32_t* displayId | Screen ID of the axis event.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR] (#input_result) if **axisEvent** or **displayId** is null.|

### OH_Input_AddKeyEventMonitor()

```
Input_Result OH_Input_AddKeyEventMonitor(Input_KeyEventCallback callback)
```

**Description**

Adds a listener for key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_KeyEventCallback](#input_keyeventcallback) callback | Callback used to receive key events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR](#input_result) if the callback is empty; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_AddMouseEventMonitor()

```
Input_Result OH_Input_AddMouseEventMonitor(Input_MouseEventCallback callback)
```

**Description**

Adds a listener for mouse events, including mouse click and movement events, but not scroll wheel events. Scroll wheel events are axis events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_MouseEventCallback](#input_mouseeventcallback) callback | Callback used to receive mouse events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR](#input_result) if the callback is empty; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_AddTouchEventMonitor()

```
Input_Result OH_Input_AddTouchEventMonitor(Input_TouchEventCallback callback)
```

**Description**

Adds a listener for touch events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_TouchEventCallback](#input_toucheventcallback) callback | Callback used to receive touch events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR](#input_result) if the callback is empty; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_AddAxisEventMonitorForAll()

```
Input_Result OH_Input_AddAxisEventMonitorForAll(Input_AxisEventCallback callback)
```

**Description**

Adds a listener for all types of axis events, which are defined in [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEventCallback](#input_axiseventcallback) callback | Callback used to receive axis events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR](#input_result) if the callback is empty; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_AddAxisEventMonitor()

```
Input_Result OH_Input_AddAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback)
```

**Description**

Adds a listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype) axisEventType | Axis event type, which is defined in [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).|
| [Input_AxisEventCallback](#input_axiseventcallback) callback | Callback used to receive the specified type of axis events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR](#input_result) if the callback is empty; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_RemoveKeyEventMonitor()

```
Input_Result OH_Input_RemoveKeyEventMonitor(Input_KeyEventCallback callback)
```

**Description**

Removes the listener for key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_KeyEventCallback](#input_keyeventcallback) callback | Callback for key events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR] (#input_result) if the callback is empty or no listener is added; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_RemoveMouseEventMonitor()

```
Input_Result OH_Input_RemoveMouseEventMonitor(Input_MouseEventCallback callback)
```

**Description**

Removes the listener for mouse events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_MouseEventCallback](#input_mouseeventcallback) callback | Callback for mouse events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR] (#input_result) if the callback is empty or no listener is added; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_RemoveTouchEventMonitor()

```
Input_Result OH_Input_RemoveTouchEventMonitor(Input_TouchEventCallback callback)
```

**Description**

Removes the listener for touch events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_TouchEventCallback](#input_toucheventcallback) callback | Callback for touch events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR] (#input_result) if the callback is empty or no listener is added; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_RemoveAxisEventMonitorForAll()

```
Input_Result OH_Input_RemoveAxisEventMonitorForAll(Input_AxisEventCallback callback)
```

**Description**

Removes the listener for all types of axis events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_AxisEventCallback](#input_axiseventcallback) callback | Callback for the all types of axis events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR] (#input_result) if the callback is empty or no listener is added; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_RemoveAxisEventMonitor()

```
Input_Result OH_Input_RemoveAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback)
```

**Description**

Removes the listener for the specified type of axis events, which are defined in [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permissions**: ohos.permission.INPUT_MONITORING

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype) axisEventType | Axis event type, which is defined in [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype).|
| [Input_AxisEventCallback](#input_axiseventcallback) callback | Callback for the specified type of axis events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR] (#input_result) if the callback is empty or no listener is added; [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_AddKeyEventInterceptor()

```
Input_Result OH_Input_AddKeyEventInterceptor(Input_KeyEventCallback callback, Input_InterceptorOptions *option)
```

**Description**

Adds an interceptor for key events. If multiple interceptors are added, only the first one takes effect. Key events are intercepted only when the application gains focus.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permission**: ohos.permission.INTERCEPT_INPUT_EVENT

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_KeyEventCallback](#input_keyeventcallback) callback | Callback used to receive key events.|
| [Input_InterceptorOptions](capi-input-interceptoroptions.md) *option | Options for event interception. If **null** is passed, the default value is used.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR] (#input_result) if the callback is empty or no listener is added; [INPUT_REPEAT_INTERCEPTOR](#input_result) if an interceptor is repeatedly added;<br>         [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_AddInputEventInterceptor()

```
Input_Result OH_Input_AddInputEventInterceptor(Input_InterceptorEventCallback *callback,Input_InterceptorOptions *option)
```

**Description**

Adds an interceptor for input events, including mouse, touch, and axis events. If multiple interceptors are added, only the first one takes effect. Key events are intercepted only when the application window is hit.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permission**: ohos.permission.INTERCEPT_INPUT_EVENT

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_InterceptorEventCallback](capi-input-interceptoreventcallback.md) *callback | Pointer to the structure of the interceptor event callback. For details, see [Input_InterceptorEventCallback](capi-input-interceptoreventcallback.md).|
| [Input_InterceptorOptions](capi-input-interceptoroptions.md) *option | Options for event interception. If **null** is passed, the default value is used.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_PARAMETER_ERROR] (#input_result) if the callback is empty or no listener is added; [INPUT_REPEAT_INTERCEPTOR](#input_result) if an interceptor is repeatedly added;<br>         [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_RemoveKeyEventInterceptor()

```
Input_Result OH_Input_RemoveKeyEventInterceptor(void)
```

**Description**

Removes the interceptor for key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permission**: ohos.permission.INTERCEPT_INPUT_EVENT

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_SERVICE_EXCEPTION] (#input_result) if the service is abnormal.|

### OH_Input_RemoveInputEventInterceptor()

```
Input_Result OH_Input_RemoveInputEventInterceptor(void)
```

**Description**

Removes the interceptor for input events, including mouse, touch, and axis events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Required permission**: ohos.permission.INTERCEPT_INPUT_EVENT

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PERMISSION_DENIED](#input_result) if permission verification fails;<br>         [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_GetIntervalSinceLastInput()

```
Input_Result OH_Input_GetIntervalSinceLastInput(int64_t *timeInterval)
```

**Description**

Obtains the interval since the last system input event.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| int64_t *timeInterval | Interval, in microseconds.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | Status code of the **OH_Input_GetIntervalSinceLastInput** function,<br>         [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_SERVICE_EXCEPTION](#input_result) otherwise.|

### OH_Input_CreateHotkey()

```
Input_Hotkey *OH_Input_CreateHotkey(void)
```

**Description**

Creates a shortcut key object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14

**Return value**

| Type| Description|
| -- | -- |
| [Input_Hotkey](capi-input-hotkey.md) | [Input_Hotkey](capi-input-hotkey.md) pointer if the operation is successful; a null pointer otherwise (possibly because of a memory allocation failure).|

### OH_Input_DestroyHotkey()

```
void OH_Input_DestroyHotkey(Input_Hotkey **hotkey)
```

**Description**

Destroys a shortcut key object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_Hotkey](capi-input-hotkey.md) **hotkey | Shortcut key object.|

### OH_Input_SetPreKeys()

```
void OH_Input_SetPreKeys(Input_Hotkey *hotkey, int32_t *preKeys, int32_t size)
```

**Description**

Sets the modifier keys.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_Hotkey](capi-input-hotkey.md) *hotkey | Shortcut key object.|
| int32_t *preKeys | List of modifier keys.|
| int32_t size | Number of modifier keys. One or two modifier keys are supported.|

### OH_Input_GetPreKeys()

```
Input_Result OH_Input_GetPreKeys(const Input_Hotkey *hotkey, int32_t **preKeys, int32_t *preKeyCount)
```

**Description**

Obtains the modifier key.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_Hotkey](capi-input-hotkey.md) *hotkey | Shortcut key object.|
| int32_t **preKeys | List of modifier keys.|
| int32_t *preKeyCount | Number of modifier keys.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | Status code of the **OH_Input_GetpressedKeys** function, which is<br>         [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR](#input_result) otherwise.|

### OH_Input_SetFinalKey()

```
void OH_Input_SetFinalKey(Input_Hotkey* hotkey, int32_t finalKey)
```

**Description**

Sets the modified key.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_Hotkey](capi-input-hotkey.md)* hotkey | Shortcut key object.|
| int32_t finalKey | Modifier key value. Only one modifier key value is allowed.|

### OH_Input_GetFinalKey()

```
Input_Result OH_Input_GetFinalKey(const Input_Hotkey* hotkey, int32_t *finalKeyCode)
```

**Description**

Obtains the modified key.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_Hotkey](capi-input-hotkey.md)* hotkey | Shortcut key object.|
| int32_t *finalKeyCode | Modified key.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | Status code of the **OH_Input_GetfinalKey** function, which is<br>         [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) otherwise.|

### OH_Input_CreateAllSystemHotkeys()

```
Input_Hotkey **OH_Input_CreateAllSystemHotkeys(int32_t count)
```

**Description**

Creates an array of [Input_Hotkey](capi-input-hotkey.md) instances.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t count | Number of [Input_Hotkey](capi-input-hotkey.md) instances.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Hotkey](capi-input-hotkey.md) | OH_Input_CreateAllSystemHotkey status code,<br>         which is [INPUT_SUCCESS](#input_result) if the operation is successful.|

### OH_Input_DestroyAllSystemHotkeys()

```
void OH_Input_DestroyAllSystemHotkeys(Input_Hotkey **hotkeys, int32_t count)
```

**Description**

Destroys the array of [Input_Hotkey](capi-input-hotkey.md) instances and reclaims the memory.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_Hotkey](capi-input-hotkey.md) **hotkeys | Double pointer to the array of [Input_Hotkey](capi-input-hotkey.md) instances.|
| int32_t count | Number of [Input_Hotkey](capi-input-hotkey.md) instances.|

### OH_Input_GetAllSystemHotkeys()

```
Input_Result OH_Input_GetAllSystemHotkeys(Input_Hotkey **hotkey, int32_t *count)
```

**Description**

Obtains all configured shortcut keys.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_Hotkey](capi-input-hotkey.md) **hotkey | Array of [Input_Hotkey](capi-input-hotkey.md) instances. When calling this API for the first time, you can pass **NULL** to obtain the array length.|
| int32_t *count | Number of supported shortcut keys.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | Status code of the **OH_Input_GetAllSystemHotkeys** function, which is<br>         [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) otherwise.|

### OH_Input_SetRepeat()

```
void OH_Input_SetRepeat(Input_Hotkey* hotkey, bool isRepeat)
```

**Description**

Specifies whether to report repeated key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_Hotkey](capi-input-hotkey.md)* hotkey | Shortcut key object.|
| bool isRepeat | Whether to report repeated key events. The value **true** means to report repeated key events, and the value **false** means the opposite.|

### OH_Input_GetRepeat()

```
Input_Result OH_Input_GetRepeat(const Input_Hotkey* hotkey, bool *isRepeat)
```

**Description**

Checks whether to report repeated key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_Hotkey](capi-input-hotkey.md)* hotkey | Shortcut key object.|
| bool *isRepeat | Whether the reported key event is repeated.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | OH_Input_GetIsRepeat status code, specifically,<br>         [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) otherwise.|

### OH_Input_AddHotkeyMonitor()

```
Input_Result OH_Input_AddHotkeyMonitor(const Input_Hotkey* hotkey, Input_HotkeyCallback callback)
```

**Description**

Subscribes to shortcut key events. This API is not applicable to wearables and lite wearables.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_Hotkey](capi-input-hotkey.md)* hotkey | Shortcut key object.|
| [Input_HotkeyCallback](#input_hotkeycallback) callback | Defines the callback used to return shortcut key events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | OH_Input_AddHotkeyMonitor status code, specifically,<br>         [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if parameter verification fails;<br>         [INPUT_OCCUPIED_BY_SYSTEM](#input_result) if the shortcut key has been occupied by the system (you can use [OH_Input_GetAllSystemHotkeys](#oh_input_getallsystemhotkeys) to query allsystem shortcut keys);<br>         [INPUT_OCCUPIED_BY_OTHER](#input_result) if the shortcut key has been occupied by another application;<br>         [INPUT_DEVICE_NOT_SUPPORTED](#input_result) if the function is not supported.|

### OH_Input_RemoveHotkeyMonitor()

```
Input_Result OH_Input_RemoveHotkeyMonitor(const Input_Hotkey* hotkey, Input_HotkeyCallback callback)
```

**Description**

Unsubscribes from shortcut key events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| const [Input_Hotkey](capi-input-hotkey.md)* hotkey | Shortcut key object.|
| [Input_HotkeyCallback](#input_hotkeycallback) callback | Defines the callback used to return shortcut key events.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | OH_Input_RemoveHotkeyMonitor status code, specifically,<br>         [INPUT_SUCCESS](#input_result) if the operation is successful; [INPUT_PARAMETER_ERROR](#input_result) if parameter verification fails.|

### OH_Input_RegisterDeviceListener()

```
Input_Result OH_Input_RegisterDeviceListener(Input_DeviceListener* listener)
```

**Description**

Registers a listener for device hot swap events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceListener](capi-input-devicelistener.md)* listener | Pointer to the [Input_DeviceListener](capi-input-devicelistener.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | **OH_Input_RegisterDeviceListener** status code, specifically:<br>         [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if the listener is null.|

### OH_Input_UnregisterDeviceListener()

```
Input_Result OH_Input_UnregisterDeviceListener(Input_DeviceListener* listener)
```

**Description**

Unregisters the listener for device hot swap events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceListener](capi-input-devicelistener.md)* listener | Pointer to the [Input_DeviceListener](capi-input-devicelistener.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | **OH_Input_UnregisterDeviceListener** status code, specifically:<br>         [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **listener** is **NULL** or the listener is not registered;<br>         [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_UnregisterDeviceListeners()

```
Input_Result OH_Input_UnregisterDeviceListeners()
```

**Description**

Unregisters the listener for all device hot swap events.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | **OH_Input_UnregisterDeviceListener** status code, specifically:<br>         [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_SERVICE_EXCEPTION](#input_result) if the service is abnormal.|

### OH_Input_GetDeviceIds()

```
Input_Result OH_Input_GetDeviceIds(int32_t *deviceIds, int32_t inSize, int32_t *outSize)
```

**Description**

Obtains the IDs of all input devices.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t *deviceIds | List of input device IDs.|
| int32_t inSize | Size of the input device ID list.|
| int32_t *outSize | Length of the input device ID list. The value must be less than or equal to the value of **inSize**.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceIds** or **outSize** is a null pointer or **inSize** is less than **0**.|

### OH_Input_GetDevice()

```
Input_Result OH_Input_GetDevice(int32_t deviceId, Input_DeviceInfo **deviceInfo)
```

**Description**

Obtains information about the input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t deviceId | Device ID.|
| [Input_DeviceInfo](capi-input-deviceinfo.md) **deviceInfo | Pointer to the [Input_DeviceInfo](capi-input-deviceinfo.md) object.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceInfo** is a null pointer or **deviceId** is invalid.<br> You can use [OH_Input_GetDeviceIds](#oh_input_getdeviceids) to query the device IDs supported by the system.|

### OH_Input_CreateDeviceInfo()

```
Input_DeviceInfo* OH_Input_CreateDeviceInfo(void)
```

**Description**

Creates a **deviceInfo** object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13

**Return value**

| Type| Description|
| -- | -- |
| Input_DeviceInfo* | Pointer to the [Input_DeviceInfo](capi-input-deviceinfo.md) object if the operation is successful; a null pointer otherwise (possibly because of a memory allocation failure).|

### OH_Input_DestroyDeviceInfo()

```
void OH_Input_DestroyDeviceInfo(Input_DeviceInfo **deviceInfo)
```

**Description**

Destroys a **deviceInfo** object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceInfo](capi-input-deviceinfo.md) **deviceInfo | **deviceInfo** object.|

### OH_Input_GetKeyboardType()

```
Input_Result OH_Input_GetKeyboardType(int32_t deviceId, int32_t *keyboardType)
```

**Description**

Obtains the keyboard type of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t deviceId | Device ID.|
| int32_t *keyboardType | Pointer to the keyboard type of the input device.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if the device ID is invalid or **keyboardType** is a null pointer.|

### OH_Input_GetDeviceId()

```
Input_Result OH_Input_GetDeviceId(Input_DeviceInfo *deviceInfo, int32_t *id)
```

**Description**

Obtains the ID of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceInfo](capi-input-deviceinfo.md) *deviceInfo | Input device information. For details, see [Input_DeviceInfo](capi-input-deviceinfo.md).|
| int32_t *id | Pointer to the input device ID.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceInfo** or **id** is a null pointer.|

### OH_Input_GetDeviceName()

```
Input_Result OH_Input_GetDeviceName(Input_DeviceInfo *deviceInfo, char **name)
```

**Description**

Obtains the name of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceInfo](capi-input-deviceinfo.md) *deviceInfo | Input device information. For details, see [Input_DeviceInfo](capi-input-deviceinfo.md).|
| char **name | Pointer to the input device name.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceInfo** or **name** is a null pointer.|

### OH_Input_GetCapabilities()

```
Input_Result OH_Input_GetCapabilities(Input_DeviceInfo *deviceInfo, int32_t *capabilities)
```

**Description**

Obtains the capabilities of an input device, for example, a touchscreen, touchpad, or keyboard.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceInfo](capi-input-deviceinfo.md) *deviceInfo | Input device information. For details, see [Input_DeviceInfo](capi-input-deviceinfo.md).|
| int32_t *capabilities | Pointer to the capability information of the input device.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceInfo** or **capabilities** is a null pointer.|

### OH_Input_GetDeviceVersion()

```
Input_Result OH_Input_GetDeviceVersion(Input_DeviceInfo *deviceInfo, int32_t *version)
```

**Description**

Obtains the version information of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceInfo](capi-input-deviceinfo.md) *deviceInfo | Input device information. For details, see [Input_DeviceInfo](capi-input-deviceinfo.md).|
| int32_t *version | Pointer to the version information of the input device.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceInfo** or **version** is a null pointer.|

### OH_Input_GetDeviceProduct()

```
Input_Result OH_Input_GetDeviceProduct(Input_DeviceInfo *deviceInfo, int32_t *product)
```

**Description**

Obtains the product information of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceInfo](capi-input-deviceinfo.md) *deviceInfo | Input device information. For details, see [Input_DeviceInfo](capi-input-deviceinfo.md).|
| int32_t *product | Pointer to the product information of the input device.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceInfo** or **product** is a null pointer.|

### OH_Input_GetDeviceVendor()

```
Input_Result OH_Input_GetDeviceVendor(Input_DeviceInfo *deviceInfo, int32_t *vendor)
```

**Description**

Obtains the vendor information of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceInfo](capi-input-deviceinfo.md) *deviceInfo | Input device information. For details, see [Input_DeviceInfo](capi-input-deviceinfo.md).|
| int32_t *vendor | Pointer to the vendor information of the input device.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceInfo** or **vendor** is a null pointer.|

### OH_Input_GetDeviceAddress()

```
Input_Result OH_Input_GetDeviceAddress(Input_DeviceInfo *deviceInfo, char **address)
```

**Description**

Obtains the physical address of an input device.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_DeviceInfo](capi-input-deviceinfo.md) *deviceInfo | Input device information. For details, see [Input_DeviceInfo](capi-input-deviceinfo.md).|
| char **address | Pointer to the physical address of the input device.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if **deviceInfo** or **address** is a null pointer.|

### OH_Input_GetFunctionKeyState()

```
Input_Result OH_Input_GetFunctionKeyState(int32_t keyCode, int32_t *state)
```

**Description**

Obtains the function key status.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t keyCode | Function key. Only the **CapsLock** key is supported.|
| int32_t *state | Function key status. The value **0** indicates that the function key is disabled, and the value **1** indicates that the function key is enabled.|

**Return value**

| Type| Description|
| -- | -- |
| [Input_Result](#input_result) | **OH_Input_GetFunctionKeyState** status code, specifically:<br>         [INPUT_SUCCESS](#input_result) if the operation is successful;<br>         [INPUT_PARAMETER_ERROR](#input_result) if the parameter is incorrect;<br>         {@link INPUT_DEVICE_NOT_EXIST } if the keyboard does not exist.|
