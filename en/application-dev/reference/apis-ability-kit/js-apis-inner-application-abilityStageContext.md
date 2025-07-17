# AbilityStageContext

The AbilityStageContext module implements the context of an ability stage. It inherits from [Context](js-apis-inner-application-context.md).

This module provides APIs for accessing a specific ability stage. You can use the APIs to obtain the ModuleInfo object and environment configuration of an ability stage.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | No| No| ModuleInfo object corresponding to the ability stage.|
| config | [Configuration](js-apis-app-ability-configuration.md) | No| No| Configuration for the environment where the application is running.|

**Example**

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    let abilityStageContext = this.context;
    // Obtain the current module name.
    let name = abilityStageContext.currentHapModuleInfo.name;
    // Obtain the current language.
    let language = abilityStageContext.config.language;
  }
}
```
