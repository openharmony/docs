# AbilityRunningInfo

AbilityRunningInfo模块提供对Ability运行的相关信息和状态的定义。

> **说明：**
> 
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## 使用说明

通过abilityManager中[getAbilityRunningInfos](js-apis-app-ability-abilityManager.md#getabilityrunninginfos)方法获取。

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ability | ElementName | 是 | 否 | Ability匹配信息  |
| pid | number | 是 | 否 | 进程ID。 |
| uid | number | 是 | 否 | 用户ID。  |
| processName | string | 是 | 否 | 进程名称。  |
| startTime | number | 是 | 否 | Ability启动时间。  |
| abilityState | [abilityManager.AbilityState](js-apis-app-ability-abilityManager.md#abilitystate14) | 是 | 否 | Ability状态。  |

**示例：**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.getAbilityRunningInfos()
    .then((data: abilityManager.AbilityRunningInfo[]) => {
      for (let i = 0; i < data.length; i++) {
        let abilityInfo = data[i];
        console.info(`getAbilityRunningInfos success, data: ${JSON.stringify(abilityInfo)}`);
      }
    })
    .catch((error: BusinessError) => {
      console.error(`getAbilityRunningInfos fail, error code: ${JSON.stringify(error.code)}, error msg: ${JSON.stringify(error.message)}`);
    })
} catch (e) {
  let code = (e as BusinessError).code;
  let msg = (e as BusinessError).message;
  console.error(`getAbilityRunningInfos fail, error code: ${JSON.stringify(code)}, error msg: ${JSON.stringify(msg)}`);
}
```