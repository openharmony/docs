# 输入法框架changeLog

## cl.inputmethod_frameworks.1 API错误信息返回方式变更

下列模块内部接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。在API9进行变更。

 - 输入法框架模块：系统接口，@ohos.inputmethod.d.ts

 - 输入法服务模块：系统接口，@ohos.inputmethodengine.d.ts

 - 输入法ExtentionAbility模块：系统接口，@ohos.inputmethodextensionability.d.ts

 - 输入法ExtentionContext模块：系统接口，@ohos.inputmethodextensioncontext.d.ts

 - 输入法子类型模块：系统接口，@ohos.inputMethodSubtype.d.ts
 
异步接口：通过AsyncCallback或Promise的error对象返回错误信息。

同步接口：通过抛出异常的方式返回错误信息。

**变更影响**

基于此前版本开发的应用，需适配接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

在以下接口增加错误码处理：
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
  InputClient 接口下：
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
  InputMethodExtensionAbility 类下：
  - onCreate(want: Want): void;
  - onDestroy(): void;
  
**适配指导**

异步接口以showOptionalInputMethods为例，示例代码如下：

callback回调：

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

Promise回调：

```js
import inputMethod from '@ohos.inputmethod';
let inputMethodSetting = inputMethod.getSetting();
inputMethodSetting.showOptionalInputMethods().then((data) => {
    console.info('Succeeded in showing optionalInputMethods.');
}).catch((err) => {
    console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
})
```

## cl.inputmethod_frameworks.2 API部分接口废弃

以下接口标记废除：
  - getInputMethodSetting(): InputMethodSetting;
  - getInputMethodController(): InputMethodController;
  - listInputMethod(callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - listInputMethod(): Promise<Array<InputMethodProperty>>;
  - displayOptionalInputMethod(callback: AsyncCallback<void>): void;
  - displayOptionalInputMethod(): Promise<void>;
  - stopInput(callback: AsyncCallback<boolean>): void;
  - stopInput(): Promise<boolean>;
  interface InputMethodProperty：
    - readonly packageName: string;
	- readonly methodId: string;
  - getInputMethodEngine(): InputMethodEngine;
  - createKeyboardDelegate(): KeyboardDelegate;
  - hideKeyboard(callback: AsyncCallback<void>): void;
  - hideKeyboard(): Promise<void>;

替代接口如下:
  - getSetting(): InputMethodSetting;
  - getController(): InputMethodController;
  - getInputMethods(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - getInputMethods(enable: boolean): Promise<Array<InputMethodProperty>>;
  - showOptionalInputMethods(callback: AsyncCallback<boolean>): void;
  - showOptionalInputMethods(): Promise<boolean>;
  - stopInputSession(callback: AsyncCallback<boolean>): void;
  - stopInputSession(): Promise<boolean>;
  interface InputMethodProperty：
    - readonly name: string;
	- readonly id: string;
  - getInputMethodAbility(): InputMethodAbility;
  - getKeyboardDelegate(): KeyboardDelegate;
  - hide(callback: AsyncCallback<void>): void;
  - hide(): Promise<void>;
  
**特别注意：**
    使用getInputMethodAbility()接口获取到InputMethodAbility对象，代替使用getInputMethodEngine()接口获取InputMethodEngine对象。
	使用InputMethodAbility中的方法，不要再使用InputMethodEngine中的方法。
	使用InputMethodAbility中的on('inputStart')方法，获取到KeyboardController实例与InputClient实例，不要再使用InputMethodEngine中的on('inputStart')方法去获取TextInputClient实例。
之前：

```js
inputMethodEngine.getInputMethodEngine().on('inputStart', (kbController, textClient) => {
    let keyboardController = kbController;
    let textInputClient = textClient;  // 获取到TextInputClient实例
});
```

之后：
```js
inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, client) => {
    let keyboardController = kbController;
    let inputClient = client;  // // 获取到InputClient实例
});
```

## cl.inputmethod_frameworks.3 API部分接口变更

变更前：
  - listInputMethod(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - listInputMethod(enable: boolean): Promise<Array<InputMethodProperty>>;
  - terminateSelf(callback: AsyncCallback<void>): void;
  - terminateSelf(): Promise<void>;
  
变更后：
  - getInputMethods(enable: boolean, callback: AsyncCallback<Array<InputMethodProperty>>): void;
  - getInputMethods(enable: boolean): Promise<Array<InputMethodProperty>>;
  - destroy(callback: AsyncCallback<void>): void;
  - destroy(): Promise<void>;
  
删除API9接口：
  - startAbility(want: Want, callback: AsyncCallback<void>): void;
  - startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>): void;
  - startAbility(want: Want, options?: StartOptions): Promise<void>;

其他新增接口：
  - on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;
  - off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void;
  - interface InputMethodProperty：
    - readonly label?: string;
	- readonly icon?: string;
	- readonly iconId?: number;
	- extra: object;
	
  - interface InputMethodAbility：
    - on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void;
    - off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void;