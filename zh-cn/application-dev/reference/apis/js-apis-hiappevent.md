# 应用打点

本模块提供了应用事件打点能力，包括对打点数据的落盘，以及对打点功能的管理配置。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import hiAppEvent from '@ohos.hiAppEvent';
```

## 使用说明

开发者在使用应用事件打点功能前，需要首先了解应用事件相关的参数规格定义。

**事件领域**

事件领域为string类型，字符串非空且长度在32个字符以内，有效的字符是0-9、a-z、下划线，不能以下划线开头。

**事件名称**

事件名称为string类型，字符串非空且长度在48个字符以内，有效的字符是0-9、a-z、下划线，不能以下划线开头。

**事件类型**

事件类型为[EventType](#eventtype)枚举类型。

**事件参数**

事件参数为object类型，key为事件的参数名称，value为事件的参数值，其规格定义如下：

- 参数名为string类型，字符串非空且长度在16个字符以内，有效的字符是0-9、a-z、下划线，不能以下划线开头或结尾；
- 参数值支持string、number、boolean、Array类型；
- 参数值为string类型时，其长度需在8*1024个字符以内，超出会做截断处理；
- 参数值为Array类型时，Array中的元素类型只能全为string、number、boolean中的一种，且元素个数需在100以内，超出会做丢弃处理；
- 参数个数需在32以内，超出的参数会做丢弃处理。

**事件回调**

开发者在调用事件打点方法后，可以在回调函数中对打点返回值进行处理，当前支持callback形式和Promise形式的回调，其返回值规格定义如下：

- 返回值为0，表示事件校验成功，将事件直接落盘到事件文件；
- 返回值大于0，表示事件校验存在异常参数，在忽略异常参数后将事件落盘到事件文件；
- 返回值小于0，表示事件校验失败，不将事件落盘到事件文件。

**订阅回调**

开发者在调用事件订阅方法后，可以在订阅回调函数中对订阅数据进行处理，其入参定义如下：

- curRow：返回的订阅事件数量；
- curSize：返回的订阅事件数据大小，单位为byte；
- holder：返回的订阅事件数据持有者，可以通过其对订阅事件进行处理。

## hiAppEvent.write<sup>(deprecated)</sup>

write(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback&lt;void&gt;): void

> **说明：** 从 API Version 9 开始废弃，建议使用[hiAppEvent.write](#hiappeventwrite9)替代。

应用事件打点方法，将事件写入到当天的事件文件中，使用callback方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名    | 类型                      | 必填 | 说明           |
| --------- | ------------------------- | ---- | -------------- |
| eventName | string                    | 是   | 事件名称。     |
| eventType | [EventType](#eventtype)   | 是   | 事件类型。     |
| keyValues | object                    | 是   | 事件参数。     |
| callback  | AsyncCallback&lt;void&gt; | 否   | 事件回调函数。 |

**示例：**

```js
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"}, (err, value) => {
    if (err) {
        // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入
        console.error(`failed to write event because ${err.code}`);
        return;
    }

    // 事件写入正常
    console.log(`success to write event: ${value}`);
});
```


## hiAppEvent.write<sup>(deprecated)</sup>

write(eventName: string, eventType: EventType, keyValues: object): Promise&lt;void&gt;

> **说明：** 从 API Version 9 开始废弃，建议使用[hiAppEvent.write](#hiappeventwrite9-1)替代。

应用事件打点方法，将事件写入到当天的事件文件中，使用Promise方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名    | 类型                    | 必填 | 说明       |
| --------- | ----------------------- | ---- | ---------- |
| eventName | string                  | 是   | 事件名称。 |
| eventType | [EventType](#eventtype) | 是   | 事件类型。 |
| keyValues | object                  | 是   | 事件参数。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise对象，可以在其then()、catch()方法中分别对事件写入成功、写入异常的情况进行异步处理。 |

**示例：**

```js
hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"})
    .then((value) => {
        // 事件写入正常
        console.log(`success to write event: ${value}`);
    }).catch((err) => {
        // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入
        console.error(`failed to write event because ${err.code}`);
    });
