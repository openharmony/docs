# @ohos.application.StaticSubscriberExtensionAbility (StaticSubscriberExtensionAbility)

StaticSubscriberExtensionAbility模块提供静态订阅者ExtensionAbility类别的能力。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口均为系统接口。

## 导入模块

```ts
import { StaticSubscriberExtensionAbility } from '@kit.BasicServicesKit';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称    | 类型                                                         | 只读 | 可选 | 说明     |
| ------- | ------------------------------------------------------------ | ---- | ---- | -------- |
| context<sup>10+</sup> | [StaticSubscriberExtensionContext](js-apis-application-StaticSubscriberExtensionContext-sys.md) | 否   | 否   | 上下文。 |

## StaticSubscriberExtensionAbility.onReceiveEvent

onReceiveEvent(event: CommonEventData): void;

静态订阅者通用事件回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | [CommonEventData](./js-apis-inner-commonEvent-commonEventData.md) | 是 | 静态订阅者通用事件回调。 |

**示例：**
  ```ts
  import { commonEventManager, StaticSubscriberExtensionAbility } from '@kit.BasicServicesKit';

    class MyStaticSubscriberExtensionAbility extends StaticSubscriberExtensionAbility {
        onReceiveEvent(event: commonEventManager.CommonEventData) {
            console.log(`onReceiveEvent, event: ${JSON.stringify(event)}`);
        }
    }
  ```