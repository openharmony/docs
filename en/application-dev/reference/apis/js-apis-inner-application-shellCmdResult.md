# ShellCmdResult

The **ShellCmdResult** module provides the shell command execution result.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name     | Type  | Readable| Writable| Description                                                        |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| stdResult | string | Yes  | Yes  | Standard output content.|
| exitCode  | number | Yes  | Yes  | Result code.|

## Usage

The result is obtained by calling [executeShellCommand](js-apis-inner-application-abilityDelegator.md#executeshellcommand) in **abilityDelegator**.

**Example**
```ts
import AbilityDelegatorRegistry from "@ohos.application.abilityDelegatorRegistry";
let abilityDelegator;
let cmd = "cmd";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (err: any, data: any) => {
    console.info("executeShellCommand callback, failed: ", err);
    console.info("executeShellCommand callback, success: ", data);
});
```
