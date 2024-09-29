# @ohos.inputMethodEngine (输入法服务)

本模块面向输入法应用（包括系统输入法应用、三方输入法应用），为输入法应用提供能力，包括：创建软键盘窗口、插入/删除字符、选中文本、监听物理键盘按键事件等。

> **说明：**
>
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { inputMethodEngine } from '@kit.IMEKit';
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
| ENTER_KEY_TYPE_NEWLINE<sup>12+</sup> | number | 8 | “换行”功能键。 |
| PATTERN_NULL | number | -1 | 无特殊性编辑框。 |
| PATTERN_TEXT | number | 0 | 文本编辑框。 |
| PATTERN_NUMBER | number | 2 | 数字编辑框。 |
| PATTERN_PHONE | number | 3 | 电话号码编辑框。 |
| PATTERN_DATETIME | number | 4 | 日期编辑框。 |
| PATTERN_EMAIL | number | 5 | 邮件编辑框。 |
| PATTERN_URI | number | 6 | 超链接编辑框。 |
| PATTERN_PASSWORD | number | 7 | 密码编辑框。 |
| PATTERN_PASSWORD_NUMBER<sup>11+</sup> | number | 8 | 数字密码编辑框。 |
| PATTERN_PASSWORD_SCREEN_LOCK<sup>11+</sup> | number | 9 | 锁屏密码编辑框。 |
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

获取输入法应用客户端实例[InputMethodAbility](#inputmethodability)，仅支持输入法应用调用。<br/>输入法应用获取该实例后，可订阅软键盘显示/隐藏请求事件、创建/销毁输入法面板等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明               |
| ----------------------------------------- | ------------------ |
| [InputMethodAbility](#inputmethodability) | 输入法应用客户端。 |

**示例：**

```ts
let InputMethodAbility = inputMethodEngine.getInputMethodAbility();
```

## inputMethodEngine.getKeyboardDelegate<sup>9+</sup>

getKeyboardDelegate(): KeyboardDelegate

获取客户端编辑事件监听代理实例[KeyboardDelegate](#keyboarddelegate)。<br/>输入法应用获取该实例后，可订阅物理键盘按键事件、选中文本变化事件等。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                  | 说明                     |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | 客户端编辑事件监听代理。 |

**示例：**

```ts
let KeyboardDelegate = inputMethodEngine.getKeyboardDelegate();
```

## inputMethodEngine.getInputMethodEngine<sup>(deprecated)</sup>

getInputMethodEngine(): InputMethodEngine

获取输入法应用客户端实例[InputMethodEngine](#inputmethodengine)。<br/>输入法应用获取该实例后，可订阅软键盘显示/隐藏请求事件等。

> **说明：**
>
> 从API version 8开始支持，API version 9开始废弃，建议使用[getInputMethodAbility()](#inputmethodenginegetinputmethodability9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                      | 说明               |
| ----------------------------------------- | ------------------ |
| [InputMethodEngine](#inputmethodengine) | 输入法应用客户端。 |

**示例：**

```ts
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate<sup>(deprecated)</sup>

createKeyboardDelegate(): KeyboardDelegate

获取客户端编辑事件监听代理实例[KeyboardDelegate](#keyboarddelegate)。输入法应用获取该实例后，可订阅物理键盘按键事件、选中文本变化事件等。

> **说明：**
>
>从API version 8开始支持，API version 9开始废弃，建议使用[getKeyboardDelegate()](#inputmethodenginegetkeyboarddelegate9)替代。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                  | 说明                     |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | 客户端编辑事件监听代理。 |

**示例：**

```ts
let keyboardDelegate = inputMethodEngine.createKeyboardDelegate();
```

## inputMethodEngine.CommandDataType<sup>12+</sup>

type CommandDataType = number | string | boolean;

表示私有数据类型，接口参数具体类型根据其功能而定。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 类型    | 说明                 |
| ------- | -------------------- |
| string  | 表示值类型为字符串。  |
| number  | 表示值类型为数字。   |
| boolean | 表示值类型为布尔值。 |

**示例：**

```ts
import { inputMethodEngine } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let record: Record<string, inputMethodEngine.CommandDataType> = {
    "valueString1": "abcdefg",
    "valueString2": true,
    "valueString3": 500,
  }
  inputClient.sendPrivateCommand(record).then(() => {
  }).catch((err: BusinessError) => {
    console.error(`sendPrivateCommand catch error: ${JSON.stringify(err)}`);
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`sendPrivateCommand catch error: ${error.code} ${error.message}`);
}
```

## InputMethodEngine

下列API均需使用[getInputMethodEngine](#inputmethodenginegetinputmethodenginedeprecated)获取到InputMethodEngine实例后，通过实例调用。

### on('inputStart')

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

订阅输入法绑定成功事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型，固定取值为'inputStart'。 |
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclientdeprecated)) => void | 是 | 回调函数，返回订阅输入法的KeyboardController和TextInputClient实例。 |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodEngine()
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, textClient: inputMethodEngine.TextInputClient) => {
      let keyboardController = kbController;
      let textInputClient = textClient;
  });
} catch(err) {
  console.error(`Failed to inputStart: ${JSON.stringify(err)}`);
}
```

### off('inputStart')

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

取消订阅输入法绑定成功事件。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | 是   | 设置监听类型，固定取值为'inputStart'。 |
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclientdeprecated)) => void | 否 | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodEngine()
    .off('inputStart', (kbController: inputMethodEngine.KeyboardController, textClient: inputMethodEngine.TextInputClient) => {
      console.log('delete inputStart notification.');
  });
} catch(err) {
  console.error(`Failed to inputStart: ${JSON.stringify(err)}`);
}
```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

订阅输入法软键盘显示或隐藏事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>-'keyboardShow'表示显示输入法软键盘。<br/>-'keyboardHide'表示隐藏输入法软键盘。 |
| callback | () => void   | 是   | 回调函数。                                                   |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodEngine().on('keyboardShow', () => {
    console.log('inputMethodEngine keyboardShow.');
  });
  inputMethodEngine.getInputMethodEngine().on('keyboardHide', () => {
    console.log('inputMethodEngine keyboardHide.');
  });
} catch(err) {
  console.error(`Failed to InputMethodEngine: ${JSON.stringify(err)}`);
}
```

### off('keyboardShow'|'keyboardHide')

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

取消订阅输入法软键盘显示或隐藏事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 要取消监听的输入法软键盘类型。<br/>-'keyboardShow'表示显示输入法软键盘。<br/>-'keyboardHide'表示隐藏输入法软键盘。|
| callback | () => void   | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
inputMethodEngine.getInputMethodEngine().off('keyboardShow');
inputMethodEngine.getInputMethodEngine().off('keyboardHide');
```

## InputMethodAbility

下列API均需使用[getInputMethodAbility](#inputmethodenginegetinputmethodability9)获取到InputMethodAbility实例后，通过实例调用。

### on('inputStart')<sup>9+</sup>

on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void

订阅输入法绑定成功事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | 是   | 设置监听类型，固定取值为'inputStart'。 |
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | 是 | 回调函数，返回输入法操作相关实例。 |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility()
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, client: inputMethodEngine.InputClient) => {
      let keyboardController = kbController;
      let inputClient = client;
  });
} catch(err) {
    console.error(`Failed to InputMethodAbility: ${JSON.stringify(err)}`);
}
```

### off('inputStart')<sup>9+</sup>

off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void

取消订阅输入法绑定成功事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | 是   | 设置监听类型，固定取值为'inputStart'。 |
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | 否 | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
inputMethodEngine.getInputMethodAbility().off('inputStart');
```

### on('inputStop')<sup>9+</sup>

on(type: 'inputStop', callback: () => void): void

订阅停止输入法应用事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型，固定取值为'inputStop'。 |
| callback | () => void   | 是   | 回调函数。                        |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility().on('inputStop', () => {
    console.log('inputMethodAbility inputStop');
  });
} catch(err) {
    console.error(`Failed to inputStop: ${JSON.stringify(err)}`);
}
```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

取消订阅停止输入法应用事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型，固定取值为'inputStop'。 |
| callback | () => void   | 是   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。        |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility().off('inputStop', () => {
    console.log('inputMethodAbility delete inputStop notification.');
  });
} catch(err) {
    console.error(`Failed to inputStop: ${JSON.stringify(err)}`);
}
```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid: number) => void): void

订阅设置调用窗口事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型，固定取值为'setCallingWindow'。 |
| callback | (wid: number) => void | 是   | 回调函数，返回调用方窗口的Id。                     |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility().on('setCallingWindow', (wid: number) => {
    console.log('inputMethodAbility setCallingWindow');
  });
} catch(err) {
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### off('setCallingWindow')<sup>9+</sup>

off(type: 'setCallingWindow', callback: (wid:number) => void): void

取消订阅设置调用窗口事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型，固定取值为'setCallingWindow'。|
| callback | (wid:number) => void | 是   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility().off('setCallingWindow', (wid: number) => {
    console.log('inputMethodAbility delete setCallingWindow notification.');
  });
} catch(err) {
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### on('keyboardShow'|'keyboardHide')<sup>9+</sup>

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

订阅输入法软键盘显示或隐藏事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>- 'keyboardShow'表示显示输入法软键盘。<br/>- 'keyboardHide'表示隐藏输入法软键盘。 |
| callback | () => void   | 是   | 回调函数。                                                   |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility().on('keyboardShow', () => {
    console.log('InputMethodAbility keyboardShow.');
  });
  inputMethodEngine.getInputMethodAbility().on('keyboardHide', () => {
    console.log('InputMethodAbility keyboardHide.');
  });
} catch(err) {
    console.error(`Failed to keyboard: ${JSON.stringify(err)}`);
}
```

### off('keyboardShow'|'keyboardHide')<sup>9+</sup>

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

取消订阅输入法事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 设置监听类型。<br/>- 'keyboardShow'表示显示键盘。<br/>- 'keyboardHide'表示隐藏键盘。 |
| callback | () => void   | 否   | 回调函数。 |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility().off('keyboardShow', () => {
    console.log('InputMethodAbility delete keyboardShow notification.');
  });
  inputMethodEngine.getInputMethodAbility().off('keyboardHide', () => {
    console.log('InputMethodAbility delete keyboardHide notification.');
  });
} catch(err) {
    console.error(`Failed to keyboard: ${JSON.stringify(err)}`);
}
```

### on('setSubtype')<sup>9+</sup>

on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void

订阅设置输入法子类型事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型 | 必填  | 说明 |
| -------- | --- | ---- | --- |
| type     | string | 是   | 设置监听类型，固定取值为'setSubtype'。 |
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | 是   | 回调函数，返回设置的输入法子类型。                         |

**示例：**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';

try {
  inputMethodEngine.getInputMethodAbility().on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {
    console.log('InputMethodAbility setSubtype.');
  });
} catch(err) {
    console.error(`Failed to setSubtype: ${JSON.stringify(err)}`);
}
```

### off('setSubtype')<sup>9+</sup>

off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void

取消订阅输入法软键盘显示或隐藏事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明   |
| ------- | ----- | ---- | ---- |
| type     | string | 是   | 设置监听类型，固定取值为'setSubtype'。 |
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。  |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility().off('setSubtype', () => {
    console.log('InputMethodAbility delete setSubtype notification.');
  });
} catch(err) {
    console.error(`Failed to setSubtype: ${JSON.stringify(err)}`);
}
```

### on('securityModeChange')<sup>11+</sup>

on(type: 'securityModeChange', callback: Callback< SecurityMode>): void

订阅输入法安全模式改变类型事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                           |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | 是   | 设置监听类型，固定取值为'securityModeChange'。 |
| callback | Callback\<[SecurityMode](#securitymode11))> | 是   | 回调函数，返回当前输入法应用的安全模式。       |

**示例：**

```ts
try {
  inputMethodEngine.getInputMethodAbility().on('securityModeChange', (securityMode: inputMethodEngine.SecurityMode) => {
    console.log(`InputMethodAbility securityModeChange, security is ${securityMode}`);
  });
} catch(err) {
    console.error(`Failed to on securityModeChange: ${JSON.stringify(err)}`);
}
```

### off('securityModeChange')<sup>11+</sup>

off(type: 'securityModeChange', callback?: Callback< SecurityMode>): void

取消订阅输入法安全模式改变类型事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | 是   | 设置监听类型，固定取值为'securityModeChange'。               |
| callback | Callback\<[SecurityMode](#securitymode11))> | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
let securityChangeCallback = (securityMode: inputMethodEngine.SecurityMode) => {
  console.log(`InputMethodAbility securityModeChange, security is ${securityMode}`);
};
let inputMethodAbility = inputMethodEngine.getInputMethodAbility();
inputMethodAbility.on('securityModeChange', securityChangeCallback);
try {
  inputMethodAbility.off('securityModeChange', securityChangeCallback);
} catch(err) {
  console.error(`Failed to off securityModeChange: ${JSON.stringify(err)}`);
}
```

