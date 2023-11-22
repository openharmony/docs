# @ohos.inputMethod    
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputMethod from '@ohos.inputMethod'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| MAX_TYPE_NUM<sup>(8+)</sup> | number |  | 可支持的最大输入法个数。 |  
    
## getInputMethodSetting<sup>(deprecated)</sup>    
获取客户端设置实例  
 **调用形式：**     
- getInputMethodSetting(): InputMethodSetting  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethod#getSetting。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputMethodSetting | 回调返回当前客户端设置实例。 |  
    
## getInputMethodController<sup>(deprecated)</sup>    
获取客户端实例  
 **调用形式：**     
- getInputMethodController(): InputMethodController  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethod#getController。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputMethodController | 回调返回当前客户端实例。 |  
    
## getSetting<sup>(9+)</sup>    
获取客户端设置实例。  
 **调用形式：**     
- getSetting(): InputMethodSetting  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputMethodSetting | 回调返回当前客户端设置实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800007 | settings extension error. |  
    
 **示例代码：**   
```ts    
let inputMethodSetting = inputMethod.getSetting();    
```    
  
    
## getController<sup>(9+)</sup>    
获取客户端实例。  
 **调用形式：**     
- getController(): InputMethodController  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputMethodController | 回调返回当前客户端实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800006 | input method controller error. |  
    
 **示例代码：**   
```ts    
let inputMethodController = inputMethod.getController();    
```    
  
    
## switchInputMethod<sup>(9+)</sup>    
切换输入法，仅系统应用可用。使用callback异步回调。  
 **调用形式：**     
    
