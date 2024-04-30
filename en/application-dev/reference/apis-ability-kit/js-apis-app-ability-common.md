# @ohos.app.ability.common (Context)

You can use this module to reference the ability public module class.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```
## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name       | Type                | Description                                                        |
| ----------- | -------------------- | ------------------------------------------------------------ |
| UIAbilityContext    | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)               | Level-2 module **UIAbilityContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.                               |
| AbilityStageContext   | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md)               | Level-2 module **AbilityStageContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ApplicationContext   | [ApplicationContext](js-apis-inner-application-applicationContext.md)               | Level-2 module **ApplicationContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| BaseContext   | [BaseContext](js-apis-inner-application-baseContext.md)               | Level-2 module **BaseContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| Context   | [Context](js-apis-inner-application-context.md)               | Level-2 module **Context**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ExtensionContext   | [ExtensionContext](js-apis-inner-application-extensionContext.md)               | Level-2 module **ExtensionContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| FormExtensionContext   | [FormExtensionContext](../apis-form-kit/js-apis-inner-application-formExtensionContext.md)               | Level-2 module **FormExtensionContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| VpnExtensionContext<sup>11+<sup> | VpnExtensionContext | Level-2 module **VpnExtensionContext**.|
| EventHub   | [EventHub](js-apis-inner-application-eventHub.md)               | Level-2 module **EventHub**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)               | Level-2 module **PacMap**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md)               | Level-2 module **AbilityResult**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AbilityStartCallback<sup>11+<sup>   | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md)               | Level-2 module **AbilityStartCallback**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md)               | Level-2 module **ConnectOptions**.|
| EmbeddableUIAbilityContext<sup>12+<sup>   | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md)               | Level-2 module **EmbeddableUIAbilityContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

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
let vpnExtensionContext: common.VpnExtensionContext;
let eventHub: common.EventHub;
let pacMap: common.PacMap;
let abilityResult: common.AbilityResult;
let abilityStartCallback: common.AbilityStartCallback;
let connectOptions: common.ConnectOptions;
let embeddableUIAbilityContext: common.EmbeddableUIAbilityContext;
```
