# oh_input_manager.h


## 概述

提供事件注入和关键状态查询等功能。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**库：** libohinput.so

**起始版本：** 12

**相关模块：**[Input](input.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Input_InterceptorEventCallback](_input___interceptor_event_callback.md) | 拦截回调事件结构体，拦截鼠标事件、触摸事件和轴事件。  | 
| struct&nbsp;&nbsp;[Input_DeviceListener](_input___device_listener.md) | 定义一个结构体用于监听设备热插拔。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Input_KeyStateAction](input.md#input_keystateaction) [Input_KeyStateAction](input.md#input_keystateaction) | 按键状态的枚举值。  | 
| typedef enum [Input_KeyEventAction](input.md#input_keyeventaction) [Input_KeyEventAction](input.md#input_keyeventaction) | 按键事件类型的枚举值。  | 
| typedef enum [Input_MouseEventAction](input.md#input_mouseeventaction) [Input_MouseEventAction](input.md#input_mouseeventaction) | 鼠标动作的枚举值。  | 
| typedef enum [InputEvent_MouseAxis](input.md#inputevent_mouseaxis) [InputEvent_MouseAxis](input.md#inputevent_mouseaxis) | 鼠标轴事件类型。  | 
| typedef enum [Input_MouseEventButton](input.md#input_mouseeventbutton) [Input_MouseEventButton](input.md#input_mouseeventbutton) | 鼠标按键的枚举值。  | 
| typedef enum [Input_TouchEventAction](input.md#input_toucheventaction) [Input_TouchEventAction](input.md#input_toucheventaction) | 触摸动作的枚举值。  | 
| typedef enum [InputEvent_SourceType](input.md#inputevent_sourcetype) [InputEvent_SourceType](input.md#inputevent_sourcetype) | 输入事件源类型。  | 
| typedef enum [Input_KeyboardType](input.md#input_keyboardtype) [Input_KeyboardType](input.md#input_keyboardtype) | 输入设备的键盘类型。  | 
| typedef struct [Input_KeyState](input.md#input_keystate) [Input_KeyState](input.md#input_keystate) | 定义按键信息，用于标识按键行为。例如，“Ctrl”按键信息包含键值和键类型。  | 
| typedef struct [Input_KeyEvent](input.md#input_keyevent) [Input_KeyEvent](input.md#input_keyevent) | 要注入的按键事件。  | 
| typedef struct [Input_MouseEvent](input.md#input_mouseevent) [Input_MouseEvent](input.md#input_mouseevent) | 要注入的鼠标事件。  | 
| typedef struct [Input_TouchEvent](input.md#input_touchevent) [Input_TouchEvent](input.md#input_touchevent) | 要注入的触摸事件。  | 
| typedef struct [Input_AxisEvent](input.md#input_axisevent) [Input_AxisEvent](input.md#input_axisevent) | 轴事件。  | 
| typedef enum [Input_Result](input.md#input_result) [Input_Result](input.md#input_result) | 错误码枚举值。  | 
| typedef void(\* [Input_KeyEventCallback](input.md#input_keyeventcallback)) (const [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | 按键事件的回调函数，keyEvent的生命周期为回调函数内。  | 
| typedef void(\* [Input_MouseEventCallback](input.md#input_mouseeventcallback)) (const [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 鼠标事件的回调函数，mouseEvent的生命周期为回调函数内。  | 
| typedef void(\* [Input_TouchEventCallback](input.md#input_toucheventcallback)) (const [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | 触摸事件的回调函数，touchEvent的生命周期为回调函数内。  | 
| typedef void(\* [Input_AxisEventCallback](input.md#input_axiseventcallback)) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent) | 轴事件的回调函数，axisEvent的生命周期为回调函数内。  | 
| typedef void(\* [Input_HotkeyCallback](input.md#input_hotkeycallback)) ([Input_Hotkey](input.md#input_hotkey) \*hotkey) | 回调函数，用于回调快捷键事件。  |
| typedef void(\* [Input_DeviceAddedCallback](input.md#input_deviceaddedcallback)) (int32_t deviceId) | 回调函数，用于回调输入设备的热插事件。  | 
| typedef void(\* [Input_DeviceRemovedCallback](input.md#input_deviceremovedcallback)) (int32_t deviceId) | 回调函数，用于回调输入设备的热拔事件。  | 
| typedef struct [Input_InterceptorEventCallback](_input___interceptor_event_callback.md) [Input_InterceptorEventCallback](input.md#input_interceptoreventcallback) | 拦截回调事件结构体，拦截鼠标事件、触摸事件和轴事件。  | 
| typedef struct [Input_DeviceListener](_input___device_listener.md) [Input_DeviceListener](input.md#input_devicelistener) | 定义一个结构体用于监听设备热插拔。  | 
| typedef struct [Input_InterceptorOptions](input.md#input_interceptoroptions) [Input_InterceptorOptions](input.md#input_interceptoroptions) | 事件拦截选项。  | 
| typedef struct [Input_Hotkey](input.md#input_hotkey) [Input_Hotkey](input.md#input_hotkey) | 定义快捷键结构体。  | 
| typedef struct [Input_DeviceInfo](input.md#input_deviceinfo) [Input_DeviceInfo](input.md#input_deviceinfo) | 输入设备信息。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Input_KeyStateAction](input.md#input_keystateaction) {<br/>[KEY_DEFAULT](input.md) = -1, [KEY_PRESSED](input.md) = 0, [KEY_RELEASED](input.md) = 1, [KEY_SWITCH_ON](input.md) = 2,<br/>[KEY_SWITCH_OFF](input.md) = 3<br/>} | 按键状态的枚举值。  | 
| [Input_KeyEventAction](input.md#input_keyeventaction) { [KEY_ACTION_CANCEL](input.md) = 0, [KEY_ACTION_DOWN](input.md) = 1, [KEY_ACTION_UP](input.md) = 2 } | 按键事件类型的枚举值。  | 
| [Input_MouseEventAction](input.md#input_mouseeventaction) {<br/>[MOUSE_ACTION_CANCEL](input.md) = 0, [MOUSE_ACTION_MOVE](input.md) = 1, [MOUSE_ACTION_BUTTON_DOWN](input.md) = 2, [MOUSE_ACTION_BUTTON_UP](input.md) = 3,<br/>[MOUSE_ACTION_AXIS_BEGIN](input.md) = 4, [MOUSE_ACTION_AXIS_UPDATE](input.md) = 5, [MOUSE_ACTION_AXIS_END](input.md) = 6<br/>} | 鼠标动作的枚举值。  | 
| [InputEvent_MouseAxis](input.md#inputevent_mouseaxis) { [MOUSE_AXIS_SCROLL_VERTICAL](input.md) = 0, [MOUSE_AXIS_SCROLL_HORIZONTAL](input.md) = 1 } | 鼠标轴事件类型。  | 
| [Input_MouseEventButton](input.md#input_mouseeventbutton) {<br/>[MOUSE_BUTTON_NONE](input.md) = -1, [MOUSE_BUTTON_LEFT](input.md) = 0, [MOUSE_BUTTON_MIDDLE](input.md) = 1, [MOUSE_BUTTON_RIGHT](input.md) = 2,<br/>[MOUSE_BUTTON_FORWARD](input.md) = 3, [MOUSE_BUTTON_BACK](input.md) = 4<br/>} | 鼠标按键的枚举值。  | 
| [Input_TouchEventAction](input.md#input_toucheventaction) { [TOUCH_ACTION_CANCEL](input.md) = 0, [TOUCH_ACTION_DOWN](input.md) = 1, [TOUCH_ACTION_MOVE](input.md) = 2, [TOUCH_ACTION_UP](input.md) = 3 } | 触摸动作的枚举值。  | 
| [InputEvent_SourceType](input.md#inputevent_sourcetype) { [SOURCE_TYPE_MOUSE](input.md) = 1, [SOURCE_TYPE_TOUCHSCREEN](input.md) = 2, [SOURCE_TYPE_TOUCHPAD](input.md) = 3 } | 输入事件源类型。  | 
| [Input_KeyboardType](input.md#input_keyboardtype) {<br/>[KEYBOARD_TYPE_NONE](input.md) = 0, [KEYBOARD_TYPE_UNKNOWN](input.md) = 1, [KEYBOARD_TYPE_ALPHABETIC](input.md) = 2, [KEYBOARD_TYPE_DIGITAL](input.md) = 3,<br/>[KEYBOARD_TYPE_STYLUS](input.md) = 4, [KEYBOARD_TYPE_REMOTE_CONTROL](input.md) = 5<br/>} | 输入设备的键盘类型。  | 
| [Input_Result](input.md#input_result) {<br/>[INPUT_SUCCESS](input.md) = 0, [INPUT_PERMISSION_DENIED](input.md) = 201, [INPUT_NOT_SYSTEM_APPLICATION](input.md) = 202, [INPUT_PARAMETER_ERROR](input.md) = 401,<br/>[INPUT_SERVICE_EXCEPTION](input.md) = 3800001, [INPUT_REPEAT_INTERCEPTOR](input.md) = 4200001, [INPUT_OCCUPIED_BY_SYSTEM](input.md) = 4200002, [INPUT_OCCUPIED_BY_OTHER](input.md) = 4200003<br/>} | 错误码枚举值。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Input_Result](input.md#input_result) [OH_Input_GetKeyState](input.md#oh_input_getkeystate) (struct [Input_KeyState](input.md#input_keystate) \*keyState) | 查询按键状态的枚举对象。  | 
| struct [Input_KeyState](input.md#input_keystate) \* [OH_Input_CreateKeyState](input.md#oh_input_createkeystate) () | 创建按键状态的枚举对象。  | 
| void [OH_Input_DestroyKeyState](input.md#oh_input_destroykeystate) (struct [Input_KeyState](input.md#input_keystate) \*\*keyState) | 销毁按键状态的枚举对象。  | 
| void [OH_Input_SetKeyCode](input.md#oh_input_setkeycode) (struct [Input_KeyState](input.md#input_keystate) \*keyState, int32_t keyCode) | 设置按键状态对象的键值。  | 
| int32_t [OH_Input_GetKeyCode](input.md#oh_input_getkeycode) (const struct [Input_KeyState](input.md#input_keystate) \*keyState) | 获取按键状态对象的键值。  | 
| void [OH_Input_SetKeyPressed](input.md#oh_input_setkeypressed) (struct [Input_KeyState](input.md#input_keystate) \*keyState, int32_t keyAction) | 设置按键状态对象的按键是否按下。  | 
| int32_t [OH_Input_GetKeyPressed](input.md#oh_input_getkeypressed) (const struct [Input_KeyState](input.md#input_keystate) \*keyState) | 获取按键状态对象的按键是否按下。  | 
| void [OH_Input_SetKeySwitch](input.md#oh_input_setkeyswitch) (struct [Input_KeyState](input.md#input_keystate) \*keyState, int32_t keySwitch) | 设置按键状态对象的按键开关。  | 
| int32_t [OH_Input_GetKeySwitch](input.md#oh_input_getkeyswitch) (const struct [Input_KeyState](input.md#input_keystate) \*keyState) | 获取按键状态对象的按键开关。  | 
| int32_t [OH_Input_InjectKeyEvent](input.md#oh_input_injectkeyevent) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | 注入按键事件。  | 
| struct [Input_KeyEvent](input.md#input_keyevent) \* [OH_Input_CreateKeyEvent](input.md#oh_input_createkeyevent) () | 创建按键事件对象。  | 
| void [OH_Input_DestroyKeyEvent](input.md#oh_input_destroykeyevent) (struct [Input_KeyEvent](input.md#input_keyevent) \*\*keyEvent) | 销毁按键事件对象。  | 
| void [OH_Input_SetKeyEventAction](input.md#oh_input_setkeyeventaction) (struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent, int32_t action) | 设置按键事件类型。  | 
| int32_t [OH_Input_GetKeyEventAction](input.md#oh_input_getkeyeventaction) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | 获取按键事件类型。  | 
| void [OH_Input_SetKeyEventKeyCode](input.md#oh_input_setkeyeventkeycode) (struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent, int32_t keyCode) | 设置按键事件的键值。  | 
| int32_t [OH_Input_GetKeyEventKeyCode](input.md#oh_input_getkeyeventkeycode) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | 获取按键事件的键值。  | 
| void [OH_Input_SetKeyEventActionTime](input.md#oh_input_setkeyeventactiontime) (struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent, int64_t actionTime) | 设置按键事件发生的时间。  | 
| int64_t [OH_Input_GetKeyEventActionTime](input.md#oh_input_getkeyeventactiontime) (const struct [Input_KeyEvent](input.md#input_keyevent) \*keyEvent) | 获取按键事件发生的时间。  | 
| int32_t [OH_Input_InjectMouseEvent](input.md#oh_input_injectmouseevent) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 注入鼠标事件。  | 
| struct [Input_MouseEvent](input.md#input_mouseevent) \* [OH_Input_CreateMouseEvent](input.md#oh_input_createmouseevent) () | 创建鼠标事件对象。  | 
| void [OH_Input_DestroyMouseEvent](input.md#oh_input_destroymouseevent) (struct [Input_MouseEvent](input.md#input_mouseevent) \*\*mouseEvent) | 销毁鼠标事件对象。  | 
| void [OH_Input_SetMouseEventAction](input.md#oh_input_setmouseeventaction) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t action) | 设置鼠标事件的动作。  | 
| int32_t [OH_Input_GetMouseEventAction](input.md#oh_input_getmouseeventaction) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 获取鼠标事件的动作。  | 
| void [OH_Input_SetMouseEventDisplayX](input.md#oh_input_setmouseeventdisplayx) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t displayX) | 设置鼠标事件的屏幕X坐标。  | 
| int32_t [OH_Input_GetMouseEventDisplayX](input.md#oh_input_getmouseeventdisplayx) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 获取鼠标事件的屏幕X坐标。 | 
| void [OH_Input_SetMouseEventDisplayY](input.md#oh_input_setmouseeventdisplayy) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t displayY) | 设置鼠标事件的屏幕Y坐标。  | 
| int32_t [OH_Input_GetMouseEventDisplayY](input.md#oh_input_getmouseeventdisplayy) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 获取鼠标事件的屏幕Y坐标。  | 
| void [OH_Input_SetMouseEventButton](input.md#oh_input_setmouseeventbutton) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t button) | 设置鼠标事件的按键。  | 
| int32_t [OH_Input_GetMouseEventButton](input.md#oh_input_getmouseeventbutton) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 获取鼠标事件的按键。  | 
| void [OH_Input_SetMouseEventAxisType](input.md#oh_input_setmouseeventaxistype) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int32_t axisType) | 设置鼠标轴事件的类型。  | 
| int32_t [OH_Input_GetMouseEventAxisType](input.md#oh_input_getmouseeventaxistype) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 获取鼠标轴事件的类型。  | 
| void [OH_Input_SetMouseEventAxisValue](input.md#oh_input_setmouseeventaxisvalue) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, float axisValue) | 设置鼠标轴事件的值。  | 
| float [OH_Input_GetMouseEventAxisValue](input.md#oh_input_getmouseeventaxisvalue) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 获取鼠标轴事件的值。  | 
| void [OH_Input_SetMouseEventActionTime](input.md#oh_input_setmouseeventactiontime) (struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent, int64_t actionTime) | 设置鼠标事件发生的时间。 | 
| int64_t [OH_Input_GetMouseEventActionTime](input.md#oh_input_getmouseeventactiontime) (const struct [Input_MouseEvent](input.md#input_mouseevent) \*mouseEvent) | 获取鼠标事件发生的时间。  | 
| int32_t [OH_Input_InjectTouchEvent](input.md#oh_input_injecttouchevent) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | 注入触摸事件。  | 
| struct [Input_TouchEvent](input.md#input_touchevent) \* [OH_Input_CreateTouchEvent](input.md#oh_input_createtouchevent) () | 创建触屏事件对象。  | 
| void [OH_Input_DestroyTouchEvent](input.md#oh_input_destroytouchevent) (struct [Input_TouchEvent](input.md#input_touchevent) \*\*touchEvent) | 销毁触屏事件对象。  | 
| void [OH_Input_SetTouchEventAction](input.md#oh_input_settoucheventaction) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t action) | 设置触屏事件的动作。  | 
| int32_t [OH_Input_GetTouchEventAction](input.md#oh_input_gettoucheventaction) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | 获取触屏事件的动作。  | 
| void [OH_Input_SetTouchEventFingerId](input.md#oh_input_settoucheventfingerid) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t id) | 设置触屏事件的手指ID。  | 
| int32_t [OH_Input_GetTouchEventFingerId](input.md#oh_input_gettoucheventfingerid) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | 获取触屏事件的手指ID。  | 
| void [OH_Input_SetTouchEventDisplayX](input.md#oh_input_settoucheventdisplayx) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t displayX) | 设置触屏事件的屏幕X坐标。  | 
| int32_t [OH_Input_GetTouchEventDisplayX](input.md#oh_input_gettoucheventdisplayx) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | 获取触屏事件的屏幕X坐标。  | 
| void [OH_Input_SetTouchEventDisplayY](input.md#oh_input_settoucheventdisplayy) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int32_t displayY) | 设置触屏事件的屏幕Y坐标。  | 
| int32_t [OH_Input_GetTouchEventDisplayY](input.md#oh_input_gettoucheventdisplayy) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | 获取触屏事件的屏幕Y坐标。  | 
| void [OH_Input_SetTouchEventActionTime](input.md#oh_input_settoucheventactiontime) (struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent, int64_t actionTime) | 设置触摸事件发生的时间。  | 
| int64_t [OH_Input_GetTouchEventActionTime](input.md#oh_input_gettoucheventactiontime) (const struct [Input_TouchEvent](input.md#input_touchevent) \*touchEvent) | 获取触摸事件发生的时间。  | 
| void [OH_Input_CancelInjection](input.md#oh_input_cancelinjection) () | 取消事件注入并撤销授权。  | 
| [Input_AxisEvent](input.md#input_axisevent) \* [OH_Input_CreateAxisEvent](input.md#oh_input_createaxisevent) (void) | 创建轴事件对象实例。  | 
| [Input_Result](input.md#input_result) [OH_Input_DestroyAxisEvent](input.md#oh_input_destroyaxisevent) ([Input_AxisEvent](input.md#input_axisevent) \*\*axisEvent) | 销毁轴事件对象实例。  | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventAction](input.md#oh_input_setaxiseventaction) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisAction](input.md#inputevent_axisaction) action) | 设置轴事件的动作。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventAction](input.md#oh_input_getaxiseventaction) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisAction](input.md#inputevent_axisaction) \*action) | 获取轴事件的动作。  | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventDisplayX](input.md#oh_input_setaxiseventdisplayx) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, float displayX) | 设置轴事件的X坐标。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventDisplayX](input.md#oh_input_getaxiseventdisplayx) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, float \*displayX) | 获取轴事件的X坐标。  | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventDisplayY](input.md#oh_input_setaxiseventdisplayy) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, float displayY) | 设置轴事件的Y坐标。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventDisplayY](input.md#oh_input_getaxiseventdisplayy) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, float \*displayY) | 获取轴事件的Y坐标。  | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventAxisValue](input.md#oh_input_setaxiseventaxisvalue) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisType](input.md#inputevent_axistype) axisType, double axisValue) | 设置轴事件指定轴类型的轴值。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventAxisValue](input.md#oh_input_getaxiseventaxisvalue) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisType](input.md#inputevent_axistype) axisType, double \*axisValue) | 获取轴事件指定轴类型的轴值。  | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventActionTime](input.md#oh_input_setaxiseventactiontime) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, int64_t actionTime) | 设置轴事件发生的时间。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventActionTime](input.md#oh_input_getaxiseventactiontime) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, int64_t \*actionTime) | 获取轴事件发生的时间。  | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventType](input.md#oh_input_setaxiseventtype) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) axisEventType) | 设置轴事件类型。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventType](input.md#oh_input_getaxiseventtype) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) \*axisEventType) | 获取轴事件类型。  | 
| [Input_Result](input.md#input_result) [OH_Input_SetAxisEventSourceType](input.md#oh_input_setaxiseventsourcetype) ([Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_SourceType](input.md#inputevent_sourcetype) sourceType) | 设置轴事件源类型。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetAxisEventSourceType](input.md#oh_input_getaxiseventsourcetype) (const [Input_AxisEvent](input.md#input_axisevent) \*axisEvent, [InputEvent_SourceType](input.md#inputevent_sourcetype) \*sourceType) | 获取轴事件源类型。  | 
| [Input_Result](input.md#input_result) [OH_Input_AddKeyEventMonitor](input.md#oh_input_addkeyeventmonitor) ([Input_KeyEventCallback](input.md#input_keyeventcallback) callback) | 添加按键事件监听。  | 
| [Input_Result](input.md#input_result) [OH_Input_AddMouseEventMonitor](input.md#oh_input_addmouseeventmonitor) ([Input_MouseEventCallback](input.md#input_mouseeventcallback) callback) | 添加鼠标事件监听,包含鼠标点击，移动，不包含滚轮事件，滚轮事件归属于轴事件。  | 
| [Input_Result](input.md#input_result) [OH_Input_AddTouchEventMonitor](input.md#oh_input_addtoucheventmonitor) ([Input_TouchEventCallback](input.md#input_toucheventcallback) callback) | 添加触摸事件监听。  | 
| [Input_Result](input.md#input_result) [OH_Input_AddAxisEventMonitorForAll](input.md#oh_input_addaxiseventmonitorforall) ([Input_AxisEventCallback](input.md#input_axiseventcallback) callback) | 添加所有类型轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](input.md#inputevent_axiseventtype)中。  | 
| [Input_Result](input.md#input_result) [OH_Input_AddAxisEventMonitor](input.md#oh_input_addaxiseventmonitor) ([InputEvent_AxisEventType](input.md#inputevent_axiseventtype) axisEventType, [Input_AxisEventCallback](input.md#input_axiseventcallback) callback) | 添加指定类型的轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](input.md#inputevent_axiseventtype)中。  | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveKeyEventMonitor](input.md#oh_input_removekeyeventmonitor) ([Input_KeyEventCallback](input.md#input_keyeventcallback) callback) | 移除按键事件监听。  | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveMouseEventMonitor](input.md#oh_input_removemouseeventmonitor) ([Input_MouseEventCallback](input.md#input_mouseeventcallback) callback) | 移除鼠标事件监听。  | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveTouchEventMonitor](input.md#oh_input_removetoucheventmonitor) ([Input_TouchEventCallback](input.md#input_toucheventcallback) callback) | 移除触摸事件监听。  | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveAxisEventMonitorForAll](input.md#oh_input_removeaxiseventmonitorforall) ([Input_AxisEventCallback](input.md#input_axiseventcallback) callback) | 移除所有类型轴事件监听。  | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveAxisEventMonitor](input.md#oh_input_removeaxiseventmonitor) ([InputEvent_AxisEventType](input.md#inputevent_axiseventtype) axisEventType, [Input_AxisEventCallback](input.md#input_axiseventcallback) callback) | 移除指定类型轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](input.md#inputevent_axiseventtype)中。  | 
| [Input_Result](input.md#input_result) [OH_Input_AddKeyEventInterceptor](input.md#oh_input_addkeyeventinterceptor) ([Input_KeyEventCallback](input.md#input_keyeventcallback) callback, [Input_InterceptorOptions](input.md#input_interceptoroptions) \*option) | 添加按键事件的拦截,重复添加只有第一次生效。  | 
| [Input_Result](input.md#input_result) [OH_Input_AddInputEventInterceptor](input.md#oh_input_addinputeventinterceptor) ([Input_InterceptorEventCallback](_input___interceptor_event_callback.md) \*callback [Input_InterceptorOptions](input.md#input_interceptoroptions) \*option) | 添加输入事件拦截，包括鼠标、触摸和轴事件，重复添加只有第一次生效。  | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveKeyEventInterceptor](input.md#oh_input_removekeyeventinterceptor) () | 移除按键事件拦截。  | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveInputEventInterceptor](input.md#oh_input_removeinputeventinterceptor) () | 移除输入事件拦截，包括鼠标、触摸和轴事件。  | 
| int32_t [OH_Input_GetIntervalSinceLastInput](input.md#oh_input_getintervalsincelastinput) (int64_t \*timeInterval) | 获取距离上次系统输入事件的时间间隔。  | 
| [Input_Hotkey](input.md#input_hotkey) \* [OH_Input_CreateHotkey](input.md#oh_input_createhotkey) () | 创建快捷键对象的实例。  | 
| void [OH_Input_DestroyHotkey](input.md#oh_input_destroyhotkey) ([Input_Hotkey](input.md#input_hotkey) \*\*hotkey) | 销毁快捷键对象的实例。  | 
| void [OH_Input_SetPreKeys](input.md#oh_input_setprekeys) ([Input_Hotkey](input.md#input_hotkey) \*hotkey, int32_t \*preKeys, int32_t size) | 设置修饰键。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetPreKeys](input.md#oh_input_getprekeys) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, int32_t \*\*preKeys, int32_t \*preKeyCount) | 获取修饰键。  | 
| void [OH_Input_SetFinalKey](input.md#oh_input_setfinalkey) ([Input_Hotkey](input.md#input_hotkey) \*hotkey, int32_t finalKey) | 设置被修饰键。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetFinalKey](input.md#oh_input_getfinalkey) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, int32_t \*finalKeyCode) | 获取被修饰键。  | 
| [Input_Hotkey](input.md#input_hotkey) \*\* [OH_Input_CreateAllSystemHotkeys](input.md#oh_input_createallsystemhotkeys) (int32_t count) | 创建[Input_Hotkey](input.md#input_hotkey)类型实例的数组。  | 
| void [OH_Input_DestroyAllSystemHotkeys](input.md#oh_input_destroyallsystemhotkeys) ([Input_Hotkey](input.md#input_hotkey) \*\*hotkeys, int32_t count) | 销毁[Input_Hotkey](input.md#input_hotkey)实例数组并回收内存。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetAllSystemHotkeys](input.md#oh_input_getallsystemhotkeys) ([Input_Hotkey](input.md#input_hotkey) \*\*hotkey, int32_t \*count) | 获取设置的所有快捷键。  | 
| void [OH_Input_SetRepeat](input.md#oh_input_setrepeat) ([Input_Hotkey](input.md#input_hotkey) \*hotkey, bool isRepeat) | 设置是否上报重复key事件。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetRepeat](input.md#oh_input_getrepeat) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, bool \*isRepeat) | 获取是否上报重复key事件。  | 
| [Input_Result](input.md#input_result) [OH_Input_AddHotkeyMonitor](input.md#oh_input_addhotkeymonitor) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, [Input_HotkeyCallback](input.md#input_hotkeycallback) callback) | 订阅快捷键事件。  | 
| [Input_Result](input.md#input_result) [OH_Input_RemoveHotkeyMonitor](input.md#oh_input_removehotkeymonitor) (const [Input_Hotkey](input.md#input_hotkey) \*hotkey, [Input_HotkeyCallback](input.md#input_hotkeycallback) callback) | 取消订阅快捷键。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceIds](input.md#oh_input_getdeviceids) (int32_t \*deviceIds, int32_t inSize, int32_t \*outSize) | 获取所有输入设备的ID列表。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetDevice](input.md#oh_input_getdevice) (int32_t deviceId, [Input_DeviceInfo](input.md#input_deviceinfo) \*\*deviceInfo) | 获取输入设备信息。  | 
| [Input_DeviceInfo](input.md#input_deviceinfo) \* [OH_Input_CreateDeviceInfo](input.md#oh_input_createdeviceinfo) (void) | 创建输入设备信息的对象。  | 
| void [OH_Input_DestroyDeviceInfo](input.md#oh_input_destroydeviceinfo) ([Input_DeviceInfo](input.md#input_deviceinfo) \*\*deviceInfo) | 销毁输入设备信息的对象。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetKeyboardType](input.md#oh_input_getkeyboardtype) (int32_t deviceId, int32_t \*keyboardType) | 获取输入设备的键盘类型。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceId](input.md#oh_input_getdeviceid) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*id) | 获取输入设备的id。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceName](input.md#oh_input_getdevicename) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, char \*\*name) | 获取输入设备的名称。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetCapabilities](input.md#oh_input_getcapabilities) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*capabilities) | 获取有关输入设备能力信息，比如设备是触摸屏、触控板、键盘等。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceVersion](input.md#oh_input_getdeviceversion) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*version) | 获取输入设备的版本信息。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceProduct](input.md#oh_input_getdeviceproduct) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*product) | 获取输入设备的产品信息。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceVendor](input.md#oh_input_getdevicevendor) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, int32_t \*vendor) | 获取输入设备的厂商信息。  | 
| [Input_Result](input.md#input_result) [OH_Input_GetDeviceAddress](input.md#oh_input_getdeviceaddress) ([Input_DeviceInfo](input.md#input_deviceinfo) \*deviceInfo, char \*\*address) | 获取输入设备的物理地址。  | 
| [Input_Result](input.md#input_result) [OH_Input_RegisterDeviceListener](input.md#oh_input_registerdevicelistener) ([Input_DeviceListener](_input___device_listener.md) \*listener) | 注册设备热插拔的监听器。  | 
| [Input_Result](input.md#input_result) [OH_Input_UnregisterDeviceListener](input.md#oh_input_unregisterdevicelistener) ([Input_DeviceListener](_input___device_listener.md) \*listener) | 取消注册设备热插拔的监听。  | 
| [Input_Result](input.md#input_result) [OH_Input_UnregisterDeviceListeners](input.md#oh_input_unregisterdevicelisteners) () | 取消注册所有的设备热插拔的监听。  | 
