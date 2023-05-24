# ProcessInfo

The **ProcessInfo** module defines process information. You can use [getProcessInfo](js-apis-inner-app-context.md#contextgetprocessinfo7) to obtain information about the processes running on the current ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| Process ID.|
| processName | string | Yes| No| Process name.|

**Example**
```ts
import featureAbility from '@ohos.ability.featureAbility';

let context = featureAbility.getContext();
context.getProcessInfo((err, data) => {
    if (err.code !== 0) {
        console.info('getProcessInfo err: ' + JSON.stringify(err) + 'data: ' + JSON.stringify(data));
        let pid = data.pid;
        let processName = data.processName;
    }
});
```

