# 输入法服务

  本模块的作用是拉通应用和输入法，保证应用可以通过输入法进行文本输入，以及应用与输入法服务的绑定、应用对输入法的显示和隐藏请求、监听输入法当前的状态等等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import inputMethodEngine from '@ohos.inputmethodengine';
```

## inputMethodEngine

常量值。

**系统能力**：以下各项对应的系统能力均为SystemCapability.MiscServices.InputMethodFramework

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ENTER_KEY_TYPE_UNSPECIFIED | number | 是 | 否 | 无功能键。 |
| ENTER_KEY_TYPE_GO | number | 是 | 否 | “前往”功能键。 |
| ENTER_KEY_TYPE_SEARCH | number | 是 | 否 | “搜索”功能键。 |
| ENTER_KEY_TYPE_SEND | number | 是 | 否 | “发送”功能键。 |
| ENTER_KEY_TYPE_NEXT | number | 是 | 否 | “下一个”功能键。 |
| ENTER_KEY_TYPE_DONE | number | 是 | 否 | “回车”功能键。 |
| ENTER_KEY_TYPE_PREVIOUS | number | 是 | 否 | “前一个”功能键。 |
| PATTERN_NULL | number | 是 | 否 | 无特殊性编辑框。 |
| PATTERN_TEXT | number | 是 | 否 | 文本编辑框。 |
| PATTERN_NUMBER | number | 是 | 否 | 数字编辑框。 |
| PATTERN_PHONE | number | 是 | 否 | 电话号码编辑框。 |
| PATTERN_DATETIME | number | 是 | 否 | 日期编辑框。 |
| PATTERN_EMAIL | number | 是 | 否 | 邮件编辑框。 |
| PATTERN_URI | number | 是 | 否 | 超链接编辑框。 |
| PATTERN_PASSWORD | number | 是 | 否 | 密码编辑框。 |
| OPTION_ASCII | number | 是 | 否 | 允许输入ASCII值。 |
| OPTION_NONE | number | 是 | 否 | 不指定编辑框输入属性。 |
| OPTION_AUTO_CAP_CHARACTERS | number | 是 | 否 | 允许输入字符。 |
| OPTION_AUTO_CAP_SENTENCES | number | 是 | 否 | 允许输入句子。 |
| OPTION_AUTO_WORDS | number | 是 | 否 | 允许输入单词。 |
| OPTION_MULTI_LINE | number | 是 | 否 | 允许输入多行。 |
| OPTION_NO_FULLSCREEN | number | 是 | 否 | 半屏样式。 |
| FLAG_SELECTING | number | 是 | 否 | 编辑框处于选择状态。 |
| FLAG_SINGLE_LINE | number | 是 | 否 | 编辑框为单行。 |
| DISPLAY_MODE_PART | number | 是 | 否 | 编辑框显示为半屏。 |
| DISPLAY_MODE_FULL | number | 是 | 否 | 编辑框显示为全屏。 |
| CURSOR_UP<sup>9+</sup> | number | 是 | 否 | 光标上移。 |
| CURSOR_DOWN<sup>9+</sup> | number | 是 | 否 | 光标下移。 |
| CURSOR_LEFT<sup>9+</sup> | number | 是 | 否 | 光标左移。 |
| CURSOR_RIGHT<sup>9+</sup> | number | 是 | 否 | 光标右移。 |
| WINDOW_TYPE_INPUT_METHOD_FLOAT<sup>9+</sup> | number | 是 | 否 | 输入法应用窗口风格标识。 |

## inputMethodEngine.getInputMethodAbility<a name="getInputMethodAbility"></a><sup>9+</sup>

getInputMethodAbility(): InputMethodAbility

获取服务端实例。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                    | 说明         |
| --------------------------------------- | ------------ |
| [InputMethodAbility](#inputmethodability) | 服务端实例。 |

**示例：**

```js
let InputMethodAbility = inputMethodAbility.getInputMethodAbility();
```

## inputMethodEngine.getKeyboardDelegate<a name="getKeyboardDelegate"></a><sup>9+</sup>

getKeyboardDelegate(): KeyboardDelegate

获取客户端监听实例。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                  | 说明             |
| ------------------------------------- | ---------------- |
| [KeyboardDelegate](#KeyboardDelegate) | 客户端监听实例。 |

**示例：**

```js
let KeyboardDelegate = inputMethodAbility.getKeyboardDelegate();
```

## inputMethodEngine.getInputMethodEngine<a name="getInputMethodEngine"></a><sup>(deprecated)</sup>

getInputMethodEngine(): InputMethodEngine

获取服务端实例。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[getInputMethodAbility()](#getInputMethodAbility)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                    | 说明         |
| --------------------------------------- | ------------ |
| [InputMethodEngine](#inputmethodengine-1) | 服务端实例。 |

**示例：**

```js
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate<a name="createKeyboardDelegate"></a><sup>(deprecated)</sup>

