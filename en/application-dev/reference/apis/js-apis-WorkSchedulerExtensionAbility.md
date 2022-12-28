# Work Scheduler Callbacks

The **WorkSchedulerExtensionAbility** module provides callbacks for Work Scheduler tasks.

When developing an application, you can override the APIs of this module and add your own task logic to the APIs.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility'
```

## WorkSchedulerExtensionAbility.onWorkStart

onWorkStart(work: workScheduler.WorkInfo): void

Triggered when the Work Scheduler task starts.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type                                      | Mandatory  | Description            |
| ---- | ---------------------------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-resourceschedule-workScheduler.md#workinfo) | Yes   | Target task.|

**Example**

  ```ts
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStart(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));
        }
    }
  ```

## WorkSchedulerExtensionAbility.onWorkStop

onWorkStop(work: workScheduler.WorkInfo): void

Triggered when the Work Scheduler task stops.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type                                      | Mandatory  | Description            |
| ---- | ---------------------------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-resourceschedule-workScheduler.md#workinfo) | Yes   | Target task.|


**Example**

  ```ts
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStop(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
        }
    }
  ```
