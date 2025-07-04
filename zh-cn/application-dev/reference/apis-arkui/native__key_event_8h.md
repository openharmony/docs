# native_key_event.h


## 概述

提供NativeKeyEvent相关接口定义。

**库：** libace_ndk.z.so

**引用文件：** <arkui/native_key_event.h>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full 

**起始版本：** 14

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_KeyCode](_ark_u_i___native_module.md#arkui_keycode) {<br/>ARKUI_KEYCODE_UNKNOWN = -1, ARKUI_KEYCODE_FN = 0, ARKUI_KEYCODE_VOLUME_UP = 16, ARKUI_KEYCODE_VOLUME_DOWN = 17,<br/>ARKUI_KEYCODE_POWER = 18, ARKUI_KEYCODE_CAMERA = 19, ARKUI_KEYCODE_VOLUME_MUTE = 22, ARKUI_KEYCODE_MUTE = 23,<br/>ARKUI_KEYCODE_BRIGHTNESS_UP = 40, ARKUI_KEYCODE_BRIGHTNESS_DOWN = 41, ARKUI_KEYCODE_0 = 2000, ARKUI_KEYCODE_1 = 2001,<br/>ARKUI_KEYCODE_2 = 2002, ARKUI_KEYCODE_3 = 2003, ARKUI_KEYCODE_4 = 2004, ARKUI_KEYCODE_5 = 2005,<br/>ARKUI_KEYCODE_6 = 2006, ARKUI_KEYCODE_7 = 2007, ARKUI_KEYCODE_8 = 2008, ARKUI_KEYCODE_9 = 2009,<br/>ARKUI_KEYCODE_STAR = 2010, ARKUI_KEYCODE_POUND = 2011, ARKUI_KEYCODE_DPAD_UP = 2012, ARKUI_KEYCODE_DPAD_DOWN = 2013,<br/>ARKUI_KEYCODE_DPAD_LEFT = 2014, ARKUI_KEYCODE_DPAD_RIGHT = 2015, ARKUI_KEYCODE_DPAD_CENTER = 2016, ARKUI_KEYCODE_A = 2017,<br/>ARKUI_KEYCODE_B = 2018, ARKUI_KEYCODE_C = 2019, ARKUI_KEYCODE_D = 2020, ARKUI_KEYCODE_E = 2021,<br/>ARKUI_KEYCODE_F = 2022, ARKUI_KEYCODE_G = 2023, ARKUI_KEYCODE_H = 2024, ARKUI_KEYCODE_I = 2025,<br/>ARKUI_KEYCODE_J = 2026, ARKUI_KEYCODE_K = 2027, ARKUI_KEYCODE_L = 2028, ARKUI_KEYCODE_M = 2029,<br/>ARKUI_KEYCODE_N = 2030, ARKUI_KEYCODE_O = 2031, ARKUI_KEYCODE_P = 2032, ARKUI_KEYCODE_Q = 2033,<br/>ARKUI_KEYCODE_R = 2034, ARKUI_KEYCODE_S = 2035, ARKUI_KEYCODE_T = 2036, ARKUI_KEYCODE_U = 2037,<br/>ARKUI_KEYCODE_V = 2038, ARKUI_KEYCODE_W = 2039, ARKUI_KEYCODE_X = 2040, ARKUI_KEYCODE_Y = 2041,<br/>ARKUI_KEYCODE_Z = 2042, ARKUI_KEYCODE_COMMA = 2043, ARKUI_KEYCODE_PERIOD = 2044, ARKUI_KEYCODE_ALT_LEFT = 2045,<br/>ARKUI_KEYCODE_ALT_RIGHT = 2046, ARKUI_KEYCODE_SHIFT_LEFT = 2047, ARKUI_KEYCODE_SHIFT_RIGHT = 2048, ARKUI_KEYCODE_TAB = 2049,<br/>ARKUI_KEYCODE_SPACE = 2050, ARKUI_KEYCODE_SYM = 2051, ARKUI_KEYCODE_EXPLORER = 2052, ARKUI_KEYCODE_ENVELOPE = 2053,<br/>ARKUI_KEYCODE_ENTER = 2054, ARKUI_KEYCODE_DEL = 2055, ARKUI_KEYCODE_GRAVE = 2056, ARKUI_KEYCODE_MINUS = 2057,<br/>ARKUI_KEYCODE_EQUALS = 2058, ARKUI_KEYCODE_LEFT_BRACKET = 2059, ARKUI_KEYCODE_RIGHT_BRACKET = 2060, ARKUI_KEYCODE_BACKSLASH = 2061,<br/>ARKUI_KEYCODE_SEMICOLON = 2062, ARKUI_KEYCODE_APOSTROPHE = 2063, ARKUI_KEYCODE_SLASH = 2064, ARKUI_KEYCODE_AT = 2065,<br/>ARKUI_KEYCODE_PLUS = 2066, ARKUI_KEYCODE_MENU = 2067, ARKUI_KEYCODE_PAGE_UP = 2068, ARKUI_KEYCODE_PAGE_DOWN = 2069,<br/>ARKUI_KEYCODE_ESCAPE = 2070, ARKUI_KEYCODE_FORWARD_DEL = 2071, ARKUI_KEYCODE_CTRL_LEFT = 2072, ARKUI_KEYCODE_CTRL_RIGHT = 2073,<br/>ARKUI_KEYCODE_CAPS_LOCK = 2074, ARKUI_KEYCODE_SCROLL_LOCK = 2075, ARKUI_KEYCODE_META_LEFT = 2076, ARKUI_KEYCODE_META_RIGHT = 2077,<br/>ARKUI_KEYCODE_FUNCTION = 2078, ARKUI_KEYCODE_SYSRQ = 2079, ARKUI_KEYCODE_BREAK = 2080, ARKUI_KEYCODE_MOVE_HOME = 2081,<br/>ARKUI_KEYCODE_MOVE_END = 2082, ARKUI_KEYCODE_INSERT = 2083, ARKUI_KEYCODE_FORWARD = 2084, ARKUI_KEYCODE_MEDIA_PLAY = 2085,<br/>ARKUI_KEYCODE_MEDIA_PAUSE = 2086, ARKUI_KEYCODE_MEDIA_CLOSE = 2087, ARKUI_KEYCODE_MEDIA_EJECT = 2088, ARKUI_KEYCODE_MEDIA_RECORD = 2089,<br/>ARKUI_KEYCODE_F1 = 2090, ARKUI_KEYCODE_F2 = 2091, ARKUI_KEYCODE_F3 = 2092, ARKUI_KEYCODE_F4 = 2093,<br/>ARKUI_KEYCODE_F5 = 2094, ARKUI_KEYCODE_F6 = 2095, ARKUI_KEYCODE_F7 = 2096, ARKUI_KEYCODE_F8 = 2097,<br/>ARKUI_KEYCODE_F9 = 2098, ARKUI_KEYCODE_F10 = 2099, ARKUI_KEYCODE_F11 = 2100, ARKUI_KEYCODE_F12 = 2101,<br/>ARKUI_KEYCODE_NUM_LOCK = 2102, ARKUI_KEYCODE_NUMPAD_0 = 2103, ARKUI_KEYCODE_NUMPAD_1 = 2104, ARKUI_KEYCODE_NUMPAD_2 = 2105,<br/>ARKUI_KEYCODE_NUMPAD_3 = 2106, ARKUI_KEYCODE_NUMPAD_4 = 2107, ARKUI_KEYCODE_NUMPAD_5 = 2108, ARKUI_KEYCODE_NUMPAD_6 = 2109,<br/>ARKUI_KEYCODE_NUMPAD_7 = 2110, ARKUI_KEYCODE_NUMPAD_8 = 2111, ARKUI_KEYCODE_NUMPAD_9 = 2112, ARKUI_KEYCODE_NUMPAD_DIVIDE = 2113,<br/>ARKUI_KEYCODE_NUMPAD_MULTIPLY = 2114, ARKUI_KEYCODE_NUMPAD_SUBTRACT = 2115, ARKUI_KEYCODE_NUMPAD_ADD = 2116, ARKUI_KEYCODE_NUMPAD_DOT = 2117,<br/>ARKUI_KEYCODE_NUMPAD_COMMA = 2118, ARKUI_KEYCODE_NUMPAD_ENTER = 2119, ARKUI_KEYCODE_NUMPAD_EQUALS = 2120, ARKUI_KEYCODE_NUMPAD_LEFT_PAREN = 2121,<br/>ARKUI_KEYCODE_NUMPAD_RIGHT_PAREN = 2122, ARKUI_KEYCODE_BUTTON_A = 2301, ARKUI_KEYCODE_BUTTON_B = 2302, ARKUI_KEYCODE_BUTTON_X = 2304,<br/>ARKUI_KEYCODE_BUTTON_Y = 2305, ARKUI_KEYCODE_BUTTON_L1 = 2307, ARKUI_KEYCODE_BUTTON_R1 = 2308, ARKUI_KEYCODE_BUTTON_L2 = 2309,<br/>ARKUI_KEYCODE_BUTTON_R2 = 2310, ARKUI_KEYCODE_BUTTON_SELECT = 2311, ARKUI_KEYCODE_BUTTON_START = 2312, ARKUI_KEYCODE_BUTTON_MODE = 2313,<br/>ARKUI_KEYCODE_BUTTON_THUMBL = 2314, ARKUI_KEYCODE_BUTTON_THUMBR = 2315<br/>} | 按键事件的键码。  | 
| [ArkUI_KeyEventType](_ark_u_i___native_module.md#arkui_keyeventtype) {<br/>ARKUI_KEY_EVENT_UNKNOWN = -1, ARKUI_KEY_EVENT_DOWN = 0, ARKUI_KEY_EVENT_UP = 1, ARKUI_KEY_EVENT_LONG_PRESS = 2,<br/>ARKUI_KEY_EVENT_CLICK = 3<br/>} | 按键的类型。  | 
| [ArkUI_KeySourceType](_ark_u_i___native_module.md#arkui_keysourcetype) { ARKUI_KEY_SOURCE_UNKNOWN = 0, ARKUI_KEY_SOURCE_TYPE_MOUSE = 1, ARKUI_KEY_SOURCE_TYPE_KEYBOARD = 4, ARKUI_KEY_SOURCE_TYPE_JOYSTICK = 5 } | 触发当前按键的输入设备类型。  | 
| [ArkUI_KeyIntension](_ark_u_i___native_module.md#arkui_keyintension) {<br/>ARKUI_KEY_INTENSION_UNKNOWN = -1, ARKUI_KEY_INTENSION_UP = 1, ARKUI_KEY_INTENSION_DOWN = 2, ARKUI_KEY_INTENSION_LEFT = 3,<br/>ARKUI_KEY_INTENSION_RIGHT = 4, ARKUI_KEY_INTENSION_SELECT = 5, ARKUI_KEY_INTENSION_ESCAPE = 6, ARKUI_KEY_INTENSION_BACK = 7,<br/>ARKUI_KEY_INTENSION_FORWARD = 8, ARKUI_KEY_INTENSION_MENU = 9, ARKUI_KEY_INTENSION_HOME = 10, ARKUI_KEY_INTENSION_PAGE_UP = 11,<br/>ARKUI_KEY_INTENSION_PAGE_DOWN = 12, ARKUI_KEY_INTENSION_ZOOM_OUT = 13, ARKUI_KEY_INTENSION_ZOOM_IN = 14, ARKUI_KEY_INTENTION_MEDIA_PLAY_PAUSE = 100,<br/>ARKUI_KEY_INTENTION_MEDIA_FAST_FORWARD = 101, ARKUI_KEY_INTENTION_MEDIA_FAST_PLAYBACK = 103, ARKUI_KEY_INTENTION_MEDIA_NEXT = 104, ARKUI_KEY_INTENTION_MEDIA_PREVIOUS = 105,<br/>ARKUI_KEY_INTENTION_MEDIA_MUTE = 106, ARKUI_KEY_INTENTION_VOLUME_UP = 107, ARKUI_KEY_INTENTION_VOLUME_DOWN = 108, ARKUI_KEY_INTENTION_CALL = 200,<br/>ARKUI_KEY_INTENTION_CAMERA = 300<br/>} | 按键对应的意图。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_KeyEventType](_ark_u_i___native_module.md#arkui_keyeventtype) [OH_ArkUI_KeyEvent_GetType](_ark_u_i___native_module.md#oh_arkui_keyevent_gettype) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取按键的类型。  | 
| int32_t [OH_ArkUI_KeyEvent_GetKeyCode](_ark_u_i___native_module.md#oh_arkui_keyevent_getkeycode) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取按键的键码。  | 
| const char \* [OH_ArkUI_KeyEvent_GetKeyText](_ark_u_i___native_module.md#oh_arkui_keyevent_getkeytext) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取按键的键值。  | 
| [ArkUI_KeySourceType](_ark_u_i___native_module.md#arkui_keysourcetype) [OH_ArkUI_KeyEvent_GetKeySource](_ark_u_i___native_module.md#oh_arkui_keyevent_getkeysource) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前按键的输入设备类型。  | 
| void [OH_ArkUI_KeyEvent_StopPropagation](_ark_u_i___native_module.md#oh_arkui_keyevent_stoppropagation) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool stopPropagation) | 阻塞事件冒泡传递。  | 
| [ArkUI_KeyIntension](_ark_u_i___native_module.md#arkui_keyintension) [OH_ArkUI_KeyEvent_GetKeyIntensionCode](_ark_u_i___native_module.md#oh_arkui_keyevent_getkeyintensioncode) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取按键对应的意图。  | 
| uint32_t [OH_ArkUI_KeyEvent_GetUnicode](_ark_u_i___native_module.md#oh_arkui_keyevent_getunicode) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取按键的unicode码值。支持范围为非空格的基本拉丁字符：0x0021-0x007E，不支持字符为0。组合键场景下，返回当前keyEvent对应按键的unicode码值。  | 
| void [OH_ArkUI_KeyEvent_SetConsumed](_ark_u_i___native_module.md#oh_arkui_keyevent_setconsumed) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool isConsumed) | 在按键事件回调中，设置事件是否被该回调消费。  | 
| void [OH_ArkUI_KeyEvent_Dispatch](_ark_u_i___native_module.md#oh_arkui_keyevent_dispatch) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) \*node, const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 将按键事件分发到特定组件节点。  | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_KeyEvent_IsNumLockOn](_ark_u_i___native_module.md#oh_arkui_keyevent_isnumlockon) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool \*state) | 获取按键事件发生时NumLock的状态。  | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_KeyEvent_IsCapsLockOn](_ark_u_i___native_module.md#oh_arkui_keyevent_iscapslockon) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool \*state) | 获取按键事件发生时CapsLock的状态。  | 
| [ArkUI_ErrorCode](_ark_u_i___native_module.md#arkui_errorcode) [OH_ArkUI_KeyEvent_IsScrollLockOn](_ark_u_i___native_module.md#oh_arkui_keyevent_isscrolllockon) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool \*state) | 获取按键事件发生时ScrollLock的状态。  | 
