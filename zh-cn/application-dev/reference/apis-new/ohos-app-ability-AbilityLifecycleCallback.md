# @ohos.app.ability.AbilityLifecycleCallback    
AbilityLifecycleCallback模块提供应用上下文[ApplicationContext](js-apis-inner-application-applicationContext.md)的生命周期发生变化时触发相应回调的能力，包括[onAbilityCreate](#abilitylifecyclecallbackonabilitycreate)、[onWindowStageCreate](#abilitylifecyclecallbackonwindowstagecreate)、[onWindowStageActive](#abilitylifecyclecallbackonwindowstageactive)、[onWindowStageInactive](#abilitylifecyclecallbackonwindowstageinactive)、[onWindowStageDestroy](#abilitylifecyclecallbackonwindowstagedestroy)、[onAbilityDestroy](#abilitylifecyclecallbackonabilitydestroy)、[onAbilityForeground](#abilitylifecyclecallbackonabilityforeground)、[onAbilityBackground](#abilitylifecyclecallbackonabilitybackground)、[onAbilityContinue](#abilitylifecyclecallbackonabilitycontinue)方法。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## AbilityLifecycleCallback  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
### onAbilityCreate    
注册监听应用上下文的生命周期后，在ability创建时触发回调。  
 **调用形式：**     
- onAbilityCreate(ability: UIAbility): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onAbilityCreate(ability){  
        console.log('AbilityLifecycleCallback onAbilityCreate.');    
    }  
};    
```    
  
    
### onWindowStageCreate    
注册监听应用上下文的生命周期后，在windowStage创建时触发回调。  
 **调用形式：**     
- onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
| windowStage | window.WindowStage | true | 当前WindowStage对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onWindowStageCreate(ability, windowStage){  
        console.log('AbilityLifecycleCallback onWindowStageCreate.');  
    }  
};    
```    
  
    
### onWindowStageActive    
注册监听应用上下文的生命周期后，在windowStage获焦时触发回调。  
 **调用形式：**     
- onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
| windowStage | window.WindowStage | true | 当前WindowStage对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onWindowStageActive(ability, windowStage){  
        console.log('AbilityLifecycleCallback onWindowStageActive.');  
    }  
};    
```    
  
    
### onWindowStageInactive    
注册监听应用上下文的生命周期后，在windowStage失焦时触发回调。  
 **调用形式：**     
- onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
| windowStage | window.WindowStage | true | 当前WindowStage对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onWindowStageInactive(ability, windowStage){  
        console.log('AbilityLifecycleCallback onWindowStageInactive.');  
    }  
};    
```    
  
    
### onWindowStageDestroy    
注册监听应用上下文的生命周期后，在windowStage销毁时触发回调。  
 **调用形式：**     
- onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
| windowStage | window.WindowStage | true | 当前WindowStage对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onWindowStageDestroy(ability, windowStage){  
        console.log('AbilityLifecycleCallback onWindowStageDestroy.');  
    }  
};    
```    
  
    
### onAbilityDestroy    
注册监听应用上下文的生命周期后，在ability销毁时触发回调。  
 **调用形式：**     
- onAbilityDestroy(ability: UIAbility): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onAbilityDestroy(ability){  
        console.log('AbilityLifecycleCallback onAbilityDestroy.');  
    }  
};    
```    
  
    
### onAbilityForeground    
注册监听应用上下文的生命周期后，在ability的状态从后台转到前台时触发回调。  
 **调用形式：**     
- onAbilityForeground(ability: UIAbility): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onAbilityForeground(ability){  
        console.log('AbilityLifecycleCallback onAbilityForeground.');  
    }  
};    
```    
  
    
### onAbilityBackground    
注册监听应用上下文的生命周期后，在ability的状态从前台转到后台时触发回调。  
 **调用形式：**     
- onAbilityBackground(ability: UIAbility): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onAbilityBackground(ability){  
        console.log('AbilityLifecycleCallback onAbilityBackground.');  
    }  
};    
```    
  
    
### onAbilityContinue    
注册监听应用上下文的生命周期后，在ability迁移时触发回调。  
 **调用形式：**     
- onAbilityContinue(ability: UIAbility): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.AbilityCore    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ability | UIAbility | true | 当前Ability对象 |  
    
 **示例代码：**   
```ts    
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';  
  
let abilityLifecycleCallback: AbilityLifecycleCallback =  {  
    onAbilityContinue(ability){  
        console.log('AbilityLifecycleCallback onAbilityContinue.');  
    }  
};    
```    
  
