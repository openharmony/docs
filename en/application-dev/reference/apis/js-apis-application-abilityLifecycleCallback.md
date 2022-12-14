# @ohos.application.AbilityLifecycleCallback

The **AbilityLifecycleCallback** module provides callbacks, such as **onAbilityCreate**, **onWindowStageCreate**, and **onWindowStageDestroy**, to receive lifecycle state changes in the application context.

> **NOTE**
> 
> The APIs of this module are supported and deprecated since API version 9. You are advised to use [@ohos.app.ability.AbilityLifecycleCallback](js-apis-app-ability-abilityLifecycleCallback.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import AbilityLifecycleCallback from "@ohos.application.AbilityLifecycleCallback";
```


## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: Ability): void;

Called when an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onWindowStageCreate

onWindowStageCreate(ability: Ability, windowStage: window.WindowStage): void;

Called when the window stage of an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|    


## AbilityLifecycleCallback.onWindowStageActive

onWindowStageActive(ability: Ability, windowStage: window.WindowStage): void;

Called when the window stage of an ability gains focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|    


## AbilityLifecycleCallback.onWindowStageInactive

onWindowStageInactive(ability: Ability, windowStage: window.WindowStage): void;

Called when the window stage of an ability loses focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|  


## AbilityLifecycleCallback.onWindowStageDestroy

onWindowStageDestroy(ability: Ability, windowStage: window.WindowStage): void;

Called when the window stage of an ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|  


## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: Ability): void;

Called when an ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: Ability): void;

Called when an ability is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: Ability): void;

Called when an ability is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: Ability): void;

Called when an ability is continued on another device.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 

**Example**
    

```ts
import AbilityStage from "@ohos.application.AbilityStage";

var lifecycleid;

export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
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
        lifecycleid = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
        console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleid));       
    }
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.unregisterAbilityLifecycleCallback(lifecycleid, (error, data) => {
        console.log("unregisterAbilityLifecycleCallback success, err: " + JSON.stringify(error));
        });
    }
}
```
