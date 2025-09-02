# MissionCallback (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @hanjiawei-->
<!--Adviser: @huipeizi-->

作为可以[registerMissionListener](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerregistermissionlistener)的入参，表示开始同步后，建立的回调函数。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { distributedMissionManager } from '@kit.AbilityKit';
```

## MissionCallback.notifyMissionsChanged

notifyMissionsChanged(deviceId: string): void

注册任务监听的callback，通知任务变化。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId |  string | 是 | 通知任务变化，返回设备ID。|

**示例：**

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

notifySnapshot(deviceId: string, mission: number): void

注册任务监听的callback，通知快照变化。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId |  string | 是 | 通知快照变化，返回设备ID。 |
| mission |  number | 是 | 通知快照变化，任务ID。 |

**示例：**
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

notifyNetDisconnect(deviceId: string, state: number): void

注册任务监听的callback，通知断开连接。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId |  string | 是 | 通知断开连接，返回设备ID。 |
| state |  number | 是 | 通知断开连接，返回网络状态。0：连接断开（固定值）。 |

**示例：**

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
