# @ohos.app.ability.common (应用上下文Context)(系统接口)

开发者可以通过该模块引用Ability公共模块类。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.common (应用上下文Context)](js-apis-app-ability-common.md)。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```
## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称  | 类型  | 只读  | 可选  | 说明            |
| ----- | ---- | ----- | ----- | -------------- |
| ServiceExtensionContext | [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext-sys.md) | 否  | 否  | ServiceExtensionContext二级模块。<br>**系统接口**：此接口为系统接口。|
| AutoFillExtensionContext<sup>11+<sup>   | [AutoFillExtensionContext](js-apis-inner-application-autoFillExtensionContext-sys.md) | 否  | 否  | AutoFillExtensionContext二级模块。<br>**系统接口**：此接口为系统接口。 |
| AutoStartupInfo<sup>11+<sup>   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | 否  | 否  | AutoStartupInfo二级模块。<br>**系统接口**：此接口为系统接口。 |
| AutoStartupCallback<sup>11+<sup>   | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md) | 否  | 否  | AutoStartupCallback二级模块。<br>**系统接口**：此接口为系统接口。 |
| UIServiceExtensionContext<sup>14+<sup> | [UIServiceExtensionContext ](js-apis-inner-application-uiserviceExtensionContext-sys.md) |  否  | 否  |UIServiceExtensionContext 二级模块。<br/>**系统接口**：此接口为系统接口。 |
| UIServiceHostProxy<sup>13+<sup> | [UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md) |  否  | 否  | UIServiceHostProxy  二级模块。<br/>**系统接口**：此接口为系统接口。 |

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
let autoFillExtensionContext: common.AutoFillExtensionContext;
let uiServiceExtensionContext: common.UIServiceExtensionContext;
let uiServiceHostProxy: common.UIServiceHostProxy;
```
