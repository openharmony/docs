# ShellCmdResult

The **ShellCmdResult** module provides the shell command execution result.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name     | Type  | Readable| Writable| Description                                                        |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| stdResult | string | Yes  | Yes  | Standard output content.|
| exitCode  | number | Yes  | Yes  | Result code.|

## Usage

The result is obtained by calling [executeShellCommand](js-apis-inner-application-abilityDelegator.md#executeshellcommand) in **abilityDelegator**.

**Example**
```ts
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';
import { BusinessError } from '@ohos.base';

let abilityDelegator: AbilityDelegatorRegistry.AbilityDelegator;
let cmd = 'cmd';

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (error: BusinessError, data) => {
    if (error) {
        console.error(`executeShellCommand fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`executeShellCommand success, data: ${JSON.stringify(data)}`);
    }
});
```
