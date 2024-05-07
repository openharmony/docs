# Input


## Overview

Provides C APIs for the multimodal input module.

**Since**: 12


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [oh_input_manager.h](oh__input__manager_8h.md) | Provides functions such as event injection and key status query.| 
| [oh_key_code.h](oh__key__code_8h.md) | Defines key codes of the key device.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Input_KeyStateAction](#input_keystateaction) {<br>KEY_DEFAULT = -1, KEY_PRESSED = 0, KEY_RELEASED = 1, KEY_SWITCH_ON = 2,<br>KEY_SWITCH_OFF = 3<br>} | Provides the enum values of the key status.| 
| [Input_Result](#input_result) { INPUT_SUCCESS = 0, INPUT_PERMISSION_DENIED = 201, INPUT_NOT_SYSTEM_APPLICATION = 202, INPUT_PARAMETER_ERROR = 401 } | Provides error codes.| 
| [Input_KeyCode](#input_keycode) {<br>KEYCODE_UNKNOWN = -1, KEYCODE_FN = 0, KEYCODE_VOLUME_UP = 16, KEYCODE_VOLUME_DOWN = 17,<br>KEYCODE_POWER = 18, KEYCODE_CAMERA = 19, KEYCODE_VOLUME_MUTE = 22, KEYCODE_MUTE = 23,<br>KEYCODE_BRIGHTNESS_UP = 40, KEYCODE_BRIGHTNESS_DOWN = 41, KEYCODE_0 = 2000, KEYCODE_1 = 2001,<br>KEYCODE_2 = 2002, KEYCODE_3 = 2003, KEYCODE_4 = 2004, KEYCODE_5 = 2005,<br>KEYCODE_6 = 2006, KEYCODE_7 = 2007, KEYCODE_8 = 2008, KEYCODE_9 = 2009,<br>KEYCODE_STAR = 2010, KEYCODE_POUND = 2011, KEYCODE_DPAD_UP = 2012, KEYCODE_DPAD_DOWN = 2013,<br>KEYCODE_DPAD_LEFT = 2014, KEYCODE_DPAD_RIGHT = 2015, KEYCODE_DPAD_CENTER = 2016, KEYCODE_A = 2017,<br>KEYCODE_B = 2018, KEYCODE_C = 2019, KEYCODE_D = 2020, KEYCODE_E = 2021,<br>KEYCODE_F = 2022, KEYCODE_G = 2023, KEYCODE_H = 2024, KEYCODE_I = 2025,<br>KEYCODE_J = 2026, KEYCODE_K = 2027, KEYCODE_L = 2028, KEYCODE_M = 2029,<br>KEYCODE_N = 2030, KEYCODE_O = 2031, KEYCODE_P = 2032, KEYCODE_Q = 2033,<br>KEYCODE_R = 2034, KEYCODE_S = 2035, KEYCODE_T = 2036, KEYCODE_U = 2037,<br>KEYCODE_V = 2038, KEYCODE_W = 2039, KEYCODE_X = 2040, KEYCODE_Y = 2041,<br>KEYCODE_Z = 2042, KEYCODE_COMMA = 2043, KEYCODE_PERIOD = 2044, KEYCODE_ALT_LEFT = 2045,<br>KEYCODE_ALT_RIGHT = 2046, KEYCODE_SHIFT_LEFT = 2047, KEYCODE_SHIFT_RIGHT = 2048, KEYCODE_TAB = 2049,<br>KEYCODE_SPACE = 2050, KEYCODE_SYM = 2051, KEYCODE_EXPLORER = 2052, KEYCODE_ENVELOPE = 2053,<br>KEYCODE_ENTER = 2054, KEYCODE_DEL = 2055, KEYCODE_GRAVE = 2056, KEYCODE_MINUS = 2057,<br>KEYCODE_EQUALS = 2058, KEYCODE_LEFT_BRACKET = 2059, KEYCODE_RIGHT_BRACKET = 2060, KEYCODE_BACKSLASH = 2061,<br>KEYCODE_SEMICOLON = 2062, KEYCODE_APOSTROPHE = 2063, KEYCODE_SLASH = 2064, KEYCODE_AT = 2065,<br>KEYCODE_PLUS = 2066, KEYCODE_MENU = 2067, KEYCODE_PAGE_UP = 2068, KEYCODE_PAGE_DOWN = 2069,<br>KEYCODE_ESCAPE = 2070, KEYCODE_FORWARD_DEL = 2071, KEYCODE_CTRL_LEFT = 2072, KEYCODE_CTRL_RIGHT = 2073,<br>KEYCODE_CAPS_LOCK = 2074, KEYCODE_SCROLL_LOCK = 2075, KEYCODE_META_LEFT = 2076, KEYCODE_META_RIGHT = 2077,<br>KEYCODE_FUNCTION = 2078, KEYCODE_SYSRQ = 2079, KEYCODE_BREAK = 2080, KEYCODE_MOVE_HOME = 2081,<br>KEYCODE_MOVE_END = 2082, KEYCODE_INSERT = 2083, KEYCODE_FORWARD = 2084, KEYCODE_MEDIA_PLAY = 2085,<br>KEYCODE_MEDIA_PAUSE = 2086, KEYCODE_MEDIA_CLOSE = 2087, KEYCODE_MEDIA_EJECT = 2088, KEYCODE_MEDIA_RECORD = 2089,<br>KEYCODE_F1 = 2090, KEYCODE_F2 = 2091, KEYCODE_F3 = 2092, KEYCODE_F4 = 2093,<br>KEYCODE_F5 = 2094, KEYCODE_F6 = 2095, KEYCODE_F7 = 2096, KEYCODE_F8 = 2097,<br>KEYCODE_F9 = 2098, KEYCODE_F10 = 2099, KEYCODE_F11 = 2100, KEYCODE_F12 = 2101,<br>KEYCODE_NUM_LOCK = 2102, KEYCODE_NUMPAD_0 = 2103, KEYCODE_NUMPAD_1 = 2104, KEYCODE_NUMPAD_2 = 2105,<br>KEYCODE_NUMPAD_3 = 2106, KEYCODE_NUMPAD_4 = 2107, KEYCODE_NUMPAD_5 = 2108, KEYCODE_NUMPAD_6 = 2109,<br>KEYCODE_NUMPAD_7 = 2110, KEYCODE_NUMPAD_8 = 2111, KEYCODE_NUMPAD_9 = 2112, KEYCODE_NUMPAD_DIVIDE = 2113,<br>KEYCODE_NUMPAD_MULTIPLY = 2114, KEYCODE_NUMPAD_SUBTRACT = 2115, KEYCODE_NUMPAD_ADD = 2116, KEYCODE_NUMPAD_DOT = 2117,<br>KEYCODE_NUMPAD_COMMA = 2118, KEYCODE_NUMPAD_ENTER = 2119, KEYCODE_NUMPAD_EQUALS = 2120, KEYCODE_NUMPAD_LEFT_PAREN = 2121,<br>KEYCODE_NUMPAD_RIGHT_PAREN = 2122<br>} | Provides key code values.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [Input_Result](#input_result)[OH_Input_GetKeyState](#oh_input_getkeystate) (struct Input_KeyState \*keyState) | Queries an enum object of the key status.| 
| struct Input_KeyState \* [OH_Input_CreateKeyState](#oh_input_createkeystate) () | Creates an enum object of the key status.| 
| void [OH_Input_DestroyKeyState](#oh_input_destroykeystate) (struct Input_KeyState \*keyState) | Destroys an enum object of the key status.| 
| void [OH_Input_SetKeyCode](#oh_input_setkeycode) (struct Input_KeyState \*keyState, int32_t keyCode) | Sets the key value of a key status enum object.| 
| int32_t [OH_Input_GetKeyCode](#oh_input_getkeycode) (struct Input_KeyState \*keyState) | Obtains the key value of a key status enum object.| 
| void [OH_Input_SetKeyPressed](#oh_input_setkeypressed) (struct Input_KeyState \*keyState, int32_t keyAction) | Sets whether the key specific to a key status enum object is pressed.| 
| int32_t [OH_Input_GetKeyPressed](#oh_input_getkeypressed) (struct Input_KeyState \*keyState) | Checks whether the key specific to a key status enum object is pressed.| 
| void [OH_Input_SetKeySwitch](#oh_input_setkeyswitch) (struct Input_KeyState \*keyState, int32_t keySwitch) | Sets the key switch of the key status enum object.| 
| int32_t [OH_Input_GetKeySwitch](#oh_input_getkeyswitch) (struct Input_KeyState \*keyState) | Obtains the key switch of the key status enum object.| 


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


### Input_Result

```
enum Input_Result
```

**Description**

Provides error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| INPUT_SUCCESS | Operation succeeded.| 
| INPUT_PERMISSION_DENIED | Permission verification failed.| 
| INPUT_NOT_SYSTEM_APPLICATION | Not a system application.| 
| INPUT_PARAMETER_ERROR | Parameter check failed.| 


## Function Description


### OH_Input_CreateKeyState()

```
struct Input_KeyState* OH_Input_CreateKeyState ()
```

**Description**

Creates an enum object of the key status.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Returns**

**Input_KeyEvent** pointer object if the operation is successful; a null pointer otherwise.


### OH_Input_DestroyKeyState()

```
void OH_Input_DestroyKeyState (struct Input_KeyState * keyState)
```

**Description**

Destroys an enum object of the key status.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Enum object of the key pressing status.| 


### OH_Input_GetKeyCode()

```
int32_t OH_Input_GetKeyCode (struct Input_KeyState * keyState)
```

**Description**

Obtains the key value of a key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Enum object of the key pressing status.| 

**Returns**

Key value of the key status enum object.


### OH_Input_GetKeyPressed()

```
int32_t OH_Input_GetKeyPressed (struct Input_KeyState * keyState)
```

**Description**

Checks whether the key specific to a key status enum object is pressed.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Enum object of the key pressing status.| 

**Returns**

Key pressing status of the key status enum object.


### OH_Input_GetKeyState()

```
Input_Result OH_Input_GetKeyState (struct Input_KeyState * keyState)
```

**Description**

Queries an enum object of the key status.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Enum object of the key pressing status.| 

**Returns**

{\@Link Input_Result::INPUT_SUCCESS} if the operation is successful; an error code defined in {\@Link Input_Result} otherwise.


### OH_Input_GetKeySwitch()

```
int32_t OH_Input_GetKeySwitch (struct Input_KeyState * keyState)
```

**Description**

Obtains the key switch of the key status enum object.

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyState | Enum object of the key pressing status.| 

**Returns**

Key switch of the key status enum object.


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
| keyState | Enum object of the key pressing status.| 
| keyCode | Key code.| 


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
| keyState | Enum object of the key pressing status.| 
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
| keyState | Enum object of the key pressing status.| 
| keySwitch | Key switch.| 
