# ExtensionRunningInfo    
ExtensionRunningInfo模块封装了Extension运行的相关信息，可以通过[getExtensionRunningInfos接口](js-apis-app-ability-abilityManager.md#getextensionrunninginfos)获取。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## ExtensionRunningInfo  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| extension | ElementName | false | true | Extension信息。 |  
| pid | number | false | true | 进程ID。 |  
| uid | number | false | true | 应用程序的uid。 |  
| processName | string | false | true | 进程名称。 |  
| startTime | number | false | true | Extension被启动时的时间戳。 |  
| clientPackage | Array<String> | false | true | 表示当期进程下的所有包名。 |  
| type | bundle.ExtensionAbilityType | false | true | Extension类型。 |  
