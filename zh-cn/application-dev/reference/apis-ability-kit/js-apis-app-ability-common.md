# @ohos.app.ability.common (应用上下文Context)

开发者可以通过该模块引用Ability公共模块类。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```
## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 类型                 | 说明                                                         |
| ----------- | -------------------- | ------------------------------------------------------------ |
| UIAbilityContext    | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)               | UIAbilityContext二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。                                |
| AbilityStageContext   | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md)               | AbilityStageContext二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| ApplicationContext   | [ApplicationContext](js-apis-inner-application-applicationContext.md)               | ApplicationContext二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| BaseContext   | [BaseContext](js-apis-inner-application-baseContext.md)               | BaseContext二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| Context   | [Context](js-apis-inner-application-context.md)               | Context二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| ExtensionContext   | [ExtensionContext](js-apis-inner-application-extensionContext.md)               | ExtensionContext二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| FormExtensionContext   | [FormExtensionContext](../apis-form-kit/js-apis-inner-application-formExtensionContext.md)               | FormExtensionContext二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| VpnExtensionContext<sup>11+<sup> | VpnExtensionContext | VpnExtensionContext二级模块。 |
| EventHub   | [EventHub](js-apis-inner-application-eventHub.md)               | EventHub二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)               | PacMap二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md)               | AbilityResult二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| AbilityStartCallback<sup>11+<sup>   | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md)               | AbilityStartCallback二级模块。<br>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md)               | ConnectOptions二级模块。 |
| EmbeddableUIAbilityContext<sup>12+<sup>   | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md)               | EmbeddableUIAbilityContext二级模块。<br>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。 |

**示例：**

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
```
