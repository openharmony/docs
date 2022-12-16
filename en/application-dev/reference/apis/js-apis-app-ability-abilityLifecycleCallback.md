# @ohos.app.ability.abilityLifecycleCallback

The **AbilityLifecycleCallback** module provides callbacks, such as **onAbilityCreate**, **onWindowStageCreate**, and **onWindowStageDestroy**, to receive lifecycle state changes in the application context.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import AbilityLifecycleCallback from "@ohos.app.ability.AbilityLifecycleCallback";
```


## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: UIAbility): void;

Called when an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onWindowStageCreate

onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void;

Called when the window stage of an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|    


## AbilityLifecycleCallback.onWindowStageActive

onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void;

Called when the window stage of an ability gains focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|    


## AbilityLifecycleCallback.onWindowStageInactive

onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void;

Called when the window stage of an ability loses focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|  


## AbilityLifecycleCallback.onWindowStageDestroy

onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void;

Called when the window stage of an ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|  


## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: UIAbility): void;

Called when an ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: UIAbility): void;

Called when an ability is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: UIAbility): void;

Called when an ability is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: UIAbility): void;

Called when an ability is continued on another device.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 

**Example**
    

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
          // 1. Obtain applicationContext through the context attribute.
          let applicationContext = this.context.getApplicationContext();
          // 2. Use applicationContext to register a listener for the ability lifecycle in the application.
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
