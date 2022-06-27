# AbilityConstant

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

Provides parameters related to ability launch.

## Modules to Import

```js
import AbilityConstant from '@ohos.application.AbilityConstant';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| launchReason | LaunchReason| Yes| Yes| Ability launch reason.|
| lastExitReason | LastExitReason | Yes| Yes| Reason for the last exit.|

## AbilityConstant.LaunchReason

Enumerates ability launch reasons.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.|
| START_ABILITY          | 1    | Ability startup.|
| CALL | 2    | Call.|
| CONTINUATION           | 3    | Ability continuation.|


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
