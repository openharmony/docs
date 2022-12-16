# ApplicationContext

The **ApplicationContext** module provides application-level context. You can use the APIs of this module to register and deregister the ability lifecycle listener in an application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Usage

Before calling any APIs in **ApplicationContext**, obtain an **ApplicationContext** instance through the **context** instance.

```ts
let applicationContext = this.context.getApplicationContext();
```

## ApplicationContext.registerAbilityLifecycleCallback

registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): **number**;

Registers a listener to monitor the ability lifecycle of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| callback | [AbilityLifecycleCallback](js-apis-app-ability-abilityLifecycleCallback.md) | Yes  | Callback used to return the ID of the registered listener.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| number | ID of the registered listener. The ID is incremented by 1 each time the listener is registered. When the ID exceeds 2^63-1, **-1** is returned.|

**Example**

```ts
import Ability from "@ohos.application.Ability";

var lifecycleId;

export default class MyAbility extends Ability {
    onCreate() {
        console.log("MyAbility onCreate")
        let AbilityLifecycleCallback = {
            onAbilityCreate(ability) {
                console.log("AbilityLifecycleCallback onAbilityCreate ability:" + JSON.stringify(ability));
            },
            onWindowStageCreate(ability, windowStage) {
                console.log("AbilityLifecycleCallback onWindowStageCreate ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageCreate windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageActive(ability, windowStage) {
                console.log("AbilityLifecycleCallback onWindowStageActive ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageActive windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageInactive(ability, windowStage) {
                console.log("AbilityLifecycleCallback onWindowStageInactive ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageInactive windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageDestroy(ability, windowStage) {
                console.log("AbilityLifecycleCallback onWindowStageDestroy ability:" + JSON.stringify(ability));
                console.log("AbilityLifecycleCallback onWindowStageDestroy windowStage:" + JSON.stringify(windowStage));
            },
            onAbilityDestroy(ability) {
                console.log("AbilityLifecycleCallback onAbilityDestroy ability:" + JSON.stringify(ability));
            },
            onAbilityForeground(ability) {
                console.log("AbilityLifecycleCallback onAbilityForeground ability:" + JSON.stringify(ability));
            },
            onAbilityBackground(ability) {
                console.log("AbilityLifecycleCallback onAbilityBackground ability:" + JSON.stringify(ability));
            },
            onAbilityContinue(ability) {
                console.log("AbilityLifecycleCallback onAbilityContinue ability:" + JSON.stringify(ability));
            }
        }
        // 1. Obtain applicationContext through the context attribute.
        let applicationContext = this.context.getApplicationContext();
        // 2. Use applicationContext to register a listener for the ability lifecycle in the application.
        lifecycleId = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
        console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleId));
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
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                  |

**Example**

```ts
import Ability from "@ohos.application.Ability";

var lifecycleId;

export default class MyAbility extends Ability {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        console.log("stage applicationContext: " + JSON.stringify(applicationContext));
        applicationContext.unregisterAbilityLifecycleCallback(lifecycleId, (error, data) => {
            console.log("unregisterAbilityLifecycleCallback success, err: " + JSON.stringify(error));
        });
    }
}
```

## ApplicationContext.registerEnvironmentCallback

registerEnvironmentCallback(callback: EnvironmentCallback): **number**;

Registers a listener for system environment changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| callback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | Yes  | Callback used to return the ID of the registered listener.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| number | ID of the registered listener. The ID is incremented by 1 each time the listener is registered. When the ID exceeds 2^63-1, **-1** is returned.|

**Example**

```ts
import Ability from "@ohos.application.Ability";

var callbackId;

export default class MyAbility extends Ability {
    onCreate() {
        console.log("MyAbility onCreate")
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
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                 |

**Example**

```ts
import Ability from "@ohos.application.Ability";

var callbackId;

export default class MyAbility extends Ability {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.unregisterEnvironmentCallback(callbackId, (error, data) => {
            console.log("unregisterEnvironmentCallback success, err: " + JSON.stringify(error));
        });
    }
}
```
