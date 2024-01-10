| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：Pinch;<br>方法or属性：type: ActionType;|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：ThreeFingersSwipe;<br>方法or属性：type: ActionType;|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：FourFingersSwipe;<br>方法or属性：type: ActionType;|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：Pinch;<br>方法or属性：scale: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：ThreeFingersSwipe;<br>方法or属性：x: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：FourFingersSwipe;<br>方法or属性：x: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：ThreeFingersSwipe;<br>方法or属性：y: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：FourFingersSwipe;<br>方法or属性：y: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：ActionType;<br>方法or属性：CANCEL = 0|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：ActionType;<br>方法or属性：BEGIN = 1|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：ActionType;<br>方法or属性：UPDATE = 2|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：ActionType;<br>方法or属性：END = 3|@ohos.multimodalInput.gestureEvent.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getDeviceInfoSync(deviceId: number): InputDeviceData;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function supportKeysSync(deviceId: number, keys: Array\<KeyCode>): Array\<boolean>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getKeyboardTypeSync(deviceId: number): KeyboardType;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function setKeyboardRepeatDelay(delay: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function setKeyboardRepeatDelay(delay: number): Promise\<void>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getKeyboardRepeatDelay(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getKeyboardRepeatDelay(): Promise\<number>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function setKeyboardRepeatRate(rate: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function setKeyboardRepeatRate(rate: number): Promise\<void>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getKeyboardRepeatRate(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputDevice;<br>方法or属性：function getKeyboardRepeatRate(): Promise\<number>;|@ohos.multimodalInput.inputDevice.d.ts|
|新增|NA|类名：inputMonitor;<br>方法or属性：function on(type: 'pinch', receiver: Callback\<Pinch>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|新增|NA|类名：inputMonitor;<br>方法or属性：function on(type: 'threeFingersSwipe', receiver: Callback\<ThreeFingersSwipe>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|新增|NA|类名：inputMonitor;<br>方法or属性：function on(type: 'fourFingersSwipe', receiver: Callback\<FourFingersSwipe>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|新增|NA|类名：inputMonitor;<br>方法or属性：function off(type: 'pinch', receiver?: Callback\<Pinch>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|新增|NA|类名：inputMonitor;<br>方法or属性：function off(type: 'threeFingersSwipe', receiver?: Callback\<ThreeFingersSwipe>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|新增|NA|类名：inputMonitor;<br>方法or属性：function off(type: 'fourFingersSwipe', receiver?: Callback\<FourFingersSwipe>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerSpeedSync(speed: number): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerSpeedSync(): number;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerStyleSync(windowId: number, pointerStyle: PointerStyle): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerStyleSync(windowId: number): PointerStyle;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerVisibleSync(visible: boolean): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function isPointerVisibleSync(): boolean;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerColor(color: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerColor(color: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerColorSync(color: number): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerColor(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerColor(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerColorSync(): number;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerSize(size: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerSize(size: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setPointerSizeSync(size: number): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerSize(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerSize(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getPointerSizeSync(): number;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setMousePrimaryButton(primary: PrimaryButton, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setMousePrimaryButton(primary: PrimaryButton): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getMousePrimaryButton(callback: AsyncCallback\<PrimaryButton>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getMousePrimaryButton(): Promise\<PrimaryButton>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setHoverScrollState(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setHoverScrollState(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getHoverScrollState(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getHoverScrollState(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setMouseScrollRows(rows: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setMouseScrollRows(rows: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getMouseScrollRows(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getMouseScrollRows(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadScrollSwitch(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadScrollSwitch(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadScrollSwitch(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadScrollSwitch(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadScrollDirection(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadScrollDirection(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadScrollDirection(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadScrollDirection(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadTapSwitch(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadTapSwitch(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadTapSwitch(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadTapSwitch(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadPointerSpeed(speed: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadPointerSpeed(speed: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadPointerSpeed(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadPointerSpeed(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadPinchSwitch(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadPinchSwitch(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadPinchSwitch(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadPinchSwitch(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadSwipeSwitch(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadSwipeSwitch(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadSwipeSwitch(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadSwipeSwitch(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadRightClickType(type: RightClickType, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function setTouchpadRightClickType(type: RightClickType): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadRightClickType(callback: AsyncCallback\<RightClickType>): void;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：pointer;<br>方法or属性：function getTouchpadRightClickType(): Promise\<RightClickType>;|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：HORIZONTAL_TEXT_CURSOR|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：CURSOR_CROSS|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：CURSOR_CIRCLE|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：LOADING|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PointerStyle;<br>方法or属性：RUNNING|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PrimaryButton;<br>方法or属性：LEFT = 0|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：PrimaryButton;<br>方法or属性：RIGHT = 1|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：RightClickType;<br>方法or属性：TOUCHPAD_RIGHT_BUTTON = 1|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：RightClickType;<br>方法or属性：TOUCHPAD_LEFT_BUTTON = 2|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：RightClickType;<br>方法or属性：TOUCHPAD_TWO_FINGER_TAP = 3|@ohos.multimodalInput.pointer.d.ts|
|新增|NA|类名：shortKey;<br>方法or属性：function setKeyDownDuration(businessKey: string, delay: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.shortKey.d.ts|
|新增|NA|类名：shortKey;<br>方法or属性：function setKeyDownDuration(businessKey: string, delay: number): Promise\<void>;|@ohos.multimodalInput.shortKey.d.ts|
|访问级别有变化|类名：KeyOptions;<br>方法or属性：preKeys: Array\<number>;<br>旧版本信息：|类名：KeyOptions;<br>方法or属性：preKeys: Array\<number>;<br>新版本信息：systemapi|@ohos.multimodalInput.inputConsumer.d.ts|
|访问级别有变化|类名：KeyOptions;<br>方法or属性：finalKey: number;<br>旧版本信息：|类名：KeyOptions;<br>方法or属性：finalKey: number;<br>新版本信息：systemapi|@ohos.multimodalInput.inputConsumer.d.ts|
|访问级别有变化|类名：KeyOptions;<br>方法or属性：isFinalKeyDown: boolean;<br>旧版本信息：|类名：KeyOptions;<br>方法or属性：isFinalKeyDown: boolean;<br>新版本信息：systemapi|@ohos.multimodalInput.inputConsumer.d.ts|
|访问级别有变化|类名：KeyOptions;<br>方法or属性：finalKeyDownDuration: number;<br>旧版本信息：|类名：KeyOptions;<br>方法or属性：finalKeyDownDuration: number;<br>新版本信息：systemapi|@ohos.multimodalInput.inputConsumer.d.ts|
|访问级别有变化|类名：KeyEvent;<br>方法or属性：isPressed: boolean;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：isPressed: boolean;<br>新版本信息：systemapi|@ohos.multimodalInput.inputEventClient.d.ts|
|访问级别有变化|类名：KeyEvent;<br>方法or属性：keyCode: number;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：keyCode: number;<br>新版本信息：systemapi|@ohos.multimodalInput.inputEventClient.d.ts|
|访问级别有变化|类名：KeyEvent;<br>方法or属性：keyDownDuration: number;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：keyDownDuration: number;<br>新版本信息：systemapi|@ohos.multimodalInput.inputEventClient.d.ts|
|访问级别有变化|类名：KeyEvent;<br>方法or属性：isIntercepted: boolean;<br>旧版本信息：|类名：KeyEvent;<br>方法or属性：isIntercepted: boolean;<br>新版本信息：systemapi|@ohos.multimodalInput.inputEventClient.d.ts|
|权限有变化|类名：TouchEventReceiver;<br>方法or属性：interface TouchEventReceiver<br>旧版本信息：|类名：TouchEventReceiver;<br>方法or属性：interface TouchEventReceiver<br>新版本信息：ohos.permission.INPUT_MONITORING|@ohos.multimodalInput.inputMonitor.d.ts|
|type有变化|类名：KeyOptions;<br>方法or属性：preKeys: Array\<number>;<br>旧版本信息：|类名：KeyOptions;<br>方法or属性：preKeys: Array\<number>;<br>新版本信息：Array\<number>|@ohos.multimodalInput.inputConsumer.d.ts|
|type有变化|类名：KeyOptions;<br>方法or属性：finalKey: number;<br>旧版本信息：|类名：KeyOptions;<br>方法or属性：finalKey: number;<br>新版本信息：number|@ohos.multimodalInput.inputConsumer.d.ts|
|type有变化|类名：KeyOptions;<br>方法or属性：isFinalKeyDown: boolean;<br>旧版本信息：|类名：KeyOptions;<br>方法or属性：isFinalKeyDown: boolean;<br>新版本信息：boolean|@ohos.multimodalInput.inputConsumer.d.ts|
|type有变化|类名：KeyOptions;<br>方法or属性：finalKeyDownDuration: number;<br>旧版本信息：|类名：KeyOptions;<br>方法or属性：finalKeyDownDuration: number;<br>新版本信息：number|@ohos.multimodalInput.inputConsumer.d.ts|
|type有变化|类名：DeviceListener;<br>方法or属性：type: ChangedType;<br>旧版本信息：|类名：DeviceListener;<br>方法or属性：type: ChangedType;<br>新版本信息：ChangedType|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：DeviceListener;<br>方法or属性：deviceId: number;<br>旧版本信息：|类名：DeviceListener;<br>方法or属性：deviceId: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：AxisRange;<br>方法or属性：source: SourceType;<br>旧版本信息：|类名：AxisRange;<br>方法or属性：source: SourceType;<br>新版本信息：SourceType|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：AxisRange;<br>方法or属性：axis: AxisType;<br>旧版本信息：|类名：AxisRange;<br>方法or属性：axis: AxisType;<br>新版本信息：AxisType|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：AxisRange;<br>方法or属性：max: number;<br>旧版本信息：|类名：AxisRange;<br>方法or属性：max: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：AxisRange;<br>方法or属性：min: number;<br>旧版本信息：|类名：AxisRange;<br>方法or属性：min: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：AxisRange;<br>方法or属性：fuzz: number;<br>旧版本信息：|类名：AxisRange;<br>方法or属性：fuzz: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：AxisRange;<br>方法or属性：flat: number;<br>旧版本信息：|类名：AxisRange;<br>方法or属性：flat: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：AxisRange;<br>方法or属性：resolution: number;<br>旧版本信息：|类名：AxisRange;<br>方法or属性：resolution: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：id: number;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：id: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：name: string;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：name: string;<br>新版本信息：string|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：sources: Array\<SourceType>;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：sources: Array\<SourceType>;<br>新版本信息：Array\<SourceType>|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：axisRanges: Array\<AxisRange>;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：axisRanges: Array\<AxisRange>;<br>新版本信息：Array\<AxisRange>|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：bus: number;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：bus: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：product: number;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：product: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：vendor: number;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：vendor: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：version: number;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：version: number;<br>新版本信息：number|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：phys: string;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：phys: string;<br>新版本信息：string|@ohos.multimodalInput.inputDevice.d.ts|
|type有变化|类名：InputDeviceData;<br>方法or属性：uniq: string;<br>旧版本信息：|类名：InputDeviceData;<br>方法or属性：uniq: string;<br>新版本信息：string|@ohos.multimodalInput.inputDevice.d.ts|
|函数有变化|类名：inputDevice;<br>方法or属性：type AxisType = 'touchMajor' \| 'touchMinor' \| 'orientation' \| 'x' \| 'y' \| 'pressure' \| 'toolMinor' \| 'toolMajor' \| 'NULL';|类名：inputDevice;<br>方法or属性：type AxisType =<br><br>    'touchmajor'<br><br>    \| 'touchminor'<br><br>    \| 'orientation'<br><br>    \| 'x'<br><br>    \| 'y'<br><br>    \| 'pressure'<br><br>    \| 'toolminor'<br><br>    \| 'toolmajor'<br><br>    \| 'null';|@ohos.multimodalInput.inputDevice.d.ts|
