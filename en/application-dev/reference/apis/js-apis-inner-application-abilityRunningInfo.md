# AbilityRunningInfo

The **AbilityRunningInfo** module defines the running information and state of an ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Usage

The ability running information is obtained by using the **getAbilityRunningInfos** API in **abilityManager**.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | Yes| No| Information that matches an ability. |
| pid | number | Yes| No| Process ID.|
| uid | number | Yes| No| User ID. |
| processName | string | Yes| No| Process name. |
| startTime | number | Yes| No| Ability start time. |
| abilityState | [abilityManager.AbilityState](js-apis-app-ability-abilityManager.md#abilitystate) | Yes| No| Ability state. |

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';
abilitymanager.getAbilityRunningInfos((err,data) => { 
    console.log("getAbilityRunningInfos err: "  + err + " data: " + JSON.stringify(data));
    for (let i = 0; i < data.length; i++) {
        let abilityinfo = data[i];
        console.log("abilityinfo.ability: " + JSON.stringify(abilityinfo.ability));
        console.log("abilityinfo.pid: " + JSON.stringify(abilityinfo.pid));
        console.log("abilityinfo.uid: " + JSON.stringify(abilityinfo.uid));
        console.log("abilityinfo.processName: " + JSON.stringify(abilityinfo.processName));
        console.log("abilityinfo.startTime: " + JSON.stringify(abilityinfo.startTime));
        console.log("abilityinfo.abilityState: " + JSON.stringify(abilityinfo.abilityState));
    }
});
```
