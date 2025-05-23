# oh_key_code.h

## Overview

Defines key codes of the key device.

**Library**: libohinput.so

**System capability**: SystemCapability.MultimodalInput.Input.Core

**Since**: 12

**Related module**: [input](capi-input.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Input_KeyCode](#input_keycode) | Input_KeyCode | Key code value.|

## Enum Description

### Input_KeyCode

```
enum Input_KeyCode
```

**Description**

Enumerates keycode values.

**Since**: 12

| Enum| Description|
| -- | -- |
| KEYCODE_UNKNOWN = -1 | Unknown key.|
| KEYCODE_FN = 0 | Function (Fn) key.|
| KEYCODE_VOLUME_UP = 16 | Volume Up key.|
| KEYCODE_VOLUME_DOWN = 17 | Volume Down key.|
| KEYCODE_POWER = 18 | Power key.|
| KEYCODE_CAMERA = 19 | Camera key.|
| KEYCODE_VOLUME_MUTE = 22 | Speaker Mute key.|
| KEYCODE_MUTE = 23 | Mute key.|
| KEYCODE_BRIGHTNESS_UP = 40 | Brightness Up key|
| KEYCODE_BRIGHTNESS_DOWN = 41 | Brightness Down key|
| KEYCODE_0 = 2000 | Key 0.|
| KEYCODE_1 = 2001 | Key 1.|
| KEYCODE_2 = 2002 | Key 2.|
| KEYCODE_3 = 2003 | Key 3.|
| KEYCODE_4 = 2004 | Key 4.|
| KEYCODE_5 = 2005 | Key 5.|
| KEYCODE_6 = 2006 | Key 6.|
| KEYCODE_7 = 2007 | Key 7.|
| KEYCODE_8 = 2008 | Key 8.|
| KEYCODE_9 = 2009 | Key 9.|
| KEYCODE_STAR = 2010 | Key *|
| KEYCODE_POUND = 2011 | Key #|
| KEYCODE_DPAD_UP = 2012 | Up key on D-pad|
| KEYCODE_DPAD_DOWN = 2013 | Down key on D-pad|
| KEYCODE_DPAD_LEFT = 2014 | Left key on D-pad|
| KEYCODE_DPAD_RIGHT = 2015 | Right key on D-pad|
| KEYCODE_DPAD_CENTER = 2016 | Center key on D-pad|
| KEYCODE_A = 2017 | Key A.|
| KEYCODE_B = 2018 | Key B.|
| KEYCODE_C = 2019 | Key C.|
| KEYCODE_D = 2020 | Key D.|
| KEYCODE_E = 2021 | Key E.|
| KEYCODE_F = 2022 | Key F.|
| KEYCODE_G = 2023 | Key G.|
| KEYCODE_H = 2024 | Key H.|
| KEYCODE_I = 2025 | Key I.|
| KEYCODE_J = 2026 | Key J.|
| KEYCODE_K = 2027 | Key K.|
| KEYCODE_L = 2028 | Key L.|
| KEYCODE_M = 2029 | Key M.|
| KEYCODE_N = 2030 | Key N.|
| KEYCODE_O = 2031 | Key O.|
| KEYCODE_P = 2032 | Key P.|
| KEYCODE_Q = 2033 | Key Q|
| KEYCODE_R = 2034 | Key R.|
| KEYCODE_S = 2035 | Key S.|
| KEYCODE_T = 2036 | Key T.|
| KEYCODE_U = 2037 | Key U.|
| KEYCODE_V = 2038 | Key V.|
| KEYCODE_W = 2039 | Key W.|
| KEYCODE_X = 2040 | Key X.|
| KEYCODE_Y = 2041 | Key Y.|
| KEYCODE_Z = 2042 | Key Z.|
| KEYCODE_COMMA = 2043 | Key ,.|
| KEYCODE_PERIOD = 2044 | Key ..|
| KEYCODE_ALT_LEFT = 2045 | Left Alt key.|
| KEYCODE_ALT_RIGHT = 2046 | Right Alt key.|
| KEYCODE_SHIFT_LEFT = 2047 | Left Shift key.|
| KEYCODE_SHIFT_RIGHT = 2048 | Right Shift key.|
| KEYCODE_TAB = 2049 | Tab key.|
| KEYCODE_SPACE = 2050 | Space key.|
| KEYCODE_SYM = 2051 | Symbol key.|
| KEYCODE_EXPLORER = 2052 | Explorer key, used to start the explorer application|
| KEYCODE_ENVELOPE = 2053 | Email key, used to start the email application|
| KEYCODE_ENTER = 2054 | Enter key.|
| KEYCODE_DEL = 2055 | Delete key.|
| KEYCODE_GRAVE = 2056 | Key `|
| KEYCODE_MINUS = 2057 | Key -.|
| KEYCODE_EQUALS = 2058 | Key =.|
| KEYCODE_LEFT_BRACKET = 2059 | Key [.|
| KEYCODE_RIGHT_BRACKET = 2060 | Key ].|
| KEYCODE_BACKSLASH = 2061 | Key \.|
| KEYCODE_SEMICOLON = 2062 | Key ;.|
| KEYCODE_APOSTROPHE = 2063 | Key '.|
| KEYCODE_SLASH = 2064 | Key /.|
| KEYCODE_AT = 2065 | Key @|
| KEYCODE_PLUS = 2066 | Key +.|
| KEYCODE_MENU = 2067 | Menu key.|
| KEYCODE_PAGE_UP = 2068 | Page Up key.|
| KEYCODE_PAGE_DOWN = 2069 | Page Down key.|
| KEYCODE_ESCAPE = 2070 | ESC key.|
| KEYCODE_FORWARD_DEL = 2071 | Forward Delete key.|
| KEYCODE_CTRL_LEFT = 2072 | Left Ctrl key.|
| KEYCODE_CTRL_RIGHT = 2073 | Right Ctrl key.|
| KEYCODE_CAPS_LOCK = 2074 | Caps Lock key.|
| KEYCODE_SCROLL_LOCK = 2075 | Scroll Lock key.|
| KEYCODE_META_LEFT = 2076 | Left Meta key.|
| KEYCODE_META_RIGHT = 2077 | Right Meta key.|
| KEYCODE_FUNCTION = 2078 | Function key.|
| KEYCODE_SYSRQ = 2079 | System Request/Print Screen key.|
| KEYCODE_BREAK = 2080 | Break/Pause key.|
| KEYCODE_MOVE_HOME = 2081 | Move to Home key.|
| KEYCODE_MOVE_END = 2082 | Move to End key.|
| KEYCODE_INSERT = 2083 | Insert key.|
| KEYCODE_FORWARD = 2084 | Forward key.|
| KEYCODE_MEDIA_PLAY = 2085 | Play key.|
| KEYCODE_MEDIA_PAUSE = 2086 | Pause key|
| KEYCODE_MEDIA_CLOSE = 2087 | Close key|
| KEYCODE_MEDIA_EJECT = 2088 | Eject key|
| KEYCODE_MEDIA_RECORD = 2089 | Record key|
| KEYCODE_F1 = 2090 | F1 key.|
| KEYCODE_F2 = 2091 | F2 key.|
| KEYCODE_F3 = 2092 | F3 key.|
| KEYCODE_F4 = 2093 | F4 key.|
| KEYCODE_F5 = 2094 | F5 key.|
| KEYCODE_F6 = 2095 | F6 key.|
| KEYCODE_F7 = 2096 | F7 key.|
| KEYCODE_F8 = 2097 | F8 key.|
| KEYCODE_F9 = 2098 | F9 key.|
| KEYCODE_F10 = 2099 | F10 key.|
| KEYCODE_F11 = 2100 | F11 key.|
| KEYCODE_F12 = 2101 | F12 key.|
| KEYCODE_NUM_LOCK = 2102 | Number Lock key.|
| KEYCODE_NUMPAD_0 = 2103 | Key 0 on numeric keypad.|
| KEYCODE_NUMPAD_1 = 2104 | Key 1 on numeric keypad.|
| KEYCODE_NUMPAD_2 = 2105 | Key 2 on numeric keypad.|
| KEYCODE_NUMPAD_3 = 2106 | Key 3 on numeric keypad.|
| KEYCODE_NUMPAD_4 = 2107 | Key 4 on numeric keypad.|
| KEYCODE_NUMPAD_5 = 2108 | Key 5 on numeric keypad.|
| KEYCODE_NUMPAD_6 = 2109 | Key 6 on numeric keypad.|
| KEYCODE_NUMPAD_7 = 2110 | Key 7 on numeric keypad.|
| KEYCODE_NUMPAD_8 = 2111 | Key 8 on numeric keypad.|
| KEYCODE_NUMPAD_9 = 2112 | Key 9 on numeric keypad.|
| KEYCODE_NUMPAD_DIVIDE = 2113 | Key / on numeric keypad.|
| KEYCODE_NUMPAD_MULTIPLY = 2114 | Key * on numeric keypad|
| KEYCODE_NUMPAD_SUBTRACT = 2115 | Key - on numeric keypad.|
| KEYCODE_NUMPAD_ADD = 2116 | Key + on numeric keypad.|
| KEYCODE_NUMPAD_DOT = 2117 | Key . on numeric keypad.|
| KEYCODE_NUMPAD_COMMA = 2118 | Key , on numeric keypad.|
| KEYCODE_NUMPAD_ENTER = 2119 | Enter key on numeric keypad.|
| KEYCODE_NUMPAD_EQUALS = 2120 | Key = on numeric keypad.|
| KEYCODE_NUMPAD_LEFT_PAREN = 2121 | Key ( on numeric keypad.|
| KEYCODE_NUMPAD_RIGHT_PAREN = 2122 | Key ) on numeric keypad.|
| KEYCODE_DAGGER_CLICK = 3211 | Dagger click key on the smart watch<br>**Since**: 18|
| KEYCODE_DAGGER_DOUBLE_CLICK = 3212 | Dagger double-click key on the smart watch<br>**Since**: 18|
| KEYCODE_DAGGER_LONG_PRESS = 3213 | Dagger long-press key on the smart watch<br>**Since**: 18|
