# oh_input_manager.h


## 概述

提供事件注入和关键状态查询等功能。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**库：** liboh_input.so

**起始版本：** 12

**相关模块：**[Input](input.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Input_KeyStateAction](input.md#input_keystateaction)[Input_KeyStateAction](input.md#input_keystateaction) | 按键状态的枚举值。 | 
| typedef enum [Input_KeyEventAction](input.md#input_keyeventaction)[Input_KeyEventAction](input.md#input_keyeventaction) | 按键事件类型的枚举值。 | 
| typedef enum [Input_MouseEventAction](input.md#input_mouseeventaction)[Input_MouseEventAction](input.md#input_mouseeventaction) | 鼠标动作的枚举值 | 
| typedef enum [InputEvent_MouseAxis](input.md#inputevent_mouseaxis)[InputEvent_MouseAxis](input.md#inputevent_mouseaxis) | 鼠标轴事件类型 | 
| typedef enum [Input_MouseEventButton](input.md#input_mouseeventbutton)[Input_MouseEventButton](input.md#input_mouseeventbutton) | 鼠标按键的枚举值。 | 
| typedef enum [Input_TouchEventAction](input.md#input_toucheventaction)[Input_TouchEventAction](input.md#input_toucheventaction) | 触摸动作的枚举值。 | 
| typedef enum [Input_Result](input.md#input_result)[Input_Result](input.md#input_result) | 错误码枚举值 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Input_KeyStateAction](input.md#input_keystateaction) {<br/>[KEY_DEFAULT](input.md) = -1, [KEY_PRESSED](input.md) = 0, [KEY_RELEASED](input.md) = 1, [KEY_SWITCH_ON](input.md) = 2,<br/>[KEY_SWITCH_OFF](input.md) = 3<br/>} | 按键状态的枚举值。 | 
| [Input_KeyEventAction](input.md#input_keyeventaction) { [KEY_ACTION_CANCEL](input.md) = 0, [KEY_ACTION_DOWN](input.md) = 1, [KEY_ACTION_UP](input.md) = 2 } | 按键事件类型的枚举值。 | 
| [Input_MouseEventAction](input.md#input_mouseeventaction) {<br/>[MOUSE_ACTION_CANCEL](input.md) = 0, [MOUSE_ACTION_MOVE](input.md) = 1, [MOUSE_ACTION_BUTTON_DOWN](input.md) = 2, [MOUSE_ACTION_BUTTON_UP](input.md) = 3,<br/>[MOUSE_ACTION_AXIS_BEGIN](input.md) = 4, [MOUSE_ACTION_AXIS_UPDATE](input.md) = 5, [MOUSE_ACTION_AXIS_END](input.md) = 6<br/>} | 鼠标动作的枚举值。 | 
| [InputEvent_MouseAxis](input.md#inputevent_mouseaxis) { [MOUSE_AXIS_SCROLL_VERTICAL](input.md) = 0, [MOUSE_AXIS_SCROLL_HORIZONTAL](input.md) = 1 } | 鼠标轴事件类型。 | 
| [Input_MouseEventButton](input.md#input_mouseeventbutton) {<br/>[MOUSE_BUTTON_NONE](input.md) = -1, [MOUSE_BUTTON_LEFT](input.md) = 0, [MOUSE_BUTTON_MIDDLE](input.md) = 1, [MOUSE_BUTTON_RIGHT](input.md) = 2,<br/>[MOUSE_BUTTON_FORWARD](input.md) = 3, [MOUSE_BUTTON_BACK](input.md) = 4<br/>} | 鼠标按键的枚举值。 | 
| [Input_TouchEventAction](input.md#input_toucheventaction) { [TOUCH_ACTION_CANCEL](input.md) = 0, [TOUCH_ACTION_DOWN](input.md) = 1, [TOUCH_ACTION_MOVE](input.md) = 2, [TOUCH_ACTION_UP](input.md) = 3 } | 触摸动作的枚举值。 | 
| [Input_Result](input.md#input_result) { [INPUT_SUCCESS](input.md) = 0, [INPUT_PERMISSION_DENIED](input.md) = 201, [INPUT_NOT_SYSTEM_APPLICATION](input.md) = 202, [INPUT_PARAMETER_ERROR](input.md) = 401 } | 错误码枚举值。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Input_Result](input.md#input_result)[OH_Input_GetKeyState](input.md#oh_input_getkeystate) (struct Input_KeyState \*keyState) | 查询按键状态的枚举对象。 | 
| struct Input_KeyState \* [OH_Input_CreateKeyState](input.md#oh_input_createkeystate) () | 创建按键状态的枚举对象。 | 
| void [OH_Input_DestroyKeyState](input.md#oh_input_destroykeystate) (struct Input_KeyState \*\*keyState) | 销毁按键状态的枚举对象。 | 
| void [OH_Input_SetKeyCode](input.md#oh_input_setkeycode) (struct Input_KeyState \*keyState, int32_t keyCode) | 设置按键状态对象的键值。 | 
| int32_t [OH_Input_GetKeyCode](input.md#oh_input_getkeycode) (const struct Input_KeyState \*keyState) | 获取按键状态对象的键值。 | 
| void [OH_Input_SetKeyPressed](input.md#oh_input_setkeypressed) (struct Input_KeyState \*keyState, int32_t keyAction) | 设置按键状态对象的按键是否按下。 | 
| int32_t [OH_Input_GetKeyPressed](input.md#oh_input_getkeypressed) (const struct Input_KeyState \*keyState) | 获取按键状态对象的按键是否按下。 | 
| void [OH_Input_SetKeySwitch](input.md#oh_input_setkeyswitch) (struct Input_KeyState \*keyState, int32_t keySwitch) | 设置按键状态对象的按键开关。 | 
| int32_t [OH_Input_GetKeySwitch](input.md#oh_input_getkeyswitch) (const struct Input_KeyState \*keyState) | 获取按键状态对象的按键开关。 | 
| int32_t [OH_Input_InjectKeyEvent](input.md#oh_input_injectkeyevent) (const struct Input_KeyEvent \*keyEvent) | 注入按键事件。 | 
| struct Input_KeyEvent \* [OH_Input_CreateKeyEvent](input.md#oh_input_createkeyevent) () | 创建按键事件对象。 | 
| void [OH_Input_DestroyKeyEvent](input.md#oh_input_destroykeyevent) (struct Input_KeyEvent \*\*keyEvent) | 销毁按键事件对象。 | 
| void [OH_Input_SetKeyEventAction](input.md#oh_input_setkeyeventaction) (struct Input_KeyEvent \*keyEvent, int32_t action) | 设置按键事件类型。 | 
| int32_t [OH_Input_GetKeyEventAction](input.md#oh_input_getkeyeventaction) (const struct Input_KeyEvent \*keyEvent) | 获取按键事件类型。 | 
| void [OH_Input_SetKeyEventKeyCode](input.md#oh_input_setkeyeventkeycode) (struct Input_KeyEvent \*keyEvent, int32_t keyCode) | 设置按键事件的键值。 | 
| int32_t [OH_Input_GetKeyEventKeyCode](input.md#oh_input_getkeyeventkeycode) (const struct Input_KeyEvent \*keyEvent) | 获取按键事件的键值。 | 
| void [OH_Input_SetKeyEventActionTime](input.md#oh_input_setkeyeventactiontime) (struct Input_KeyEvent \*keyEvent, int64_t actionTime) | 设置按键事件发生的时间。 | 
| int64_t [OH_Input_GetKeyEventActionTime](input.md#oh_input_getkeyeventactiontime) (const struct Input_KeyEvent \*keyEvent) | 获取按键事件发生的时间。 | 
| int32_t [OH_Input_InjectMouseEvent](input.md#oh_input_injectmouseevent) (const struct Input_MouseEvent \*mouseEvent) | 注入鼠标事件。 | 
| struct Input_MouseEvent \* [OH_Input_CreateMouseEvent](input.md#oh_input_createmouseevent) () | 创建鼠标事件对象。 | 
| void [OH_Input_DestroyMouseEvent](input.md#oh_input_destroymouseevent) (struct Input_MouseEvent \*\*mouseEvent) | 销毁鼠标事件对象。 | 
| void [OH_Input_SetMouseEventAction](input.md#oh_input_setmouseeventaction) (struct Input_MouseEvent \*mouseEvent, int32_t action) | 设置鼠标事件的动作。 | 
| int32_t [OH_Input_GetMouseEventAction](input.md#oh_input_getmouseeventaction) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件的动作。 | 
| void [OH_Input_SetMouseEventDisplayX](input.md#oh_input_setmouseeventdisplayx) (struct Input_MouseEvent \*mouseEvent, int32_t displayX) | 设置鼠标事件的屏幕横坐标。 | 
| int32_t [OH_Input_GetMouseEventDisplayX](input.md#oh_input_getmouseeventdisplayx) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件的屏幕横坐标。 | 
| void [OH_Input_SetMouseEventDisplayY](input.md#oh_input_setmouseeventdisplayy) (struct Input_MouseEvent \*mouseEvent, int32_t displayY) | 设置鼠标事件的屏幕纵坐标。 | 
| int32_t [OH_Input_GetMouseEventDisplayY](input.md#oh_input_getmouseeventdisplayy) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件的屏幕纵坐标。 | 
| void [OH_Input_SetMouseEventButton](input.md#oh_input_setmouseeventbutton) (struct Input_MouseEvent \*mouseEvent, int32_t button) | 设置鼠标事件的按键。 | 
| int32_t [OH_Input_GetMouseEventButton](input.md#oh_input_getmouseeventbutton) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件的按键。 | 
| void [OH_Input_SetMouseEventAxisType](input.md#oh_input_setmouseeventaxistype) (struct Input_MouseEvent \*mouseEvent, int32_t axisType) | 设置鼠标轴事件的类型。 | 
| int32_t [OH_Input_GetMouseEventAxisType](input.md#oh_input_getmouseeventaxistype) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标轴事件的类型。 | 
| void [OH_Input_SetMouseEventAxisValue](input.md#oh_input_setmouseeventaxisvalue) (struct Input_MouseEvent \*mouseEvent, float axisValue) | 设置鼠标轴事件的值。 | 
| float [OH_Input_GetMouseEventAxisValue](input.md#oh_input_getmouseeventaxisvalue) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标轴事件的值。 | 
| void [OH_Input_SetMouseEventActionTime](input.md#oh_input_setmouseeventactiontime) (struct Input_MouseEvent \*mouseEvent, int64_t actionTime) | 设置鼠标事件发生的时间。 | 
| int64_t [OH_Input_GetMouseEventActionTime](input.md#oh_input_getmouseeventactiontime) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件发生的时间。 | 
| int32_t [OH_Input_InjectTouchEvent](input.md#oh_input_injecttouchevent) (const struct Input_TouchEvent \*touchEvent) | 注入触摸事件。 | 
| struct Input_TouchEvent \* [OH_Input_CreateTouchEvent](input.md#oh_input_createtouchevent) () | 创建触屏事件对象。 | 
| void [OH_Input_DestroyTouchEvent](input.md#oh_input_destroytouchevent) (struct Input_TouchEvent \*\*touchEvent) | 销毁触屏事件对象。 | 
| void [OH_Input_SetTouchEventAction](input.md#oh_input_settoucheventaction) (struct Input_TouchEvent \*touchEvent, int32_t action) | 设置触屏事件的动作。 | 
| int32_t [OH_Input_GetTouchEventAction](input.md#oh_input_gettoucheventaction) (const struct Input_TouchEvent \*touchEvent) | 获取触屏事件的动作。 | 
| void [OH_Input_SetTouchEventFingerId](input.md#oh_input_settoucheventfingerid) (struct Input_TouchEvent \*touchEvent, int32_t id) | 设置触屏事件的手指ID。 | 
| int32_t [OH_Input_GetTouchEventFingerId](input.md#oh_input_gettoucheventfingerid) (const struct Input_TouchEvent \*touchEvent) | 获取触屏事件的手指ID。 | 
| void [OH_Input_SetTouchEventDisplayX](input.md#oh_input_settoucheventdisplayx) (struct Input_TouchEvent \*touchEvent, int32_t displayX) | 设置触屏事件的屏幕横坐标。 | 
| int32_t [OH_Input_GetTouchEventDisplayX](input.md#oh_input_gettoucheventdisplayx) (const struct Input_TouchEvent \*touchEvent) | 获取触屏事件的屏幕横坐标。 | 
| void [OH_Input_SetTouchEventDisplayY](input.md#oh_input_settoucheventdisplayy) (struct Input_TouchEvent \*touchEvent, int32_t displayY) | 设置触屏事件的屏幕纵坐标。 | 
| int32_t [OH_Input_GetTouchEventDisplayY](input.md#oh_input_gettoucheventdisplayy) (const struct Input_TouchEvent \*touchEvent) | 获取触屏事件的屏幕纵坐标。 | 
| void [OH_Input_SetTouchEventActionTime](input.md#oh_input_settoucheventactiontime) (struct Input_TouchEvent \*touchEvent, int64_t actionTime) | 设置触摸事件发生的时间。 | 
| int64_t [OH_Input_GetTouchEventActionTime](input.md#oh_input_gettoucheventactiontime) (const struct Input_TouchEvent \*touchEvent) | 获取触摸事件发生的时间。 | 
| void [OH_Input_CancelInjection](input.md#oh_input_cancelinjection) () | 取消事件注入并撤销授权。 | 
