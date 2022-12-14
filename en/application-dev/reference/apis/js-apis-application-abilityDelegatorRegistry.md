# @ohos.application.abilityDelegatorRegistry

The **AbilityDelegatorRegistry** module provides APIs for storing the global registers of the registered **AbilityDelegator** and **AbilityDelegatorArgs** objects. You can use the APIs to obtain the **AbilityDelegator** and **AbilityDelegatorArgs** objects of an application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```

## AbilityLifecycleState

Enumerates the ability lifecycle states.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name         | Value  | Description                       |
| ------------- | ---- | --------------------------- |
| UNINITIALIZED | 0    | The ability is in an invalid state.             |
| CREATE        | 1    | The ability is created.|
| FOREGROUND    | 2    | The ability is running in the foreground.  |
| BACKGROUND    | 3    | The ability is running in the background.  |
| DESTROY       | 4    | The ability is destroyed.|

## AbilityDelegatorRegistry.getAbilityDelegator

getAbilityDelegator(): AbilityDelegator

Obtains the **AbilityDelegator** object of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegator](js-apis-inner-application-abilityDelegator.md#AbilityDelegator) | [AbilityDelegator](js-apis-inner-application-abilityDelegator.md#AbilityDelegator) object, which can be used to schedule functions related to the test framework.|

**Example**

```ts
var abilityDelegator;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
```

## AbilityDelegatorRegistry.getArguments

getArguments(): AbilityDelegatorArgs

Obtains the **AbilityDelegatorArgs** object of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md#AbilityDelegatorArgs) | [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md#AbilityDelegatorArgs) object, which can be used to obtain test parameters.|

**Example**

```ts
var args = AbilityDelegatorRegistry.getArguments();
console.info("getArguments bundleName:" + args.bundleName);
console.info("getArguments testCaseNames:" + args.testCaseNames);
console.info("getArguments testRunnerClassName:" + args.testRunnerClassName);
```
