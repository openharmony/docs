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

## inputMethodEngine.getInputMethodEngine<a name="getInputMethodEngine"></a>

getInputMethodEngine(): InputMethodEngine

获取服务端实例。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                    | 说明         |
| --------------------------------------- | ------------ |
| [InputMethodEngine](#InputMethodEngine) | 服务端实例。 |

**示例：**

  ```js
  var InputMethodEngine = inputMethodEngine.getInputMethodEngine();
  ```

## inputMethodEngine.createKeyboardDelegate<a name="createKeyboardDelegate"></a>

createKeyboardDelegate(): KeyboardDelegate

获取客户端监听实例。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                  | 说明             |
| ------------------------------------- | ---------------- |
| [KeyboardDelegate](#KeyboardDelegate) | 客户端监听实例。 |

**示例：**

  ```js
  var KeyboardDelegate = inputMethodEngine.createKeyboardDelegate();
  ```

## InputMethodEngine<a name="InputMethodEngine"></a>

下列API示例中都需使用[getInputMethodEngine](#getInputMethodEngine)回调获取到InputMethodEngine实例，再通过此实例调用对应方法。

### on('inputStart')<a name="inputStart"></a>

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

订阅输入法绑定成功事件，使用callback回调返回输入法操作相关实例。参数个数为2，参数1为napi_string，参数2为napi_function，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型。<br/>-type为‘inputStart’时表示订阅输入法绑定。 |
| callback | [KeyboardController](#KeyboardController), [TextInputClient](#TextInputClient) | 是 | 回调返回输入法操作相关实例。 |

**示例：**

  ```js
  InputMethodEngine.on('inputStart', (kbController, textInputClient) => {
      KeyboardController = kbController;
      TextInputClient = textInputClient;
  });
  ```

### off('inputStart')

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

取消订阅输入法绑定成功事件。参数个数不为1或2抛出异常。若为1，参数不为napi_string抛出异常；若为2，参数1不为napi_string，参数2不为napi_function抛出异常。参数若为1，取消此类型所有监听；参数若为2，取消此类型当前监听。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | 是   | 设置监听类型。<br/>-type为‘inputStart’时表示订阅输入法绑定。 |
| callback | [KeyboardController](#KeyboardController), [TextInputClient](#TextInputClient) | 否 | 回调返回输入法操作相关实例。 |



**示例：**

  ```js
  InputMethodEngine.off('inputStart', (kbController, textInputClient) => {
      console.log("delete inputStart notification.");
  });
  ```

### on('inputStop')<sup>9+</sup>

on(type: 'inputStop', callback: () => void): void

订阅停止输入法应用事件，使用callback回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘inputStop’时表示订阅停止输入法应用事件。 |
| callback | void   | 是   | 回调函数。                                                   |

**示例：**

  ```js
InputMethodEngine.getInputMethodEngine().on('inputStop', () => {
    console.log("inputMethodEngine inputStop");
});
  ```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

取消订阅停止输入法应用事件。使用callback回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘inputStop’时表示订阅停止输入法应用事件。 |
| callback | void   | 是   | 回调函数。                                                   |

**示例：**

  ```js
InputMethodEngine.getInputMethodEngine().off('inputStop', () => {
    console.log("inputMethodEngine delete inputStop notification.");
});
  ```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid:number) => void): void

订阅设置调用窗口事件，使用callback回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘setCallingWindow’时表示订阅设置调用窗口事件。 |
| callback | number | 是   | 调用方window id。                                            |

**示例：**

  ```js
InputMethodEngine.getInputMethodEngine().on('setCallingWindow', (wid) => {
    console.log("inputMethodEngine setCallingWindow");
});
  ```

### off('setCallingWindow')<sup>9+</sup>

off(type: 'setCallingWindow', callback: (wid:number) => void): void

取消订阅设置调用窗口事件。使用callback回调。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-type为‘setCallingWindow’时表示订阅设置调用窗口事件。 |
| callback | number | 是   | 调用方window id。                                 |

**示例：**

  ```js
InputMethodEngine.getInputMethodEngine().off('setCallingWindow', () => {
    console.log("inputMethodEngine delete setCallingWindow notification.");
});
  ```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

订阅输入法事件。参数个数为2，参数1为napi_string，参数2为napi_function，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | void   | 否   | 回调函数。                                                   |

**示例：**

  ```js
  InputMethodEngine.on('keyboardShow', () => {
      console.log("inputMethodEngine keyboardShow.");
  });
  InputMethodEngine.on('keyboardHide', () => {
      console.log("inputMethodEngine keyboardHide.");
  });
  ```

### off('keyboardShow'|'keyboardHide')

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

取消订阅输入法事件。参数个数不为1或2抛出异常。若为1，参数不为napi_string抛出异常；若为2，参数1不为napi_string，参数2不为napi_function抛出异常。参数若为1，取消此类型所有监听；参数若为2，取消此类型当前监听。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | void   | 否   | 回调函数。                                                   |

**示例：**

  ```js
  InputMethodEngine.off('keyboardShow', () => {
      console.log("inputMethodEngine delete keyboardShow notification.");
  });
  InputMethodEngine.off('keyboardHide', () => {
      console.log("inputMethodEngine delete keyboardHide notification.");
  });
  ```


## KeyboardDelegate<a name="KeyboardDelegate"></a>

下列API示例中都需使用[createKeyboardDelegate](#createKeyboardDelegate)回调获取到KeyboardDelegate实例，再通过此实例调用对应方法。

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

订阅硬键盘事件，使用callback回调返回按键信息。参数个数为2，参数1为napi_string，参数2为napi_function，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type   | string         | 是   | 设置监听类型。<br/>-&nbsp;type为'keyDown'，表示订阅硬键盘按下。<br/>-&nbsp;type为'keyUp'，表示订阅硬键盘抬起。 |
| callback | [KeyEvent](#KeyEvent) | 是 | 回调返回按键信息。 |



**示例：**

  ```js
  KeyboardDelegate.on('keyUp', (keyEvent) => {
      console.info("inputMethodEngine keyCode.(keyUp):" + JSON.stringify(keyEvent.keyCode));
      console.info("inputMethodEngine keyAction.(keyUp):" + JSON.stringify(keyEvent.keyAction));
      return true;
  });
  KeyboardDelegate.on('keyDown', (keyEvent) => {
      console.info("inputMethodEngine keyCode.(keyDown):" + JSON.stringify(keyEvent.keyCode));
      console.info("inputMethodEngine keyAction.(keyDown):" + JSON.stringify(keyEvent.keyAction));
      return true;
  });
  ```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

取消订阅硬键盘事件。参数个数不为1或2抛出异常。若为1，参数不为napi_string抛出异常；若为2，参数1不为napi_string，参数2不为napi_function抛出异常。参数若为1，取消此类型所有监听；参数若为2，取消此类型当前监听。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| type     | string                | 是   | 设置监听类型。<br/>-&nbsp;type为'keyDown'，表示订阅硬键盘按下。<br/>-&nbsp;type为'keyUp'，表示订阅硬键盘抬起。 |
| callback | [KeyEvent](#KeyEvent) | 否   | 回调返回按键信息。                                           |

**示例：**

  ```js
  KeyboardDelegate.off('keyUp', (keyEvent) => {
      console.log("delete keyUp notification.");
      return true;
  });
  KeyboardDelegate.off('keyDown', (keyEvent) => {
      console.log("delete keyDown notification.");
      return true;
  });
  ```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

订阅光标变化事件，使用callback回调返回光标信息。使用callback回调返回光标信息。参数个数为2，参数1为napi_string，参数2为napi_function，否则抛出异常。

  **系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 光标变化事件。<br/>-type为’cursorContextChange‘时，表示光标变化。 |
| callback | number | 是   | 回调返回光标信息。                                           |



  **示例：**

```js
KeyboardDelegate.on('cursorContextChange', (x, y, height) => {
    console.log("inputMethodEngine cursorContextChange x:" + x);
    console.log("inputMethodEngine cursorContextChange y:" + y);
    console.log("inputMethodEngine cursorContextChange height:" + height);
});
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y:number, height:number) => void): void

取消订阅光标变化事件。参数个数不为1或2抛出异常。若为1，参数不为napi_string抛出异常；若为2，参数1不为napi_string，参数2不为napi_function抛出异常。参数若为1，取消此类型所有监听；参数若为2，取消此类型当前监听。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 光标变化事件。<br/>-type为’cursorContextChange‘时，表示光标变化。 |
| callback | number | 否   | 回调返回光标信息。                                           |


  **示例：**

```js
KeyboardDelegate.off('cursorContextChange', (x, y, height) => {
    console.log("delete cursorContextChange notification.");
});
```
### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

订阅文本选择变化事件，使用callback回调返回文本选择信息。参数个数为2，参数1为napi_string，参数2为napi_function，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本选择变化事件。<br/>-type为’selectionChange‘时，表示选择文本变化。 |
| callback | number | 是   | 回调返回文本选择信息。                                       |

  **示例：**

```js
KeyboardDelegate.on('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
    console.log("inputMethodEngine beforeEach selectionChange oldBegin:" + oldBegin);
    console.log("inputMethodEngine beforeEach selectionChange oldEnd:" + oldEnd);
    console.log("inputMethodEngine beforeEach selectionChange newBegin:" + newBegin);
    console.log("inputMethodEngine beforeEach selectionChange newEnd:" + newEnd);
});
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

取消订阅文本选择变化事件。参数个数不为1或2抛出异常。若为1，参数不为napi_string抛出异常；若为2，参数1不为napi_string，参数2不为napi_function抛出异常。参数若为1，取消此类型所有监听；参数若为2，取消此类型当前监听。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本选择变化事件。<br/>-type为’selectionChange‘时，表示选择文本变化。 |
| callback | number | 否   | 回调返回文本选择信息。                                       |

  **示例：**

```js
KeyboardDelegate.off('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
  console.log("delete selectionChange notification.");
});
```


### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

订阅文本变化事件，使用callback回调返回当前文本内容。参数个数为2，参数1为napi_string，参数2为napi_function，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件。<br/>-type为’textChange‘时，表示当前文本变化。 |
| callback | string | 是   | 回调返回当前文本内容。                                       |

  **示例：**

```js
KeyboardDelegate.on('textChange', (text) => {
    console.log("inputMethodEngine textChange. text:" + text);
});
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

取消订阅文本变化事件。参数个数不为1或2抛出异常。若为1，参数不为napi_string抛出异常；若为2，参数1不为napi_string，参数2不为napi_function抛出异常。参数若为1，取消此类型所有监听；参数若为2，取消此类型当前监听。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件。<br/>-type为’textChange‘时，表示当前文本变化。 |
| callback | string | 否   | 回调返回当前文本内容。                                       |

  **示例：**

```js
keyboardDelegate.off('textChange', (text) => {
    console.log("delete textChange notification. text:" + text);
});
```

## KeyboardController<a name="KeyboardController"></a>

下列API示例中都需使用[inputStart](#inputStart)回调获取到KeyboardController实例，再通过此实例调用对应方法。

### hideKeyboard

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏输入法。使用callback形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | 否   | 回调函数 |

**示例：**


```js
KeyboardController.hideKeyboard((err) => {
    if (err == undefined) {
        console.error("hideKeyboard callback result---err: " + err.msg);
        return;
    }
    console.log("hideKeyboard callback.");
});
```

### hideKeyboard

hideKeyboard(): Promise&lt;void&gt;

隐藏输入法。使用peomise形式返回结果。参数个数为0，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型             | 说明                      |
| ---------------- | ------------------------- |
| Promise&lt;void> | 无返回结果的Promise对象。 |

**示例：**

```js
async function InputMethodEngine() {
    await KeyboardController.hideKeyboard().then(() => {
        console.info("hideKeyboard promise.");
    }).catch((err) => {
        console.info("hideKeyboard promise err: " + err.msg);
    });
}
```

## TextInputClient<a name="TextInputClient"></a>

下列API示例中都需使用[inputStart](#inputStart)回调获取到TextInputClient实例，再通过此实例调用对应方法。

### getForward

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标前固定长度的文本。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 返回文本。 |

**示例：**

  ```js
  var length = 1;
  TextInputClient.getForward(length, (err, text) => {
      if (err == undefined) {
          console.error("getForward callback result---err: " + err.msg);
          return;
      }
      console.log("getForward callback result---text: " + text);
  });
  ```

### getForward

getForward(length:number): Promise&lt;string&gt;

获取光标前固定长度的文本。使用promise形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  返回文本。                |

**示例：**

  ```js
  async function InputMethodEngine() {
      var length = 1;
      await TextInputClient.getForward(length).then((text) => {
          console.info("getForward promise result---res: " + text);
      }).catch((err) => {
          console.error("getForward promise err: " + err.msg);
      });
  }
  ```

### getBackward

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标后固定长度的文本。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 返回文本。 |

**示例：**

  ```js
  var length = 1;
  TextInputClient.getBackward(length, (err, text) => {
      if (err == undefined) {
          console.error("getBackward callback result---err: " + err.msg);
          return;
      }
      console.log("getBackward callback result---text: " + text);
  });
  ```

### getBackward

getBackward(length:number): Promise&lt;string&gt;

获取光标后固定长度的文本。使用promise形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  返回文本。                |

**示例：**

  ```js
  async function InputMethodEngine() {
      var length = 1;
      await TextInputClient.getBackward(length).then((text) => {
          console.info("getBackward promise result---res: " + text);
      }).catch((err) => {
          console.error("getBackward promise err: " + err.msg);
      });
  }
  ```

### deleteForward

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标前固定长度的文本。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 操作成功与否。 |

**示例：**

  ```js
  var length = 1;
  TextInputClient.deleteForward(length, (err, result) => {
      if (err == undefined) {
          console.error('deleteForward callback result---err: ' + err.msg);
          return;
      }
      if (result) {
          console.info("Success to deleteForward.(callback) ");
      } else {
          console.error("Failed to deleteForward.(callback) ");
      }
  });
  ```
### deleteForward

deleteForward(length:number): Promise&lt;boolean&gt;

删除光标前固定长度的文本。使用promise形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

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
async function InputMethodEngine() {
    var length = 1;
    await TextInputClient.deleteForward(length).then((result) => {
        if (result) {
            console.info("Success to deleteForward.(promise) ");
        } else {
            console.error("Failed to deleteForward.(promise) ");
        }
    }).catch((err) => {
        console.error("deleteForward promise err: " + err.msg);
    });
}
```

### deleteBackward

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标后固定长度的文本。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | 是   | 文本长度。     |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 操作成功与否。 |

  **示例：**

```js
var length = 1;
TextInputClient.deleteBackward(length, (err, result) => {
    if (err == undefined) {
        console.error("deleteBackward callback result---err: " + err.msg);
        return;
    }
    if (result) {
        console.info("Success to deleteBackward.(callback) ");
    } else {
        console.error("Failed to deleteBackward.(callback) ");
    }
});
```

### deleteBackward

deleteBackward(length:number): Promise&lt;boolean&gt;

删除光标后固定长度的文本。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：** 

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  操作成功与否。                |

**示例：**

```js
async function InputMethodEngine() {
    var length = 1;
    await TextInputClient.deleteBackward(length).then((result) => {
        if (result) {
            console.info("Success to deleteBackward.(promise) ");
        } else {
            console.error("Failed to deleteBackward.(promise) ");
        }
    }).catch((err) => {
        console.error("deleteBackward promise err: " + err.msg);
    });
}
```
### sendKeyFunction

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

发送功能键。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 编辑框属性。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 操作成功与否。 |

  **示例：**

```js
TextInputClient.sendKeyFunction(keyFunction, (err, result) => {
    if (err == undefined) {
        console.error("sendKeyFunction callback result---err: " + err.msg);
        return;
    }
    if (result) {
        console.info("Success to sendKeyFunction.(callback) ");
    } else {
        console.error("Failed to sendKeyFunction.(callback) ");
    }
});
```

### sendKeyFunction

sendKeyFunction(action:number): Promise&lt;boolean&gt;

发送功能键。使用promise形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 编辑框属性。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  操作成功与否。                |

**示例：**

  ```js
  async function InputMethodEngine() {
      await client.sendKeyFunction(keyFunction).then((result) => {
          if (result) {
              console.info("Success to sendKeyFunction.(promise) ");
          } else {
              console.error("Failed to sendKeyFunction.(promise) ");
          }
      }).catch((err) => {
          console.error("sendKeyFunction promise err:" + err.msg);
      });
  }
  ```

### insertText

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

插入文本。使用callback形式返回结果。参数个数为2，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 操作成功与否。 |

**示例：**

```js
TextInputClient.insertText('test', (err, result) => {
    if (err == undefined) {
        console.error("insertText callback result---err: " + err.msg);
        return;
    }
    if (result) {
        console.info("Success to insertText.(callback) ");
    } else {
        console.error("Failed to insertText.(callback) ");
    }
});
```

### insertText

insertText(text:string): Promise&lt;boolean&gt;

插入文本。使用promise形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |

**返回值：**  

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  操作成功与否。                |

**示例：**

  ```js
  async function InputMethodEngine() {
      await TextInputClient.insertText('test').then((result) => {
          if (result) {
              console.info("Success to insertText.(promise) ");
          } else {
              console.error("Failed to insertText.(promise) ");
          }
      }).catch((err) => {
          console.error("insertText promise err: " + err.msg);
      });
  }
  ```

### getEditorAttribute

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

获取编辑框属性值。使用callback形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名                         | 类型                          | 必填                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#EditorAttribute)&gt; | 是 |  编辑框属性值。                |

**示例：**

  ```js
  TextInputClient.getEditorAttribute((err, editorAttribute) => {
      if (err == undefined) {
          console.error("getEditorAttribute callback result---err: " + err.msg);
          return;
      }
      console.log("editorAttribute.inputPattern(callback): " + JSON.stringify(editorAttribute.inputPattern));
      console.log("editorAttribute.enterKeyType(callback): " + JSON.stringify(editorAttribute.enterKeyType));
  });
  ```

### getEditorAttribute

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

获取编辑框属性值。使用promise形式返回结果。参数个数为0，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#EditorAttribute)&gt; |  返回编辑框属性值。           |

**示例：**

   ```js
   async function InputMethodEngine() {
       await TextInputClient.getEditorAttribute().then((editorAttribute) => {
           console.info("editorAttribute.inputPattern(promise): " + JSON.stringify(editorAttribute.inputPattern));
           console.info("editorAttribute.enterKeyType(promise): " + JSON.stringify(editorAttribute.enterKeyType));
       }).catch((err) => {
           console.error("getEditorAttribute promise err: " + err.msg);
       });
   }
   ```

### moveCursor<sup>9+</sup>

moveCursor(direction: number, callback: AsyncCallback&lt;void&gt;): void

移动光标。使用callback形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------- |
| direction | number                    | 是   | 光标移动方向。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。     |

**示例：**

```js
TextInputClient.moveCursor(inputMethodEngine.CURSOR_xxx, (err) => {
    if (err == undefined) {
        console.error("moveCursor callback result---err: " + err.msg);
        return;
    }
});
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number): Promise&lt;void&gt;

移动光标。使用promise形式返回结果。参数个数为1，否则抛出异常。

**系统能力**： SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型   | 必填 | 说明           |
| --------- | ------ | ---- | -------------- |
| direction | number | 是   | 光标移动方向。 |

**返回值：**  

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

  ```js
async function InputMethodEngine() {
    await TextInputClient.moveCursor(inputMethodEngine.CURSOR_xxx).then(async (err) => {
        console.log('moveCursor success');
    }).catch((err) => {
        console.error("moveCursor success err: " + err.msg);
    });
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

