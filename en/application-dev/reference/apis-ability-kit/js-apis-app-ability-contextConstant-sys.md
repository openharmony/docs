# @ohos.app.ability.contextConstant (Context-related Constants) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy; @yangxuguang-huawei; @Luobniz21-->
<!--Designer: @ccllee1; @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=d829b404b25f83e4c48da22db445de147ed4fe46 translatedAt=2026-08-13T13:24:13.410Z pushedAt=2026-08-14T08:42:29.039Z -->

ContextConstant provides context-related enums, including the file encryption partition level and the process mode after a UIAbility is started.

**Since**: 26.0.0

> **NOTE**
>
> The APIs of this module can be used only in the stage model.
>
> This page contains only the system APIs of this module. For details about other public APIs, see [@ohos.app.ability.contextConstant (Context-related Constants)](js-apis-app-ability-contextConstant.md).

## Modules to Import

```ts
import { contextConstant } from '@kit.AbilityKit';
```

## ContextType

Enumerates the common context types, used by the [isContextOf](./js-apis-inner-application-context.md) API.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

| Name  | Value | Description                                                                                                                   |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| SERVICE_EXTENSION_CONTEXT | 5 | [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext-sys.md) type.     |
| UI_SERVICE_EXTENSION_CONTEXT | 6 | [UIServiceExtensionContext](js-apis-inner-application-uiserviceExtensionContext-sys.md) type.     |
| AUTO_FILL_EXTENSION_CONTEXT | 7 | [AutoFillExtensionContext](js-apis-inner-application-autoFillExtensionContext-sys.md) type.     |

**Example**

```ts
import { ServiceExtensionAbility, contextConstant } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryServiceExtAbility extends ServiceExtensionAbility {
  onCreate() {
    hilog.info(0x0000, 'testTag', `%{public}s`, 'Ability onCreate');
    // Check whether the current context is of the ServiceExtensionContext type.
    let result = this.context.isContextOf(contextConstant.ContextType.SERVICE_EXTENSION_CONTEXT);
    hilog.info(0x0000, 'testTag', `match contextType result is:%{public}s`, JSON.stringify(result));
  }
  }
```
<!--no_check-->