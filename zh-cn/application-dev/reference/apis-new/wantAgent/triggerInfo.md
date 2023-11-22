# triggerInfo    
作为[trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger)的入参定义触发WantAgent所需要的信息。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## TriggerInfo  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| code | number | false | true | 提供给目标wantAgent的自定义结果码。 |  
| want | Want | false | false | Want。 |  
| permission | string | false | false | 权限定义。 |  
| extraInfo | object | false | false | 额外数据。 |  