### on('privateCommand')<sup>12+</sup>

on(type: 'privateCommand', callback: Callback<Record<string, CommandDataType>>): void;

订阅输入法私有数据事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                          | 必填 | 说明                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                        | 是   | 设置监听类型，固定取值为'privateCommand'。 |
| callback | Callback<Record<string, [CommandDataType](#inputmethodenginecommanddatatype12)>> | 是   | 回调函数，返回向输入法应用发送的私有数据。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 12800010 | not default input method configured by system. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine } from '@kit.IMEKit';

let privateCommandCallback = (record: Record<string, inputMethodEngine.CommandDataType>) => {
  for (let i = 0; i < record.length; i++) {
    console.log(`private command key: ${i}, value: ${record[i]}`);
  }
}
try {
  console.log(`regist private command `);
  inputMethodEngine.getInputMethodAbility().on('privateCommand', privateCommandCallback);
} catch (err) {
  let error = err as BusinessError;
  console.error(`regist private command error: ${error.code} ${error.message}`);
}
```

### off('privateCommand')<sup>12+</sup>

off(type: 'privateCommand', callback?: Callback<Record<string, CommandDataType>>): void

取消订阅输入法私有数据事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | 是   | 设置监听类型，固定取值为'privateCommand'。                   |
| callback | Callback<Record<string, [CommandDataType](#inputmethodenginecommanddatatype12)>> | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 12800010 | not default input method configured by system. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine } from '@kit.IMEKit';

let privateCommandCallback = (record: Record<string, inputMethodEngine.CommandDataType>) => {
  for (let i = 0; i < record.length; i++) {
    console.log(`private command key: ${i}, value: ${record[i]}`);
  }
}
try {
  console.log(`regist private command `);
  inputMethodEngine.getInputMethodAbility().off('privateCommand', privateCommandCallback);
} catch (err) {
  let error = err as BusinessError;
  console.error(`regist private command error: ${error.code} ${error.message}`);
}
```

### getSecurityMode<sup>11+</sup>

getSecurityMode(): SecurityMode

获取输入法应用的当前安全模式。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                            | 说明       |
| ------------------------------- | ---------- |
| [SecurityMode](#securitymode11) | 安全模式。 |

**错误码：**

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800004 | not an input method extension. |

**示例：**

```ts
try {
  let security = inputMethodEngine.getInputMethodAbility().getSecurityMode();
  console.error(`getSecurityMode, securityMode is : ${security}`);
} catch (err) {
  console.error(`Failed to getSecurityMode: ${JSON.stringify(err)}`);
}
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void

创建输入法面板，仅支持输入法应用调用。使用callback异步回调。<br>单个输入法应用仅允许创建一个[软键盘类型](#paneltype10)和[状态栏类型](#paneltype10)的面板。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前输入法应用上下文信息。 |
| info    | [PanelInfo](#panelinfo10)   | 是   | 输入法应用信息。 |
| callback | AsyncCallback\<[Panel](#panel10)> | 是   | 回调函数。当输入法面板创建成功，返回当前创建的输入法面板对象。  |

**错误码：**

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 401        | parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12800004   | not an input method extension. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
try {
  inputMethodEngine.getInputMethodAbility()
    .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
      if (err) {
        console.error(`Failed to createPanel: ${JSON.stringify(err)}`);
        return;
      }
      console.log('Succeed in creating panel.');
    })
} catch (err) {
  console.error(`Failed to createPanel: ${JSON.stringify(err)}`);
}
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo): Promise\<Panel>

创建输入法面板，仅支持输入法应用调用。使用promise异步回调。<br>单个输入法应用仅允许创建一个[软键盘类型](#paneltype10)和[状态栏类型](#paneltype10)的面板。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | 是   | 当前输入法应用上下文信息。 |
| info    | [PanelInfo](#panelinfo10)   | 是   | 输入法面板信息。 |

**返回值：**
| 类型   | 说明                                                                 |
| ------- | ------------------------------------------------------------------ |
| Promise\<[Panel](#panel10)> | 回调函数。当输入法面板创建成功，返回当前创建的输入法面板对象。  |

**错误码：**

| 错误码ID   | 错误信息                       |
| ---------- | ----------------------------- |
| 401        | parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12800004   | not an input method extension. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo)
  .then((panel: inputMethodEngine.Panel) => {
    console.log('Succeed in creating panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create panel: ${JSON.stringify(err)}`);
  })
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel, callback: AsyncCallback\<void>): void

