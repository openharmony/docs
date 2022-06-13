# AbilityLifecycleCallback

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。


应用上下文ApplicationContext的生命周期监听方法的回调类，里面提供了onAbilityCreate、onAbilityWindowStageCreate、onAbilityWindowStageDestroy等方法。

## 导入模块

```js
import AbilityLifecycleCallback from "@ohos.application.abilityLifecycleCallback";
```


## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: Ability): void;

注册监听应用上下文的生命周期后，在ability创建时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityWindowStageCreate

onAbilityWindowStageCreate(ability: Ability): void;

注册监听应用上下文的生命周期后，在windowStage创建时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | 是 | 当前Ability对象 |  


## AbilityLifecycleCallback.onAbilityWindowStageDestroy

onAbilityWindowStageDestroy(ability: Ability): void;

注册监听应用上下文的生命周期后，在windowStage销毁时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | 是 | 当前Ability对象 |  


## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: Ability): void;

注册监听应用上下文的生命周期后，在ability销毁时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: Ability): void;

注册监听应用上下文的生命周期后，在ability的状态从后台转到前台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: Ability): void;

注册监听应用上下文的生命周期后，在ability的状态从前台转到后台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | 是 | 当前Ability对象 | 


## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: Ability): void;

注册监听应用上下文的生命周期后，在ability迁移时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | 是 | 当前Ability对象 | 

**示例：**
    

  ```js
  import AbilityStage from "@ohos.application.AbilityStage";
  
  export default class MyAbilityStage extends AbilityStage {
      onCreate() {
          console.log("MyAbilityStage onCreate")
          let AbilityLifecycleCallback  =  {
              onAbilityCreate(ability){
                  console.log("AbilityLifecycleCallback onAbilityCreate ability:" + JSON.stringify(ability));        
              },
              onAbilityWindowStageCreate(ability){
                  console.log("AbilityLifecycleCallback onAbilityWindowStageCreate ability:" + JSON.stringify(ability));           
              },
              onAbilityWindowStageDestroy(ability){
                  console.log("AbilityLifecycleCallback onAbilityWindowStageDestroy ability:" + JSON.stringify(ability));
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
          let lifecycleid = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
          console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleid));       
      }
  }
  ```