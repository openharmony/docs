| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: const MAX_TYPE_NUM: number|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getInputMethodSetting(): InputMethodSetting;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getInputMethodController(): InputMethodController;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getSetting(): InputMethodSetting;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getController(): InputMethodController;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchInputMethod(target: InputMethodProperty, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchInputMethod(target: InputMethodProperty): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getCurrentInputMethod(): InputMethodProperty;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function getCurrentInputMethodSubtype(): InputMethodSubtype;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: inputMethod<br>方法 or 属性: function switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback\<Array\<InputMethodSubtype>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise\<Array\<InputMethodSubtype>>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listCurrentInputMethodSubtype(callback: AsyncCallback\<Array\<InputMethodSubtype>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listCurrentInputMethodSubtype(): Promise\<Array\<InputMethodSubtype>>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: getInputMethods(enable: boolean, callback: AsyncCallback\<Array\<InputMethodProperty>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: getInputMethods(enable: boolean): Promise\<Array\<InputMethodProperty>>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listInputMethod(callback: AsyncCallback\<Array\<InputMethodProperty>>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: listInputMethod(): Promise\<Array\<InputMethodProperty>>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: showOptionalInputMethods(callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: showOptionalInputMethods(): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: displayOptionalInputMethod(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodSetting<br>方法 or 属性: displayOptionalInputMethod(): Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: stopInputSession(callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: stopInputSession(): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: stopInput(callback: AsyncCallback\<boolean>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: stopInput(): Promise\<boolean>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: showSoftKeyboard(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: showSoftKeyboard():Promise\<void>;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: hideSoftKeyboard(callback: AsyncCallback\<void>): void;|@ohos.inputMethod.d.ts|
|新增|NA|模块名: ohos.inputMethod<br>类名: InputMethodController<br>方法 or 属性: hideSoftKeyboard():Promise\<void>;|@ohos.inputMethod.d.ts|
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
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController<br>方法 or 属性: hide(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController<br>方法 or 属性: hide(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController<br>方法 or 属性: hideKeyboard(callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: KeyboardController<br>方法 or 属性: hideKeyboard(): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
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
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: sendKeyFunction(action: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: deleteForward(length: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: deleteForward(length: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: deleteBackward(length: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: deleteBackward(length: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: insertText(text: string, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: insertText(text: string): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getForward(length: number, callback: AsyncCallback\<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getForward(length: number): Promise\<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getBackward(length: number, callback: AsyncCallback\<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getBackward(length: number): Promise\<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: TextInputClient<br>方法 or 属性: getEditorAttribute(): Promise\<EditorAttribute>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: sendKeyFunction(action: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: deleteForward(length: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: deleteForward(length: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: deleteBackward(length: number, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: deleteBackward(length: number): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: insertText(text: string, callback: AsyncCallback\<boolean>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: insertText(text: string): Promise\<boolean>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getForward(length: number, callback: AsyncCallback\<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getForward(length: number): Promise\<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getBackward(length: number, callback: AsyncCallback\<string>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getBackward(length: number): Promise\<string>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: getEditorAttribute(): Promise\<EditorAttribute>;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: moveCursor(direction: number, callback: AsyncCallback\<void>): void;|@ohos.inputMethodEngine.d.ts|
|新增|NA|模块名: ohos.inputMethodEngine<br>类名: InputClient<br>方法 or 属性: moveCursor(direction: number): Promise\<void>;|@ohos.inputMethodEngine.d.ts|
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
|新增|NA|模块名: ohos.InputMethodExtensionContext<br>类名: InputMethodExtensionContext<br>方法 or 属性: destroy(callback: AsyncCallback\<void>): void;|@ohos.InputMethodExtensionContext.d.ts|
|新增|NA|模块名: ohos.InputMethodExtensionContext<br>类名: InputMethodExtensionContext<br>方法 or 属性: destroy(): Promise\<void>;|@ohos.InputMethodExtensionContext.d.ts|
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
|新增|NA|类名：pasteboard<br>方法or属性：const MIMETYPE_PIXELMAP: string;|@ohos.pasteboard.d.ts|
|新增|NA|类名：pasteboard<br>方法or属性：function createData(mimeType: string, value: ValueType): PasteData;|@ohos.pasteboard.d.ts|
|新增|NA|类名：pasteboard<br>方法or属性：function createRecord(mimeType: string, value: ValueType): PasteDataRecord;|@ohos.pasteboard.d.ts|
|新增|NA|模块名: ohos.pasteboard<br>类名: ShareOption|@ohos.pasteboard.d.ts|
|新增|NA|类名：ShareOption<br>方法or属性：|@ohos.pasteboard.d.ts|
|新增|NA|模块名: ohos.pasteboard<br>类名: ShareOption<br>方法 or 属性：INAPP|@ohos.pasteboard.d.ts|
|新增|NA|类名：ShareOption<br>方法or属性：INAPP|@ohos.pasteboard.d.ts|
|新增|NA|模块名: ohos.pasteboard<br>类名: ShareOption<br>方法 or 属性：LOCALDEVICE|@ohos.pasteboard.d.ts|
|新增|NA|类名：ShareOption<br>方法or属性：LOCALDEVICE|@ohos.pasteboard.d.ts|
|新增|NA|模块名: ohos.pasteboard<br>类名: ShareOption<br>方法 or 属性：CROSSDEVICE|@ohos.pasteboard.d.ts|
|新增|NA|类名：ShareOption<br>方法or属性：CROSSDEVICE|@ohos.pasteboard.d.ts|
|新增|NA|模块名: ohos.pasteboard<br>类名: PasteDataProperty<br>方法 or 属性：shareOption: ShareOption;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteDataProperty<br>方法or属性：shareOption: ShareOption;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteDataRecord<br>方法or属性：pixelMap: image.PixelMap;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteDataRecord<br>方法or属性：data: {<br><br>      [mimeType: string]: ArrayBuffer<br><br>    }|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteDataRecord<br>方法or属性：toPlainText(): string;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData<br>方法or属性：addRecord(mimeType: string, value: ValueType): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData<br>方法or属性：getPrimaryPixelMap(): image.PixelMap;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData<br>方法or属性：setProperty(property: PasteDataProperty): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData<br>方法or属性：getRecord(index: number): PasteDataRecord;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData<br>方法or属性：hasType(mimeType: string): boolean;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData<br>方法or属性：removeRecord(index: number): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：PasteData<br>方法or属性：replaceRecord(index: number, record: PasteDataRecord): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard<br>方法or属性：clearData(callback: AsyncCallback\<void>): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard<br>方法or属性：clearData(): Promise\<void>;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard<br>方法or属性：getData(callback: AsyncCallback\<PasteData>): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard<br>方法or属性：getData(): Promise\<PasteData>;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard<br>方法or属性：hasData(callback: AsyncCallback\<boolean>): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard<br>方法or属性：hasData(): Promise\<boolean>;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard<br>方法or属性：setData(data: PasteData, callback: AsyncCallback\<void>): void;|@ohos.pasteboard.d.ts|
|新增|NA|类名：SystemPasteboard<br>方法or属性：setData(data: PasteData): Promise\<void>;|@ohos.pasteboard.d.ts|
|新增|NA|类名：request<br>方法or属性：const EXCEPTION_PERMISSION: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const EXCEPTION_PARAMCHECK: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const EXCEPTION_UNSUPPORTED: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const EXCEPTION_FILEIO: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const EXCEPTION_FILEPATH: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const EXCEPTION_SERVICE: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const EXCEPTION_OTHERS: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const ERROR_OFFLINE: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const ERROR_UNSUPPORTED_NETWORK_TYPE: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：const PAUSED_BY_USER: number;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：function downloadFile(context: BaseContext, config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：function downloadFile(context: BaseContext, config: DownloadConfig): Promise\<DownloadTask>;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：function uploadFile(context: BaseContext, config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;|@ohos.request.d.ts|
|新增|NA|类名：request<br>方法or属性：function uploadFile(context: BaseContext, config: UploadConfig): Promise\<UploadTask>;|@ohos.request.d.ts|
|新增|NA|模块名: ohos.request<br>类名: DownloadConfig<br>方法 or 属性：background?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：DownloadConfig<br>方法or属性：background?: boolean;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：delete(callback: AsyncCallback\<boolean>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：delete(): Promise\<boolean>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：suspend(callback: AsyncCallback\<boolean>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：suspend(): Promise\<boolean>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：restore(callback: AsyncCallback\<boolean>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：restore(): Promise\<boolean>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：getTaskInfo(callback: AsyncCallback\<DownloadInfo>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：getTaskInfo(): Promise\<DownloadInfo>;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：getTaskMimeType(callback: AsyncCallback\<string>): void;|@ohos.request.d.ts|
|新增|NA|类名：DownloadTask<br>方法or属性：getTaskMimeType(): Promise\<string>;|@ohos.request.d.ts|
|新增|NA|模块名: ohos.request<br>类名: TaskState|@ohos.request.d.ts|
|新增|NA|类名：TaskState<br>方法or属性：|@ohos.request.d.ts|
|新增|NA|模块名: ohos.request<br>类名: TaskState<br>方法 or 属性：path: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskState<br>方法or属性：path: string;|@ohos.request.d.ts|
|新增|NA|模块名: ohos.request<br>类名: TaskState<br>方法 or 属性：responseCode: number;|@ohos.request.d.ts|
|新增|NA|类名：TaskState<br>方法or属性：responseCode: number;|@ohos.request.d.ts|
|新增|NA|模块名: ohos.request<br>类名: TaskState<br>方法 or 属性：message: string;|@ohos.request.d.ts|
|新增|NA|类名：TaskState<br>方法or属性：message: string;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask<br>方法or属性：on(type:'complete' \| 'fail', callback: Callback\<Array\<TaskState>>): void;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask<br>方法or属性：on(type:'complete' \| 'fail', callback: Callback\<Array\<TaskState>>): void;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask<br>方法or属性：off(type:'complete' \| 'fail', callback?: Callback\<Array\<TaskState>>): void;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask<br>方法or属性：off(type:'complete' \| 'fail', callback?: Callback\<Array\<TaskState>>): void;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask<br>方法or属性：delete(callback: AsyncCallback\<boolean>): void;|@ohos.request.d.ts|
|新增|NA|类名：UploadTask<br>方法or属性：delete(): Promise\<boolean>;|@ohos.request.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: EventType<br>方法 or 属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：EventType<br>方法or属性：type EventType =<br><br>      'beginWakeUp'<br><br>      \| 'endWakeUp'<br><br>      \| 'beginScreenOn'<br><br>      \| 'endScreenOn'<br><br>      \| 'beginScreenOff'<br><br>      \| 'endScreenOff'<br><br>      \| 'unlockScreen'<br><br>      \| 'lockScreen'<br><br>      \| 'beginExitAnimation'<br><br>      \| 'beginSleep'<br><br>      \| 'endSleep'<br><br>      \| 'changeUser'<br><br>      \| 'screenlockEnabled'<br><br>      \| 'serviceRestart'|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock<br>方法or属性：function isLocked(): boolean;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock<br>方法or属性：function unlock(callback: AsyncCallback\<boolean>): void;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock<br>方法or属性：function unlock():Promise\<boolean>;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock<br>方法or属性：function lock(callback: AsyncCallback\<boolean>): void;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock<br>方法or属性：function lock():Promise\<boolean>;|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: SystemEvent|@ohos.screenLock.d.ts|
|新增|NA|类名：SystemEvent<br>方法or属性：|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: SystemEvent<br>方法 or 属性：eventType: EventType,|@ohos.screenLock.d.ts|
|新增|NA|类名：SystemEvent<br>方法or属性：eventType: EventType,|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.screenLock<br>类名: SystemEvent<br>方法 or 属性：params: string|@ohos.screenLock.d.ts|
|新增|NA|类名：SystemEvent<br>方法or属性：params: string|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock<br>方法or属性：function onSystemEvent(callback: Callback\<SystemEvent>): boolean;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;|@ohos.screenLock.d.ts|
|新增|NA|类名：screenLock<br>方法or属性：function sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>;|@ohos.screenLock.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setTime(time : number, callback : AsyncCallback\<void>) : void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setTime(time : number) : Promise\<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getCurrentTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getCurrentTime(callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getCurrentTime(isNano?: boolean): Promise\<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealActiveTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealActiveTime(callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealActiveTime(isNano?: boolean): Promise\<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealTime(isNano: boolean, callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealTime(callback: AsyncCallback\<number>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getRealTime(isNano?: boolean): Promise\<number>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setDate(date: Date, callback: AsyncCallback\<void>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setDate(date: Date): Promise\<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getDate(callback: AsyncCallback\<Date>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getDate(): Promise\<Date>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function setTimezone(timezone: string): Promise\<void>;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getTimezone(callback: AsyncCallback\<string>): void;|@ohos.systemDateTime.d.ts|
|新增|NA|模块名: ohos.systemDateTime<br>类名: systemDateTime<br>方法 or 属性: function getTimezone(): Promise\<string>;|@ohos.systemDateTime.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function getColorsSync(wallpaperType: WallpaperType): Array\<RgbaColor>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function getMinHeightSync(): number;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function getMinWidthSync(): number;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function restore(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function restore(wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function setImage(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function setImage(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function getImage(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;|@ohos.wallpaper.d.ts|
|新增|NA|类名：wallpaper<br>方法or属性：function getImage(wallpaperType: WallpaperType): Promise\<image.PixelMap>;|@ohos.wallpaper.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：const MAX_TYPE_NUM: number|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function getInputMethodSetting(): InputMethodSetting;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: inputMethod<br>方法 or 属性：function getInputMethodController(): InputMethodController;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：listInputMethod(callback: AsyncCallback\<Array\<InputMethodProperty>>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：listInputMethod(): Promise\<Array\<InputMethodProperty>>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：displayOptionalInputMethod(callback: AsyncCallback\<void>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodSetting<br>方法 or 属性：displayOptionalInputMethod(): Promise\<void>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：stopInput(callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodController<br>方法 or 属性：stopInput(): Promise\<boolean>;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly packageName: string;|NA|@ohos.inputmethod.d.ts|
|删除|模块名: ohos.inputmethod<br>类名: InputMethodProperty<br>方法 or 属性：readonly methodId: string;|NA|@ohos.inputmethod.d.ts|
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
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：function getInputMethodEngine(): InputMethodEngine;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: inputMethodEngine<br>方法 or 属性：function createKeyboardDelegate(): KeyboardDelegate;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardController|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardController<br>方法 or 属性：hideKeyboard(callback: AsyncCallback\<void>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: KeyboardController<br>方法 or 属性：hideKeyboard(): Promise\<void>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：on(type: 'keyboardShow'\|'keyboardHide', callback: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: InputMethodEngine<br>方法 or 属性：off(type: 'keyboardShow'\|'keyboardHide', callback?: () => void): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：sendKeyFunction(action: number): Promise\<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：deleteForward(length: number, callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：deleteForward(length: number): Promise\<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：deleteBackward(length: number, callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：deleteBackward(length: number): Promise\<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：insertText(text: string, callback: AsyncCallback\<boolean>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：insertText(text: string): Promise\<boolean>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getForward(length: number, callback: AsyncCallback\<string>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getForward(length: number): Promise\<string>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getBackward(length: number, callback: AsyncCallback\<string>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getBackward(length: number): Promise\<string>;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void;|NA|@ohos.inputmethodengine.d.ts|
|删除|模块名: ohos.inputmethodengine<br>类名: TextInputClient<br>方法 or 属性：getEditorAttribute(): Promise\<EditorAttribute>;|NA|@ohos.inputmethodengine.d.ts|
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
|删除|模块名：ohos.wallpaper<br>类名:wallpaper<br>方法 or 属性:function screenshotLiveWallpaper(scale: number, pixelFormat: image.PixelMapFormat, callback: AsyncCallback\<image.PixelMap>): void;|NA|@ohos.wallpaper.d.ts|
|删除|模块名：ohos.wallpaper<br>类名:wallpaper<br>方法 or 属性:function screenshotLiveWallpaper(scale: number, pixelFormat: image.PixelMapFormat): Promise\<image.PixelMap>;|NA|@ohos.wallpaper.d.ts|
|model有变化|类名：request<br>方法 or 属性：function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>model:N/A|类名：request<br>方法 or 属性：function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>model:@FAModelOnly|@ohos.request.d.ts|
|model有变化|类名：request<br>方法 or 属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>model:N/A|类名：request<br>方法 or 属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>model:@FAModelOnly|@ohos.request.d.ts|
|model有变化|类名：request<br>方法 or 属性：function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>model:N/A|类名：request<br>方法 or 属性：function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>model:@FAModelOnly|@ohos.request.d.ts|
|model有变化|类名：request<br>方法 or 属性：function upload(config: UploadConfig): Promise\<UploadTask>;<br>model:N/A|类名：request<br>方法 or 属性：function upload(config: UploadConfig): Promise\<UploadTask>;<br>model:@FAModelOnly|@ohos.request.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise\<number>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise\<number>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise\<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise\<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise\<void>;<br>访问级别：公开API|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise\<void>;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>访问级别：公开API|类名：TimerOptions<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：type: number;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：type: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|访问级别有变化|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>访问级别：公开API|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>访问级别：系统API|@ohos.systemTimer.d.ts|
|废弃版本有变化|类名：pasteboard<br>方法 or 属性：function createHtmlData(htmlText: string): PasteData;<br>废弃版本：N/A|类名：pasteboard<br>方法 or 属性：function createHtmlData(htmlText: string): PasteData;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard<br>方法 or 属性：function createWantData(want: Want): PasteData;<br>废弃版本：N/A|类名：pasteboard<br>方法 or 属性：function createWantData(want: Want): PasteData;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard<br>方法 or 属性：function createPlainTextData(text: string): PasteData;<br>废弃版本：N/A|类名：pasteboard<br>方法 or 属性：function createPlainTextData(text: string): PasteData;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard<br>方法 or 属性：function createUriData(uri: string): PasteData;<br>废弃版本：N/A|类名：pasteboard<br>方法 or 属性：function createUriData(uri: string): PasteData;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard<br>方法 or 属性：function createHtmlTextRecord(htmlText: string): PasteDataRecord;<br>废弃版本：N/A|类名：pasteboard<br>方法 or 属性：function createHtmlTextRecord(htmlText: string): PasteDataRecord;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard<br>方法 or 属性：function createWantRecord(want: Want): PasteDataRecord;<br>废弃版本：N/A|类名：pasteboard<br>方法 or 属性：function createWantRecord(want: Want): PasteDataRecord;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard<br>方法 or 属性：function createPlainTextRecord(text: string): PasteDataRecord;<br>废弃版本：N/A|类名：pasteboard<br>方法 or 属性：function createPlainTextRecord(text: string): PasteDataRecord;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：pasteboard<br>方法 or 属性：function createUriRecord(uri: string): PasteDataRecord;<br>废弃版本：N/A|类名：pasteboard<br>方法 or 属性：function createUriRecord(uri: string): PasteDataRecord;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteDataRecord<br>方法 or 属性：convertToText(callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：PasteDataRecord<br>方法 or 属性：convertToText(callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteDataRecord<br>方法 or 属性：convertToText(): Promise\<string>;<br>废弃版本：N/A|类名：PasteDataRecord<br>方法 or 属性：convertToText(): Promise\<string>;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData<br>方法 or 属性：addHtmlRecord(htmlText: string): void;<br>废弃版本：N/A|类名：PasteData<br>方法 or 属性：addHtmlRecord(htmlText: string): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData<br>方法 or 属性：addWantRecord(want: Want): void;<br>废弃版本：N/A|类名：PasteData<br>方法 or 属性：addWantRecord(want: Want): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData<br>方法 or 属性：addTextRecord(text: string): void;<br>废弃版本：N/A|类名：PasteData<br>方法 or 属性：addTextRecord(text: string): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData<br>方法 or 属性：addUriRecord(uri: string): void;<br>废弃版本：N/A|类名：PasteData<br>方法 or 属性：addUriRecord(uri: string): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData<br>方法 or 属性：getRecordAt(index: number): PasteDataRecord;<br>废弃版本：N/A|类名：PasteData<br>方法 or 属性：getRecordAt(index: number): PasteDataRecord;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData<br>方法 or 属性：hasMimeType(mimeType: string): boolean;<br>废弃版本：N/A|类名：PasteData<br>方法 or 属性：hasMimeType(mimeType: string): boolean;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData<br>方法 or 属性：removeRecordAt(index: number): boolean;<br>废弃版本：N/A|类名：PasteData<br>方法 or 属性：removeRecordAt(index: number): boolean;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：PasteData<br>方法 or 属性：replaceRecordAt(index: number, record: PasteDataRecord): boolean;<br>废弃版本：N/A|类名：PasteData<br>方法 or 属性：replaceRecordAt(index: number, record: PasteDataRecord): boolean;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard<br>方法 or 属性：clear(callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：SystemPasteboard<br>方法 or 属性：clear(callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard<br>方法 or 属性：clear(): Promise\<void>;<br>废弃版本：N/A|类名：SystemPasteboard<br>方法 or 属性：clear(): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard<br>方法 or 属性：getPasteData(callback: AsyncCallback\<PasteData>): void;<br>废弃版本：N/A|类名：SystemPasteboard<br>方法 or 属性：getPasteData(callback: AsyncCallback\<PasteData>): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard<br>方法 or 属性：getPasteData(): Promise\<PasteData>;<br>废弃版本：N/A|类名：SystemPasteboard<br>方法 or 属性：getPasteData(): Promise\<PasteData>;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard<br>方法 or 属性：hasPasteData(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：SystemPasteboard<br>方法 or 属性：hasPasteData(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard<br>方法 or 属性：hasPasteData(): Promise\<boolean>;<br>废弃版本：N/A|类名：SystemPasteboard<br>方法 or 属性：hasPasteData(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard<br>方法 or 属性：setPasteData(data: PasteData, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：SystemPasteboard<br>方法 or 属性：setPasteData(data: PasteData, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：SystemPasteboard<br>方法 or 属性：setPasteData(data: PasteData): Promise\<void>;<br>废弃版本：N/A|类名：SystemPasteboard<br>方法 or 属性：setPasteData(data: PasteData): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.pasteboard.pasteboard|@ohos.pasteboard.d.ts|
|废弃版本有变化|类名：request<br>方法 or 属性：function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>废弃版本：N/A|类名：request<br>方法 or 属性：function download(config: DownloadConfig, callback: AsyncCallback\<DownloadTask>): void;<br>废弃版本：9<br>代替接口：ohos.request.downloadFile   |@ohos.request.d.ts|
|废弃版本有变化|类名：request<br>方法 or 属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>废弃版本：N/A|类名：request<br>方法 or 属性：function download(config: DownloadConfig): Promise\<DownloadTask>;<br>废弃版本：9<br>代替接口：ohos.request.downloadFile   |@ohos.request.d.ts|
|废弃版本有变化|类名：request<br>方法 or 属性：function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>废弃版本：N/A|类名：request<br>方法 or 属性：function upload(config: UploadConfig, callback: AsyncCallback\<UploadTask>): void;<br>废弃版本：9<br>代替接口：ohos.request.uploadFile   |@ohos.request.d.ts|
|废弃版本有变化|类名：request<br>方法 or 属性：function upload(config: UploadConfig): Promise\<UploadTask>;<br>废弃版本：N/A|类名：request<br>方法 or 属性：function upload(config: UploadConfig): Promise\<UploadTask>;<br>废弃版本：9<br>代替接口：ohos.request.uploadFile   |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：remove(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：remove(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.request.delete     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：remove(): Promise\<boolean>;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：remove(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：ohos.request.delete     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：pause(callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：pause(callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.request.suspend     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：pause(): Promise\<void>;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：pause(): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.request.suspend     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：resume(callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：resume(callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.request.restore     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：resume(): Promise\<void>;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：resume(): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.request.restore     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：query(callback: AsyncCallback\<DownloadInfo>): void;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：query(callback: AsyncCallback\<DownloadInfo>): void;<br>废弃版本：9<br>代替接口：ohos.request.getTaskInfo     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：query(): Promise\<DownloadInfo>;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：query(): Promise\<DownloadInfo>;<br>废弃版本：9<br>代替接口：ohos.request.getTaskInfo     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：queryMimeType(callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：queryMimeType(callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：ohos.request.getTaskMimeType     |@ohos.request.d.ts|
|废弃版本有变化|类名：DownloadTask<br>方法 or 属性：queryMimeType(): Promise\<string>;<br>废弃版本：N/A|类名：DownloadTask<br>方法 or 属性：queryMimeType(): Promise\<string>;<br>废弃版本：9<br>代替接口：ohos.request.getTaskMimeType     |@ohos.request.d.ts|
|废弃版本有变化|类名：UploadTask<br>方法 or 属性：remove(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：UploadTask<br>方法 or 属性：remove(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.request.delete     |@ohos.request.d.ts|
|废弃版本有变化|类名：UploadTask<br>方法 or 属性：remove(): Promise\<boolean>;<br>废弃版本：N/A|类名：UploadTask<br>方法 or 属性：remove(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：ohos.request.delete     |@ohos.request.d.ts|
|废弃版本有变化|类名：screenLock<br>方法 or 属性：function isScreenLocked(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：screenLock<br>方法 or 属性：function isScreenLocked(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock<br>方法 or 属性：function isScreenLocked(): Promise\<boolean>;<br>废弃版本：N/A|类名：screenLock<br>方法 or 属性：function isScreenLocked(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：N/A|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock<br>方法 or 属性：function isSecureMode(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：screenLock<br>方法 or 属性：function isSecureMode(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock<br>方法 or 属性：function isSecureMode(): Promise\<boolean>;<br>废弃版本：N/A|类名：screenLock<br>方法 or 属性：function isSecureMode(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：N/A|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock<br>方法 or 属性：function unlockScreen(callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：screenLock<br>方法 or 属性：function unlockScreen(callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：screenLock<br>方法 or 属性：function unlockScreen():Promise\<void>;<br>废弃版本：N/A|类名：screenLock<br>方法 or 属性：function unlockScreen():Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.screenLock.d.ts|
|废弃版本有变化|类名：systemTime<br>废弃版本：N/A|类名：systemTime<br>废弃版本：9<br>代替接口：ohos.systemDateTime |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setTime(time : number, callback : AsyncCallback\<void>) : void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setTime(time : number, callback : AsyncCallback\<void>) : void;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setTime(time : number) : Promise\<void>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setTime(time : number) : Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano?: boolean): Promise\<number>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano?: boolean): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getCurrentTime     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano?: boolean): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getRealActiveTime     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getRealTime(isNano?: boolean): Promise\<number>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getRealTime(isNano?: boolean): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getRealTime     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setDate(date: Date, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setDate(date: Date): Promise\<void>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setDate(date: Date): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getDate(callback: AsyncCallback\<Date>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getDate(callback: AsyncCallback\<Date>): void;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getDate     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getDate(): Promise\<Date>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getDate(): Promise\<Date>;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getDate     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setTimezone(timezone: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function setTimezone(timezone: string): Promise\<void>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function setTimezone(timezone: string): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getTimezone(callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getTimezone(callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getTimezone     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：systemTime<br>方法 or 属性：function getTimezone(): Promise\<string>;<br>废弃版本：N/A|类名：systemTime<br>方法 or 属性：function getTimezone(): Promise\<string>;<br>废弃版本：9<br>代替接口：ohos.systemDateTime/systemDateTime.getTimezone     |@ohos.systemTime.d.ts|
|废弃版本有变化|类名：RgbaColor<br>废弃版本：N/A|类名：RgbaColor<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getId(wallpaperType: WallpaperType): Promise\<number>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getId(wallpaperType: WallpaperType): Promise\<number>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getFile(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getFile(wallpaperType: WallpaperType): Promise\<number>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getFile(wallpaperType: WallpaperType): Promise\<number>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getMinHeight(callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getMinHeight(callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getMinHeight(): Promise\<number>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getMinHeight(): Promise\<number>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getMinWidth(callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getMinWidth(callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getMinWidth(): Promise\<number>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getMinWidth(): Promise\<number>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function isChangePermitted(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function isChangePermitted(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function isChangePermitted(): Promise\<boolean>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function isChangePermitted(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function isOperationAllowed(callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function isOperationAllowed(callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function isOperationAllowed(): Promise\<boolean>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function isOperationAllowed(): Promise\<boolean>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function reset(wallpaperType: WallpaperType): Promise\<void>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function reset(wallpaperType: WallpaperType): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：wallpaper<br>方法 or 属性：function off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>废弃版本：N/A|类名：wallpaper<br>方法 or 属性：function off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.wallpaper.d.ts|
|废弃版本有变化|类名：UploadResponse<br>废弃版本：N/A|类名：UploadResponse<br>废弃版本：9<br>代替接口：ohos.request |@system.request.d.ts|
|废弃版本有变化|类名：UploadResponse<br>方法 or 属性：code: number;<br>废弃版本：N/A|类名：UploadResponse<br>方法 or 属性：code: number;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadResponse<br>方法 or 属性：data: string;<br>废弃版本：N/A|类名：UploadResponse<br>方法 or 属性：data: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadResponse<br>方法 or 属性：headers: Object;<br>废弃版本：N/A|类名：UploadResponse<br>方法 or 属性：headers: Object;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadResponse<br>废弃版本：N/A|类名：DownloadResponse<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadResponse<br>方法 or 属性：token: string;<br>废弃版本：N/A|类名：DownloadResponse<br>方法 or 属性：token: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteResponse<br>废弃版本：N/A|类名：OnDownloadCompleteResponse<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteResponse<br>方法 or 属性：uri: string;<br>废弃版本：N/A|类名：OnDownloadCompleteResponse<br>方法 or 属性：uri: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile<br>废弃版本：N/A|类名：RequestFile<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile<br>方法 or 属性：filename?: string;<br>废弃版本：N/A|类名：RequestFile<br>方法 or 属性：filename?: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile<br>方法 or 属性：name?: string;<br>废弃版本：N/A|类名：RequestFile<br>方法 or 属性：name?: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile<br>方法 or 属性：uri: string;<br>废弃版本：N/A|类名：RequestFile<br>方法 or 属性：uri: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：RequestFile<br>方法 or 属性：type?: string;<br>废弃版本：N/A|类名：RequestFile<br>方法 or 属性：type?: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：RequestData<br>废弃版本：N/A|类名：RequestData<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：RequestData<br>方法 or 属性：name: string;<br>废弃版本：N/A|类名：RequestData<br>方法 or 属性：name: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：RequestData<br>方法 or 属性：value: string;<br>废弃版本：N/A|类名：RequestData<br>方法 or 属性：value: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>废弃版本：N/A|类名：UploadRequestOptions<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>方法 or 属性：url: string;<br>废弃版本：N/A|类名：UploadRequestOptions<br>方法 or 属性：url: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>方法 or 属性：data?: Array\<RequestData>;<br>废弃版本：N/A|类名：UploadRequestOptions<br>方法 or 属性：data?: Array\<RequestData>;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>方法 or 属性：files: Array\<RequestFile>;<br>废弃版本：N/A|类名：UploadRequestOptions<br>方法 or 属性：files: Array\<RequestFile>;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>方法 or 属性：header?: Object;<br>废弃版本：N/A|类名：UploadRequestOptions<br>方法 or 属性：header?: Object;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>方法 or 属性：method?: string;<br>废弃版本：N/A|类名：UploadRequestOptions<br>方法 or 属性：method?: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>方法 or 属性：success?: (data: UploadResponse) => void;<br>废弃版本：N/A|类名：UploadRequestOptions<br>方法 or 属性：success?: (data: UploadResponse) => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>方法 or 属性：fail?: (data: any, code: number) => void;<br>废弃版本：N/A|类名：UploadRequestOptions<br>方法 or 属性：fail?: (data: any, code: number) => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：UploadRequestOptions<br>方法 or 属性：complete?: () => void;<br>废弃版本：N/A|类名：UploadRequestOptions<br>方法 or 属性：complete?: () => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions<br>废弃版本：N/A|类名：DownloadRequestOptions<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions<br>方法 or 属性：url: string;<br>废弃版本：N/A|类名：DownloadRequestOptions<br>方法 or 属性：url: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions<br>方法 or 属性：filename?: string;<br>废弃版本：N/A|类名：DownloadRequestOptions<br>方法 or 属性：filename?: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions<br>方法 or 属性：header?: string;<br>废弃版本：N/A|类名：DownloadRequestOptions<br>方法 or 属性：header?: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions<br>方法 or 属性：description?: string;<br>废弃版本：N/A|类名：DownloadRequestOptions<br>方法 or 属性：description?: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions<br>方法 or 属性：success?: (data: DownloadResponse) => void;<br>废弃版本：N/A|类名：DownloadRequestOptions<br>方法 or 属性：success?: (data: DownloadResponse) => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions<br>方法 or 属性：fail?: (data: any, code: number) => void;<br>废弃版本：N/A|类名：DownloadRequestOptions<br>方法 or 属性：fail?: (data: any, code: number) => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：DownloadRequestOptions<br>方法 or 属性：complete?: () => void;<br>废弃版本：N/A|类名：DownloadRequestOptions<br>方法 or 属性：complete?: () => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions<br>废弃版本：N/A|类名：OnDownloadCompleteOptions<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions<br>方法 or 属性：token: string;<br>废弃版本：N/A|类名：OnDownloadCompleteOptions<br>方法 or 属性：token: string;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions<br>方法 or 属性：success?: (data: OnDownloadCompleteResponse) => void;<br>废弃版本：N/A|类名：OnDownloadCompleteOptions<br>方法 or 属性：success?: (data: OnDownloadCompleteResponse) => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions<br>方法 or 属性：fail?: (data: any, code: number) => void;<br>废弃版本：N/A|类名：OnDownloadCompleteOptions<br>方法 or 属性：fail?: (data: any, code: number) => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：OnDownloadCompleteOptions<br>方法 or 属性：complete?: () => void;<br>废弃版本：N/A|类名：OnDownloadCompleteOptions<br>方法 or 属性：complete?: () => void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：Request<br>废弃版本：N/A|类名：Request<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：Request<br>方法 or 属性：static upload(options: UploadRequestOptions): void;<br>废弃版本：N/A|类名：Request<br>方法 or 属性：static upload(options: UploadRequestOptions): void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：Request<br>方法 or 属性：static download(options: DownloadRequestOptions): void;<br>废弃版本：N/A|类名：Request<br>方法 or 属性：static download(options: DownloadRequestOptions): void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|废弃版本有变化|类名：Request<br>方法 or 属性：static onDownloadComplete(options: OnDownloadCompleteOptions): void;<br>废弃版本：N/A|类名：Request<br>方法 or 属性：static onDownloadComplete(options: OnDownloadCompleteOptions): void;<br>废弃版本：9<br>代替接口：N/A|@system.request.d.ts|
|起始版本有变化|类名：DownloadTask<br>起始版本：N/A|类名：DownloadTask<br>起始版本：6|@ohos.request.d.ts|
|起始版本有变化|类名：UploadTask<br>起始版本：N/A|类名：UploadTask<br>起始版本：6|@ohos.request.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_REALTIME: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_WAKEUP: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_EXACT: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：const TIMER_TYPE_IDLE: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise\<number>;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise\<number>;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise\<void>;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise\<void>;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise\<void>;<br>起始版本：N/A|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise\<void>;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>起始版本：N/A|类名：TimerOptions<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：type: number;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：type: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：repeat: boolean;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：interval?: number;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：wantAgent?: WantAgent;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>起始版本：N/A|类名：TimerOptions<br>方法 or 属性：callback?: () => void;<br>起始版本：7|@ohos.systemTimer.d.ts|
|起始版本有变化|类名：RgbaColor<br>起始版本：N/A|类名：RgbaColor<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：WallpaperType<br>起始版本：N/A|类名：WallpaperType<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getColors(wallpaperType: WallpaperType, callback: AsyncCallback\<Array\<RgbaColor>>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getColors(wallpaperType: WallpaperType): Promise\<Array\<RgbaColor>>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getId(wallpaperType: WallpaperType, callback: AsyncCallback\<number>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getId(wallpaperType: WallpaperType): Promise\<number>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getId(wallpaperType: WallpaperType): Promise\<number>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getMinHeight(callback: AsyncCallback\<number>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getMinHeight(callback: AsyncCallback\<number>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getMinHeight(): Promise\<number>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getMinHeight(): Promise\<number>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getMinWidth(callback: AsyncCallback\<number>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getMinWidth(callback: AsyncCallback\<number>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getMinWidth(): Promise\<number>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getMinWidth(): Promise\<number>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function isChangePermitted(callback: AsyncCallback\<boolean>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function isChangePermitted(callback: AsyncCallback\<boolean>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function isChangePermitted(): Promise\<boolean>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function isChangePermitted(): Promise\<boolean>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function isOperationAllowed(callback: AsyncCallback\<boolean>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function isOperationAllowed(callback: AsyncCallback\<boolean>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function isOperationAllowed(): Promise\<boolean>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function isOperationAllowed(): Promise\<boolean>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function reset(wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function reset(wallpaperType: WallpaperType): Promise\<void>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function reset(wallpaperType: WallpaperType): Promise\<void>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType, callback: AsyncCallback\<void>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function setWallpaper(source: string \| image.PixelMap, wallpaperType: WallpaperType): Promise\<void>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function on(type: 'colorChange', callback: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：wallpaper<br>方法 or 属性：function off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>起始版本：N/A|类名：wallpaper<br>方法 or 属性：function off(type: 'colorChange', callback?: (colors: Array\<RgbaColor>, wallpaperType: WallpaperType) => void): void;<br>起始版本：7|@ohos.wallpaper.d.ts|
|起始版本有变化|类名：Request<br>方法 or 属性：static upload(options: UploadRequestOptions): void;<br>起始版本：N/A|类名：Request<br>方法 or 属性：static upload(options: UploadRequestOptions): void;<br>起始版本：3|@system.request.d.ts|
|起始版本有变化|类名：Request<br>方法 or 属性：static download(options: DownloadRequestOptions): void;<br>起始版本：N/A|类名：Request<br>方法 or 属性：static download(options: DownloadRequestOptions): void;<br>起始版本：3|@system.request.d.ts|
|起始版本有变化|类名：Request<br>方法 or 属性：static onDownloadComplete(options: OnDownloadCompleteOptions): void;<br>起始版本：N/A|类名：Request<br>方法 or 属性：static onDownloadComplete(options: OnDownloadCompleteOptions): void;<br>起始版本：3|@system.request.d.ts|
|权限有变化|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>权限:ohos.permission.READ_USER_STORAGE|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType, callback: AsyncCallback\<image.PixelMap>): void;<br>权限:ohos.permission.GET_WALLPAPER|@ohos.wallpaper.d.ts|
|权限有变化|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>权限:ohos.permission.READ_USER_STORAGE|类名：wallpaper<br>方法 or 属性：function getPixelMap(wallpaperType: WallpaperType): Promise\<image.PixelMap>;<br>权限:ohos.permission.GET_WALLPAPER|@ohos.wallpaper.d.ts|
|新增(错误码)|NA|类名：SystemPasteboard<br>方法 or 属性：on(type: 'update', callback: () => void): void;<br>错误码内容: 401|@ohos.pasteboard.d.ts|
|新增(错误码)|NA|类名：SystemPasteboard<br>方法 or 属性：off(type: 'update', callback?: () => void): void;<br>错误码内容: 401|@ohos.pasteboard.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions, callback: AsyncCallback\<number>): void;<br>错误码内容: 202, 401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function createTimer(options: TimerOptions): Promise\<number>;<br>错误码内容: 202, 401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 202, 401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function startTimer(timer: number, triggerTime: number): Promise\<void>;<br>错误码内容: 202, 401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 202, 401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function stopTimer(timer: number): Promise\<void>;<br>错误码内容: 202, 401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number, callback: AsyncCallback\<void>): void;<br>错误码内容: 202, 401|@ohos.systemTimer.d.ts|
|新增(错误码)|NA|类名：systemTimer<br>方法 or 属性：function destroyTimer(timer: number): Promise\<void>;<br>错误码内容: 202, 401|@ohos.systemTimer.d.ts|
|新增(权限)|类名：DownloadTask<br>权限:N/A|类名：DownloadTask<br>权限:ohos.permission.INTERNET|@ohos.request.d.ts|
|新增(权限)|类名：UploadTask<br>权限:N/A|类名：UploadTask<br>权限:ohos.permission.INTERNET|@ohos.request.d.ts|
|SysCap有变化|类名：DownloadTask<br>SysCap:N/A|类名：DownloadTask<br>SysCap:SystemCapability.MiscServices.Download|@ohos.request.d.ts|
|SysCap有变化|类名：UploadTask<br>SysCap:N/A|类名：UploadTask<br>SysCap:SystemCapability.MiscServices.Download|@ohos.request.d.ts|
|函数有变化|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano: boolean, callback: AsyncCallback\<number>): void;<br>|@ohos.systemTime.d.ts|
|函数有变化|类名：systemTime<br>方法 or 属性：function getCurrentTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>|类名：systemTime<br>方法 or 属性：function getCurrentTime(callback: AsyncCallback\<number>): void;<br>|@ohos.systemTime.d.ts|
|函数有变化|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano: boolean, callback: AsyncCallback\<number>): void;<br>|@ohos.systemTime.d.ts|
|函数有变化|类名：systemTime<br>方法 or 属性：function getRealActiveTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>|类名：systemTime<br>方法 or 属性：function getRealActiveTime(callback: AsyncCallback\<number>): void;<br>|@ohos.systemTime.d.ts|
|函数有变化|类名：systemTime<br>方法 or 属性：function getRealTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>|类名：systemTime<br>方法 or 属性：function getRealTime(isNano: boolean, callback: AsyncCallback\<number>): void;<br>|@ohos.systemTime.d.ts|
|函数有变化|类名：systemTime<br>方法 or 属性：function getRealTime(isNano?: boolean, callback: AsyncCallback\<number>): void;<br>|类名：systemTime<br>方法 or 属性：function getRealTime(callback: AsyncCallback\<number>): void;<br>|@ohos.systemTime.d.ts|
