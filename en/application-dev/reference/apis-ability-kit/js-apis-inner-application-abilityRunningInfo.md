# AbilityRunningInfo

The AbilityRunningInfo module defines the running information and state of an ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## Usage

The ability running information is obtained by calling [getAbilityRunningInfos](js-apis-app-ability-abilityManager.md#getabilityrunninginfos) in **abilityManager**.

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | Yes| No| Information that matches an ability. |
| pid | number | Yes| No| Process ID.|
| uid | number | Yes| No| User ID. |
| processName | string | Yes| No| Process name. |
| startTime | number | Yes| No| Ability start time. |
| abilityState | [AbilityState](js-apis-app-ability-abilityManager.md#abilitystate) | Yes| No| Ability state. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';

abilityManager.getAbilityRunningInfos((error, data) => {
  if (error) {
    console.error(`getAbilityRunningInfos fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);
    for (let i = 0; i < data.length; i++) {
      let abilityInfo = data[i];
      console.log(`abilityInfo.ability: ${JSON.stringify(abilityInfo.ability)}`);
      console.log(`abilityInfo.pid: ${JSON.stringify(abilityInfo.pid)}`);
      console.log(`abilityInfo.uid: ${JSON.stringify(abilityInfo.uid)}`);
      console.log(`abilityInfo.processName: ${JSON.stringify(abilityInfo.processName)}`);
      console.log(`abilityInfo.startTime: ${JSON.stringify(abilityInfo.startTime)}`);
      console.log(`abilityInfo.abilityState: ${JSON.stringify(abilityInfo.abilityState)}`);
    }
  }
});
```
