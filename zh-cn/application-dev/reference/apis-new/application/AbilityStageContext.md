# AbilityStageContext    
AbilityStageContext是AbilityStage的上下文环境，继承自[Context](js-apis-inner-application-context.md)。AbilityStageContext提供允许访问特定于abilityStage的资源的能力，包括获取AbilityStage对应的ModuleInfo对象、环境变化对象。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import common from '@ohos.app.ability.common';  
    
```  
    
## AbilityStageContext    
通过AbilityStage实例来获取。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| currentHapModuleInfo | HapModuleInfo | false | true | AbilityStage对应的ModuleInfo对象。 |  
| config | Configuration | false | true | 环境变化对象。 |  
