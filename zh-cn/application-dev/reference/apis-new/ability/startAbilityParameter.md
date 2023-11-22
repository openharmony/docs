# startAbilityParameter    
定义启动Ability参数，可以作为入参，调用[startAbility](js-apis-ability-featureAbility.md#featureabilitystartability)启动指定的Ability。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## StartAbilityParameter  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| want | Want | false | true | 启动Ability的want信息。 |  
| abilityStartSetting | object | false | false | 启动Ability的特殊属性，当开发者启动Ability时，该属性可以作为调用中的输入参数传递。 |  