销毁输入法面板。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ------- | ----------- | ---- | ------------------------ |
| panel     | [Panel](#panel10) | 是   | 要销毁的面板对象。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当输入法面板销毁成功，err为undefined，否则为错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
let inputPanel: inputMethodEngine.Panel | undefined = undefined;
try {
  inputMethodEngine.getInputMethodAbility()
    .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
      if (err) {
        console.error(`Failed to create panel: ${JSON.stringify(err)}`);
        return;
      }
      inputPanel = panel;
      console.log('Succeed in creating panel.');
    })
} catch (err) {
  console.error(`Failed to create panel: ${JSON.stringify(err)}`);
}
try {
  if (inputPanel) {
    inputMethodEngine.getInputMethodAbility().destroyPanel(inputPanel, (err: BusinessError) => {
      if (err !== undefined) {
        console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
        return;
      }
      console.log('Succeed in destroying panel.');
    })
  }
} catch (err) {
  console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
}
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel): Promise\<void>

销毁输入法面板。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型        | 必填 | 说明                     |
| ---------| ----------- | ---- | ------------------------ |
| panel    | [Panel](#panel10)       | 是   | 要销毁的面板对象。      |

**返回值：**
| 类型    | 说明                                                                 |
| ------- | -------------------------------------------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
let inputPanel: inputMethodEngine.Panel | undefined = undefined;
try {
  inputMethodEngine.getInputMethodAbility()
    .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
      if (err) {
        console.error(`Failed to create panel: ${JSON.stringify(err)}`);
        return;
      }
      inputPanel = panel;
      console.log('Succeed in creating panel.');
    })
} catch (err) {
  console.error(`Failed to create panel: ${JSON.stringify(err)}`);
}

try {
  if (inputPanel) {
    inputMethodEngine.getInputMethodAbility().destroyPanel(inputPanel).then(() => {
      console.log('Succeed in destroying panel.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
    });
  }
} catch (err) {
  console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
}
```

## KeyboardDelegate

下列API均需使用[getKeyboardDelegate](#inputmethodenginegetkeyboarddelegate9)获取到KeyboardDelegate实例后，通过实例调用。

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

订阅硬键盘（即物理键盘）上物理按键的按下或抬起事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                  |
| -------- | ------------------------------- | ---- |-----------------------------------------------------|
| type   | string         | 是   | 设置监听类型。<br/>- 'keyDown'表示键盘按下。<br/>- 'keyUp'表示键盘抬起。 |
| callback | (event: [KeyEvent](#keyevent)) => boolean | 是 | 回调函数，返回按键信息。 若按键事件被事件订阅者消费，则callback应返回true，否则返回false。   |

**示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().on('keyUp', (keyEvent: inputMethodEngine.KeyEvent) => {
    console.log('inputMethodEngine keyCode.(keyUp):' + JSON.stringify(keyEvent.keyCode));
    console.log('inputMethodEngine keyAction.(keyUp):' + JSON.stringify(keyEvent.keyAction));
    return true;
  });
  inputMethodEngine.getKeyboardDelegate().on('keyDown', (keyEvent: inputMethodEngine.KeyEvent) => {
    console.log('inputMethodEngine keyCode.(keyDown):' + JSON.stringify(keyEvent.keyCode));
    console.log('inputMethodEngine keyAction.(keyDown):' + JSON.stringify(keyEvent.keyAction));
    return true;
  });
} catch(err) {
    console.error(`Failed to KeyboardDelegate: ${JSON.stringify(err)}`);
}
```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

取消订阅硬键盘（即物理键盘）上物理按键的按下或抬起事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型     | 必填  | 说明  |
| -------- | ------- | ---- | ----- |
| type     | string  | 是   | 设置监听类型。<br/>- 'keyDown'表示键盘按下。<br/>- 'keyUp'表示键盘抬起。 |
| callback | (event: [KeyEvent](#keyevent)) => boolean | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。   |

**示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().off('keyUp', (keyEvent: inputMethodEngine.KeyEvent) => {
    console.log('delete keyUp notification.');
    return true;
  });
  inputMethodEngine.getKeyboardDelegate().off('keyDown', (keyEvent: inputMethodEngine.KeyEvent) => {
    console.log('delete keyDown notification.');
    return true;
  });
} catch(err) {
    console.error(`Failed to keyevent: ${JSON.stringify(err)}`);
}
```

### on('keyEvent')<sup>10+</sup>

on(type: 'keyEvent', callback: (event: InputKeyEvent) => boolean): void

订阅硬键盘（即物理键盘）事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 设置监听类型，固定取值为'keyEvent'。 |
| callback | function | 是   | 回调函数，入参为按键事件信息，返回值类型为布尔类型。<br/>-&nbsp;入参按键事件信息的数据类型为[InputKeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent)。<br/>-&nbsp;若按键事件被事件订阅者消费，则callback应返回true，否则返回false。|

**示例：**

```ts
import type { KeyEvent } from '@kit.InputKit';

try {
  inputMethodEngine.getKeyboardDelegate().on('keyEvent', (keyEvent: KeyEvent) => {
    console.log('inputMethodEngine keyEvent.action:' + JSON.stringify(keyEvent.action));
    console.log('inputMethodEngine keyEvent.key.code:' + JSON.stringify(keyEvent.key.code));
    console.log('inputMethodEngine keyEvent.ctrlKey:' + JSON.stringify(keyEvent.ctrlKey));
    return true;
  });
} catch(err) {
    console.error(`Failed to inputMethodEngine: ${JSON.stringify(err)}`);
}
```

### off('keyEvent')<sup>10+</sup>

off(type: 'keyEvent', callback?: (event: InputKeyEvent) => boolean): void

取消订阅硬键盘（即物理键盘）事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 设置监听类型，固定取值为'keyEvent'。 |
| callback | function | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
import type { KeyEvent } from '@kit.InputKit';

try {
  inputMethodEngine.getKeyboardDelegate().off('keyEvent', (keyEvent: KeyEvent) => {
    console.log('This is a callback function which will be deregistered.');
    return true;
  });
  inputMethodEngine.getKeyboardDelegate().off('keyEvent');
} catch(err) {
    console.error(`Failed to keyEvent: ${JSON.stringify(err)}`);
}
```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

订阅光标变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型  | 必填  | 说明  |
| -------- | ---- | ---- | ----- |
| type     | string | 是   | 光标变化事件，固定取值为'cursorContextChange'。 |
| callback | (x: number, y: number, height: number) => void | 是   | 回调函数，返回光标信息。<br/>-x为光标上端的的x坐标值，y为光标上端的y坐标值，height为光标的高度值。 |

**示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().on('cursorContextChange', (x: number, y: number, height: number) => {
    console.log('inputMethodEngine cursorContextChange x:' + x);
    console.log('inputMethodEngine cursorContextChange y:' + y);
    console.log('inputMethodEngine cursorContextChange height:' + height);
  });
} catch(err) {
    console.error(`Failed to cursorContextChange: ${JSON.stringify(err)}`);
}
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void

取消订阅光标变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名    | 类型  | 必填  | 说明   |
| -------- | ---- | ---- | ------ |
| type     | string  | 是   | 光标变化事件，固定取值为'cursorContextChange' |
| callback | (x: number, y:number, height:number) => void | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |


  **示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().off('cursorContextChange', (x: number, y: number, height: number) => {
    console.log('delete cursorContextChange notification.');
  });
} catch(err) {
    console.error(`Failed to cursorContextChange: ${JSON.stringify(err)}`);
}
```
### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

订阅文本选择范围变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型   | 必填 | 说明   |
| -------- | ----- | ---- | ---- |
| type     | string  | 是   | 文本选择变化事件，固定取值为'selectionChange'。 |
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | 是   | 回调函数，返回文本选择信息。<br/>- oldBegin为变化前被选中文本的起始下标，oldEnd为变化前被选中文本的终止下标。<br/>- newBegin为变化后被选中文本的起始下标，newEnd为变化后被选中文本的终止下标。|

**示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate()
    .on('selectionChange', (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => {
      console.log('inputMethodEngine beforeEach selectionChange oldBegin:' + oldBegin);
      console.log('inputMethodEngine beforeEach selectionChange oldEnd:' + oldEnd);
      console.log('inputMethodEngine beforeEach selectionChange newBegin:' + newBegin);
      console.log('inputMethodEngine beforeEach selectionChange newEnd:' + newEnd);
    });
} catch(err) {
    console.error(`Failed to selectionChange: ${JSON.stringify(err)}`);
}
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

取消订阅文本选择范围变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型  | 必填 | 说明     |
| -------- | ------- | ---- | ------- |
| type     | string  | 是   | 文本选择变化事件，固定取值为'selectionChange'。 |
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate()
    .off('selectionChange', (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number)  => {
      console.log('delete selectionChange notification.');
    });
} catch(err) {
    console.error(`Failed to selectionChange: ${JSON.stringify(err)}`);
}
```


### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

订阅文本内容变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件，固定取值为'textChange'。 |
| callback | (text: string) => void | 是   | 回调函数，返回订阅的文本内容。|

**示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().on('textChange', (text: string) => {
    console.log('inputMethodEngine textChange. text:' + text);
  });
} catch(err) {
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);
}
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

取消订阅文本内容变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件，固定取值为'textChange'。 |
| callback | (text: string) => void | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。|

**示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().off('textChange', (text: string) => {
    console.log('delete textChange notification. text:' + text);
  });
} catch(err) {
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);
}
```

### on('editorAttributeChanged')<sup>10+</sup>

on(type: 'editorAttributeChanged', callback: (attr: EditorAttribute) => void): void

订阅编辑框属性变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件，固定取值为'editorAttributeChanged'。 |
| callback | (attr: EditorAttribute) => void | 是   | 回调函数，返回变化的编辑框属性。|

**示例：**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().on('editorAttributeChanged', (attr: inputMethodEngine.EditorAttribute) => {
    console.log(`Succeeded in receiving attribute of editor, inputPattern = ${attr.inputPattern}, enterKeyType = ${attr.enterKeyType}`);
  });
} catch(err) {
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);
}
```

### off('editorAttributeChanged')<sup>10+</sup>

off(type: 'editorAttributeChanged', callback?: (attr: EditorAttribute) => void): void

取消订阅编辑框属性变化事件。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 文本变化事件，固定取值为'editorAttributeChanged'。 |
| callback | (attr: EditorAttribute) => void | 否   | 所要取消订阅的回调处理函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**示例：**

```ts
inputMethodEngine.getKeyboardDelegate().off('editorAttributeChanged');
```

## Panel<sup>10+</sup>

