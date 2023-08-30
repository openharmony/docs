| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：inputMethod;<br>方法or属性：function getInputMethodSetting(): InputMethodSetting;|NA|@ohos.inputmethod.d.ts|
|删除|类名：inputMethod;<br>方法or属性：function getInputMethodController(): InputMethodController;|NA|@ohos.inputmethod.d.ts|
|删除|类名：InputMethodSetting;<br>方法or属性：listInputMethod(callback: AsyncCallback\<Array\<InputMethodProperty>>): void;|NA|@ohos.inputmethod.d.ts|
|删除|类名：InputMethodSetting;<br>方法or属性：listInputMethod(): Promise\<Array\<InputMethodProperty>>;|NA|@ohos.inputmethod.d.ts|
|删除|类名：InputMethodSetting;<br>方法or属性：displayOptionalInputMethod(callback: AsyncCallback\<void>): void;|NA|@ohos.inputmethod.d.ts|
|删除|类名：InputMethodSetting;<br>方法or属性：displayOptionalInputMethod(): Promise\<void>;|NA|@ohos.inputmethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：stopInput(callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethod.d.ts|
|删除|类名：InputMethodController;<br>方法or属性：stopInput(): Promise\<boolean>;|NA|@ohos.inputmethod.d.ts|
|删除|类名：InputMethodProperty;<br>方法or属性：readonly packageName: string;|NA|@ohos.inputmethod.d.ts|
|删除|类名：InputMethodProperty;<br>方法or属性：readonly methodId: string;|NA|@ohos.inputmethod.d.ts|
|删除|类名：inputMethodEngine;<br>方法or属性：function getInputMethodEngine(): InputMethodEngine;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：inputMethodEngine;<br>方法or属性：function createKeyboardDelegate(): KeyboardDelegate;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardController;<br>方法or属性：hideKeyboard(callback: AsyncCallback\<void>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardController;<br>方法or属性：hideKeyboard(): Promise\<void>;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：InputMethodEngine;<br>方法or属性：on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：InputMethodEngine;<br>方法or属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：InputMethodEngine;<br>方法or属性：off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：InputMethodEngine;<br>方法or属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：sendKeyFunction(action: number): Promise\<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：deleteForward(length: number, callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：deleteForward(length: number): Promise\<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：deleteBackward(length: number, callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：deleteBackward(length: number): Promise\<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：insertText(text: string, callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：insertText(text: string): Promise\<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：getForward(length: number, callback: AsyncCallback\<string>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：getForward(length: number): Promise\<string>;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：getBackward(length: number, callback: AsyncCallback\<string>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：getBackward(length: number): Promise\<string>;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：TextInputClient;<br>方法or属性：getEditorAttribute(): Promise\<EditorAttribute>;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardDelegate;<br>方法or属性：on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardDelegate;<br>方法or属性：on(type: 'cursorContextChange', callback: (x: number, y: number, height: number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardDelegate;<br>方法or属性：on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardDelegate;<br>方法or属性：on(type: 'textChange', callback: (text: string) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardDelegate;<br>方法or属性：off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardDelegate;<br>方法or属性：off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardDelegate;<br>方法or属性：off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyboardDelegate;<br>方法or属性：off(type: 'textChange', callback?: (text: string) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：EditorAttribute;<br>方法or属性：readonly inputPattern: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：EditorAttribute;<br>方法or属性：readonly enterKeyType: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyEvent;<br>方法or属性：readonly keyCode: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：KeyEvent;<br>方法or属性：readonly keyAction: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|类名：systemTime;<br>方法or属性：function getCurrentTime(isNano?: boolean, callback: AsyncCallback\<number>): void;|NA|@ohos.systemTime.d.ts|
|删除|类名：systemTime;<br>方法or属性：function getRealActiveTime(isNano?: boolean, callback: AsyncCallback\<number>): void;|NA|@ohos.systemTime.d.ts|
|删除|类名：systemTime;<br>方法or属性：function getRealTime(isNano?: boolean, callback: AsyncCallback\<number>): void;|NA|@ohos.systemTime.d.ts|
|删除|类名：wallpaper;<br>方法or属性：function screenshotLiveWallpaper(scale: number, pixelFormat: image.PixelMapFormat, callback: AsyncCallback\<image.PixelMap>): void;|NA|@ohos.wallpaper.d.ts|
|删除|类名：wallpaper;<br>方法or属性：function screenshotLiveWallpaper(scale: number, pixelFormat: image.PixelMapFormat): Promise\<image.PixelMap>;|NA|@ohos.wallpaper.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function getInputMethodSetting(): InputMethodSetting;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function getInputMethodController(): InputMethodController;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function getSetting(): InputMethodSetting;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function getController(): InputMethodController;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function switchInputMethod(target: InputMethodProperty, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function switchInputMethod(target: InputMethodProperty): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function getCurrentInputMethod(): InputMethodProperty;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function getCurrentInputMethodSubtype(): InputMethodSubtype;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethod;<br>方法or属性：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback\<Array\<InputMethodSubtype>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise\<Array\<InputMethodSubtype>>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：listCurrentInputMethodSubtype(callback: AsyncCallback\<Array\<InputMethodSubtype>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：listCurrentInputMethodSubtype(): Promise\<Array\<InputMethodSubtype>>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：getInputMethods(enable: boolean, callback: AsyncCallback\<Array\<InputMethodProperty>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：getInputMethods(enable: boolean): Promise\<Array\<InputMethodProperty>>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：listInputMethod(callback: AsyncCallback\<Array\<InputMethodProperty>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：listInputMethod(): Promise\<Array\<InputMethodProperty>>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：showOptionalInputMethods(callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：showOptionalInputMethods(): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：displayOptionalInputMethod(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodSetting;<br>方法or属性：displayOptionalInputMethod(): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：stopInputSession(callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：stopInputSession(): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：stopInput(callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：stopInput(): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：showSoftKeyboard(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：showSoftKeyboard():Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：hideSoftKeyboard(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodController;<br>方法or属性：hideSoftKeyboard():Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：readonly packageName: string;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：readonly methodId: string;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：readonly name: string;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：readonly id: string;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：readonly label?: string;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：readonly icon?: string;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：readonly iconId?: number;|@ohos.inputMethod.d.ts|
|新增|NA|类名：InputMethodProperty;<br>方法or属性：extra: object;|@ohos.inputMethod.d.ts|
|新增|NA|类名：inputMethodEngine;<br>方法or属性：function getInputMethodAbility(): InputMethodAbility;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：inputMethodEngine;<br>方法or属性：function getInputMethodEngine(): InputMethodEngine;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：inputMethodEngine;<br>方法or属性：function getKeyboardDelegate(): KeyboardDelegate;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：inputMethodEngine;<br>方法or属性：function createKeyboardDelegate(): KeyboardDelegate;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardController;<br>方法or属性：hide(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardController;<br>方法or属性：hide(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardController;<br>方法or属性：hideKeyboard(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardController;<br>方法or属性：hideKeyboard(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodEngine;<br>方法or属性：on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodEngine;<br>方法or属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodEngine;<br>方法or属性：off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodEngine;<br>方法or属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：on(type: 'inputStop', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：on(type: 'setCallingWindow', callback: (wid:number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：off(type: 'inputStop', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：off(type: 'setCallingWindow', callback: (wid:number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodAbility;<br>方法or属性：off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：sendKeyFunction(action: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：sendKeyFunction(action: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：deleteForward(length: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：deleteForward(length: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：deleteForward(length: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：deleteForward(length: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：deleteBackward(length: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：deleteBackward(length: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：deleteBackward(length: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：deleteBackward(length: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：insertText(text: string, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：insertText(text: string, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：insertText(text: string): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：insertText(text: string): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：getForward(length: number, callback: AsyncCallback\<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getForward(length: number, callback: AsyncCallback\<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：getForward(length: number): Promise\<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getForward(length: number): Promise\<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：getBackward(length: number, callback: AsyncCallback\<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getBackward(length: number, callback: AsyncCallback\<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：getBackward(length: number): Promise\<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getBackward(length: number): Promise\<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：TextInputClient;<br>方法or属性：getEditorAttribute(): Promise\<EditorAttribute>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：getEditorAttribute(): Promise\<EditorAttribute>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：moveCursor(direction: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputClient;<br>方法or属性：moveCursor(direction: number): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：on(type: 'cursorContextChange', callback: (x: number, y: number, height: number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：on(type: 'textChange', callback: (text: string) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyboardDelegate;<br>方法or属性：off(type: 'textChange', callback?: (text: string) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：EditorAttribute;<br>方法or属性：readonly inputPattern: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：EditorAttribute;<br>方法or属性：readonly enterKeyType: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：readonly keyCode: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：KeyEvent;<br>方法or属性：readonly keyAction: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|类名：InputMethodExtensionAbility;<br>方法or属性：context: InputMethodExtensionContext;|@ohos.InputMethodExtensionAbility.d.ts|
|新增|NA|类名：InputMethodExtensionAbility;<br>方法or属性：onCreate(want: Want): void;|@ohos.InputMethodExtensionAbility.d.ts|
|新增|NA|类名：InputMethodExtensionAbility;<br>方法or属性：onDestroy(): void;|@ohos.InputMethodExtensionAbility.d.ts|
|新增|NA|类名：InputMethodExtensionContext;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;|@ohos.InputMethodExtensionContext.d.ts|
|新增|NA|类名：InputMethodExtensionContext;<br>方法or属性：destroy(): Promise\<void>;|@ohos.InputMethodExtensionContext.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly label?: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly name: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly id: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly mode?: 'upper'\|'lower';|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly locale: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly language: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly icon?: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：readonly iconId?: number;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：InputMethodSubtype;<br>方法or属性：extra: object;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|类名：pasteboard;<br>方法or属性：type ValueType = string \| image.PixelMap \| Want \| ArrayBuffer;|@ohos.pasteboard.d.ts|
|新增|NA|类名：pasteboard;<br>方法or属性：function createData(mimeType: string, value: ValueType): PasteData;|@ohos.pasteboard.d.ts|
|新增|NA|类名：pasteboard;<br>方法or属性：function createRecord(mimeType: string, value: ValueType): PasteDataRecord;|@ohos.pasteboard.d.ts|
|新增|NA|类名：ShareOption;<br>方法or属性：INAPP|@ohos.pasteboard.d.ts|
|新增|NA|类名：ShareOption;<br>方法or属性：LOCALDEVICE|@ohos.pasteboard.d.ts|
|新增|NA|类名：ShareOption;<br>方法or属性：CROSSDEVICE|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteDataProperty;<br>方法or属性：shareOption: ShareOption;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteDataRecord;<br>方法or属性：pixelMap: image.PixelMap;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteDataRecord;<br>方法or属性：data: {<br><br>      [mimeType: string]: ArrayBuffer<br><br>    }|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteDataRecord;<br>方法or属性：toPlainText(): string;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData;<br>方法or属性：addRecord(mimeType: string, value: ValueType): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData;<br>方法or属性：getPrimaryPixelMap(): image.PixelMap;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData;<br>方法or属性：setProperty(property: PasteDataProperty): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData;<br>方法or属性：getRecord(index: number): PasteDataRecord;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData;<br>方法or属性：hasType(mimeType: string): boolean;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData;<br>方法or属性：removeRecord(index: number): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData;<br>方法or属性：replaceRecord(index: number, record: PasteDataRecord): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard;<br>方法or属性：clearData(callback: AsyncCallback\<void>): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard;<br>方法or属性：clearData(): Promise\<void>;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard;<br>方法or属性：getData(callback: AsyncCallback\<PasteData>): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard;<br>方法or属性：getData(): Promise\<PasteData>;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard;<br>方法or属性：hasData(callback: AsyncCallback\<boolean>): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard;<br>方法or属性：hasData(): Promise\<boolean>;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard;<br>方法or属性：setData(data: PasteData, callback: AsyncCallback\<void>): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard;<br>方法or属性：setData(data: PasteData): Promise\<void>;|@ohos.pasteboard.d.ts|
|新增|NA|类名：request;<br>方法or属性：function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;|@ohos.request.d.ts|
|新增|NA|类名：request;<br>方法or属性：function downloadFile(context: BaseContext, config: DownloadConfig): Promise\<DownloadTask>;|@ohos.request.d.ts|
|新增|NA|类名：request;<br>方法or属性：function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;|@ohos.request.d.ts|
|新增|NA|类名：request;<br>方法or属性：function uploadFile(context: BaseContext, config: UploadConfig): Promise\<UploadTask>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadConfig;<br>方法or属性：background?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：delete(callback: AsyncCallback\<boolean>): void;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask;<br>方法or属性：delete(callback: AsyncCallback\<boolean>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：delete(): Promise\<boolean>;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask;<br>方法or属性：delete(): Promise\<boolean>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：suspend(callback: AsyncCallback\<boolean>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：suspend(): Promise\<boolean>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：restore(callback: AsyncCallback\<boolean>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：restore(): Promise\<boolean>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：getTaskInfo(callback: AsyncCallback\<DownloadInfo>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：getTaskInfo(): Promise\<DownloadInfo>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：getTaskMimeType(callback: AsyncCallback\<string>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask;<br>方法or属性：getTaskMimeType(): Promise\<string>;|@ohos.request.d.ts|
|新增|NA|类名：TaskState;<br>方法or属性：path: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskState;<br>方法or属性：responseCode: number;|@ohos.request.d.ts|
|新增|NA|类名：TaskState;<br>方法or属性：message: string;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask;<br>方法or属性：on(type:'complete' \| 'fail', callback: Callback\<Array\<TaskState>>): void;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask;<br>方法or属性：off(type:'complete' \| 'fail', callback?: Callback\<Array\<TaskState>>): void;|@ohos.request.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：function isLocked(): boolean;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：function unlock(callback: AsyncCallback\<boolean>): void;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：function unlock():Promise\<boolean>;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：function lock(callback: AsyncCallback\<boolean>): void;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：function lock():Promise\<boolean>;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：function onSystemEvent(callback: Callback\<SystemEvent>): boolean;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock;<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;|@ohos.screenLock.d.ts|
|新增|NA|类名：SystemEvent;<br>方法or属性：eventType: EventType,|@ohos.screenLock.d.ts|
|新增|NA|类名：SystemEvent;<br>方法or属性：params: string|@ohos.screenLock.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function setTime(time : number, callback : AsyncCallback\<void>) : void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function setTime(time : number) : Promise\<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getCurrentTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getCurrentTime(callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getCurrentTime(isNano?: boolean): Promise\<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getRealActiveTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getRealActiveTime(callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getRealTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getRealTime(callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getRealTime(isNano?: boolean): Promise\<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getDate(): Promise\<Date>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getTimezone(callback: AsyncCallback\<string>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemDateTime;<br>方法or属性：function getTimezone(): Promise\<string>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：systemTime;<br>方法or属性：function getCurrentTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemTime.d.ts|
|新增|NA|类名：systemTime;<br>方法or属性：function getCurrentTime(callback: AsyncCallback\<number>): void;|@ohos.systemTime.d.ts|
|新增|NA|类名：systemTime;<br>方法or属性：function getRealActiveTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemTime.d.ts|
|新增|NA|类名：systemTime;<br>方法or属性：function getRealActiveTime(callback: AsyncCallback\<number>): void;|@ohos.systemTime.d.ts|
|新增|NA|类名：systemTime;<br>方法or属性：function getRealTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemTime.d.ts|
|新增|NA|类名：systemTime;<br>方法or属性：function getRealTime(callback: AsyncCallback\<number>): void;|@ohos.systemTime.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function getColorsSync(wallpaperType: WallpaperType): Array\<RgbaColor>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function getMinHeightSync(): number;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function getMinWidthSync(): number;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function restore(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function restore(wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function setImage(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function setImage(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function getImage(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper;<br>方法or属性：function getImage(wallpaperType: WallpaperType): Promise\<image.PixelMap>;|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：pasteboard;<br>方法or属性：function createHtmlData(htmlText: string): PasteData;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：function createHtmlData(htmlText: string): PasteData;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#createData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard;<br>方法or属性：function createWantData(want: Want): PasteData;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：function createWantData(want: Want): PasteData;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#createData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard;<br>方法or属性：function createPlainTextData(text: string): PasteData;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：function createPlainTextData(text: string): PasteData;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#createData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard;<br>方法or属性：function createUriData(uri: string): PasteData;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：function createUriData(uri: string): PasteData;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#createData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard;<br>方法or属性：function createHtmlTextRecord(htmlText: string): PasteDataRecord;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：function createHtmlTextRecord(htmlText: string): PasteDataRecord;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#createRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard;<br>方法or属性：function createWantRecord(want: Want): PasteDataRecord;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：function createWantRecord(want: Want): PasteDataRecord;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#createRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard;<br>方法or属性：function createPlainTextRecord(text: string): PasteDataRecord;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：function createPlainTextRecord(text: string): PasteDataRecord;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#createRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard;<br>方法or属性：function createUriRecord(uri: string): PasteDataRecord;<br>旧版本信息：|类名：pasteboard;<br>方法or属性：function createUriRecord(uri: string): PasteDataRecord;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#createRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteDataRecord;<br>方法or属性：convertToText(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：PasteDataRecord;<br>方法or属性：convertToText(callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#convertToTextV9|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData;<br>方法or属性：addHtmlRecord(htmlText: string): void;<br>旧版本信息：|类名：PasteData;<br>方法or属性：addHtmlRecord(htmlText: string): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#addRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData;<br>方法or属性：addWantRecord(want: Want): void;<br>旧版本信息：|类名：PasteData;<br>方法or属性：addWantRecord(want: Want): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#addRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData;<br>方法or属性：addTextRecord(text: string): void;<br>旧版本信息：|类名：PasteData;<br>方法or属性：addTextRecord(text: string): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#addRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData;<br>方法or属性：addUriRecord(uri: string): void;<br>旧版本信息：|类名：PasteData;<br>方法or属性：addUriRecord(uri: string): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#addRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData;<br>方法or属性：getRecordAt(index: number): PasteDataRecord;<br>旧版本信息：|类名：PasteData;<br>方法or属性：getRecordAt(index: number): PasteDataRecord;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#getRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData;<br>方法or属性：hasMimeType(mimeType: string): boolean;<br>旧版本信息：|类名：PasteData;<br>方法or属性：hasMimeType(mimeType: string): boolean;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#hasType|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData;<br>方法or属性：removeRecordAt(index: number): boolean;<br>旧版本信息：|类名：PasteData;<br>方法or属性：removeRecordAt(index: number): boolean;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#removeRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData;<br>方法or属性：replaceRecordAt(index: number, record: PasteDataRecord): boolean;<br>旧版本信息：|类名：PasteData;<br>方法or属性：replaceRecordAt(index: number, record: PasteDataRecord): boolean;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#replaceRecord|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：clear(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：clear(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#clearData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：getPasteData(callback: AsyncCallback\<PasteData>): void;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：getPasteData(callback: AsyncCallback\<PasteData>): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#getData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：hasPasteData(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：hasPasteData(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#hasData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard;<br>方法or属性：setPasteData(data: PasteData, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：setPasteData(data: PasteData, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.pasteboard.pasteboard#setData|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：request;<br>方法or属性：function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>旧版本信息：|类名：request;<br>方法or属性：function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>新版本信息：9<br>代替接口： ohos.request.downloadFile|@ohos.request.d.ts|
|废弃版本有变化|类名：request;<br>方法or属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>旧版本信息：|类名：request;<br>方法or属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>新版本信息：9,<br>代替接口： ohos.request.downloadFile|@ohos.request.d.ts|
|废弃版本有变化|类名：request;<br>方法or属性：function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>旧版本信息：|类名：request;<br>方法or属性：function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>新版本信息：9<br>代替接口： ohos.request.uploadFile|@ohos.request.d.ts|
|废弃版本有变化|类名：request;<br>方法or属性：function upload(config: UploadConfig): Promise\<UploadTask>;<br>旧版本信息：|类名：request;<br>方法or属性：function upload(config: UploadConfig): Promise\<UploadTask>;<br>新版本信息：9<br>代替接口： ohos.request.uploadFile|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：remove(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：remove(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.request.delete|@ohos.request.d.ts|
|废弃版本有变化|类名：UploadTask;<br>方法or属性：remove(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：remove(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.request.delete|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：remove(): Promise\<boolean>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：remove(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.request.delete|@ohos.request.d.ts|
|废弃版本有变化|类名：UploadTask;<br>方法or属性：remove(): Promise\<boolean>;<br>旧版本信息：|类名：UploadTask;<br>方法or属性：remove(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.request.delete|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：pause(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：pause(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.request.suspend|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：pause(): Promise\<void>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：pause(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.request.suspend|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：resume(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：resume(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.request.restore|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：resume(): Promise\<void>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：resume(): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.request.restore|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：query(callback: AsyncCallback\<DownloadInfo>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：query(callback: AsyncCallback\<DownloadInfo>): void;<br>新版本信息：9<br>代替接口： ohos.request.getTaskInfo|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：query(): Promise\<DownloadInfo>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：query(): Promise\<DownloadInfo>;<br>新版本信息：9<br>代替接口： ohos.request.getTaskInfo|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：queryMimeType(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：queryMimeType(callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.request.getTaskMimeType|@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask;<br>方法or属性：queryMimeType(): Promise\<string>;<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：queryMimeType(): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.request.getTaskMimeType|@ohos.request.d.ts|
|废弃版本有变化|类名：screenLock;<br>方法or属性：function isScreenLocked(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function isScreenLocked(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口：|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock;<br>方法or属性：function isScreenLocked(): Promise\<boolean>;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function isScreenLocked(): Promise\<boolean>;<br>新版本信息：9<br>代替接口：|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock;<br>方法or属性：function isSecureMode(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function isSecureMode(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口：|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock;<br>方法or属性：function isSecureMode(): Promise\<boolean>;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function isSecureMode(): Promise\<boolean>;<br>新版本信息：9<br>代替接口：|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock;<br>方法or属性：function unlockScreen(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function unlockScreen(callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock;<br>方法or属性：function unlockScreen():Promise\<void>;<br>旧版本信息：|类名：screenLock;<br>方法or属性：function unlockScreen():Promise\<void>;<br>新版本信息：9<br>代替接口：|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：declare systemTime<br>旧版本信息：|类名：systemTime;<br>方法or属性：declare systemTime<br>新版本信息：9<br>代替接口： ohos.systemDateTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function setTime(time : number, callback : AsyncCallback\<void>) : void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTime(time : number, callback : AsyncCallback\<void>) : void;<br>新版本信息：9<br>代替接口： ohos.systemDateTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function setTime(time : number) : Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTime(time : number) : Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.systemDateTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function getCurrentTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getCurrentTime(isNano?: boolean): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.systemDateTime/systemDateTime.getCurrentTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.systemDateTime/systemDateTime.getRealActiveTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function getRealTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getRealTime(isNano?: boolean): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.systemDateTime/systemDateTime.getRealTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.systemDateTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.systemDateTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;<br>新版本信息：9<br>代替接口： ohos.systemDateTime/systemDateTime.getDate|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>新版本信息：9<br>代替接口： ohos.systemDateTime/systemDateTime.getDate|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.systemDateTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.systemDateTime|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function getTimezone(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getTimezone(callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.systemDateTime/systemDateTime.getTimezone|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime;<br>方法or属性：function getTimezone(): Promise\<string>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getTimezone(): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.systemDateTime/systemDateTime.getTimezone|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getId(wallpaperType: WallpaperType): Promise\<number>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getId(wallpaperType: WallpaperType): Promise\<number>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getFile(wallpaperType: WallpaperType): Promise\<number>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getFile(wallpaperType: WallpaperType): Promise\<number>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getMinHeight(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getMinHeight(callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getMinHeight(): Promise\<number>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getMinHeight(): Promise\<number>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getMinWidth(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getMinWidth(callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getMinWidth(): Promise\<number>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getMinWidth(): Promise\<number>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function isChangePermitted(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function isChangePermitted(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function isChangePermitted(): Promise\<boolean>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function isChangePermitted(): Promise\<boolean>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function isOperationAllowed(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function isOperationAllowed(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function isOperationAllowed(): Promise\<boolean>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function isOperationAllowed(): Promise\<boolean>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function reset(wallpaperType: WallpaperType): Promise\<void>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function reset(wallpaperType: WallpaperType): Promise\<void>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper;<br>方法or属性：function off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>旧版本信息：|类名：wallpaper;<br>方法or属性：function off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：RgbaColor;<br>方法or属性：interface RgbaColor<br>旧版本信息：|类名：RgbaColor;<br>方法or属性：interface RgbaColor<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：RgbaColor;<br>方法or属性：red: number;<br>旧版本信息：|类名：RgbaColor;<br>方法or属性：red: number;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：RgbaColor;<br>方法or属性：green: number;<br>旧版本信息：|类名：RgbaColor;<br>方法or属性：green: number;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：RgbaColor;<br>方法or属性：blue: number;<br>旧版本信息：|类名：RgbaColor;<br>方法or属性：blue: number;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：RgbaColor;<br>方法or属性：alpha: number;<br>旧版本信息：|类名：RgbaColor;<br>方法or属性：alpha: number;<br>新版本信息：9<br>代替接口：|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：UploadResponse;<br>方法or属性：export interface UploadResponse<br>旧版本信息：|类名：UploadResponse;<br>方法or属性：export interface UploadResponse<br>新版本信息：9,<br>代替接口： ohos.request|@system.request.d.ts|
|废弃版本有变化|类名：UploadResponse;<br>方法or属性：code: number;<br>旧版本信息：|类名：UploadResponse;<br>方法or属性：code: number;<br>新版本信息：9<br>代替接口： ohos.request|@system.request.d.ts|
|废弃版本有变化|类名：UploadResponse;<br>方法or属性：data: string;<br>旧版本信息：|类名：UploadResponse;<br>方法or属性：data: string;<br>新版本信息：9<br>代替接口： ohos.request|@system.request.d.ts|
|废弃版本有变化|类名：UploadResponse;<br>方法or属性：headers: Object;<br>旧版本信息：|类名：UploadResponse;<br>方法or属性：headers: Object;<br>新版本信息：9<br>代替接口： ohos.request|@system.request.d.ts|
|废弃版本有变化|类名：DownloadResponse;<br>方法or属性：export interface DownloadResponse<br>旧版本信息：|类名：DownloadResponse;<br>方法or属性：export interface DownloadResponse<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadResponse;<br>方法or属性：token: string;<br>旧版本信息：|类名：DownloadResponse;<br>方法or属性：token: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions;<br>方法or属性：token: string;<br>旧版本信息：|类名：OnDownloadCompleteOptions;<br>方法or属性：token: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteResponse;<br>方法or属性：export interface OnDownloadCompleteResponse<br>旧版本信息：|类名：OnDownloadCompleteResponse;<br>方法or属性：export interface OnDownloadCompleteResponse<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteResponse;<br>方法or属性：uri: string;<br>旧版本信息：|类名：OnDownloadCompleteResponse;<br>方法or属性：uri: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile;<br>方法or属性：uri: string;<br>旧版本信息：|类名：RequestFile;<br>方法or属性：uri: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile;<br>方法or属性：export interface RequestFile<br>旧版本信息：|类名：RequestFile;<br>方法or属性：export interface RequestFile<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile;<br>方法or属性：filename?: string;<br>旧版本信息：|类名：RequestFile;<br>方法or属性：filename?: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions;<br>方法or属性：filename?: string;<br>旧版本信息：|类名：DownloadRequestOptions;<br>方法or属性：filename?: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile;<br>方法or属性：name?: string;<br>旧版本信息：|类名：RequestFile;<br>方法or属性：name?: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile;<br>方法or属性：type?: string;<br>旧版本信息：|类名：RequestFile;<br>方法or属性：type?: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：RequestData;<br>方法or属性：export interface RequestData<br>旧版本信息：|类名：RequestData;<br>方法or属性：export interface RequestData<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：RequestData;<br>方法or属性：name: string;<br>旧版本信息：|类名：RequestData;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：RequestData;<br>方法or属性：value: string;<br>旧版本信息：|类名：RequestData;<br>方法or属性：value: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：export interface UploadRequestOptions<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：export interface UploadRequestOptions<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：url: string;<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：url: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions;<br>方法or属性：url: string;<br>旧版本信息：|类名：DownloadRequestOptions;<br>方法or属性：url: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：data?: Array\<RequestData>;<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：data?: Array\<RequestData>;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：files: Array\<RequestFile>;<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：files: Array\<RequestFile>;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：header?: Object;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：method?: string;<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：method?: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：success?: (data: UploadResponse) => void;<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：success?: (data: UploadResponse) => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：fail?: (data: any, code: number) => void;<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：fail?: (data: any, code: number) => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions;<br>方法or属性：fail?: (data: any, code: number) => void;<br>旧版本信息：|类名：DownloadRequestOptions;<br>方法or属性：fail?: (data: any, code: number) => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions;<br>方法or属性：fail?: (data: any, code: number) => void;<br>旧版本信息：|类名：OnDownloadCompleteOptions;<br>方法or属性：fail?: (data: any, code: number) => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：UploadRequestOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：DownloadRequestOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：OnDownloadCompleteOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions;<br>方法or属性：export interface DownloadRequestOptions<br>旧版本信息：|类名：DownloadRequestOptions;<br>方法or属性：export interface DownloadRequestOptions<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions;<br>方法or属性：header?: string;<br>旧版本信息：|类名：DownloadRequestOptions;<br>方法or属性：header?: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions;<br>方法or属性：description?: string;<br>旧版本信息：|类名：DownloadRequestOptions;<br>方法or属性：description?: string;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions;<br>方法or属性：success?: (data: DownloadResponse) => void;<br>旧版本信息：|类名：DownloadRequestOptions;<br>方法or属性：success?: (data: DownloadResponse) => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions;<br>方法or属性：export interface OnDownloadCompleteOptions<br>旧版本信息：|类名：OnDownloadCompleteOptions;<br>方法or属性：export interface OnDownloadCompleteOptions<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions;<br>方法or属性：success?: (data: OnDownloadCompleteResponse) => void;<br>旧版本信息：|类名：OnDownloadCompleteOptions;<br>方法or属性：success?: (data: OnDownloadCompleteResponse) => void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：Request;<br>方法or属性：export default class Request<br>旧版本信息：|类名：Request;<br>方法or属性：export default class Request<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：Request;<br>方法or属性：static upload(options: UploadRequestOptions): void;<br>旧版本信息：|类名：Request;<br>方法or属性：static upload(options: UploadRequestOptions): void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：Request;<br>方法or属性：static download(options: DownloadRequestOptions): void;<br>旧版本信息：|类名：Request;<br>方法or属性：static download(options: DownloadRequestOptions): void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|废弃版本有变化|类名：Request;<br>方法or属性：static onDownloadComplete(options: OnDownloadCompleteOptions): void;<br>旧版本信息：|类名：Request;<br>方法or属性：static onDownloadComplete(options: OnDownloadCompleteOptions): void;<br>新版本信息：9<br>代替接口：|@system.request.d.ts|
|新增(错误码)|类名：SystemPasteboard;<br>方法or属性：on(type: 'update', callback: () => void): void;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：on(type: 'update', callback: () => void): void;<br>新版本信息：401|@ohos.pasteboard.d.ts|
|新增(错误码)|类名：SystemPasteboard;<br>方法or属性：off(type: 'update', callback?: () => void): void;<br>旧版本信息：|类名：SystemPasteboard;<br>方法or属性：off(type: 'update', callback?: () => void): void;<br>新版本信息：401|@ohos.pasteboard.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setTime(time : number, callback : AsyncCallback\<void>) : void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTime(time : number, callback : AsyncCallback\<void>) : void;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setTime(time : number) : Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTime(time : number) : Promise\<void>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getCurrentTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getCurrentTime(isNano?: boolean): Promise\<number>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getRealTime(isNano?: boolean): Promise\<number>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getRealTime(isNano?: boolean): Promise\<number>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setDate(date: Date): Promise\<void>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getDate(callback: AsyncCallback\<Date>): void;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getDate(): Promise\<Date>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function setTimezone(timezone: string): Promise\<void>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getTimezone(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getTimezone(callback: AsyncCallback\<string>): void;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTime;<br>方法or属性：function getTimezone(): Promise\<string>;<br>旧版本信息：|类名：systemTime;<br>方法or属性：function getTimezone(): Promise\<string>;<br>新版本信息：-1|@ohos.systemTime.d.ts|
|新增(错误码)|类名：systemTimer;<br>方法or属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>新版本信息：202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|类名：systemTimer;<br>方法or属性：function createTimer(options: TimerOptions): Promise\<number>;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function createTimer(options: TimerOptions): Promise\<number>;<br>新版本信息：202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|类名：systemTimer;<br>方法or属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>新版本信息：202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|类名：systemTimer;<br>方法or属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>新版本信息：202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|类名：systemTimer;<br>方法or属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>新版本信息：202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|类名：systemTimer;<br>方法or属性：function stopTimer(timer: number): Promise\<void>;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function stopTimer(timer: number): Promise\<void>;<br>新版本信息：202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|类名：systemTimer;<br>方法or属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>新版本信息：202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|类名：systemTimer;<br>方法or属性：function destroyTimer(timer: number): Promise\<void>;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function destroyTimer(timer: number): Promise\<void>;<br>新版本信息：202,401|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer;<br>方法or属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer;<br>方法or属性：function createTimer(options: TimerOptions): Promise\<number>;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function createTimer(options: TimerOptions): Promise\<number>;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer;<br>方法or属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer;<br>方法or属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer;<br>方法or属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer;<br>方法or属性：function stopTimer(timer: number): Promise\<void>;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function stopTimer(timer: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer;<br>方法or属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer;<br>方法or属性：function destroyTimer(timer: number): Promise\<void>;<br>旧版本信息：|类名：systemTimer;<br>方法or属性：function destroyTimer(timer: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions;<br>方法or属性：interface TimerOptions<br>旧版本信息：|类名：TimerOptions;<br>方法or属性：interface TimerOptions<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions;<br>方法or属性：type: number;<br>旧版本信息：|类名：TimerOptions;<br>方法or属性：type: number;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions;<br>方法or属性：repeat: boolean;<br>旧版本信息：|类名：TimerOptions;<br>方法or属性：repeat: boolean;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions;<br>方法or属性：interval?: number;<br>旧版本信息：|类名：TimerOptions;<br>方法or属性：interval?: number;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions;<br>方法or属性：wantAgent?: WantAgent;<br>旧版本信息：|类名：TimerOptions;<br>方法or属性：wantAgent?: WantAgent;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions;<br>方法or属性：callback?: () => void;<br>旧版本信息：|类名：TimerOptions;<br>方法or属性：callback?: () => void;<br>新版本信息：systemapi|@ohos.systemTimer.d.ts|
|权限有变化|类名：DownloadTask;<br>方法or属性：interface DownloadTask<br>旧版本信息：|类名：DownloadTask;<br>方法or属性：interface DownloadTask<br>新版本信息：ohos.permission.INTERNET|@ohos.request.d.ts|
|权限有变化|类名：UploadTask;<br>方法or属性：interface UploadTask<br>旧版本信息：|类名：UploadTask;<br>方法or属性：interface UploadTask<br>新版本信息：ohos.permission.INTERNET|@ohos.request.d.ts|
|权限有变化|类名：wallpaper;<br>方法or属性：function getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>旧版本信息：ohos.permission.GET_WALLPAPER,ohos.permission.READ_USER_STORAGE|类名：wallpaper;<br>方法or属性：function getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.GET_WALLPAPER|@ohos.wallpaper.d.ts|
|权限有变化|类名：wallpaper;<br>方法or属性：function getFile(wallpaperType: WallpaperType): Promise\<number>;<br>旧版本信息：ohos.permission.GET_WALLPAPER,ohos.permission.READ_USER_STORAGE|类名：wallpaper;<br>方法or属性：function getFile(wallpaperType: WallpaperType): Promise\<number>;<br>新版本信息：ohos.permission.GET_WALLPAPER|@ohos.wallpaper.d.ts|
|权限有变化|类名：wallpaper;<br>方法or属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>旧版本信息：ohos.permission.GET_WALLPAPER,ohos.permission.READ_USER_STORAGE|类名：wallpaper;<br>方法or属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>新版本信息：ohos.permission.GET_WALLPAPER|@ohos.wallpaper.d.ts|
|权限有变化|类名：wallpaper;<br>方法or属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>旧版本信息：ohos.permission.GET_WALLPAPER,ohos.permission.READ_USER_STORAGE|类名：wallpaper;<br>方法or属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>新版本信息：ohos.permission.GET_WALLPAPER|@ohos.wallpaper.d.ts|
|model有变化|类名：request;<br>方法or属性：function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>旧版本信息：|类名：request;<br>方法or属性：function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>新版本信息：FAModelOnly|@ohos.request.d.ts|
|model有变化|类名：request;<br>方法or属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>旧版本信息：|类名：request;<br>方法or属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>新版本信息：FAModelOnly|@ohos.request.d.ts|
|model有变化|类名：request;<br>方法or属性：function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>旧版本信息：|类名：request;<br>方法or属性：function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>新版本信息：FAModelOnly|@ohos.request.d.ts|
|model有变化|类名：request;<br>方法or属性：function upload(config: UploadConfig): Promise\<UploadTask>;<br>旧版本信息：|类名：request;<br>方法or属性：function upload(config: UploadConfig): Promise\<UploadTask>;<br>新版本信息：FAModelOnly|@ohos.request.d.ts|
