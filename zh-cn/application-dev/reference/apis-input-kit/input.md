# Input


## 概述

提供多模态输入域的C接口。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [oh_input_manager.h](oh__input__manager_8h.md) | 提供事件注入和关键状态查询等功能。 | 
| [oh_key_code.h](oh__key__code_8h.md) | 按键设备的键码值。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Input_KeyStateAction](#input_keystateaction)[Input_KeyStateAction](#input_keystateaction) | 按键状态的枚举值。 | 
| typedef enum [Input_KeyEventAction](#input_keyeventaction)[Input_KeyEventAction](#input_keyeventaction) | 按键事件类型的枚举值。 | 
| typedef enum [Input_MouseEventAction](#input_mouseeventaction)[Input_MouseEventAction](#input_mouseeventaction) | 鼠标动作的枚举值 | 
| typedef enum [InputEvent_MouseAxis](#inputevent_mouseaxis)[InputEvent_MouseAxis](#inputevent_mouseaxis) | 鼠标轴事件类型 | 
| typedef enum [Input_MouseEventButton](#input_mouseeventbutton)[Input_MouseEventButton](#input_mouseeventbutton) | 鼠标按键的枚举值。 | 
| typedef enum [Input_TouchEventAction](#input_toucheventaction)[Input_TouchEventAction](#input_toucheventaction) | 触摸动作的枚举值。 | 
| typedef enum [Input_Result](#input_result)[Input_Result](#input_result) | 错误码枚举值 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Input_KeyStateAction](#input_keystateaction) {<br/>KEY_DEFAULT = -1, KEY_PRESSED = 0, KEY_RELEASED = 1, KEY_SWITCH_ON = 2,<br/>KEY_SWITCH_OFF = 3<br/>} | 按键状态的枚举值。 | 
| [Input_KeyEventAction](#input_keyeventaction) { KEY_ACTION_CANCEL = 0, KEY_ACTION_DOWN = 1, KEY_ACTION_UP = 2 } | 按键事件类型的枚举值。 | 
| [Input_MouseEventAction](#input_mouseeventaction) {<br/>MOUSE_ACTION_CANCEL = 0, MOUSE_ACTION_MOVE = 1, MOUSE_ACTION_BUTTON_DOWN = 2, MOUSE_ACTION_BUTTON_UP = 3,<br/>MOUSE_ACTION_AXIS_BEGIN = 4, MOUSE_ACTION_AXIS_UPDATE = 5, MOUSE_ACTION_AXIS_END = 6<br/>} | 鼠标动作的枚举值 | 
| [InputEvent_MouseAxis](#inputevent_mouseaxis) { MOUSE_AXIS_SCROLL_VERTICAL = 0, MOUSE_AXIS_SCROLL_HORIZONTAL = 1 } | 鼠标轴事件类型 | 
| [Input_MouseEventButton](#input_mouseeventbutton) {<br/>MOUSE_BUTTON_NONE = -1, MOUSE_BUTTON_LEFT = 0, MOUSE_BUTTON_MIDDLE = 1, MOUSE_BUTTON_RIGHT = 2,<br/>MOUSE_BUTTON_FORWARD = 3, MOUSE_BUTTON_BACK = 4<br/>} | 鼠标按键的枚举值。 | 
| [Input_TouchEventAction](#input_toucheventaction) { TOUCH_ACTION_CANCEL = 0, TOUCH_ACTION_DOWN = 1, TOUCH_ACTION_MOVE = 2, TOUCH_ACTION_UP = 3 } | 触摸动作的枚举值。 | 
| [Input_Result](#input_result) { INPUT_SUCCESS = 0, INPUT_PERMISSION_DENIED = 201, INPUT_NOT_SYSTEM_APPLICATION = 202, INPUT_PARAMETER_ERROR = 401 } | 错误码枚举值 | 
| [Input_KeyCode](#input_keycode) {<br/>KEYCODE_UNKNOWN = -1, KEYCODE_FN = 0, KEYCODE_VOLUME_UP = 16, KEYCODE_VOLUME_DOWN = 17,<br/>KEYCODE_POWER = 18, KEYCODE_CAMERA = 19, KEYCODE_VOLUME_MUTE = 22, KEYCODE_MUTE = 23,<br/>KEYCODE_BRIGHTNESS_UP = 40, KEYCODE_BRIGHTNESS_DOWN = 41, KEYCODE_0 = 2000, KEYCODE_1 = 2001,<br/>KEYCODE_2 = 2002, KEYCODE_3 = 2003, KEYCODE_4 = 2004, KEYCODE_5 = 2005,<br/>KEYCODE_6 = 2006, KEYCODE_7 = 2007, KEYCODE_8 = 2008, KEYCODE_9 = 2009,<br/>KEYCODE_STAR = 2010, KEYCODE_POUND = 2011, KEYCODE_DPAD_UP = 2012, KEYCODE_DPAD_DOWN = 2013,<br/>KEYCODE_DPAD_LEFT = 2014, KEYCODE_DPAD_RIGHT = 2015, KEYCODE_DPAD_CENTER = 2016, KEYCODE_A = 2017,<br/>KEYCODE_B = 2018, KEYCODE_C = 2019, KEYCODE_D = 2020, KEYCODE_E = 2021,<br/>KEYCODE_F = 2022, KEYCODE_G = 2023, KEYCODE_H = 2024, KEYCODE_I = 2025,<br/>KEYCODE_J = 2026, KEYCODE_K = 2027, KEYCODE_L = 2028, KEYCODE_M = 2029,<br/>KEYCODE_N = 2030, KEYCODE_O = 2031, KEYCODE_P = 2032, KEYCODE_Q = 2033,<br/>KEYCODE_R = 2034, KEYCODE_S = 2035, KEYCODE_T = 2036, KEYCODE_U = 2037,<br/>KEYCODE_V = 2038, KEYCODE_W = 2039, KEYCODE_X = 2040, KEYCODE_Y = 2041,<br/>KEYCODE_Z = 2042, KEYCODE_COMMA = 2043, KEYCODE_PERIOD = 2044, KEYCODE_ALT_LEFT = 2045,<br/>KEYCODE_ALT_RIGHT = 2046, KEYCODE_SHIFT_LEFT = 2047, KEYCODE_SHIFT_RIGHT = 2048, KEYCODE_TAB = 2049,<br/>KEYCODE_SPACE = 2050, KEYCODE_SYM = 2051, KEYCODE_EXPLORER = 2052, KEYCODE_ENVELOPE = 2053,<br/>KEYCODE_ENTER = 2054, KEYCODE_DEL = 2055, KEYCODE_GRAVE = 2056, KEYCODE_MINUS = 2057,<br/>KEYCODE_EQUALS = 2058, KEYCODE_LEFT_BRACKET = 2059, KEYCODE_RIGHT_BRACKET = 2060, KEYCODE_BACKSLASH = 2061,<br/>KEYCODE_SEMICOLON = 2062, KEYCODE_APOSTROPHE = 2063, KEYCODE_SLASH = 2064, KEYCODE_AT = 2065,<br/>KEYCODE_PLUS = 2066, KEYCODE_MENU = 2067, KEYCODE_PAGE_UP = 2068, KEYCODE_PAGE_DOWN = 2069,<br/>KEYCODE_ESCAPE = 2070, KEYCODE_FORWARD_DEL = 2071, KEYCODE_CTRL_LEFT = 2072, KEYCODE_CTRL_RIGHT = 2073,<br/>KEYCODE_CAPS_LOCK = 2074, KEYCODE_SCROLL_LOCK = 2075, KEYCODE_META_LEFT = 2076, KEYCODE_META_RIGHT = 2077,<br/>KEYCODE_FUNCTION = 2078, KEYCODE_SYSRQ = 2079, KEYCODE_BREAK = 2080, KEYCODE_MOVE_HOME = 2081,<br/>KEYCODE_MOVE_END = 2082, KEYCODE_INSERT = 2083, KEYCODE_FORWARD = 2084, KEYCODE_MEDIA_PLAY = 2085,<br/>KEYCODE_MEDIA_PAUSE = 2086, KEYCODE_MEDIA_CLOSE = 2087, KEYCODE_MEDIA_EJECT = 2088, KEYCODE_MEDIA_RECORD = 2089,<br/>KEYCODE_F1 = 2090, KEYCODE_F2 = 2091, KEYCODE_F3 = 2092, KEYCODE_F4 = 2093,<br/>KEYCODE_F5 = 2094, KEYCODE_F6 = 2095, KEYCODE_F7 = 2096, KEYCODE_F8 = 2097,<br/>KEYCODE_F9 = 2098, KEYCODE_F10 = 2099, KEYCODE_F11 = 2100, KEYCODE_F12 = 2101,<br/>KEYCODE_NUM_LOCK = 2102, KEYCODE_NUMPAD_0 = 2103, KEYCODE_NUMPAD_1 = 2104, KEYCODE_NUMPAD_2 = 2105,<br/>KEYCODE_NUMPAD_3 = 2106, KEYCODE_NUMPAD_4 = 2107, KEYCODE_NUMPAD_5 = 2108, KEYCODE_NUMPAD_6 = 2109,<br/>KEYCODE_NUMPAD_7 = 2110, KEYCODE_NUMPAD_8 = 2111, KEYCODE_NUMPAD_9 = 2112, KEYCODE_NUMPAD_DIVIDE = 2113,<br/>KEYCODE_NUMPAD_MULTIPLY = 2114, KEYCODE_NUMPAD_SUBTRACT = 2115, KEYCODE_NUMPAD_ADD = 2116, KEYCODE_NUMPAD_DOT = 2117,<br/>KEYCODE_NUMPAD_COMMA = 2118, KEYCODE_NUMPAD_ENTER = 2119, KEYCODE_NUMPAD_EQUALS = 2120, KEYCODE_NUMPAD_LEFT_PAREN = 2121,<br/>KEYCODE_NUMPAD_RIGHT_PAREN = 2122<br/>} | 键码值。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Input_Result](#input_result)[OH_Input_GetKeyState](#oh_input_getkeystate) (struct Input_KeyState \*keyState) | 查询按键状态的枚举对象。 | 
| struct Input_KeyState \* [OH_Input_CreateKeyState](#oh_input_createkeystate) () | 创建按键状态的枚举对象。 | 
| void [OH_Input_DestroyKeyState](#oh_input_destroykeystate) (struct Input_KeyState \*\*keyState) | 销毁按键状态的枚举对象。 | 
| void [OH_Input_SetKeyCode](#oh_input_setkeycode) (struct Input_KeyState \*keyState, int32_t keyCode) | 设置按键状态对象的键值。 | 
| int32_t [OH_Input_GetKeyCode](#oh_input_getkeycode) (const struct Input_KeyState \*keyState) | 获取按键状态对象的键值。 | 
| void [OH_Input_SetKeyPressed](#oh_input_setkeypressed) (struct Input_KeyState \*keyState, int32_t keyAction) | 设置按键状态对象的按键是否按下。 | 
| int32_t [OH_Input_GetKeyPressed](#oh_input_getkeypressed) (const struct Input_KeyState \*keyState) | 获取按键状态对象的按键是否按下。 | 
| void [OH_Input_SetKeySwitch](#oh_input_setkeyswitch) (struct Input_KeyState \*keyState, int32_t keySwitch) | 设置按键状态对象的按键开关。 | 
| int32_t [OH_Input_GetKeySwitch](#oh_input_getkeyswitch) (const struct Input_KeyState \*keyState) | 获取按键状态对象的按键开关。 | 
| int32_t [OH_Input_InjectKeyEvent](#oh_input_injectkeyevent) (const struct Input_KeyEvent \*keyEvent) | 注入按键事件。 | 
| struct Input_KeyEvent \* [OH_Input_CreateKeyEvent](#oh_input_createkeyevent) () | 创建按键事件对象。 | 
| void [OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent) (struct Input_KeyEvent \*\*keyEvent) | 销毁按键事件对象。 | 
| void [OH_Input_SetKeyEventAction](#oh_input_setkeyeventaction) (struct Input_KeyEvent \*keyEvent, int32_t action) | 设置按键事件类型。 | 
| int32_t [OH_Input_GetKeyEventAction](#oh_input_getkeyeventaction) (const struct Input_KeyEvent \*keyEvent) | 获取按键事件类型。 | 
| void [OH_Input_SetKeyEventKeyCode](#oh_input_setkeyeventkeycode) (struct Input_KeyEvent \*keyEvent, int32_t keyCode) | 设置按键事件的键值。 | 
| int32_t [OH_Input_GetKeyEventKeyCode](#oh_input_getkeyeventkeycode) (const struct Input_KeyEvent \*keyEvent) | 获取按键事件的键值。 | 
| void [OH_Input_SetKeyEventActionTime](#oh_input_setkeyeventactiontime) (struct Input_KeyEvent \*keyEvent, int64_t actionTime) | 设置按键事件发生的时间。 | 
| int64_t [OH_Input_GetKeyEventActionTime](#oh_input_getkeyeventactiontime) (const struct Input_KeyEvent \*keyEvent) | 获取按键事件发生的时间。 | 
| int32_t [OH_Input_InjectMouseEvent](#oh_input_injectmouseevent) (const struct Input_MouseEvent \*mouseEvent) | 注入鼠标事件。 | 
| struct Input_MouseEvent \* [OH_Input_CreateMouseEvent](#oh_input_createmouseevent) () | 创建鼠标事件对象。 | 
| void [OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent) (struct Input_MouseEvent \*\*mouseEvent) | 销毁鼠标事件对象。 | 
| void [OH_Input_SetMouseEventAction](#oh_input_setmouseeventaction) (struct Input_MouseEvent \*mouseEvent, int32_t action) | 设置鼠标事件的动作。 | 
| int32_t [OH_Input_GetMouseEventAction](#oh_input_getmouseeventaction) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件的动作。 | 
| void [OH_Input_SetMouseEventDisplayX](#oh_input_setmouseeventdisplayx) (struct Input_MouseEvent \*mouseEvent, int32_t displayX) | 设置鼠标事件的屏幕横坐标。 | 
| int32_t [OH_Input_GetMouseEventDisplayX](#oh_input_getmouseeventdisplayx) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件的屏幕横坐标。 | 
| void [OH_Input_SetMouseEventDisplayY](#oh_input_setmouseeventdisplayy) (struct Input_MouseEvent \*mouseEvent, int32_t displayY) | 设置鼠标事件的屏幕纵坐标。 | 
| int32_t [OH_Input_GetMouseEventDisplayY](#oh_input_getmouseeventdisplayy) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件的屏幕纵坐标。 | 
| void [OH_Input_SetMouseEventButton](#oh_input_setmouseeventbutton) (struct Input_MouseEvent \*mouseEvent, int32_t button) | 设置鼠标事件的按键。 | 
| int32_t [OH_Input_GetMouseEventButton](#oh_input_getmouseeventbutton) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件的按键。 | 
| void [OH_Input_SetMouseEventAxisType](#oh_input_setmouseeventaxistype) (struct Input_MouseEvent \*mouseEvent, int32_t axisType) | 设置鼠标轴事件的类型。 | 
| int32_t [OH_Input_GetMouseEventAxisType](#oh_input_getmouseeventaxistype) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标轴事件的类型。 | 
| void [OH_Input_SetMouseEventAxisValue](#oh_input_setmouseeventaxisvalue) (struct Input_MouseEvent \*mouseEvent, float axisValue) | 设置鼠标轴事件的值。 | 
| float [OH_Input_GetMouseEventAxisValue](#oh_input_getmouseeventaxisvalue) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标轴事件的值。 | 
| void [OH_Input_SetMouseEventActionTime](#oh_input_setmouseeventactiontime) (struct Input_MouseEvent \*mouseEvent, int64_t actionTime) | 设置鼠标事件发生的时间。 | 
| int64_t [OH_Input_GetMouseEventActionTime](#oh_input_getmouseeventactiontime) (const struct Input_MouseEvent \*mouseEvent) | 获取鼠标事件发生的时间。 | 
| int32_t [OH_Input_InjectTouchEvent](#oh_input_injecttouchevent) (const struct Input_TouchEvent \*touchEvent) | 注入触摸事件。 | 
| struct Input_TouchEvent \* [OH_Input_CreateTouchEvent](#oh_input_createtouchevent) () | 创建触屏事件对象。 | 
| void [OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent) (struct Input_TouchEvent \*\*touchEvent) | 销毁触屏事件对象。 | 
| void [OH_Input_SetTouchEventAction](#oh_input_settoucheventaction) (struct Input_TouchEvent \*touchEvent, int32_t action) | 设置触屏事件的动作。 | 
| int32_t [OH_Input_GetTouchEventAction](#oh_input_gettoucheventaction) (const struct Input_TouchEvent \*touchEvent) | 获取触屏事件的动作。 | 
| void [OH_Input_SetTouchEventFingerId](#oh_input_settoucheventfingerid) (struct Input_TouchEvent \*touchEvent, int32_t id) | 设置触屏事件的手指ID。 | 
| int32_t [OH_Input_GetTouchEventFingerId](#oh_input_gettoucheventfingerid) (const struct Input_TouchEvent \*touchEvent) | 获取触屏事件的手指ID。 | 
| void [OH_Input_SetTouchEventDisplayX](#oh_input_settoucheventdisplayx) (struct Input_TouchEvent \*touchEvent, int32_t displayX) | 设置触屏事件的屏幕横坐标。 | 
| int32_t [OH_Input_GetTouchEventDisplayX](#oh_input_gettoucheventdisplayx) (const struct Input_TouchEvent \*touchEvent) | 获取触屏事件的屏幕横坐标。 | 
| void [OH_Input_SetTouchEventDisplayY](#oh_input_settoucheventdisplayy) (struct Input_TouchEvent \*touchEvent, int32_t displayY) | 设置触屏事件的屏幕纵坐标。 | 
| int32_t [OH_Input_GetTouchEventDisplayY](#oh_input_gettoucheventdisplayy) (const struct Input_TouchEvent \*touchEvent) | 获取触屏事件的屏幕纵坐标。 | 
| void [OH_Input_SetTouchEventActionTime](#oh_input_settoucheventactiontime) (struct Input_TouchEvent \*touchEvent, int64_t actionTime) | 设置触摸事件发生的时间。 | 
| int64_t [OH_Input_GetTouchEventActionTime](#oh_input_gettoucheventactiontime) (const struct Input_TouchEvent \*touchEvent) | 获取触摸事件发生的时间。 | 
| void [OH_Input_CancelInjection](#oh_input_cancelinjection) () | 取消事件注入并撤销授权。 | 


## 类型定义说明


### Input_KeyEventAction

```
typedef enum Input_KeyEventActionInput_KeyEventAction
```

**描述**

按键事件类型的枚举值。

**起始版本：** 12


### Input_KeyStateAction

```
typedef enum Input_KeyStateActionInput_KeyStateAction
```

**描述**

按键状态的枚举值。

**起始版本：** 12


### Input_MouseEventAction

```
typedef enum Input_MouseEventActionInput_MouseEventAction
```

**描述**

鼠标动作的枚举值

**起始版本：** 12


### Input_MouseEventButton

```
typedef enum Input_MouseEventButtonInput_MouseEventButton
```

**描述**

鼠标按键的枚举值。

**起始版本：** 12


### Input_Result

```
typedef enum Input_ResultInput_Result
```

**描述**

错误码枚举值

**起始版本：** 12


### Input_TouchEventAction

```
typedef enum Input_TouchEventActionInput_TouchEventAction
```

**描述**

触摸动作的枚举值。

**起始版本：** 12


### InputEvent_MouseAxis

```
typedef enum InputEvent_MouseAxisInputEvent_MouseAxis
```

**描述**

鼠标轴事件类型

**起始版本：** 12


## 枚举类型说明


### Input_KeyCode

```
enum Input_KeyCode
```

**描述**

键码值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| KEYCODE_UNKNOWN | 未知按键 | 
| KEYCODE_FN | 功能（Fn）键 | 
| KEYCODE_VOLUME_UP | 音量增加键 | 
| KEYCODE_VOLUME_DOWN | 音量减小键 | 
| KEYCODE_POWER | 电源键 | 
| KEYCODE_CAMERA | 拍照键 | 
| KEYCODE_VOLUME_MUTE | 扬声器静音键 | 
| KEYCODE_MUTE | 话筒静音键 | 
| KEYCODE_BRIGHTNESS_UP | 亮度调节按键：调亮 | 
| KEYCODE_BRIGHTNESS_DOWN | 亮度调节按键：调暗 | 
| KEYCODE_0 | 按键'0' | 
| KEYCODE_1 | 按键'1' | 
| KEYCODE_2 | 按键'2' | 
| KEYCODE_3 | 按键'3' | 
| KEYCODE_4 | 按键'4' | 
| KEYCODE_5 | 按键'5' | 
| KEYCODE_6 | 按键'6' | 
| KEYCODE_7 | 按键'7' | 
| KEYCODE_8 | 按键'8' | 
| KEYCODE_9 | 按键'9' | 
| KEYCODE_STAR | 按键'\*' | 
| KEYCODE_POUND | 按键'\#' | 
| KEYCODE_DPAD_UP | 导航键：向上 | 
| KEYCODE_DPAD_DOWN | 导航键：向下 | 
| KEYCODE_DPAD_LEFT | 导航键：向左 | 
| KEYCODE_DPAD_RIGHT | 导航键：向右 | 
| KEYCODE_DPAD_CENTER | 导航键：确定键 | 
| KEYCODE_A | 按键'A' | 
| KEYCODE_B | 按键'B' | 
| KEYCODE_C | 按键'C' | 
| KEYCODE_D | 按键'D' | 
| KEYCODE_E | 按键'E' | 
| KEYCODE_F | 按键'F' | 
| KEYCODE_G | 按键'G' | 
| KEYCODE_H | 按键'H' | 
| KEYCODE_I | 按键'I' | 
| KEYCODE_J | 按键'J' | 
| KEYCODE_K | 按键'K' | 
| KEYCODE_L | 按键'L' | 
| KEYCODE_M | 按键'M' | 
| KEYCODE_N | 按键'N' | 
| KEYCODE_O | 按键'O' | 
| KEYCODE_P | 按键'P' | 
| KEYCODE_Q | 按键'Q' | 
| KEYCODE_R | 按键'R' | 
| KEYCODE_S | 按键'S' | 
| KEYCODE_T | 按键'T' | 
| KEYCODE_U | 按键'U' | 
| KEYCODE_V | 按键'V' | 
| KEYCODE_W | 按键'W' | 
| KEYCODE_X | 按键'X' | 
| KEYCODE_Y | 按键'Y' | 
| KEYCODE_Z | 按键'Z' | 
| KEYCODE_COMMA | 按键',' | 
| KEYCODE_PERIOD | 按键'.' | 
| KEYCODE_ALT_LEFT | 左Alt键 | 
| KEYCODE_ALT_RIGHT | 右Alt键 | 
| KEYCODE_SHIFT_LEFT | 左Shift键 | 
| KEYCODE_SHIFT_RIGHT | 右Shift键 | 
| KEYCODE_TAB | Tab键 | 
| KEYCODE_SPACE | 空格键 | 
| KEYCODE_SYM | 符号修改器按键 | 
| KEYCODE_EXPLORER | 浏览器功能键，此键用于启动浏览器应用程序 | 
| KEYCODE_ENVELOPE | 电子邮件功能键，此键用于启动电子邮件应用程序 | 
| KEYCODE_ENTER | 回车键 | 
| KEYCODE_DEL | 退格键 | 
| KEYCODE_GRAVE | 按键'‘’ | 
| KEYCODE_MINUS | 按键'-' | 
| KEYCODE_EQUALS | 按键'=' | 
| KEYCODE_LEFT_BRACKET | 按键'[' | 
| KEYCODE_RIGHT_BRACKET | 按键']' | 
| KEYCODE_BACKSLASH | 按键'\' | 
| KEYCODE_SEMICOLON | 按键';' | 
| KEYCODE_APOSTROPHE | 按键''' (单引号) | 
| KEYCODE_SLASH | 按键'/' | 
| KEYCODE_AT | 按键'\@' | 
| KEYCODE_PLUS | 按键'+' | 
| KEYCODE_MENU | 菜单键 | 
| KEYCODE_PAGE_UP | 向上翻页键 | 
| KEYCODE_PAGE_DOWN | 向下翻页键 | 
| KEYCODE_ESCAPE | ESC键 | 
| KEYCODE_FORWARD_DEL | 删除键 | 
| KEYCODE_CTRL_LEFT | 左Ctrl键 | 
| KEYCODE_CTRL_RIGHT | 右Ctrl键 | 
| KEYCODE_CAPS_LOCK | 大写锁定键 | 
| KEYCODE_SCROLL_LOCK | 滚动锁定键 | 
| KEYCODE_META_LEFT | 左元修改器键 | 
| KEYCODE_META_RIGHT | 右元修改器键 | 
| KEYCODE_FUNCTION | 功能键 | 
| KEYCODE_SYSRQ | 系统请求/打印屏幕键 | 
| KEYCODE_BREAK | Break/Pause键 | 
| KEYCODE_MOVE_HOME | 光标移动到开始键 | 
| KEYCODE_MOVE_END | 光标移动到末尾键 | 
| KEYCODE_INSERT | 插入键 | 
| KEYCODE_FORWARD | 前进键 | 
| KEYCODE_MEDIA_PLAY | 多媒体键：播放 | 
| KEYCODE_MEDIA_PAUSE | 多媒体键：暂停 | 
| KEYCODE_MEDIA_CLOSE | 多媒体键：关闭 | 
| KEYCODE_MEDIA_EJECT | 多媒体键：弹出 | 
| KEYCODE_MEDIA_RECORD | 多媒体键：录音 | 
| KEYCODE_F1 | 按键'F1' | 
| KEYCODE_F2 | 按键'F2' | 
| KEYCODE_F3 | 按键'F3' | 
| KEYCODE_F4 | 按键'F4' | 
| KEYCODE_F5 | 按键'F5' | 
| KEYCODE_F6 | 按键'F6' | 
| KEYCODE_F7 | 按键'F7' | 
| KEYCODE_F8 | 按键'F8' | 
| KEYCODE_F9 | 按键'F9' | 
| KEYCODE_F10 | 按键'F10' | 
| KEYCODE_F11 | 按键'F11' | 
| KEYCODE_F12 | 按键'F12' | 
| KEYCODE_NUM_LOCK | 小键盘锁 | 
| KEYCODE_NUMPAD_0 | 小键盘按键'0' | 
| KEYCODE_NUMPAD_1 | 小键盘按键'1' | 
| KEYCODE_NUMPAD_2 | 小键盘按键'2' | 
| KEYCODE_NUMPAD_3 | 小键盘按键'3' | 
| KEYCODE_NUMPAD_4 | 小键盘按键'4' | 
| KEYCODE_NUMPAD_5 | 小键盘按键'5' | 
| KEYCODE_NUMPAD_6 | 小键盘按键'6' | 
| KEYCODE_NUMPAD_7 | 小键盘按键'7' | 
| KEYCODE_NUMPAD_8 | 小键盘按键'8' | 
| KEYCODE_NUMPAD_9 | 小键盘按键'9' | 
| KEYCODE_NUMPAD_DIVIDE | 小键盘按键'/' | 
| KEYCODE_NUMPAD_MULTIPLY | 小键盘按键'\*' | 
| KEYCODE_NUMPAD_SUBTRACT | 小键盘按键'-' | 
| KEYCODE_NUMPAD_ADD | 小键盘按键'+' | 
| KEYCODE_NUMPAD_DOT | 小键盘按键'.' | 
| KEYCODE_NUMPAD_COMMA | 小键盘按键',' | 
| KEYCODE_NUMPAD_ENTER | 小键盘按键回车 | 
| KEYCODE_NUMPAD_EQUALS | 小键盘按键'=' | 
| KEYCODE_NUMPAD_LEFT_PAREN | 小键盘按键'(' | 
| KEYCODE_NUMPAD_RIGHT_PAREN | 小键盘按键')' | 


### Input_KeyEventAction

```
enum Input_KeyEventAction
```

**描述**

按键事件类型的枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| KEY_ACTION_CANCEL | 按键动作取消 | 
| KEY_ACTION_DOWN | 按键按下 | 
| KEY_ACTION_UP | 按键抬起 | 


### Input_KeyStateAction

```
enum Input_KeyStateAction
```

**描述**

按键状态的枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| KEY_DEFAULT | 默认状态 | 
| KEY_PRESSED | 按键按下 | 
| KEY_RELEASED | 按键抬起 | 
| KEY_SWITCH_ON | 按键开关使能 | 
| KEY_SWITCH_OFF | 按键开关去使能 | 


### Input_MouseEventAction

```
enum Input_MouseEventAction
```

**描述**

鼠标动作的枚举值

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MOUSE_ACTION_CANCEL | 取消鼠标动作 | 
| MOUSE_ACTION_MOVE | 移动鼠标 | 
| MOUSE_ACTION_BUTTON_DOWN | 按下鼠标 | 
| MOUSE_ACTION_BUTTON_UP | 抬起鼠标按键 | 
| MOUSE_ACTION_AXIS_BEGIN | 鼠标轴事件开始 | 
| MOUSE_ACTION_AXIS_UPDATE | 更新鼠标轴事件 | 
| MOUSE_ACTION_AXIS_END | 鼠标轴事件结束 | 


### Input_MouseEventButton

```
enum Input_MouseEventButton
```

**描述**

鼠标按键的枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MOUSE_BUTTON_NONE | 无效按键 | 
| MOUSE_BUTTON_LEFT | 鼠标左键 | 
| MOUSE_BUTTON_MIDDLE | 鼠标中间键 | 
| MOUSE_BUTTON_RIGHT | 鼠标右键 | 
| MOUSE_BUTTON_FORWARD | 鼠标前进键 | 
| MOUSE_BUTTON_BACK | 鼠标返回键 | 


### Input_Result

```
enum Input_Result
```

**描述**

错误码枚举值

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| INPUT_SUCCESS | 操作成功 | 
| INPUT_PERMISSION_DENIED | 权限验证失败 | 
| INPUT_NOT_SYSTEM_APPLICATION | 非系统应用 | 
| INPUT_PARAMETER_ERROR | 参数检查失败 | 


### Input_TouchEventAction

```
enum Input_TouchEventAction
```

**描述**

触摸动作的枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| TOUCH_ACTION_CANCEL | 触摸取消 | 
| TOUCH_ACTION_DOWN | 触摸按下 | 
| TOUCH_ACTION_MOVE | 触摸移动 | 
| TOUCH_ACTION_UP | 触摸抬起 | 


### InputEvent_MouseAxis

```
enum InputEvent_MouseAxis
```

**描述**

鼠标轴事件类型

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MOUSE_AXIS_SCROLL_VERTICAL | 垂直滚动轴 | 
| MOUSE_AXIS_SCROLL_HORIZONTAL | 水平滚动轴 | 


## 函数说明


### OH_Input_CancelInjection()

```
void OH_Input_CancelInjection ()
```

**描述**

取消事件注入并撤销授权

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


### OH_Input_CreateKeyEvent()

```
struct Input_KeyEvent* OH_Input_CreateKeyEvent ()
```

**描述**

创建按键事件对象

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

如果操作成功返回一个**Input_KeyEvent**指针对象 否则返回空指针。


### OH_Input_CreateKeyState()

```
struct Input_KeyState* OH_Input_CreateKeyState ()
```

**描述**

创建按键状态的枚举对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

如果操作成功，

返回一个**Input_KeyState**指针对象 否则返回空指针。


### OH_Input_CreateMouseEvent()

```
struct Input_MouseEvent* OH_Input_CreateMouseEvent ()
```

**描述**

创建鼠标事件对象

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

如果操作成功返回一个**Input_MouseEvent**指针对象 否则返回空指针。


### OH_Input_CreateTouchEvent()

```
struct Input_TouchEvent* OH_Input_CreateTouchEvent ()
```

**描述**

创建触屏事件对象

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

如果操作成功返回一个**Input_TouchEvent**指针对象 否则返回空指针。


### OH_Input_DestroyKeyEvent()

```
void OH_Input_DestroyKeyEvent (struct Input_KeyEvent ** keyEvent)
```

**描述**

销毁按键事件对象

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件对象 | 


### OH_Input_DestroyKeyState()

```
void OH_Input_DestroyKeyState (struct Input_KeyState ** keyState)
```

**描述**

销毁按键状态的枚举对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyState | 按键状态的枚举对象 | 


### OH_Input_DestroyMouseEvent()

```
void OH_Input_DestroyMouseEvent (struct Input_MouseEvent ** mouseEvent)
```

**描述**

销毁鼠标事件对象

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 


### OH_Input_DestroyTouchEvent()

```
void OH_Input_DestroyTouchEvent (struct Input_TouchEvent ** touchEvent)
```

**描述**

销毁触屏事件对象

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 


### OH_Input_GetKeyCode()

```
int32_t OH_Input_GetKeyCode (const struct Input_KeyState * keyState)
```

**描述**

获取按键状态对象的键值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyState | 按键状态的枚举对象 | 

**返回：**

返回按键状态对象的键值。


### OH_Input_GetKeyEventAction()

```
int32_t OH_Input_GetKeyEventAction (const struct Input_KeyEvent * keyEvent)
```

**描述**

获取按键事件类型

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件对象 | 

**返回：**

返回按键事件类型


### OH_Input_GetKeyEventActionTime()

```
int64_t OH_Input_GetKeyEventActionTime (const struct Input_KeyEvent * keyEvent)
```

**描述**

获取按键事件发生的时间

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件对象 | 

**返回：**

返回按键事件发生的时间


### OH_Input_GetKeyEventKeyCode()

```
int32_t OH_Input_GetKeyEventKeyCode (const struct Input_KeyEvent * keyEvent)
```

**描述**

获取按键事件的键值

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件对象 | 

**返回：**

Key code.


### OH_Input_GetKeyPressed()

```
int32_t OH_Input_GetKeyPressed (const struct Input_KeyState * keyState)
```

**描述**

获取按键状态对象的按键是否按下。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyState | 按键状态的枚举对象 | 

**返回：**

返回按键状态对象的按键按下状态。


### OH_Input_GetKeyState()

```
Input_Result OH_Input_GetKeyState (struct Input_KeyState * keyState)
```

**描述**

查询按键状态的枚举对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyState | 按键状态的枚举对象 | 

**返回：**

如果操作成功，

返回{\@Link Input_Result::INPUT_SUCCESS}; 否则返回{\@Link Input_Result}中定义的其他错误代码。


### OH_Input_GetKeySwitch()

```
int32_t OH_Input_GetKeySwitch (const struct Input_KeyState * keyState)
```

**描述**

获取按键状态对象的按键开关。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyState | 按键状态的枚举对象 | 

**返回：**

返回按键状态对象的按键开关。


### OH_Input_GetMouseEventAction()

```
int32_t OH_Input_GetMouseEventAction (const struct Input_MouseEvent * mouseEvent)
```

**描述**

获取鼠标事件的动作

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 

**返回：**

鼠标的动作


### OH_Input_GetMouseEventActionTime()

```
int64_t OH_Input_GetMouseEventActionTime (const struct Input_MouseEvent * mouseEvent)
```

**描述**

获取鼠标事件发生的时间

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 鼠标事件对象 | 

**返回：**

返回鼠标事件发生的时间


### OH_Input_GetMouseEventAxisType()

```
int32_t OH_Input_GetMouseEventAxisType (const struct Input_MouseEvent * mouseEvent)
```

**描述**

获取鼠标轴事件的类型

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 

**返回：**

轴类型


### OH_Input_GetMouseEventAxisValue()

```
float OH_Input_GetMouseEventAxisValue (const struct Input_MouseEvent * mouseEvent)
```

**描述**

获取鼠标轴事件的值

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 

**返回：**

轴事件的值


### OH_Input_GetMouseEventButton()

```
int32_t OH_Input_GetMouseEventButton (const struct Input_MouseEvent * mouseEvent)
```

**描述**

获取鼠标事件的按键

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 

**返回：**

鼠标按键


### OH_Input_GetMouseEventDisplayX()

```
int32_t OH_Input_GetMouseEventDisplayX (const struct Input_MouseEvent * mouseEvent)
```

**描述**

获取鼠标事件的屏幕横坐标

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 

**返回：**

屏幕横坐标


### OH_Input_GetMouseEventDisplayY()

```
int32_t OH_Input_GetMouseEventDisplayY (const struct Input_MouseEvent * mouseEvent)
```

**描述**

获取鼠标事件的屏幕纵坐标

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 

**返回：**

屏幕纵坐标


### OH_Input_GetTouchEventAction()

```
int32_t OH_Input_GetTouchEventAction (const struct Input_TouchEvent * touchEvent)
```

**描述**

获取触屏事件的动作

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 

**返回：**

触屏的动作


### OH_Input_GetTouchEventActionTime()

```
int64_t OH_Input_GetTouchEventActionTime (const struct Input_TouchEvent * touchEvent)
```

**描述**

获取触摸事件发生的时间

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 触屏事件对象 | 

**返回：**

返回触摸事件发生的时间


### OH_Input_GetTouchEventDisplayX()

```
int32_t OH_Input_GetTouchEventDisplayX (const struct Input_TouchEvent * touchEvent)
```

**描述**

获取触屏事件的屏幕横坐标

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 

**返回：**

触屏的屏幕横坐标


### OH_Input_GetTouchEventDisplayY()

```
int32_t OH_Input_GetTouchEventDisplayY (const struct Input_TouchEvent * touchEvent)
```

**描述**

获取触屏事件的屏幕纵坐标

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 

**返回：**

触屏的屏幕纵坐标


### OH_Input_GetTouchEventFingerId()

```
int32_t OH_Input_GetTouchEventFingerId (const struct Input_TouchEvent * touchEvent)
```

**描述**

获取触屏事件的手指ID

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 

**返回：**

触屏的手指ID


### OH_Input_InjectKeyEvent()

```
int32_t OH_Input_InjectKeyEvent (const struct Input_KeyEvent * keyEvent)
```

**描述**

注入按键事件

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 要注入的按键事件 | 

**返回：**

0 - 成功 201 - 缺少权限 401 - 参数错误


### OH_Input_InjectMouseEvent()

```
int32_t OH_Input_InjectMouseEvent (const struct Input_MouseEvent * mouseEvent)
```

**描述**

注入鼠标事件

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 要注入的鼠标事件 | 

**返回：**

0 - 成功 201 - 缺少权限 401 - 参数错误


### OH_Input_InjectTouchEvent()

```
int32_t OH_Input_InjectTouchEvent (const struct Input_TouchEvent * touchEvent)
```

**描述**

注入触摸事件

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | -要注入的触摸事件 | 

**返回：**

0 - 成功 201 - 缺少权限 401 - 参数错误


### OH_Input_SetKeyCode()

```
void OH_Input_SetKeyCode (struct Input_KeyState * keyState, int32_t keyCode )
```

**描述**

设置按键状态对象的键值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyState | 按键状态的枚举对象 | 
| keyCode | 按键键值。 | 


### OH_Input_SetKeyEventAction()

```
void OH_Input_SetKeyEventAction (struct Input_KeyEvent * keyEvent, int32_t action )
```

**描述**

设置按键事件类型

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件对象 | 
| action | 按键事件类型 | 


### OH_Input_SetKeyEventActionTime()

```
void OH_Input_SetKeyEventActionTime (struct Input_KeyEvent * keyEvent, int64_t actionTime )
```

**描述**

设置按键事件发生的时间

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件对象 | 
| actionTime | 按键事件发生的时间 | 


### OH_Input_SetKeyEventKeyCode()

```
void OH_Input_SetKeyEventKeyCode (struct Input_KeyEvent * keyEvent, int32_t keyCode )
```

**描述**

设置按键事件的键值

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 按键事件对象 | 
| keyCode | 按键的键值 | 


### OH_Input_SetKeyPressed()

```
void OH_Input_SetKeyPressed (struct Input_KeyState * keyState, int32_t keyAction )
```

**描述**

设置按键状态对象的按键是否按下。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyState | 按键状态的枚举对象 | 
| keyAction | 按键是否按下 | 


### OH_Input_SetKeySwitch()

```
void OH_Input_SetKeySwitch (struct Input_KeyState * keyState, int32_t keySwitch )
```

**描述**

设置按键状态对象的按键开关。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyState | 按键状态的枚举对象，具体请参考{\@Link Input_KeyStateAction} | 
| keySwitch | 按键开关。 | 


### OH_Input_SetMouseEventAction()

```
void OH_Input_SetMouseEventAction (struct Input_MouseEvent * mouseEvent, int32_t action )
```

**描述**

设置鼠标事件的动作

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 
| action | 鼠标的动作 | 


### OH_Input_SetMouseEventActionTime()

```
void OH_Input_SetMouseEventActionTime (struct Input_MouseEvent * mouseEvent, int64_t actionTime )
```

**描述**

设置鼠标事件发生的时间

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 
| actionTime | 鼠标事件发生的时间 | 


### OH_Input_SetMouseEventAxisType()

```
void OH_Input_SetMouseEventAxisType (struct Input_MouseEvent * mouseEvent, int32_t axisType )
```

**描述**

设置鼠标轴事件的类型

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 
| axisType | 轴类型，比如垂直轴、水平轴。 | 


### OH_Input_SetMouseEventAxisValue()

```
void OH_Input_SetMouseEventAxisValue (struct Input_MouseEvent * mouseEvent, float axisValue )
```

**描述**

设置鼠标轴事件的值

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 
| axisType | 轴事件的值，正数向前滚动，负数向后滚动。 | 


### OH_Input_SetMouseEventButton()

```
void OH_Input_SetMouseEventButton (struct Input_MouseEvent * mouseEvent, int32_t button )
```

**描述**

设置鼠标事件的按键

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 
| button | 鼠标按键 | 


### OH_Input_SetMouseEventDisplayX()

```
void OH_Input_SetMouseEventDisplayX (struct Input_MouseEvent * mouseEvent, int32_t displayX )
```

**描述**

设置鼠标事件的屏幕横坐标

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 
| displayX | 屏幕横坐标 | 


### OH_Input_SetMouseEventDisplayY()

```
void OH_Input_SetMouseEventDisplayY (struct Input_MouseEvent * mouseEvent, int32_t displayY )
```

**描述**

设置鼠标事件的屏幕纵坐标

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mouseEvent | 鼠标事件对象 | 
| displayY | 屏幕纵坐标 | 


### OH_Input_SetTouchEventAction()

```
void OH_Input_SetTouchEventAction (struct Input_TouchEvent * touchEvent, int32_t action )
```

**描述**

设置触屏事件的动作

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 
| 触屏的动作 |  | 


### OH_Input_SetTouchEventActionTime()

```
void OH_Input_SetTouchEventActionTime (struct Input_TouchEvent * touchEvent, int64_t actionTime )
```

**描述**

设置触摸事件发生的时间

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| keyEvent | 触屏事件对象 | 
| actionTime | 触摸事件发生的时间 | 


### OH_Input_SetTouchEventDisplayX()

```
void OH_Input_SetTouchEventDisplayX (struct Input_TouchEvent * touchEvent, int32_t displayX )
```

**描述**

设置触屏事件的屏幕横坐标

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 
| displayX | 触屏的屏幕横坐标 | 


### OH_Input_SetTouchEventDisplayY()

```
void OH_Input_SetTouchEventDisplayY (struct Input_TouchEvent * touchEvent, int32_t displayY )
```

**描述**

设置触屏事件的屏幕纵坐标

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 
| displayY | 触屏的屏幕纵坐标 | 


### OH_Input_SetTouchEventFingerId()

```
void OH_Input_SetTouchEventFingerId (struct Input_TouchEvent * touchEvent, int32_t id )
```

**描述**

设置触屏事件的手指ID

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| touchEvent | 触屏事件对象 | 
| id | 触屏的手指ID | 
