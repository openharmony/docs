# Native XComponent


## 概述

描述ArkUI XComponent持有的surface和触摸事件，该事件可用于EGL/OpenGLES和媒体数据输入，并显示在ArkUI XComponent上，具体使用请参考[Native XComponent](../../ui/napi-xcomponent-guidelines.md)。

> **说明：**
>
> 该模块从API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 汇总


### 文件

| 名称                                       | 描述                                       |
| ---------------------------------------- | ---------------------------------------- |
| [native_interface_xcomponent.h](native__interface__xcomponent_8h.md) | 声明用于访问Native&nbsp;XComponent的API。 |
| [native_xcomponent_key_event.h](native__xcomponent__key__event_8h.md) | 声明用于访问Native&nbsp;XComponent键盘事件所使用到的枚举类型。 |


### 结构体

| 名称                                       | 描述                    |
| ---------------------------------------- | --------------------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) | 触摸事件中触摸点的信息。          |
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | 触摸事件。                 |
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | 鼠标事件。                 |
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | 注册surface生命周期和触摸事件回调。 |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | 注册鼠标事件的回调。            |
| [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) | 定义期望帧率范围。  |


### 类型定义

| 名称                                       | 描述                                   |
| ---------------------------------------- | ------------------------------------ |
| [OH_NativeXComponent](#oh_nativexcomponent) | 提供封装的OH_NativeXComponent实例。          |
| [OH_NativeXComponent_Callback](#oh_nativexcomponent_callback) | 注册surface生命周期和触摸事件回调。                |
| [OH_NativeXComponent_MouseEvent_Callback](#oh_nativexcomponent_mouseevent_callback) | 注册鼠标事件的回调。                           |
| [OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent) | 提供封装的OH_NativeXComponent_KeyEvent实例。 |
| [OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo) | 提供封装的扩展的鼠标事件信息实例。|
| [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback) | 定义surface生命周期回调函数。|
| [OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder) | 提供封装的OH_ArkUI_SurfaceHolder实例。|
| [OHNativeWindow](#ohnativewindow) | 提供封装的NativeWindow实例。|


### 枚举

| 名称                                       | 描述         |
| ---------------------------------------- | ---------- |
| {&nbsp;OH_NATIVEXCOMPONENT_RESULT_SUCCESS&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_RESULT_FAILED&nbsp;=&nbsp;-1,&nbsp;OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER&nbsp;=&nbsp;-2&nbsp;} | 枚举API访问状态。 |
| [OH_NativeXComponent_TouchEventType](#oh_nativexcomponent_toucheventtype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_DOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_UP,&nbsp;OH_NATIVEXCOMPONENT_MOVE,&nbsp;OH_NATIVEXCOMPONENT_CANCEL,<br/>OH_NATIVEXCOMPONENT_UNKNOWN<br/>} | 触摸事件类型。    |
| [OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS<br/>} | 触摸点工具类型。   |
| [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD<br/>} | 触摸事件源类型。   |
| [OH_NativeXComponent_MouseEventAction](#oh_nativexcomponent_mouseeventaction)&nbsp;{&nbsp;OH_NATIVEXCOMPONENT_MOUSE_NONE&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_PRESS,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_RELEASE,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_MOVE&nbsp;OH_NATIVEXCOMPONENT_MOUSE_CANCEL&nbsp;} | 鼠标事件动作。    |
| [OH_NativeXComponent_MouseEventButton](#oh_nativexcomponent_mouseeventbutton)&nbsp;{<br/>OH_NATIVEXCOMPONENT_NONE_BUTTON&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_LEFT_BUTTON&nbsp;=&nbsp;0x01,&nbsp;OH_NATIVEXCOMPONENT_RIGHT_BUTTON&nbsp;=&nbsp;0x02,&nbsp;OH_NATIVEXCOMPONENT_MIDDLE_BUTTON&nbsp;=&nbsp;0x04,<br/>OH_NATIVEXCOMPONENT_BACK_BUTTON&nbsp;=&nbsp;0x08,&nbsp;OH_NATIVEXCOMPONENT_FORWARD_BUTTON&nbsp;=&nbsp;0x10<br/>} | 鼠标事件按键。    |
| [OH_NativeXComponent_KeyCode](#oh_nativexcomponent_keycode)&nbsp;{<br/>KEY_UNKNOWN&nbsp;=&nbsp;-1,&nbsp;KEY_FN&nbsp;=&nbsp;0,&nbsp;KEY_HOME&nbsp;=&nbsp;1,&nbsp;KEY_BACK&nbsp;=&nbsp;2,KEY_MEDIA_PLAY_PAUSE&nbsp;=&nbsp;10,&nbsp;KEY_MEDIA_STOP&nbsp;=&nbsp;11,&nbsp;KEY_MEDIA_NEXT&nbsp;=&nbsp;12,&nbsp;KEY_MEDIA_PREVIOUS&nbsp;=&nbsp;13,<br/>KEY_MEDIA_REWIND&nbsp;=&nbsp;14,&nbsp;KEY_MEDIA_FAST_FORWARD&nbsp;=&nbsp;15,&nbsp;KEY_VOLUME_UP&nbsp;=&nbsp;16,&nbsp;KEY_VOLUME_DOWN&nbsp;=&nbsp;17,<br/>KEY_POWER&nbsp;=&nbsp;18,&nbsp;KEY_CAMERA&nbsp;=&nbsp;19,&nbsp;KEY_VOLUME_MUTE&nbsp;=&nbsp;22,&nbsp;KEY_MUTE&nbsp;=&nbsp;23,KEY_BRIGHTNESS_UP&nbsp;=&nbsp;40,&nbsp;KEY_BRIGHTNESS_DOWN&nbsp;=&nbsp;41,&nbsp;KEY_0&nbsp;=&nbsp;2000,&nbsp;KEY_1&nbsp;=&nbsp;2001,<br/>KEY_2&nbsp;=&nbsp;2002,&nbsp;KEY_3&nbsp;=&nbsp;2003,&nbsp;KEY_4&nbsp;=&nbsp;2004,&nbsp;KEY_5&nbsp;=&nbsp;2005,<br/>KEY_6&nbsp;=&nbsp;2006,&nbsp;KEY_7&nbsp;=&nbsp;2007,&nbsp;KEY_8&nbsp;=&nbsp;2008,&nbsp;KEY_9&nbsp;=&nbsp;2009,<br/>KEY_STAR&nbsp;=&nbsp;2010,&nbsp;KEY_POUND&nbsp;=&nbsp;2011,&nbsp;KEY_DPAD_UP&nbsp;=&nbsp;2012,&nbsp;KEY_DPAD_DOWN&nbsp;=&nbsp;2013,KEY_DPAD_LEFT&nbsp;=&nbsp;2014,&nbsp;KEY_DPAD_RIGHT&nbsp;=&nbsp;2015,&nbsp;KEY_DPAD_CENTER&nbsp;=&nbsp;2016,<br/>KEY_A&nbsp;=&nbsp;2017,<br/>KEY_B&nbsp;=&nbsp;2018,&nbsp;KEY_C&nbsp;=&nbsp;2019,&nbsp;KEY_D&nbsp;=&nbsp;2020,&nbsp;KEY_E&nbsp;=&nbsp;2021,<br/>KEY_F&nbsp;=&nbsp;2022,&nbsp;KEY_G&nbsp;=&nbsp;2023,&nbsp;KEY_H&nbsp;=&nbsp;2024,&nbsp;KEY_I&nbsp;=&nbsp;2025,<br/>KEY_J&nbsp;=&nbsp;2026,&nbsp;KEY_K&nbsp;=&nbsp;2027,&nbsp;KEY_L&nbsp;=&nbsp;2028,&nbsp;KEY_M&nbsp;=&nbsp;2029,<br/>KEY_N&nbsp;=&nbsp;2030,&nbsp;KEY_O&nbsp;=&nbsp;2031,&nbsp;KEY_P&nbsp;=&nbsp;2032,&nbsp;KEY_Q&nbsp;=&nbsp;2033,<br/>KEY_R&nbsp;=&nbsp;2034,&nbsp;KEY_S&nbsp;=&nbsp;2035,&nbsp;KEY_T&nbsp;=&nbsp;2036,&nbsp;KEY_U&nbsp;=&nbsp;2037,<br/>KEY_V&nbsp;=&nbsp;2038,&nbsp;KEY_W&nbsp;=&nbsp;2039,&nbsp;KEY_X&nbsp;=&nbsp;2040,&nbsp;KEY_Y&nbsp;=&nbsp;2041,<br/>KEY_Z&nbsp;=&nbsp;2042,&nbsp;KEY_COMMA&nbsp;=&nbsp;2043,&nbsp;KEY_PERIOD&nbsp;=&nbsp;2044,&nbsp;KEY_ALT_LEFT&nbsp;=&nbsp;2045,<br/>KEY_ALT_RIGHT&nbsp;=&nbsp;2046,&nbsp;KEY_SHIFT_LEFT&nbsp;=&nbsp;2047,&nbsp;KEY_SHIFT_RIGHT&nbsp;=&nbsp;2048,&nbsp;KEY_TAB&nbsp;=&nbsp;2049,<br/>KEY_SPACE&nbsp;=&nbsp;2050,&nbsp;KEY_SYM&nbsp;=&nbsp;2051,&nbsp;KEY_EXPLORER&nbsp;=&nbsp;2052,&nbsp;KEY_ENVELOPE&nbsp;=&nbsp;2053,<br/>KEY_ENTER&nbsp;=&nbsp;2054,&nbsp;KEY_DEL&nbsp;=&nbsp;2055,&nbsp;KEY_GRAVE&nbsp;=&nbsp;2056,&nbsp;KEY_MINUS&nbsp;=&nbsp;2057,<br/>KEY_EQUALS&nbsp;=&nbsp;2058,&nbsp;KEY_LEFT_BRACKET&nbsp;=&nbsp;2059,&nbsp;KEY_RIGHT_BRACKET&nbsp;=&nbsp;2060,&nbsp;KEY_BACKSLASH&nbsp;=&nbsp;2061,<br/>KEY_SEMICOLON&nbsp;=&nbsp;2062,&nbsp;KEY_APOSTROPHE&nbsp;=&nbsp;2063,&nbsp;KEY_SLASH&nbsp;=&nbsp;2064,&nbsp;KEY_AT&nbsp;=&nbsp;2065,<br/>KEY_PLUS&nbsp;=&nbsp;2066,&nbsp;KEY_MENU&nbsp;=&nbsp;2067,&nbsp;KEY_PAGE_UP&nbsp;=&nbsp;2068,&nbsp;KEY_PAGE_DOWN&nbsp;=&nbsp;2069,<br/>KEY_ESCAPE&nbsp;=&nbsp;2070,&nbsp;KEY_FORWARD_DEL&nbsp;=&nbsp;2071,&nbsp;KEY_CTRL_LEFT&nbsp;=&nbsp;2072,&nbsp;KEY_CTRL_RIGHT&nbsp;=&nbsp;2073,<br/>KEY_CAPS_LOCK&nbsp;=&nbsp;2074,&nbsp;KEY_SCROLL_LOCK&nbsp;=&nbsp;2075,&nbsp;KEY_META_LEFT&nbsp;=&nbsp;2076,&nbsp;KEY_META_RIGHT&nbsp;=&nbsp;2077,<br/>KEY_FUNCTION&nbsp;=&nbsp;2078,&nbsp;KEY_SYSRQ&nbsp;=&nbsp;2079,&nbsp;KEY_BREAK&nbsp;=&nbsp;2080,&nbsp;KEY_MOVE_HOME&nbsp;=&nbsp;2081,<br/>KEY_MOVE_END&nbsp;=&nbsp;2082,&nbsp;KEY_INSERT&nbsp;=&nbsp;2083,&nbsp;KEY_FORWARD&nbsp;=&nbsp;2084,&nbsp;KEY_MEDIA_PLAY&nbsp;=&nbsp;2085,<br/>KEY_MEDIA_PAUSE&nbsp;=&nbsp;2086,&nbsp;KEY_MEDIA_CLOSE&nbsp;=&nbsp;2087,&nbsp;KEY_MEDIA_EJECT&nbsp;=&nbsp;2088,&nbsp;KEY_MEDIA_RECORD&nbsp;=&nbsp;2089,<br/>KEY_F1&nbsp;=&nbsp;2090,&nbsp;KEY_F2&nbsp;=&nbsp;2091,&nbsp;KEY_F3&nbsp;=&nbsp;2092,&nbsp;KEY_F4&nbsp;=&nbsp;2093,<br/>KEY_F5&nbsp;=&nbsp;2094,&nbsp;KEY_F6&nbsp;=&nbsp;2095,&nbsp;KEY_F7&nbsp;=&nbsp;2096,&nbsp;KEY_F8&nbsp;=&nbsp;2097,<br/>KEY_F9&nbsp;=&nbsp;2098,&nbsp;KEY_F10&nbsp;=&nbsp;2099,&nbsp;KEY_F11&nbsp;=&nbsp;2100,&nbsp;KEY_F12&nbsp;=&nbsp;2101,<br/>KEY_NUM_LOCK&nbsp;=&nbsp;2102,&nbsp;KEY_NUMPAD_0&nbsp;=&nbsp;2103,&nbsp;KEY_NUMPAD_1&nbsp;=&nbsp;2104,&nbsp;KEY_NUMPAD_2&nbsp;=&nbsp;2105,<br/>KEY_NUMPAD_3&nbsp;=&nbsp;2106,&nbsp;KEY_NUMPAD_4&nbsp;=&nbsp;2107,&nbsp;KEY_NUMPAD_5&nbsp;=&nbsp;2108,&nbsp;KEY_NUMPAD_6&nbsp;=&nbsp;2109,<br/>KEY_NUMPAD_7&nbsp;=&nbsp;2110,&nbsp;KEY_NUMPAD_8&nbsp;=&nbsp;2111,&nbsp;KEY_NUMPAD_9&nbsp;=&nbsp;2112,&nbsp;KEY_NUMPAD_DIVIDE&nbsp;=&nbsp;2113,<br/>KEY_NUMPAD_MULTIPLY&nbsp;=&nbsp;2114,&nbsp;KEY_NUMPAD_SUBTRACT&nbsp;=&nbsp;2115,&nbsp;KEY_NUMPAD_ADD&nbsp;=&nbsp;2116,&nbsp;KEY_NUMPAD_DOT&nbsp;=&nbsp;2117,<br/>KEY_NUMPAD_COMMA&nbsp;=&nbsp;2118,&nbsp;KEY_NUMPAD_ENTER&nbsp;=&nbsp;2119,&nbsp;KEY_NUMPAD_EQUALS&nbsp;=&nbsp;2120,&nbsp;KEY_NUMPAD_LEFT_PAREN&nbsp;=&nbsp;2121,<br/>KEY_NUMPAD_RIGHT_PAREN&nbsp;=&nbsp;2122,&nbsp;KEY_VIRTUAL_MULTITASK&nbsp;=&nbsp;2210,&nbsp;KEY_SLEEP&nbsp;=&nbsp;2600,&nbsp;KEY_ZENKAKU_HANKAKU&nbsp;=&nbsp;2601,<br/>KEY_102ND&nbsp;=&nbsp;2602,&nbsp;KEY_RO&nbsp;=&nbsp;2603,&nbsp;KEY_KATAKANA&nbsp;=&nbsp;2604,&nbsp;KEY_HIRAGANA&nbsp;=&nbsp;2605,<br/>KEY_HENKAN&nbsp;=&nbsp;2606,&nbsp;KEY_KATAKANA_HIRAGANA&nbsp;=&nbsp;2607,&nbsp;KEY_MUHENKAN&nbsp;=&nbsp;2608,&nbsp;KEY_LINEFEED&nbsp;=&nbsp;2609,<br/>KEY_MACRO&nbsp;=&nbsp;2610,&nbsp;KEY_NUMPAD_PLUSMINUS&nbsp;=&nbsp;2611,&nbsp;KEY_SCALE&nbsp;=&nbsp;2612,&nbsp;KEY_HANGUEL&nbsp;=&nbsp;2613,<br/>KEY_HANJA&nbsp;=&nbsp;2614,&nbsp;KEY_YEN&nbsp;=&nbsp;2615,&nbsp;KEY_STOP&nbsp;=&nbsp;2616,&nbsp;KEY_AGAIN&nbsp;=&nbsp;2617,<br/>KEY_PROPS&nbsp;=&nbsp;2618,&nbsp;KEY_UNDO&nbsp;=&nbsp;2619,&nbsp;KEY_COPY&nbsp;=&nbsp;2620,&nbsp;KEY_OPEN&nbsp;=&nbsp;2621,<br/>KEY_PASTE&nbsp;=&nbsp;2622,&nbsp;KEY_FIND&nbsp;=&nbsp;2623,&nbsp;KEY_CUT&nbsp;=&nbsp;2624,&nbsp;KEY_HELP&nbsp;=&nbsp;2625,<br/>KEY_CALC&nbsp;=&nbsp;2626,&nbsp;KEY_FILE&nbsp;=&nbsp;2627,&nbsp;KEY_BOOKMARKS&nbsp;=&nbsp;2628,&nbsp;KEY_NEXT&nbsp;=&nbsp;2629,<br/>KEY_PLAYPAUSE&nbsp;=&nbsp;2630,&nbsp;KEY_PREVIOUS&nbsp;=&nbsp;2631,&nbsp;KEY_STOPCD&nbsp;=&nbsp;2632,&nbsp;KEY_CONFIG&nbsp;=&nbsp;2634,<br/>KEY_REFRESH&nbsp;=&nbsp;2635,&nbsp;KEY_EXIT&nbsp;=&nbsp;2636,&nbsp;KEY_EDIT&nbsp;=&nbsp;2637,&nbsp;KEY_SCROLLUP&nbsp;=&nbsp;2638,<br/>KEY_SCROLLDOWN&nbsp;=&nbsp;2639,&nbsp;KEY_NEW&nbsp;=&nbsp;2640,&nbsp;KEY_REDO&nbsp;=&nbsp;2641,&nbsp;KEY_CLOSE&nbsp;=&nbsp;2642,<br/>KEY_PLAY&nbsp;=&nbsp;2643,&nbsp;KEY_BASSBOOST&nbsp;=&nbsp;2644,&nbsp;KEY_PRINT&nbsp;=&nbsp;2645,&nbsp;KEY_CHAT&nbsp;=&nbsp;2646,<br/>KEY_FINANCE&nbsp;=&nbsp;2647,&nbsp;KEY_CANCEL&nbsp;=&nbsp;2648,&nbsp;KEY_KBDILLUM_TOGGLE&nbsp;=&nbsp;2649,&nbsp;KEY_KBDILLUM_DOWN&nbsp;=&nbsp;2650,<br/>KEY_KBDILLUM_UP&nbsp;=&nbsp;2651,&nbsp;KEY_SEND&nbsp;=&nbsp;2652,&nbsp;KEY_REPLY&nbsp;=&nbsp;2653,&nbsp;KEY_FORWARDMAIL&nbsp;=&nbsp;2654,<br/>KEY_SAVE&nbsp;=&nbsp;2655,&nbsp;KEY_DOCUMENTS&nbsp;=&nbsp;2656,&nbsp;KEY_VIDEO_NEXT&nbsp;=&nbsp;2657,&nbsp;KEY_VIDEO_PREV&nbsp;=&nbsp;2658,<br/>KEY_BRIGHTNESS_CYCLE&nbsp;=&nbsp;2659,&nbsp;KEY_BRIGHTNESS_ZERO&nbsp;=&nbsp;2660,&nbsp;KEY_DISPLAY_OFF&nbsp;=&nbsp;2661,&nbsp;KEY_BTN_MISC&nbsp;=&nbsp;2662,<br/>KEY_GOTO&nbsp;=&nbsp;2663,&nbsp;KEY_INFO&nbsp;=&nbsp;2664,&nbsp;KEY_PROGRAM&nbsp;=&nbsp;2665,&nbsp;KEY_PVR&nbsp;=&nbsp;2666,<br/>KEY_SUBTITLE&nbsp;=&nbsp;2667,&nbsp;KEY_FULL_SCREEN&nbsp;=&nbsp;2668,&nbsp;KEY_KEYBOARD&nbsp;=&nbsp;2669,&nbsp;KEY_ASPECT_RATIO&nbsp;=&nbsp;2670,<br/>KEY_PC&nbsp;=&nbsp;2671,&nbsp;KEY_TV&nbsp;=&nbsp;2672,&nbsp;KEY_TV2&nbsp;=&nbsp;2673,&nbsp;KEY_VCR&nbsp;=&nbsp;2674,<br/>KEY_VCR2&nbsp;=&nbsp;2675,&nbsp;KEY_SAT&nbsp;=&nbsp;2676,&nbsp;KEY_CD&nbsp;=&nbsp;2677,&nbsp;KEY_TAPE&nbsp;=&nbsp;2678,<br/>KEY_TUNER&nbsp;=&nbsp;2679,&nbsp;KEY_PLAYER&nbsp;=&nbsp;2680,&nbsp;KEY_DVD&nbsp;=&nbsp;2681,&nbsp;KEY_AUDIO&nbsp;=&nbsp;2682,<br/>KEY_VIDEO&nbsp;=&nbsp;2683,&nbsp;KEY_MEMO&nbsp;=&nbsp;2684,&nbsp;KEY_CALENDAR&nbsp;=&nbsp;2685,&nbsp;KEY_RED&nbsp;=&nbsp;2686,<br/>KEY_GREEN&nbsp;=&nbsp;2687,&nbsp;KEY_YELLOW&nbsp;=&nbsp;2688,&nbsp;KEY_BLUE&nbsp;=&nbsp;2689,&nbsp;KEY_CHANNELUP&nbsp;=&nbsp;2690,<br/>KEY_CHANNELDOWN&nbsp;=&nbsp;2691,&nbsp;KEY_LAST&nbsp;=&nbsp;2692,&nbsp;KEY_RESTART&nbsp;=&nbsp;2693,&nbsp;KEY_SLOW&nbsp;=&nbsp;2694,<br/>KEY_SHUFFLE&nbsp;=&nbsp;2695,&nbsp;KEY_VIDEOPHONE&nbsp;=&nbsp;2696,&nbsp;KEY_GAMES&nbsp;=&nbsp;2697,&nbsp;KEY_ZOOMIN&nbsp;=&nbsp;2698,<br/>KEY_ZOOMOUT&nbsp;=&nbsp;2699,&nbsp;KEY_ZOOMRESET&nbsp;=&nbsp;2700,&nbsp;KEY_WORDPROCESSOR&nbsp;=&nbsp;2701,&nbsp;KEY_EDITOR&nbsp;=&nbsp;2702,<br/>KEY_SPREADSHEET&nbsp;=&nbsp;2703,&nbsp;KEY_GRAPHICSEDITOR&nbsp;=&nbsp;2704,&nbsp;KEY_PRESENTATION&nbsp;=&nbsp;2705,&nbsp;KEY_DATABASE&nbsp;=&nbsp;2706,<br/>KEY_NEWS&nbsp;=&nbsp;2707,&nbsp;KEY_VOICEMAIL&nbsp;=&nbsp;2708,&nbsp;KEY_ADDRESSBOOK&nbsp;=&nbsp;2709,&nbsp;KEY_MESSENGER&nbsp;=&nbsp;2710,<br/>KEY_BRIGHTNESS_TOGGLE&nbsp;=&nbsp;2711,&nbsp;KEY_SPELLCHECK&nbsp;=&nbsp;2712,&nbsp;KEY_COFFEE&nbsp;=&nbsp;2713,&nbsp;KEY_MEDIA_REPEAT&nbsp;=&nbsp;2714,<br/>KEY_IMAGES&nbsp;=&nbsp;2715,&nbsp;KEY_BUTTONCONFIG&nbsp;=&nbsp;2716,&nbsp;KEY_TASKMANAGER&nbsp;=&nbsp;2717,&nbsp;KEY_JOURNAL&nbsp;=&nbsp;2718,<br/>KEY_CONTROLPANEL&nbsp;=&nbsp;2719,&nbsp;KEY_APPSELECT&nbsp;=&nbsp;2720,&nbsp;KEY_SCREENSAVER&nbsp;=&nbsp;2721,&nbsp;KEY_ASSISTANT&nbsp;=&nbsp;2722,<br/>KEY_KBD_LAYOUT_NEXT&nbsp;=&nbsp;2723,&nbsp;KEY_BRIGHTNESS_MIN&nbsp;=&nbsp;2724,&nbsp;KEY_BRIGHTNESS_MAX&nbsp;=&nbsp;2725,&nbsp;KEY_KBDINPUTASSIST_PREV&nbsp;=&nbsp;2726,<br/>KEY_KBDINPUTASSIST_NEXT&nbsp;=&nbsp;2727,&nbsp;KEY_KBDINPUTASSIST_PREVGROUP&nbsp;=&nbsp;2728,&nbsp;KEY_KBDINPUTASSIST_NEXTGROUP&nbsp;=&nbsp;2729,&nbsp;KEY_KBDINPUTASSIST_ACCEPT&nbsp;=&nbsp;2730,<br/>KEY_KBDINPUTASSIST_CANCEL&nbsp;=&nbsp;2731,&nbsp;KEY_FRONT&nbsp;=&nbsp;2800,&nbsp;KEY_SETUP&nbsp;=&nbsp;2801,&nbsp;KEY_WAKEUP&nbsp;=&nbsp;2802,<br/>KEY_SENDFILE&nbsp;=&nbsp;2803,&nbsp;KEY_DELETEFILE&nbsp;=&nbsp;2804,&nbsp;KEY_XFER&nbsp;=&nbsp;2805,&nbsp;KEY_PROG1&nbsp;=&nbsp;2806,<br/>KEY_PROG2&nbsp;=&nbsp;2807,&nbsp;KEY_MSDOS&nbsp;=&nbsp;2808,&nbsp;KEY_SCREENLOCK&nbsp;=&nbsp;2809,&nbsp;KEY_DIRECTION_ROTATE_DISPLAY&nbsp;=&nbsp;2810,<br/>KEY_CYCLEWINDOWS&nbsp;=&nbsp;2811,&nbsp;KEY_COMPUTER&nbsp;=&nbsp;2812,&nbsp;KEY_EJECTCLOSECD&nbsp;=&nbsp;2813,&nbsp;KEY_ISO&nbsp;=&nbsp;2814,<br/>KEY_MOVE&nbsp;=&nbsp;2815,&nbsp;KEY_F13&nbsp;=&nbsp;2816,&nbsp;KEY_F14&nbsp;=&nbsp;2817,&nbsp;KEY_F15&nbsp;=&nbsp;2818,<br/>KEY_F16&nbsp;=&nbsp;2819,&nbsp;KEY_F17&nbsp;=&nbsp;2820,&nbsp;KEY_F18&nbsp;=&nbsp;2821,&nbsp;KEY_F19&nbsp;=&nbsp;2822,<br/>KEY_F20&nbsp;=&nbsp;2823,&nbsp;KEY_F21&nbsp;=&nbsp;2824,&nbsp;KEY_F22&nbsp;=&nbsp;2825,&nbsp;KEY_F23&nbsp;=&nbsp;2826,<br/>KEY_F24&nbsp;=&nbsp;2827,&nbsp;KEY_PROG3&nbsp;=&nbsp;2828,&nbsp;KEY_PROG4&nbsp;=&nbsp;2829,&nbsp;KEY_DASHBOARD&nbsp;=&nbsp;2830,<br/>KEY_SUSPEND&nbsp;=&nbsp;2831,&nbsp;KEY_HP&nbsp;=&nbsp;2832,&nbsp;KEY_SOUND&nbsp;=&nbsp;2833,&nbsp;KEY_QUESTION&nbsp;=&nbsp;2834,<br/>KEY_CONNECT&nbsp;=&nbsp;2836,&nbsp;KEY_SPORT&nbsp;=&nbsp;2837,&nbsp;KEY_SHOP&nbsp;=&nbsp;2838,&nbsp;KEY_ALTERASE&nbsp;=&nbsp;2839,<br/>KEY_SWITCHVIDEOMODE&nbsp;=&nbsp;2841,&nbsp;KEY_BATTERY&nbsp;=&nbsp;2842,&nbsp;KEY_BLUETOOTH&nbsp;=&nbsp;2843,&nbsp;KEY_WLAN&nbsp;=&nbsp;2844,<br/>KEY_UWB&nbsp;=&nbsp;2845,&nbsp;KEY_WWAN_WIMAX&nbsp;=&nbsp;2846,&nbsp;KEY_RFKILL&nbsp;=&nbsp;2847,&nbsp;KEY_CHANNEL&nbsp;=&nbsp;3001,<br/>KEY_BTN_0&nbsp;=&nbsp;3100,&nbsp;KEY_BTN_1&nbsp;=&nbsp;3101,&nbsp;KEY_BTN_2&nbsp;=&nbsp;3102,&nbsp;KEY_BTN_3&nbsp;=&nbsp;3103,<br/>KEY_BTN_4&nbsp;=&nbsp;3104,&nbsp;KEY_BTN_5&nbsp;=&nbsp;3105,&nbsp;KEY_BTN_6&nbsp;=&nbsp;3106,&nbsp;KEY_BTN_7&nbsp;=&nbsp;3107,<br/>KEY_BTN_8&nbsp;=&nbsp;3108,&nbsp;KEY_BTN_9&nbsp;=&nbsp;3109<br/>} | 按键事件的键码。   |
| [OH_NativeXComponent_KeyAction](#oh_nativexcomponent_keyaction)&nbsp;{&nbsp;OH_NATIVEXCOMPONENT_KEY_ACTION_UNKNOWN&nbsp;=&nbsp;-1,&nbsp;OH_NATIVEXCOMPONENT_KEY_ACTION_DOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_KEY_ACTION_UP&nbsp;} | 按键事件动作。    |
|[ArkUI_XComponent_ImageAnalyzerState](#arkui_xcomponent_imageanalyzerstate)&nbsp;{&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_FINISHED&nbsp;=&nbsp;0,&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_DISABLED&nbsp;=&nbsp;110000,&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_UNSUPPORTED&nbsp;=&nbsp;110001,&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_ONGOING&nbsp;=&nbsp;110002,&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_STOPPED&nbsp;=&nbsp;110003}|XComponent图像AI分析状态码。|


### 函数

| 名称                                       | 描述                                     |
| ---------------------------------------- | -------------------------------------- |
| [OH_NativeXComponent_GetXComponentId](#oh_nativexcomponent_getxcomponentid)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;char&nbsp;\*id,&nbsp;uint64_t&nbsp;\*size) | 获取ArkUI&nbsp;XComponent的id。            |
| [OH_NativeXComponent_GetXComponentSize](#oh_nativexcomponent_getxcomponentsize)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;uint64_t&nbsp;\*width,&nbsp;uint64_t&nbsp;\*height) | 获取ArkUI&nbsp;XComponent持有的surface的大小。  |
| [OH_NativeXComponent_GetXComponentOffset](#oh_nativexcomponent_getxcomponentoffset)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;double&nbsp;\*x,&nbsp;double&nbsp;\*y) | 获取XComponent持有的surface相对其父组件左顶点的偏移量。 |
| [OH_NativeXComponent_GetTouchEvent](#oh_nativexcomponent_gettouchevent)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;[OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md)&nbsp;\*touchEvent) | 获取ArkUI&nbsp;XComponent调度的触摸事件。        |
| [OH_NativeXComponent_GetTouchPointToolType](#oh_nativexcomponent_gettouchpointtooltype)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;[OH_NativeXComponent_TouchPointToolType](#oh_nativexcomponent_touchpointtooltype)&nbsp;\*toolType) | 获取ArkUI&nbsp;XComponent触摸点工具类型。        |
| [OH_NativeXComponent_GetTouchPointTiltX](#oh_nativexcomponent_gettouchpointtiltx)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;float&nbsp;\*tiltX) | 获取ArkUI&nbsp;XComponent触摸点倾斜与X轴角度。     |
| [OH_NativeXComponent_GetTouchPointTiltY](#oh_nativexcomponent_gettouchpointtilty)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;float&nbsp;\*tiltY) | 获取ArkUI&nbsp;XComponent触摸点倾斜与Y轴角度。     |
| [OH_NativeXComponent_GetMouseEvent](#oh_nativexcomponent_getmouseevent)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;[OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md)&nbsp;\*mouseEvent) | 获取ArkUI&nbsp;XComponent调度的鼠标事件。        |
| [OH_NativeXComponent_RegisterCallback](#oh_nativexcomponent_registercallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md)&nbsp;\*callback) | 为此OH_NativeXComponent实例注册回调。           |
| [OH_NativeXComponent_RegisterMouseEventCallback](#oh_nativexcomponent_registermouseeventcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md)&nbsp;\*callback) | 为此OH_NativeXComponent实例注册鼠标事件回调。       |
| [OH_NativeXComponent_RegisterFocusEventCallback](#oh_nativexcomponent_registerfocuseventcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册获焦事件回调。       |
| [OH_NativeXComponent_RegisterKeyEventCallback](#oh_nativexcomponent_registerkeyeventcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册按键事件回调。       |
| [OH_NativeXComponent_RegisterKeyEventCallbackWithResult](#oh_nativexcomponent_registerkeyeventcallbackwithresult)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;bool(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册有返回值的按键事件回调。       |
| [OH_NativeXComponent_RegisterBlurEventCallback](#oh_nativexcomponent_registerblureventcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册失焦事件回调。       |
| [OH_NativeXComponent_GetKeyEvent](#oh_nativexcomponent_getkeyevent)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*\*keyEvent) | 获取ArkUI&nbsp;XComponent调度的按键事件。        |
| [OH_NativeXComponent_GetKeyEventAction](#oh_nativexcomponent_getkeyeventaction)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_KeyAction](#oh_nativexcomponent_keyaction)&nbsp;\*action) | 获取传入按键事件的动作。                           |
| [OH_NativeXComponent_GetKeyEventCode](#oh_nativexcomponent_getkeyeventcode)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_KeyCode](#oh_nativexcomponent_keycode)&nbsp;\*code) | 获取传入按键事件的按键码。                          |
| [OH_NativeXComponent_GetKeyEventSourceType](#oh_nativexcomponent_getkeyeventsourcetype)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype)&nbsp;\*sourceType) | 获取传入按键事件的事件源类型。                        |
| [OH_NativeXComponent_GetKeyEventDeviceId](#oh_nativexcomponent_getkeyeventdeviceid)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;int64_t&nbsp;\*deviceId) | 获取传入按键事件的设备id。                         |
| [OH_NativeXComponent_GetKeyEventTimestamp](#oh_nativexcomponent_getkeyeventtimestamp)&nbsp;([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;int64_t&nbsp;\*timeStamp) | 获取传入按键事件的时间戳。                          |
| [OH_NativeXComponent_SetExpectedFrameRateRange](#oh_nativexcomponent_setexpectedframeraterange) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) \*range) | 设置期望帧率范围。                                           |
| [OH_NativeXComponent_RegisterOnFrameCallback](#oh_nativexcomponent_registeronframecallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, uint64_t timestamp, uint64_t targetTimestamp)) | 为此OH_NativeXComponent实例注册显示更新回调，并使能每帧回调此函数。 |
| [OH_NativeXComponent_UnregisterOnFrameCallback](#oh_nativexcomponent_unregisteronframecallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component) | 为此OH_NativeXComponent实例取消注册回调函数，并关闭每帧回调此函数。 |
| int32_t [OH_NativeXComponent_AttachNativeRootNode](#oh_nativexcomponent_attachnativerootnode) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) root) | 将通过ArkUI的native接口创建出来的UI组件挂载到当前XComponent上。  |
| int32_t [OH_NativeXComponent_DetachNativeRootNode](#oh_nativexcomponent_detachnativerootnode) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) root) | 将ArkUI的native组件从当前XComponent上卸载.  |
| int32_t [OH_NativeXComponent_RegisterUIInputEventCallback](#oh_nativexcomponent_registeruiinputeventcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) type), [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) type) | 为此OH_NativeXComponent实例注册UI输入事件回调，并使能收到UI输入事件时回调此函数。  |
| int32_t [OH_NativeXComponent_RegisterOnTouchInterceptCallback](#oh_nativexcomponent_registerontouchinterceptcallback) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, [HitTestMode](_ark_u_i___native_module.md#hittestmode)(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event)) | 为此OH_NativeXComponent实例注册自定义事件拦截回调，并使能在做触摸测试时回调此函数。  |
| int32_t [OH_NativeXComponent_SetNeedSoftKeyboard](#oh_nativexcomponent_setneedsoftkeyboard) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, bool isNeedSoftKeyboard) | 为此OH_NativeXComponent实例设置是否需要软键盘。  |
| int32_t [OH_NativeXComponent_RegisterSurfaceShowCallback](#oh_nativexcomponent_registersurfaceshowcallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册surface显示回调，该回调在应用从后台返回前台后触发。 |
| int32_t [OH_NativeXComponent_RegisterSurfaceHideCallback](#oh_nativexcomponent_registersurfacehidecallback)&nbsp;([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册surface隐藏回调，该回调在应用从前台来到后台后触发。 |
| int32_t [OH_NativeXComponent_GetTouchEventSourceType](#oh_nativexcomponent_gettoucheventsourcetype) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, int32_t pointId, [OH_NativeXComponent_EventSourceType](#oh_nativexcomponent_eventsourcetype) \*sourceType) | 获取ArkUI XComponent触摸事件的输入设备类型。  |
| [OH_NativeXComponent](#oh_nativexcomponent) \* [OH_NativeXComponent_GetNativeXComponent](#oh_nativexcomponent_getnativexcomponent) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 基于Native接口创建的组件实例获取OH_NativeXComponent类型的指针。  |
| int32_t [OH_NativeXComponent_GetNativeAccessibilityProvider](#oh_nativexcomponent_getnativeaccessibilityprovider)([OH_NativeXComponent](#oh_nativexcomponent)* component, [ArkUI_AccessibilityProvider](./arkui_native_interface_accessibility.md#arkui_accessibilityprovider)** handle); | 基于NativeXComponent实例获取的ArkUI_AccessibilityProvider类型的指针。 |
| int32_t [OH_NativeXComponent_RegisterKeyEventCallbackWithResult](#oh_nativexcomponent_registerkeyeventcallbackwithresult) ([OH_NativeXComponent](#oh_nativexcomponent) \*component, bool(\*callback)([OH_NativeXComponent](#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册有返回值的按键事件回调。  | 
|int32_t [OH_ArkUI_XComponent_StartImageAnalyzer](#oh_arkui_xcomponent_startimageanalyzer) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData,void (\*callback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_XComponent_ImageAnalyzerState](#arkui_xcomponent_imageanalyzerstate) statusCode, void \*userData))|为此XComponent组件实例开始图像AI分析。|
|int32_t [OH_ArkUI_XComponent_StopImageAnalyzer](#oh_arkui_xcomponent_stopimageanalyzer)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|为此XComponent组件实例停止图像AI分析。|
|[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* [OH_ArkUI_SurfaceCallback_Create](#oh_arkui_surfacecallback_create)()|创建OH_ArkUI_SurfaceCallback对象。|
|void [OH_ArkUI_SurfaceCallback_Dispose](#oh_arkui_surfacecallback_dispose)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback)|销毁OH_ArkUI_SurfaceCallback对象。|
|[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* [OH_ArkUI_SurfaceHolder_Create](#oh_arkui_surfaceholder_create)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|创建XComponent组件的OH_ArkUI_SurfaceHolder对象。|
|void [OH_ArkUI_SurfaceHolder_Dispose](#oh_arkui_surfaceholder_dispose)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder)|销毁OH_ArkUI_SurfaceHolder对象。|
|int32_t [OH_ArkUI_SurfaceHolder_SetUserData](#oh_arkui_surfaceholder_setuserdata)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder, void* userData)|向OH_ArkUI_SurfaceHolder实例存储自定义数据。|
|void* [OH_ArkUI_SurfaceHolder_GetUserData](#oh_arkui_surfaceholder_getuserdata)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder)|获取OH_ArkUI_SurfaceHolder实例存储的自定义数据。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent](#oh_arkui_surfacecallback_setsurfacecreatedevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback, void (\*onSurfaceCreated)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)\* surfaceHolder))|设置surface生命周期回调中的创建回调事件。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent](#oh_arkui_surfacecallback_setsurfacechangedevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback, void (\*onSurfaceChanged)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)\* surfaceHolder, uint64_t width, uint64_t height))|设置surface生命周期回调中的大小改变回调事件。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent](#oh_arkui_surfacecallback_setsurfacedestroyedevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback, void (\*onSurfaceDestroyed)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)\* surfaceHolder))|设置surface生命周期回调中的销毁回调事件。|
|int32_t [OH_ArkUI_SurfaceHolder_AddSurfaceCallback](#oh_arkui_surfaceholder_addsurfacecallback)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder, [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback)|添加surface生命周期回调到OH_ArkUI_SurfaceHolder实例。|
|int32_t [OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback](#oh_arkui_surfaceholder_removesurfacecallback)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder, [OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback)|删除OH_ArkUI_SurfaceHolder实例的先前添加的surface生命周期回调。|
|[OHNativeWindow](#ohnativewindow)* [OH_ArkUI_XComponent_GetNativeWindow](#oh_arkui_xcomponent_getnativewindow)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder)|获取OH_ArkUI_SurfaceHolder实例关联的nativeWindow。|
|int32_t [OH_ArkUI_XComponent_SetAutoInitialize](#oh_arkui_xcomponent_setautoinitialize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool autoInitialize)|设置XComponent组件是否需要自动初始化Surface的标志位。|
|int32_t [OH_ArkUI_XComponent_Initialize](#oh_arkui_xcomponent_initialize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|初始化XComponent组件持有的Surface。|
|int32_t [OH_ArkUI_XComponent_Finalize](#oh_arkui_xcomponent_finalize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|销毁XComponent组件持有的surface。|
|int32_t [OH_ArkUI_XComponent_IsInitialized](#oh_arkui_xcomponent_isinitialized)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool* isInitialized)|获取XComponent组件是否已经初始化Surface的标志位。|
|int32_t [OH_NativeXComponent_GetExtraMouseEventInfo](#oh_nativexcomponent_getextramouseeventinfo)([OH_NativeXComponent](#oh_nativexcomponent)* component, [OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo)** extraMouseEventInfo)| 从此OH_NativeXComponent实例中获取扩展的鼠标事件信息。|
|int32_t [OH_NativeXComponent_GetMouseEventModifierKeyStates](#oh_nativexcomponent_getmouseeventmodifierkeystates)([OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo)* extraMouseEventInfo, uint64_t* keys)|从OH_NativeXComponent_ExtraMouseEventInfo实例中获取功能键按压状态信息。|
|int32_t [OH_NativeXComponent_GetKeyEventModifierKeyStates](#oh_nativexcomponent_getkeyeventmodifierkeystates)([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)* keyEvent, uint64_t* keys)|从按键事件中获取功能键按压状态信息。|
|int32_t [OH_NativeXComponent_GetKeyEventNumLockState](#oh_nativexcomponent_getkeyeventnumlockstate)([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)* keyEvent, bool* isNumLockOn) | 从按键事件中获取NumLock（小键盘锁定）键的状态信息。|
|int32_t [OH_NativeXComponent_GetKeyEventCapsLockState](#oh_nativexcomponent_getkeyeventcapslockstate)([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)* keyEvent, bool* isCapsLockOn)| 从按键事件中获取CapsLock（大写锁定）键的状态信息。|
|int32_t [OH_NativeXComponent_GetKeyEventScrollLockState](#oh_nativexcomponent_getkeyeventscrolllockstate)([OH_NativeXComponent_KeyEvent](#oh_nativexcomponent_keyevent)* keyEvent, bool* isScrollLockOn) | 从按键事件中获取ScrollLock（滚动锁定）键的状态信息。|
|int32_t [OH_ArkUI_XComponent_SetExpectedFrameRateRange](#oh_arkui_xcomponent_setexpectedframeraterange)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) range)|为此XComponent组件实例设置期望帧率。|
|int32_t [OH_ArkUI_XComponent_RegisterOnFrameCallback](#oh_arkui_xcomponent_registeronframecallback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node,void (*callback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, uint64_t timestamp, uint64_t targetTimestamp))|为此XComponent组件实例注册帧回调函数。|
|int32_t [OH_ArkUI_XComponent_UnregisterOnFrameCallback](#oh_arkui_xcomponent_unregisteronframecallback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|为此XComponent组件实例取消注册帧回调函数。|
|int32_t [OH_ArkUI_XComponent_SetNeedSoftKeyboard](#oh_arkui_xcomponent_setneedsoftkeyboard)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool needSoftKeyboard) | 为此XComponent组件实例设置是否需要软键盘。|
|[ArkUI_AccessibilityProvider](_o_h___native_x_component.md#oh_arkui_accessibilityprovider_create)* [OH_ArkUI_AccessibilityProvider_Create](#oh_arkui_accessibilityprovider_create)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 基于此XComponent组件实例创建ArkUI_AccessibilityProvider实例。|
|void [OH_ArkUI_AccessibilityProvider_Dispose](#oh_arkui_accessibilityprovider_dispose)([ArkUI_AccessibilityProvider](_o_h___native_x_component.md#oh_arkui_accessibilityprovider_create)* provider)|销毁由NDK接口[OH_ArkUI_AccessibilityProvider_Create](#oh_arkui_accessibilityprovider_create)创建的[ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider)实例。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent](#oh_arkui_surfacecallback_setsurfaceshowevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback,void (\*onSurfaceShow)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder))|为此OH_ArkUI_SurfaceCallback实例设置Surface显示回调。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent](#oh_arkui_surfacecallback_setsurfacehideevent)([OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)* callback,void (\*onSurfaceHide)([OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)* surfaceHolder))|为此OH_ArkUI_SurfaceCallback实例设置Surface隐藏回调。|

### 变量

| 名称                                       | 描述                             |
| ---------------------------------------- | ------------------------------ |
| [OH_XCOMPONENT_ID_LEN_MAX](#oh_xcomponent_id_len_max)&nbsp;=&nbsp;128 | ArkUI&nbsp;XComponent的id最大长度。  |
| [OH_MAX_TOUCH_POINTS_NUMBER](#oh_max_touch_points_number)&nbsp;=&nbsp;10 | 触摸事件中的可识别的触摸点个数最大值。            |
| [OH_NativeXComponent_TouchPoint::id](#id-12)&nbsp;=&nbsp;0 | 手指的唯一标识符。                      |
| [OH_NativeXComponent_TouchPoint::screenX](#screenx-13)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent所在应用窗口左上角的x坐标。 |
| [OH_NativeXComponent_TouchPoint::screenY](#screeny-13)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent所在应用窗口左上角的y坐标。 |
| [OH_NativeXComponent_TouchPoint::x](#x-13)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent组件左边缘的x坐标。     |
| [OH_NativeXComponent_TouchPoint::y](#y-13)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent组件上边缘的y坐标。     |
| [OH_NativeXComponent_TouchPoint::type](#type-12)&nbsp;=&nbsp;OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | 触摸事件的触摸类型。                     |
| [OH_NativeXComponent_TouchPoint::size](#size-12)&nbsp;=&nbsp;0.0 | 指垫和屏幕之间的接触面积。                  |
| [OH_NativeXComponent_TouchPoint::force](#force-12)&nbsp;=&nbsp;0.0 | 当前触摸事件的压力。                     |
| [OH_NativeXComponent_TouchPoint::timeStamp](#timestamp-12)&nbsp;=&nbsp;0 | 当前触摸事件的时间戳。                    |
| [OH_NativeXComponent_TouchPoint::isPressed](#ispressed)&nbsp;=&nbsp;false | 当前点是否被按下。                      |
| [OH_NativeXComponent_TouchEvent::id](#id-22)&nbsp;=&nbsp;0 | 手指的唯一标识符。                      |
| [OH_NativeXComponent_TouchEvent::screenX](#screenx-23)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent所在应用窗口左上角的x坐标。               |
| [OH_NativeXComponent_TouchEvent::screenY](#screeny-23)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent所在应用窗口左上角的y坐标。               |
| [OH_NativeXComponent_TouchEvent::x](#x-23)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent组件左边缘的x坐标。     |
| [OH_NativeXComponent_TouchEvent::y](#y-23)&nbsp;=&nbsp;0.0 | 触摸点相对于XComponent组件上边缘的y坐标。     |
| [OH_NativeXComponent_TouchEvent::type](#type-22)&nbsp;=&nbsp;OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | 触摸事件的触摸类型。                     |
| [OH_NativeXComponent_TouchEvent::size](#size-22)&nbsp;=&nbsp;0.0 | 指垫和屏幕之间的接触面积。                  |
| [OH_NativeXComponent_TouchEvent::force](#force-22)&nbsp;=&nbsp;0.0 | 当前触摸事件的压力。                     |
| [OH_NativeXComponent_TouchEvent::deviceId](#deviceid)&nbsp;=&nbsp;0 | 产生当前触摸事件的设备的ID。                |
| [OH_NativeXComponent_TouchEvent::timeStamp](#timestamp-22)&nbsp;=&nbsp;0 | 当前触摸事件的时间戳。                    |
| [OH_NativeXComponent_TouchEvent::touchPoints](#touchpoints)&nbsp;[OH_MAX_TOUCH_POINTS_NUMBER] | 当前触摸点的数组。                      |
| [OH_NativeXComponent_TouchEvent::numPoints](#numpoints)&nbsp;=&nbsp;0 | 当前接触点的数量。                      |
| [OH_NativeXComponent_MouseEvent::x](#x-33)&nbsp;=&nbsp;0.0 | 点击触点相对于当前组件左上角的x轴坐标。           |
| [OH_NativeXComponent_MouseEvent::y](#y-33)=&nbsp;0.0 | 点击触点相对于当前组件左上角的y轴坐标。           |
| [OH_NativeXComponent_MouseEvent::screenX](#screenx-33)=&nbsp;0.0 | 点击触点相对于屏幕左上角的x轴坐标。             |
| [OH_NativeXComponent_MouseEvent::screenY](#screeny-33)=&nbsp;0.0 | 点击触点相对于屏幕左上角的y轴坐标。             |
| [OH_NativeXComponent_MouseEvent::timestamp](#timestamp)=&nbsp;0 | 当前鼠标事件的时间戳。                    |
| [OH_NativeXComponent_MouseEvent::action](#action)=&nbsp;[OH_NativeXComponent_MouseEventAction::OH_NATIVEXCOMPONENT_MOUSE_NONE](#oh_nativexcomponent_mouseeventaction) | 当前鼠标事件动作。                      |
| [OH_NativeXComponent_MouseEvent::button](#button)=&nbsp;[OH_NativeXComponent_MouseEventButton::OH_NATIVEXCOMPONENT_NONE_BUTTON](#oh_nativexcomponent_mouseeventbutton) | 鼠标事件按键。                        |
| [OH_NativeXComponent_Callback::OnSurfaceCreated](#onsurfacecreated) | 创建surface时调用。                  |
| [OH_NativeXComponent_Callback::OnSurfaceChanged](#onsurfacechanged) | 当surface改变时调用。                 |
| [OH_NativeXComponent_Callback::OnSurfaceDestroyed](#onsurfacedestroyed) | 当surface被销毁时调用。                |
| [OH_NativeXComponent_Callback::DispatchTouchEvent](#dispatchtouchevent) | 当触摸事件被触发时调用。                   |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent](#dispatchmouseevent) | 当鼠标事件被触发时调用。                   |
| [OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent](#dispatchhoverevent) | 当悬停事件被触发时调用。                   |


## 类型定义说明


### OH_NativeXComponent

```
typedef struct OH_NativeXComponent OH_NativeXComponent
```

**描述:**

提供封装的OH_NativeXComponent实例。

**起始版本：**

8


### OH_NativeXComponent_Callback

```
typedef struct OH_NativeXComponent_Callback OH_NativeXComponent_Callback
```

**描述:**

注册surface生命周期和触摸事件回调。

**起始版本：**

8


### OH_NativeXComponent_KeyEvent

```
typedef struct OH_NativeXComponent_KeyEvent OH_NativeXComponent_KeyEvent
```

**描述:**

提供封装的OH_NativeXComponent_KeyEvent实例。

**起始版本：**

10


### OH_NativeXComponent_MouseEvent_Callback

```
typedef struct OH_NativeXComponent_MouseEvent_Callback OH_NativeXComponent_MouseEvent_Callback
```

**描述:**

注册鼠标事件的回调。

**起始版本：**

9


### OH_ArkUI_SurfaceCallback

```
typedef struct OH_ArkUI_SurfaceCallback OH_ArkUI_SurfaceCallback
```

**描述：**

定义surface生命周期回调函数。

> **说明：**
>
> 此类型的具体定义并不直接暴露。可调用[OH_ArkUI_SurfaceCallback_Create](#oh_arkui_surfacecallback_create)接口以创建此类型实例，可调用[OH_ArkUI_SurfaceCallback_Dispose](#oh_arkui_surfacecallback_dispose)接口以销毁此类型实例。

**起始版本：**

19


### OH_ArkUI_SurfaceHolder

```
typedef struct OH_ArkUI_SurfaceHolder OH_ArkUI_SurfaceHolder
```

**描述：**

提供封装的OH_ArkUI_SurfaceHolder实例。

> **说明：**
>
> 此类型的具体定义并不直接暴露。可调用[OH_ArkUI_SurfaceHolder_Create](#oh_arkui_surfaceholder_create)接口以创建此类型实例，可调用[OH_ArkUI_SurfaceHolder_Dispose](#oh_arkui_surfaceholder_dispose)接口以销毁此类型实例。

**起始版本：**

19


### OHNativeWindow

```
typedef struct NativeWindow OHNativeWindow
```

**描述：**

提供封装的NativeWindow实例。

> **说明：**
>
> 此类型的具体定义并不直接暴露。可调用[OH_ArkUI_XComponent_GetNativeWindow](#oh_arkui_xcomponent_getnativewindow)接口以获取此类型实例

**起始版本：**

19


### OH_NativeXComponent_ExtraMouseEventInfo

```
typedef struct OH_NativeXComponent_ExtraMouseEventInfo OH_NativeXComponent_ExtraMouseEventInfo
```

**描述：**

提供封装的扩展的鼠标事件信息实例。

> **说明：**
>
> 此类型的具体定义并不直接暴露。可调用[OH_NativeXComponent_GetMouseEventModifierKeyStates](#oh_nativexcomponent_getmouseeventmodifierkeystates)接口以获取该类型实例中的内容。

**起始版本：**

20


## 枚举类型说明


### anonymous enum

```
anonymous enum
```

**描述:**

枚举API访问状态。

| 枚举值                                      | 描述    |
| ---------------------------------------- | ----- |
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS       | 成功结果。 |
| OH_NATIVEXCOMPONENT_RESULT_FAILED        | 失败结果。 |
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER | 无效参数。 |

**起始版本：**

8


### OH_NativeXComponent_EventSourceType

```
enum OH_NativeXComponent_EventSourceType
```

**描述:**

触摸事件源类型。

| 枚举值                                      | 描述                                                   |
| ------------------------------------------- | ------------------------------------------------------ |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN     | 未知的输入源类型。                                     |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE       | 表示输入源生成鼠标多点触摸事件。                       |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN | 表示输入源生成一个触摸屏多点触摸事件。                 |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD    | 表示输入源生成一个触摸板多点触摸事件。                 |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK    | 表示输入源生成一个操纵杆多点触摸事件。                 |
| OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD<sup>10+</sup>    | 表示输入源生成一个键盘事件。            |

**起始版本：**

9


### OH_NativeXComponent_KeyAction

```
enum OH_NativeXComponent_KeyAction
```

**描述:**

按键事件动作。

| 枚举值                                    | 描述       |
| -------------------------------------- | -------- |
| OH_NATIVEXCOMPONENT_KEY_ACTION_UNKNOWN | 未知的按键动作。 |
| OH_NATIVEXCOMPONENT_KEY_ACTION_DOWN    | 按键按下动作。  |
| OH_NATIVEXCOMPONENT_KEY_ACTION_UP      | 按键抬起动作。  |

**起始版本：**

10


### OH_NativeXComponent_KeyCode

```
enum OH_NativeXComponent_KeyCode
```

**描述:**

按键事件的键码。

| 枚举值                          | 描述                          |
| ---------------------------- | --------------------------- |
| KEY_UNKNOWN                  | 未知按键                        |
| KEY_FN                       | 功能（Fn）键                     |
| KEY_HOME                     | 功能（Home）键                   |
| KEY_BACK                     | 返回键                         |
| KEY_MEDIA_PLAY_PAUSE         | 多媒体键&nbsp;播放/暂停             |
| KEY_MEDIA_STOP               | 多媒体键&nbsp;停止                |
| KEY_MEDIA_NEXT               | 多媒体键&nbsp;下一首               |
| KEY_MEDIA_PREVIOUS           | 多媒体键&nbsp;上一首               |
| KEY_MEDIA_REWIND             | 多媒体键&nbsp;快退                |
| KEY_MEDIA_FAST_FORWARD       | 多媒体键&nbsp;快进                |
| KEY_VOLUME_UP                | 音量增加键                       |
| KEY_VOLUME_DOWN              | 音量减小键                       |
| KEY_POWER                    | 电源键                         |
| KEY_CAMERA                   | 拍照键                         |
| KEY_VOLUME_MUTE              | 扬声器静音键                      |
| KEY_MUTE                     | 话筒静音键                       |
| KEY_BRIGHTNESS_UP            | 亮度调节按键&nbsp;调亮              |
| KEY_BRIGHTNESS_DOWN          | 亮度调节按键&nbsp;调暗              |
| KEY_0                        | 按键'0'                       |
| KEY_1                        | 按键'1'                       |
| KEY_2                        | 按键'2'                       |
| KEY_3                        | 按键'3'                       |
| KEY_4                        | 按键'4'                       |
| KEY_5                        | 按键'5'                       |
| KEY_6                        | 按键'6'                       |
| KEY_7                        | 按键'7'                       |
| KEY_8                        | 按键'8'                       |
| KEY_9                        | 按键'9'                       |
| KEY_STAR                     | 按键'\*'                      |
| KEY_POUND                    | 按键'\#'                      |
| KEY_DPAD_UP                  | 导航键&nbsp;向上                 |
| KEY_DPAD_DOWN                | 导航键&nbsp;向下                 |
| KEY_DPAD_LEFT                | 导航键&nbsp;向左                 |
| KEY_DPAD_RIGHT               | 导航键&nbsp;向右                 |
| KEY_DPAD_CENTER              | 导航键&nbsp;确定键                |
| KEY_A                        | 按键'A'                       |
| KEY_B                        | 按键'B'                       |
| KEY_C                        | 按键'C'                       |
| KEY_D                        | 按键'D'                       |
| KEY_E                        | 按键'E'                       |
| KEY_F                        | 按键'F'                       |
| KEY_G                        | 按键'G'                       |
| KEY_H                        | 按键'H'                       |
| KEY_I                        | 按键'I'                       |
| KEY_J                        | 按键'J'                       |
| KEY_K                        | 按键'K'                       |
| KEY_L                        | 按键'L'                       |
| KEY_M                        | 按键'M'                       |
| KEY_N                        | 按键'N'                       |
| KEY_O                        | 按键'O'                       |
| KEY_P                        | 按键'P'                       |
| KEY_Q                        | 按键'Q'                       |
| KEY_R                        | 按键'R'                       |
| KEY_S                        | 按键'S'                       |
| KEY_T                        | 按键'T'                       |
| KEY_U                        | 按键'U'                       |
| KEY_V                        | 按键'V'                       |
| KEY_W                        | 按键'W'                       |
| KEY_X                        | 按键'X'                       |
| KEY_Y                        | 按键'Y'                       |
| KEY_Z                        | 按键'Z'                       |
| KEY_COMMA                    | 按键','                       |
| KEY_PERIOD                   | 按键'.'                       |
| KEY_ALT_LEFT                 | 左Alt键                       |
| KEY_ALT_RIGHT                | 右Alt键                       |
| KEY_SHIFT_LEFT               | 左Shift键                     |
| KEY_SHIFT_RIGHT              | 右Shift键                     |
| KEY_TAB                      | Tab键                        |
| KEY_SPACE                    | 空格键                         |
| KEY_SYM                      | 符号修改器按键                     |
| KEY_EXPLORER                 | 浏览器功能键，此键用于启动浏览器应用程序。       |
| KEY_ENVELOPE                 | 电子邮件功能键，此键用于启动电子邮件应用程序。     |
| KEY_ENTER                    | 回车键                         |
| KEY_DEL                      | 退格键                         |
| KEY_GRAVE                    | 按键'‘’                       |
| KEY_MINUS                    | 按键'-'                       |
| KEY_EQUALS                   | 按键'='                       |
| KEY_LEFT_BRACKET             | 按键'['                       |
| KEY_RIGHT_BRACKET            | 按键']'                       |
| KEY_BACKSLASH                | 按键'\\'                       |
| KEY_SEMICOLON                | 按键';'                       |
| KEY_APOSTROPHE               | 按键'''&nbsp;(单引号)            |
| KEY_SLASH                    | 按键'/'                       |
| KEY_AT                       | 按键'\@'                      |
| KEY_PLUS                     | 按键'+'                       |
| KEY_MENU                     | 菜单键                         |
| KEY_PAGE_UP                  | 向上翻页键                       |
| KEY_PAGE_DOWN                | 向下翻页键                       |
| KEY_ESCAPE                   | ESC键                        |
| KEY_FORWARD_DEL              | 删除键                         |
| KEY_CTRL_LEFT                | 左Ctrl键                      |
| KEY_CTRL_RIGHT               | 右Ctrl键                      |
| KEY_CAPS_LOCK                | 大写锁定键                       |
| KEY_SCROLL_LOCK              | 滚动锁定键                       |
| KEY_META_LEFT                | 左元修改器键                      |
| KEY_META_RIGHT               | 右元修改器键                      |
| KEY_FUNCTION                 | 功能键                         |
| KEY_SYSRQ                    | 系统请求/打印屏幕键                  |
| KEY_BREAK                    | Break/Pause键                |
| KEY_MOVE_HOME                | 光标移动到开始键                    |
| KEY_MOVE_END                 | 光标移动到末尾键                    |
| KEY_INSERT                   | 插入键                         |
| KEY_FORWARD                  | 前进键                         |
| KEY_MEDIA_PLAY               | 多媒体键&nbsp;播放                |
| KEY_MEDIA_PAUSE              | 多媒体键&nbsp;暂停                |
| KEY_MEDIA_CLOSE              | 多媒体键&nbsp;关闭                |
| KEY_MEDIA_EJECT              | 多媒体键&nbsp;弹出                |
| KEY_MEDIA_RECORD             | 多媒体键&nbsp;录音                |
| KEY_F1                       | 按键'F1'                      |
| KEY_F2                       | 按键'F2'                      |
| KEY_F3                       | 按键'F3'                      |
| KEY_F4                       | 按键'F4'                      |
| KEY_F5                       | 按键'F5'                      |
| KEY_F6                       | 按键'F6'                      |
| KEY_F7                       | 按键'F7'                      |
| KEY_F8                       | 按键'F8'                      |
| KEY_F9                       | 按键'F9'                      |
| KEY_F10                      | 按键'F10'                     |
| KEY_F11                      | 按键'F11'                     |
| KEY_F12                      | 按键'F12'                     |
| KEY_NUM_LOCK                 | 小键盘锁                        |
| KEY_NUMPAD_0                 | 小键盘按键'0'                    |
| KEY_NUMPAD_1                 | 小键盘按键'1'                    |
| KEY_NUMPAD_2                 | 小键盘按键'2'                    |
| KEY_NUMPAD_3                 | 小键盘按键'3'                    |
| KEY_NUMPAD_4                 | 小键盘按键'4'                    |
| KEY_NUMPAD_5                 | 小键盘按键'5'                    |
| KEY_NUMPAD_6                 | 小键盘按键'6'                    |
| KEY_NUMPAD_7                 | 小键盘按键'7'                    |
| KEY_NUMPAD_8                 | 小键盘按键'8'                    |
| KEY_NUMPAD_9                 | 小键盘按键'9'                    |
| KEY_NUMPAD_DIVIDE            | 小键盘按键'/'                    |
| KEY_NUMPAD_MULTIPLY          | 小键盘按键'\*'                   |
| KEY_NUMPAD_SUBTRACT          | 小键盘按键'-'                    |
| KEY_NUMPAD_ADD               | 小键盘按键'+'                    |
| KEY_NUMPAD_DOT               | 小键盘按键'.'                    |
| KEY_NUMPAD_COMMA             | 小键盘按键','                    |
| KEY_NUMPAD_ENTER             | 小键盘按键回车                     |
| KEY_NUMPAD_EQUALS            | 小键盘按键'='                    |
| KEY_NUMPAD_LEFT_PAREN        | 小键盘按键'('                    |
| KEY_NUMPAD_RIGHT_PAREN       | 小键盘按键')'                    |
| KEY_VIRTUAL_MULTITASK        | 虚拟多任务键                      |
| KEY_SLEEP                    | 睡眠键                         |
| KEY_ZENKAKU_HANKAKU          | 日文全宽/半宽键                    |
| KEY_102ND                    | 102nd按键                     |
| KEY_RO                       | 日文Ro键                       |
| KEY_KATAKANA                 | 日文片假名键                      |
| KEY_HIRAGANA                 | 日文平假名键                      |
| KEY_HENKAN                   | 日文转换键                       |
| KEY_KATAKANA_HIRAGANA        | 日语片假名/平假名键                  |
| KEY_MUHENKAN                 | 日文非转换键                      |
| KEY_LINEFEED                 | 换行键                         |
| KEY_MACRO                    | 宏键                          |
| KEY_NUMPAD_PLUSMINUS         | 数字键盘上的加号/减号键                |
| KEY_SCALE                    | 扩展键                         |
| KEY_HANGUEL                  | 日文韩语键                       |
| KEY_HANJA                    | 日文汉语键                       |
| KEY_YEN                      | 日元键                         |
| KEY_STOP                     | 停止键                         |
| KEY_AGAIN                    | 重复键                         |
| KEY_PROPS                    | 道具键                         |
| KEY_UNDO                     | 撤消键                         |
| KEY_COPY                     | 复制键                         |
| KEY_OPEN                     | 打开键                         |
| KEY_PASTE                    | 粘贴键                         |
| KEY_FIND                     | 查找键                         |
| KEY_CUT                      | 剪切键                         |
| KEY_HELP                     | 帮助键                         |
| KEY_CALC                     | 计算器特殊功能键，用于启动计算器应用程序        |
| KEY_FILE                     | 文件按键                        |
| KEY_BOOKMARKS                | 书签键                         |
| KEY_NEXT                     | 下一个按键                       |
| KEY_PLAYPAUSE                | 播放/暂停键                      |
| KEY_PREVIOUS                 | 上一个按键                       |
| KEY_STOPCD                   | CD停止键                       |
| KEY_CONFIG                   | 配置键                         |
| KEY_REFRESH                  | 刷新键                         |
| KEY_EXIT                     | 退出键                         |
| KEY_EDIT                     | 编辑键                         |
| KEY_SCROLLUP                 | 向上滚动键                       |
| KEY_SCROLLDOWN               | 向下滚动键                       |
| KEY_NEW                      | 新建键                         |
| KEY_REDO                     | 恢复键                         |
| KEY_CLOSE                    | 关闭键                         |
| KEY_PLAY                     | 播放键                         |
| KEY_BASSBOOST                | 低音增强键                       |
| KEY_PRINT                    | 打印键                         |
| KEY_CHAT                     | 聊天键                         |
| KEY_FINANCE                  | 金融键                         |
| KEY_CANCEL                   | 取消键                         |
| KEY_KBDILLUM_TOGGLE          | 键盘灯光切换键                     |
| KEY_KBDILLUM_DOWN            | 键盘灯光调亮键                     |
| KEY_KBDILLUM_UP              | 键盘灯光调暗键                     |
| KEY_SEND                     | 发送键                         |
| KEY_REPLY                    | 答复键                         |
| KEY_FORWARDMAIL              | 邮件转发键                       |
| KEY_SAVE                     | 保存键                         |
| KEY_DOCUMENTS                | 文件键                         |
| KEY_VIDEO_NEXT               | 下一个视频键                      |
| KEY_VIDEO_PREV               | 上一个视频键                      |
| KEY_BRIGHTNESS_CYCLE         | 背光渐变键                       |
| KEY_BRIGHTNESS_ZERO          | 亮度调节为0键                     |
| KEY_DISPLAY_OFF              | 显示关闭键                       |
| KEY_BTN_MISC                 | 游戏手柄上的各种按键                  |
| KEY_GOTO                     | 进入键                         |
| KEY_INFO                     | 信息查看键                       |
| KEY_PROGRAM                  | 程序键                         |
| KEY_PVR                      | 个人录像机(PVR)键                 |
| KEY_SUBTITLE                 | 字幕键                         |
| KEY_FULL_SCREEN              | 全屏键                         |
| KEY_KEYBOARD                 | 键盘                          |
| KEY_ASPECT_RATIO             | 屏幕纵横比调节键                    |
| KEY_PC                       | 端口控制键                       |
| KEY_TV                       | TV键                         |
| KEY_TV2                      | TV键2                        |
| KEY_VCR                      | 录像机开启键                      |
| KEY_VCR2                     | 录像机开启键2                     |
| KEY_SAT                      | SIM卡应用工具包（SAT）键             |
| KEY_CD                       | CD键                         |
| KEY_TAPE                     | 磁带键                         |
| KEY_TUNER                    | 调谐器键                        |
| KEY_PLAYER                   | 播放器键                        |
| KEY_DVD                      | DVD键                        |
| KEY_AUDIO                    | 音频键                         |
| KEY_VIDEO                    | 视频键                         |
| KEY_MEMO                     | 备忘录键                        |
| KEY_CALENDAR                 | 日历键                         |
| KEY_RED                      | 红色指示器                       |
| KEY_GREEN                    | 绿色指示器                       |
| KEY_YELLOW                   | 黄色指示器                       |
| KEY_BLUE                     | 蓝色指示器                       |
| KEY_CHANNELUP                | 频道向上键                       |
| KEY_CHANNELDOWN              | 频道向下键                       |
| KEY_LAST                     | 末尾键                         |
| KEY_RESTART                  | 重启键                         |
| KEY_SLOW                     | 慢速键                         |
| KEY_SHUFFLE                  | 随机播放键                       |
| KEY_VIDEOPHONE               | 可视电话键                       |
| KEY_GAMES                    | 游戏键                         |
| KEY_ZOOMIN                   | 放大键                         |
| KEY_ZOOMOUT                  | 缩小键                         |
| KEY_ZOOMRESET                | 缩放重置键                       |
| KEY_WORDPROCESSOR            | 文字处理键                       |
| KEY_EDITOR                   | 编辑器键                        |
| KEY_SPREADSHEET              | 电子表格键                       |
| KEY_GRAPHICSEDITOR           | 图形编辑器键                      |
| KEY_PRESENTATION             | 演示文稿键                       |
| KEY_DATABASE                 | 数据库键标                       |
| KEY_NEWS                     | 新闻键                         |
| KEY_VOICEMAIL                | 语音信箱                        |
| KEY_ADDRESSBOOK              | 通讯簿                         |
| KEY_MESSENGER                | 通信键                         |
| KEY_BRIGHTNESS_TOGGLE        | 亮度切换键                       |
| KEY_SPELLCHECK               | AL拼写检查                      |
| KEY_COFFEE                   | 终端锁/屏幕保护程序                  |
| KEY_MEDIA_REPEAT             | 媒体循环键                       |
| KEY_IMAGES                   | 图像键                         |
| KEY_BUTTONCONFIG             | 按键配置键                       |
| KEY_TASKMANAGER              | 任务管理器                       |
| KEY_JOURNAL                  | 日志按键                        |
| KEY_CONTROLPANEL             | 控制面板键                       |
| KEY_APPSELECT                | 应用程序选择键                     |
| KEY_SCREENSAVER              | 屏幕保护程序键                     |
| KEY_ASSISTANT                | 辅助键                         |
| KEY_KBD_LAYOUT_NEXT          | 下一个键盘布局键                    |
| KEY_BRIGHTNESS_MIN           | 最小亮度键                       |
| KEY_BRIGHTNESS_MAX           | 最大亮度键                       |
| KEY_KBDINPUTASSIST_PREV      | 键盘输入Assist_Previous         |
| KEY_KBDINPUTASSIST_NEXT      | 键盘输入Assist_Next             |
| KEY_KBDINPUTASSIST_PREVGROUP | 键盘输入Assist_Previous         |
| KEY_KBDINPUTASSIST_NEXTGROUP | 键盘输入Assist_Next             |
| KEY_KBDINPUTASSIST_ACCEPT    | 键盘输入Assist_Accept           |
| KEY_KBDINPUTASSIST_CANCEL    | 键盘输入Assist_Cancel           |
| KEY_FRONT                    | 挡风玻璃除雾器开关                   |
| KEY_SETUP                    | 设置键                         |
| KEY_WAKEUP                   | 唤醒键                         |
| KEY_SENDFILE                 | 发送文件按键                      |
| KEY_DELETEFILE               | 删除文件按键                      |
| KEY_XFER                     | 文件传输(XFER)按键                |
| KEY_PROG1                    | 程序键1                        |
| KEY_PROG2                    | 程序键2                        |
| KEY_MSDOS                    | MS-DOS键（微软磁盘操作系统            |
| KEY_SCREENLOCK               | 屏幕锁定键                       |
| KEY_DIRECTION_ROTATE_DISPLAY | 方向旋转显示键                     |
| KEY_CYCLEWINDOWS             | Windows循环键                  |
| KEY_COMPUTER                 | 按键                          |
| KEY_EJECTCLOSECD             | 弹出CD键                       |
| KEY_ISO                      | ISO键                        |
| KEY_MOVE                     | 移动键                         |
| KEY_F13                      | 按键'F13'                     |
| KEY_F14                      | 按键'F14'                     |
| KEY_F15                      | 按键'F15'                     |
| KEY_F16                      | 按键'F16'                     |
| KEY_F17                      | 按键'F17'                     |
| KEY_F18                      | 按键'F18'                     |
| KEY_F19                      | 按键'F19'                     |
| KEY_F20                      | 按键'F20'                     |
| KEY_F21                      | 按键'F21'                     |
| KEY_F22                      | 按键'F22'                     |
| KEY_F23                      | 按键'F23'                     |
| KEY_F24                      | 按键'F24'                     |
| KEY_PROG3                    | 程序键3                        |
| KEY_PROG4                    | 程序键4                        |
| KEY_DASHBOARD                | 仪表板                         |
| KEY_SUSPEND                  | 挂起键                         |
| KEY_HP                       | 高阶路径键                       |
| KEY_SOUND                    | 音量键                         |
| KEY_QUESTION                 | 疑问按键                        |
| KEY_CONNECT                  | 连接键                         |
| KEY_SPORT                    | 运动按键                        |
| KEY_SHOP                     | 商城键                         |
| KEY_ALTERASE                 | 交替键                         |
| KEY_SWITCHVIDEOMODE          | 在可用视频之间循环输出（监视器/LCD/TV输出/等） |
| KEY_BATTERY                  | 电池按键                        |
| KEY_BLUETOOTH                | 蓝牙按键                        |
| KEY_WLAN                     | 无线局域网                       |
| KEY_UWB                      | 超宽带（UWB）                    |
| KEY_WWAN_WIMAX               | WWAN&nbsp;WiMAX按键           |
| KEY_RFKILL                   | 控制所有收音机的键                   |
| KEY_CHANNEL                  | 向上频道键                       |
| KEY_BTN_0                    | 按键0                         |
| KEY_BTN_1                    | 按键1                         |
| KEY_BTN_2                    | 按键2                         |
| KEY_BTN_3                    | 按键3                         |
| KEY_BTN_4                    | 按键4                         |
| KEY_BTN_5                    | 按键5                         |
| KEY_BTN_6                    | 按键6                         |
| KEY_BTN_7                    | 按键7                         |
| KEY_BTN_8                    | 按键8                         |
| KEY_BTN_9                    | 按键9                         |

**起始版本：**

10


### OH_NativeXComponent_MouseEventAction

```
enum OH_NativeXComponent_MouseEventAction
```

**描述:**

鼠标事件动作。

| 枚举值                               | 描述               |
| --------------------------------- | ---------------- |
| OH_NATIVEXCOMPONENT_MOUSE_NONE    | 无效鼠标事件&nbsp;。    |
| OH_NATIVEXCOMPONENT_MOUSE_PRESS   | 鼠标按键按下时触发鼠标事件。   |
| OH_NATIVEXCOMPONENT_MOUSE_RELEASE | 鼠标按键松开时触发鼠标事件。   |
| OH_NATIVEXCOMPONENT_MOUSE_MOVE    | 鼠标在屏幕上移动时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_MOUSE_CANCEL    | 鼠标按键被取消时触发鼠标事件。<br/>**起始版本：** 18 |

**起始版本：**

9


### OH_NativeXComponent_MouseEventButton

```
enum OH_NativeXComponent_MouseEventButton
```

**描述:**

鼠标事件按键。

| 枚举值                                | 描述                |
| ---------------------------------- | ----------------- |
| OH_NATIVEXCOMPONENT_NONE_BUTTON    | 鼠标无按键操作时触发鼠标事件。   |
| OH_NATIVEXCOMPONENT_LEFT_BUTTON    | 按下鼠标左键时触发鼠标事件。    |
| OH_NATIVEXCOMPONENT_RIGHT_BUTTON   | 按下鼠标右键时触发鼠标事件。    |
| OH_NATIVEXCOMPONENT_MIDDLE_BUTTON  | 按下鼠标中键时触发鼠标事件。    |
| OH_NATIVEXCOMPONENT_BACK_BUTTON    | 按下鼠标左侧后退键时触发鼠标事件。 |
| OH_NATIVEXCOMPONENT_FORWARD_BUTTON | 按下鼠标左侧前进键时触发鼠标事件。 |

**起始版本：**

9


### OH_NativeXComponent_TouchEventType

```
enum OH_NativeXComponent_TouchEventType
```

**描述:**

触摸事件类型。

| 枚举值                         | 描述                    |
| --------------------------- | --------------------- |
| OH_NATIVEXCOMPONENT_DOWN    | 手指按下时触发触摸事件。          |
| OH_NATIVEXCOMPONENT_UP      | 手指抬起时触发触摸事件。          |
| OH_NATIVEXCOMPONENT_MOVE    | 手指按下状态下在屏幕上移动时触发触摸事件。 |
| OH_NATIVEXCOMPONENT_CANCEL  | 触摸事件取消时触发事件。          |
| OH_NATIVEXCOMPONENT_UNKNOWN | 无效的触摸类型。              |

**起始版本：**

8


### OH_NativeXComponent_TouchPointToolType

```
enum OH_NativeXComponent_TouchPointToolType
```

**描述:**

触摸点工具类型

| 枚举值                                    | 描述       |
| -------------------------------------- | -------- |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN  | 未识别工具类型。 |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER   | 表示用手指。   |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN      | 表示用触笔。   |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER   | 表示用橡皮擦。  |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH    | 表示用画笔。   |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL   | 表示用铅笔。   |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH | 表示用气笔。   |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE    | 表示用鼠标。   |
| OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS     | 表示用晶状体。  |

**起始版本：**

9

### ArkUI_XComponent_ImageAnalyzerState

```
enum ArkUI_XComponent_ImageAnalyzerState
```

**描述**

XComponent图像AI分析状态码。

| 枚举值                                    | 描述     |
| --------------------------------------   | -------- |
| ARKUI_XCOMPONENT_AI_ANALYSIS_FINISHED    | 图像AI分析完成。|
| ARKUI_XCOMPONENT_AI_ANALYSIS_DISABLED    | 图像AI分析已禁用。|
| ARKUI_XCOMPONENT_AI_ANALYSIS_UNSUPPORTED | 设备不支持图像AI分析。|
| ARKUI_XCOMPONENT_AI_ANALYSIS_ONGOING     | 图像AI分析进行中。|
| ARKUI_XCOMPONENT_AI_ANALYSIS_STOPPED     | 图像AI分析停止。|

**起始版本：**

18

## 函数说明

### OH_NativeXComponent_AttachNativeRootNode()

```
int32_t OH_NativeXComponent_AttachNativeRootNode (OH_NativeXComponent * component, ArkUI_NodeHandle root )
```
**描述：**

将通过ArkUI的native接口创建出来的UI组件挂载到当前XComponent上。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。  |
| root | 指向Native接口创建的组件实例的指针。  |

**返回：**

0：成功。 

-2：参数异常。


### OH_NativeXComponent_DetachNativeRootNode()

```
int32_t OH_NativeXComponent_DetachNativeRootNode (OH_NativeXComponent * component, ArkUI_NodeHandle root )
```
**描述：**

将ArkUI的native组件从当前XComponent上卸载.

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。  |
| root | 指向Native接口创建的组件实例的指针。  |

**返回：**

0：成功。 

-2：参数异常。



### OH_NativeXComponent_GetKeyEvent()

```
int32_t OH_NativeXComponent_GetKeyEvent (OH_NativeXComponent * component, OH_NativeXComponent_KeyEvent ** keyEvent )
```

**描述:**

获取ArkUI XComponent调度的按键事件。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| keyEvent  | 表示指向当前按键事件指针的指针。              |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventAction()

```
int32_t OH_NativeXComponent_GetKeyEventAction (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_KeyAction * action )
```

**描述:**

获取传入按键事件的动作。

**参数:**

| 名称       | 描述                                     |
| -------- | -------------------------------------- |
| keyEvent | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| action   | 表示指向按键事件动作的指针。                         |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventCode()

```
int32_t OH_NativeXComponent_GetKeyEventCode (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_KeyCode * code )
```

**描述:**

获取传入按键事件的按键码。

**参数:**

| 名称       | 描述                                     |
| -------- | -------------------------------------- |
| keyEvent | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| code     | 表示指向按键事件按键码的指针。                        |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventDeviceId()

```
int32_t OH_NativeXComponent_GetKeyEventDeviceId (OH_NativeXComponent_KeyEvent * keyEvent, int64_t * deviceId )
```

**描述:**

获取传入按键事件的设备id。

**参数:**

| 名称       | 描述                                     |
| -------- | -------------------------------------- |
| keyEvent | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| deviceId | 表示指向按键事件设备id的指针。                       |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventSourceType()

```
int32_t OH_NativeXComponent_GetKeyEventSourceType (OH_NativeXComponent_KeyEvent * keyEvent, OH_NativeXComponent_EventSourceType * sourceType )
```

**描述:**

获取传入按键事件的事件源类型。

**参数:**

| 名称         | 描述                                     |
| ---------- | -------------------------------------- |
| keyEvent   | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| sourceType | 表示指向按键事件事件源类型的指针。                      |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetKeyEventTimestamp()

```
int32_t OH_NativeXComponent_GetKeyEventTimestamp (OH_NativeXComponent_KeyEvent * keyEvent, int64_t * timeStamp )
```

**描述:**

获取传入按键事件的时间戳。

**参数:**

| 名称        | 描述                                     |
| --------- | -------------------------------------- |
| keyEvent  | 表示指向OH_NativeXComponent_KeyEvent实例的指针。 |
| timeStamp | 表示指向按键事件时间戳的指针。                        |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_GetMouseEvent()

```
int32_t OH_NativeXComponent_GetMouseEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_MouseEvent * mouseEvent )
```

**描述:**

获取ArkUI XComponent调度的鼠标事件

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。 |
| window     | 表示NativeWindow句柄              |
| mouseEvent | 指示指向当前鼠标事件的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

9

### OH_NativeXComponent_GetNativeXComponent()

```
OH_NativeXComponent* OH_NativeXComponent_GetNativeXComponent (ArkUI_NodeHandle node)
```
**描述：**

基于Native接口创建的组件实例获取OH_NativeXComponent类型的指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 指向Native接口创建的组件实例的指针。  |

**返回：**

表示指向OH_NativeXComponent实例的指针。


### OH_NativeXComponent_GetTouchEvent()

```
int32_t OH_NativeXComponent_GetTouchEvent (OH_NativeXComponent * component, const void * window, OH_NativeXComponent_TouchEvent * touchEvent )
```

**描述:**

获取ArkUI XComponent调度的触摸事件。

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。 |
| window     | 表示NativeWindow句柄。             |
| touchEvent | 指示指向当前触摸事件的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_GetTouchPointTiltX()

```
int32_t OH_NativeXComponent_GetTouchPointTiltX (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltX )
```

**描述:**

获取ArkUI XComponent触摸点倾斜与X轴角度。

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。 |
| pointIndex | 表示触摸点的指针索引。                   |
| tiltX      | 表示指向X倾斜度的指针。                  |

**返回:**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetTouchPointTiltY()

```
int32_t OH_NativeXComponent_GetTouchPointTiltY (OH_NativeXComponent * component, uint32_t pointIndex, float * tiltY )
```

**描述:**

获取ArkUI XComponent触摸点倾斜与Y轴角度。

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。 |
| pointIndex | 表示触摸点的指针索引。                   |
| tiltY      | 表示指向Y倾斜度的指针。                  |

**返回:**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetTouchPointWindowX()

```
int32_t OH_NativeXComponent_GetTouchPointWindowX(OH_NativeXComponent * component, uint32_t pointIndex, float * windowX )
```

**描述:**

获取ArkUI XComponent触摸点相对于应用窗口左上角的X坐标。

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。        |
| pointIndex | 表示触摸点的指针索引。                          |
| windowX    | 表示指向触摸点相对于应用窗口左上角的X坐标的指针。  |

**返回:**

返回执行的状态代码。

**起始版本：**

12


### OH_NativeXComponent_GetTouchPointWindowY()

```
int32_t OH_NativeXComponent_GetTouchPointWindowY(OH_NativeXComponent * component, uint32_t pointIndex, float * windowY )
```

**描述:**

获取ArkUI XComponent触摸点相对于应用窗口左上角的Y坐标。

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。        |
| pointIndex | 表示触摸点的指针索引。                          |
| windowY    | 表示指向触摸点相对于应用窗口左上角的Y坐标的指针。  |

**返回:**

返回执行的状态代码。

**起始版本：**

12


### OH_NativeXComponent_GetTouchPointDisplayX()

```
int32_t OH_NativeXComponent_GetTouchPointDisplayX(OH_NativeXComponent * component, uint32_t pointIndex, float * displayX )
```

**描述:**

获取ArkUI XComponent触摸点相对于应用所在屏幕左上角的X坐标。

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。        |
| pointIndex | 表示触摸点的指针索引。                          |
| displayX    | 表示指向触摸点相对于应用所在屏幕左上角的X坐标的指针。  |

**返回:**

返回执行的状态代码。

**起始版本：**

12


### OH_NativeXComponent_GetTouchPointDisplayY()

```
int32_t OH_NativeXComponent_GetTouchPointDisplayY(OH_NativeXComponent * component, uint32_t pointIndex, float * displayY )
```

**描述:**

获取ArkUI XComponent触摸点相对于应用所在屏幕左上角的Y坐标。

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。        |
| pointIndex | 表示触摸点的指针索引。                          |
| displayY    | 表示指向触摸点相对于应用所在屏幕左上角的Y坐标的指针。  |

**返回:**

返回执行的状态代码。

**起始版本：**

12


### OH_NativeXComponent_GetTouchPointToolType()

```
int32_t OH_NativeXComponent_GetTouchPointToolType (OH_NativeXComponent * component, uint32_t pointIndex, OH_NativeXComponent_TouchPointToolType * toolType )
```

**描述:**

获取ArkUI XComponent触摸点工具类型。

**参数:**

| 名称         | 描述                            |
| ---------- | ----------------------------- |
| component  | 表示指向OH_NativeXComponent实例的指针。 |
| pointIndex | 表示触摸点的指针索引。                   |
| toolType   | 表示指向工具类型的指针。                  |

**返回:**

返回执行的状态代码。

**起始版本：**

9


### OH_NativeXComponent_GetXComponentId()

```
int32_t OH_NativeXComponent_GetXComponentId (OH_NativeXComponent * component, char * id, uint64_t * size )
```

**描述:**

获取ArkUI XComponent的id。

**参数:**

| 名称      | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| component | 表示指向OH_NativeXComponent实例的指针。                      |
| id        | 指示用于保存此OH_NativeXComponent实例的ID的字符缓冲区。&nbsp;请注意，空终止符将附加到字符缓冲区，因此字符缓冲区的大小应至少比真实id长度大一个单位。&nbsp;建议字符缓冲区的大小为[OH_XCOMPONENT_ID_LEN_MAX&nbsp;+&nbsp;1]。 |
| size      | 指示指向id长度的指针，用于接收id的长度信息。                 |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_GetXComponentOffset()

```
int32_t OH_NativeXComponent_GetXComponentOffset (OH_NativeXComponent * component, const void * window, double * x, double * y )
```

**描述:**

获取ArkUI XComponent持有的surface相对其父组件左顶点的偏移量。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window    | 表示NativeWindow句柄。             |
| x         | 指示指向当前surface相对于XComponent父组件左顶点x坐标的指针。         |
| y         | 指示指向当前surface相对于XComponent父组件左顶点y坐标的指针。         |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_GetXComponentSize()

```
int32_t OH_NativeXComponent_GetXComponentSize (OH_NativeXComponent * component, const void * window, uint64_t * width, uint64_t * height )
```

**描述:**

获取ArkUI XComponent持有的surface的大小。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window    | 表示NativeWindow句柄。             |
| width     | 指示指向当前surface宽度的指针。           |
| height    | 指示指向当前surface高度的指针。           |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_RegisterBlurEventCallback()

```
int32_t OH_NativeXComponent_RegisterBlurEventCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**描述:**

为此OH_NativeXComponent实例注册失焦事件回调。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向失焦事件回调的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_RegisterCallback()

```
int32_t OH_NativeXComponent_RegisterCallback (OH_NativeXComponent * component, OH_NativeXComponent_Callback * callback )
```

**描述:**

为此OH_NativeXComponent实例注册回调。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向surface生命周期和触摸事件回调的指针。    |

**返回:**

返回执行的状态代码。

**起始版本：**

8


### OH_NativeXComponent_RegisterFocusEventCallback()

```
int32_t OH_NativeXComponent_RegisterFocusEventCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**描述:**

为此OH_NativeXComponent实例注册获焦事件回调。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向获焦事件回调的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_RegisterKeyEventCallback()

```
int32_t OH_NativeXComponent_RegisterKeyEventCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**描述:**

为此OH_NativeXComponent实例注册按键事件回调。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向按键事件回调的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

10


### OH_NativeXComponent_RegisterKeyEventCallbackWithResult()

```
int32_t OH_NativeXComponent_RegisterKeyEventCallbackWithResult (OH_NativeXComponent * component, bool(*callback)(OH_NativeXComponent *component, void *window))
```

**描述:**

为此OH_NativeXComponent实例注册带有返回值的按键事件回调。通过此接口注册的按键事件回调都必须返回一个结果，即true或false。当返回值为true时，该事件将不会继续分发；当返回值为false时，该事件将按照事件处理流程继续分发。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向按键事件回调的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

14


### OH_NativeXComponent_RegisterMouseEventCallback()

```
int32_t OH_NativeXComponent_RegisterMouseEventCallback (OH_NativeXComponent * component, OH_NativeXComponent_MouseEvent_Callback * callback )
```

**描述:**

为此OH_NativeXComponent实例注册鼠标事件回调。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向鼠标事件回调的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

9

### OH_NativeXComponent_RegisterOnFrameCallback()

```
int32_t OH_NativeXComponent_RegisterOnFrameCallback (OH_NativeXComponent* component, void (*callback)(OH_NativeXComponent *component, uint64_t timestamp, uint64_t targetTimestamp))
```
**描述：**

为此OH_NativeXComponent实例注册显示更新回调，并使能每帧回调此函数。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。  |
| callback | 指示指向显示更新回调的指针。  |
| timestamp | 当前帧到达的时间（单位：纳秒）。 |
| targetTimestamp | 下一帧预期到达的时间（单位：纳秒）。 |

**返回：**

返回执行的状态代码。

**起始版本：** 

11

### OH_NativeXComponent_RegisterOnTouchInterceptCallback()

```
int32_t OH_NativeXComponent_RegisterOnTouchInterceptCallback (OH_NativeXComponent * component, HitTestMode(*callback)(OH_NativeXComponent *component, ArkUI_UIInputEvent *event))
```
**描述：**

为此OH_NativeXComponent实例注册自定义事件拦截回调，并使能在做触摸测试时回调此函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。  |
| callback | 指示指向自定义事件拦截回调的指针。  |

**返回：**

0 - 成功。 401 - 参数异常。

### OH_NativeXComponent_RegisterUIInputEventCallback()

```
int32_t OH_NativeXComponent_RegisterUIInputEventCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, ArkUI_UIInputEvent *event, ArkUI_UIInputEvent_Type type), ArkUI_UIInputEvent_Type type )
```
**描述：**

为此OH_NativeXComponent实例注册UI输入事件回调，并使能收到UI输入事件时回调此函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。  |
| callback | 指示指向UI输入事件回调的指针。  |
| type | 指示当前UI输入事件的类型。  |

**返回：**

返回执行的状态代码。

### OH_NativeXComponent_SetExpectedFrameRateRange()

```
int32_t OH_NativeXComponent_SetExpectedFrameRateRange (OH_NativeXComponent * component, OH_NativeXComponent_ExpectedRateRange * range )
```
**描述：**

设置期望帧率范围。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。  |
| range | 表示指向期望帧率范围的指针。 |

**返回：**

返回执行的状态代码。

**起始版本：** 

11


### OH_NativeXComponent_UnregisterOnFrameCallback()

```
int32_t OH_NativeXComponent_UnregisterOnFrameCallback (OH_NativeXComponent * component)
```
**描述：**

为此OH_NativeXComponent实例取消注册回调函数，并关闭每帧回调此函数。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向OH_NativeXComponent实例的指针。  |

**返回：**

返回执行的状态代码。

**起始版本：** 

11

### OH_NativeXComponent_SetNeedSoftKeyboard()

```
int32_t OH_NativeXComponent_SetNeedSoftKeyboard(OH_NativeXComponent* component, bool isNeedSoftKeyboard)
```

**描述：**

为此OH_NativeXComponent实例设置是否需要软键盘。

**参数:**

| 名称               | 描述                                          |
| ------------------ | --------------------------------------------- |
| component          | 表示指向OH_NativeXComponent实例的指针。       |
| isNeedSoftKeyboard | 表示此OH_NativeXComponent实例是否需要软键盘。 |

**返回：**

返回执行的状态代码。

**起始版本：** 

12

### OH_NativeXComponent_RegisterSurfaceShowCallback()

```
int32_t OH_NativeXComponent_RegisterSurfaceShowCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**描述:**

为此OH_NativeXComponent实例注册surface显示回调，该回调在应用从后台返回前台后触发。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向surface显示回调的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

12

### OH_NativeXComponent_RegisterSurfaceHideCallback()

```
int32_t OH_NativeXComponent_RegisterSurfaceHideCallback (OH_NativeXComponent * component, void(*callback)(OH_NativeXComponent *component, void *window))
```

**描述:**

为此OH_NativeXComponent实例注册surface隐藏回调，该回调在应用从前台来到后台后触发。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| callback  | 指示指向surface隐藏回调的指针。                |

**返回:**

返回执行的状态代码。

**起始版本：**

12

### OH_NativeXComponent_GetTouchEventSourceType()

```
int32_t OH_NativeXComponent_GetTouchEventSourceType (OH_NativeXComponent* component, int32_t pointId, OH_NativeXComponent_EventSourceType* sourceType)
```

**描述:**

获取ArkUI XComponent触摸事件的输入设备类型。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| pointId  | 表示触摸点的id。<br/>**说明：**<br/>仅当传入的id为触发该touch事件的触点id时，可正确返回输入设备类型，否则返回OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER。 |
| sourceType  | 指示指向返回设备类型的指针。 |

**返回:**

OH_NATIVEXCOMPONENT_RESULT_SUCCESS - 成功。

OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER - 参数异常。

OH_NATIVEXCOMPONENT_RESULT_FAILED - 其他错误。

**起始版本：**

12

### OH_NativeXComponent_GetNativeAccessibilityProvider()

```
int32_t OH_NativeXComponent_GetNativeAccessibilityProvider(
    OH_NativeXComponent* component, ArkUI_AccessibilityProvider** handle)
```

**描述:**

获取ArkUI XComponent无障碍接入句柄指针。

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| handle    | 返回无障碍接入句柄指针。                |

**返回:**

OH_NATIVEXCOMPONENT_RESULT_SUCCESS - 成功。

OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER - 参数异常。

OH_NATIVEXCOMPONENT_RESULT_FAILED - 其他错误。

**起始版本：**

13

### OH_ArkUI_XComponent_StartImageAnalyzer()

```
int32_t OH_ArkUI_XComponent_StartImageAnalyzer(ArkUI_NodeHandle node, void* userData,
    void (*callback)(ArkUI_NodeHandle node, ArkUI_XComponent_ImageAnalyzerState statusCode, void* userData))
```

**描述：**

为此XComponent组件实例开始图像AI分析，使用前需先使能图像AI分析能力。

**起始版本：**

18

**参数：**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| node | 表示XComponent组件实例。 |
| userData    | 表示开发者需要在回调函数执行时获取的数据的指针。                |
|callback| 表示图像AI分析状态刷新时触发的回调函数。|
|statusCode|回调函数的入参之一，表示当前的图像分析状态。|

> **说明：**
>
> 该接口发起的图像AI分析过程为异步执行，接口返回后，并不代表图像AI分析已经产生分析内容。
> 
> 该方法调用时，将截取调用时刻的画面帧进行分析，使用时需注意启动分析的时机，以避免出现画面和分析内容不一致的情况。
>
> 图像AI分析状态刷新时，将会触发传入的回调函数。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_XComponent_StopImageAnalyzer()

```
int32_t OH_ArkUI_XComponent_StopImageAnalyzer(ArkUI_NodeHandle node)
```

**描述：**

为此XComponent组件实例停止图像AI分析。

**起始版本：**

18

**参数：**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| node | 表示XComponent组件实例。 |

> **说明：**
>
> 停止图像AI分析功能后，图像AI分析展示的内容将被销毁。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_SurfaceCallback_Create()

```
OH_ArkUI_SurfaceCallback* OH_ArkUI_SurfaceCallback_Create()
```

**描述：**

创建[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)对象。

**起始版本：**

19

**返回：**

返回创建的[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)对象的指针。

### OH_ArkUI_SurfaceCallback_Dispose()

```
void OH_ArkUI_SurfaceCallback_Dispose(OH_ArkUI_SurfaceCallback* callback)
```

**描述：**

销毁[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)对象。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| callback | 表示指向需要销毁的[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)对象的指针。 |

### OH_ArkUI_SurfaceHolder_Create()

```
OH_ArkUI_SurfaceHolder* OH_ArkUI_SurfaceHolder_Create(ArkUI_NodeHandle node)
```

**描述：**

创建XComponent组件的[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)对象。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| node | 表示指向Native接口创建的XComponent组件实例的指针。  |

**返回：**

返回被创建的[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)对象的指针。

### OH_ArkUI_SurfaceHolder_Dispose()

```
void OH_ArkUI_SurfaceHolder_Dispose(OH_ArkUI_SurfaceHolder* surfaceHolder)
```

**描述：**

销毁[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)对象。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| surfaceHolder |  表示指向需要销毁的[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例的指针。 |

### OH_ArkUI_SurfaceHolder_SetUserData()

```
int32_t OH_ArkUI_SurfaceHolder_SetUserData(OH_ArkUI_SurfaceHolder* surfaceHolder, void* userData)
```

**描述：**

向[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例存储自定义数据。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| surfaceHolder |  表示指向需要销毁的[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例的指针。 |
| userData |  表示指向要存储的自定义数据的指针。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_SurfaceHolder_GetUserData()

```
void* OH_ArkUI_SurfaceHolder_GetUserData(OH_ArkUI_SurfaceHolder* surfaceHolder);
```

**描述：**

获取[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例存储的自定义数据。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| surfaceHolder |  表示指向需要销毁的[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例的指针。 |

**返回：**

返回自定义数据。

### OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent(OH_ArkUI_SurfaceCallback* callback, void (*onSurfaceCreated)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**描述：**

设置surface生命周期回调中的创建回调事件。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| callback |  表示指示指向surface生命周期回调的指针。 |
| onSurfaceCreated |  表示声明surface创建时会触发的回调事件。 |

### OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent(OH_ArkUI_SurfaceCallback* callback, void (*onSurfaceChanged)(OH_ArkUI_SurfaceHolder* surfaceHolder, uint64_t width, uint64_t heigh))
```

**描述：**

设置surface生命周期回调中的大小改变回调事件。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| callback |  表示指示指向surface生命周期回调的指针。 |
| onSurfaceChanged |  表示声明surface大小改变时会触发的回调事件。 |

### OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent(OH_ArkUI_SurfaceCallback* callback, void (*onSurfaceDestroyed)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**描述：**

设置surface生命周期回调中的销毁回调事件。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| callback |  表示指示指向surface生命周期回调的指针。 |
| onSurfaceDestroyed |  表示声明surface销毁时会触发的回调事件。 |

### OH_ArkUI_SurfaceHolder_AddSurfaceCallback()

```
int32_t OH_ArkUI_SurfaceHolder_AddSurfaceCallback(OH_ArkUI_SurfaceHolder* surfaceHolder, OH_ArkUI_SurfaceCallback* callback)
```

**描述：**

添加surface生命周期回调到[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| surfaceHolder |  表示指向需要销毁的[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例的指针。 |
| callback |  表示指向新回调的指针。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback()

```
int32_t OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback(OH_ArkUI_SurfaceHolder* surfaceHolder, OH_ArkUI_SurfaceCallback* callback)
```

**描述：**

删除[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例先前添加的surface生命周期回调。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| surfaceHolder |  表示指向需要销毁的[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例的指针。 |
| callback |  表示指向新回调的指针。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_XComponent_GetNativeWindow()

```
OHNativeWindow* OH_ArkUI_XComponent_GetNativeWindow(OH_ArkUI_SurfaceHolder* surfaceHolder)
```

**描述：**

获取[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例关联的NativeWindow。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| surfaceHolder |  表示指向需要销毁的[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例的指针。 |

**返回：**

返回OH_ArkUI_SurfaceHolder实例关联的nativeWindow。

### OH_ArkUI_XComponent_SetAutoInitialize()

```
int32_t OH_ArkUI_XComponent_SetAutoInitialize(ArkUI_NodeHandle node, bool autoInitialize)
```

**描述：**

设置XComponent组件是否需要自动初始化Surface的标志位。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| node |  表示指向XComponent组件实例的指针。 |
| autoInitialize |  表示XComponent组件是否需要自动初始化Surface。如果autoInitialize值是true，OnSurfaceCreated回调会在挂树时被触发，OnSurfaceDestroyed回调会在下树时被触发。autoInitialize默认值是true。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_XComponent_Initialize()

```
int32_t OH_ArkUI_XComponent_Initialize(ArkUI_NodeHandle node)
```

**描述：**

初始化XComponent组件持有的Surface。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| node |  表示指向XComponent组件实例的指针。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

[ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - XComponent持有的surface已经被初始化。

### OH_ArkUI_XComponent_Finalize()

```
int32_t OH_ArkUI_XComponent_Finalize(ArkUI_NodeHandle node)
```

**描述：**

销毁XComponent组件持有的surface。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| node |  表示指向XComponent组件实例的指针。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

[ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - XComponent持有的surface已经被销毁。

### OH_ArkUI_XComponent_IsInitialized()

```
int32_t OH_ArkUI_XComponent_IsInitialized(ArkUI_NodeHandle node, bool* isInitialized)
```

**描述：**

销毁XComponent组件持有的surface。

**起始版本：**

19

**参数:**

| 名称      | 描述                                    |
| --------- | --------------------------------------- |
| node |  表示指向XComponent组件实例的指针。 |
| isInitialized |  表示XComponent组件是否已经初始化Surface。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_NativeXComponent_GetExtraMouseEventInfo()

```
int32_t OH_NativeXComponent_GetExtraMouseEventInfo(OH_NativeXComponent* component, OH_NativeXComponent_ExtraMouseEventInfo** extraMouseEventInfo)
```

**描述：**

从此[OH_NativeXComponent](#oh_nativexcomponent)实例中获取扩展的鼠标事件信息。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| component | 表示指向[OH_NativeXComponent](#oh_nativexcomponent)实例的指针。  |
| extraMouseEventInfo | 表示[OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo)类型指针的地址。  |

> **说明：**
>
> 此接口应在鼠标事件回调函数的作用域中调用，不应在鼠标事件回调函数的作用域之外调用此接口或使用OH_NativeXComponent_ExtraMouseEventInfo实例。
>
> 对于调用此接口获取的OH_NativeXComponent_ExtraMouseEventInfo类型的指针，不能调用delete语句将其销毁。
>
> 传入此接口的component参数或extraMouseEventInfo参数为空指针时，为传入参数异常情况。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_NativeXComponent_GetMouseEventModifierKeyStates()

```
int32_t OH_NativeXComponent_GetMouseEventModifierKeyStates(OH_NativeXComponent_ExtraMouseEventInfo* extraMouseEventInfo, uint64_t* keys)
```

**描述：**

从[OH_NativeXComponent_ExtraMouseEventInfo](#oh_nativexcomponent_extramouseeventinfo)实例中获取功能键按压状态信息。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| extraMouseEventInfo | 表示指向扩展的鼠标事件信息实例的指针。  |
| keys | 用于接收功能键按压状态信息的64位无符号整数的地址。  |

> **说明：**
>
> 调用此接口获取的功能键按状态信息存储在一个64位无符号整数中，应使用[ArkUI_ModifierKeyName](./_ark_u_i___event_module.md#arkui_modifierkeyname)类型的枚举值与获取的64位无符号整数进行与（&）位运算操作来获取某一功能按键的按压状态，位运算的结果为0表示该功能键未按下，位运算的结果为1表示该功能键按下。
>
> 传入此接口的component参数或keys参数为空指针时，为传入参数异常情况。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_NativeXComponent_GetKeyEventModifierKeyStates()

```
int32_t OH_NativeXComponent_GetKeyEventModifierKeyStates(OH_NativeXComponent_KeyEvent* keyEvent, uint64_t* keys)
```

**描述：**

从按键事件中获取功能键按压状态。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向按键事件的指针。  |
| keys | 用于接收功能键按压状态信息的64位无符号整数的地址。  |

> **说明：**
>
> 调用此接口获取的功能键按状态信息存储在一个64位无符号整数中，应使用[ArkUI_ModifierKeyName](./_ark_u_i___event_module.md#arkui_modifierkeyname)类型的枚举值与获取的64位无符号整数进行与（&）位运算操作来获取某一功能按键的按压状态，位运算的结果为0表示该功能键未按下，位运算的结果为1表示该功能键按下。
>
> 传入此接口的keyEvent参数或keys参数为空指针时，为传入参数异常情况。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_NativeXComponent_GetKeyEventNumLockState()

```
int32_t OH_NativeXComponent_GetKeyEventNumLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isNumLockOn)
```

**描述：**

从按键事件中获取NumLock（小键盘锁定）键的状态信息。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向按键事件的指针。  |
| isNumLockOn | 用于接收NumLock（小键盘锁定）键状态的bool类型变量的地址。  |

> **说明：**
>
> 调用此接口获取的NumLock（小键盘锁定）键状态信息存储在一个bool类型变量中，其值为true时表示NumLock（小键盘锁定）键处于生效状态，其值为false时表示NumLock（小键盘锁定）键处于未生效状态。
>
> 传入此接口的keyEvent参数或isNumLockOn参数为空指针时，为传入参数异常情况。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_NativeXComponent_GetKeyEventCapsLockState()

```
int32_t OH_NativeXComponent_GetKeyEventCapsLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isCapsLockOn)
```

**描述：**

从按键事件中获取CapsLock（大写锁定）键的状态信息。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向按键事件的指针。  |
| isCapsLockOn | 用于接收CapsLock（大写锁定）键状态的bool类型变量的地址。  |

> **说明：**
>
> 调用此接口获取的CapsLock（大写锁定）键状态信息存储在一个bool类型变量中，其值为true时表示CapsLock（大写锁定）键处于生效状态，其值为false时表示CapsLock（大写锁定）键处于未生效状态。
>
> 传入此接口的keyEvent参数或isCapsLockOn参数为空指针时，为传入参数异常情况。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_NativeXComponent_GetKeyEventScrollLockState()

```
int32_t OH_NativeXComponent_GetKeyEventScrollLockState(OH_NativeXComponent_KeyEvent* keyEvent, bool* isScrollLockOn)
```

**描述：**

从按键事件中获取ScrollLock（滚动锁定）键的状态信息。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| keyEvent | 表示指向按键事件的指针。  |
| isScrollLockOn | 用于接收ScrollLock（滚动锁定）键状态的bool类型变量的地址。  |

> **说明：**
>
> 调用此接口获取的ScrollLock（滚动锁定）键状态信息存储在一个bool类型变量中，其值为true时表示ScrollLock（滚动锁定）键处于生效状态，其值为false时表示ScrollLock（滚动锁定）键处于未生效状态。
>
> 传入此接口的keyEvent参数或isScrollLockOn参数为空指针时，为传入参数异常情况。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_XComponent_SetExpectedFrameRateRange()

```
int32_t OH_ArkUI_XComponent_SetExpectedFrameRateRange(
    ArkUI_NodeHandle node, OH_NativeXComponent_ExpectedRateRange range)
```

**描述：**

为此XComponent组件实例设置期望帧率。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 表示XComponent组件实例。  |
| range | 表示[OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md)类型的期望帧率信息对象。  |

> **说明：**
>
> 此接口中传入的XComponent组件实例需要由[ArkUI NDK接口](../../ui/ndk-access-the-arkts-page.md)创建或通过[NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters)构造。
>
> 传入参数中的[OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md)对象的[min](#min)成员的值需要小于等于[max](#max)成员的值，同时[expected](#expected)成员的值应大于等于[min](#min)成员的值且小于等于[max](#max)成员的值。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_XComponent_RegisterOnFrameCallback()

```
int32_t OH_ArkUI_XComponent_RegisterOnFrameCallback(ArkUI_NodeHandle node,
    void (*callback)(ArkUI_NodeHandle node, uint64_t timestamp, uint64_t targetTimestamp))
```

**描述：**

为此XComponent组件实例注册帧回调函数。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 表示XComponent组件实例。  |
| callback | 表示执行帧回调函数的指针。 <br> - timestamp: 当前帧到达的时间（单位：纳秒）。<br> - targetTimestamp: 下一帧预期到达的时间（单位：纳秒）。    |

> **说明：**
>
> 此接口中传入的XComponent组件实例需要由[ArkUI NDK接口](../../ui/ndk-access-the-arkts-page.md)创建或通过[NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters)构造。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_XComponent_UnregisterOnFrameCallback()

```
int32_t OH_ArkUI_XComponent_UnregisterOnFrameCallback(ArkUI_NodeHandle node)
```

**描述：**

为此XComponent组件实例取消注册帧回调函数。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 表示XComponent组件实例。  |

> **说明：**
>
> 此接口中传入的XComponent组件实例需要由[ArkUI NDK接口](../../ui/ndk-access-the-arkts-page.md)创建或通过[NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters)构造。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_XComponent_SetNeedSoftKeyboard()

```
int32_t OH_ArkUI_XComponent_SetNeedSoftKeyboard(ArkUI_NodeHandle node, bool needSoftKeyboard)
```

**描述：**

为此XComponent组件实例设置是否需要软键盘。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 表示XComponent组件实例。  |
|needSoftKeyboard|表示是否需要软键盘。|

> **说明：**
>
> 此接口中传入的XComponent组件实例需要由[ArkUI NDK接口](../../ui/ndk-access-the-arkts-page.md)创建或通过[NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters)构造。
>
> XComponent组件默认的needSoftKeyboard值为false。

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md#arkui_errorcode) - 执行成功。

[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md#arkui_errorcode) - 传入参数异常。

### OH_ArkUI_AccessibilityProvider_Create()

```
ArkUI_AccessibilityProvider* OH_ArkUI_AccessibilityProvider_Create(ArkUI_NodeHandle node)
```

**描述：**

基于此XComponent实例创建[ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider)实例。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| node | 表示XComponent组件实例。  |

> **说明：**
>
> 此接口中传入的XComponent组件实例需要由[ArkUI NDK接口](../../ui/ndk-access-the-arkts-page.md)创建或通过[NativeXComponentParameters](./arkui-ts/ts-basic-components-xcomponent.md#nativexcomponentparameters)构造。

**返回：**

[ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider)类型的指针。

### OH_ArkUI_AccessibilityProvider_Dispose()

```
void OH_ArkUI_AccessibilityProvider_Dispose(ArkUI_AccessibilityProvider* provider)
```

**描述：**

销毁由NDK接口[OH_ArkUI_AccessibilityProvider_Create](#oh_arkui_accessibilityprovider_create)创建的[ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider)实例。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| provider | 表示由NDK接口[OH_ArkUI_AccessibilityProvider_Create](#oh_arkui_accessibilityprovider_create)创建的[ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider)实例。  |

### OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent(
    OH_ArkUI_SurfaceCallback* callback,
    void (*onSurfaceShow)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**描述：**

为此[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)实例设置Surface显示回调。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| callback | 表示指向[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)实例的指针。 |
|onSurfaceShow|表示Surface显示回调函数指针。<br> - surfaceHolder：表示指向[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例的指针。|

### OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent()

```
void OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent(
    OH_ArkUI_SurfaceCallback* callback,
    void (*onSurfaceHide)(OH_ArkUI_SurfaceHolder* surfaceHolder))
```

**描述：**

为此[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)实例设置Surface隐藏回调。

**起始版本：**

20

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| callback | 表示指向[OH_ArkUI_SurfaceCallback](#oh_arkui_surfacecallback)实例的指针。 |
|onSurfaceHide|表示Surface隐藏回调函数指针。<br> - surfaceHolder：表示指向[OH_ArkUI_SurfaceHolder](#oh_arkui_surfaceholder)实例的指针。|

<!--  -->

## 变量说明


### OH_XCOMPONENT_ID_LEN_MAX

```
const uint32_t OH_XCOMPONENT_ID_LEN_MAX = 128
```


**描述：**


ArkUI XComponent的id最大长度。


**起始版本：**


8


### OH_MAX_TOUCH_POINTS_NUMBER

```
const uint32_t OH_MAX_TOUCH_POINTS_NUMBER = 10
```

**描述：**

触摸事件中的可识别的触摸点个数最大值。

**起始版本：**

8


### action

```
OH_NativeXComponent_MouseEventAction OH_NativeXComponent_MouseEvent::action
```

**描述:**

当前鼠标事件动作。

**起始版本：**

8


### button

```
OH_NativeXComponent_MouseEventButton OH_NativeXComponent_MouseEvent::button
```

**描述:**

鼠标事件按键。

**起始版本：**

8


### deviceId

```
int64_t OH_NativeXComponent_TouchEvent::deviceId = 0
```

**描述:**

产生当前触摸事件的设备的ID。

**起始版本：**

8


### DispatchHoverEvent

```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchHoverEvent) (OH_NativeXComponent *component, bool isHover)
```

**描述:**

当悬停事件被触发时调用。

**起始版本：**

8


### DispatchMouseEvent

```
void(* OH_NativeXComponent_MouseEvent_Callback::DispatchMouseEvent) (OH_NativeXComponent *component, void *window)
```

**描述:**

当鼠标事件被触发时调用。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window  | 表示NatievWindow句柄。              |

**起始版本：**

8


### DispatchTouchEvent

```
void(* OH_NativeXComponent_Callback::DispatchTouchEvent) (OH_NativeXComponent *component, void *window)
```

**描述:**

当触摸事件被触发时调用。

**起始版本：**

8


### force [1/2]

```
float OH_NativeXComponent_TouchPoint::force = 0.0
```

**描述:**

当前触摸事件的压力。

**起始版本：**

8


### force [2/2]

```
float OH_NativeXComponent_TouchEvent::force = 0.0
```

**描述:**

当前触摸事件的压力。

**起始版本：**

8


### id [1/2]

```
int32_t OH_NativeXComponent_TouchPoint::id = 0
```

**描述:**

手指的唯一标识符。

**起始版本：**

8


### id [2/2]

```
int32_t OH_NativeXComponent_TouchEvent::id = 0
```

**描述:**

手指的唯一标识符。

**起始版本：**

8


### isPressed

```
bool OH_NativeXComponent_TouchPoint::isPressed = false
```

**描述:**

当前点是否被按下。

**起始版本：**

8


### numPoints

```
uint32_t OH_NativeXComponent_TouchEvent::numPoints = 0
```

**描述:**

当前接触点的数量。

**起始版本：**

8


### OnSurfaceChanged

```
void(* OH_NativeXComponent_Callback::OnSurfaceChanged) (OH_NativeXComponent *component, void *window)
```

**描述:**

当surface改变时调用。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window  | 表示NatievWindow句柄。              |

**起始版本：**

8


### OnSurfaceCreated

```
void(* OH_NativeXComponent_Callback::OnSurfaceCreated) (OH_NativeXComponent *component, void *window)
```

**描述:**

创建surface时调用。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window  | 表示NatievWindow句柄。              |

**起始版本：**

8


### OnSurfaceDestroyed

```
void(* OH_NativeXComponent_Callback::OnSurfaceDestroyed) (OH_NativeXComponent *component, void *window)
```

**描述:**

当surface被销毁时调用。

**参数:**

| 名称        | 描述                            |
| --------- | ----------------------------- |
| component | 表示指向OH_NativeXComponent实例的指针。 |
| window  | 表示NatievWindow句柄。              |

**起始版本：**

8


### screenX [1/3]

```
float OH_NativeXComponent_TouchPoint::screenX = 0.0
```

**描述:**

触摸点相对于XComponent所在应用窗口左上角的x坐标。

**起始版本：**

8


### screenX [2/3]

```
float OH_NativeXComponent_TouchEvent::screenX = 0.0
```

**描述:**

触摸点相对于所在应用窗口左上角的x坐标。

**起始版本：**

8


### screenX [3/3]

```
float OH_NativeXComponent_MouseEvent::screenX
```

**描述:**

点击触点相对于所在应用屏幕左上角的x轴坐标。

**起始版本：**

8


### screenY [1/3]

```
float OH_NativeXComponent_TouchPoint::screenY = 0.0
```

**描述:**

触摸点相对于XComponent所在应用窗口左上角的y坐标。

**起始版本：**

8


### screenY [2/3]

```
float OH_NativeXComponent_TouchEvent::screenY = 0.0
```

**描述:**

触摸点相对于所在应用窗口左上角的y坐标。

**起始版本：**

8


### screenY [3/3]

```
float OH_NativeXComponent_MouseEvent::screenY
```

**描述:**

点击触点相对于所在应用屏幕左上角的y轴坐标。

**起始版本：**

8


### size [1/2]

```
double OH_NativeXComponent_TouchPoint::size = 0.0
```

**描述:**

指垫和屏幕之间的接触面积。

**起始版本：**

8


### size [2/2]

```
double OH_NativeXComponent_TouchEvent::size = 0.0
```

**描述:**

指垫和屏幕之间的接触面积。

**起始版本：**

8


### timeStamp [1/2]

```
long long OH_NativeXComponent_TouchPoint::timeStamp = 0
```

**描述:**

当前触摸事件的时间戳。

**起始版本：**

8


### timeStamp [2/2]

```
long long OH_NativeXComponent_TouchEvent::timeStamp = 0
```

**描述:**

当前触摸事件的时间戳。

**起始版本：**

8


### timestamp

```
int64_t OH_NativeXComponent_MouseEvent::timestamp
```

**描述:**

当前鼠标事件的时间戳。

**起始版本：**

8


### touchPoints

```
OH_NativeXComponent_TouchPoint OH_NativeXComponent_TouchEvent::touchPoints[OH_MAX_TOUCH_POINTS_NUMBER]
```

**描述:**

当前触摸点的数组。

**起始版本：**

8


### type [1/2]

```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchPoint::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**描述:**

触摸事件的触摸类型。

**起始版本：**

8


### type [2/2]

```
OH_NativeXComponent_TouchEventType OH_NativeXComponent_TouchEvent::type = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN
```

**描述:**

触摸事件的触摸类型。

**起始版本：**

8


### x [1/3]

```
float OH_NativeXComponent_TouchPoint::x = 0.0
```

**描述:**

触摸点相对于XComponent组件左边缘的x坐标。

**起始版本：**

8


### x [2/3]

```
float OH_NativeXComponent_TouchEvent::x = 0.0
```

**描述:**

触摸点相对于XComponent组件左边缘的x坐标。

**起始版本：**

8


### x [3/3]

```
float OH_NativeXComponent_MouseEvent::x
```

**描述:**

点击触点相对于当前组件左上角的x轴坐标。

**起始版本：**

8


### y [1/3]

```
float OH_NativeXComponent_TouchPoint::y = 0.0
```

**描述:**

触摸点相对于XComponent组件上边缘的y坐标。

**起始版本：**

8


### y [2/3]

```
float OH_NativeXComponent_TouchEvent::y = 0.0
```

**描述:**

触摸点相对于XComponent组件上边缘的y坐标。

**起始版本：**

8


### y [3/3]

```
float OH_NativeXComponent_MouseEvent::y
```

**描述:**

点击触点相对于当前组件左上角的y轴坐标。

**起始版本：**

8

### expected

```
int32_t OH_NativeXComponent_ExpectedRateRange::expected
```
**描述：**

期望帧率。

**起始版本：**

11

### max

```
int32_t OH_NativeXComponent_ExpectedRateRange::max
```
**描述：**

期望帧率范围最大值。

**起始版本：**

11


### min

```
int32_t OH_NativeXComponent_ExpectedRateRange::min
```
**描述：**

期望帧率范围最小值。

**起始版本：**

11
