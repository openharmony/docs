# MissionInfo (系统接口)

表示任务的详细信息，可以通过[getMissionInfo](js-apis-app-ability-missionManager-sys.md#missionmanagergetmissioninfo)获取。

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

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| missionId | number | 否 | 否 | 表示任务ID。|
| runningState | number | 否 | 否 | 表示运行状态。 |
| lockedState | boolean | 否 | 否 | 表示锁定状态。返回true表示锁定状态，返回false表示未锁定状态。 |
| timestamp | string | 否 | 否 | 表示任务的最近创建或更新时间。 |
| want | [Want](js-apis-app-ability-want.md) | 否 | 否 | 表示任务的Want信息。 |
| label | string | 否 | 否 | 表示任务的标签。 |
| iconPath | string | 否 | 否 | 表示任务的图标路径。 |
| continuable | boolean | 否 | 否 | 表示任务是否可以迁移。返回true表示可以迁移，返回false表示不可迁移。 |
| abilityState<sup>10+</sup> | number | 否 | 否 | 表示此任务的能力状态。 |
| unclearable<sup>10+</sup> | boolean | 否 | 否 | 表示任务是否可以被用户手动删除。返回true表示可以被用户手动删除，返回false表示不可被用户手动删除。 |

**示例：**
```ts
import { missionManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  missionManager.getMissionInfo('', 1, (error, data) => {
    if (error) {
      // 处理业务逻辑错误
      console.error(`getMissionInfo failed, error.code: ${error.code}, error.message: ${error.message}`);
      return;
    }

    console.info(`getMissionInfo missionId is: ${JSON.stringify(data.missionId)}`);
    console.info(`getMissionInfo runningState is: ${JSON.stringify(data.runningState)}`);
    console.info(`getMissionInfo lockedState is: ${JSON.stringify(data.lockedState)}`);
    console.info(`getMissionInfo timestamp is: ${JSON.stringify(data.timestamp)}`);
    console.info(`getMissionInfo want is: ${JSON.stringify(data.want)}`);
    console.info(`getMissionInfo label is: ${JSON.stringify(data.label)}`);
    console.info(`getMissionInfo iconPath is: ${JSON.stringify(data.iconPath)}`);
    console.info(`getMissionInfo continuable is: ${JSON.stringify(data.continuable)}`);
    console.info(`getMissionInfo unclearable is: ${JSON.stringify(data.unclearable)}`);
  });
} catch (paramError) {
  console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
}
```