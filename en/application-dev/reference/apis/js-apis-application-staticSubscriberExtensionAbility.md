# StaticSubscriberExtensionAbility

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.
## Modules to Import

```
import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility'
```

## StaticSubscriberExtensionAbility.onReceiveEvent

onReceiveEvent(event: CommonEventData): void;

Callback of the common event of a static subscriber.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | event | CommonEventData | Yes| Callback of the common event of a static subscriber.| 

**Example**
    
  ```js
  var StaticSubscriberExtensionAbility = requireNapi("application.StaticSubscriberExtensionAbility")
  {
      onReceiveEvent(event){
          console.log('onReceiveEvent,event:' + event.code);
      }
  }
  export default MyStaticSubscriberExtensionAbility

  ```
