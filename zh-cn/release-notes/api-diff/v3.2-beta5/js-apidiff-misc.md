| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: const MAX_TYPE_NUM: number|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getInputMethodSetting(): InputMethodSetting;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getInputMethodController(): InputMethodController;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getSetting(): InputMethodSetting;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getController(): InputMethodController;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchInputMethod(target: InputMethodProperty, callback: AsyncCallback<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchInputMethod(target: InputMethodProperty): Promise<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getCurrentInputMethod(): InputMethodProperty;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getCurrentInputMethodSubtype(): InputMethodSubtype;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback<Array<InputMethodSubtype>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise<Array<InputMethodSubtype>>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listCurrentInputMethodSubtype(callback: AsyncCallback<Array<InputMethodSubtype>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listCurrentInputMethodSubtype(): Promise<Array<InputMethodSubtype>>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: getInputMethods(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: getInputMethods(enable: boolean): Promise<Array<InputMethodProperty>>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listInputMethod(callback: AsyncCallback<Array<InputMethodProperty>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listInputMethod(): Promise<Array<InputMethodProperty>>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: showOptionalInputMethods(callback: AsyncCallback<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: showOptionalInputMethods(): Promise<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: displayOptionalInputMethod(callback: AsyncCallback<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: displayOptionalInputMethod(): Promise<void>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: stopInputSession(callback: AsyncCallback<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: stopInputSession(): Promise<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: stopInput(callback: AsyncCallback<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: stopInput(): Promise<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: showSoftKeyboard(callback: AsyncCallback<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: showSoftKeyboard():Promise<void>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: hideSoftKeyboard(callback: AsyncCallback<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: hideSoftKeyboard():Promise<void>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty<br>方法 or 属性: readonly packageName: string;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty<br>方法 or 属性: readonly methodId: string;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty<br>方法 or 属性: readonly name: string;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty<br>方法 or 属性: readonly id: string;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty<br>方法 or 属性: readonly label?: string;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty<br>方法 or 属性: readonly icon?: string;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty<br>方法 or 属性: readonly iconId?: number;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodProperty<br>方法 or 属性: extra: object;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const ENTER_KEY_TYPE_UNSPECIFIED: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const ENTER_KEY_TYPE_GO: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const ENTER_KEY_TYPE_SEARCH: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const ENTER_KEY_TYPE_SEND: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const ENTER_KEY_TYPE_NEXT: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const ENTER_KEY_TYPE_DONE: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const ENTER_KEY_TYPE_PREVIOUS: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const PATTERN_NULL: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const PATTERN_TEXT: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const PATTERN_NUMBER: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const PATTERN_PHONE: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const PATTERN_DATETIME: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const PATTERN_EMAIL: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const PATTERN_URI: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const PATTERN_PASSWORD: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const FLAG_SELECTING: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const FLAG_SINGLE_LINE: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const DISPLAY_MODE_PART: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const DISPLAY_MODE_FULL: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const OPTION_ASCII: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const OPTION_NONE: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const OPTION_AUTO_CAP_CHARACTERS: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const OPTION_AUTO_CAP_SENTENCES: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const OPTION_AUTO_WORDS: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const OPTION_MULTI_LINE: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const OPTION_NO_FULLSCREEN: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const CURSOR_UP: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const CURSOR_DOWN: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const CURSOR_LEFT: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const CURSOR_RIGHT: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: const WINDOW_TYPE_INPUT_METHOD_FLOAT: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: function getInputMethodAbility(): InputMethodAbility;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: function getInputMethodEngine(): InputMethodEngine;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: function getKeyboardDelegate(): KeyboardDelegate;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: inputMethodEngine<br>方法 or 属性: function createKeyboardDelegate(): KeyboardDelegate;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController<br>方法 or 属性: hide(callback: AsyncCallback<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController<br>方法 or 属性: hide(): Promise<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController<br>方法 or 属性: hideKeyboard(callback: AsyncCallback<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController<br>方法 or 属性: hideKeyboard(): Promise<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodEngine|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodEngine<br>方法 or 属性: on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodEngine<br>方法 or 属性: off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodEngine<br>方法 or 属性: on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodEngine<br>方法 or 属性: on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodEngine<br>方法 or 属性: off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodEngine<br>方法 or 属性: off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: on(type: 'inputStop', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: off(type: 'inputStop', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: on(type: 'setCallingWindow', callback: (wid:number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: off(type: 'setCallingWindow', callback: (wid:number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputMethodAbility<br>方法 or 属性: off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: sendKeyFunction(action: number, callback: AsyncCallback<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: sendKeyFunction(action: number): Promise<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: deleteForward(length: number, callback: AsyncCallback<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: deleteForward(length: number): Promise<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: deleteBackward(length: number, callback: AsyncCallback<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: deleteBackward(length: number): Promise<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: insertText(text: string, callback: AsyncCallback<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: insertText(text: string): Promise<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getForward(length: number, callback: AsyncCallback<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getForward(length: number): Promise<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getBackward(length: number, callback: AsyncCallback<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getBackward(length: number): Promise<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getEditorAttribute(callback: AsyncCallback<EditorAttribute>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getEditorAttribute(): Promise<EditorAttribute>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: sendKeyFunction(action: number, callback: AsyncCallback<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: sendKeyFunction(action: number): Promise<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: deleteForward(length: number, callback: AsyncCallback<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: deleteForward(length: number): Promise<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: deleteBackward(length: number, callback: AsyncCallback<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: deleteBackward(length: number): Promise<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: insertText(text: string, callback: AsyncCallback<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: insertText(text: string): Promise<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getForward(length: number, callback: AsyncCallback<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getForward(length: number): Promise<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getBackward(length: number, callback: AsyncCallback<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getBackward(length: number): Promise<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getEditorAttribute(callback: AsyncCallback<EditorAttribute>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getEditorAttribute(): Promise<EditorAttribute>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: moveCursor(direction: number, callback: AsyncCallback<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: moveCursor(direction: number): Promise<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: on(type: 'cursorContextChange', callback: (x: number, y: number, height: number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: on(type: 'textChange', callback: (text: string) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardDelegate<br>方法 or 属性: off(type: 'textChange', callback?: (text: string) => void): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: EditorAttribute|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: EditorAttribute<br>方法 or 属性: readonly inputPattern: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: EditorAttribute<br>方法 or 属性: readonly enterKeyType: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyEvent|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyEvent<br>方法 or 属性: readonly keyCode: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyEvent<br>方法 or 属性: readonly keyAction: number;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.InputMethodExtensionAbility<br>类名: InputMethodExtensionAbility|@ohos.InputMethodExtensionAbility.d.ts|
|新增|NA|模块名: ohos.InputMethodExtensionAbility<br>类名: InputMethodExtensionAbility<br>方法 or 属性: context: InputMethodExtensionContext;|@ohos.InputMethodExtensionAbility.d.ts|
|新增|NA|模块名: ohos.InputMethodExtensionAbility<br>类名: InputMethodExtensionAbility<br>方法 or 属性: onCreate(want: Want): void;|@ohos.InputMethodExtensionAbility.d.ts|
|新增|NA|模块名: ohos.InputMethodExtensionAbility<br>类名: InputMethodExtensionAbility<br>方法 or 属性: onDestroy(): void;|@ohos.InputMethodExtensionAbility.d.ts|
|新增|NA|模块名: ohos.InputMethodExtensionContext<br>类名: InputMethodExtensionContext|@ohos.InputMethodExtensionContext.d.ts|
|新增|NA|模块名: ohos.InputMethodExtensionContext<br>类名: InputMethodExtensionContext<br>方法 or 属性: destroy(callback: AsyncCallback<void>): void;|@ohos.InputMethodExtensionContext.d.ts|
|新增|NA|模块名: ohos.InputMethodExtensionContext<br>类名: InputMethodExtensionContext<br>方法 or 属性: destroy(): Promise<void>;|@ohos.InputMethodExtensionContext.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: readonly label?: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: readonly name: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: readonly id: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: readonly mode?: 'upper'\|'lower';|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: readonly locale: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: readonly language: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: readonly icon?: string;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: readonly iconId?: number;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.InputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性: extra: object;|@ohos.InputMethodSubtype.d.ts|
|新增|NA|模块名: ohos.request<br>类名: request<br>方法 or 属性：const PAUSED_BY_USER: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const PAUSED_BY_USER: number;|@ohos.request.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setTime(time : number, callback : AsyncCallback<void>) : void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setTime(time : number) : Promise<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getCurrentTime(isNano: boolean, callback: AsyncCallback<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getCurrentTime(callback: AsyncCallback<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getCurrentTime(isNano?: boolean): Promise<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealActiveTime(isNano: boolean, callback: AsyncCallback<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealActiveTime(callback: AsyncCallback<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealActiveTime(isNano?: boolean): Promise<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealTime(isNano: boolean, callback: AsyncCallback<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealTime(callback: AsyncCallback<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealTime(isNano?: boolean): Promise<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setDate(date: Date, callback: AsyncCallback<void>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setDate(date: Date): Promise<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getDate(callback: AsyncCallback<Date>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getDate(): Promise<Date>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setTimezone(timezone: string, callback: AsyncCallback<void>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setTimezone(timezone: string): Promise<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getTimezone(callback: AsyncCallback<string>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getTimezone(): Promise<string>;|@ohos.systemDateTime.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：const MAX_TYPE_NUM: number|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function getInputMethodSetting(): InputMethodSetting;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function getInputMethodController(): InputMethodController;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function getSetting(): InputMethodSetting;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function getController(): InputMethodController;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function switchInputMethod(target: InputMethodProperty, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function switchInputMethod(target: InputMethodProperty): Promise<boolean>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function getCurrentInputMethod(): InputMethodProperty;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise<boolean>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function getCurrentInputMethodSubtype(): InputMethodSubtype;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise<boolean>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback<Array<InputMethodSubtype>>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise<Array<InputMethodSubtype>>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：listCurrentInputMethodSubtype(callback: AsyncCallback<Array<InputMethodSubtype>>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：listCurrentInputMethodSubtype(): Promise<Array<InputMethodSubtype>>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：getInputMethods(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：getInputMethods(enable: boolean): Promise<Array<InputMethodProperty>>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：listInputMethod(callback: AsyncCallback<Array<InputMethodProperty>>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：listInputMethod(): Promise<Array<InputMethodProperty>>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：showOptionalInputMethods(callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：showOptionalInputMethods(): Promise<boolean>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：displayOptionalInputMethod(callback: AsyncCallback<void>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：displayOptionalInputMethod(): Promise<void>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：stopInputSession(callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：stopInputSession(): Promise<boolean>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：stopInput(callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：stopInput(): Promise<boolean>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：showSoftKeyboard(callback: AsyncCallback<void>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：showSoftKeyboard():Promise<void>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：hideSoftKeyboard(callback: AsyncCallback<void>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：hideSoftKeyboard():Promise<void>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly packageName: string;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly methodId: string;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly name: string;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly id: string;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly label?: string;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly icon?: string;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly iconId?: number;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：extra: object;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const ENTER_KEY_TYPE_UNSPECIFIED: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const ENTER_KEY_TYPE_GO: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const ENTER_KEY_TYPE_SEARCH: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const ENTER_KEY_TYPE_SEND: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const ENTER_KEY_TYPE_NEXT: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const ENTER_KEY_TYPE_DONE: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const ENTER_KEY_TYPE_PREVIOUS: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const PATTERN_NULL: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const PATTERN_TEXT: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const PATTERN_NUMBER: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const PATTERN_PHONE: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const PATTERN_DATETIME: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const PATTERN_EMAIL: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const PATTERN_URI: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const PATTERN_PASSWORD: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const FLAG_SELECTING: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const FLAG_SINGLE_LINE: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const DISPLAY_MODE_PART: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const DISPLAY_MODE_FULL: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const OPTION_ASCII: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const OPTION_NONE: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const OPTION_AUTO_CAP_CHARACTERS: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const OPTION_AUTO_CAP_SENTENCES: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const OPTION_AUTO_WORDS: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const OPTION_MULTI_LINE: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const OPTION_NO_FULLSCREEN: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const CURSOR_UP: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const CURSOR_DOWN: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const CURSOR_LEFT: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const CURSOR_RIGHT: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：const WINDOW_TYPE_INPUT_METHOD_FLOAT: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：function getInputMethodAbility(): InputMethodAbility;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：function getInputMethodEngine(): InputMethodEngine;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：function getKeyboardDelegate(): KeyboardDelegate;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：function createKeyboardDelegate(): KeyboardDelegate;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardController|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardController<br>方法 or 属性：hide(callback: AsyncCallback<void>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardController<br>方法 or 属性：hide(): Promise<void>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardController<br>方法 or 属性：hideKeyboard(callback: AsyncCallback<void>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardController<br>方法 or 属性：hideKeyboard(): Promise<void>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：on(type: 'inputStop', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：off(type: 'inputStop', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：on(type: 'setCallingWindow', callback: (wid:number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：off(type: 'setCallingWindow', callback: (wid:number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodAbility<br>方法 or 属性：off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：sendKeyFunction(action: number, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：sendKeyFunction(action: number): Promise<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：deleteForward(length: number, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：deleteForward(length: number): Promise<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：deleteBackward(length: number, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：deleteBackward(length: number): Promise<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：insertText(text: string, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：insertText(text: string): Promise<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getForward(length: number, callback: AsyncCallback<string>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getForward(length: number): Promise<string>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getBackward(length: number, callback: AsyncCallback<string>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getBackward(length: number): Promise<string>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getEditorAttribute(callback: AsyncCallback<EditorAttribute>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getEditorAttribute(): Promise<EditorAttribute>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：sendKeyFunction(action: number, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：sendKeyFunction(action: number): Promise<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：deleteForward(length: number, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：deleteForward(length: number): Promise<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：deleteBackward(length: number, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：deleteBackward(length: number): Promise<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：insertText(text: string, callback: AsyncCallback<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：insertText(text: string): Promise<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：getForward(length: number, callback: AsyncCallback<string>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：getForward(length: number): Promise<string>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：getBackward(length: number, callback: AsyncCallback<string>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：getBackward(length: number): Promise<string>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：getEditorAttribute(callback: AsyncCallback<EditorAttribute>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：getEditorAttribute(): Promise<EditorAttribute>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：moveCursor(direction: number, callback: AsyncCallback<void>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputClient<br>方法 or 属性：moveCursor(direction: number): Promise<void>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：on(type: 'keyDown'\|'keyUp', callback: (event: KeyEvent) => boolean): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：off(type: 'keyDown'\|'keyUp', callback?: (event: KeyEvent) => boolean): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：on(type: 'cursorContextChange', callback: (x: number, y: number, height: number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：on(type: 'textChange', callback: (text: string) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardDelegate<br>方法 or 属性：off(type: 'textChange', callback?: (text: string) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: EditorAttribute|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: EditorAttribute<br>方法 or 属性：readonly inputPattern: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: EditorAttribute<br>方法 or 属性：readonly enterKeyType: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyEvent|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyEvent<br>方法 or 属性：readonly keyCode: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyEvent<br>方法 or 属性：readonly keyAction: number;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodextensionability<br>类名: InputMethodExtensionAbility|NA|@ohos.inputmethodextensionability.d.ts|
|删除|模块名: ohos.inputmethodextensionability<br>类名: InputMethodExtensionAbility<br>方法 or 属性：context: InputMethodExtensionContext;|NA|@ohos.inputmethodextensionability.d.ts|
|删除|模块名: ohos.inputmethodextensionability<br>类名: InputMethodExtensionAbility<br>方法 or 属性：onCreate(want: Want): void;|NA|@ohos.inputmethodextensionability.d.ts|
|删除|模块名: ohos.inputmethodextensionability<br>类名: InputMethodExtensionAbility<br>方法 or 属性：onDestroy(): void;|NA|@ohos.inputmethodextensionability.d.ts|
|删除|模块名: ohos.inputmethodextensioncontext<br>类名: InputMethodExtensionContext|NA|@ohos.inputmethodextensioncontext.d.ts|
|删除|模块名: ohos.inputmethodextensioncontext<br>类名: InputMethodExtensionContext<br>方法 or 属性：destroy(callback: AsyncCallback<void>): void;|NA|@ohos.inputmethodextensioncontext.d.ts|
|删除|模块名: ohos.inputmethodextensioncontext<br>类名: InputMethodExtensionContext<br>方法 or 属性：destroy(): Promise<void>;|NA|@ohos.inputmethodextensioncontext.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：readonly label?: string;|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：readonly name: string;|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：readonly id: string;|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：readonly mode?: 'upper'\|'lower';|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：readonly locale: string;|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：readonly language: string;|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：readonly icon?: string;|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：readonly iconId?: number;|NA|@ohos.inputMethodSubtype.d.ts|
|删除|模块名: ohos.inputMethodSubtype<br>类名: InputMethodSubtype<br>方法 or 属性：extra: object;|NA|@ohos.inputMethodSubtype.d.ts|
|访问级别有变化|类名：SystemEvent<br>访问级别：公开API|类名：SystemEvent<br>访问级别：系统API|@ohos.screenLock.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise<number>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise<number>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>访问级别：公开API|类名：TimerOptions<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：type: number;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：type: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|废弃版本有变化|类名：systemTime<br>废弃版本：N/A|类名：systemTime<br>废弃版本：9<br>代替接口：ohos.systemDateTime |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setTime(time : number, callback : AsyncCallback<void>) : void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setTime(time : number, callback : AsyncCallback<void>) : void;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setTime(time : number) : Promise<void>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setTime(time : number) : Promise<void>;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano: boolean, callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano: boolean, callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getCurrentTime     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getCurrentTime(callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getCurrentTime(callback: AsyncCallback<number>): void;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano?: boolean): Promise<number>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano?: boolean): Promise<number>;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano: boolean, callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano: boolean, callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getRealActiveTime     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getRealActiveTime(callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getRealActiveTime(callback: AsyncCallback<number>): void;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano?: boolean): Promise<number>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano?: boolean): Promise<number>;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getRealTime(isNano: boolean, callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getRealTime(isNano: boolean, callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getRealTime     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getRealTime(callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getRealTime(callback: AsyncCallback<number>): void;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getRealTime(isNano?: boolean): Promise<number>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getRealTime(isNano?: boolean): Promise<number>;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setDate(date: Date, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setDate(date: Date, callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setDate(date: Date): Promise<void>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setDate(date: Date): Promise<void>;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getDate(callback: AsyncCallback<Date>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getDate(callback: AsyncCallback<Date>): void;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getDate     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getDate(): Promise<Date>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getDate(): Promise<Date>;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setTimezone(timezone: string, callback: AsyncCallback<void>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setTimezone(timezone: string, callback: AsyncCallback<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setTimezone(timezone: string): Promise<void>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setTimezone(timezone: string): Promise<void>;<br>废弃版本：9|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getTimezone(callback: AsyncCallback<string>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getTimezone(callback: AsyncCallback<string>): void;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getTimezone     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getTimezone(): Promise<string>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getTimezone(): Promise<string>;<br>废弃版本：9|@ohos.systemTime.d.ts|
|起始版本有变化|类名：DownloadTask<br>起始版本：N/A|类名：DownloadTask<br>起始版本：6|@ohos.request.d.ts|
|起始版本有变化|类名：UploadTask<br>起始版本：N/A|类名：UploadTask<br>起始版本：6|@ohos.request.d.ts|
|起始版本有变化|类名：SystemEvent<br>起始版本：N/A|类名：SystemEvent<br>起始版本：9|@ohos.screenLock.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise<number>;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise<number>;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise<void>;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise<void>;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback<void>): void;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback<void>): void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise<void>;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise<void>;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback<void>): void;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback<void>): void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise<void>;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise<void>;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>起始版本：N/A|类名：TimerOptions<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：type: number;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：type: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：DownloadTask<br>方法 or 属性：delete(): Promise<boolean>;<br>错误码内容:N/A|@ohos.request.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise<number>;<br>错误码内容:202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise<void>;<br>错误码内容:202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise<void>;<br>错误码内容:202,401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise<void>;<br>错误码内容:202,401|@ohos.systemTimer.d.ts|
|新增(权限)|类名：DownloadTask<br>权限:N/A|类名：DownloadTask<br>权限:ohos.permission.INTERNET|@ohos.request.d.ts|
|新增(权限)|类名：UploadTask<br>权限:N/A|类名：UploadTask<br>权限:ohos.permission.INTERNET|@ohos.request.d.ts|
|访问级别有变化|类名：SystemEvent<br>访问级别：公开API|类名：SystemEvent<br>访问级别：系统API|@ohos.screenLock.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback<number>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise<number>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise<number>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>访问级别：公开API|类名：TimerOptions<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：type: number;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：type: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
