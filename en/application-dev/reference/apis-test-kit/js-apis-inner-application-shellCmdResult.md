# ShellCmdResult

The **ShellCmdResult** module provides the shell command execution result.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in <!--RP1-->[arkxtest](../../application-test/arkxtest-guidelines.md)<!--RP1End-->.

## Modules to Import

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## ShellCmdResult

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name     | Type  | Read-Only| Optional| Description                                                        |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| stdResult | string | No  | No  | Standard output of the shell command.|
| exitCode  | number | No  | No  | Result code of the shell command.|

## Usage

The result is obtained by calling [executeShellCommand](js-apis-inner-application-abilityDelegator.md#executeshellcommand) in **abilityDelegator**.

**Example**
```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator;
let cmd = 'cmd';

abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (error: BusinessError, data) => {
  if (error) {
    console.error(`executeShellCommand fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`executeShellCommand success, data: ${JSON.stringify(data)}`);
  }
});
```
