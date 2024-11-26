# AbilityForegroundStateObserver (系统接口)

定义应用前后台状态监听。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                             | 类型                    | 可读 | 可写 | 说明   |
| -------------------------------- | ---------------------- | ---- | ---- | ------------------ |
| onAbilityStateChanged   | AsyncCallback\<void>   | 是   | 否   | Ability前后台状态发生变化时执行的回调函数。传入参数类型是[AbilityStateData](js-apis-inner-application-abilityStateData.md)。 |

**示例：**
```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: abilityManager.AbilityForegroundStateObserver = {
  onAbilityStateChanged(abilityStateData) {
    console.log(`onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
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
