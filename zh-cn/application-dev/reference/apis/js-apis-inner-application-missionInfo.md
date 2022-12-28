# MissionInfo

表示任务的详细信息，可以通过[getMissionInfo](js-apis-app-ability-missionManager.md#missionmanagergetmissioninfo)获取。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | 是 | 是 | 表示任务ID。|
| runningState | number | 是 | 是 | 表示运行状态。 |
| lockedState | boolean | 是 | 是 | 表示锁定状态。 |
| timestamp | string | 是 | 是 | 表示任务的最近创建或更新时间。 |
| want | [Want](js-apis-application-want.md) | 是 | 是 | 表示任务的Want信息。 |
| label | string | 是 | 是 | 表示任务的标签。 |
| iconPath | string | 是 | 是 | 表示任务的图标路径。 |
| continuable | boolean | 是 | 是 | 表示任务是否可以迁移。 |

**示例：**
```ts
import missionManager from '@ohos.app.ability.missionManager'

try {
  missionManager.getMissionInfo("", 1, (error, data) => {
    if (error.code) {
        // 处理业务逻辑错误
        console.log("getMissionInfo failed, error.code:" + JSON.stringify(error.code) +
          "error.message:" + JSON.stringify(error.message));
        return;
    }

    console.log('getMissionInfo missionId is:' + JSON.stringify(data.missionId));
    console.log('getMissionInfo runningState is:' + JSON.stringify(data.runningState));
    console.log('getMissionInfo lockedState is:' + JSON.stringify(data.lockedState));
    console.log('getMissionInfo timestamp is:' + JSON.stringify(data.timestamp));
    console.log('getMissionInfo want is:' + JSON.stringify(data.want));
    console.log('getMissionInfo label is:' + JSON.stringify(data.label));
    console.log('getMissionInfo iconPath is:' + JSON.stringify(data.iconPath));
    console.log('getMissionInfo continuable is:' + JSON.stringify(data.continuable));
    });
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```