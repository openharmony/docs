# AbilityStageContext

The **AbilityStageContext** module, inherited from [Context](js-apis-inner-application-context.md), implements the context of an ability stage.

This module provides APIs for accessing a specific ability stage. You can use the APIs to obtain the **ModuleInfo** object and environment configuration of an ability stage.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Usage

The ability stage context is obtained through an **AbilityStage** instance.

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    let abilityStageContext = this.context;
  }
}
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | Yes | No | **ModuleInfo** object corresponding to the **AbilityStage**. |
| config | [Configuration](js-apis-app-ability-configuration.md) | Yes | No | Configuration for the environment where the application is running. |
