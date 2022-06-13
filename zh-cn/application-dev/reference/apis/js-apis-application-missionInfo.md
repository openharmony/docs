# MissionInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import MissionInfo from '@ohos.application.missionInfo'
```

## MissionInfo

表示Ability对应任务信息的枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityBase

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | 是 | 是 | 表示任务ID。| 
| runningState | number | 是 | 是 | 表示运行状态。 | 
| lockedState | boolean | 是 | 是 | 表示锁定状态。 | 
| timestamp | string | 是 | 是 | 表示任务的最近创建或更新时间。 | 
| want | [Want](js-apis-application-Want.md) | 是 | 是 | 表示任务的Want信息。 | 
| label | string | 是 | 是 | 表示任务的标签。 | 
| iconPath | string | 是 | 是 | 表示任务的图标路径。 | 
| continuable | boolean | 是 | 是 | 表示任务是否可以继续。 | 
