# @ohos.app.ability.common (Context) (System API)

You can use this module to reference the ability public module class.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.app.ability.common (Context)](js-apis-app-ability-common.md).

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```
## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name       | Type                | Description                                                        |
| ----------- | -------------------- | ------------------------------------------------------------ |
| ServiceExtensionContext | [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext-sys.md) | Level-2 module **ServiceExtensionContext**.<br>**System API**: This is a system API.|
| AutoFillExtensionContext<sup>11+<sup>   | [AutoFillExtensionContext](js-apis-inner-application-autoFillExtensionContext-sys.md)               | Level-2 module **AutoFillExtensionContext**.<br>**System API**: This is a system API.|
| AutoStartupInfo<sup>11+<sup>   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)               | Level-2 module **AutoStartupInfo**.<br>**System API**: This is a system API.|
| AutoStartupCallback<sup>11+<sup>   | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md)               | Level-2 module **AutoStartupCallback**.<br>**System API**: This is a system API.|

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
let autoFillExtensionContext: common.AutoFillExtensionContext;
```
