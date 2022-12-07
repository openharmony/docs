# MissionInfo

表示Ability对应任务信息的枚举。

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
import missionManager from '@ohos.application.missionManager'

missionManager.getMissionInfo("12345", 1, (error, data) => {
    console.info('getMissionInfo missionId is:' + JSON.stringify(data.missionId));
    console.info('getMissionInfo runningState is:' + JSON.stringify(data.runningState));
    console.info('getMissionInfo lockedState is:' + JSON.stringify(data.lockedState));
    console.info('getMissionInfo timestamp is:' + JSON.stringify(data.timestamp));
    console.info('getMissionInfo want is:' + JSON.stringify(data.want));
    console.info('getMissionInfo label is:' + JSON.stringify(data.label));
    console.info('getMissionInfo iconPath is:' + JSON.stringify(data.iconPath));
    console.info('getMissionInfo continuable is:' + JSON.stringify(data.continuable));
});
```