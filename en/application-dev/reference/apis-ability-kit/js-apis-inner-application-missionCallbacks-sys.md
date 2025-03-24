# MissionCallback (System API)

The MissionCallback module defines the callbacks invoked after synchronization starts. These callbacks can be used as input parameters in [registerMissionListener](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerregistermissionlistener).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { distributedMissionManager } from '@kit.AbilityKit';
```

## MissionCallback.notifyMissionsChanged

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

| Name| Template| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceId |  string | Yes| Device ID in the callback that notifies a mission change.|

**Example**
```ts
import { distributedMissionManager } from '@kit.AbilityKit';

distributedMissionManager.registerMissionListener(
  {
    deviceId: '123456'
  },
  {
    notifyMissionsChanged: (deviceId: string) => {
      console.log(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);
    },
    notifySnapshot: (deviceId: string, mission: number) => {
      console.log(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);
      console.log(`notifySnapshot mission: ${JSON.stringify(mission)}`);
    },
    notifyNetDisconnect: (deviceId: string, state: number) => {
      console.log(`notifyNetDisconnect deviceId: ${JSON.stringify(deviceId)}`);
      console.log(`notifyNetDisconnect state: ${JSON.stringify(state)}`);
    }
  }
);
```

## MissionCallback.notifySnapshot

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

| Name| Template| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceId |  string | Yes| Device ID in the callback that notifies a snapshot change.|
| mission |  number | Yes| Mission ID in the callback that notifies a snapshot change.|

**Example**
```ts
import { distributedMissionManager } from '@kit.AbilityKit';

distributedMissionManager.registerMissionListener(
  {
    deviceId: '123456'
  },
  {
    notifyMissionsChanged: (deviceId: string) => {
      console.log(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);
    },
    notifySnapshot: (deviceId: string, mission: number) => {
      console.log(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);
      console.log(`notifySnapshot mission: ${JSON.stringify(mission)}`);
    },
    notifyNetDisconnect: (deviceId: string, state: number) => {
      console.log(`notifyNetDisconnect deviceId: ${JSON.stringify(deviceId)}`);
      console.log(`notifyNetDisconnect state: ${JSON.stringify(state)}`);
    }
  }
);
```

## MissionCallback.notifyNetDisconnect

**System capability**: SystemCapability.Ability.AbilityRuntime.Mission

**System API**: This is a system API.

**Parameters**

| Name| Template| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| deviceId |  string | Yes| Device ID in the callback that notifies disconnection.|
| state |  number | Yes| Network status in the callback that notifies disconnection.|

**Example**
```ts
import { distributedMissionManager } from '@kit.AbilityKit';

distributedMissionManager.registerMissionListener(
  {
    deviceId: '123456'
  },
  {
    notifyMissionsChanged: (deviceId: string) => {
      console.log(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);
    },
    notifySnapshot: (deviceId: string, mission: number) => {
      console.log(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);
      console.log(`notifySnapshot mission: ${JSON.stringify(mission)}`);
    },
    notifyNetDisconnect: (deviceId: string, state: number) => {
      console.log(`notifyNetDisconnect deviceId: ${JSON.stringify(deviceId)}`);
      console.log(`notifyNetDisconnect state: ${JSON.stringify(state)}`);
    }
  }
);
```
