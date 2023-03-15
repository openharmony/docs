# @ohos.app.ability.common (Context)

The **Common** module provides all level-2 module APIs for developers to export.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Type                | Description                                                        |
| ----------- | -------------------- | ------------------------------------------------------------ |
| UIAbilityContext    | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)               | Level-2 module **UIAbilityContext**.                               |
| AbilityStageContext   | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md)               | Level-2 module **AbilityStageContext**.|
| ApplicationContext   | [ApplicationContext](js-apis-inner-application-applicationContext.md)               | Level-2 module **ApplicationContext**.|
| BaseContext   | [BaseContext](js-apis-inner-application-baseContext.md)               | Level-2 module **BaseContext**.|
| Context   | [Context](js-apis-inner-application-context.md)               | Level-2 module **Context**.|
| ExtensionContext   | [ExtensionContext](js-apis-inner-application-extensionContext.md)               | Level-2 module **ExtensionContext**.|
| FormExtensionContext   | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md)               | Level-2 module **FormExtensionContext**.|
| ServiceExtensionContext | [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext.md) | Level-2 module **ServiceExtensionContext**.|
| EventHub   | [EventHub](js-apis-inner-application-eventHub.md)               | Level-2 module **EventHub**.|
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#PacMap)               | Level-2 module **PacMap**.|
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md)               | Level-2 module **AbilityResult**.|
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md)               | Level-2 module **ConnectOptions**.|

**Example**
```ts
import common from '@ohos.app.ability.common';

let uiAbilityContext: common.UIAbilityContext;
let abilityStageContext: common.AbilityStageContext;
let applicationContext: common.ApplicationContext;
let baseContext: common.BaseContext;
let context: common.Context;
let extensionContext: common.ExtensionContext;
let formExtensionContext: common.FormExtensionContext;
let eventHub: common.EventHub;
let pacMap: common.PacMap;
let abilityResult: common.AbilityResult;
let connectOptions: common.ConnectOptions;
```
