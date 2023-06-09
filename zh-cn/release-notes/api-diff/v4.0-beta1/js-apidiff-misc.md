| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：InputMethodSetting<br>方法or属性：on(type: 'imeShow' \| 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting<br>方法or属性：off(type: 'imeShow' \| 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：attach(showKeyboard: boolean, textConfig: TextConfig, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：attach(showKeyboard: boolean, textConfig: TextConfig): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：showTextInput(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：showTextInput(): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：hideTextInput(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：hideTextInput(): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：detach(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：detach(): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：setCallingWindow(windowId: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：setCallingWindow(windowId: number): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：updateCursor(cursorInfo: CursorInfo, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：updateCursor(cursorInfo: CursorInfo): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：changeSelection(text: string, start: number, end: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：changeSelection(text: string, start: number, end: number): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：updateAttribute(attribute: InputAttribute, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：updateAttribute(attribute: InputAttribute): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：on(type: 'selectByRange', callback: Callback\<Range>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：on(type: 'selectByMovement', callback: Callback\<Movement>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：off(type: 'selectByRange'): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：off(type: 'selectByMovement'): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：on(type: 'insertText', callback: (text: string) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：off(type: 'insertText'): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：on(type: 'deleteLeft' \| 'deleteRight', callback: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：off(type: 'deleteLeft' \| 'deleteRight'): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：on(type: 'sendKeyboardStatus', callback: (keyBoardStatus: KeyboardStatus) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：off(type: 'sendKeyboardStatus'): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：on(type: 'sendFunctionKey', callback: (functionKey: FunctionKey) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：off(type: 'sendFunctionKey'): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：on(type: 'moveCursor', callback: (direction: Direction) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：off(type: 'moveCursor'): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：on(type: 'handleExtendAction', callback: (action: ExtendAction) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController<br>方法or属性：off(type: 'handleExtendAction'): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty<br>方法or属性：readonly labelId?: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty<br>方法or属性：extra?: object;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Direction|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Direction<br>方法 or 属性：CURSOR_UP = 1|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Direction<br>方法 or 属性：CURSOR_DOWN|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Direction<br>方法 or 属性：CURSOR_LEFT|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Direction<br>方法 or 属性：CURSOR_RIGHT|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Range|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Range<br>方法 or 属性：start: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Range<br>方法 or 属性：end: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Movement|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: Movement<br>方法 or 属性：direction: Direction;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：NONE = -1|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：TEXT = 0|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：MULTILINE|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：NUMBER|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：PHONE|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：DATETIME|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：EMAIL_ADDRESS|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：URL|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextInputType<br>方法 or 属性：VISIBLE_PASSWORD|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType<br>方法 or 属性：UNSPECIFIED = 0|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType<br>方法 or 属性：NONE|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType<br>方法 or 属性：GO|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType<br>方法 or 属性：SEARCH|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType<br>方法 or 属性：SEND|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType<br>方法 or 属性：NEXT|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType<br>方法 or 属性：DONE|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: EnterKeyType<br>方法 or 属性：PREVIOUS|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: KeyboardStatus|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: KeyboardStatus<br>方法 or 属性：NONE = 0|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: KeyboardStatus<br>方法 or 属性：HIDE = 1|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: KeyboardStatus<br>方法 or 属性：SHOW = 2|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputAttribute|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputAttribute<br>方法 or 属性：textInputType: TextInputType;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputAttribute<br>方法 or 属性：enterKeyType: EnterKeyType;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: FunctionKey|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: FunctionKey<br>方法 or 属性：enterKeyType: EnterKeyType;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: CursorInfo|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: CursorInfo<br>方法 or 属性：left: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: CursorInfo<br>方法 or 属性：top: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: CursorInfo<br>方法 or 属性：width: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: CursorInfo<br>方法 or 属性：height: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextConfig|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: TextConfig<br>方法 or 属性：inputAttribute: InputAttribute;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: ExtendAction|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: ExtendAction<br>方法 or 属性：SELECT_ALL = 0|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: ExtendAction<br>方法 or 属性：CUT = 3|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: ExtendAction<br>方法 or 属性：COPY = 4|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: ExtendAction<br>方法 or 属性：PASTE = 5|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputWindowInfo|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputWindowInfo<br>方法 or 属性：name: string;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputWindowInfo<br>方法 or 属性：left: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputWindowInfo<br>方法 or 属性：top: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputWindowInfo<br>方法 or 属性：width: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputWindowInfo<br>方法 or 属性：height: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodAbility<br>方法or属性：createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility<br>方法or属性：createPanel(ctx: BaseContext, info: PanelInfo): Promise\<Panel>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility<br>方法or属性：destroyPanel(panel: Panel, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility<br>方法or属性：destroyPanel(panel: Panel): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性：selectByRange(range: Range, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性：selectByRange(range: Range): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性：selectByMovement(movement: Movement, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性：selectByMovement(movement: Movement): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性：getTextIndexAtCursor(callback: AsyncCallback\<number>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性：getTextIndexAtCursor(): Promise\<number>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性：sendExtendAction(action: ExtendAction, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性：sendExtendAction(action: ExtendAction): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：setUiContent(path: string, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：setUiContent(path: string): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：setUiContent(path: string, storage: LocalStorage): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：resize(width: number, height: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：resize(width: number, height: number): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：moveTo(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：moveTo(x: number, y: number): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：show(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：show(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：hide(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：hide(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：on(type: 'show' \| 'hide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：on(type: 'show' \| 'hide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：off(type: 'show' \| 'hide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：off(type: 'show' \| 'hide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Panel<br>方法 or 属性：changeFlag(flag: PanelFlag): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelFlag|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelFlag<br>方法 or 属性：FLG_FIXED = 0|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelFlag<br>方法 or 属性：FLG_FLOATING|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelType|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelType<br>方法 or 属性：SOFT_KEYBOARD = 0|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelType<br>方法 or 属性：STATUS_BAR|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelInfo|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelInfo<br>方法 or 属性：type: PanelType;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: PanelInfo<br>方法 or 属性：flag?: PanelFlag;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Direction|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Direction<br>方法 or 属性：CURSOR_UP = 1|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Direction<br>方法 or 属性：CURSOR_DOWN|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Direction<br>方法 or 属性：CURSOR_LEFT|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Direction<br>方法 or 属性：CURSOR_RIGHT|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Range|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Range<br>方法 or 属性：start: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Range<br>方法 or 属性：end: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Movement|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: Movement<br>方法 or 属性：direction: Direction;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: ExtendAction|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: ExtendAction<br>方法 or 属性：SELECT_ALL = 0|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: ExtendAction<br>方法 or 属性：CUT = 3|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: ExtendAction<br>方法 or 属性：COPY = 4|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: ExtendAction<br>方法 or 属性：PASTE = 5|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodSubtype<br>方法or属性：readonly labelId?: number;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype<br>方法or属性：extra?: object;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.wallpaper<br>类名: WallpaperResourceType|@ohos.wallpaper.d.ts|
|新增|NA|模块名: ohos.wallpaper<br>类名: WallpaperResourceType<br>方法 or 属性：DEFAULT|@ohos.wallpaper.d.ts|
|新增|NA|模块名: ohos.wallpaper<br>类名: WallpaperResourceType<br>方法 or 属性：PICTURE|@ohos.wallpaper.d.ts|
|新增|NA|模块名: ohos.wallpaper<br>类名: WallpaperResourceType<br>方法 or 属性：VIDEO|@ohos.wallpaper.d.ts|
|新增|NA|模块名: ohos.wallpaper<br>类名: WallpaperResourceType<br>方法 or 属性：PACKAGE|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function setVideo(source: string, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function setVideo(source: string, wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function on(<br><br>    type: 'wallpaperChange',<br><br>    callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
|新增(权限)|类名：screenLock<br>方法 or 属性：function lock(callback: AsyncCallback\<boolean>): void;<br>权限:N/A|类名：screenLock<br>方法 or 属性：function lock(callback: AsyncCallback\<boolean>): void;<br>权限:ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|新增(权限)|类名：screenLock<br>方法 or 属性：function onSystemEvent(callback: Callback\<SystemEvent>): boolean;<br>权限:N/A|类名：screenLock<br>方法 or 属性：function onSystemEvent(callback: Callback\<SystemEvent>): boolean;<br>权限:ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|新增(权限)|类名：screenLock<br>方法 or 属性：function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>权限:N/A|类名：screenLock<br>方法 or 属性：function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>权限:ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|新增(权限)|类名：screenLock<br>方法 or 属性：function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;<br>权限:N/A|类名：screenLock<br>方法 or 属性：function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;<br>权限:ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
