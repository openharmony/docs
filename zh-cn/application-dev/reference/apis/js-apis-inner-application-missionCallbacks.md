# MissionCallbacks

表示开始同步后，建立的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称                    | 类型       | 可读   | 可写   | 说明                 |
| --------------------- | -------- | ---- | ---- | ------------------ |
| notifyMissionsChanged | function | 是    | 否    | 通知任务变化，返回设备ID。     |
| notifySnapshot        | function | 是    | 否    | 通知快照变化，返回设备ID，任务ID |
| notifyNetDisconnect   | function | 是    | 否    | 通知断开连接，返回设备ID，网络状态 |

**示例：**
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