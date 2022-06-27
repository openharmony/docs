# ApplicationContext

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

Provides application-level context and APIs for registering and deregistering the ability lifecycle listener in an application.

## Modules to Import

```
import Ability from '@ohos.application.Ability';
```

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
  let applicationContext = this.context.getApplicationContext();
  console.log("stage applicationContext: " + JSON.stringify(applicationContext));
  let lifecycleid = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
  console.log("registerAbilityLifecycleCallback number: " + JSON.stringify(lifecycleid));
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
  console.log("stage applicationContext: " + JSON.stringify(applicationContext));
  applicationContext.unregisterAbilityLifecycleCallback(lifecycleid, (error, data) => {
      console.log("unregisterAbilityLifecycleCallback success, err: " + JSON.stringify(error));
  });
  ```
