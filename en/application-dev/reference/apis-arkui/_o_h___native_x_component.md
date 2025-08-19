# Native XComponent


## Overview

Describes the surface and touch event held by the ArkUI XComponent, which can be used for the EGL/OpenGL ES and media data input and displayed on the ArkUI XComponent. For details, see [Custom Rendering (XComponent)](../../ui/napi-xcomponent-guidelines.md).

> **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Summary


### Files

| Name                                      | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| [native_interface_xcomponent.h](native__interface__xcomponent_8h.md) | Declares the APIs for accessing **NativeXComponent**.|
| [native_xcomponent_key_event.h](native__xcomponent__key__event_8h.md) | Declares the enums used to access **NativeXComponent** key events.|


### Structs

| Name                                      | Description                   |
| ---------------------------------------- | --------------------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) | Describes the touch point of the touch event.         |
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | Describes the touch event.                |
| [OH_NativeXComponent_HistoricalPoint](_o_h___native_x_component___historical_point.md) | Represents a historical touch point.|
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | Describes the mouse event.                |
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | Registers callbacks for the surface lifecycle and touch event.|
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | Registers callbacks for the mouse event.           |
| [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) | Defines the expected frame rate range. |


### Types

| Name                                      | Description                                  |
| ---------------------------------------- | ------------------------------------ |
| [OH_NativeXComponent](#oh_nativexcomponent) | Provides an encapsulated **OH_NativeXComponent** instance.         |
| [OH_NativeXComponent_Callback](#oh_nativexcomponent_callback) | Registers callbacks for the surface lifecycle and touch event.               |
| [OH_NativeXComponent_MouseEvent_Callback](#oh_nativexcomponent_mouseevent_callback) | Registers callbacks for the mouse event.                          |
| [OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) | Provides an encapsulated **OH_NativeXComponent_KeyEvent** instance.|
| [OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo) | Provides an encapsulated instance of extended mouse event information.|
| [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) | Defines surface lifecycle callback functions.|
| [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) | Provides an encapsulated **OH_ArkUI_SurfaceHolder** instance.|
| [OHNativeWindow](#ohnativewindow) | Provides an encapsulated **NativeWindow** instance.|


### Enums

| Name                                      | Description        |
| ---------------------------------------- | ---------- |
| { OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2 } | Enumerates the API access states.|
| [OH_NativeXComponent_TouchEventType](#oh_nativexcomponent_toucheventtype) {<br>OH_NATIVEXCOMPONENT_DOWN = 0, OH_NATIVEXCOMPONENT_UP, OH_NATIVEXCOMPONENT_MOVE, OH_NATIVEXCOMPONENT_CANCEL,<br>OH_NATIVEXCOMPONENT_UNKNOWN<br>} | Enumerates the touch event types.   |
| [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype) {<br>OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN = 0, OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER, OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN, OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER,<br>OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH, OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL, OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH, OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE,<br>OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS<br>} | Enumerates the touch point tool types.  |
| [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype) {<br>OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN = 0, OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE, OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN, OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD,<br>OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK, OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD<br>} | Enumerates the touch event source types.  |
| [OH_NativeXComponent_TouchEvent_SourceTool](#oh_nativexcomponent_touchevent_sourcetool) {<br>OH_NATIVEXCOMPONENT_SOURCETOOL_UNKNOWN = 0, OH_NATIVEXCOMPONENT_SOURCETOOL_FINGER, OH_NATIVEXCOMPONENT_SOURCETOOL_PEN, OH_NATIVEXCOMPONENT_SOURCETOOL_RUBBER,<br>OH_NATIVEXCOMPONENT_SOURCETOOL_BRUSH, OH_NATIVEXCOMPONENT_SOURCETOOL_PENCIL, OH_NATIVEXCOMPONENT_SOURCETOOL_AIRBRUSH, OH_NATIVEXCOMPONENT_SOURCETOOL_MOUSE,<br>OH_NATIVEXCOMPONENT_SOURCETOOL_LENS, OH_NATIVEXCOMPONENT_SOURCETOOL_TOUCHPAD<br>} | Enumerates the source tool types of touch events.|
| [OH_NativeXComponent_MouseEventAction](#oh_nativexcomponent_mouseeventaction) { OH_NATIVEXCOMPONENT_MOUSE_NONE = 0, OH_NATIVEXCOMPONENT_MOUSE_PRESS, OH_NATIVEXCOMPONENT_MOUSE_RELEASE, OH_NATIVEXCOMPONENT_MOUSE_MOVE OH_NATIVEXCOMPONENT_MOUSE_CANCEL } | Enumerates the mouse event actions.   |
| [OH_NativeXComponent_MouseEventButton](#oh_nativexcomponent_mouseeventbutton) {<br>OH_NATIVEXCOMPONENT_NONE_BUTTON = 0, OH_NATIVEXCOMPONENT_LEFT_BUTTON = 0x01, OH_NATIVEXCOMPONENT_RIGHT_BUTTON = 0x02, OH_NATIVEXCOMPONENT_MIDDLE_BUTTON = 0x04,<br>OH_NATIVEXCOMPONENT_BACK_BUTTON = 0x08, OH_NATIVEXCOMPONENT_FORWARD_BUTTON = 0x10<br>} | Enumerates the mouse event buttons.   |
| [OH_NativeXComponent_KeyCode](#oh_nativexcomponent_keycode) {<br>KEY_UNKNOWN = -1, KEY_FN = 0, KEY_HOME = 1, KEY_BACK = 2,KEY_MEDIA_PLAY_PAUSE = 10, KEY_MEDIA_STOP = 11, KEY_MEDIA_NEXT = 12, KEY_MEDIA_PREVIOUS = 13,<br>KEY_MEDIA_REWIND = 14, KEY_MEDIA_FAST_FORWARD = 15, KEY_VOLUME_UP = 16, KEY_VOLUME_DOWN = 17,<br>KEY_POWER = 18, KEY_CAMERA = 19, KEY_VOLUME_MUTE = 22, KEY_MUTE = 23,KEY_BRIGHTNESS_UP = 40, KEY_BRIGHTNESS_DOWN = 41, KEY_0 = 2000, KEY_1 = 2001,<br>KEY_2 = 2002, KEY_3 = 2003, KEY_4 = 2004, KEY_5 = 2005,<br>KEY_6 = 2006, KEY_7 = 2007, KEY_8 = 2008, KEY_9 = 2009,<br>KEY_STAR = 2010, KEY_POUND = 2011, KEY_DPAD_UP = 2012, KEY_DPAD_DOWN = 2013,KEY_DPAD_LEFT = 2014, KEY_DPAD_RIGHT = 2015, KEY_DPAD_CENTER = 2016,<br>KEY_A = 2017,<br>KEY_B = 2018, KEY_C = 2019, KEY_D = 2020, KEY_E = 2021,<br>KEY_F = 2022, KEY_G = 2023, KEY_H = 2024, KEY_I = 2025,<br>KEY_J = 2026, KEY_K = 2027, KEY_L = 2028, KEY_M = 2029,<br>KEY_N = 2030, KEY_O = 2031, KEY_P = 2032, KEY_Q = 2033,<br>KEY_R = 2034, KEY_S = 2035, KEY_T = 2036, KEY_U = 2037,<br>KEY_V = 2038, KEY_W = 2039, KEY_X = 2040, KEY_Y = 2041,<br>KEY_Z = 2042, KEY_COMMA = 2043, KEY_PERIOD = 2044, KEY_ALT_LEFT = 2045,<br>KEY_ALT_RIGHT = 2046, KEY_SHIFT_LEFT = 2047, KEY_SHIFT_RIGHT = 2048, KEY_TAB = 2049,<br>KEY_SPACE = 2050, KEY_SYM = 2051, KEY_EXPLORER = 2052, KEY_ENVELOPE = 2053,<br>KEY_ENTER = 2054, KEY_DEL = 2055, KEY_GRAVE = 2056, KEY_MINUS = 2057,<br>KEY_EQUALS = 2058, KEY_LEFT_BRACKET = 2059, KEY_RIGHT_BRACKET = 2060, KEY_BACKSLASH = 2061,<br>KEY_SEMICOLON = 2062, KEY_APOSTROPHE = 2063, KEY_SLASH = 2064, KEY_AT = 2065,<br>KEY_PLUS = 2066, KEY_MENU = 2067, KEY_PAGE_UP = 2068, KEY_PAGE_DOWN = 2069,<br>KEY_ESCAPE = 2070, KEY_FORWARD_DEL = 2071, KEY_CTRL_LEFT = 2072, KEY_CTRL_RIGHT = 2073,<br>KEY_CAPS_LOCK = 2074, KEY_SCROLL_LOCK = 2075, KEY_META_LEFT = 2076, KEY_META_RIGHT = 2077,<br>KEY_FUNCTION = 2078, KEY_SYSRQ = 2079, KEY_BREAK = 2080, KEY_MOVE_HOME = 2081,<br>KEY_MOVE_END = 2082, KEY_INSERT = 2083, KEY_FORWARD = 2084, KEY_MEDIA_PLAY = 2085,<br>KEY_MEDIA_PAUSE = 2086, KEY_MEDIA_CLOSE = 2087, KEY_MEDIA_EJECT = 2088, KEY_MEDIA_RECORD = 2089,<br>KEY_F1 = 2090, KEY_F2 = 2091, KEY_F3 = 2092, KEY_F4 = 2093,<br>KEY_F5 = 2094, KEY_F6 = 2095, KEY_F7 = 2096, KEY_F8 = 2097,<br>KEY_F9 = 2098, KEY_F10 = 2099, KEY_F11 = 2100, KEY_F12 = 2101,<br>KEY_NUM_LOCK = 2102, KEY_NUMPAD_0 = 2103, KEY_NUMPAD_1 = 2104, KEY_NUMPAD_2 = 2105,<br>KEY_NUMPAD_3 = 2106, KEY_NUMPAD_4 = 2107, KEY_NUMPAD_5 = 2108, KEY_NUMPAD_6 = 2109,<br>KEY_NUMPAD_7 = 2110, KEY_NUMPAD_8 = 2111, KEY_NUMPAD_9 = 2112, KEY_NUMPAD_DIVIDE = 2113,<br>KEY_NUMPAD_MULTIPLY = 2114, KEY_NUMPAD_SUBTRACT = 2115, KEY_NUMPAD_ADD = 2116, KEY_NUMPAD_DOT = 2117,<br>KEY_NUMPAD_COMMA = 2118, KEY_NUMPAD_ENTER = 2119, KEY_NUMPAD_EQUALS = 2120, KEY_NUMPAD_LEFT_PAREN = 2121,<br>KEY_NUMPAD_RIGHT_PAREN = 2122, KEY_VIRTUAL_MULTITASK = 2210, KEY_SLEEP = 2600, KEY_ZENKAKU_HANKAKU = 2601,<br>KEY_102ND = 2602, KEY_RO = 2603, KEY_KATAKANA = 2604, KEY_HIRAGANA = 2605,<br>KEY_HENKAN = 2606, KEY_KATAKANA_HIRAGANA = 2607, KEY_MUHENKAN = 2608, KEY_LINEFEED = 2609,<br>KEY_MACRO = 2610, KEY_NUMPAD_PLUSMINUS = 2611, KEY_SCALE = 2612, KEY_HANGUEL = 2613,<br>KEY_HANJA = 2614, KEY_YEN = 2615, KEY_STOP = 2616, KEY_AGAIN = 2617,<br>KEY_PROPS = 2618, KEY_UNDO = 2619, KEY_COPY = 2620, KEY_OPEN = 2621,<br>KEY_PASTE = 2622, KEY_FIND = 2623, KEY_CUT = 2624, KEY_HELP = 2625,<br>KEY_CALC = 2626, KEY_FILE = 2627, KEY_BOOKMARKS = 2628, KEY_NEXT = 2629,<br>KEY_PLAYPAUSE = 2630, KEY_PREVIOUS = 2631, KEY_STOPCD = 2632, KEY_CONFIG = 2634,<br>KEY_REFRESH = 2635, KEY_EXIT = 2636, KEY_EDIT = 2637, KEY_SCROLLUP = 2638,<br>KEY_SCROLLDOWN = 2639, KEY_NEW = 2640, KEY_REDO = 2641, KEY_CLOSE = 2642,<br>KEY_PLAY = 2643, KEY_BASSBOOST = 2644, KEY_PRINT = 2645, KEY_CHAT = 2646,<br>KEY_FINANCE = 2647, KEY_CANCEL = 2648, KEY_KBDILLUM_TOGGLE = 2649, KEY_KBDILLUM_DOWN = 2650,<br>KEY_KBDILLUM_UP = 2651, KEY_SEND = 2652, KEY_REPLY = 2653, KEY_FORWARDMAIL = 2654,<br>KEY_SAVE = 2655, KEY_DOCUMENTS = 2656, KEY_VIDEO_NEXT = 2657, KEY_VIDEO_PREV = 2658,<br>KEY_BRIGHTNESS_CYCLE = 2659, KEY_BRIGHTNESS_ZERO = 2660, KEY_DISPLAY_OFF = 2661, KEY_BTN_MISC = 2662,<br>KEY_GOTO = 2663, KEY_INFO = 2664, KEY_PROGRAM = 2665, KEY_PVR = 2666,<br>KEY_SUBTITLE = 2667, KEY_FULL_SCREEN = 2668, KEY_KEYBOARD = 2669, KEY_ASPECT_RATIO = 2670,<br>KEY_PC = 2671, KEY_TV = 2672, KEY_TV2 = 2673, KEY_VCR = 2674,<br>KEY_VCR2 = 2675, KEY_SAT = 2676, KEY_CD = 2677, KEY_TAPE = 2678,<br>KEY_TUNER = 2679, KEY_PLAYER = 2680, KEY_DVD = 2681, KEY_AUDIO = 2682,<br>KEY_VIDEO = 2683, KEY_MEMO = 2684, KEY_CALENDAR = 2685, KEY_RED = 2686,<br>KEY_GREEN = 2687, KEY_YELLOW = 2688, KEY_BLUE = 2689, KEY_CHANNELUP = 2690,<br>KEY_CHANNELDOWN = 2691, KEY_LAST = 2692, KEY_RESTART = 2693, KEY_SLOW = 2694,<br>KEY_SHUFFLE = 2695, KEY_VIDEOPHONE = 2696, KEY_GAMES = 2697, KEY_ZOOMIN = 2698,<br>KEY_ZOOMOUT = 2699, KEY_ZOOMRESET = 2700, KEY_WORDPROCESSOR = 2701, KEY_EDITOR = 2702,<br>KEY_SPREADSHEET = 2703, KEY_GRAPHICSEDITOR = 2704, KEY_PRESENTATION = 2705, KEY_DATABASE = 2706,<br>KEY_NEWS = 2707, KEY_VOICEMAIL = 2708, KEY_ADDRESSBOOK = 2709, KEY_MESSENGER = 2710,<br>KEY_BRIGHTNESS_TOGGLE = 2711, KEY_SPELLCHECK = 2712, KEY_COFFEE = 2713, KEY_MEDIA_REPEAT = 2714,<br>KEY_IMAGES = 2715, KEY_BUTTONCONFIG = 2716, KEY_TASKMANAGER = 2717, KEY_JOURNAL = 2718,<br>KEY_CONTROLPANEL = 2719, KEY_APPSELECT = 2720, KEY_SCREENSAVER = 2721, KEY_ASSISTANT = 2722,<br>KEY_KBD_LAYOUT_NEXT = 2723, KEY_BRIGHTNESS_MIN = 2724, KEY_BRIGHTNESS_MAX = 2725, KEY_KBDINPUTASSIST_PREV = 2726,<br>KEY_KBDINPUTASSIST_NEXT = 2727, KEY_KBDINPUTASSIST_PREVGROUP = 2728, KEY_KBDINPUTASSIST_NEXTGROUP = 2729, KEY_KBDINPUTASSIST_ACCEPT = 2730,<br>KEY_KBDINPUTASSIST_CANCEL = 2731, KEY_FRONT = 2800, KEY_SETUP = 2801, KEY_WAKEUP = 2802,<br>KEY_SENDFILE = 2803, KEY_DELETEFILE = 2804, KEY_XFER = 2805, KEY_PROG1 = 2806,<br>KEY_PROG2 = 2807, KEY_MSDOS = 2808, KEY_SCREENLOCK = 2809, KEY_DIRECTION_ROTATE_DISPLAY = 2810,<br>KEY_CYCLEWINDOWS = 2811, KEY_COMPUTER = 2812, KEY_EJECTCLOSECD = 2813, KEY_ISO = 2814,<br>KEY_MOVE = 2815, KEY_F13 = 2816, KEY_F14 = 2817, KEY_F15 = 2818,<br>KEY_F16 = 2819, KEY_F17 = 2820, KEY_F18 = 2821, KEY_F19 = 2822,<br>KEY_F20 = 2823, KEY_F21 = 2824, KEY_F22 = 2825, KEY_F23 = 2826,<br>KEY_F24 = 2827, KEY_PROG3 = 2828, KEY_PROG4 = 2829, KEY_DASHBOARD = 2830,<br>KEY_SUSPEND = 2831, KEY_HP = 2832, KEY_SOUND = 2833, KEY_QUESTION = 2834,<br>KEY_CONNECT = 2836, KEY_SPORT = 2837, KEY_SHOP = 2838, KEY_ALTERASE = 2839,<br>KEY_SWITCHVIDEOMODE = 2841, KEY_BATTERY = 2842, KEY_BLUETOOTH = 2843, KEY_WLAN = 2844,<br>KEY_UWB = 2845, KEY_WWAN_WIMAX = 2846, KEY_RFKILL = 2847, KEY_CHANNEL = 3001,<br>KEY_BTN_0 = 3100, KEY_BTN_1 = 3101, KEY_BTN_2 = 3102, KEY_BTN_3 = 3103,<br>KEY_BTN_4 = 3104, KEY_BTN_5 = 3105, KEY_BTN_6 = 3106, KEY_BTN_7 = 3107,<br>KEY_BTN_8 = 3108, KEY_BTN_9 = 3109<br>} | Enumerates the mouse event key codes.  |
| [OH_NativeXComponent_KeyAction](#oh_nativexcomponent_keyaction) { OH_NATIVEXCOMPONENT_KEY_ACTION_UNKNOWN = -1, OH_NATIVEXCOMPONENT_KEY_ACTION_DOWN = 0, OH_NATIVEXCOMPONENT_KEY_ACTION_UP } | Enumerates the key event actions.   |
|[ArkUI_XComponent_ImageAnalyzerState](#arkui_xcomponent_imageanalyzerstate) { ARKUI_XCOMPONENT_AI_ANALYSIS_FINISHED = 0, ARKUI_XCOMPONENT_AI_ANALYSIS_DISABLED = 110000, ARKUI_XCOMPONENT_AI_ANALYSIS_UNSUPPORTED = 110001, ARKUI_XCOMPONENT_AI_ANALYSIS_ONGOING = 110002, ARKUI_XCOMPONENT_AI_ANALYSIS_STOPPED = 110003}|Enumerates the AI image analyzer error codes of the XComponent.|


### Functions

| Name                                      | Description                                    |
| ---------------------------------------- | -------------------------------------- |
| [OH_NativeXComponent_GetXComponentId](#oh_nativexcomponent_getxcomponentid) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, char \*id, uint64_t \*size) | Obtains the ID of the ArkUI XComponent.           |
| [OH_NativeXComponent_GetXComponentSize](#oh_nativexcomponent_getxcomponentsize) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, uint64_t \*width, uint64_t \*height) | Obtains the size of the surface held by the ArkUI XComponent. |
| [OH_NativeXComponent_GetXComponentOffset](#oh_nativexcomponent_getxcomponentoffset) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, double \*x, double \*y) | Obtains the offset of the surface held by the **XComponent** relative to the upper left corner of its parent component.|
| [OH_NativeXComponent_GetTouchEvent](#oh_nativexcomponent_gettouchevent) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) \*touchEvent) | Obtains the touch event scheduled by the ArkUI XComponent.       |
| [OH_NativeXComponent_GetTouchPointToolType](#oh_nativexcomponent_gettouchpointtooltype) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype) \*toolType) | Obtains the ArkUI XComponent touch point tool type.       |
| [OH_NativeXComponent_GetTouchPointTiltX](#oh_nativexcomponent_gettouchpointtiltx) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltX) | Obtains the angle between the Y-Z plane of the ArkUI XComponent touch point and the x-axis.    |
| [OH_NativeXComponent_GetTouchPointTiltY](#oh_nativexcomponent_gettouchpointtilty) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltY) | Obtains the angle between the X-Z plane of the ArkUI XComponent touch point and the y-axis.    |
| [OH_NativeXComponent_GetTouchPointWindowX](#oh_nativexcomponent_gettouchpointwindowx) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*windowX) | Obtains the X coordinate of the touch point relative to the upper left corner of the application window where the ArkUI XComponent is located.    |
| [OH_NativeXComponent_GetTouchPointWindowY](#oh_nativexcomponent_gettouchpointwindowy) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*windowY) | Obtains the Y coordinate of the touch point relative to the upper left corner of the application window where the ArkUI XComponent is located.    |
| [OH_NativeXComponent_GetTouchPointDisplayX](#oh_nativexcomponent_gettouchpointdisplayx) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*displayX) | Obtains the X coordinate of the touch point relative to the upper left corner of the screen where the ArkUI XComponent is located.    |
| [OH_NativeXComponent_GetTouchPointDisplayY](#oh_nativexcomponent_gettouchpointdisplayy) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*displayY) | Obtains the Y coordinate of the touch point relative to the upper left corner of the screen where the ArkUI XComponent is located.    |
| [OH_NativeXComponent_GetHistoricalPoints](#oh_nativexcomponent_gethistoricalpoints) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, int32_t \*size, [OH_NativeXComponent_HistoricalPoint](_o_h___native_x_component___historical_point.md) \*\*historicalPoints) | Obtains the historical touch points of the XComponent.|
| [OH_NativeXComponent_GetMouseEvent](#oh_nativexcomponent_getmouseevent) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) \*mouseEvent) | Obtains the mouse event scheduled by ArkUI XComponent.       |
| [OH_NativeXComponent_RegisterCallback](#oh_nativexcomponent_registercallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) \*callback) | Registers a callback for this **OH_NativeXComponent** instance.          |
| [OH_NativeXComponent_RegisterMouseEventCallback](#oh_nativexcomponent_registermouseeventcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) \*callback) | Registers the mouse event callback for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_RegisterFocusEventCallback](#oh_nativexcomponent_registerfocuseventcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, void \*window)) | Registers the focus event callback for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_RegisterKeyEventCallback](#oh_nativexcomponent_registerkeyeventcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, void \*window)) | Registers the key event callback for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_RegisterKeyEventCallbackWithResult](#oh_nativexcomponent_registerkeyeventcallbackwithresult) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, bool(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, void \*window)) | Registers a key event callback with a return value for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_RegisterBlurEventCallback](#oh_nativexcomponent_registerblureventcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, void \*window)) | Registers the blur event callback for this **OH_NativeXComponent** instance.      |
| [OH_NativeXComponent_GetKeyEvent](#oh_nativexcomponent_getkeyevent) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) \*\*keyEvent) | Obtains the key event scheduled by the ArkUI XComponent.       |
| [OH_NativeXComponent_GetKeyEventAction](#oh_nativexcomponent_getkeyeventaction) ([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_KeyAction](#oh_nativexcomponent_keyaction) \*action) | Obtains the action of the specified key event.                          |
| [OH_NativeXComponent_GetKeyEventCode](#oh_nativexcomponent_getkeyeventcode) ([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_KeyCode](#oh_nativexcomponent_keycode) \*code) | Obtains the key code of the specified key event.                         |
| [OH_NativeXComponent_GetKeyEventSourceType](#oh_nativexcomponent_getkeyeventsourcetype) ([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype) \*sourceType) | Obtains the source type of the specified key event.                       |
| [OH_NativeXComponent_GetKeyEventDeviceId](#oh_nativexcomponent_getkeyeventdeviceid) ([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) \*keyEvent, int64_t \*deviceId) | Obtains the device ID of the specified key event.                        |
| [OH_NativeXComponent_GetKeyEventTimestamp](#oh_nativexcomponent_getkeyeventtimestamp) ([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) \*keyEvent, int64_t \*timeStamp) | Obtains the timestamp of the specified key event.                         |
| [OH_NativeXComponent_SetExpectedFrameRateRange](#oh_nativexcomponent_setexpectedframeraterange) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) \*range) | Sets the expected frame rate range.                                          |
| [OH_NativeXComponent_RegisterOnFrameCallback](#oh_nativexcomponent_registeronframecallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint64_t timestamp, uint64_t targetTimestamp)) | Registers the display update callback for this **OH_NativeXComponent** instance and enables the callback for each frame.|
| [OH_NativeXComponent_UnregisterOnFrameCallback](#oh_nativexcomponent_unregisteronframecallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component) | Deregisters the display update callback for this **OH_NativeXComponent** instance and disables the callback for each frame.|
| int32_t [OH_NativeXComponent_AttachNativeRootNode](#oh_nativexcomponent_attachnativerootnode) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) root) | Attaches the UI component created through the native API of ArkUI to this **OH_NativeXComponent** instance. |
| int32_t [OH_NativeXComponent_DetachNativeRootNode](#oh_nativexcomponent_detachnativerootnode) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) root) | Detaches the native component of ArkUI from this **OH_NativeXComponent** instance. |
| int32_t [OH_NativeXComponent_RegisterUIInputEventCallback](#oh_nativexcomponent_registeruiinputeventcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) type), [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) type) | Registers a UI input event callback for an **OH_NativeXComponent** instance and enables the callback to be invoked when a UI input event is received. |
| int32_t [OH_NativeXComponent_RegisterOnTouchInterceptCallback](#oh_nativexcomponent_registerontouchinterceptcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_HitTestMode](_ark_u_i___event_module.md#hittestmode)(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event)) | Registers a custom event intercept callback for an **OH_NativeXComponent** and enables the callback during the hit test. |
| int32_t [OH_NativeXComponent_SetNeedSoftKeyboard](#oh_nativexcomponent_setneedsoftkeyboard) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, bool isNeedSoftKeyboard) | Sets whether the soft keyboard is required for an **OH_NativeXComponent** instance. |
| int32_t [OH_NativeXComponent_RegisterSurfaceShowCallback](#oh_nativexcomponent_registersurfaceshowcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, void \*window)) | Registers a surface display callback for an **OH_NativeXComponent** instance. The callback is invoked after the application is switched to the foreground.|
| int32_t [OH_NativeXComponent_RegisterSurfaceHideCallback](#oh_nativexcomponent_registersurfacehidecallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, void \*window)) | Registers a surface hiding callback for an **OH_NativeXComponent** instance. The callback is invoked after the application is switched to the background.|
| int32_t [OH_NativeXComponent_GetTouchEventSourceType](#oh_nativexcomponent_gettoucheventsourcetype) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, int32_t pointId, [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype) \*sourceType) | Obtains the touch event source type of an **OH_NativeXComponent** instance. |
| [OH_NativeXComponent](#oh_nativexcomponent) \* [OH_NativeXComponent_GetNativeXComponent](#oh_nativexcomponent_getnativexcomponent) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Obtains a pointer of the **OH_NativeXComponent** type based on the specified component instance created by the native API. |
| int32_t [OH_NativeXComponent_GetNativeAccessibilityProvider](#oh_nativexcomponent_getnativeaccessibilityprovider)([OH_NativeXComponent](#oh_nativexcomponent)* component, [ArkUI_AccessibilityProvider](./arkui_native_interface_accessibility.md#arkui_accessibilityprovider)** handle); | Obtains a pointer of the **ArkUI_AccessibilityProvider** type based on an **OH_NativeXComponent** instance.|
| int32_t [OH_NativeXComponent_RegisterKeyEventCallbackWithResult](#oh_nativexcomponent_registerkeyeventcallbackwithresult) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, bool(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, void \*window)) | Registers a key event callback with a return value for this **OH_NativeXComponent** instance. |
|int32_t [OH_ArkUI_XComponent_StartImageAnalyzer](#oh_arkui_xcomponent_startimageanalyzer) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData,void (\*callback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_XComponent_ImageAnalyzerState](#arkui_xcomponent_imageanalyzerstate) statusCode, void \*userData))|Starts AI image analysis for this XComponent instance.|
|int32_t [OH_ArkUI_XComponent_StopImageAnalyzer](#oh_arkui_xcomponent_stopimageanalyzer)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|Stops AI image analysis for this XComponent instance.|
|[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* [OH_ArkUI_SurfaceCallback_Create](#oh_arkui_surfacecallback_create)()|Creates an **OH_ArkUI_SurfaceCallback** object.|
|void [OH_ArkUI_SurfaceCallback_Dispose](#oh_arkui_surfacecallback_dispose)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback)|Disposes of an **OH_ArkUI_SurfaceCallback** object.|
|[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* [OH_ArkUI_SurfaceHolder_Create](#oh_arkui_surfaceholder_create)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|Creates an **OH_ArkUI_SurfaceHolder** object for an XComponent.|
|void [OH_ArkUI_SurfaceHolder_Dispose](#oh_arkui_surfaceholder_dispose)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder)|Disposes of an **OH_ArkUI_SurfaceHolder** object.|
|int32_t [OH_ArkUI_SurfaceHolder_SetUserData](#oh_arkui_surfaceholder_setuserdata)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder, void* userData)|Stores custom data in an **OH_ArkUI_SurfaceHolder** instance.|
|void* [OH_ArkUI_SurfaceHolder_GetUserData](#oh_arkui_surfaceholder_getuserdata)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder)|Obtains the custom data stored in an **OH_ArkUI_SurfaceHolder** instance.|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent](#oh_arkui_surfacecallback_setsurfacecreatedevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback, void (\*onSurfaceCreated)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)\* surfaceHolder))|Sets the creation callback event in the surface lifecycle callback.|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent](#oh_arkui_surfacecallback_setsurfacechangedevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback, void (\*onSurfaceChanged)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)\* surfaceHolder, uint64_t width, uint64_t height))|Sets the size change callback event in the surface lifecycle callback.|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent](#oh_arkui_surfacecallback_setsurfacedestroyedevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback, void (\*onSurfaceDestroyed)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)\* surfaceHolder))|Sets the destruction callback event in the surface lifecycle callback.|
|int32_t [OH_ArkUI_SurfaceHolder_AddSurfaceCallback](#oh_arkui_surfaceholder_addsurfacecallback)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder, [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback)|Adds a surface lifecycle callback to an **OH_ArkUI_SurfaceHolder** instance.|
|int32_t [OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback](#oh_arkui_surfaceholder_removesurfacecallback)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder, [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback)|Removes a previously added surface lifecycle callback from an **OH_ArkUI_SurfaceHolder** instance.|
|[OHNativeWindow](#ohnativewindow)* [OH_ArkUI_XComponent_GetNativeWindow](#oh_arkui_xcomponent_getnativewindow)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder)|Obtains the **NativeWindow** instance associated with an **OH_ArkUI_SurfaceHolder** instance.|
|int32_t [OH_ArkUI_XComponent_SetAutoInitialize](#oh_arkui_xcomponent_setautoinitialize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool autoInitialize)|Sets whether the **XComponent** component needs to automatically initialize the surface.|
|int32_t [OH_ArkUI_XComponent_Initialize](#oh_arkui_xcomponent_initialize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|Initializes the surface held by the **XComponent** component.|
|int32_t [OH_ArkUI_XComponent_Finalize](#oh_arkui_xcomponent_finalize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|Destroys the surface held by the **XComponent** component.|
|int32_t [OH_ArkUI_XComponent_IsInitialized](#oh_arkui_xcomponent_isinitialized)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool* isInitialized)|Checks whether the surface held by the **XComponent** component is initialized.|
|int32_t [OH_NativeXComponent_GetExtraMouseEventInfo](#oh_nativexcomponent_getextramouseeventinfo)([OH_NativeXComponent](#oh_nativexcomponent)* component, [OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo)** extraMouseEventInfo)| Obtains extended mouse event information from an **OH_NativeXComponent** instance.|
|int32_t [OH_NativeXComponent_GetMouseEventModifierKeyStates](#oh_nativexcomponent_getmouseeventmodifierkeystates)([OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo)* extraMouseEventInfo, uint64_t* keys)|Obtains the state of modifier keys from an **OH_NativeXComponent_ExtraMouseEventInfo** instance.|
|int32_t [OH_NativeXComponent_GetKeyEventModifierKeyStates](#oh_nativexcomponent_getkeyeventmodifierkeystates)([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)* keyEvent, uint64_t* keys)|Obtains the state of modifier keys from a key event.|
|int32_t [OH_NativeXComponent_GetKeyEventNumLockState](#oh_nativexcomponent_getkeyeventnumlockstate)([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)* keyEvent, bool* isNumLockOn) | Obtains the state of the NumLock key from a key event.|
|int32_t [OH_NativeXComponent_GetKeyEventCapsLockState](#oh_nativexcomponent_getkeyeventcapslockstate)([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)* keyEvent, bool* isCapsLockOn)| Obtains the state of the CapsLock key from a key event.|
|int32_t [OH_NativeXComponent_GetKeyEventScrollLockState](#oh_nativexcomponent_getkeyeventscrolllockstate)([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)* keyEvent, bool* isScrollLockOn) | Obtains the state of the ScrollLock key from a key event.|
|int32_t [OH_ArkUI_XComponent_SetExpectedFrameRateRange](#oh_arkui_xcomponent_setexpectedframeraterange)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) range)|Sets the expected frame rate range for the XComponent.|
|int32_t [OH_ArkUI_XComponent_RegisterOnFrameCallback](#oh_arkui_xcomponent_registeronframecallback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node,void (*callback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, uint64_t timestamp, uint64_t targetTimestamp))|Registers a frame callback function for the XComponent.|
|int32_t [OH_ArkUI_XComponent_UnregisterOnFrameCallback](#oh_arkui_xcomponent_unregisteronframecallback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|Unregisters the frame callback function for the XComponent.|
|int32_t [OH_ArkUI_XComponent_SetNeedSoftKeyboard](#oh_arkui_xcomponent_setneedsoftkeyboard)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool needSoftKeyboard) | Sets whether the soft keyboard is required for the XComponent.|
|[ArkUI_AccessibilityProvider](_o_h___native_x_component.md#oh_arkui_accessibilityprovider_create)* [OH_ArkUI_AccessibilityProvider_Create](#oh_arkui_accessibilityprovider_create)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | Creates an **ArkUI_AccessibilityProvider** instance for the XComponent.|
|void [OH_ArkUI_AccessibilityProvider_Dispose](#oh_arkui_accessibilityprovider_dispose)([ArkUI_AccessibilityProvider](_o_h___native_x_component.md#oh_arkui_accessibilityprovider_create)* provider)|Destroys the [ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider) instance created using [OH_ArkUI_AccessibilityProvider_Create](#oh_arkui_accessibilityprovider_create).|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent](#oh_arkui_surfacecallback_setsurfaceshowevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback,void (\*onSurfaceShow)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder))|Sets a surface display callback for this **OH_ArkUI_SurfaceCallback** instance. The callback is invoked when the application window has returned to the foreground from the background.|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent](#oh_arkui_surfacecallback_setsurfacehideevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback,void (\*onSurfaceHide)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder))|Sets a surface hiding callback for this **OH_ArkUI_SurfaceCallback** instance. The callback is invoked when the application window has entered the background from the foreground.|

### Variables

| Name                                      | Description                            |
| ---------------------------------------- | ------------------------------ |
| [OH_XCOMPONENT_ID_LEN_MAX](#oh_xcomponent_id_len_max) = 128 | Maximum length of the ArkUI XComponent ID. |
| [OH_MAX_TOUCH_POINTS_NUMBER](#oh_max_touch_points_number) = 10 | Maximum number of identifiable touch points in a touch event.           |
| [OH_NativeXComponent_TouchPoint::id](#id-13) = 0 | Unique identifier of the finger.                     |
| [OH_NativeXComponent_TouchPoint::screenX](#screenx-14) = 0.0 | X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.|
| [OH_NativeXComponent_TouchPoint::screenY](#screeny-14) = 0.0 | Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.|
| [OH_NativeXComponent_TouchPoint::x](#x-14) = 0.0 | X coordinate of the touch point relative to the left edge of the XComponent.    |
| [OH_NativeXComponent_TouchPoint::y](#y-14) = 0.0 | Y coordinate of the touch point relative to the upper edge of the XComponent.    |
| [OH_NativeXComponent_TouchPoint::type](#type-13) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | Touch type of the touch event.                    |
| [OH_NativeXComponent_TouchPoint::size](#size-13) = 0.0 | Contact area between the finger pad and the screen.                 |
| [OH_NativeXComponent_TouchPoint::force](#force-13) = 0.0 | Pressure of the touch event.                    |
| [OH_NativeXComponent_TouchPoint::timeStamp](#timestamp-13) = 0 | Timestamp of the touch event.                   |
| [OH_NativeXComponent_TouchPoint::isPressed](#ispressed) = false | Whether the current point is pressed.                     |
| [OH_NativeXComponent_TouchEvent::id](#id-23) = 0 | Unique identifier of the finger.                     |
| [OH_NativeXComponent_TouchEvent::screenX](#screenx-24) = 0.0 | X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.              |
| [OH_NativeXComponent_TouchEvent::screenY](#screeny-24) = 0.0 | Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.              |
| [OH_NativeXComponent_TouchEvent::x](#x-24) = 0.0 | X coordinate of the touch point relative to the left edge of the XComponent.    |
| [OH_NativeXComponent_TouchEvent::y](#y-24) = 0.0 | Y coordinate of the touch point relative to the upper edge of the XComponent.    |
| [OH_NativeXComponent_TouchEvent::type](#type-23) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | Touch type of the touch event.                    |
| [OH_NativeXComponent_TouchEvent::size](#size-23) = 0.0 | Contact area between the finger pad and the screen.                 |
| [OH_NativeXComponent_TouchEvent::force](#force-23) = 0.0 | Pressure of the touch event.                    |
| [OH_NativeXComponent_TouchEvent::deviceId](#deviceid) = 0 | ID of the device where the current touch event is triggered.               |
| [OH_NativeXComponent_TouchEvent::timeStamp](#timestamp-23) = 0 | Timestamp of the touch event.                   |
| [OH_NativeXComponent_TouchEvent::touchPoints](#touchpoints) [OH_MAX_TOUCH_POINTS_NUMBER] | Array of the touch points.                     |
| [OH_NativeXComponent_TouchEvent::numPoints](#numpoints) = 0 | Number of current touch points.                     |
| [OH_NativeXComponent_MouseEvent::x](#x-34) = 0.0 | X coordinate of the clicked point relative to the upper left corner of the component.          |
| [OH_NativeXComponent_MouseEvent::y](#y-34) = 0.0 | Y coordinate of the clicked point relative to the upper left corner of the component.          |
| [OH_NativeXComponent_MouseEvent::screenX](#screenx-34) = 0.0 | X coordinate of the clicked point relative to the upper left corner of the screen.            |
| [OH_NativeXComponent_MouseEvent::screenY](#screeny-34) = 0.0 | Y coordinate of the clicked point relative to the upper left corner of the screen.            |
| [OH_NativeXComponent_MouseEvent::timestamp](#timestamp) = 0 | Timestamp of the mouse event.                   |
| [OH_NativeXComponent_MouseEvent::action](#action) = [OH_NativeXComponent_MouseEventAction::OH_NATIVEXCOMPONENT_MOUSE_NONE](#oh_nativexcomponent_mouseeventaction) | Action of the mouse event.                     |
| [OH_NativeXComponent_MouseEvent::button](#button) = [OH_NativeXComponent_MouseEventButton::OH_NATIVEXCOMPONENT_NONE_BUTTON](#oh_nativexcomponent_mouseeventbutton) | Mouse event button.                       |
| [OH_NativeXComponent_Callback::OnSurfaceCreated](#onsurfacecreated) | Invoked when a surface is created.                 |
| [OH_NativeXComponent_Callback::OnSurfaceChanged](#onsurfacechanged) | Invoked when the surface changes.                |
| [OH_NativeXComponent_Callback::OnSurfaceDestroyed](#onsurfacedestroyed) | Invoked when the surface is destroyed.               |
| [OH_NativeXComponent_Callback::DispatchTouchEvent](#dispatchtouchevent) | Invoked when a touch event is triggered.                  |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent](#dispatchmouseevent) | Invoked when a mouse event is triggered.                  |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent](#dispatchhoverevent) | Invoked when a hover event is triggered.                  |
| [OH_NativeXComponent_HistoricalPoint::id](#id-33) = 0 | Unique identifier of the finger.                     |
| [OH_NativeXComponent_HistoricalPoint::screenX](#screenx-44) = 0.0 | X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.|
| [OH_NativeXComponent_HistoricalPoint::screenY](#screeny-44) = 0.0 | Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.|
| [OH_NativeXComponent_HistoricalPoint::x](#x-44) = 0.0 | X coordinate of the touch point relative to the left edge of the XComponent.          |
| [OH_NativeXComponent_HistoricalPoint::y](#y-44) = 0.0 | Y coordinate of the touch point relative to the upper edge of the XComponent.          |
| [OH_NativeXComponent_HistoricalPoint::type](#type-33) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | Touch type of the touch event.                    |
| [OH_NativeXComponent_HistoricalPoint::size](#size-33) = 0.0 | Contact area between the finger pad and the screen.                 |
| [OH_NativeXComponent_HistoricalPoint::force](#force-33) = 0.0 | Pressure of the touch event.                    |
| [OH_NativeXComponent_HistoricalPoint::timeStamp](#timestamp-33) | Timestamp of the touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.|
| [OH_NativeXComponent_HistoricalPoint::titlX](#titlx) | Angle between the projection on the x-y plane and the z-axis of the touch event.|
| [OH_NativeXComponent_HistoricalPoint::titlY](#titly) | Angle between the projection on the y-z plane and the z-axis of the current touch event.|
| [OH_NativeXComponent_HistoricalPoint::sourceTool](#sourcetool) | Source tool of the touch event.|


## Type Description


### OH_NativeXComponent

```
typedef struct OH_NativeXComponent OH_NativeXComponent
```

**Description**

Provides an encapsulated **OH_NativeXComponent** instance.

**Since**

8


### OH_NativeXComponent_Callback

```
typedef struct OH_NativeXComponent_Callback OH_NativeXComponent_Callback
```

**Description**

Registers callbacks for the surface lifecycle and touch event.

**Since**

8


### OH_NativeXComponent_KeyEvent

```
typedef struct OH_NativeXComponent_KeyEvent OH_NativeXComponent_KeyEvent
```

**Description**

Provides an encapsulated **OH_NativeXComponent_KeyEvent** instance.

> **NOTE**
>
> This struct can be accessed through APIs such as [OH_NativeXComponent_GetKeyEventAction](#oh_nativexcomponent_getkeyeventaction), [OH_NativeXComponent_GetKeyEventCode](#oh_nativexcomponent_getkeyeventcode), [OH_NativeXComponent_GetKeyEventDeviceId](#oh_nativexcomponent_getkeyeventdeviceid), [OH_NativeXComponent_GetKeyEventSourceType](#oh_nativexcomponent_getkeyeventsourcetype), and [OH_NativeXComponent_GetKeyEventTimestamp](#oh_nativexcomponent_getkeyeventtimestamp) to obtain parameters within the struct.

**Since**

10


### OH_NativeXComponent_MouseEvent_Callback

```
typedef struct OH_NativeXComponent_MouseEvent_Callback OH_NativeXComponent_MouseEvent_Callback
```

**Description**

Registers callbacks for the mouse event.

**Since**

9


### OH_ArkUI_SurfaceCallback

```
typedef struct OH_ArkUI_SurfaceCallback OH_ArkUI_SurfaceCallback
```

**Description**

Defines surface lifecycle callback functions.

> **NOTE**
>
> The specific definition of this type is not directly exposed. Instances of this type can be created by calling the [OH_ArkUI_SurfaceCallback_Create](#oh_arkui_surfacecallback_create) API and destroyed by calling the [OH_ArkUI_SurfaceCallback_Dispose](#oh_arkui_surfacecallback_dispose) API.

**Since**

19


### OH_ArkUI_SurfaceHolder

```
typedef struct OH_ArkUI_SurfaceHolder OH_ArkUI_SurfaceHolder
```

**Description**

Provides an encapsulated **OH_ArkUI_SurfaceHolder** instance.

> **NOTE**
>
> The specific definition of this type is not directly exposed. Instances of this type can be created by calling the [OH_ArkUI_SurfaceHolder_Create](#oh_arkui_surfaceholder_create) API and destroyed by calling the [OH_ArkUI_SurfaceHolder_Dispose](#oh_arkui_surfaceholder_dispose) API.

**Since**

19


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```

**Description**

Provides an encapsulated **NativeWindow** instance.

> **NOTE**
>
> The specific definition of this type is not directly exposed. Instances of this type can be created by calling the [OH_ArkUI_XComponent_GetNativeWindow](#oh_arkui_xcomponent_getnativewindow) API.

**Since**

19


### OH_NativeXComponent_ExtraMouseEventInfo

```
typedef struct OH_NativeXComponent_ExtraMouseEventInfo OH_NativeXComponent_ExtraMouseEventInfo
```

**Description**

Provides an encapsulated instance of extended mouse event information.

> **NOTE**
>
> The specific definition of this type is not directly exposed. You call the [OH_NativeXComponent_GetMouseEventModifierKeyStates](#oh_nativexcomponent_getmouseeventmodifierkeystates) API to obtain the pressed states of modifier keys (**Ctrl**, **Shift**, and **Alt**).

**Since**

20


## Enum Description


### anonymous enum

```
anonymous enum
```

**Description**

Enumerates the API access states.

| Value                                     | Description   |
| ---------------------------------------- | ----- |
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS       | Success.|
| OH_NATIVEXCOMPONENT_RESULT_FAILED        | Failure.|
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER | Invalid parameter.|

**Since**

8


### OH_NativeXComponent_EventSourceType

```
enum OH_NativeXComponent_EventSourceType
```

**Description**

Enumerates the touch event source types.

| Value                                     | Description                                                  |
| ------------------------------------------- | ------------------------------------------------------ |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN     | Unknown source type.                                    |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE       | Source that generates a mouse multi-click event.                      |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN | Source that generates a touchscreen multi-touch event.                |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD    | Source that generates a touchpad multi-touch event.                |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK    | Source that generates a joystick multi-touch event.                |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD<sup>10+</sup>    | Source that generates a key event.           |

**Since**

9


### OH_NativeXComponent_TouchEvent_SourceTool

```
enum OH_NativeXComponent_TouchEvent_SourceTool
```

**Description**

Enumerates the source tool types of touch events.

| Value                                     | Description                                                  |
| ------------------------------------------- | ------------------------------------------------------ |
| OH_NATIVEXCOMPONENT_SOURCETOOL_UNKNOWN     | Unknown source tool.                                    |
| OH_NATIVEXCOMPONENT_SOURCETOOL_FINGER       | Finger.                      |
| OH_NATIVEXCOMPONENT_SOURCETOOL_PEN | Pen.                |
| OH_NATIVEXCOMPONENT_SOURCETOOL_RUBBER    | Eraser.                |
| OH_NATIVEXCOMPONENT_SOURCETOOL_BRUSH    | Brush.                |
| OH_NATIVEXCOMPONENT_SOURCETOOL_PENCIL    | Pencil.           |
| OH_NATIVEXCOMPONENT_SOURCETOOL_AIRBRUSH | Airbrush.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_MOUSE | Mouse pointer.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_LENS | Lens.|
| OH_NATIVEXCOMPONENT_SOURCETOOL_TOUCHPAD | Touchpad.|

**Since**

10


### OH_NativeXComponent_KeyAction

```
enum OH_NativeXComponent_KeyAction
```

**Description**

Enumerates the key event actions.

| Value                                   | Description      |
| -------------------------------------- | -------- |
| OH_NATIVEXCOMPONENT_KEY_ACTION_UNKNOWN | Unknown key event action.|
| OH_NATIVEXCOMPONENT_KEY_ACTION_DOWN    | Button press. |
| OH_NATIVEXCOMPONENT_KEY_ACTION_UP      | Button release. |

**Since**

10


### OH_NativeXComponent_KeyCode

```
enum OH_NativeXComponent_KeyCode
```

**Description**

Enumerates the mouse event key codes.

| Value                         | Description                         |
| ---------------------------- | --------------------------- |
| KEY_UNKNOWN                  | Unknown key.                       |
| KEY_FN                       | Function (Fn) key.                    |
| KEY_HOME                     | Function (Home) key.                  |
| KEY_BACK                     | Back key.                        |
| KEY_MEDIA_PLAY_PAUSE         | Multimedia key - play/pause.            |
| KEY_MEDIA_STOP               | Multimedia key - stop.               |
| KEY_MEDIA_NEXT               | Multimedia key - next song.              |
| KEY_MEDIA_PREVIOUS           | Multimedia key - previous song.              |
| KEY_MEDIA_REWIND             | Multimedia key - rewind.               |
| KEY_MEDIA_FAST_FORWARD       | Multimedia key - fast-forward.               |
| KEY_VOLUME_UP                | Volume Up key.                      |
| KEY_VOLUME_DOWN              | Volume Down key.                      |
| KEY_POWER                    | Power key.                        |
| KEY_CAMERA                   | Camera key.                        |
| KEY_VOLUME_MUTE              | Speaker Mute key.                     |
| KEY_MUTE                     | Microphone Mute key.                      |
| KEY_BRIGHTNESS_UP            | Brightness key - turn up.             |
| KEY_BRIGHTNESS_DOWN          | Brightness key - turn down.             |
| KEY_0                        | Key **0**.                      |
| KEY_1                        | Key **1**.                      |
| KEY_2                        | Key **2**.                      |
| KEY_3                        | Key **3**.                      |
| KEY_4                        | Key **4**.                      |
| KEY_5                        | Key **5**.                      |
| KEY_6                        | Key **6**.                      |
| KEY_7                        | Key **7**.                      |
| KEY_8                        | Key **8**.                      |
| KEY_9                        | Key **9**.                      |
| KEY_STAR                     | Key **\***.                     |
| KEY_POUND                    | Key **\#**.                     |
| KEY_DPAD_UP                  | Navigation key - up.                |
| KEY_DPAD_DOWN                | Navigation key - down.                |
| KEY_DPAD_LEFT                | Navigation key - left.                |
| KEY_DPAD_RIGHT               | Navigation key - right.                |
| KEY_DPAD_CENTER              | Navigation key - OK.               |
| KEY_A                        | Key **A**.                      |
| KEY_B                        | Key **B**.                      |
| KEY_C                        | Key **C**.                      |
| KEY_D                        | Key **D**.                      |
| KEY_E                        | Key **E**.                      |
| KEY_F                        | Key **F**.                      |
| KEY_G                        | Key **G**.                      |
| KEY_H                        | Key **H**.                      |
| KEY_I                        | Key **I**.                      |
| KEY_J                        | Key **J**.                      |
| KEY_K                        | Key **K**.                      |
| KEY_L                        | Key **L**.                      |
| KEY_M                        | Key **M**.                      |
| KEY_N                        | Key **N**.                      |
| KEY_O                        | Key **O**.                      |
| KEY_P                        | Key **P**.                      |
| KEY_Q                        | Key **Q**.                      |
| KEY_R                        | Key **R**.                      |
| KEY_S                        | Key **S**.                      |
| KEY_T                        | Key **T**.                      |
| KEY_U                        | Key **U**.                      |
| KEY_V                        | Key **V**.                      |
| KEY_W                        | Key **W**.                      |
| KEY_X                        | Key **X**.                      |
| KEY_Y                        | Key **Y**.                      |
| KEY_Z                        | Key **Z**.                      |
| KEY_COMMA                    | Key **,**.                      |
| KEY_PERIOD                   | Key **.**.                      |
| KEY_ALT_LEFT                 | Left Alt key.                      |
| KEY_ALT_RIGHT                | Right Alt key.                      |
| KEY_SHIFT_LEFT               | Left Shift key.                    |
| KEY_SHIFT_RIGHT              | Right Shift key.                    |
| KEY_TAB                      | Tab key.                       |
| KEY_SPACE                    | Space key.                        |
| KEY_SYM                      | Symbol key.                    |
| KEY_EXPLORER                 | Explorer key, which is used to start the explorer application.      |
| KEY_ENVELOPE                 | Email key, which is used to start the email application.    |
| KEY_ENTER                    | Enter key.                        |
| KEY_DEL                      | Backspace/Delete key.                        |
| KEY_GRAVE                    | Key **`**.                      |
| KEY_MINUS                    | Key **-**.                      |
| KEY_EQUALS                   | Key **=**.                      |
| KEY_LEFT_BRACKET             | Key **[**.                      |
| KEY_RIGHT_BRACKET            | Key **]**.                      |
| KEY_BACKSLASH                | Key \\.                      |
| KEY_SEMICOLON                | Key **;**.                      |
| KEY_APOSTROPHE               | Key **'**.           |
| KEY_SLASH                    | Key **/**.                      |
| KEY_AT                       | Key **\@**.                     |
| KEY_PLUS                     | Key **+**.                      |
| KEY_MENU                     | Menu key.                        |
| KEY_PAGE_UP                  | Page Up key.                      |
| KEY_PAGE_DOWN                | Page Down key.                      |
| KEY_ESCAPE                   | ESC key.                       |
| KEY_FORWARD_DEL              | Forward Delete key.                        |
| KEY_CTRL_LEFT                | Left Ctrl key.                     |
| KEY_CTRL_RIGHT               | Right Ctrl key.                     |
| KEY_CAPS_LOCK                | Caps Lock key.                      |
| KEY_SCROLL_LOCK              | Scroll Lock key.                      |
| KEY_META_LEFT                | Left Meta key.                     |
| KEY_META_RIGHT               | Right Meta key.                     |
| KEY_FUNCTION                 | Function key.                        |
| KEY_SYSRQ                    | System Request/Print Screen key.                 |
| KEY_BREAK                    | Break/Pause key.               |
| KEY_MOVE_HOME                | Move to Home key.                   |
| KEY_MOVE_END                 | Move to End key.                   |
| KEY_INSERT                   | Insert key.                        |
| KEY_FORWARD                  | Forward key.                        |
| KEY_MEDIA_PLAY               | Multimedia key - play.               |
| KEY_MEDIA_PAUSE              | Multimedia key - pause.               |
| KEY_MEDIA_CLOSE              | Multimedia key - close.               |
| KEY_MEDIA_EJECT              | Multimedia key - eject.               |
| KEY_MEDIA_RECORD             | Multimedia key - record.               |
| KEY_F1                       | F1 key.                     |
| KEY_F2                       | F2 key.                     |
| KEY_F3                       | F3 key.                     |
| KEY_F4                       | F4 key.                     |
| KEY_F5                       | F5 key.                     |
| KEY_F6                       | F6 key.                     |
| KEY_F7                       | F7 key.                     |
| KEY_F8                       | F8 key.                     |
| KEY_F9                       | F9 key.                     |
| KEY_F10                      | F10 key.                    |
| KEY_F11                      | F11 key.                    |
| KEY_F12                      | F12 key.                    |
| KEY_NUM_LOCK                 | Number Lock key.                       |
| KEY_NUMPAD_0                 | Key **0** on numeric keypad.                   |
| KEY_NUMPAD_1                 | Key **1** on numeric keypad.                   |
| KEY_NUMPAD_2                 | Key **2** on numeric keypad.                   |
| KEY_NUMPAD_3                 | Key **3** on numeric keypad.                   |
| KEY_NUMPAD_4                 | Key **4** on numeric keypad.                   |
| KEY_NUMPAD_5                 | Key **5** on numeric keypad.                   |
| KEY_NUMPAD_6                 | Key **6** on numeric keypad.                   |
| KEY_NUMPAD_7                 | Key **7** on numeric keypad.                   |
| KEY_NUMPAD_8                 | Key **8** on numeric keypad.                   |
| KEY_NUMPAD_9                 | Key **9** on numeric keypad.                   |
| KEY_NUMPAD_DIVIDE            | Key **/** on numeric keypad.                   |
| KEY_NUMPAD_MULTIPLY          | Key ***** on numeric keypad.                  |
| KEY_NUMPAD_SUBTRACT          | Key **-** on numeric keypad.                   |
| KEY_NUMPAD_ADD               | Key **+** on numeric keypad.                   |
| KEY_NUMPAD_DOT               | Key **.** on numeric keypad.                   |
| KEY_NUMPAD_COMMA             | Key **,** on numeric keypad.                   |
| KEY_NUMPAD_ENTER             | Enter key on numeric keypad.                    |
| KEY_NUMPAD_EQUALS            | Key **=** on numeric keypad.                   |
| KEY_NUMPAD_LEFT_PAREN        | Key **(** on numeric keypad.                   |
| KEY_NUMPAD_RIGHT_PAREN       | Key **)** on numeric keypad.                   |
| KEY_VIRTUAL_MULTITASK        | Multi-task key.                     |
| KEY_SLEEP                    | Sleep key.                        |
| KEY_ZENKAKU_HANKAKU          | Zenkaku/Hankaku key.                   |
| KEY_102ND                    | 102nd key.                    |
| KEY_RO                       | Ro key.                      |
| KEY_KATAKANA                 | Katakana key.                     |
| KEY_HIRAGANA                 | Hiragana key.                     |
| KEY_HENKAN                   | Henkan key.                      |
| KEY_KATAKANA_HIRAGANA        | Katakana/Hiragana key.                 |
| KEY_MUHENKAN                 | Muhenkan key.                     |
| KEY_LINEFEED                 | Linefeed key.                        |
| KEY_MACRO                    | Macro key.                         |
| KEY_NUMPAD_PLUSMINUS         | Plus/Minus key on the numeric keypad.               |
| KEY_SCALE                    | Scale key.                        |
| KEY_HANGUEL                  | Hanguel key.                      |
| KEY_HANJA                    | Hanja key.                      |
| KEY_YEN                      | Yen key.                        |
| KEY_STOP                     | Stop key.                        |
| KEY_AGAIN                    | Again key.                        |
| KEY_PROPS                    | Props key.                        |
| KEY_UNDO                     | Undo key.                        |
| KEY_COPY                     | Copy key.                        |
| KEY_OPEN                     | Open key.                        |
| KEY_PASTE                    | Paste key.                        |
| KEY_FIND                     | Find key.                        |
| KEY_CUT                      | Cut key.                        |
| KEY_HELP                     | Help key.                        |
| KEY_CALC                     | Calc key, which is used to start the calculator application.       |
| KEY_FILE                     | File key.                       |
| KEY_BOOKMARKS                | Bookmarks key.                        |
| KEY_NEXT                     | Next key.                      |
| KEY_PLAYPAUSE                | Play/Pause key.                     |
| KEY_PREVIOUS                 | Previous key.                      |
| KEY_STOPCD                   | Stop CD key.                      |
| KEY_CONFIG                   | Config key.                        |
| KEY_REFRESH                  | Refresh key.                        |
| KEY_EXIT                     | Exit key.                        |
| KEY_EDIT                     | Edit key.                        |
| KEY_SCROLLUP                 | Scroll Up key.                      |
| KEY_SCROLLDOWN               | Scroll Down key.                      |
| KEY_NEW                      | New key.                        |
| KEY_REDO                     | Redo key.                        |
| KEY_CLOSE                    | Close key.                        |
| KEY_PLAY                     | Play key.                        |
| KEY_BASSBOOST                | Bass Boost key.                      |
| KEY_PRINT                    | Print key.                        |
| KEY_CHAT                     | Chat key.                        |
| KEY_FINANCE                  | Finance key.                        |
| KEY_CANCEL                   | Cancel key.                        |
| KEY_KBDILLUM_TOGGLE          | Keyboard Illumination Toggle key.                    |
| KEY_KBDILLUM_DOWN            | Keyboard Illumination Up key.                    |
| KEY_KBDILLUM_UP              | Keyboard Illumination Down key.                    |
| KEY_SEND                     | Send key.                        |
| KEY_REPLY                    | Reply key.                        |
| KEY_FORWARDMAIL              | Forward Mail key.                      |
| KEY_SAVE                     | Save key.                        |
| KEY_DOCUMENTS                | Documents key.                        |
| KEY_VIDEO_NEXT               | Next Video key.                     |
| KEY_VIDEO_PREV               | Previous Video key.                     |
| KEY_BRIGHTNESS_CYCLE         | Brightness Cycle key.                      |
| KEY_BRIGHTNESS_ZERO          | Brightness Zero key.                    |
| KEY_DISPLAY_OFF              | Display Off Key.                      |
| KEY_BTN_MISC                 | Misc Button key.                 |
| KEY_GOTO                     | Goto key.                        |
| KEY_INFO                     | Info key.                      |
| KEY_PROGRAM                  | Program key.                        |
| KEY_PVR                      | PVR key.                |
| KEY_SUBTITLE                 | Subtitle key.                        |
| KEY_FULL_SCREEN              | Full Screen key.                        |
| KEY_KEYBOARD                 | Keyboard.                         |
| KEY_ASPECT_RATIO             | Aspect Ratio key.                   |
| KEY_PC                       | Port Control key.                      |
| KEY_TV                       | TV key.                        |
| KEY_TV2                      | TV key 2.                       |
| KEY_VCR                      | VCR key.                     |
| KEY_VCR2                     | VCR key 2.                    |
| KEY_SAT                      | SAT key.            |
| KEY_CD                       | CD key.                        |
| KEY_TAPE                     | Tape key.                        |
| KEY_TUNER                    | Tuner key.                       |
| KEY_PLAYER                   | Player key.                       |
| KEY_DVD                      | DVD key.                       |
| KEY_AUDIO                    | Audio key.                        |
| KEY_VIDEO                    | Video key.                        |
| KEY_MEMO                     | Memo key.                       |
| KEY_CALENDAR                 | Calendar key.                        |
| KEY_RED                      | Red indicator.                      |
| KEY_GREEN                    | Green indicator.                      |
| KEY_YELLOW                   | Yellow indicator.                      |
| KEY_BLUE                     | Blue indicator.                      |
| KEY_CHANNELUP                | Channel Up key.                      |
| KEY_CHANNELDOWN              | Channel Down key.                      |
| KEY_LAST                     | Last key.                        |
| KEY_RESTART                  | Restart key.                        |
| KEY_SLOW                     | Slow key.                        |
| KEY_SHUFFLE                  | Shuffle key.                      |
| KEY_VIDEOPHONE               | Videophone key.                      |
| KEY_GAMES                    | Games key.                        |
| KEY_ZOOMIN                   | Zoom in key.                        |
| KEY_ZOOMOUT                  | Zoom out key.                        |
| KEY_ZOOMRESET                | Zoom Reset key.                      |
| KEY_WORDPROCESSOR            | Word Processor key.                      |
| KEY_EDITOR                   | Editor key.                       |
| KEY_SPREADSHEET              | Spreadsheet key.                      |
| KEY_GRAPHICSEDITOR           | Graphics Editor key.                     |
| KEY_PRESENTATION             | Presentation key.                      |
| KEY_DATABASE                 | Database key.                      |
| KEY_NEWS                     | News key.                        |
| KEY_VOICEMAIL                | Voicemail key.                       |
| KEY_ADDRESSBOOK              | Address book key.                        |
| KEY_MESSENGER                | Messenger key.                        |
| KEY_BRIGHTNESS_TOGGLE        | Brightness Toggle key.                      |
| KEY_SPELLCHECK               | Spell Check key.                     |
| KEY_COFFEE                   | Coffee key, which is used to launch screen lock or screen saver.                 |
| KEY_MEDIA_REPEAT             | Media Repeat key.                      |
| KEY_IMAGES                   | Images key.                        |
| KEY_BUTTONCONFIG             | Button Configuration key.                      |
| KEY_TASKMANAGER              | Task Manager key.                      |
| KEY_JOURNAL                  | Log key.                       |
| KEY_CONTROLPANEL             | Control Panel key.                      |
| KEY_APPSELECT                | App Select key.                    |
| KEY_SCREENSAVER              | Screen Saver key.                    |
| KEY_ASSISTANT                | Assistant key.                        |
| KEY_KBD_LAYOUT_NEXT          | Next Keyboard Layout key.                   |
| KEY_BRIGHTNESS_MIN           | Min Brightness key.                      |
| KEY_BRIGHTNESS_MAX           | Max Brightness key.                      |
| KEY_KBDINPUTASSIST_PREV      | Keyboard Input-assisted Previous key.        |
| KEY_KBDINPUTASSIST_NEXT      | Keyboard Input-assisted Next key.            |
| KEY_KBDINPUTASSIST_PREVGROUP | Keyboard Input-assisted Previous key.        |
| KEY_KBDINPUTASSIST_NEXTGROUP | Keyboard Input-assisted Next key.            |
| KEY_KBDINPUTASSIST_ACCEPT    | Keyboard Input-assisted Accept key.          |
| KEY_KBDINPUTASSIST_CANCEL    | Keyboard Input-assisted Cancel key.          |
| KEY_FRONT                    | Front key, which is used to launch the windshield defogger.                  |
| KEY_SETUP                    | Setup key.                        |
| KEY_WAKEUP                   | Wakeup key.                        |
| KEY_SENDFILE                 | Send File key.                     |
| KEY_DELETEFILE               | Delete File key.                     |
| KEY_XFER                     | XFER key, which is used to start file transfer.               |
| KEY_PROG1                    | Program key 1.                       |
| KEY_PROG2                    | Program key 2.                       |
| KEY_MSDOS                    | MS-DOS key.           |
| KEY_SCREENLOCK               | Screen Lock key.                      |
| KEY_DIRECTION_ROTATE_DISPLAY | Directional Rotation Display key.                    |
| KEY_CYCLEWINDOWS             | Windows Cycle key.                 |
| KEY_COMPUTER                 | Keys.                         |
| KEY_EJECTCLOSECD             | Eject CD key.                      |
| KEY_ISO                      | ISO key.                       |
| KEY_MOVE                     | Move key.                        |
| KEY_F13                      | F13 key.                    |
| KEY_F14                      | F14 key.                    |
| KEY_F15                      | F15 key.                    |
| KEY_F16                      | F16 key.                    |
| KEY_F17                      | F17 key.                    |
| KEY_F18                      | F18 key.                    |
| KEY_F19                      | F19 key.                    |
| KEY_F20                      | F20 key.                    |
| KEY_F21                      | F21 key.                    |
| KEY_F22                      | F22 key.                    |
| KEY_F23                      | F23 key.                    |
| KEY_F24                      | F24 key.                    |
| KEY_PROG3                    | Program key 3.                       |
| KEY_PROG4                    | Program key 4.                       |
| KEY_DASHBOARD                | Dashboard.                        |
| KEY_SUSPEND                  | Suspend key.                        |
| KEY_HP                       | HP key.                      |
| KEY_SOUND                    | Sound key.                        |
| KEY_QUESTION                 | Question key.                       |
| KEY_CONNECT                  | Connect key.                        |
| KEY_SPORT                    | Sport key.                       |
| KEY_SHOP                     | Shop key.                        |
| KEY_ALTERASE                 | Alternate key.                        |
| KEY_SWITCHVIDEOMODE          | Switch Video Mode key (monitor, LCD, and TV, etc.).|
| KEY_BATTERY                  | Battery key.                       |
| KEY_BLUETOOTH                | Bluetooth key.                       |
| KEY_WLAN                     | WLAN key.                      |
| KEY_UWB                      | Ultra-wideband key.                   |
| KEY_WWAN_WIMAX               | WWAN WiMAX key.          |
| KEY_RFKILL                   | RF Kill key.                  |
| KEY_CHANNEL                  | Channel key.                      |
| KEY_BTN_0                    | Button 0.                        |
| KEY_BTN_1                    | Button 1.                        |
| KEY_BTN_2                    | Button 2.                        |
| KEY_BTN_3                    | Button 3.                        |
| KEY_BTN_4                    | Button 4.                        |
| KEY_BTN_5                    | Button 5.                        |
| KEY_BTN_6                    | Button 6.                        |
| KEY_BTN_7                    | Button 7.                        |
| KEY_BTN_8                    | Button 8.                        |
| KEY_BTN_9                    | Button 9.                        |

**Since**

10


### OH_NativeXComponent_MouseEventAction

```
enum OH_NativeXComponent_MouseEventAction
```

**Description**

Enumerates the mouse event actions.

| Value                              | Description              |
| --------------------------------- | ---------------- |
| OH_NATIVEXCOMPONENT_MOUSE_NONE    | Invalid mouse event.   |
| OH_NATIVEXCOMPONENT_MOUSE_PRESS   | Mouse button press.  |
| OH_NATIVEXCOMPONENT_MOUSE_RELEASE | Mouse button release.  |
| OH_NATIVEXCOMPONENT_MOUSE_MOVE    | Mouse movement.|
| OH_NATIVEXCOMPONENT_MOUSE_CANCEL    | Mouse button canceling.<br>**Since**: 18|

**Since**

9


### OH_NativeXComponent_MouseEventButton

```
enum OH_NativeXComponent_MouseEventButton
```

**Description**

Enumerates the mouse event buttons.

| Value                               | Description               |
| ---------------------------------- | ----------------- |
| OH_NATIVEXCOMPONENT_NONE_BUTTON    | No button.  |
| OH_NATIVEXCOMPONENT_LEFT_BUTTON    | Left mouse button.   |
| OH_NATIVEXCOMPONENT_RIGHT_BUTTON   | Right mouse button.   |
| OH_NATIVEXCOMPONENT_MIDDLE_BUTTON  | Middle mouse button.   |
| OH_NATIVEXCOMPONENT_BACK_BUTTON    | Back button on the left of the mouse.|
| OH_NATIVEXCOMPONENT_FORWARD_BUTTON | Forward key on the left of the mouse.|

**Since**

9


### OH_NativeXComponent_TouchEventType

```
enum OH_NativeXComponent_TouchEventType
```

**Description**

Enumerates the touch event types.

| Value                        | Description                   |
| --------------------------- | --------------------- |
| OH_NATIVEXCOMPONENT_DOWN    | The touch event is triggered when a finger is pressed.         |
| OH_NATIVEXCOMPONENT_UP      | The touch event is triggered when a finger is lifted.         |
| OH_NATIVEXCOMPONENT_MOVE    | The touch event is triggered when a finger is moved on the screen.|
| OH_NATIVEXCOMPONENT_CANCEL  | The event is triggered when a touch event is canceled.         |
| OH_NATIVEXCOMPONENT_UNKNOWN | Invalid touch type.             |

**Since**

8


### OH_NativeXComponent_TouchPointToolType

```
enum OH_NativeXComponent_TouchPointToolType
```

**Description**

Enumerates the touch point tool types.

| Value                                   | Description      |
| -------------------------------------- | -------- |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN  | Unknown tool type.|
| OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER   | Finger.  |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN      | Stylus.  |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER   | Rubber. |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH    | Brush.  |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL   | Pencil.  |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH | Air brush.  |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE    | Mouse.  |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS     | Lens. |

**Since**

9

### ArkUI_XComponent_ImageAnalyzerState

```
enum ArkUI_XComponent_ImageAnalyzerState
```

**Description**

Enumerates the AI image analyzer error codes of the XComponent.

| Value                                   | Description    |
| --------------------------------------   | -------- |
| ARKUI_XCOMPONENT_AI_ANALYSIS_FINISHED    | AI image analysis is complete.|
| ARKUI_XCOMPONENT_AI_ANALYSIS_DISABLED    | AI image analysis is disabled.|
| ARKUI_XCOMPONENT_AI_ANALYSIS_UNSUPPORTED | The device does not support AI image analysis.|
| ARKUI_XCOMPONENT_AI_ANALYSIS_ONGOING     | AI image analysis is in progress.|
| ARKUI_XCOMPONENT_AI_ANALYSIS_STOPPED     | AI image analysis has been stopped.|

**Since**

18

## Function Description

### OH_NativeXComponent_AttachNativeRootNode()

```
int32_t OH_NativeXComponent_AttachNativeRootNode (OH_NativeXComponent * component, ArkUI_NodeHandle root )
```
**Description**

Attaches the UI component created through the native API of ArkUI to this **OH_NativeXComponent** instance.

**Since**: 12

**Deprecated from**: 20

**Substitute**: [OH_ArkUI_NodeContent_AddNode](./_ark_u_i___native_module.md#oh_arkui_nodecontent_addnode)

**Parameters**

| Name| Description|
| -------- | -------- |
| component | Pointer to the **OH_NativeXComponent** instance. |
| root | Pointer to the component instance created through the native API. |

**Returns**

**0**: success

**-2**: parameter error


### OH_NativeXComponent_DetachNativeRootNode()

```
int32_t OH_NativeXComponent_DetachNativeRootNode (OH_NativeXComponent * component, ArkUI_NodeHandle root )
```
**Description**

Detaches the native component of ArkUI from this **OH_NativeXComponent** instance.

**Since**: 12

**Deprecated from**: 20

**Substitute**: [OH_ArkUI_NodeContent_RemoveNode](./_ark_u_i___native_module.md#oh_arkui_nodecontent_removenode)

**Parameters**

| Name| Description|
| -------- | -------- |
| component | Pointer to the **OH_NativeXComponent** instance. |
| root | Pointer to the component instance created through the native API. |

**Returns**

**0**: success

**-2**: parameter error



### OH_NativeXComponent_GetKeyEvent()

```
int32_t OH_NativeXComponent_GetKeyEvent (OH_NativeXComponent * component, OH_NativeXComponent_KeyEvent ** keyEvent )
```

**Description**

Obtains the key event scheduled by the ArkUI XComponent.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| keyEvent  | Pointer to the current key event.             |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_GetKeyEventAction()

```
int32_t OH_NativeXComponent_GetKeyEventAction (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_KeyAction * action )
```

**Description**

Obtains the action of the specified key event.

**Parameters**

| Name      | Description                                    |
| -------- | -------------------------------------- |
| keyEvent | Pointer to the **OH_NativeXComponent_KeyEvent** instance.|
| action   | Pointer to the key event action.                        |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_GetKeyEventCode()

```
int32_t OH_NativeXComponent_GetKeyEventCode (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_KeyCode * code )
```

**Description**

Obtains the key code of the specified key event.

**Parameters**

| Name      | Description                                    |
| -------- | -------------------------------------- |
| keyEvent | Pointer to the **OH_NativeXComponent_KeyEvent** instance.|
| code     | Pointer to the key code of the key event.                       |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_GetKeyEventDeviceId()

```
int32_t OH_NativeXComponent_GetKeyEventDeviceId (OH_NativeXComponent_KeyEvent * keyEvent, int64_t * deviceId )
```

**Description**

Obtains the device ID of the specified key event.

**Parameters**

| Name      | Description                                    |
| -------- | -------------------------------------- |
| keyEvent | Pointer to the **OH_NativeXComponent_KeyEvent** instance.|
| deviceId | Pointer to the device ID of the key event.                      |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_GetKeyEventSourceType()

```
int32_t OH_NativeXComponent_GetKeyEventSourceType (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_EventSourceType * sourceType )
```

**Description**

Obtains the source type of the specified key event.

**Parameters**

| Name        | Description                                    |
| ---------- | -------------------------------------- |
| keyEvent   | Pointer to the **OH_NativeXComponent_KeyEvent** instance.|
| sourceType | Pointer to the source type of the key event.                     |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_GetKeyEventTimestamp()

```
int32_t OH_NativeXComponent_GetKeyEventTimestamp (OH_NativeXComponent_KeyEvent * keyEvent, int64_t * timeStamp )
```

**Description**

Obtains the timestamp of the specified key event.

**Parameters**

| Name       | Description                                    |
| --------- | -------------------------------------- |
| keyEvent  | Pointer to the **OH_NativeXComponent_KeyEvent** instance.|
| timeStamp | Pointer to the timestamp of the key event.                       |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_GetHistoricalPoints()

```
int32_t OH_NativeXComponent_GetHistoricalPoints (OH_NativeXComponent * component, const void * window, int32_t * size, OH_NativeXComponent_HistoricalPoint ** historicalPoints )
```

**Description**

Obtains the historical touch point data for the touch event of an **OH_NativeXComponent** instance. Some input devices report touch points at very high frequencies (up to 1 ms intervals). However, since UI updates typically do not require such high-frequency updates, the system consolidates touch events and reports them once per frame. All touch points collected during the current frame are preserved as historical touch points for applications that need direct access to this raw data.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.|
| window     | Handle to the **NativeWindow** instance.             |
| size       | Length of the historical touch point array.     |
| historicalPoints | Pointer to the historical touch point array.               |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_GetMouseEvent()

```
int32_t OH_NativeXComponent_GetMouseEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_MouseEvent * mouseEvent )
```

**Description**

Obtains the mouse event scheduled by the ArkUI XComponent.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.|
| window     | Handle to the **NativeWindow** instance.             |
| mouseEvent | Pointer to the current mouse event.               |

**Returns**

Result code.

**Since**

9

### OH_NativeXComponent_GetNativeXComponent()

```
OH_NativeXComponent* OH_NativeXComponent_GetNativeXComponent (ArkUI_NodeHandle node)
```
**Description**

Obtains the pointer to an **OH_NativeXComponent** instance based on the specified component instance created by the native API.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| node | Pointer to the component instance created through the native API. |

**Returns**

Pointer to the **OH_NativeXComponent** instance.


### OH_NativeXComponent_GetTouchEvent()

```
int32_t OH_NativeXComponent_GetTouchEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_TouchEvent * touchEvent )
```

**Description**

Obtains the touch event scheduled by the ArkUI XComponent.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.|
| window     | Handle to the **NativeWindow** instance.            |
| touchEvent | Pointer to the current touch event.               |

**Returns**

Result code.

**Since**

8


### OH_NativeXComponent_GetTouchPointTiltX()

```
int32_t OH_NativeXComponent_GetTouchPointTiltX (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltX )
```

**Description**

Obtains the angle between the Y-Z plane of the ArkUI XComponent touch point and the x-axis.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.|
| pointIndex | Pointer to the index of the touch point.                  |
| tiltX      | Pointer to the angle between the Y-Z plane of the touch point and the x-axis.                 |

**Returns**

Result code.

**Since**

9


### OH_NativeXComponent_GetTouchPointTiltY()

```
int32_t OH_NativeXComponent_GetTouchPointTiltY (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltY )
```

**Description**

Obtains the angle between the X-Z plane of the ArkUI XComponent touch point and the y-axis.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.|
| pointIndex | Pointer to the index of the touch point.                  |
| tiltY      | Pointer to the angle between the X-Z plane of the touch point and the y-axis.                 |

**Returns**

Result code.

**Since**

9


### OH_NativeXComponent_GetTouchPointWindowX()

```
int32_t OH_NativeXComponent_GetTouchPointWindowX(OH_NativeXComponent * component, uint32_t pointIndex, float * windowX )
```

**Description**

Obtains the X coordinate of the touch point relative to the upper left corner of the application window where the ArkUI XComponent is located.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.       |
| pointIndex | Pointer to the index of the touch point.                         |
| windowX    | Pointer to the X coordinate of the touch point relative to the upper left corner of the application window. |

**Returns**

Result code.

**Since**

12


### OH_NativeXComponent_GetTouchPointWindowY()

```
int32_t OH_NativeXComponent_GetTouchPointWindowY(OH_NativeXComponent * component, uint32_t pointIndex, float * windowY )
```

**Description**

Obtains the Y coordinate of the touch point relative to the upper left corner of the application window where the ArkUI XComponent is located.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.       |
| pointIndex | Pointer to the index of the touch point.                         |
| windowY    | Pointer to the Y coordinate of the touch point relative to the upper left corner of the application window. |

**Returns**

Result code.

**Since**

12


### OH_NativeXComponent_GetTouchPointDisplayX()

```
int32_t OH_NativeXComponent_GetTouchPointDisplayX(OH_NativeXComponent * component, uint32_t pointIndex, float * displayX )
```

**Description**

Obtains the X coordinate of the touch point relative to the upper left corner of the screen where the ArkUI XComponent is located.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.       |
| pointIndex | Pointer to the index of the touch point.                         |
| displayX    | Pointer to the X coordinate of the touch point relative to the upper left corner of the screen. |

**Returns**

Result code.

**Since**

12


### OH_NativeXComponent_GetTouchPointDisplayY()

```
int32_t OH_NativeXComponent_GetTouchPointDisplayY(OH_NativeXComponent * component, uint32_t pointIndex, float * displayY )
```

**Description**

Obtains the Y coordinate of the touch point relative to the upper left corner of the screen where the ArkUI XComponent is located.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.       |
| pointIndex | Pointer to the index of the touch point.                         |
| displayY    | Pointer to the Y coordinate of the touch point relative to the upper left corner of the screen. |

**Returns**

Result code.

**Since**

12


### OH_NativeXComponent_GetTouchPointToolType()

```
int32_t OH_NativeXComponent_GetTouchPointToolType (OH_NativeXComponent * component, uint32_t pointIndex, OH_NativeXComponent_TouchPointToolType * toolType )
```

**Description**

Obtains the ArkUI XComponent touch point tool type.

**Parameters**

| Name        | Description                           |
| ---------- | ----------------------------- |
| component  | Pointer to the **OH_NativeXComponent** instance.|
| pointIndex | Pointer to the index of the touch point.                  |
| toolType   | Pointer to the tool type.                 |

**Returns**

Result code.

**Since**

9


### OH_NativeXComponent_GetXComponentId()

```
int32_t OH_NativeXComponent_GetXComponentId (OH_NativeXComponent * component, char * id, uint64_t * size )
```

**Description**

Obtains the ID of ArkUI XComponent.

**Parameters**

| Name     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| component | Pointer to the **OH_NativeXComponent** instance.                     |
| id        | Pointer to the character buffer for storing the ID of the **OH_NativeXComponent** instance. Note that null terminators will be attached to the character buffer, so the size of the character buffer should be at least one unit greater than the length of the real ID. The recommended size is [OH_XCOMPONENT_ID_LEN_MAX + 1].|
| size      | Pointer to the length of the ID, used to receive the length information of the ID.                |

**Returns**

Result code.

**Since**

8


### OH_NativeXComponent_GetXComponentOffset()

```
int32_t OH_NativeXComponent_GetXComponentOffset (OH_NativeXComponent * component, const void * window, double * x, double * y )
```

**Description**

Obtains the offset of the surface held by the XComponent relative to the upper left corner of its parent component.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| window    | Handle to the **NativeWindow** instance.            |
| x         | Pointer to the X coordinate of the current surface relative to the upper left corner of the XComponent's parent component.        |
| y         | Pointer to the Y coordinate of the current surface relative to the upper left corner of the XComponent's parent component.        |

**Returns**

Result code.

**Since**

8


### OH_NativeXComponent_GetXComponentSize()

```
int32_t OH_NativeXComponent_GetXComponentSize (OH_NativeXComponent * component, const void * window, uint64_t * width, uint64_t * height )
```

**Description**

Obtains the size of the surface held by the ArkUI XComponent.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| window    | Handle to the **NativeWindow** instance.            |
| width     | Pointer to the width of the current surface.          |
| height    | Pointer to the height of the current surface.          |

**Returns**

Result code.

**Since**

8


### OH_NativeXComponent_RegisterBlurEventCallback()

```
int32_t OH_NativeXComponent_RegisterBlurEventCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**Description**

Registers the blur event callback for this **OH_NativeXComponent** instance.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| callback  | Pointer to the blur event callback.<br> - **window**: handle to the **NativeWindow** instance.              |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_RegisterCallback()

```
int32_t OH_NativeXComponent_RegisterCallback (OH_NativeXComponent * component, OH_NativeXComponent_Callback * callback )
```

**Description**

Registers a callback for this **OH_NativeXComponent** instance.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| callback  | Pointer to the surface lifecycle and touch event callback.   |

**Returns**

Result code.

**Since**

8


### OH_NativeXComponent_RegisterFocusEventCallback()

```
int32_t OH_NativeXComponent_RegisterFocusEventCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**Description**

Registers the focus event callback for this **OH_NativeXComponent** instance.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| callback  | Pointer to the focus event callback.<br> - **window**: handle to the **NativeWindow** instance.              |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_RegisterKeyEventCallback()

```
int32_t OH_NativeXComponent_RegisterKeyEventCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**Description**

Registers the key event callback for this **OH_NativeXComponent** instance.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| callback  | Pointer to the key event callback.<br> - **window**: handle to the **NativeWindow** instance.              |

**Returns**

Result code.

**Since**

10


### OH_NativeXComponent_RegisterKeyEventCallbackWithResult()

```
int32_t OH_NativeXComponent_RegisterKeyEventCallbackWithResult (OH_NativeXComponent * component, bool(*callback)(OH_NativeXComponent *component, void *window))
```

**Description**

Registers a key event callback with a return value for this **OH_NativeXComponent** instance. The callback must return a result (**true** or **false**). If the callback returns **true**, the event will not be further propagated. If it returns **false**, the event will continue to be processed according to the normal event handling flow.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| callback  | Pointer to the key event callback.<br> - **window**: handle to the **NativeWindow** instance.|

**Returns**

Result code.

**Since**

14


### OH_NativeXComponent_RegisterMouseEventCallback()

```
int32_t OH_NativeXComponent_RegisterMouseEventCallback (OH_NativeXComponent * component, OH_NativeXComponent_MouseEvent_Callback * callback )
```

**Description**

Registers the mouse event callback for this **OH_NativeXComponent** instance.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| callback  | Pointer to the mouse event callback.               |

**Returns**

Result code.

**Since**

9

### OH_NativeXComponent_RegisterOnFrameCallback()

```
int32_t OH_NativeXComponent_RegisterOnFrameCallback (OH_NativeXComponent* component, void (*callback)(OH_NativeXComponent *component, uint64_t timestamp, uint64_t targetTimestamp))
```
**Description**

Registers the display update callback for this **OH_NativeXComponent** instance and enables the callback for each frame.

**Parameters**

| Name| Description|
| -------- | -------- |
| component | Pointer to the **OH_NativeXComponent** instance. |
| callback | Pointer to the display update callback.<br> - **timestamp**: time when the current frame arrives, in nanoseconds.<br> - **targetTimestamp**: expected arrival time of the next frame, in nanoseconds.|

**Returns**

Result code.

**Since**

11

### OH_NativeXComponent_RegisterOnTouchInterceptCallback()

```
int32_t OH_NativeXComponent_RegisterOnTouchInterceptCallback (OH_NativeXComponent * component, HitTestMode(*callback)(OH_NativeXComponent *component, ArkUI_UIInputEvent *event))
```
**Description**

Registers a custom event intercept callback for an **OH_NativeXComponent** and enables the callback during the hit test.
UI input–related operations are not supported on event objects received through this callback. For full functionality, use the **NODE_ON_TOUCH_INTERCEPT** event on native nodes instead.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| component | Pointer to the **OH_NativeXComponent** instance. |
| callback | Pointer to the custom event intercept callback.<br> - **event**: pointer to the UI input event.|

**Returns**

**0**: The operation is successful.
**401**: Any parameter error occurs.

### OH_NativeXComponent_RegisterUIInputEventCallback()

```
int32_t OH_NativeXComponent_RegisterUIInputEventCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, ArkUI_UIInputEvent *event, ArkUI_UIInputEvent_Type type), ArkUI_UIInputEvent_Type type )
```
**Description**

Registers a UI input event callback for an **OH_NativeXComponent** instance and enables the callback to be invoked when a UI input event is received. Currently, only axis events are supported.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| component | Pointer to the **OH_NativeXComponent** instance. |
| callback | Pointer to the UI input event callback.<br> - **event**: pointer to the UI input event. |
| type | Type of the current UI input event. |

**Returns**

Result code.

### OH_NativeXComponent_SetExpectedFrameRateRange()

```
int32_t OH_NativeXComponent_SetExpectedFrameRateRange (OH_NativeXComponent * component, OH_NativeXComponent_ExpectedRateRange * range )
```
**Description**

Sets the expected frame rate range.

**Parameters**

| Name| Description|
| -------- | -------- |
| component | Pointer to the **OH_NativeXComponent** instance. |
| range | Pointer to the expected frame rate range.|

**Returns**

Result code.

**Since**

11


### OH_NativeXComponent_UnregisterOnFrameCallback()

```
int32_t OH_NativeXComponent_UnregisterOnFrameCallback (OH_NativeXComponent * component)
```
**Description**

Deregisters the display update callback for this **OH_NativeXComponent** instance and disables the callback for each frame.

**Parameters**

| Name| Description|
| -------- | -------- |
| component | Pointer to the **OH_NativeXComponent** instance. |

**Returns**

Result code.

**Since**

11

### OH_NativeXComponent_SetNeedSoftKeyboard()

```
int32_t OH_NativeXComponent_SetNeedSoftKeyboard(OH_NativeXComponent* component, bool isNeedSoftKeyboard)
```

**Description**

Sets whether the soft keyboard is required for an **OH_NativeXComponent** instance.

**Parameters**

| Name              | Description                                         |
| ------------------ | --------------------------------------------- |
| component          | Pointer to the **OH_NativeXComponent** instance.      |
| isNeedSoftKeyboard | Whether the soft keyboard is required for the **OH_NativeXComponent** instance.|

**Returns**

Result code.

**Since**

12

### OH_NativeXComponent_RegisterSurfaceShowCallback()

```
int32_t OH_NativeXComponent_RegisterSurfaceShowCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**Description**

Registers a surface display callback for an **OH_NativeXComponent** instance. The callback is invoked after the application is switched to the foreground.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| callback  | Pointer to the surface display callback.<br> - **window**: handle to the **NativeWindow** instance.              |

**Returns**

Result code.

**Since**

12

### OH_NativeXComponent_RegisterSurfaceHideCallback()

```
int32_t OH_NativeXComponent_RegisterSurfaceHideCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**Description**

Registers a surface hiding callback for an **OH_NativeXComponent** instance. The callback is invoked after the application is switched to the background.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| callback  | Pointer to the surface hiding callback.<br> - **window**: handle to the **NativeWindow** instance.              |

**Returns**

Result code.

**Since**

12

### OH_NativeXComponent_GetTouchEventSourceType()

```
int32_t OH_NativeXComponent_GetTouchEventSourceType (OH_NativeXComponent* component, int32_t pointId, OH_NativeXComponent_EventSourceType* sourceType)
```

**Description**

Obtains the touch event source type of an **OH_NativeXComponent** instance.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| pointId  | ID of the touch point.<br>**NOTE**<br>The touch event source type can be correctly returned only when the ID passed in is the ID of the touch point that triggers the touch event. Otherwise, **OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER** is returned.|
| sourceType  | Pointer to the touch event source type.|

**Returns**

**OH_NATIVEXCOMPONENT_RESULT_SUCCESS**: The operation is successful.

**OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER**: A parameter error occurs.

**OH_NATIVEXCOMPONENT_RESULT_FAILED**: Any other error occurs.

**Since**

12

### OH_NativeXComponent_GetNativeAccessibilityProvider()

```
int32_t OH_NativeXComponent_GetNativeAccessibilityProvider(
    OH_NativeXComponent* component, ArkUI_AccessibilityProvider** handle)
```

**Description**

Obtains the accessibility provider handle for an ArkUI XComponent.

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| handle    | Pointer to an **ArkUI_AccessibilityProvider** instance.               |

**Returns**

**OH_NATIVEXCOMPONENT_RESULT_SUCCESS**: The operation is successful.

**OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER**: A parameter error occurs.

**OH_NATIVEXCOMPONENT_RESULT_FAILED**: Any other error occurs.

**Since**

13

### OH_ArkUI_XComponent_StartImageAnalyzer()

```
int32_t OH_ArkUI_XComponent_StartImageAnalyzer(ArkUI_NodeHandle node, void* userData,
    void (*callback)(ArkUI_NodeHandle node, ArkUI_XComponent_ImageAnalyzerState statusCode, void* userData))
```

**Description**

Starts AI image analysis for this XComponent instance. Before calling this API, make sure the AI image analyzer is enabled.

**Since**

18

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| node | XComponent instance.|
| userData    | Pointer to the data that you need to obtain when the callback function is executed.               |
|callback| Callback function triggered when the AI image analysis status is updated.<br> - **statusCode**: one of the input parameters of the callback function, indicating the current image analysis status.|

> **NOTE**
>
> The AI image analysis process initiated by this API is executed asynchronously. The return of the API does not indicate that the AI image analysis has produced results.
> 
> When this API is called, it captures the frame at the moment of the call for analysis. Care should be taken to choose the right timing to start the analysis to avoid inconsistencies between the captured frame and the analysis content.
>
> When the AI image analysis status is updated, the passed callback function will be triggered.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_XComponent_StopImageAnalyzer()

```
int32_t OH_ArkUI_XComponent_StopImageAnalyzer(ArkUI_NodeHandle node)
```

**Description**

Stops AI image analysis for this XComponent instance.

**Since**

18

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| node | XComponent instance.|

> **NOTE**
>
> After AI image analysis is stopped, the content displayed as a result of the image AI analysis will be destroyed.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_SurfaceCallback_Create()

```
OH_ArkUI_SurfaceCallback* OH_ArkUI_SurfaceCallback_Create()
```

**Description**

Creates an [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) object.

**Since**

19

**Returns**

Pointer to the created [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) object.

### OH_ArkUI_SurfaceCallback_Dispose()

```
void OH_ArkUI_SurfaceCallback_Dispose(OH_ArkUI_SurfaceCallback* callback)
```

**Description**

Disposes of an [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) object.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| callback | Pointer to the [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) object to be disposed of.|

### OH_ArkUI_SurfaceHolder_Create()

```
OH_ArkUI_SurfaceHolder* OH_ArkUI_SurfaceHolder_Create(ArkUI_NodeHandle node)
```

**Description**

Creates an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) object for an XComponent.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| node | Pointer to the XComponent instance created through the native API. |

**Returns**

Pointer to the created [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) object.

### OH_ArkUI_SurfaceHolder_Dispose()

```
void OH_ArkUI_SurfaceHolder_Dispose(OH_ArkUI_SurfaceHolder* surfaceHolder)
```

**Description**

Disposes of an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) object.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| surfaceHolder |  Pointer to the [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance to be disposed of.|

### OH_ArkUI_SurfaceHolder_SetUserData()

```
int32_t OH_ArkUI_SurfaceHolder_SetUserData(OH_ArkUI_SurfaceHolder* surfaceHolder, void* userData)
```

**Description**

Stores custom data in an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| surfaceHolder |  Pointer to the [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance where the custom data will be stored.|
| userData |  Pointer to the custom data to be stored.|

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_SurfaceHolder_GetUserData()

```
void* OH_ArkUI_SurfaceHolder_GetUserData(OH_ArkUI_SurfaceHolder* surfaceHolder);
```

**Description**

Obtains the custom data stored in an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| surfaceHolder |  Pointer to the [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance where the custom data is stored.|

**Returns**

Custom data.

### OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent(OH_ArkUI_SurfaceCallback* callback, void (*onSurfaceCreated)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**Description**

Sets the creation callback event in the surface lifecycle callback.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| callback |  Pointer to the surface lifecycle callback.|
| onSurfaceCreated |  Callback event triggered when the surface is created.<br> - **surfaceHolder**: pointer to an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.|

### OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent(OH_ArkUI_SurfaceCallback* callback, void (*onSurfaceChanged)(OH_ArkUI_SurfaceHolder* surfaceHolder, uint64_t width, uint64_t height))
```

**Description**

Sets the size change callback event in the surface lifecycle callback.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| callback |  Pointer to the surface lifecycle callback.|
| onSurfaceChanged |  Callback event triggered when the surface size changes. <br> - **surfaceHolder**: pointer to an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.<br> - **width**: new width of the surface after the size change.<br> - **height**: new height of the surface after the size change.|

### OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent(OH_ArkUI_SurfaceCallback* callback, void (*onSurfaceDestroyed)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**Description**

Sets the destruction callback event in the surface lifecycle callback.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| callback |  Pointer to the surface lifecycle callback.|
| onSurfaceDestroyed |  Callback event triggered when the surface is destroyed.<br> - **surfaceHolder**: pointer to an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.|

### OH_ArkUI_SurfaceHolder_AddSurfaceCallback()

```
int32_t OH_ArkUI_SurfaceHolder_AddSurfaceCallback(OH_ArkUI_SurfaceHolder* surfaceHolder, OH_ArkUI_SurfaceCallback* callback)
```

**Description**

Adds a surface lifecycle callback to an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| surfaceHolder |  Pointer to an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.|
| callback |  Pointer to the new callback.|

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback()

```
int32_t OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback(OH_ArkUI_SurfaceHolder* surfaceHolder, OH_ArkUI_SurfaceCallback* callback)
```

**Description**

Removes a previously added surface lifecycle callback from an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| surfaceHolder |  Pointer to the [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance from which the callback will be removed.|
| callback |  Pointer to the callback to be removed.|

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_XComponent_GetNativeWindow()

```
OHNativeWindow* OH_ArkUI_XComponent_GetNativeWindow(OH_ArkUI_SurfaceHolder* surfaceHolder)
```

**Description**

Obtains the **NativeWindow** instance associated with an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| surfaceHolder |  Pointer to an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.|

**Returns**

NativeWindow associated with the **OH_ArkUI_SurfaceHolder** instance.

### OH_ArkUI_XComponent_SetAutoInitialize()

```
int32_t OH_ArkUI_XComponent_SetAutoInitialize(ArkUI_NodeHandle node, bool autoInitialize)
```

**Description**

Sets whether the **XComponent** component needs to automatically initialize the surface.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| node |  Pointer to the **XComponent** component instance.|
| autoInitialize |  Whether the XComponent needs to automatically initialize the surface. If **autoInitialize** is **true**, the **OnSurfaceCreated** callback will be triggered when the component is attached to the tree, and the **OnSurfaceDestroyed** callback will be triggered when the component is detached from the tree. The default value of **autoInitialize** is **true**.|

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_XComponent_Initialize()

```
int32_t OH_ArkUI_XComponent_Initialize(ArkUI_NodeHandle node)
```

**Description**

Initializes the surface held by the **XComponent** component.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| node |  Pointer to the **XComponent** component instance.|

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

[ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID](_ark_u_i___native_module.md#arkui_errorcode): The surface held by the **XComponent** component has been initialized.

### OH_ArkUI_XComponent_Finalize()

```
int32_t OH_ArkUI_XComponent_Finalize(ArkUI_NodeHandle node)
```

**Description**

Destroys the surface held by the **XComponent** component.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| node |  Pointer to the **XComponent** component instance.|

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

[ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID](_ark_u_i___native_module.md#arkui_errorcode): The surface held by the **XComponent** component has been destroyed.

### OH_ArkUI_XComponent_IsInitialized()

```
int32_t OH_ArkUI_XComponent_IsInitialized(ArkUI_NodeHandle node, bool* isInitialized)
```

**Description**

Checks whether the surface held by the **XComponent** component is initialized.

**Since**

19

**Parameters**

| Name     | Description                                   |
| --------- | --------------------------------------- |
| node |  Pointer to the **XComponent** component instance.|
| isInitialized |  Whether the surface held by the **XComponent** component is initialized.|

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_NativeXComponent_GetExtraMouseEventInfo()

```
int32_t OH_NativeXComponent_GetExtraMouseEventInfo(OH_NativeXComponent* component, OH_NativeXComponent_ExtraMouseEventInfo** extraMouseEventInfo)
```

**Description**

Obtains extended mouse event information from an [OH_NativeXComponent](#oh_nativexcomponent) instance.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| component | Pointer to the [OH_NativeXComponent](#oh_nativexcomponent) instance. |
| extraMouseEventInfo | Address of a pointer to the [OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo) type. |

> **NOTE**
>
> This API must be called within the scope of the mouse event callback function. Do not call this API or use the **OH_NativeXComponent_ExtraMouseEventInfo** instance outside the scope of the mouse event callback.
>
> The pointer to the **OH_NativeXComponent_ExtraMouseEventInfo** type obtained through this API must not be destroyed using the **delete** statement.
>
> Passing a null pointer for either the **component** or **extraMouseEventInfo** parameter is considered an invalid input.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_NativeXComponent_GetMouseEventModifierKeyStates()

```
int32_t OH_NativeXComponent_GetMouseEventModifierKeyStates(OH_NativeXComponent_ExtraMouseEventInfo* extraMouseEventInfo, uint64_t* keys)
```

**Description**

Obtains the state of modifier keys from an [OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo) instance.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| extraMouseEventInfo | Pointer to the extended mouse event information instance. |
| keys | Address of a 64-bit unsigned integer to receive the modifier key press state information. |

> **NOTE**
>
> This API can be used to obtain the press state of the **Ctrl**, **Shift**, and **Alt** keys.
>
> The modifier key press state information obtained through this API is stored in a 64-bit unsigned integer. To determine the state of a specific modifier key, perform a bitwise AND (&) operation between the 64-bit unsigned integer and the enumerated values of the [ArkUI_ModifierKeyName](./_ark_u_i___event_module.md#arkui_modifierkeyname) type. A result of **0** indicates that the modifier key is not pressed, while a result of **1** indicates that the modifier key is pressed. For example, using the **ARKUI_MODIFIER_KEY_CTRL** enumerated value with the obtained **keys** value through the AND (&) operation allows you to obtain the press state of the **Ctrl** key.
>
> Passing a null pointer for either the **component** or **keys** parameter is considered an invalid input.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_NativeXComponent_GetKeyEventModifierKeyStates()

```
int32_t OH_NativeXComponent_GetKeyEventModifierKeyStates(OH_NativeXComponent_KeyEvent* keyEvent, uint64_t* keys)
```

**Description**

Obtains the state of modifier keys from a key event.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| keyEvent | Pointer to the key event. |
| keys | Address of a 64-bit unsigned integer to receive the modifier key press state information. |

> **NOTE**
>
> The modifier key press state information obtained through this API is stored in a 64-bit unsigned integer. To determine the state of a specific modifier key, perform a bitwise AND (&) operation between the 64-bit unsigned integer and the enumerated values of the [ArkUI_ModifierKeyName](./_ark_u_i___event_module.md#arkui_modifierkeyname) type. A result of **0** indicates that the modifier key is not pressed, while a result of **1** indicates that the modifier key is pressed.
>
> Passing a null pointer for either the **keyEvent** or **keys** parameter is considered an invalid input.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_NativeXComponent_GetKeyEventNumLockState()

```
int32_t OH_NativeXComponent_GetKeyEventNumLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isNumLockOn)
```

**Description**

Obtains the state of the NumLock key from a key event.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| keyEvent | Pointer to the key event. |
| isNumLockOn | Address of a boolean variable to receive the state of the NumLock key. |

> **NOTE**
>
> The state of the NumLock key is stored in a boolean variable. The value **true** means that the NumLock key is active, and **false** means the opposite.
>
> Passing a null pointer for either the **keyEvent** or **isNumLockOn** parameter is considered an invalid input.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_NativeXComponent_GetKeyEventCapsLockState()

```
int32_t OH_NativeXComponent_GetKeyEventCapsLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isCapsLockOn)
```

**Description**

Obtains the state of the CapsLock key from a key event.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| keyEvent | Pointer to the key event. |
| isCapsLockOn | Address of a boolean variable to receive the state of the CapsLock key. |

> **NOTE**
>
> The state of the CapsLock key is stored in a boolean variable. The value **true** means that the CapsLock key is active, and **false** means the opposite.
>
> Passing a null pointer for either the **keyEvent** or **isCapsLockOn** parameter is considered an invalid input.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_NativeXComponent_GetKeyEventScrollLockState()

```
int32_t OH_NativeXComponent_GetKeyEventScrollLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isScrollLockOn)
```

**Description**

Obtains the state of the ScrollLock key from a key event.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| keyEvent | Pointer to the key event. |
| isScrollLockOn | Address of a boolean variable to receive the state of the ScrollLock key. |

> **NOTE**
>
> The state of the ScrollLock key is stored in a boolean variable. The value **true** means that the ScrollLock key is active, and **false** means the opposite.
>
> Passing a null pointer for either the **keyEvent** or **isScrollLockOn** parameter is considered an invalid input.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_XComponent_SetExpectedFrameRateRange()

```
int32_t OH_ArkUI_XComponent_SetExpectedFrameRateRange(
    ArkUI_NodeHandle node, OH_NativeXComponent_ExpectedRateRange range)
```

**Description**

Sets the expected frame rate range for the XComponent.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| node | XComponent instance. |
| range | Expected frame rate information object of the [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) type. |

> **NOTE**
>
> The XComponent instance passed to this API must be created using the [ArkUI NDK API](../../ui/ndk-access-the-arkts-page.md) or constructed through [NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters19).
>
> For the [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) object:<br>- The value of the [min](#min) member must be less than or equal to the value of the [max](#max) member.<br>- The value of the [expected](#expected) member must be greater than or equal to the value of the [min](#min) member and less than or equal to the value of the [max](#max) member.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_XComponent_RegisterOnFrameCallback()

```
int32_t OH_ArkUI_XComponent_RegisterOnFrameCallback(ArkUI_NodeHandle node,
    void (*callback)(ArkUI_NodeHandle node, uint64_t timestamp, uint64_t targetTimestamp))
```

**Description**

Registers a frame callback function for the XComponent.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| node | XComponent instance. |
| callback | Pointer to the frame callback function.<br> - **timestamp**: time when the current frame arrives, in nanoseconds.<br> - **targetTimestamp**: expected arrival time of the next frame, in nanoseconds.   |

> **NOTE**
>
> The XComponent instance passed to this API must be created using the [ArkUI NDK API](../../ui/ndk-access-the-arkts-page.md) or constructed through [NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters19).

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_XComponent_UnregisterOnFrameCallback()

```
int32_t OH_ArkUI_XComponent_UnregisterOnFrameCallback(ArkUI_NodeHandle node)
```

**Description**

Unregisters the frame callback function for the XComponent.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| node | XComponent instance. |

> **NOTE**
>
> The XComponent instance passed to this API must be created using the [ArkUI NDK API](../../ui/ndk-access-the-arkts-page.md) or constructed through [NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters19).

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_XComponent_SetNeedSoftKeyboard()

```
int32_t OH_ArkUI_XComponent_SetNeedSoftKeyboard(ArkUI_NodeHandle node, bool needSoftKeyboard)
```

**Description**

Sets whether the soft keyboard is required for the XComponent.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| node | XComponent instance. |
|needSoftKeyboard|Whether the soft keyboard is required.|

> **NOTE**
>
> The XComponent instance passed to this API must be created using the [ArkUI NDK API](../../ui/ndk-access-the-arkts-page.md) or constructed through [NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters19).
>
> The default value of **needSoftKeyboard** of the XComponent is **false**.

**Returns**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode): The operation is successful.

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode): A parameter error occurs.

### OH_ArkUI_AccessibilityProvider_Create()

```
ArkUI_AccessibilityProvider* OH_ArkUI_AccessibilityProvider_Create(ArkUI_NodeHandle node)
```

**Description**

Creates an [ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider) instance for the XComponent.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| node | XComponent instance. |

> **NOTE**
>
> The XComponent instance passed to this API must be created using the [ArkUI NDK API](../../ui/ndk-access-the-arkts-page.md) or constructed through [NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters19).

**Returns**

Pointer of the [ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider) type.

### OH_ArkUI_AccessibilityProvider_Dispose()

```
void OH_ArkUI_AccessibilityProvider_Dispose(ArkUI_AccessibilityProvider* provider)
```

**Description**

Destroys the [ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider) instance created using [OH_ArkUI_AccessibilityProvider_Create](#oh_arkui_accessibilityprovider_create).

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| provider | [ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider) instance created using [OH_ArkUI_AccessibilityProvider_Create](#oh_arkui_accessibilityprovider_create). |

### OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent(
    OH_ArkUI_SurfaceCallback* callback,
    void (*onSurfaceShow)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**Description**

Sets a surface display callback for this [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) instance. The callback is invoked when the application window has returned to the foreground from the background.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| callback | Pointer to the [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) instance.|
|onSurfaceShow|Pointer to the surface display callback.<br> - **surfaceHolder**: pointer to an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.|

### OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent(
    OH_ArkUI_SurfaceCallback* callback,
    void (*onSurfaceHide)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**Description**

Sets a surface hiding callback for this [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) instance. The callback is invoked when the application window has entered the background from the foreground.

**Since**

20

**Parameters**

| Name| Description|
| -------- | -------- |
| callback | Pointer to the [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) instance.|
|onSurfaceHide|Pointer to the surface hiding callback.<br> - **surfaceHolder**: pointer to an [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) instance.|

<!--  -->

## Variable Description


### OH_XCOMPONENT_ID_LEN_MAX

```
const uint32_t OH_XCOMPONENT_ID_LEN_MAX = 128
```


**Description**


Maximum length of the ArkUI XComponent ID.


**Since**


8


### OH_MAX_TOUCH_POINTS_NUMBER

```
const uint32_t OH_MAX_TOUCH_POINTS_NUMBER = 10
```

**Description**

Maximum number of identifiable touch points in a touch event.

**Since**

8


### action

```
OH_NativeXComponent_MouseEventAction OH_NativeXComponent_MouseEvent::action
```

**Description**

Action of the mouse event.

**Since**

8


### button

```
OH_NativeXComponent_MouseEventButton OH_NativeXComponent_MouseEvent::button
```

**Description**

Mouse event button.

**Since**

8


### deviceId

```
int64_t OH_NativeXComponent_TouchEvent::deviceId = 0
```

**Description**

ID of the device where the current touch event is triggered.

**Since**

8


### DispatchHoverEvent

```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent) (OH_NativeXComponent *component, bool isHover)
```

**Description**

Invoked when a hover event is triggered.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| isHover  | Whether the mouse pointer or stylus is hovering over the component.<br>**true**: The mouse pointer or stylus has entered the component.<br>**false**: The mouse pointer or stylus has left the component.|

**Since**

8


### DispatchMouseEvent

```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when a mouse event is triggered.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| window  | Handle to the **NativeWindow** instance.             |

**Since**

8


### DispatchTouchEvent

```
void(* OH_NativeXComponent_Callback::DispatchTouchEvent) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when a touch event is triggered.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| window  | Handle to the **NativeWindow** instance.             |

**Since**

8


### force [1/3]

```
float OH_NativeXComponent_TouchPoint::force = 0.0
```

**Description**

Pressure of the touch event.

**Since**

8


### force [2/3]

```
float OH_NativeXComponent_TouchEvent::force = 0.0
```

**Description**

Pressure of the touch event.

**Since**

8


### force [3/3]

```
float OH_NativeXComponent_HistoricalPoint::force = 0.0
```

**Description**

Pressure of the touch event.

**Since**

10


### id [1/3]

```
int32_t OH_NativeXComponent_TouchPoint::id = 0
```

**Description**

Unique identifier of the finger.

**Since**

8


### id [2/3]

```
int32_t OH_NativeXComponent_TouchEvent::id = 0
```

**Description**

Unique identifier of the finger.

**Since**

8


### id [3/3]

```
int32_t OH_NativeXComponent_HistoricalPoint::id = 0
```

**Description**

Unique identifier of the finger.

**Since**

10


### isPressed

```
bool OH_NativeXComponent_TouchPoint::isPressed = false
```

**Description**

Whether the current point is pressed.

**Since**

8


### numPoints

```
uint32_t OH_NativeXComponent_TouchEvent::numPoints = 0
```

**Description**

Number of current touch points. The value **1** indicates single-finger touch, while a value greater than **1** indicates multi-finger touch.

**Since**

8


### OnSurfaceChanged

```
void(* OH_NativeXComponent_Callback::OnSurfaceChanged) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when the surface changes.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| window  | Handle to the **NativeWindow** instance.             |

**Since**

8


### OnSurfaceCreated

```
void(* OH_NativeXComponent_Callback::OnSurfaceCreated) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when a surface is created.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| window  | Handle to the **NativeWindow** instance.             |

**Since**

8


### OnSurfaceDestroyed

```
void(* OH_NativeXComponent_Callback::OnSurfaceDestroyed) (OH_NativeXComponent *component, void *window)
```

**Description**

Invoked when the surface is destroyed.

**Parameters**

| Name       | Description                           |
| --------- | ----------------------------- |
| component | Pointer to the **OH_NativeXComponent** instance.|
| window  | Handle to the **NativeWindow** instance.             |

**Since**

8


### screenX [1/4]

```
float OH_NativeXComponent_TouchPoint::screenX = 0.0
```

**Description**

X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since**

8


### screenX [2/4]

```
float OH_NativeXComponent_TouchEvent::screenX = 0.0
```

**Description**

X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since**

8


### screenX [3/4]

```
float OH_NativeXComponent_MouseEvent::screenX
```

**Description**

X coordinate of the click point relative to the upper left corner of the application screen where the XComponent is located.

**Since**

8


### screenX [4/4]

```
float OH_NativeXComponent_HistoricalPoint::screenX
```

**Description**

X coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since**

10


### screenY [1/4]

```
float OH_NativeXComponent_TouchPoint::screenY = 0.0
```

**Description**

Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since**

8


### screenY [2/4]

```
float OH_NativeXComponent_TouchEvent::screenY = 0.0
```

**Description**

Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since**

8


### screenY [3/4]

```
float OH_NativeXComponent_MouseEvent::screenY
```

**Description**

Y coordinate of the click point relative to the upper left corner of the application window where the XComponent is located.

**Since**

8


### screenY [4/4]

```
float OH_NativeXComponent_HistoricalPoint::screenY
```

**Description**

Y coordinate of the touch point relative to the upper left corner of the application window where the XComponent is located.

**Since**

10


### size [1/3]

```
double OH_NativeXComponent_TouchPoint::size = 0.0
```

**Description**

Contact area between the finger pad and the screen.

**Since**

8


### size [2/3]

```
double OH_NativeXComponent_TouchEvent::size = 0.0
```

**Description**

Contact area between the finger pad and the screen.

**Since**

8


### size [3/3]

```
double OH_NativeXComponent_HistoricalPoint::size = 0.0
```

**Description**

Contact area between the finger pad and the screen.

**Since**

10


### timeStamp [1/3]

```
long long OH_NativeXComponent_TouchPoint::timeStamp = 0
```

**Description**

Timestamp of the touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.

**Since**

8


### timeStamp [2/3]

```
long long OH_NativeXComponent_TouchEvent::timeStamp = 0
```

**Description**

Timestamp of the touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.

**Since**

8


### timeStamp [3/3]

```
int64_t OH_NativeXComponent_HistoricalPoint::timeStamp = 0
```

**Description**

Timestamp of the touch event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.

**Since**

10


### timestamp

```
int64_t OH_NativeXComponent_MouseEvent::timestamp
```

**Description**

Timestamp of the mouse event. It is interval between the time when the event is triggered and the time when the system starts, in nanoseconds.

**Since**

8


### touchPoints

```
OH_NativeXComponent_TouchPoint OH_NativeXComponent_TouchEvent::touchPoints[OH_MAX_TOUCH_POINTS_NUMBER]
```

**Description**

Array of the touch points.

**Since**

8


### type [1/3]

```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchPoint::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**Description**

Touch type of the touch event.

**Since**

8


### type [2/3]

```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchEvent::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**Description**

Touch type of the touch event.

**Since**

8


### type [3/3]

```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_HistoricalPoint::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**Description**

Touch type of the touch event.

**Since**

10


### x [1/4]

```
float OH_NativeXComponent_TouchPoint::x = 0.0
```

**Description**

X coordinate of the touch point relative to the left edge of the XComponent.

**Since**

8


### x [2/4]

```
float OH_NativeXComponent_TouchEvent::x = 0.0
```

**Description**

X coordinate of the touch point relative to the left edge of the XComponent.

**Since**

8


### x [3/4]

```
float OH_NativeXComponent_MouseEvent::x
```

**Description**

X coordinate of the clicked point relative to the upper left corner of the component.

**Since**

8


### x [4/4]

```
float OH_NativeXComponent_HistoricalPoint::x
```

**Description**

X coordinate of the touch point relative to the left edge of the XComponent.

**Since**

10


### y [1/4]

```
float OH_NativeXComponent_TouchPoint::y = 0.0
```

**Description**

Y coordinate of the touch point relative to the upper edge of the XComponent.

**Since**

8


### y [2/4]

```
float OH_NativeXComponent_TouchEvent::y = 0.0
```

**Description**

Y coordinate of the touch point relative to the upper edge of the XComponent.

**Since**

8


### y [3/4]

```
float OH_NativeXComponent_MouseEvent::y
```

**Description**

Y coordinate of the clicked point relative to the upper left corner of the component.

**Since**

8


### y [4/4]

```
float OH_NativeXComponent_HistoricalPoint::y
```

**Description**

Y coordinate of the touch point relative to the upper edge of the XComponent.

**Since**

10


### expected

```
int32_t OH_NativeXComponent_ExpectedRateRange::expected
```
**Description**

Expected frame rate range.

**Since**

11

### max

```
int32_t OH_NativeXComponent_ExpectedRateRange::max
```
**Description**

Maximum value of the expected frame rate range.

**Since**

11


### min

```
int32_t OH_NativeXComponent_ExpectedRateRange::min
```
**Description**

Minimum value of the expected frame rate range.

**Since**

11

### titlX

```
float OH_NativeXComponent_HistoricalPoint::titlX
```
**Description**

Angle between the projection on the x-y plane and the z-axis of the touch event.

**Since**

10


### titlY

```
float OH_NativeXComponent_HistoricalPoint::titlY
```
**Description**

Angle between the projection on the y-z plane and the z-axis of the current touch event.

**Since**

10


### sourceTool

```
OH_NativeXComponent_TouchEvent_SourceTool OH_NativeXComponent_HistoricalPoint::sourceTool
```
**Description**

Source tool of the touch event.

**Since**

10
