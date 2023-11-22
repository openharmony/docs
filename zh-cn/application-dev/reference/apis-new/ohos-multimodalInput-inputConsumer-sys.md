# @ohos.multimodalInput.inputConsumer    
组合按键订阅模块，用于处理组合按键的订阅。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputConsumer from '@ohos.multimodalInput.inputConsumer'    
```  
    
## KeyOptions    
组合键选项。  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputConsumer    
### 属性    
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputConsumer    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| preKeys | Array<number> | false | true | 前置按键集合，数量范围[0, 4]，前置按键无顺序要求。<br/>如组合按键Ctrl+Alt+A中，Ctrl+Alt称为前置按键。<br/> |  
| finalKey | number | false | true | 最终按键，此项必填，最终按键触发上报回调函数。<br/>如组合按键Ctrl+Alt+A中，A称为最终按键按键。<br/> |  
| isFinalKeyDown | boolean | false | true | 最终按键状态。<br/>ture表示按键按下，false表示按键抬起。<br/> |  
| finalKeyDownDuration | number | false | true | 最终按键保持按下持续时间，单位为微秒（μs）。<br/>当finalKeyDownDuration为0时，立即触发回调函数。<br/>当finalKeyDownDuration大于0时，isFinalKeyDown为true，则最终按键按下超过设置时长后触发回调函数；isFinalKeyDown为false，则最终按键按下到抬起时间小于设置时长时触发回调函数。<br/> |  
    
## on('key')    
订阅组合按键，当满足条件的组合按键输入事件发生时，使用Callback异步方式上报组合按键数据。  
 **调用形式：**     
    
- on(type: 'key', keyOptions: KeyOptions, callback: Callback\<KeyOptions>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputConsumer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件类型，目前仅支持'key'。<br/> |  
| keyOptions | KeyOptions | true | 组合键选项。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当满足条件的组合按键输入事件发生时，异步上报组合按键数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例代码（callback）：  
```js    
let leftAltKey = 2045;  
let tabKey = 2049;  
let keyOptions: inputConsumer.KeyOptions = {  
  preKeys: [ leftAltKey ],  
  finalKey: tabKey,  
  isFinalKeyDown: true,  
  finalKeyDownDuration: 0  
};  
let callback = (keyOptions: inputConsumer.KeyOptions) => {  
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);  
}  
try {  
  inputConsumer.on("key", keyOptions, callback);  
} catch (error) {  
  console.log(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('key')    
取消订阅组合按键。  
 **调用形式：**     
    
- off(type: 'key', keyOptions: KeyOptions, callback?: Callback\<KeyOptions>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputConsumer    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件类型，当前仅支持 'key'。<br/> |  
| keyOptions | KeyOptions | true | <table><tbody><tr><td><br/>组合键选项。</td></tr></tbody></table> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若不填，则取消当前应用组合键选项已订阅的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例代码（callback）：  
```js    
let leftAltKey = 2045;  
let tabKey = 2049;  
// 取消订阅单个回调函数  
let callback = (keyOptions: inputConsumer.KeyOptions) => {  
  console.log(`keyOptions: ${JSON.stringify(keyOptions)}`);  
}  
let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};  
try {  
  inputConsumer.on("key", keyOption, callback);  
  inputConsumer.off("key", keyOption, callback);  
  console.log(`Unsubscribe success`);  
} catch (error) {  
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
