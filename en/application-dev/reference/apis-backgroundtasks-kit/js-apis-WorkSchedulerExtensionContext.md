# WorkSchedulerExtensionContext

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=7be3499f7c151ec869cff3a879d447af32ef1a02 translatedAt=2026-08-11T01:57:14.720Z pushedAt=2026-08-11T07:57:01.730Z -->

The **WorkSchedulerExtensionContext** module, inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md), provides a context environment for the **WorkSchedulerExtensionAbility**.

This module provides APIs for accessing the resources of a **WorkSchedulerExtensionAbility**.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - The APIs of this module can be used only in the stage model.

## How to Use

Obtain the context through a **WorkSchedulerExtensionAbility** child class instance.

```ts
import { WorkSchedulerExtensionAbility, workScheduler } from '@kit.BackgroundTasksKit';

class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
    onWorkStart(workInfo: workScheduler.WorkInfo) {
        let WorkSchedulerExtensionContext = this.context; // Obtain the WorkSchedulerExtensionContext.
    }
}
```

## WorkSchedulerExtensionContext

Provides a context environment for the **WorkSchedulerExtensionAbility**.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Model restriction**: This API can be used only in the stage model.