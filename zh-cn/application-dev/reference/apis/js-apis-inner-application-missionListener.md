# MissionListener

定义系统任务状态监听。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

| 名称        | 读写属性 | 类型                 | 必填 | 描述                                                         |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| onMissionCreated    | 只读     | function               | 否   | 表示当系统创建任务时回调执行。                                |
| onMissionDestroyed   | 只读     | function               | 否   | 表示当系统销毁任务时回调执行。 |
| onMissionSnapshotChanged   | 只读     | function               | 否   | 表示当系统更新任务缩略图时回调执行。 |
| onMissionMovedToFront   | 只读     | function               | 否   | 表示当系统将任务移动到前台时回调执行。 |
| onMissionLabelUpdated   | 只读     | function               | 否   | 表示当系统更新任务标签时回调执行。 |
| onMissionIconUpdated   | 只读     | function               | 否   | 表示当系统更新任务图标时回调执行。 |
| onMissionClosed   | 只读     | function               | 否   | 表示当系统关闭任务时回调执行。 |

**示例：**
```ts
import missionManager from '@ohos.application.missionManager'

let listener = {
    onMissionCreated: function (mission) {
        console.log("onMissionCreated mission: " + JSON.stringify(mission));
    },
    onMissionDestroyed: function (mission) {
        console.log("onMissionDestroyed mission: " + JSON.stringify(mission));
    },
    onMissionSnapshotChanged: function (mission) {
        console.log("onMissionSnapshotChanged mission: " + JSON.stringify(mission));
    },
    onMissionMovedToFront: function (mission) {
        console.log("onMissionMovedToFront mission: " + JSON.stringify(mission));
    },
    onMissionIconUpdated: function (mission, icon) {
        console.log("onMissionIconUpdated mission: " + JSON.stringify(mission));
    },
    onMissionClosed: function (mission) {
        console.log("onMissionClosed mission: " + JSON.stringify(mission));
    }
};
let listenerid = missionManager.registerMissionListener(listener);
```