# @ohos.app.ability.Ability

The **Ability** module manages the ability lifecycle and context, such as creating and destroying an ability, and dumping client information.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import Ability from '@ohos.app.ability.Ability';
```

## Ability.onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void;

Called when the configuration of the environment where the ability is running is updated.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | newConfig | [Configuration](js-apis-app-ability-configuration.md) | Yes| New configuration.| 

**Example**
    
  ```ts
  class myAbility extends Ability {
      onConfigurationUpdate(config) {
          console.log('onConfigurationUpdate, config:' + JSON.stringify(config));
      }
  }
  ```

## Ability.onMemoryLevel

onMemoryLevel(level: AbilityConstant.MemoryLevel): void;

Called when the system has decided to adjust the memory level. For example, this API can be used when there is not enough memory to run as many background processes as possible.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#abilityconstantmemorylevel) | Yes| Memory level that indicates the memory usage status. When the specified memory level is reached, a callback will be invoked and the system will start adjustment.| 

**Example**
    
  ```ts
  class myAbility extends Ability {
    onMemoryLevel(level) {
        console.log('onMemoryLevel, level:' + JSON.stringify(level));
    } 
  }
  ```
