# @ohos.app.ability.StartOptions (StartOptions)

StartOptions可以作为[startAbility()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)的入参，用于指定目标Ability的窗口模式。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import StartOptions from '@ohos.app.ability.StartOptions';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| [windowMode](js-apis-app-ability-abilityConstant.md#abilityconstantwindowmode) | number | 否 | 窗口模式。<br>**系统API**：该接口为系统接口，三方应用不支持调用。 |
| displayId | number | 否 | 屏幕ID。默认是0，表示当前屏幕。 |
| withAnimation<sup>11+</sup> | boolean | 否 | Ability是否具有动画效果。 |
| windowLeft<sup>11+</sup> | number | 否 | 窗口左边的位置。 |
| windowTop<sup>11+</sup> | number | 否 | 窗口顶部的位置。 |
| windowWidth<sup>11+</sup> | number | 否 | 窗口的宽度。 |
| windowHeight<sup>11+</sup> | number | 否 | 窗口的高度。 |

**示例：**

  ```ts
  import missionManager from '@ohos.app.ability.missionManager';
  import StartOptions from '@ohos.app.ability.StartOptions';
  import { BusinessError } from '@ohos.base';

  try {
    missionManager.getMissionInfos('', 10, (error, missions) => {
      if (error) {
          console.error(`getMissionInfos failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
          return;
      }
      console.log(`size = ${missions.length}`);
      console.log(`missions = ${JSON.stringify(missions)}`);
      let id = missions[0].missionId;

      let startOptions: StartOptions = {
          windowMode : 101,
          displayId: 0
      };
      missionManager.moveMissionToFront(id, startOptions).then(() => {
  	    console.log('moveMissionToFront is called');
      });
    });
  } catch (paramError) {
    let code = (paramError as BusinessError).code;
    let message = (paramError as BusinessError).message;
    console.error(`error: ${code}, ${message}`);
  }
  ```
