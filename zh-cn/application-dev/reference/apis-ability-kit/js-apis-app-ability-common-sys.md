# @ohos.app.ability.common (Ability公共模块)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

开发者可以通过该模块引用Ability公共模块类。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.common (Ability公共模块)](js-apis-app-ability-common.md)。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## ServiceExtensionContext

type ServiceExtensionContext = _ServiceExtensionContext.default

ServiceExtensionContext二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_ServiceExtensionContext.default](js-apis-inner-application-serviceExtensionContext-sys.md) | ServiceExtensionContext二级模块。 |

## AutoFillExtensionContext<sup>11+<sup>

type AutoFillExtensionContext = _AutoFillExtensionContext.default

AutoFillExtensionContext二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AutoFillExtensionContext.default](js-apis-inner-application-autoFillExtensionContext-sys.md) | AutoFillExtensionContext二级模块。 |

## AutoStartupInfo<sup>11+<sup>

type AutoStartupInfo = _AutoStartupInfo

AutoStartupInfo二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | AutoStartupInfo二级模块。 |

## AutoStartupCallback<sup>11+<sup>

type AutoStartupCallback = _AutoStartupCallback

AutoStartupCallback二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md) | AutoStartupCallback二级模块。 |

## UIServiceExtensionContext<sup>14+<sup>

type UIServiceExtensionContext = _UIServiceExtensionContext.default

UIServiceExtensionContext二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_UIServiceExtensionContext.default](js-apis-inner-application-uiserviceExtensionContext-sys.md) | UIServiceExtensionContext二级模块。 |

## UIServiceHostProxy<sup>14+<sup>

type UIServiceHostProxy = _UIServiceHostProxy.default

UIServiceHostProxy二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_UIServiceHostProxy.default](js-apis-inner-application-uiservicehostproxy-sys.md) | UIServiceHostProxy二级模块。 |

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
