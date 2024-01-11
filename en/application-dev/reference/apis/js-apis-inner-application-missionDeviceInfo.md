# MissionDeviceInfo

The **MissionDeviceInfo** module defines the parameters required for registering a listener. It can be used as an input parameter in [registerMissionListener](js-apis-distributedMissionManager.md#distributedmissionmanagerregistermissionlistener).

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

| Name      | Type  | Readable  | Writable  | Description     |
| -------- | ------ | ---- | ---- | ------- |
| deviceId | string | Yes   | Yes   | Device ID.|

**Example**
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