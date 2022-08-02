# AbilityRunningInfo

The **AbilityRunningInfo** module implements ability running information and ability states.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Usage

The ability running information is obtained by using the **getAbilityRunningInfos** API in **abilityManager**.

```js
import abilitymanager from '@ohos.application.abilityManager';
abilitymanager.getAbilityRunningInfos((err,data) => { 
    console.log("getAbilityRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```

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
| abilityState | [abilityManager.AbilityState](js-apis-application-abilityManager.md#abilitystate) | Yes| No| Ability state. |
