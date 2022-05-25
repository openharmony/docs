# Emitter

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7.

## Modules to Import

```javascript
import emitter from '@ohos.events.emitter'
```

## Required Permissions

None

## EventPriority

Enumerates the event emit priority levels.

 | Name | Value | Description |
 | --------- | ---- | ------------------------------------------------- |
 | IMMEDIATE | 0 | The event will be emitted immediately.<br>**System capability**: SystemCapability.Notification.Emitter |
 | HIGH | 1 | The event will be emitted before low-priority events.<br>**System capability**: SystemCapability.Notification.Emitter |
 | LOW | 2 | The event will be emitted before idle-priority events. By default, an event is in LOW priority.<br>**System capability**: SystemCapability.Notification.Emitter |
 | IDLE | 3 | The event will be emitted after all the other events.<br>**System capability**: SystemCapability.Notification.Emitter |

## emitter.on

on(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in persistent manner. This API uses a callback to return the event.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | ----------------------------------- | ---- | ------------------------ |
 | event | [InnerEvent](#innerevent) | Yes | Event to subscribe to in persistent manner. |
 | callback | Callback\<[EventData](#eventdata)\> | Yes | Callback used to return the event. |

**Example**

```javascript
var innerEvent = {
    eventId: 1
};
var callback = (eventData) => {
    console.info('callback');
};
emitter.on(innerEvent, callback);
```

## emitter.once

once(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is received.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | ----------------------------------- | ---- | ------------------------ |
 | event | [InnerEvent](#innerevent) | Yes | Event to subscribe to in one-shot manner. |
 | callback | Callback\<[EventData](#eventdata)\> | Yes | Callback used to return the event. |

**Example**

```javascript
var innerEvent = {
    eventId: 1
};
var callback = (eventData) => {
    console.info('once callback');
};
emitter.once(innerEvent, callback);
```

## emitter.off

off(eventId: number): void

Unsubscribes from an event.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

 | Name | Type | Mandatory | Description |
 | ------- | ------ | ---- | ------ |
 | eventId | number | Yes | Event ID. |

**Example**

```javascript
emitter.off(1);
```

## emitter.emit

emit(event: InnerEvent, data?: EventData): void

Emits an event to the event queue.

**System capability**: SystemCapability.Notification.Emitter

**Parameters**

 | Name | Type | Mandatory | Description |
 | ------ | ------------------------- | ---- | -------------- |
 | event | [InnerEvent](#innerevent) | Yes | Event to emit. |
 | data | [EventData](#eventdata) | No | Data carried by the event. |

**Example**

```javascript
var eventData = {
    data: {
        "content": "c",
        "id": 1,
    }};
var innerEvent = {
    eventId: 1,
    priority: emitter.EventPriority.HIGH
};
emitter.emit(innerEvent, eventData);
```

## InnerEvent

Describes an intra-process event.

 | Name | Type | Readable | Writable | Description |
 | -------- | ------------------------------- | ---- | ---- | ---------------------------------- |
 | eventId | number | Yes | Yes | Event ID, which is used to identify an event.<br>**System capability**: SystemCapability.Notification.Emitter |
 | priority | [EventPriority](#eventpriority) | Yes | Yes | Emit priority of the event.<br>**System capability**: SystemCapability.Notification.Emitter |

## EventData

Describes the data passed in the event.

 | Name | Type | Readable | Writable | Description |
 | ---- | ------------------ | ---- | ---- | -------------- |
 | data | [key: string]: any | Yes | Yes | Data carried by the event. The data type can be String, Integer, or Boolean.<br>**System capability**: SystemCapability.Notification.Emitter |
