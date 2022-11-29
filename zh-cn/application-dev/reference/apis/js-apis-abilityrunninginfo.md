# AbilityRunningInfo

AbilityRunningInfo模块提供对Ability运行的相关信息和状态的定义。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 使用说明

通过abilityManager中getAbilityRunningInfos方法获取。

```js
import abilitymanager from '@ohos.application.abilityManager';
abilitymanager.getAbilityRunningInfos((err,data) => { 
    console.log("getAbilityRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | 是 | 否 | Ability匹配信息  |
| pid | number | 是 | 否 | 进程ID。 |
| uid | number | 是 | 否 | 用户ID。  |
| processName | string | 是 | 否 | 进程名称。  |
| startTime | number | 是 | 否 | Ability启动时间。  |
| abilityState | [abilityManager.AbilityState](js-apis-application-abilityManager.md#abilitystate) | 是 | 否 | Ability状态。  |