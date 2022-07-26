# ApplicationContext

The **ApplicationContext** module provides application-level context. You can use the APIs of this module to register and deregister the ability lifecycle listener in an application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## How to Use

Before calling any APIs in **ApplicationContext**, obtain an **ApplicationContext** instance through the **context** instance.

```js
let applicationContext = this.context.getApplicationContext();
```


## ApplicationContext.registerAbilityLifecycleCallback

registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): **number**;

Registers a listener to monitor the ability lifecycle of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| [AbilityLifecycleCallback](js-apis-application-abilityLifecycleCallback.md) | callback | Yes  | Callback used to return the ID of the registered listener.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| number | ID of the registered listener. The ID is incremented by 1 each time the listener is registered. When the ID exceeds 2^63-1, **-1** is returned.|

**Example**

  ```js
import AbilityStage from "@ohos.application.AbilityStage";

var lifecycleId;

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
        lifecycleId = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
        console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleId));
    }
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.unregisterAbilityLifecycleCallback(lifecycleId, (error, data) => {
            console.log("unregisterAbilityLifecycleCallback success, err: " + JSON.stringify(error));
        });
    }
}
  ```


## ApplicationContext.unregisterAbilityLifecycleCallback

unregisterAbilityLifecycleCallback(callbackId: **number**,  callback: AsyncCallback<**void**>): **void**;

Deregisters the listener that monitors the ability lifecycle of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | Yes  | ID of the listener to deregister.|
| AsyncCallback | callback | Yes  | Callback used to return the result.                  |

**Example**

  ```js
  let applicationContext = this.context.getApplicationContext();
  let lifecycleId = 1;
  console.log("stage applicationContext: " + JSON.stringify(applicationContext));
  applicationContext.unregisterAbilityLifecycleCallback(lifecycleId, (error, data) => {
      console.log("unregisterAbilityLifecycleCallback success, err: " + JSON.stringify(error));
  });
  ```

## ApplicationContext.registerEnvironmentCallback

registerEnvironmentCallback(callback: EnvironmentCallback): **number**;

Registers a listener for system environment changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| [EnvironmentCallback](js-apis-application-EnvironmentCallback.md) | callback | Yes  | Callback used to return the ID of the registered listener.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| number | ID of the registered listener. The ID is incremented by 1 each time the listener is registered. When the ID exceeds 2^63-1, **-1** is returned.|

**Example**

  ```js
import AbilityStage from "@ohos.application.AbilityStage";

var callbackId;

export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
        globalThis.applicationContext = this.context.getApplicationContext();
        let EnvironmentCallback = {
            onConfigurationUpdated(config){
                console.log("onConfigurationUpdated config:" + JSON.stringify(config));
            },
        }
        // 1. Obtain an applicationContext object.
        let applicationContext = globalThis.applicationContext;
        // 2. Use applicationContext to register a listener for the ability lifecycle in the application.
        callbackId = applicationContext.registerEnvironmentCallback(EnvironmentCallback);
        console.log("registerEnvironmentCallback number: " + JSON.stringify(callbackId));
    }
    onDestroy() {
        let applicationContext = globalThis.applicationContext;
        applicationContext.unregisterEnvironmentCallback(callbackId, (error, data) => {
            console.log("unregisterEnvironmentCallback success, err: " + JSON.stringify(error));
        });
    }
}
  ```

## ApplicationContext.unregisterEnvironmentCallback

unregisterEnvironmentCallback(callbackId: **number**,  callback: AsyncCallback<**void**>): **void**;

Deregisters the listener for system environment changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | Yes  | ID of the listener to deregister.  |
| AsyncCallback | callback | Yes  | Callback used to return the result.                 |

**Example**

  ```js
  let applicationContext = this.context.getApplicationContext();
  let callbackId = 1;
  applicationContext.unregisterEnvironmentCallback(callbackId, (error, data) => {
      console.log("unregisterEnvironmentCallback success, err: " + JSON.stringify(error));
  });
  ```
