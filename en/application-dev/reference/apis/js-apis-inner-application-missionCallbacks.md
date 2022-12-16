# MissionCallbacks

The **MissionCallbacks** module defines the callbacks that can be registered as a mission status listener.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name                   | Template      | Readable  | Writable  | Description                |
| --------------------- | -------- | ---- | ---- | ------------------ |
| notifyMissionsChanged | function | Yes   | No   | Callback used to notify the mission change event and return the device ID.    |
| notifySnapshot        | function | Yes   | No   | Callback used to notify the snapshot change event and return the device ID and mission ID.|
| notifyNetDisconnect   | function | Yes   | No   | Callback used to notify the disconnection event and return the device ID and network status.|

**Example**
```ts
import distributedMissionManager from '@ohos.distributedMissionManager';

let missionDeviceInfo = {
    deviceId: "123456"
};
let missionCallback = {
    notifyMissionsChanged: function (deviceId) {
        console.log("notifyMissionsChanged deviceId: " + JSON.stringify(deviceId));
    },
    notifySnapshot: function (mission, deviceId) {
        console.log("notifySnapshot mission: " + JSON.stringify(mission));
        console.log("notifySnapshot deviceId: " + JSON.stringify(deviceId));
    },
    notifyNetDisconnect: function (mission, state) {
        console.log("notifyNetDisconnect mission: " + JSON.stringify(mission));
        console.log("notifyNetDisconnect state: " + JSON.stringify(state));
    }
};
distributedMissionManager.registerMissionListener(missionDeviceInfo, missionCallback);
```
