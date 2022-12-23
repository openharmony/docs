# @ohos.events.emitter (Emitter)

本模块提供了在同一进程不同线程间，或同一进程同一线程内，发送和处理事件的能力，包括持续订阅事件、单次订阅事件、取消订阅事件，以及发送事件到事件队列的能力。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口在FA模型及Stage模型下均可使用。

## 导入模块

```javascript
import emitter from '@ohos.events.emitter'
```

## 权限列表

无权限要求。

## emitter.on

on(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

持续订阅指定的事件，并在接收到该事件时，执行对应的回调处理函数。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                     |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------ |
| event    | [InnerEvent](#innerevent)           | 是   | 持续订阅的事件，其中[EventPriority](#eventpriority)，在订阅事件时无需指定，也不生效 |
| callback | Callback\<[EventData](#eventdata)\> | 是   | 接收到该事件时需要执行的回调处理函数                       |

**示例：**

```javascript
let innerEvent = {
    eventId: 1
};

// 收到eventId为1的事件后执行该回调函数
function emitterCallback() {
    console.info('callback');
}
emitter.on(innerEvent, emitterCallback);
```

## emitter.once

once(event: [InnerEvent](#innerevent), callback: Callback\<[EventData](#eventdata)\>): void

单次订阅指定的事件，并在接收到该事件并执行完相应的回调函数后，自动取消订阅。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                                            |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------------------------ |
| event    | [InnerEvent](#innerevent)           | 是   | 单次订阅的事件，其中[EventPriority](#eventpriority)，在订阅事件时无需指定，也不生效 |
| callback | Callback\<[EventData](#innerevent)\> | 是   | 接收到该事件时需要执行的回调处理函数                                             |

**示例：**

```javascript
let innerEvent = {
    eventId: 1
};

// 收到eventId为1的事件后执行该回调函数
function emitterCallback() {
    console.info('once callback');
};
emitter.once(innerEvent, emitterCallback);
```

## emitter.off

off(eventId: number): void

取消所有针对该事件ID的订阅。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型   | 必填 | 说明   |
| ------- | ------ | ---- | ------ |
| eventId | number | 是   | 事件ID |

**示例：**

```javascript
emitter.off(1);
```

## emitter.emit

emit(event: [InnerEvent](#innerevent), data?: [EventData](#eventdata)): void

发送指定的事件。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名 | 类型                      | 必填 | 说明           |
| ------ | ------------------------- | ---- | ------------- |
| event  | [InnerEvent](#innerevent) | 是   | 发送的事件，其中[EventPriority](#eventpriority)用于指定事件被发送的优先级 |
| data   | [EventData](#eventdata)   | 否   | 事件携带的数据 |

**示例：**

```javascript
let eventData = {
    data: {
        "content": "c",
        "id": 1,
    }
};

let innerEvent = {
    eventId: 1,
    priority: emitter.EventPriority.HIGH
};

emitter.emit(innerEvent, eventData);
```

## EventPriority

用于表示事件被发送的优先级。

**系统能力**:  `SystemCapability.Notification.Emitter`

| 名称      | 值    | 说明                                                |
| --------- | ---- | --------------------------------------------------- |
| IMMEDIATE | 0    | 表示事件被立即投递。                                 |
| HIGH      | 1    | 表示事件先于LOW优先级投递。                           |
| LOW       | 2    | 表示事件优于IDLE优先级投递，事件的默认优先级是LOW。     |
| IDLE      | 3    | 表示在没有其他事件的情况下，才投递该事件。             |

## InnerEvent

订阅或发送的事件，订阅事件时`EventPriority`不生效。

**系统能力**: `SystemCapability.Notification.Emitter`

| 名称     | 类型                        | 可读 | 可写 | 说明                                 |
| -------- | ------------------------------- | ---- | ---- | ------------------------------ |
| eventId  | number                          | 是   | 是   | 事件ID，由开发者定义用来辨别事件。 |
| priority | [EventPriority](#eventpriority) | 是   | 是   | 事件被投递的优先级。             |

## EventData

发送事件时传递的数据。

**系统能力**: `SystemCapability.Notification.Emitter`

| 名称 | 类型           | 可读 | 可写 | 说明           |
| ---- | ------------------ | ---- | ---- | -------------- |
| data | [key: string]: any | 是   | 是   | 发送事件时传递的数据，数据类型支持字符串、整型和布尔型。 |
