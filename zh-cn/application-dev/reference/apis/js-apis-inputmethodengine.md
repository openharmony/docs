# @ohos.inputMethodEngine (输入法服务)

本模块面向输入法应用（包括系统输入法应用、三方输入法应用），为输入法应用提供能力，功能包括：创建软键盘窗口、插入/删除字符、选中文本、物理键盘按键事件监听等。

> **说明：**
>
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import inputMethodEngine from '@ohos.inputMethodEngine';
```

## 常量

功能键常量值、编辑框常量值及光标常量值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 值 | 说明 |
| -------- | -------- | -------- | -------- |
| ENTER_KEY_TYPE_UNSPECIFIED | number | 0 | 无功能键。 |
| ENTER_KEY_TYPE_GO | number | 2 | “前往”功能键。 |
| ENTER_KEY_TYPE_SEARCH | number | 3 | “搜索”功能键。 |
| ENTER_KEY_TYPE_SEND | number | 4 | “发送”功能键。 |
| ENTER_KEY_TYPE_NEXT | number | 5 | “下一个”功能键。 |
| ENTER_KEY_TYPE_DONE | number | 6 | “回车”功能键。 |
| ENTER_KEY_TYPE_PREVIOUS | number | 7 | “前一个”功能键。 |
| PATTERN_NULL | number | -1 | 无特殊性编辑框。 |
| PATTERN_TEXT | number | 0 | 文本编辑框。 |
| PATTERN_NUMBER | number | 2 | 数字编辑框。 |
| PATTERN_PHONE | number | 3 | 电话号码编辑框。 |
| PATTERN_DATETIME | number | 4 | 日期编辑框。 |
| PATTERN_EMAIL | number | 5 | 邮件编辑框。 |
| PATTERN_URI | number | 6 | 超链接编辑框。 |
| PATTERN_PASSWORD | number | 7 | 密码编辑框。 |
| OPTION_ASCII | number | 20 | 允许输入ASCII值。 |
| OPTION_NONE | number | 0 | 不指定编辑框输入属性。 |
| OPTION_AUTO_CAP_CHARACTERS | number | 2 | 允许输入字符。 |
| OPTION_AUTO_CAP_SENTENCES | number | 8 | 允许输入句子。 |
| OPTION_AUTO_WORDS | number | 4 | 允许输入单词。 |
| OPTION_MULTI_LINE | number | 1 | 允许输入多行。 |
| OPTION_NO_FULLSCREEN | number | 10 | 半屏样式。 |
| FLAG_SELECTING | number | 2 | 编辑框处于选择状态。 |
| FLAG_SINGLE_LINE | number | 1 | 编辑框为单行。 |
| DISPLAY_MODE_PART | number | 0 | 编辑框显示为半屏。 |
| DISPLAY_MODE_FULL | number | 1 | 编辑框显示为全屏。 |
| CURSOR_UP<sup>9+</sup> | number | 1 | 光标上移。 |
| CURSOR_DOWN<sup>9+</sup> | number | 2 | 光标下移。 |
| CURSOR_LEFT<sup>9+</sup> | number | 3 | 光标左移。 |
| CURSOR_RIGHT<sup>9+</sup> | number | 4 | 光标右移。 |
| WINDOW_TYPE_INPUT_METHOD_FLOAT<sup>9+</sup> | number | 2105 | 输入法应用窗口风格标识。 |

## inputMethodEngine.getInputMethodAbility<sup>9+</sup>

getInputMethodAbility(): InputMethodAbility

为输入法应用获取输入法应用客户端实例[InputMethodAbility](#inputmethodability)。
该接口仅限于输入法应用调用。
输入法应用获取该实例可订阅软键盘显示/隐藏请求事件、创建/销毁输入法应用面板等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明               |
| ----------------------------------------- | ------------------ |
| [InputMethodAbility](#inputmethodability) | 输入法应用客户端。 |

**示例：**

```js
let InputMethodAbility = inputMethodEngine.getInputMethodAbility();
```

## inputMethodEngine.getKeyboardDelegate<sup>9+</sup>

getKeyboardDelegate(): KeyboardDelegate

为输入法应用获取客户端编辑事件监听代理实例[KeyboardDelegate](#keyboarddelegate)。输入法应用获取该实例可订阅物理键盘按键事件、选中文本变化事件等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                  | 说明                     |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | 客户端编辑事件监听代理。 |

**示例：**

```js
let KeyboardDelegate = inputMethodEngine.getKeyboardDelegate();
```

## inputMethodEngine.getInputMethodEngine<sup>(deprecated)</sup>

getInputMethodEngine(): InputMethodEngine

为输入法应用获取输入法应用客户端实例[InputMethodEngine](#inputmethodengine-1)。输入法应用获取该实例可订阅软键盘显示/隐藏请求事件等。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[getInputMethodAbility()](#inputmethodenginegetinputmethodability9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明               |
| ----------------------------------------- | ------------------ |
| [InputMethodEngine](#inputmethodengine-1) | 输入法应用客户端。 |

**示例：**

```js
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate<sup>(deprecated)</sup>

createKeyboardDelegate(): KeyboardDelegate

