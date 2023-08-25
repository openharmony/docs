| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：InputMethodSetting;<br>方法or属性：on(type: 'imeShow' \| 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodSetting;<br>方法or属性：off(type: 'imeShow' \| 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：on(type: 'deleteLeft' \| 'deleteRight', callback: (length: number) => void): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：on(type: 'sendKeyboardStatus', callback: (keyBoardStatus: KeyboardStatus) => void): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：off(type: 'selectByRange'): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：off(type: 'selectByMovement'): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：off(type: 'insertText'): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：off(type: 'deleteLeft' \| 'deleteRight'): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：off(type: 'sendKeyboardStatus'): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：off(type: 'sendFunctionKey'): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：off(type: 'moveCursor'): void;|NA|@ohos.inputMethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：off(type: 'handleExtendAction'): void;|NA|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：on(type: 'imeShow', callback: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：on(type: 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：off(type: 'imeShow', callback?: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：off(type: 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'deleteLeft', callback: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'deleteRight', callback: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：on(type: 'sendKeyboardStatus', callback: (keyboardStatus: KeyboardStatus) => void): void;|@ohos.inputMethod.d.ts|
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
|新增|NA|类名：TextConfig;<br>方法or属性：cursorInfo?: CursorInfo;|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextConfig;<br>方法or属性：selection?: Range;|@ohos.inputMethod.d.ts|
|新增|NA|类名：TextConfig;<br>方法or属性：windowId?: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：on(type: 'keyEvent', callback: (event: InputKeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：on(type: 'editorAttributeChanged', callback: (attr: EditorAttribute) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：off(type: 'keyEvent', callback?: (event: InputKeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：off(type: 'editorAttributeChanged', callback?: (attr: EditorAttribute) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function setCustomWallpaper(source: string, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function setCustomWallpaper(source: string, wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：WallpaperExtensionAbility;<br>方法or属性：onCreate(want: object): void;|@ohos.WallpaperExtensionAbility.d.ts|
|新增|NA|类名：WallpaperExtensionAbility;<br>方法or属性：onWallpaperChange(wallpaperType: number): void;|@ohos.WallpaperExtensionAbility.d.ts|
|新增|NA|类名：WallpaperExtensionAbility;<br>方法or属性：onDestroy(): void;|@ohos.WallpaperExtensionAbility.d.ts|
|错误码有变化|类名：wallpaper;<br>方法or属性：function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;<br>旧版本信息：202|类名：wallpaper;<br>方法or属性：function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;<br>新版本信息：401,202|@ohos.wallpaper.d.ts|
|type有变化|类名：InputMethodProperty;<br>方法or属性：readonly labelId?: number;<br>旧版本信息：|类名：InputMethodProperty;<br>方法or属性：readonly labelId?: number;<br>新版本信息：?number|@ohos.inputMethod.d.ts|
|type有变化|类名：InputMethodProperty;<br>方法or属性：readonly iconId?: number;<br>旧版本信息：|类名：InputMethodProperty;<br>方法or属性：readonly iconId?: number;<br>新版本信息：?number|@ohos.inputMethod.d.ts|
|type有变化|类名：Movement;<br>方法or属性：direction: Direction;<br>旧版本信息：number|类名：Movement;<br>方法or属性：direction: Direction;<br>新版本信息：Direction|@ohos.inputMethod.d.ts|
|type有变化|类名：TextConfig;<br>方法or属性：inputAttribute: InputAttribute;<br>旧版本信息：|类名：TextConfig;<br>方法or属性：inputAttribute: InputAttribute;<br>新版本信息：InputAttribute|@ohos.inputMethod.d.ts|
|type有变化|类名：Movement;<br>方法or属性：direction: Direction;<br>旧版本信息：number|类名：Movement;<br>方法or属性：direction: Direction;<br>新版本信息：Direction|@ohos.inputMethodEngine.d.ts|
|type有变化|类名：InputMethodSubtype;<br>方法or属性：readonly labelId?: number;<br>旧版本信息：|类名：InputMethodSubtype;<br>方法or属性：readonly labelId?: number;<br>新版本信息：?number|@ohos.InputMethodSubtype.d.ts|
|函数有变化|类名：Panel;<br>方法or属性：on(type: 'show' \| 'hide', callback: () => void): void;|类名：Panel;<br>方法or属性：on(type: 'show', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|函数有变化|类名：Panel;<br>方法or属性：on(type: 'show' \| 'hide', callback: () => void): void;|类名：Panel;<br>方法or属性：on(type: 'hide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|函数有变化|类名：Panel;<br>方法or属性：off(type: 'show' \| 'hide', callback?: () => void): void;|类名：Panel;<br>方法or属性：off(type: 'show', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|函数有变化|类名：Panel;<br>方法or属性：off(type: 'show' \| 'hide', callback?: () => void): void;|类名：Panel;<br>方法or属性：off(type: 'hide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|函数有变化|类名：wallpaper;<br>方法or属性：function on(<br><br>    type: 'wallpaperChange',<br><br>    callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType) => void<br><br>  ): void;|类名：wallpaper;<br>方法or属性：function on(<br><br>    type: 'wallpaperChange',<br><br>    callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
|函数有变化|类名：wallpaper;<br>方法or属性：function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType) => void<br><br>  ): void;|类名：wallpaper;<br>方法or属性：function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
