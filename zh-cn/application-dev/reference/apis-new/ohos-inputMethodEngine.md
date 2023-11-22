# @ohos.inputMethodEngine    
本模块面向输入法应用（包括系统输入法应用、三方输入法应用），为输入法应用提供能力，包括：创建软键盘窗口、插入/删除字符、选中文本、监听物理键盘按键事件等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputMethodEngine from '@ohos.inputMethodEngine'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| ENTER_KEY_TYPE_UNSPECIFIED | number |  | 无功能键。 |  
| ENTER_KEY_TYPE_GO | number |  | “前往”功能键。 |  
| ENTER_KEY_TYPE_SEARCH | number |  | “搜索”功能键。 |  
| ENTER_KEY_TYPE_SEND | number |  | “发送”功能键。 |  
| ENTER_KEY_TYPE_NEXT | number |  | “下一个”功能键。 |  
| ENTER_KEY_TYPE_DONE | number |  | “回车”功能键。 |  
| ENTER_KEY_TYPE_PREVIOUS | number |  | “前一个”功能键。 |  
| PATTERN_NULL | number |  | 无特殊性编辑框。 |  
| PATTERN_TEXT | number |  | 文本编辑框。 |  
| PATTERN_NUMBER | number |  | 数字编辑框。 |  
| PATTERN_PHONE | number |  | 电话号码编辑框。 |  
| PATTERN_DATETIME | number |  | 日期编辑框。 |  
| PATTERN_EMAIL | number |  | 邮件编辑框。 |  
| PATTERN_URI | number |  | 超链接编辑框。 |  
| PATTERN_PASSWORD | number |  | 密码编辑框。 |  
| FLAG_SELECTING | number |  | 编辑框处于选择状态。 |  
| FLAG_SINGLE_LINE | number |  | 编辑框为单行。 |  
| DISPLAY_MODE_PART | number |  | 编辑框显示为半屏。 |  
| DISPLAY_MODE_FULL | number |  | 编辑框显示为全屏。 |  
| OPTION_ASCII | number |  | 允许输入ASCII值。 |  
| OPTION_NONE | number |  | 不指定编辑框输入属性。 |  
| OPTION_AUTO_CAP_CHARACTERS | number |  | 允许输入字符。 |  
| OPTION_AUTO_CAP_SENTENCES | number |  | 允许输入句子。 |  
| OPTION_AUTO_WORDS | number |  | 允许输入单词。 |  
| OPTION_MULTI_LINE | number |  | 允许输入多行。 |  
| OPTION_NO_FULLSCREEN | number |  | 半屏样式。 |  
| CURSOR_UP<sup>(9+)</sup> | number |  | 光标上移。 |  
| CURSOR_DOWN<sup>(9+)</sup> | number |  | 光标下移。 |  
| CURSOR_LEFT<sup>(9+)</sup> | number |  | 光标左移。 |  
| CURSOR_RIGHT<sup>(9+)</sup> | number |  | 光标右移。 |  
| WINDOW_TYPE_INPUT_METHOD_FLOAT<sup>(9+)</sup> | number |  | 输入法应用窗口风格标识。 |  
    