createKeyboardDelegate(): KeyboardDelegate

获取客户端监听实例。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[getKeyboardDelegate()](#getKeyboardDelegate)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                  | 说明             |
| ------------------------------------- | ---------------- |
| [KeyboardDelegate](#KeyboardDelegate) | 客户端监听实例。 |

**示例：**

```js
let KeyboardDelegate = inputMethodEngine.createKeyboardDelegate();
```

## InputMethodEngine<a name="InputMethodEngine"></a>

下列API示例中都需使用[getInputMethodEngine](#getInputMethodEngine)回调获取到InputMethodEngine实例，再通过此实例调用对应方法。

### on('inputStart')<a name="inputStart"></a>

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

订阅输入法绑定成功事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型。<br/>-type为‘inputStart’时表示订阅输入法绑定。 |
| callback | [KeyboardController](#keyboardcontroller), [TextInputClient](#textinputclient) | 是 | 回调函数，返回订阅输入法的KeyboardController和TextInputClient实例。 |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().on('inputStart', (kbController, textInputClient) => {
    KeyboardController = kbController;
    TextInputClient = textInputClient;
});
```

### off('inputStart')

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

取消订阅输入法绑定成功事件。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | 是   | 设置监听类型。<br/>-type为‘inputStart’时表示订阅输入法绑定。 |
| callback | [KeyboardController](#keyboardcontroller), [TextInputClient](#textinputclient) | 否 | 回调函数，返回取消订阅的KeyboardController和TextInputClient实例。 |



**示例：**

```js
inputMethodEngine.getInputMethodEngine().off('inputStart', (kbController, textInputClient) => {
    console.log('delete inputStart notification.');
});
```

### on('inputStop')<sup>9+</sup>

on(type: 'inputStop', callback: () => void): void

订阅停止输入法应用事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘inputStop’时表示订阅停止输入法应用事件。 |
| callback | void   | 是   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().on('inputStop', () => {
    console.log('inputMethodEngine inputStop');
});
```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

取消订阅停止输入法应用事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘inputStop’时表示订阅停止输入法应用事件。 |
| callback | void   | 是   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().off('inputStop', () => {
    console.log('inputMethodEngine delete inputStop notification.');
});
```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid:number) => void): void

订阅设置调用窗口事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘setCallingWindow’时表示订阅设置调用窗口事件。 |
| callback | number | 是   | 回调函数，返回调用方window id。                                            |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().on('setCallingWindow', (wid) => {
    console.log('inputMethodEngine setCallingWindow');
});
```

### off('setCallingWindow')<sup>9+</sup>

off(type: 'setCallingWindow', callback: (wid:number) => void): void

取消订阅设置调用窗口事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘setCallingWindow’时表示订阅设置调用窗口事件。 |
| callback | number | 是   | 回调函数，返回调用方window id。                                 |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().off('setCallingWindow', () => {
    console.log('inputMethodEngine delete setCallingWindow notification.');
});
```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

订阅输入法事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | void   | 否   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().on('keyboardShow', () => {
    console.log('inputMethodEngine keyboardShow.');
});
inputMethodEngine.getInputMethodEngine().on('keyboardHide', () => {
    console.log('inputMethodEngine keyboardHide.');
});
```

### off('keyboardShow'|'keyboardHide')

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

取消订阅输入法事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | void   | 否   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().off('keyboardShow', () => {
    console.log('inputMethodEngine delete keyboardShow notification.');
});
inputMethodEngine.getInputMethodEngine().off('keyboardHide', () => {
    console.log('inputMethodEngine delete keyboardHide notification.');
});
```

## InputMethodAbility<a name="InputMethodAbility"></a>

下列API示例中都需使用[getInputMethodAbility](#getInputMethodAbility)回调获取到InputMethodAbility实例，再通过此实例调用对应方法。

### on('inputStart')<a name="inputStart9"></a><sup>9+</sup>

on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void

订阅输入法绑定成功事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型。<br/>-type为‘inputStart’时表示订阅输入法绑定。 |
| callback | [KeyboardController](#keyboardcontroller), [InputClient](#inputclient-9) | 是 | 回调函数，返回输入法操作相关实例。 |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, inputClient) => {
    KeyboardController = kbController;
    InputClient = inputClient;
});
```

### off('inputStart')<sup>9+</sup>

off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void

取消订阅输入法绑定成功事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | 是   | 设置监听类型。<br/>-type为‘inputStart’时表示订阅输入法绑定。 |
| callback | [KeyboardController](#keyboardcontroller), [InputClient](#inputclient) | 否 | 回调函数，返回输入法操作相关实例。 |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('inputStart', (kbController, inputClient) => {
    console.log('delete inputStart notification.');
});
```

### on('inputStop')<sup>9+</sup>

on(type: 'inputStop', callback: () => void): void

订阅停止输入法应用事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘inputStop’时表示订阅停止输入法应用事件。 |
| callback | void   | 是   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('inputStop', () => {
    console.log('inputMethodAbility inputStop');
});
```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

取消订阅停止输入法应用事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘inputStop’时表示订阅停止输入法应用事件。 |
| callback | void   | 是   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('inputStop', () => {
    console.log('inputMethodAbility delete inputStop notification.');
});
```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid:number) => void): void

订阅设置调用窗口事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘setCallingWindow’时表示订阅设置调用窗口事件。 |
| callback | number | 是   | 回调函数，返回调用方window id。                                            |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('setCallingWindow', (wid) => {
    console.log('inputMethodAbility setCallingWindow');
});
```

### off('setCallingWindow')<sup>9+</sup>

off(type: 'setCallingWindow', callback: (wid:number) => void): void

取消订阅设置调用窗口事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘setCallingWindow’时表示订阅设置调用窗口事件。 |
| callback | number | 是   | 回调函数，返回调用方window id。                                 |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('setCallingWindow', () => {
    console.log('inputMethodAbility delete setCallingWindow notification.');
});
```

### on('keyboardShow'|'keyboardHide')<sup>9+</sup>

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

订阅输入法事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | void   | 否   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('keyboardShow', () => {
    console.log('InputMethodAbility keyboardShow.');
});
inputMethodEngine.getInputMethodAbility().on('keyboardHide', () => {
    console.log('InputMethodAbility keyboardHide.');
});
```

### off('keyboardShow'|'keyboardHide')<sup>9+</sup>

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

取消订阅输入法事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | void   | 否   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('keyboardShow', () => {
    console.log('InputMethodAbility delete keyboardShow notification.');
});
inputMethodEngine.getInputMethodAbility().off('keyboardHide', () => {
    console.log('InputMethodAbility delete keyboardHide notification.');
});
```

### on('setSubtype')<sup>9+</sup>

on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void

订阅设置输入法子类型事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'setSubtype'，表示订阅输入法子类型设置。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | InputMethodSubtype   | 是   | 回调函数，返回调用方的输入法子类型。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('setSubtype', (inputMethodSubtype) => {
    console.log('InputMethodAbility setSubtype.');
});
```

### off('setSubtype')<sup>9+</sup>

off(ype: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void

取消订阅输入法子类型事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'setSubtype'，表示取消订阅输入法子类型设置。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | InputMethodSubtype   | 是   | 回调函数，返回调用方的输入法子类型。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('setSubtype', () => {
    console.log('InputMethodAbility delete setSubtype notification.');
});
```

## KeyboardDelegate<a name="KeyboardDelegate"></a>

下列API示例中都需使用[getKeyboardDelegate](#getKeyboardDelegate)回调获取到KeyboardDelegate实例，再通过此实例调用对应方法。

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

订阅硬键盘事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type   | string         | 是   | 设置监听类型。<br/>-&nbsp;type为'keyDown'，表示订阅硬键盘按下。<br/>-&nbsp;type为'keyUp'，表示订阅硬键盘抬起。 |
| callback | [KeyEvent](#keyevent) | 是 | 回调函数，返回按键信息。 |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('keyUp', (keyEvent) => {
    console.info('inputMethodEngine keyCode.(keyUp):' + JSON.stringify(keyEvent.keyCode));
    console.info('inputMethodEngine keyAction.(keyUp):' + JSON.stringify(keyEvent.keyAction));
    return true;
});
inputMethodEngine.getKeyboardDelegate().on('keyDown', (keyEvent) => {
    console.info('inputMethodEngine keyCode.(keyDown):' + JSON.stringify(keyEvent.keyCode));
    console.info('inputMethodEngine keyAction.(keyDown):' + JSON.stringify(keyEvent.keyAction));
    return true;
});
```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

取消订阅硬键盘事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| type     | string                | 是   | 设置监听类型。<br/>-&nbsp;type为'keyDown'，表示订阅硬键盘按下。<br/>-&nbsp;type为'keyUp'，表示订阅硬键盘抬起。 |
| callback | [KeyEvent](#keyevent) | 否   | 回调函数，返回按键信息。                                           |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('keyUp', (keyEvent) => {
    console.log('delete keyUp notification.');
    return true;
});
inputMethodEngine.getKeyboardDelegate().off('keyDown', (keyEvent) => {
    console.log('delete keyDown notification.');
    return true;
});
```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

订阅光标变化事件。使用callback异步回调。

  **系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 光标变化事件。<br/>-type为’cursorContextChange‘时，表示光标变化。 |
| callback | number | 是   | 回调函数，返回光标信息。                                           |



  **示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('cursorContextChange', (x, y, height) => {
    console.log('inputMethodEngine cursorContextChange x:' + x);
    console.log('inputMethodEngine cursorContextChange y:' + y);
    console.log('inputMethodEngine cursorContextChange height:' + height);
});
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y:number, height:number) => void): void

取消订阅光标变化事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 光标变化事件。<br/>-type为’cursorContextChange‘时，表示光标变化。 |
| callback | number | 否   | 回调函数，返回光标信息。                                           |


  **示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('cursorContextChange', (x, y, height) => {
    console.log('delete cursorContextChange notification.');
});
```
### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

订阅文本选择变化事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本选择变化事件。<br/>-type为’selectionChange‘时，表示选择文本变化。 |
| callback | number | 是   | 回调函数，返回文本选择信息。                                       |

  **示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
    console.log('inputMethodEngine beforeEach selectionChange oldBegin:' + oldBegin);
    console.log('inputMethodEngine beforeEach selectionChange oldEnd:' + oldEnd);
    console.log('inputMethodEngine beforeEach selectionChange newBegin:' + newBegin);
    console.log('inputMethodEngine beforeEach selectionChange newEnd:' + newEnd);
});
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

