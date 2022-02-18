# Emitter

> Note: The initial APIs of this module are supported since API version 7.

## Modules to Import

```javascript
import emitter from '@ohos.events.emitter'
```

## System Capabilities

```javascript
SystemCapability.Notification.Emitter
```

## Required Permissions

None

## EventPriority

Enumerates the event emit priority levels.

| Name| Value| Description|
| --------- | ---- | ------------------------------------------------- |
| IMMEDIATE | 0    | The event will be emitted immediately.|
| HIGH      | 1    | The event will be emitted before low-priority events.|
| LOW       | 2    | The event will be emitted before idle-priority events. By default, an event is in LOW priority.|
| IDLE      | 3    | The event will be emitted after all the other events.|

## emitter.on

on(event: [InnerEvent](#InnerEvent), callback: Callback\<[EventData](#EventData)\>): void

Subscribes to an event in persistent manner. This method uses a callback to return the event.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------------------- | ---- | ------------------------ |
| event    | [InnerEvent](#InnerEvent)           | Yes| Event to subscribe to in persistent manner.|
| callback | Callback\<[EventData](#EventData)\> | Yes| Callback used to return the event.|

**Example**

```javascript
var innerEvent = {
    eventId : 1
};
var callback = (eventData) => {
    console.info('callback');
};
emitter.on(innerEvent, callback);
```

## emitter.once

once(event: [InnerEvent](#InnerEvent), callback: Callback\<[EventData](#EventData)\>): void

Subscribes to an event in one-shot manner and unsubscribes from it after the event callback is received.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------------------- | ---- | ------------------------ |
| event    | [InnerEvent](#InnerEvent)           | Yes| Event to subscribe to in one-shot manner.|
| callback | Callback\<[EventData](#EventData)\> | Yes| Callback used to return the event.|

**Example**

```javascript
var innerEvent = {
    eventId : 1
};
var callback = (eventData) => {
    console.info('once callback');
};
emitter.once(innerEvent, callback);
```

## emitter.off

off(eventId: number): void

Unsubscribes from an event.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------ | ---- | -------------- |
| eventId | number | Yes| Event ID.|

**Example**

```javascript
emitter.off(1);
```

## emitter.emit

emit(event: InnerEvent, data?: EventData): void

Emits an event to the event queue.

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------------------------- | ---- | -------------- |
| event  | [InnerEvent](#InnerEvent) | Yes| Event to emit.|
| data   | [EventData](#EventData)   | No| Data carried by the event.|

**Example**

```javascript
var eventData = {
    data: {
        1:"t",
        'content':"c",
        "id":1,
    }};
var innerEvent = {
    eventId : 1,
    priority: emitter.EventPriority.HIGH
};
emitter.emit(innerEvent, eventData);
```

## InnerEvent

Describes an intra-process event.

| Name| Type| Readable| Writable| Description|
| -------- | ------------------------------- | ---- | ---- | ---------------------------------- |
| eventId  | number                          | Yes| Yes| Event ID, which is used to identify an event.|
| priority | [EventPriority](#EventPriority) | Yes| Yes| Emit priority of the event.|

## EventData

Describes the data passed in the event.

| Name| Type| Readable| Writable| Description|
| ---- | ------------------ | ---- | ---- | -------------- |
| data | [key: string]: any | Yes| Yes| Data carried by the event.|
