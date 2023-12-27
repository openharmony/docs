# MissionDeviceInfo

作为可以[registerMissionListener](js-apis-distributedMissionManager.md#distributedmissionmanagerregistermissionlistener)的入参，表示注册监听时所需参数的枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称       | 类型   | 可读   | 可写   | 说明      |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | 是    | 是    | 表示设备ID。 |

**示例：**
```ts
import distributedMissionManager from '@ohos.distributedMissionManager';

distributedMissionManager.registerMissionListener(
    {
        deviceId: '123456'
    },
    {
        notifyMissionsChanged: (deviceId: string) => {
            console.log(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);
        },
        notifySnapshot: (deviceId: string, mission: number) => {
            console.log(`notifySnapshot mission: ${JSON.stringify(mission)}`);
            console.log(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);
        },
        notifyNetDisconnect: (mission: string, state: number) => {
            console.log(`notifyNetDisconnect mission: ${JSON.stringify(mission)}`);
            console.log(`notifyNetDisconnect state: ${JSON.stringify(state)}`);
        }
    }
);
```