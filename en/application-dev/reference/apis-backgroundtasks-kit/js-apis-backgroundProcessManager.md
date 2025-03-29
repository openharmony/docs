# @ohos.resourceschedule.backgroundProcessManager (Background Child Process Management)

The **backgroundProcessManager** module provides APIs for background child process management. You can use these APIs to suppress and unsuppress child processes to prevent child processes from occupying too many system resources and causing system stuttering. The APIs take effect only for the child processes created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess).

>  **NOTE**
>
> The initial APIs of this module are supported since API version 15. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';
```

## backgroundProcessManager.setProcessPriority

setProcessPriority(pid: number, priority: ProcessPriority): Promise&lt;void&gt;

Sets the child process priority. After a child process is suppressed, the CPU resources that can be obtained will be limited. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. To suppress the child process, call this API again.

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

**Parameters**

| Name     | Type                                 | Mandatory  | Description                                                                                                                           |
|----------|-------------------------------------| ---- |-------------------------------------------------------------------------------------------------------------------------------|
| pid      | number                              | Yes   | ID of the child process to be suppressed, which is returned when the child process is created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess).|
| priority | [ProcessPriority](#processpriority) | Yes   | Suppression priority.                                                                                                                        |



**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundProcessManager Error Codes](errorcode-backgroundProcessManager.md).

| ID   | Error Message            |
|----------|------------------|
| 401      | Parameter error. Possible causes: priority is out of range. |
| 31800001 | remote error. Possible causes: remote is not work.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';

let childProcessPid = 33333;
try {
    backgroundProcessManager.setProcessPriority(childProcessPid,
        backgroundProcessManager.ProcessPriority.PROCESS_INACTIVE);
} catch (error) {
    console.error(`setProcessPriority failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## backgroundProcessManager.resetProcessPriority

resetProcessPriority(pid: number): Promise&lt;void&gt;

Unsuppresses the child process. In this case, the child process follows the scheduling policy of the main process. If the scheduling policy of the main process changes, for example, from the background to the foreground, the child process changes with the main process. The effect is the same as calling **resetProcessPriority**.

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

**Parameters**

| Name     | Type                | Mandatory  | Description                                                                                                                       |
|----------|--------------------| ---- |---------------------------------------------------------------------------------------------------------------------------|
| pid      | number             | Yes   | Child process ID, which is returned when the child process is created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess).|

**Error codes**

For details about the following error codes, see [BackgroundProcessManager Error Codes](errorcode-backgroundProcessManager.md).

| ID   | Error Message                                                                                                          |
|----------|----------------------------------------------------------------------------------------------------------------|
| 31800001 | remote error. Possible causes: remote is not work.                                                             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';

let childProcessPid = 33333;
try {
    backgroundProcessManager.resetProcessPriority(childProcessPid); 
} catch (error) {
    console.error(`setProcessPriority failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## ProcessPriority

Specifies the child process priority.

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

| Name                  |  Value     | Description                                                                            |
|----------------------| -------- |--------------------------------------------------------------------------------|
| PROCESS_BACKGROUND   | 1        | Compared with **PROCESS_INACTIVE**, this priority has a more obvious suppression effect. Child processes can obtain less CPU resources. You are advised to set this priority when executing background child processes that cannot be perceived by users, such as background image-text pages. |
| PROCESS_INACTIVE     | 2        | You are advised to set this priority when executing background child processes that can be perceived by users, such as audio playback and navigation.                                            |
