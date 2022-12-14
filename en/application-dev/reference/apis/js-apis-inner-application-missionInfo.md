# MissionInfo

The **MissionInfo** module defines the mission information of an ability.

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
import missionManager from '@ohos.application.missionManager'

missionManager.getMissionInfo("12345", 1, (error, data) => {
    console.info('getMissionInfo missionId is:' + JSON.stringify(data.missionId));
    console.info('getMissionInfo runningState is:' + JSON.stringify(data.runningState));
    console.info('getMissionInfo lockedState is:' + JSON.stringify(data.lockedState));
    console.info('getMissionInfo timestamp is:' + JSON.stringify(data.timestamp));
    console.info('getMissionInfo want is:' + JSON.stringify(data.want));
    console.info('getMissionInfo label is:' + JSON.stringify(data.label));
    console.info('getMissionInfo iconPath is:' + JSON.stringify(data.iconPath));
    console.info('getMissionInfo continuable is:' + JSON.stringify(data.continuable));
});
```
