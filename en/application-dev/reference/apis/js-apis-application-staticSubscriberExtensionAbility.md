# @ohos.application.StaticSubscriberExtensionAbility

The **StaticSubscriberExtensionAbility** module provides Extension abilities for static subscribers.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.
## Modules to Import

```ts
import StaticSubscriberExtensionAbility from '@ohos.application.StaticSubscriberExtensionAbility'
```

## StaticSubscriberExtensionAbility.onReceiveEvent

onReceiveEvent(event: CommonEventData): void;

Callback of the common event of a static subscriber.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | [CommonEventData](js-apis-commonEvent.md#commoneventdata) | Yes| Common event of a static subscriber.|

**Example**    
  ```ts
  var StaticSubscriberExtensionAbility = requireNapi("application.StaticSubscriberExtensionAbility")
  {
      onReceiveEvent(event){
          console.log('onReceiveEvent,event:' + event.code);
      }
  }
  export default MyStaticSubscriberExtensionAbility

  ```
