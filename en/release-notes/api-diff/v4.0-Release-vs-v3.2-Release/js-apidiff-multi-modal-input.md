| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: Pinch;<br>Method or attribute name: type: ActionType;|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: ThreeFingersSwipe;<br>Method or attribute name: type: ActionType;|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: FourFingersSwipe;<br>Method or attribute name: type: ActionType;|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: Pinch;<br>Method or attribute name: scale: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: ThreeFingersSwipe;<br>Method or attribute name: x: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: FourFingersSwipe;<br>Method or attribute name: x: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: ThreeFingersSwipe;<br>Method or attribute name: y: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: FourFingersSwipe;<br>Method or attribute name: y: number;|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: ActionType;<br>Method or attribute name: CANCEL = 0|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: ActionType;<br>Method or attribute name: BEGIN = 1|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: ActionType;<br>Method or attribute name: UPDATE = 2|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: ActionType;<br>Method or attribute name: END = 3|@ohos.multimodalInput.gestureEvent.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getDeviceInfoSync(deviceId: number): InputDeviceData;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function supportKeysSync(deviceId: number, keys: Array\<KeyCode>): Array\<boolean>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getKeyboardTypeSync(deviceId: number): KeyboardType;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function setKeyboardRepeatDelay(delay: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function setKeyboardRepeatDelay(delay: number): Promise\<void>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getKeyboardRepeatDelay(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getKeyboardRepeatDelay(): Promise\<number>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function setKeyboardRepeatRate(rate: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function setKeyboardRepeatRate(rate: number): Promise\<void>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getKeyboardRepeatRate(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputDevice;<br>Method or attribute name: function getKeyboardRepeatRate(): Promise\<number>;|@ohos.multimodalInput.inputDevice.d.ts|
|Added|NA|Class name: inputMonitor;<br>Method or attribute name: function on(type: 'pinch', receiver: Callback\<Pinch>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|Added|NA|Class name: inputMonitor;<br>Method or attribute name: function on(type: 'threeFingersSwipe', receiver: Callback\<ThreeFingersSwipe>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|Added|NA|Class name: inputMonitor;<br>Method or attribute name: function on(type: 'fourFingersSwipe', receiver: Callback\<FourFingersSwipe>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|Added|NA|Class name: inputMonitor;<br>Method or attribute name: function off(type: 'pinch', receiver?: Callback\<Pinch>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|Added|NA|Class name: inputMonitor;<br>Method or attribute name: function off(type: 'threeFingersSwipe', receiver?: Callback\<ThreeFingersSwipe>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|Added|NA|Class name: inputMonitor;<br>Method or attribute name: function off(type: 'fourFingersSwipe', receiver?: Callback\<FourFingersSwipe>): void;|@ohos.multimodalInput.inputMonitor.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerSpeedSync(speed: number): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerSpeedSync(): number;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerStyleSync(windowId: number, pointerStyle: PointerStyle): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerStyleSync(windowId: number): PointerStyle;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerVisibleSync(visible: boolean): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function isPointerVisibleSync(): boolean;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerColor(color: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerColor(color: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerColorSync(color: number): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerColor(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerColor(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerColorSync(): number;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerSize(size: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerSize(size: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setPointerSizeSync(size: number): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerSize(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerSize(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getPointerSizeSync(): number;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setMousePrimaryButton(primary: PrimaryButton, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setMousePrimaryButton(primary: PrimaryButton): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getMousePrimaryButton(callback: AsyncCallback\<PrimaryButton>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getMousePrimaryButton(): Promise\<PrimaryButton>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setHoverScrollState(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setHoverScrollState(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getHoverScrollState(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getHoverScrollState(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setMouseScrollRows(rows: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setMouseScrollRows(rows: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getMouseScrollRows(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getMouseScrollRows(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadScrollSwitch(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadScrollSwitch(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadScrollSwitch(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadScrollSwitch(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadScrollDirection(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadScrollDirection(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadScrollDirection(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadScrollDirection(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadTapSwitch(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadTapSwitch(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadTapSwitch(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadTapSwitch(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadPointerSpeed(speed: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadPointerSpeed(speed: number): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadPointerSpeed(callback: AsyncCallback\<number>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadPointerSpeed(): Promise\<number>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadPinchSwitch(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadPinchSwitch(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadPinchSwitch(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadPinchSwitch(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadSwipeSwitch(state: boolean, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadSwipeSwitch(state: boolean): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadSwipeSwitch(callback: AsyncCallback\<boolean>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadSwipeSwitch(): Promise\<boolean>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadRightClickType(type: RightClickType, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function setTouchpadRightClickType(type: RightClickType): Promise\<void>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadRightClickType(callback: AsyncCallback\<RightClickType>): void;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: pointer;<br>Method or attribute name: function getTouchpadRightClickType(): Promise\<RightClickType>;|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: HORIZONTAL_TEXT_CURSOR|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: CURSOR_CROSS|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: CURSOR_CIRCLE|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: LOADING|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PointerStyle;<br>Method or attribute name: RUNNING|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PrimaryButton;<br>Method or attribute name: LEFT = 0|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: PrimaryButton;<br>Method or attribute name: RIGHT = 1|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: RightClickType;<br>Method or attribute name: TOUCHPAD_RIGHT_BUTTON = 1|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: RightClickType;<br>Method or attribute name: TOUCHPAD_LEFT_BUTTON = 2|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: RightClickType;<br>Method or attribute name: TOUCHPAD_TWO_FINGER_TAP = 3|@ohos.multimodalInput.pointer.d.ts|
|Added|NA|Class name: shortKey;<br>Method or attribute name: function setKeyDownDuration(businessKey: string, delay: number, callback: AsyncCallback\<void>): void;|@ohos.multimodalInput.shortKey.d.ts|
|Added|NA|Class name: shortKey;<br>Method or attribute name: function setKeyDownDuration(businessKey: string, delay: number): Promise\<void>;|@ohos.multimodalInput.shortKey.d.ts|
|Access level changed|Class name: KeyOptions;<br>Method or attribute name: preKeys: Array\<number>;<br>Old version information: |Class name: KeyOptions;<br>Method or attribute name: preKeys: Array\<number>;<br>New version information: systemapi|@ohos.multimodalInput.inputConsumer.d.ts|
|Access level changed|Class name: KeyOptions;<br>Method or attribute name: finalKey: number;<br>Old version information: |Class name: KeyOptions;<br>Method or attribute name: finalKey: number;<br>New version information: systemapi|@ohos.multimodalInput.inputConsumer.d.ts|
|Access level changed|Class name: KeyOptions;<br>Method or attribute name: isFinalKeyDown: boolean;<br>Old version information: |Class name: KeyOptions;<br>Method or attribute name: isFinalKeyDown: boolean;<br>New version information: systemapi|@ohos.multimodalInput.inputConsumer.d.ts|
|Access level changed|Class name: KeyOptions;<br>Method or attribute name: finalKeyDownDuration: number;<br>Old version information: |Class name: KeyOptions;<br>Method or attribute name: finalKeyDownDuration: number;<br>New version information: systemapi|@ohos.multimodalInput.inputConsumer.d.ts|
|Access level changed|Class name: KeyEvent;<br>Method or attribute name: isPressed: boolean;<br>Old version information: |Class name: KeyEvent;<br>Method or attribute name: isPressed: boolean;<br>New version information: systemapi|@ohos.multimodalInput.inputEventClient.d.ts|
|Access level changed|Class name: KeyEvent;<br>Method or attribute name: keyCode: number;<br>Old version information: |Class name: KeyEvent;<br>Method or attribute name: keyCode: number;<br>New version information: systemapi|@ohos.multimodalInput.inputEventClient.d.ts|
|Access level changed|Class name: KeyEvent;<br>Method or attribute name: keyDownDuration: number;<br>Old version information: |Class name: KeyEvent;<br>Method or attribute name: keyDownDuration: number;<br>New version information: systemapi|@ohos.multimodalInput.inputEventClient.d.ts|
|Access level changed|Class name: KeyEvent;<br>Method or attribute name: isIntercepted: boolean;<br>Old version information: |Class name: KeyEvent;<br>Method or attribute name: isIntercepted: boolean;<br>New version information: systemapi|@ohos.multimodalInput.inputEventClient.d.ts|
|Permission changed|Class name: TouchEventReceiver;<br>Method or attribute name: interface TouchEventReceiver<br>Old version information: |Class name: TouchEventReceiver;<br>Method or attribute name: interface TouchEventReceiver<br>New version information: ohos.permission.INPUT_MONITORING|@ohos.multimodalInput.inputMonitor.d.ts|
|Type changed|Class name: KeyOptions;<br>Method or attribute name: preKeys: Array\<number>;<br>Old version information: |Class name: KeyOptions;<br>Method or attribute name: preKeys: Array\<number>;<br>New version information: Array\<number>|@ohos.multimodalInput.inputConsumer.d.ts|
|Type changed|Class name: KeyOptions;<br>Method or attribute name: finalKey: number;<br>Old version information: |Class name: KeyOptions;<br>Method or attribute name: finalKey: number;<br>New version information: number|@ohos.multimodalInput.inputConsumer.d.ts|
|Type changed|Class name: KeyOptions;<br>Method or attribute name: isFinalKeyDown: boolean;<br>Old version information: |Class name: KeyOptions;<br>Method or attribute name: isFinalKeyDown: boolean;<br>New version information: boolean|@ohos.multimodalInput.inputConsumer.d.ts|
|Type changed|Class name: KeyOptions;<br>Method or attribute name: finalKeyDownDuration: number;<br>Old version information: |Class name: KeyOptions;<br>Method or attribute name: finalKeyDownDuration: number;<br>New version information: number|@ohos.multimodalInput.inputConsumer.d.ts|
|Type changed|Class name: DeviceListener;<br>Method or attribute name: type: ChangedType;<br>Old version information: |Class name: DeviceListener;<br>Method or attribute name: type: ChangedType;<br>New version information: ChangedType|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: DeviceListener;<br>Method or attribute name: deviceId: number;<br>Old version information: |Class name: DeviceListener;<br>Method or attribute name: deviceId: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: AxisRange;<br>Method or attribute name: source: SourceType;<br>Old version information: |Class name: AxisRange;<br>Method or attribute name: source: SourceType;<br>New version information: SourceType|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: AxisRange;<br>Method or attribute name: axis: AxisType;<br>Old version information: |Class name: AxisRange;<br>Method or attribute name: axis: AxisType;<br>New version information: AxisType|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: AxisRange;<br>Method or attribute name: max: number;<br>Old version information: |Class name: AxisRange;<br>Method or attribute name: max: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: AxisRange;<br>Method or attribute name: min: number;<br>Old version information: |Class name: AxisRange;<br>Method or attribute name: min: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: AxisRange;<br>Method or attribute name: fuzz: number;<br>Old version information: |Class name: AxisRange;<br>Method or attribute name: fuzz: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: AxisRange;<br>Method or attribute name: flat: number;<br>Old version information: |Class name: AxisRange;<br>Method or attribute name: flat: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: AxisRange;<br>Method or attribute name: resolution: number;<br>Old version information: |Class name: AxisRange;<br>Method or attribute name: resolution: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: id: number;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: id: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: name: string;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: name: string;<br>New version information: string|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: sources: Array\<SourceType>;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: sources: Array\<SourceType>;<br>New version information: Array\<SourceType>|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: axisRanges: Array\<AxisRange>;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: axisRanges: Array\<AxisRange>;<br>New version information: Array\<AxisRange>|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: bus: number;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: bus: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: product: number;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: product: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: vendor: number;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: vendor: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: version: number;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: version: number;<br>New version information: number|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: phys: string;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: phys: string;<br>New version information: string|@ohos.multimodalInput.inputDevice.d.ts|
|Type changed|Class name: InputDeviceData;<br>Method or attribute name: uniq: string;<br>Old version information: |Class name: InputDeviceData;<br>Method or attribute name: uniq: string;<br>New version information: string|@ohos.multimodalInput.inputDevice.d.ts|
|Function changed|Class name: inputDevice;<br>Method or attribute name: type AxisType = 'touchMajor' \| 'touchMinor' \| 'orientation' \| 'x' \| 'y' \| 'pressure' \| 'toolMinor' \| 'toolMajor' \| 'NULL';|Class name: inputDevice;<br>Method or attribute name: type AxisType =<br><br>    'touchmajor'<br><br>    \| 'touchminor'<br><br>    \| 'orientation'<br><br>    \| 'x'<br><br>    \| 'y'<br><br>    \| 'pressure'<br><br>    \| 'toolminor'<br><br>    \| 'toolmajor'<br><br>    \| 'null';|@ohos.multimodalInput.inputDevice.d.ts|
