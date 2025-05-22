# EventHub

The **EventHub** module provides APIs to subscribe to, unsubscribe from, and trigger events.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Usage

Before using any APIs in the **EventHub**, you must obtain an **EventHub** instance through the member variable **context** of the **UIAbility** instance.

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  eventFunc() {
    console.log('eventFunc is called');
  }

  onCreate() {
    this.context.eventHub.on('myEvent', this.eventFunc);
  }
}
```
EventHub is not a global event center. Different context objects have different EventHub objects. Event subscription, unsubscription, and triggering are performed on a specific EventHub object. Therefore, EventHub cannot be used for event transmission between VMs or processes.

## EventHub.on

on(event: string, callback: Function): void;

Subscribes to an event.
> **NOTE**
>
>  When the callback is triggered by **emit**, the invoker is the **EventHub** object. To change the direction of **this** in **callback**, use an arrow function.

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
When the callback is triggered by **emit**, the invoker is the **EventHub** object. The **EventHub** object does not have the **value** property. Therefore, the result **undefined** is returned.

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
When the callback uses an arrow function, the invoker is the **EntryAbility** object. The **EntryAbility** object has the **value** property. Therefore, the result **12** is returned.

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
