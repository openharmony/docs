# AbilityDelegatorArgs

The **AbilityDelegatorArgs** module provides a global register to store the registered **AbilityDelegator** and **AbilityDelegatorArgs** instances during application startup.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Usage

The ability delegator arguments are obtained by calling **getArguments** in **AbilityDelegatorRegistry**.

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
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry';

var args = AbilityDelegatorRegistry.getArguments();
```
