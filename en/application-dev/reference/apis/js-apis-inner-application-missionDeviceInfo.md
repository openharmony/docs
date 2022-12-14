# MissionDeviceInfo

The **MissionDeviceInfo** module defines the parameters required for registering a listener.

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | Yes   | Yes   | Device ID.|

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
