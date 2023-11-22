# @ohos.multimodalInput.inputDeviceCooperate    
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'    
```  
    
## EventMsg    
键鼠穿越事件。  
    
## enable    
开启、关闭键鼠穿越，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- enable(enable: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- enable(enable: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Cooperator    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 键鼠穿越使能状态。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回键鼠穿越开启、关闭结果。 |  
| Promise<void> | Promise对象，异步返回键鼠穿越开启、关闭结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
import { BusinessError } from '@ohos.base'  
  
try {  
  inputDeviceCooperate.enable(true, (error: BusinessError) => {  
    if (error) {  
      console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Keyboard mouse crossing enable success.`);  
  });  
} catch (error) {  
  console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
import { BusinessError } from '@ohos.base'  
  
try {  
  inputDeviceCooperate.enable(true).then(() => {  
    console.log(`Keyboard mouse crossing enable success.`);  
  }, (error: BusinessError) => {  
    console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Keyboard mouse crossing enable failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## start    
启动键鼠穿越，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- start(sinkDeviceDescriptor: string, srcInputDeviceId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- start(sinkDeviceDescriptor: string, srcInputDeviceId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Cooperator    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sinkDeviceDescriptor | string | true | 键鼠穿越目标设备描述符。<br/> |  
| srcInputDeviceId | number | true | 键鼠穿越待穿越外设标识符。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回键鼠穿越启动、停止状态。 |  
| Promise<void> | Promise对象，异步返回键鼠穿越启动、关闭结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 4400001 | Incorrect descriptor for the target device. |  
| 4400002 | Screen hop failed. |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
import { BusinessError } from '@ohos.base'  
  
let sinkDeviceDescriptor = "descriptor";  
let srcInputDeviceId = 0;  
try {  
  inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId, (error: BusinessError) => {  
    if (error) {  
      console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Start Keyboard mouse crossing success.`);  
  });  
} catch (error) {  
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
import { BusinessError } from '@ohos.base'  
  
let sinkDeviceDescriptor = "descriptor";  
let srcInputDeviceId = 0;  
try {  
  inputDeviceCooperate.start(sinkDeviceDescriptor, srcInputDeviceId).then(() => {  
    console.log(`Start Keyboard mouse crossing success.`);  
  }, (error: BusinessError) => {  
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## stop    
停止键鼠穿越，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- stop(callback: AsyncCallback\<void>): void    
起始版本： 9    
- stop(): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Cooperator    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回停止键鼠穿越结果。 |  
| Promise<void> | Promise对象，异步返回停止键鼠穿越结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
import { BusinessError } from '@ohos.base'  
  
try {  
  inputDeviceCooperate.stop((error: BusinessError) => {  
    if (error) {  
      console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Stop Keyboard mouse crossing success.`);  
  });  
} catch (error) {  
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
import { BusinessError } from '@ohos.base'  
  
try {  
  inputDeviceCooperate.stop().then(() => {  
    console.log(`Stop Keyboard mouse crossing success.`);  
  }, (error: BusinessError) => {  
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getState    
获取键鼠穿越开关的状态，使用AsyncCallback异步方式返回结果。  
 **调用形式：**     
    
- getState(deviceDescriptor: string, callback: AsyncCallback\<{ state: boolean }>): void    
起始版本： 9    
- getState(deviceDescriptor: string): Promise\<{ state: boolean }>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Cooperator    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceDescriptor | string | true | 键鼠穿越目标设备描述符。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回键鼠穿越开关状态。 |  
| Promise<{ state: boolean }> | Promise对象，异步返回键鼠穿越开关状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
import { BusinessError } from '@ohos.base'  
  
let deviceDescriptor = "descriptor";  
try {  
  inputDeviceCooperate.getState(deviceDescriptor, (error: BusinessError, data: boolean) => {  
    if (error) {  
      console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);  
  });  
} catch (error) {  
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
import { BusinessError } from '@ohos.base'  
  
let deviceDescriptor = "descriptor";  
try {  
  inputDeviceCooperate.getState(deviceDescriptor).then((data: boolean) => {  
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);  
  }, (error: BusinessError) => {  
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## on('cooperation')    
注册监听键鼠穿越状态。  
 **调用形式：**     
    
- on(type: 'cooperation', callback: AsyncCallback\<{ deviceDescriptor: string, eventMsg: EventMsg }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Cooperator    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册类型，取值”cooperation“。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回键鼠穿越事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例代码（callback）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
  
function callback(deviceDescriptor: string, eventMsg: inputDeviceCooperate.EventMsg) {  
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(deviceDescriptor)}`);  
  return false;  
}  
try {  
  inputDeviceCooperate.on('cooperation', callback);  
} catch (error) {  
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
  
function callback(deviceDescriptor: string, eventMsg: inputDeviceCooperate.EventMsg) {  
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(deviceDescriptor)}`);  
  return false;  
}  
try {  
  inputDeviceCooperate.on('cooperation', callback);  
} catch (error) {  
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('cooperation')    
关闭监听键鼠穿越状态。  
 **调用形式：**     
    
- off(type: 'cooperation', callback?: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.MultimodalInput.Input.Cooperator    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册类型，取值“cooperation”。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import inputDeviceCooperate from '@ohos.multimodalInput.inputDeviceCooperate'  
  
// 取消注册单个回调函数  
function callbackOn(deviceDescriptor: string, eventMsg: inputDeviceCooperate.EventMsg) {  
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(deviceDescriptor)}`);  
  return false;  
}  
function callbackOff() {  
  console.log(`Keyboard mouse crossing event`);  
  return false;  
}  
try {  
  inputDeviceCooperate.on('cooperation', callbackOn);  
  inputDeviceCooperate.off("cooperation", callbackOff);  
} catch (error) {  
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
