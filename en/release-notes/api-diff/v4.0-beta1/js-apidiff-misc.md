| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: InputMethodSetting<br>Method or attribute name: on(type: 'imeShow' \| 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodSetting<br>Method or attribute name: off(type: 'imeShow' \| 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: attach(showKeyboard: boolean, textConfig: TextConfig, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: attach(showKeyboard: boolean, textConfig: TextConfig): Promise\<void>;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: showTextInput(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: showTextInput(): Promise\<void>;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: hideTextInput(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: hideTextInput(): Promise\<void>;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: detach(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: detach(): Promise\<void>;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: setCallingWindow(windowId: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: setCallingWindow(windowId: number): Promise\<void>;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: updateCursor(cursorInfo: CursorInfo, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: updateCursor(cursorInfo: CursorInfo): Promise\<void>;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: changeSelection(text: string, start: number, end: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: changeSelection(text: string, start: number, end: number): Promise\<void>;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: updateAttribute(attribute: InputAttribute, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: updateAttribute(attribute: InputAttribute): Promise\<void>;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: on(type: 'selectByRange', callback: Callback\<Range>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: on(type: 'selectByMovement', callback: Callback\<Movement>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: off(type: 'selectByRange'): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: off(type: 'selectByMovement'): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: on(type: 'insertText', callback: (text: string) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: off(type: 'insertText'): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: on(type: 'deleteLeft' \| 'deleteRight', callback: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: off(type: 'deleteLeft' \| 'deleteRight'): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: on(type: 'sendKeyboardStatus', callback: (keyBoardStatus: KeyboardStatus) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: off(type: 'sendKeyboardStatus'): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: on(type: 'sendFunctionKey', callback: (functionKey: FunctionKey) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: off(type: 'sendFunctionKey'): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: on(type: 'moveCursor', callback: (direction: Direction) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: off(type: 'moveCursor'): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: on(type: 'handleExtendAction', callback: (action: ExtendAction) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController<br>Method or attribute name: off(type: 'handleExtendAction'): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodProperty<br>Method or attribute name: readonly labelId?: number;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodProperty<br>Method or attribute name: extra?: object;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Direction|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Direction<br>Method or attribute name: CURSOR_UP = 1|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Direction<br>Method or attribute name: CURSOR_DOWN|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Direction<br>Method or attribute name: CURSOR_LEFT|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Direction<br>Method or attribute name: CURSOR_RIGHT|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Range|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Range<br>Method or attribute name: start: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Range<br>Method or attribute name: end: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Movement|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: Movement<br>Method or attribute name: direction: Direction;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: NONE = -1|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: TEXT = 0|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: MULTILINE|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: NUMBER|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: PHONE|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: DATETIME|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: EMAIL_ADDRESS|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: URL|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextInputType<br>Method or attribute name: VISIBLE_PASSWORD|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType<br>Method or attribute name: UNSPECIFIED = 0|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType<br>Method or attribute name: NONE|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType<br>Method or attribute name: GO|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType<br>Method or attribute name: SEARCH|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType<br>Method or attribute name: SEND|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType<br>Method or attribute name: NEXT|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType<br>Method or attribute name: DONE|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: EnterKeyType<br>Method or attribute name: PREVIOUS|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: KeyboardStatus|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: KeyboardStatus<br>Method or attribute name: NONE = 0|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: KeyboardStatus<br>Method or attribute name: HIDE = 1|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: KeyboardStatus<br>Method or attribute name: SHOW = 2|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputAttribute|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputAttribute<br>Method or attribute name: textInputType: TextInputType;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputAttribute<br>Method or attribute name: enterKeyType: EnterKeyType;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: FunctionKey|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: FunctionKey<br>Method or attribute name: enterKeyType: EnterKeyType;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: CursorInfo|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: CursorInfo<br>Method or attribute name: left: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: CursorInfo<br>Method or attribute name: top: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: CursorInfo<br>Method or attribute name: width: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: CursorInfo<br>Method or attribute name: height: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextConfig|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: TextConfig<br>Method or attribute name: inputAttribute: InputAttribute;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: ExtendAction|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: ExtendAction<br>Method or attribute name: SELECT_ALL = 0|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: ExtendAction<br>Method or attribute name: CUT = 3|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: ExtendAction<br>Method or attribute name: COPY = 4|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: ExtendAction<br>Method or attribute name: PASTE = 5|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputWindowInfo|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputWindowInfo<br>Method or attribute name: name: string;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputWindowInfo<br>Method or attribute name: left: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputWindowInfo<br>Method or attribute name: top: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputWindowInfo<br>Method or attribute name: width: number;|@ohos.inputMethod.d.ts|
|Added|NA|Module name: ohos.inputMethod<br>Class name: InputWindowInfo<br>Method or attribute name: height: number;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodAbility<br>Method or attribute name: createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Class name: InputMethodAbility<br>Method or attribute name: createPanel(ctx: BaseContext, info: PanelInfo): Promise\<Panel>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Class name: InputMethodAbility<br>Method or attribute name: destroyPanel(panel: Panel, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Class name: InputMethodAbility<br>Method or attribute name: destroyPanel(panel: Panel): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: InputClient<br>Method or attribute name: selectByRange(range: Range, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: InputClient<br>Method or attribute name: selectByRange(range: Range): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: InputClient<br>Method or attribute name: selectByMovement(movement: Movement, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: InputClient<br>Method or attribute name: selectByMovement(movement: Movement): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: InputClient<br>Method or attribute name: getTextIndexAtCursor(callback: AsyncCallback\<number>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: InputClient<br>Method or attribute name: getTextIndexAtCursor(): Promise\<number>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: InputClient<br>Method or attribute name: sendExtendAction(action: ExtendAction, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: InputClient<br>Method or attribute name: sendExtendAction(action: ExtendAction): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: setUiContent(path: string, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: setUiContent(path: string): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: setUiContent(path: string, storage: LocalStorage): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: resize(width: number, height: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: resize(width: number, height: number): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: moveTo(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: moveTo(x: number, y: number): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: show(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: show(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: hide(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: hide(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: on(type: 'show' \| 'hide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: on(type: 'show' \| 'hide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: off(type: 'show' \| 'hide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: off(type: 'show' \| 'hide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Panel<br>Method or attribute name: changeFlag(flag: PanelFlag): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelFlag|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelFlag<br>Method or attribute name: FLG_FIXED = 0|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelFlag<br>Method or attribute name: FLG_FLOATING|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelType|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelType<br>Method or attribute name: SOFT_KEYBOARD = 0|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelType<br>Method or attribute name: STATUS_BAR|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelInfo|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelInfo<br>Method or attribute name: type: PanelType;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: PanelInfo<br>Method or attribute name: flag?: PanelFlag;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Direction|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Direction<br>Method or attribute name: CURSOR_UP = 1|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Direction<br>Method or attribute name: CURSOR_DOWN|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Direction<br>Method or attribute name: CURSOR_LEFT|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Direction<br>Method or attribute name: CURSOR_RIGHT|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Range|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Range<br>Method or attribute name: start: number;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Range<br>Method or attribute name: end: number;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Movement|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: Movement<br>Method or attribute name: direction: Direction;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: ExtendAction|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: ExtendAction<br>Method or attribute name: SELECT_ALL = 0|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: ExtendAction<br>Method or attribute name: CUT = 3|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: ExtendAction<br>Method or attribute name: COPY = 4|@ohos.inputMethodEngine.d.ts|
|Added|NA|Module name: ohos.inputMethodEngine<br>Class name: ExtendAction<br>Method or attribute name: PASTE = 5|@ohos.inputMethodEngine.d.ts|
|Added|NA|Class name: InputMethodSubtype<br>Method or attribute name: readonly labelId?: number;|@ohos.InputMethodSubtype.d.ts|
|Added|NA|Class name: InputMethodSubtype<br>Method or attribute name: extra?: object;|@ohos.InputMethodSubtype.d.ts|
|Added|NA|Module name: ohos.wallpaper<br>Class name: WallpaperResourceType|@ohos.wallpaper.d.ts|
|Added|NA|Module name: ohos.wallpaper<br>Class name: WallpaperResourceType<br>Method or attribute name: DEFAULT|@ohos.wallpaper.d.ts|
|Added|NA|Module name: ohos.wallpaper<br>Class name: WallpaperResourceType<br>Method or attribute name: PICTURE|@ohos.wallpaper.d.ts|
|Added|NA|Module name: ohos.wallpaper<br>Class name: WallpaperResourceType<br>Method or attribute name: VIDEO|@ohos.wallpaper.d.ts|
|Added|NA|Module name: ohos.wallpaper<br>Class name: WallpaperResourceType<br>Method or attribute name: PACKAGE|@ohos.wallpaper.d.ts|
|Added|NA|Class name: wallpaper<br>Method or attribute name: function setVideo(source: string, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|Added|NA|Class name: wallpaper<br>Method or attribute name: function setVideo(source: string, wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|Added|NA|Class name: wallpaper<br>Method or attribute name: function on(<br><br>    type: 'wallpaperChange',<br><br>    callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
|Added|NA|Class name: wallpaper<br>Method or attribute name: function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
|Permission added|Class name: screenLock<br>Method or attribute name: function lock(callback: AsyncCallback\<boolean>): void;<br>Permission: N/A|Class name: screenLock<br>Method or attribute name: function lock(callback: AsyncCallback\<boolean>): void;<br>Permission: ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|Permission added|Class name: screenLock<br>Method or attribute name: function onSystemEvent(callback: Callback\<SystemEvent>): boolean;<br>Permission: N/A|Class name: screenLock<br>Method or attribute name: function onSystemEvent(callback: Callback\<SystemEvent>): boolean;<br>Permission: ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|Permission added|Class name: screenLock<br>Method or attribute name: function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>Permission: N/A|Class name: screenLock<br>Method or attribute name: function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>Permission: ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|Permission added|Class name: screenLock<br>Method or attribute name: function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;<br>Permission: N/A|Class name: screenLock<br>Method or attribute name: function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;<br>Permission: ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
