# @ohos.application.StaticSubscriberExtensionAbility (StaticSubscriberExtensionAbility)

StaticSubscriberExtensionAbility模块提供静态订阅者ExtensionAbility的类别的能力。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。
## 导入模块

```ts
import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility'
```

## StaticSubscriberExtensionAbility.onReceiveEvent

onReceiveEvent(event: CommonEventData): void;

静态订阅者通用事件回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | event | [CommonEventData](js-apis-commonEvent.md#commoneventdata) | 是 | 静态订阅者通用事件回调。 | 

**示例：**
    
  ```ts
  var StaticSubscriberExtensionAbility = requireNapi("application.StaticSubscriberExtensionAbility")
  {
      onReceiveEvent(event){
          console.log('onReceiveEvent,event:' + event.code);
      }
  }
  export default MyStaticSubscriberExtensionAbility

  ```