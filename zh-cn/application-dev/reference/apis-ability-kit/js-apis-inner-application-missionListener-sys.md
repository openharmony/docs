# MissionListener (系统接口)

定义系统任务状态监听，可以通过[on](js-apis-app-ability-missionManager-sys.md#missionmanageronmission)注册。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { missionManager } from '@kit.AbilityKit';
```

## 属性

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Mission

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------- | ---- | ------------------------------------------------------------ |
| onMissionCreated    | function               | 否   | 表示当系统创建任务时回调执行。                                |
| onMissionDestroyed   | function               | 否   | 表示当系统销毁任务时回调执行。 |
| onMissionSnapshotChanged   | function               | 否   | 表示当系统更新任务缩略图时回调执行。 |
| onMissionMovedToFront   | function               | 否   | 表示当系统将任务移动到前台时回调执行。 |
| onMissionLabelUpdated<sup>9+</sup>   | function               | 否   | 表示当系统更新任务标签时回调执行。 |
| onMissionIconUpdated<sup>9+</sup>   | function               | 否   | 表示当系统更新任务图标时回调执行。 |
| onMissionClosed<sup>9+</sup>   | function               | 否   | 表示当系统关闭任务时回调执行。 |

**示例：**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let listener: missionManager.MissionListener = {
  onMissionCreated: (mission) => {
    console.log(`onMissionCreated mission: ${JSON.stringify(mission)}`);
  },
  onMissionDestroyed: (mission) => {
    console.log(`onMissionDestroyed mission: ${JSON.stringify(mission)}`);
  },
  onMissionSnapshotChanged: (mission) => {
    console.log(`onMissionSnapshotChanged mission: ${JSON.stringify(mission)}`);
  },
  onMissionMovedToFront: (mission) => {
    console.log(`onMissionMovedToFront mission: ${JSON.stringify(mission)}`);
  },
  onMissionLabelUpdated: (mission) => {
    console.log(`onMissionLabelUpdated mission: ${JSON.stringify(mission)}`);
  },
  onMissionIconUpdated: (mission, icon) => {
    console.log(`onMissionIconUpdated mission: ${JSON.stringify(mission)}`);
    console.log(`onMissionIconUpdated icon: ${JSON.stringify(icon)}`);
  },
  onMissionClosed: (mission) => {
    console.log(`onMissionClosed mission: ${JSON.stringify(mission)}`);
  }
};

try {
  let listenerId = missionManager.on('mission', listener);
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```