取消订阅文本选择变化事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本选择变化事件。<br/>-type为’selectionChange‘时，表示选择文本变化。 |
| callback | number | 否   | 回调函数，返回文本选择信息。                                       |

  **示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
  console.log('delete selectionChange notification.');
});
```


### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

订阅文本变化事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件。<br/>-type为’textChange‘时，表示当前文本变化。 |
| callback | string | 是   | 回调函数，返回当前文本内容。                                       |

  **示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('textChange', (text) => {
    console.log('inputMethodEngine textChange. text:' + text);
});
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

取消订阅文本变化事件。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件。<br/>-type为’textChange‘时，表示当前文本变化。 |
| callback | string | 否   | 回调函数，返回当前文本内容。                                       |

  **示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('textChange', (text) => {
    console.log('delete textChange notification. text:' + text);
});
```

## KeyboardController<a name="KeyboardController"></a>

下列API示例中都需使用[inputStart](#inputStart9)回调获取到KeyboardController实例，再通过此实例调用对应方法。

### hide<sup>9+</sup>

hide(callback: AsyncCallback&lt;void&gt;): void

隐藏输入法。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | 否   | 回调函数。当输入法隐藏成功，err为undefined，否则为错误对象 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800003 | Input method client error. |

**示例：**

```js
KeyboardController.hide((err) => {
    if (err === undefined) {
        console.error('hide err: ' + JSON.stringify(err));
        return;
    }
    console.log('hide success.');
});
```

### hide<sup>9+</sup>

hide(): Promise&lt;void&gt;

隐藏输入法。使用promise异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型             | 说明                      |
| ---------------- | ------------------------- |
| Promise&lt;void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800003 | Input method client error. |

**示例：**

```js
async function InputMethodEngine() {
    await KeyboardController.hide().then(() => {
        console.info('hide success.');
    }).catch((err) => {
        console.info('hide err: ' + JSON.stringify(err));
    });
}
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏输入法。使用callback异步回调。

> **说明：**
> 从API version 8开始支持，API version 9开始废弃, 建议使用[hide](#hide9)替代。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | 否   | 回调函数。当输入法隐藏成功，err为undefined，否则为错误对象 |

**示例：**

```js
KeyboardController.hideKeyboard((err) => {
    if (err === undefined) {
        console.error('hideKeyboard err: ' + JSON.stringify(err));
        return;
    }
    console.log('hideKeyboard success.');
});
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(): Promise&lt;void&gt;

隐藏输入法。使用promise异步回调。

> **说明：**
> 从API version 8开始支持，API version 9开始废弃, 建议使用[hide](#hide9-1)替代。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型             | 说明                      |
| ---------------- | ------------------------- |
| Promise&lt;void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```js
async function InputMethodEngine() {
    await KeyboardController.hideKeyboard().then(() => {
        console.info('hideKeyboard success.');
    }).catch((err) => {
        console.info('hideKeyboard err: ' + JSON.stringify(err));
    });
}
```

## InputClient<a name="InputClient "></a><sup>9+</sup>

下列API示例中都需使用[inputStart](#inputStart9)回调获取到InputClient实例，再通过此实例调用对应方法。

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

发送功能键。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 编辑框属性。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当功能键发送成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800003 | Input method client error. |

 **示例：**

```js
try {
    InputClient.sendKeyFunction(keyFunction, (err, result) => {
        if (err) {
            console.error('sendKeyFunction err: ' + JSON.stringify(err)JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Success to sendKeyFunction. ');
        } else {
            console.error('Failed to sendKeyFunction. ');
        }
    });
} catch (err) {
    console.error('sendKeyFunction err: ' + JSON.stringify(err));
}
```

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action:number): Promise&lt;boolean&gt;

发送功能键。使用promise异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 编辑框属性。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示功能键发送成功；返回false表示功能键发送失败。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800003 | Input method client error. |

**示例：**

```js
try {
    InputClient.sendKeyFunction(keyFunction).then((result) => {
        if (result) {
            console.info('Success to sendKeyFunction. ');
        } else {
            console.error('Failed to sendKeyFunction. ');
        }
    }).catch((err) => {
        console.error('sendKeyFunction err:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('sendKeyFunction err: ' + JSON.stringify(err));
}
```

### getForward<sup>9+</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标前固定长度的文本。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标前固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                     |
| -------- | ------------------------------ |
| 12800003 | Input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
let length = 1;
try {
    InputClient.getForward(length, (err, text) => {
        if (err) {
            console.error('getForward err: ' + JSON.stringify(err));
            return;
        }
        console.log('getForward result: ' + text);
    });
} catch (err) {
    console.error('getForward err: ' + JSON.stringify(err));
}
```

### getForward<sup>9+</sup>

getForward(length:number): Promise&lt;string&gt;

获取光标前固定长度的文本。使用promise异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise对象，返回光标前固定长度的文本。                     |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                     |
| -------- | ------------------------------ |
| 12800003 | Input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
async function InputMethodAbility() {
    let length = 1;
    try {
        await InputClient.getForward(length).then((text) => {
            console.info('getForward resul: ' + text);
        }).catch((err) => {
            console.error('getForward err: ' + JSON.stringify(err));
        });
    } catch (err) {
        console.error('getForward err: ' + JSON.stringify(err));
    }
}
```

### getBackward<sup>9+</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标后固定长度的文本。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标后固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                     |
| -------- | ------------------------------ |
| 12800003 | Input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
let length = 1;
try {
    InputClient.getBackward(length, (err, text) => {
        if (err) {
            console.error('getBackward result: ' + JSON.stringify(err));
            return;
        }
        console.log('getBackward result---text: ' + text);
    });
} catch (err) {
    console.error('getBackward result: ' + JSON.stringify(err));
}
```

### getBackward<sup>9+</sup>

getBackward(length:number): Promise&lt;string&gt;

获取光标后固定长度的文本。使用promise异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise对象，返回光标后固定长度的文本。                     |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                     |
| -------- | ------------------------------ |
| 12800003 | Input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
async function InputMethodAbility() {
    let length = 1;
    try {
        await InputClient.getBackward(length).then((text) => {
            console.info('getBackward result: ' + text);
        }).catch((err) => {
            console.error('getBackward err: ' + JSON.stringify(err));
        });
    } catch (err) {
        console.error('getBackward err: ' + JSON.stringify(err));
    }
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标前固定长度的文本。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当光标前固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | Input method client error. |

**示例：**

```js
let length = 1;
try {
    InputClient.deleteForward(length, (err, result) => {
        if (err) {
            console.error('deleteForward result: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Success to deleteForward. ');
        } else {
            console.error('Failed to deleteForward. ');
        }
    });
} catch (err) {
    console.error('deleteForward result: ' + JSON.stringify(err));
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number): Promise&lt;boolean&gt;

删除光标前固定长度的文本。使用promise异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。 |

**返回值：**  

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示删除光标前固定长度的文本成功；返回false表示删除光标前固定长度的文本失败。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | Input method client error. |

**示例：**

```js
async function InputMethodAbility() {
    let length = 1;
    try {
        await InputClient.deleteForward(length).then((result) => {
            if (result) {
                console.info('Success to deleteForward. ');
            } else {
                console.error('Failed to deleteForward. ');
            }
        }).catch((err) => {
            console.error('deleteForward err: ' + JSON.stringify(err));
        });
    } catch (err) {
        console.error('deleteForward err: ' + JSON.stringify(err));
    }
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标后固定长度的文本。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | 是   | 文本长度。     |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。当光标后固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | Input method client error. |

**示例：**

```js
let length = 1;
try {
    InputClient.deleteBackward(length, (err, result) => {
        if (err) {
            console.error('deleteBackward err: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Success to deleteBackward. ');
        } else {
            console.error('Failed to deleteBackward. ');
        }
    });
} catch (err) {
    console.error('deleteBackward err: ' + JSON.stringify(err));
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number): Promise&lt;boolean&gt;

删除光标后固定长度的文本。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：** 

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示删除光标后固定长度的文本成功；返回false表示删除光标后固定长度的文本失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | Input method client error. |

**示例：**

```js
async function InputMethodAbility() {
    let length = 1;
    await InputClient.deleteBackward(length).then((result) => {
        if (result) {
            console.info('Success to deleteBackward. ');
        } else {
            console.error('Failed to deleteBackward. ');
        }
    }).catch((err) => {
        console.error('deleteBackward err: ' + JSON.stringify(err));
    });
}
```

### insertText<sup>9+</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

插入文本。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当文本插入成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | Input method client error. |

**示例：**

```js
InputClient.insertText('test', (err, result) => {
    if (err) {
        console.error('insertText err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to insertText. ');
    } else {
        console.error('Failed to insertText. ');
    }
});
```

### insertText<sup>9+</sup>

insertText(text:string): Promise&lt;boolean&gt;

插入文本。使用promise异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |

**返回值：**  

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt;  |  Promise对象。返回true表示插入文本成功；返回false表示插入文本失败。  |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | Input method client error. |

**示例：**

```js
async function InputMethodAbility() {
    try {
        await InputClient.insertText('test').then((result) => {
            if (result) {
                console.info('Success to insertText. ');
            } else {
                console.error('Failed to insertText. ');
            }
        }).catch((err) => {
            console.error('insertText err: ' + JSON.stringify(err));
        });
    } catch (e) {
        console.error('insertText err: ' + JSON.stringify(err));
    }
}
```

### getEditorAttribute<sup>9+</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

获取编辑框属性值。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名                         | 类型                          | 必填                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#EditorAttribute)&gt; | 是 |  回调函数。当编辑框属性值获取成功，err为undefined，data为编辑框属性值；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800003 | Input method client error. |

**示例：**

```js
InputClient.getEditorAttribute((err, editorAttribute) => {
    if (err) {
        console.error('getEditorAttribute err: ' + JSON.stringify(err));
        return;
    }
    console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
});
```

### getEditorAttribute<sup>9+</sup>

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

获取编辑框属性值。使用promise异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#editorattribute)&gt; |  Promise对象，返回编辑框属性值。           |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800003 | Input method client error. |

**示例：**

```js
async function InputMethodEngine() {
    await InputClient.getEditorAttribute().then((editorAttribute) => {
        console.info('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
        console.info('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
    }).catch((err) => {
        console.error('getEditorAttribute err: ' + JSON.stringify(err));
    });
}
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number, callback: AsyncCallback&lt;void&gt;): void

移动光标。使用callback异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------- |
| direction | number                    | 是   | 光标移动方向。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当光标移动成功，err为undefined，否则为错误对象    |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800003 | Input method client error. |

**示例：**

```js
try {
    InputClient.moveCursor(inputMethodAbility.CURSOR_xxx, (err) => {
        if (err) {
            console.error('moveCursor err: ' + JSON.stringify(err));
            return;
        }
        console.info('moveCursor success');
    });
} catch (err) {
    console.error('moveCursor err: ' + JSON.stringify(err));
}
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number): Promise&lt;void&gt;

移动光标。使用promise异步回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型   | 必填 | 说明           |
| --------- | ------ | ---- | -------------- |
| direction | number | 是   | 光标移动方向。 |

**返回值：**  

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errcode-inputmethod-framework.md)。

