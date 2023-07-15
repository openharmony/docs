# AbilityDelegatorArgs

The **AbilityDelegatorArgs** module provides APIs to obtain an **AbilityDelegatorArgs** object during the execution of test cases.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';
```

## Usage

An **AbilityDelegatorArgs** object is obtained by calling [getArguments](js-apis-app-ability-abilityDelegatorRegistry.md#abilitydelegatorregistrygetarguments) in **AbilityDelegatorRegistry**.

## AbilityDelegatorArgs

Describes the ability delegator arguments.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name               | Type                  | Readable| Writable| Description                                                        |
| ------------------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName          | string                 | Yes  | Yes  | Bundle name of the application to test.|
| parameters          | {[key:string]: string} | Yes  | Yes  | Parameters of the unit test that is started currently.|
| testCaseNames       | string                 | Yes  | Yes  | Test case names.|
| testRunnerClassName | string                 | Yes  | Yes  | Names of the test case executors.|

**Example**

```ts
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';

let args: AbilityDelegatorRegistry.AbilityDelegatorArgs = AbilityDelegatorRegistry.getArguments();
```
