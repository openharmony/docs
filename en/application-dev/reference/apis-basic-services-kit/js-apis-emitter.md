# @ohos.events.emitter (Emitter)

The **Emitter** module provides the capabilities of sending and processing inter- or intra-thread events in a process. You can use the APIs of this module to subscribe to an event in persistent or one-shot manner, unsubscribe from an event, or emit an event to the event queue.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { emitter } from '@kit.BasicServicesKit';
```

## Required Permissions

None.

## emitter.on

on(event: InnerEvent, callback: Callback\<EventData\>): void

Subscribes to an event in persistent manner and executes a callback after the event is received.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| event    | [InnerEvent](#innerevent)           | Yes  | Event to subscribe to in persistent manner. The [EventPriority](#eventpriority) parameter is not required and does not take effect.|
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to be executed when the event is received.                      |

**Example**

```ts
let innerEvent: emitter.InnerEvent = {
  eventId: 1
};

// Execute the callback after receiving the event whose eventId is 1.
emitter.on(innerEvent, () => {
  console.info('callback');
});
```

## emitter.on<sup>11+</sup>

on(eventId: string, callback:  Callback\<EventData\>): void

Subscribes to an event in persistent manner and executes a callback after the event is received.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                  |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| eventId    | string                              | Yes  | Event to subscribe to in persistent manner. The value cannot be an empty string and exceed 10240 bytes.                      |
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to be executed when the event is received.|

**Example**

```ts
// Execute the callback after receiving the event whose eventId is eventId.
emitter.on("eventId", () => {
  console.info('callback');
});
```

## emitter.on<sup>12+</sup>

on<T\>(eventId: string, callback:  Callback\<GenericEventData<T\>\>): void

Subscribes to an event in persistent manner and executes a callback after the event is received.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                  |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| eventId    | string                              | Yes  | Event to subscribe to in persistent manner. The value cannot be an empty string and exceed 10240 bytes.                      |
| callback | Callback\<[GenericEventData<T\>](#genericeventdatat12)\> | Yes  | Callback to be executed when the event is received.|

**Example**

```ts
@Sendable
class Sample {
    constructor() {
        this.count = 100;
    }
    printCount() {
        console.info('Print count : ' + this.count);
    }
    count: number;
}

let callback = (eventData: emitter.GenericEventData<Sample>): void => {
   let storage: Sample = eventData.data!;
   storage.printCount();
}
// Execute the callback after receiving the event whose eventId is eventId.
emitter.on("eventId", callback);
```

## emitter.once

once(event: InnerEvent, callback: Callback\<EventData\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is executed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                                        |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| event    | [InnerEvent](#innerevent)           | Yes  | Event to subscribe to in one-shot manner. The [EventPriority](#eventpriority) parameter is not required and does not take effect.|
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to be executed when the event is received.                      |

**Example**

```ts
let innerEvent: emitter.InnerEvent = {
    eventId: 1
};

// Execute the callback after receiving the event whose eventId is 1.
emitter.once(innerEvent, () => {
    console.info('once callback');
});
```

## emitter.once<sup>11+</sup>

once(eventId: string, callback: Callback\<EventData\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is executed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                  |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| eventId    | string                              | Yes  | Event to subscribe to in one-shot manner. The value cannot be an empty string and exceed 10240 bytes.                      |
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to be executed when the event is received.|

**Example**

```ts
// Execute the callback after receiving the event whose eventId is eventId.
emitter.once("eventId", () => {
    console.info('once callback');
});
```

## emitter.once<sup>12+</sup>

once<T\>(eventId: string, callback: Callback\<GenericEventData<T\>\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is executed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                  |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| eventId    | string                              | Yes  | Event to subscribe to in one-shot manner. The value cannot be an empty string and exceed 10240 bytes.                      |
| callback | Callback\<[GenericEventData<T\>](#genericeventdatat12)\> | Yes  | Callback to be executed when the event is received.|

**Example**

```ts
@Sendable
class Sample {
    constructor() {
        this.count = 100;
    }
    printCount() {
        console.info('Print count : ' + this.count);
    }
    count: number;
}

