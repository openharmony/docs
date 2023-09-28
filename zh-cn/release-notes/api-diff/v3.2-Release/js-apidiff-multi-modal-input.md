| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：inputDevice;<br>方法or属性：type ChangedType = 'add' \| 'remove';|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function on(type: "change", listener: Callback\<DeviceListener>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function off(type: "change", listener?: Callback\<DeviceListener>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getDeviceList(callback: AsyncCallback\<Array\<number>>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getDeviceList(): Promise\<Array\<number>>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getDeviceInfo(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getDeviceInfo(deviceId: number): Promise\<InputDeviceData>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function supportKeys(deviceId: number, keys: Array\<KeyCode>, callback: AsyncCallback\<Array\<boolean>>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function supportKeys(deviceId: number, keys: Array\<KeyCode>): Promise\<Array\<boolean>>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getKeyboardType(deviceId: number, callback: AsyncCallback\<KeyboardType>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getKeyboardType(deviceId: number): Promise\<KeyboardType>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：KeyboardType;<br>方法or属性：NONE = 0|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：KeyboardType;<br>方法or属性：UNKNOWN = 1|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：KeyboardType;<br>方法or属性：ALPHABETIC_KEYBOARD = 2|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：KeyboardType;<br>方法or属性：DIGITAL_KEYBOARD = 3|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：KeyboardType;<br>方法or属性：HANDWRITING_PEN = 4|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：KeyboardType;<br>方法or属性：REMOTE_CONTROL = 5|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：DeviceListener;<br>方法or属性：type: ChangedType;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：DeviceListener;<br>方法or属性：deviceId: number;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：AxisRange;<br>方法or属性：fuzz: number;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：AxisRange;<br>方法or属性：flat: number;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：AxisRange;<br>方法or属性：resolution: number;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：InputDeviceData;<br>方法or属性：bus: number;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：InputDeviceData;<br>方法or属性：product: number;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：InputDeviceData;<br>方法or属性：vendor: number;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：InputDeviceData;<br>方法or属性：version: number;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：InputDeviceData;<br>方法or属性：phys: string;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：InputDeviceData;<br>方法or属性：uniq: string;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function enable(enable: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function enable(enable: boolean): Promise\<void>;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise\<void>;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function stop(callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function stop(): Promise\<void>;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function getState(deviceDescriptor: string, callback: AsyncCallback\<{ state: boolean }>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function getState(deviceDescriptor: string): Promise\<{ state: boolean }>;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function on(type: 'cooperation', callback: AsyncCallback\<{ deviceDescriptor: string, eventMsg: EventMsg }>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：inputDeviceCooperate;<br>方法or属性：function off(type: 'cooperation', callback?: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：EventMsg;<br>方法or属性：MSG_COOPERATE_INFO_START = 200|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：EventMsg;<br>方法or属性：MSG_COOPERATE_INFO_SUCCESS = 201|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：EventMsg;<br>方法or属性：MSG_COOPERATE_INFO_FAIL = 202|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：EventMsg;<br>方法or属性：MSG_COOPERATE_STATE_ON = 500|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：EventMsg;<br>方法or属性：MSG_COOPERATE_STATE_OFF = 501|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|新增|NA|类名：InputEvent;<br>方法or属性：id: number;|@ohos.multimodalInput.inputEvent.d.ts|
|新增|NA|类名：InputEvent;<br>方法or属性：deviceId: number;|@ohos.multimodalInput.inputEvent.d.ts|
|新增|NA|类名：InputEvent;<br>方法or属性：actionTime: number;|@ohos.multimodalInput.inputEvent.d.ts|
|新增|NA|类名：InputEvent;<br>方法or属性：screenId: number;|@ohos.multimodalInput.inputEvent.d.ts|
|新增|NA|类名：InputEvent;<br>方法or属性：windowId: number;|@ohos.multimodalInput.inputEvent.d.ts|
|新增|NA|类名：inputMonitor;<br>方法or属性：function on(type:"mouse", receiver:Callback\<MouseEvent>):void;|@ohos.multimodalInput.inputMonitor.d.ts|
|新增|NA|类名：inputMonitor;<br>方法or属性：function off(type:"mouse", receiver?:Callback\<MouseEvent>):void;|@ohos.multimodalInput.inputMonitor.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FN = 0|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_UNKNOWN = -1|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_HOME = 1|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BACK = 2|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_PLAY_PAUSE = 10|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_STOP = 11|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_NEXT = 12|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_PREVIOUS = 13|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_REWIND = 14|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_FAST_FORWARD = 15|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VOLUME_UP = 16|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VOLUME_DOWN = 17|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_POWER = 18|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CAMERA = 19|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VOLUME_MUTE = 22|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MUTE = 23|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BRIGHTNESS_UP = 40|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BRIGHTNESS_DOWN = 41|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_0 = 2000|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_1 = 2001|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_2 = 2002|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_3 = 2003|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_4 = 2004|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_5 = 2005|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_6 = 2006|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_7 = 2007|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_8 = 2008|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_9 = 2009|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_STAR = 2010|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_POUND = 2011|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DPAD_UP = 2012|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DPAD_DOWN = 2013|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DPAD_LEFT = 2014|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DPAD_RIGHT = 2015|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DPAD_CENTER = 2016|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_A = 2017|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_B = 2018|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_C = 2019|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_D = 2020|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_E = 2021|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F = 2022|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_G = 2023|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_H = 2024|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_I = 2025|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_J = 2026|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_K = 2027|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_L = 2028|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_M = 2029|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_N = 2030|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_O = 2031|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_P = 2032|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_Q = 2033|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_R = 2034|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_S = 2035|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_T = 2036|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_U = 2037|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_V = 2038|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_W = 2039|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_X = 2040|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_Y = 2041|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_Z = 2042|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_COMMA = 2043|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PERIOD = 2044|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ALT_LEFT = 2045|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ALT_RIGHT = 2046|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SHIFT_LEFT = 2047|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SHIFT_RIGHT = 2048|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_TAB = 2049|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SPACE = 2050|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SYM = 2051|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_EXPLORER = 2052|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ENVELOPE = 2053|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ENTER = 2054|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DEL = 2055|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_GRAVE = 2056|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MINUS = 2057|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_EQUALS = 2058|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_LEFT_BRACKET = 2059|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_RIGHT_BRACKET = 2060|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BACKSLASH = 2061|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SEMICOLON = 2062|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_APOSTROPHE = 2063|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SLASH = 2064|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_AT = 2065|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PLUS = 2066|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MENU = 2067|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PAGE_UP = 2068|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PAGE_DOWN = 2069|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ESCAPE = 2070|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FORWARD_DEL = 2071|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CTRL_LEFT = 2072|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CTRL_RIGHT = 2073|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CAPS_LOCK = 2074|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SCROLL_LOCK = 2075|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_META_LEFT = 2076|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_META_RIGHT = 2077|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FUNCTION = 2078|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SYSRQ = 2079|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BREAK = 2080|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MOVE_HOME = 2081|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MOVE_END = 2082|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_INSERT = 2083|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FORWARD = 2084|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_PLAY = 2085|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_PAUSE = 2086|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_CLOSE = 2087|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_EJECT = 2088|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_RECORD = 2089|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F1 = 2090|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F2 = 2091|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F3 = 2092|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F4 = 2093|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F5 = 2094|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F6 = 2095|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F7 = 2096|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F8 = 2097|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F9 = 2098|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F10 = 2099|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F11 = 2100|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F12 = 2101|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUM_LOCK = 2102|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_0 = 2103|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_1 = 2104|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_2 = 2105|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_3 = 2106|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_4 = 2107|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_5 = 2108|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_6 = 2109|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_7 = 2110|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_8 = 2111|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_9 = 2112|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_DIVIDE = 2113|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_MULTIPLY = 2114|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_SUBTRACT = 2115|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_ADD = 2116|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_DOT = 2117|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_COMMA = 2118|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_ENTER = 2119|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_EQUALS = 2120|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_LEFT_PAREN = 2121|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_RIGHT_PAREN = 2122|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VIRTUAL_MULTITASK = 2210|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SLEEP = 2600|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ZENKAKU_HANKAKU = 2601|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_102ND = 2602|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_RO = 2603|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KATAKANA = 2604|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_HIRAGANA = 2605|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_HENKAN = 2606|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KATAKANA_HIRAGANA = 2607|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MUHENKAN = 2608|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_LINEFEED = 2609|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MACRO = 2610|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NUMPAD_PLUSMINUS = 2611|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SCALE = 2612|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_HANGUEL = 2613|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_HANJA = 2614|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_YEN = 2615|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_STOP = 2616|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_AGAIN = 2617|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PROPS = 2618|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_UNDO = 2619|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_COPY = 2620|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_OPEN = 2621|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PASTE = 2622|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FIND = 2623|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CUT = 2624|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_HELP = 2625|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CALC = 2626|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FILE = 2627|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BOOKMARKS = 2628|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NEXT = 2629|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PLAYPAUSE = 2630|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PREVIOUS = 2631|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_STOPCD = 2632|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CONFIG = 2634|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_REFRESH = 2635|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_EXIT = 2636|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_EDIT = 2637|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SCROLLUP = 2638|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SCROLLDOWN = 2639|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NEW = 2640|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_REDO = 2641|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CLOSE = 2642|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PLAY = 2643|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BASSBOOST = 2644|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PRINT = 2645|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CHAT = 2646|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FINANCE = 2647|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CANCEL = 2648|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDILLUM_TOGGLE = 2649|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDILLUM_DOWN = 2650|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDILLUM_UP = 2651|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SEND = 2652|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_REPLY = 2653|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FORWARDMAIL = 2654|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SAVE = 2655|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DOCUMENTS = 2656|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VIDEO_NEXT = 2657|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VIDEO_PREV = 2658|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BRIGHTNESS_CYCLE = 2659|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BRIGHTNESS_ZERO = 2660|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DISPLAY_OFF = 2661|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_MISC = 2662|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_GOTO = 2663|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_INFO = 2664|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PROGRAM = 2665|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PVR = 2666|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SUBTITLE = 2667|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FULL_SCREEN = 2668|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KEYBOARD = 2669|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ASPECT_RATIO = 2670|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PC = 2671|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_TV = 2672|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_TV2 = 2673|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VCR = 2674|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VCR2 = 2675|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SAT = 2676|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CD = 2677|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_TAPE = 2678|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_TUNER = 2679|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PLAYER = 2680|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DVD = 2681|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_AUDIO = 2682|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VIDEO = 2683|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEMO = 2684|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CALENDAR = 2685|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_RED = 2686|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_GREEN = 2687|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_YELLOW = 2688|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BLUE = 2689|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CHANNELUP = 2690|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CHANNELDOWN = 2691|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_LAST = 2692|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_RESTART = 2693|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SLOW = 2694|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SHUFFLE = 2695|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VIDEOPHONE = 2696|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_GAMES = 2697|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ZOOMIN = 2698|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ZOOMOUT = 2699|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ZOOMRESET = 2700|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_WORDPROCESSOR = 2701|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_EDITOR = 2702|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SPREADSHEET = 2703|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_GRAPHICSEDITOR = 2704|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PRESENTATION = 2705|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DATABASE = 2706|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_NEWS = 2707|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_VOICEMAIL = 2708|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ADDRESSBOOK = 2709|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MESSENGER = 2710|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BRIGHTNESS_TOGGLE = 2711|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SPELLCHECK = 2712|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_COFFEE = 2713|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MEDIA_REPEAT = 2714|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_IMAGES = 2715|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BUTTONCONFIG = 2716|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_TASKMANAGER = 2717|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_JOURNAL = 2718|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CONTROLPANEL = 2719|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_APPSELECT = 2720|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SCREENSAVER = 2721|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ASSISTANT = 2722|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBD_LAYOUT_NEXT = 2723|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BRIGHTNESS_MIN = 2724|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BRIGHTNESS_MAX = 2725|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDINPUTASSIST_PREV = 2726|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDINPUTASSIST_NEXT = 2727|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDINPUTASSIST_PREVGROUP = 2728|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDINPUTASSIST_NEXTGROUP = 2729|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDINPUTASSIST_ACCEPT = 2730|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_KBDINPUTASSIST_CANCEL = 2731|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_FRONT = 2800|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SETUP = 2801|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_WAKEUP = 2802|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SENDFILE = 2803|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DELETEFILE = 2804|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_XFER = 2805|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PROG1 = 2806|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PROG2 = 2807|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MSDOS = 2808|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SCREENLOCK = 2809|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DIRECTION_ROTATE_DISPLAY = 2810|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CYCLEWINDOWS = 2811|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_COMPUTER = 2812|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_EJECTCLOSECD = 2813|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ISO = 2814|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_MOVE = 2815|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F13 = 2816|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F14 = 2817|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F15 = 2818|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F16 = 2819|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F17 = 2820|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F18 = 2821|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F19 = 2822|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F20 = 2823|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F21 = 2824|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F22 = 2825|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F23 = 2826|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_F24 = 2827|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PROG3 = 2828|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_PROG4 = 2829|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_DASHBOARD = 2830|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SUSPEND = 2831|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_HP = 2832|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SOUND = 2833|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_QUESTION = 2834|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CONNECT = 2836|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SPORT = 2837|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SHOP = 2838|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_ALTERASE = 2839|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_SWITCHVIDEOMODE = 2841|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BATTERY = 2842|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BLUETOOTH = 2843|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_WLAN = 2844|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_UWB = 2845|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_WWAN_WIMAX = 2846|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_RFKILL = 2847|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_CHANNEL = 3001|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_0 = 3100|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_1 = 3101|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_2 = 3102|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_3 = 3103|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_4 = 3104|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_5 = 3105|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_6 = 3106|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_7 = 3107|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_8 = 3108|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：KeyCode;<br>方法or属性：KEYCODE_BTN_9 = 3109|@ohos.multimodalInput.keyCode.d.ts|
|新增|NA|类名：Action;<br>方法or属性：CANCEL = 0|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：DOWN = 1|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：UP = 2|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：Key;<br>方法or属性：code: KeyCode;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：Key;<br>方法or属性：pressedTime: number;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：Key;<br>方法or属性：deviceId: number;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：action: Action;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：key: Key;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：unicodeChar: number;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：keys: Key[];|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：ctrlKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：altKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：shiftKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：logoKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：fnKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：capsLock: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：numLock: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：scrollLock: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：CANCEL = 0|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：MOVE = 1|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：BUTTON_DOWN = 2|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：BUTTON_UP = 3|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：AXIS_BEGIN = 4|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：AXIS_UPDATE = 5|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：AXIS_END = 6|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Button;<br>方法or属性：LEFT = 0|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Button;<br>方法or属性：MIDDLE = 1|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Button;<br>方法or属性：RIGHT = 2|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Button;<br>方法or属性：SIDE = 3|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Button;<br>方法or属性：EXTRA = 4|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Button;<br>方法or属性：FORWARD = 5|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Button;<br>方法or属性：BACK = 6|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Button;<br>方法or属性：TASK = 7|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Axis;<br>方法or属性：SCROLL_VERTICAL = 0|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Axis;<br>方法or属性：SCROLL_HORIZONTAL = 1|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：Axis;<br>方法or属性：PINCH = 2|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：AxisValue;<br>方法or属性：axis: Axis;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：AxisValue;<br>方法or属性：value: number|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：action: Action;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：screenX: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：screenY: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：windowX: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：windowY: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：rawDeltaX: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：rawDeltaY: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：button: Button;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：pressedButtons: Button[];|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：axes: AxisValue[];|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：pressedKeys: KeyCode[];|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：ctrlKey: boolean;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：altKey: boolean;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：shiftKey: boolean;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：logoKey: boolean;|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：fnKey:boolean|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：capsLock:boolean|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：numLock:boolean|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：MouseEvent;<br>方法or属性：scrollLock:boolean|@ohos.multimodalInput.mouseEvent.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerSpeed(speed: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerSpeed(speed: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerSpeed(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerSpeed(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerStyle(windowId: number, pointerStyle: PointerStyle): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerStyle(windowId: number, callback: AsyncCallback\<PointerStyle>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerStyle(windowId: number): Promise\<PointerStyle>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerVisible(visible: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerVisible(visible: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function isPointerVisible(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function isPointerVisible(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：DEFAULT|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：WEST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：SOUTH|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：NORTH|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：WEST_EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：NORTH_SOUTH|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：NORTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：NORTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：SOUTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：SOUTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：NORTH_EAST_SOUTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：NORTH_WEST_SOUTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：CROSS|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：CURSOR_COPY|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：CURSOR_FORBID|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：COLOR_SUCKER|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：HAND_GRABBING|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：HAND_OPEN|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：HAND_POINTING|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：HELP|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MOVE|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：RESIZE_LEFT_RIGHT|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：RESIZE_UP_DOWN|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：SCREENSHOT_CHOOSE|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：SCREENSHOT_CURSOR|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：TEXT_CURSOR|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：ZOOM_IN|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：ZOOM_OUT|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_WEST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_SOUTH|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_NORTH|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_NORTH_SOUTH|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_NORTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_NORTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_SOUTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_SOUTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：MIDDLE_BTN_NORTH_SOUTH_WEST_EAST|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：Action;<br>方法or属性：CANCEL = 0|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：DOWN = 1|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：MOVE = 2|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Action;<br>方法or属性：UP = 3|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：ToolType;<br>方法or属性：FINGER = 0|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：ToolType;<br>方法or属性：PEN = 1|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：SourceType;<br>方法or属性：PEN = 1|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：ToolType;<br>方法or属性：RUBBER = 2|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：ToolType;<br>方法or属性：BRUSH = 3|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：ToolType;<br>方法or属性：PENCIL = 4|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：ToolType;<br>方法or属性：AIRBRUSH = 5|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：ToolType;<br>方法or属性：MOUSE = 6|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：ToolType;<br>方法or属性：LENS = 7|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：SourceType;<br>方法or属性：TOUCH_SCREEN = 0|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：SourceType;<br>方法or属性：TOUCH_PAD = 2|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：id: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：pressedTime: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：screenX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：screenY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：windowX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：windowY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：pressure: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：width: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：height: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：tiltX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：tiltY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：toolX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：toolY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：toolWidth: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：toolHeight: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：rawX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：rawY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：Touch;<br>方法or属性：toolType: ToolType;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：TouchEvent;<br>方法or属性：action: Action;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：TouchEvent;<br>方法or属性：touch: Touch;|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：TouchEvent;<br>方法or属性：touches: Touch[];|@ohos.multimodalInput.touchEvent.d.ts|
|新增|NA|类名：TouchEvent;<br>方法or属性：sourceType: SourceType;|@ohos.multimodalInput.touchEvent.d.ts|
|废弃版本有变化|类名：inputDevice;<br>方法or属性：function getDeviceIds(callback: AsyncCallback\<Array\<number>>): void;<br>旧版本信息：|类名：inputDevice;<br>方法or属性：function getDeviceIds(callback: AsyncCallback\<Array\<number>>): void;<br>新版本信息：9<br>代替接口： ohos.multimodalInput.inputDevice#getDeviceList|@ohos.multimodalInput.inputDevice.d.ts|
|废弃版本有变化|类名：inputDevice;<br>方法or属性：function getDeviceIds(): Promise\<Array\<number>>;<br>旧版本信息：|类名：inputDevice;<br>方法or属性：function getDeviceIds(): Promise\<Array\<number>>;<br>新版本信息：9<br>代替接口： ohos.multimodalInput.inputDevice#getDeviceList|@ohos.multimodalInput.inputDevice.d.ts|
|废弃版本有变化|类名：inputDevice;<br>方法or属性：function getDevice(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void;<br>旧版本信息：|类名：inputDevice;<br>方法or属性：function getDevice(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void;<br>新版本信息：9<br>代替接口： ohos.multimodalInput.inputDevice#getDeviceInfo|@ohos.multimodalInput.inputDevice.d.ts|
|废弃版本有变化|类名：inputDevice;<br>方法or属性：function getDevice(deviceId: number): Promise\<InputDeviceData>;<br>旧版本信息：|类名：inputDevice;<br>方法or属性：function getDevice(deviceId: number): Promise\<InputDeviceData>;<br>新版本信息：9<br>代替接口： ohos.multimodalInput.inputDevice#getDeviceInfo|@ohos.multimodalInput.inputDevice.d.ts|
|新增(错误码)|类名：inputConsumer;<br>方法or属性：function on(type: "key", keyOptions: KeyOptions, callback: Callback\<KeyOptions>): void;<br>旧版本信息：|类名：inputConsumer;<br>方法or属性：function on(type: "key", keyOptions: KeyOptions, callback: Callback\<KeyOptions>): void;<br>新版本信息：401|@ohos.multimodalInput.inputConsumer.d.ts|
|新增(错误码)|类名：inputConsumer;<br>方法or属性：function off(type: "key", keyOptions: KeyOptions, callback?: Callback\<KeyOptions>): void;<br>旧版本信息：|类名：inputConsumer;<br>方法or属性：function off(type: "key", keyOptions: KeyOptions, callback?: Callback\<KeyOptions>): void;<br>新版本信息：401|@ohos.multimodalInput.inputConsumer.d.ts|
|新增(错误码)|类名：inputEventClient;<br>方法or属性：function injectEvent({KeyEvent: KeyEvent}): void;<br>旧版本信息：|类名：inputEventClient;<br>方法or属性：function injectEvent({KeyEvent: KeyEvent}): void;<br>新版本信息：401|@ohos.multimodalInput.inputEventClient.d.ts|
|新增(错误码)|类名：inputMonitor;<br>方法or属性：function on(type:"touch", receiver:TouchEventReceiver):void;<br>旧版本信息：|类名：inputMonitor;<br>方法or属性：function on(type:"touch", receiver:TouchEventReceiver):void;<br>新版本信息：401,201|@ohos.multimodalInput.inputMonitor.d.ts|
|新增(错误码)|类名：inputMonitor;<br>方法or属性：function off(type:"touch", receiver?:TouchEventReceiver):void;<br>旧版本信息：|类名：inputMonitor;<br>方法or属性：function off(type:"touch", receiver?:TouchEventReceiver):void;<br>新版本信息：401,201|@ohos.multimodalInput.inputMonitor.d.ts|
|函数有变化|类名：inputDevice;<br>方法or属性：type AxisType = 'NULL';|类名：inputDevice;<br>方法or属性：type AxisType = 'touchMajor' \| 'touchMinor' \| 'orientation' \| 'x' \| 'y' \| 'pressure' \| 'toolMinor' \| 'toolMajor' \| 'NULL';|@ohos.multimodalInput.inputDevice.d.ts|
