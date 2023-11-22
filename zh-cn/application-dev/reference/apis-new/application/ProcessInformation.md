# ProcessInformation    
ProcessInformation模块提供对进程运行信息进行查询的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ProcessInformation  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pid | number | false | true | 进程ID。 |  
| uid | number | false | true | 用户ID。 |  
| processName | string | false | true | 进程名称。 |  
| bundleNames | Array<string> | false | true | 进程中所有运行的Bundle名称。 |  
| state<sup>(10+)</sup> | appManager.ProcessState | false | true | 当前进程运行状态。 |  
