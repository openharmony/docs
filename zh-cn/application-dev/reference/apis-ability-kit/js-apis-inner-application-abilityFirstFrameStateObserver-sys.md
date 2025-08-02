# AbilityFirstFrameStateObserver(系统接口)

定义Ability首帧绘制完成事件监听对象，可以作为[on](js-apis-app-ability-appManager-sys.md#appmanageronabilityfirstframestate12)的入参监听Ability首帧绘制完成事件。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import { appManager } from '@kit.AbilityKit';
```

## AbilityFirstFrameStateObserver

### onAbilityFirstFrameDrawn

onAbilityFirstFrameDrawn(data: AbilityFirstFrameStateData): void

Ability首帧绘制完成后触发的回调函数。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [AbilityFirstFrameStateData](js-apis-inner-application-abilityFirstFrameStateData-sys.md) | 是 | 表示首帧绘制完成后返回的数据。 |

**示例**：

```ts
import { appManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: appManager.AbilityFirstFrameStateObserver = {
  onAbilityFirstFrameDrawn(data: appManager.AbilityFirstFrameStateData) {
    console.info(`onAbilityFirstFrameDrawn success, abilityFirstFrameStateData: ${data}.`);
  }
};

try {
  appManager.on('abilityFirstFrameState', observer);
} catch (e) {
  let code = (e as BusinessError).code;
  let msg = (e as BusinessError).message;
  console.error(`appmanager.on failed, err code: ${code}, err msg: ${msg}.`);
}
```
