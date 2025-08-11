# @ohos.app.ability.StartOptions (StartOptions)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @dsz2025; @yangxuguang-huawei; @Luobniz21-->
<!--SE: @ccllee1-->
<!--TSE: @lixueqing513-->

StartOptions可以作为启动UIAbility接口（例如[startAbility()](js-apis-inner-application-uiAbilityContext.md#startability-1)）的入参，用于指定目标UIAbility启动时的选项，包括但不局限于窗口模式、目标UIAbility启动时所在的屏幕等。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.StartOptions (StartOptions)](js-apis-app-ability-startOptions.md)。

## 导入模块

```ts
import { StartOptions } from '@kit.AbilityKit';
```

## StartOptions

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| windowFocused<sup>12+</sup> | boolean | 否 | 是 | 窗口是否获焦。默认是true，表示窗口获焦。<br>**约束：**<br>1.该功能仅在2in1和tablet设备上生效。<br>2.仅在[UIAbilityContext.startAbility](js-apis-inner-application-uiAbilityContext.md#startability-1)中生效。 |

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
