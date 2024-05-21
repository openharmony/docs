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
import common from '@ohos.app.ability.common';
```
## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 类型                 | 说明                                                         |
| ----------- | -------------------- | ------------------------------------------------------------ |
| ServiceExtensionContext | [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext-sys.md) | ServiceExtensionContext二级模块。<br>**系统接口**：此接口为系统接口。|
| AutoFillExtensionContext<sup>11+<sup>   | [AutoFillExtensionContext](js-apis-inner-application-autoFillExtensionContext-sys.md)               | AutoFillExtensionContext二级模块。<br>**系统接口**：此接口为系统接口。 |
| AutoStartupInfo<sup>11+<sup>   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)               | AutoStartupInfo二级模块。<br>**系统接口**：此接口为系统接口。 |
| AutoStartupCallback<sup>11+<sup>   | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md)               | AutoStartupCallback二级模块。<br>**系统接口**：此接口为系统接口。 |

**示例：**

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
let autoFillExtensionContext: common.AutoFillExtensionContext;
```
