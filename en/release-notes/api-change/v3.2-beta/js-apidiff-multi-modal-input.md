# JS API Changes of the Multimodal Input Subsystem

The table below lists the APIs changes of the multimodal input subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.multimodalInput.inputDevice | inputDevice | function getKeyboardType(deviceId: number, callback: AsyncCallback\<KeyboardType>): void;<br>function getKeyboardType(deviceId: number): Promise\<KeyboardType>; | Added|
| ohos.multimodalInput.inputDevice | inputDevice | function supportKeys(deviceId: number, keys: Array\<KeyCode>, callback: Callback\<Array\<boolean>>): void;<br>function supportKeys(deviceId: number, keys: Array\<KeyCode>): Promise\<Array\<boolean>>; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | uniq: string; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | phys: string; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | version: number; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | vendor: number; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | product: number; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | bus: number; | Added|
| ohos.multimodalInput.inputDevice | AxisRange | resolution: number; | Added|
| ohos.multimodalInput.inputDevice | AxisRange | flat: number; | Added|
| ohos.multimodalInput.inputDevice | AxisRange | fuzz: number; | Added|
| ohos.multimodalInput.inputDevice | inputDevice | function off(type: "change", listener?: Callback\<DeviceListener>): void; | Added|
| ohos.multimodalInput.inputDevice | inputDevice | function on(type: "change", listener: Callback\<DeviceListener>): void; | Added|
| ohos.multimodalInput.inputDevice | DeviceListener | deviceId: number; | Added|
| ohos.multimodalInput.inputDevice | DeviceListener | type: ChangedType; | Added|
| ohos.multimodalInput.inputDevice | KeyboardType | REMOTE_CONTROL = 5 | Added|
| ohos.multimodalInput.inputDevice | KeyboardType | HANDWRITING_PEN = 4 | Added|
| ohos.multimodalInput.inputDevice | KeyboardType | DIGITAL_KEYBOARD = 3 | Added|
| ohos.multimodalInput.inputDevice | KeyboardType | ALPHABETIC_KEYBOARD = 2 | Added|
| ohos.multimodalInput.inputDevice | KeyboardType | UNKNOWN = 1 | Added|
| ohos.multimodalInput.inputDevice | KeyboardType | NONE = 0 | Added|
| ohos.multimodalInput.inputEvent | InputEvent | windowId: number; | Added|
| ohos.multimodalInput.inputEvent | InputEvent | screenId: number; | Added|
| ohos.multimodalInput.inputEvent | InputEvent | actionTime: number; | Added|
| ohos.multimodalInput.inputEvent | InputEvent | deviceId: number; | Added|
| ohos.multimodalInput.inputEvent | InputEvent | id: number; | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_9 = 3109 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_8 = 3108 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_7 = 3107 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_6 = 3106 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_5 = 3105 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_4 = 3104 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_3 = 3103 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_2 = 3102 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_1 = 3101 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_0 = 3100 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CHANNEL = 3001 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RFKILL = 2847 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_WWAN_WIMAX = 2846 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_UWB = 2845 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_WLAN = 2844 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BLUETOOTH = 2843 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BATTERY = 2842 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SWITCHVIDEOMODE = 2841 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ALTERASE = 2839 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SHOP = 2838 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SPORT = 2837 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CONNECT = 2836 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_QUESTION = 2834 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SOUND = 2833 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HP = 2832 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SUSPEND = 2831 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DASHBOARD = 2830 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROG4 = 2829 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROG3 = 2828 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F24 = 2827 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F23 = 2826 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F22 = 2825 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F21 = 2824 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F20 = 2823 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F19 = 2822 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F18 = 2821 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F17 = 2820 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F16 = 2819 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F15 = 2818 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F14 = 2817 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F13 = 2816 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MOVE = 2815 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ISO = 2814 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EJECTCLOSECD = 2813 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_COMPUTER = 2812 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CYCLEWINDOWS = 2811 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DIRECTION_ROTATE_DISPLAY = 2810 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCREENLOCK = 2809 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MSDOS = 2808 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROG2 = 2807 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROG1 = 2806 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_XFER = 2805 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DELETEFILE = 2804 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SENDFILE = 2803 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_WAKEUP = 2802 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SETUP = 2801 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FRONT = 2800 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_CANCEL = 2731 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_ACCEPT = 2730 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_NEXTGROUP = 2729 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_PREVGROUP = 2728 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_NEXT = 2727 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_PREV = 2726 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_MAX = 2725 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_MIN = 2724 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBD_LAYOUT_NEXT = 2723 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ASSISTANT = 2722 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCREENSAVER = 2721 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_APPSELECT = 2720 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CONTROLPANEL = 2719 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_JOURNAL = 2718 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TASKMANAGER = 2717 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BUTTONCONFIG = 2716 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_IMAGES = 2715 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_REPEAT = 2714 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_COFFEE = 2713 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SPELLCHECK = 2712 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_TOGGLE = 2711 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MESSENGER = 2710 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ADDRESSBOOK = 2709 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VOICEMAIL = 2708 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NEWS = 2707 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DATABASE = 2706 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PRESENTATION = 2705 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GRAPHICSEDITOR = 2704 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SPREADSHEET = 2703 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EDITOR = 2702 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_WORDPROCESSOR = 2701 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ZOOMRESET = 2700 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ZOOMOUT = 2699 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ZOOMIN = 2698 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GAMES = 2697 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIDEOPHONE = 2696 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SHUFFLE = 2695 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SLOW = 2694 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RESTART = 2693 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_LAST = 2692 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CHANNELDOWN = 2691 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CHANNELUP = 2690 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BLUE = 2689 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_YELLOW = 2688 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GREEN = 2687 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RED = 2686 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CALENDAR = 2685 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEMO = 2684 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIDEO = 2683 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_AUDIO = 2682 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DVD = 2681 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PLAYER = 2680 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TUNER = 2679 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TAPE = 2678 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CD = 2677 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SAT = 2676 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VCR2 = 2675 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VCR = 2674 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TV2 = 2673 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TV = 2672 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PC = 2671 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ASPECT_RATIO = 2670 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KEYBOARD = 2669 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FULL_SCREEN = 2668 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SUBTITLE = 2667 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PVR = 2666 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROGRAM = 2665 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_INFO = 2664 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GOTO = 2663 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_MISC = 2662 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DISPLAY_OFF = 2661 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_ZERO = 2660 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_CYCLE = 2659 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIDEO_PREV = 2658 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIDEO_NEXT = 2657 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DOCUMENTS = 2656 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SAVE = 2655 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FORWARDMAIL = 2654 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_REPLY = 2653 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SEND = 2652 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDILLUM_UP = 2651 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDILLUM_DOWN = 2650 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDILLUM_TOGGLE = 2649 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CANCEL = 2648 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FINANCE = 2647 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CHAT = 2646 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PRINT = 2645 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BASSBOOST = 2644 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PLAY = 2643 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CLOSE = 2642 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_REDO = 2641 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NEW = 2640 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCROLLDOWN = 2639 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCROLLUP = 2638 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EDIT = 2637 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EXIT = 2636 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_REFRESH = 2635 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CONFIG = 2634 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_STOPCD = 2632 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PREVIOUS = 2631 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PLAYPAUSE = 2630 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NEXT = 2629 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BOOKMARKS = 2628 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FILE = 2627 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CALC = 2626 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HELP = 2625 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CUT = 2624 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FIND = 2623 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PASTE = 2622 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_OPEN = 2621 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_COPY = 2620 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_UNDO = 2619 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROPS = 2618 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_AGAIN = 2617 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_STOP = 2616 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_YEN = 2615 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HANJA = 2614 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HANGUEL = 2613 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCALE = 2612 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_PLUSMINUS = 2611 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MACRO = 2610 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_LINEFEED = 2609 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MUHENKAN = 2608 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KATAKANA_HIRAGANA = 2607 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HENKAN = 2606 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HIRAGANA = 2605 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KATAKANA = 2604 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RO = 2603 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_102ND = 2602 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ZENKAKU_HANKAKU = 2601 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SLEEP = 2600 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIRTUAL_MULTITASK = 2210 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_RIGHT_PAREN = 2122 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_LEFT_PAREN = 2121 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_EQUALS = 2120 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_ENTER = 2119 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_COMMA = 2118 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_DOT = 2117 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_ADD = 2116 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_SUBTRACT = 2115 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_MULTIPLY = 2114 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_DIVIDE = 2113 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_9 = 2112 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_8 = 2111 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_7 = 2110 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_6 = 2109 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_5 = 2108 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_4 = 2107 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_3 = 2106 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_2 = 2105 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_1 = 2104 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_0 = 2103 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUM_LOCK = 2102 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F12 = 2101 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F11 = 2100 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F10 = 2099 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F9 = 2098 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F8 = 2097 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F7 = 2096 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F6 = 2095 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F5 = 2094 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F4 = 2093 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F3 = 2092 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F2 = 2091 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F1 = 2090 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_RECORD = 2089 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_EJECT = 2088 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_CLOSE = 2087 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_PAUSE = 2086 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_PLAY = 2085 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FORWARD = 2084 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_INSERT = 2083 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MOVE_END = 2082 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MOVE_HOME = 2081 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BREAK = 2080 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SYSRQ = 2079 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FUNCTION = 2078 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_META_RIGHT = 2077 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_META_LEFT = 2076 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCROLL_LOCK = 2075 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CAPS_LOCK = 2074 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CTRL_RIGHT = 2073 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CTRL_LEFT = 2072 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FORWARD_DEL = 2071 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ESCAPE = 2070 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PAGE_DOWN = 2069 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PAGE_UP = 2068 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MENU = 2067 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PLUS = 2066 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_AT = 2065 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SLASH = 2064 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_APOSTROPHE = 2063 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SEMICOLON = 2062 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BACKSLASH = 2061 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RIGHT_BRACKET = 2060 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_LEFT_BRACKET = 2059 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EQUALS = 2058 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MINUS = 2057 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GRAVE = 2056 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DEL = 2055 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ENTER = 2054 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ENVELOPE = 2053 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EXPLORER = 2052 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SYM = 2051 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SPACE = 2050 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TAB = 2049 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SHIFT_RIGHT = 2048 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SHIFT_LEFT = 2047 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ALT_RIGHT = 2046 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ALT_LEFT = 2045 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PERIOD = 2044 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_COMMA = 2043 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_Z = 2042 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_Y = 2041 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_X = 2040 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_W = 2039 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_V = 2038 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_U = 2037 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_T = 2036 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_S = 2035 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_R = 2034 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_Q = 2033 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_P = 2032 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_O = 2031 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_N = 2030 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_M = 2029 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_L = 2028 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_K = 2027 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_J = 2026 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_I = 2025 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_H = 2024 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_G = 2023 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F = 2022 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_E = 2021 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_D = 2020 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_C = 2019 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_B = 2018 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_A = 2017 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_CENTER = 2016 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_RIGHT = 2015 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_LEFT = 2014 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_DOWN = 2013 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_UP = 2012 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_POUND = 2011 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_STAR = 2010 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_9 = 2009 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_8 = 2008 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_7 = 2007 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_6 = 2006 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_5 = 2005 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_4 = 2004 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_3 = 2003 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_2 = 2002 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_1 = 2001 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_0 = 2000 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_DOWN = 41 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_UP = 40 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MUTE = 23 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VOLUME_MUTE = 22 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CAMERA = 19 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_POWER = 18 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VOLUME_DOWN = 17 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VOLUME_UP = 16 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_FAST_FORWARD = 15 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_REWIND = 14 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_PREVIOUS = 13 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_NEXT = 12 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_STOP = 11 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_PLAY_PAUSE = 10 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BACK = 2 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HOME = 1 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_UNKNOWN = -1 | Added|
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FN = 0 | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | scrollLock: boolean; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | numLock: boolean; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | capsLock: boolean; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | fnKey: boolean; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | logoKey: boolean; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | shiftKey: boolean; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | altKey: boolean; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | ctrlKey: boolean; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | keys: Key[]; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | unicodeChar: number; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | key: Key; | Added|
| ohos.multimodalInput.keyEvent | KeyEvent | action: Action; | Added|
| ohos.multimodalInput.keyEvent | Key | deviceId: number; | Added|
| ohos.multimodalInput.keyEvent | Key | pressedTime: number; | Added|
| ohos.multimodalInput.keyEvent | Key | code: KeyCode; | Added|
| ohos.multimodalInput.keyEvent | Action | UP = 2 | Added|
| ohos.multimodalInput.keyEvent | Action | DOWN = 1 | Added|
| ohos.multimodalInput.keyEvent | Action | CANCEL = 0 | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | scrollLock:boolean | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | numLock:boolean | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | capsLock:boolean | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | fnKey:boolean | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | logoKey: boolean; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | shiftKey: boolean; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | altKey: boolean; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | ctrlKey: boolean; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | pressedKeys: KeyCode[]; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | axes: AxisValue[]; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | pressedButtons: Button[]; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | button: Button; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | rawDeltaY: number; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | rawDeltaX: number; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | windowY: number; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | windowX: number; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | screenY: number; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | screenX: number; | Added|
| ohos.multimodalInput.mouseEvent | MouseEvent | action: Action; | Added|
| ohos.multimodalInput.mouseEvent | AxisValue | value: number | Added|
| ohos.multimodalInput.mouseEvent | AxisValue | axis: Axis; | Added|
| ohos.multimodalInput.mouseEvent | Axis | PINCH = 2 | Added|
| ohos.multimodalInput.mouseEvent | Axis | SCROLL_HORIZONTAL = 1 | Added|
| ohos.multimodalInput.mouseEvent | Axis | SCROLL_VERTICAL = 0 | Added|
| ohos.multimodalInput.mouseEvent | Button | TASK = 7 | Added|
| ohos.multimodalInput.mouseEvent | Button | BACK = 6 | Added|
| ohos.multimodalInput.mouseEvent | Button | FORWARD = 5 | Added|
| ohos.multimodalInput.mouseEvent | Button | EXTRA = 4 | Added|
| ohos.multimodalInput.mouseEvent | Button | SIDE = 3 | Added|
| ohos.multimodalInput.mouseEvent | Button | RIGHT = 2 | Added|
| ohos.multimodalInput.mouseEvent | Button | MIDDLE = 1 | Added|
| ohos.multimodalInput.mouseEvent | Button | LEFT = 0 | Added|
| ohos.multimodalInput.mouseEvent | Action | AXIS_END = 6 | Added|
| ohos.multimodalInput.mouseEvent | Action | AXIS_UPDATE = 5 | Added|
| ohos.multimodalInput.mouseEvent | Action | AXIS_BEGIN = 4 | Added|
| ohos.multimodalInput.mouseEvent | Action | BUTTON_UP = 3 | Added|
| ohos.multimodalInput.mouseEvent | Action | BUTTON_DOWN = 2 | Added|
| ohos.multimodalInput.mouseEvent | Action | MOVE = 1 | Added|
| ohos.multimodalInput.mouseEvent | Action | CANCEL = 0 | Added|
| ohos.multimodalInput.touchEvent | TouchEvent | sourceType: SourceType; | Added|
| ohos.multimodalInput.touchEvent | TouchEvent | touches: Touch[]; | Added|
| ohos.multimodalInput.touchEvent | TouchEvent | touch: Touch; | Added|
| ohos.multimodalInput.touchEvent | TouchEvent | action: Action; | Added|
| ohos.multimodalInput.touchEvent | Touch | toolType: ToolType; | Added|
| ohos.multimodalInput.touchEvent | Touch | rawY: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | rawX: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | toolHeight: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | toolWidth: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | toolY: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | toolX: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | tiltY: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | tiltX: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | height: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | width: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | pressure: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | windowY: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | windowX: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | screenY: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | screenX: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | pressedTime: number; | Added|
| ohos.multimodalInput.touchEvent | Touch | id: number; | Added|
| ohos.multimodalInput.touchEvent | SourceType | TOUCH_PAD = 2 | Added|
| ohos.multimodalInput.touchEvent | SourceType | PEN = 1 | Added|
| ohos.multimodalInput.touchEvent | SourceType | TOUCH_SCREEN = 0 | Added|
| ohos.multimodalInput.touchEvent | ToolType | LENS = 7 | Added|
| ohos.multimodalInput.touchEvent | ToolType | MOUSE = 6 | Added|
| ohos.multimodalInput.touchEvent | ToolType | AIRBRUSH = 5 | Added|
| ohos.multimodalInput.touchEvent | ToolType | PENCIL = 4 | Added|
| ohos.multimodalInput.touchEvent | ToolType | BRUSH = 3 | Added|
| ohos.multimodalInput.touchEvent | ToolType | RUBBER = 2 | Added|
| ohos.multimodalInput.touchEvent | ToolType | PEN = 1 | Added|
| ohos.multimodalInput.touchEvent | ToolType | FINGER = 0 | Added|
| ohos.multimodalInput.touchEvent | Action | UP = 3 | Added|
| ohos.multimodalInput.touchEvent | Action | MOVE = 2 | Added|
| ohos.multimodalInput.touchEvent | Action | DOWN = 1 | Added|
| ohos.multimodalInput.touchEvent | Action | CANCEL = 0 | Added|
