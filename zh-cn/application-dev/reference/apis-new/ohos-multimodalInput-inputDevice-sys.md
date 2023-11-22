# @ohos.multimodalInput.inputDevice    
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputDevice from '@ohos.multimodalInput.inputDevice'    
```  
    
## setKeyboardRepeatDelay<sup>(10+)</sup>    
设置键盘按键的重复时延，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setKeyboardRepeatDelay(delay: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setKeyboardRepeatDelay(delay: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| delay | number | true | 键盘按键重复延迟时间，默认值500ms，调节范围 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  inputDevice.setKeyboardRepeatDelay(350, (error: Error) => {  
    if (error) {  
      console.log(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Set keyboard repeat delay success`);  
  });  
} catch (error) {  
  console.log(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  inputDevice.setKeyboardRepeatDelay(350).then(() => {  
    console.log(`Set keyboard repeat delay success`);  
  });  
} catch (error) {  
  console.log(`Set keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getKeyboardRepeatDelay<sup>(10+)</sup>  
 **调用形式：**     
    
- getKeyboardRepeatDelay(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getKeyboardRepeatDelay(): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<number> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  inputDevice.getKeyboardRepeatDelay((error: Error, delay: Number) => {  
    if (error) {  
      console.log(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Get keyboard repeat delay success`);  
  });  
} catch (error) {  
  console.log(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  inputDevice.getKeyboardRepeatDelay().then((delay: Number) => {  
    console.log(`Get keyboard repeat delay success`);  
  });  
} catch (error) {  
  console.log(`Get keyboard repeat delay failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## setKeyboardRepeatRate<sup>(10+)</sup>    
设置键盘按键的重复速率，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- setKeyboardRepeatRate(rate: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setKeyboardRepeatRate(rate: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rate | number | true | 键盘按键重复速率，默认值50ms/次，调节范围[36ms/次，100ms/次]。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  inputDevice.setKeyboardRepeatRate(60, (error: Error) => {  
    if (error) {  
      console.log(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Set keyboard repeat rate success`);  
  });  
} catch (error) {  
  console.log(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  inputDevice.setKeyboardRepeatRate(60).then(() => {  
    console.log(`Set keyboard repeat rate success`);  
  });  
} catch (error) {  
  console.log(`Set keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getKeyboardRepeatRate<sup>(10+)</sup>    
获取键盘按键的重复速率，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getKeyboardRepeatRate(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getKeyboardRepeatRate(): Promise\<number>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.InputDevice    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回键盘按键的重复速率。 |  
| Promise<number> | Promise实例，异步返回键盘按键的重复速率。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
try {  
  inputDevice.getKeyboardRepeatRate((error: Error, rate: Number) => {  
    if (error) {  
      console.log(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Get keyboard repeat rate success`);  
  });  
} catch (error) {  
  console.log(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
try {  
  inputDevice.getKeyboardRepeatRate().then((rate: Number) => {  
    console.log(`Get keyboard repeat rate success`);  
  });  
} catch (error) {  
  console.log(`Get keyboard repeat rate failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
