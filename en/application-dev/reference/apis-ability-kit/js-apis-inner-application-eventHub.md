# EventHub

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

EventHub is an event communication mechanism based on the publish-subscribe pattern. It decouples senders and subscribers through event names, supporting efficient data transfer and state synchronization between different service modules. It is primarily used for [data communication between UIAbility components and UI pages](../../application-models/uiability-data-sync-with-ui.md).

Different Context objects have different EventHub objects, and different EventHub objects cannot communicate directly with each other. Event subscription, unsubscription, and triggering all take place on a specific EventHub object.

Since Worker and TaskPool implement [multithreaded concurrency](../../arkts-utils/multi-thread-concurrency-overview.md#multithreaded-concurrency-models) through the actor model, where different virtual machine instances have exclusive memory, EventHub objects cannot be used for inter-thread data communication.


> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
>  - The APIs of this module can be used only in the stage model.

## Constraints

- EventHub cannot be used for data communication between processes.
- EventHub cannot be used for data communication between Worker or TaskPool threads. Instead, use [Emitter for inter-thread communication](../../basic-services/common-event/itc-with-emitter.md).
- Data communication between EventHub objects of different Context objects within the same thread is not supported.
- A Context object converted by [sendableContextManager](js-apis-app-ability-sendableContextManager.md) is considered different from the original Context object, and data communication between their EventHub objects is not supported.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Usage

You need to obtain an EventHub object through a Context object. The following example demonstrates how to obtain the EventHub object of a UIAbility instance's Context object.

```ts
import { common, UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  eventFunc() {
    console.log('eventFunc is called');
  }

  onCreate() {
    // Method 1 (recommended)
    this.context.eventHub.on('myEvent', this.eventFunc);

    // Method 2
    let eventhub = this.context.eventHub as common.EventHub;
    eventhub.on('myEvent', this.eventFunc);
  }
}
```

## EventHub.on

on(event: string, callback: Function): void;

Subscribes to an event.
> **NOTE**
>
>  When the callback is triggered by **emit**, the invoker is the EventHub object. To change the direction of **this** in **callback**, use an arrow function.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| Event name.|
| callback | Function | Yes| Callback invoked when the event is triggered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example 1**
When the callback is triggered by **emit**, the invoker is the EventHub object. The EventHub object does not have the **value** property. Therefore, the result **undefined** is returned.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  value: number = 12;

  onCreate() {
    try {
      this.context.eventHub.on('myEvent', this.eventFunc);
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  onForeground() {
    try {
      // Result
      // eventFunc is called, value: undefined
      this.context.eventHub.emit('myEvent');
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  eventFunc() {
    console.log(`eventFunc is called, value: ${this.value}`);
  }
}
```

**Example 2**
When the callback uses an arrow function, the invoker is the EntryAbility object. The EntryAbility object has the **value** property. Therefore, the result **12** is returned.

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  value: number = 12;

  onCreate() {
    try {
      // Anonymous functions can be used to subscribe to events.
      this.context.eventHub.on('myEvent', () => {
        console.log(`anonymous eventFunc is called, value: ${this.value}`);
      });
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  onForeground() {
    try {
      // Result
      // anonymous eventFunc is called, value: 12
      this.context.eventHub.emit('myEvent');
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  eventFunc() {
    console.log(`eventFunc is called, value: ${this.value}`);
  }
}
```

## EventHub.off

off(event: string, callback?: Function): void;

Unsubscribes from an event.
 - If **callback** is specified, this API unsubscribes from the given event with the specified callback.
 - If **callback** is not specified, this API unsubscribes from the given event with all callbacks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| Event name.|
| callback | Function | No| Callback for the event. If **callback** is unspecified, the given event with all callbacks is unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    try {
      this.context.eventHub.on('myEvent', this.eventFunc1);
      this.context.eventHub.off('myEvent', this.eventFunc1); // Unsubscribe from the myEvent event with the callback eventFunc1.
      this.context.eventHub.on('myEvent', this.eventFunc1);
      this.context.eventHub.on('myEvent', this.eventFunc2);
      this.context.eventHub.off('myEvent'); // Unsubscribe from the myEvent event with all the callbacks (eventFunc1 and eventFunc2).
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  eventFunc1() {
    console.log('eventFunc1 is called');
  }

  eventFunc2() {
    console.log('eventFunc2 is called');
  }
}
```

## EventHub.emit

emit(event: string, ...args: Object[]): void;

Triggers an event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| Event name.|
| ...args | Object[] | No| Variable parameters, which are passed to the callback when the event is triggered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    this.context.eventHub.on('myEvent', this.eventFunc);
  }

  onDestroy() {
    try {
      // Result
      // eventFunc is called,undefined,undefined
      this.context.eventHub.emit('myEvent');
      // Result
      // eventFunc is called,1,undefined
      this.context.eventHub.emit('myEvent', 1);
      // Result
      // eventFunc is called,1,2
      this.context.eventHub.emit('myEvent', 1, 2);
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  eventFunc(argOne: number, argTwo: number) {
    console.log(`eventFunc is called, ${argOne}, ${argTwo}`);
  }
}
```
