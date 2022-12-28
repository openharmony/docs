# MissionParameter

作为[startSyncRemoteMissions](js-apis-distributedMissionManager.md#distributedmissionmanagerstartsyncremotemissions)的入参，表示同步时所需参数的枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称          | 类型    | 可读   | 可写   | 说明          |
| ----------- | ------- | ---- | ---- | ----------- |
| deviceId    | string  | 是    | 是    | 表示设备ID。     |
| fixConflict | boolean | 是    | 是    | 表示是否存在版本冲突。 |
| tag         | number  | 是    | 是    | 表示特定的标签。    |

**示例：**
```ts
import distributedMissionManager from '@ohos.distributedMissionManager';

let missionParameter = {
    deviceId: "123456",
    fixConflict: true,
    tag: 123
};
try {
    distributedMissionManager.startSyncRemoteMissions(missionParameter,
        (err, data) => {
            console.log("startSyncRemoteMissions, data: " + JSON.stringify(data));
        }
    );
} catch (err) {
    console.error('startSyncRemoteMissions fail: ' + JSON.stringify(err));
}
```