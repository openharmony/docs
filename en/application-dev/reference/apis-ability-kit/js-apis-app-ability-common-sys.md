# @ohos.app.ability.common (Ability Common Module) (System APIs)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

You can use this module to reference the ability public module class.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.common (Ability Common Module)](js-apis-app-ability-common.md).

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## ServiceExtensionContext

type ServiceExtensionContext = _ServiceExtensionContext.default

Level-2 module ServiceExtensionContext.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_ServiceExtensionContext.default](js-apis-inner-application-serviceExtensionContext-sys.md) | Level-2 module ServiceExtensionContext.|

## AutoFillExtensionContext<sup>11+<sup>

type AutoFillExtensionContext = _AutoFillExtensionContext.default

Level-2 module AutoFillExtensionContext.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_AutoFillExtensionContext.default](js-apis-inner-application-autoFillExtensionContext-sys.md) | Level-2 module AutoFillExtensionContext.|

## AutoStartupInfo<sup>11+<sup>

type AutoStartupInfo = _AutoStartupInfo

Level-2 module AutoStartupInfo.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | Level-2 module AutoStartupInfo.|

## AutoStartupCallback<sup>11+<sup>

type AutoStartupCallback = _AutoStartupCallback

Level-2 module AutoStartupCallback.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md) | Level-2 module AutoStartupCallback.|

## UIServiceExtensionContext<sup>14+<sup>

type UIServiceExtensionContext = _UIServiceExtensionContext.default

Level-2 module UIServiceExtensionContext.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_UIServiceExtensionContext.default](js-apis-inner-application-uiserviceExtensionContext-sys.md) | Level-2 module UIServiceExtensionContext.|

## UIServiceHostProxy<sup>14+<sup>

type UIServiceHostProxy = _UIServiceHostProxy.default

Level-2 module UIServiceHostProxy.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_UIServiceHostProxy.default](js-apis-inner-application-uiservicehostproxy-sys.md) | Level-2 module UIServiceHostProxy.|

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
let autoFillExtensionContext: common.AutoFillExtensionContext;
let uiServiceExtensionContext: common.UIServiceExtensionContext;
let uiServiceHostProxy: common.UIServiceHostProxy;
```
