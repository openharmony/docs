# EventHub

The **EventHub** module provides APIs to subscribe to, unsubscribe from, and trigger events.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Usage

Before using any APIs in the **EventHub**, you must obtain an **EventHub** instance through the member variable **context** of the **UIAbility** instance.

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    eventFunc(){
        console.log('eventFunc is called');
    }

    onForeground() {
        this.context.eventHub.on('myEvent', this.eventFunc);
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
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onForeground() {
        this.context.eventHub.on('myEvent', this.eventFunc);
        // Anonymous functions can be used to subscribe to events.
        this.context.eventHub.on('myEvent', () => {
            console.log('call anonymous eventFunc');
        });
        // Result
        // eventFunc is called
        // call anonymous eventFunc
        this.context.eventHub.emit('myEvent'); 
    }

    eventFunc() {
        console.log('eventFunc is called');
    }
}
```

## EventHub.off

off(event: string, callback?: Function): void;

Unsubscribes from an event.
 - If **callback** is specified, this API unsubscribes from the given event with the specified callback.
 - If **callback** is not specified, this API unsubscribes from the given event with all callbacks.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| Event name.|
| callback | Function | No| Callback for the event. If **callback** is unspecified, the given event with all callbacks is unsubscribed.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onForeground() {
        this.context.eventHub.on('myEvent', this.eventFunc1);
        this.context.eventHub.off('myEvent', this.eventFunc1); // Unsubscribe from the myEvent event with the callback eventFunc1.
        this.context.eventHub.on('myEvent', this.eventFunc1);
        this.context.eventHub.on('myEvent', this.eventFunc2);
        this.context.eventHub.off('myEvent');  // Unsubscribe from the myEvent event with all the callbacks (eventFunc1 and eventFunc2).
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

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| Event name.|
| ...args | Object[] | Yes| Variable parameters, which are passed to the callback when the event is triggered.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onForeground() {
        this.context.eventHub.on('myEvent', this.eventFunc);
        // Result
        // eventFunc is called,undefined,undefined
        this.context.eventHub.emit('myEvent');
        // Result
        // eventFunc is called,1,undefined
        this.context.eventHub.emit('myEvent', 1);
        // Result
        // eventFunc is called,1,2
        this.context.eventHub.emit('myEvent', 1, 2);
    }

    eventFunc(argOne, argTwo) {
        console.log('eventFunc is called, ${argOne}, ${argTwo}');
    }
}
```
