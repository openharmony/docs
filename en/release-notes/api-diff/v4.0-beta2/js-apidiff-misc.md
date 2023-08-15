| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Deleted|Class name: InputMethodSetting;<br>Method or attribute name: on(type: 'imeShow' \| 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodSetting;<br>Method or attribute name: off(type: 'imeShow' \| 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: on(type: 'deleteLeft' \| 'deleteRight', callback: (length: number) => void): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: on(type: 'sendKeyboardStatus', callback: (keyBoardStatus: KeyboardStatus) => void): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: off(type: 'selectByRange'): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: off(type: 'selectByMovement'): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: off(type: 'insertText'): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: off(type: 'deleteLeft' \| 'deleteRight'): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: off(type: 'sendKeyboardStatus'): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: off(type: 'sendFunctionKey'): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: off(type: 'moveCursor'): void;|NA|@ohos.inputMethod.d.ts|
|Deleted|Class name: InputMethodController;<br>Method or attribute name: off(type: 'handleExtendAction'): void;|NA|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodSetting;<br>Method or attribute name: on(type: 'imeShow', callback: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodSetting;<br>Method or attribute name: on(type: 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodSetting;<br>Method or attribute name: off(type: 'imeShow', callback?: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodSetting;<br>Method or attribute name: off(type: 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: on(type: 'deleteLeft', callback: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: on(type: 'deleteRight', callback: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: on(type: 'sendKeyboardStatus', callback: (keyboardStatus: KeyboardStatus) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: on(type: 'getLeftTextOfCursor', callback: (length: number) => string): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: on(type: 'getRightTextOfCursor', callback: (length: number) => string): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: on(type: 'getTextIndexAtCursor', callback: () => number): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'selectByRange', callback?: Callback\<Range>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'selectByMovement', callback?: Callback\<Movement>): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'insertText', callback?: (text: string) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'deleteLeft', callback?: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'deleteRight', callback?: (length: number) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'sendKeyboardStatus', callback?: (keyboardStatus: KeyboardStatus) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'sendFunctionKey', callback?: (functionKey: FunctionKey) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'moveCursor', callback?: (direction: Direction) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'handleExtendAction', callback?: (action: ExtendAction) => void): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'getLeftTextOfCursor', callback?: (length: number) => string): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'getRightTextOfCursor', callback?: (length: number) => string): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: InputMethodController;<br>Method or attribute name: off(type: 'getTextIndexAtCursor', callback?: () => number): void;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: TextConfig;<br>Method or attribute name: cursorInfo?: CursorInfo;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: TextConfig;<br>Method or attribute name: selection?: Range;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: TextConfig;<br>Method or attribute name: windowId?: number;|@ohos.inputMethod.d.ts|
|Added|NA|Class name: KeyboardDelegate;<br>Method or attribute name: on(type: 'keyEvent', callback: (event: InputKeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Class name: KeyboardDelegate;<br>Method or attribute name: on(type: 'editorAttributeChanged', callback: (attr: EditorAttribute) => void): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Class name: KeyboardDelegate;<br>Method or attribute name: off(type: 'keyEvent', callback?: (event: InputKeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Class name: KeyboardDelegate;<br>Method or attribute name: off(type: 'editorAttributeChanged', callback?: (attr: EditorAttribute) => void): void;|@ohos.inputMethodEngine.d.ts|
|Added|NA|Class name: wallpaper;<br>Method or attribute name: function setCustomWallpaper(source: string, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|Added|NA|Class name: wallpaper;<br>Method or attribute name: function setCustomWallpaper(source: string, wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|Added|NA|Class name: WallpaperExtensionAbility;<br>Method or attribute name: onCreate(want: object): void;|@ohos.WallpaperExtensionAbility.d.ts|
|Added|NA|Class name: WallpaperExtensionAbility;<br>Method or attribute name: onWallpaperChange(wallpaperType: number): void;|@ohos.WallpaperExtensionAbility.d.ts|
|Added|NA|Class name: WallpaperExtensionAbility;<br>Method or attribute name: onDestroy(): void;|@ohos.WallpaperExtensionAbility.d.ts|
|Error code changed|Class name: wallpaper;<br>Method or attribute name: function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;<br>Old version information: 202|Class name: wallpaper;<br>Method or attribute name: function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;<br>New version information: 401,202|@ohos.wallpaper.d.ts|
|Type changed|Class name: InputMethodProperty;<br>Method or attribute name: readonly labelId?: number;<br>Old version information: |Class name: InputMethodProperty;<br>Method or attribute name: readonly labelId?: number;<br>New version information: ?number|@ohos.inputMethod.d.ts|
|Type changed|Class name: InputMethodProperty;<br>Method or attribute name: readonly iconId?: number;<br>Old version information: |Class name: InputMethodProperty;<br>Method or attribute name: readonly iconId?: number;<br>New version information: ?number|@ohos.inputMethod.d.ts|
|Type changed|Class name: Movement;<br>Method or attribute name: direction: Direction;<br>Old version information: number|Class name: Movement;<br>Method or attribute name: direction: Direction;<br>New version information: Direction|@ohos.inputMethod.d.ts|
|Type changed|Class name: TextConfig;<br>Method or attribute name: inputAttribute: InputAttribute;<br>Old version information: |Class name: TextConfig;<br>Method or attribute name: inputAttribute: InputAttribute;<br>New version information: InputAttribute|@ohos.inputMethod.d.ts|
|Type changed|Class name: Movement;<br>Method or attribute name: direction: Direction;<br>Old version information: number|Class name: Movement;<br>Method or attribute name: direction: Direction;<br>New version information: Direction|@ohos.inputMethodEngine.d.ts|
|Type changed|Class name: InputMethodSubtype;<br>Method or attribute name: readonly labelId?: number;<br>Old version information: |Class name: InputMethodSubtype;<br>Method or attribute name: readonly labelId?: number;<br>New version information: ?number|@ohos.InputMethodSubtype.d.ts|
|Function changed|Class name: Panel;<br>Method or attribute name: on(type: 'show' \| 'hide', callback: () => void): void;|Class name: Panel;<br>Method or attribute name: on(type: 'show', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|Function changed|Class name: Panel;<br>Method or attribute name: on(type: 'show' \| 'hide', callback: () => void): void;|Class name: Panel;<br>Method or attribute name: on(type: 'hide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|Function changed|Class name: Panel;<br>Method or attribute name: off(type: 'show' \| 'hide', callback?: () => void): void;|Class name: Panel;<br>Method or attribute name: off(type: 'show', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|Function changed|Class name: Panel;<br>Method or attribute name: off(type: 'show' \| 'hide', callback?: () => void): void;|Class name: Panel;<br>Method or attribute name: off(type: 'hide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|Function changed|Class name: wallpaper;<br>Method or attribute name: function on(<br><br>    type: 'wallpaperChange',<br><br>    callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType) => void<br><br>  ): void;|Class name: wallpaper;<br>Method or attribute name: function on(<br><br>    type: 'wallpaperChange',<br><br>    callback: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
|Function changed|Class name: wallpaper;<br>Method or attribute name: function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType) => void<br><br>  ): void;|Class name: wallpaper;<br>Method or attribute name: function off(<br><br>    type: 'wallpaperChange',<br><br>    callback?: (wallpaperType: WallpaperType, resourceType: WallpaperResourceType, uri?: string) => void<br><br>  ): void;|@ohos.wallpaper.d.ts|