```

## hiAppEvent.write<sup>9+</sup>

write(info: [AppEventInfo](#appeventinfo9), callback: AsyncCallback&lt;void&gt;): void

应用事件打点方法，将事件写入到当天的事件文件中，可接收[AppEventInfo](#appeventinfo9)类型的事件对象，使用callback方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名   | 类型                           | 必填 | 说明           |
| -------- | ------------------------------ | ---- | -------------- |
| info     | [AppEventInfo](#appeventinfo9) | 是   | 应用事件对象。 |
| callback | AsyncCallback&lt;void&gt;      | 否   | 事件回调函数。 |

**示例：**

```js
hiAppEvent.write({
    domain: "test_domain",
    name: "test_event",
    eventType: hiAppEvent.EventType.FAULT,
    params: {
        int_data: 100,
        str_data: "strValue"
    }
}, (err, value) => {
    if (err) {
        // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入
        console.error(`failed to write event because ${err.code}`);
        return;
    }

    // 事件写入正常
    console.log(`success to write event: ${value}`);
});
```

## hiAppEvent.write<sup>9+</sup>

write(info: [AppEventInfo](#appeventinfo9)): Promise&lt;void&gt;

应用事件打点方法，将事件写入到当天的事件文件中，可接收[AppEventInfo](#appeventinfo9)类型的事件对象，使用Promise方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                           | 必填 | 说明           |
| ------ | ------------------------------ | ---- | -------------- |
| info   | [AppEventInfo](#appeventinfo9) | 是   | 应用事件对象。 |

**返回值：**

| 类型                | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise对象，可以在其then()、catch()方法中分别对事件写入成功、写入异常的情况进行异步处理。 |

**示例：**

```js
hiAppEvent.write({
    domain: "test_domain",
    name: "test_event",
    eventType: hiAppEvent.EventType.FAULT,
    params: {
        int_data: 100,
        str_data: "strValue"
    }
}).then((value) => {
    // 事件写入正常
    console.log(`success to write event: ${value}`);
}).catch((err) => {
    // 事件写入异常：事件存在异常参数时忽略异常参数后继续写入，或者事件校验失败时不执行写入
    console.error(`failed to write event because ${err.code}`);
});
```

## AppEventInfo<sup>9+</sup>

此接口提供了应用事件信息的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 参数类型                | 必填 | 说明       |
| --------- | ----------------------- | ---- | ---------- |
| domain    | string                  | 是   | 事件领域。 |
| name      | string                  | 是   | 事件名称。 |
| eventType | [EventType](#eventtype) | 是   | 事件类型。 |
| params    | object                  | 是   | 事件参数。 |

## hiAppEvent.configure

configure(config: ConfigOption): boolean

应用事件打点配置方法，可用于配置打点开关、文件目录存储限额大小等功能。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                          | 必填 | 说明                     |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | 是   | 应用事件打点配置项对象。 |

**返回值：**

| 类型    | 说明                                                        |
| ------- | ----------------------------------------------------------- |
| boolean | 配置结果，true&nbsp;表示配置成功，false&nbsp;表示配置失败。 |

**示例：**

```js
// 配置应用事件打点功能开关
hiAppEvent.configure({
    disable: true
});

// 配置事件文件目录存储限额大小
hiAppEvent.configure({
    maxStorage: '100M'
});
```

## ConfigOption

此接口提供了应用打点的配置选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 参数名     | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | 否   | 应用打点功能开关。配置值为true表示关闭打点功能，false表示不关闭打点功能。 |
| maxStorage | string  | 否   | 打点数据本地存储文件所在目录的配额大小，默认限额为“10M”。所在目录大小超出限额后会对目录进行清理操作，会按从旧到新的顺序逐个删除打点数据文件，直到目录大小不超出限额时停止。 |

## hiAppEvent.addWatcher<sup>9+</sup>

addWatcher(watcher: [Watcher](#watcher9)): [AppEventPackageHolder](#appeventpackageholder9)

添加应用事件订阅者。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名  | 类型                 | 必填 | 说明             |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher9) | 是   | 应用事件订阅者。 |

**返回值：**

| 类型                                             | 说明                                 |
| ------------------------------------------------ | ------------------------------------ |
| [AppEventPackageHolder](#appeventpackageholder9) | 订阅数据持有者，订阅失败时返回null。 |

**示例：**

```js
// 1. 如果订阅者传入了回调的相关参数，则可以选择在自动触发的回调函数中对订阅事件进行处理
hiAppEvent.addWatcher({
    name: "watcher1",
    appEventFilters: [
        {
            domain: "domain_test1",
            eventTypes: [hiAppEvent.EventType.FAULT, hiAppEvent.EventType.BEHAVIOR]
        }
    ],
    triggerCondition: {
        row: 10,
        size: 1000,
        timeOut: 1
    },
    onTrigger: function (curRow, curSize, holder) {
        if (holder == null) {
            console.error("holder is null");
            return;
        }
        let eventPkg = null;
        while ((eventPkg = holder.takeNext()) != null) {
            console.info("eventPkg.packageId=" + eventPkg.packageId);
            console.info("eventPkg.row=" + eventPkg.row);
            console.info("eventPkg.size=" + eventPkg.size);
            for (const eventInfo of eventPkg.data) {
                console.info("eventPkg.data=" + eventInfo);
            }
        }
    }
});

