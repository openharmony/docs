# @ohos.app.ability.ExtensionAbility

The **ExtensionAbility** module manages the Extension ability lifecycle and context, such as creating and destroying an Extension ability, and dumping client information.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import ExtensionAbility from '@ohos.app.ability.ExtensionAbility';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**  

  ```ts
  class MyExtensionAbility extends ExtensionAbility {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, config:' + JSON.stringify(config));
      }

      onMemoryLevel(level) {
          console.log('onMemoryLevel, level:' + JSON.stringify(level));
      }
  }
  ```