为输入法应用获取客户端编辑事件监听代理实例[KeyboardDelegate](#keyboarddelegate)。输入法应用获取该实例可订阅物理键盘按键事件、选中文本变化事件等。

> **说明：**
>
>从API version 8开始支持，API version 9开始废弃，建议使用[getKeyboardDelegate()](#inputmethodenginegetkeyboarddelegate9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                  | 说明                     |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | 客户端编辑事件监听代理。 |

**示例：**

```js
let keyboardDelegate = inputMethodEngine.createKeyboardDelegate();
```

## InputMethodEngine

下列API示例中都需使用[getInputMethodEngine](#inputmethodenginegetinputmethodenginedeprecated)回调获取到InputMethodEngine实例，再通过此实例调用对应方法。

### on('inputStart')

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

订阅输入法绑定成功事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型。<br/>-&nbsp;type为‘inputStart’时表示订阅输入法绑定。 |
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclient)) => void | 是 | 回调函数，返回订阅输入法的KeyboardController和TextInputClient实例。 |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().on('inputStart', (kbController, textClient) => {
  let keyboardController = kbController;
  let textInputClient = textClient;
});
```

### off('inputStart')

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

取消订阅输入法绑定成功事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | 是   | 设置监听类型。<br/>-&nbsp;type为‘inputStart’时表示订阅输入法绑定。 |
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclient)) => void | 否 | 回调函数，返回取消订阅的KeyboardController和TextInputClient实例。 |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().off('inputStart', (kbController, textInputClient) => {
  console.log('delete inputStart notification.');
});
```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

订阅输入法事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | () => void   | 是   | 回调函数。                                                   |

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

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅输入法显示。<br/>-&nbsp;type为'keyboardHide'，表示订阅输入法隐藏。 |
| callback | () => void   | 否   | 回调函数。 |

**示例：**

```js
inputMethodEngine.getInputMethodEngine().off('keyboardShow');
inputMethodEngine.getInputMethodEngine().off('keyboardHide');
```

## InputMethodAbility

下列API示例中都需使用[getInputMethodAbility](#inputmethodenginegetinputmethodability9)回调获取到InputMethodAbility实例，再通过此实例调用对应方法。

### on('inputStart')<sup>9+</sup>

on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void

订阅输入法绑定成功事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型。<br/>-&nbsp;type为‘inputStart’时表示订阅输入法绑定。 |
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | 是 | 回调函数，返回输入法操作相关实例。 |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, client) => {
  let keyboardController = kbController;
  let inputClient = client;
});
```

### off('inputStart')<sup>9+</sup>

off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void

取消订阅输入法绑定成功事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | 是   | 设置监听类型。<br/>-&nbsp;type为‘inputStart’时表示订阅输入法绑定。 |
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | 否 | 回调函数，返回输入法操作相关实例。 |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('inputStart');
```

### on('inputStop')<sup>9+</sup>

on(type: 'inputStop', callback: () => void): void

订阅停止输入法应用事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为‘inputStop’时表示订阅停止输入法应用事件。 |
| callback | () => void   | 是   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('inputStop', () => {
  console.log('inputMethodAbility inputStop');
});
```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

取消订阅停止输入法应用事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为‘inputStop’时表示订阅停止输入法应用事件。 |
| callback | () => void   | 是   | 回调函数。                                                   |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('inputStop', () => {
  console.log('inputMethodAbility delete inputStop notification.');
});
```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid: number) => void): void

订阅设置调用窗口事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为‘setCallingWindow’时表示订阅设置调用窗口事件。 |
| callback | (wid: number) => void | 是   | 回调函数，返回调用方window id。                                            |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('setCallingWindow', (wid) => {
  console.log('inputMethodAbility setCallingWindow');
});
```

### off('setCallingWindow')<sup>9+</sup>

off(type: 'setCallingWindow', callback: (wid:number) => void): void

取消订阅设置调用窗口事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为‘setCallingWindow’时表示订阅设置调用窗口事件。 |
| callback | (wid:number) => void | 是   | 回调函数，返回调用方window id。                                 |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('setCallingWindow', (wid) => {
  console.log('inputMethodAbility delete setCallingWindow notification.');
});
```

### on('keyboardShow'|'keyboardHide')<sup>9+</sup>

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

订阅输入法事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示订阅显示键盘事件。<br/>-&nbsp;type为'keyboardHide'，表示订阅隐藏键盘事件。 |
| callback | () => void   | 是   | 回调函数。                                                   |

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

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'keyboardShow'，表示取消订阅显示键盘事件。<br/>-&nbsp;type为'keyboardHide'，表示取消订阅隐藏键盘事件。 |
| callback | () => void   | 否   | 回调函数。     |

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

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型 | 必填  | 说明 |
| -------- | --- | ---- | --- |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'setSubtype'，表示订阅输入法子类型的设置事件。 |
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | 是   | 回调函数，返回设置的输入法子类型。                           |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().on('setSubtype', (inputMethodSubtype) => {
  console.log('InputMethodAbility setSubtype.');
});
```

### off('setSubtype')<sup>9+</sup>

off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void

取消订阅输入法子类型事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明   |
| ------- | ----- | ---- | ---- |
| type     | string | 是   | 设置监听类型。<br/>-&nbsp;type为'setSubtype'，表示取消订阅输入法子类型的设置事件。 |
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | 否   | 回调函数，返回设置的输入法子类型。  |

**示例：**

```js
inputMethodEngine.getInputMethodAbility().off('setSubtype', () => {
  console.log('InputMethodAbility delete setSubtype notification.');
});
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void

创建输入法应用面板。使用callback异步回调。

仅支持输入法应用调用。单个输入法应用仅仅允许创建一个SOFT_KEYBOARD及一个STATUS_BAR类型的面板。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](js-apis-inner-application-baseContext.md) | 是   | 当前输入法应用上下文信息。 |
| info    | [PanelInfo](#panelinfo10)   | 是   | 输入法面板信息。 |
| callback | AsyncCallback\<[Panel](#panel10)> | 是   | 回调函数。当输入法面板创建成功，返回当前创建的输入法面板对象。  |

**错误码：**

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 12800004   | not an input method extension. |

**示例：**

```js
let panelInfo: inputMethodEngine.PanelInfo = {
  panelType: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  panelFlag: inputMethodEngine.PanelFlag.FLG_FIXED
}
try {
  inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo, (err, panel) => {
    if (err) {
      console.error(`Failed to createPanel: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeed in creating panel.');
  })
} catch(err) {
  console.error(`Failed to createPanel: ${JSON.stringify(err)}`);
}
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo): Promise\<Panel>

创建输入法应用面板。使用promise异步回调。

