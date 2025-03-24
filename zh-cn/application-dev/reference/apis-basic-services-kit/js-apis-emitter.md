# @ohos.events.emitter (Emitter)

本模块提供了在同一进程不同线程间，或同一进程同一线程内，发送和处理事件的能力，包括持续订阅事件、单次订阅事件、取消订阅事件，以及发送事件到事件队列的能力。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { emitter } from '@kit.BasicServicesKit';
```

## 权限列表

无权限要求。

## emitter.on

on(event: InnerEvent, callback: Callback\<EventData\>): void

持续订阅指定的事件，并在接收到该事件时，执行对应的回调处理函数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| event    | [InnerEvent](#innerevent)           | 是   | 持续订阅的事件，其中[EventPriority](#eventpriority)，在订阅事件时无需指定，也不生效。 |
| callback | Callback\<[EventData](#eventdata)\> | 是   | 接收到该事件时需要执行的回调处理函数。                       |

**示例：**

```ts
let innerEvent: emitter.InnerEvent = {
  eventId: 1
};

// 收到eventId为1的事件后执行回调函数
emitter.on(innerEvent, () => {
  console.info('callback');
});
```

## emitter.on<sup>11+</sup>

on(eventId: string, callback:  Callback\<EventData\>): void

持续订阅指定事件，并在接收到该事件时，执行对应的回调处理函数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                   |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| eventId    | string                              | 是   | 持续订阅的事件。长度不超过10240字节的自定义字符串，且不可为空字符。                       |
| callback | Callback\<[EventData](#eventdata)\> | 是   | 接收到该事件时需要执行的回调处理函数。 |

**示例：**

```ts
// 收到eventId为"eventId"的事件后执行回调函数
emitter.on("eventId", () => {
  console.info('callback');
});
```

## emitter.on<sup>12+</sup>

on<T\>(eventId: string, callback:  Callback\<GenericEventData<T\>\>): void

持续订阅指定事件，并在接收到该事件时，执行对应的回调处理函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                   |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| eventId    | string                              | 是   | 持续订阅的事件。长度不超过10240字节的自定义字符串，且不可为空字符。                       |
| callback | Callback\<[GenericEventData<T\>](#genericeventdatat12)\> | 是   | 接收到该事件时需要执行的回调处理函数。 |

**示例：**

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
// 收到eventId为"eventId"的事件后执行回调函数
emitter.on("eventId", callback);
```

## emitter.once

once(event: InnerEvent, callback: Callback\<EventData\>): void

