# AbilityLifecycleCallback

> **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


A callback class that provides APIs, such as **onAbilityCreate**, **onAbilityWindowStageCreate**, and **onAbilityWindowStageDestroy**, to listen for the lifecycle of the application context.


## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: Ability): void;

Called when an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.| 


## AbilityLifecycleCallback.onAbilityWindowStageCreate

onAbilityWindowStageCreate(ability: Ability): void;

Called when the window stage of an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  


## AbilityLifecycleCallback.onAbilityWindowStageDestroy

onAbilityWindowStageDestroy(ability: Ability): void;

Called when the window stage of an ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [Ability](js-apis-application-ability.md#Ability) | Yes| **Ability** object.|  


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
          // 1. Obtain applicationContext through the context attribute.
          let applicationContext = this.context.getApplicationContext();
          // 2. Use applicationContext to register a listener for the ability lifecycle in the application.
          let lifecycleid = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
          console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleid));       
      }
  }
  ```
