# EventHub

The **EventHub** module provides APIs to subscribe to, unsubscribe from, and trigger events.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Usage

Before using any APIs in the **EventHub**, you must obtain an **EventHub** instance through the member variable **context** of the **Ability** instance.

```ts
import Ability from '@ohos.application.Ability';
export default class MainAbility extends Ability {
    func1(){
        console.log("func1 is called");
    }
    onForeground() {
        this.context.eventHub.on("123", this.func1);
    }
}
```

## EventHub.on

on(event: string, callback: Function): void;

Subscribes to an event.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| Event name.|
| callback | Function | Yes| Callback invoked when the event is triggered.|

**Example**    

  ```ts
  import Ability from '@ohos.application.Ability';
  
  export default class MainAbility extends Ability {
      onForeground() {
          this.context.eventHub.on("123", this.func1);
          this.context.eventHub.on("123", () => {
              console.log("call anonymous func 1");
          });
          // Result
          // func1 is called
          // call anonymous func 1
          this.context.eventHub.emit("123"); 
      }
      func1() {
          console.log("func1 is called");
      }
  }
  ```


## EventHub.off

off(event: string, callback?: Function): void;

Unsubscribes from an event. If **callback** is specified, this API unsubscribes from the specified callback. If **callback** is not specified, this API unsubscribes from all callbacks in the event.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| Event name.|
| callback | Function | No| Callback for the event. If **callback** is unspecified, all callbacks of the event are unsubscribed.|

**Example**    

  ```ts
  import Ability from '@ohos.application.Ability';
  
  export default class MainAbility extends Ability {
      onForeground() {
          this.context.eventHub.on("123", this.func1);
          this.context.eventHub.off("123", this.func1); // Unsubscribe from func1.
          this.context.eventHub.on("123", this.func1);
          this.context.eventHub.on("123", this.func2);
          this.context.eventHub.off("123"); // Unsubscribe from func1 and func2.
      }
      func1() {
          console.log("func1 is called");
      }
      func2() {
          console.log("func2 is called");
      }
  }
  ```


## EventHub.emit

emit(event: string, ...args: Object[]): void;

Triggers an event.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| Event name.|
| ...args | Object[] | Yes| Variable parameters, which are passed to the callback when the event is triggered.|

**Example**    

  ```ts
  import Ability from '@ohos.application.Ability';
  
  export default class MainAbility extends Ability {
      onForeground() {
          this.context.eventHub.on("123", this.func1);
          // Result
          // func1 is called,undefined,undefined
          this.context.eventHub.emit("123");
          // Result
          // func1 is called,1,undefined
          this.context.eventHub.emit("123", 1);
          // Result
          // func1 is called,1,2
          this.context.eventHub.emit("123", 1, 2);
      }
      func1(a, b) {
          console.log("func1 is called," + a + "," + b);
      }
  }
  ```
