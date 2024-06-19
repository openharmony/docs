# AbilityRunningInfo (系统接口)

AbilityRunningInfo模块提供对Ability运行的相关信息和状态的定义。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## 使用说明

通过abilityManager中[getAbilityRunningInfos](js-apis-app-ability-abilityManager-sys.md#getabilityrunninginfos)方法获取。

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | 是 | 否 | Ability匹配信息  |
| pid | number | 是 | 否 | 进程ID。 |
| uid | number | 是 | 否 | 用户ID。  |
| processName | string | 是 | 否 | 进程名称。  |
| startTime | number | 是 | 否 | Ability启动时间。  |
| abilityState | [abilityManager.AbilityState](js-apis-app-ability-abilityManager-sys.md#abilitystate) | 是 | 否 | Ability状态。  |

**示例：**

```ts
import { abilityManager } from '@kit.AbilityKit';

abilityManager.getAbilityRunningInfos((error, data) => {
  if (error) {
    console.error(`getAbilityRunningInfos fail, error: ${JSON.stringify(error)}`);
  } else {
    console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);
    for (let i = 0; i < data.length; i++) {
      let abilityInfo = data[i];
      console.log(`abilityInfo.ability: ${JSON.stringify(abilityInfo.ability)}`);
      console.log(`abilityInfo.pid: ${JSON.stringify(abilityInfo.pid)}`);
      console.log(`abilityInfo.uid: ${JSON.stringify(abilityInfo.uid)}`);
      console.log(`abilityInfo.processName: ${JSON.stringify(abilityInfo.processName)}`);
      console.log(`abilityInfo.startTime: ${JSON.stringify(abilityInfo.startTime)}`);
      console.log(`abilityInfo.abilityState: ${JSON.stringify(abilityInfo.abilityState)}`);
    }
  }
});
```