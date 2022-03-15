# Work Scheduler Callbacks

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility'
```

## WorkSchedulerExtensionAbility.onWorkStart
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
onWorkStart(workInfo: WorkInfo);

- **Description**
Triggered when the Work Scheduler task starts.

- **Example**

  ```
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStart(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));
        }
    }
  ```

## WorkSchedulerExtensionAbility.onWorkStop
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
onWorkStop(workInfo: WorkInfo);

- **Description**
Triggered when the Work Scheduler task stops.

- **Example**

  ```
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStop(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
        }
    }
  ```
