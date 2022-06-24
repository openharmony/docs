# Emitter

本模块提供发送和处理进程内事件的能力，包括对持续订阅事件或单次订阅事件的处理，取消订阅事件，发送事件到事件队列。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。

## 导入模块

```javascript
import emitter from '@ohos.events.emitter'
```

## 权限列表

无

## EventPriority

用于表示事件被投递的优先级。

| 名称      | 值   | 说明                                              |
| --------- | ---- | ------------------------------------------------- |
| IMMEDIATE | 0    | 表示事件被立即投递。<br/>**系统能力**: SystemCapability.Notification.Emitter                                |
| HIGH      | 1    | 表示事件先于LOW优先级投递。<br/>**系统能力**: SystemCapability.Notification.Emitter                         |
| LOW       | 2    | 表示事件优于IDLE优先级投递，事件的默认优先级是LOW。<br/>**系统能力**: SystemCapability.Notification.Emitter |
| IDLE      | 3    | 表示在没有其他事件的情况下，才投递该事件。<br/>**系统能力**: SystemCapability.Notification.Emitter          |

## emitter.on

on(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

持续订阅某个事件以及接收事件的回调处理。

**系统能力**: SystemCapability.Notification.Emitter

**参数：**

| 参数名   | 类型                                | 必填 | 说明                     |
| -------- | ----------------------------------- | ---- | ------------------------ |
| event    | [InnerEvent](#innerevent)           | 是   | 持续订阅的事件           |
| callback | Callback\<[EventData](#eventdata)\> | 是   | 接收订阅事件时的回调处理 |

**示例：**

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

单次订阅某个事件以及接收事件的回调处理，接收到回调处理后自动取消订阅。

**系统能力**: SystemCapability.Notification.Emitter

**参数：**

| 参数名   | 类型                                | 必填 | 说明                     |
| -------- | ----------------------------------- | ---- | ------------------------ |
| event    | [InnerEvent](#innerevent)           | 是   | 单次订阅的事件           |
| callback | Callback\<[EventData](#eventdata)\> | 是   | 接收订阅事件时的回调处理 |

**示例：**

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

取消订阅某个事件。

**系统能力**: SystemCapability.Notification.Emitter

**参数：**

| 参数名  | 类型   | 必填 | 说明   |
| ------- | ------ | ---- | ------ |
| eventId | number | 是   | 事件ID |

**示例：**

```javascript
emitter.off(1);
```

## emitter.emit

emit(event: InnerEvent, data?: EventData): void

发送一个事件到事件队列。

**系统能力**: SystemCapability.Notification.Emitter

**参数：**

| 参数名 | 类型                      | 必填 | 说明           |
| ------ | ------------------------- | ---- | -------------- |
| event  | [InnerEvent](#innerevent) | 是   | 发送的事件     |
| data   | [EventData](#eventdata)   | 否   | 事件携带的数据 |

**示例：**

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

进程内的事件。

| 名称     | 参数类型                        | 可读 | 可写 | 说明                               |
| -------- | ------------------------------- | ---- | ---- | ---------------------------------- |
| eventId  | number                          | 是   | 是   | 事件的ID，由开发者定义用来辨别事件。<br/>**系统能力**: SystemCapability.Notification.Emitter |
| priority | [EventPriority](#eventpriority) | 是   | 是   | 事件被投递的优先级。<br/>**系统能力**: SystemCapability.Notification.Emitter                 |

## EventData

发送事件时传递的数据。

| 名称 | 参数类型           | 可读 | 可写 | 说明           |
| ---- | ------------------ | ---- | ---- | -------------- |
| data | [key: string]: any | 是   | 是   | 发送事件时传递的数据，数据类型支持字符串、整型和布尔型。<br/>**系统能力**: SystemCapability.Notification.Emitter |
