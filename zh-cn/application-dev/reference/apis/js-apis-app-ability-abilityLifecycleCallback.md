# @ohos.app.ability.abilityLifecycleCallback (AbilityLifecycleCallback)

AbilityLifecycleCallback模块提供应用上下文[ApplicationContext](js-apis-inner-application-applicationContext.md)的生命周期发生变化时触发相应回调的能力，包括[onAbilityCreate](#abilitylifecyclecallbackonabilitycreate)、[onWindowStageCreate](#abilitylifecyclecallbackonwindowstagecreate)、[onWindowStageActive](#abilitylifecyclecallbackonwindowstageactive)、[onWindowStageInactive](#abilitylifecyclecallbackonwindowstageinactive)、[onWindowStageDestroy](#abilitylifecyclecallbackonwindowstagedestroy)、[onAbilityDestroy](#abilitylifecyclecallbackonabilitydestroy)、[onAbilityForeground](#abilitylifecyclecallbackonabilityforeground)、[onAbilityBackground](#abilitylifecyclecallbackonabilitybackground)、[onAbilityContinue](#abilitylifecyclecallbackonabilitycontinue)方法。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。


## 导入模块

```ts
import AbilityLifecycleCallback from "@ohos.app.ability.AbilityLifecycleCallback";
```


## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: [UIAbility](js-apis-app-ability-uiAbility.md)): void;

注册监听应用上下文的生命周期后，在ability创建时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onWindowStageCreate

onWindowStageCreate(ability: [UIAbility](js-apis-app-ability-uiAbility.md), windowStage: [window.WindowStage](js-apis-window.md#windowstage9)): void;

注册监听应用上下文的生命周期后，在windowStage创建时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |    


## AbilityLifecycleCallback.onWindowStageActive

onWindowStageActive(ability: [UIAbility](js-apis-app-ability-uiAbility.md), windowStage: [window.WindowStage](js-apis-window.md#windowstage9)): void;

注册监听应用上下文的生命周期后，在windowStage获焦时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |    


## AbilityLifecycleCallback.onWindowStageInactive

onWindowStageInactive(ability: [UIAbility](js-apis-app-ability-uiAbility.md), windowStage: [window.WindowStage](js-apis-window.md#windowstage9)): void;

注册监听应用上下文的生命周期后，在windowStage失焦时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |  


## AbilityLifecycleCallback.onWindowStageDestroy

onWindowStageDestroy(ability: [UIAbility](js-apis-app-ability-uiAbility.md), windowStage: [window.WindowStage](js-apis-window.md#windowstage9)): void;

注册监听应用上下文的生命周期后，在windowStage销毁时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |  


## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: [UIAbility](js-apis-app-ability-uiAbility.md)): void;

注册监听应用上下文的生命周期后，在ability销毁时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: [UIAbility](js-apis-app-ability-uiAbility.md)): void;

注册监听应用上下文的生命周期后，在ability的状态从后台转到前台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: [UIAbility](js-apis-app-ability-uiAbility.md)): void;

注册监听应用上下文的生命周期后，在ability的状态从前台转到后台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: [UIAbility](js-apis-app-ability-uiAbility.md)): void;

注册监听应用上下文的生命周期后，在ability迁移时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 | 

**示例：**

MyAbilityStage.ts
```ts
import AbilityLifecycleCallback from "@ohos.app.ability.AbilityLifecycleCallback";
import AbilityStage from "@ohos.app.ability.AbilityStage"

// 声明ability生命周期回调
let abilityLifecycleCallback  =  {
    onAbilityCreate(ability){
        console.log("AbilityLifecycleCallback onAbilityCreate.");        
    },
    onWindowStageCreate(ability, windowStage){
        console.log("AbilityLifecycleCallback onWindowStageCreate.");          
    },
    onWindowStageActive(ability, windowStage){
        console.log("AbilityLifecycleCallback onWindowStageActive.");          
    },
    onWindowStageInactive(ability, windowStage){
        console.log("AbilityLifecycleCallback onWindowStageInactive.");
    },
    onWindowStageDestroy(ability, windowStage){
        console.log("AbilityLifecycleCallback onWindowStageDestroy."); 
    },
    onAbilityDestroy(ability){
        console.log("AbilityLifecycleCallback onAbilityDestroy.");             
    },
    onAbilityForeground(ability){
        console.log("AbilityLifecycleCallback onAbilityForeground.");             
    },
    onAbilityBackground(ability){
        console.log("AbilityLifecycleCallback onAbilityBackground.");              
    },
    onAbilityContinue(ability){
        console.log("AbilityLifecycleCallback onAbilityContinue.");
    }
}

export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate");
        // 1.通过context属性获取applicationContext
        let applicationContext = this.context.getApplicationContext();
        // 2.通过applicationContext注册监听应用内生命周期
        try {
            globalThis.lifecycleId = applicationContext.on("abilityLifecycle", abilityLifecycleCallback);
            console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleId));
        } catch (paramError) {
            console.log("error: " + paramError.code + " ," + paramError.message);
        }
    }
}
```

MyAbility.ts
```ts
import UIAbility from "ohos.app.ability.UIAbility"

export default class MyAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        // 3.通过applicationContext注销监听应用内生命周期
        applicationContext.off("abilityLifecycle", globalThis.lifecycleId, (error) => {
            if (error.code != 0) {
                console.log("unregisterAbilityLifecycleCallback failed, error: " + JSON.stringify(error));
            } else {
                console.log("unregisterAbilityLifecycleCallback success.");
            }
        });
    }
}
```