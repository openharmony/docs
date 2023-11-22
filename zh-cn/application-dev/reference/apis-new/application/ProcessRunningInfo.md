# ProcessRunningInfo    
本模块提供对进程运行信息进行查询的能力。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ProcessRunningInfo<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ProcessInformation/ProcessInformation替代。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Mission    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pid<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ProcessInformation/ProcessInformation#pid替代。<br>进程ID。 |  
| uid<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ProcessInformation/ProcessInformation#uid替代。<br>用户ID。 |  
| processName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ProcessInformation/ProcessInformation#processName替代。<br>进程名称。 |  
| bundleNames<sup>(deprecated)</sup> | Array<string> | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ProcessInformation/ProcessInformation#bundleNames替代。<br>进程中所有运行的Bundle名称。 |  
