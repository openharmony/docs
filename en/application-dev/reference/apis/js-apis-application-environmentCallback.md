# @ohos.application.EnvironmentCallback (EnvironmentCallback)

The **EnvironmentCallback** module provides APIs, such as **onConfigurationUpdated** and **onMemoryLevel**, for the application context to listen for system environment changes.

> **NOTE**
> 
> The APIs of this module are supported since API version 9 and are deprecated in versions later than API version 9. You are advised to use [@ohos.app.ability.EnvironmentCallback](js-apis-app-ability-environmentCallback.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import EnvironmentCallback from "@ohos.application.EnvironmentCallback";
```


## EnvironmentCallback.onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

Called when the system environment changes.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | config | [Configuration](js-apis-application-configuration.md) | Yes| **Configuration** object after the change.|

## EnvironmentCallback.onMemoryLevel

onMemoryLevel(level: number): void;

Called when the system memory level changes.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | level  | [MemoryLevel](js-apis-application-abilityConstant.md#abilityconstantmemorylevel) | Yes| New memory level.|

**Example**

  ```ts
import UIAbility from '@ohos.app.ability.UIAbility';

var callbackId;

export default class EntryAbility extends UIAbility {
    onCreate() {
        console.log("MyAbility onCreate")
        globalThis.applicationContext = this.context.getApplicationContext();
        let EnvironmentCallback  =  {
            onConfigurationUpdated(config){
                console.log("onConfigurationUpdated config:" + JSON.stringify(config));
            },
            onMemoryLevel(level){
                console.log("onMemoryLevel level:" + level);
            }
        }
        // 1. Obtain an applicationContext object.
        let applicationContext = globalThis.applicationContext;
        // 2. Register a listener for the environment changes through the applicationContext object.
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
