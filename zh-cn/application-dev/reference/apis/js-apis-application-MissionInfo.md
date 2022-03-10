# MissionInfo

> **说明：**
> 本模块首批接口从API 8开始支持。


Ability对应的任务信息。


## 导入模块

使用前需导入Want


```
import Want from "../@ohos.application.Want";
```


## MissionInfo

表示Ability对应任务信息的枚举。

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | 是 | 是 | 表示任务ID。<br/>**系统能力**：SystemCapability.Ability.AbilityBase| 
| runningState | number | 是 | 是 | 表示运行状态。<br/>**系统能力**：SystemCapability.Ability.AbilityBase | 
| lockedState | boolean | 是 | 是 | 表示锁定状态。<br/>**系统能力**：SystemCapability.Ability.AbilityBase | 
| timestamp | string | 是 | 是 | 表示任务的最近创建或更新时间。<br/>**系统能力**：SystemCapability.Ability.AbilityBase | 
| want | [Want](js-apis-featureAbility.md#want) | 是 | 是 | 表示任务的Want信息。 <br/>**系统能力**：SystemCapability.Ability.AbilityBase| 
| label | string | 是 | 是 | 表示任务的标签。<br/>**系统能力**：SystemCapability.Ability.AbilityBase | 
| iconPath | string | 是 | 是 | 表示任务的图标路径。<br/>**系统能力**：SystemCapability.Ability.AbilityBase | 
| continuable | boolean | 是 | 是 | 表示任务是否可以继续。 <br/>**系统能力**：SystemCapability.Ability.AbilityBase| 
