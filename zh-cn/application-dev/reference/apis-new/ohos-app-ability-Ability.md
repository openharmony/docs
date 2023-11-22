# @ohos.app.ability.Ability    
[UIAbility](js-apis-app-ability-uiAbility.md)和[ExtensionAbility](js-apis-app-ability-extensionAbility.md)的基类，提供系统配置更新回调和系统内存调整回调。不支持开发者直接继承该基类。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Ability  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### onConfigurationUpdate    
当系统配置更新时调用。  
 **调用形式：**     
- onConfigurationUpdate(newConfig: Configuration): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newConfig | Configuration | true | 表示需要更新的配置信息。 |  
    
 **示例代码：**   
```ts    
// Ability是顶层基类，不支持开发者直接继承。故以派生类UIAbility举例说明。  
import UIAbility from '@ohos.app.ability.UIAbility';  
import { Configuration } from '@ohos.app.ability.Configuration';  
  
class MyUIAbility extends UIAbility {  
  onConfigurationUpdate(config: Configuration) {  
      console.log(`onConfigurationUpdate, config: ${JSON.stringify(config)}`);  
  }  
}  
    
```    
  
    
### onMemoryLevel    
当内存到达不同级别时系统回调该方法。  
 **调用形式：**     
- onMemoryLevel(level: AbilityConstant.MemoryLevel): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| level | AbilityConstant.MemoryLevel | true | 当前内存使用级别。 |  
    
 **示例代码：**   
```ts    
// Ability是顶层基类，不支持开发者直接继承。故以派生类UIAbility举例说明。  
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
class MyUIAbility extends UIAbility {  
  onMemoryLevel(level: AbilityConstant.MemoryLevel) {  
      console.log(`onMemoryLevel, level: ${JSON.stringify(level)}`);  
  }   
}  
    
```    
  
