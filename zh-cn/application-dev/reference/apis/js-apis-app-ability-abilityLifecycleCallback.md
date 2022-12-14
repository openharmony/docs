# AbilityLifecycleCallback

AbilityLifecycleCallback模块提供应用上下文ApplicationContext的生命周期监听方法的回调类的能力，包括onAbilityCreate、onWindowStageCreate、onWindowStageDestroy等方法。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。


## 导入模块

```ts
import AbilityLifecycleCallback from "@ohos.app.ability.AbilityLifecycleCallback";
```


## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability创建时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onWindowStageCreate

onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void;

注册监听应用上下文的生命周期后，在windowStage创建时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 |  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |    


## AbilityLifecycleCallback.onWindowStageActive

onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void;

注册监听应用上下文的生命周期后，在windowStage获焦时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 |  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |    


## AbilityLifecycleCallback.onWindowStageInactive

onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void;

注册监听应用上下文的生命周期后，在windowStage失焦时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 |  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |  


## AbilityLifecycleCallback.onWindowStageDestroy

onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void;

注册监听应用上下文的生命周期后，在windowStage销毁时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 |  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |  


## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability销毁时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability的状态从后台转到前台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability的状态从前台转到后台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability迁移时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md#Ability) | 是 | 当前Ability对象 | 

**示例：**
    

  ```ts
  import UIAbility from "@ohos.app.ability.UIAbility";
  
  export default class MyAbility extends UIAbility {
      onCreate() {
          console.log("MyAbility onCreate")
          let AbilityLifecycleCallback  =  {
              onAbilityCreate(ability){
                  console.log("AbilityLifecycleCallback onAbilityCreate ability:" + JSON.stringify(ability));        
              },
            onWindowStageCreate(ability, windowStage){
                console.log("AbilityLifecycleCallback onWindowStageCreate ability:" + JSON.stringify(ability)); 
                console.log("AbilityLifecycleCallback onWindowStageCreate windowStage:" + JSON.stringify(windowStage));           
            },
            onWindowStageActive(ability, windowStage){
                console.log("AbilityLifecycleCallback onWindowStageActive ability:" + JSON.stringify(ability)); 
                console.log("AbilityLifecycleCallback onWindowStageActive windowStage:" + JSON.stringify(windowStage));           
            },
            onWindowStageInactive(ability, windowStage){
                console.log("AbilityLifecycleCallback onWindowStageInactive ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageInactive windowStage:" + JSON.stringify(windowStage));  
            },
            onWindowStageDestroy(ability, windowStage){
                console.log("AbilityLifecycleCallback onWindowStageDestroy ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageDestroy windowStage:" + JSON.stringify(windowStage));  
            },
              onAbilityDestroy(ability){
                  console.log("AbilityLifecycleCallback onAbilityDestroy ability:" + JSON.stringify(ability));             
              },
              onAbilityForeground(ability){
                  console.log("AbilityLifecycleCallback onAbilityForeground ability:" + JSON.stringify(ability));             
              },
              onAbilityBackground(ability){
                  console.log("AbilityLifecycleCallback onAbilityBackground ability:" + JSON.stringify(ability));              
              },
              onAbilityContinue(ability){
                  console.log("AbilityLifecycleCallback onAbilityContinue ability:" + JSON.stringify(ability));
              }
          }
          // 1.通过context属性获取applicationContext
          let applicationContext = this.context.getApplicationContext();
          // 2.通过applicationContext注册监听应用内生命周期
          let lifecycleid = applicationContext.on("abilityLifecycle", AbilityLifecycleCallback);
          console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleid));       
      },
      onDestroy() {
          let applicationContext = this.context.getApplicationContext();
          applicationContext.off("abilityLifecycle", lifecycleid, (error, data) => {
              console.log("unregisterAbilityLifecycleCallback success, err: " + JSON.stringify(error));
          });
      }
  }
  ```