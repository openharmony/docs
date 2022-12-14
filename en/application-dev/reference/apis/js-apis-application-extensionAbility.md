# @ohos.application.ExtensionAbility

The **ExtensionAbility** module manages the Extension ability lifecycle and context, such as creating and destroying an Extension ability, and dumping client information.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import ExtensionAbility from '@ohos.application.ExtensionAbility';
```

## ExtensionAbility.onConfigurationUpdated

onConfigurationUpdated(newConfig: Configuration): void;

Called when the configuration of the environment where the ability is running is updated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | newConfig | [Configuration](js-apis-application-configuration.md) | Yes| New configuration.| 

**Example**
    
  ```ts
  class MyExtensionAbility extends ExtensionAbility {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, config:' + JSON.stringify(config));
      }
  }
  ```

## ExtensionAbility.onMemoryLevel

onMemoryLevel(level: AbilityConstant.MemoryLevel): void;

Called when the system has decided to adjust the memory level. For example, this API can be used when there is not enough memory to run as many background processes as possible.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-application-abilityConstant.md#abilityconstantmemorylevel) | Yes| Memory level that indicates the memory usage status. When the specified memory level is reached, a callback will be invoked and the system will start adjustment.| 

**Example**
    
  ```ts
  class MyExtensionAbility extends ExtensionAbility {
    onMemoryLevel(level) {
        console.log('onMemoryLevel, level:' + JSON.stringify(level));
    } 
  }
  ```
