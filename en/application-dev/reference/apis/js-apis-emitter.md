# Emitter

The **Emitter** module provides APIs for sending and processing in-process events, including the APIs for processing events that are subscribed to in persistent or one-shot manner, unsubscribing from events, and emitting events to the event queue.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7.

## Modules to Import

```javascript
import emitter from '@ohos.events.emitter'
```

## Required Permissions

None

## emitter.on

on(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in persistent manner. This API uses a callback to return the event.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                   |
| -------- | ----------------------------------- | ---- | --------------------------------------- |
| event    | [InnerEvent](#innerevent)           | Yes  | Event to subscribe to in persistent manner. The **EventPriority** settings do not take effect.|
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback used to return the event.               |

**Example**

```javascript
let innerEvent = {
    eventId: 1
};
function EmitterCallback(eventData) {
    console.info('callback');
}
emitter.on(innerEvent, EmitterCallback);
```

## emitter.once

once(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is received.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name  | Type                               | Mandatory| Description                                   |
| -------- | ----------------------------------- | ---- | --------------------------------------- |
| event    | [InnerEvent](#innerevent)           | Yes  | Event to subscribe to in one-shot manner. The **EventPriority** settings do not take effect.|
| callback | Callback\<[EventData](#eventdata)\> | Yes  | Callback used to return the event.               |

**Example**

```javascript
let innerEvent = {
    eventId: 1
};
function EmitterCallback(eventData) {
    console.info('once callback');
};
emitter.once(innerEvent, EmitterCallback);
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

```javascript
emitter.off(1);
```

## emitter.emit

emit(event: InnerEvent, data?: EventData): void

Emits an event to the event queue.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

| Name| Type                     | Mandatory| Description          |
| ------ | ------------------------- | ---- | -------------- |
| event  | [InnerEvent](#innerevent) | Yes  | Event to emit.    |
| data   | [EventData](#eventdata)   | No  | Data carried by the event.|

**Example**

```javascript
let eventData = {
    data: {
        "content": "c",
        "id": 1,
    }};
let innerEvent = {
    eventId: 1,
    priority: emitter.EventPriority.HIGH
};
emitter.emit(innerEvent, eventData);
```

## EventPriority

Enumerates the event emit priority levels.

**System capability**: SystemCapability.Notification.Emitter

| Name     | Value  | Description                                               |
| --------- | ---- | --------------------------------------------------- |
| IMMEDIATE | 0    | The event will be emitted immediately.                               |
| HIGH      | 1    | The event will be emitted before low-priority events.                        |
| LOW       | 2    | The event will be emitted before idle-priority events. By default, an event is in LOW priority.|
| IDLE      | 3    | The event will be emitted after all the other events.         |

## InnerEvent

Describes an in-process event.

**System capability**: SystemCapability.Notification.Emitter

| Name    | Type                       | Readable| Writable| Description                              |
| -------- | ------------------------------- | ---- | ---- | ---------------------------------- |
| eventId  | number                          | Yes  | Yes  | Event ID.|
| priority | [EventPriority](#eventpriority) | Yes  | Yes  | Emit priority of the event.        |

## EventData

Describes the data passed in the event.

**System capability**: SystemCapability.Notification.Emitter

| Name| Type          | Readable| Writable| Description          |
| ---- | ------------------ | ---- | ---- | -------------- |
| data | [key: string]: any | Yes  | Yes  | Data carried by the event. The data type can be String, Integer, or Boolean.|
