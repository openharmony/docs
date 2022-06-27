# AbilityRunningInfo

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

Provides ability running information.

## Modules to Import

```js
import abilitymanager from '@ohos.application.abilityManager';
```

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

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | Yes| No| Information that matches an ability. | 
| pid | number | Yes| No| Process ID.| 
| uid | number | Yes| No| User ID. | 
| processName | string | Yes| No| Process name. | 
| startTime | number | Yes| No| Ability start time. | 
| abilityState | [abilityManager.AbilityState](#abilitymanagerabilitystate) | Yes| No| Ability state. | 


## abilityManager.AbilityState

Enumerates the ability states.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description| 
| -------- | -------- | -------- |
| INITIAL | 0 | The ability is in the initial state.| 
| FOREGROUND | 9 | The ability is in the foreground state. | 
| BACKGROUND | 10 | The ability is in the background state. | 
| FOREGROUNDING | 11 | The ability is in the foregrounding state. | 
| BACKGROUNDING | 12 | The ability is in the backgrounding state. | 
