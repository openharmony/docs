# @ohos.app.ability.abilityDelegatorRegistry (AbilityDelegatorRegistry)

**AbilityDelegatorRegistry**, a module of the [Test Framework](../../application-test/arkxtest-guidelines.md), is used to obtain [AbilityDelegator](js-apis-inner-application-abilityDelegator.md) and [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md) objects. **AbilityDelegator** provides APIs for creating **AbilityMonitor** objects, which can be used to listen for ability lifecycle changes. **AbilityDelegatorArgs** provides APIs for obtaining test parameters.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module can be used only in the test framework.

## Modules to Import

```ts
import AbilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';
```

## AbilityLifecycleState

Enumerates the ability lifecycle states. It can be used in [getAbilityState(ability)](js-apis-inner-application-abilityDelegator.md#getabilitystate9) of [AbilityDelegator](js-apis-inner-application-abilityDelegator.md) to return different ability lifecycle states.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name         | Value  | Description                       |
| ------------- | ---- | --------------------------- |
| UNINITIALIZED | 0    | The ability is in an invalid state.  |
| CREATE        | 1    | The ability is created.|
| FOREGROUND    | 2    | The ability is running in the foreground.  |
| BACKGROUND    | 3    | The ability is running in the background.  |
| DESTROY       | 4    | The ability is destroyed.|

## AbilityDelegatorRegistry.getAbilityDelegator

getAbilityDelegator(): AbilityDelegator

Obtains an [AbilityDelegator](js-apis-inner-application-abilityDelegator.md) object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegator](js-apis-inner-application-abilityDelegator.md#AbilityDelegator) | [AbilityDelegator](js-apis-inner-application-abilityDelegator.md#AbilityDelegator) object, which can be used to schedule the functionalities of the test framework.|

**Example**

```ts
let abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();

let want = {
    bundleName: 'com.ohos.example',
    abilityName: 'MainAbility'
};
abilityDelegator.startAbility(want, (err) => {
    if (err.code !== 0) {
        console.log('Success start ability.');
    } else {
        console.log('Failed start ability, error: ' + JSON.stringify(err));
    }
})
```

## AbilityDelegatorRegistry.getArguments

getArguments(): AbilityDelegatorArgs

Obtains an [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md) object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md) | [AbilityDelegatorArgs](js-apis-inner-application-abilityDelegatorArgs.md) object, which can be used to obtain test parameters.|

**Example**

```ts
let args = AbilityDelegatorRegistry.getArguments();
console.info('getArguments bundleName:' + args.bundleName);
console.info('getArguments parameters:' + JSON.stringify(args.parameters));
console.info('getArguments testCaseNames:' + args.testCaseNames);
console.info('getArguments testRunnerClassName:' + args.testRunnerClassName);
```
