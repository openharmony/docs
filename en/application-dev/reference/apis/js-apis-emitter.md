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

| Name  | Type                               | Mandatory| Description                                                    |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------ |
| event    | [InnerEvent](#innerevent)           | Yes  | Event to subscribe to in persistent manner. The [EventPriority](#eventpriority) settings do not take effect.|
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to execute after the event is received.                      |

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

## emitter.once

once(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is executed.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                                                           |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------------------------ |
| event    | [InnerEvent](#innerevent)           | Yes  | Event to subscribe to in one-shot manner. The [EventPriority](#eventpriority) settings do not take effect.|
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback to execute after the event is received.                                            |

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

## emitter.off

off(eventId: number): void

Unsubscribes from an event.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name | Type  | Mandatory| Description  |
| ------- | ------ | ---- | ------ |
| eventId | number | Yes  | Event ID.|

**Example**

```ts
// Unregister the callbacks of all events whose eventID is 1.
emitter.off(1);
```

## emitter.off<sup>10+<sup>

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

## emitter.emit

emit(event: [InnerEvent](#innerevent), data?: [EventData](#eventdata)): void

Emits an event.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name| Type                     | Mandatory| Description          |
| ------ | ------------------------- | ---- | ------------- |
| event  | [InnerEvent](#innerevent) | Yes  | Event to emit, where [EventPriority](#eventpriority) specifies the emit priority of the event.|
| data   | [EventData](#eventdata)   | No  | Data carried by the event.|

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
| data | [key: string]: any | Yes  | Yes  | Data carried by the event. The value can be a string, integer, or Boolean, wherein a string contains a maximum of 10240 bytes.|
