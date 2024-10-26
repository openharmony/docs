# @ohos.app.ability.common (Context)

You can use this module to reference the ability public module class.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```
## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read Only| Optional| Description       |
| ---- | ---- | ---- | ---- | ---------- |
| UIAbilityContext    | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | No | No | Level-2 module **UIAbilityContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.                               |
| AbilityStageContext   | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | No | No | Level-2 module **AbilityStageContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| ApplicationContext   | [ApplicationContext](js-apis-inner-application-applicationContext.md) | No | No | Level-2 module **ApplicationContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| BaseContext   | [BaseContext](js-apis-inner-application-baseContext.md) | No | No | Level-2 module **BaseContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| Context   | [Context](js-apis-inner-application-context.md) | No | No | Level-2 module **Context**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| ExtensionContext   | [ExtensionContext](js-apis-inner-application-extensionContext.md) | No | No | Level-2 module **ExtensionContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| FormExtensionContext   | [FormExtensionContext](../apis-form-kit/js-apis-inner-application-formExtensionContext.md) | No | No | Level-2 module **FormExtensionContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| VpnExtensionContext<sup>11+<sup> | VpnExtensionContext  | No | No | Level-2 module **VpnExtensionContext**.<br>**Model restriction**: This API can be used only in the stage model.|
| EventHub   | [EventHub](js-apis-inner-application-eventHub.md)  | No | No | Level-2 module **EventHub**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap) | No | No | Level-2 module **PacMap**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md) | No | No | Level-2 module **AbilityResult**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| AbilityStartCallback<sup>11+<sup>   | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | No | No | Level-2 module **AbilityStartCallback**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**Model restriction**: This API can be used only in the stage model.|
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | No | No | Level-2 module **ConnectOptions**.<br>**Model restriction**: This API can be used only in the stage model.|
| EmbeddableUIAbilityContext<sup>12+<sup>   | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md) | No | No | Level-2 module **EmbeddableUIAbilityContext**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>**Model restriction**: This API can be used only in the stage model.|
| UIServiceProxy <sup>13+<sup> | [UIServiceProxy ](js-apis-inner-application-uiserviceproxy.md) | No | No | Level-2 module **UIServiceProxy**.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**Model restriction**: This API can be used only in the stage model.|
| UIServiceExtensionConnectCallback  <sup>13+<sup> | [UIServiceExtensionConnectCallback](js-apis-inner-application-uiServiceExtensionconnectcallback.md) | No | No | Level-2 module **UIServiceExtensionConnectCallback**.<br>**Atomic service API**: This API can be used in atomic services since API version 13.<br>**Model restriction**: This API can be used only in the stage model.|

**Example**

```ts
import { common } from '@kit.AbilityKit';

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
let uiServiceProxy : common.UIServiceProxy;
let uiServiceExtensionConnectCallback : common.UIServiceExtensionConnectCallback;
```
