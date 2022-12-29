# MissionCallbacks

作为可以[registerMissionListener](js-apis-distributedMissionManager.md#distributedmissionmanagerregistermissionlistener)的入参，表示开始同步后，建立的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称                                                 | 类型     | 可读 | 可写 | 说明                               |
| ---------------------------------------------------- | -------- | ---- | ---- | ---------------------------------- |
| notifyMissionsChanged(deviceId: string)              | function | 是   | 否   | 通知任务变化，返回设备ID。         |
| notifySnapshot(deviceId: string, mission: number)    | function | 是   | 否   | 通知快照变化，返回设备ID，任务ID   |
| notifyNetDisconnect(deviceId: string, state: number) | function | 是   | 否   | 通知断开连接，返回设备ID，网络状态 |

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
    notifySnapshot: function (deviceId, mission) {
        console.log("notifySnapshot deviceId: " + JSON.stringify(deviceId));
        console.log("notifySnapshot mission: " + JSON.stringify(mission));
    },
    notifyNetDisconnect: function (deviceId, state) {
        console.log("notifyNetDisconnect deviceId: " + JSON.stringify(deviceId));
        console.log("notifyNetDisconnect state: " + JSON.stringify(state));
    }
};
distributedMissionManager.registerMissionListener(missionDeviceInfo, missionCallback);
```