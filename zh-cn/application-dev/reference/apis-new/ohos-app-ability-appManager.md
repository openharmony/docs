# @ohos.app.ability.appManager    
appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import appManager from '@ohos.app.ability.appManager'    
```  
    
## ProcessState<sup>(10+)</sup>    
进程状态，该类型为枚举，可配合[ProcessData](js-apis-inner-application-processData.md)返回相应的进程状态。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_CREATE | 0 | 当进程在创建中的时候处于的状态。  |  
| STATE_FOREGROUND | 1 | 当进程切换到前台的时候处于的状态。 |  
| STATE_ACTIVE | 2 | 当进程在获焦的时候处于的状态。 |  
| STATE_BACKGROUND | 3 | 当进程处于后台不可见时处于的状态。 |  
| STATE_DESTROY | 4 | 当进程在销毁的时候处于的状态。  |  
    
## isRunningInStabilityTest  
 **调用形式：**     
    
- isRunningInStabilityTest(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isRunningInStabilityTest(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及当前是否处于稳定性测试场景，可进行错误处理或其他自定义处理。true: 处于稳定性测试场景，false：处于非稳定性测试场景。 |  
| Promise<boolean> | 以Promise方式返回接口运行结果及当前是否处于稳定性测试场景，可进行错误处理或其他自定义处理。true: 处于稳定性测试场景，false：处于非稳定性测试场景。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 16000050 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
  
appManager.isRunningInStabilityTest((err, flag) => {  
    if (err) {  
        console.error(`isRunningInStabilityTest fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log(`The result of isRunningInStabilityTest is: ${JSON.stringify(flag)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
appManager.isRunningInStabilityTest().then((flag) => {  
    console.log(`The result of isRunningInStabilityTest is: ${JSON.stringify(flag)}`);  
}).catch((error: BusinessError) => {  
    console.error(`error: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
## isRamConstrainedDevice    
查询是否为ram受限设备。  
 **调用形式：**     
    
- isRamConstrainedDevice(): Promise\<boolean>    
起始版本： 9    
- isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及当前设备是否为ram受限设备，可进行错误处理或其他自定义处理。true：当前设备为ram受限设备，false：当前设备为非ram受限设备。 |  
| Promise<boolean> | 以Promise方式返回接口运行结果及当前设备是否为ram受限设备，可进行错误处理或其他自定义处理。true：当前设备为ram受限设备，false：当前设备为非ram受限设备。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 16000050 | Internal error. |  
| 401 |  |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
appManager.isRamConstrainedDevice().then((data) => {  
    console.log(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);  
}).catch((error: BusinessError) => {  
    console.error(`error: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
  
appManager.isRamConstrainedDevice((err, data) => {  
    if (err) {  
        console.error(`isRamConstrainedDevice fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log(`The result of isRamConstrainedDevice is: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
## getAppMemorySize    
获取应用程序的内存大小。  
 **调用形式：**     
    
- getAppMemorySize(): Promise\<number>    
起始版本： 9    
- getAppMemorySize(callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及应用程序内存大小，可进行错误处理或其他自定义处理。 |  
| Promise<number> | 以Promise方式返回接口运行结果及应用程序内存大小，可进行错误处理或其他自定义处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 16000050 | Internal error. |  
| 401 |  |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError} from '@ohos.base'  
  
appManager.getAppMemorySize().then((data) => {  
    console.log(`The size of app memory is: ${JSON.stringify(data)}`);  
}).catch((error: BusinessError) => {  
    console.error(`error: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
  
appManager.getAppMemorySize((err, data) => {  
    if (err) {  
        console.error(`getAppMemorySize fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log(`The size of app memory is: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
## getRunningProcessInformation    
获取有关运行进程的信息。  
 **调用形式：**     
    
- getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>    
起始版本： 9    
- getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |  
| Promise<Array<ProcessInformation>> | 以Promise方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 16000050 | Internal error. |  
| 401 |  |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
import { BusinessError } from '@ohos.base';  
  
appManager.getRunningProcessInformation().then((data) => {  
    console.log(`The running process information is: ${JSON.stringify(data)}`);  
}).catch((error: BusinessError) => {  
    console.error(`error: ${JSON.stringify(error)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import appManager from '@ohos.app.ability.appManager';  
  
appManager.getRunningProcessInformation((err, data) => {  
    if (err) {  
        console.error(`getRunningProcessInformation fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log(`The process running information is: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
