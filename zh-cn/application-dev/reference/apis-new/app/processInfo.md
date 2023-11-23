# processInfo    
定义进程信息，可以通过[getProcessInfo](js-apis-inner-app-context.md#contextgetprocessinfo7)获取当前Ability运行的进程信息。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ProcessInfo  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pid | number | false | true | 进程ID。 |  
| processName | string | false | true | 进程名称。 |  