| 错误码ID | 错误码信息                 |
| -------- | -------------------------- |
| 12800003 | Input method client error. |

**示例：**

```js
async function InputMethodAbility() {
    try {
        await InputClient.moveCursor(inputMethodEngine.CURSOR_xxx).then((err) => {
            if (err) {
                console.log('moveCursor err: ' + JSON.stringify(err));
                return;
            }
            console.log('moveCursor success');
        }).catch((err) => {
            console.error('moveCursor success err: ' + JSON.stringify(err));
        });
    } catch (err) {
        console.log('moveCursor err: ' + JSON.stringify(err));
    }
}
```

## EditorAttribute<a name="EditorAttribute"></a>

编辑框属性值。

**系统能力**：以下各项对应的系统能力均为SystemCapability.MiscServices.InputMethodFramework

| 名称         | 参数类型 | 可读 | 可写 | 说明               |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | 是   | 否   | 编辑框的功能属性。 |
| inputPattern | number   | 是   | 否   | 编辑框的文本属性。 |

## KeyEvent<a name="KeyEvent"></a>

按键属性值。

**系统能力**：以下各项对应的系统能力均为SystemCapability.MiscServices.InputMethodFramework

| 名称      | 参数类型 | 可读 | 可写 | 说明         |
| --------- | -------- | ---- | ---- | ------------ |
| keyCode   | number   | 是   | 否   | 按键的键值。 |
| keyAction | number   | 是   | 否   | 按键的状态。 |

