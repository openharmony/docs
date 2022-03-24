# AbilityConstant

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 9.


Provides parameters related to ability launch.


## Modules to Import

  
```js
import AbilityConstant from '@ohos.application.AbilityConstant';
```


## Attributes

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| launchReason | LaunchReason| Yes| Yes| Ability launch reason.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core| 
| lastExitReason | LastExitReason | Yes| Yes| Reason for the last exit.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core| 

## AbilityConstant.LaunchReason

Enumerates ability launch reasons.

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| START_ABILITY          | 1    | Ability startup.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| CALL | 2    | Call.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| CONTINUATION           | 3    | Ability continuation.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|


## AbilityConstant.LaunchReason

Enumerates reasons for the last exit.

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| ABILITY_NOT_RESPONDING          | 1    | The ability does not respond.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| NORMAL | 2    | Normal status.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|


## AbilityConstant.OnContinueResult 

Enumerates ability continuation results.

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | Continuation agreed.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| REJECT           | 1    | Continuation denied.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| MISMATCH  | 2    | Mismatch.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
