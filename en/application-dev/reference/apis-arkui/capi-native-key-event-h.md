# native_key_event.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## Overview

Declares the APIs of **NativeKeyEvent**.

**File to include**: <arkui/native_key_event.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 14

**Related module**: [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkUI_KeyCode](#arkui_keycode) | ArkUI_KeyCode | Enumerates the key codes for key events.|
| [ArkUI_KeyEventType](#arkui_keyeventtype) | ArkUI_KeyEventType | Enumerates the types of key events.|
| [ArkUI_KeySourceType](#arkui_keysourcetype) | ArkUI_KeySourceType | Enumerates the types of input devices that trigger key events.|
| [ArkUI_KeyIntension](#arkui_keyintension) | ArkUI_KeyIntension | Enumerates the intentions corresponding to key events.|

### Functions

| Name| Description|
| -- | -- |
| [ArkUI_KeyEventType OH_ArkUI_KeyEvent_GetType(const ArkUI_UIInputEvent* event)](#oh_arkui_keyevent_gettype) | Obtains the type of the specified key event.|
| [int32_t OH_ArkUI_KeyEvent_GetKeyCode(const ArkUI_UIInputEvent* event)](#oh_arkui_keyevent_getkeycode) | Obtains the key code from the specified key event.|
| [const char *OH_ArkUI_KeyEvent_GetKeyText(const ArkUI_UIInputEvent* event)](#oh_arkui_keyevent_getkeytext) | Obtains the key value from the specified key event.|
| [ArkUI_KeySourceType OH_ArkUI_KeyEvent_GetKeySource(const ArkUI_UIInputEvent* event)](#oh_arkui_keyevent_getkeysource) | Obtains the type of input device that triggers the specified key event.|
| [void OH_ArkUI_KeyEvent_StopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)](#oh_arkui_keyevent_stoppropagation) | Stops the specified key event from bubbling upwards or downwards.|
| [ArkUI_KeyIntension OH_ArkUI_KeyEvent_GetKeyIntensionCode(const ArkUI_UIInputEvent* event)](#oh_arkui_keyevent_getkeyintensioncode) | Obtains the intention code associated with the specified key event.|
| [uint32_t OH_ArkUI_KeyEvent_GetUnicode(const ArkUI_UIInputEvent* event)](#oh_arkui_keyevent_getunicode) | Obtains the Unicode value of the specified key event. Non-space basic Latin characters in the 0x0021-0x007E range are supported. Characters with a value of 0 are not supported. In the case of key combination, this API returns the Unicode value of the key corresponding to the key event.|
| [void OH_ArkUI_KeyEvent_SetConsumed(const ArkUI_UIInputEvent* event, bool isConsumed)](#oh_arkui_keyevent_setconsumed) | Sets whether the specified key event is consumed in the key event callback.|
| [void OH_ArkUI_KeyEvent_Dispatch(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event)](#oh_arkui_keyevent_dispatch) | Dispatches the specified key event to a specific node.|
| [ArkUI_ErrorCode OH_ArkUI_KeyEvent_IsNumLockOn(const ArkUI_UIInputEvent* event, bool* state)](#oh_arkui_keyevent_isnumlockon) | Obtains the state of the NumLock key when the specified key event occurs.|
| [ArkUI_ErrorCode OH_ArkUI_KeyEvent_IsCapsLockOn(const ArkUI_UIInputEvent* event, bool* state)](#oh_arkui_keyevent_iscapslockon) | Obtains the state of the CapsLock key when the specified key event occurs.|
| [ArkUI_ErrorCode OH_ArkUI_KeyEvent_IsScrollLockOn(const ArkUI_UIInputEvent* event, bool* state)](#oh_arkui_keyevent_isscrolllockon) | Obtains the state of the ScrollLock key when the specified key event occurs.|

## Enum Description

### ArkUI_KeyCode

```
enum ArkUI_KeyCode
```

**Description**


Enumerates the key codes for key events.

**Since**: 14

| Value| Description                        |
| -- |----------------------------|
| ARKUI_KEYCODE_UNKNOWN = -1 | Unknown key                     |
| ARKUI_KEYCODE_FN = 0 | Function (Fn) key                  |
| ARKUI_KEYCODE_VOLUME_UP = 16 | Volume Up key                    |
| ARKUI_KEYCODE_VOLUME_DOWN = 17 | Volume Down key                    |
| ARKUI_KEYCODE_POWER = 18 | Power key                      |
| ARKUI_KEYCODE_CAMERA = 19 | Camera key                      |
| ARKUI_KEYCODE_VOLUME_MUTE = 22 | Speaker Mute key                   |
| ARKUI_KEYCODE_MUTE = 23 | Mute key                    |
| ARKUI_KEYCODE_BRIGHTNESS_UP = 40 | Brightness Up key.                |
| ARKUI_KEYCODE_BRIGHTNESS_DOWN = 41 | Brightness Down key.                |
| ARKUI_KEYCODE_0 = 2000 | Key 0                    |
| ARKUI_KEYCODE_1 = 2001 | Key 1                    |
| ARKUI_KEYCODE_2 = 2002 | Key 2                    |
| ARKUI_KEYCODE_3 = 2003 | Key 3                    |
| ARKUI_KEYCODE_4 = 2004 | Key 4                    |
| ARKUI_KEYCODE_5 = 2005 | Key 5                    |
| ARKUI_KEYCODE_6 = 2006 | Key 6                    |
| ARKUI_KEYCODE_7 = 2007 | Key 7                    |
| ARKUI_KEYCODE_8 = 2008 | Key 8                    |
| ARKUI_KEYCODE_9 = 2009 | Key 9                    |
| ARKUI_KEYCODE_STAR = 2010 | Key *                    |
| ARKUI_KEYCODE_POUND = 2011 | Key #                    |
| ARKUI_KEYCODE_DPAD_UP = 2012 | Up key on D-pad.                   |
| ARKUI_KEYCODE_DPAD_DOWN = 2013 | Down key on D-pad.                   |
| ARKUI_KEYCODE_DPAD_LEFT = 2014 | Left key on D-pad.                   |
| ARKUI_KEYCODE_DPAD_RIGHT = 2015 | Right key on D-pad.                   |
| ARKUI_KEYCODE_DPAD_CENTER = 2016 | Center key on D-pad.                  |
| ARKUI_KEYCODE_A = 2017 | Key A                    |
| ARKUI_KEYCODE_B = 2018 | Key B                    |
| ARKUI_KEYCODE_C = 2019 | Key C                    |
| ARKUI_KEYCODE_D = 2020 | Key D                    |
| ARKUI_KEYCODE_E = 2021 | Key E                    |
| ARKUI_KEYCODE_F = 2022 | Key F                    |
| ARKUI_KEYCODE_G = 2023 | Key G                    |
| ARKUI_KEYCODE_H = 2024 | Key H                    |
| ARKUI_KEYCODE_I = 2025 | Key I                    |
| ARKUI_KEYCODE_J = 2026 | Key J                    |
| ARKUI_KEYCODE_K = 2027 | Key K                    |
| ARKUI_KEYCODE_L = 2028 | Key L                    |
| ARKUI_KEYCODE_M = 2029 | Key M                    |
| ARKUI_KEYCODE_N = 2030 | Key N                    |
| ARKUI_KEYCODE_O = 2031 | Key O                    |
| ARKUI_KEYCODE_P = 2032 | Key P                    |
| ARKUI_KEYCODE_Q = 2033 | Key R                    |
| ARKUI_KEYCODE_R = 2034 | Key R                    |
| ARKUI_KEYCODE_S = 2035 | Key S                    |
| ARKUI_KEYCODE_T = 2036 | Key T                    |
| ARKUI_KEYCODE_U = 2037 | Key U                    |
| ARKUI_KEYCODE_V = 2038 | Key V                    |
| ARKUI_KEYCODE_W = 2039 | Key W                    |
| ARKUI_KEYCODE_X = 2040 | Key X                    |
| ARKUI_KEYCODE_Y = 2041 | Key Y                    |
| ARKUI_KEYCODE_Z = 2042 | Key Z                    |
| ARKUI_KEYCODE_COMMA = 2043 | Key ,                    |
| ARKUI_KEYCODE_PERIOD = 2044 | Key .                    |
| ARKUI_KEYCODE_ALT_LEFT = 2045 | Left Alt key                    |
| ARKUI_KEYCODE_ALT_RIGHT = 2046 | Right Alt key                    |
| ARKUI_KEYCODE_SHIFT_LEFT = 2047 | Left Shift key                  |
| ARKUI_KEYCODE_SHIFT_RIGHT = 2048 | Right Shift key                  |
| ARKUI_KEYCODE_TAB = 2049 | Tab key                     |
| ARKUI_KEYCODE_SPACE = 2050 | Space key                      |
| ARKUI_KEYCODE_SYM = 2051 | Symbol key                  |
| ARKUI_KEYCODE_EXPLORER = 2052 | Explorer key, which is used to start the explorer application     |
| ARKUI_KEYCODE_ENVELOPE = 2053 | Email key, which is used to start the email application   |
| ARKUI_KEYCODE_ENTER = 2054 | Enter key                      |
| ARKUI_KEYCODE_DEL = 2055 | Delete key                      |
| ARKUI_KEYCODE_GRAVE = 2056 | Key `                    |
| ARKUI_KEYCODE_MINUS = 2057 | Key -                    |
| ARKUI_KEYCODE_EQUALS = 2058 | Key =                    |
| ARKUI_KEYCODE_LEFT_BRACKET = 2059 | Key [                    |
| ARKUI_KEYCODE_RIGHT_BRACKET = 2060 | Key ]                    |
| ARKUI_KEYCODE_BACKSLASH = 2061 | Key \                   |
| ARKUI_KEYCODE_SEMICOLON = 2062 | Key ;                    |
| ARKUI_KEYCODE_APOSTROPHE = 2063 | Key '              |
| ARKUI_KEYCODE_SLASH = 2064 | Key /                    |
| ARKUI_KEYCODE_AT = 2065 | Key @                    |
| ARKUI_KEYCODE_PLUS = 2066 | Key +                    |
| ARKUI_KEYCODE_MENU = 2067 | Menu key                      |
| ARKUI_KEYCODE_PAGE_UP = 2068 | Page Up key                    |
| ARKUI_KEYCODE_PAGE_DOWN = 2069 | Page Down key                    |
| ARKUI_KEYCODE_ESCAPE = 2070 | ESC key.                     |
| ARKUI_KEYCODE_FORWARD_DEL = 2071 | Forward Delete key                      |
| ARKUI_KEYCODE_CTRL_LEFT = 2072 | Left Ctrl key                   |
| ARKUI_KEYCODE_CTRL_RIGHT = 2073 | Right Ctrl key                   |
| ARKUI_KEYCODE_CAPS_LOCK = 2074 | Caps Lock key                    |
| ARKUI_KEYCODE_SCROLL_LOCK = 2075 | Scroll Lock key                    |
| ARKUI_KEYCODE_META_LEFT = 2076 | Left Meta key                   |
| ARKUI_KEYCODE_META_RIGHT = 2077 | Right Meta key                   |
| ARKUI_KEYCODE_FUNCTION = 2078 | Function key                      |
| ARKUI_KEYCODE_SYSRQ = 2079 | System Request/Print Screen key               |
| ARKUI_KEYCODE_BREAK = 2080 | Break/Pause key             |
| ARKUI_KEYCODE_MOVE_HOME = 2081 | Move to Home key                 |
| ARKUI_KEYCODE_MOVE_END = 2082 | Move to End key                 |
| ARKUI_KEYCODE_INSERT = 2083 | Insert key                      |
| ARKUI_KEYCODE_FORWARD = 2084 | Forward key                      |
| ARKUI_KEYCODE_MEDIA_PLAY = 2085 | Play key                  |
| ARKUI_KEYCODE_MEDIA_PAUSE = 2086 | Pause key                  |
| ARKUI_KEYCODE_MEDIA_CLOSE = 2087 | Close key                  |
| ARKUI_KEYCODE_MEDIA_EJECT = 2088 | Eject key                  |
| ARKUI_KEYCODE_MEDIA_RECORD = 2089 | Record key                  |
| ARKUI_KEYCODE_F1 = 2090 | F1 key                   |
| ARKUI_KEYCODE_F2 = 2091 | F2 key                   |
| ARKUI_KEYCODE_F3 = 2092 | F3 key                   |
| ARKUI_KEYCODE_F4 = 2093 | F4 key                   |
| ARKUI_KEYCODE_F5 = 2094 | F5 key                   |
| ARKUI_KEYCODE_F6 = 2095 | F6 key                   |
| ARKUI_KEYCODE_F7 = 2096 | F7 key                   |
| ARKUI_KEYCODE_F8 = 2097 | F8 key                   |
| ARKUI_KEYCODE_F9 = 2098 | F9 key                   |
| ARKUI_KEYCODE_F10 = 2099 | F10 key                  |
| ARKUI_KEYCODE_F11 = 2100 | F11 key                  |
| ARKUI_KEYCODE_F12 = 2101 | F12 key                  |
| ARKUI_KEYCODE_NUM_LOCK = 2102 | Number Lock key on numeric keypad                     |
| ARKUI_KEYCODE_NUMPAD_0 = 2103 | Key 0 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_1 = 2104 | Key 1 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_2 = 2105 | Key 2 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_3 = 2106 | Key 3 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_4 = 2107 | Key 4 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_5 = 2108 | Key 5 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_6 = 2109 | Key 6 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_7 = 2110 | Key 7 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_8 = 2111 | Key 8 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_9 = 2112 | Key 9 on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_DIVIDE = 2113 | Key / on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_MULTIPLY = 2114 | Key * on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_SUBTRACT = 2115 | Key - on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_ADD = 2116 | Key + on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_DOT = 2117 | Key . on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_COMMA = 2118 | Key , on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_ENTER = 2119 | Enter key on numeric keypad                  |
| ARKUI_KEYCODE_NUMPAD_EQUALS = 2120 | Key = on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_LEFT_PAREN = 2121 | Key ( on numeric keypad                 |
| ARKUI_KEYCODE_NUMPAD_RIGHT_PAREN = 2122 | Key ) on numeric keypad                 |
| ARKUI_KEYCODE_BUTTON_A = 2301 | Joystick key A<br>**Since**: 15|
| ARKUI_KEYCODE_BUTTON_B = 2302 | Joystick key B<br>**Since**: 15                |
| ARKUI_KEYCODE_BUTTON_X = 2304 | Joystick key X<br>**Since**: 15                |
| ARKUI_KEYCODE_BUTTON_Y = 2305 | Joystick key Y<br>**Since**: 15                |
| ARKUI_KEYCODE_BUTTON_L1 = 2307 | Joystick key L1<br>**Since**: 15               |
| ARKUI_KEYCODE_BUTTON_R1 = 2308 | Joystick key R1<br>**Since**: 15               |
| ARKUI_KEYCODE_BUTTON_L2 = 2309 | Joystick key L2<br>**Since**: 15               |
| ARKUI_KEYCODE_BUTTON_R2 = 2310 | Joystick key R2<br>**Since**: 15               |
| ARKUI_KEYCODE_BUTTON_SELECT = 2311 | Joystick key Select<br>**Since**: 15           |
| ARKUI_KEYCODE_BUTTON_START = 2312 | Joystick key Start<br>**Since**: 15            |
| ARKUI_KEYCODE_BUTTON_MODE = 2313 | Joystick key Mode<br>**Since**: 15             |
| ARKUI_KEYCODE_BUTTON_THUMBL = 2314 | Joystick key THUMBL<br>**Since**: 15           |
| ARKUI_KEYCODE_BUTTON_THUMBR = 2315 | Joystick key THUMBR<br>**Since**: 15           |

### ArkUI_KeyEventType

```
enum ArkUI_KeyEventType
```

**Description**


Enumerates the types of key events.

**Since**: 14

| Value| Description|
| -- | -- |
| ARKUI_KEY_EVENT_UNKNOWN = -1 | Unknown type.|
| ARKUI_KEY_EVENT_DOWN = 0 | Key press.|
| ARKUI_KEY_EVENT_UP = 1 | Release of a key.|
| ARKUI_KEY_EVENT_LONG_PRESS = 2 | Long press of a key.|
| ARKUI_KEY_EVENT_CLICK = 3 | Click of a key.|

### ArkUI_KeySourceType

```
enum ArkUI_KeySourceType
```

**Description**


Enumerates the types of input devices that trigger key events.

**Since**: 14

| Value| Description       |
| -- |-----------|
| ARKUI_KEY_SOURCE_UNKNOWN = 0 | Unknown type.    |
| ARKUI_KEY_SOURCE_TYPE_MOUSE = 1 | Mouse.      |
| ARKUI_KEY_SOURCE_TYPE_KEYBOARD = 4 | Keyboard.      |
| ARKUI_KEY_SOURCE_TYPE_JOYSTICK = 5 | Game controller.<br>**Since**: 15|

### ArkUI_KeyIntension

```
enum ArkUI_KeyIntension
```

**Description**


Enumerates the intentions corresponding to key events.

**Since**: 14

| Value| Description|
| -- | -- |
| ARKUI_KEY_INTENSION_UNKNOWN = -1 | Unknown intention.|
| ARKUI_KEY_INTENSION_UP = 1 | Upward.|
| ARKUI_KEY_INTENSION_DOWN = 2 | Downward.|
| ARKUI_KEY_INTENSION_LEFT = 3 | Leftward.|
| ARKUI_KEY_INTENSION_RIGHT = 4 | Rightward.|
| ARKUI_KEY_INTENSION_SELECT = 5 | Select.|
| ARKUI_KEY_INTENSION_ESCAPE = 6 | Return.|
| ARKUI_KEY_INTENSION_BACK = 7 | Back.|
| ARKUI_KEY_INTENSION_FORWARD = 8 | Forward.|
| ARKUI_KEY_INTENSION_MENU = 9 | Menu.|
| ARKUI_KEY_INTENSION_HOME = 10 | Home page.|
| ARKUI_KEY_INTENSION_PAGE_UP = 11 | Previous.|
| ARKUI_KEY_INTENSION_PAGE_DOWN = 12 | Next.|
| ARKUI_KEY_INTENSION_ZOOM_OUT = 13 | Zoom out.|
| ARKUI_KEY_INTENSION_ZOOM_IN = 14 | Zoom in.|
| ARKUI_KEY_INTENTION_MEDIA_PLAY_PAUSE = 100 | Play.|
| ARKUI_KEY_INTENTION_MEDIA_FAST_FORWARD = 101 | Fast-forward.|
| ARKUI_KEY_INTENTION_MEDIA_FAST_PLAYBACK = 103 | Fast playback.|
| ARKUI_KEY_INTENTION_MEDIA_NEXT = 104 | Play the next media asset.|
| ARKUI_KEY_INTENTION_MEDIA_PREVIOUS = 105 | Play the previous media asset.|
| ARKUI_KEY_INTENTION_MEDIA_MUTE = 106 | Mute.|
| ARKUI_KEY_INTENTION_VOLUME_UP = 107 | Volume up.|
| ARKUI_KEY_INTENTION_VOLUME_DOWN = 108 | Volume down.|
| ARKUI_KEY_INTENTION_CALL = 200 | Answer a call.|
| ARKUI_KEY_INTENTION_CAMERA = 300 | Take a photo.|


## Function Description

### OH_ArkUI_KeyEvent_GetType()

```
ArkUI_KeyEventType OH_ArkUI_KeyEvent_GetType(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the type of the specified key event.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_KeyEventType](capi-native-key-event-h.md#arkui_keyeventtype) | Key event type.|

### OH_ArkUI_KeyEvent_GetKeyCode()

```
int32_t OH_ArkUI_KeyEvent_GetKeyCode(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the key code from the specified key event.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Key code.|

### OH_ArkUI_KeyEvent_GetKeyText()

```
const char *OH_ArkUI_KeyEvent_GetKeyText(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the key value from the specified key event.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| const char * | Key value.|

### OH_ArkUI_KeyEvent_GetKeySource()

```
ArkUI_KeySourceType OH_ArkUI_KeyEvent_GetKeySource(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the type of input device that triggers the specified key event.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_KeySourceType](capi-native-key-event-h.md#arkui_keysourcetype) | Input device type.|

### OH_ArkUI_KeyEvent_StopPropagation()

```
void OH_ArkUI_KeyEvent_StopPropagation(const ArkUI_UIInputEvent* event, bool stopPropagation)
```

**Description**


Stops the specified key event from bubbling upwards or downwards.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| bool stopPropagation | Whether to stop event propagation. The value **true** means to stop event propagation, and **false** means the opposite.|

### OH_ArkUI_KeyEvent_GetKeyIntensionCode()

```
ArkUI_KeyIntension OH_ArkUI_KeyEvent_GetKeyIntensionCode(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the intention code associated with the specified key event.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_KeyIntension](capi-native-key-event-h.md#arkui_keyintension) | Intention code associated with the key event.|

### OH_ArkUI_KeyEvent_GetUnicode()

```
uint32_t OH_ArkUI_KeyEvent_GetUnicode(const ArkUI_UIInputEvent* event)
```

**Description**


Obtains the Unicode value of the specified key event. Non-space basic Latin characters in the 0x0021-0x007E range are supported. Characters with a value of 0 are not supported. In the case of key combination, this API returns the Unicode value of the key corresponding to the key event.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | Unicode value.|

### OH_ArkUI_KeyEvent_SetConsumed()

```
void OH_ArkUI_KeyEvent_SetConsumed(const ArkUI_UIInputEvent* event, bool isConsumed)
```

**Description**


Sets whether the specified key event is consumed in the key event callback.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| bool isConsumed | Whether the key event is consumed by the callback. The value **true** means that the key event is consumed, and **false** the opposite.|

### OH_ArkUI_KeyEvent_Dispatch()

```
void OH_ArkUI_KeyEvent_Dispatch(ArkUI_NodeHandle node, const ArkUI_UIInputEvent* event)
```

**Description**


Dispatches the specified key event to a specific node.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [ArkUI_NodeHandle](capi-arkui-nativemodule-arkui-node8h.md) node | Target node.|
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|

### OH_ArkUI_KeyEvent_IsNumLockOn()

```
ArkUI_ErrorCode OH_ArkUI_KeyEvent_IsNumLockOn(const ArkUI_UIInputEvent* event, bool* state)
```

**Description**


Obtains the state of the NumLock key when the specified key event occurs.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| bool* state | Output parameter that returns the state of the NumLock key. The value **true** indicates an activated state, and **false** indicates an inactivated state.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyEvent_IsCapsLockOn()

```
ArkUI_ErrorCode OH_ArkUI_KeyEvent_IsCapsLockOn(const ArkUI_UIInputEvent* event, bool* state)
```

**Description**


Obtains the state of the CapsLock key when the specified key event occurs.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| bool* state | Output parameter that returns the state of the CapsLock key. The value **true** indicates an activated state, and **false** indicates an inactivated state.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|

### OH_ArkUI_KeyEvent_IsScrollLockOn()

```
ArkUI_ErrorCode OH_ArkUI_KeyEvent_IsScrollLockOn(const ArkUI_UIInputEvent* event, bool* state)
```

**Description**


Obtains the state of the ScrollLock key when the specified key event occurs.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [const ArkUI_UIInputEvent](capi-arkui-eventmodule-arkui-uiinputevent.md)* event | Pointer to the target **ArkUI_UIInputEvent** object.|
| bool* state | Output parameter that returns the state of the ScrollLock key. The value **true** indicates an activated state, and **false** indicates an inactivated state.|

**Return value**

| Type| Description|
| -- | -- |
| [ArkUI_ErrorCode](capi-native-type-h.md#arkui_errorcode) | Result code.<br>         Returns [ARKUI_ERROR_CODE_NO_ERROR](capi-native-type-h.md#arkui_errorcode) if the operation is successful.<br>         Returns [ARKUI_ERROR_CODE_PARAM_INVALID](capi-native-type-h.md#arkui_errorcode) if a parameter error occurs.|
