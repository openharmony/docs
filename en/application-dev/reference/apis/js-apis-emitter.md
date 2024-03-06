# @ohos.events.emitter (Emitter)

The **Emitter** module provides the capabilities of sending and processing inter- or intra-thread events in a process. You can use the APIs of this module to subscribe to an event in persistent or one-shot manner, unsubscribe from an event, or emit an event to the event queue.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import emitter from '@ohos.events.emitter';
```

## Required Permissions

None

## emitter.on

on(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in persistent manner and executes a callback after the event is received.

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

on(eventId: string, callback:  Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in persistent manner and executes a callback after the event is received.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                  |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| event    | string                              | Yes  | Event to subscribe to in persistent manner. The value cannot be an empty string.                      |
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to be executed when the event is received.|

**Example**

```ts
// Execute the callback after receiving the event whose eventId is eventId.
emitter.on("eventId", () => {
  console.info('callback');
});
```

## emitter.once

once(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is executed.

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

once(eventId: string, callback: Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is executed.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                  |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| event    | string                              | Yes  | Event to subscribe to in one-shot manner. The value cannot be an empty string.                      |
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to be executed when the event is received.|

**Example**

```ts
// Execute the callback after receiving the event whose eventId is eventId.
emitter.once("eventId", () => {
    console.info('once callback');
});
```

## emitter.off

off(eventId: number): void

Unsubscribes from an event.

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

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type  | Mandatory| Description    |
| ------- | ------ | ---- | -------- |
| eventId | string | Yes  | Event ID. The value cannot be an empty string.|

**Example**

```ts
// Unregister the callbacks of all events whose eventID is 1.
emitter.off("eventId");
```

## emitter.off<sup>10+</sup>

off(eventId: number, callback: Callback\<[EventData](#eventdata)\>): void

Unsubscribes from an event. If the specified callback has been registered through the **on** or **once** API, it is unregistered. Otherwise, no processing is performed.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type  | Mandatory| Description  |
| ------- | ------ | ---- | ------ |
| eventId | number | Yes  | Event ID.|
| callback<sup>10+</sup> | Callback\<[EventData](#eventdata)\> | Yes  | Callback to unregister.  |

**Example**

```ts
// Unregister the emitterCallback callback for the event whose eventID is 1.
// If the callback has not been registered, no processing is performed.
emitter.off(1, () => {
  console.info('callback');
});
```

## emitter.off<sup>11+</sup>

off(eventId: string, callback: Callback\<[EventData](#eventdata)\>): void

Unsubscribes from an event. If the specified callback has been registered through the **on** or **once** API, it is unregistered. Otherwise, no processing is performed.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                      |
| -------- | ----------------------------------- | ---- | -------------------------- |
| eventId  | string                              | Yes  | Event ID. The value cannot be an empty string.                  |
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to unregister.|

**Example**

```ts
// Unregister the emitterCallback callback for the event whose eventID is eventId.
// If the callback has not been registered, no processing is performed.
emitter.off("eventId", () => {
  console.info('callback');
});
```

## emitter.emit

emit(event: [InnerEvent](#innerevent), data?: [EventData](#eventdata)): void

Emits an event.

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
        "content": "c",
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

emit(eventId: string, data?: [EventData](#eventdata)): void

Emits the specified event.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type                   | Mandatory| Description            |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | Yes  | ID of the event to emit. The value cannot be an empty string.  |
| data    | [EventData](#eventdata) | No  | Data passed in the event.|

**Example**

```ts
let eventData: emitter.EventData = {
    data: {
        "content": "c",
        "id": 1,
    }
};

emitter.emit("eventId", eventData);
```

## emitter.emit<sup>11+</sup>

emit(eventId: string, options: [Options](#options11), data?: [EventData](#eventdata)): void

Emits an event of a specified priority.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type                   | Mandatory| Description            |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | Yes  | ID of the event to emit. The value cannot be an empty string.  |
| options | [Options](#options11)   | Yes  | Event emit priority.    |
| data    | [EventData](#eventdata) | No  | Data passed in the event.|

**Example**

```ts
let eventData: emitter.EventData = {
    data: {
        "content": "c",
        "id": 1,
    }
};

let options: emitter.Options = {
    priority: emitter.EventPriority.HIGH
};

emitter.emit("eventId", options, eventData);
```

## emitter.getListenerCount<sup>11+</sup>

getListenerCount(eventId: number|string): number

Obtains the number of subscriptions to a specified event.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type          | Mandatory| Description    |
| ------- | -------------- | ---- | -------- |
| eventId | number\|string | Yes  | Event ID. The value of the string type cannot be an empty string.|

**Example**

```ts
let count = emitter.getListenerCount("eventId");
```

## EventPriority

Enumerates the event emit priority levels.

**System capability**: SystemCapability.Notification.Emitter

| Name     | Value   | Description                                               |
| --------- | ---- | --------------------------------------------------- |
| IMMEDIATE | 0    | The event will be emitted immediately.                                |
| HIGH      | 1    | The event will be emitted before low-priority events.                          |
| LOW       | 2    | The event will be emitted before idle-priority events. By default, an event is in LOW priority.    |
| IDLE      | 3    | The event will be emitted after all the other events.            |

## InnerEvent

Describes an event to subscribe to or emit. The **EventPriority** settings do not take effect under event subscription.

**System capability**: SystemCapability.Notification.Emitter

| Name    | Type                       | Readable| Writable| Description                                |
| -------- | ------------------------------- | ---- | ---- | ------------------------------ |
| eventId  | number                          | Yes  | Yes  | Event ID.|
| priority | [EventPriority](#eventpriority) | Yes  | Yes  | Emit priority of the event.            |

## EventData

Describes the data passed in the event.

**System capability**: SystemCapability.Notification.Emitter

| Name| Type          | Readable| Writable| Description          |
| ---- | ------------------ | ---- | ---- | -------------- |
| data | [key: string]: any | Yes  | Yes  | Data passed in the event. The value can be in any of the following types: Array, ArrayBuffer, Boolean, DataView, Date, Error, Map, Number, Object, Primitive (except symbol), RegExp, Set, String, and TypedArray. The maximum data size is 16 MB.|

## Options<sup>11+</sup>

Describes the event emit priority.

**System capability**: SystemCapability.Notification.Emitter

| Name    | Type                           | Readable| Writable| Description          |
| -------- | ------------------------------- | ---- | ---- | -------------- |
| priority | [EventPriority](#eventpriority) | Yes  | Yes  | Event priority.|
