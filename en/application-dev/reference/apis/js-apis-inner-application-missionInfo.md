# MissionInfo

The **MissionInfo** module defines detailed information about a mission. The information can be obtained through [getMissionInfo](js-apis-app-ability-missionManager.md#missionmanagergetmissioninfo).

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | Yes| Yes| Mission ID.|
| runningState | number | Yes| Yes| Running state of the mission.|
| lockedState | boolean | Yes| Yes| Locked state of the mission.|
| timestamp | string | Yes| Yes| Latest time when the mission was created or updated.|
| want | [Want](js-apis-application-want.md) | Yes| Yes| Want information of the mission.|
| label | string | Yes| Yes| Label of the mission.|
| iconPath | string | Yes| Yes| Path of the mission icon.|
| continuable | boolean | Yes| Yes| Whether the mission can be continued on another device.|

**Example**
```ts
import missionManager from '@ohos.app.ability.missionManager';

try {
  missionManager.getMissionInfo('', 1, (error, data) => {
    if (error.code) {
        // Process service logic errors.
        console.log('getMissionInfo failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}');
        return;
    }

    console.log('getMissionInfo missionId is: ${JSON.stringify(data.missionId)}');
    console.log('getMissionInfo runningState is: ${JSON.stringify(data.runningState)}');
    console.log('getMissionInfo lockedState is: ${JSON.stringify(data.lockedState)}');
    console.log('getMissionInfo timestamp is: ${JSON.stringify(data.timestamp)}');
    console.log('getMissionInfo want is: ${JSON.stringify(data.want)}');
    console.log('getMissionInfo label is: ${JSON.stringify(data.label)}');
    console.log('getMissionInfo iconPath is: ${JSON.stringify(data.iconPath)}');
    console.log('getMissionInfo continuable is: ${JSON.stringify(data.continuable)}');
    });
} catch (paramError) {
    console.log('error: ${paramError.code}, ${paramError.message}');
}
```
