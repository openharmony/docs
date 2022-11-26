# 应用事件打点

本模块提供了应用事件打点能力，包括应用事件落盘、应用事件订阅、应用事件清理、打点功能配置等功能。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import hiAppEvent from '@ohos.hiviewdfx.hiAppEvent';
```

## hiAppEvent.write

write(info: [AppEventInfo](#appeventinfo), callback: AsyncCallback&lt;void&gt;): void

应用事件打点方法，将事件写入到当天的事件文件中，可接收[AppEventInfo](#appeventinfo)类型的事件对象，使用callback方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名   | 类型                           | 必填 | 说明           |
| -------- | ------------------------------ | ---- | -------------- |
| info     | [AppEventInfo](#appeventinfo) | 是   | 应用事件对象。 |
| callback | AsyncCallback&lt;void&gt;      | 是   | 打点回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 11100001 | Function is disabled.                         |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

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
}, (err) => {
    if (err) {
        console.error(`code: ${err.code}, message: ${err.message}`);
        return;
    }
    console.log(`success to write event`);
});
```

## hiAppEvent.write

write(info: [AppEventInfo](#appeventinfo)): Promise&lt;void&gt;

应用事件打点方法，将事件写入到当天的事件文件中，可接收[AppEventInfo](#appeventinfo)类型的事件对象，使用Promise方式作为异步回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                           | 必填 | 说明           |
| ------ | ------------------------------ | ---- | -------------- |
| info   | [AppEventInfo](#appeventinfo) | 是   | 应用事件对象。 |

**返回值：**

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息                                      |
| -------- | --------------------------------------------- |
| 11100001 | Function is disabled.                         |
| 11101001 | Invalid event domain.                         |
| 11101002 | Invalid event name.                           |
| 11101003 | Invalid number of event parameters.           |
| 11101004 | Invalid string length of the event parameter. |
| 11101005 | Invalid event parameter name.                 |
| 11101006 | Invalid array length of the event parameter.  |

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
}).then(() => {
    console.log(`success to write event`);
}).catch((err) => {
    console.error(`code: ${err.code}, message: ${err.message}`);
});
```

## AppEventInfo

此接口提供了应用事件信息的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 类型                    | 必填 | 说明       |
| --------- | ----------------------- | ---- | ---------- |
| domain    | string                  | 是   | 事件领域。 |
| name      | string                  | 是   | 事件名称。 |
| eventType | [EventType](#eventtype) | 是   | 事件类型。 |
| params    | object                  | 是   | 事件参数。 |

## hiAppEvent.configure

configure(config: [ConfigOption](configoption)): void

应用事件打点配置方法，可用于配置打点开关、目录存储配额大小等功能。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型                          | 必填 | 说明                     |
| ------ | ----------------------------- | ---- | ------------------------ |
| config | [ConfigOption](#configoption) | 是   | 应用事件打点配置项对象。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 11103001 | Invalid max storage quota value. |

**示例：**

```js
// 配置打点开关为关闭状态
hiAppEvent.configure({
    disable: true
});

// 配置文件目录存储配额为100M
hiAppEvent.configure({
    maxStorage: '100M'
});
```

## ConfigOption

此接口提供了对应用事件打点功能的配置选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称       | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| disable    | boolean | 否   | 打点功能开关，默认值为false。true：关闭打点功能，false：不关闭打点功能。 |
| maxStorage | string  | 否   | 打点数据存放目录的配额大小，默认值为“10M”。<br>在目录大小超出配额后，下次打点会触发对目录的清理操作：按从旧到新的顺序逐个删除打点数据文件，直到目录大小不超出配额时结束。 |

## hiAppEvent.addWatcher

addWatcher(watcher: [Watcher](#watcher)): [AppEventPackageHolder](#appeventpackageholder)

添加应用事件观察者方法，可用于订阅应用事件。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名  | 类型                 | 必填 | 说明             |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | 是   | 应用事件观察者。 |

**返回值：**

| 类型                                             | 说明                                 |
| ------------------------------------------------ | ------------------------------------ |
| [AppEventPackageHolder](#appeventpackageholder) | 订阅数据持有者，订阅失败时返回null。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 11102001 | Invalid watcher name.           |
| 11102002 | Invalid filtering event domain. |
| 11102003 | Invalid row value.              |
| 11102004 | Invalid size value.             |
| 11102005 | Invalid timeout value.          |

**示例：**

```js
// 1. 如果观察者传入了回调的相关参数，则可以选择在自动触发的回调函数中对订阅事件进行处理
hiAppEvent.addWatcher({
    name: "watcher1",
    appEventFilters: [
        {
            domain: "test_domain",
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
            console.info(`eventPkg.packageId=${eventPkg.packageId}`);
            console.info(`eventPkg.row=${eventPkg.row}`);
            console.info(`eventPkg.size=${eventPkg.size}`);
            for (const eventInfo of eventPkg.data) {
                console.info(`eventPkg.data=${eventInfo}`);
            }
        }
    }
});

// 2. 如果观察者未传入回调的相关参数，则可以选择使用返回的holder对象手动去处理订阅事件
let holder = hiAppEvent.addWatcher({
    name: "watcher2",
});
if (holder != null) {
    let eventPkg = null;
    while ((eventPkg = holder.takeNext()) != null) {
        console.info(`eventPkg.packageId=${eventPkg.packageId}`);
        console.info(`eventPkg.row=${eventPkg.row}`);
        console.info(`eventPkg.size=${eventPkg.size}`);
        for (const eventInfo of eventPkg.data) {
            console.info(`eventPkg.data=${eventInfo}`);
        }
    }
}
```

## hiAppEvent.removeWatcher

removeWatcher(watcher: [Watcher](#watcher)): void

移除应用事件观察者方法，可用于取消订阅应用事件。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名  | 类型                 | 必填 | 说明             |
| ------- | -------------------- | ---- | ---------------- |
| watcher | [Watcher](#watcher) | 是   | 应用事件观察者。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 11102001 | Invalid watcher name. |

**示例：**

```js
// 1. 定义一个应用事件观察者
let watcher = {
    name: "watcher1",
}

// 2. 添加一个应用事件观察者来订阅事件
hiAppEvent.addWatcher(watcher);

// 3. 移除该应用事件观察者以取消订阅事件
hiAppEvent.removeWatcher(watcher);
```

## Watcher

此接口提供了应用事件观察者的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称             | 类型                                                         | 必填 | 说明                                                         |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| name             | string                                                       | 是   | 观察者名称，用于唯一标识观察者。                             |
| triggerCondition | [TriggerCondition](#triggercondition)                        | 否   | 订阅回调触发条件，需要与回调函数一同传入才会生效。           |
| appEventFilters  | [AppEventFilter](#appeventfilter)[]                          | 否   | 订阅过滤条件，在需要对订阅事件进行过滤时传入。               |
| onTrigger        | (curRow: number, curSize: number, holder: [AppEventPackageHolder](#appeventpackageholder)) => void | 否   | 订阅回调函数，需要与回调触发条件一同传入才会生效，函数入参说明如下：<br>curRow：在本次回调触发时的订阅事件总数量； <br>curSize：在本次回调触发时的订阅事件总大小，单位为byte；  <br/>holder：订阅数据持有者对象，可以通过其对订阅事件进行处理。 |

## TriggerCondition

此接口提供了回调触发条件的参数选项，只要满足任一条件就会触发订阅回调。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称    | 类型   | 必填 | 说明                                   |
| ------- | ------ | ---- | -------------------------------------- |
| row     | number | 否   | 满足触发回调的事件总数量。             |
| size    | number | 否   | 满足触发回调的事件总大小，单位为byte。 |
| timeOut | number | 否   | 满足触发回调的超时时长，单位为30s。    |

## AppEventFilter

此接口提供了过滤应用事件的参数选项。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称       | 类型                      | 必填 | 说明                     |
| ---------- | ------------------------- | ---- | ------------------------ |
| domain     | string                    | 是   | 需要订阅的事件领域。     |
| eventTypes | [EventType](#eventtype)[] | 否   | 需要订阅的事件类型集合。 |

## AppEventPackageHolder

订阅数据持有者类，用于对订阅事件进行处理。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

### constructor

constructor(watcherName: string)

类构造函数，在添加应用事件观察者时，会由系统自动调用来创建一个该观察者对应的订阅数据持有者对象，并返回给开发者。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型              | 必填 | 说明                     |
| ------ | ----------------- | ---- | ------------------------ |
| watcherName | string | 是   | 观察者名称。 |

**示例：**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
```

### setSize

setSize(size: number): void

设置每次取出的应用事件包的数据大小阈值。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**参数：**

| 参数名 | 类型   | 必填 | 说明                                         |
| ------ | ------ | ---- | -------------------------------------------- |
| size   | number | 是   | 数据大小阈值，单位为byte，默认值为512*1024。 |

**错误码：**

以下错误码的详细介绍请参见[应用事件打点错误码](../errorcodes/errorcode-hiappevent.md)。

| 错误码ID | 错误信息            |
| -------- | ------------------- |
| 11104001 | Invalid size value. |

**示例：**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
holder.setSize(1000);
```

### takeNext

takeNext(): [AppEventPackage](#appeventpackage)

根据设置的数据大小阈值来取出订阅事件数据，当订阅事件数据全部被取出时返回null作为标识。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**示例：**

```js
let holder = hiAppEvent.addWatcher({
    name: "watcher",
});
let eventPkg = holder.takeNext();
```

## AppEventPackage

此接口提供了订阅返回的应用事件包的参数定义。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 类型     | 必填 | 说明                           |
| --------- | -------- | ---- | ------------------------------ |
| packageId | number   | 是   | 事件包ID，从0开始自动递增。    |
| row       | number   | 是   | 事件包的事件数量。             |
| size      | number   | 是   | 事件包的事件大小，单位为byte。 |
| data      | string[] | 是   | 事件包的事件信息。             |

## hiAppEvent.clearData

clearData(): void

应用事件打点数据清理方法，将应用存储在本地的打点数据进行清除。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

**示例：**

```js
hiAppEvent.clearData();
```


## EventType

事件类型枚举。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称      | 值   | 说明           |
| --------- | ---- | -------------- |
| FAULT     | 1    | 故障类型事件。 |
| STATISTIC | 2    | 统计类型事件。 |
| SECURITY  | 3    | 安全类型事件。 |
| BEHAVIOR  | 4    | 行为类型事件。 |


## Event

此接口提供了所有预定义事件的事件名称常量。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                      | 类型   | 可读 | 可写 | 说明                 |
| ------------------------- | ------ | ---- | ---- | -------------------- |
| USER_LOGIN                | string | 是   | 否   | 用户登录事件。       |
| USER_LOGOUT               | string | 是   | 否   | 用户登出事件。       |
| DISTRIBUTED_SERVICE_START | string | 是   | 否   | 分布式服务启动事件。 |


## Param

此接口提供了所有预定义参数的参数名称常量。

**系统能力：** SystemCapability.HiviewDFX.HiAppEvent

| 名称                            | 类型   | 可读 | 可写 | 说明               |
| ------------------------------- | ------ | ---- | ---- | ------------------ |
| USER_ID                         | string | 是   | 否   | 用户自定义ID。     |
| DISTRIBUTED_SERVICE_NAME        | string | 是   | 否   | 分布式服务名称。   |
| DISTRIBUTED_SERVICE_INSTANCE_ID | string | 是   | 否   | 分布式服务实例ID。 |