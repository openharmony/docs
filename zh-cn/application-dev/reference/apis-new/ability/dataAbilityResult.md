# dataAbilityResult    
定义DataAbility数据操作结果，通过[executeBatch](js-apis-inner-ability-dataAbilityHelper.md#dataabilityhelperexecutebatch)操作数据库时，操作结果使用DataAbilityResult对象返回。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## DataAbilityResult  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.FAModel    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uri | string | false | false | 指示待处理的DataAbility。例：'dataability:///com.example.xxx.xxxx'。 |  
| count | number | false | false | 指示受操作影响的数据数量。 |  
