# AbilityRunningInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


Ability运行相关信息。


## 使用说明


通过abilityManager中getAbilityRunningInfos方法获取。


  
```js
import abilitymanager from '@ohos.application.abilityManager';
abilitymanager.getAbilityRunningInfos((err,data) => { 
    console.log("getAbilityRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```

## 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | 是 | 否 | Ability匹配信息。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 
| pid | number | 是 | 否 | 进程ID。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 
| uid | number | 是 | 否 | 用户ID。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 
| processName | string | 是 | 否 | 进程名称。 <br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| startTime | number | 是 | 否 | Ability启动时间。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 
| abilityState | [abilityManager.AbilityState](#abilitymanager-abilitystate) | 是 | 否 | Ability状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 


## abilityManager.AbilityState

Ability的状态信息。

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| INITIAL | 0 | 表示ability为initial状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core| 
| FOREGROUND | 9 | 表示ability为foreground状态。 <br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| BACKGROUND | 10 | 表示ability为background状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 
| FOREGROUNDING | 11 | 表示ability为foregrounding状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 
| BACKGROUNDING | 12 | 表示ability为backgrounding状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core  | 