let callback = (eventData: emitter.GenericEventData<Sample>): void => {
   let storage: Sample = eventData.data!;
   storage.printCount();
}
// Execute the callback after receiving the event whose eventId is eventId.
emitter.once("eventId", callback);
```

## emitter.off

off(eventId: number): void

Unsubscribes from an event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type  | Mandatory| Description    |
| ------- | ------ | ---- | -------- |
| eventId | number | Yes  | Event ID.|

**Example**

```ts
// Unregister the callbacks of all events whose eventID is 1.
emitter.off(1);
```

## emitter.off<sup>11+</sup>

off(eventId: string): void

Unsubscribes from an event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type  | Mandatory| Description    |
| ------- | ------ | ---- | -------- |
| eventId | string | Yes  | Event ID. The value cannot be an empty string and exceed 10240 bytes.|

**Example**

```ts
// Unregister the callbacks of all events whose eventID is eventId.
emitter.off("eventId");
```

## emitter.off<sup>10+</sup>

off(eventId: number, callback: Callback\<EventData\>): void

Unsubscribes from an event. If **Callback\<EventData\>** has been registered through the **on** or **once** API, it is unregistered. Otherwise, no processing is performed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type  | Mandatory| Description  |
| ------- | ------ | ---- | ------ |
| eventId | number | Yes  | Event ID.|
| callback | Callback\<[EventData](#eventdata)\> | Yes  |Callback to unregister.  |

**Example**

```ts
// Unregister the callbacks of all events whose eventID is 1.
// If the callback has not been registered, no processing is performed.
emitter.off(1, () => {
  console.info('callback');
});
```

## emitter.off<sup>11+</sup>

off(eventId: string, callback: Callback\<EventData\>): void

Unsubscribes from an event. If **Callback\<EventData\>** has been registered through the **on** or **once** API, it is unregistered. Otherwise, no processing is performed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                      |
| -------- | ----------------------------------- | ---- | -------------------------- |
| eventId  | string                              | Yes  | Event ID. The value cannot be an empty string and exceed 10240 bytes.                  |
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to unregister.|

**Example**

```ts
// Unregister the callback of the event whose eventID is eventId.
// If the callback has not been registered, no processing is performed.
emitter.off("eventId", () => {
  console.info('callback');
});
```

## emitter.off<sup>12+</sup>

off<T\>(eventId: string, callback: Callback\<GenericEventData<T\>\>): void

Unsubscribes from an event. If **Callback\<GenericEventData<T\>\>** has been registered through the **on** or **once** API, it is unregistered. Otherwise, no processing is performed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                      |
| -------- | ----------------------------------- | ---- | -------------------------- |
| eventId  | string                              | Yes  | Event ID. The value cannot be an empty string and exceed 10240 bytes.                  |
| callback | Callback\<[GenericEventData<T\>](#genericeventdatat12)\> | Yes  | Callback to unregister.|

**Example**

```ts
@Sendable
class Sample {
    constructor() {
        this.count = 100;
    }
    printCount() {
        console.info('Print count : ' + this.count);
    }
    count: number;
}

let callback = (eventData: emitter.GenericEventData<Sample>): void => {
   let storage: Sample = eventData.data!;
   storage.printCount();
}
// Unregister the callback of the event whose eventID is eventId.
// If the callback has not been registered, no processing is performed.
emitter.off("eventId", callback);
```

## emitter.emit

emit(event: InnerEvent, data?: EventData): void

Emits the specified event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name| Type                     | Mandatory| Description          |
| ------ | ------------------------- | ---- | ------------- |
| event  | [InnerEvent](#innerevent) | Yes  | Event to emit, where [EventPriority](#eventpriority) specifies the emit priority of the event.|
| data   | [EventData](#eventdata)   | No  | Data passed in the event.|

**Example**

```ts
let eventData: emitter.EventData = {
    data: {
        "content": "content",
        "id": 1,
    }
};

let innerEvent: emitter.InnerEvent = {
    eventId: 1,
    priority: emitter.EventPriority.HIGH
};

emitter.emit(innerEvent, eventData);
```

## emitter.emit<sup>11+</sup>

emit(eventId: string, data?: EventData): void

Emits the specified event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type                   | Mandatory| Description            |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | Yes  | ID of the event to emit. The value cannot be an empty string and exceed 10240 bytes.  |
| data    | [EventData](#eventdata) | No  | Data passed in the event.|

**Example**

```ts
let eventData: emitter.EventData = {
    data: {
        "content": "content",
        "id": 1,
    }
};

