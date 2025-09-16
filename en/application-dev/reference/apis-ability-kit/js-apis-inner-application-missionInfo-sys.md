# MissionInfo (System API)

The module defines detailed information about a mission. The information can be obtained through [getMissionInfo](js-apis-app-ability-missionManager-sys.md#missionmanagergetmissioninfo).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { missionManager } from '@kit.AbilityKit';
```

## Attributes

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | No| No| Mission ID.|
| runningState | number | No| No| Running state of the mission.|
| lockedState | boolean | No| No| Locked state of the mission. **true** if locked, **false** otherwise.|
| timestamp | string | No| No| Latest time when the mission was created or updated.|
| want | [Want](js-apis-app-ability-want.md) | No| No| Want information of the mission.|
| label | string | No| No| Label of the mission.|
| iconPath | string | No| No| Path of the mission icon.|
| continuable | boolean | No| No| Whether the mission can be continued on another device. **true** if the mission can be continued on another device, **false** otherwise.|
| abilityState<sup>10+</sup> | number | No| No| Capability status of the mission.|
| unclearable<sup>10+</sup> | boolean | No| No| Whether the mission can be manually deleted. **true** if the mission can be manually deleted, **false** otherwise.|

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

    console.info(`getMissionInfo missionId is: ${JSON.stringify(data.missionId)}`);
    console.info(`getMissionInfo runningState is: ${JSON.stringify(data.runningState)}`);
    console.info(`getMissionInfo lockedState is: ${JSON.stringify(data.lockedState)}`);
    console.info(`getMissionInfo timestamp is: ${JSON.stringify(data.timestamp)}`);
    console.info(`getMissionInfo want is: ${JSON.stringify(data.want)}`);
    console.info(`getMissionInfo label is: ${JSON.stringify(data.label)}`);
    console.info(`getMissionInfo iconPath is: ${JSON.stringify(data.iconPath)}`);
    console.info(`getMissionInfo continuable is: ${JSON.stringify(data.continuable)}`);
    console.info(`getMissionInfo unclearable is: ${JSON.stringify(data.unclearable)}`);
  });
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```
