| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: inputDevice;<br>Method or attribute name: type ChangedType = 'add' \| 'remove';|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function on(type: "change", listener: Callback\<DeviceListener>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function off(type: "change", listener?: Callback\<DeviceListener>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getDeviceList(callback: AsyncCallback\<Array\<number>>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getDeviceList(): Promise\<Array\<number>>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getDeviceInfo(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getDeviceInfo(deviceId: number): Promise\<InputDeviceData>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function supportKeys(deviceId: number, keys: Array\<KeyCode>, callback: AsyncCallback\<Array\<boolean>>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function supportKeys(deviceId: number, keys: Array\<KeyCode>): Promise\<Array\<boolean>>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getKeyboardType(deviceId: number, callback: AsyncCallback\<KeyboardType>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getKeyboardType(deviceId: number): Promise\<KeyboardType>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: KeyboardType;<br>Method or attribute name: NONE = 0|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: KeyboardType;<br>Method or attribute name: UNKNOWN = 1|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: KeyboardType;<br>Method or attribute name: ALPHABETIC_KEYBOARD = 2|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: KeyboardType;<br>Method or attribute name: DIGITAL_KEYBOARD = 3|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: KeyboardType;<br>Method or attribute name: HANDWRITING_PEN = 4|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: KeyboardType;<br>Method or attribute name: REMOTE_CONTROL = 5|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: DeviceListener;<br>Method or attribute name: type: ChangedType;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: DeviceListener;<br>Method or attribute name: deviceId: number;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: AxisRange;<br>Method or attribute name: fuzz: number;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: AxisRange;<br>Method or attribute name: flat: number;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: AxisRange;<br>Method or attribute name: resolution: number;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: InputDeviceData;<br>Method or attribute name: bus: number;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: InputDeviceData;<br>Method or attribute name: product: number;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: InputDeviceData;<br>Method or attribute name: vendor: number;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: InputDeviceData;<br>Method or attribute name: version: number;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: InputDeviceData;<br>Method or attribute name: phys: string;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: InputDeviceData;<br>Method or attribute name: uniq: string;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function enable(enable: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function enable(enable: boolean): Promise\<void>;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise\<void>;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function stop(callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function stop(): Promise\<void>;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function getState(deviceDescriptor: string, callback: AsyncCallback\<{ state: boolean }>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function getState(deviceDescriptor: string): Promise\<{ state: boolean }>;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function on(type: 'cooperation', callback: AsyncCallback\<{ deviceDescriptor: string, eventMsg: EventMsg }>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: inputDeviceCooperate;<br>Method or attribute name: function off(type: 'cooperation', callback?: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: EventMsg;<br>Method or attribute name: MSG_COOPERATE_INFO_START = 200|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: EventMsg;<br>Method or attribute name: MSG_COOPERATE_INFO_SUCCESS = 201|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: EventMsg;<br>Method or attribute name: MSG_COOPERATE_INFO_FAIL = 202|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: EventMsg;<br>Method or attribute name: MSG_COOPERATE_STATE_ON = 500|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: EventMsg;<br>Method or attribute name: MSG_COOPERATE_STATE_OFF = 501|@ohos.multimodalInput.inputDeviceCooperate.d.ts|
|Added|NA|Class name: InputEvent;<br>Method or attribute name: id: number;|@ohos.multimodalInput.inputEvent.d.ts|
|Added|NA|Class name: InputEvent;<br>Method or attribute name: deviceId: number;|@ohos.multimodalInput.inputEvent.d.ts|
|Added|NA|Class name: InputEvent;<br>Method or attribute name: actionTime: number;|@ohos.multimodalInput.inputEvent.d.ts|
|Added|NA|Class name: InputEvent;<br>Method or attribute name: screenId: number;|@ohos.multimodalInput.inputEvent.d.ts|
|Added|NA|Class name: InputEvent;<br>Method or attribute name: windowId: number;|@ohos.multimodalInput.inputEvent.d.ts|
|Added|NA|Class name: inputMonitor;<br>Method or attribute name: function on(type:"mouse", receiver:Callback\<MouseEvent>):void;|@ohos.multimodalInput.inputMonitor.d.ts|
|Added|NA|Class name: inputMonitor;<br>Method or attribute name: function off(type:"mouse", receiver?:Callback\<MouseEvent>):void;|@ohos.multimodalInput.inputMonitor.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FN = 0|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_UNKNOWN = -1|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_HOME = 1|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BACK = 2|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_PLAY_PAUSE = 10|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_STOP = 11|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_NEXT = 12|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_PREVIOUS = 13|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_REWIND = 14|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_FAST_FORWARD = 15|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VOLUME_UP = 16|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VOLUME_DOWN = 17|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_POWER = 18|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CAMERA = 19|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VOLUME_MUTE = 22|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MUTE = 23|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BRIGHTNESS_UP = 40|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BRIGHTNESS_DOWN = 41|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_0 = 2000|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_1 = 2001|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_2 = 2002|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_3 = 2003|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_4 = 2004|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_5 = 2005|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_6 = 2006|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_7 = 2007|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_8 = 2008|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_9 = 2009|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_STAR = 2010|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_POUND = 2011|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DPAD_UP = 2012|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DPAD_DOWN = 2013|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DPAD_LEFT = 2014|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DPAD_RIGHT = 2015|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DPAD_CENTER = 2016|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_A = 2017|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_B = 2018|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_C = 2019|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_D = 2020|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_E = 2021|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F = 2022|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_G = 2023|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_H = 2024|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_I = 2025|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_J = 2026|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_K = 2027|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_L = 2028|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_M = 2029|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_N = 2030|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_O = 2031|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_P = 2032|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_Q = 2033|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_R = 2034|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_S = 2035|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_T = 2036|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_U = 2037|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_V = 2038|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_W = 2039|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_X = 2040|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_Y = 2041|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_Z = 2042|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_COMMA = 2043|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PERIOD = 2044|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ALT_LEFT = 2045|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ALT_RIGHT = 2046|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SHIFT_LEFT = 2047|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SHIFT_RIGHT = 2048|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_TAB = 2049|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SPACE = 2050|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SYM = 2051|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_EXPLORER = 2052|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ENVELOPE = 2053|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ENTER = 2054|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DEL = 2055|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_GRAVE = 2056|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MINUS = 2057|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_EQUALS = 2058|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_LEFT_BRACKET = 2059|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_RIGHT_BRACKET = 2060|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BACKSLASH = 2061|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SEMICOLON = 2062|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_APOSTROPHE = 2063|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SLASH = 2064|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_AT = 2065|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PLUS = 2066|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MENU = 2067|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PAGE_UP = 2068|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PAGE_DOWN = 2069|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ESCAPE = 2070|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FORWARD_DEL = 2071|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CTRL_LEFT = 2072|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CTRL_RIGHT = 2073|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CAPS_LOCK = 2074|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SCROLL_LOCK = 2075|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_META_LEFT = 2076|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_META_RIGHT = 2077|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FUNCTION = 2078|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SYSRQ = 2079|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BREAK = 2080|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MOVE_HOME = 2081|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MOVE_END = 2082|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_INSERT = 2083|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FORWARD = 2084|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_PLAY = 2085|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_PAUSE = 2086|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_CLOSE = 2087|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_EJECT = 2088|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_RECORD = 2089|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F1 = 2090|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F2 = 2091|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F3 = 2092|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F4 = 2093|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F5 = 2094|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F6 = 2095|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F7 = 2096|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F8 = 2097|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F9 = 2098|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F10 = 2099|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F11 = 2100|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F12 = 2101|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUM_LOCK = 2102|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_0 = 2103|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_1 = 2104|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_2 = 2105|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_3 = 2106|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_4 = 2107|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_5 = 2108|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_6 = 2109|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_7 = 2110|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_8 = 2111|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_9 = 2112|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_DIVIDE = 2113|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_MULTIPLY = 2114|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_SUBTRACT = 2115|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_ADD = 2116|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_DOT = 2117|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_COMMA = 2118|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_ENTER = 2119|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_EQUALS = 2120|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_LEFT_PAREN = 2121|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_RIGHT_PAREN = 2122|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VIRTUAL_MULTITASK = 2210|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SLEEP = 2600|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ZENKAKU_HANKAKU = 2601|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_102ND = 2602|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_RO = 2603|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KATAKANA = 2604|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_HIRAGANA = 2605|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_HENKAN = 2606|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KATAKANA_HIRAGANA = 2607|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MUHENKAN = 2608|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_LINEFEED = 2609|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MACRO = 2610|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NUMPAD_PLUSMINUS = 2611|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SCALE = 2612|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_HANGUEL = 2613|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_HANJA = 2614|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_YEN = 2615|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_STOP = 2616|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_AGAIN = 2617|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PROPS = 2618|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_UNDO = 2619|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_COPY = 2620|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_OPEN = 2621|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PASTE = 2622|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FIND = 2623|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CUT = 2624|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_HELP = 2625|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CALC = 2626|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FILE = 2627|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BOOKMARKS = 2628|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NEXT = 2629|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PLAYPAUSE = 2630|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PREVIOUS = 2631|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_STOPCD = 2632|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CONFIG = 2634|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_REFRESH = 2635|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_EXIT = 2636|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_EDIT = 2637|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SCROLLUP = 2638|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SCROLLDOWN = 2639|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NEW = 2640|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_REDO = 2641|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CLOSE = 2642|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PLAY = 2643|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BASSBOOST = 2644|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PRINT = 2645|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CHAT = 2646|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FINANCE = 2647|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CANCEL = 2648|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDILLUM_TOGGLE = 2649|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDILLUM_DOWN = 2650|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDILLUM_UP = 2651|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SEND = 2652|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_REPLY = 2653|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FORWARDMAIL = 2654|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SAVE = 2655|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DOCUMENTS = 2656|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VIDEO_NEXT = 2657|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VIDEO_PREV = 2658|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BRIGHTNESS_CYCLE = 2659|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BRIGHTNESS_ZERO = 2660|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DISPLAY_OFF = 2661|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_MISC = 2662|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_GOTO = 2663|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_INFO = 2664|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PROGRAM = 2665|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PVR = 2666|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SUBTITLE = 2667|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FULL_SCREEN = 2668|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KEYBOARD = 2669|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ASPECT_RATIO = 2670|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PC = 2671|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_TV = 2672|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_TV2 = 2673|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VCR = 2674|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VCR2 = 2675|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SAT = 2676|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CD = 2677|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_TAPE = 2678|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_TUNER = 2679|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PLAYER = 2680|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DVD = 2681|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_AUDIO = 2682|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VIDEO = 2683|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEMO = 2684|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CALENDAR = 2685|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_RED = 2686|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_GREEN = 2687|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_YELLOW = 2688|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BLUE = 2689|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CHANNELUP = 2690|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CHANNELDOWN = 2691|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_LAST = 2692|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_RESTART = 2693|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SLOW = 2694|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SHUFFLE = 2695|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VIDEOPHONE = 2696|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_GAMES = 2697|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ZOOMIN = 2698|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ZOOMOUT = 2699|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ZOOMRESET = 2700|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_WORDPROCESSOR = 2701|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_EDITOR = 2702|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SPREADSHEET = 2703|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_GRAPHICSEDITOR = 2704|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PRESENTATION = 2705|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DATABASE = 2706|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_NEWS = 2707|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_VOICEMAIL = 2708|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ADDRESSBOOK = 2709|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MESSENGER = 2710|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BRIGHTNESS_TOGGLE = 2711|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SPELLCHECK = 2712|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_COFFEE = 2713|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MEDIA_REPEAT = 2714|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_IMAGES = 2715|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BUTTONCONFIG = 2716|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_TASKMANAGER = 2717|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_JOURNAL = 2718|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CONTROLPANEL = 2719|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_APPSELECT = 2720|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SCREENSAVER = 2721|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ASSISTANT = 2722|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBD_LAYOUT_NEXT = 2723|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BRIGHTNESS_MIN = 2724|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BRIGHTNESS_MAX = 2725|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDINPUTASSIST_PREV = 2726|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDINPUTASSIST_NEXT = 2727|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDINPUTASSIST_PREVGROUP = 2728|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDINPUTASSIST_NEXTGROUP = 2729|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDINPUTASSIST_ACCEPT = 2730|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_KBDINPUTASSIST_CANCEL = 2731|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_FRONT = 2800|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SETUP = 2801|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_WAKEUP = 2802|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SENDFILE = 2803|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DELETEFILE = 2804|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_XFER = 2805|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PROG1 = 2806|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PROG2 = 2807|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MSDOS = 2808|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SCREENLOCK = 2809|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DIRECTION_ROTATE_DISPLAY = 2810|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CYCLEWINDOWS = 2811|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_COMPUTER = 2812|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_EJECTCLOSECD = 2813|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ISO = 2814|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_MOVE = 2815|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F13 = 2816|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F14 = 2817|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F15 = 2818|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F16 = 2819|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F17 = 2820|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F18 = 2821|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F19 = 2822|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F20 = 2823|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F21 = 2824|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F22 = 2825|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F23 = 2826|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_F24 = 2827|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PROG3 = 2828|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_PROG4 = 2829|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_DASHBOARD = 2830|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SUSPEND = 2831|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_HP = 2832|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SOUND = 2833|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_QUESTION = 2834|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CONNECT = 2836|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SPORT = 2837|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SHOP = 2838|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_ALTERASE = 2839|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_SWITCHVIDEOMODE = 2841|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BATTERY = 2842|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BLUETOOTH = 2843|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_WLAN = 2844|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_UWB = 2845|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_WWAN_WIMAX = 2846|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_RFKILL = 2847|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_CHANNEL = 3001|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_0 = 3100|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_1 = 3101|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_2 = 3102|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_3 = 3103|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_4 = 3104|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_5 = 3105|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_6 = 3106|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_7 = 3107|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_8 = 3108|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: KeyCode;<br>Method or attribute name: KEYCODE_BTN_9 = 3109|@ohos.multimodalInput.keyCode.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: CANCEL = 0|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: DOWN = 1|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: UP = 2|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: Key;<br>Method or attribute name: code: KeyCode;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: Key;<br>Method or attribute name: pressedTime: number;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: Key;<br>Method or attribute name: deviceId: number;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: action: Action;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: key: Key;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: unicodeChar: number;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: keys: Key[];|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: ctrlKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: altKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: shiftKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: logoKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: fnKey: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: capsLock: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: numLock: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: KeyEvent;<br>Method or attribute name: scrollLock: boolean;|@ohos.multimodalInput.keyEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: CANCEL = 0|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: MOVE = 1|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: BUTTON_DOWN = 2|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: BUTTON_UP = 3|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: AXIS_BEGIN = 4|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: AXIS_UPDATE = 5|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: AXIS_END = 6|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Button;<br>Method or attribute name: LEFT = 0|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Button;<br>Method or attribute name: MIDDLE = 1|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Button;<br>Method or attribute name: RIGHT = 2|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Button;<br>Method or attribute name: SIDE = 3|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Button;<br>Method or attribute name: EXTRA = 4|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Button;<br>Method or attribute name: FORWARD = 5|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Button;<br>Method or attribute name: BACK = 6|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Button;<br>Method or attribute name: TASK = 7|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Axis;<br>Method or attribute name: SCROLL_VERTICAL = 0|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Axis;<br>Method or attribute name: SCROLL_HORIZONTAL = 1|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: Axis;<br>Method or attribute name: PINCH = 2|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: AxisValue;<br>Method or attribute name: axis: Axis;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: AxisValue;<br>Method or attribute name: value: number|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: action: Action;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: screenX: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: screenY: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: windowX: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: windowY: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: rawDeltaX: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: rawDeltaY: number;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: button: Button;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: pressedButtons: Button[];|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: axes: AxisValue[];|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: pressedKeys: KeyCode[];|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: ctrlKey: boolean;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: altKey: boolean;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: shiftKey: boolean;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: logoKey: boolean;|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: fnKey:boolean|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: capsLock:boolean|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: numLock:boolean|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: MouseEvent;<br>Method or attribute name: scrollLock:boolean|@ohos.multimodalInput.mouseEvent.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerSpeed(speed: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerSpeed(speed: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerSpeed(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerSpeed(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerStyle(windowId: number, pointerStyle: PointerStyle): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerStyle(windowId: number, callback: AsyncCallback\<PointerStyle>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerStyle(windowId: number): Promise\<PointerStyle>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerVisible(visible: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerVisible(visible: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function isPointerVisible(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function isPointerVisible(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: DEFAULT|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: WEST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: SOUTH|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: NORTH|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: WEST_EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: NORTH_SOUTH|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: NORTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: NORTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: SOUTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: SOUTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: NORTH_EAST_SOUTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: NORTH_WEST_SOUTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: CROSS|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: CURSOR_COPY|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: CURSOR_FORBID|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: COLOR_SUCKER|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: HAND_GRABBING|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: HAND_OPEN|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: HAND_POINTING|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: HELP|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MOVE|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: RESIZE_LEFT_RIGHT|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: RESIZE_UP_DOWN|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: SCREENSHOT_CHOOSE|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: SCREENSHOT_CURSOR|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: TEXT_CURSOR|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: ZOOM_IN|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: ZOOM_OUT|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_WEST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_SOUTH|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_NORTH|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_NORTH_SOUTH|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_NORTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_NORTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_SOUTH_EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_SOUTH_WEST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: MIDDLE_BTN_NORTH_SOUTH_WEST_EAST|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: CANCEL = 0|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: DOWN = 1|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: MOVE = 2|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Action;<br>Method or attribute name: UP = 3|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: ToolType;<br>Method or attribute name: FINGER = 0|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: ToolType;<br>Method or attribute name: PEN = 1|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: SourceType;<br>Method or attribute name: PEN = 1|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: ToolType;<br>Method or attribute name: RUBBER = 2|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: ToolType;<br>Method or attribute name: BRUSH = 3|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: ToolType;<br>Method or attribute name: PENCIL = 4|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: ToolType;<br>Method or attribute name: AIRBRUSH = 5|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: ToolType;<br>Method or attribute name: MOUSE = 6|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: ToolType;<br>Method or attribute name: LENS = 7|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: SourceType;<br>Method or attribute name: TOUCH_SCREEN = 0|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: SourceType;<br>Method or attribute name: TOUCH_PAD = 2|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: id: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: pressedTime: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: screenX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: screenY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: windowX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: windowY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: pressure: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: width: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: height: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: tiltX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: tiltY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: toolX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: toolY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: toolWidth: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: toolHeight: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: rawX: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: rawY: number;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: Touch;<br>Method or attribute name: toolType: ToolType;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: TouchEvent;<br>Method or attribute name: action: Action;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: TouchEvent;<br>Method or attribute name: touch: Touch;|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: TouchEvent;<br>Method or attribute name: touches: Touch[];|@ohos.multimodalInput.touchEvent.d.ts|
|Added|NA|Class name: TouchEvent;<br>Method or attribute name: sourceType: SourceType;|@ohos.multimodalInput.touchEvent.d.ts|
|Deprecated version changed|Class name: inputDevice;<br>Method or attribute name: function getDeviceIds(callback: AsyncCallback\<Array\<number>>): void;<br>Old version: |Class name: inputDevice;<br>Method or attribute name: function getDeviceIds(callback: AsyncCallback\<Array\<number>>): void;<br>New version: 9<br>Substitute API: ohos.multimodalInput.inputDevice#getDeviceList|@ohos.multimodalInput.inputDevice.d.ts|
|Deprecated version changed|Class name: inputDevice;<br>Method or attribute name: function getDeviceIds(): Promise\<Array\<number>>;<br>Old version: |Class name: inputDevice;<br>Method or attribute name: function getDeviceIds(): Promise\<Array\<number>>;<br>New version: 9<br>Substitute API: ohos.multimodalInput.inputDevice#getDeviceList|@ohos.multimodalInput.inputDevice.d.ts|
|Deprecated version changed|Class name: inputDevice;<br>Method or attribute name: function getDevice(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void;<br>Old version: |Class name: inputDevice;<br>Method or attribute name: function getDevice(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void;<br>New version: 9<br>Substitute API: ohos.multimodalInput.inputDevice#getDeviceInfo|@ohos.multimodalInput.inputDevice.d.ts|
|Deprecated version changed|Class name: inputDevice;<br>Method or attribute name: function getDevice(deviceId: number): Promise\<InputDeviceData>;<br>Old version: |Class name: inputDevice;<br>Method or attribute name: function getDevice(deviceId: number): Promise\<InputDeviceData>;<br>New version: 9<br>Substitute API: ohos.multimodalInput.inputDevice#getDeviceInfo|@ohos.multimodalInput.inputDevice.d.ts|
|Error code added|Class name: inputConsumer;<br>Method or attribute name: function on(type: "key", keyOptions: KeyOptions, callback: Callback\<KeyOptions>): void;<br>Old version: |Class name: inputConsumer;<br>Method or attribute name: function on(type: "key", keyOptions: KeyOptions, callback: Callback\<KeyOptions>): void;<br>New version: 401|@ohos.multimodalInput.inputConsumer.d.ts|
|Error code added|Class name: inputConsumer;<br>Method or attribute name: function off(type: "key", keyOptions: KeyOptions, callback?: Callback\<KeyOptions>): void;<br>Old version: |Class name: inputConsumer;<br>Method or attribute name: function off(type: "key", keyOptions: KeyOptions, callback?: Callback\<KeyOptions>): void;<br>New version: 401|@ohos.multimodalInput.inputConsumer.d.ts|
|Error code added|Class name: inputEventClient;<br>Method or attribute name: function injectEvent({KeyEvent: KeyEvent}): void;<br>Old version: |Class name: inputEventClient;<br>Method or attribute name: function injectEvent({KeyEvent: KeyEvent}): void;<br>New version: 401|@ohos.multimodalInput.inputEventClient.d.ts|
|Error code added|Class name: inputMonitor;<br>Method or attribute name: function on(type:"touch", receiver:TouchEventReceiver):void;<br>Old version: |Class name: inputMonitor;<br>Method or attribute name: function on(type:"touch", receiver:TouchEventReceiver):void;<br>New version: 401,201|@ohos.multimodalInput.inputMonitor.d.ts|
|Error code added|Class name: inputMonitor;<br>Method or attribute name: function off(type:"touch", receiver?:TouchEventReceiver):void;<br>Old version: |Class name: inputMonitor;<br>Method or attribute name: function off(type:"touch", receiver?:TouchEventReceiver):void;<br>New version: 401,201|@ohos.multimodalInput.inputMonitor.d.ts|
|Function changed|Class name: inputDevice;<br>Method or attribute name: type AxisType = 'NULL';|Class name: inputDevice;<br>Method or attribute name: type AxisType = 'touchMajor' \| 'touchMinor' \| 'orientation' \| 'x' \| 'y' \| 'pressure' \| 'toolMinor' \| 'toolMajor' \| 'NULL';|@ohos.multimodalInput.inputDevice.d.ts|
