# MissionCallback

The **MissionCallback** module defines the callbacks invoked after synchronization starts. These callbacks can be used as input parameters in [registerMissionListener](js-apis-distributedMissionManager.md#distributedmissionmanagerregistermissionlistener).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name                                                | Template    | Readable| Writable| Description                              |
| ---------------------------------------------------- | -------- | ---- | ---- | ---------------------------------- |
| notifyMissionsChanged(deviceId: string)              | function | Yes  | No  | Callback used to notify the mission change event and return the device ID.        |
| notifySnapshot(deviceId: string, mission: number)    | function | Yes  | No  | Callback used to notify the snapshot change event and return the device ID and mission ID.  |
| notifyNetDisconnect(deviceId: string, state: number) | function | Yes  | No  | Callback used to notify the disconnection event and return the device ID and network status.|

**Example**
```ts
import distributedMissionManager from '@ohos.distributedMissionManager';

distributedMissionManager.registerMissionListener(
    {
        deviceId: '123456'
    },
    {
        notifyMissionsChanged: (deviceId) => {
            console.log(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);
        },
        notifySnapshot: (deviceId, mission) => {
            console.log(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);
            console.log(`notifySnapshot mission: ${JSON.stringify(mission)}`);
        },
        notifyNetDisconnect: (deviceId, state) => {
            console.log(`notifyNetDisconnect deviceId: ${JSON.stringify(deviceId)}`);
            console.log(`notifyNetDisconnect state: ${JSON.stringify(state)}`);
        }
    });
```
