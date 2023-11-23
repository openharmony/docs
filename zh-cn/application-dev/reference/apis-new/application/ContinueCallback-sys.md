# ContinueCallback    
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ContinueCallback  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
### onContinueDone  
 **调用形式：**     
- onContinueDone(result: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| result | number | true |  |  
    
 **示例代码：**   
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager';  
  import { BusinessError } from '@ohos.base';  
  
  distributedMissionManager.continueMission(  
    {  
      srcDeviceId: '123',  
      dstDeviceId: '456',  
      missionId: 123,  
      wantParam: {  
          'key':'value'  
      }  
    },  
    {  
      onContinueDone(result) {  
          console.log(`onContinueDone, result: ${JSON.stringify(result)}`);  
      }  
    }, (error: BusinessError) => {  
      if (error  error.code) {  
          console.error(`continueMission failed, error.code: ${error.code}, error.message: ${error.message}`);  
      }  
      co  
    
```    
  
