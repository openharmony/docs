# oh_key_code.h

## 概述

按键设备的键码值。

**库：** libohinput.so

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**相关模块：** [input](capi-input.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Input_KeyCode](#input_keycode) | Input_KeyCode | 键码值。 |

## 枚举类型说明

### Input_KeyCode

```
enum Input_KeyCode
```

**描述**

键码值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| KEYCODE_UNKNOWN = -1 | 未知按键 |
| KEYCODE_FN = 0 | 功能（Fn）键 |
| KEYCODE_VOLUME_UP = 16 | 音量增加键 |
| KEYCODE_VOLUME_DOWN = 17 | 音量减小键 |
| KEYCODE_POWER = 18 | 电源键 |
| KEYCODE_CAMERA = 19 | 拍照键 |
| KEYCODE_VOLUME_MUTE = 22 | 扬声器静音键 |
| KEYCODE_MUTE = 23 | 话筒静音键 |
| KEYCODE_BRIGHTNESS_UP = 40 | 亮度调节按键：调亮 |
| KEYCODE_BRIGHTNESS_DOWN = 41 | 亮度调节按键：调暗 |
| KEYCODE_0 = 2000 | 按键'0' |
| KEYCODE_1 = 2001 | 按键'1' |
| KEYCODE_2 = 2002 | 按键'2' |
| KEYCODE_3 = 2003 | 按键'3' |
| KEYCODE_4 = 2004 | 按键'4' |
| KEYCODE_5 = 2005 | 按键'5' |
| KEYCODE_6 = 2006 | 按键'6' |
| KEYCODE_7 = 2007 | 按键'7' |
| KEYCODE_8 = 2008 | 按键'8' |
| KEYCODE_9 = 2009 | 按键'9' |
| KEYCODE_STAR = 2010 | 按键'*' |
| KEYCODE_POUND = 2011 | 按键'#' |
| KEYCODE_DPAD_UP = 2012 | 导航键：向上 |
| KEYCODE_DPAD_DOWN = 2013 | 导航键：向下 |
| KEYCODE_DPAD_LEFT = 2014 | 导航键：向左 |
| KEYCODE_DPAD_RIGHT = 2015 | 导航键：向右 |
| KEYCODE_DPAD_CENTER = 2016 | 导航键：确定键 |
| KEYCODE_A = 2017 | 按键'A' |
| KEYCODE_B = 2018 | 按键'B' |
| KEYCODE_C = 2019 | 按键'C' |
| KEYCODE_D = 2020 | 按键'D' |
| KEYCODE_E = 2021 | 按键'E' |
| KEYCODE_F = 2022 | 按键'F' |
| KEYCODE_G = 2023 | 按键'G' |
| KEYCODE_H = 2024 | 按键'H' |
| KEYCODE_I = 2025 | 按键'I' |
| KEYCODE_J = 2026 | 按键'J' |
| KEYCODE_K = 2027 | 按键'K' |
| KEYCODE_L = 2028 | 按键'L' |
| KEYCODE_M = 2029 | 按键'M' |
| KEYCODE_N = 2030 | 按键'N' |
| KEYCODE_O = 2031 | 按键'O' |
| KEYCODE_P = 2032 | 按键'P' |
| KEYCODE_Q = 2033 | 按键'Q' |
| KEYCODE_R = 2034 | 按键'R' |
| KEYCODE_S = 2035 | 按键'S' |
| KEYCODE_T = 2036 | 按键'T' |
| KEYCODE_U = 2037 | 按键'U' |
| KEYCODE_V = 2038 | 按键'V' |
| KEYCODE_W = 2039 | 按键'W' |
| KEYCODE_X = 2040 | 按键'X' |
| KEYCODE_Y = 2041 | 按键'Y' |
| KEYCODE_Z = 2042 | 按键'Z' |
| KEYCODE_COMMA = 2043 | 按键',' |
| KEYCODE_PERIOD = 2044 | 按键'.' |
| KEYCODE_ALT_LEFT = 2045 | 左Alt键 |
| KEYCODE_ALT_RIGHT = 2046 | 右Alt键 |
| KEYCODE_SHIFT_LEFT = 2047 | 左Shift键 |
| KEYCODE_SHIFT_RIGHT = 2048 | 右Shift键 |
| KEYCODE_TAB = 2049 | Tab键 |
| KEYCODE_SPACE = 2050 | 空格键 |
| KEYCODE_SYM = 2051 | 符号修改器按键 |
| KEYCODE_EXPLORER = 2052 | 浏览器功能键，此键用于启动浏览器应用程序 |
| KEYCODE_ENVELOPE = 2053 | 电子邮件功能键，此键用于启动电子邮件应用程序 |
| KEYCODE_ENTER = 2054 | 回车键 |
| KEYCODE_DEL = 2055 | 退格键 |
| KEYCODE_GRAVE = 2056 | 按键'`' |
| KEYCODE_MINUS = 2057 | 按键'-' |
| KEYCODE_EQUALS = 2058 | 按键'=' |
| KEYCODE_LEFT_BRACKET = 2059 | 按键'[' |
| KEYCODE_RIGHT_BRACKET = 2060 | 按键']' |
| KEYCODE_BACKSLASH = 2061 | 按键'\' |
| KEYCODE_SEMICOLON = 2062 | 按键';' |
| KEYCODE_APOSTROPHE = 2063 | 按键''' (单引号) |
| KEYCODE_SLASH = 2064 | 按键'/' |
| KEYCODE_AT = 2065 | 按键'@' |
| KEYCODE_PLUS = 2066 | 按键'+' |
| KEYCODE_MENU = 2067 | 菜单键 |
| KEYCODE_PAGE_UP = 2068 | 向上翻页键 |
| KEYCODE_PAGE_DOWN = 2069 | 向下翻页键 |
| KEYCODE_ESCAPE = 2070 | ESC键 |
| KEYCODE_FORWARD_DEL = 2071 | 删除键 |
| KEYCODE_CTRL_LEFT = 2072 | 左Ctrl键 |
| KEYCODE_CTRL_RIGHT = 2073 | 右Ctrl键 |
| KEYCODE_CAPS_LOCK = 2074 | 大写锁定键 |
| KEYCODE_SCROLL_LOCK = 2075 | 滚动锁定键 |
| KEYCODE_META_LEFT = 2076 | 左元修改器键 |
| KEYCODE_META_RIGHT = 2077 | 右元修改器键 |
| KEYCODE_FUNCTION = 2078 | 功能键 |
| KEYCODE_SYSRQ = 2079 | 系统请求/打印屏幕键 |
| KEYCODE_BREAK = 2080 | Break/Pause键 |
| KEYCODE_MOVE_HOME = 2081 | 光标移动到开始键 |
| KEYCODE_MOVE_END = 2082 | 光标移动到末尾键 |
| KEYCODE_INSERT = 2083 | 插入键 |
| KEYCODE_FORWARD = 2084 | 前进键 |
| KEYCODE_MEDIA_PLAY = 2085 | 多媒体键：播放 |
| KEYCODE_MEDIA_PAUSE = 2086 | 多媒体键：暂停 |
| KEYCODE_MEDIA_CLOSE = 2087 | 多媒体键：关闭 |
| KEYCODE_MEDIA_EJECT = 2088 | 多媒体键：弹出 |
| KEYCODE_MEDIA_RECORD = 2089 | 多媒体键：录音 |
| KEYCODE_F1 = 2090 | 按键'F1' |
| KEYCODE_F2 = 2091 | 按键'F2' |
| KEYCODE_F3 = 2092 | 按键'F3' |
| KEYCODE_F4 = 2093 | 按键'F4' |
| KEYCODE_F5 = 2094 | 按键'F5' |
| KEYCODE_F6 = 2095 | 按键'F6' |
| KEYCODE_F7 = 2096 | 按键'F7' |
| KEYCODE_F8 = 2097 | 按键'F8' |
| KEYCODE_F9 = 2098 | 按键'F9' |
| KEYCODE_F10 = 2099 | 按键'F10' |
| KEYCODE_F11 = 2100 | 按键'F11' |
| KEYCODE_F12 = 2101 | 按键'F12' |
| KEYCODE_NUM_LOCK = 2102 | 小键盘锁 |
| KEYCODE_NUMPAD_0 = 2103 | 小键盘按键'0' |
| KEYCODE_NUMPAD_1 = 2104 | 小键盘按键'1' |
| KEYCODE_NUMPAD_2 = 2105 | 小键盘按键'2' |
| KEYCODE_NUMPAD_3 = 2106 | 小键盘按键'3' |
| KEYCODE_NUMPAD_4 = 2107 | 小键盘按键'4' |
| KEYCODE_NUMPAD_5 = 2108 | 小键盘按键'5' |
| KEYCODE_NUMPAD_6 = 2109 | 小键盘按键'6' |
| KEYCODE_NUMPAD_7 = 2110 | 小键盘按键'7' |
| KEYCODE_NUMPAD_8 = 2111 | 小键盘按键'8' |
| KEYCODE_NUMPAD_9 = 2112 | 小键盘按键'9' |
| KEYCODE_NUMPAD_DIVIDE = 2113 | 小键盘按键'/' |
| KEYCODE_NUMPAD_MULTIPLY = 2114 | 小键盘按键'*' |
| KEYCODE_NUMPAD_SUBTRACT = 2115 | 小键盘按键'-' |
| KEYCODE_NUMPAD_ADD = 2116 | 小键盘按键'+' |
| KEYCODE_NUMPAD_DOT = 2117 | 小键盘按键'.' |
| KEYCODE_NUMPAD_COMMA = 2118 | 小键盘按键',' |
| KEYCODE_NUMPAD_ENTER = 2119 | 小键盘按键回车 |
| KEYCODE_NUMPAD_EQUALS = 2120 | 小键盘按键'=' |
| KEYCODE_NUMPAD_LEFT_PAREN = 2121 | 小键盘按键'(' |
| KEYCODE_NUMPAD_RIGHT_PAREN = 2122 | 小键盘按键')' |
| KEYCODE_DAGGER_CLICK = 3211 | 智能手表智感窗按键单击<br/>**起始版本：** 18 |
| KEYCODE_DAGGER_DOUBLE_CLICK = 3212 | 智能手表智感窗按键双击<br/>**起始版本：** 18 |
| KEYCODE_DAGGER_LONG_PRESS = 3213 | 智能手表智感窗按键长按<br/>**起始版本：** 18 |


