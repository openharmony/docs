# Work Scheduler Callbacks

> **NOTE**<br/>
> The initial APIs of this module are supported since API version 9. API version 9 is a canary version for trial use. The APIs of this version may be unstable.


## Modules to Import

```
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility'
```

## WorkSchedulerExtensionAbility.onWorkStart

onWorkStart(work: workScheduler.WorkInfo): void

Triggered when the Work Scheduler task starts.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | --------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-workScheduler.md#workinfo) | Yes | Task to be added to the execution queue.|

**Example**

  ```
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

| Name | Type | Mandatory | Description |
| ---- | --------------------- | ---- | -------------- |
| work | [workScheduler.WorkInfo](js-apis-workScheduler.md#workinfo) | Yes | Task to be added to the execution queue.|


**Example**

  ```
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStop(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
        }
    }
  ```
