# @ohos.app.ability.common (应用上下文Context)

开发者可以通过该模块引用Ability公共模块类。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```
## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明        |
| ---- | ---- | ---- | ---- | ---------- |
| UIAbilityContext    | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | 否  | 否  | UIAbilityContext二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。                                |
| AbilityStageContext   | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | 否  | 否  | AbilityStageContext二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| ApplicationContext   | [ApplicationContext](js-apis-inner-application-applicationContext.md) | 否  | 否  | ApplicationContext二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| BaseContext   | [BaseContext](js-apis-inner-application-baseContext.md) | 否  | 否  | BaseContext二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| Context   | [Context](js-apis-inner-application-context.md) | 否  | 否  | Context二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| ExtensionContext   | [ExtensionContext](js-apis-inner-application-extensionContext.md) | 否  | 否  | ExtensionContext二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| FormExtensionContext   | [FormExtensionContext](../apis-form-kit/js-apis-inner-application-formExtensionContext.md) | 否  | 否  | FormExtensionContext二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| VpnExtensionContext<sup>11+<sup> | VpnExtensionContext  | 否  | 否  | VpnExtensionContext二级模块。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| EventHub   | [EventHub](js-apis-inner-application-eventHub.md)  | 否  | 否  | EventHub二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| PacMap   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap) | 否  | 否  | PacMap二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| AbilityResult   | [AbilityResult](js-apis-inner-ability-abilityResult.md) | 否  | 否  | AbilityResult二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| AbilityStartCallback<sup>11+<sup>   | [AbilityStartCallback](js-apis-inner-application-abilityStartCallback.md) | 否  | 否  | AbilityStartCallback二级模块。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| ConnectOptions   | [ConnectOptions](js-apis-inner-ability-connectOptions.md) | 否  | 否  | ConnectOptions二级模块。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| EmbeddableUIAbilityContext<sup>12+<sup>   | [EmbeddableUIAbilityContext](js-apis-inner-application-EmbeddableUIAbilityContext.md) | 否  | 否  | EmbeddableUIAbilityContext二级模块。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| UIServiceProxy <sup>13+<sup> | [UIServiceProxy ](js-apis-inner-application-uiserviceproxy.md) | 否  | 否  | UIServiceProxy 二级模块。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |
| UIServiceExtensionConnectCallback  <sup>13+<sup> | [UIServiceExtensionConnectCallback](js-apis-inner-application-uiServiceExtensionconnectcallback.md) | 否  | 否  | UIServiceExtensionConnectCallback 二级模块。<br/>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。<br/> **模型约束：** 此接口仅可在Stage模型下使用。 |

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
let uiServiceProxy : common.UIServiceProxy;
let uiServiceExtensionConnectCallback : common.UIServiceExtensionConnectCallback;
```
