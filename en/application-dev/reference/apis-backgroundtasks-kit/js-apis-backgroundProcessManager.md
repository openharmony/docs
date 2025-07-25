# @ohos.resourceschedule.backgroundProcessManager (Background Child Process Management)

The **backgroundProcessManager** module provides APIs for background child process management. You can use these APIs to suppress and unsuppress child processes to prevent child processes from occupying too many system resources and causing system stuttering. The APIs take effect only for the child processes created through [OH_Ability_StartNativeChildProcess](../apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess).

>  **NOTE**
>
> The initial APIs of this module are supported since API version 17. Newly added APIs will be marked with a superscript to indicate their earliest API version.

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

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message            |
|----------|------------------|
| 401      | Parameter error. Possible causes: priority is out of range. |

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

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

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

## backgroundProcessManager.setPowerSaveMode<sup>20+</sup>

setPowerSaveMode(pid: number, powerSaveMode: PowerSaveMode): Promise&lt;void&gt;

Sets the power saving mode for a process. This API uses a promise to return the result. This API takes effect only on PCs/2-in-1 devices.

You can set to enter the power saving mode when:
- The application is not focused, and there are no audio operations or UI updates.
- The application cannot obtain the power lock through the system framework.
- The application needs to perform time-consuming computing tasks, such as compression, decompression, and compilation, which are significantly restricted by CPU resources. (In this case, the power saving mode will be enabled forcibly.)

**Required permissions**: ohos.permission.BACKGROUND_MANAGER_POWER_SAVE_MODE

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

**Parameters**

| Name     | Type     | Mandatory     | Description     |
|-------------|-----------|-----------|-----------|
| pid         | number    | Yes       | Process ID. |
| powerSaveMode | [PowerSaveMode](#powersavemode20) | Yes| Power saving mode.|

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [backgroundProcessManager Error Codes](errorcode-backgroundProcessManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message            |
|----------|------------------|
| 201      | Permission denied. |
| 801      | Capability not supported. |
| 31800002      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified; <br> 2. Incorrect parameter types; 3. PowerSaveMode status is out of range. |
| 31800003      | Setup error, This setting is overridden by setting in Task Manager. |
| 31800004      | The setting failed due to system scheduling reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';

let pid = 33333;
try {
    backgroundProcessManager.setPowerSaveMode(pid, backgroundProcessManager.PowerSaveMode.EFFICIENCY_MODE); 
} catch (error) {
    console.error(`setPowerSaveMode failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## backgroundProcessManager.isPowerSaveMode<sup>20+</sup>

isPowerSaveMode(pid: number): Promise&lt;boolean&gt;

Queries whether the process is in power saving mode. This API uses a promise to return the result. This API takes effect only on PCs/2-in-1 devices.

**Required permissions**: ohos.permission.BACKGROUND_MANAGER_POWER_SAVE_MODE

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

**Parameters**

| Name     | Type     | Mandatory     | Description     |
|-------------|-----------|-----------|-----------|
| pid         | number    | Yes       | Process ID. |

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<boolean> | Promise used to return the query result. The value **true** means that the process is in power saving mode; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [backgroundProcessManager Error Codes](errorcode-backgroundProcessManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message            |
|----------|------------------|
| 201      | Permission denied. |
| 801      | Capability not supported. |
| 31800002      | Parameter error. Possible causes: <br> 1. Mandatory parameters are left unspecified; <br> 2. Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundProcessManager } from '@kit.BackgroundTasksKit';

let pid = 33333;
try {
    backgroundProcessManager.isPowerSaveMode(pid).then((result: boolean) => {
        console.info("isPowerSaveMode: " + result.toString());
    });
} catch (error) {
    console.error(`isPowerSaveMode failed, errCode: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`);
}
```

## ProcessPriority

Specifies the child process priority.

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

| Name                  |  Value     | Description                                                                            |
|----------------------| -------- |--------------------------------------------------------------------------------|
| PROCESS_BACKGROUND   | 1        | Compared with **PROCESS_INACTIVE**, this priority has a more obvious suppression effect. Child processes can obtain less CPU resources. You are advised to set this priority when executing background child processes that cannot be perceived by users, such as background image-text pages. |
| PROCESS_INACTIVE     | 2        | You are advised to set this priority when executing background child processes that can be perceived by users, such as audio playback and navigation.                                            |

## PowerSaveMode<sup>20+</sup>

Specifies the power saving mode.

**System capability**: SystemCapability.Resourceschedule.BackgroundProcessManager

| Name| Value| Description|
|-----|----|-------|
| EFFICIENCY_MODE | 1 | Efficiency mode. Applications set to this mode will not enter the power saving mode, where fewer CPU resources are available.|
| DEFAULT_MODE | 2 | Default mode. Applications set to this mode may follow the system to enter the power saving mode.|
