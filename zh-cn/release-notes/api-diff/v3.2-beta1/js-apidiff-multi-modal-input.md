# 多模输入子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，多模输入子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.multimodalInput.inputDevice | inputDevice | function getKeyboardType(deviceId: number, callback: AsyncCallback\<KeyboardType>): void;<br>function getKeyboardType(deviceId: number): Promise\<KeyboardType>; | 新增 |
| ohos.multimodalInput.inputDevice | inputDevice | function supportKeys(deviceId: number, keys: Array\<KeyCode>, callback: Callback\<Array\<boolean>>): void;<br>function supportKeys(deviceId: number, keys: Array\<KeyCode>): Promise\<Array\<boolean>>; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | uniq: string; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | phys: string; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | version: number; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | vendor: number; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | product: number; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | bus: number; | 新增 |
| ohos.multimodalInput.inputDevice | AxisRange | resolution: number; | 新增 |
| ohos.multimodalInput.inputDevice | AxisRange | flat: number; | 新增 |
| ohos.multimodalInput.inputDevice | AxisRange | fuzz: number; | 新增 |
| ohos.multimodalInput.inputDevice | inputDevice | function off(type: "change", listener?: Callback\<DeviceListener>): void; | 新增 |
| ohos.multimodalInput.inputDevice | inputDevice | function on(type: "change", listener: Callback\<DeviceListener>): void; | 新增 |
| ohos.multimodalInput.inputDevice | DeviceListener | deviceId: number; | 新增 |
| ohos.multimodalInput.inputDevice | DeviceListener | type: ChangedType; | 新增 |
| ohos.multimodalInput.inputDevice | KeyboardType | REMOTE_CONTROL = 5 | 新增 |
| ohos.multimodalInput.inputDevice | KeyboardType | HANDWRITING_PEN = 4 | 新增 |
| ohos.multimodalInput.inputDevice | KeyboardType | DIGITAL_KEYBOARD = 3 | 新增 |
| ohos.multimodalInput.inputDevice | KeyboardType | ALPHABETIC_KEYBOARD = 2 | 新增 |
| ohos.multimodalInput.inputDevice | KeyboardType | UNKNOWN = 1 | 新增 |
| ohos.multimodalInput.inputDevice | KeyboardType | NONE = 0 | 新增 |
| ohos.multimodalInput.inputEvent | InputEvent | windowId: number; | 新增 |
| ohos.multimodalInput.inputEvent | InputEvent | screenId: number; | 新增 |
| ohos.multimodalInput.inputEvent | InputEvent | actionTime: number; | 新增 |
| ohos.multimodalInput.inputEvent | InputEvent | deviceId: number; | 新增 |
| ohos.multimodalInput.inputEvent | InputEvent | id: number; | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_9 = 3109 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_8 = 3108 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_7 = 3107 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_6 = 3106 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_5 = 3105 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_4 = 3104 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_3 = 3103 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_2 = 3102 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_1 = 3101 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_0 = 3100 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CHANNEL = 3001 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RFKILL = 2847 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_WWAN_WIMAX = 2846 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_UWB = 2845 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_WLAN = 2844 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BLUETOOTH = 2843 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BATTERY = 2842 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SWITCHVIDEOMODE = 2841 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ALTERASE = 2839 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SHOP = 2838 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SPORT = 2837 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CONNECT = 2836 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_QUESTION = 2834 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SOUND = 2833 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HP = 2832 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SUSPEND = 2831 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DASHBOARD = 2830 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROG4 = 2829 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROG3 = 2828 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F24 = 2827 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F23 = 2826 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F22 = 2825 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F21 = 2824 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F20 = 2823 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F19 = 2822 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F18 = 2821 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F17 = 2820 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F16 = 2819 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F15 = 2818 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F14 = 2817 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F13 = 2816 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MOVE = 2815 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ISO = 2814 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EJECTCLOSECD = 2813 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_COMPUTER = 2812 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CYCLEWINDOWS = 2811 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DIRECTION_ROTATE_DISPLAY = 2810 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCREENLOCK = 2809 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MSDOS = 2808 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROG2 = 2807 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROG1 = 2806 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_XFER = 2805 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DELETEFILE = 2804 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SENDFILE = 2803 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_WAKEUP = 2802 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SETUP = 2801 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FRONT = 2800 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_CANCEL = 2731 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_ACCEPT = 2730 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_NEXTGROUP = 2729 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_PREVGROUP = 2728 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_NEXT = 2727 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDINPUTASSIST_PREV = 2726 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_MAX = 2725 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_MIN = 2724 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBD_LAYOUT_NEXT = 2723 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ASSISTANT = 2722 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCREENSAVER = 2721 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_APPSELECT = 2720 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CONTROLPANEL = 2719 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_JOURNAL = 2718 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TASKMANAGER = 2717 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BUTTONCONFIG = 2716 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_IMAGES = 2715 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_REPEAT = 2714 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_COFFEE = 2713 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SPELLCHECK = 2712 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_TOGGLE = 2711 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MESSENGER = 2710 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ADDRESSBOOK = 2709 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VOICEMAIL = 2708 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NEWS = 2707 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DATABASE = 2706 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PRESENTATION = 2705 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GRAPHICSEDITOR = 2704 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SPREADSHEET = 2703 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EDITOR = 2702 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_WORDPROCESSOR = 2701 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ZOOMRESET = 2700 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ZOOMOUT = 2699 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ZOOMIN = 2698 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GAMES = 2697 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIDEOPHONE = 2696 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SHUFFLE = 2695 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SLOW = 2694 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RESTART = 2693 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_LAST = 2692 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CHANNELDOWN = 2691 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CHANNELUP = 2690 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BLUE = 2689 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_YELLOW = 2688 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GREEN = 2687 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RED = 2686 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CALENDAR = 2685 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEMO = 2684 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIDEO = 2683 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_AUDIO = 2682 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DVD = 2681 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PLAYER = 2680 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TUNER = 2679 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TAPE = 2678 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CD = 2677 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SAT = 2676 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VCR2 = 2675 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VCR = 2674 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TV2 = 2673 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TV = 2672 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PC = 2671 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ASPECT_RATIO = 2670 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KEYBOARD = 2669 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FULL_SCREEN = 2668 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SUBTITLE = 2667 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PVR = 2666 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROGRAM = 2665 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_INFO = 2664 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GOTO = 2663 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BTN_MISC = 2662 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DISPLAY_OFF = 2661 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_ZERO = 2660 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_CYCLE = 2659 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIDEO_PREV = 2658 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIDEO_NEXT = 2657 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DOCUMENTS = 2656 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SAVE = 2655 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FORWARDMAIL = 2654 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_REPLY = 2653 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SEND = 2652 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDILLUM_UP = 2651 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDILLUM_DOWN = 2650 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KBDILLUM_TOGGLE = 2649 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CANCEL = 2648 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FINANCE = 2647 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CHAT = 2646 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PRINT = 2645 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BASSBOOST = 2644 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PLAY = 2643 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CLOSE = 2642 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_REDO = 2641 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NEW = 2640 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCROLLDOWN = 2639 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCROLLUP = 2638 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EDIT = 2637 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EXIT = 2636 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_REFRESH = 2635 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CONFIG = 2634 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_STOPCD = 2632 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PREVIOUS = 2631 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PLAYPAUSE = 2630 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NEXT = 2629 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BOOKMARKS = 2628 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FILE = 2627 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CALC = 2626 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HELP = 2625 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CUT = 2624 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FIND = 2623 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PASTE = 2622 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_OPEN = 2621 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_COPY = 2620 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_UNDO = 2619 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PROPS = 2618 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_AGAIN = 2617 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_STOP = 2616 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_YEN = 2615 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HANJA = 2614 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HANGUEL = 2613 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCALE = 2612 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_PLUSMINUS = 2611 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MACRO = 2610 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_LINEFEED = 2609 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MUHENKAN = 2608 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KATAKANA_HIRAGANA = 2607 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HENKAN = 2606 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HIRAGANA = 2605 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_KATAKANA = 2604 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RO = 2603 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_102ND = 2602 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ZENKAKU_HANKAKU = 2601 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SLEEP = 2600 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VIRTUAL_MULTITASK = 2210 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_RIGHT_PAREN = 2122 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_LEFT_PAREN = 2121 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_EQUALS = 2120 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_ENTER = 2119 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_COMMA = 2118 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_DOT = 2117 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_ADD = 2116 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_SUBTRACT = 2115 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_MULTIPLY = 2114 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_DIVIDE = 2113 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_9 = 2112 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_8 = 2111 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_7 = 2110 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_6 = 2109 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_5 = 2108 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_4 = 2107 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_3 = 2106 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_2 = 2105 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_1 = 2104 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUMPAD_0 = 2103 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_NUM_LOCK = 2102 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F12 = 2101 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F11 = 2100 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F10 = 2099 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F9 = 2098 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F8 = 2097 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F7 = 2096 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F6 = 2095 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F5 = 2094 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F4 = 2093 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F3 = 2092 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F2 = 2091 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F1 = 2090 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_RECORD = 2089 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_EJECT = 2088 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_CLOSE = 2087 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_PAUSE = 2086 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_PLAY = 2085 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FORWARD = 2084 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_INSERT = 2083 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MOVE_END = 2082 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MOVE_HOME = 2081 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BREAK = 2080 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SYSRQ = 2079 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FUNCTION = 2078 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_META_RIGHT = 2077 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_META_LEFT = 2076 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SCROLL_LOCK = 2075 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CAPS_LOCK = 2074 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CTRL_RIGHT = 2073 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CTRL_LEFT = 2072 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FORWARD_DEL = 2071 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ESCAPE = 2070 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PAGE_DOWN = 2069 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PAGE_UP = 2068 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MENU = 2067 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PLUS = 2066 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_AT = 2065 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SLASH = 2064 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_APOSTROPHE = 2063 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SEMICOLON = 2062 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BACKSLASH = 2061 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_RIGHT_BRACKET = 2060 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_LEFT_BRACKET = 2059 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EQUALS = 2058 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MINUS = 2057 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_GRAVE = 2056 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DEL = 2055 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ENTER = 2054 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ENVELOPE = 2053 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_EXPLORER = 2052 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SYM = 2051 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SPACE = 2050 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_TAB = 2049 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SHIFT_RIGHT = 2048 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_SHIFT_LEFT = 2047 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ALT_RIGHT = 2046 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_ALT_LEFT = 2045 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_PERIOD = 2044 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_COMMA = 2043 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_Z = 2042 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_Y = 2041 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_X = 2040 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_W = 2039 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_V = 2038 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_U = 2037 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_T = 2036 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_S = 2035 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_R = 2034 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_Q = 2033 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_P = 2032 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_O = 2031 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_N = 2030 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_M = 2029 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_L = 2028 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_K = 2027 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_J = 2026 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_I = 2025 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_H = 2024 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_G = 2023 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_F = 2022 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_E = 2021 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_D = 2020 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_C = 2019 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_B = 2018 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_A = 2017 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_CENTER = 2016 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_RIGHT = 2015 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_LEFT = 2014 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_DOWN = 2013 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_DPAD_UP = 2012 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_POUND = 2011 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_STAR = 2010 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_9 = 2009 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_8 = 2008 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_7 = 2007 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_6 = 2006 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_5 = 2005 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_4 = 2004 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_3 = 2003 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_2 = 2002 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_1 = 2001 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_0 = 2000 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_DOWN = 41 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BRIGHTNESS_UP = 40 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MUTE = 23 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VOLUME_MUTE = 22 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_CAMERA = 19 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_POWER = 18 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VOLUME_DOWN = 17 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_VOLUME_UP = 16 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_FAST_FORWARD = 15 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_REWIND = 14 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_PREVIOUS = 13 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_NEXT = 12 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_STOP = 11 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_MEDIA_PLAY_PAUSE = 10 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_BACK = 2 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_HOME = 1 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_UNKNOWN = -1 | 新增 |
| ohos.multimodalInput.keyCode | KeyCode | KEYCODE_FN = 0 | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | scrollLock: boolean; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | numLock: boolean; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | capsLock: boolean; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | fnKey: boolean; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | logoKey: boolean; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | shiftKey: boolean; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | altKey: boolean; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | ctrlKey: boolean; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | keys: Key[]; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | unicodeChar: number; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | key: Key; | 新增 |
| ohos.multimodalInput.keyEvent | KeyEvent | action: Action; | 新增 |
| ohos.multimodalInput.keyEvent | Key | deviceId: number; | 新增 |
| ohos.multimodalInput.keyEvent | Key | pressedTime: number; | 新增 |
| ohos.multimodalInput.keyEvent | Key | code: KeyCode; | 新增 |
| ohos.multimodalInput.keyEvent | Action | UP = 2 | 新增 |
| ohos.multimodalInput.keyEvent | Action | DOWN = 1 | 新增 |
| ohos.multimodalInput.keyEvent | Action | CANCEL = 0 | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | scrollLock:boolean | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | numLock:boolean | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | capsLock:boolean | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | fnKey:boolean | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | logoKey: boolean; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | shiftKey: boolean; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | altKey: boolean; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | ctrlKey: boolean; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | pressedKeys: KeyCode[]; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | axes: AxisValue[]; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | pressedButtons: Button[]; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | button: Button; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | rawDeltaY: number; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | rawDeltaX: number; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | windowY: number; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | windowX: number; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | screenY: number; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | screenX: number; | 新增 |
| ohos.multimodalInput.mouseEvent | MouseEvent | action: Action; | 新增 |
| ohos.multimodalInput.mouseEvent | AxisValue | value: number | 新增 |
| ohos.multimodalInput.mouseEvent | AxisValue | axis: Axis; | 新增 |
| ohos.multimodalInput.mouseEvent | Axis | PINCH = 2 | 新增 |
| ohos.multimodalInput.mouseEvent | Axis | SCROLL_HORIZONTAL = 1 | 新增 |
| ohos.multimodalInput.mouseEvent | Axis | SCROLL_VERTICAL = 0 | 新增 |
| ohos.multimodalInput.mouseEvent | Button | TASK = 7 | 新增 |
| ohos.multimodalInput.mouseEvent | Button | BACK = 6 | 新增 |
| ohos.multimodalInput.mouseEvent | Button | FORWARD = 5 | 新增 |
| ohos.multimodalInput.mouseEvent | Button | EXTRA = 4 | 新增 |
| ohos.multimodalInput.mouseEvent | Button | SIDE = 3 | 新增 |
| ohos.multimodalInput.mouseEvent | Button | RIGHT = 2 | 新增 |
| ohos.multimodalInput.mouseEvent | Button | MIDDLE = 1 | 新增 |
| ohos.multimodalInput.mouseEvent | Button | LEFT = 0 | 新增 |
| ohos.multimodalInput.mouseEvent | Action | AXIS_END = 6 | 新增 |
| ohos.multimodalInput.mouseEvent | Action | AXIS_UPDATE = 5 | 新增 |
| ohos.multimodalInput.mouseEvent | Action | AXIS_BEGIN = 4 | 新增 |
| ohos.multimodalInput.mouseEvent | Action | BUTTON_UP = 3 | 新增 |
| ohos.multimodalInput.mouseEvent | Action | BUTTON_DOWN = 2 | 新增 |
| ohos.multimodalInput.mouseEvent | Action | MOVE = 1 | 新增 |
| ohos.multimodalInput.mouseEvent | Action | CANCEL = 0 | 新增 |
| ohos.multimodalInput.touchEvent | TouchEvent | sourceType: SourceType; | 新增 |
| ohos.multimodalInput.touchEvent | TouchEvent | touches: Touch[]; | 新增 |
| ohos.multimodalInput.touchEvent | TouchEvent | touch: Touch; | 新增 |
| ohos.multimodalInput.touchEvent | TouchEvent | action: Action; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | toolType: ToolType; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | rawY: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | rawX: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | toolHeight: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | toolWidth: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | toolY: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | toolX: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | tiltY: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | tiltX: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | height: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | width: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | pressure: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | windowY: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | windowX: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | screenY: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | screenX: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | pressedTime: number; | 新增 |
| ohos.multimodalInput.touchEvent | Touch | id: number; | 新增 |
| ohos.multimodalInput.touchEvent | SourceType | TOUCH_PAD = 2 | 新增 |
| ohos.multimodalInput.touchEvent | SourceType | PEN = 1 | 新增 |
| ohos.multimodalInput.touchEvent | SourceType | TOUCH_SCREEN = 0 | 新增 |
| ohos.multimodalInput.touchEvent | ToolType | LENS = 7 | 新增 |
| ohos.multimodalInput.touchEvent | ToolType | MOUSE = 6 | 新增 |
| ohos.multimodalInput.touchEvent | ToolType | AIRBRUSH = 5 | 新增 |
| ohos.multimodalInput.touchEvent | ToolType | PENCIL = 4 | 新增 |
| ohos.multimodalInput.touchEvent | ToolType | BRUSH = 3 | 新增 |
| ohos.multimodalInput.touchEvent | ToolType | RUBBER = 2 | 新增 |
| ohos.multimodalInput.touchEvent | ToolType | PEN = 1 | 新增 |
| ohos.multimodalInput.touchEvent | ToolType | FINGER = 0 | 新增 |
| ohos.multimodalInput.touchEvent | Action | UP = 3 | 新增 |
| ohos.multimodalInput.touchEvent | Action | MOVE = 2 | 新增 |
| ohos.multimodalInput.touchEvent | Action | DOWN = 1 | 新增 |
| ohos.multimodalInput.touchEvent | Action | CANCEL = 0 | 新增 |

