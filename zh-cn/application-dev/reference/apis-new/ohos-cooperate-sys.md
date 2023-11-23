# @ohos.cooperate    
键鼠穿越功能模块，提供两台或多台设备组网协同后键鼠共享能力，实现键鼠输入设备的跨设备协同操作。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import cooperate from '@ohos.cooperate'    
```  
    
## CooperateMsg    
键鼠穿越的消息通知。    
    
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Cooperate    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COOPERATE_PREPARE | 0 | 表示准备键鼠穿越。<br/> |  
| COOPERATE_UNPREPARE | 1 | 表示取消键鼠穿越准备。<br/> |  
| COOPERATE_ACTIVATE | 2 | 表示启动键鼠穿越。<br/> |  
| COOPERATE_ACTIVATE_SUCCESS | 3 | 表示键鼠穿越启动成功。 |  
| COOPERATE_ACTIVATE_FAIL | 4 | 表示键鼠穿越启动失败。<br/> |  
| COOPERATE_DEACTIVATE_SUCCESS | 5 | 表示键鼠穿越停止成功。<br/> |  
| COOPERATE_DEACTIVATE_FAIL | 6 | 表示键鼠穿越停止失败。<br/> |  
| COOPERATE_SESSION_DISCONNECTED | 7 | 表示键鼠穿越会话断开。<br/> |  
    
## prepare    
准备键鼠穿越，使用Callback异步回调。  
 **调用形式：**     
    
- prepare(callback: AsyncCallback\<void>): void    
起始版本： 10    
- prepare(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Cooperate    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，准备键鼠穿越成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  cooperate.prepare((error: BusinessError) => {  
    if (error) {  
      console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Keyboard mouse crossing prepare success.`);  
  });  
} catch (error) {  
  console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  cooperate.prepare().then(() => {  
    console.log(`Keyboard mouse crossing prepare success.`);  
  }, (error: BusinessError) => {  
    console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Keyboard mouse crossing prepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## unprepare    
取消键鼠穿越准备，使用Callback异步回调。  
 **调用形式：**     
    
- unprepare(callback: AsyncCallback\<void>): void    
起始版本： 10    
- unprepare(): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Cooperate    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，取消键鼠穿越准备成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  cooperate.unprepare((error: BusinessError) => {  
    if (error) {  
      console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
      return;  
    }  
    console.log(`Keyboard mouse crossing unprepare success.`);  
  });  
} catch (error) {  
  console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  cooperate.unprepare().then(() => {  
    console.log(`Keyboard mouse crossing unprepare success.`);  
  }, (error: BusinessError) => {  
    console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Keyboard mouse crossing unprepare failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## activate    
启动键鼠穿越，使用Callback异步回调。  
 **调用形式：**     
    
- activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- activate(targetNetworkId: string, inputDeviceId: number): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Cooperate    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| targetNetworkId | string | true | 键鼠穿越目标设备描述符。<br/> |  
| inputDeviceId | number | true | 待穿越输入设备标识符。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，键鼠穿越启动成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 20900001 | Operation failed. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let targetNetworkId = "networkId";  
let inputDeviceId = 0;  
try {  
  cooperate.activate(targetNetworkId, inputDeviceId, (error: BusinessError) => {  
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
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let targetNetworkId = "networkId";  
let inputDeviceId = 0;  
try {  
 cooperate.activate(targetNetworkId, inputDeviceId).then(() => {  
    console.log(`Start Keyboard mouse crossing success.`);  
  }, (error: BusinessError) => {  
    console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Start Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## deactivate    
停止键鼠穿越，使用Callback异步回调。  
 **调用形式：**     
    
- deactivate(isUnchained: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- deactivate(isUnchained: boolean): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Cooperate    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isUnchained | boolean | true | 是否关闭跨设备链路。<br/>ture表示关闭跨设备链路，false表示不关闭。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，键鼠穿越停止成功时，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  cooperate.deactivate(false, (error: BusinessError) => {  
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
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  cooperate.deactivate(false).then(() => {  
    console.log(`Stop Keyboard mouse crossing success.`);  
  }, (error: BusinessError) => {  
    console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Stop Keyboard mouse crossing failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## getCrossingSwitchState    
获取目标设备键鼠穿越开关的状态，使用Callback异步回调。  
 **调用形式：**     
    
- getCrossingSwitchState(networkId: string, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- getCrossingSwitchState(networkId: string): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Cooperate    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| networkId | string | true | 键鼠穿越目标设备描述符。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |  
| Promise<boolean> | Promise对象，返回ture表示目标设备键鼠穿越的开关开启，返回false表示开关未开启。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let deviceDescriptor = "networkId";  
try {  
  cooperate.getCrossingSwitchState(deviceDescriptor, (error: BusinessError, data: boolean) => {  
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
示例（promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
let deviceDescriptor = "networkId";  
try {  
  cooperate.getCrossingSwitchState(deviceDescriptor).then((data: boolean) => {  
    console.log(`Get the status success, data: ${JSON.stringify(data)}`);  
  }, (error: BusinessError) => {  
    console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
  });  
} catch (error) {  
  console.log(`Get the status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## on('cooperate')    
注册监听键鼠穿越状态。  
 **调用形式：**     
    
- on(type: 'cooperate', callback: Callback\<{ networkId: string, msg: CooperateMsg }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Cooperate    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听类型，取值为'cooperate'<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回键鼠穿越状态消息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
function callback(networkId: string, msg: cooperate.CooperateMsg) {  
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);  
  return false;  
}  
try {  
  cooperate.on('cooperate', callback);  
} catch (error) {  
  console.log(`Register failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
    
```    
  
    
## off('cooperate')    
取消监听键鼠穿越状态。  
 **调用形式：**     
    
- off(type: 'cooperate', callback?: Callback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Cooperate    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听类型，取值为'cooperate'。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消注册的回调函数，若无此参数，则取消当前应用注册的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
// 取消注册单个回调函数  
function callbackOn(networkId: string, msg: cooperate.CooperateMsg) {  
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);  
  return false;  
}  
function callbackOff() {  
  console.log(`Keyboard mouse crossing event`);  
  return false;  
}  
try {  
  cooperate.on('cooperate', callbackOn);  
  cooperate.off('cooperate', callbackOff);  
} catch (error) {  
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
  
// 取消注册所有回调函数  
function callbackOn(networkId: string, msg: cooperate.CooperateMsg) {  
  console.log(`Keyboard mouse crossing event: ${JSON.stringify(networkId)}`);  
  return false;  
}  
try {  
  cooperate.on('cooperate', callbackOn);  
  cooperate.off('cooperate');  
} catch (error) {  
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);  
}  
  
    
```    
  
