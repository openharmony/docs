# @ohos.application.appManager    
appManager模块提供App管理的能力，包括查询当前是否处于稳定性测试场景、查询是否为ram受限设备、获取应用程序的内存大小、获取有关运行进程的信息等。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import appManager from '@ohos.application.appManager'    
```  
    
## isRunningInStabilityTest<sup>(deprecated)</sup>    
查询当前是否处于稳定性测试场景。  
 **调用形式：**     
- isRunningInStabilityTest(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#isRunningInStabilityTest。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 返回当前是否处于稳定性测试场景。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
  
  appManager.isRunningInStabilityTest((error, flag) => {  
    if (error  error.code !== 0) {  
        console.error(`isRunningInStabilityTest fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`isRunningInStabilityTest success, the result is: ${JSON.stringify(flag)}`);  
    }  
  });  
    
```    
  
    
## isRunningInStabilityTest<sup>(deprecated)</sup>    
查询当前是否处于稳定性测试场景。  
 **调用形式：**     
- isRunningInStabilityTest(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#isRunningInStabilityTest。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 返回当前是否处于稳定性测试场景。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
  import { BusinessError } from '@ohos.base';  
  
  appManager.isRunningInStabilityTest().then((flag) => {  
      console.log(`The result of isRunningInStabilityTest is: ${JSON.stringify(flag)}`);  
  }).catch((error: BusinessError) => {  
      console.error(`error: ${JSON.stringify(error)}`);  
  });  
    
```    
  
    
## getProcessRunningInfos<sup>(deprecated)</sup>    
获取有关运行进程的信息。  
 **调用形式：**     
- getProcessRunningInfos(): Promise\<Array\<ProcessRunningInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#getRunningProcessInformation。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<ProcessRunningInfo>> | 获取有关运行进程的信息。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
  import { BusinessError } from '@ohos.base';  
  
  appManager.getProcessRunningInfos().then((data) => {  
      console.log(`The process running infos is: ${JSON.stringify(data)}`);  
  }).catch((error: BusinessError) => {  
      console.error(`error: ${JSON.stringify(error)}`);  
  });  
    
```    
  
    
## getProcessRunningInfos<sup>(deprecated)</sup>  
 **调用形式：**     
- getProcessRunningInfos(callback: AsyncCallback\<Array\<ProcessRunningInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.ability.appManager/appManager#getRunningProcessInformation。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<ProcessRunningInfo>> | true | 获取有关运行进程的信息。 |  
    
 **示例代码：**   
```ts    
import appManager from '@ohos.application.appManager';  
  
  appManager.getProcessRunningInfos((error, data) => {  
      if (error  error.code !== 0) {  
          console.error(`getProcessRunningInfos fail, error: ${JSON.stringify(error)}`);  
      } else {  
          console.log(`getProcessRunningInfos success, data: ${JSON.stringify(data)}`);  
      }  
  });  
    
```    
  