## TextInputClient<a name="TextInputClient"></a>

下列API示例中都需使用[inputStart](#inputStart)回调获取到TextInputClient实例，再通过此实例调用对应方法。

### getForward<sup>(deprecated)</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标前固定长度的文本。使用callback异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[getForward](#getforward9)替代。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标前固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。|

**示例：**

```js
let length = 1;
TextInputClient.getForward(length, (err, text) => {
    if (err === undefined) {
        console.error('getForward err: ' + JSON.stringify(err));
        return;
    }
    console.log('getForward result---text: ' + text);
});
```

### getForward<sup>(deprecated)</sup>

getForward(length:number): Promise&lt;string&gt;

获取光标前固定长度的文本。使用promise异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[getForward](#getforward9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise对象，返回光标前固定长度的文本。                |

**示例：**

```js
async function InputMethodEngine() {
    let length = 1;
    await TextInputClient.getForward(length).then((text) => {
        console.info('getForward result---res: ' + text);
    }).catch((err) => {
        console.error('getForward err: ' + JSON.stringify(err));
    });
}
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标后固定长度的文本。使用callback异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[getBackward](#getbackward9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标后固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |

**示例：**

```js
let length = 1;
TextInputClient.getBackward(length, (err, text) => {
    if (err === undefined) {
        console.error('getBackward err: ' + JSON.stringify(err));
        return;
    }
    console.log('getBackward result---text: ' + text);
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number): Promise&lt;string&gt;

获取光标后固定长度的文本。使用promise异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[getBackward](#getbackward9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise对象，返回光标后固定长度的文本。                |

**示例：**

```js
async function InputMethodEngine() {
    let length = 1;
    await TextInputClient.getBackward(length).then((text) => {
        console.info('getBackward result---res: ' + text);
    }).catch((err) => {
        console.error('getBackward err: ' + JSON.stringify(err));
    });
}
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标前固定长度的文本。使用callback异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[deleteForward](#deleteforward9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当光标前固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
let length = 1;
TextInputClient.deleteForward(length, (err, result) => {
    if (err === undefined) {
        console.error('deleteForward err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to deleteForward. ');
    } else {
        console.error('Failed to deleteForward. ');
    }
});
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number): Promise&lt;boolean&gt;

删除光标前固定长度的文本。使用promise异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[deleteForward](#deleteforward9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。 |

**返回值：**  

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示删除光标前固定长度的文本成功；返回false表示删除光标前固定长度的文本失败。|

**示例：**

```js
async function InputMethodEngine() {
    let length = 1;
    await TextInputClient.deleteForward(length).then((result) => {
        if (result) {
            console.info('Success to deleteForward. ');
        } else {
            console.error('Failed to deleteForward. ');
        }
    }).catch((err) => {
        console.error('deleteForward err: ' + JSON.stringify(err));
    });
}
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标后固定长度的文本。使用callback异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[deleteBackward](#deletebackward9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | 是   | 文本长度。     |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。当光标后固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。|

  **示例：**

```js
let length = 1;
TextInputClient.deleteBackward(length, (err, result) => {
    if (err === undefined) {
        console.error('deleteBackward err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to deleteBackward. ');
    } else {
        console.error('Failed to deleteBackward. ');
    }
});
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number): Promise&lt;boolean&gt;

删除光标后固定长度的文本。使用callback异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[deleteBackward](#deletebackward9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：** 

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示删除光标后固定长度的文本成功；返回false表示删除光标后固定长度的文本失败。|

**示例：**

```js
async function InputMethodEngine() {
    let length = 1;
    await TextInputClient.deleteBackward(length).then((result) => {
        if (result) {
            console.info('Success to deleteBackward. ');
        } else {
            console.error('Failed to deleteBackward. ');
        }
    }).catch((err) => {
        console.error('deleteBackward err: ' + JSON.stringify(err));
    });
}
```
### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

发送功能键。使用callback异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[sendKeyFunction](#sendkeyfunction9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 编辑框属性。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当功能键发送成功，err为undefined，data为true；否则为错误对象。 |

  **示例：**

```js
TextInputClient.sendKeyFunction(keyFunction, (err, result) => {
    if (err === undefined) {
        console.error('sendKeyFunction err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to sendKeyFunction. ');
    } else {
        console.error('Failed to sendKeyFunction. ');
    }
});
```

### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action:number): Promise&lt;boolean&gt;

发送功能键。使用promise异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[sendKeyFunction](#sendkeyfunction9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 编辑框属性。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示发送功能键成功；返回false表示发送功能键失败。 |

**示例：**

```js
async function InputMethodEngine() {
    await client.sendKeyFunction(keyFunction).then((result) => {
        if (result) {
            console.info('Success to sendKeyFunction. ');
        } else {
            console.error('Failed to sendKeyFunction. ');
        }
    }).catch((err) => {
        console.error('sendKeyFunction err:' + JSON.stringify(err));
    });
}
```

### insertText<sup>(deprecated)</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

插入文本。使用callback异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[insertText](#inserttext9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当文本插入成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
TextInputClient.insertText('test', (err, result) => {
    if (err === undefined) {
        console.error('insertText err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to insertText. ');
    } else {
        console.error('Failed to insertText. ');
    }
});
```

### insertText<sup>(deprecated)</sup>

insertText(text:string): Promise&lt;boolean&gt;

插入文本。使用promise异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[insertText](#inserttext9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |

**返回值：**  

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示插入文本成功；返回false表示插入文本失败。 |

**示例：**

```js
async function InputMethodEngine() {
    await TextInputClient.insertText('test').then((result) => {
        if (result) {
            console.info('Success to insertText. ');
        } else {
            console.error('Failed to insertText. ');
        }
    }).catch((err) => {
        console.error('insertText err: ' + JSON.stringify(err));
    });
}
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

获取编辑框属性值。使用callback异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[getEditorAttribute](#geteditorattribute9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名                         | 类型                          | 必填                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#editorattribute)&gt; | 是 |  回调函数。当编辑框的属性值获取成功，err为undefined，data为编辑框属性值；否则为错误对象。|

**示例：**

```js
TextInputClient.getEditorAttribute((err, editorAttribute) => {
    if (err === undefined) {
        console.error('getEditorAttribute err: ' + JSON.stringify(err));
        return;
    }
    console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
});
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

获取编辑框属性值。使用promise异步回调。

> **说明：** 
> 从API version 8开始支持，API version 9开始废弃, 建议使用[getEditorAttribute](#geteditorattribute9)替代

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#editorattribute)&gt; |  Promise对象，返回编辑框属性值。           |

**示例：**

```js
async function InputMethodEngine() {
    await TextInputClient.getEditorAttribute().then((editorAttribute) => {
        console.info('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
        console.info('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
    }).catch((err) => {
        console.error('getEditorAttribute err: ' + JSON.stringify(err));
    });
}
```