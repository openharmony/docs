# StaticSubscriberExtensionAbility


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 9开始支持。


## 导入模块

```
import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility'
```

## StaticSubscriberExtensionAbility.onReceiveEvent

onReceiveEvent(event: CommonEventData): void;

静态订阅者通用事件回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | event | CommonEventData | 是 | 静态订阅者通用事件回调。 | 

**示例：**
    
  ```js
  var StaticSubscriberExtensionAbility = requireNapi("application.StaticSubscriberExtensionAbility")
  {
      onReceiveEvent(event){
          console.log('onReceiveEvent,event:' + event.code);
      }
  }
  export default MyStaticSubscriberExtensionAbility

  ```