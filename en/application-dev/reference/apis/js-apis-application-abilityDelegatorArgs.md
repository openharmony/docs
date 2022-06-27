# AbilityDelegatorArgs

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```

## AbilityDelegatorArgs

Describes the test parameters.

| Name               | Type                  | Readable| Writable| Description                                                        |
| ------------------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName          | string                 | Yes  | Yes  | Bundle name of the application to test.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| parameters          | {[key:string]: string} | Yes  | Yes  | Parameters of the unit test that is started currently.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| testCaseNames       | string                 | Yes  | Yes  | Test case names.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
| testRunnerClassName | string                 | Yes  | Yes  | Names of the test executors that execute the test cases.<br>**System capability**: SystemCapability.Ability.AbilityRuntime.Core|
