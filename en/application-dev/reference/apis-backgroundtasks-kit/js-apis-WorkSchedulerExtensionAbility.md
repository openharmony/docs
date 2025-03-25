# @ohos.WorkSchedulerExtensionAbility (Deferred Task Scheduling Callbacks)

The WorkSchedulerExtensionAbility module provides callbacks for deferred task scheduling. You can override the APIs provided by this module. When a deferred task is triggered, the system calls back the application through the APIs and processes the task logic in the callback.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { WorkSchedulerExtensionAbility } from '@kit.BackgroundTasksKit';
```

## WorkSchedulerExtensionContext<sup>10+</sup>

type WorkSchedulerExtensionContext = _WorkSchedulerExtensionContext

| Type| Description|
| -------- |  -------- |
| WorkSchedulerExtensionContext|  Context of the WorkSchedulerExtensionAbility.|

## WorkSchedulerExtensionAbility

### Properties

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context<sup>10+</sup> | [WorkSchedulerExtensionContext](js-apis-inner-application-WorkSchedulerExtensionContext.md)  | Yes| No| Context of the WorkSchedulerExtensionAbility. This context inherits from **ExtensionContext**.|

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

  export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
    onWorkStart(workInfo: workScheduler.WorkInfo) {
        console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));
    }
  }
  ```

### onWorkStop

onWorkStop(work: workScheduler.WorkInfo): void

Called when the system stops scheduling the deferred task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type                                      | Mandatory  | Description            |
| ---- | ---------------------------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-resourceschedule-workScheduler.md#workinfo) | Yes   | Deferred task that stops.|


**Example**

  ```ts
  import { workScheduler } from '@kit.BackgroundTasksKit';

  export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
    onWorkStop(workInfo: workScheduler.WorkInfo) {
        console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
    }
  }
  ```