- switchInputMethod(target: InputMethodProperty, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- switchInputMethod(target: InputMethodProperty): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework  
 **需要权限：** ohos.permission.CONNECT_IME_ABILITY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target | InputMethodProperty | true | 目标输入法。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当输入法切换成功，err为undefined，data为true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示切换输入法成功，返回false表示切换输入法失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12800005 | configuration persisting error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码：**   
```ts    
let currentIme = inputMethod.getCurrentInputMethod();  
try{  
  inputMethod.switchInputMethod(currentIme, (err: BusinessError, result: boolean) => {  
    if (err) {  
      console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);  
      return;  
    }  
    if (result) {  
      console.log('Succeeded in switching inputmethod.');  
    } else {  
      console.error('Failed to switchInputMethod.');  
    }  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
## getCurrentInputMethod<sup>(9+)</sup>    
使用同步方法获取当前输入法。  
 **调用形式：**     
- getCurrentInputMethod(): InputMethodProperty  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputMethodProperty | 返回当前输入法属性对象。 |  
    
 **示例代码：**   
```ts    
let currentIme = inputMethod.getCurrentInputMethod();    
```    
  
    
## switchCurrentInputMethodSubtype<sup>(9+)</sup>    
切换当前输入法的子类型。使用callback异步回调。  
 **调用形式：**     
    
- switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework  
 **需要权限：** ohos.permission.CONNECT_IME_ABILITY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| target | InputMethodSubtype | true | 目标输入法子类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当输入法子类型切换成功，err为undefined，data为true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示当前输入法切换子类型成功，返回false表示当前输入法切换子类型成功失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12800005 | configuration persisting error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  let extra: Record<string, string> = {}  
  inputMethod.switchCurrentInputMethodSubtype({  
    id: "ServiceExtAbility",  
    label: "",  
    name: "com.example.kikakeyboard",  
    mode: "upper",  
    locale: "",  
    language: "",  
    icon: "",  
    iconId: 0,  
    extra: extra  
  }, (err: BusinessError, result: boolean) => {  
    if (err) {  
      console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);  
      return;  
    }  
    if (result) {  
      console.log('Succeeded in switching currentInputMethodSubtype.');  
    } else {  
      console.error('Failed to switchCurrentInputMethodSubtype');  
    }  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
## getCurrentInputMethodSubtype<sup>(9+)</sup>    
获取当前输入法的子类型。  
 **调用形式：**     
- getCurrentInputMethodSubtype(): InputMethodSubtype  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| InputMethodSubtype | 返回当前输入法子类型对象。 |  
    
 **示例代码：**   
```ts    
let currentIme = inputMethod.getCurrentInputMethod();  
let imSubType = inputMethod.getCurrentInputMethodSubtype();  
try {  
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType, (err: BusinessError, result: boolean) => {  
    if (err) {  
      console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);  
      return;  
    }  
    if (result) {  
      console.log('Succeeded in switching currentInputMethodAndSubtype.');  
    } else {  
      console.error('Failed to switchCurrentInputMethodAndSubtype.');  
    }  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
## switchCurrentInputMethodAndSubtype<sup>(9+)</sup>    
切换至指定输入法的指定子类型，适用于跨输入法切换子类型。使用callback异步回调。  
 **调用形式：**     
    
- switchCurrentInputMethodAndSubtype(     inputMethodProperty: InputMethodProperty,     inputMethodSubtype: InputMethodSubtype,     callback: AsyncCallback\<boolean>   ): void    
起始版本： 9    
- switchCurrentInputMethodAndSubtype(     inputMethodProperty: InputMethodProperty,     inputMethodSubtype: InputMethodSubtype   ): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework  
 **需要权限：** ohos.permission.CONNECT_IME_ABILITY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inputMethodProperty | InputMethodProperty | true | 目标输入法。 |  
| inputMethodSubtype | InputMethodSubtype | true | 目标输入法子类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当输入法和子类型切换成功，err为undefined，data为获取到的切换子类型结果true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示切换至指定输入法的指定子类型成功，返回false表示切换至指定输入法的指定子类型失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12800005 | configuration persisting error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
let currentIme = inputMethod.getCurrentInputMethod();  
let imSubType = inputMethod.getCurrentInputMethodSubtype();  
try {  
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType).then((result: boolean) => {  
    if (result) {  
      console.log('Succeeded in switching currentInputMethodAndSubtype.');  
    } else {  
      console.error('Failed to switchCurrentInputMethodAndSubtype.');  
    }  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);  
  })  
} catch(err: BusinessError) {  
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
## InputMethodSetting<sup>(8+)</sup>    
获取客户端设置实例  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### on('imeChange')<sup>(9+)</sup>    
订阅输入法及子类型变化监听事件。使用callback异步回调。  
 **调用形式：**     
    
- on(       type: 'imeChange',       callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void     ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'imeChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回输入法属性对象及子类型对象。 |  
    
 **示例代码：**   
```ts    
try {  
  import InputMethodSubtype from '@ohos.InputMethodSubtype';  
  inputMethodSetting.on('imeChange', (inputMethodProperty: inputMethod.InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => {  
    console.log('Succeeded in subscribing imeChange: inputMethodProperty: ' + JSON.stringify(inputMethodProperty) + " , inputMethodSubtype: " + JSON.stringify(inputMethodSubtype));  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing inputMethodProperty. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('imeChange')<sup>(9+)</sup>    
取消订阅输入法及子类型变化监听事件。使用callback异步回调。  
 **调用形式：**     
    
- off(       type: 'imeChange',       callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void     ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'imeChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回取消订阅的输入法属性对象及子类型对象。 |  
    
 **示例代码：**   
```ts    
inputMethodSetting.off('imeChange');    
```    
  
    
### listInputMethodSubtype<sup>(9+)</sup>    
获取指定输入法应用的所有子类型。使用callback异步回调。  
 **调用形式：**     
    
- listInputMethodSubtype(       inputMethodProperty: InputMethodProperty,       callback: AsyncCallback\<Array\<InputMethodSubtype>>     ): void    
起始版本： 9    
- listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise\<Array\<InputMethodSubtype>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inputMethodProperty | InputMethodProperty | true | 输入法应用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回指定输入法应用的所有子类型。 |  
| Promise<Array<InputMethodSubtype>> | Promise对象，返回指定输入法应用的所有子类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800001 | package manager error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
import InputMethodSubtype from '@ohos.InputMethodSubtype';  
  
let inputMethodProperty: inputMethod.InputMethodProperty = {  
  name: 'InputMethodExAbility',  
  id: 'propertyId',  
}  
let inputMethodSetting = inputMethod.getSetting();  
try {  
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty, (err: BusinessError, data: Array<InputMethodSubtype>) => {  
    if (err) {  
      console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in listing inputMethodSubtype.');  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### listCurrentInputMethodSubtype<sup>(9+)</sup>    
查询当前输入法应用的所有子类型。使用callback异步回调。  
 **调用形式：**     
    
- listCurrentInputMethodSubtype(callback: AsyncCallback\<Array\<InputMethodSubtype>>): void    
起始版本： 9    
- listCurrentInputMethodSubtype(): Promise\<Array\<InputMethodSubtype>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回当前输入法应用的所有子类型。 |  
| Promise<Array<InputMethodSubtype>> | Promise对象，返回当前输入法应用的所有子类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800001 | package manager error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
import InputMethodSubtype from '@ohos.InputMethodSubtype';  
  
let inputMethodProperty: inputMethod.InputMethodProperty = {  
  name: 'InputMethodExAbility',  
  id: 'propertyId',  
}  
let inputMethodSetting = inputMethod.getSetting();  
try {  
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty).then((data: Array<InputMethodSubtype>) => {  
    console.log('Succeeded in listing inputMethodSubtype.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);  
  })  
} catch(err: BusinessError) {  
  console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### getInputMethods<sup>(9+)</sup>    
获取已激活/未激活的输入法应用列表。使用callback异步回调。  
 **调用形式：**     
    
- getInputMethods(enable: boolean, callback: AsyncCallback\<Array\<InputMethodProperty>>): void    
起始版本： 9    
- getInputMethods(enable: boolean): Promise\<Array\<InputMethodProperty>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | true表示返回已激活输入法列表，false表示返回未激活输入法列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回已激活/未激活输入法列表。 |  
| Promise<Array<InputMethodProperty>> | Promise对象，返回已激活/未激活输入法列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800001 | package manager error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码：**   
```ts    
  
try {  
  inputMethodSetting.getInputMethods(true, (err: BusinessError, data: Array<inputMethod.InputMethodProperty>) => {  
    if (err) {  
      console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in getting inputMethods.');  
  });  
} catch (err: BusinessError) {  
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### listInputMethod<sup>(deprecated)</sup>    
查询已安装的输入法列表。使用callback异步回调。  
 **调用形式：**     
- listInputMethod(callback: AsyncCallback\<Array\<InputMethodProperty>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethod.InputMethodSetting#getInputMethods。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<InputMethodProperty>> | true | 回调函数，返回已安装的输入法列表。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
inputMethodSetting.listInputMethod((err: BusinessError, data: Array<inputMethod.InputMethodProperty>) => {  
  if (err) {  
    console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in listing inputMethod.');  
 });    
```    
  
    
### listInputMethod<sup>(deprecated)</sup>  
 **调用形式：**     
- listInputMethod(): Promise\<Array\<InputMethodProperty>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethod.InputMethodSetting#getInputMethods。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<InputMethodProperty>> |  |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
inputMethodSetting.listInputMethod().then((data: Array<inputMethod.InputMethodProperty>) => {  
  console.log('Succeeded in listing inputMethod.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);  
})    
```    
  
    
### showOptionalInputMethods<sup>(9+)</sup>    
显示输入法选择对话框。使用callback异步回调。  
 **调用形式：**     
    
- showOptionalInputMethods(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- showOptionalInputMethods(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当输入法选择对话框显示成功，err为undefined，data为true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示输入法选择对话框显示成功，返回false表示输入法选择对话框显示失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800008 | input method manager service error. |  
    
 **示例代码：**   
```ts    
inputMethodSetting.showOptionalInputMethods().then((data: boolean) => {  
  console.log('Succeeded in showing optionalInputMethods.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);  
})    
```    
  
    
### displayOptionalInputMethod<sup>(deprecated)</sup>    
显示输入法选择对话框。使用callback异步回调。  
 **调用形式：**     
- displayOptionalInputMethod(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethod.InputMethodSetting#showOptionalInputMethods。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当输入法选择对话框显示成功。err为undefined，否则为错误对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
inputMethodSetting.displayOptionalInputMethod((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in displaying optionalInputMethod.');  
});    
```    
  
    
### displayOptionalInputMethod<sup>(deprecated)</sup>  
 **调用形式：**     
- displayOptionalInputMethod(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethod.InputMethodSetting#showOptionalInputMethods。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> |  |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
inputMethodSetting.displayOptionalInputMethod().then(() => {  
  console.log('Succeeded in displaying optionalInputMethod.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);  
})    
```    
  
    
## InputMethodController    
获取客户端实例。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### attach<sup>(10+)</sup>    
自绘控件绑定输入法。使用callback异步回调。  
 **调用形式：**     
    
- attach(showKeyboard: boolean, textConfig: TextConfig, callback: AsyncCallback\<void>): void    
起始版本： 10    
- attach(showKeyboard: boolean, textConfig: TextConfig): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| showKeyboard | boolean | true | 绑定输入法成功后，是否拉起输入法键盘。<br>- ture表示拉起，false表示不拉起。 |  
| textConfig | TextConfig | true | 编辑框的配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当绑定输入法成功后，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
try {  
  let textConfig: inputMethod.TextConfig = {  
    inputAttribute: {  
      textInputType: 0,  
      enterKeyType: 1  
    }  
  };  
  inputMethodController.attach(true, textConfig, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to attach: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in attaching the inputMethod.');  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to attach: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
try {  
  let textConfig: inputMethod.TextConfig = {  
    inputAttribute: {  
      textInputType: 0,  
      enterKeyType: 1  
    }  
  };  
  inputMethodController.attach(true, textConfig).then(() => {  
    console.log('Succeeded in attaching inputMethod.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to attach: ${JSON.stringify(err)}`);  
  })  
} catch(err: BusinessError) {  
  console.error(`Failed to attach: ${JSON.stringify(err)}`);  
}  
  
```ts    
示例代码（promise）：    
```    
  
    
### showTextInput<sup>(10+)</sup>    
进入文本编辑状态。使用callback异步回调。  
 **调用形式：**     
    
- showTextInput(callback: AsyncCallback\<void>): void    
起始版本： 10    
- showTextInput(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。若成功进入编辑状态，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
| 12800009 | input method client is detached. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
inputMethodController.showTextInput((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in showing the inputMethod.');  
});    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
inputMethodController.showTextInput().then(() => {  
  console.log('Succeeded in showing text input.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);  
});    
```    
  
    
### hideTextInput<sup>(10+)</sup>    
退出文本编辑状态。使用callback异步回调。  
 **调用形式：**     
    
- hideTextInput(callback: AsyncCallback\<void>): void    
起始版本： 10    
- hideTextInput(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功退出编辑状态时，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
| 12800009 | input method client is detached. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
inputMethodController.hideTextInput((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in hiding text input.');  
});    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
inputMethodController.hideTextInput().then(() => {  
  console.log('Succeeded in hiding inputMethod.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);  
})    
```    
  
    
### detach<sup>(10+)</sup>    
自绘控件解除与输入法的绑定。使用callback异步回调。  
 **调用形式：**     
    
- detach(callback: AsyncCallback\<void>): void    
起始版本： 10    
- detach(): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当解绑定输入法成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
inputMethodController.detach((err: BusinessError) => {  
  if (err) {  
    console.error(`Failed to detach: ${JSON.stringify(err)}`);  
    return;  
  }  
  console.log('Succeeded in detaching inputMethod.');  
});    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
inputMethodController.detach().then(() => {  
  console.log('Succeeded in detaching inputMethod.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to detach: ${JSON.stringify(err)}`);  
});    
```    
  
    
### setCallingWindow<sup>(10+)</sup>    
设置要避让软键盘的窗口。使用callback异步回调。  
 **调用形式：**     
    
- setCallingWindow(windowId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setCallingWindow(windowId: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| windowId | number | true | 绑定输入法应用的应用程序所在的窗口Id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
| 12800009 | input method client is detached. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
try {  
  let windowId: number = 2000;  
  inputMethodController.setCallingWindow(windowId, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in setting callingWindow.');  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
try {  
  let windowId: number = 2000;  
  inputMethodController.setCallingWindow(windowId).then(() => {  
    console.log('Succeeded in setting callingWindow.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);  
  })  
} catch(err: BusinessError) {  
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### updateCursor<sup>(10+)</sup>    
更新当前编辑框内的光标信息。当光标信息发生变化时，调用该接口使输入法感知到光标变化。使用callback异步回调。  
 **调用形式：**     
    
- updateCursor(cursorInfo: CursorInfo, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateCursor(cursorInfo: CursorInfo): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| cursorInfo | CursorInfo | true | 光标信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当光标信息更新成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
| 12800009 | input method client is detached. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
try {  
  let cursorInfo: inputMethod.CursorInfo = { left: 0, top: 0, width: 600, height: 800 };  
  inputMethodController.updateCursor(cursorInfo, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in updating cursorInfo.');  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
try {  
  let cursorInfo: inputMethod.CursorInfo = { left: 0, top: 0, width: 600, height: 800 };  
  inputMethodController.updateCursor(cursorInfo).then(() => {  
    console.log('Succeeded in updating cursorInfo.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);  
  })  
} catch(err: BusinessError) {  
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### changeSelection<sup>(10+)</sup>    
更新当前编辑框内被选中的文本信息。当选中的文本内容或文本范围发生变化时，可调用该接口更新文本信息，使输入法应用感知到变化。使用callback异步回调。  
 **调用形式：**     
    
- changeSelection(text: string, start: number, end: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- changeSelection(text: string, start: number, end: number): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 整个输入文本。 |  
| start | number | true | 所选文本的起始位置。 |  
| end | number | true | 所选文本的结束位置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当文本信息更新成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
| 12800009 | input method client is detached. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.changeSelection('text', 0, 5, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in changing selection.');  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
try {  
  inputMethodController.changeSelection('test', 0, 5).then(() => {  
    console.log('Succeeded in changing selection.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);  
  })  
} catch(err: BusinessError) {  
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### updateAttribute<sup>(10+)</sup>    
更新编辑框属性信息。使用callback异步回调。  
 **调用形式：**     
    
- updateAttribute(attribute: InputAttribute, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateAttribute(attribute: InputAttribute): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| attribute | InputAttribute | true | 编辑框属性对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当编辑框属性信息更新成功时，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
| 12800009 | input method client is detached. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
try {  
  let inputAttribute: inputMethod.InputAttribute = { textInputType: 0, enterKeyType: 1 };  
  inputMethodController.updateAttribute(inputAttribute, (err: BusinessError) => {  
    if (err) {  
      console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);  
      return;  
    }  
    console.log('Succeeded in updating attribute.');  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
try {  
  let inputAttribute: inputMethod.InputAttribute = { textInputType: 0, enterKeyType: 1 };  
  inputMethodController.updateAttribute(inputAttribute).then(() => {  
    console.log('Succeeded in updating attribute.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);  
  })  
} catch(err: BusinessError) {  
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### stopInputSession<sup>(9+)</sup>    
结束输入会话。使用callback异步回调。  
 **调用形式：**     
    
- stopInputSession(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- stopInputSession(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当结束输入会话成功时，err为undefined，data为true；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示结束输入会话成功，返回false表示结束输入会话失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.stopInputSession((err: BusinessError, result: boolean) => {  
    if (err) {  
      console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);  
      return;  
    }  
    if (result) {  
      console.log('Succeeded in stopping inputSession.');  
    } else {  
      console.error('Failed to stopInputSession.');  
    }  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
try {  
  inputMethodController.stopInputSession().then((result: boolean) => {  
    if (result) {  
      console.log('Succeeded in stopping inputSession.');  
    } else {  
      console.error('Failed to stopInputSession.');  
    }  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);  
  })  
} catch(err: BusinessError) {  
  console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### stopInput<sup>(deprecated)</sup>    
结束输入会话。使用callback异步回调。  
 **调用形式：**     
- stopInput(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethod.InputMethodController#stopInputSession。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当会话结束成功，err为undefined，data为true；否则为错误对象。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
inputMethodController.stopInput((err: BusinessError, result: boolean) => {  
  if (err) {  
    console.error(`Failed to stopInput: ${JSON.stringify(err)}`);  
    return;  
  }  
  if (result) {  
    console.log('Succeeded in stopping input.');  
  } else {  
    console.error('Failed to stopInput.');  
  }  
});  
    
```    
  
    
### stopInput<sup>(deprecated)</sup>    
示例代码（promise）：。  
 **调用形式：**     
- stopInput(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: inputMethod.InputMethodController#stopInputSession。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示会话结束成功；返回false表示会话结束失败。 |  
    
 **示例代码：**   
```ts    
inputMethodController.stopInput().then((result: boolean) => {  
  if (result) {  
    console.log('Succeeded in stopping input.');  
  } else {  
    console.error('Failed to stopInput.');  
  }  
}).catch((err: BusinessError) => {  
  console.error(`Failed to stopInput: ${JSON.stringify(err)}`);  
})  
    
```    
  
    
### showSoftKeyboard<sup>(9+)</sup>    
显示输入法软键盘。使用callback异步回调。  
 **调用形式：**     
    
- showSoftKeyboard(callback: AsyncCallback\<void>): void    
起始版本： 9    
- showSoftKeyboard(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework  
 **需要权限：** ohos.permission.CONNECT_IME_ABILITY    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当软键盘显示成功。err为undefined，否则为错误对象。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
inputMethodController.showSoftKeyboard((err: BusinessError) => {  
  if (!err) {  
    console.log('Succeeded in showing softKeyboard.');  
  } else {  
    console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
inputMethodController.showSoftKeyboard().then(() => {  
  console.log('Succeeded in showing softKeyboard.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);  
});    
```    
  
    
### hideSoftKeyboard<sup>(9+)</sup>    
隐藏输入法软键盘。使用callback异步回调。  
 **调用形式：**     
    
- hideSoftKeyboard(callback: AsyncCallback\<void>): void    
起始版本： 9    
- hideSoftKeyboard(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework  
 **需要权限：** ohos.permission.CONNECT_IME_ABILITY    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当软键盘隐藏成功。err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 12800003 | input method client error. |  
| 12800008 | input method manager service error. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
inputMethodController.hideSoftKeyboard((err: BusinessError) => {  
  if (!err) {  
    console.log('Succeeded in hiding softKeyboard.');  
  } else {  
    console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);  
  }  
})  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
inputMethodController.hideSoftKeyboard().then(() => {  
  console.log('Succeeded in hiding softKeyboard.');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);  
});    
```    
  
    
### on('selectByRange')<sup>(10+)</sup>    
订阅输入法应用按范围选中文本事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'selectByRange', callback: Callback\<Range>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'selectByRange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回需要选中的文本范围。<br/>根据传入的文本范围，开发者在回调函数中编辑框中相应文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('selectByRange', (range: inputMethod.Range) => {  
    console.log(`Succeeded in subscribing selectByRange: start: ${range.start} , end: ${range.end}`);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe selectByRange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('selectByRange')<sup>(10+)</sup>    
取消订阅输入法应用按范围选中文本事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'selectByRange', callback?: Callback\<Range>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'selectByRange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（promise）：  
```ts    
try {  
  let onSelectByRangeCallback = (range: inputMethod.Range) => {  
    console.log(`Succeeded in subscribing selectByRange, range: ${JSON.stringify(range)}`);  
  };  
  inputMethodController.off('selectByRange', onSelectByRangeCallback);  
  inputMethodController.off('selectByRange');  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe selectByRange: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('selectByMovement')<sup>(10+)</sup>    
订阅输入法应用按光标移动方向，选中文本事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'selectByMovement', callback: Callback\<Movement>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'selectByMovement'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回光标移动的方向。<br/>根据传入的光标移动方向，选中编辑框中相应文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('selectByMovement', (movement: inputMethod.Movement) => {  
    console.log('Succeeded in subscribing selectByMovement: direction: ' + movement.direction);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe selectByMovement: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('selectByMovement')<sup>(10+)</sup>    
取消订阅输入法应用按光标移动方向，选中文本事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'selectByMovement', callback?: Callback\<Movement>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  let onSelectByMovementCallback = (movement: inputMethod.Movement) => {  
    console.log(`Succeeded in subscribing selectByMovement, movement.direction: ${movement.direction}`);  
  };  
  inputMethodController.off('selectByMovement', onSelectByMovementCallback);  
  inputMethodController.off('selectByMovement');  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing selectByMovement: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('insertText')<sup>(10+)</sup>    
订阅输入法应用插入文本事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'insertText', callback: (text: string) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'insertText'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回需要插入的文本内容。<br/>根据传入的文本，在回调函数中操作编辑框中的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. | |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
function callback1(text: string) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(text));  
}  
  
function callback2(text: string) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(text));  
}  
  
try {  
  inputMethodController.on('insertText', callback1);  
  inputMethodController.on('insertText', callback2);  
  //仅取消insertText的callback1的回调  
  inputMethodController.off('insertText', callback1);  
  //取消insertText的所有回调  
  inputMethodController.off('insertText');  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe insertText: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('insertText')<sup>(10+)</sup>    
取消订阅输入法应用插入文本事件。  
 **调用形式：**     
    
- off(type: 'insertText', callback?: (text: string) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'insertText'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br/>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let onInsertTextCallback = (text: string) => {  
    console.log(`Succeeded in subscribing insertText: ${text}`);  
};  
inputMethodController.off('insertText', onInsertTextCallback);  
inputMethodController.off('insertText');    
```    
  
    
### on('deleteLeft')<sup>(10+)</sup>    
订阅输入法应用向左删除事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'deleteLeft', callback: (length: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'deleteLeft'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回需要向左删除的文本长度。<br/>根据传入的删除长度，在回调函数中操作编辑框中的文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('deleteLeft', (length: number) => {  
    console.log(`Succeeded in subscribing deleteLeft, length: ${length}`);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe deleteLeft: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('deleteLeft')<sup>(10+)</sup>    
取消订阅输入法应用向左删除文本事件。  
 **调用形式：**     
    
- off(type: 'deleteLeft', callback?: (length: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听，固定取值为'deleteLeft'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
let onDeleteLeftCallback = (length: number) => {  
    console.log(`Succeeded in subscribing deleteLeft, length: ${length}`);  
};  
inputMethodController.off('deleteLeft', onDeleteLeftCallback);  
inputMethodController.off('deleteLeft');  
```ts    
示例代码（callback）：    
```    
  
    
### on('deleteRight')<sup>(10+)</sup>    
订阅输入法应用向右删除事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'deleteRight', callback: (length: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'deleteRight'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回需要向右删除的文本长度。<br/>根据传入的删除长度，在回调函数中操作编辑框中的文本。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('deleteRight', (length: number) => {  
    console.log(`Succeeded in subscribing deleteRight, length: ${length}`);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe deleteRight: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('deleteRight')<sup>(10+)</sup>    
取消订阅输入法应用向右删除文本事件。  
 **调用形式：**     
    
- off(type: 'deleteRight', callback?: (length: number) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为`deleteRight`。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let onDeleteRightCallback = (length: number) => {  
    console.log(`Succeeded in subscribing deleteRight, length: ${length}`);  
};  
inputMethodController.off('deleteRight', onDeleteRightCallback);  
inputMethodController.off('deleteRight');    
```    
  
    
### on('sendKeyboardStatus')<sup>(10+)</sup>    
订阅输入法应用发送输入法软键盘状态事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'sendKeyboardStatus', callback: (keyboardStatus: KeyboardStatus) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'sendKeyboardStatus'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回软键盘状态。<br/>根据传入的软键盘状态，在回调函数中做相应操作。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('sendKeyboardStatus', (keyboardStatus: inputMethod.KeyboardStatus) => {  
    console.log(`Succeeded in subscribing sendKeyboardStatus, keyboardStatus: ${keyboardStatus}`);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe sendKeyboardStatus: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('sendKeyboardStatus')<sup>(10+)</sup>    
取消订阅输入法应用发送软键盘状态事件。  
 **调用形式：**     
    
- off(type: 'sendKeyboardStatus', callback?: (keyboardStatus: KeyboardStatus) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'sendKeyboardStatus'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let onSendKeyboardStatus = (keyboardStatus: inputMethod.KeyboardStatus) => {  
    console.log(`Succeeded in subscribing sendKeyboardStatus, keyboardStatus: ${keyboardStatus}`);  
};  
inputMethodController.off('sendKeyboardStatus', onSendKeyboardStatus);  
inputMethodController.off('sendKeyboardStatus');    
```    
  
    
### on('sendFunctionKey')<sup>(10+)</sup>    
订阅输入法应用发送功能键事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'sendFunctionKey', callback: (functionKey: FunctionKey) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'sendFunctionKey'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回输入法应用发送的功能键信息。<br/>根据返回的功能键信息，做相应操作。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('sendFunctionKey', (functionKey: inputMethod.FunctionKey) => {  
    console.log(`Succeeded in subscribing sendFunctionKey, functionKey.enterKeyType: ${functionKey.enterKeyType}`);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe sendFunctionKey: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('sendFunctionKey')<sup>(10+)</sup>    
取消订阅输入法应用发送功能键事件。  
 **调用形式：**     
    
- off(type: 'sendFunctionKey', callback?: (functionKey: FunctionKey) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'sendFunctionKey'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let onSendFunctionKey = (functionKey: inputMethod.FunctionKey) => {  
    console.log(`Succeeded in subscribing sendFunctionKey, functionKey: ${functionKey.enterKeyType}`);  
};  
inputMethodController.off('sendFunctionKey', onSendFunctionKey);  
inputMethodController.off('sendFunctionKey');    
```    
  
    
### on('moveCursor')<sup>(10+)</sup>    
订阅输入法应用移动光标事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'moveCursor', callback: (direction: Direction) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'moveCursor'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回光标信息。<br/>根据返回的光标移动方向，改变光标位置，如光标向上或向下。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('moveCursor', (direction: inputMethod.Direction) => {  
    console.log(`Succeeded in subscribing moveCursor, direction: ${direction}`);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe moveCursor: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('moveCursor')<sup>(10+)</sup>    
取消订阅输入法应用移动光标事件。  
 **调用形式：**     
    
- off(type: 'moveCursor', callback?: (direction: Direction) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'moveCursor'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
let onMoveCursorCallback = (direction: inputMethod.Direction) => {  
    console.log(`Succeeded in subscribing moveCursor, direction: ${direction}`);  
};  
inputMethodController.off('moveCursor', onMoveCursorCallback);  
inputMethodController.off('moveCursor');    
```    
  
    
### on('handleExtendAction')<sup>(10+)</sup>    
订阅输入法应用发送扩展编辑操作事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'handleExtendAction', callback: (action: ExtendAction) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'handleExtendAction'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回扩展编辑操作类型。<br/>根据传入的扩展编辑操作类型，做相应的操作，如剪切、复制等。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('handleExtendAction', (action: inputMethod.ExtendAction) => {  
    console.log(`Succeeded in subscribing handleExtendAction, action: ${action}`);  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe handleExtendAction: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('handleExtendAction')<sup>(10+)</sup>    
取消订阅输入法应用发送扩展编辑操作事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'handleExtendAction', callback?: (action: ExtendAction) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'handleExtendAction'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  let onHandleExtendActionCallback = (action: inputMethod.ExtendAction) => {  
    console.log(`Succeeded in subscribing handleExtendAction, action: ${action}`);  
  };  
  inputMethodController.off('handleExtendAction', onHandleExtendActionCallback);  
  inputMethodController.off('handleExtendAction');  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe handleExtendAction: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('getLeftTextOfCursor')<sup>(10+)</sup>    
订阅输入法应用获取光标左侧指定长度文本事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'getLeftTextOfCursor', callback: (length: number) => string): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'getLeftTextOfCursor'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取编辑框最新状态下光标左侧指定长度的文本内容并返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('getLeftTextOfCursor', (length: number) => {  
    console.info(`Succeeded in subscribing getLeftTextOfCursor, length: ${length}`);  
    let text:string = "";  
    return text;  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing getLeftTextOfCursor. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('getLeftTextOfCursor')<sup>(10+)</sup>    
取消订阅输入法应用获取光标左侧指定长度文本事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'getLeftTextOfCursor', callback?: (length: number) => string): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'getLeftTextOfCursor'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  let getLeftTextOfCursorCallback = (length: number) => {  
    console.info(`Succeeded in unsubscribing getLeftTextOfCursor, length: ${length}`);  
    let text:string = "";  
    return text;  
  };  
  inputMethodController.off('getLeftTextOfCursor', getLeftTextOfCursorCallback);  
  inputMethodController.off('getLeftTextOfCursor');  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing getLeftTextOfCursor. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('getRightTextOfCursor')<sup>(10+)</sup>    
订阅输入法应用获取光标右侧指定长度文本事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'getRightTextOfCursor', callback: (length: number) => string): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'getRightTextOfCursor'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取编辑框最新状态下光标右侧指定长度的文本内容并返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 | input method client is detached. |  
    
 **示例代码：**   
示例代码（callback）：  
  
```ts    
try {  
  inputMethodController.on('getRightTextOfCursor', (length: number) => {  
    console.info(`Succeeded in subscribing getRightTextOfCursor, length: ${length}`);  
    let text:string = "";  
    return text;  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe getRightTextOfCursor. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('getRightTextOfCursor')<sup>(10+)</sup>    
取消订阅输入法应用获取光标右侧指定长度文本事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'getRightTextOfCursor', callback?: (length: number) => string): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'getRightTextOfCursor'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  let getLeftTextOfCursorCallback = (length: number) => {  
    console.info(`Succeeded in unsubscribing getLeftTextOfCursor, length: ${length}`);  
    let text:string = "";  
    return text;  
  };  
  inputMethodController.off('getLeftTextOfCursor', getLeftTextOfCursorCallback);  
  inputMethodController.off('getLeftTextOfCursor');  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing getLeftTextOfCursor. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('getTextIndexAtCursor')<sup>(10+)</sup>    
订阅输入法应用获取光标处文本索引事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'getTextIndexAtCursor', callback: () => number): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'getTextIndexAtCursor'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取编辑框最新状态下光标处文本索引并返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12800009 |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodController.on('getTextIndexAtCursor', () => {  
    console.info(`Succeeded in subscribing getTextIndexAtCursor.`);  
    let index:number = 0;  
    return index;  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to subscribe getTextIndexAtCursor. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('getTextIndexAtCursor')<sup>(10+)</sup>    
取消订阅输入法应用获取光标处文本索引事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'getTextIndexAtCursor', callback?: () => number): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'getTextIndexAtCursor'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数，需要与on接口传入的保持一致。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  let getTextIndexAtCursorCallback = () => {  
    console.info(`Succeeded in unsubscribing getTextIndexAtCursor.`);  
    let index:number = 0;  
    return index;  
  };  
  inputMethodController.off('getTextIndexAtCursor', getTextIndexAtCursorCallback);  
  inputMethodController.off('getTextIndexAtCursor');  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing getTextIndexAtCursor. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
## InputMethodProperty<sup>(8+)</sup>    
输入法应用属性。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| packageName<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用inputMethod.InputMethodProperty#name替代。<br>输入法包名。必填。<br/>说明：从API version 8开始支持，从API version 9开始废弃，建议使用name替代。 |  
| methodId<sup>(deprecated)</sup> | string | true | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用inputMethod.InputMethodProperty#id替代。<br>输入法唯一标识。必填。<br/>说明：从API version 8开始支持，从API version 9开始废弃，建议使用id替代。 |  
| name<sup>(9+)</sup> | string | true | true | 必填。输入法内部名称。 |  
| id<sup>(9+)</sup> | string | true | true | 必填。输入法唯一标识。 |  
| label<sup>(9+)</sup> | string | true | false | 非必填。输入法对外显示名称。 |  
| labelId<sup>(10+)</sup> | number | true | false | 非必填。输入法对外显示名称资源号。 |  
| icon<sup>(9+)</sup> | string | true | false | 非必填。输入法图标数据，可以通过iconId查询获取。预留字段，暂不支持使用。 |  
| iconId<sup>(9+)</sup> | number | true | false | 非必填。输入法图标资源号。 |  
| extra<sup>(9+)</sup> | object | false | true | 输入法扩展信息。预留字段，当前无具体含义，暂不支持使用。<br/>- API version 10起：非必填；<br/>- API version 9：必填。 |  
| extra<sup>(10+)</sup> | object | false | false | 输入法扩展信息。预留字段，当前无具体含义，暂不支持使用。<br/>- API version 10起：非必填；<br/>- API version 9：必填。 |  
    
## Direction<sup>(10+)</sup>    
光标移动方向。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CURSOR_UP | 1 | 向上 |  
| CURSOR_DOWN | 2 | 向下<br/> |  
| CURSOR_LEFT | 3 | 向左<br/> |  
| CURSOR_RIGHT | 4 | 向右<br/> |  
    
## Range<sup>(10+)</sup>    
文本的选中范围。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| start<sup>(10+)</sup> | number | false | true | 选中文本的首字符在编辑框的索引值。 |  
| end<sup>(10+)</sup> | number | false | true | 选中文本的末字符在编辑框的索引值。 |  
    
## Movement<sup>(10+)</sup>    
选中文本时，光标移动的方向。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| direction<sup>(10+)</sup> | Direction | false | true | 选中文本时，光标的移动方向。 |  
    
## TextInputType<sup>(10+)</sup>    
文本输入类型。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | -1 | NONE。 |  
| TEXT | 0 | 文本类型。 |  
| MULTILINE | 1 | 多行类型。 |  
| NUMBER | 2 | 数字类型。 |  
| PHONE | 3 | 电话号码类型。 |  
| DATETIME | 4 | 日期类型。 |  
| EMAIL_ADDRESS | 5 | 邮箱地址类型。 |  
| URL | 6 | 链接类型。 |  
| VISIBLE_PASSWORD | 7 | 密码类型。 |  
    
## EnterKeyType<sup>(10+)</sup>    
Enter键的功能类型。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSPECIFIED | 0 | 未指定。 |  
| NONE | 1 | NONE。 |  
| GO | 2 | 前往。 |  
| SEARCH | 3 | 查找。 |  
| SEND | 4 | 发送。 |  
| NEXT | 5 | 下一步。 |  
| DONE | 6 | 完成。 |  
| PREVIOUS | 7 | 上一步。 |  
    
## KeyboardStatus<sup>(10+)</sup>    
输入法软键盘状态。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | NONE。 |  
| HIDE | 1 | 隐藏状态。 |  
| SHOW | 2 | 显示状态。 |  
    
## InputAttribute<sup>(10+)</sup>    
编辑框属性，包含文本输入类型和Enter键功能类型。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| textInputType<sup>(10+)</sup> | TextInputType | false | true | 文本输入类型。 |  
| enterKeyType<sup>(10+)</sup> | EnterKeyType | false | true | Enter键功能类型。 |  
    
## FunctionKey<sup>(10+)</sup>    
输入法功能键类型。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| enterKeyType<sup>(10+)</sup> | EnterKeyType | false | true | 输入法enter键类型。 |  
    
## CursorInfo<sup>(10+)</sup>    
光标信息。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| left<sup>(10+)</sup> | number | false | true | 光标的left坐标。 |  
| top<sup>(10+)</sup> | number | false | true | 光标的top坐标。 |  
| width<sup>(10+)</sup> | number | false | true | 光标的宽度。 |  
| height<sup>(10+)</sup> | number | false | true | 光标的高度。 |  
    
## TextConfig<sup>(10+)</sup>    
编辑框的配置信息。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| inputAttribute<sup>(10+)</sup> | InputAttribute | false | true | 编辑框属性。 |  
| cursorInfo<sup>(10+)</sup> | CursorInfo | false | false | 光标信息。 |  
| selection<sup>(10+)</sup> | Range | false | false | 文本选中的范围。 |  
| windowId<sup>(10+)</sup> | number | false | false | 编辑框所在的窗口Id。 |  
    
## ExtendAction<sup>(10+)</sup>    
编辑框中文本的扩展编辑操作类型，如剪切、复制等。    
    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SELECT_ALL | 0 | 全选。 |  
| CUT | 3 | 剪切。 |  
| COPY | 4 | 复制。 |  
| PASTE | 5 | 粘贴。 |  
    
## InputWindowInfo<sup>(10+)</sup>    
输入法软键盘的窗口信息。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(10+)</sup> | string | false | true | 输入法窗口的名称。 |  
| left<sup>(10+)</sup> | number | false | true | 输入法窗口左上顶点的横坐标，单位为px。 |  
| top<sup>(10+)</sup> | number | false | true | 输入法窗口左上顶点的纵坐标，单位为px。 |  
| width<sup>(10+)</sup> | number | false | true | 输入法窗口的宽度，单位为px。 |  
| height<sup>(10+)</sup> | number | false | true | 输入法窗口的高度，单位为px。 |  
