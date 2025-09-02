# AbilityDelegatorArgs

The **AbilityDelegatorArgs** module provides APIs to obtain an **AbilityDelegatorArgs** object during the execution of test cases.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in <!--RP1-->[arkxtest](../../application-test/arkxtest-guidelines.md)<!--RP1End-->.

## Modules to Import

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## Usage

An **AbilityDelegatorArgs** object is obtained by calling [getArguments](js-apis-app-ability-abilityDelegatorRegistry.md#abilitydelegatorregistrygetarguments) in **AbilityDelegatorRegistry**.

## AbilityDelegatorArgs

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name               | Type                  | Read-Only| Optional| Description                                                        |
| ------------------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName          | string                 | No  | No  | Bundle name of the application to test.|
| parameters          | Record\<string, string> | No  | No  | Parameters of the unit test that is started currently.|
| testCaseNames       | string                 | No  | No  | Test case name.|
| testRunnerClassName | string                 | No  | No  | Names of the test case executors.|

**Example**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';

let args: abilityDelegatorRegistry.AbilityDelegatorArgs = abilityDelegatorRegistry.getArguments();
```