仅支持输入法应用调用。单个输入法应用仅仅允许创建一个SOFT_KEYBOARD及一个STATUS_BAR类型的面板。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](js-apis-inner-application-baseContext.md) | 是   | 当前输入法应用上下文信息。 |
| info    | [PanelInfo](#panelinfo10)   | 是   | 输入法面板信息。 |

**返回值：**
| 类型   | 说明                                                                 |
| ------- | ------------------------------------------------------------------ |
| Promise\<[Panel](#panel10)> | 回调函数。当输入法面板创建成功，返回当前创建的输入法面板对象。  |

**错误码：**

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 12800004   | not an input method extension. |

**示例：**

```js
let panelInfo: inputMethodEngine.PanelInfo = {
  panelType: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  panelFlag: inputMethodEngine.PanelFlag.FLG_FIXED
}
inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo).then((panel) => {
  console.log('Succeed in creating panel.');
}).catch((err) => {
  console.error(`Failed to create panel: ${JSON.stringify(err)}`);
})
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel, callback: AsyncCallback\<void>): void;

销毁输入法应用面板。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ------- | ----------- | ---- | ------------------------ |
| panel     | [Panel](#panel10) | 是   | 要销毁的panel对象。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当输入法面板销毁成功，err为undefined，否则为错误对象。  |

**示例：**

```js
let panelInfo: inputMethodEngine.PanelInfo = {
  panelType: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  panelFlag: inputMethodEngine.PanelFlag.FLG_FIXED
}
try {
  inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo, (err, panel) => {
    if (err) {
      console.error(`Failed to create panel: ${JSON.stringify(err)}`);
      return;
    }
	globalThis.inputMethodPanel = panel;
    console.log('Succeed in creating panel.');
  })
} catch(err) {
  console.error(`Failed to create panel: ${JSON.stringify(err)}`);
}

try {
  inputMethodEngine.getInputMethodAbility().destroyPanel(globalThis.inputMethodPanel, (err) => {
    if(err !== undefined) {
      console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeed in destroying panel.');
  })
} catch(err) {
  console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
}
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel): Promise\<void>;

销毁输入法应用面板。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ---------| ----------- | ---- | ------------------------ |
| panel    | [Panel](#panel10)       | 是   | 要销毁的panel对象。      |

**返回值：**
| 类型    | 说明                                                                 |
| ------- | -------------------------------------------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。|

**示例：**

```js
let panelInfo: inputMethodEngine.PanelInfo = {
  panelType: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  panelFlag: inputMethodEngine.PanelFlag.FLG_FIXED
}
try {
  inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo, (err, panel) => {
    if (err) {
      console.error(`Failed to create panel: ${JSON.stringify(err)}`);
      return;
    }
	globalThis.inputMethodPanel = panel;
    console.log('Succeed in creating panel.');
  })
} catch(err) {
  console.error(`Failed to create panel: ${JSON.stringify(err)}`);
}

try {
  inputMethodEngine.getInputMethodAbility().destroyPanel(globalThis.inputMethodPanel).then(() => {
    console.log('Succeed in destroying panel.');
  }).catch((err) => {
    console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
}
```

## KeyboardDelegate

下列API示例中都需使用[getKeyboardDelegate](#inputmethodenginegetkeyboarddelegate9)回调获取到KeyboardDelegate实例，再通过此实例调用对应方法。

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

订阅硬键盘（即物理键盘）事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type   | string         | 是   | 设置监听类型。<br/>-&nbsp;type为'keyDown'，表示订阅硬键盘按下事件。<br/>-&nbsp;type为'keyUp'，表示订阅硬键盘抬起事件。 |
| callback | (event: [KeyEvent](#keyevent)) => boolean | 是 | 回调函数，返回按键信息。 |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('keyUp', (keyEvent) => {
  console.log('inputMethodEngine keyCode.(keyUp):' + JSON.stringify(keyEvent.keyCode));
  console.log('inputMethodEngine keyAction.(keyUp):' + JSON.stringify(keyEvent.keyAction));
  return true;
});
inputMethodEngine.getKeyboardDelegate().on('keyDown', (keyEvent) => {
  console.log('inputMethodEngine keyCode.(keyDown):' + JSON.stringify(keyEvent.keyCode));
  console.log('inputMethodEngine keyAction.(keyDown):' + JSON.stringify(keyEvent.keyAction));
  return true;
});
```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

取消订阅硬键盘（即物理键盘）事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型     | 必填  | 说明  |
| -------- | ------- | ---- | ----- |
| type     | string  | 是   | 设置监听类型。<br/>-&nbsp;type为'keyDown'，表示取消订阅硬键盘按下事件。<br/>-&nbsp;type为'keyUp'，表示取消订阅硬键盘抬起事件。 |
| callback | (event: [KeyEvent](#keyevent)) => boolean | 否   | 回调函数，返回按键信息。  |

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

### on('keyEvent')<sup>10+</sup>

on(type: 'keyEvent', callback: (event: InputKeyEvent) => boolean): void

订阅硬键盘（即物理键盘）事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 设置监听类型。<br/>-&nbsp;type为'keyEvent'，表示订阅硬键盘按键事件。 |
| callback | function | 是   | 回调函数，入参为按键事件信息，返回值类型为布尔类型。<br/>-&nbsp;入参按键事件信息的数据类型为[InputKeyEvent](js-apis-keyevent.md#KeyEvent)。<br/>-&nbsp;若按键事件被事件订阅者消费，则callback应返回true，否则返回false。 |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('keyEvent', (keyEvent) => {
  console.log('inputMethodEngine keyEvent.action:' + JSON.stringify(keyEvent.action));
  console.log('inputMethodEngine keyEvent.key.code:' + JSON.stringify(keyEvent.key.code));
  console.log('inputMethodEngine keyEvent.ctrlKey:' + JSON.stringify(keyEvent.ctrlKey));
  return true;
});
```

### off('keyEvent')<sup>10+</sup>

off(type: 'keyEvent', callback?: (event: InputKeyEvent) => boolean): void

取消订阅硬键盘（即物理键盘）事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 设置监听类型。<br/>-&nbsp;type为'keyEvent'，表示取消订阅硬键盘按键事件。 |
| callback | function | 否   | 回调函数，入参为按键事件信息，返回值类型为布尔类型。<br/>-&nbsp;入参按键事件信息的数据类型为[InputKeyEvent](js-apis-keyevent.md#KeyEvent)。<br/>-&nbsp;若按键事件被事件订阅者消费，则callback应返回true，否则返回false。<br/>-&nbsp;可选参数，若填写表示不再回调此函数，若不填写则取消注册该事件所有回调函数。 |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('keyEvent', (keyEvent) => {
  console.log('This is a callback function which will be deregistered.');
  return true;
});
inputMethodEngine.getKeyboardDelegate().off('keyEvent');
```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

订阅光标变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型  | 必填  | 说明  |
| -------- | ---- | ---- | ----- |
| type     | string | 是   | 光标变化事件。<br/>-&nbsp;type为‘cursorContextChange’时，表示订阅光标变化事件。 |
| callback | (x: number, y: number, height: number) => void | 是   | 回调函数，返回光标信息。<br/>-&nbsp;x为光标上端的的x坐标值。<br/>-&nbsp;y为光标上端的y坐标值。<br/>-&nbsp;height为光标的高度值。 |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('cursorContextChange', (x, y, height) => {
  console.log('inputMethodEngine cursorContextChange x:' + x);
  console.log('inputMethodEngine cursorContextChange y:' + y);
  console.log('inputMethodEngine cursorContextChange height:' + height);
});
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void

取消订阅光标变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名    | 类型  | 必填  | 说明   |
| -------- | ---- | ---- | ------ |
| type     | string  | 是   | 光标变化事件。<br/>-&nbsp;type为‘cursorContextChange’时，表示光标变化。 |
| callback | (x: number, y:number, height:number) => void | 否   | 回调函数，返回光标信息。<br/>-&nbsp;x为光标上端的的x坐标值。<br/>-&nbsp;y为光标上端的y坐标值。<br/>-&nbsp;height为光标的高度值。<br/> |


  **示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('cursorContextChange', (x, y, height) => {
  console.log('delete cursorContextChange notification.');
});
```
### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

订阅文本选择变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型   | 必填 | 说明   |
| -------- | ----- | ---- | ---- |
| type     | string  | 是   | 文本选择变化事件。<br/>-&nbsp;type为‘selectionChange’时，表示选择文本变化。 |
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | 是   | 回调函数，返回文本选择信息。<br/>-&nbsp;oldBegin为变化之前被选中文本的起始下标。<br/>-&nbsp;oldEnd为变化之前被选中文本的终止下标。<br/>-&nbsp;newBegin为变化之后被选中文本的起始下标。<br/>-&nbsp;newEnd为变化之后被选中文本的终止下标。 |

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

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明     |
| -------- | ------- | ---- | ------- |
| type     | string  | 是   | 文本选择变化事件。<br/>-&nbsp;type为‘selectionChange’时，表示选择文本变化。 |
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | 否   | 回调函数，返回文本选择信息。<br/>-&nbsp;oldBegin为变化之前被选中文本的起始下标。<br/>-&nbsp;oldEnd为变化之前被选中文本的终止下标。<br/>-&nbsp;newBegin为变化之后被选中文本的起始下标。<br/>-&nbsp;newEnd为变化之后被选中文本的终止下标。<br/> |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
  console.log('delete selectionChange notification.');
});
```


### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

订阅文本变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件。<br/>-&nbsp;type为‘textChange’时，表示订阅文本变化事件。 |
| callback | (text: string) => void | 是   | 回调函数，返回订阅的文本内容。|

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('textChange', (text) => {
  console.log('inputMethodEngine textChange. text:' + text);
});
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

取消订阅文本变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件。<br/>-&nbsp;type为‘textChange’时，表示取消订阅文本变化事件。 |
| callback | (text: string) => void | 否   | 回调函数，返回取消订阅的文本内容。 |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('textChange', (text) => {
  console.log('delete textChange notification. text:' + text);
});
```

### on('editorAttributeChanged')<sup>10+</sup>

on(type: 'editorAttributeChanged', callback: (attr: EditorAttribute) => void): void

订阅编辑框属性变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件。<br/>-&nbsp;type为‘editorAttributeChanged’时，表示订阅编辑框属性变化事件。 |
| callback | (attr: EditorAttribute) => void | 是   | 用于接受编辑框属性变化的回调函数。|

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().on('editorAttributeChanged', (attr) => {
  console.log(`Succeeded in receiving attribute of editor, inputPattern = ${attr.inputPattern}, enterKeyType = ${attr.enterKeyType}`);
});
```

### off('editorAttributeChanged')<sup>10+</sup>

off(type: 'editorAttributeChanged', callback?: (attr: EditorAttribute) => void): void

取消订阅编辑框属性变化事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件。<br/>-&nbsp;type为‘editorAttributeChanged’时，表示取消订阅编辑框属性变化事件。 |
| callback | (attr: EditorAttribute) => void | 否   | 所要取消订阅的回调处理函数，和on接口参数对应。 |

**示例：**

```js
inputMethodEngine.getKeyboardDelegate().off('editorAttributeChanged');
```

## Panel<sup>10+</sup>

下列API示例中都需使用[createPanel](#createpanel10)回调获取到Panel实例，再通过此实例调用对应方法。

### setUiContent<sup>10+</sup>

setUiContent(path: string, callback: AsyncCallback\<void>): void

为当前面板加载具体页面内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| path | string | 是   | 设置加载页面的路径。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板页面内容加载成功，err为undefined，否则err为错误对象。 |

**示例：**

```js
try {
  panel.setUiContent('pages/page2/page2', (err) => {
    if (err) {
      console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in setting the content.');
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string): Promise\<void>

为当前面板加载具体页面内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| path | string | 是   | 设置加载页面的路径。 |

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**示例：**

```js
try {
  let promise = panel.setUiContent('pages/page2/page2');
  promise.then(() => {
    console.log('Succeeded in setting the content.');
  }).catch((err) =>{
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void

为当前面板加载与LocalStorage相关联的具体页面内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| path | string | 是   | 设置加载页面的路径。 |
| storage | [LocalStorage](../arkui-ts/ts-state-management.md#localstorage9) | 是   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板页面内容加载成功，err为undefined，否则err为错误对象。 |

**示例：**

```js
let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
try {
  panel.setUiContent('pages/page2/page2', storage, (err) => {
    if (err) {
      console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in setting the content.');
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string, storage: LocalStorage): Promise\<void>

为当前面板加载与LocalStorage相关联的具体页面内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| path | string | 是   | 设置加载页面的路径。 |
| storage | [LocalStorage](../arkui-ts/ts-state-management.md#localstorage9) | 是   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。|

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**示例：**

```js
let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
try {
  let promise = panel.setUiContent('pages/page2/page2');
  promise.then(() => {
    console.log('Succeeded in setting the content.');
  }).catch((err) =>{
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### resize<sup>10+</sup>

resize(width: number, height: number, callback: AsyncCallback\<void>): void

改变当前面板大小，使用callback异步回调。

面板存在大小限制，面板宽度不超出屏幕宽度，面板高度不高于屏幕高度的二分之一。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| width | number | 是   | 目标面板的宽度，单位为px。|
| height | number | 是   | 目标面板的高度，单位为px。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板大小改变成功，err为undefined，否则err为错误对象。 |

**示例：**

```js
try {
  panel.resize(500, 1000, (err) => {
    if (err) {
      console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in changing the panel size.');
  });
} catch (err) {
  console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
}
```

### resize<sup>10+</sup>

resize(width: number, height: number): Promise\<void>;

改变当前面板大小，使用Promise异步回调。

面板存在大小限制，面板宽度不超出屏幕宽度，面板高度不高于屏幕高度的二分之一。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| width | number | 是   | 目标面板的宽度，单位为px。|
| height | number | 是   | 目标面板的高度，单位为px。|

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**示例：**

```js
try {
  let promise = panel.resize(500, 1000);
  promise.then(() => {
    console.log('Succeeded in changing the panel size.');
  }).catch((err) =>{
    console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
}
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number, callback: AsyncCallback\<void>): void

移动面板位置，使用callback异步回调。

对FLG_FIXED状态的panel不产生实际移动效果。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| x | number | 是   | 面板在x轴方向移动的值，值为正表示右移，单位为px。|
| y | number | 是   | 面板在y轴方向移动的值，值为正表示下移，单位为px。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板位置移动成功，err为undefined，否则err为错误对象。 |

**示例：**

```js
try {
  panel.moveTo(300, 300, (err) =>{
    if (err) {
      console.error(`Failed to move panel: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in moving the panel.');
  });
} catch (err) {
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);
}
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number): Promise\<void>

移动面板位置。使用promise异步回调。

对FLG_FIXED状态的panel不产生实际移动效果。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| x | number | 是   | 面板在x轴方向移动的值，值为正表示右移，单位为px。|
| y | number | 是   | 面板在y轴方向移动的值，值为正表示下移，单位为px。|

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**示例：**

```js
try {
  let promise = panel.moveTo(300, 300);
  promise.then(() => {
    console.log('Succeeded in moving the panel.');
  }).catch((err) =>{
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to move panel: ${JSON.stringify(err)}`);
}
```

### show<sup>10+</sup>

show(callback: AsyncCallback\<void>): void

显示当前面板，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板显示成功，err为undefined，否则err为错误对象。 |

**示例：**

```js
panel.show((err) => {
  if (err) {
    console.error(`Failed to show panel: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in showing the panel.');
});
```

### show<sup>10+</sup>

show(): Promise\<void>

显示当前面板，使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**示例：**

```js
let promise = panel.show();
promise.then(() => {
  console.log('Succeeded in showing the panel.');
}).catch((err) =>{
  console.error(`Failed to show panel: ${JSON.stringify(err)}`);
});
```

### hide<sup>10+</sup>

hide(callback: AsyncCallback\<void>): void

隐藏当前面板，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板隐藏成功，err为undefined，否则err为错误对象。 |

**示例：**

```js
panel.hide((err) => {
  if (err) {
    console.error(`Failed to hide panel: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in hiding the panel.');
});
```

### hide<sup>10+</sup>

hide(): Promise\<void>

隐藏当前面板，使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**示例：**

```js
let promise = panel.hide();
promise.then(() => {
  console.log('Succeeded in hiding the panel.');
}).catch((err) =>{
  console.error(`Failed to hide panel: ${JSON.stringify(err)}`);
});
```

### on('show')<sup>10+</sup>

on(type: 'show', callback: () => void): void

监听当前面板显示状态，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 监听当前面板的状态类型。 <br/>- type为`show`表示显示状态。 |
| callback | () => void | 是   | 回调函数。 |

**示例：**

```js
panel.on('show', () => {
  console.log('Panel is showing.');
});
```

### on('hide')<sup>10+</sup>

on(type: 'hide', callback: () => void): void

监听当前面板隐藏状态，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 监听当前面板的状态类型。 <br/>- type为`hide`表示隐藏状态。 |
| callback | () => void | 是   | 回调函数。 |

**示例：**

```js
panel.on('hide', () => {
  console.log('Panel is hiding.');
});
```

### off('show')<sup>10+</sup>

off(type: 'show', callback?: () => void): void

取消监听当前面板显示状态，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 要取消监听的当前面板状态类型。 <br/>- type为`show`表示显示状态。 |
| callback | () => void | 否   | 回调函数。 |

**示例：**

```js
panel.off('show');
```

### off('hide')<sup>10+</sup>

off(type: 'hide', callback?: () => void): void

取消监听当前面板隐藏状态，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 要取消监听的当前面板状态类型。 <br/>- type为`hide`表示隐藏状态。 |
| callback | () => void | 否   | 回调函数。 |

**示例：**

```js
panel.off('hide');
```

### changeFlag<sup>10+</sup>

changeFlag(flag: PanelFlag): void

改变面板状态为固定态或者悬浮态。仅对SOFT_KEYBOARD类型生效。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | 是 | 要切换到的面板状态类型。 |

**示例：**

```js
let panelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
panel.changeFlag(panelFlag);
```

## KeyboardController

下列API示例中都需使用[on('inputStart')](#oninputstart9)回调获取到KeyboardController实例，再通过此实例调用对应方法。

### hide<sup>9+</sup>

hide(callback: AsyncCallback&lt;void&gt;): void

隐藏输入法。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | 是   | 回调函数。当输入法隐藏成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```js
keyboardController.hide((err) => {
  if (err) {
    console.error(`Failed to hide: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in hiding keyboard.');
});
```

### hide<sup>9+</sup>

hide(): Promise&lt;void&gt;

隐藏输入法。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型             | 说明                      |
| ---------------- | ------------------------- |
| Promise&lt;void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```js
keyboardController.hide().then(() => {
  console.log('Succeeded in hiding keyboard.');
}).catch((err) => {
  console.log(`Failed to hide: ${JSON.stringify(err)}`);
});
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

隐藏输入法。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[hide](#hide9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | 是   | 回调函数。当输入法隐藏成功，err为undefined，否则为错误对象。 |

**示例：**

```js
keyboardController.hideKeyboard((err) => {
  if (err) {
    console.error(`Failed to hideKeyboard: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in hiding keyboard.');
});
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(): Promise&lt;void&gt;

隐藏输入法。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[hide](#hide9-1)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型             | 说明                      |
| ---------------- | ------------------------- |
| Promise&lt;void> | 无返回结果的Promise对象。 |

**示例：**

```js
keyboardController.hideKeyboard().then(() => {
  console.log('Succeeded in hiding keyboard.');
}).catch((err) => {
  console.log(`Failed to hideKeyboard: ${JSON.stringify(err)}`);
});
```

## ExtendAction<sup>10+</sup>

对编辑框中文本的扩展编辑操作类型。

**系统能力**: SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| SELECT_ALL  | 0 |全选。 |
| CUT  | 3 |剪切。 |
| COPY  | 4 |复制。 |
| PASTE  | 5 |粘贴。 |

## Direction<sup>10+</sup>

输入法光标移动方向。

**系统能力**: SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| CURSOR_UP  | 1 |向上。 |
| CURSOR_DOWN  | 2 |向下。 |
| CURSOR_LEFT  | 3 |向左。 |
| CURSOR_RIGHT  | 4 |向右。 |

## Range<sup>10+</sup>

描述选中文本的范围。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| start  | number | 是 | 是 | 选中文本的首字符在编辑框的索引值。|
| end  | number | 是 | 是 | 选中文本的末字符在编辑框的索引值。|

## Movement<sup>10+</sup>

描述进行选中文本动作时光标移动的方向。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| direction  | [Direction](#direction10) | 是 | 是 | 进行选中文本动作时光标移动的方向。|

## InputClient<sup>9+</sup>

下列API示例中都需使用[on('inputStart')](#oninputstart9)回调获取到InputClient实例，再通过此实例调用对应方法。

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

发送功能键。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 功能键键值。<br/>- 当值为0时，表示无效按键；<br/>- 当值为1时，表示确认键（即回车键）。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当功能键发送成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

 **示例：**

```js
let action = 1;
try {
  inputClient.sendKeyFunction(action, (err, result) => {
    if (err) {
      console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in sending key function.');
    } else {
      console.error('Failed to sendKeyFunction.');
    }
  });
} catch (err) {
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
}
```

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action: number): Promise&lt;boolean&gt;

发送功能键。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 功能键键值。<br/>当值为0时，表示无效按键；<br/>当值为1时，表示确认键（即回车键）。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示功能键发送成功；返回false表示功能键发送失败。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```js
let action = 1;
try {
  inputClient.sendKeyFunction(action).then((result) => {
    if (result) {
      console.log('Succeeded in sending key function.');
    } else {
      console.error('Failed to sendKeyFunction.');
    }
  }).catch((err) => {
    console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
}
```

### getForward<sup>9+</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标前固定长度的文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标前固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
let length = 1;
try {
  inputClient.getForward(length, (err, text) => {
    if (err) {
      console.error(`Failed to getForward: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in getting forward, text: ' + text);
  });
} catch (err) {
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);
}
```

### getForward<sup>9+</sup>

getForward(length:number): Promise&lt;string&gt;

获取光标前固定长度的文本。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise对象，返回光标前固定长度的文本。                     |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
let length = 1;
try {
  inputClient.getForward(length).then((text) => {
    console.log('Succeeded in getting forward, text: ' + text);
  }).catch((err) => {
    console.error(`Failed to getForward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);
}
```

### getBackward<sup>9+</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标后固定长度的文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标后固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
let length = 1;
try {
  inputClient.getBackward(length, (err, text) => {
    if (err) {
      console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in getting backward, text: ' + text);
  });
} catch (err) {
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
}
```

### getBackward<sup>9+</sup>

getBackward(length:number): Promise&lt;string&gt;

获取光标后固定长度的文本。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise对象，返回光标后固定长度的文本。                     |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
let length = 1;
try {
  inputClient.getBackward(length).then((text) => {
    console.log('Succeeded in getting backward, text: ' + text);
  }).catch((err) => {
    console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标前固定长度的文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当光标前固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```js
let length = 1;
try {
  inputClient.deleteForward(length, (err, result) => {
    if (err) {
      console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in deleting forward.');
    } else {
      console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
    }
  });
} catch (err) {
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number): Promise&lt;boolean&gt;

删除光标前固定长度的文本。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。 |

**返回值：**  

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示删除光标前固定长度的文本成功；返回false表示删除光标前固定长度的文本失败。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```js
let length = 1;
try {
  inputClient.deleteForward(length).then((result) => {
    if (result) {
      console.log('Succeeded in deleting forward.');
    } else {
      console.error('Failed to delete Forward.');
    }
  }).catch((err) => {
    console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标后固定长度的文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | 是   | 文本长度。     |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。当光标后固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```js
let length = 1;
try {
  inputClient.deleteBackward(length, (err, result) => {
    if (err) {
      console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in deleting backward.');
    } else {
      console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
    }
  });
} catch (err) {
  console.error('deleteBackward err: ' + JSON.stringify(err));
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number): Promise&lt;boolean&gt;

删除光标后固定长度的文本。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |

**返回值：** 

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示删除光标后固定长度的文本成功；返回false表示删除光标后固定长度的文本失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```js
let length = 1;
inputClient.deleteBackward(length).then((result) => {
  if (result) {
    console.log('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
}).catch((err) => {
  console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
});
```

### insertText<sup>9+</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

插入文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当文本插入成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```js
inputClient.insertText('test', (err, result) => {
  if (err) {
    console.error(`Failed to insertText: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.log('Succeeded in inserting text.');
  } else {
    console.error('Failed to insertText.');
  }
});
```

### insertText<sup>9+</sup>

insertText(text:string): Promise&lt;boolean&gt;

插入文本。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |

**返回值：**  

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt;  |  Promise对象。返回true表示插入文本成功；返回false表示插入文本失败。  |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```js
try {
  inputClient.insertText('test').then((result) => {
    if (result) {
      console.log('Succeeded in inserting text.');
    } else {
      console.error('Failed to insertText.');
    }
  }).catch((err) => {
    console.error(`Failed to insertText: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to insertText: ${JSON.stringify(err)}`);
}
```

### getEditorAttribute<sup>9+</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

获取编辑框属性值。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名                         | 类型                          | 必填                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#editorattribute)&gt; | 是 |  回调函数。当编辑框属性值获取成功，err为undefined，data为编辑框属性值；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```js
inputClient.getEditorAttribute((err, editorAttribute) => {
  if (err) {
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
    return;
  }
  console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
  console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
});
```

### getEditorAttribute<sup>9+</sup>

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

获取编辑框属性值。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#editorattribute)&gt; |  Promise对象，返回编辑框属性值。           |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```js
inputClient.getEditorAttribute().then((editorAttribute) => {
  console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
  console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
}).catch((err) => {
  console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
});
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number, callback: AsyncCallback&lt;void&gt;): void

移动光标。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------- |
| direction | number                    | 是   | 光标移动方向。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当光标移动成功，err为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```js
try {
  inputClient.moveCursor(inputMethodEngine.CURSOR_UP, (err) => {
    if (err) {
      console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in moving cursor.');
  });
} catch (err) {
  console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
}
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number): Promise&lt;void&gt;

移动光标。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型   | 必填 | 说明           |
| --------- | ------ | ---- | -------------- |
| direction | number | 是   | 光标移动方向。 |

**返回值：**  

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```js
try {
  inputClient.moveCursor(inputMethodEngine.CURSOR_UP).then(() => {
    console.log('Succeeded in moving cursor.');
  }).catch((err) => {
    console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
}
```

### selectByRange<sup>10+</sup>

selectByRange(range: Range, callback: AsyncCallback&lt;void&gt;): void

根据索引范围选中文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                                         |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| range    | [Range](#range10) | 是   | 选中文本的范围。                                             |
| callback | AsyncCallback&lt;void&gt;                                 | 是   | 回调函数。当成功发送选中事件后，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error.           |
| 12800003 | input method client error. |

**示例：**

```js
try {
  inputClient.selectByRange({start: 0, end: 1}, (err) => {
    if (err) {
      console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in selecting by range.');
  });
} catch (err) {
  console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
}
```

### selectByRange<sup>10+</sup>

selectByRange(range: Range): Promise&lt;void&gt;

根据索引范围选中文本。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型                                                      | 必填 | 说明             |
| ------ | --------------------------------------------------------- | ---- | ---------------- |
| range  | [Range](#range10) | 是   | 选中文本的范围。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error.           |
| 12800003 | input method client error. |

**示例：**

```js
try {
  inputClient.selectByRange({start: 0, end:1}).then(() => {
    console.log('Succeeded in selecting by range.');
  }).catch((err) => {
    console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
}
```

### selectByMovement<sup>10+</sup>

selectByMovement(movement: Movement, callback: AsyncCallback&lt;void&gt;): void

根据光标移动方向选中文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明   |
| -------- | ------ | ---- | ------ |
| movement | [Movement](#movement10)   | 是   | 选中时光标移动的方向。  |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当成功发送选中事件后，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error.           |
| 12800003 | input method client error. |

**示例：**

```js
try {
  inputClient.selectByMovement({direction: 1}, (err) => {
    if (err) {
      console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in selecting by movement.');
  });
} catch (err) {
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
}
```

### selectByMovement<sup>10+</sup>

selectByMovement(movement: Movement): Promise&lt;void&gt;

根据索引范围选中文本。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| movement | [Movement](#movement10) | 是   | 选中时光标移动的方向。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error.           |
| 12800003 | input method client error. |

**示例：**

```js
try {
  inputClient.selectByMovement({direction: 1}).then(() => {
    console.log('Succeeded in selecting by movement.');
  }).catch((err) => {
    console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
}
```

### getTextIndexAtCursor<sup>10+</sup>

getTextIndexAtCursor(callback: AsyncCallback&lt;number&gt;): void

获取光标所在处的文本索引。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。当文本索引获取成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
inputClient.getTextIndexAtCursor((err, index) => {
  if (err) {
    console.error(`Failed to getTextIndexAtCursor: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in getTextIndexAtCursor: ' + index);
});
```

### getTextIndexAtCursor<sup>10+</sup>

getTextIndexAtCursor(): Promise&lt;number&gt;

获取光标所在处的文本索引。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回光标所在处的文本索引。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
inputClient.getTextIndexAtCursor().then((index) => {
  console.log('Succeeded in getTextIndexAtCursor: ' + index);
}).catch((err) => {
  console.error(`Failed to getTextIndexAtCursor: ${JSON.stringify(err)}`);
});
```

### sendExtendAction<sup>10+</sup>

sendExtendAction(action: ExtendAction, callback: AsyncCallback&lt;void&gt;): void

发送扩展编辑操作。使用callback异步回调。

输入法应用调用该接口向编辑控件（如：输入框）发送扩展编辑操作，编辑控件监听相应事件[on(handleExtendAction)](./js-apis-inputmethod.md#onhandleextendaction10)，从而进一步做出处理。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| action | [ExtendAction](#extendaction10) | 是   | 要发送的扩展操作。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。发送成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
try {
  inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY, (err) => {
    if (err) {
      console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in sending extend action.');
  });
} catch(err) {
  console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
}
```

### sendExtendAction<sup>10+</sup>

sendExtendAction(action: ExtendAction): Promise&lt;void&gt;

发送扩展编辑操作。使用promise异步回调。

输入法应用调用该接口向编辑控件（如：输入框）发送扩展编辑操作，编辑控件监听相应事件[on(handleExtendAction)](./js-apis-inputmethod.md#onhandleextendaction10)，从而进一步做出处理。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | [ExtendAction](#extendaction10) | 是 | 要发送的扩展操作。 |

**返回值：**

| 类型                  | 说明                                    |
| --------------------- | --------------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](../errorcodes/errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```js
try {
  inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY).then(() => {
    console.log('Succeeded in sending extend action.');
  }).catch((err) => {
    console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
  });
} catch(err) {
  console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
}
```

## EditorAttribute

编辑框属性值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称         | 类型 | 可读 | 可写 | 说明               |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | 是   | 否   | 编辑框的功能属性。 |
| inputPattern | number   | 是   | 否   | 编辑框的文本属性。 |

## KeyEvent

按键属性值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称      | 类型 | 可读 | 可写 | 说明         |
| --------- | -------- | ---- | ---- | ------------ |
| keyCode   | number   | 是   | 否   | 按键的键值。键码值说明参考[KeyCode](js-apis-keycode.md#keycode)。 |
| keyAction | number   | 是   | 否   | 按键事件类型。<br/>- 当值为2时，表示按下事件；<br/>- 当值为3时，表示抬起事件。 |

## PanelFlag<sup>10+</sup>

输入法面板状态类型枚举。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称         | 值 | 说明               |
| ------------ | -- | ------------------ |
| FLG_FIXED  | 0 | 固定态面板类型。 |
| FLG_FLOATING | 1 | 悬浮态面板类型。 |

## PanelType<sup>10+</sup>

输入法面板类型枚举。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称         | 值 | 说明               |
| ------------ | -- | ------------------ |
| SOFT_KEYBOARD | 0 | 软键盘类型。 |
| STATUS_BAR   | 1 | 状态栏类型。 |

## PanelInfo<sup>10+</sup>

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

输入法面板属性。

| 名称      | 类型 | 可读 | 可写 | 说明         |
| --------- | -------- | ---- | ---- | ------------ |
| type   	| number   | 是   | 是   | 面板的类型。 |
| flag	    | number   | 是   | 是   | 面板的状态类型。 |

## TextInputClient<sup>(deprecated)</sup>

> **说明：** 
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[InputClient](#inputclient9)替代。

下列API示例中都需使用[on('inputStart')](#oninputstart)回调获取到TextInputClient实例，再通过此实例调用对应方法。

### getForward<sup>(deprecated)</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标前固定长度的文本。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[getForward](#getforward9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标前固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。|

**示例：**

```js
let length = 1;
textInputClient.getForward(length, (err, text) => {
  if (err) {
    console.error(`Failed to getForward: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in getting forward, text: ' + text);
});
```

### getForward<sup>(deprecated)</sup>

getForward(length:number): Promise&lt;string&gt;

获取光标前固定长度的文本。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[getForward](#getforward9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

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
let length = 1;
textInputClient.getForward(length).then((text) => {
  console.log('Succeeded in getting forward, text: ' + text);
}).catch((err) => {
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标后固定长度的文本。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[getBackward](#getbackward9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标后固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |

**示例：**

```js
let length = 1;
textInputClient.getBackward(length, (err, text) => {
  if (err) {
    console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in getting borward, text: ' + text);
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number): Promise&lt;string&gt;

获取光标后固定长度的文本。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[getBackward](#getbackward9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

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
let length = 1;
textInputClient.getBackward(length).then((text) => {
  console.log('Succeeded in getting backward: ' + JSON.stringify(text));
}).catch((err) => {
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
});
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标前固定长度的文本。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[deleteForward](#deleteforward9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当光标前固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
let length = 1;
textInputClient.deleteForward(length, (err, result) => {
  if (err) {
    console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.log('Succeeded in deleting forward.');
  } else {
    console.error('Failed to deleteForward.');
  }
});
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number): Promise&lt;boolean&gt;

删除光标前固定长度的文本。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[deleteForward](#deleteforward9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

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
let length = 1;
textInputClient.deleteForward(length).then((result) => {
  if (result) {
    console.log('Succeeded in deleting forward.');
  } else {
    console.error('Failed to delete forward.');
  }
}).catch((err) => {
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
});
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标后固定长度的文本。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[deleteBackward](#deletebackward9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | 是   | 文本长度。     |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。当光标后固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。|

**示例：**

```js
let length = 1;
textInputClient.deleteBackward(length, (err, result) => {
  if (err) {
    console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.log('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
});
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number): Promise&lt;boolean&gt;

删除光标后固定长度的文本。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[deleteBackward](#deletebackward9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

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
let length = 1;
textInputClient.deleteBackward(length).then((result) => {
  if (result) {
    console.log('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
}).catch((err) => {
  console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
});
```
### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action: number, callback: AsyncCallback&lt;boolean&gt;): void

发送功能键。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[sendKeyFunction](#sendkeyfunction9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 功能键键值。<br/>- 当值为0时，表示无效按键；<br/>- 当值为1时，表示确认键（即回车键）。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当功能键发送成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
let action = 1;
textInputClient.sendKeyFunction(action, (err, result) => {
  if (err) {
    console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.log('Succeeded in sending key function.');
  } else {
    console.error('Failed to sendKeyFunction.');
  }
});
```

### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action: number): Promise&lt;boolean&gt;

发送功能键。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[sendKeyFunction](#sendkeyfunction9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 功能键键值。<br/>当值为0时，表示无效按键；<br/>当值为1时，表示确认键（即回车键）。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示发送功能键成功；返回false表示发送功能键失败。 |

**示例：**

```js
let action = 1;
textInputClient.sendKeyFunction(action).then((result) => {
  if (result) {
    console.log('Succeeded in sending key function.');
  } else {
    console.error('Failed to sendKeyFunction.');
  }
}).catch((err) => {
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
});
```

### insertText<sup>(deprecated)</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

插入文本。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[insertText](#inserttext9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当文本插入成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```js
textInputClient.insertText('test', (err, result) => {
  if (err) {
    console.error(`Failed to insertText: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.log('Succeeded in inserting text.');
  } else {
    console.error('Failed to insertText.');
  }
});
```

### insertText<sup>(deprecated)</sup>

insertText(text:string): Promise&lt;boolean&gt;

插入文本。使用promise异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[insertText](#inserttext9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

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
textInputClient.insertText('test').then((result) => {
  if (result) {
    console.log('Succeeded in inserting text.');
  } else {
    console.error('Failed to insertText.');
  }
}).catch((err) => {
  console.error(`Failed to insertText: ${JSON.stringify(err)}`);
});
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

获取编辑框属性值。使用callback异步回调。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[getEditorAttribute](#geteditorattribute9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型   | 必填  | 说明   |
| -------- | ----- | ----- | ----- |
| callback | AsyncCallback&lt;[EditorAttribute](#editorattribute)&gt; | 是 |  回调函数。当编辑框的属性值获取成功，err为undefined，data为编辑框属性值；否则为错误对象。|

**示例：**

```js
textInputClient.getEditorAttribute((err, editorAttribute) => {
  if (err) {
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
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
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[getEditorAttribute](#geteditorattribute9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#editorattribute)&gt; |  Promise对象，返回编辑框属性值。           |

**示例：**

```js
textInputClient.getEditorAttribute().then((editorAttribute) => {
  console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
  console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
}).catch((err) => {
  console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
});
```
<!--no_check-->