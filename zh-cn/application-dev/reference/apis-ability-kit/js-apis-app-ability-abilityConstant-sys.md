# @ohos.app.ability.AbilityConstant (AbilityConstant)(系统接口)

提供UIAbility中窗口类型的枚举。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.AbilityConstant (AbilityConstant)](js-apis-app-ability-abilityConstant.md)。

## 导入模块

```ts
import { AbilityConstant } from '@kit.AbilityKit';
```

## WindowMode<sup>12+</sup>

启动Ability时的窗口模式，该类型为枚举，可配合startAbility使用指定启动Ability的窗口模式。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称                        | 值 | 说明                 |
| ---                         | --- | ---                  |
| WINDOW_MODE_UNDEFINED       | 0   | 未定义窗口模式。       |
| WINDOW_MODE_FLOATING        | 102 | 自由悬浮形式窗口模式。 |

**示例：**

```ts
import { UIAbility, StartOptions, Want, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let option: StartOptions = {
  windowMode: AbilityConstant.WindowMode.WINDOW_MODE_FULLSCREEN
};

// 确保从上下文获取到context
class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.startAbility(want, option).then(() => {
      console.log('Succeed to start ability.');
    }).catch((error: BusinessError) => {
      console.error('Failed to start ability with error: ${JSON.stringify(error)}');
    });
  }
}
```