## getInputMethodAbility<sup>(9+)</sup>    
获取输入法应用客户端实例[InputMethodAbility](#inputmethodability)，仅支持输入法应用调用。  
输入法应用获取该实例后，可订阅软键盘显示/隐藏请求事件、创建/销毁输入法面板等。  
 **调用形式：**     
- getInputMethodAbility(): InputMethodAbility  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputMethodAbility | 输入法应用客户端。 |  
    
 **示例代码：**   
```ts    
let InputMethodAbility = inputMethodEngine.getInputMethodAbility();    
```    
  
    
## getInputMethodEngine<sup>(deprecated)</sup>    
获取输入法应用客户端实例[InputMethodEngine](#inputmethodengine)。  
输入法应用获取该实例后，可订阅软键盘显示/隐藏请求事件等。  
 **调用形式：**     
- getInputMethodEngine(): InputMethodEngine  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine#getInputMethodAbility。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputMethodEngine | 输入法应用客户端。 |  
    
 **示例代码：**   
```ts    
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();    
```    
  
    
## getKeyboardDelegate<sup>(9+)</sup>    
获取客户端编辑事件监听代理实例[KeyboardDelegate](#keyboarddelegate)。  
输入法应用获取该实例后，可订阅物理键盘按键事件、选中文本变化事件等。  
 **调用形式：**     
- getKeyboardDelegate(): KeyboardDelegate  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| KeyboardDelegate | 客户端编辑事件监听代理。 |  
    
 **示例代码：**   
```ts    
let KeyboardDelegate = inputMethodEngine.getKeyboardDelegate();    
```    
  
    
## createKeyboardDelegate<sup>(deprecated)</sup>    
获取客户端编辑事件监听代理实例[KeyboardDelegate](#keyboarddelegate)。输入法应用获取该实例后，可订阅物理键盘按键事件、选中文本变化事件等。  
 **调用形式：**     
- createKeyboardDelegate(): KeyboardDelegate  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine#getKeyboardDelegate。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| KeyboardDelegate | 客户端编辑事件监听代理。 |  
    
 **示例代码：**   
```ts    
let keyboardDelegate = inputMethodEngine.createKeyboardDelegate();    
```    
  
    
## KeyboardController    
下列API均需使用[on('inputStart')](#oninputstart9)获取到KeyboardController实例后，通过实例调用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### hide<sup>(9+)</sup>    
隐藏输入法。使用异步回调。  
 **调用形式：**     
    
- hide(callback: AsyncCallback\<void>): void    
起始版本： 9    
- hide(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当输入法隐藏成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
panel.hide((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to hide panel: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in hiding the panel.');  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
try {  
  panel.on('show', () => {  
    console.log('Panel is showing.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to show: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### hideKeyboard<sup>(deprecated)</sup>    
隐藏输入法。使用callback异步回调。  
 **调用形式：**     
- hideKeyboard(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.KeyboardController#hide。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当输入法隐藏成功，err为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
keyboardController.hideKeyboard((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to hideKeyboard: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in hiding keyboard.');  
});    
```    
  
    
### hideKeyboard<sup>(deprecated)</sup>    
隐藏输入法。使用promise异步回调。  
 **调用形式：**     
- hideKeyboard(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.KeyboardController#hide。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
keyboardController.hideKeyboard().then(() => {  
  console.log('Succeeded in hiding keyboard.');  
}).catch((err: BusinessError) => {  
  console.log(`Failed to hideKeyboard: ${JSON.stringify(err)}`);  
});    
```    
  
    
## InputMethodEngine    
下列API均需使用[getInputMethodEngine](#inputmethodenginegetinputmethodenginedeprecated)获取到InputMethodEngine实例后，通过实例调用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### on('inputStart')    
订阅输入法绑定成功事件。使用callback异步回调。  
 **调用形式：**     
    
- on(       type: 'inputStart',       callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void     ): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'inputStart'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回订阅输入法的KeyboardController和TextInputClient实例。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodEngine()  
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, textClient: inputMethodEngine.TextInputClient) => {  
      let keyboardController = kbController;  
      let textInputClient = textClient;  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to inputStart: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('inputStart')    
取消订阅输入法绑定成功事件。  
 **调用形式：**     
    
- off(       type: 'inputStart',       callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void     ): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'inputStart'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodEngine()  
    .off('inputStart', (kbController: inputMethodEngine.KeyboardController, textClient: inputMethodEngine.TextInputClient) => {  
      console.log('delete inputStart notification.');  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to inputStart: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('keyboardShow' | 'keyboardHide')    
订阅输入法软键盘显示或隐藏事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'keyboardShow' | 'keyboardHide', callback: () => void): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型。<br/>-'keyboardShow'表示显示输入法软键盘。<br/>-'keyboardHide'表示隐藏输入法软键盘。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodEngine().on('keyboardShow', () => {  
    console.log('inputMethodEngine keyboardShow.');  
  });  
  inputMethodEngine.getInputMethodEngine().on('keyboardHide', () => {  
    console.log('inputMethodEngine keyboardHide.');  
});  
} catch(err: BusinessError) {  
  console.error(`Failed to InputMethodEngine: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('keyboardShow' | 'keyboardHide')    
取消订阅输入法软键盘显示或隐藏事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'keyboardShow' | 'keyboardHide', callback?: () => void): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要取消监听的输入法软键盘类型。<br/>-'keyboardShow'表示显示输入法软键盘。<br/>-'keyboardHide'表示隐藏输入法软键盘。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
inputMethodEngine.getInputMethodEngine().off('keyboardShow');  
inputMethodEngine.getInputMethodEngine().off('keyboardHide');    
```    
  
    
## InputMethodAbility<sup>(9+)</sup>    
下列API均需使用[getInputMethodAbility](#inputmethodenginegetinputmethodability9)获取到InputMethodAbility实例后，通过实例调用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### on('inputStart')<sup>(9+)</sup>    
订阅输入法绑定成功事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'inputStart'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回输入法操作相关实例。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility()  
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, client: inputMethodEngine.InputClient) => {  
      let keyboardController = kbController;  
      let inputClient = client;  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to InputMethodAbility: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('inputStart')<sup>(9+)</sup>    
取消订阅输入法绑定成功事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'inputStart'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
inputMethodEngine.getInputMethodAbility().off('inputStart');    
```    
  
    
### on('inputStop')<sup>(9+)</sup>    
订阅停止输入法应用事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'inputStop', callback: () => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'inputStop'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility().on('inputStop', () => {  
    console.log('inputMethodAbility inputStop');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to inputStop: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('inputStop')<sup>(9+)</sup>    
取消订阅停止输入法应用事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'inputStop', callback: () => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'inputStop'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility().off('inputStop', () => {  
    console.log('inputMethodAbility delete inputStop notification.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to inputStop: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('setCallingWindow')<sup>(9+)</sup>    
订阅设置调用窗口事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'setCallingWindow', callback: (wid: number) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'setCallingWindow'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回调用方窗口的Id。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility().on('setCallingWindow', (wid: number) => {  
    console.log('inputMethodAbility setCallingWindow');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('setCallingWindow')<sup>(9+)</sup>    
取消订阅设置调用窗口事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'setCallingWindow', callback: (wid: number) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'setCallingWindow'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility().off('setCallingWindow', (wid: number) => {  
    console.log('inputMethodAbility delete setCallingWindow notification.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('keyboardShow' | 'keyboardHide')<sup>(9+)</sup>    
订阅输入法软键盘显示或隐藏事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'keyboardShow' | 'keyboardHide', callback: () => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型。<br/>- 'keyboardShow'表示显示输入法软键盘。<br/>- 'keyboardHide'表示隐藏输入法软键盘。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility().on('keyboardShow', () => {  
    console.log('InputMethodAbility keyboardShow.');  
  });  
  inputMethodEngine.getInputMethodAbility().on('keyboardHide', () => {  
    console.log('InputMethodAbility keyboardHide.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to keyboard: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('keyboardShow' | 'keyboardHide')<sup>(9+)</sup>    
取消订阅输入法事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'keyboardShow' | 'keyboardHide', callback?: () => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型。<br/>- 'keyboardShow'表示显示键盘。<br/>- 'keyboardHide'表示隐藏键盘。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility().off('keyboardShow', () => {  
    console.log('InputMethodAbility delete keyboardShow notification.');  
  });  
  inputMethodEngine.getInputMethodAbility().off('keyboardHide', () => {  
    console.log('InputMethodAbility delete keyboardHide notification.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to keyboard: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('setSubtype')<sup>(9+)</sup>    
订阅设置输入法子类型事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'setSubtype'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回设置的输入法子类型。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility().on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {  
    console.log('InputMethodAbility setSubtype.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to setSubtype: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('setSubtype')<sup>(9+)</sup>    
取消订阅输入法软键盘显示或隐藏事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'setSubtype'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getInputMethodAbility().off('setSubtype', () => {  
    console.log('InputMethodAbility delete setSubtype notification.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to setSubtype: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### createPanel<sup>(10+)</sup>    
创建输入法面板，仅支持输入法应用调用。使用异步回调。  
单个输入法应用仅允许创建一个[软键盘类型](#paneltype10)和[状态栏类型](#paneltype10)的面板。  
 **调用形式：**     
    
- createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void    
起始版本： 10    
- createPanel(ctx: BaseContext, info: PanelInfo): Promise\<Panel>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ctx | BaseContext | true | 当前输入法应用上下文信息。 |  
| info | PanelInfo | true | 输入法应用信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当输入法面板创建成功，返回当前创建的输入法面板对象。 |  
| Promise<Panel> | 回调函数。当输入法面板创建成功，返回当前创建的输入法面板对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800004 | not an input method extension. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to createPanel: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
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
  
    
### destroyPanel<sup>(10+)</sup>    
销毁输入法面板。使用异步回调。  
 **调用形式：**     
    
- destroyPanel(panel: Panel, callback: AsyncCallback\<void>): void    
起始版本： 10    
- destroyPanel(panel: Panel): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| panel | Panel | true | 要销毁的面板对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当输入法面板销毁成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
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
} catch (err: BusinessError) {  
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
} catch (err: BusinessError) {  
  console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
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
} catch (err: BusinessError) {  
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
} catch (err: BusinessError) {  
  console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
## TextInputClient<sup>(deprecated)</sup>    
下列API示例中都需使用[on('inputStart')](#oninputstart)回调获取到TextInputClient实例，再通过此实例调用对应方法。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用inputMethodEngine#InputClient替代。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### sendKeyFunction<sup>(deprecated)</sup>    
发送功能键。使用callback异步回调。  
 **调用形式：**     
- sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#sendKeyFunction。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| action<sup>(deprecated)</sup> | number | true | 功能键键值。<br/>- 当值为0时，表示无效按键；<br/>- 当值为1时，表示确认键（即回车键）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当功能键发送成功，err为undefined，data为true；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### sendKeyFunction<sup>(deprecated)</sup>    
发送功能键。使用promise异步回调。  
 **调用形式：**     
- sendKeyFunction(action: number): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#sendKeyFunction。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| action<sup>(deprecated)</sup> | number | true | 功能键键值。<br/>当值为0时，表示无效按键；<br/>当值为1时，表示确认键（即回车键）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示发送功能键成功；返回false表示发送功能键失败。 |  
    
 **示例代码：**   
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### deleteForward<sup>(deprecated)</sup>    
删除光标前固定长度的文本。使用callback异步回调。  
 **调用形式：**     
- deleteForward(length: number, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#deleteForward。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | true | 文本长度。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当光标前固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### deleteForward<sup>(deprecated)</sup>    
删除光标前固定长度的文本。使用promise异步回调。  
 **调用形式：**     
- deleteForward(length: number): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#deleteForward。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示删除光标前固定长度的文本成功；返回false表示删除光标前固定长度的文本失败。 |  
    
 **示例代码：**   
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### deleteBackward<sup>(deprecated)</sup>    
删除光标后固定长度的文本。使用callback异步回调。  
 **调用形式：**     
- deleteBackward(length: number, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#deleteBackward。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | true | 文本长度。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当光标后固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
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
} catch (err: BusinessError) {  
  console.error('deleteBackward err: ' + JSON.stringify(err));  
}  
    
```    
  
    
### deleteBackward<sup>(deprecated)</sup>    
删除光标后固定长度的文本。使用promise异步回调。  
 **调用形式：**     
- deleteBackward(length: number): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#deleteBackward。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示删除光标后固定长度的文本成功；返回false表示删除光标后固定长度的文本失败。 |  
    
 **示例代码：**   
```ts    
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
  
    
### insertText<sup>(deprecated)</sup>    
插入文本。使用callback异步回调。  
 **调用形式：**     
- insertText(text: string, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#insertText。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text<sup>(deprecated)</sup> | string | true | 文本内容。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当文本插入成功，err为undefined，data为true；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
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
  
    
### insertText<sup>(deprecated)</sup>    
插入文本。使用promise异步回调。  
 **调用形式：**     
- insertText(text: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#insertText。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text<sup>(deprecated)</sup> | string | true | 文本。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示插入文本成功；返回false表示插入文本失败。 |  
    
 **示例代码：**   
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to insertText: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getForward<sup>(deprecated)</sup>    
获取光标前固定长度的文本。使用callback异步回调。  
 **调用形式：**     
- getForward(length: number, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#getForward。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | true | 文本长度。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。当光标前固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
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
获取光标前固定长度的文本。使用promise异步回调。  
 **调用形式：**     
- getForward(length: number): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#getForward。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回光标前固定长度的文本。 |  
    
 **示例代码：**   
```ts    
let length = 1;  
textInputClient.getForward(length).then((text: string) => {  
  console.log('Succeeded in getting forward, text: ' + text);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);  
});    
```    
  
    
### getBackward<sup>(deprecated)</sup>    
获取光标后固定长度的文本。使用callback异步回调。  
 **调用形式：**     
- getBackward(length: number, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#getBackward。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | true | 文本长度。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。当光标后固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
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
 **调用形式：**     
- getBackward(length: number): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#getBackward。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回光标后固定长度的文本。 |  
    
 **示例代码：**   
```ts    
let length = 1;  
textInputClient.getBackward(length).then((text: string) => {  
  console.log('Succeeded in getting backward: ' + JSON.stringify(text));  
}).catch((err: BusinessError) => {  
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);  
});    
```    
  
    
### getEditorAttribute<sup>(deprecated)</sup>    
获取编辑框属性值。使用callback异步回调。  
 **调用形式：**     
- getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#getEditorAttribute。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<EditorAttribute> | true | 回调函数。当编辑框的属性值获取成功，err为undefined，data为编辑框属性值；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
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
获取编辑框属性值。使用promise异步回调。  
 **调用形式：**     
- getEditorAttribute(): Promise\<EditorAttribute>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethodEngine.InputClient#getEditorAttribute。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<EditorAttribute> | Promise对象，返回编辑框属性值。 |  
    
 **示例代码：**   
```ts    
textInputClient.getEditorAttribute().then((editorAttribute: inputMethodEngine.EditorAttribute) => {  
  console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));  
  console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));  
}).catch((err: BusinessError) => {  
  console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);  
});    
```    
  
    
## InputClient<sup>(9+)</sup>    
下列API均需使用[on('inputStart')](#oninputstart9)获取到InputClient实例后，通过实例调用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### sendKeyFunction<sup>(9+)</sup>    
发送功能键。使用异步回调。  
 **调用形式：**     
    
- sendKeyFunction(action: number, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- sendKeyFunction(action: number): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| action | number | true | 功能键键值。<br/>- 当值为0时，表示无效按键。<br/>- 当值为1时，表示确认键（即回车键）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当功能键发送成功，err为undefined，data为true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示功能键发送成功；返回false表示功能键发送失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### deleteForward<sup>(9+)</sup>    
删除光标前固定长度的文本。使用异步回调。  
 **调用形式：**     
    
- deleteForward(length: number, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- deleteForward(length: number): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当光标前固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示删除光标前固定长度的文本成功；返回false表示删除光标前固定长度的文本失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800002 | Input method engine error. |  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### deleteForwardSync<sup>(10+)</sup>    
删除光标前固定长度的文本。  
 **调用形式：**     
- deleteForwardSync(length: number): void  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length | number | true | 文本长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800002 | input method engine error. |  
| 12800003 | input method client error. |  
    
 **示例代码：**   
```ts    
let length = 1;  
try {  
  inputClient.deleteForwardSync(length);  
  console.log('Succeeded in deleting forward.');  
} catch (err: BusinessError) {  
  console.error('deleteForwardSync err: ' + JSON.stringify(err));  
}  
    
```    
  
    
### deleteBackward<sup>(9+)</sup>    
删除光标后固定长度的文本。使用异步回调。  
 **调用形式：**     
    
- deleteBackward(length: number, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- deleteBackward(length: number): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当光标后固定长度的文本删除成功，err为undefined，data为true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示删除光标后固定长度的文本成功；返回false表示删除光标后固定长度的文本失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800002 | Input method engine error. |  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
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
} catch (err: BusinessError) {  
  console.error('deleteBackward err: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
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
  
    
### deleteBackwardSync<sup>(10+)</sup>    
删除光标后固定长度的文本。  
 **调用形式：**     
- deleteBackwardSync(length: number): void  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length | number | true | 文本长度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800002 | input method engine error. |  
| 12800003 | input method client error. |  
    
 **示例代码：**   
```ts    
let length = 1;  
try {  
  inputClient.deleteBackwardSync(length);  
  console.log('Succeeded in deleting backward.');  
} catch (err: BusinessError) {  
  console.error('deleteBackwardSync err: ' + JSON.stringify(err));  
}  
    
```    
  
    
### insertText<sup>(9+)</sup>    
插入文本。使用异步回调。  
 **调用形式：**     
    
- insertText(text: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- insertText(text: string): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 文本内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当文本插入成功，err为undefined，data为true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示插入文本成功；返回false表示插入文本失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800002 | Input method engine error. |  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to insertText: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### insertTextSync<sup>(10+)</sup>    
插入文本。  
 **调用形式：**     
- insertTextSync(text: string): void  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 文本内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800002 | input method engine error. |  
| 12800003 | input method client error. |  
    
 **示例代码：**   
```ts    
try {  
  inputClient.insertTextSync('test');  
  console.log('Succeeded in inserting text.');  
} catch (err: BusinessError) {  
  console.error(`Failed to insertTextSync: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getForward<sup>(9+)</sup>    
获取光标前固定长度的文本。使用异步回调。  
 **调用形式：**     
    
- getForward(length: number, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getForward(length: number): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当光标前固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |  
| Promise<string> | Promise对象，返回光标前固定长度的文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800006 | Input method controller error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
let length = 1;  
try {  
  inputClient.getForward(length, (err: BusinessError, text: string) => {  
    if (err) {  
      console.error(`Failed to getForward: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in getting forward, text: ' + text);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let length = 1;  
try {  
  inputClient.getForward(length).then((text: string) => {  
    console.log('Succeeded in getting forward, text: ' + text);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to getForward: ${JSON.stringify(err)}`);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getForwardSync<sup>(10+)</sup>    
获取光标前固定长度的文本。  
 **调用形式：**     
- getForwardSync(length: number): string  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回光标前固定长度的文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800006 | input method controller error. |  
    
 **示例代码：**   
```ts    
let length = 1;  
try {  
  let text: string = inputClient.getForwardSync(length);  
  console.log(`Succeeded in getting forward, text: ${text}`);  
} catch (err: BusinessError) {  
  console.error(`Failed to getForwardSync: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getBackward<sup>(9+)</sup>    
获取光标后固定长度的文本。使用异步回调。  
 **调用形式：**     
    
- getBackward(length: number, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getBackward(length: number): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当光标后固定长度的文本获取成功，err为undefined，data为获取到的文本；否则为错误对象。 |  
| Promise<string> | Promise对象，返回光标后固定长度的文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800006 | Input method controller error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
let length = 1;  
try {  
  inputClient.getBackward(length, (err: BusinessError, text: string) => {  
    if (err) {  
      console.error(`Failed to getBackward: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in getting backward, text: ' + text);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let length = 1;  
try {  
  inputClient.getBackward(length).then((text: string) => {  
    console.log('Succeeded in getting backward, text: ' + text);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to getBackward: ${JSON.stringify(err)}`);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getBackwardSync<sup>(10+)</sup>    
获取光标后固定长度的文本。  
 **调用形式：**     
- getBackwardSync(length: number): string  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| length | number | true | 文本长度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回光标后固定长度的文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800006 | input method controller error. |  
    
 **示例代码：**   
```ts    
let length = 1;  
try {  
  let text: string = inputClient.getBackwardSync(length);  
  console.log(`Succeeded in getting backward, text: ${text}`);  
} catch (err: BusinessError) {  
  console.error(`Failed to getBackwardSync: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getEditorAttribute<sup>(9+)</sup>    
获取编辑框属性值。使用异步回调。  
 **调用形式：**     
    
- getEditorAttribute(callback: AsyncCallback\<EditorAttribute>): void    
起始版本： 9    
- getEditorAttribute(): Promise\<EditorAttribute>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当编辑框属性值获取成功，err为undefined，data为编辑框属性值；否则为错误对象。 |  
| Promise<EditorAttribute> | Promise对象，返回编辑框属性值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
inputClient.getEditorAttribute((err: BusinessError, editorAttribute: inputMethodEngine.EditorAttribute) => {  
  if (err) {  
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));  
  console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
try {  
  inputClient.getEditorAttribute().then((editorAttribute: inputMethodEngine.EditorAttribute) => {  
    console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));  
    console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getEditorAttributeSync<sup>(10+)</sup>    
获取编辑框属性值。  
 **调用形式：**     
- getEditorAttributeSync(): EditorAttribute  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| EditorAttribute | 编辑框属性对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
    
 **示例代码：**   
```ts    
try {  
  let editorAttribute: inputMethodEngine.EditorAttribute = inputClient.getEditorAttributeSync();  
  console.log(`Succeeded in getEditorAttributeSync, editorAttribute = ${JSON.stringify(editorAttribute)}`);  
} catch (err: BusinessError) {  
  console.error(`Failed to getEditorAttributeSync: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### moveCursor<sup>(9+)</sup>    
移动光标。使用异步回调。  
 **调用形式：**     
    
- moveCursor(direction: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- moveCursor(direction: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| direction | number | true | 光标移动方向。<br/>- 当值为1时，表示向上。<br/>- 当值为2时，表示向下。<br/>- 当值为3时，表示向左。<br/>- 当值为4时，表示向右。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当光标移动成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
try {  
  inputClient.moveCursor(inputMethodEngine.Direction.CURSOR_UP, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in moving cursor.');  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
try {  
  inputClient.moveCursor(inputMethodEngine.Direction.CURSOR_UP).then(() => {  
    console.log('Succeeded in moving cursor.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### moveCursorSync<sup>(10+)</sup>    
移动光标。  
 **调用形式：**     
- moveCursorSync(direction: number): void  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| direction | number | true | 光标移动方向。<br/>- 当值为1时，表示向上。<br/>- 当值为2时，表示向下。<br/>- 当值为3时，表示向左。<br/>- 当值为4时，表示向右。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
    
 **示例代码：**   
```ts    
try {  
  inputClient.moveCursorSync(inputMethodEngine.Direction.CURSOR_UP);  
  console.log('Succeeded in moving cursor.');  
} catch (err: BusinessError) {  
  console.error(`Failed to moveCursorSync: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### selectByRange<sup>(10+)</sup>    
根据索引范围选中文本。使用异步回调。  
 **调用形式：**     
    
- selectByRange(range: Range, callback: AsyncCallback\<void>): void    
起始版本： 10    
- selectByRange(range: Range): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| range | Range | true | 选中文本的范围。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功发送选中事件后，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | parameter error. |  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
try {  
  let range: inputMethodEngine.Range = { start: 0, end: 1 };  
  inputClient.selectByRange(range, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in selecting by range.');  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
try {  
  let range: inputMethodEngine.Range = { start: 0, end: 1 };  
  inputClient.selectByRange(range).then(() => {  
    console.log('Succeeded in selecting by range.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### selectByRangeSync<sup>(10+)</sup>    
根据索引范围选中文本。  
 **调用形式：**     
- selectByRangeSync(range: Range): void  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| range | Range | true | 选中文本的范围。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | parameter error. |  
| 12800003 | input method client error. |  
    
 **示例代码：**   
```ts    
try {  
  let range: inputMethodEngine.Range = { start: 0, end: 1 };  
  inputClient.selectByRangeSync(range);  
  console.log('Succeeded in selecting by range.');  
} catch (err: BusinessError) {  
  console.error(`Failed to selectByRangeSync: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### selectByMovement<sup>(10+)</sup>    
根据光标移动方向选中文本。使用异步回调。  
 **调用形式：**     
    
- selectByMovement(movement: Movement, callback: AsyncCallback\<void>): void    
起始版本： 10    
- selectByMovement(movement: Movement): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| movement | Movement | true | 选中时光标移动的方向。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功发送选中事件后，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | parameter error. |  
| 12800003 | input method client error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
try {  
  let movement: inputMethodEngine.Movement = { direction: 1 };  
  inputClient.selectByMovement(movement, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in selecting by movement.');  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
try {  
  let movement: inputMethodEngine.Movement = { direction: 1 };  
  inputClient.selectByMovement(movement).then(() => {  
    console.log('Succeeded in selecting by movement.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### selectByMovementSync<sup>(10+)</sup>    
根据光标移动方向选中文本。  
 **调用形式：**     
- selectByMovementSync(movement: Movement): void  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| movement | Movement | true | 选中时光标移动的方向。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | parameter error. |  
| 12800003 | input method client error. |  
    
 **示例代码：**   
```ts    
try {  
  let movement: inputMethodEngine.Movement = { direction: 1 };    
  inputClient.selectByMovementSync(movement);  
  console.log('Succeeded in selecting by movement.');  
} catch (err: BusinessError) {  
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getTextIndexAtCursor<sup>(10+)</sup>    
获取光标所在处的文本索引。使用异步回调。  
 **调用形式：**     
    
- getTextIndexAtCursor(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getTextIndexAtCursor(): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当文本索引获取成功，err为undefined，否则为错误对象。 |  
| Promise<number> | Promise对象，返回光标所在处的文本索引。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
| 12800006 | Input method controller error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
inputClient.getTextIndexAtCursor((err: BusinessError, index: number) => {  
  if (err) {  
    console.error(`Failed to getTextIndexAtCursor: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in getTextIndexAtCursor: ' + index);  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
inputClient.getTextIndexAtCursor().then((index: number) => {  
  console.log('Succeeded in getTextIndexAtCursor: ' + index);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to getTextIndexAtCursor: ${JSON.stringify(err)}`);  
});    
```    
  
    
### getTextIndexAtCursorSync<sup>(10+)</sup>    
获取光标所在处的文本索引。  
 **调用形式：**     
- getTextIndexAtCursorSync(): number  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回光标所在处的文本索引。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
| 12800006 | Input method controller error. |  
    
 **示例代码：**   
```ts    
try{  
  let index: number = inputClient.getTextIndexAtCursorSync();  
  console.log(`Succeeded in getTextIndexAtCursorSync, index: ${index}`);  
} catch (err: BusinessError) {  
  console.error(`Failed to getTextIndexAtCursorSync: ${JSON.stringify(err)}`);  
}    
```    
  
    
### sendExtendAction<sup>(10+)</sup>    
发送扩展编辑操作。使用异步回调。  
 **调用形式：**     
    
- sendExtendAction(action: ExtendAction, callback: AsyncCallback\<void>): void    
起始版本： 10    
- sendExtendAction(action: ExtendAction): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| action | ExtendAction | true | 要发送的扩展操作。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。发送成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800006 | Input method controller error. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
try {  
  inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in sending extend action.');  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
try {  
  inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY).then(() => {  
    console.log('Succeeded in sending extend action.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
## KeyboardDelegate    
下列API均需使用[getKeyboardDelegate](#inputmethodenginegetkeyboarddelegate9)获取到KeyboardDelegate实例后，通过实例调用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### on('keyDown' | 'keyUp')    
订阅硬键盘（即物理键盘）上物理按键的按下或抬起事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'keyDown' | 'keyUp', callback: (event: KeyEvent) => boolean): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型。<br/>- 'keyDown'表示键盘按下。<br/>- 'keyUp'表示键盘抬起。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回按键信息。 |  
    
 **示例代码：**   
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
} catch(err: BusinessError) {  
    console.error(`Failed to KeyboardDelegate: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('keyDown' | 'keyUp')    
取消订阅硬键盘（即物理键盘）上物理按键的按下或抬起事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'keyDown' | 'keyUp', callback?: (event: KeyEvent) => boolean): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型。<br/>- 'keyDown'表示键盘按下。<br/>- 'keyUp'表示键盘抬起。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
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
} catch(err: BusinessError) {  
    console.error(`Failed to keyevent: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('keyEvent')<sup>(10+)</sup>    
订阅硬键盘（即物理键盘）事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'keyEvent', callback: (event: InputKeyEvent) => boolean): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'keyEvent'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，入参为按键事件信息，返回值类型为布尔类型。<br/>-入参按键事件信息的数据类型为[InputKeyEvent](js-apis-keyevent.md#KeyEvent)。<br/>-若按键事件被事件订阅者消费，则callback应返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
import type { KeyEvent } from '@ohos.multimodalInput.keyEvent';  
  
try {  
  inputMethodEngine.getKeyboardDelegate().on('keyEvent', (keyEvent: KeyEvent) => {  
    console.log('inputMethodEngine keyEvent.action:' + JSON.stringify(keyEvent.action));  
    console.log('inputMethodEngine keyEvent.key.code:' + JSON.stringify(keyEvent.key.code));  
    console.log('inputMethodEngine keyEvent.ctrlKey:' + JSON.stringify(keyEvent.ctrlKey));  
    return true;  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to inputMethodEngine: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('keyEvent')<sup>(10+)</sup>    
取消订阅硬键盘（即物理键盘）事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'keyEvent', callback?: (event: InputKeyEvent) => boolean): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'keyEvent'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
import type { KeyEvent } from '@ohos.multimodalInput.keyEvent';  
  
try {  
  inputMethodEngine.getKeyboardDelegate().off('keyEvent', (keyEvent: KeyEvent) => {  
    console.log('This is a callback function which will be deregistered.');  
    return true;  
  });  
  inputMethodEngine.getKeyboardDelegate().off('keyEvent');  
} catch(err: BusinessError) {  
    console.error(`Failed to keyEvent: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('cursorContextChange')    
订阅光标变化事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'cursorContextChange', callback: (x: number, y: number, height: number) => void): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 光标变化事件，固定取值为'cursorContextChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回光标信息。<br/>-x为光标上端的的x坐标值，y为光标上端的y坐标值，height为光标的高度值。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getKeyboardDelegate().on('cursorContextChange', (x: number, y: number, height: number) => {  
    console.log('inputMethodEngine cursorContextChange x:' + x);  
    console.log('inputMethodEngine cursorContextChange y:' + y);  
    console.log('inputMethodEngine cursorContextChange height:' + height);  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to cursorContextChange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('cursorContextChange')    
取消订阅光标变化事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 光标变化事件，固定取值为'cursorContextChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getKeyboardDelegate().off('cursorContextChange', (x: number, y: number, height: number) => {  
    console.log('delete cursorContextChange notification.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to cursorContextChange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('selectionChange')    
订阅文本选择范围变化事件。使用callback异步回调。  
 **调用形式：**     
    
- on(       type: 'selectionChange',       callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void     ): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 文本选择变化事件，固定取值为'selectionChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回文本选择信息。<br/>- oldBegin为变化前被选中文本的起始下标，oldEnd为变化前被选中文本的终止下标。<br/>- newBegin为变化后被选中文本的起始下标，newEnd为变化后被选中文本的终止下标。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getKeyboardDelegate()  
    .on('selectionChange', (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => {  
      console.log('inputMethodEngine beforeEach selectionChange oldBegin:' + oldBegin);  
      console.log('inputMethodEngine beforeEach selectionChange oldEnd:' + oldEnd);  
      console.log('inputMethodEngine beforeEach selectionChange newBegin:' + newBegin);  
      console.log('inputMethodEngine beforeEach selectionChange newEnd:' + newEnd);  
    });  
} catch(err: BusinessError) {  
    console.error(`Failed to selectionChange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('selectionChange')    
取消订阅文本选择范围变化事件。使用callback异步回调。  
 **调用形式：**     
    
- off(       type: 'selectionChange',       callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void     ): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 文本选择变化事件，固定取值为'selectionChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getKeyboardDelegate()  
    .off('selectionChange', (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number)  => {  
      console.log('delete selectionChange notification.');  
    });  
} catch(err: BusinessError) {  
    console.error(`Failed to selectionChange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('textChange')    
订阅文本内容变化事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'textChange', callback: (text: string) => void): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 文本变化事件，固定取值为'textChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回订阅的文本内容。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getKeyboardDelegate().on('textChange', (text: string) => {  
    console.log('inputMethodEngine textChange. text:' + text);  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('textChange')    
取消订阅文本内容变化事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'textChange', callback?: (text: string) => void): void    
起始版本： 8  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 文本变化事件，固定取值为'textChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getKeyboardDelegate().off('textChange', (text: string) => {  
    console.log('delete textChange notification. text:' + text);  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('editorAttributeChanged')<sup>(10+)</sup>    
订阅编辑框属性变化事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'editorAttributeChanged', callback: (attr: EditorAttribute) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 文本变化事件，固定取值为'editorAttributeChanged'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回变化的编辑框属性。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodEngine.getKeyboardDelegate().on('editorAttributeChanged', (attr: inputMethodEngine.EditorAttribute) => {  
    console.log(`Succeeded in receiving attribute of editor, inputPattern = ${attr.inputPattern}, enterKeyType = ${attr.enterKeyType}`);  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('editorAttributeChanged')<sup>(10+)</sup>    
取消订阅编辑框属性变化事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'editorAttributeChanged', callback?: (attr: EditorAttribute) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 文本变化事件，固定取值为'editorAttributeChanged'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 所要取消订阅的回调处理函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
inputMethodEngine.getKeyboardDelegate().off('editorAttributeChanged');    
```    
  
    
## Panel<sup>(10+)</sup>    
下列API均需使用[createPanel](#createpanel10)获取到Panel实例后，通过实例调用。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### setUiContent<sup>(10+)</sup>    
为当前的输入法面板加载具体页面内容，使用异步回调。  
 **调用形式：**     
    
- setUiContent(path: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setUiContent(path: string): Promise\<void>    
起始版本： 10    
- setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setUiContent(path: string, storage: LocalStorage): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| path | string | true | 具体页面的路径。 |  
| storage | LocalStorage | true | 存储单元，为应用程序范围内的可变和不可变状态属性提供存储。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当面板页面内容加载成功，err为undefined，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
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
} catch (err: BusinessError) {  
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
let storage = new LocalStorage();  
storage.setOrCreate('storageSimpleProp',121);  
try {  
  panel.setUiContent('pages/page2/page2')then(() => {  
    console.log('Succeeded in setting the content.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### resize<sup>(10+)</sup>    
改变当前输入法面板的大小，使用异步回调。  
 **调用形式：**     
    
- resize(width: number, height: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- resize(width: number, height: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| width | number | true | 目标面板的宽度，单位为px。 |  
| height | number | true | 目标面板的高度，单位为px。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当面板大小改变成功，err为undefined，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
try {  
  panel.resize(500, 1000, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to resize panel: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in changing the panel size.');  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to resize panel: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
try {  
  panel.resize(500, 1000).then(() => {  
    console.log('Succeeded in changing the panel size.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to resize panel: ${JSON.stringify(err)}`);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to resize panel: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### moveTo<sup>(10+)</sup>    
移动面板位置，使用异步回调。[面板状态](#panelflag10)为固定态时，不产生实际移动效果。  
 **调用形式：**     
    
- moveTo(x: number, y: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- moveTo(x: number, y: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number | true | x轴方向移动的值，值大于0表示右移，单位为px。 |  
| y | number | true | y轴方向移动的值，值大于0表示下移，单位为px。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当面板位置移动成功，err为undefined，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
try {  
  panel.moveTo(300, 300, (err: BusinessError) =>{  
    if (err) {  
      console.error(`Failed to move panel: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in moving the panel.');  
  });  
} catch (err: BusinessError) {  
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
try {  
  panel.moveTo(300, 300).then(() => {  
    console.log('Succeeded in moving the panel.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to move panel: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### show<sup>(10+)</sup>    
显示当前输入法面板，使用异步回调。  
 **调用形式：**     
    
- show(callback: AsyncCallback\<void>): void    
起始版本： 10    
- show(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当面板显示成功，err为undefined，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
panel.show((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to show panel: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in showing the panel.');  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
panel.show().then(() => {  
  console.log('Succeeded in showing the panel.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to show panel: ${JSON.stringify(err)}`);  
});    
```    
  
    
### hide<sup>(10+)</sup>    
隐藏当前输入法面板，使用异步回调。  
 **调用形式：**     
    
- hide(callback: AsyncCallback\<void>): void    
起始版本： 10    
- hide(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当面板隐藏成功，err为undefined，否则err为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
panel.hide((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to hide panel: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in hiding the panel.');  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
panel.hide().then(() => {  
  console.log('Succeeded in hiding the panel.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to hide panel: ${JSON.stringify(err)}`);  
});    
```    
  
    
### on('show')<sup>(10+)</sup>    
监听当前面板显示状态，使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'show', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听当前面板的状态类型，固定取值为'show'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
```ts    
try {  
  panel.on('show', () => {  
    console.log('Panel is showing.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to show: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('show')<sup>(10+)</sup>    
取消监听当前输入法面板的隐藏状态，使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'show', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听当前面板的状态类型，固定取值为'show'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  panel.off('show');  
} catch(err: BusinessError) {  
    console.error(`Failed to show: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('hide')<sup>(10+)</sup>    
监听当前面板隐藏状态，使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'hide', callback: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听当前面板的状态类型，固定取值为'hide'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
 **示例代码：**   
```ts    
try {  
  panel.on('hide', () => {  
    console.log('Panel is hiding.');  
  });  
} catch(err: BusinessError) {  
    console.error(`Failed to hide: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('hide')<sup>(10+)</sup>    
取消监听当前面板隐藏状态，使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'hide', callback?: () => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 要取消监听的当前面板状态类型，固定取值为'hide'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  panel.off('hide');  
} catch(err: BusinessError) {  
    console.error(`Failed to hide: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### changeFlag<sup>(10+)</sup>    
将输入法应用的面板状态改变为固定态或者悬浮态，仅对[SOFT_KEYBOARD](#paneltype10)生效。  
 **调用形式：**     
- changeFlag(flag: PanelFlag): void  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| flag | PanelFlag | true | 目标面板状态类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let panelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;  
  panel.changeFlag(panelFlag);  
} catch(err: BusinessError) {  
    console.error(`Failed to panelFlag: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
## EditorAttribute    
编辑框属性值。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| inputPattern | number | true | true | 编辑框的文本属性。 |  
| enterKeyType | number | true | true | 编辑框的功能属性。 |  
    
## KeyEvent    
按键属性值。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| keyCode | number | true | true | 按键的键值。键码值说明参考[KeyCode](js-apis-keycode.md#keycode)。 |  
| keyAction | number | true | true | 按键事件类型。<br/>- 当值为2时，表示按下事件；<br/>- 当值为3时，表示抬起事件。 |  
    
## PanelFlag<sup>(10+)</sup>    
输入法面板状态类型枚举。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FLG_FIXED | 0 | 固定态面板类型。 |  
| FLG_FLOATING | 1 | 悬浮态面板类型。 |  
    
## PanelType<sup>(10+)</sup>    
输入法面板类型枚举。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SOFT_KEYBOARD | 0 | 软键盘类型。 |  
| STATUS_BAR | 1 | 状态栏类型。 |  
    
## PanelInfo<sup>(10+)</sup>    
输入法面板属性。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(10+)</sup> | PanelType | false | true | 面板的类型。 |  
| flag<sup>(10+)</sup> | PanelFlag | false | false | 面板的状态类型。 |  
    
## Direction<sup>(10+)</sup>    
光标的移动方向。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CURSOR_UP | 1 | 向上。 |  
| CURSOR_DOWN | 2 | 向下。 |  
| CURSOR_LEFT | 3 | 向左。 |  
| CURSOR_RIGHT | 4 | 向右。 |  
    
## Range<sup>(10+)</sup>    
选中的文本范围。  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| start<sup>(10+)</sup> | number | false | true | 选中文本的首字符在编辑框的索引值。 |  
| end<sup>(10+)</sup> | number | false | true | 选中文本的末字符在编辑框的索引值。 |  
    
## Movement<sup>(10+)</sup>    
选中文本时，光标移动的方向  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| direction<sup>(10+)</sup> | Direction | false | true | 选中文本时，光标的移动方向。 |  
    
## ExtendAction<sup>(10+)</sup>    
编辑框中文本的扩展编辑操作类型，如剪切、复制等。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SELECT_ALL | 0 | 全选。 |  
| CUT | 3 | 剪切。 |  
| COPY | 4 | 复制。 |  
| PASTE | 5 | 粘贴。 |  
