# ProcessInfo

The **ProcessInfo** module defines process information.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| Process ID.| 
| processName | string | Yes| No| Process name.| 

**Example**
```ts
import featureAbility from '@ohos.ability.featureAbility';

var context = featureAbility.getContext();
context.getProcessInfo((err, data) => {
    console.info("getProcessInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
    let pid = data.pid;
    let processName = data.processName;
});
```
