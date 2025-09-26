# AbilityForegroundStateObserver (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

定义应用前后台状态监听。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## AbilityForegroundStateObserver

### onAbilityStateChanged

onAbilityStateChanged(abilityStateData: AbilityStateData): void

当Ability前后台状态发生变化时，系统会触发该回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名  | 类型  | 必填  | 说明  |
| ------ | ----- | ----- | ----- |
| abilityStateData   | [AbilityStateData](js-apis-inner-application-abilityStateData.md)   | 是 | Ability状态信息。 |

**示例：**
```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: abilityManager.AbilityForegroundStateObserver = {
  onAbilityStateChanged(abilityStateData) {
    console.info(`onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
};
try {
  abilityManager.on('abilityForegroundState', observer);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error code: ${code}, error msg: ${message}`);
}
```
