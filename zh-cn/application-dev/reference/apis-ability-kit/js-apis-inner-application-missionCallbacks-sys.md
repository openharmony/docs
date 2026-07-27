# MissionCallbacks (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hobbycao-->
<!--Designer: @gsxiaowen-->
<!--Tester: @hanjiawei-->
<!--Adviser: @hu-zhiqiong-->

作为可以[registerMissionListener](js-apis-distributedMissionManager-sys.md#distributedmissionmanagerregistermissionlistener)的入参，表示开始同步后，建立的回调函数。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { distributedMissionManager } from '@kit.AbilityKit';
```

## MissionCallback.notifyMissionsChanged

notifyMissionsChanged(deviceId: string): void

notifyMissionsChanged是任务监听的callback函数，用于通知任务变化。用于在多设备协同场景下，监听远程设备的任务状态变化，如任务管理器、多屏协同等场景。例如：跨设备任务切换、任务列表同步等。

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MISSIONS

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId |  string | 是 | 设备ID，表示发生任务变化的远程设备。|

**示例：**

```ts
import { distributedMissionManager } from '@kit.AbilityKit';

// 注册任务监听器
distributedMissionManager.registerMissionListener(
  {
    deviceId: '123456'
  },
  {
    // 任务变化时的回调，接收设备ID
    notifyMissionsChanged: (deviceId: string) => {
      console.info(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);
    },
    // 快照变化时的回调，接收设备ID和任务ID
    notifySnapshot: (deviceId: string, mission: number) => {
      console.info(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);
      console.info(`notifySnapshot mission: ${JSON.stringify(mission)}`);
    },
    // 网络断开时的回调，接收设备ID和网络状态
    notifyNetDisconnect: (deviceId: string, state: number) => {
      console.info(`notifyNetDisconnect deviceId: ${JSON.stringify(deviceId)}`);
      console.info(`notifyNetDisconnect state: ${JSON.stringify(state)}`);
    }
  }
);
```

## MissionCallback.notifySnapshot

notifySnapshot(deviceId: string, mission: number): void

notifySnapshot是任务监听的callback函数，用于通知任务快照变化。当任务的快照（即任务当前界面状态的快照）发生变化时触发该回调。用于在多设备协同场景下，监听远程设备任务快照的变化，如任务切换、任务恢复等场景。例如：任务切换动画同步、任务快照实时预览等。

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MISSIONS

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId |  string | 是 | 设备ID，表示快照发生变化的远程设备。 |
| mission |  number | 是 | 任务ID，表示快照发生变化的任务。 |

**示例：**
```ts
import { distributedMissionManager } from '@kit.AbilityKit';

// 注册任务监听器
distributedMissionManager.registerMissionListener(
  {
    deviceId: '123456'
  },
  {
    // 任务变化时的回调，接收设备ID
    notifyMissionsChanged: (deviceId: string) => {
      console.info(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);
    },
    // 快照变化时的回调，接收设备ID和任务ID
    notifySnapshot: (deviceId: string, mission: number) => {
      console.info(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);
      console.info(`notifySnapshot mission: ${JSON.stringify(mission)}`);
    },
    // 网络断开时的回调，接收设备ID和网络状态
    notifyNetDisconnect: (deviceId: string, state: number) => {
      console.info(`notifyNetDisconnect deviceId: ${JSON.stringify(deviceId)}`);
      console.info(`notifyNetDisconnect state: ${JSON.stringify(state)}`);
    }
  }
);
```

## MissionCallback.notifyNetDisconnect

notifyNetDisconnect(deviceId: string, state: number): void

notifyNetDisconnect是任务监听的callback函数，用于通知断开连接。用于在多设备协同场景下，监听远程设备的网络连接状态变化，当设备断开连接时触发回调，用于清理相关资源或提示用户。例如：断开连接时释放会话资源、显示断开提示等。

**设备行为差异：** 该接口在不支持分布式业务的Wearable设备不生效。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

**系统接口**：此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MISSIONS

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId |  string | 是 | 设备ID，表示网络断开的远程设备。 |
| state |  number | 是 | 网络连接状态，固定为0，表示网络连接断开。 |

**示例：**

```ts
import { distributedMissionManager } from '@kit.AbilityKit';

// 注册任务监听器
distributedMissionManager.registerMissionListener(
  {
    deviceId: '123456'
  },
  {
    // 任务变化时的回调，接收设备ID
    notifyMissionsChanged: (deviceId: string) => {
      console.info(`notifyMissionsChanged deviceId: ${JSON.stringify(deviceId)}`);
    },
    // 快照变化时的回调，接收设备ID和任务ID
    notifySnapshot: (deviceId: string, mission: number) => {
      console.info(`notifySnapshot deviceId: ${JSON.stringify(deviceId)}`);
      console.info(`notifySnapshot mission: ${JSON.stringify(mission)}`);
    },
    // 网络断开时的回调，接收设备ID和网络状态
    notifyNetDisconnect: (deviceId: string, state: number) => {
      console.info(`notifyNetDisconnect deviceId: ${JSON.stringify(deviceId)}`);
      console.info(`notifyNetDisconnect state: ${JSON.stringify(state)}`);
    }
  }
);
```
