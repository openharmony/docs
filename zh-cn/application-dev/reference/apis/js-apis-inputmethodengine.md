# 输入法服务

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import inputMethodEngine from '@ohos.inputmethodengine';
```

## inputMethodEngine

常量值。

**系统能力**：SystemCapability.Miscservices.InputMethodFramework

| 名称                  | 参数类型 | 可读 | 可写 | 说明                   |
| -------------------- | -------- | ---- | ---- | ------------------- |
| ENTER_KEY_TYPE_UNSPECIFIED | number   | 是   | 否   | 无功能键。|
| ENTER_KEY_TYPE_GO          | number   | 是   | 否   | “前往”功能键。|
| ENTER_KEY_TYPE_SEARCH      | number   | 是   | 否   | “搜索”功能键。|
| ENTER_KEY_TYPE_SEND        | number   | 是   | 否   | “发送”功能键。|
| ENTER_KEY_TYPE_NEXT        | number   | 是   | 否   | “下一个”功能键。 |
| ENTER_KEY_TYPE_DONE        | number   | 是   | 否   | “回车”功能键。  |
| ENTER_KEY_TYPE_PREVIOUS    | number   | 是   | 否   | “前一个”功能键。 |
| PATTERN_NULL               | number   | 是   | 否   | 无特殊性编辑框。 |
| PATTERN_TEXT               | number   | 是   | 否   | 文本编辑框。    |
| PATTERN_NUMBER             | number   | 是   | 否   | 数字编辑框。 |
| PATTERN_PHONE              | number   | 是   | 否   | 电话号码编辑框。|
| PATTERN_DATETIME           | number   | 是   | 否   | 日期编辑框。 |
| PATTERN_EMAIL              | number   | 是   | 否   | 邮件编辑框。 |
| PATTERN_URI                | number   | 是   | 否   | 超链接编辑框。|
| PATTERN_PASSWORD           | number   | 是   | 否   | 密码编辑框。|
| OPTION_ASCII               | number   | 是   | 否   | 允许输入ASCII值。 |
| OPTION_NONE                | number   | 是   | 否   | 不指定编辑框输入属性。 |
| OPTION_AUTO_CAP_CHARACTERS | number   | 是   | 否   | 允许输入字符。 |
| OPTION_AUTO_CAP_SENTENCES  | number   | 是   | 否   | 允许输入句子。|
| OPTION_AUTO_WORDS          | number   | 是   | 否   | 允许输入单词。|
| OPTION_MULTI_LINE          | number   | 是   | 否   | 允许输入多行。 |
| OPTION_NO_FULLSCREEN       | number   | 是   | 否   | 半屏样式。|
| FLAG_SELECTING             | number   | 是   | 否   | 编辑框处于选择状态。|
| FLAG_SINGLE_LINE           | number   | 是   | 否   | 编辑框为单行。  |
| DISPLAY_MODE_PART          | number   | 是   | 否   | 编辑框显示为半屏。|
| DISPLAY_MODE_FULL          | number   | 是   | 否   | 编辑框显示为全屏。 |

## inputMethodEngine.getInputMethodEngine

getInputMethodEngine(): InputMethodEngine

获取服务端实例。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型                                    | 说明         |
| --------------------------------------- | ------------ |
| [InputMethodEngine](#InputMethodEngine) | 服务端实例。 |

**示例：**

```js
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate

createKeyboardDelegate(): KeyboardDelegate

