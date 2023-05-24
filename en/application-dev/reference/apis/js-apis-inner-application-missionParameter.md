# MissionParameter

The **MissionParameter** module defines the parameters required for mission synchronization. It can be used an input parameter in [startSyncRemoteMissions](js-apis-distributedMissionManager.md#distributedmissionmanagerstartsyncremotemissions).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name         | Type   | Readable  | Writable  | Description         |
| ----------- | ------- | ---- | ---- | ----------- |
| deviceId    | string  | Yes   | Yes   | Device ID.    |
| fixConflict | boolean | Yes   | Yes   | Whether a version conflict occurs.|
| tag         | number  | Yes   | Yes   | Tag of the mission.   |

**Example**
```ts
import distributedMissionManager from '@ohos.distributedMissionManager';

let missionParameter = {
    deviceId: '123456',
    fixConflict: true,
    tag: 123
};
try {
    distributedMissionManager.startSyncRemoteMissions(missionParameter,
        (err, data) => {
            console.log('startSyncRemoteMissions, data: ' + JSON.stringify(data));
        }
    );
} catch (err) {
    console.error('startSyncRemoteMissions fail: ' + JSON.stringify(err));
}
```
