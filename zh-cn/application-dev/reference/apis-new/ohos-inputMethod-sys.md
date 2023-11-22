# @ohos.inputMethod    
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputMethod from '@ohos.inputMethod'    
```  
    
## InputMethodSetting<sup>(8+)</sup>    
获取客户端设置实例  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
### on('imeShow')<sup>(10+)</sup>    
订阅输入法软键盘显示事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'imeShow', callback: (info: Array\<InputWindowInfo>) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'imeShow'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回输入法软键盘信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodSetting.on('imeShow', (info: Array<inputMethod.InputWindowInfo>) => {  
    console.info('Succeeded in subscribing imeShow event.');  
  });  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing imeShow. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('imeShow')<sup>(10+)</sup>    
取消订阅输入法软键盘显示事件。  
 **调用形式：**     
    
- off(type: 'imeShow', callback?: (info: Array\<InputWindowInfo>) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值`imeShow`。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodSetting.off('imeShow');  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing imeShow. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### on('imeHide')<sup>(10+)</sup>    
订阅输入法软键盘隐藏事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值为'imeHide'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回输入法软键盘信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
示例代码（callback）：  
```ts    
try {  
  inputMethodSetting.off('imeHide');  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing imeHide. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
    
### off('imeHide')<sup>(10+)</sup>    
取消订阅输入法软键盘显示事件。  
 **调用形式：**     
    
- off(type: 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MiscServices.InputMethodFramework    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置监听类型，固定取值`imeShow`。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅的回调函数。<br>参数不填写时，取消订阅type对应的所有回调事件。 |  
    
 **示例代码：**   
```ts    
try {  
  inputMethodSetting.off('imeHide');  
} catch(err: BusinessError) {  
  console.error(`Failed to unsubscribing imeHide. err: ${JSON.stringify(err)}`);  
}  
    
```    
  
