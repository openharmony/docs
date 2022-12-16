# @ohos.application.testRunner

The **TestRunner** module provides a test framework. You can use the APIs of this module to prepare the unit test environment and run test cases.

To implement your own unit test framework, extend this class and override its APIs.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import TestRunner from '@ohos.application.testRunner'
```

## TestRunner.onPrepare

onPrepare(): void

Prepares the unit test environment to run test cases.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

```ts
export default class UserTestRunner implements TestRunner {
    onPrepare() {
        console.log("Trigger onPrepare")
    }
    onRun() {}
};
```



## TestRunner.onRun

onRun(): void

Runs test cases.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

```ts
export default class UserTestRunner implements TestRunner {
    onPrepare() {}
    onRun() {
        console.log("Trigger onRun")
    }
};
```