emitter.emit("eventId", eventData);
```

## emitter.emit<sup>12+</sup>

emit<T\>(eventId: string, data?: GenericEventData<T\>): void

Emits the specified event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type                   | Mandatory| Description            |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | Yes  | ID of the event to emit. The value cannot be an empty string and exceed 10240 bytes.  |
| data    | [GenericEventData<T\>](#genericeventdatat12) | No  | Data passed in the event.|

**Example**

```ts
@Sendable
class Sample {
    constructor() {
        this.count = 100;
    }
    printCount() {
        console.info('Print count : ' + this.count);
    }
    count: number;
}

class SelfEventData implements emitter.EventData {
    data: Sample = new Sample();
}

let eventData = new SelfEventData();
emitter.emit("eventId", eventData);
```

## emitter.emit<sup>11+</sup>

emit(eventId: string, options: Options, data?: EventData): void

Emits an event of a specified priority.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type                   | Mandatory| Description            |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | Yes  | ID of the event to emit. The value cannot be an empty string and exceed 10240 bytes.  |
| options | [Options](#options11)   | Yes  | Event emit priority.    |
| data    | [EventData](#eventdata) | No  | Data passed in the event.|

**Example**

```ts
let eventData: emitter.EventData = {
    data: {
        "content": "content",
        "id": 1,
    }
};

let options: emitter.Options = {
    priority: emitter.EventPriority.HIGH
};

emitter.emit("eventId", options, eventData);
```

## emitter.emit<sup>12+</sup>

emit<T\>(eventId: string, options: Options, data?: GenericEventData<T\>): void

Emits an event of a specified priority.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type                   | Mandatory| Description            |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | Yes  | ID of the event to emit. The value cannot be an empty string and exceed 10240 bytes.  |
| options | [Options](#options11)   | Yes  | Event emit priority.    |
| data    | [GenericEventData<T\>](#genericeventdatat12) | No  | Data passed in the event.|

**Example**

```ts
@Sendable
class Sample {
    constructor() {
        this.count = 100;
    }
    printCount() {
        console.info('Print count : ' + this.count);
    }
    count: number;
}

class SelfEventData implements emitter.EventData {
    data: Sample = new Sample();
}

let options: emitter.Options = {
    priority: emitter.EventPriority.HIGH
};

let eventData = new SelfEventData();
emitter.emit("eventId", options, eventData);
```

## emitter.getListenerCount<sup>11+</sup>

getListenerCount(eventId: number | string): number

Obtains the number of subscriptions to a specified event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type          | Mandatory| Description    |
| ------- | -------------- | ---- | -------- |
| eventId | number \| string | Yes  | Event ID. The value of the string type cannot be an empty string.|

**Example**

```ts
let count = emitter.getListenerCount("eventId");
```

## EventPriority

Enumerates the event emit priority levels.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

| Name     | Value   | Description                                               |
| --------- | ---- | --------------------------------------------------- |
| IMMEDIATE | 0    | The event will be emitted immediately.                                |
| HIGH      | 1    | The event will be emitted before low-priority events.                          |
| LOW       | 2    | The event will be emitted before idle-priority events. By default, an event is in LOW priority.    |
| IDLE      | 3    | The event will be emitted after all the other events.            |

## InnerEvent

Describes an event to subscribe to or emit. The **EventPriority** settings do not take effect under event subscription.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

| Name    | Type                       | Read Only| Optional| Description                                |
| -------- | ------------------------------- | ---- | ---- | ------------------------------ |
| eventId  | number                          | No  | No  | Event ID.|
| priority | [EventPriority](#eventpriority) | No  | Yes  | Emit priority of the event.            |

## EventData

Describes data passed in the event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

| Name| Type          | Read Only| Optional| Description          |
| ---- | ------------------ | ---- | ---- | -------------- |
| data | { [key: string]: any } | No  | Yes  | Data passed in the event. The value can be in any of the following types: Array, ArrayBuffer, Boolean, DataView, Date, Error, Map, Number, Object, Primitive (except symbol), RegExp, Set, String, and TypedArray. The maximum data size is 16 MB.|

## Options<sup>11+</sup>

Describes the event emit priority.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.Emitter

| Name    | Type                           | Read Only| Optional| Description          |
| -------- | ------------------------------- | ---- | ---- | -------------- |
| priority | [EventPriority](#eventpriority) | No  | Yes  | Event priority.|

## GenericEventData<T\><sup>12+</sup>

Describes the generic data passed in the event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Notification.Emitter

| Name    | Type                           | Read Only| Optional| Description          |
| -------- | ------------------------------- | ---- | ---- | -------------- |
| data | T | No  | Yes  | Data passed in the event. **T**: generic type.|
