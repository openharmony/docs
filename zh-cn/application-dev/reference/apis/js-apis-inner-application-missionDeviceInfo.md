# MissionDeviceInfo

表示注册监听时所需参数的枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 参数类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | 是    | 是    | 表示设备ID。 |

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