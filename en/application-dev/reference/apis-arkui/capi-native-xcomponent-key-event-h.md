# native_xcomponent_key_event.h

## Overview

Declares the enums used to access native XComponent key events.

**File to include**: <ace/xcomponent/native_xcomponent_key_event.h>

**Library**: libace_ndk.z.so

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Since**: 10

**Related module**: [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_NativeXComponent_KeyCode](#oh_nativexcomponent_keycode) | OH_NativeXComponent_KeyCode | Enumerates the key codes for key events.|
| [OH_NativeXComponent_KeyAction](#oh_nativexcomponent_keyaction) | OH_NativeXComponent_KeyAction | Enumerates the key event actions.|

## Enum Description

### OH_NativeXComponent_KeyCode

```
enum OH_NativeXComponent_KeyCode
```

**Description**


Enumerates the key codes for key events.

**Since**: 10

| Value| Description|
| -- | -- |
| KEY_UNKNOWN = -1 | Unknown key|
| KEY_FN = 0 | Function (Fn) key|
| KEY_HOME = 1 | Function (Home) key|
| KEY_BACK = 2 | Back key|
| KEY_MEDIA_PLAY_PAUSE = 10 | Play/Pause key|
| KEY_MEDIA_STOP = 11 | Stop key|
| KEY_MEDIA_NEXT = 12 | Next key|
| KEY_MEDIA_PREVIOUS = 13 | Previous key|
| KEY_MEDIA_REWIND = 14 | Rewind key|
| KEY_MEDIA_FAST_FORWARD = 15 | Fast forward key|
| KEY_VOLUME_UP = 16 | Volume Up key|
| KEY_VOLUME_DOWN = 17 | Volume Down key|
| KEY_POWER = 18 | Power key|
| KEY_CAMERA = 19 | Camera key|
| KEY_VOLUME_MUTE = 22 | Speaker Mute key|
| KEY_MUTE = 23 | Mute key|
| KEY_BRIGHTNESS_UP = 40 | Brightness Up key.|
| KEY_BRIGHTNESS_DOWN = 41 | Brightness Down key.|
| KEY_0 = 2000 | Key 0|
| KEY_1 = 2001 | Key 1|
| KEY_2 = 2002 | Key 2|
| KEY_3 = 2003 | Key 3|
| KEY_4 = 2004 | Key 4|
| KEY_5 = 2005 | Key 5|
| KEY_6 = 2006 | Key 6|
| KEY_7 = 2007 | Key 7|
| KEY_8 = 2008 | Key 8|
| KEY_9 = 2009 | Key 9|
| KEY_STAR = 2010 | Key *|
| KEY_POUND = 2011 | Key #|
| KEY_DPAD_UP = 2012 | Up key on D-pad.|
| KEY_DPAD_DOWN = 2013 | Down key on D-pad.|
| KEY_DPAD_LEFT = 2014 | Left key on D-pad.|
| KEY_DPAD_RIGHT = 2015 | Right key on D-pad.|
| KEY_DPAD_CENTER = 2016 | Center key on D-pad.|
| KEY_A = 2017 | Key A|
| KEY_B = 2018 | Key B|
| KEY_C = 2019 | Key C|
| KEY_D = 2020 | Key D|
| KEY_E = 2021 | Key E|
| KEY_F = 2022 | Key F|
| KEY_G = 2023 | Key G|
| KEY_H = 2024 | Key H|
| KEY_I = 2025 | Key I|
| KEY_J = 2026 | Key J|
| KEY_K = 2027 | Key K|
| KEY_L = 2028 | Key L|
| KEY_M = 2029 | Key M|
| KEY_N = 2030 | Key N|
| KEY_O = 2031 | Key O|
| KEY_P = 2032 | Key P|
| KEY_Q = 2033 | Key Q|
| KEY_R = 2034 | Key R|
| KEY_S = 2035 | Key S|
| KEY_T = 2036 | Key T|
| KEY_U = 2037 | Key U|
| KEY_V = 2038 | Key V|
| KEY_W = 2039 | Key W|
| KEY_X = 2040 | Key X|
| KEY_Y = 2041 | Key Y|
| KEY_Z = 2042 | Key Z|
| KEY_COMMA = 2043 | Key ,|
| KEY_PERIOD = 2044 | Key .|
| KEY_ALT_LEFT = 2045 | Left Alt key|
| KEY_ALT_RIGHT = 2046 | Right Alt key|
| KEY_SHIFT_LEFT = 2047 | Left Shift key|
| KEY_SHIFT_RIGHT = 2048 | Right Shift key|
| KEY_TAB = 2049 | Tab key|
| KEY_SPACE = 2050 | Space key|
| KEY_SYM = 2051 | Symbol key|
| KEY_EXPLORER = 2052 | Explorer key, which is used to start the explorer application|
| KEY_ENVELOPE = 2053 | Email key, which is used to start the email application|
| KEY_ENTER = 2054 | Enter key|
| KEY_DEL = 2055 | Delete key|
| KEY_GRAVE = 2056 | Key `|
| KEY_MINUS = 2057 | Key -|
| KEY_EQUALS = 2058 | Key =|
| KEY_LEFT_BRACKET = 2059 | Key [|
| KEY_RIGHT_BRACKET = 2060 | Key ]|
| KEY_BACKSLASH = 2061 | Key \|
| KEY_SEMICOLON = 2062 | Key ;|
| KEY_APOSTROPHE = 2063 | Key '|
| KEY_SLASH = 2064 | Key /|
| KEY_AT = 2065 | Key @|
| KEY_PLUS = 2066 | Key +|
| KEY_MENU = 2067 | Menu key|
| KEY_PAGE_UP = 2068 | Page Up key|
| KEY_PAGE_DOWN = 2069 | Page Down key|
| KEY_ESCAPE = 2070 | ESC key.|
| KEY_FORWARD_DEL = 2071 | Forward Delete key|
| KEY_CTRL_LEFT = 2072 | Left Ctrl key|
| KEY_CTRL_RIGHT = 2073 | Right Ctrl key|
| KEY_CAPS_LOCK = 2074 | Caps Lock key|
| KEY_SCROLL_LOCK = 2075 | Scroll Lock key|
| KEY_META_LEFT = 2076 | Left Meta key|
| KEY_META_RIGHT = 2077 | Right Meta key|
| KEY_FUNCTION = 2078 | Function key|
| KEY_SYSRQ = 2079 | System Request/Print Screen key|
| KEY_BREAK = 2080 | Break/Pause key|
| KEY_MOVE_HOME = 2081 | Move to Home key|
| KEY_MOVE_END = 2082 | Move to End key|
| KEY_INSERT = 2083 | Insert key|
| KEY_FORWARD = 2084 | Forward key|
| KEY_MEDIA_PLAY = 2085 | Play key|
| KEY_MEDIA_PAUSE = 2086 | Pause key|
| KEY_MEDIA_CLOSE = 2087 | Close key|
| KEY_MEDIA_EJECT = 2088 | Eject key|
| KEY_MEDIA_RECORD = 2089 | Record key|
| KEY_F1 = 2090 | F1 key|
| KEY_F2 = 2091 | F2 key|
| KEY_F3 = 2092 | F3 key|
| KEY_F4 = 2093 | F4 key|
| KEY_F5 = 2094 | F5 key|
| KEY_F6 = 2095 | F6 key|
| KEY_F7 = 2096 | F7 key|
| KEY_F8 = 2097 | F8 key|
| KEY_F9 = 2098 | F9 key|
| KEY_F10 = 2099 | F10 key|
| KEY_F11 = 2100 | F11 key|
| KEY_F12 = 2101 | F12 key|
| KEY_NUM_LOCK = 2102 | Number Lock key on numeric keypad|
| KEY_NUMPAD_0 = 2103 | Key 0 on numeric keypad|
| KEY_NUMPAD_1 = 2104 | Key 1 on numeric keypad|
| KEY_NUMPAD_2 = 2105 | Key 2 on numeric keypad|
| KEY_NUMPAD_3 = 2106 | Key 3 on numeric keypad|
| KEY_NUMPAD_4 = 2107 | Key 4 on numeric keypad|
| KEY_NUMPAD_5 = 2108 | Key 5 on numeric keypad|
| KEY_NUMPAD_6 = 2109 | Key 6 on numeric keypad|
| KEY_NUMPAD_7 = 2110 | Key 7 on numeric keypad|
| KEY_NUMPAD_8 = 2111 | Key 8 on numeric keypad|
| KEY_NUMPAD_9 = 2112 | Key 9 on numeric keypad|
| KEY_NUMPAD_DIVIDE = 2113 | Key / on numeric keypad|
| KEY_NUMPAD_MULTIPLY = 2114 | Key * on numeric keypad|
| KEY_NUMPAD_SUBTRACT = 2115 | Key - on numeric keypad|
| KEY_NUMPAD_ADD = 2116 | Key + on numeric keypad|
| KEY_NUMPAD_DOT = 2117 | Key . on numeric keypad|
| KEY_NUMPAD_COMMA = 2118 | Key , on numeric keypad|
| KEY_NUMPAD_ENTER = 2119 | Enter key on numeric keypad|
| KEY_NUMPAD_EQUALS = 2120 | Key = on numeric keypad|
| KEY_NUMPAD_LEFT_PAREN = 2121 | Key ( on numeric keypad|
| KEY_NUMPAD_RIGHT_PAREN = 2122 | Key ) on numeric keypad|
| KEY_VIRTUAL_MULTITASK = 2210 | Multi-task key|
| KEY_SLEEP = 2600 | Sleep key|
| KEY_ZENKAKU_HANKAKU = 2601 | Zenkaku/Hankaku key|
| KEY_102ND = 2602 | 102nd key|
| KEY_RO = 2603 | Ro key|
| KEY_KATAKANA = 2604 | Katakana key|
| KEY_HIRAGANA = 2605 | Hiragana key|
| KEY_HENKAN = 2606 | Henkan key|
| KEY_KATAKANA_HIRAGANA = 2607 | Katakana/Hiragana key|
| KEY_MUHENKAN = 2608 | Muhenkan key|
| KEY_LINEFEED = 2609 | Linefeed key|
| KEY_MACRO = 2610 | Macro key|
| KEY_NUMPAD_PLUSMINUS = 2611 | Plus/Minus key on the numeric keypad|
| KEY_SCALE = 2612 | Scale key|
| KEY_HANGUEL = 2613 | Hanguel key|
| KEY_HANJA = 2614 | Hanja key|
| KEY_YEN = 2615 | Yen key|
| KEY_STOP = 2616 | Stop key|
| KEY_AGAIN = 2617 | Again key|
| KEY_PROPS = 2618 | Props key|
| KEY_UNDO = 2619 | Undo key|
| KEY_COPY = 2620 | Copy key|
| KEY_OPEN = 2621 | Open key|
| KEY_PASTE = 2622 | Paste key|
| KEY_FIND = 2623 | Find key|
| KEY_CUT = 2624 | Cut key|
| KEY_HELP = 2625 | Help key|
| KEY_CALC = 2626 | Calc key, which is used to start the calculator application|
| KEY_FILE = 2627 | File key|
| KEY_BOOKMARKS = 2628 | Bookmarks key|
| KEY_NEXT = 2629 | Next key|
| KEY_PLAYPAUSE = 2630 | Play/Pause key|
| KEY_PREVIOUS = 2631 | Previous key|
| KEY_STOPCD = 2632 | Stop CD key|
| KEY_CONFIG = 2634 | Config key|
| KEY_REFRESH = 2635 | Refresh key|
| KEY_EXIT = 2636 | Exit key|
| KEY_EDIT = 2637 | Edit key|
| KEY_SCROLLUP = 2638 | Scroll Up key|
| KEY_SCROLLDOWN = 2639 | Scroll Down key|
| KEY_NEW = 2640 | New key|
| KEY_REDO = 2641 | Redo key|
| KEY_CLOSE = 2642 | Close key|
| KEY_PLAY = 2643 | Play key|
| KEY_BASSBOOST = 2644 | Bass Boost key|
| KEY_PRINT = 2645 | Print key|
| KEY_CHAT = 2646 | Chat key|
| KEY_FINANCE = 2647 | Finance key|
| KEY_CANCEL = 2648 | Cancel key|
| KEY_KBDILLUM_TOGGLE = 2649 | Keyboard Illumination Toggle key|
| KEY_KBDILLUM_DOWN = 2650 | Keyboard Illumination Up key|
| KEY_KBDILLUM_UP = 2651 | Keyboard Illumination Down key|
| KEY_SEND = 2652 | Send key|
| KEY_REPLY = 2653 | Reply key|
| KEY_FORWARDMAIL = 2654 | Forward Mail key|
| KEY_SAVE = 2655 | Save key|
| KEY_DOCUMENTS = 2656 | Documents key|
| KEY_VIDEO_NEXT = 2657 | Next Video key|
| KEY_VIDEO_PREV = 2658 | Previous Video key|
| KEY_BRIGHTNESS_CYCLE = 2659 | Brightness Cycle key|
| KEY_BRIGHTNESS_ZERO = 2660 | Brightness Zero key|
| KEY_DISPLAY_OFF = 2661 | Display Off key|
| KEY_BTN_MISC = 2662 | Misc Button key|
| KEY_GOTO = 2663 | Goto key|
| KEY_INFO = 2664 | Info key|
| KEY_PROGRAM = 2665 | Program key|
| KEY_PVR = 2666 | PVR key|
| KEY_SUBTITLE = 2667 | Subtitle key|
| KEY_FULL_SCREEN = 2668 | Full Screen key|
| KEY_KEYBOARD = 2669 | Keyboard.|
| KEY_ASPECT_RATIO = 2670 | Aspect Ratio key|
| KEY_PC = 2671 | Port Control key|
| KEY_TV = 2672 | TV key|
| KEY_TV2 = 2673 | TV key 2|
| KEY_VCR = 2674 | VCR key|
| KEY_VCR2 = 2675 | VCR key 2|
| KEY_SAT = 2676 | SAT key|
| KEY_CD = 2677 | CD key|
| KEY_TAPE = 2678 | Tape key|
| KEY_TUNER = 2679 | Tuner key|
| KEY_PLAYER = 2680 | Player key|
| KEY_DVD = 2681 | DVD key|
| KEY_AUDIO = 2682 | Audio key|
| KEY_VIDEO = 2683 | Video key|
| KEY_MEMO = 2684 | Memo key|
| KEY_CALENDAR = 2685 | Calendar key|
| KEY_RED = 2686 | Red indicator.|
| KEY_GREEN = 2687 | Green indicator.|
| KEY_YELLOW = 2688 | Yellow indicator.|
| KEY_BLUE = 2689 | Blue indicator.|
| KEY_CHANNELUP = 2690 | Channel Up key|
| KEY_CHANNELDOWN = 2691 | Channel Down key|
| KEY_LAST = 2692 | Last key|
| KEY_RESTART = 2693 | Restart key|
| KEY_SLOW = 2694 | Slow key|
| KEY_SHUFFLE = 2695 | Shuffle key|
| KEY_VIDEOPHONE = 2696 | Videophone key|
| KEY_GAMES = 2697 | Games key|
| KEY_ZOOMIN = 2698 | Zoom in|
| KEY_ZOOMOUT = 2699 | Zoom out|
| KEY_ZOOMRESET = 2700 | Zoom Reset key|
| KEY_WORDPROCESSOR = 2701 | Word Processor key|
| KEY_EDITOR = 2702 | Editor key|
| KEY_SPREADSHEET = 2703 | Spreadsheet key|
| KEY_GRAPHICSEDITOR = 2704 | Graphics Editor key|
| KEY_PRESENTATION = 2705 | Presentation key|
| KEY_DATABASE = 2706 | Database key|
| KEY_NEWS = 2707 | News key|
| KEY_VOICEMAIL = 2708 | Voicemail key|
| KEY_ADDRESSBOOK = 2709 | Address book key|
| KEY_MESSENGER = 2710 | Messenger key|
| KEY_BRIGHTNESS_TOGGLE = 2711 | Brightness Toggle key|
| KEY_SPELLCHECK = 2712 | Spell Check key|
| KEY_COFFEE = 2713 | Coffee key, which is used to launch screen lock or screen saver|
| KEY_MEDIA_REPEAT = 2714 | Media Repeat key|
| KEY_IMAGES = 2715 | Images key|
| KEY_BUTTONCONFIG = 2716 | Button Configuration key|
| KEY_TASKMANAGER = 2717 | Task Manager key|
| KEY_JOURNAL = 2718 | Log key|
| KEY_CONTROLPANEL = 2719 | Control Panel key|
| KEY_APPSELECT = 2720 | App Select key|
| KEY_SCREENSAVER = 2721 | Screen Saver key|
| KEY_ASSISTANT = 2722 | Assistant key|
| KEY_KBD_LAYOUT_NEXT = 2723 | Next Keyboard Layout key|
| KEY_BRIGHTNESS_MIN = 2724 | Min Brightness key|
| KEY_BRIGHTNESS_MAX = 2725 | Max Brightness key|
| KEY_KBDINPUTASSIST_PREV = 2726 | Keyboard Input-assisted Previous key|
| KEY_KBDINPUTASSIST_NEXT = 2727 | Keyboard Input-assisted Next key|
| KEY_KBDINPUTASSIST_PREVGROUP = 2728 | Keyboard Input-assisted Previous key|
| KEY_KBDINPUTASSIST_NEXTGROUP = 2729 | Keyboard Input-assisted Next key|
| KEY_KBDINPUTASSIST_ACCEPT = 2730 | Keyboard Input-assisted Accept key|
| KEY_KBDINPUTASSIST_CANCEL = 2731 | Keyboard Input-assisted Cancel key|
| KEY_FRONT = 2800 | Front key, which is used to launch the windshield defogger|
| KEY_SETUP = 2801 | Setup key|
| KEY_WAKEUP = 2802 | Wakeup key|
| KEY_SENDFILE = 2803 | Send File key|
| KEY_DELETEFILE = 2804 | Delete File key|
| KEY_XFER = 2805 | XFER key, which is used to start file transfer|
| KEY_PROG1 = 2806 | Program key 1|
| KEY_PROG2 = 2807 | Program key 2|
| KEY_MSDOS = 2808 | MS-DOS key|
| KEY_SCREENLOCK = 2809 | Screen Lock key|
| KEY_DIRECTION_ROTATE_DISPLAY = 2810 | Directional Rotation Display key|
| KEY_CYCLEWINDOWS = 2811 | Windows Cycle key|
| KEY_COMPUTER = 2812 | Key|
| KEY_EJECTCLOSECD = 2813 | Eject CD key|
| KEY_ISO = 2814 | ISO key|
| KEY_MOVE = 2815 | Move key|
| KEY_F13 = 2816 | F13 key|
| KEY_F14 = 2817 | F14 key|
| KEY_F15 = 2818 | F15 key|
| KEY_F16 = 2819 | F16 key|
| KEY_F17 = 2820 | F17 key|
| KEY_F18 = 2821 | F18 key|
| KEY_F19 = 2822 | F19 key|
| KEY_F20 = 2823 | F20 key|
| KEY_F21 = 2824 | F21 key|
| KEY_F22 = 2825 | F22 key|
| KEY_F23 = 2826 | F23 key|
| KEY_F24 = 2827 | F24 key|
| KEY_PROG3 = 2828 | Program key 3|
| KEY_PROG4 = 2829 | Program key 4|
| KEY_DASHBOARD = 2830 | Dashboard key|
| KEY_SUSPEND = 2831 | Suspend key|
| KEY_HP = 2832 | HP key|
| KEY_SOUND = 2833 | Sound key|
| KEY_QUESTION = 2834 | Question key|
| KEY_CONNECT = 2836 | Connect key|
| KEY_SPORT = 2837 | Sport key|
| KEY_SHOP = 2838 | Shop key|
| KEY_ALTERASE = 2839 | Alternate key|
| KEY_SWITCHVIDEOMODE = 2841 | Switch Video Mode key (monitor, LCD, and TV, etc.)|
| KEY_BATTERY = 2842 | Battery key|
| KEY_BLUETOOTH = 2843 | Bluetooth key|
| KEY_WLAN = 2844 | WLAN key|
| KEY_UWB = 2845 | Ultra-wideband key|
| KEY_WWAN_WIMAX = 2846 | WWAN WiMAX key|
| KEY_RFKILL = 2847 | RF Kill key|
| KEY_CHANNEL = 3001 | Channel key|
| KEY_BTN_0 = 3100 | Button 0|
| KEY_BTN_1 = 3101 | Button 1|
| KEY_BTN_2 = 3102 | Button 2|
| KEY_BTN_3 = 3103 | Button 3|
| KEY_BTN_4 = 3104 | Button 4|
| KEY_BTN_5 = 3105 | Button 5|
| KEY_BTN_6 = 3106 | Button 6|
| KEY_BTN_7 = 3107 | Button 7|
| KEY_BTN_8 = 3108 | Button 8|
| KEY_BTN_9 = 3109 | Button 9|

### OH_NativeXComponent_KeyAction

```
enum OH_NativeXComponent_KeyAction
```

**Description**


Enumerates the key event actions.

**Since**: 10

| Value| Description|
| -- | -- |
| OH_NATIVEXCOMPONENT_KEY_ACTION_UNKNOWN = -1 | Unknown key action.|
| OH_NATIVEXCOMPONENT_KEY_ACTION_DOWN = 0 | Key press.|
| OH_NATIVEXCOMPONENT_KEY_ACTION_UP | Key release.|
