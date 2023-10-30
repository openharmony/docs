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

try {
    distributedMissionManager.startSyncRemoteMissions(
        {
            deviceId: '123456',
            fixConflict: true,
            tag: 123
        },
        (error, data) => {
            if (error && error.code !== 0) {
                console.error(`startSyncRemoteMissions fail, error: ${JSON.stringify(error)}`);
            } else {
                console.log(`startSyncRemoteMissions success, data: ${JSON.stringify(data)}`);
            }
        }
    );
} catch (err) {
    console.error(`startSyncRemoteMissions fail: ${JSON.stringify(err)}`);
}
```
