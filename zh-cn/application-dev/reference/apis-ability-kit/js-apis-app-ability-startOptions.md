# @ohos.app.ability.StartOptions (StartOptions)

StartOptions可以作为[startAbility()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)的入参，用于指定目标Ability的窗口模式。

> **说明：**
>
> - 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { StartOptions } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| windowMode<sup>12+<sup> | number | 否 | 是 | 启动Ability时的窗口模式，详见[WindowMode](./js-apis-app-ability-abilityConstant.md#windowmode12)。 |
| displayId | number | 否 | 是 | 屏幕ID模式。默认是0，表示当前屏幕。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| withAnimation<sup>11+</sup> | boolean | 否 | 是 | Ability是否具有动画效果。 |
| windowLeft<sup>11+</sup> | number | 否 | 是 | 窗口左边的位置。 |
| windowTop<sup>11+</sup> | number | 否 | 是 | 窗口顶部的位置。 |
| windowWidth<sup>11+</sup> | number | 否 | 是 | 窗口的宽度。 |
| windowHeight<sup>11+</sup> | number | 否 | 是 | 窗口的高度。 |
| processMode<sup>12+</sup> | [contextConstant.ProcessMode](js-apis-app-ability-contextConstant.md#processmode12) | 否 | 是 | 进程模式。<br>**约束：**<br>1.仅在平板类设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)中生效。<br>3.processMode和startupVisibility必须同时设置。 |
| startupVisibility<sup>12+</sup> | [contextConstant.StartupVisibility](js-apis-app-ability-contextConstant.md#startupvisibility12) | 是 | 否 | Ability启动后的可见性。<br>**约束：**<br>1.仅在平板类设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-1)中生效。<br>3.processMode和startupVisibility必须同时设置。 |

**示例：**

  ```ts
  import { UIAbility, Want, StartOptions } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class EntryAbility extends UIAbility {

    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'EntryAbility'
      };
      let options: StartOptions = {
        displayId: 0
      };

      try {
        this.context.startAbility(want, options, (err: BusinessError) => {
          if (err.code) {
            // 处理业务逻辑错误
            console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
            return;
          }
          // 执行正常业务
          console.info('startAbility succeed');
        });
      } catch (err) {
        // 处理入参错误异常
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`startAbility failed, code is ${code}, message is ${message}`);
      }
    }
  }
  ```