// 2. 如果订阅者未传入回调的相关参数，则可以选择使用返回的holder对象手动去处理订阅事件
let holder = hiAppEvent.addWatcher({
    name: "watcher2",
});
if (holder != null) {
    let eventPkg = null;
    while ((eventPkg = holder.takeNext()) != null) {
        console.info("eventPkg.packageId=" + eventPkg.packageId);
        console.info("eventPkg.row=" + eventPkg.row);
        console.info("eventPkg.size=" + eventPkg.size);
        for (const eventInfo of eventPkg.data) {
            console.info("eventPkg.data=" + eventInfo);
        }
    }
}
```

## hiAppEvent.removeWatcher<sup>9+</sup>

removeWatcher(watcher: [Watcher](#watcher9)): void

移除应用事件订阅者。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名  | 类型                 | 必填 | 说明             |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher9) | 是   | 应用事件订阅者。 |

**示例：**

```js
// 1. 定义一个应用事件订阅者
let watcher = {
    name: "watcher1",
}

// 2. 开始订阅事件
hiAppEvent.addWatcher(watcher);

// 3. 取消订阅事件
hiAppEvent.removeWatcher(watcher);
```

## Watcher<sup>9+</sup>

此接口提供了应用事件订阅者的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称             | 参数类型                                                     | 必填 | 说明                             |
| ---------------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| name             | string                                                       | 是   | 订阅者名称，用于唯一标识订阅者。 |
| triggerCondition | [TriggerCondition](#triggercondition9)                       | 否   | 订阅回调触发条件。               |
| appEventFilters  | [AppEventFilter](#appeventfilter9)[]                         | 否   | 订阅过滤条件。                   |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder9)) => void | 否   | 订阅回调函数 。                  |

## TriggerCondition<sup>9+</sup>

此接口提供了订阅者回调触发条件的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称    | 参数类型 | 必填 | 说明                                   |
| ------- | -------- | ---- | -------------------------------------- |
| row     | number   | 否   | 满足触发回调的事件总数。               |
| size    | number   | 否   | 满足触发回调的事件总大小，单位为byte。 |
| timeOut | number   | 否   | 满足触发回调的定时时长，单位为30s。    |

## AppEventFilter<sup>9+</sup>

此接口提供了订阅者过滤应用事件的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称       | 参数类型                  | 必填 | 说明                     |
| ---------- | ------------------------- | ---- | ------------------------ |
| domain     | string                    | 是   | 需要订阅的事件领域。     |
| eventTypes | [EventType](#eventtype)[] | 否   | 需要订阅的事件类型集合。 |

## AppEventPackageHolder<sup>9+</sup>

订阅数据持有者类，用于对订阅事件进行处理。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

### constructor<sup>9+</sup>

constructor(watcherName: string);

类构造函数，在添加订阅时会被系统自动调用来创建一个订阅数据持有者对象并返回给开发者。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**示例：**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
```

### setSize<sup>9+</sup>

setSize(size: number): void

设置每次取出的应用事件包的数据大小阈值，单位为byte，默认值为512*1024。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**示例：**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
holder.setSize(1000);
```

### takeNext<sup>9+</sup>

takeNext(): [AppEventPackage](#appeventpackage9)

根据设置的数据大小阈值来取出订阅事件数据，当订阅事件数据全部被取出时返回null作为标识。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**示例：**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
let eventPkg = holder.takeNext();
```

## AppEventPackage<sup>9+</sup>

此接口提供了订阅返回的应用事件包的参数定义。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 参数类型 | 说明                           |
| --------- | -------- | ------------------------------ |
| packageId | number   | 事件包ID，从0开始自动递增。    |
| row       | number   | 事件包的事件数量。             |
| size      | number   | 事件包的数据大小，单位为byte。 |
| data      | string[] | 事件包的事件信息。             |

## hiAppEvent.clearData<sup>9+</sup>

clearData(): void

应用打点数据清理方法，将应用存储在本地的打点数据进行清除。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**示例：**

```js
hiAppEvent.clearData();
```


## EventType

事件类型枚举。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 默认值 | 说明           |
| --------- | ------ | -------------- |
| FAULT     | 1      | 故障类型事件。 |
| STATISTIC | 2      | 统计类型事件。 |
| SECURITY  | 3      | 安全类型事件。 |
| BEHAVIOR  | 4      | 行为类型事件。 |


## Event

此接口提供了所有预定义事件的事件名称常量。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                      | 参数类型 | 可读 | 可写 | 说明                 |
| ------------------------- | -------- | ---- | ---- | -------------------- |
| USER_LOGIN                | string   | 是   | 否   | 用户登录事件。       |
| USER_LOGOUT               | string   | 是   | 否   | 用户登出事件。       |
| DISTRIBUTED_SERVICE_START | string   | 是   | 否   | 分布式服务启动事件。 |


## Param

此接口提供了所有预定义参数的参数名称常量。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                            | 参数类型 | 可读 | 可写 | 说明               |
| ------------------------------- | -------- | ---- | ---- | ------------------ |
| USER_ID                         | string   | 是   | 否   | 用户自定义ID。     |
| DISTRIBUTED_SERVICE_NAME        | string   | 是   | 否   | 分布式服务名称。   |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string   | 是   | 否   | 分布式服务实例ID。 |