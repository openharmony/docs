# @ohos.WorkSchedulerExtensionAbility (Deferred Task Scheduling Callbacks)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=276864ac1aee9d6ac1e6115d16df081282882c33 translatedAt=2026-08-11T01:56:48.598Z pushedAt=2026-08-11T07:08:19.041Z -->

The **WorkSchedulerExtensionAbility** module provides callbacks for deferred task scheduling. You can override the APIs provided by this module. When a deferred task is triggered, the system calls back the application through the APIs and processes the task logic in the callback.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { WorkSchedulerExtensionAbility } from '@kit.BackgroundTasksKit';
```

## Constraints

To ensure system security and stability and prevent **WorkSchedulerExtensionAbility** from abusing system resources, the system imposes certain restrictions. Importing the following modules is not supported:

  [@ohos.resourceschedule.backgroundTaskManager (Background Task Management)](./js-apis-resourceschedule-backgroundTaskManager.md)

  [@ohos.backgroundTaskManager (Background Task Management)](./js-apis-backgroundTaskManager.md)

  [@ohos.multimedia.camera (Camera Management)](../apis-camera-kit/arkts-apis-camera.md)

  [@ohos.multimedia.audio (Audio Management)](../apis-audio-kit/arkts-apis-audio.md)

  [@ohos.multimedia.media (Media)](../apis-media-kit/arkts-apis-media.md)

## WorkSchedulerExtensionContext<sup>10+</sup>

type WorkSchedulerExtensionContext = _WorkSchedulerExtensionContext

**WorkSchedulerExtensionContext** represents the context of **WorkSchedulerExtensionAbility** and is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Type| Description|
| -------- |  -------- |
| [_WorkSchedulerExtensionContext](js-apis-WorkSchedulerExtensionContext.md)|  Context of the **WorkSchedulerExtension**.|

## WorkSchedulerExtensionAbility

Provides callbacks to be invoked when the scheduling conditions are met or the scheduling ends, for example, [onWorkStart()](#onworkstart) or [onWorkStop()](#onworkstop) in **WorkSchedulerExtensionAbility**.

### Properties

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context<sup>10+</sup> | [WorkSchedulerExtensionContext](js-apis-WorkSchedulerExtensionContext.md)  | No| No| Context of the **WorkSchedulerExtension**. This context inherits from **ExtensionContext**.|

### onWorkStart

onWorkStart(work: workScheduler.WorkInfo): void

Called when the system starts scheduling the deferred task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type                                      | Mandatory  | Description            |
| ---- | ---------------------------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-resourceschedule-workScheduler.md#workinfo) | Yes   | Deferred task that starts.|

**Example**

  ```ts
  import { workScheduler } from '@kit.BackgroundTasksKit';
  import { WorkSchedulerExtensionAbility } from '@kit.BackgroundTasksKit';

  export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
    onWorkStart(workInfo: workScheduler.WorkInfo) {
        console.info(`MyWorkSchedulerExtensionAbility onWorkStart, workId: ${workInfo.workId},
            bundleName: ${workInfo.bundleName}, abilityName: ${workInfo.abilityName}.`);
    }
  }
  ```

### onWorkStop

onWorkStop(work: workScheduler.WorkInfo): void

Called when the system stops scheduling the deferred task. This callback is triggered when the deferred task times out for 2 minutes or the [stopWork](js-apis-resourceschedule-workScheduler.md#workschedulerstopwork) API is called to cancel the task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type                                      | Mandatory  | Description            |
| ---- | ---------------------------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-resourceschedule-workScheduler.md#workinfo) | Yes   | Deferred task that stops.|

**Example**

  ```ts
  import { workScheduler } from '@kit.BackgroundTasksKit';
  import { WorkSchedulerExtensionAbility } from '@kit.BackgroundTasksKit';

  export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
    onWorkStop(workInfo: workScheduler.WorkInfo) {
        console.info(`MyWorkSchedulerExtensionAbility onWorkStop, workId: ${workInfo.workId},
            bundleName: ${workInfo.bundleName}, abilityName: ${workInfo.abilityName}.`);
    }
  }
  ```