下列API均需使用[createPanel](#createpanel10)获取到Panel实例后，通过实例调用。

### setUiContent<sup>10+</sup>

setUiContent(path: string, callback: AsyncCallback\<void>): void

为当前的输入法面板加载具体页面内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| path | string | 是   | 具体页面的路径。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板页面内容加载成功，err为undefined，否则err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.setUiContent('pages/page2/page2', (err: BusinessError) => {
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

为当前的输入法面板加载具体页面内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| path | string | 是   |  具体页面的路径。 |

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.setUiContent('pages/page2/page2').then(() => {
    console.log('Succeeded in setting the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void

为当前的输入法面板加载与LocalStorage相关联的具体页面内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| path | string | 是   | LocalStorage相关联的具体页面的路径。 |
| storage | [LocalStorage](../apis-arkui/arkui-ts/ts-state-management.md#localstorage9) | 是   | 存储单元，为应用程序范围内的可变和不可变状态属性提供存储。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板页面内容加载成功，err为undefined，否则err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
try {
  panel.setUiContent('pages/page2/page2', storage, (err: BusinessError) => {
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
| storage | [LocalStorage](../apis-arkui/arkui-ts/ts-state-management.md#localstorage9) | 是   | 存储单元，为应用程序范围内的可变状态属性和非可变状态属性提供存储。|

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
try {
  panel.setUiContent('pages/page2/page2', storage).then(() => {
    console.log('Succeeded in setting the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### resize<sup>10+</sup>

resize(width: number, height: number, callback: AsyncCallback\<void>): void

改变当前输入法面板的大小，使用callback异步回调。

> **说明**
>
> 面板宽度不超出屏幕宽度，面板高度不高于屏幕高度的0.6倍。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| width | number | 是   | 目标面板的宽度，单位为px。|
| height | number | 是   | 目标面板的高度，单位为px。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板大小改变成功，err为undefined，否则err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.resize(500, 1000, (err: BusinessError) => {
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

resize(width: number, height: number): Promise\<void>

改变当前输入法面板的大小，使用Promise异步回调。

> **说明**
>
> 面板宽度不超出屏幕宽度，面板高度不高于屏幕高度的0.6倍。

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

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.resize(500, 1000).then(() => {
    console.log('Succeeded in changing the panel size.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
}
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number, callback: AsyncCallback\<void>): void

移动面板位置，使用callback异步回调。[面板状态](#panelflag10)为固定态时，不产生实际移动效果。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| x | number | 是   | x轴方向移动的值，值大于0表示右移，单位为px。|
| y | number | 是   | y轴方向移动的值，值大于0表示下移，单位为px。|
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板位置移动成功，err为undefined，否则err为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.moveTo(300, 300, (err: BusinessError) =>{
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

移动面板位置，使用promise异步回调。[面板状态](#panelflag10)为固定态时，不产生实际移动效果。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| x | number | 是   |x轴方向移动的值，值大于0表示右移，单位为px。|
| y | number | 是   |y轴方向移动的值，值大于0表示下移，单位为px。|

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.moveTo(300, 300).then(() => {
    console.log('Succeeded in moving the panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to move panel: ${JSON.stringify(err)}`);
}
```

### show<sup>10+</sup>

show(callback: AsyncCallback\<void>): void

显示当前输入法面板，使用callback异步回调。输入法应用与编辑框绑定成功后可正常调用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板显示成功，err为undefined，否则err为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.show((err: BusinessError) => {
  if (err) {
    console.error(`Failed to show panel: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in showing the panel.');
});
```

### show<sup>10+</sup>

show(): Promise\<void>

显示当前输入法面板，使用promise异步回调。输入法应用与编辑框绑定成功后可正常调用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.show().then(() => {
  console.log('Succeeded in showing the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show panel: ${JSON.stringify(err)}`);
});
```

### hide<sup>10+</sup>

hide(callback: AsyncCallback\<void>): void

隐藏当前输入法面板，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当面板隐藏成功，err为undefined，否则err为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.hide((err: BusinessError) => {
  if (err) {
    console.error(`Failed to hide panel: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in hiding the panel.');
});
```

### hide<sup>10+</sup>

hide(): Promise\<void>

隐藏当前输入法面板，使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型   | 说明                             |
| ------- | ------------------------------ |
| Promise\<void> | 无返回结果的Promise对象。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.hide().then(() => {
  console.log('Succeeded in hiding the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide panel: ${JSON.stringify(err)}`);
});
```

### adjustPanelRect<sup>12+</sup>

adjustPanelRect(flag: PanelFlag, rect: PanelRect): void

预设置输入法应用横竖屏大小。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | 是 | 目标面板状态类型。类型为FLG_FIXED或FLG_FLOATING |
| rect | [PanelRect](#panelrect12) | 是   | 目标面板横屏状态及竖屏状态的横坐标，纵坐标，宽度以及高度。固定态：高度不能超过屏幕高度的70%，宽度不能超过屏幕宽度；悬浮态：高度不能超过屏幕高度，宽度不能超过屏幕宽度。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800013 | window manager service error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let panelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
  let panelRect:inputMethodEngine.PanelRect = {
    landscapeRect:{left:100, top:100, width:400, height:400},
    portraitRect:{left:200, top:200, width:300, height:300}
  };
  panel.adjustPanelRect(panelFlag, panelRect);
} catch(err) {
  console.error(`Failed to adjustPanelRect: ${JSON.stringify(err)}`);
}
```

### on('show')<sup>10+</sup>

on(type: 'show', callback: () => void): void

监听当前面板显示状态，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 监听当前面板的状态类型，固定取值为'show'。 |
| callback | () => void | 是   | 回调函数。 |

**示例：**

```ts
try {
  panel.on('show', () => {
    console.log('Panel is showing.');
  });
} catch(err) {
    console.error(`Failed to show: ${JSON.stringify(err)}`);
}
```

### on('hide')<sup>10+</sup>

on(type: 'hide', callback: () => void): void

监听当前面板隐藏状态，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 监听当前面板的状态类型，固定取值为'hide'。 |
| callback | () => void | 是   | 回调函数。 |

**示例：**

```ts
try {
  panel.on('hide', () => {
    console.log('Panel is hiding.');
  });
} catch(err) {
    console.error(`Failed to hide: ${JSON.stringify(err)}`);
}
```

### on('sizeChange')<sup>12+</sup>

on(type: 'sizeChange', callback: Callback&lt;window.Size&gt;): void;

监听当前面板大小变化，使用callback异步回调。

>**说明:**
>
> 仅用于SOFT_KEYBOARD类型，状态为FLG_FIXED或FLG_FLOATING的面板。由于输入法通过adjustPanelRect等接口对面板大小调节时，系统往往要根据一定规则校验计算得出最终的数值(例如超出屏幕等场景)，输入法应用可通过该回调做最终的面板布局刷新。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 监听当前面板的大小是否产生变化，固定取值为'sizeChange'。 |
| callback | Callback\<[window.Size](../apis-arkui/js-apis-window.md#size7)> |  是  | 回调函数。返回当前软键盘面板的大小，包含宽度和高度值。 |

**示例：**

```ts
import { window } from '@kit.ArkUI';
try {
  panel.on('sizeChange', (windowSize: window.Size) => {
    console.info(`panel is size changes, width: ${JSON.stringify(windowSize.width)}, height:${JSON.stringify(windowSize.width)}`);
  });
} catch(err) {
  console.error(`Failed to sizeChange: ${JSON.stringify(err)}`);
}
```

### off('show')<sup>10+</sup>

off(type: 'show', callback?: () => void): void

取消监听当前输入法面板的隐藏状态，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 取消监听当前面板的状态类型，固定取值为'show'。 |
| callback | () => void | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
try {
  panel.off('show');
} catch(err) {
    console.error(`Failed to show: ${JSON.stringify(err)}`);
}
```

### off('hide')<sup>10+</sup>

off(type: 'hide', callback?: () => void): void

取消监听当前面板隐藏状态，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 要取消监听的当前面板状态类型，固定取值为'hide'。 |
| callback | () => void | 否   | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
try {
  panel.off('hide');
} catch(err) {
    console.error(`Failed to hide: ${JSON.stringify(err)}`);
}
```

### off('sizeChange')<sup>12+</sup>

off(type: 'sizeChange', callback?: Callback&lt;window.Size&gt;): void;

取消监听当前面板大小变化，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| type | string | 是 | 监听当前面板的大小是否产生变化，固定取值为'sizeChange'。 |
| callback | Callback\<[window.Size](../apis-arkui/js-apis-window.md#size7)> | 否   | 回调函数。返回当前软键盘面板的大小，包含宽度和高度值。 |

**示例：**

```ts
import { window } from '@kit.ArkUI';
try {
  panel.off('sizeChange', (windowSize: window.Size) => {
    console.info(`panel is size changes, width: ${JSON.stringify(windowSize.width)}, height:${JSON.stringify(windowSize.width)}`);
  });
} catch(err) {
    console.error(`Failed to sizeChange: ${JSON.stringify(err)}`);
}
```

### changeFlag<sup>10+</sup>

changeFlag(flag: PanelFlag): void

将输入法应用的面板状态改变为固定态或者悬浮态，仅对[SOFT_KEYBOARD](#paneltype10)生效。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | 是 | 目标面板状态类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**示例：**

```ts
try {
  let panelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
  panel.changeFlag(panelFlag);
} catch(err) {
    console.error(`Failed to panelFlag: ${JSON.stringify(err)}`);
}
```

### setPrivacyMode<sup>11+</sup>

setPrivacyMode(isPrivacyMode: boolean): void

将输入法应用的面板设置为隐私模式，隐私模式不可被录屏、截屏。

**需要权限：** ohos.permission.PRIVACY_WINDOW

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名        | 类型    | 必填 | 说明               |
| ------------- | ------- | ---- | ------------------ |
| isPrivacyMode | boolean | 是   | 是否设置隐私模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 201      | permissions check fails.  |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
try {
    let isPrivacyMode = true;
    panel.setPrivacyMode(isPrivacyMode);
} catch(err) {
    console.error(`Failed to set privacy mode: ${JSON.stringify(err)}`);
}
```

## KeyboardController

下列API均需使用[on('inputStart')](#oninputstart9)获取到KeyboardController实例后，通过实例调用。

### hide<sup>9+</sup>

hide(callback: AsyncCallback&lt;void&gt;): void

隐藏输入法。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明     |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | 是   | 回调函数。当输入法隐藏成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hide((err: BusinessError) => {
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hide().then(() => {
  console.log('Succeeded in hiding keyboard.');
}).catch((err: BusinessError) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hideKeyboard((err: BusinessError) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hideKeyboard().then(() => {
  console.log('Succeeded in hiding keyboard.');
}).catch((err: BusinessError) => {
  console.log(`Failed to hideKeyboard: ${JSON.stringify(err)}`);
});
```

### exitCurrentInputType<sup>11+</sup>

exitCurrentInputType(callback: AsyncCallback&lt;void&gt;): void

退出当前输入类型，仅支持系统配置的默认输入法应用调用。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void> | 是   | 回调函数。当退出当前输入类型成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 12800008 | input method manager service error.            |
| 12800010 | not default input method configured by system. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.exitCurrentInputType((err: BusinessError) => {
  if (err) {
    console.error(`Failed to exitCurrentInputType: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in exiting current input type.');
});
```

### exitCurrentInputType<sup>11+</sup>

exitCurrentInputType(): Promise&lt;void&gt;

退出当前输入类型，仅支持系统配置的默认输入法应用调用。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型             | 说明                      |
| ---------------- | ------------------------- |
| Promise&lt;void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 12800008 | input method manager service error.            |
| 12800010 | not default input method configured by system. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.exitCurrentInputType().then(() => {
  console.log('Succeeded in exiting current input type.');
}).catch((err: BusinessError) => {
  console.log(`Failed to exit current input type: ${JSON.stringify(err)}`);
});
```

## SecurityMode<sup>11+</sup>

输入法的安全模式，如BASIC或FULL。

**系统能力**: SystemCapability.MiscServices.InputMethodFramework

| 名称  | 值   | 说明                                         |
| ----- | ---- | -------------------------------------------- |
| BASIC | 0    | 基础访问模式，基础打字模式，会限制网络访问。 |
| FULL  | 1    | 完全访问模式，不做限制，可以访问网络。       |

## ExtendAction<sup>10+</sup>

编辑框中文本的扩展编辑操作类型，如剪切、复制等。

**系统能力**: SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| SELECT_ALL  | 0 |全选。 |
| CUT  | 3 |剪切。 |
| COPY  | 4 |复制。 |
| PASTE  | 5 |粘贴。 |

## Direction<sup>10+</sup>

光标的移动方向。

**系统能力**: SystemCapability.MiscServices.InputMethodFramework

| 名称 | 值 |说明 |
| -------- | -------- |-------- |
| CURSOR_UP  | 1 |向上。 |
| CURSOR_DOWN  | 2 |向下。 |
| CURSOR_LEFT  | 3 |向左。 |
| CURSOR_RIGHT  | 4 |向右。 |

## Range<sup>10+</sup>

选中的文本范围。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| start  | number | 是 | 是 | 选中文本的首字符在编辑框的索引值。|
| end  | number | 是 | 是 | 选中文本的末字符在编辑框的索引值。|

## Movement<sup>10+</sup>

选中文本时，光标移动的方向

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| direction  | [Direction](#direction10) | 是 | 是 | 选中文本时，光标的移动方向。|

## InputClient<sup>9+</sup>

下列API均需使用[on('inputStart')](#oninputstart9)获取到InputClient实例后，通过实例调用。

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

发送功能键。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

  **参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| action | number | 是 | 功能键键值。<br/>- 当值为0时，表示无效按键。<br/>- 当值为1时，表示确认键（即回车键）。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当功能键发送成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. |

 **示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action = 1;
try {
  inputClient.sendKeyFunction(action, (err: BusinessError, result: boolean) => {
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action = 1;
try {
  inputClient.sendKeyFunction(action).then((result: boolean) => {
    if (result) {
      console.log('Succeeded in sending key function.');
    } else {
      console.error('Failed to sendKeyFunction.');
    }
  }).catch((err: BusinessError) => {
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
| length | number | 是 | 文本长度。不能小于0。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标前固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.getForward(length, (err: BusinessError, text: string) => {
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
| length | number | 是 | 文本长度。不能小于0 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise对象，返回光标前固定长度的文本。                     |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.getForward(length).then((text: string) => {
    console.log('Succeeded in getting forward, text: ' + text);
  }).catch((err: BusinessError) => {
    console.error(`Failed to getForward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);
}
```

### getForwardSync<sup>10+</sup>

getForwardSync(length:number): string

获取光标前固定长度的文本。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。不能小于0。 |

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 返回光标前固定长度的文本。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error.     |
| 12800006 | input method controller error. |

**示例：**

```ts
let length = 1;
try {
  let text: string = inputClient.getForwardSync(length);
  console.log(`Succeeded in getting forward, text: ${text}`);
} catch (err) {
  console.error(`Failed to getForwardSync: ${JSON.stringify(err)}`);
}
```

### getBackward<sup>9+</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

获取光标后固定长度的文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。不能小于0。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标后固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.getBackward(length, (err: BusinessError, text: string) => {
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
| length | number | 是 | 文本长度。不能小于0。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise对象，返回光标后固定长度的文本。                     |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                     |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.getBackward(length).then((text: string) => {
    console.log('Succeeded in getting backward, text: ' + text);
  }).catch((err: BusinessError) => {
    console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
}
```

### getBackwardSync<sup>10+</sup>

getBackwardSync(length:number): string

获取光标后固定长度的文本。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。不能小于0。 |

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 返回光标后固定长度的文本。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error.     |
| 12800006 | input method controller error. |

**示例：**

```ts
let length = 1;
try {
  let text: string = inputClient.getBackwardSync(length);
  console.log(`Succeeded in getting backward, text: ${text}`);
} catch (err) {
  console.error(`Failed to getBackwardSync: ${JSON.stringify(err)}`);
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标前固定长度的文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| length | number | 是 | 文本长度。不能小于0。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当光标前固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.deleteForward(length, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in deleting forward.');
    } else {
      console.error(`Failed to deleteForward.`);
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
| length | number | 是   | 文本长度。不能小于0。 |

**返回值：**  

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示删除光标前固定长度的文本成功；返回false表示删除光标前固定长度的文本失败。|

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.deleteForward(length).then((result: boolean) => {
    if (result) {
      console.log('Succeeded in deleting forward.');
    } else {
      console.error('Failed to delete Forward.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
}
```

### deleteForwardSync<sup>10+</sup>

deleteForwardSync(length:number): void

删除光标前固定长度的文本。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。不能小于0。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800002 | input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
let length = 1;
try {
  inputClient.deleteForwardSync(length);
  console.log('Succeeded in deleting forward.');
} catch (err) {
  console.error('deleteForwardSync err: ' + JSON.stringify(err));
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

删除光标后固定长度的文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                         | 必填 | 说明           |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | 是   | 文本长度。不能小于0。     |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。当光标后固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.deleteBackward(length, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in deleting backward.');
    } else {
      console.error(`Failed to deleteBackward.`);
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
| length | number | 是 | 文本长度。不能小于0。    |

**返回值：** 

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示删除光标后固定长度的文本成功；返回false表示删除光标后固定长度的文本失败。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
inputClient.deleteBackward(length).then((result: boolean) => {
  if (result) {
    console.log('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
});
```

### deleteBackwardSync<sup>10+</sup>

deleteBackwardSync(length:number): void

删除光标后固定长度的文本。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| length | number | 是   | 文本长度。不能小于0。  |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800002 | input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
let length = 1;
try {
  inputClient.deleteBackwardSync(length);
  console.log('Succeeded in deleting backward.');
} catch (err) {
  console.error('deleteBackwardSync err: ' + JSON.stringify(err));
}
```

### insertText<sup>9+</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

插入文本。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 文本内容。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当文本插入成功，err为undefined，data为true；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.insertText('test', (err: BusinessError, result: boolean) => {
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.insertText('test').then((result: boolean) => {
    if (result) {
      console.log('Succeeded in inserting text.');
    } else {
      console.error('Failed to insertText.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to insertText: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to insertText: ${JSON.stringify(err)}`);
}
```

### insertTextSync<sup>10+</sup>

insertTextSync(text: string): void

插入文本。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| text   | string | 是   | 文本内容。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. |
| 12800003 | input method client error. |

**示例：**

```ts
try {
  inputClient.insertTextSync('test');
  console.log('Succeeded in inserting text.');
} catch (err) {
  console.error(`Failed to insertTextSync: ${JSON.stringify(err)}`);
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getEditorAttribute((err: BusinessError, editorAttribute: inputMethodEngine.EditorAttribute) => {
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.getEditorAttribute().then((editorAttribute: inputMethodEngine.EditorAttribute) => {
    console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
  }).catch((err: BusinessError) => {
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
  });
} catch(err) {
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
}
```

### getEditorAttributeSync<sup>10+</sup>

getEditorAttributeSync(): EditorAttribute

获取编辑框属性值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                | 说明           |
| ----------------------------------- | -------------- |
| [EditorAttribute](#editorattribute) | 编辑框属性对象 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**示例：**

```ts
try {
  let editorAttribute: inputMethodEngine.EditorAttribute = inputClient.getEditorAttributeSync();
  console.log(`Succeeded in getEditorAttributeSync, editorAttribute = ${JSON.stringify(editorAttribute)}`);
} catch (err) {
  console.error(`Failed to getEditorAttributeSync: ${JSON.stringify(err)}`);
}
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number, callback: AsyncCallback&lt;void&gt;): void

移动光标。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------- |
| direction | number                    | 是   | 光标移动方向。<br/>- 当值为1时，表示向上。<br/>- 当值为2时，表示向下。<br/>- 当值为3时，表示向左。<br/>- 当值为4时，表示向右。不能小于0。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当光标移动成功，err为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.moveCursor(inputMethodEngine.Direction.CURSOR_UP, (err: BusinessError) => {
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

| 参数名    | 类型   | 必填 | 说明                                                         |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| direction | number | 是   | 光标移动方向。<br/>- 当值为1时，表示向上。<br/>- 当值为2时，表示向下。<br/>- 当值为3时，表示向左。<br/>- 当值为4时，表示向右。不能小于0。 |

**返回值：**  

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.moveCursor(inputMethodEngine.Direction.CURSOR_UP).then(() => {
    console.log('Succeeded in moving cursor.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
}
```

### moveCursorSync<sup>10+</sup>

moveCursorSync(direction: number): void

移动光标。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名    | 类型   | 必填 | 说明                                                         |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| direction | number | 是   | 光标移动方向。<br/>- 当值为1时，表示向上。<br/>- 当值为2时，表示向下。<br/>- 当值为3时，表示向左。<br/>- 当值为4时，表示向右。不能小于0。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. |

**示例：**

```ts
try {
  inputClient.moveCursorSync(inputMethodEngine.Direction.CURSOR_UP);
  console.log('Succeeded in moving cursor.');
} catch (err) {
  console.error(`Failed to moveCursorSync: ${JSON.stringify(err)}`);
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.selectByRange(range, (err: BusinessError) => {
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.selectByRange(range).then(() => {
    console.log('Succeeded in selecting by range.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
}
```

### selectByRangeSync<sup>10+</sup>

selectByRangeSync(range: Range): void

根据索引范围选中文本。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型              | 必填 | 说明             |
| ------ | ----------------- | ---- | ---------------- |
| range  | [Range](#range10) | 是   | 选中文本的范围。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. |

**示例：**

```ts
try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.selectByRangeSync(range);
  console.log('Succeeded in selecting by range.');
} catch (err) {
  console.error(`Failed to selectByRangeSync: ${JSON.stringify(err)}`);
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let movement: inputMethodEngine.Movement = { direction: 1 };
  inputClient.selectByMovement(movement, (err: BusinessError) => {
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let movement: inputMethodEngine.Movement = { direction: 1 };
  inputClient.selectByMovement(movement).then(() => {
    console.log('Succeeded in selecting by movement.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
}
```

### selectByMovementSync<sup>10+</sup>

selectByMovementSync(movement: Movement): void

根据光标移动方向选中文本。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                    | 必填 | 说明                   |
| -------- | ----------------------- | ---- | ---------------------- |
| movement | [Movement](#movement10) | 是   | 选中时光标移动的方向。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. |

**示例：**

```ts
try {
  let movement: inputMethodEngine.Movement = { direction: 1 };  
  inputClient.selectByMovementSync(movement);
  console.log('Succeeded in selecting by movement.');
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getTextIndexAtCursor((err: BusinessError, index: number) => {
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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getTextIndexAtCursor().then((index: number) => {
  console.log('Succeeded in getTextIndexAtCursor: ' + index);
}).catch((err: BusinessError) => {
  console.error(`Failed to getTextIndexAtCursor: ${JSON.stringify(err)}`);
});
```

### getTextIndexAtCursorSync<sup>10+</sup>

getTextIndexAtCursorSync(): number

获取光标所在处的文本索引。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 返回光标所在处的文本索引。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
try{
  let index: number = inputClient.getTextIndexAtCursorSync();
  console.log(`Succeeded in getTextIndexAtCursorSync, index: ${index}`);
} catch (err) {
  console.error(`Failed to getTextIndexAtCursorSync: ${JSON.stringify(err)}`);
}
```

### sendExtendAction<sup>10+</sup>

sendExtendAction(action: ExtendAction, callback: AsyncCallback&lt;void&gt;): void

发送扩展编辑操作。使用callback异步回调。

> **说明**
>
> 输入法应用调用该接口向编辑框发送扩展编辑操作，编辑框监听相应事件[on('handleExtendAction')](./js-apis-inputmethod.md#onhandleextendaction10)，从而进一步做出处理。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| action | [ExtendAction](#extendaction10) | 是   | 要发送的扩展操作。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。发送成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY, (err: BusinessError) => {
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

>**说明**
>
> 输入法应用调用该接口向编辑框发送扩展编辑操作，编辑框监听相应事件[on('handleExtendAction')](./js-apis-inputmethod.md#onhandleextendaction10)，从而进一步做出处理。

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

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY).then(() => {
    console.log('Succeeded in sending extend action.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
  });
} catch(err) {
  console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
}
```

### sendPrivateCommand<sup>12+</sup>

sendPrivateCommand(commandData: Record&lt;string, CommandDataType&gt;): Promise&lt;void&gt;

发送私有数据至需要与输入法应用通信的系统其他部分。

>**说明:**
>
> - 私有数据通道是系统预置输入法应用与系统特定组件（如文本框、桌面应用等）的通信机制，常用于设备级厂商在特定设备上实现自定义的输入法功能。
> - 私有数据规格限制：总大小32KB，数量限制5条。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名      | 类型                            | 必填 | 说明       |
| ----------- | ------------------------------- | ---- | ---------- |
| commandData | Record<string, [CommandDataType](#inputmethodenginecommanddatatype12)> | 是   | 私有数据。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error.                     |
| 12800010 | not default input method configured by system. |

**示例：**

```ts
import { inputMethodEngine } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, textInputClient) => {
  try {
    let record: Record<string, inputMethodEngine.CommandDataType> = {
      "valueString1": "abcdefg",
      "valueString2": true,
      "valueString3": 500,
    }
    textInputClient.sendPrivateCommand(record).then(() => {
    }).catch((err: BusinessError) => {
      if (err !== undefined) {
        let error = err as BusinessError;
        console.error(`sendPrivateCommand catch error: ${error.code} ${error.message}`);
      }
    });
  } catch (err) {
    let error = err as BusinessError;
    console.error(`sendPrivateCommand catch error: ${error.code} ${error.message}`);
  }
})
```

### getCallingWindowInfo<sup>12+</sup>

getCallingWindowInfo(): Promise&lt;WindowInfo&gt;

获取当前拉起输入法的输入框所在应用窗口信息。使用promise异步回调。

>**说明：**
>
>本接口仅适用于适配使用[Panel](#panel10)作为软键盘窗口的输入法应用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                                       | 说明                                                  |
| ------------------------------------------ | ----------------------------------------------------- |
| Promise&lt;[WindowInfo](#windowinfo12)&gt; | Promise对象，返回拉起输入法的输入框所在应用窗口信息。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 12800003 | input method client error.        |
| 12800012 | input method panel doesn't exist. |
| 12800013 | window manager service error.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.getCallingWindowInfo().then((windowInfo: inputMethodEngine.WindowInfo) => {
    console.log(`windowInfo.rect: ${JSON.stringify(windowInfo.rect)}`);
    console.log('windowInfo.status: ' + JSON.stringify(windowInfo.status));
  }).catch((err: BusinessError) => {
    console.error(`Failed to getCallingWindowInfo: ${JSON.stringify(err)}`);
  });
} catch(err) {
    console.error(`Failed to getCallingWindowInfo: ${JSON.stringify(err)}`);
}
```

### setPreviewText<sup>12+</sup>

setPreviewText(text: string, range: Range): Promise&lt;void&gt;

设置预上屏文本。使用promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型              | 必填 | 说明                                                         |
| ------ | ----------------- | ---- | ------------------------------------------------------------ |
| text   | string            | 是   | 将被预上屏的文本。                                           |
| range  | [Range](#range10) | 是   | 目标替换的文本范围。<br/>- 当值为{ start: -1, end: -1 }时，默认将参数text替换当前预上屏区域全部文本。<br/>- 当start等于end，默认将参数text插入start对应的光标位置。<br/>- 当start不等于end，将参数text替换range对应区域的文本。<br/>- 当start与end为其他含有负数值的组合，按照参数错误返回。<br/>- 当输入框已有预上屏文本，参数range不得超过预上屏文本范围，否则按照参数错误返回。<br/>- 当输入框无预上屏文本，参数range不得超过输入框文本范围，否则按照参数错误返回。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error.                                   |
| 12800011 | text preview is not supported.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.setPreviewText('test', range).then(() => {
    console.log('Succeeded in setting preview text.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setPreviewText: ${JSON.stringify(err)}`);
  });
} catch(err) {
    console.error(`Failed to setPreviewText: ${JSON.stringify(err)}`);
}
```

### setPreviewTextSync<sup>12+</sup>

setPreviewTextSync(text: string, range: Range): void

设置预上屏文本。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型              | 必填 | 说明                                                         |
| ------ | ----------------- | ---- | ------------------------------------------------------------ |
| text   | string            | 是   | 将被预上屏的文本。                                           |
| range  | [Range](#range10) | 是   | 目标替换的文本范围。<br/>- 当值为{ start: -1, end: -1 }时，默认将参数text替换当前预上屏区域全部文本。<br/>- 当start等于end，默认将参数text插入start对应的光标位置。<br/>- 当start不等于end，将参数text替换range对应区域的文本。<br/>- 当start与end为其他含有负数值的组合，按照参数错误返回。<br/>- 当输入框已有预上屏文本，参数range不得超过预上屏文本范围，否则按照参数错误返回。<br/>- 当输入框无预上屏文本，参数range不得超过输入框文本范围，否则按照参数错误返回。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error.                                   |
| 12800011 | text preview is not supported.                               |

**示例：**

```ts
try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.setPreviewTextSync('test', range);
  console.log('Succeeded in setting preview text with synchronized method.');
} catch (err) {
  console.error(`Failed to setPreviewTextSync: ${JSON.stringify(err)}`);
}
```

### finishTextPreview<sup>12+</sup>

finishTextPreview(): Promise&lt;void&gt;

结束预上屏。使用promise异步回调。

>**说明：**
>
>若当前输入框已有预上屏状态文本，调用此接口后，预上屏内容将被系统正式上屏。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800011 | text preview is not supported. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.finishTextPreview().then(() => {
    console.log('Succeeded in finishing text preview.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to finishTextPreview: ${JSON.stringify(err)}`);
  });
} catch(err) {
    console.error(`Failed to finishTextPreview: ${JSON.stringify(err)}`);
}
```

### finishTextPreviewSync<sup>12+</sup>

finishTextPreviewSync(): void

结束预上屏。

>**说明：**
>
>若当前输入框已有预上屏状态文本，调用此接口后，预上屏内容将被系统正式上屏。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800011 | text preview is not supported. |

**示例：**

```ts
try {
  inputClient.finishTextPreviewSync();
  console.log('Succeeded in finishing text preview with synchronized method.');
} catch (err) {
  console.error(`Failed to finishTextPreviewSync: ${JSON.stringify(err)}`);
}
```

## EditorAttribute

编辑框属性值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称         | 类型 | 只读 | 可选 | 说明               |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | 是   | 否   | 编辑框的功能属性。 |
| inputPattern | number   | 是   | 否   | 编辑框的文本属性。 |
| isTextPreviewSupported<sup>12+</sup> | boolean | 否 | 否 | 编辑框是否支持预上屏。 |

## KeyEvent

按键属性值。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称      | 类型 | 只读 | 可选 | 说明         |
| --------- | -------- | ---- | ---- | ------------ |
| keyCode   | number   | 是   | 否   | 按键的键值。键码值说明参考[KeyCode](../apis-input-kit/js-apis-keycode.md#keycode)。 |
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

输入法面板属性。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称      | 类型 | 只读 | 可选 | 说明         |
| --------- | -------- | ---- | ---- | ------------ |
| type   	| [PanelType](#paneltype10)   | 是   | 是   | 面板的类型。 |
| flag	    | [PanelFlag](#panelflag10)   | 是   | 是   | 面板的状态类型。 |

## PanelRect<sup>12+</sup>

输入法面板位置大小信息。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称         | 类型 | 只读 | 可选 | 说明               |
| ------------ | -------- | ---- | ---- | ------------------ |
| landscapeRect | [window.Rect](../apis-arkui/js-apis-window.md#rect7)   | 是   | 是   | 横屏状态时输入法面板窗口的位置大小。 |
| portraitRect | [window.Rect](../apis-arkui/js-apis-window.md#rect7)   | 是   | 是   | 竖屏状态时输入法面板窗口的位置大小。 |

## WindowInfo<sup>12+</sup>

窗口信息。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

| 名称   | 类型                                                         | 只读 | 可选 | 说明           |
| ------ | ------------------------------------------------------------ | ---- | ---- | -------------- |
| rect   | [window.Rect](../apis-arkui/js-apis-window.md#rect7)         | 是   | 是   | 窗口矩形区域。 |
| status | [window.WindowStatusType](../apis-arkui/js-apis-window.md#windowstatustype11) | 是   | 是   | 窗口模式类型。 |

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
| length | number | 是 | 文本长度。不能小于0。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标前固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.getForward(length, (err: BusinessError, text: string) => {
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
| length | number | 是 | 文本长度。不能小于0。|

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise对象，返回光标前固定长度的文本。                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.getForward(length).then((text: string) => {
  console.log('Succeeded in getting forward, text: ' + text);
}).catch((err: BusinessError) => {
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
| length | number | 是 | 文本长度。不能小于0。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。当光标后固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.getBackward(length, (err: BusinessError, text: string) => {
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
| length | number | 是 | 文本长度。不能小于0。 |

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise对象，返回光标后固定长度的文本。                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.getBackward(length).then((text: string) => {
  console.log('Succeeded in getting backward: ' + JSON.stringify(text));
}).catch((err: BusinessError) => {
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
| length | number | 是 | 文本长度。不能小于0。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当光标前固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.deleteForward(length, (err: BusinessError, result: boolean) => {
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
| length | number | 是   | 文本长度。不能小于0。 |

**返回值：**  

| 类型                   | 说明           |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示删除光标前固定长度的文本成功；返回false表示删除光标前固定长度的文本失败。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.deleteForward(length).then((result: boolean) => {
  if (result) {
    console.log('Succeeded in deleting forward.');
  } else {
    console.error('Failed to delete forward.');
  }
}).catch((err: BusinessError) => {
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
| length   | number                       | 是   | 文本长度。不能小于0。      |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。当光标后固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.deleteBackward(length, (err: BusinessError, result: boolean) => {
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
| length | number | 是 | 文本长度。不能小于0。  |

**返回值：** 

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise对象。返回true表示删除光标后固定长度的文本成功；返回false表示删除光标后固定长度的文本失败。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.deleteBackward(length).then((result: boolean) => {
  if (result) {
    console.log('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
}).catch((err: BusinessError) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action = 1;
textInputClient.sendKeyFunction(action, (err: BusinessError, result: boolean) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action = 1;
textInputClient.sendKeyFunction(action).then((result: boolean) => {
  if (result) {
    console.log('Succeeded in sending key function.');
  } else {
    console.error('Failed to sendKeyFunction.');
  }
}).catch((err: BusinessError) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.insertText('test', (err: BusinessError, result: boolean) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.insertText('test').then((result: boolean) => {
  if (result) {
    console.log('Succeeded in inserting text.');
  } else {
    console.error('Failed to insertText.');
  }
}).catch((err: BusinessError) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.getEditorAttribute((err: BusinessError, editorAttribute: inputMethodEngine.EditorAttribute) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.getEditorAttribute().then((editorAttribute: inputMethodEngine.EditorAttribute) => {
  console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
  console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
}).catch((err: BusinessError) => {
  console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
});
```
<!--no_check-->