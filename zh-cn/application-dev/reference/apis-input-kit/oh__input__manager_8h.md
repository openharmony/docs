# oh_input_manager.h


## 概述

提供事件注入和按键状态查询等功能。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**库：** liboh_input.so

**起始版本：** 12

**相关模块：**[Input](input.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Input_KeyStateAction](input.md#input_keystateaction) {<br/>[KEY_DEFAULT](input.md) = -1, [KEY_PRESSED](input.md) = 0, [KEY_RELEASED](input.md) = 1, [KEY_SWITCH_ON](input.md) = 2,<br/>[KEY_SWITCH_OFF](input.md) = 3<br/>} | 按键状态的枚举值。 | 
| [Input_Result](input.md#input_result) { [INPUT_SUCCESS](input.md) = 0, [INPUT_PERMISSION_DENIED](input.md) = 201, [INPUT_NOT_SYSTEM_APPLICATION](input.md) = 202, [INPUT_PARAMETER_ERROR](input.md) = 401 } | 错误码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Input_Result](input.md#input_result)[OH_Input_GetKeyState](input.md#oh_input_getkeystate) (struct Input_KeyState \*keyState) | 查询按键状态的枚举对象。 | 
| Input_KeyState \* [OH_Input_CreateKeyState](input.md#oh_input_createkeystate) () | 创建按键状态的枚举对象。 | 
| [OH_Input_DestroyKeyState](input.md#oh_input_destroykeystate) (struct Input_KeyState \*keyState) | 销毁按键状态的枚举对象。 | 
| [OH_Input_SetKeyCode](input.md#oh_input_setkeycode) (struct Input_KeyState \*keyState, int32_t keyCode) | 设置按键状态对象的键值。 | 
| [OH_Input_GetKeyCode](input.md#oh_input_getkeycode) (struct Input_KeyState \*keyState) | 获取按键状态对象的键值。 | 
| [OH_Input_SetKeyPressed](input.md#oh_input_setkeypressed) (struct Input_KeyState \*keyState, int32_t keyAction) | 设置按键状态对象的按键是否按下。 | 
| [OH_Input_GetKeyPressed](input.md#oh_input_getkeypressed) (struct Input_KeyState \*keyState) | 获取按键状态对象的按键是否按下。 | 
| [OH_Input_SetKeySwitch](input.md#oh_input_setkeyswitch) (struct Input_KeyState \*keyState, int32_t keySwitch) | 设置按键状态对象的按键开关。 | 
| [OH_Input_GetKeySwitch](input.md#oh_input_getkeyswitch) (struct Input_KeyState \*keyState) | 获取按键状态对象的按键开关。 | 
