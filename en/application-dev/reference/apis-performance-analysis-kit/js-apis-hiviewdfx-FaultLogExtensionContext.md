# @ohos.hiviewdfx.FaultLogExtensionContext (Delayed Fault Notification Context)
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @StevenLai1994-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

FaultLogExtensionContext is the context of [FaultLogExtensionAbility](js-apis-hiviewdfx-FaultLogExtensionAbility.md) and inherits from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

This module provides APIs for accessing resources of a specific [FaultLogExtensionAbility](js-apis-hiviewdfx-FaultLogExtensionAbility.md). An ExtensionAbility can use the context directly provided by ExtensionContext or that extended from ExtensionContext.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 21. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module can be used only in the stage model.

## How to Use

You can obtain a **FaultLogExtensionContext** object through a **FaultLogExtensionAbility** child class instance.
```ts
import { FaultLogExtensionAbility } from '@kit.PerformanceAnalysisKit';

export default class MyFaultLogExtension extends FaultLogExtensionAbility {
    onFaultReportReady() {
        let context = this.context; // Obtain FaultLogExtensionContext.
        console.info('cache dir is ' + context.cacheDir); // Access the members in the context.
    }
}
```

## FaultLogExtensionContext

Represents the context of [FaultLogExtensionAbility](js-apis-hiviewdfx-FaultLogExtensionAbility.md).

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger
