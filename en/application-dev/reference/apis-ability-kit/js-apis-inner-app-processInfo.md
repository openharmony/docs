# ProcessInfo

The ProcessInfo module defines process information. You can use [getProcessInfo](js-apis-inner-app-context.md#contextgetprocessinfo7) to obtain information about the processes running on the current ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. The APIs of this module can be used only in the FA model. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| Process ID.|
| processName | string | Yes| No| Process name.|

**Example**
<!--code_no_check_fa-->
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context = featureAbility.getContext();
context.getProcessInfo((error, data) => {
    if (error && error.code !== 0) {
        console.error(`getProcessInfo fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getProcessInfo success, data: ${JSON.stringify(data)}`);
        let pid = data.pid;
        let processName = data.processName;
    }
});
```
