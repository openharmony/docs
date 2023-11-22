# ContinueMissionInfo    
表示发起按照包名迁移时所需参数的枚举，迁移Mission详见：[continueMission接口](js-apis-distributedMissionManager.md#distributedmissionmanagercontinuemission10)。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ContinueMissionInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| srcDeviceId | string | false | true | 表示任务迁移源设备ID。 |  
| dstDeviceId | string | false | true | 表示任务迁移目标设备ID。 |  
| bundleName | string | false | true | 表示任务所属应用包名。  |  
| wantParam | object | false | true | 表示扩展参数。 |  
    
 **示例代码：**   
```ts    
import distributedMissionManager from '@ohos.distributedMissionManager';  
  import { BusinessError } from '@ohos.base';  
  
  try {  
      distributedMissionManager.continueMission(  
        {  
            srcDeviceId: "",  
            dstDeviceId: "",  
            bundleName: "ohos.test.continueapp",  
            wantParam: {"key": "value"}  
        }, (error: BusinessError) => {  
          if (error.code != 0) {  
              console.error('continueMission failed, cause: ' + JSON.stringify(error))  
          }  
          console.info('continueMission finished')  
      })  
  } catch (error) {  
      console.error('continueMission failed, cause: ' + JSON.stringify(error))  
  }  
    
```    
  
