# TestRunner

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```js
import TestRunner from '@ohos.application.testRunner'
```



## TestRunner.onPrepare

onPrepare(): void

Prepares the unit test environment to run test cases.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

```js
export default class UserTestRunner extends TestRunner {
    onPrepare() {
        console.log("Trigger onPrepare")
    }
};
```



## TestRunner.onRun

onRun(): void

Runs test cases.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

```js
export default class UserTestRunner extends TestRunner {
    onRun() {
        console.log("Trigger onRun")
    }
};
```
