# MissionInfo (System API)

The **MissionInfo** module defines detailed information about a mission. The information can be obtained through [getMissionInfo](js-apis-app-ability-missionManager-sys.md#missionmanagergetmissioninfo).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { missionManager } from '@kit.AbilityKit';
```

## Attributes

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | Yes | Yes | Mission ID.|
| runningState | number | Yes | Yes | Running state of the mission. |
| lockedState | boolean | Yes | Yes | Locked state of the mission. |
| timestamp | string | Yes | Yes | Latest time when the mission was created or updated. |
| want | [Want](js-apis-app-ability-want.md) | Yes | Yes | Want information of the mission. |
| label | string | Yes | Yes | Label of the mission. |
| iconPath | string | Yes | Yes | Path of the mission icon. |
| continuable | boolean | Yes | Yes | Whether the mission can be continued on another device. |
| abilityState<sup>10+</sup> | number | Yes | Yes | Capability status of the mission. |
| unclearable<sup>10+</sup> | boolean | Yes | Yes | Whether the mission can be manually deleted. |

**Example**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfo('', 1, (error, data) => {
    if (error) {
      // Process service logic errors.
      console.error(`getMissionInfo failed, error.code: ${error.code}, error.message: ${error.message}`);
      return;
    }

    console.log(`getMissionInfo missionId is: ${JSON.stringify(data.missionId)}`);
    console.log(`getMissionInfo runningState is: ${JSON.stringify(data.runningState)}`);
    console.log(`getMissionInfo lockedState is: ${JSON.stringify(data.lockedState)}`);
    console.log(`getMissionInfo timestamp is: ${JSON.stringify(data.timestamp)}`);
    console.log(`getMissionInfo want is: ${JSON.stringify(data.want)}`);
    console.log(`getMissionInfo label is: ${JSON.stringify(data.label)}`);
    console.log(`getMissionInfo iconPath is: ${JSON.stringify(data.iconPath)}`);
    console.log(`getMissionInfo continuable is: ${JSON.stringify(data.continuable)}`);
    console.log(`getMissionInfo unclearable is: ${JSON.stringify(data.unclearable)}`);
  });
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```