单次订阅指定的事件，并在接收到该事件并执行完相应的回调函数后，自动取消订阅。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                                         |
| -------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| event    | [InnerEvent](#innerevent)           | 是   | 单次订阅的事件，其中[EventPriority](#eventpriority)，在订阅事件时无需指定，也不生效。 |
| callback | Callback\<[EventData](#eventdata)\> | 是   | 接收到该事件时需要执行的回调处理函数。                       |

**示例：**

```ts
let innerEvent: emitter.InnerEvent = {
    eventId: 1
};

// 收到eventId为1的事件后执行该回调函数
emitter.once(innerEvent, () => {
    console.info('once callback');
});
```

## emitter.once<sup>11+</sup>

once(eventId: string, callback: Callback\<EventData\>): void

单次订阅指定事件，并在接收到该事件并执行完相应的回调函数后，自动取消订阅。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                   |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| eventId    | string                              | 是   | 单次订阅的事件。长度不超过10240字节的自定义字符串，且不可为空字符。                       |
| callback | Callback\<[EventData](#eventdata)\> | 是   | 接收到该事件时需要执行的回调处理函数。 |

**示例：**

```ts
// 收到eventId为"eventId"的事件后执行该回调函数
emitter.once("eventId", () => {
    console.info('once callback');
});
```

## emitter.once<sup>12+</sup>

once<T\>(eventId: string, callback: Callback\<GenericEventData<T\>\>): void

单次订阅指定事件，并在接收到该事件并执行完相应的回调函数后，自动取消订阅。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                   |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| eventId    | string                              | 是   | 单次订阅的事件。长度不超过10240字节的自定义字符串，且不可为空字符。                       |
| callback | Callback\<[GenericEventData<T\>](#genericeventdatat12)\> | 是   | 接收到该事件时需要执行的回调处理函数。 |

**示例：**

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
// 收到eventId为"eventId"的事件后执行回调函数
emitter.once("eventId", callback);
```

## emitter.off

off(eventId: number): void

取消针对该事件ID的订阅。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型   | 必填 | 说明     |
| ------- | ------ | ---- | -------- |
| eventId | number | 是   | 事件ID。 |

**示例：**

```ts
// 取消eventID为1的所有事件回调处理函数
emitter.off(1);
```

## emitter.off<sup>11+</sup>

off(eventId: string): void

取消订阅指定事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型   | 必填 | 说明     |
| ------- | ------ | ---- | -------- |
| eventId | string | 是   | 事件ID。长度不超过10240字节的自定义字符串，且不可为空字符。 |

**示例：**

```ts
// 取消eventID为"eventId"的所有事件回调处理函数
emitter.off("eventId");
```

## emitter.off<sup>10+</sup>

off(eventId: number, callback: Callback\<EventData\>): void

取消针对该事件ID的订阅，传入可选参数Callback\<EventData\>，并且该Callback\<EventData\>已经通过on或者once接口订阅，则取消该订阅；否则，不做任何处理。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型   | 必填 | 说明   |
| ------- | ------ | ---- | ------ |
| eventId | number | 是   | 事件ID。 |
| callback | Callback\<[EventData](#eventdata)\> | 是   |取消该事件的回调处理函数。   |

**示例：**

```ts
// 取消eventID为1的事件回调处理函数
// 如果该回调处理函数没有被订阅，则不做任何处理
emitter.off(1, () => {
  console.info('callback');
});
```

## emitter.off<sup>11+</sup>

off(eventId: string, callback: Callback\<EventData\>): void

取消针对该事件ID的订阅，传入可选参数Callback\<EventData\>，并且该Callback\<EventData\>已经通过on或者once接口订阅，则取消该订阅；否则，不做任何处理。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                       |
| -------- | ----------------------------------- | ---- | -------------------------- |
| eventId  | string                              | 是   | 事件ID。长度不超过10240字节的自定义字符串，且不可为空字符。                   |
| callback | Callback\<[EventData](#eventdata)\> | 是   | 取消该事件的回调处理函数。 |

**示例：**

```ts
// 取消eventID为"eventId"的事件回调处理函数
// 如果该回调处理函数没有被订阅，则不做任何处理
emitter.off("eventId", () => {
  console.info('callback');
});
```

## emitter.off<sup>12+</sup>

off<T\>(eventId: string, callback: Callback\<GenericEventData<T\>\>): void

取消针对该事件ID的订阅，传入可选参数Callback\<GenericEventData<T\>\>，如果该Callback\<GenericEventData<T\>\>已经通过on或者once接口订阅，则取消该订阅；否则，不做任何处理。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名   | 类型                                | 必填 | 说明                       |
| -------- | ----------------------------------- | ---- | -------------------------- |
| eventId  | string                              | 是   | 事件ID。长度不超过10240字节的自定义字符串，且不可为空字符。                   |
| callback | Callback\<[GenericEventData<T\>](#genericeventdatat12)\> | 是   | 取消该事件的回调处理函数。 |

**示例：**

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
// 取消eventID为"eventId"的事件回调处理函数
// 如果该回调处理函数没有被订阅，则不做任何处理
emitter.off("eventId", callback);
```

## emitter.emit

emit(event: InnerEvent, data?: EventData): void

发送指定的事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名 | 类型                      | 必填 | 说明           |
| ------ | ------------------------- | ---- | ------------- |
| event  | [InnerEvent](#innerevent) | 是   | 发送的事件，其中[EventPriority](#eventpriority)用于指定事件被发送的优先级。 |
| data   | [EventData](#eventdata)   | 否   | 事件携带的数据。 |

**示例：**

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

发送指定事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型                    | 必填 | 说明             |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | 是   | 发送的事件ID。长度不超过10240字节的自定义字符串，且不可为空字符。   |
| data    | [EventData](#eventdata) | 否   | 事件携带的数据。 |

**示例：**

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

发送指定事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型                    | 必填 | 说明             |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | 是   | 发送的事件ID。长度不超过10240字节的自定义字符串，且不可为空字符。   |
| data    | [GenericEventData<T\>](#genericeventdatat12) | 否   | 事件携带的数据。 |

**示例：**

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

发送指定优先级事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型                    | 必填 | 说明             |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | 是   | 发送的事件ID。长度不超过10240字节的自定义字符串，且不可为空字符。   |
| options | [Options](#options11)   | 是   | 事件优先级。     |
| data    | [EventData](#eventdata) | 否   | 事件携带的数据。 |

**示例：**

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

发送指定优先级事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型                    | 必填 | 说明             |
| ------- | ----------------------- | ---- | ---------------- |
| eventId | string                  | 是   | 发送的事件ID。长度不超过10240字节的自定义字符串，且不可为空字符。   |
| options | [Options](#options11)   | 是   | 事件优先级。     |
| data    | [GenericEventData<T\>](#genericeventdatat12) | 否   | 事件携带的数据。 |

**示例：**

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

获取指定事件的订阅数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

**参数：**

| 参数名  | 类型           | 必填 | 说明     |
| ------- | -------------- | ---- | -------- |
| eventId | number \| string | 是   | 事件ID，string类型的eventId不支持空字符串。 |

**示例：**

```ts
let count = emitter.getListenerCount("eventId");
```

## EventPriority

用于表示事件被发送的优先级。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**:  `SystemCapability.Notification.Emitter`

| 名称      | 值    | 说明                                                |
| --------- | ---- | --------------------------------------------------- |
| IMMEDIATE | 0    | 表示事件被立即投递。                                 |
| HIGH      | 1    | 表示事件先于LOW优先级投递。                           |
| LOW       | 2    | 表示事件优于IDLE优先级投递，事件的默认优先级是LOW。     |
| IDLE      | 3    | 表示在没有其他事件的情况下，才投递该事件。             |

## InnerEvent

订阅或发送的事件，订阅事件时`EventPriority`不生效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

| 名称     | 类型                        | 只读 | 可选 | 说明                                 |
| -------- | ------------------------------- | ---- | ---- | ------------------------------ |
| eventId  | number                          | 否   | 否   | 事件ID，由开发者定义用来辨别事件。 |
| priority | [EventPriority](#eventpriority) | 否   | 是   | 事件被投递的优先级。             |

## EventData

发送事件时传递的数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

| 名称 | 类型           | 只读 | 可选 | 说明           |
| ---- | ------------------ | ---- | ---- | -------------- |
| data | { [key: string]: any } | 否   | 是   | 发送事件时传递的数据，支持数据类型包括Array、ArrayBuffer、Boolean、DataView、Date、Error、Map、Number、Object、Primitive（除了symbol）、RegExp、Set、String、TypedArray，数据大小最大为16M。 |

## Options<sup>11+</sup>

发送事件的优先级。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

| 名称     | 类型                            | 只读 | 可选 | 说明           |
| -------- | ------------------------------- | ---- | ---- | -------------- |
| priority | [EventPriority](#eventpriority) | 否   | 是   | 事件的优先级。 |

## GenericEventData<T\><sup>12+</sup>

发送事件时传递的泛型数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**: `SystemCapability.Notification.Emitter`

| 名称     | 类型                            | 只读 | 可选 | 说明           |
| -------- | ------------------------------- | ---- | ---- | -------------- |
| data | T | 否   | 是   | 发送事件时传递的数据。T：泛型类型。 |

