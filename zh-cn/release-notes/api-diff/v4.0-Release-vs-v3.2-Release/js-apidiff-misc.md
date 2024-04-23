| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：InputMethodSetting;<br>方法or属性：on(type: 'imeShow', callback: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：on(type: 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：off(type: 'imeShow', callback?: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：off(type: 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：attach(showKeyboard: boolean, textConfig: TextConfig, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：attach(showKeyboard: boolean, textConfig: TextConfig): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：showTextInput(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：showTextInput(): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：hideTextInput(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：hideTextInput(): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：detach(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：detach(): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：setCallingWindow(windowId: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：setCallingWindow(windowId: number): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：updateCursor(cursorInfo: CursorInfo, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：updateCursor(cursorInfo: CursorInfo): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：changeSelection(text: string, start: number, end: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：changeSelection(text: string, start: number, end: number): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：updateAttribute(attribute: InputAttribute, callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：updateAttribute(attribute: InputAttribute): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'selectByRange', callback: Callback\<Range>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'selectByMovement', callback: Callback\<Movement>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'insertText', callback: (text: string) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'deleteLeft', callback: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'deleteRight', callback: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'sendKeyboardStatus', callback: (keyboardStatus: KeyboardStatus) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'sendFunctionKey', callback: (functionKey: FunctionKey) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'moveCursor', callback: (direction: Direction) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'handleExtendAction', callback: (action: ExtendAction) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'getLeftTextOfCursor', callback: (length: number) => string): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'getRightTextOfCursor', callback: (length: number) => string): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'getTextIndexAtCursor', callback: () => number): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'selectByRange', callback?: Callback\<Range>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'selectByMovement', callback?: Callback\<Movement>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'insertText', callback?: (text: string) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'deleteLeft', callback?: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'deleteRight', callback?: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'sendKeyboardStatus', callback?: (keyboardStatus: KeyboardStatus) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'sendFunctionKey', callback?: (functionKey: FunctionKey) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'moveCursor', callback?: (direction: Direction) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'handleExtendAction', callback?: (action: ExtendAction) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'getLeftTextOfCursor', callback?: (length: number) => string): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'getRightTextOfCursor', callback?: (length: number) => string): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：off(type: 'getTextIndexAtCursor', callback?: () => number): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：readonly labelId?: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：CURSOR_UP = 1|@ohos.inputMethod.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：CURSOR_DOWN|@ohos.inputMethod.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：CURSOR_LEFT|@ohos.inputMethod.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：CURSOR_RIGHT|@ohos.inputMethod.d.ts|
|新增|NA|类名：Range;<br>方法or属性：start: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：Range;<br>方法or属性：end: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：Movement;<br>方法or属性：direction: Direction;|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：NONE = -1|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：TEXT = 0|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：MULTILINE|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：NUMBER|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：PHONE|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：DATETIME|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：EMAIL_ADDRESS|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：URL|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextInputType;<br>方法or属性：VISIBLE_PASSWORD|@ohos.inputMethod.d.ts|
|新增|NA|类名：EnterKeyType;<br>方法or属性：UNSPECIFIED = 0|@ohos.inputMethod.d.ts|
|新增|NA|类名：EnterKeyType;<br>方法or属性：NONE|@ohos.inputMethod.d.ts|
|新增|NA|类名：EnterKeyType;<br>方法or属性：GO|@ohos.inputMethod.d.ts|
|新增|NA|类名：EnterKeyType;<br>方法or属性：SEARCH|@ohos.inputMethod.d.ts|
|新增|NA|类名：EnterKeyType;<br>方法or属性：SEND|@ohos.inputMethod.d.ts|
|新增|NA|类名：EnterKeyType;<br>方法or属性：NEXT|@ohos.inputMethod.d.ts|
|新增|NA|类名：EnterKeyType;<br>方法or属性：DONE|@ohos.inputMethod.d.ts|
|新增|NA|类名：EnterKeyType;<br>方法or属性：PREVIOUS|@ohos.inputMethod.d.ts|
|新增|NA|类名：KeyboardStatus;<br>方法or属性：NONE = 0|@ohos.inputMethod.d.ts|
|新增|NA|类名：KeyboardStatus;<br>方法or属性：HIDE = 1|@ohos.inputMethod.d.ts|
|新增|NA|类名：KeyboardStatus;<br>方法or属性：SHOW = 2|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputAttribute;<br>方法or属性：textInputType: TextInputType;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputAttribute;<br>方法or属性：enterKeyType: EnterKeyType;|@ohos.inputMethod.d.ts|
|新增|NA|类名：FunctionKey;<br>方法or属性：enterKeyType: EnterKeyType;|@ohos.inputMethod.d.ts|
|新增|NA|类名：CursorInfo;<br>方法or属性：left: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputWindowInfo;<br>方法or属性：left: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：CursorInfo;<br>方法or属性：top: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputWindowInfo;<br>方法or属性：top: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：CursorInfo;<br>方法or属性：width: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputWindowInfo;<br>方法or属性：width: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：CursorInfo;<br>方法or属性：height: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputWindowInfo;<br>方法or属性：height: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextConfig;<br>方法or属性：inputAttribute: InputAttribute;|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextConfig;<br>方法or属性：cursorInfo?: CursorInfo;|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextConfig;<br>方法or属性：selection?: Range;|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextConfig;<br>方法or属性：windowId?: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：ExtendAction;<br>方法or属性：SELECT_ALL = 0|@ohos.inputMethod.d.ts|
|新增|NA|类名：ExtendAction;<br>方法or属性：CUT = 3|@ohos.inputMethod.d.ts|
|新增|NA|类名：ExtendAction;<br>方法or属性：COPY = 4|@ohos.inputMethod.d.ts|
|新增|NA|类名：ExtendAction;<br>方法or属性：PASTE = 5|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputWindowInfo;<br>方法or属性：name: string;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：createPanel(ctx: BaseContext, info: PanelInfo): Promise\<Panel>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：destroyPanel(panel: Panel, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：destroyPanel(panel: Panel): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：deleteForwardSync(length: number): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：deleteBackwardSync(length: number): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：insertTextSync(text: string): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getForwardSync(length: number): string;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getBackwardSync(length: number): string;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getEditorAttributeSync(): EditorAttribute;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：moveCursorSync(direction: number): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：selectByRange(range: Range, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：selectByRange(range: Range): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：selectByRangeSync(range: Range): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：selectByMovement(movement: Movement, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：selectByMovement(movement: Movement): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：selectByMovementSync(movement: Movement): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getTextIndexAtCursor(callback: AsyncCallback\<number>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getTextIndexAtCursor(): Promise\<number>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getTextIndexAtCursorSync(): number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：sendExtendAction(action: ExtendAction, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：sendExtendAction(action: ExtendAction): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：on(type: 'keyEvent', callback: (event: InputKeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：on(type: 'editorAttributeChanged', callback: (attr: EditorAttribute) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：off(type: 'keyEvent', callback?: (event: InputKeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：off(type: 'editorAttributeChanged', callback?: (attr: EditorAttribute) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：setUiContent(path: string, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：setUiContent(path: string): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：setUiContent(path: string, storage: LocalStorage): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：resize(width: number, height: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：resize(width: number, height: number): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：moveTo(x: number, y: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：moveTo(x: number, y: number): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：show(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：show(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：hide(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：hide(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：on(type: 'show', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：on(type: 'hide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：off(type: 'show', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：off(type: 'hide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Panel;<br>方法or属性：changeFlag(flag: PanelFlag): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：PanelFlag;<br>方法or属性：FLG_FIXED = 0|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：PanelFlag;<br>方法or属性：FLG_FLOATING|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：PanelType;<br>方法or属性：SOFT_KEYBOARD = 0|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：PanelType;<br>方法or属性：STATUS_BAR|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：PanelInfo;<br>方法or属性：type: PanelType;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：PanelInfo;<br>方法or属性：flag?: PanelFlag;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：CURSOR_UP = 1|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：CURSOR_DOWN|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：CURSOR_LEFT|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Direction;<br>方法or属性：CURSOR_RIGHT|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Range;<br>方法or属性：start: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Range;<br>方法or属性：end: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：Movement;<br>方法or属性：direction: Direction;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：ExtendAction;<br>方法or属性：SELECT_ALL = 0|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：ExtendAction;<br>方法or属性：CUT = 3|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：ExtendAction;<br>方法or属性：COPY = 4|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：ExtendAction;<br>方法or属性：PASTE = 5|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly labelId?: number;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getTime(isNanoseconds?: boolean): number;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getUptime(timeType: TimeType, isNanoseconds?: boolean): number;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getTimezoneSync(): string;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：TimeType;<br>方法or属性：STARTUP|@ohos.systemDateTime.d.ts|
|新增|NA|类名：TimeType;<br>方法or属性：ACTIVE|@ohos.systemDateTime.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function setVideo(source: string, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function setVideo(source: string, wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function setCustomWallpaper(source: string, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function setCustomWallpaper(source: string, wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function on(<br><br>    type: 'wallpaperChange',<br><br>    callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：WallpaperResourceType;<br>方法or属性：DEFAULT|@ohos.wallpaper.d.ts|
|新增|NA|类名：WallpaperResourceType;<br>方法or属性：PICTURE|@ohos.wallpaper.d.ts|
|新增|NA|类名：WallpaperResourceType;<br>方法or属性：VIDEO|@ohos.wallpaper.d.ts|
|新增|NA|类名：WallpaperResourceType;<br>方法or属性：PACKAGE|@ohos.wallpaper.d.ts|
|新增|NA|类名：WallpaperExtensionAbility;<br>方法or属性：onCreate(want: object): void;|@ohos.WallpaperExtensionAbility.d.ts|
|新增|NA|类名：WallpaperExtensionAbility;<br>方法or属性：onWallpaperChange(wallpaperType: number): void;|@ohos.WallpaperExtensionAbility.d.ts|
|新增|NA|类名：WallpaperExtensionAbility;<br>方法or属性：onDestroy(): void;|@ohos.WallpaperExtensionAbility.d.ts|
|废弃版本有变化|类名：PasteDataRecord;<br>方法or属性：convertToText(): Promise\<string>;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：convertToText(): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#convertToTextV9|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：clear(): Promise\<void>;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：clear(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#clearData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：getPasteData(): Promise\<PasteData>;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：getPasteData(): Promise\<PasteData>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#getData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：hasPasteData(): Promise\<boolean>;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：hasPasteData(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#hasData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：setPasteData(data: PasteData): Promise\<void>;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：setPasteData(data: PasteData): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#setData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：request;<br>方法or属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>旧版本信息：9,|类名：request;<br>方法or属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>新版本信息：9<br>代替接口： ohos.request.downloadFile|@ohos.request.d.ts|
|废弃版本有变化|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>新版本信息：10<br>代替接口： systemDateTime.setTime|@ohos.systemDateTime.d.ts|
|废弃版本有变化|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>新版本信息：10<br>代替接口： systemDateTime.setTime|@ohos.systemDateTime.d.ts|
|废弃版本有变化|类名：systemDateTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;<br>新版本信息：10<br>代替接口： new|@ohos.systemDateTime.d.ts|
|废弃版本有变化|类名：systemDateTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>新版本信息：10<br>代替接口： new|@ohos.systemDateTime.d.ts|
|废弃版本有变化|类名：UploadResponse;<br>方法or属性：export interface UploadResponse<br>旧版本信息：9,|类名：UploadResponse;<br>方法or属性：export interface UploadResponse<br>新版本信息：9<br>代替接口： ohos.request|@system.request.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setTime(time: number): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTime(time: number): Promise\<void>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getCurrentTime(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getCurrentTime(callback: AsyncCallback\<number>): void;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getCurrentTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getCurrentTime(isNano?: boolean): Promise\<number>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getRealActiveTime(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getRealActiveTime(callback: AsyncCallback\<number>): void;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getRealTime(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getRealTime(callback: AsyncCallback\<number>): void;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getRealTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getRealTime(isNano?: boolean): Promise\<number>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getTimezone(): Promise\<string>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getTimezone(): Promise\<string>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|错误码有变化|类名：PasteData;<br>方法or属性：addRecord(mimeType: string, value: ValueType): void;<br>旧版本信息：401,12900002|类名：PasteData;<br>方法or属性：addRecord(mimeType: string, value: ValueType): void;<br>新版本信息：401|@ohos.pasteboard.d.ts|
|错误码有变化|类名：screenLock;<br>方法or属性：function lock(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：401,13200002|类名：screenLock;<br>方法or属性：function lock(callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201,202,13200002|@ohos.screenLock.d.ts|
|错误码有变化|类名：screenLock;<br>方法or属性：function lock(): Promise\<boolean>;<br>旧版本信息：13200002|类名：screenLock;<br>方法or属性：function lock(): Promise\<boolean>;<br>新版本信息：201,202,13200002|@ohos.screenLock.d.ts|
|错误码有变化|类名：screenLock;<br>方法or属性：function onSystemEvent(callback: Callback\<SystemEvent>): boolean;<br>旧版本信息：401,13200002|类名：screenLock;<br>方法or属性：function onSystemEvent(callback: Callback\<SystemEvent>): boolean;<br>新版本信息：401,201,202,13200002|@ohos.screenLock.d.ts|
|错误码有变化|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：401,13200002|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201,202,13200002|@ohos.screenLock.d.ts|
|错误码有变化|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;<br>旧版本信息：401,13200002|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;<br>新版本信息：401,201,202,13200002|@ohos.screenLock.d.ts|
|错误码有变化|类名：systemDateTime;<br>方法or属性：function setTime(time: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：202,401|类名：systemDateTime;<br>方法or属性：function setTime(time: number, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401|@ohos.systemDateTime.d.ts|
|错误码有变化|类名：systemDateTime;<br>方法or属性：function setTime(time: number): Promise\<void>;<br>旧版本信息：202,401|类名：systemDateTime;<br>方法or属性：function setTime(time: number): Promise\<void>;<br>新版本信息：201,202,401|@ohos.systemDateTime.d.ts|
|错误码有变化|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>旧版本信息：202,401|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401|@ohos.systemDateTime.d.ts|
|错误码有变化|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>旧版本信息：202,401|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>新版本信息：201,202,401|@ohos.systemDateTime.d.ts|
|错误码有变化|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：202,401|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401|@ohos.systemDateTime.d.ts|
|错误码有变化|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>旧版本信息：202,401|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>新版本信息：201,202,401|@ohos.systemDateTime.d.ts|
|错误码有变化|类名：wallpaper;<br>方法or属性：function getImage(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>旧版本信息：401,201|类名：wallpaper;<br>方法or属性：function getImage(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>新版本信息：401,201,202|@ohos.wallpaper.d.ts|
|错误码有变化|类名：wallpaper;<br>方法or属性：function getImage(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>旧版本信息：401,201|类名：wallpaper;<br>方法or属性：function getImage(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>新版本信息：401,201,202|@ohos.wallpaper.d.ts|
|权限有变化|类名：DownloadConfig;<br>方法or属性：background?: boolean;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：background?: boolean;<br>新版本信息：ohos.permission.INTERNET|@ohos.request.d.ts|
|权限有变化|类名：screenLock;<br>方法or属性：function lock(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function lock(callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|权限有变化|类名：screenLock;<br>方法or属性：function lock(): Promise\<boolean>;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function lock(): Promise\<boolean>;<br>新版本信息：ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|权限有变化|类名：screenLock;<br>方法or属性：function onSystemEvent(callback: Callback\<SystemEvent>): boolean;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function onSystemEvent(callback: Callback\<SystemEvent>): boolean;<br>新版本信息：ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|权限有变化|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|权限有变化|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;<br>新版本信息：ohos.permission.ACCESS_SCREEN_LOCK_INNER|@ohos.screenLock.d.ts|
|权限有变化|类名：systemDateTime;<br>方法or属性：function setTime(time: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setTime(time: number, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.SET_TIME|@ohos.systemDateTime.d.ts|
|权限有变化|类名：systemDateTime;<br>方法or属性：function setTime(time: number): Promise\<void>;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setTime(time: number): Promise\<void>;<br>新版本信息：ohos.permission.SET_TIME|@ohos.systemDateTime.d.ts|
|权限有变化|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.SET_TIME|@ohos.systemDateTime.d.ts|
|权限有变化|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>新版本信息：ohos.permission.SET_TIME|@ohos.systemDateTime.d.ts|
|权限有变化|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.SET_TIME_ZONE|@ohos.systemDateTime.d.ts|
|权限有变化|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>旧版本信息：|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>新版本信息：ohos.permission.SET_TIME_ZONE|@ohos.systemDateTime.d.ts|
|权限有变化|类名：systemTime;<br>方法or属性：function setTime(time: number): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTime(time: number): Promise\<void>;<br>新版本信息：ohos.permission.SET_TIME|@ohos.systemTime.d.ts|
|权限有变化|类名：systemTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>新版本信息：ohos.permission.SET_TIME|@ohos.systemTime.d.ts|
|权限有变化|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>新版本信息：ohos.permission.SET_TIME_ZONE|@ohos.systemTime.d.ts|
|type有变化|类名：InputMethodProperty;<br>方法or属性：readonly iconId?: number;<br>旧版本信息：|类名：InputMethodProperty;<br>方法or属性：readonly iconId?: number;<br>新版本信息：?number|@ohos.inputMethod.d.ts|
|type有变化|类名：InputMethodProperty;<br>方法or属性：extra?: object;<br>旧版本信息：|类名：InputMethodProperty;<br>方法or属性：extra?: object;<br>新版本信息：?object|@ohos.inputMethod.d.ts|
|type有变化|类名：InputMethodSubtype;<br>方法or属性：extra?: object;<br>旧版本信息：|类名：InputMethodSubtype;<br>方法or属性：extra?: object;<br>新版本信息：?object|@ohos.InputMethodSubtype.d.ts|
|type有变化|类名：pasteboard;<br>方法or属性：type ValueType = string \| image.PixelMap \| Want \| ArrayBuffer;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：type ValueType = string \| image.PixelMap \| Want \| ArrayBuffer;<br>新版本信息：string \| image.PixelMap \| Want \| ArrayBuffer|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：additions: {<br><br>      [key: string]: object<br><br>    }<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：additions: {<br><br>      [key: string]: object<br><br>    }<br>新版本信息：[key: string]: object|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：readonly mimeTypes: Array\<string>;<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：readonly mimeTypes: Array\<string>;<br>新版本信息：Array\<string>|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：tag: string;<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：tag: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：readonly timestamp: number;<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：readonly timestamp: number;<br>新版本信息：number|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataProperty;<br>方法or属性：localOnly: boolean;<br>旧版本信息：|类名：PasteDataProperty;<br>方法or属性：localOnly: boolean;<br>新版本信息：boolean|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：htmlText: string;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：htmlText: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：want: Want;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：want: Want;<br>新版本信息：Want|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：mimeType: string;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：mimeType: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：plainText: string;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：plainText: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：PasteDataRecord;<br>方法or属性：uri: string;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：uri: string;<br>新版本信息：string|@ohos.pasteboard.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：url: string;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：url: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：UploadConfig;<br>方法or属性：url: string;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：url: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：header?: Object;<br>新版本信息：?Object|@ohos.request.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：enableMetered?: boolean;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：enableMetered?: boolean;<br>新版本信息：?boolean|@ohos.request.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：enableRoaming?: boolean;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：enableRoaming?: boolean;<br>新版本信息：?boolean|@ohos.request.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：description?: string;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：description?: string;<br>新版本信息：?string|@ohos.request.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：networkType?: number;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：networkType?: number;<br>新版本信息：?number|@ohos.request.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：filePath?: string;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：filePath?: string;<br>新版本信息：?string|@ohos.request.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：title?: string;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：title?: string;<br>新版本信息：?string|@ohos.request.d.ts|
|type有变化|类名：DownloadConfig;<br>方法or属性：background?: boolean;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：background?: boolean;<br>新版本信息：?boolean|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：description: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：description: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：downloadedBytes: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：downloadedBytes: number;<br>新版本信息：number|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：downloadId: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：downloadId: number;<br>新版本信息：number|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：failedReason: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：failedReason: number;<br>新版本信息：number|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：fileName: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：fileName: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：filePath: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：filePath: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：pausedReason: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：pausedReason: number;<br>新版本信息：number|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：status: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：status: number;<br>新版本信息：number|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：targetURI: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：targetURI: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：downloadTitle: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：downloadTitle: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：DownloadInfo;<br>方法or属性：downloadTotalBytes: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：downloadTotalBytes: number;<br>新版本信息：number|@ohos.request.d.ts|
|type有变化|类名：File;<br>方法or属性：filename: string;<br>旧版本信息：|类名：File;<br>方法or属性：filename: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：File;<br>方法or属性：name: string;<br>旧版本信息：|类名：File;<br>方法or属性：name: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：RequestData;<br>方法or属性：name: string;<br>旧版本信息：|类名：RequestData;<br>方法or属性：name: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：File;<br>方法or属性：uri: string;<br>旧版本信息：|类名：File;<br>方法or属性：uri: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：File;<br>方法or属性：type: string;<br>旧版本信息：|类名：File;<br>方法or属性：type: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：RequestData;<br>方法or属性：value: string;<br>旧版本信息：|类名：RequestData;<br>方法or属性：value: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：UploadConfig;<br>方法or属性：header: Object;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：header: Object;<br>新版本信息：Object|@ohos.request.d.ts|
|type有变化|类名：UploadConfig;<br>方法or属性：method: string;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：method: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：UploadConfig;<br>方法or属性：files: Array\<File>;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：files: Array\<File>;<br>新版本信息：Array\<File>|@ohos.request.d.ts|
|type有变化|类名：UploadConfig;<br>方法or属性：data: Array\<RequestData>;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：data: Array\<RequestData>;<br>新版本信息：Array\<RequestData>|@ohos.request.d.ts|
|type有变化|类名：TaskState;<br>方法or属性：path: string;<br>旧版本信息：|类名：TaskState;<br>方法or属性：path: string;<br>新版本信息：string|@ohos.request.d.ts|
|type有变化|类名：TaskState;<br>方法or属性：responseCode: number;<br>旧版本信息：|类名：TaskState;<br>方法or属性：responseCode: number;<br>新版本信息：number|@ohos.request.d.ts|
|type有变化|类名：TaskState;<br>方法or属性：message: string;<br>旧版本信息：|类名：TaskState;<br>方法or属性：message: string;<br>新版本信息：string|@ohos.request.d.ts|
|函数有变化|类名：InputMethodProperty;<br>方法or属性：extra: object;|类名：InputMethodProperty;<br>方法or属性：extra?: object;|@ohos.inputMethod.d.ts|
|函数有变化|类名：InputMethodSubtype;<br>方法or属性：extra: object;|类名：InputMethodSubtype;<br>方法or属性：extra?: object;|@ohos.InputMethodSubtype.d.ts|
|跨平台能力有变化|类名：request;<br>方法or属性：function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>旧版本信息：|类名：request;<br>方法or属性：function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：request;<br>方法or属性：function downloadFile(context: BaseContext, config: DownloadConfig): Promise\<DownloadTask>;<br>旧版本信息：|类名：request;<br>方法or属性：function downloadFile(context: BaseContext, config: DownloadConfig): Promise\<DownloadTask>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：request;<br>方法or属性：function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>旧版本信息：|类名：request;<br>方法or属性：function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：request;<br>方法or属性：function uploadFile(context: BaseContext, config: UploadConfig): Promise\<UploadTask>;<br>旧版本信息：|类名：request;<br>方法or属性：function uploadFile(context: BaseContext, config: UploadConfig): Promise\<UploadTask>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：interface DownloadConfig<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：interface DownloadConfig<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：url: string;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：url: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadConfig;<br>方法or属性：url: string;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：url: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：header?: Object;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：enableMetered?: boolean;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：enableMetered?: boolean;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：enableRoaming?: boolean;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：enableRoaming?: boolean;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：description?: string;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：description?: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：networkType?: number;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：networkType?: number;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：filePath?: string;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：filePath?: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：title?: string;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：title?: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadConfig;<br>方法or属性：background?: boolean;<br>旧版本信息：|类名：DownloadConfig;<br>方法or属性：background?: boolean;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：interface DownloadInfo<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：interface DownloadInfo<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：description: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：description: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：downloadedBytes: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：downloadedBytes: number;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：downloadId: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：downloadId: number;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：failedReason: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：failedReason: number;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：fileName: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：fileName: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：filePath: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：filePath: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：pausedReason: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：pausedReason: number;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：status: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：status: number;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：targetURI: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：targetURI: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：downloadTitle: string;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：downloadTitle: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadInfo;<br>方法or属性：downloadTotalBytes: number;<br>旧版本信息：|类名：DownloadInfo;<br>方法or属性：downloadTotalBytes: number;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：interface DownloadTask<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：interface DownloadTask<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：on(type: 'progress', callback: (receivedSize: number, totalSize: number) => void): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：on(type: 'progress', callback: (receivedSize: number, totalSize: number) => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：on(type: 'complete' \| 'pause' \| 'remove', callback: () => void): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：on(type: 'complete' \| 'pause' \| 'remove', callback: () => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：on(type: 'fail', callback: (err: number) => void): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：on(type: 'fail', callback: (err: number) => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：off(type: 'progress', callback?: (receivedSize: number, totalSize: number) => void): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：off(type: 'progress', callback?: (receivedSize: number, totalSize: number) => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：off(type: 'complete' \| 'pause' \| 'remove', callback?: () => void): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：off(type: 'complete' \| 'pause' \| 'remove', callback?: () => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：off(type: 'fail', callback?: (err: number) => void): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：off(type: 'fail', callback?: (err: number) => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：delete(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：delete(callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：delete(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：delete(callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：delete(): Promise\<boolean>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：delete(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：delete(): Promise\<boolean>;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：delete(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：suspend(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：suspend(callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：suspend(): Promise\<boolean>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：suspend(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：restore(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：restore(callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：restore(): Promise\<boolean>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：restore(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：getTaskInfo(callback: AsyncCallback\<DownloadInfo>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：getTaskInfo(callback: AsyncCallback\<DownloadInfo>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：getTaskInfo(): Promise\<DownloadInfo>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：getTaskInfo(): Promise\<DownloadInfo>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：getTaskMimeType(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：getTaskMimeType(callback: AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：DownloadTask;<br>方法or属性：getTaskMimeType(): Promise\<string>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：getTaskMimeType(): Promise\<string>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：File;<br>方法or属性：interface File<br>旧版本信息：|类名：File;<br>方法or属性：interface File<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：File;<br>方法or属性：filename: string;<br>旧版本信息：|类名：File;<br>方法or属性：filename: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：File;<br>方法or属性：name: string;<br>旧版本信息：|类名：File;<br>方法or属性：name: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：RequestData;<br>方法or属性：name: string;<br>旧版本信息：|类名：RequestData;<br>方法or属性：name: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：File;<br>方法or属性：uri: string;<br>旧版本信息：|类名：File;<br>方法or属性：uri: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：File;<br>方法or属性：type: string;<br>旧版本信息：|类名：File;<br>方法or属性：type: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：RequestData;<br>方法or属性：interface RequestData<br>旧版本信息：|类名：RequestData;<br>方法or属性：interface RequestData<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：RequestData;<br>方法or属性：value: string;<br>旧版本信息：|类名：RequestData;<br>方法or属性：value: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadConfig;<br>方法or属性：interface UploadConfig<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：interface UploadConfig<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadConfig;<br>方法or属性：header: Object;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：header: Object;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadConfig;<br>方法or属性：method: string;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：method: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadConfig;<br>方法or属性：files: Array\<File>;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：files: Array\<File>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadConfig;<br>方法or属性：data: Array\<RequestData>;<br>旧版本信息：|类名：UploadConfig;<br>方法or属性：data: Array\<RequestData>;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：TaskState;<br>方法or属性：interface TaskState<br>旧版本信息：|类名：TaskState;<br>方法or属性：interface TaskState<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：TaskState;<br>方法or属性：path: string;<br>旧版本信息：|类名：TaskState;<br>方法or属性：path: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：TaskState;<br>方法or属性：responseCode: number;<br>旧版本信息：|类名：TaskState;<br>方法or属性：responseCode: number;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：TaskState;<br>方法or属性：message: string;<br>旧版本信息：|类名：TaskState;<br>方法or属性：message: string;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：interface UploadTask<br>旧版本信息：|类名：UploadTask;<br>方法or属性：interface UploadTask<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：on(type: 'progress', callback: (uploadedSize: number, totalSize: number) => void): void;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：on(type: 'progress', callback: (uploadedSize: number, totalSize: number) => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：on(type: 'headerReceive', callback: (header: object) => void): void;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：on(type: 'headerReceive', callback: (header: object) => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：on(type: 'complete' \| 'fail', callback: Callback\<Array\<TaskState>>): void;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：on(type: 'complete' \| 'fail', callback: Callback\<Array\<TaskState>>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：off(type: 'progress', callback?: (uploadedSize: number, totalSize: number) => void): void;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：off(type: 'progress', callback?: (uploadedSize: number, totalSize: number) => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：off(type: 'headerReceive', callback?: (header: object) => void): void;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：off(type: 'headerReceive', callback?: (header: object) => void): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
|跨平台能力有变化|类名：UploadTask;<br>方法or属性：off(type: 'complete' \| 'fail', callback?: Callback\<Array\<TaskState>>): void;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：off(type: 'complete' \| 'fail', callback?: Callback\<Array\<TaskState>>): void;<br>新版本信息：crossplatform|@ohos.request.d.ts|
