# @ohos.app.ability.AbilityConstant

The **AbilityConstant** module provides ability launch parameters.

The parameters include the initial launch reasons, reasons for the last exit, and ability continuation results.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| launchReason | LaunchReason| Yes| Yes| Ability launch reason.| 
| lastExitReason | LastExitReason | Yes| Yes| Reason for the last exit.| 

## AbilityConstant.LaunchReason

Enumerates the ability launch reasons.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.|
| START_ABILITY          | 1    | Ability startup.|
| CALL | 2    | Call.|
| CONTINUATION           | 3    | Ability continuation.|
| APP_RECOVERY           | 4    | Application recovery.|


## AbilityConstant.LastExitReason

Enumerates reasons for the last exit.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.|
| ABILITY_NOT_RESPONDING          | 1    | The ability does not respond.|
| NORMAL | 2    | Normal status.|


## AbilityConstant.OnContinueResult 

Enumerates ability continuation results.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | Continuation agreed.|
| REJECT           | 1    | Continuation denied.|
| MISMATCH  | 2    | Mismatch.|

## AbilityConstant.WindowMode

Enumerates the window modes in which an ability can be displayed at startup.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                       | Value| Description                |
| ---                         | --- | ---                  |
| WINDOW_MODE_UNDEFINED       | 0   | Undefined window mode.      |
| WINDOW_MODE_FULLSCREEN      | 1   | The ability is displayed in full screen.           |
| WINDOW_MODE_SPLIT_PRIMARY   | 100 | The ability is displayed in the primary window in split-screen mode.  |
| WINDOW_MODE_SPLIT_SECONDARY | 101 | The ability is displayed in the secondary window in split-screen mode.  |
| WINDOW_MODE_FLOATING        | 102 | The ability is displayed in a floating window.|

## AbilityConstant.MemoryLevel

Enumerates the memory levels.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                        | Value| Description               |
| ---                         | --- | ---                  |
| MEMORY_LEVEL_MODERATE       | 0   | Moderate memory usage.      |
| MEMORY_LEVEL_LOW            | 1   | Low memory usage.           |
| MEMORY_LEVEL_CRITICAL       | 2   | High memory usage.  |

## AbilityConstant.OnSaveResult

Enumerates the result types for the operation of saving application data.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALL_AGREE           | 0    | Agreed to save the status.|
| CONTINUATION_REJECT           | 1    | Rejected to save the status in continuation.|
| CONTINUATION_MISMATCH  | 2    | Continuation mismatch.|
| RECOVERY_AGREE           | 3    | Agreed to restore the saved status.|
| RECOVERY_REJECT  | 4    | Rejected to restore the saved state.|
| ALL_REJECT  | 5    | Rejected to save the status.|

## AbilityConstant.StateType

Enumerates the scenarios for saving application data.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| CONTINUATION           | 0    | Saving the status in continuation.|
| APP_RECOVERY           | 1    | Saving the status in application recovery.|
