# Input Method Framework ChangeLog

## cl.inputmethod_frameworks.1 API Error Information Return Method Change

The internal APIs of the following modules used service logic return values to indicate error information, which did not comply with the error code specifications of OpenHarmony. Therefore, they are modified in API version 9 and later.

 - Input method framework module: system API, @ohos.inputmethod.d.ts

 - Input method service module: system API, @ohos.inputmethodengine.d.ts

 - Input method ExtentionAbility module: system API, @ohos.inputmethodextensionability.d.ts

 - Input method ExtentionContext module: system API, @ohos.inputmethodextensioncontext.d.ts

 - Input method subtype module: system API, @ohos.inputMethodSubtype.d.ts

Asynchronous API: An error message is returned via **AsyncCallback** or the **error** object of **Promise**.

Synchronous API: An error message is returned via an exception.

**Change Impacts**

The application developed based on earlier versions needs to adapt the method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

Error code processing is added for the following APIs:
  - getSetting(): InputMethodSetting;
  - getController(): InputMethodController;
  - switchInputMethod(target: InputMethodProperty, callback: AsyncCallback<boolean>): void;
  - switchInputMethod(target: InputMethodProperty): Promise<boolean>;
  - switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback<boolean>): void;
  - switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise<boolean>;
  - switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback<boolean>): void;
  - switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise<boolean>;
  - listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback<Array<InputMethodSubtype>>): void;
  - listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise<Array<InputMethodSubtype>>;
  - listCurrentInputMethodSubtype(callback: AsyncCallback<Array<InputMethodSubtype>>): void;
  - listCurrentInputMethodSubtype(): Promise<Array<InputMethodSubtype>>;
  - getInputMethods(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - getInputMethods(enable: boolean): Promise<Array<InputMethodProperty>>;
  - showOptionalInputMethods(callback: AsyncCallback<boolean>): void;
  - showOptionalInputMethods(): Promise<boolean>;
  - stopInputSession(callback: AsyncCallback<boolean>): void;
  - stopInputSession(): Promise<boolean>;
  - showSoftKeyboard(callback: AsyncCallback<void>): void;
  - showSoftKeyboard():Promise<void>;
  - hideSoftKeyboard(callback: AsyncCallback<void>): void;
  - hideSoftKeyboard():Promise<void>;
  - hide(callback: AsyncCallback<void>): void;
  - hide(): Promise<void>;
  - onCreate(want: Want): void;
  - onDestroy(): void;
    In **InputClient**:
  - sendKeyFunction(action: number, callback: AsyncCallback<boolean>): void;
  - sendKeyFunction(action: number): Promise<boolean>;
  - deleteForward(length: number, callback: AsyncCallback<boolean>): void;
  - deleteForward(length: number): Promise<boolean>;
  - deleteBackward(length: number, callback: AsyncCallback<boolean>): void;
  - deleteBackward(length: number): Promise<boolean>;
  - insertText(text: string, callback: AsyncCallback<boolean>): void;
  - insertText(text: string): Promise<boolean>;
  - getForward(length: number, callback: AsyncCallback<string>): void;
  - getForward(length: number): Promise<string>;
  - getBackward(length: number, callback: AsyncCallback<string>): void;
  - getBackward(length: number): Promise<string>;
  - getEditorAttribute(callback: AsyncCallback<EditorAttribute>): void;
  - getEditorAttribute(): Promise<EditorAttribute>;
  - moveCursor(direction: number, callback: AsyncCallback<void>): void;
  - moveCursor(direction: number): Promise<void>;
    In **InputMethodExtensionAbility**:
  - onCreate(want: Want): void;
  - onDestroy(): void;

**Adaptation Guide**

The following uses **showOptionalInputMethods** as an example for asynchronous APIs:

Callback mode:

```js
import inputMethod from '@ohos.inputmethod';
let inputMethodSetting = inputMethod.getSetting();
try {
    inputMethodSetting.showOptionalInputMethods((err, data) => {
        if (err !== undefined) {
            console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in showing optionalInputMethods.');
    });
} catch (err) {
    console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
}
```

Promise mode:

```js
import inputMethod from '@ohos.inputmethod';
let inputMethodSetting = inputMethod.getSetting();
inputMethodSetting.showOptionalInputMethods().then((data) => {
    console.info('Succeeded in showing optionalInputMethods.');
}).catch((err) => {
    console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
})
```

## cl.inputmethod_frameworks.2 Deprecation of Some APIs

Deprecated APIs:
  - getInputMethodSetting(): InputMethodSetting;
  - getInputMethodController(): InputMethodController;
  - listInputMethod(callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - listInputMethod(): Promise<Array<InputMethodProperty>>;
  - displayOptionalInputMethod(callback: AsyncCallback<void>): void;
  - displayOptionalInputMethod(): Promise<void>;
  - stopInput(callback: AsyncCallback<boolean>): void;
  - stopInput(): Promise<boolean>;
    interface InputMethodProperty:
    - readonly packageName: string;
	- readonly methodId: string;
  - getInputMethodEngine(): InputMethodEngine;
  - createKeyboardDelegate(): KeyboardDelegate;
  - hideKeyboard(callback: AsyncCallback<void>): void;
  - hideKeyboard(): Promise<void>;

Substitute APIs:
  - getSetting(): InputMethodSetting;
  - getController(): InputMethodController;
  - getInputMethods(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - getInputMethods(enable: boolean): Promise<Array<InputMethodProperty>>;
  - showOptionalInputMethods(callback: AsyncCallback<boolean>): void;
  - showOptionalInputMethods(): Promise<boolean>;
  - stopInputSession(callback: AsyncCallback<boolean>): void;
  - stopInputSession(): Promise<boolean>;
    interface InputMethodProperty:
    - readonly name: string;
	- readonly id: string;
  - getInputMethodAbility(): InputMethodAbility;
  - getKeyboardDelegate(): KeyboardDelegate;
  - hide(callback: AsyncCallback<void>): void;
  - hide(): Promise<void>;

**NOTE**

-    Use the **getInputMethodAbility()** API to obtain an **InputMethodAbility** object, and do not use **getInputMethodEngine()** to obtain an **InputMethodEngine** object.
- Use methods in **InputMethodAbility**, and do not use methods in **InputMethodEngine**.
- Use the **on('inputStart')** method in **InputMethodAbility** to obtain a **KeyboardController** instance and an **InputClient** instance, and do not use the **on('inputStart')** method in **InputMethodEngine** to obtain a **TextInputClient** instance.

Before:

```js
inputMethodEngine.getInputMethodEngine().on('inputStart', (kbController, textClient) => {
    let keyboardController = kbController;
    let textInputClient = textClient;  // Obtain a TextInputClient instance.
});
```

After:
```js
inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, client) => {
    let keyboardController = kbController;
    let inputClient = client;  // // Obtain an InputClient instance.
});
```

## cl.inputmethod_frameworks.3 Change of Some APIs

Before change:
  - listInputMethod(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - listInputMethod(enable: boolean): Promise<Array<InputMethodProperty>>;
  - terminateSelf(callback: AsyncCallback<void>): void;
  - terminateSelf(): Promise<void>;

After change:
  - getInputMethods(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - getInputMethods(enable: boolean): Promise<Array<InputMethodProperty>>;
  - destroy(callback: AsyncCallback<void>): void;
  - destroy(): Promise<void>;

Deleted APIs in API version 9:
  - startAbility(want: Want, callback: AsyncCallback<void>): void;
  - startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>): void;
  - startAbility(want: Want, options?: StartOptions): Promise<void>;

Added APIs:
  - on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;
  - off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;
  - interface InputMethodProperty:
    - readonly label?: string;
	- readonly icon?: string;
	- readonly iconId?: number;
	- extra: object;
	
  - interface InputMethodAbility:
    - on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void;
    - off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void;