获取客户端监听实例。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型                                  | 说明             |
| ------------------------------------- | ---------------- |
| [KeyboardDelegate](#KeyboardDelegate) | 客户端监听实例。 |

**示例：**

```js
let KeyboardDelegate = inputMethodEngine.createKeyboardDelegate();
```

## InputMethodEngine

下列API示例中都需使用[getInputMethodEngine](#getInputMethodEngine)回调获取到InputMethodEngine实例，再通过此实例调用对应方法。

### on('inputStart')

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

订阅输入法绑定成功事件，使用callback回调返回输入法操作相关实例。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------- |
| type     | string                                                       | 是   | 设置监听类型。<br/>-type为‘inputStart’时表示订阅输入法绑定。 |
| callback | [KeyboardController](#KeyboardController), [TextInputClient](#TextInputClient) | 是   | 回调返回输入法操作相关实例。  |

**示例：**

```js
InputMethodEngine.on('inputStart', (kbController, textInputClient) => {
    KeyboardController = kbController;
    TextInputClient = textInputClient;
});
```

### off('inputStart')

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

取消订阅输入法绑定成功事件。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                       | 必填 | 说明            |
| -------- | ------------------- | ---- | --------------------------- |
| type     | string          | 是   | 设置监听类型。<br/>-type为‘inputStart’时表示订阅输入法绑定。 |
| callback | [KeyboardController](#KeyboardController), [TextInputClient](#TextInputClient) | 否   | 回调返回输入法操作相关实例。   |


**示例：**

```js
InputMethodEngine.off('inputStart');
```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

订阅输入法事件。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                        |
| -------- | ------ | ---- | --------------------------- |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | void   | 否   | 回调函数。    |

**示例：**

```js
InputMethodEngine.on('keyboardShow', (err) => {
    console.info('keyboardShow');
});
```

### off('keyboardShow'|'keyboardHide')

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

取消订阅输入法事件。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明         |
| -------- | ------ | ---- | ------------------------- |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | void   | 否   | 回调函数。    |

**示例：**

```js
InputMethodEngine.off('keyboardShow');
```

## KeyboardDelegate

下列API示例中都需使用[createKeyboardDelegate](#createKeyboardDelegate)回调获取到KeyboardDelegate实例，再通过此实例调用对应方法。

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

订阅硬键盘事件，使用callback回调返回按键信息。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明   |
| -------- | --------------- | ---- | ----------------- |
| type     | string                | 是   | 设置监听类型。<br/>-&nbsp;type为'keyDown'，表示订阅硬键盘按下。<br/>-&nbsp;type为'keyUp'，表示订阅硬键盘抬起。 |
| callback | [KeyEvent](#KeyEvent) | 是   | 回调返回按键信息。     |

**示例：**

```js
KeyboardDelegate.on('keyDown', (event) => {
    console.info('keyDown');
});
```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

取消订阅硬键盘事件。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型           | 必填 | 说明   |
| -------- | --------------------- | ---- | -------------------------- |
| type     | string                | 是   | 设置监听类型。<br/>-&nbsp;type为'keyDown'，表示订阅硬键盘按下。<br/>-&nbsp;type为'keyUp'，表示订阅硬键盘抬起。 |
| callback | [KeyEvent](#KeyEvent) | 否   | 回调返回按键信息。  |

**示例：**

```js
KeyboardDelegate.off('keyDown');
```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

订阅光标变化事件，使用callback回调返回光标信息。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明    |
| -------- | ------ | ---- | ----------------- |
| type     | string | 是   | 光标变化事件。<br/>-type为’cursorContextChange‘时，表示光标变化。 |
| callback | number | 是   | 回调返回光标信息。 |

**示例：**

```js
KeyboardDelegate.on('cursorContextChange', (x, y, height) => {
    console.info('cursorContextChange');
});
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y:number, height:number) => void): void

取消订阅光标变化事件。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string       | 是   | 光标变化事件。<br/>-type为’cursorContextChange‘时，表示光标变化。 |
| callback | number | 否 | 回调返回光标信息。 |

**示例：**

```js
KeyboardDelegate.off('cursorContextChange');
```

### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

订阅文本选择变化事件，使用callback回调返回文本选择信息。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明          |
| -------- | ------ | ---- | ------------------------------ |
| type     | string | 是   | 文本选择变化事件。<br/>-type为’selectionChange‘时，表示选择文本变化。 |
| callback | number | 是   | 回调返回文本选择信息。         |

**示例：**

```js
KeyboardDelegate.on('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
    console.info('selectionChange');
});
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

取消订阅文本选择变化事件。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 文本选择变化事件。<br/>-type为’selectionChange‘时，表示选择文本变化。 |
| callback | number | 否 | 回调返回文本选择信息。 |

**示例：**

```js
KeyboardDelegate.off('selectionChange');
```

### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

订阅文本变化事件，使用callback回调返回当前文本内容。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明               |
| -------- | ---------------------- | ---- | ------------------------- |
| type     | string                  | 是   | 文本变化事件。<br/>-type为’textChange‘时，表示当前文本变化。 |
| callback | string | 是 | 回调返回当前文本内容。 |

**示例：**

```js
KeyboardDelegate.on('textChange', (text) => {
    console.info('textChange');
});
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

取消订阅文本变化事件。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 文本变化事件。<br/>-type为’textChange‘时，表示当前文本变化。 |
| callback | string | 否 | 回调返回当前文本内容。 |

**示例：**

```js
KeyboardDelegate.off('textChange');
```

## KeyboardController

下列API示例中都需使用[inputStart](#inputStart)回调获取到KeyboardController实例，再通过此实例调用对应方法。

### hideKeyboard

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏输入法。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | 否   | 回调函数 |

**示例：**

```js
KeyboardController.hideKeyboard(()=>{
});
```

### hideKeyboard

hideKeyboard(): Promise&lt;void&gt;

隐藏输入法。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型             | 说明     |
| ---------------- | -------- |
| Promise&lt;void> | 回调函数 |

**示例：**

```js
KeyboardController.hideKeyboard();
```

## TextInputClient

下列API示例中都需使用[inputStart](#inputStart)回调获取到TextInputClient实例，再通过此实例调用对应方法。

### getForward

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标前固定长度的文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                        | 必填 | 说明       |
| -------- | --------------------------- | ---- | ---------- |
| length   | number                      | 是   | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 返回文本。 |

**示例：**

```js
TextInputClient.getForward(5,(text) =>{
    console.info("text = " + text);
});
```

### getForward

getForward(length:number): Promise&lt;string&gt;

获取光标前固定长度的文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。 |

**返回值：**

| 类型                  | 说明       |
| --------------------- | ---------- |
| Promise&lt;string&gt; | 返回文本。 |

**示例：**

```js
let text = TextInputClient.getForward(5);
console.info("text = " + text);
```

### getBackward

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标后固定长度的文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                        | 必填 | 说明       |
| -------- | --------------------------- | ---- | ---------- |
| length   | number                      | 是   | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是   | 返回文本。 |

**示例：**

```js
TextInputClient.getBackward(5,(text)=>{
    console.info("text = " + text);
});
```

### getBackward

getBackward(length:number): Promise&lt;string&gt;

获取光标后固定长度的文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。 |

**返回值：**

| 类型                  | 说明       |
| --------------------- | ---------- |
| Promise&lt;string&gt; | 返回文本。 |

**示例：**

```js
let text = TextInputClient.getBackward(5);
console.info("text = " + text);
```

### deleteForward

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标前固定长度的文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | 是   | 文本长度。     |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 操作成功与否。 |

**示例：**

```js
TextInputClient.deleteForward(5,(isSuccess)=>{
    console.info("isSuccess = " + isSuccess);
});
```

### deleteForward

deleteForward(length:number): Promise&lt;boolean&gt;

删除光标前固定长度的文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：** 

| 类型                 | 说明                                    |
| -------------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; |  操作成功与否。                |

**示例：**

```js
let isSuccess = TextInputClient.deleteForward(5);
console.info("isSuccess = " + isSuccess);
```

### deleteBackward

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标后固定长度的文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 操作成功与否。 |

**示例：**

```js
TextInputClient.deleteBackward(5, (isSuccess)=>{
    console.info("isSuccess = " + isSuccess);
});
```

### deleteBackward

deleteBackward(length:number): Promise&lt;boolean&gt;

删除光标后固定长度的文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**
| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。 |

**返回值：** 

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | 操作成功与否。 |

**示例：**

```js
let isSuccess = TextInputClient.deleteBackward(5);
console.info("isSuccess = " + isSuccess);
```

### sendKeyFunction

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

发送功能键。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 编辑框属性。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 操作成功与否。 |

**示例：**

```js
TextInputClient.sendKeyFunction(inputMethod.ENTER_KEY_TYPE_NEXT,(isSuccess)=>{
    console.info("isSuccess = " + isSuccess);
});
```

### sendKeyFunction

sendKeyFunction(action:number): Promise&lt;boolean&gt;

发送功能键。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| action | number | 是   | 编辑框属性。 |

**返回值：**

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | 操作成功与否。 |

**示例：**

```js
let isSuccess = TextInputClient.sendKeyFunction(inputMethod.ENTER_KEY_TYPE_NEXT);
console.info("isSuccess = " + isSuccess);
```

### insertText

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

插入文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 操作成功与否。 |

**示例：**

```js
TextInputClient.insertText("test", (isSuccess)=>{
    console.info("isSuccess = " + isSuccess);
});
```

### insertText

insertText(text:string): Promise&lt;boolean&gt;

插入文本。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明   |
| ------ | ------ | ---- | ------ |
| text   | string | 是   | 文本。 |

**返回值：**  

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | 操作成功与否。 |

**示例：**

```js
let isSuccess = TextInputClient.insertText("test");
console.info("isSuccess = " + isSuccess);
```

### getEditorAttribute

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

获取编辑框属性值。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明           |
| -------- | ----------------------- | ---- | -------------- |
| callback | AsyncCallback&lt;[EditorAttribute](#EditorAttribute)&gt; | 是   | 编辑框属性值。 |

**示例：**

```js
TextInputClient.getEditorAttribute((EditorAttribute)=>{
});
```

### getEditorAttribute

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

获取编辑框属性值。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

**返回值：**

| 类型             | 说明               |
| -------------------------- | ------------------ |
| Promise&lt;[EditorAttribute](#EditorAttribute)&gt; | 返回编辑框属性值。 |

**示例：**

```js
let EditorAttribute = TextInputClient.getEditorAttribute();
```

## EditorAttribute

编辑框属性值。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

| 名称         | 参数类型 | 可读 | 可写 | 说明               |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | 是   | 否   | 编辑框的功能属性。 |
| inputPattern | number   | 是   | 否   | 编辑框的文本属性。 |

## KeyEvent

按键属性值。

**系统能力**： SystemCapability.Miscservices.InputMethodFramework

| 名称      | 参数类型 | 可读 | 可写 | 说明         |
| --------- | -------- | ---- | ---- | ------------ |
| keyCode   | number   | 是   | 否   | 按键的键值。 |
| keyAction | number   | 是   | 否   | 按键的状态。 |